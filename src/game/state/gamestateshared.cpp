/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
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
#include "state/basketballstate.h"
#include "state/courtstate.h"
#include "state/gamestateshared.h"
#include "state/hoopstate.h"
#include "state/teamstate.h"

// static declarations
bool gameStateShared::initialized;  // if true then tbe object has been initialized
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
//teamStateMSharedPtr gameStateShared::activeTeamInstance;  // stores active team instance

//size_t gameStateShared::activeBBallInstance;  // stores which instance of the baskteball class is active
//basketballStateMSharedPtr gameStateShared::basketballInstance;  // creates instance of the basketballs class
//courtStateMSharedPtr gameStateShared::courtInstance;  // stores the court instance
//hoopStateMSharedPtr gameStateShared::hoopInstance;  // creates instance of the hoop class
//playerEntityMSharedPtr gameStateShared::playerInstance;  // stores the vector of the players loaded from the xml files
//teamStateMSharedPtr  gameStateShared::teamInstance;  // creates instance of the teamState class
jumpBallsSharedPtr gameStateShared::jumpBall; // instance that is used for jumpBall functions.
float gameStateShared::yOffset; // stores the y offset for objects on the screen
std::vector<bool> gameStateShared::teamActivePlayersChanged;  // stores whether the team's active player instances have changed

gameStateShared::gameStateShared()  // constructor
{
    initialized = false;
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
    quarter = NOQUARTER;
    numActiveBasketballs = 0;
    yOffset = 0.0;
    teamWithBall = NOTEAM;
    jumpBallCreated = false;
    tipOffComplete = false;
//    activeBBallInstance = -1;
    gameType = NOGAME;

    
}

gameStateShared::~gameStateShared()  // destructor
{
    
}
        
// getters and setters

bool gameStateShared::getInitialized()  // retrieves the value of initialized
{
    return (initialized);
}
void gameStateShared::setInitialized(bool set)  // sets the value of initialized
{
    initialized = set;
}

gameTypes gameStateShared::getGameType()  // retrieves the value of gameType
{
    return(gameType);
}
void gameStateShared::setGameType(gameTypes set)  // sets the value of gameType
{
    gameType = set;
}

quarters gameStateShared::getQuarter()  // retrieves the value of quarter
{
    return (quarter);
}
void gameStateShared::setQuarter(quarters set)  // sets the value of quarter
{
    quarter = set;
}

size_t gameStateShared::getNumActiveBasketballs()  // retrieves the value of numActiveBasketballs
{
    return (numActiveBasketballs);
}
void gameStateShared::setNumActiveBasketballs(size_t set)  // sets the value of numActiveBasketballs
{
    numActiveBasketballs = set;
}

sizeTVec gameStateShared::getTeamIDS()  // retrieves the value of teamIDS
{
    return (teamIDS);
}
void gameStateShared::setTeamIDS(sizeTVec set)  // sets the value of teamIDS
{
    teamIDS = set;
}

std::vector<std::unordered_map<std::string, size_t> > gameStateShared::getTeamStarterID()  // retrieves value of teamStarterID
{
    return (teamStarterID);
}
void gameStateShared::setTeamStarterID(std::vector<std::unordered_map<std::string, size_t> > set)  // sets the value of teamStarterID
{
    teamStarterID = set;
}

bool gameStateShared::getActiveBasketballInstancesCreated()  // retrieves the value of activeBasketballInstancesCreated
{
    return (activeBasketballInstancesCreated);
}

void gameStateShared::setActiveBasketballInstancesCreated(bool set)  // sets the value of activeBasketballInstancesCreated
{
    activeBasketballInstancesCreated = set;
}

bool gameStateShared::getActiveCourtInstancesCreated()  // retrieves the value of activeCourtInstancesCreated
{
    return (activeCourtInstancesCreated);
}
void gameStateShared::setActiveCourtInstancesCreated(bool set)  // sets the value of activeCourtInstancesCreated
{
    activeCourtInstancesCreated = set;
}

bool gameStateShared::getActiveHoopInstancesCreated()    // retrieves the value of activeHoopInstancesCreated
{
    return (activeHoopInstancesCreated);
}
void gameStateShared::setActiveHoopInstancesCreated(bool set)    // sets the value of activeHoopInstancesCreated
{
    activeHoopInstancesCreated = set;
}

bool gameStateShared::getActiveTeamInstancesCreated()  // retrieves the value of activeTeamInstancesCreated
{
    return (activeTeamInstancesCreated);
}
void gameStateShared::setActiveTeamInstancesCreated(bool set)  // sets the value of activeTeamInstancesCreated
{
    activeTeamInstancesCreated = set;
}

bool gameStateShared::getActiveTeamInstancesSetup()  // retrieves the value of activeTeamInstancesSetup
{
    return (activeTeamInstancesSetup);
}
void gameStateShared::setActiveTeamInstancesSetup(bool set)  // sets the value of activeTeamInstancesSetup
{
    activeTeamInstancesSetup = set;
}

bool gameStateShared::getBasketballInstanceCreated()  // gets the value of basketballInstanceCreated
{
    return (basketballInstanceCreated);
}
void gameStateShared::setBasketballInstanceCreated(bool set)  // sets the value of basketballInstanceCreated
{
    basketballInstanceCreated = set;
}

bool gameStateShared::getBasketballInstanceNeedCreated()  // gets the value of basketballInstanceNeedCreated
{
    return (basketballInstanceNeedCreated);
}
void gameStateShared::setBasketballInstanceNeedCreated(bool set)  // sets the value of basketballInstanceNeedCreated
{
    basketballInstanceNeedCreated = set;
}

bool gameStateShared::getCourtInstancesCreated()  // gets the value of the courtInstancesCreated
{
    return (courtInstancesCreated);
}
void gameStateShared::setCourtInstancesCreated(bool set)  // sets the value of the courtInstancesCreated
{
    courtInstancesCreated = set;
}

bool gameStateShared::getCourtInstancesNeedCreated()  // gets the value of the courtInstancesNeedCreated
{
    return (courtInstancesNeedCreated);
}
void gameStateShared::setCourtInstancesNeedCreated(bool set)  // sets the value of the courtInstancesNeedCreated
{
    courtInstancesNeedCreated = set;
}

bool gameStateShared::getHoopInstancesCreated()  // retrieves the value of hoopInstancesCreated
{
    return (hoopInstancesCreated);
}
void gameStateShared::setHoopInstancesCreated(bool set)  // sets the value of hoopInstancesCreated
{
    hoopInstancesCreated = set;
}

bool gameStateShared::getHoopInstanceNeedCreated()  // retrieves the value of hoopInstancesNeedCreated
{
    return (hoopInstancesNeedCreated);
}
void gameStateShared::setHoopInstanceNeedCreated(bool set)  // sets the value of hoopInstancesNeedCreated
{
    hoopInstancesNeedCreated = set;
}

bool gameStateShared::getPlayerInstanceCreated()  // retrieves the value of playerInstanceCreated
{
    return (playerInstanceCreated);
}
void gameStateShared::setPlayerInstanceCreated(bool set)  // sets the value of playerInstanceCreated
{
    playerInstanceCreated = set;
}

bool gameStateShared::getPlayerInstanceNeedCreated()  // retrieves the value of playerInstanceNeedCreated
{
    return (playerInstanceNeedCreated);
}
void gameStateShared::setPlayerInstanceNeedCreated(bool set)  // sets the value of playerInstanceNeedCreated
{
    playerInstanceNeedCreated = set;
}

bool gameStateShared::getTeamInstancesCreated()  // gets the value of teamInstancesCreated
{
    return (teamInstancesCreated);
}
void gameStateShared::setTeamInstancesCreated(bool set)  // sets the value of teamInstancesCreated
{
    teamInstancesCreated = set;
}

bool gameStateShared::getBBallNodePositionChanged()  // retrieves the value of bballNodePositionChanged
{
    return (bballNodePositionChanged);
}
void gameStateShared::setBBallNodePositionChanged(bool set)  // sets the value of bballNodePositionChanged
{
    bballNodePositionChanged = set;
}

bool gameStateShared::getTeamWithBallChanged()  // retrieves the value of bballNodePositionChanged
{
    return (teamWithBallChanged);
}
void gameStateShared::setTeamWithBallChanged(bool set)  // sets the value of teamWithBallChanged
{
    teamWithBallChanged = set;
}

bool gameStateShared::getActiveTeamInstanceChanged()  // retrieves the value of activeTeamInstanceChanged
{
    return (activeTeamInstanceChanged);
}
void gameStateShared::setActiveTeamInstanceChanged(bool set)  // sets the value of activeTeamInstanceChanged
{
    activeTeamInstanceChanged = set;
}

bool gameStateShared::getGameSetupComplete()  // retrieves the value of gameSetupComplete
{
    return (gameSetupComplete);
}
void gameStateShared::setGameSetupComplete(bool set)  // sets the value of gameSetupComplete
{
    gameSetupComplete = set;
}

bool gameStateShared::getJumpBallCreated()  // retrieves the value of jumpBallCreated
{
    return (jumpBallCreated);
}

void gameStateShared::setJumpBallCreated(bool set)  // sets the value of jumpBallCreated
{
    jumpBallCreated = set;
}

bool gameStateShared::getTipOffComplete()  // retrieves the value of tipOffComplete
{
    return (tipOffComplete);
}
void gameStateShared::setTipOffComplete(bool set)  // sets the value of tipOffComplete
{
    tipOffComplete = set;
}

Ogre::Vector3 gameStateShared::getBBallNodePosition()  // retrieves the value of bballNodePosition
{
    return (bballNodePosition);
}
void gameStateShared::setBBallNodePosition(Ogre::Vector3 set)  // sets the value of bballNodePosition
{
    bballNodePosition = set;
}

teamTypes gameStateShared::getTeamWithBall()  // retrieves the value of teamWithBall
{
    return (teamWithBall);
}
void gameStateShared::setTeamWithBall(teamTypes set)  // sets the value of teamWithBall
{
    teamWithBall = set;
}

basketballStateMSharedPtr gameStateShared::getActiveBasketballInstance()  // retrieves the value of activeBasketballInstance
{
    return (activeBasketballInstance);
}
void gameStateShared::setActiveBasketballInstance(basketballStateMSharedPtr set)  // sets the value of activeBasketballInstance
{
    activeBasketballInstance = set;
}

courtStateMSharedPtr gameStateShared::getActiveCourtInstance()  // retrieves the value of activeCourtInstance
{
    return (activeCourtInstance);
}
void gameStateShared::setActiveCourtInstance(courtStateMSharedPtr set)  // sets the value of activeCourtInstance
{
    activeCourtInstance = set;
}

hoopStateMSharedPtr gameStateShared::getActiveHoopInstance()  // retrieves the value of activeHoopInstance
{
    return(activeHoopInstance);
}
void gameStateShared::setActiveHoopInstance(hoopStateMSharedPtr set)  // sets the value of activeHoopInstance
{
    activeHoopInstance = set;
}

teamStateMSharedPtr gameStateShared::getActiveTeamInstance()  // retrieves the value of activeTeamInstance
{
    return (activeTeamInstance);
}
void gameStateShared::setActiveTeamInstance(teamStateMSharedPtr set)  // sets the value of activeTeamInstance
{
    activeTeamInstance = set;
}

basketballStateMSharedPtr gameStateShared::getBasketballInstance()  // retrieves the value of basketballInstance
{
    return (basketballInstance);
}
void gameStateShared::setBasketballInstance(basketballStateMSharedPtr set)  // sets the value of basketballInstance
{
    basketballInstance = set;
}

courtStateMSharedPtr gameStateShared::getCourtInstance()  // retrieves the value of courtInstance
{
    return (courtInstance);
}
void gameStateShared::setCourtInstance(courtStateMSharedPtr set)  // sets the value of courtInstance
{
    courtInstance = set;
}

hoopStateMSharedPtr gameStateShared::getHoopInstance()  // retrieves the value of hoopInstance
{
    return (hoopInstance);
}
void gameStateShared::setHoopInstance(hoopStateMSharedPtr set)  // sets the value of hoopInstance
{
    hoopInstance = set;
}

playerEntityMSharedPtr gameStateShared::getPlayerInstance()  // retrieves the value of playerInstance
{
    return (playerInstance);
}
void gameStateShared::setPlayerInstance(playerEntityMSharedPtr set)  // sets the value of playerInstance
{
    playerInstance = set;
}

teamStateMSharedPtr gameStateShared::getTeamInstance()  // retrieves the value of teamInstance
{
    return (teamInstance);
}
void gameStateShared::setTeamInstance(teamStateMSharedPtr set)  // sets the value of teamInstance
{
    teamInstance = set;
}

jumpBallsSharedPtr gameStateShared::getJumpBall()  // retrieves the value of jumpBall
{
    return (jumpBall);
}
void gameStateShared::setJumpBall(jumpBallsSharedPtr set)  // sets the value of jumpBall
{
    jumpBall = set;
    
    
}

float gameStateShared::getYOffset()  // returns the value of yOffset
{
    return (yOffset);
}
void gameStateShared::setYOffset(float set)  // sets the value of yOffset
{
    yOffset = set;
}

std::vector<bool> gameStateShared::getTeamActivePlayersChanged()  // retrieves the value of teamActivePlayersChanged
{
    return (teamActivePlayersChanged);
}
void gameStateShared::setTeamActivePlayersChanged(std::vector<bool> set)  // sets the value of teamActivePlayersChanged
{
    teamActivePlayersChanged = set;
}


