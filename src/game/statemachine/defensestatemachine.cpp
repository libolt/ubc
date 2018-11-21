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

#include "statemachine/defensestatemachine.h"
#include "utilities/logging.h"

defenseStateMachine::defenseStateMachine() :
    stateMachine(ST_MAX_STATES)
{
}

void defenseStateMachine::pSetup(defenseSMData *data)  // sets up the state machine
{
    std:: string func = "defenseStateMachine::pSetup";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)          // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_SETUP)          // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_SETUP)          // ST_CREATE_NODES
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);

}

void defenseStateMachine::pExecute(defenseSMData *data)  // executes the defense
{
    std:: string func = "defenseStateMachine::pExecute";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_EXECUTE)          // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)          // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_EXECUTE)          // ST_CREATE_NODES
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);

}

void defenseStateMachine::pHalt()
{
    std:: string func = "defenseStateMachine::halt";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_IDLE)          // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_IDLE)          // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)          // ST_IDLE
    END_TRANSITION_MAP(nullptr)

    logMsg(func +" end");
//    exit(0);

}

// sets up the state machine
STATE_DEFINE(defenseStateMachine, setup, defenseSMData)
{

}

// executes the defense
STATE_DEFINE(defenseStateMachine, execute, defenseSMData)
{

}

// sets defense to Idle
STATE_DEFINE(defenseStateMachine, Idle, noEventData)
{

}
