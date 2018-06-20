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

#include "data/gamedata.h"

gameData::gameData()  // constructor
{
    numActiveHoops = 2;
    bballBounce = -1;
    gameTimeLeft = 0.0f;
    quarterTimeLeft = 0.0f;
    selectedCourtDataInstance = -1;
    quarter = NOQUARTER;
    numActiveBasketballs = 0;
    yOffset = 0.0;
    teamWithBall = NOTEAM;
    gameType = NOGAME;

}
gameData::~gameData()  // destructor
{
    
}

size_t gameData::getSelectedCourtDataInstance()  // retrieves the value of selectedCourtDataInstance
{
    return (selectedCourtDataInstance);
}
void gameData::setSelectedCourtDataInstance(size_t set)  // sets the value of selectedCourtDataInstance
{
    selectedCourtDataInstance = set;
}

sizeTVec gameData::getPlayerID()  // retrieves the value of playerID
{
    return (playerID);
}
void gameData::setPlayerID(sizeTVec set)  // sets the value of playerID
{
    playerID = set;
}

size_t gameData::getBballBounce()  // retrieves the value of bballBounce
{
    return (bballBounce);
}
void gameData::setBballBounce(size_t set)  // sets the value of bballBounce
{
    bballBounce = set;
}

gameTypes gameData::getGameType()  // retrieves the value of gameType
{
    return(gameType);
}
void gameData::setGameType(gameTypes set)  // sets the value of gameType
{
    gameType = set;
}

quarters gameData::getQuarter()  // retrieves the value of quarter
{
    return (quarter);
}
void gameData::setQuarter(quarters set)  // sets the value of quarter
{
    quarter = set;
}

size_t gameData::getNumActiveBasketballs()  // retrieves the value of numActiveBasketballs
{
    return (numActiveBasketballs);
}
void gameData::setNumActiveBasketballs(size_t set)  // sets the value of numActiveBasketballs
{
    numActiveBasketballs = set;
}

sizeTVec gameData::getTeamIDS()  // retrieves the value of teamIDS
{
    return (teamIDS);
}
void gameData::setTeamIDS(sizeTVec set)  // sets the value of teamIDS
{
    teamIDS = set;
}

teamStarterIDsVecM gameData::getTeamStarterID()  // retrieves value of teamStarterID
{
    return (teamStarterID);
}
void gameData::setTeamStarterID(teamStarterIDsVecM set)  // sets the value of teamStarterID
{
    teamStarterID = set;
}

Ogre::Vector3 gameData::getBBallNodePosition()  // retrieves the value of bballNodePosition
{
    return (bballNodePosition);
}
void gameData::setBBallNodePosition(Ogre::Vector3 set)  // sets the value of bballNodePosition
{
    bballNodePosition = set;
}

teamTypes gameData::getTeamWithBall()  // retrieves the value of teamWithBall
{
    return (teamWithBall);
}
void gameData::setTeamWithBall(teamTypes set)  // sets the value of teamWithBall
{
    teamWithBall = set;
}

float gameData::getYOffset()  // returns the value of yOffset
{
    return (yOffset);
}
void gameData::setYOffset(float set)  // sets the value of yOffset
{
    yOffset = set;
}

std::vector<bool> gameData::getTeamActivePlayersChanged()  // retrieves the value of teamActivePlayersChanged
{
    return (teamActivePlayersChanged);
}
void gameData::setTeamActivePlayersChanged(std::vector<bool> set)  // sets the value of teamActivePlayersChanged
{
    teamActivePlayersChanged = set;
}


