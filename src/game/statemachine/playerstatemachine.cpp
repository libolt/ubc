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

#include "conversion.h"
#include "statemachine/playerstatemachine.h"

#include "logging.h"

playerStateMachine::playerStateMachine() :
    stateMachine(ST_MAX_STATES),
    currentSpeed(0),
    currentDirection(NODIRECT),
    currentAction(NOACTION)
//    currentPosition(Ogre::Vector3(0,0,0)
    
{
}
    
// set player speed external event
void playerStateMachine::setSpeed(playerSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_START_MOVEMENT)            // ST_IDLE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_STOP
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)              // ST_START
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)              // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_JUMP
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SHOOT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_PASS
    END_TRANSITION_MAP(data)
//    exit(0);
}

// halt player external event
void playerStateMachine::halt()
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_IDLE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_STOP
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_START
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_JUMP
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_SHOOT
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_PASS
    END_TRANSITION_MAP(NULL)
}
    
// jump player external event
void playerStateMachine::pJump(playerSMData *data)
{
    logMsg("daaa");
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_JUMP)                      // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_JUMP)                      // ST_STOP
        TRANSITION_MAP_ENTRY (ST_JUMP)                      // ST_START
        TRANSITION_MAP_ENTRY (ST_JUMP)                      // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_JUMP)                      // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_JUMP
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SHOOT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_PASS
    END_TRANSITION_MAP(data)
    logMsg("dooo");
//    exit(0);
}
   
// change direction player external event
void playerStateMachine::pChangeDirection(playerSMData *data)
{
    
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_STOP
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_START
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_JUMP
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_SHOOT
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_PASS
    END_TRANSITION_MAP(data)
//    exit(0);
}
    
// change  player position external event
void playerStateMachine::pChangePosition(playerSMData *data)
{
    
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_STOP
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_START
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_JUMP
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_SHOOT
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_PASS
    END_TRANSITION_MAP(data)
//    exit(0);
}
// state machine sits here when player is not moving
STATE_DEFINE(playerStateMachine, Idle, noEventData)
{
    logMsg("playerStateMachine::ST_Idle");
//    exit(0);
}

// stop the player
STATE_DEFINE(playerStateMachine, StopMovement, noEventData)
{
    logMsg("playerStateMachine::ST_Stop");
    currentSpeed = 0; 
    currentDirection = NODIRECT;

    // perform the stop motor processing here
    // transition to Idle via an internal event
    internalEvent(ST_IDLE);
//    exit(0);
}

// start the player moving
STATE_DEFINE(playerStateMachine, StartMovement, playerSMData)
{
    sharedPtr<conversion> convert = conversion::Instance();

    logMsg("playerStateMachine::ST_Start : Speed is " +convert->toString(data->speed));
    currentSpeed = data->speed;
//    exit(0);
    // set initial player speed processing here
}

// changes the player's position on the court
STATE_DEFINE(playerStateMachine, ChangePosition, playerSMData)
{
//    exit(0);
    sharedPtr<conversion> convert = conversion::Instance();

    logMsg("playerStateMachine::ST_ChangePosition : Speed is " +convert->toString(data->speed));
    currentSpeed = data->speed;
//    exit(0);
    // perform the change player speed to data->speed here
}
// changes the player's speed once the player is moving
STATE_DEFINE(playerStateMachine, ChangeSpeed, playerSMData)
{
//    exit(0);
    sharedPtr<conversion> convert = conversion::Instance();

    logMsg("playerStateMachine::ST_ChangeSpeed : Speed is " +convert->toString(data->speed));
    currentSpeed = data->speed;
//    exit(0);
    // perform the change player speed to data->speed here
}

// changes the player's direction once the player is moving
STATE_DEFINE(playerStateMachine, ChangeDirection, playerSMData)
{
    sharedPtr<conversion> convert = conversion::Instance();
   
    logMsg("playerStateMachine::ST_ChangeDirection : Direction is " +convert->toString(data->direction));
//    currentSpeed = data->direction;
//    exit(0);
    // perform the change player direction to data->direction here
}

STATE_DEFINE(playerStateMachine, Jump, playerSMData)
{
//    exit(0)
    logMsg("jump");
    logMsg("flee");
    sharedPtr<conversion> convert = conversion::Instance();
    
    logMsg("playerStateMachine::ST_Jump : Speed is " +convert->toString(data->speed));
    internalEvent(ST_IDLE);

//    currentSpeed = data->speed;
//    exit(0);
    // set initial player speed processing here
}

STATE_DEFINE(playerStateMachine, Shoot, playerSMData)
{
    sharedPtr<conversion> convert = conversion::Instance();

    logMsg("playerStateMachine::ST_Shoot : Speed is " +convert->toString(data->speed));
    currentSpeed = data->speed;
//    exit(0);

    // set initial player shoot processing here
}

STATE_DEFINE(playerStateMachine, Pass, playerSMData)
{
    sharedPtr<conversion> convert = conversion::Instance();

    logMsg("playerStateMachine::ST_Pass : Speed is " +convert->toString(data->speed));
    currentSpeed = data->speed;
//    exit(0);
    // set initial player pass processing here
}
