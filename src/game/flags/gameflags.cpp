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

#include "flags/gameflags.h" 

gameFlags::gameFlags()  // constructor
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
    inputReceived = false;   
    basketballModelLoaded = false;
    courtModelLoaded = false;
    hoopModelLoaded = false;
    modelsLoaded = false;
    nodesCreated = false;
    setupEnvironmentCompleted = false;
    courtDataLoaded = false;
    gameStarted = false;
    tipOffSetupComplete = false;
    sceneCreated = false;
    finished = false;
    
}

gameFlags::~gameFlags()  // destructor
{
    
}

bool gameFlags::getInitialized()  // retrieves the value of initialized
{
    return (initialized);
}
void gameFlags::setInitialized(bool set)  // sets the value of initialized
{
    initialized = set;
}

bool gameFlags::getActiveBasketballInstancesCreated()  // retrieves the value of activeBasketballInstancesCreated
{
    return (activeBasketballInstancesCreated);
}

void gameFlags::setActiveBasketballInstancesCreated(bool set)  // sets the value of activeBasketballInstancesCreated
{
    activeBasketballInstancesCreated = set;
}

bool gameFlags::getActiveCourtInstancesCreated()  // retrieves the value of activeCourtInstancesCreated
{
    return (activeCourtInstancesCreated);
}
void gameFlags::setActiveCourtInstancesCreated(bool set)  // sets the value of activeCourtInstancesCreated
{
    activeCourtInstancesCreated = set;
}

bool gameFlags::getActiveHoopInstancesCreated()    // retrieves the value of activeHoopInstancesCreated
{
    return (activeHoopInstancesCreated);
}
void gameFlags::setActiveHoopInstancesCreated(bool set)    // sets the value of activeHoopInstancesCreated
{
    activeHoopInstancesCreated = set;
}

bool gameFlags::getActiveTeamInstancesCreated()  // retrieves the value of activeTeamInstancesCreated
{
    return (activeTeamInstancesCreated);
}
void gameFlags::setActiveTeamInstancesCreated(bool set)  // sets the value of activeTeamInstancesCreated
{
    activeTeamInstancesCreated = set;
}

bool gameFlags::getActiveTeamInstancesSetup()  // retrieves the value of activeTeamInstancesSetup
{
    return (activeTeamInstancesSetup);
}
void gameFlags::setActiveTeamInstancesSetup(bool set)  // sets the value of activeTeamInstancesSetup
{
    activeTeamInstancesSetup = set;
}

bool gameFlags::getBasketballInstanceCreated()  // gets the value of basketballInstanceCreated
{
    return (basketballInstanceCreated);
}
void gameFlags::setBasketballInstanceCreated(bool set)  // sets the value of basketballInstanceCreated
{
    basketballInstanceCreated = set;
}

bool gameFlags::getBasketballInstanceNeedCreated()  // gets the value of basketballInstanceNeedCreated
{
    return (basketballInstanceNeedCreated);
}
void gameFlags::setBasketballInstanceNeedCreated(bool set)  // sets the value of basketballInstanceNeedCreated
{
    basketballInstanceNeedCreated = set;
}

bool gameFlags::getCourtInstancesCreated()  // gets the value of the courtInstancesCreated
{
    return (courtInstancesCreated);
}
void gameFlags::setCourtInstancesCreated(bool set)  // sets the value of the courtInstancesCreated
{
    courtInstancesCreated = set;
}

bool gameFlags::getCourtInstancesNeedCreated()  // gets the value of the courtInstancesNeedCreated
{
    return (courtInstancesNeedCreated);
}
void gameFlags::setCourtInstancesNeedCreated(bool set)  // sets the value of the courtInstancesNeedCreated
{
    courtInstancesNeedCreated = set;
}

bool gameFlags::getHoopInstancesCreated()  // retrieves the value of hoopInstancesCreated
{
    return (hoopInstancesCreated);
}
void gameFlags::setHoopInstancesCreated(bool set)  // sets the value of hoopInstancesCreated
{
    hoopInstancesCreated = set;
}

bool gameFlags::getHoopInstanceNeedCreated()  // retrieves the value of hoopInstancesNeedCreated
{
    return (hoopInstancesNeedCreated);
}
void gameFlags::setHoopInstanceNeedCreated(bool set)  // sets the value of hoopInstancesNeedCreated
{
    hoopInstancesNeedCreated = set;
}

bool gameFlags::getPlayerInstanceCreated()  // retrieves the value of playerInstanceCreated
{
    return (playerInstanceCreated);
}
void gameFlags::setPlayerInstanceCreated(bool set)  // sets the value of playerInstanceCreated
{
    playerInstanceCreated = set;
}

bool gameFlags::getPlayerInstanceNeedCreated()  // retrieves the value of playerInstanceNeedCreated
{
    return (playerInstanceNeedCreated);
}
void gameFlags::setPlayerInstanceNeedCreated(bool set)  // sets the value of playerInstanceNeedCreated
{
    playerInstanceNeedCreated = set;
}

bool gameFlags::getTeamInstancesCreated()  // gets the value of teamInstancesCreated
{
    return (teamInstancesCreated);
}
void gameFlags::setTeamInstancesCreated(bool set)  // sets the value of teamInstancesCreated
{
    teamInstancesCreated = set;
}

bool gameFlags::getBBallNodePositionChanged()  // retrieves the value of bballNodePositionChanged
{
    return (bballNodePositionChanged);
}
void gameFlags::setBBallNodePositionChanged(bool set)  // sets the value of bballNodePositionChanged
{
    bballNodePositionChanged = set;
}

bool gameFlags::getTeamWithBallChanged()  // retrieves the value of bballNodePositionChanged
{
    return (teamWithBallChanged);
}
void gameFlags::setTeamWithBallChanged(bool set)  // sets the value of teamWithBallChanged
{
    teamWithBallChanged = set;
}

bool gameFlags::getActiveTeamInstanceChanged()  // retrieves the value of activeTeamInstanceChanged
{
    return (activeTeamInstanceChanged);
}
void gameFlags::setActiveTeamInstanceChanged(bool set)  // sets the value of activeTeamInstanceChanged
{
    activeTeamInstanceChanged = set;
}

bool gameFlags::getGameSetupComplete()  // retrieves the value of gameSetupComplete
{
    return (gameSetupComplete);
}
void gameFlags::setGameSetupComplete(bool set)  // sets the value of gameSetupComplete
{
    gameSetupComplete = set;
}

bool gameFlags::getJumpBallCreated()  // retrieves the value of jumpBallCreated
{
    return (jumpBallCreated);
}

void gameFlags::setJumpBallCreated(bool set)  // sets the value of jumpBallCreated
{
    jumpBallCreated = set;
}

bool gameFlags::getTipOffComplete()  // retrieves the value of tipOffComplete
{
    return (tipOffComplete);
}
void gameFlags::setTipOffComplete(bool set)  // sets the value of tipOffComplete
{
    tipOffComplete = set;
}

bool gameFlags::getGameStarted()  // retrieves the value of gameStarted
{
    return(gameStarted);
}
void gameFlags::setGameStarted(bool set)  // sets the value of gameStarted
{
    gameStarted = set;
}

bool gameFlags::getTipOffSetupComplete()  // retrieves the value of tipOffSetupComplete
{
    return (tipOffSetupComplete);
}
void gameFlags::setTipOffSetupComplete(bool set)  // sets the value of tipOffSetupComplete
{
    tipOffSetupComplete = set;
}

bool gameFlags::getCourtDataLoaded()  // retrieves the value of courtDataLoaded
{
    return (courtDataLoaded);
}
void gameFlags::setCourtDataLoaded(bool set)  // sets the value of courtDataLoaded
{
    courtDataLoaded = set;
}

bool gameFlags::getModelsLoaded()  // retrieves the value of modelsLoaded
{
    return (modelsLoaded);
}
void gameFlags::setModelsLoaded(bool set)  // sets the value of modelsLoaded
{
    modelsLoaded = set;
}

bool gameFlags::getNodesCreated()  // retrieves the value of nodesCreated
{
    return(nodesCreated);
}
void gameFlags::setNodesCreated(bool set)  // sets the value of nodesCreated
{
    nodesCreated = set;
}

bool gameFlags::getInputReceived()  // retrieves the value of inputReceived
{
    return (inputReceived);
}
void gameFlags::setInputReceived(bool set)  // sets the value of inputReceived
{
    inputReceived = set;
}

bool gameFlags::getSetupEnvironmentCompleted()  // retrieves the value of setupEnvironmentCompleted
{
    returb(setupEnvironmentCompleted);
}
void gameFlags::setSetupEnvironmentCompleted(bool set)  // sets the value of setupEnvironmentCompleted
{
    setupEnvironmentCompleted = set;
}
