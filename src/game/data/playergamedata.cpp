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
#include <algorithm>

#include "data/playergamedata.h"
#include "utilities/typedefs.h"

//#include "OgreVector3.h"

playerGameData::playerGameData()  // constructor
{
    activePosition = NONE;
    courtPosition = Ogre::Vector3(0.0f,0.0f,0.0f);
    posChange = Ogre::Vector3(0.0f,0.0f,0.0f);
    passToPlayer = NONE;
    direction = NODIRECT;
    oldDirection = NODIRECT;
    courtPositionChangedType = NOCHANGE;
}
playerGameData::~playerGameData() = default;  // destructor

playerPositions playerGameData::getActivePosition() const  // retrieves the value of activePosition
{
    return (activePosition);
}
void playerGameData::setActivePosition(const playerPositions &set)  // sets the value of activePosition
{
    activePosition = set;
}

Ogre::Vector3 playerGameData::getCourtPosition() const  // retrieves the value of courtPosition
{
    return (courtPosition);
}
void playerGameData::setCourtPosition(const Ogre::Vector3 &set)  // sets the value of courtPosition
{
    courtPosition = set;
}


std::vector<playerActions> playerGameData::getStateAction() const  // retrieves the value of stateAction
{
    return (stateAction);
}
void playerGameData::setStateAction(const std::vector<playerActions> &set)  // sets the value of stateAction
{
    stateAction = set; 
}

directions playerGameData::getDirection() const  // retrieves the value of direction
{
    return (direction);
}
void playerGameData::setDirection(const directions &set)  // sets the value of direction
{
    direction = set;
}

directions playerGameData::getOldDirection() const  // retrieves the value of oldDirection
{
    return (oldDirection);
}
void playerGameData::setOldDirection(const directions &set)  // sets the value of oldDirection
{
    oldDirection = set;
}

Ogre::Vector3 playerGameData::getPosChange() const  // retrieves the value of posChange
{
    return (posChange);
}
void playerGameData::setPosChange(const Ogre::Vector3 &set)  // sets the value of posChange
{
    posChange = set;
}

playerPositions playerGameData::getPassToPlayer() const  // retrieves the value of passToPlayer
{
    return (passToPlayer);
}
void playerGameData::setPassToPlayer(const playerPositions &set)  // sets the value of passToPlayer
{
    passToPlayer = set;
}

Ogre::Vector3 playerGameData::getJumpBeginPos() const  // retrieves the value of playerJumpBeginPos
{
    return (jumpBeginPos);
}
void playerGameData::setJumpBeginPos(const Ogre::Vector3 &set)  // sets the value of playerJumpBeginPos
{
    jumpBeginPos = set;
}

Ogre::Vector3 playerGameData::getJumpEndPos() const  // retrieves the value of playerJumpEndPos
{
    return (jumpEndPos);
}
void playerGameData::setJumpEndPos(const Ogre::Vector3 &set)  // sets the value of playerJumpEndPos
{
    jumpEndPos = set;
}

Ogre::Vector3 playerGameData::getNewCourtPosition() const  // retrieves the value of newCourtPosition
{
    return (newCourtPosition);
}
void playerGameData::setNewCourtPosition(const Ogre::Vector3 &set)  // sets the value of newCourtPosition
{
    newCourtPosition = set;
}

positionChangedTypes playerGameData::getCourtPositionChangedType() const  // retrieves the value of courtPositionChangedType
{
    return (courtPositionChangedType);
}
void playerGameData::setCourtPositionChangedType(const positionChangedTypes &set)  // sets the value of courtPositionChangedType
{
    courtPositionChangedType = set;
}


