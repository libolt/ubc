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

#include "statemachine/teamstatemachine.h"
#include "components/teamcomponents.h"
#include "data/teamdata.h"
#include "flags/teamflags.h"
#include "setup/setupplayers.h"
#include "setup/setupteams.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

teamStateMachine::teamStateMachine() :
    stateMachine(ST_MAX_STATES)
{
}
    
void teamStateMachine::pInit(teamSMData *data)
{
    std::string func = "teamStateMachine::pInit()";

    logMsg(func +" begin");
    
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_INIT)                // ST_INIT
        TRANSITION_MAP_ENTRY (ST_INIT)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_INIT)                // ST_CREATE_PLAYERINSTANCES
    END_TRANSITION_MAP(data)

}
// halt motor external event
void teamStateMachine::pCreatePlayerInstances(teamSMData *data)
{
    std::string func = "teamStateMachine::pCreatePlayerInstance()";

    logMsg(func +" begin");
//    exit(0);
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_CREATE_PLAYERINSTANCES)                // ST_INIT
        TRANSITION_MAP_ENTRY (ST_CREATE_PLAYERINSTANCES)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_CREATE_PLAYERINSTANCES)                // ST_CREATE_PLAYERINSTANCES
    END_TRANSITION_MAP(data)
}

STATE_DEFINE(teamStateMachine, init, teamSMData)
{
    std::string func = "teamStateMachine::ST_INIT";
    logMsg(func +" begin");
//    exit(0);
}

// state machine sits here when motor is not running
STATE_DEFINE(teamStateMachine, Idle, noEventData)
{
    std::string func = "teamStateMachine::ST_Idle";
    logMsg(func +" begin");
//    exit(0);
}

// creates player instances
STATE_DEFINE(teamStateMachine, createPlayerInstances, teamSMData)
{
    conversionSharedPtr convert;
    playerEntityMSharedPtr playerInstance;
    setupPlayers setupPlayer;
    std::string func = "teamStateMachine::createPlayerInstances";
    logMsg(func +" begin");
//    exit(0);
    playerInstance = setupPlayer.createTeamPlayerInstances(data->gamePlayerInstance, data->tData->getID());
    logMsg(func +" playerInstance.size() == " +convert->toString(playerInstance.size()));
    exit(0);
    if (playerInstance.size() > 0)
    {
        logMsg(func +" " +data->tData->getCity() +" " +data->tData->getName() + " Player Instances Created!");
        data->flag->setPlayerInstancesCreated(true);
        data->component->setPlayerInstance(playerInstance);
//        returnType = true;
    }
    else
    {
        logMsg(func +" Unable to Create " +data->tData->getCity() +" " +data->tData->getName() + " Player Instances!");
    }
    // perform the stop motor processing here
    // transition to Idle via an internal event
    internalEvent(ST_IDLE);
    
}


