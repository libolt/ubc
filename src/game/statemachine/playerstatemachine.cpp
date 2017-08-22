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

#include "statemachine/playerstatemachine.h"
#include "logging.h"

playerStateMachine::playerStateMachine() :
    stateMachine(ST_MAX_STATES),
    m_currentSpeed(0)
{
}
    
// set motor speed external event
void playerStateMachine::setSpeed(playerSMData* data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_START)                     // ST_IDLE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_STOP
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)              // ST_START
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)              // ST_CHANGE_SPEED
    END_TRANSITION_MAP(data)
}

// halt motor external event
void playerStateMachine::halt()
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_IDLE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_STOP
        TRANSITION_MAP_ENTRY (ST_STOP)                      // ST_START
        TRANSITION_MAP_ENTRY (ST_STOP)                      // ST_CHANGE_SPEED
    END_TRANSITION_MAP(NULL)
}

// state machine sits here when motor is not running
STATE_DEFINE(playerStateMachine, Idle, noEventData)
{
    logMsg("Motor::ST_Idle");
}

// stop the motor 
STATE_DEFINE(playerStateMachine, Stop, noEventData)
{
    logMsg("Motor::ST_Stop");
    m_currentSpeed = 0; 

    // perform the stop motor processing here
    // transition to Idle via an internal event
    internalEvent(ST_IDLE);
}

// start the motor going
STATE_DEFINE(playerStateMachine, Start, playerSMData)
{
    logMsg("Motor::ST_Start : Speed is " +data->speed);
    m_currentSpeed = data->speed;

    // set initial motor speed processing here
}

// changes the motor speed once the motor is moving
STATE_DEFINE(playerStateMachine, ChangeSpeed, playerSMData)
{
    logMsg("Motor::ST_ChangeSpeed : Speed is " +data->speed);
    m_currentSpeed = data->speed;

    // perform the change motor speed to data->speed here
}

