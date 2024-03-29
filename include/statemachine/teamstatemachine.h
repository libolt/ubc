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

#ifndef _TEAMSTATEMACHINE_H_
#define _TEAMSTATEMACHINE_H_

#include "statemachine/StateMachine.h"
#include "utilities/typedefs.h"

class teamSMData : public EventData
{
    public:
        teamComponentsSharedPtr component;  // instance of teamComponents object
        teamDataSharedPtr tData;  //  instance of the teamData object
        teamFlagsSharedPtr flag;  // instance of teamFlags object
        teamGameDataSharedPtr gData;  // instance of teamGameData object
        playerEntityMSharedPtr gamePlayerInstance;  // instance of gameEntity player objects
        renderEngineSharedPtr render;  // copy of renderEngine object
        courtEntityMSharedPtr courtInstance; // copy of courtInstance object
        teamStarterIDsVecM teamStarterID;  // copy of teamStartID object
};

class teamStateMachine : public StateMachine
{
public:
    teamStateMachine();

    // External events taken by this state machine
    
    void pInit(teamSMData *data);
    void pCreatePlayerInstances(teamSMData *data);
    void pSetupPlayerInstances(teamSMData *data);
    void pSetPlayerStartPositions(teamSMData *data);
    void pSetPlayerStartDirections(teamSMData *data);
    void pUpdateActivePlayers(teamSMData *data);
    void pExecuteOffense(teamSMData *data);
    void pExecuteDefense(teamSMData *data);

private:

    // State enumeration order must match the order of state method entries
    // in the state map.
    enum States
    {       
        ST_INIT,
        ST_IDLE,
        ST_CREATE_PLAYERINSTANCES,
        ST_SETUP_PLAYERINSTANCES,
        ST_SET_PLAYER_START_POSITIONS,
        ST_SET_PLAYER_START_DIRECTIONS,
        ST_UPDATE_ACTIVEPLAYERS,
        ST_EXECUTE_OFFENSE,
        ST_EXECUTE_DEFENSE,
        ST_MAX_STATES
    };

    // Define the state machine state functions with event data type
    STATE_DECLARE(teamStateMachine,    init,   teamSMData)
    STATE_DECLARE(teamStateMachine,    Idle,           NoEventData)
    STATE_DECLARE(teamStateMachine,    createPlayerInstances,   teamSMData)
    STATE_DECLARE(teamStateMachine, setupPlayerInstances, teamSMData)
    STATE_DECLARE(teamStateMachine, setPlayerStartPositions, teamSMData)
    STATE_DECLARE(teamStateMachine, setPlayerStartDirections, teamSMData)
    STATE_DECLARE(teamStateMachine, updateActivePlayers, teamSMData)
    STATE_DECLARE(teamStateMachine, executeOffense, teamSMData)
    STATE_DECLARE(teamStateMachine, executeDefense, teamSMData)

    // State map to define state object order. Each state map entry defines a
    // state object.
    BEGIN_STATE_MAP
        STATE_MAP_ENTRY(&init)
        STATE_MAP_ENTRY(&Idle)
        STATE_MAP_ENTRY(&createPlayerInstances)
        STATE_MAP_ENTRY(&setupPlayerInstances)
        STATE_MAP_ENTRY(&setPlayerStartPositions)
        STATE_MAP_ENTRY(&setPlayerStartDirections)
        STATE_MAP_ENTRY(&updateActivePlayers)
        STATE_MAP_ENTRY(&executeOffense)
        STATE_MAP_ENTRY(&executeDefense)
    END_STATE_MAP
};

#endif
