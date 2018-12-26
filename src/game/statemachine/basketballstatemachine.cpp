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

#include "statemachine/basketballstatemachine.h"
#include "components/basketballcomponents.h"
#include "data/basketballdata.h"
#include "physics/basketballphysics.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

basketballStateMachine::basketballStateMachine() :
    stateMachine(ST_MAX_STATES),
    m_currentSpeed(0)
{
}
    
// Initialize state machine external event
void basketballStateMachine::pInitialize(basketballSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_STOP
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_START
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_JUMP
    END_TRANSITION_MAP(nullptr)
}

// set motor speed external event
void basketballStateMachine::setSpeed(basketballSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_START_MOVEMENT)            // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_START_MOVEMENT)            // ST_IDLE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_STOP
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)              // ST_START
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)              // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_JUMP

    END_TRANSITION_MAP(data)
}

// halt motor external event
void basketballStateMachine::halt()
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_IDLE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_STOP
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_START
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_JUMP
    END_TRANSITION_MAP(nullptr)
}

// Initialize the state machine
STATE_DEFINE(basketballStateMachine, Initialize, basketballSMData)
{
    sharedPtr<basketballPhysics> tempPhysics(new basketballPhysics);
    data->component->setPhysics(tempPhysics);

    std::string func = "basketballStateMachine::Initialize()";

    logMsg(func +" begin");

    basketballDataSharedPtr tempData(new basketballData);
    data->bData = tempData;

/*    basketballEntitySharedPtr tempEntity(new basketballEntity);
    entity = tempEntity;

    if (!entity->getInitialized())
    {
        if (entity->initialize())
        {
            entity->setInitialized(true);
        }
        else
        {
            logMsg(func +"Unable to initialize basketball entity object!");
            exit(0);
        }
    }*/

    logMsg(func +" end");

}

// state machine sits here when motor is not running
STATE_DEFINE(basketballStateMachine, Idle, noEventData)
{
    logMsg("Motor::ST_Idle");
}

// stop the motor 
STATE_DEFINE(basketballStateMachine, StopMovement, noEventData)
{
    logMsg("Motor::ST_Stop");
    m_currentSpeed = 0; 

    // perform the stop motor processing here
    // transition to Idle via an internal event
    internalEvent(ST_IDLE);
}

// start the motor going
STATE_DEFINE(basketballStateMachine, StartMovement, basketballSMData)
{
    conversionSharedPtr convert;
//    logMsg("Motor::ST_Start : Speed is " +convert->toString(data->speed));
//    m_currentSpeed = data->speed;
exit(0);
    // set initial motor speed processing here
}

// changes the motor speed once the motor is moving
STATE_DEFINE(basketballStateMachine, ChangeSpeed, basketballSMData)
{
    conversionSharedPtr convert;

//    logMsg("Motor::ST_ChangeSpeed : Speed is " +convert->toString(data->speed));
//    m_currentSpeed = data->speed;

    // perform the change motor speed to data->speed here
}

STATE_DEFINE(basketballStateMachine, Jump, basketballSMData)
{
    conversionSharedPtr convert;

//    logMsg("Motor::ST_Jump : Speed is " +convert->toString(data->speed));
//    m_currentSpeed = data->speed;

    // set initial motor speed processing here
}
