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

#ifndef _BASKETBALLSTATEMACHINE_H_
#define _BASKETBALLSTATEMACHINE_H_

#include "statemachine/statemachine.h"

class basketballSMData : public eventData
{
public:
    INT speed;
};

class basketballStateMachine : public stateMachine
{
public:
    basketballStateMachine();

    // External events taken by this state machine
    void setSpeed(basketballSMData* data);
    void halt();

private:
    INT m_currentSpeed; 

    // State enumeration order must match the order of state method entries
    // in the state map.
    enum States
    {
        ST_IDLE,
        ST_STOP_MOVEMENT,
        ST_START_MOVEMENT, 
        ST_CHANGE_SPEED,
        ST_JUMP,
        ST_MAX_STATES
    };

    // Define the state machine state functions with event data type
    STATE_DECLARE(basketballStateMachine,    Idle,           noEventData)
    STATE_DECLARE(basketballStateMachine,    StopMovement,   noEventData)
    STATE_DECLARE(basketballStateMachine,    StartMovement,  basketballSMData)
    STATE_DECLARE(basketballStateMachine,    ChangeSpeed,    basketballSMData)
    STATE_DECLARE(basketballStateMachine,    Jump,           basketballSMData)

    // State map to define state object order. Each state map entry defines a
    // state object.
    BEGIN_STATE_MAP
        STATE_MAP_ENTRY(&Idle)
        STATE_MAP_ENTRY(&StopMovement)
        STATE_MAP_ENTRY(&StartMovement)
        STATE_MAP_ENTRY(&ChangeSpeed)
        STATE_MAP_ENTRY(&Jump)
    END_STATE_MAP   
};

#endif
