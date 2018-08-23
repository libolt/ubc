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

#ifndef _TEAMSTATEMACHINE_H_
#define _TEAMSTATEMACHINE_H_

#include "statemachine/statemachine.h"

class teamSMData : public eventData
{
    public:
        INT speed;
        teamComponentsSharedPtr component;  // instance of teamComponents object
        teamDataSharedPtr tData;  //  instance of the teamData object
        teamFlagsSharedPtr flag;  // instance of teamFlags object
        teamGameDataSharedPtr gData;  // instance of teamGameData object
};

class teamStateMachine : public stateMachine
{
public:
    teamStateMachine();

    // External events taken by this state machine
    void setSpeed(teamSMData* data);
    void pCreatePlayerInstances(teamSMData *data);

private:
    INT m_currentSpeed; 

    // State enumeration order must match the order of state method entries
    // in the state map.
    enum States
    {
        ST_IDLE,
        ST_CREATE_PLAYERINSTANCES,
        ST_START_MOVEMENT, 
        ST_CHANGE_SPEED,
        ST_JUMP,
        ST_MAX_STATES
    };

    // Define the state machine state functions with event data type
    STATE_DECLARE(teamStateMachine,    Idle,           noEventData)
    STATE_DECLARE(teamStateMachine,    createPlayerInstances,   teamSMData)
    STATE_DECLARE(teamStateMachine,    StartMovement,  teamSMData)
    STATE_DECLARE(teamStateMachine,    ChangeSpeed,    teamSMData)
    STATE_DECLARE(teamStateMachine,    Jump,           teamSMData)

    // State map to define state object order. Each state map entry defines a
    // state object.
    BEGIN_STATE_MAP
        STATE_MAP_ENTRY(&Idle)
        STATE_MAP_ENTRY(&createPlayerInstances)
        STATE_MAP_ENTRY(&StartMovement)
        STATE_MAP_ENTRY(&ChangeSpeed)
        STATE_MAP_ENTRY(&Jump)
    END_STATE_MAP   
};

#endif
