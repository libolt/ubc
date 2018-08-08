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

#ifndef _PLAYERSTATEMACHINE_H_
#define _PLAYERSTATEMACHINE_H_

#include <cstdio>
#include "statemachine/statemachine.h"
#include "utilities/enums.h"
#include "utilities/typedefs.h"

class playerSMData : public eventData
{
public:
    size_t speed;
    directions direction;
    playerActions action;
    Ogre::Vector3 position;
    OgreEntitySharedPtr model;  // stores 3d model
    OgreSceneNodeSharedPtr node;  // stores node 3d model is attached to
};

class playerStateMachine : public stateMachine
{
public:
    playerStateMachine();

    // External events taken by this state machine
    void setPNode(playerSMData *data);  // sets the node to that of the entity parent object
    void setPModel(playerSMData *data);  // sets the model to that of the entity parent object
    void setSpeed(playerSMData *data);
    void halt();
    void pJump(playerSMData *data);
    void pChangeDirection(playerSMData *data);
    void pChangePosition(playerSMData *data);

    
private:
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
        ST_SET_NODE,
        ST_SET_MODEL,
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
    STATE_DECLARE(playerStateMachine,    SetNode,    playerSMData)
    STATE_DECLARE(playerStateMachine,    SetModel,    playerSMData)
    STATE_DECLARE(playerStateMachine,    Idle,            noEventData)
    STATE_DECLARE(playerStateMachine,    StopMovement,    noEventData)
    STATE_DECLARE(playerStateMachine,    StartMovement,   playerSMData)
    STATE_DECLARE(playerStateMachine,    ChangePosition,  playerSMData)
    STATE_DECLARE(playerStateMachine,    ChangeSpeed,     playerSMData)
    STATE_DECLARE(playerStateMachine,    Jump,            playerSMData)
    STATE_DECLARE(playerStateMachine,    ChangeDirection, playerSMData)
    STATE_DECLARE(playerStateMachine,    Shoot,           playerSMData)
    STATE_DECLARE(playerStateMachine,    Pass,            playerSMData)

    // State map to define state object order. Each state map entry defines a
    // state object.
    BEGIN_STATE_MAP
        STATE_MAP_ENTRY(&SetNode)
        STATE_MAP_ENTRY(&SetModel)
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

