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

#include "statemachine/teamstatemachine.h"
#include "components/defensecomponents.h"
#include "components/offensecomponents.h"
#include "components/teamcomponents.h"
#include "data/teamdata.h"
#include "data/teamgamedata.h"
#include "defense/defense.h"
#include "engine/renderengine.h"
#include "flags/defenseflags.h"
#include "flags/offenseflags.h"
#include "flags/teamflags.h"
#include "offense/offense.h"
#include "setup/setupplayers.h"
#include "setup/setupteams.h"
#include "update/updateteams.h"
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
    
    BEGIN_TRANSITION_MAP                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_INIT)      // ST_INIT
        TRANSITION_MAP_ENTRY (ST_INIT)      // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_INIT)      // ST_CREATE_PLAYERINSTANCES
        TRANSITION_MAP_ENTRY (ST_INIT)      // ST_SETUP_PLAYERINSTANCES
        TRANSITION_MAP_ENTRY (ST_INIT)      // ST_SET_PLAYER_START_POSITIONS
        TRANSITION_MAP_ENTRY (ST_INIT)      // ST_SET_PLAYER_START_DIRECTIONS
        TRANSITION_MAP_ENTRY (ST_INIT)      // ST_UPDATE_ACTIVEPLAYERS
        TRANSITION_MAP_ENTRY (ST_INIT)      // ST_EXECUTE_OFFENSE
        TRANSITION_MAP_ENTRY (ST_INIT)      // ST_EXECUTE_DEFENSE
    END_TRANSITION_MAP(data)

}

// Create Player Instances external event
void teamStateMachine::pCreatePlayerInstances(teamSMData *data)
{
    std::string func = "teamStateMachine::pCreatePlayerInstance()";

    logMsg(func +" begin");
//    exit(0);
    BEGIN_TRANSITION_MAP                                      // - Current State -
        TRANSITION_MAP_ENTRY (ST_CREATE_PLAYERINSTANCES)      // ST_INIT
        TRANSITION_MAP_ENTRY (ST_CREATE_PLAYERINSTANCES)      // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_CREATE_PLAYERINSTANCES)      // ST_CREATE_PLAYERINSTANCES
        TRANSITION_MAP_ENTRY (ST_CREATE_PLAYERINSTANCES)      // ST_SETUP_PLAYERINSTANCES
        TRANSITION_MAP_ENTRY (ST_CREATE_PLAYERINSTANCES)      // ST_SET_PLAYER_START_POSITIONS
        TRANSITION_MAP_ENTRY (ST_CREATE_PLAYERINSTANCES)      // ST_SET_PLAYER_START_DIRECTIONS
        TRANSITION_MAP_ENTRY (ST_CREATE_PLAYERINSTANCES)      // ST_UPDATE_ACTIVEPLAYERS
        TRANSITION_MAP_ENTRY (ST_CREATE_PLAYERINSTANCES)      // ST_EXECUTE_OFFENSE
        TRANSITION_MAP_ENTRY (ST_CREATE_PLAYERINSTANCES)      // ST_EXECUTE_DEFENSE
    END_TRANSITION_MAP(data)
}

// Setup Player Instances external event
void teamStateMachine::pSetupPlayerInstances(teamSMData *data)
{
    std::string func = "teamStateMachine::pSetupPlayerInstances()";

    logMsg(func +" begin");
//    exit(0);
    BEGIN_TRANSITION_MAP                                      // - Current State -
        TRANSITION_MAP_ENTRY (ST_SETUP_PLAYERINSTANCES)      // ST_INIT
        TRANSITION_MAP_ENTRY (ST_SETUP_PLAYERINSTANCES)      // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_SETUP_PLAYERINSTANCES)      // ST_CREATE_PLAYERINSTANCES
        TRANSITION_MAP_ENTRY (ST_SETUP_PLAYERINSTANCES)      // ST_SETUP_PLAYERINSTANCES
        TRANSITION_MAP_ENTRY (ST_SETUP_PLAYERINSTANCES)      // ST_SET_PLAYER_START_POSITIONS
        TRANSITION_MAP_ENTRY (ST_SETUP_PLAYERINSTANCES)      // ST_SET_PLAYER_START_DIRECTIONS
        TRANSITION_MAP_ENTRY (ST_SETUP_PLAYERINSTANCES)      // ST_UPDATE_ACTIVEPLAYERS
        TRANSITION_MAP_ENTRY (ST_SETUP_PLAYERINSTANCES)      // ST_EXECUTE_OFFENSE
        TRANSITION_MAP_ENTRY (ST_SETUP_PLAYERINSTANCES)      // ST_EXECUTE_DEFENSE
    END_TRANSITION_MAP(data)
}

// Set Player Start Positions external event
void teamStateMachine::pSetPlayerStartPositions(teamSMData *data)
{
    std::string func = "teamStateMachine::pSetPlayerStartPositions()";

    logMsg(func +" begin");
//    exit(0);
    BEGIN_TRANSITION_MAP                                      // - Current State -
        TRANSITION_MAP_ENTRY (ST_SET_PLAYER_START_POSITIONS)      // ST_INIT
        TRANSITION_MAP_ENTRY (ST_SET_PLAYER_START_POSITIONS)      // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_SET_PLAYER_START_POSITIONS)      // ST_CREATE_PLAYERINSTANCES
        TRANSITION_MAP_ENTRY (ST_SET_PLAYER_START_POSITIONS)      // ST_SETUP_PLAYERINSTANCES
        TRANSITION_MAP_ENTRY (ST_SET_PLAYER_START_POSITIONS)      // ST_SET_PLAYER_START_POSITIONS
        TRANSITION_MAP_ENTRY (ST_SET_PLAYER_START_POSITIONS)      // ST_SET_PLAYER_START_DIRECTIONS
        TRANSITION_MAP_ENTRY (ST_SET_PLAYER_START_POSITIONS)      // ST_UPDATE_ACTIVEPLAYERS
        TRANSITION_MAP_ENTRY (ST_SET_PLAYER_START_POSITIONS)      // ST_EXECUTE_OFFENSE
        TRANSITION_MAP_ENTRY (ST_SET_PLAYER_START_POSITIONS)      // ST_EXECUTE_DEFENSE
    END_TRANSITION_MAP(data)
}

// Set Player Start Positions external event
void teamStateMachine::pSetPlayerStartDirections(teamSMData *data)
{
    std::string func = "teamStateMachine::pSetPlayerStartDirections()";

    logMsg(func +" begin");
//    exit(0);
    BEGIN_TRANSITION_MAP                                      // - Current State -
        TRANSITION_MAP_ENTRY (ST_SET_PLAYER_START_DIRECTIONS)      // ST_INIT
        TRANSITION_MAP_ENTRY (ST_SET_PLAYER_START_DIRECTIONS)      // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_SET_PLAYER_START_DIRECTIONS)      // ST_CREATE_PLAYERINSTANCES
        TRANSITION_MAP_ENTRY (ST_SET_PLAYER_START_DIRECTIONS)      // ST_SETUP_PLAYERINSTANCES
        TRANSITION_MAP_ENTRY (ST_SET_PLAYER_START_DIRECTIONS)      // ST_SET_PLAYER_START_POSITIONS
        TRANSITION_MAP_ENTRY (ST_SET_PLAYER_START_DIRECTIONS)      // ST_SET_PLAYER_START_DIRECTIONS
        TRANSITION_MAP_ENTRY (ST_SET_PLAYER_START_DIRECTIONS)      // ST_UPDATE_ACTIVEPLAYERS
        TRANSITION_MAP_ENTRY (ST_SET_PLAYER_START_DIRECTIONS)      // ST_EXECUTE_OFFENSE
        TRANSITION_MAP_ENTRY (ST_SET_PLAYER_START_DIRECTIONS)      // ST_EXECUTE_DEFENSE
    END_TRANSITION_MAP(data)
}

void teamStateMachine::pUpdateActivePlayers(teamSMData *data)
{
    std::string func = "teamStateMachine::pUpdateActivePlayers()";

    logMsg(func +" begin");
//    exit(0);
    BEGIN_TRANSITION_MAP                                      // - Current State -
        TRANSITION_MAP_ENTRY (ST_UPDATE_ACTIVEPLAYERS)      // ST_INIT
        TRANSITION_MAP_ENTRY (ST_UPDATE_ACTIVEPLAYERS)      // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_UPDATE_ACTIVEPLAYERS)      // ST_CREATE_PLAYERINSTANCES
        TRANSITION_MAP_ENTRY (ST_UPDATE_ACTIVEPLAYERS)      // ST_SETUP_PLAYERINSTANCES
        TRANSITION_MAP_ENTRY (ST_UPDATE_ACTIVEPLAYERS)      // ST_SET_PLAYER_START_POSITIONS
        TRANSITION_MAP_ENTRY (ST_UPDATE_ACTIVEPLAYERS)      // ST_SET_PLAYER_START_DIRECTIONS
        TRANSITION_MAP_ENTRY (ST_UPDATE_ACTIVEPLAYERS)      // ST_UPDATE_ACTIVEPLAYERS
        TRANSITION_MAP_ENTRY (ST_UPDATE_ACTIVEPLAYERS)      // ST_EXECUTE_OFFENSE
        TRANSITION_MAP_ENTRY (ST_UPDATE_ACTIVEPLAYERS)      // ST_EXECUTE_DEFENSE
    END_TRANSITION_MAP(data)
}

void teamStateMachine::pExecuteOffense(teamSMData *data)
{
    std::string func = "teamStateMachine::pExecuteOffense()";

    logMsg(func +" begin");
//    exit(0);
    BEGIN_TRANSITION_MAP                                      // - Current State -
        TRANSITION_MAP_ENTRY (ST_EXECUTE_OFFENSE)      // ST_INIT
        TRANSITION_MAP_ENTRY (ST_EXECUTE_OFFENSE)      // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_EXECUTE_OFFENSE)      // ST_CREATE_PLAYERINSTANCES
        TRANSITION_MAP_ENTRY (ST_EXECUTE_OFFENSE)      // ST_SETUP_PLAYERINSTANCES
        TRANSITION_MAP_ENTRY (ST_EXECUTE_OFFENSE)      // ST_SET_PLAYER_START_POSITIONS
        TRANSITION_MAP_ENTRY (ST_EXECUTE_OFFENSE)      // ST_SET_PLAYER_START_DIRECTIONS
        TRANSITION_MAP_ENTRY (ST_EXECUTE_OFFENSE)      // ST_UPDATE_ACTIVEPLAYERS
        TRANSITION_MAP_ENTRY (ST_EXECUTE_OFFENSE)      // ST_EXECUTE_OFFENSE
        TRANSITION_MAP_ENTRY (ST_EXECUTE_OFFENSE)      // ST_EXECUTE_DEFENSE
    END_TRANSITION_MAP(data)
}

void teamStateMachine::pExecuteDefense(teamSMData *data)
{
    std::string func = "teamStateMachine::pExecuteDefense()";

    logMsg(func +" begin");
//    exit(0);
    BEGIN_TRANSITION_MAP                                      // - Current State -
        TRANSITION_MAP_ENTRY (ST_EXECUTE_DEFENSE)      // ST_INIT
        TRANSITION_MAP_ENTRY (ST_EXECUTE_DEFENSE)      // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_EXECUTE_DEFENSE)      // ST_CREATE_PLAYERINSTANCES
        TRANSITION_MAP_ENTRY (ST_EXECUTE_DEFENSE)      // ST_SETUP_PLAYERINSTANCES
        TRANSITION_MAP_ENTRY (ST_EXECUTE_DEFENSE)      // ST_SET_PLAYER_START_POSITIONS
        TRANSITION_MAP_ENTRY (ST_EXECUTE_DEFENSE)      // ST_SET_PLAYER_START_DIRECTIONS
        TRANSITION_MAP_ENTRY (ST_EXECUTE_DEFENSE)      // ST_UPDATE_ACTIVEPLAYERS
        TRANSITION_MAP_ENTRY (ST_EXECUTE_DEFENSE)      // ST_EXECUTE_OFFENSE
        TRANSITION_MAP_ENTRY (ST_EXECUTE_DEFENSE)      // ST_EXECUTE_DEFENSE
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
//    exit(0);
    if (!playerInstance.empty())
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

    logMsg(func +" end");
    // perform the stop motor processing here
    // transition to Idle via an internal event
    internalEvent(ST_IDLE);
    
}

// creates player instances
STATE_DEFINE(teamStateMachine, setupPlayerInstances, teamSMData)
{
    conversionSharedPtr convert;
    playerEntityMSharedPtr activePlayerInstance = data->component->getActivePlayerInstance();
    setupPlayers setupPlayer;
    std::string func = "teamStateMachine::setupPlayerInstances";
    logMsg(func +" begin");
//    exit(0);
    activePlayerInstance = setupPlayer.setupActivePlayerInstances(activePlayerInstance, data->render);
    if (!activePlayerInstance.empty())
    {
        data->component->setActivePlayerInstance(activePlayerInstance);
        data->flag->setActivePlayerInstancesSetup(true);
    }
    else
    {
        logMsg(func +"Unable to setup playerInstances!");
        exit(0);
    }
    logMsg(func +" end");

}

STATE_DEFINE(teamStateMachine, setPlayerStartPositions, teamSMData)
{
    conversionSharedPtr convert;
    playerEntityMSharedPtr activePlayerInstance = data->component->getActivePlayerInstance();
    setupTeams setupTeam;
    std::string func = "teamStateMachine::setPlayerStartPositions";
    logMsg(func +" begin");
//    exit(0);
    logMsg(func +" Player Start Positions Not Yet Set!");
    logMsg(func +" component->getActivePlayerInstance().size() = " +convert->toString(activePlayerInstance.size()));
            exit(0);
    activePlayerInstance = setupTeam.setPlayerStartPositions(activePlayerInstance, data->courtInstance, data->gData, data->teamStarterID);
//            if (setPlayerStartPositions(activePlayerInstance, gameInstanceComponent->getCourtInstance(), gameInstanceData->getTeamStarterID()))  //   sets starting positions for the players
    if (!activePlayerInstance.empty())
    {
        data->flag->setPlayerStartPositionsSet(true);
        data->component->setActivePlayerInstance(activePlayerInstance);
        logMsg(func +" Player Start Positions set!");
//                exit(0);
    }
    else
    {
        logMsg(func +" Player Start Positions NOT set!");
        exit(0);
    }
    logMsg(func +" end");
//    exit(0);
}

// Set player start positions
STATE_DEFINE(teamStateMachine, setPlayerStartDirections, teamSMData)
{
    conversionSharedPtr convert;
    playerEntityMSharedPtr activePlayerInstance = data->component->getActivePlayerInstance();
    setupTeams setupTeam;
    std::string func = "teamStateMachine::setPlayerStartDirections";
    logMsg(func +" begin");
//    exit(0);

    activePlayerInstance = setupTeam.setPlayerStartDirections(activePlayerInstance, data->gData);
    if (!activePlayerInstance.empty())  // sets starting directions for the players
    {
        data->flag->setPlayerStartDirectionsSet(true);
        data->component->setActivePlayerInstance(activePlayerInstance);
        logMsg(func +" Player Start Directions set!");
//                    exit(0);
    }
    else
    {
        logMsg("Player Start Directions NOT set!");
        exit(0);
    }
    logMsg(func +" end");

}

STATE_DEFINE(teamStateMachine, updateActivePlayers, teamSMData)
{
    conversionSharedPtr convert;
    playerEntityMSharedPtr activePlayerInstance = data->component->getActivePlayerInstance();
    updateTeams updateTeam;
    std::string func = "teamStateMachine::updateActivePlayers";
    logMsg(func +" begin");

    activePlayerInstance = updateTeam.updateActivePlayers(activePlayerInstance, data->render);
    if (!activePlayerInstance.empty())
    {
//        exit(0);
        data->component->setActivePlayerInstance(activePlayerInstance);
    }
    else
    {
        logMsg(func +" Unable to update Active Player Instances!");
        exit(0);
    }

    logMsg(func +" end");
//    exit(0);
}

STATE_DEFINE(teamStateMachine, executeOffense, teamSMData)
{
    conversionSharedPtr convert;
    playerEntityMSharedPtr activePlayerInstance = data->component->getActivePlayerInstance();
    updateTeams updateTeam;
    std::string func = "teamStateMachine::executeOffense";
    logMsg(func +" begin");

    logMsg(func +" offense executing");
//            exit(0);
    data->component->getOffenseInstance()->getFlag()->setExecute(true);
    data->component->getDefenseInstance()->getFlag()->setExecute(false);
    if (data->component->getOffenseInstance()->getComponent()->getTeamType() != data->gData->getTeamType())  // sets type of team for offense
    {
        data->component->getOffenseInstance()->getComponent()->setTeamType(data->gData->getTeamType());
    }

    logMsg(func +" end");

}

STATE_DEFINE(teamStateMachine, executeDefense, teamSMData)
{
    conversionSharedPtr convert;
    playerEntityMSharedPtr activePlayerInstance = data->component->getActivePlayerInstance();
    updateTeams updateTeam;
    std::string func = "teamStateMachine::executeDefense";
    logMsg(func +" begin");
    data->component->getOffenseInstance()->getFlag()->setExecute(false);
    data->component->getDefenseInstance()->getFlag()->setExecute(true);
    if (data->component->getDefenseInstance()->getComponent()->getTeamType() !=  data->gData->getTeamType())  // sets type of team for defense
    {
        data->component->getDefenseInstance()->getComponent()->setTeamType(data->gData->getTeamType());
    }

    logMsg(func +" end");

}
