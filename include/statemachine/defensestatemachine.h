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

#ifndef _DEFENSESTATEMACHINE_H_
#define _DEFENSESTATEMACHINE_H_

#include "statemachine/statemachine.h"
#include "utilities/enums.h"
#include "utilities/typedefs.h"

class defenseSMData : public eventData
{
    public:
};

class defenseStateMachine : public stateMachine
{
public:
    defenseStateMachine();

    // External events taken by this state machine
    void pCreateInstances(defenseSMData *data);  // creates game object instances
    void pLoadModels(defenseSMData *data);  // loads the object model
    void pCreateNodes(defenseSMData *data);  // sets the scene nodes and attaches the models
    void pSetStartPositions(defenseSMData *data);  // sets object start positions
    void pSetupJumpBall(defenseSMData *data);
    void pExecuteJumpBall(defenseSMData *data);
    void halt();
    void pChangePosition(defenseSMData *data);

private:
    gameDataSharedPtr currentData;  // game data object
    gameFlagsSharedPtr currentFlag;  // boolean flags object

    // State enumeration order must match the order of state method entries
    // in the state map.
    enum States
    {
        ST_CREATE_INSTANCES,
        ST_LOAD_MODELS,
        ST_CREATE_NODES,
        ST_SET_START_POS,
        ST_SETUP_JUMPBALL,
        ST_EXECUTE_JUMPBALL,
        ST_IDLE,
        ST_START_MOVEMENT,
        ST_CHANGE_POSITION,
        ST_CHANGE_SPEED,
        ST_SHOOT,
        ST_PASS,
        ST_MAX_STATES
    };

    // Define the state machine state functions with event data type
    STATE_DECLARE(defenseStateMachine,    createInstances,    defenseSMData)
    STATE_DECLARE(defenseStateMachine,    loadModels,    defenseSMData)
    STATE_DECLARE(defenseStateMachine,    createNodes,    defenseSMData)
    STATE_DECLARE(defenseStateMachine,    setStartPositions,    defenseSMData)
    STATE_DECLARE(defenseStateMachine,    setupJumpBall, defenseSMData)
    STATE_DECLARE(defenseStateMachine,    executeJumpBall, defenseSMData)
    STATE_DECLARE(defenseStateMachine,    Idle,            noEventData)
    STATE_DECLARE(defenseStateMachine,    StartMovement,   defenseSMData)
    STATE_DECLARE(defenseStateMachine,    ChangePosition,  defenseSMData)
    STATE_DECLARE(defenseStateMachine,    ChangeSpeed,     defenseSMData)
    STATE_DECLARE(defenseStateMachine,    Shoot,           defenseSMData)
    STATE_DECLARE(defenseStateMachine,    Pass,            defenseSMData)

    // State map to define state object order. Each state map entry defines a
    // state object.
    BEGIN_STATE_MAP
        STATE_MAP_ENTRY(&createInstances)
        STATE_MAP_ENTRY(&loadModels)
        STATE_MAP_ENTRY(&createNodes)
        STATE_MAP_ENTRY(&setStartPositions)
        STATE_MAP_ENTRY(&setupJumpBall)
        STATE_MAP_ENTRY(&executeJumpBall)
        STATE_MAP_ENTRY(&Idle)
        STATE_MAP_ENTRY(&StartMovement)
        STATE_MAP_ENTRY(&ChangePosition)
        STATE_MAP_ENTRY(&ChangeSpeed)
        STATE_MAP_ENTRY(&Shoot)
        STATE_MAP_ENTRY(&Pass)
    END_STATE_MAP
};

#endif // DEFENSESTATEMACHINE_H
