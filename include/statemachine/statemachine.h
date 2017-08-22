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

#ifndef _STATEMACHINE_H_
#define _STATEMACHINE_H_

#include "eventdata/datatypes.h"
#include "eventdata/eventdata.h"
#include "statemachine/fault.h"

typedef eventData noEventData;

class stateMachine;

/// @brief Abstract state base class that all states inherit from.
class stateBase
{
public:
    /// Called by the state machine engine to execute a state action. If a guard condition
    /// exists and it evaluates to false, the state action will not execute.
    /// @param[in] sm - A state machine instance.
    /// @param[in] data - The event data.
    virtual void invokeStateAction(stateMachine* sm, const eventData* data) const = 0;
};

/// @brief StateAction takes three template arguments: A state machine class,
/// a state function event data type (derived from EventData) and a state machine
/// member function pointer.
template <class SM, class Data, void (SM::*Func)(const Data*)>
class stateAction : public stateBase
{
public:
    /// @see StateBase::InvokeStateAction
    virtual void invokeStateAction(stateMachine* sm, const eventData* data) const
    {
        // Downcast the state machine and event data to the correct derived type
        SM* derivedSM = static_cast<SM*>(sm);

        // If this check fails, there is a mismatch between the STATE_DECLARE
        // event data type and the data type being sent to the state function.
        // For instance, given the following state defintion:
        //    STATE_DECLARE(MyStateMachine, MyStateFunction, MyEventData)
        // The following internal event transition is valid:
        //    InternalEvent(ST_MY_STATE_FUNCTION, new MyEventData());
        // This next internal event is not valid and causes the assert to fail:
        //    InternalEvent(ST_MY_STATE_FUNCTION, new OtherEventData());
        const Data* derivedData = dynamic_cast<const Data*>(data);
        ASSERT_TRUE(derivedData != NULL);

        // Call the state function
        (derivedSM->*Func)(derivedData);
    }
};

/// @brief Abstract guard base class that all guards classes inherit from.
class guardBase
{
public:
    /// Called by the state machine engine to execute a guard condition action. If guard
    /// condition evaluates to TRUE the state action is executed. If FALSE, no state transition
    /// is performed.
    /// @param[in] sm - A state machine instance.
    /// @param[in] data - The event data.
    /// @return Returns TRUE if no guard condition or the guard condition evaluates to TRUE.
    virtual BOOL invokeGuardCondition(stateMachine* sm, const eventData* data) const = 0;
};

/// @brief GuardCondition takes three template arguments: A state machine class,
/// a state function event data type (derived from EventData) and a state machine
/// member function pointer.
template <class SM, class Data, BOOL (SM::*Func)(const Data*)>
class guardCondition : public guardBase
{
public:
    virtual BOOL invokeGuardCondition(stateMachine* sm, const eventData* data) const
    {
        SM* derivedSM = static_cast<SM*>(sm);
        const Data* derivedData = dynamic_cast<const Data*>(data);
        ASSERT_TRUE(derivedData != NULL);

        // Call the guard function
        return (derivedSM->*Func)(derivedData);
    }
};

/// @brief Abstract entry base class that all entry classes inherit from.
class entryBase
{
public:
    /// Called by the state machine engine to execute a state entry action. Called when
    /// entering a state.
    /// @param[in] sm - A state machine instance.
    /// @param[in] data - The event data.
    virtual void invokeEntryAction(stateMachine* sm, const eventData* data) const = 0;
};

/// @brief EntryAction takes three template arguments: A state machine class,
/// a state function event data type (derived from EventData) and a state machine
/// member function pointer.
template <class SM, class Data, void (SM::*Func)(const Data*)>
class entryAction : public entryBase
{
public:
    virtual void InvokeEntryAction(stateMachine* sm, const eventData* data) const
    {
        SM* derivedSM = static_cast<SM*>(sm);
        const Data* derivedData = dynamic_cast<const Data*>(data);
        ASSERT_TRUE(derivedData != NULL);

        // Call the entry function
        (derivedSM->*Func)(derivedData);
    }
};

/// @brief Abstract exit base class that all exit classes inherit from.
class exitBase
{
public:
    /// Called by the state machine engine to execute a state exit action. Called when
    /// leaving a state.
    /// @param[in] sm - A state machine instance.
    virtual void invokeExitAction(stateMachine* sm) const = 0;
};

/// @brief ExitAction takes two template arguments: A state machine class and
/// a state machine member function pointer.
template <class SM, void (SM::*Func)(void)>
class exitAction : public exitBase
{
public:
    virtual void InvokeExitAction(stateMachine* sm) const
    {
        SM* derivedSM = static_cast<SM*>(sm);

        // Call the exit function
        (derivedSM->*Func)();
    }
};

/// @brief A structure to hold a single row within the state map.
struct stateMapRow
{
    const stateBase* const state;
};

/// @brief A structure to hold a single row within the extended state map.
struct stateMapRowEx
{
    const stateBase* const state;
    const guardBase* const guard;
    const entryBase* const entry;
    const exitBase* const exit;
};

/// @brief StateMachine implements a software-based state machine.
class stateMachine
{
public:
    enum { EVENT_IGNORED = 0xFE, CANNOT_HAPPEN };

    ///	Constructor.
    ///	@param[in] maxStates - the maximum number of state machine states.
    stateMachine(BYTE maxStates, BYTE initialState = 0);

    virtual ~stateMachine() {}

    /// Gets the current state machine state.
    /// @return Current state machine state.
    BYTE getCurrentState() { return m_currentState; }

    /// Gets the maximum number of state machine states.
    /// @return The maximum state machine states.
    BYTE getMaxStates() { return MAX_STATES; }

protected:
    /// External state machine event.
    /// @param[in] newState - the state machine state to transition to.
    /// @param[in] pData - the event data sent to the state.
    void externalEvent(BYTE newState, const eventData* pData = NULL);

    /// Internal state machine event. These events are generated while executing
    ///	within a state machine state.
    /// @param[in] newState - the state machine state to transition to.
    /// @param[in] pData - the event data sent to the state.
    void internalEvent(BYTE newState, const eventData* pData = NULL);

private:
    /// The maximum number of state machine states.
    const BYTE MAX_STATES;

    /// The current state machine state.
    BYTE m_currentState;

    /// The new state the state machine has yet to transition to.
    BYTE m_newState;

    /// Set to TRUE when an event is generated.
    BOOL m_eventGenerated;

    /// The state event data pointer.
    const eventData* m_pEventData;

    /// Gets the state map as defined in the derived class. The BEGIN_STATE_MAP,
    /// STATE_MAP_ENTRY and END_STATE_MAP macros are used to assist in creating the
    /// map. A state machine only needs to return a state map using either GetStateMap()
    /// or GetStateMapEx() but not both.
    /// @return An array of StateMapRow pointers with the array size MAX_STATES or
    /// NULL if the state machine uses the GetStateMapEx().
    virtual const stateMapRow* getStateMap() = 0;

    /// Gets the extended state map as defined in the derived class. The BEGIN_STATE_MAP_EX,
    /// STATE_MAP_ENTRY_EX, STATE_MAP_ENTRY_ALL_EX, and END_STATE_MAP_EX macros are used to
    /// assist in creating the map. A state machine only needs to return a state map using
    /// either GetStateMap() or GetStateMapEx() but not both.
    /// @return An array of StateMapRowEx pointers with the array size MAX_STATES or
    /// NULL if the state machine uses the GetStateMap().
    virtual const stateMapRowEx* getStateMapEx() = 0;

    /// Set a new current state.
    /// @param[in] newState - the new state.
    void setCurrentState(BYTE newState) { m_currentState = newState; }

    /// State machine engine that executes the external event and, optionally, all
    /// internal events generated during state execution.
    void stateEngine(void);
    void stateEngine(const stateMapRow* const pStateMap);
    void stateEngine(const stateMapRowEx* const pStateMapEx);
};

#define STATE_DECLARE(stateMachine, stateName, eventData) \
    void ST_##stateName(const eventData*); \
    stateAction<stateMachine, eventData, &stateMachine::ST_##stateName> stateName;

#define STATE_DEFINE(stateMachine, stateName, eventData) \
    void stateMachine::ST_##stateName(const eventData* data)

#define GUARD_DECLARE(stateMachine, guardName, eventData) \
    BOOL GD_##guardName(const eventData*); \
    GuardCondition<stateMachine, eventData, &stateMachine::GD_##guardName> guardName;

#define GUARD_DEFINE(stateMachine, guardName, eventData) \
    BOOL stateMachine::GD_##guardName(const eventData* data)

#define ENTRY_DECLARE(stateMachine, entryName, eventData) \
    void EN_##entryName(const eventData*); \
    EntryAction<stateMachine, eventData, &stateMachine::EN_##entryName> entryName;

#define ENTRY_DEFINE(stateMachine, entryName, eventData) \
    void stateMachine::EN_##entryName(const eventData* data)

#define EXIT_DECLARE(stateMachine, exitName) \
    void EX_##exitName(void); \
    ExitAction<stateMachine, &stateMachine::EX_##exitName> exitName;

#define EXIT_DEFINE(stateMachine, exitName) \
    void stateMachine::EX_##exitName(void)

#define BEGIN_TRANSITION_MAP \
    static const BYTE TRANSITIONS[] = {\

#define TRANSITION_MAP_ENTRY(entry)\
    entry,

#define END_TRANSITION_MAP(data) \
    };\
    ASSERT_TRUE(getCurrentState() < ST_MAX_STATES); \
    externalEvent(TRANSITIONS[getCurrentState()], data); \
    C_ASSERT((sizeof(TRANSITIONS)/sizeof(BYTE)) == ST_MAX_STATES);

#define PARENT_TRANSITION(state) \
    if (GetCurrentState() >= ST_MAX_STATES && \
        GetCurrentState() < GetMaxStates()) { \
        ExternalEvent(state); \
        return; }

#define BEGIN_STATE_MAP \
    private:\
    virtual const stateMapRowEx* getStateMapEx() { return NULL; }\
    virtual const stateMapRow* getStateMap() {\
        static const stateMapRow STATE_MAP[] = {

#define STATE_MAP_ENTRY(stateName)\
    stateName,

#define END_STATE_MAP \
    }; \
    C_ASSERT((sizeof(STATE_MAP)/sizeof(stateMapRow)) == ST_MAX_STATES); \
    return &STATE_MAP[0]; }

#define BEGIN_STATE_MAP_EX \
    private:\
    virtual const StateMapRow* GetStateMap() { return NULL; }\
    virtual const StateMapRowEx* GetStateMapEx() {\
        static const StateMapRowEx STATE_MAP[] = {

#define STATE_MAP_ENTRY_EX(stateName)\
    { stateName, 0, 0, 0 },

#define STATE_MAP_ENTRY_ALL_EX(stateName, guardName, entryName, exitName)\
    { stateName, guardName, entryName, exitName },

#define END_STATE_MAP_EX \
    }; \
    C_ASSERT((sizeof(STATE_MAP)/sizeof(StateMapRowEx)) == ST_MAX_STATES); \
   return &STATE_MAP[0]; }

#endif
