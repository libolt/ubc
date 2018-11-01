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
    stateMachineInitialized = false;
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
    setupComplete = false;
    inputReceived = false;   
    basketballModelLoaded = false;
    courtModelLoaded = false;
    hoopModelLoaded = false;
    modelsLoaded = false;
    basketballNodeCreated = false;
    courtNodeCreated = false;
    hoopNodeCreated = false;
    nodesCreated = false;
    basketballStartPositionSet = false;
    courtStartPositionSet = false;
    hoopStartPositionSet = false;
    startPositionsSet = false;
    setupEnvironmentCompleted = false;
    courtDataLoaded = false;
    gameStarted = false;
    jumpBallCreated = false;
    jumpBallSetup = false;
    jumpBallExecuteComplete = false;
    tipOffSetupComplete = false;
    sceneCreated = false;
    finished = false;
    tipOffComplete = false;
    
}

gameFlags::~gameFlags()  // destructor
{
    
}

bool gameFlags::getInitialized() const  // retrieves the value of initialized
{
    return (initialized);
}
void gameFlags::setInitialized(const bool &set)  // sets the value of initialized
{
    initialized = set;
}

bool gameFlags::getStateMachineInitialized() const  // retrieves the value of initialized
{
    return (stateMachineInitialized);
}
void gameFlags::setStateMachineInitialized(const bool &set)  // sets the value of initialized
{
    stateMachineInitialized = set;
}

bool gameFlags::getActiveBasketballInstancesCreated() const  // retrieves the value of activeBasketballInstancesCreated
{
    return (activeBasketballInstancesCreated);
}

void gameFlags::setActiveBasketballInstancesCreated(const bool &set)  // sets the value of activeBasketballInstancesCreated
{
    activeBasketballInstancesCreated = set;
}

bool gameFlags::getActiveCourtInstancesCreated() const  // retrieves the value of activeCourtInstancesCreated
{
    return (activeCourtInstancesCreated);
}
void gameFlags::setActiveCourtInstancesCreated(const bool $set)  // sets the value of activeCourtInstancesCreated
{
    activeCourtInstancesCreated = $set;
}

bool gameFlags::getActiveHoopInstancesCreated() const    // retrieves the value of activeHoopInstancesCreated
{
    return (activeHoopInstancesCreated);
}
void gameFlags::setActiveHoopInstancesCreated(const bool &set)    // sets the value of activeHoopInstancesCreated
{
    activeHoopInstancesCreated = set;
}

bool gameFlags::getActiveTeamInstancesCreated() const  // retrieves the value of activeTeamInstancesCreated
{
    return (activeTeamInstancesCreated);
}
void gameFlags::setActiveTeamInstancesCreated(const bool &set)  // sets the value of activeTeamInstancesCreated
{
    activeTeamInstancesCreated = set;
}

bool gameFlags::getActiveTeamInstancesSetup() const  // retrieves the value of activeTeamInstancesSetup
{
    return (activeTeamInstancesSetup);
}
void gameFlags::setActiveTeamInstancesSetup(const bool &set)  // sets the value of activeTeamInstancesSetup
{
    activeTeamInstancesSetup = set;
}

bool gameFlags::getBasketballInstanceCreated() const  // gets the value of basketballInstanceCreated
{
    return (basketballInstanceCreated);
}
void gameFlags::setBasketballInstanceCreated(const bool &set)  // sets the value of basketballInstanceCreated
{
    basketballInstanceCreated = set;
}

bool gameFlags::getBasketballInstanceNeedCreated() const  // gets the value of basketballInstanceNeedCreated
{
    return (basketballInstanceNeedCreated);
}
void gameFlags::setBasketballInstanceNeedCreated(const bool &set)  // sets the value of basketballInstanceNeedCreated
{
    basketballInstanceNeedCreated = set;
}

bool gameFlags::getCourtInstancesCreated() const  // gets the value of the courtInstancesCreated
{
    return (courtInstancesCreated);
}
void gameFlags::setCourtInstancesCreated(const bool &set)  // sets the value of the courtInstancesCreated
{
    courtInstancesCreated = set;
}

bool gameFlags::getCourtInstancesNeedCreated() const  // gets the value of the courtInstancesNeedCreated
{
    return (courtInstancesNeedCreated);
}
void gameFlags::setCourtInstancesNeedCreated(const bool &set)  // sets the value of the courtInstancesNeedCreated
{
    courtInstancesNeedCreated = set;
}

bool gameFlags::getHoopInstancesCreated() const  // retrieves the value of hoopInstancesCreated
{
    return (hoopInstancesCreated);
}
void gameFlags::setHoopInstancesCreated(const bool &set)  // sets the value of hoopInstancesCreated
{
    hoopInstancesCreated = set;
}

bool gameFlags::getHoopInstanceNeedCreated() const  // retrieves the value of hoopInstancesNeedCreated
{
    return (hoopInstancesNeedCreated);
}
void gameFlags::setHoopInstanceNeedCreated(const bool &set)  // sets the value of hoopInstancesNeedCreated
{
    hoopInstancesNeedCreated = set;
}

bool gameFlags::getPlayerInstanceCreated() const  // retrieves the value of playerInstanceCreated
{
    return (playerInstanceCreated);
}
void gameFlags::setPlayerInstanceCreated(const bool &set)  // sets the value of playerInstanceCreated
{
    playerInstanceCreated = set;
}

bool gameFlags::getPlayerInstanceNeedCreated() const  // retrieves the value of playerInstanceNeedCreated
{
    return (playerInstanceNeedCreated);
}
void gameFlags::setPlayerInstanceNeedCreated(const bool &set)  // sets the value of playerInstanceNeedCreated
{
    playerInstanceNeedCreated = set;
}

bool gameFlags::getTeamInstancesCreated() const  // gets the value of teamInstancesCreated
{
    return (teamInstancesCreated);
}
void gameFlags::setTeamInstancesCreated(const bool &set)  // sets the value of teamInstancesCreated
{
    teamInstancesCreated = set;
}

bool gameFlags::getBBallNodePositionChanged() const  // retrieves the value of bballNodePositionChanged
{
    return (bballNodePositionChanged);
}
void gameFlags::setBBallNodePositionChanged(const bool &set)  // sets the value of bballNodePositionChanged
{
    bballNodePositionChanged = set;
}

bool gameFlags::getTeamWithBallChanged() const  // retrieves the value of bballNodePositionChanged
{
    return (teamWithBallChanged);
}
void gameFlags::setTeamWithBallChanged(const bool &set)  // sets the value of teamWithBallChanged
{
    teamWithBallChanged = set;
}

bool gameFlags::getActiveTeamInstanceChanged() const  // retrieves the value of activeTeamInstanceChanged
{
    return (activeTeamInstanceChanged);
}
void gameFlags::setActiveTeamInstanceChanged(const bool &set)  // sets the value of activeTeamInstanceChanged
{
    activeTeamInstanceChanged = set;
}

bool gameFlags::getSetupComplete() const  // retrieves the value of setupComplete
{
    return (setupComplete);
}
void gameFlags::setSetupComplete(const bool &set)  // sets the value of setupComplete
{
    setupComplete = set;
}

bool gameFlags::getJumpBallCreated() const  // retrieves the value of jumpBallCreated
{
    return (jumpBallCreated);
}

void gameFlags::setJumpBallCreated(const bool &set)  // sets the value of jumpBallCreated
{
    jumpBallCreated = set;
}

bool gameFlags::getJumpBallSetup() const  // retrieves the value of jumpBallSetup
{
    return (jumpBallSetup);
}
void gameFlags::setJumpBallSetup(const bool &set)  // sets the value of jumpBallSetup
{
    jumpBallSetup = set;
}

bool gameFlags::getJumpBallExecuteComplete() const  // retrieves the value of jumpBallExecuteComplete
{
    return (jumpBallExecuteComplete);
}
void gameFlags::setJumpBallExecuteComplete(const bool &set)  // sets the value of jumpBallExecuteComplete
{
    jumpBallExecuteComplete = set;
}

bool gameFlags::getTipOffComplete() const  // retrieves the value of tipOffComplete
{
    return (tipOffComplete);
}
void gameFlags::setTipOffComplete(const bool &set)  // sets the value of tipOffComplete
{
    tipOffComplete = set;
}

bool gameFlags::getGameStarted() const  // retrieves the value of gameStarted
{
    return(gameStarted);
}
void gameFlags::setGameStarted(const bool &set)  // sets the value of gameStarted
{
    gameStarted = set;
}

bool gameFlags::getTipOffSetupComplete() const  // retrieves the value of tipOffSetupComplete
{
    return (tipOffSetupComplete);
}
void gameFlags::setTipOffSetupComplete(const bool &set)  // sets the value of tipOffSetupComplete
{
    tipOffSetupComplete = set;
}

bool gameFlags::getCourtDataLoaded() const  // retrieves the value of courtDataLoaded
{
    return (courtDataLoaded);
}
void gameFlags::setCourtDataLoaded(const bool &set)  // sets the value of courtDataLoaded
{
    courtDataLoaded = set;
}

bool gameFlags::getBasketballModelLoaded() const  // retrieves the value of basketballModelLoaded
{
    return (basketballModelLoaded);
}
void gameFlags::setBasketballModelLoaded(const bool &set)  // sets the value of basketballModelLoaded
{
    basketballModelLoaded = set;
}

bool gameFlags::getCourtModelLoaded() const  // retrieves the value of courtModelLoaded
{
    return (courtModelLoaded);
}
void gameFlags::setCourtModelLoaded(const bool &set)  // sets the value of courtModelLoaded
{
    courtModelLoaded = set;
}

bool gameFlags::getHoopModelLoaded() const  // retrieves the value of hoopModelLoaded
{
    return (hoopModelLoaded);
}
void gameFlags::setHoopModelLoaded(const bool &set)  // sets the value of hoopModelLoaded
{
    hoopModelLoaded = set;
}

bool gameFlags::getModelsLoaded() const  // retrieves the value of modelsLoaded
{
    return (modelsLoaded);
}
void gameFlags::setModelsLoaded(const bool &set)  // sets the value of modelsLoaded
{
    modelsLoaded = set;
}

bool gameFlags::getBasketballNodeCreated() const  // retrieves the value of basketballNodeCreated
{
    return (basketballNodeCreated);
}
void gameFlags::setBasketballNodeCreated(const bool &set)  // sets the value of basketballNodeCreated
{
    basketballNodeCreated = set;
}

bool gameFlags::getCourtNodeCreated() const  // retrieves the value of courtNodeCreated
{
    return (courtNodeCreated);
}
void gameFlags::setCourtNodeCreated(const bool &set)  // sets the value of courtNodeCreated
{
    courtNodeCreated = set;
}

bool gameFlags::getHoopNodeCreated() const  // retrieves the value of hoopNodeCreated
{
    return(hoopNodeCreated);
}
void gameFlags::setHoopNodeCreated(const bool &set)  // sets the value of hoopNodeCreated
{
    hoopNodeCreated = set;
}

bool gameFlags::getNodesCreated() const  // retrieves the value of nodesCreated
{
    return(nodesCreated);
}
void gameFlags::setNodesCreated(const bool &set)  // sets the value of nodesCreated
{
    nodesCreated = set;
}

bool gameFlags::getBasketballStartPositionSet() const  // retrieves the value of basketballStartPositionSet
{
    return (basketballStartPositionSet);
}
void gameFlags::setBasketballStartPositionSet(const bool &set)  // sets the value of basketballStartPositionSet
{
    basketballStartPositionSet = set;
}

bool gameFlags::getCourtStartPositionSet() const  // retrieves the value of courtStartPositionSet
{
    return (courtStartPositionSet);
}
void gameFlags::setCourtStartPositionSet(const bool &set)  // sets the value of courtStartPositionSet
{
    courtStartPositionSet = set;
}

bool gameFlags::getHoopStartPositionSet() const  // retrieves the value of hoopStartPositionSet
{
    return (hoopStartPositionSet);
}
void gameFlags::setHoopStartPositionSet(const bool &set)  // sets the value of hoopStartPositionSet
{
    hoopStartPositionSet = set;
}

bool gameFlags::getStartPositionsSet() const  // retrieves the value of startPositionsSet
{
    return (startPositionsSet);
}
void gameFlags::setStartPositionsSet(const bool &set)  // sets the value of startPositionsSet
{
    startPositionsSet = set;
}

bool gameFlags::getInputReceived() const  // retrieves the value of inputReceived
{
    return (inputReceived);
}
void gameFlags::setInputReceived(const bool &set)  // sets the value of inputReceived
{
    inputReceived = set;
}

bool gameFlags::getSetupEnvironmentCompleted() const  // retrieves the value of setupEnvironmentCompleted
{
    return(setupEnvironmentCompleted);
}
void gameFlags::setSetupEnvironmentCompleted(const bool &set)  // sets the value of setupEnvironmentCompleted
{
    setupEnvironmentCompleted = set;
}


