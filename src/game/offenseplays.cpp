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

#include "offenseplays.h"

offensePlays::offensePlays()  // constructor
{
    playName = "";
    variation = 0;
}

offensePlays::~offensePlays() = default;  // destructor

std::string offensePlays::getPlayName() const	 // retrieves the value of playName
{
    return (playName);
}
void offensePlays::setPlayName(const std::string &set)  // sets the value of playName
{
    playName = set;
}

int offensePlays::getVariation() const  // retrieves the value of variation
{
    return (variation);
}
void offensePlays::setVariation(const int &set)  // sets the value of variation
{
    variation = set;
}

std::string offensePlays::getTitle() const  // retrieves the value of title
{
    return (title);
}
void offensePlays::setTitle(const std::string &set)	// sets the value of title
{
    title = set;
}

playerPositionsVec offensePlays::getPlayerPosition() const	// retrieves the value of playerPosition
{
    return (playerPosition);
}
void offensePlays::setPlayerPosition(const playerPositionsVec &set)  // sets the value of playerPosition
{
    playerPosition = set;
}

OgreVector3Vec offensePlays::getStartPositions() const  // retrieves the value of startPositions
{
    return (startPositions);
}
void offensePlays::setStartPositions(const OgreVector3Vec &set)  // sets the value of startPositions
{
    startPositions = set;
}

std::vector< OgreVector3Vec > offensePlays::getExecutePositions() const  // retrieves the value of startPositions
{
    return (executePositions);
}
void offensePlays::setExecutePositions(const std::vector<OgreVector3Vec> &set)  // sets the value of startPositions
{
    executePositions = set;
}

boolVec offensePlays::getStartPositionSet() const  // returns the value of startPositionSet
{
    return (startPositionSet);
}
void offensePlays::setStartPositionSet(const boolVec &set) // sets the value of startPositionSet
{
    startPositionSet = set;
}

std::vector< boolVec > offensePlays::getExecutePositionReached() const  // returns the value of executePositionSet
{
    return (executePositionReached);
}
void offensePlays::setExecutePositionReached(const std::vector<boolVec> &set)  // sets the value of executePositionSet
{
    executePositionReached = set;
}

std::vector<offensePlays::playerDirectives> offensePlays::getPlayerDirective() const  // returns the value of playerDirective
{
    return (playerDirective);
}
void offensePlays::setPlayerDirective(const std::vector<offensePlays::playerDirectives> &set)  // sets the value of playerDirective
{
    playerDirective = set;
}

playerPositions offensePlays::playerDirectives::getPlayerPosition() const  // retrieves the value of playerPosition
{
    return (playerPosition);
}
void offensePlays::playerDirectives::setPlayerPosition(const playerPositions &set)  // sets the value of playerPosition
{
    playerPosition = set;
}

directiveTypes offensePlays::playerDirectives::getType() const  // retrieves the value of type
{
    return (type);
}
void offensePlays::playerDirectives::setType(const directiveTypes &set)  // sets the value of type
{
    type = set;
}

offenseWaitFor offensePlays::playerDirectives::getWaitFor() const  // retrieves the value of waitFor
{
    return (waitFor);
}
void offensePlays::playerDirectives::setWaitFor(const offenseWaitFor &set)  // sets the value of waitFor
{
    waitFor = set;
}
		
playerPositions offensePlays::playerDirectives::getPlayerSet() const  // retrieves the value of playerSet
{
    return (playerSet);
}
void offensePlays::playerDirectives::setPlayerSet(const playerPositions &set)  // sets the value of playerSet
{
    playerSet = set;
}

positionTypes offensePlays::playerDirectives::getPositionType() const  // retrieves the value of positionType
{
    return (positionType);
}
void offensePlays::playerDirectives::setPositionType(const positionTypes &set)  // sets the value of positionType
{
    positionType = set;
}

int offensePlays::playerDirectives::getPosition() const  // retrieves the value of position
{
    return (position);
}
void offensePlays::playerDirectives::setPosition(const int &set)  // sets the value of position
{
    position = set;
}
