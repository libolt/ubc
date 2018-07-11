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

#ifndef _GAMESTATEMACHINE_H_
#define _GAMESTATEMACHINE_H_

#include <cstdio>
#include "statemachine/statemachine.h"
#include "utilities/enums.h"
#include "utilities/typedefs.h"

class gameFlags;

class gameSMData : public eventData
{
    public:
        gameFlagsSharedPtr flag;  // boolean flags object
    size_t speed;
    directions direction;
    playerActions action;
    Ogre::Vector3 position;
    OgreEntitySharedPtr model;  // stores 3d model
};

class gameStateMachine : public stateMachine
{
public:
    gameStateMachine();

    // External events taken by this state machine
    void pCreateInstances(gameSMData *data);  // creates game object instances
    void setPModel(gameSMData *data);  // sets the model to that of the entity parent object
    void setSpeed(gameSMData *data);
    void halt();
    void pJump(gameSMData *data);
    void pChangeDirection(gameSMData *data);
    void pChangePosition(gameSMData *data);

    
private:
    gameFlagsSharedPtr currentFlag;  // boolean flags object
    size_t currentSpeed; 
    directions currentDirection;
    playerActions currentAction;
    Ogre::Vector3 currentPosition;
    OgreEntitySharedPtr currentModel;  // stores 3d model
    OgreSceneNodeSharedPtr currentNode;  // stores node 3d model is attached to

    // State enumeration order must match the order of state method entries
    // in the state map.
    enum States
    {
        ST_CREATE_INSTANCES,
        ST_SET_START_POS,
        ST_IDLE,
        ST_STOP_MOVEMENT,
        ST_START_MOVEMENT,
        ST_CHANGE_POSITION,  
        ST_CHANGE_SPEED,
        ST_JUMP,
        ST_CHANGE_DIRECTION,
        ST_SHOOT,
        ST_PASS,
        ST_MAX_STATES
    };

    // Define the state machine state functions with event data type
    STATE_DECLARE(gameStateMachine,    createInstances,    gameSMData)
    STATE_DECLARE(gameStateMachine,    setStartPositions,    gameSMData)
    STATE_DECLARE(gameStateMachine,    Idle,            noEventData)
    STATE_DECLARE(gameStateMachine,    StopMovement,    noEventData)
    STATE_DECLARE(gameStateMachine,    StartMovement,   gameSMData)
    STATE_DECLARE(gameStateMachine,    ChangePosition,  gameSMData)
    STATE_DECLARE(gameStateMachine,    ChangeSpeed,     gameSMData)
    STATE_DECLARE(gameStateMachine,    Jump,            gameSMData)
    STATE_DECLARE(gameStateMachine,    ChangeDirection, gameSMData)
    STATE_DECLARE(gameStateMachine,    Shoot,           gameSMData)
    STATE_DECLARE(gameStateMachine,    Pass,            gameSMData)

    // State map to define state object order. Each state map entry defines a
    // state object.
    BEGIN_STATE_MAP
        STATE_MAP_ENTRY(&createInstances)
        STATE_MAP_ENTRY(&setStartPositions)
        STATE_MAP_ENTRY(&Idle)
        STATE_MAP_ENTRY(&StopMovement)
        STATE_MAP_ENTRY(&StartMovement)
        STATE_MAP_ENTRY(&ChangePosition)
        STATE_MAP_ENTRY(&ChangeSpeed)
        STATE_MAP_ENTRY(&Jump)
        STATE_MAP_ENTRY(&ChangeDirection)
        STATE_MAP_ENTRY(&Shoot)
        STATE_MAP_ENTRY(&Pass)       
    END_STATE_MAP   
};

#endif
