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

#include "offenseplays.h"

std::string offensePlays::getPlayName()	 // retrieves the value of playName
{
    return (playName);
}
void offensePlays::setPlayName(std::string set)  // sets the value of playName
{
    playName = set;
}

int offensePlays::getVariation()  // retrieves the value of variation
{
    return (variation);
}
void offensePlays::setVariation(int set)  // sets the value of variation
{
    variation = set;
}

std::string offensePlays::getTitle()  // retrieves the value of title
{
    return (title);
}
void offensePlays::setTitle(std::string set)	// sets the value of title
{
    title = set;
}

std::vector<playerPositions> offensePlays::getPlayerPosition()	// retrieves the value of playerPosition
{
    return (playerPosition);
}
void offensePlays::setPlayerPosition(std::vector<playerPositions> set)  // sets the value of playerPosition
{
    playerPosition = set;
}

std::vector<Ogre::Vector3> offensePlays::getStartPositions()  // retrieves the value of startPositions 
{
    return (startPositions);
}
void offensePlays::setStartPositions(std::vector<Ogre::Vector3> set)  // sets the value of startPositions
{
    startPositions = set;
}

std::vector< std::vector<Ogre::Vector3> > offensePlays::getExecutePositions()  // retrieves the value of startPositions 
{
    return (executePositions);
}
void offensePlays::setExecutePositions(std::vector< std::vector<Ogre::Vector3> > set)  // sets the value of startPositions
{
    executePositions = set;
}

std::vector<bool> offensePlays::getStartPositionSet()  // returns the value of startPositionSet
{
    return (startPositionSet);
}
void offensePlays::setStartPositionSet(std::vector<bool> set) // sets the value of startPositionSet
{
    startPositionSet = set;
}

std::vector< std::vector<bool> > offensePlays::getExecutePositionReached()  // returns the value of executePositionSet
{
    return (executePositionReached);
}
void offensePlays::setExecutePositionReached(std::vector< std::vector<bool> > set)  // sets the value of executePositionSet
{
    executePositionReached = set;
}

std::vector<offensePlays::playerDirectives> offensePlays::getPlayerDirective()  // returns the value of playerDirective
{
    return (playerDirective);
}
void offensePlays::setPlayerDirective(std::vector<offensePlays::playerDirectives> set)  // sets the value of playerDirective
{
    playerDirective = set;
}

playerPositions offensePlays::playerDirectives::getPlayerPosition()  // retrieves the value of playerPosition
{
    return (playerPosition);
}
void offensePlays::playerDirectives::setPlayerPosition(playerPositions set)  // sets the value of playerPosition
{
    playerPosition = set;
}

directiveTypes offensePlays::playerDirectives::getType()  // retrieves the value of type
{
    return (type);
}
void offensePlays::playerDirectives::setType(directiveTypes set)  // sets the value of type
{
    type = set;
}

offenseWaitFor offensePlays::playerDirectives::getWaitFor()  // retrieves the value of waitFor
{
    return (waitFor);
}
void offensePlays::playerDirectives::setWaitFor(offenseWaitFor set)  // sets the value of waitFor
{
    waitFor = set;
}
		
playerPositions offensePlays::playerDirectives::getPlayerSet()  // retrieves the value of playerSet
{
    return (playerSet);
}
void offensePlays::playerDirectives::setPlayerSet(playerPositions set)  // sets the value of playerSet
{
    playerSet = set;
}

positionTypes offensePlays::playerDirectives::getPositionType()  // retrieves the value of positionType
{
    return (positionType);
}
void offensePlays::playerDirectives::setPositionType(positionTypes set)  // sets the value of positionType 
{
    positionType = set;
}

int offensePlays::playerDirectives::getPosition()  // retrieves the value of position
{
    return (position);
}
void offensePlays::playerDirectives::setPosition(int set)  // sets the value of position
{
    position = set;
}
