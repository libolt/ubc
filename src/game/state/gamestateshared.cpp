/***************************************************************************
 *   Copyright (C) 1999 - 2018 by Mike McLean                              *
 *   libolt@libolt.net                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundatioean; either version 2 of the License, or   *
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

#include "entity/playerentity.h"
#include "flags/gameflags.h"
#include "state/basketballstate.h"
#include "state/courtstate.h"
#include "state/gamestateshared.h"
#include "state/hoopstate.h"
#include "state/teamstate.h"

// static declarations
/*bool gameStateShared::initialized;  // if true then tbe object has been initialized
bool gameStateShared::activeBasketballInstancesCreated;  // stores whether the active basketball instances have been created
bool gameStateShared::activeCourtInstancesCreated;  // stores whether the active court instances have been created.
bool gameStateShared::activeHoopInstancesCreated;  // stores whether the active hoop instances have been created
bool gameStateShared::activeTeamInstancesCreated;  // stores whether the active team instances have been created
bool gameStateShared::activeTeamInstancesSetup;  // stores whether or not to setup active team instances
bool gameStateShared::basketballInstanceCreated;  // stores whether basketball instance(s) have been created
bool gameStateShared::basketballInstanceNeedCreated;  // stores whether or not to create basketball instance(s)
bool gameStateShared::courtInstancesCreated;  // stores whether court instances have been created
bool gameStateShared::courtInstancesNeedCreated;  // stores whether or not to create court instances
bool gameStateShared::hoopInstancesCreated;  // stores whether hoop instances have been created
bool gameStateShared::hoopInstancesNeedCreated;  // stores whether or not to create hoop instances
bool gameStateShared::playerInstanceCreated;  // stores whether player instances have been created
bool gameStateShared::playerInstanceNeedCreated;  // stores whether or not to create player instances
bool gameStateShared::teamInstancesCreated;  // stores whether team instances have been created
bool gameStateShared::teamInstancesNeedCreated;  // stores whether or not to create team instances
bool gameStateShared::bballNodePositionChanged;  // stores whether basketball node position has changed
bool gameStateShared::teamWithBallChanged;  // stores whether team with ball has changed
bool gameStateShared::activeTeamInstanceChanged;  // stores whether activeTeamInstance has changed
bool gameStateShared::gameSetupComplete;  // indicates whether initial game setup is complete.
bool gameStateShared::jumpBallCreated;  // indicates whether jumpBall object has been created.
bool gameStateShared::tipOffComplete;  // Determines whether or not game Tip Off has completed


gameTypes gameStateShared::gameType;  // Indicates whether a single or multi player game is being played.
quarters gameStateShared::quarter;  // stores the quarter currently being played
size_t gameStateShared::numActiveBasketballs;  // stores the number of active basketballs in the game.
sizeTVec gameStateShared::teamIDS;  // std::vector that stores the IDs of the 2 teams currently playing
std::vector<std::unordered_map<std::string, size_t> > gameStateShared::teamStarterID;  // stores the selected starters for each team
Ogre::Vector3 gameStateShared::bballNodePosition;  // stores a copy of the basketball node position
teamTypes gameStateShared::teamWithBall;  // store which team has the basketball
//basketballStateMSharedPtr gameStateShared::activeBasketballInstance;  // stores active basketball instance
//courtStateMSharedPtr gameStateShared::activeCourtInstance;  // stores active court instance
//hoopStateMSharedPtr gameStateShared::activeHoopInstance;  // stores active hoop instance
//teamEntityMSharedPtr gameStateShared::activeTeamInstance;  // stores active team instance

//size_t gameStateShared::activeBBallInstance;  // stores which instance of the baskteball class is active
//basketballStateMSharedPtr gameStateShared::basketballInstance;  // creates instance of the basketballs class
//courtStateMSharedPtr gameStateShared::courtInstance;  // stores the court instance
//hoopStateMSharedPtr gameStateShared::hoopInstance;  // creates instance of the hoop class
//playerEntityMSharedPtr gameStateShared::playerInstance;  // stores the vector of the players loaded from the xml files
//teamEntityMSharedPtr  gameStateShared::teamInstance;  // creates instance of the teamState class
jumpBallsSharedPtr gameStateShared::jumpBall; // instance that is used for jumpBall functions.
float gameStateShared::yOffset; // stores the y offset for objects on the screen
std::vector<bool> gameStateShared::teamActivePlayersChanged;  // stores whether the team's active player instances have changed
*/

gameStateShared::gameStateShared()  // constructor
{
/*    initialized = false;
    activeBasketballInstancesCreated = false;
    activeCourtInstancesCreated = false;
    activeHoopInstancesCreated = false;
    activeTeamInstancesCreated = false;
    activeTeamInstancesSetup = false;
    basketballInstanceCreated = false;
    basketballInstanceNeedCreated = false;
    courtInstancesCreated = false;
//    exit(0);
    courtInstancesNeedCreated = false;
    hoopInstancesCreated = false;
    hoopInstancesNeedCreated = false;
    playerInstanceCreated = false;
    playerInstanceNeedCreated = false;
    teamInstancesCreated = false;
    teamInstancesNeedCreated = false;
    bballNodePositionChanged = false;
    teamWithBallChanged = false;
    activeTeamInstanceChanged = false;
    gameSetupComplete = false;
*/


    
}

gameStateShared::~gameStateShared()  // destructor
{
    
}
        
// getters and setters





