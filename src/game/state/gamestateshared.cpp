/***************************************************************************
 *   Copyright (C) 1999 - 2016 by Mike McLean                              *
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

#include "state/gamestateshared.h"

gameStateShared::gameStateShared()  // constructor
{
    activeTeamInstancesCreated = false;
    activeTeamInstancesNeedCreated = false;
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
}

gameStateShared::~gameStateShared()  // destructor
{
    
}
        
// getters and setters
gameTypes gameStateShared::getGameType()  // retrieves the value of gameType
{
    return(gameType);
}
void gameStateShared::setGameType(gameTypes set)  // sets the value of gameType
{
    gameType = set;
}

std::vector<size_t> gameStateShared::getTeamID()  // retrieves the value of teamID
{
    return (teamID);
}
void gameStateShared::setTeamID(std::vector<size_t> set)  // sets the value of teamID
{
    teamID = set;
}

std::vector< std::vector<size_t> > gameStateShared::getTeamStarterID()  // retrieves value of teamStarterID
{
    return (teamStarterID);
}
void gameStateShared::setTeamStarterID(std::vector< std::vector<size_t> > set)  // sets the value of teamStarterID
{
    teamStarterID = set;
}

bool gameStateShared::getActiveTeamInstancesCreated()  // retrieves the value of activeTeamInstancesCreated
{
    return (activeTeamInstancesCreated);
}

void gameStateShared::setActiveTeamInstancesCreated(bool set)  // sets the value of activeTeamInstancesCreated
{
    activeTeamInstancesCreated = set;
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

bool gameStateShared::getHoopInstancesNeedCreated()  // retrieves the value of hoopInstancesNeedCreated
{
    return (hoopInstancesNeedCreated);
}
void gameStateShared::setHoopInstancesNeedCreated(bool set)  // sets the value of hoopInstancesNeedCreated
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

std::vector<boost::shared_ptr<teamState> > gameStateShared::getActiveTeamInstance()  // retrieves the value of activeTeamInstance
{
    return (activeTeamInstance);
}
void gameStateShared::setActiveTeamInstance(std::vector<boost::shared_ptr<teamState> > set)  // sets the value of activeTeamInstance
{
    activeTeamInstance = set;
}

size_t gameStateShared::getActiveCourtInstance()  // retrieves the value of activeCourtInstance
{
    return (activeCourtInstance);
}
void gameStateShared::setActiveCourtInstance(size_t set)  // sets the value of activeCourtInstance
{
    activeCourtInstance = set;
}

std::vector<courtState> gameStateShared::getCourtInstance()  // retrieves the value of courtInstance
{
    return (courtInstance);
}
void gameStateShared::setCourtInstance(std::vector<courtState> set)  // sets the value of courtInstance
{
    courtInstance = set;
}

std::vector<boost::shared_ptr<playerState> > gameStateShared::getPlayerInstance()  // retrieves the value of playerInstance
{
    return (playerInstance);
}
void gameStateShared::setPlayerInstances(std::vector<boost::shared_ptr<playerState> > set)  // sets the value of playerInstance
{
    playerInstance = set;
}

std::vector<boost::shared_ptr<teamState> > gameStateShared::getTeamInstance()  // retrieves the value of teamInstance
{
    return (teamInstance);
}
void gameStateShared::setTeamInstance(std::vector<boost::shared_ptr<teamState> > set)  // sets the value of teamInstance
{
    teamInstance = set;
}

