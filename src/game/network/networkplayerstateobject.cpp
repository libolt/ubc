/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean                              *
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

#include "networkplayerstateobject.h"

networkPlayerStateObject::networkPlayerStateObject()  // constructor
{
    teamID = -1;
    playerID = -1;
    packetType = -1;
    movement = false;
    direction = -1;
    shootBlock = false;
    passSteal = false;
    XCoord = 0.0;
    YCoord = 0.0;
    ZCoord = 0.0;
}

int networkPlayerStateObject::getTeamID()  // retrieves the value of teamID
{
    return (teamID);
}
void networkPlayerStateObject::setTeamID(int set) // sets the value of teamID
{
    teamID = set;
}

int networkPlayerStateObject::getPlayerID()  // retrieves the value of playerID
{
    return (playerID);
}
void networkPlayerStateObject::setPlayerID(int set)  // sets the value of playerID
{
    playerID = set;
}

int networkPlayerStateObject::getPacketType()  // retrieves the value of packetType
{
    return (packetType);
}
void networkPlayerStateObject::setPacketType(int set)  // sets the value of packetType
{
    packetType = set;
}

bool networkPlayerStateObject::getMovement()  // retrieves the value of movement
{
    return (movement);
}
void networkPlayerStateObject::setMovement(bool set)  // sets the value of movement
{
    movement = set;
}

int networkPlayerStateObject::getDirection()  // retrieves the value of direction
{
    return (direction);
}
void networkPlayerStateObject::setDirection(int set)  // sets value of direction
{
    direction = set;
}

bool networkPlayerStateObject::getShootBlock()  // retrieves the value of shootBlock
{
    return (shootBlock);
}
void networkPlayerStateObject::setShootBlock(bool set)   // sets the value of shootBlock
{
    shootBlock = set;
}
bool networkPlayerStateObject::getPassSteal()  // retrieves the value of passSteal
{
    return (passSteal);
}
void networkPlayerStateObject::setPassSteal(bool set)  // sets the value of passSteal
{
    passSteal = set;
}

float networkPlayerStateObject::getXCoord()  // retrieves the value of XCoord
{
    return (XCoord);
}
void networkPlayerStateObject::setXCoord(float set)  // sets the value of XCoord
{
	XCoord = set;
}

float networkPlayerStateObject::getYCoord()  // retrieves the value of YCoord
{
    return (YCoord);
}
void networkPlayerStateObject::setYCoord(float set)  // sets the value of YCoord
{
    YCoord = set;
}

float networkPlayerStateObject::getZCoord()  // retrieves the value of ZCoord
{
    return (ZCoord);
}
void networkPlayerStateObject::setZCoord(float set)  // sets the value of ZCoord
{
    ZCoord = set;
}
