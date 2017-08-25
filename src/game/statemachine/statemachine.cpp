/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
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
// StateMachine
//----------------------------------------------------------------------------
stateMachine::stateMachine(BYTE maxStates, BYTE initialState) :
    MAX_STATES(maxStates),
    m_currentState(initialState),
    m_newState(FALSE),
    m_eventGenerated(FALSE),
    m_pEventData(NULL)
{
    ASSERT_TRUE(MAX_STATES < EVENT_IGNORED);
}

//----------------------------------------------------------------------------
// ExternalEvent
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
        EventData data;
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

    m_pEventData = pData;
    m_eventGenerated = TRUE;
    m_newState = newState;
}

//----------------------------------------------------------------------------
// StateEngine
//----------------------------------------------------------------------------
void stateMachine::stateEngine(void)
{
    const stateMapRow* pStateMap = getStateMap();
    if (pStateMap != NULL)
        stateEngine(pStateMap);
    else
    {
        const stateMapRowEx* pStateMapEx = getStateMapEx();
        if (pStateMapEx != NULL)
            stateEngine(pStateMapEx);
        else
            ASSERT();
    }
}

//----------------------------------------------------------------------------
// StateEngine
//----------------------------------------------------------------------------
void stateMachine::stateEngine(const stateMapRow* const pStateMap)
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
        const stateBase* state = pStateMap[m_newState].state;

        // Copy of event data pointer
        pDataTemp = m_pEventData;

        // Event data used up, reset the pointer
        m_pEventData = NULL;

        // Event used up, reset the flag
        m_eventGenerated = FALSE;

        // Switch to the new current state
        setCurrentState(m_newState);

        // Execute the state action passing in event data
        ASSERT_TRUE(state != NULL);
        state->invokeStateAction(this, pDataTemp);

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
// StateEngine
//----------------------------------------------------------------------------
void stateMachine::stateEngine(const stateMapRowEx* const pStateMapEx)
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
        const stateBase* state = pStateMapEx[m_newState].state;
        const guardBase* guard = pStateMapEx[m_newState].guard;
        const entryBase* entry = pStateMapEx[m_newState].entry;
        const exitBase* exit = pStateMapEx[m_currentState].exit;

        // Copy of event data pointer
        pDataTemp = m_pEventData;

        // Event data used up, reset the pointer
        m_pEventData = NULL;

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
            setCurrentState(m_newState);

            // Execute the state action passing in event data
            ASSERT_TRUE(state != NULL);
            state->invokeStateAction(this, pDataTemp);
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

