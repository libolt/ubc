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

#include "data/teamgamedata.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

teamGameData::teamGameData()  // constructor
{
    teamType = NOTEAM;
    playerType = ' ';
    playerInstanceCreatedCount = 0;
    playerWithBallInstance = NONE;
    playerWithBallID = -1;
    humanPlayer = 4;
    hoop = -1;

}
teamGameData::~teamGameData()  // destructor
{
    
}

teamTypes teamGameData::getTeamType() const  // retrieves the value of teamType
{
 return (teamType);
}
void teamGameData::setTeamType(const teamTypes &set)  // sets the value of teamType
{
    teamType = set;
}

std::string teamGameData::getPlayerType() const  // retrieves the value of playerType
{
    return (playerType);
}
void teamGameData::setPlayerType(const std::string &set)  // sets the value of playerType
{
    playerType = set;
}


sizeTVec teamGameData::getPlayerID() const  // retrieves the value of playerID
{
    return (playerID);
}
void teamGameData::setPlayerID(const sizeTVec &set)  // sets the value of playerID
{
    playerID = set;
}

sizeTVec teamGameData::getActivePlayerID() const  // retrieves the value of activePlayerID
{
    return (activePlayerID);
}
void teamGameData::setActivePlayerID(const sizeTVec &set)  // sets the value of activePlayerID
{
    activePlayerID = set;
}

sizeTVec teamGameData::getStarterID() const  // retrieves the value of starterID
{
    return (starterID);
}
void teamGameData::setStarterID(const sizeTVec &set)  // sets the value of starterID
{
    logMsg("blap");
    starterID = set;
}

size_t teamGameData::getPlayerWithBallID() const  // retrieves the value of the playerWithBallID
{
    return (playerWithBallID);
}
void teamGameData::setPlayerWithBallID(const size_t &set)  // sets the value of the playerWithBallID
{
    playerWithBallID = set;
}

playerPositions teamGameData::getPlayerWithBallInstance() const  // retrives the value of playerWithBall
{
    return (playerWithBallInstance);
}
void teamGameData::setPlayerWithBallInstance(const playerPositions &set)  // sets the value of playerWithBall
{
    playerWithBallInstance = set;
}

size_t teamGameData::getHumanPlayer() const  // retrieves the value of humanPlayer
{
    return (humanPlayer);
}
void teamGameData::setHumanPlayer(const size_t &set)  // sets the value of humanPlayer
{
    humanPlayer = set;
}

size_t teamGameData::getHoop() const  // retrieves the value of hoop
{
    return (hoop);
}
void teamGameData::setHoop(const size_t &set)  // sets the value of hoop
{
    hoop = set;
}

size_t teamGameData::getTeamColObject() const  // retrieves the value of teamColObject
{
    return (teamColObject);
}
void teamGameData::setTeamColObject(const size_t &set)  // sets the value of teamColObject
{
    teamColObject = set;
}

size_t teamGameData::getTeamCollidesWith() const // retrieves the value of teamCollidesWith
{
    return (teamCollidesWith);
}
void teamGameData::setTeamCollidesWith(const size_t &set)  // sets the value of teamCollidesWith
{
    teamCollidesWith = set;
}


