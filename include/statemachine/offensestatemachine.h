/***************************************************************************
 *   Copyright (C) 1999 - 2019 by Mike McLean                              *
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

#ifndef _OFFENSESTATEMACHINE_H_
#define _OFFENSESTATEMACHINE_H_

#ifdef _MSC_VER
#define NOMINMAX
#include "winsock2.h"
#endif

#include "statemachine/statemachine.h"
#include "utilities/enums.h"
#include "utilities/typedefs.h"

class offenseSMData : public eventData
{
    public:
        offenseComponentsSharedPtr component;  // component object
        offenseFlagsSharedPtr flag;  // boolean flags object
        quarters currentQuarter;  // stores copy of currentQuarter
        float yOffset;  // stores copy of yOffset
        teamTypes teamWithBall;  // stores copy of teamWithBall
        playerPositions playerPosition;  // stores a copy of playerPosition
};

class offenseStateMachine : public stateMachine
{
public:
    offenseStateMachine();

    // External events taken by this state machine
    void pSetup(offenseSMData *data);  // sets up the state machine
    void pExecute(offenseSMData *data);  // executes the offense
    void pCheckDirectives(offenseSMData *data);  // checks for offensive directive
    void pExecutePass(offenseSMData *data);  // executes a pass
    void pHalt();

private:
    gameDataSharedPtr currentData;  // game data object
    gameFlagsSharedPtr currentFlag;  // boolean flags object

    // State enumeration order must match the order of state method entries
    // in the state map.
    enum States
    {
        ST_SETUP,
        ST_EXECUTE,
        ST_CHECKDIRECTIVES,
        ST_EXECUTEPASS,
        ST_IDLE,
        ST_MAX_STATES
    };

    // Define the state machine state functions with event data type
    STATE_DECLARE(offenseStateMachine,    setup,    offenseSMData)
    STATE_DECLARE(offenseStateMachine,    execute,    offenseSMData)
    STATE_DECLARE(offenseStateMachine,    checkDirectives,    offenseSMData)
    STATE_DECLARE(offenseStateMachine,    executePass,    offenseSMData)
    STATE_DECLARE(offenseStateMachine,    Idle, noEventData)

    // State map to define state object order. Each state map entry defines a
    // state object.
    BEGIN_STATE_MAP
        STATE_MAP_ENTRY(&setup)
        STATE_MAP_ENTRY(&execute)
        STATE_MAP_ENTRY(&checkDirectives)
        STATE_MAP_ENTRY(&executePass)
        STATE_MAP_ENTRY(&Idle)
    END_STATE_MAP
};

#endif // OFFENSESTATEMACHINE_H
