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

#include "statemachine/offensestatemachine.h"
#include "utilities/logging.h"

offenseStateMachine::offenseStateMachine() :
    stateMachine(ST_MAX_STATES)
{
}

void offenseStateMachine::pSetup(offenseSMData *data)  // sets up the state machine
{
    std:: string func = "offenseStateMachine::pSetup";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)          // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_SETUP)          // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_SETUP)          // ST_CREATE_NODES
        TRANSITION_MAP_ENTRY (ST_SETUP)          // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (ST_SETUP)          // ST_IDLE
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);

}

void offenseStateMachine::pExecute(offenseSMData *data)  // executes the offense
{
    std:: string func = "offenseStateMachine::pExecute";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_EXECUTE)          // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)          // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_EXECUTE)          // ST_CREATE_NODES
        TRANSITION_MAP_ENTRY (ST_EXECUTE)          // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (ST_EXECUTE)          // ST_IDLE
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);

}

void offenseStateMachine::pCheckDirectives(offenseSMData *data)  // checks for offensive directive
{
    std:: string func = "offenseStateMachine::pCheckDirectives";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_CHECKDIRECTIVES)          // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_CHECKDIRECTIVES)          // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)          // ST_CREATE_NODES
        TRANSITION_MAP_ENTRY (ST_CHECKDIRECTIVES)          // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (ST_CHECKDIRECTIVES)          // ST_IDLE
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);

}

void offenseStateMachine::pExecutePass(offenseSMData *data)  // executes a pass
{
    std:: string func = "offenseStateMachine::pExecutePass";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_EXECUTEPASS)          // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_EXECUTEPASS)          // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_EXECUTEPASS)          // ST_CREATE_NODES
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)          // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (ST_EXECUTEPASS)          // ST_IDLE
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);

}

void offenseStateMachine::pHalt(offenseSMData *data)
{
    std:: string func = "offenseStateMachine::halt";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_HALT)          // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_HALT)          // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_HALT)          // ST_CREATE_NODES
        TRANSITION_MAP_ENTRY (ST_HALT)          // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)          // ST_IDLE
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);

}
