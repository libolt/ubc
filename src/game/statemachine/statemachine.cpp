/***************************************************************************
 *   Copyright (C) 1999 - 2018 by Mike McLean                              *
 *   libolt@libolt.net                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

//#include <stdafx.h>
#include "statemachine/statemachine.h"
#include "statemachine/fault.h"
#include "eventdata/eventdata.h"

//----------------------------------------------------------------------------
// stateMachine
//----------------------------------------------------------------------------
stateMachine::stateMachine(BYTE maxstates, BYTE initialstate) :
    MAX_STATES(maxstates),
    m_currentState(initialstate),
    m_newState(FALSE),
    m_eventGenerated(FALSE),
    m_peventData(NULL)
{
    ASSERT_TRUE(MAX_STATES < EVENT_IGNORED);
}

//----------------------------------------------------------------------------
// externalEvent
//----------------------------------------------------------------------------
void stateMachine::externalEvent(BYTE newState, const eventData* pData)
{
    // If we are supposed to ignore this event
    if (newState == EVENT_IGNORED)
    {
#ifndef EXTERNAL_EVENT_NO_HEAP_DATA
        // Just delete the event data, if any
        if (pData != NULL)
            delete pData;
#endif
    }
    else
    {
        // TODO - capture software lock here for thread-safety if necessary

#ifdef EXTERNAL_EVENT_NO_HEAP_DATA
        eventData data;
        if (pData == NULL)
            pData = &data;
#endif
        // Generate the event
        internalEvent(newState, pData);

        // Execute the state engine. This function call will only return
        // when all state machine events are processed.
        stateEngine();

        // TODO - release software lock here
    }
}

//----------------------------------------------------------------------------
// InternalEvent
//----------------------------------------------------------------------------
void stateMachine::internalEvent(BYTE newState, const eventData* pData)
{
    if (pData == NULL)
        pData = new noEventData();

    m_peventData = pData;
    m_eventGenerated = TRUE;
    m_newState = newState;
}

//----------------------------------------------------------------------------
// stateEngine
//----------------------------------------------------------------------------
void stateMachine::stateEngine(void)
{
    const stateMapRow* pstateMap = GetstateMap();
    if (pstateMap != NULL)
        stateEngine(pstateMap);
    else
    {
        const stateMapRowEx* pstateMapEx = GetstateMapEx();
        if (pstateMapEx != NULL)
            stateEngine(pstateMapEx);
        else
            ASSERT();
    }
}

//----------------------------------------------------------------------------
// stateEngine
//----------------------------------------------------------------------------
void stateMachine::stateEngine(const stateMapRow* const pstateMap)
{
#if EXTERNAL_EVENT_NO_HEAP_DATA
    BOOL externalEvent = TRUE;
#endif
    const eventData* pDataTemp = NULL;

    // While events are being generated keep executing states
    while (m_eventGenerated)
    {
        // Error check that the new state is valid before proceeding
        ASSERT_TRUE(m_newState < MAX_STATES);

        // Get the pointer from the state map
        const stateBase* state = pstateMap[m_newState].state;

        // Copy of event data pointer
        pDataTemp = m_peventData;

        // Event data used up, reset the pointer
        m_peventData = NULL;

        // Event used up, reset the flag
        m_eventGenerated = FALSE;

        // Switch to the new current state
        SetCurrentstate(m_newState);

        // Execute the state action passing in event data
        ASSERT_TRUE(state != NULL);
        state->invokestateAction(this, pDataTemp);

        // If event data was used, then delete it
#if EXTERNAL_EVENT_NO_HEAP_DATA
        if (pDataTemp)
        {
            if (!externalEvent)
                delete pDataTemp;
            pDataTemp = NULL;
        }
        externalEvent = FALSE;
#else
        if (pDataTemp)
        {
            delete pDataTemp;
            pDataTemp = NULL;
        }
#endif
    }
}

//----------------------------------------------------------------------------
// stateEngine
//----------------------------------------------------------------------------
void stateMachine::stateEngine(const stateMapRowEx* const pstateMapEx)
{
#if EXTERNAL_EVENT_NO_HEAP_DATA
    BOOL externalEvent = TRUE;
#endif
    const eventData* pDataTemp = NULL;

    // While events are being generated keep executing states
    while (m_eventGenerated)
    {
        // Error check that the new state is valid before proceeding
        ASSERT_TRUE(m_newState < MAX_STATES);

        // Get the pointers from the state map
        const stateBase* state = pstateMapEx[m_newState].state;
        const GuardBase* guard = pstateMapEx[m_newState].Guard;
        const EntryBase* entry = pstateMapEx[m_newState].Entry;
        const ExitBase* exit = pstateMapEx[m_currentState].Exit;

        // Copy of event data pointer
        pDataTemp = m_peventData;

        // Event data used up, reset the pointer
        m_peventData = NULL;

        // Event used up, reset the flag
        m_eventGenerated = FALSE;

        // Execute the guard condition
        BOOL guardResult = TRUE;
        if (guard != NULL)
            guardResult = guard->invokeGuardCondition(this, pDataTemp);

        // If the guard condition succeeds
        if (guardResult == TRUE)
        {
            // Transitioning to a new state?
            if (m_newState != m_currentState)
            {
                // Execute the state exit action on current state before switching to new state
                if (exit != NULL)
                    exit->invokeExitAction(this);

                // Execute the state entry action on the new state
                if (entry != NULL)
                    entry->invokeEntryAction(this, pDataTemp);

                // Ensure exit/entry actions didn't call InternalEvent by accident
                ASSERT_TRUE(m_eventGenerated == FALSE);
            }

            // Switch to the new current state
            SetCurrentstate(m_newState);

            // Execute the state action passing in event data
            ASSERT_TRUE(state != NULL);
            state->invokestateAction(this, pDataTemp);
        }

        // If event data was used, then delete it
#if EXTERNAL_EVENT_NO_HEAP_DATA
        if (pDataTemp)
        {
            if (!externalEvent)
                delete pDataTemp;
            pDataTemp = NULL;
        }
        externalEvent = FALSE;
#else
        if (pDataTemp)
        {
            delete pDataTemp;
            pDataTemp = NULL;
        }
#endif
    }
}



