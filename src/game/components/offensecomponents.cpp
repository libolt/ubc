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

#include "components/offensecomponents.h"

offenseComponents::offenseComponents()  // constructor
{
    teamType = NOTEAM;
    selectedOffense = -1; // sets the default offense to box
    courtSide = NOSIDE;
    executePositions.resize(5);
    numStartPositionsReached = 0;
}

offenseComponents::~offenseComponents() = default;  // destructor

teamTypes offenseComponents::getTeamType() const  // retrieves the value of teamType
{
    return (teamType);
}
void offenseComponents::setTeamType(const teamTypes &set)  // sets the value of teamType
{
    teamType = set;
}

courtSide_t offenseComponents::getCourtSide() const  // retrieves the value of courtSide
{
    return (courtSide);
}
void offenseComponents::setCourtSide(const courtSide_t &set)  // sets the value of courtSide
{
    courtSide = set;
}

int offenseComponents::getSelectedOffense() const  // returns value of selectedOffense
{
    return (selectedOffense);
}
void offenseComponents::setSelectedOffense(const int &set)  // sets the value of selectedOffense
{
    selectedOffense = set;
}

offensePlaysVecSharedPtr offenseComponents::getPlays() const  // returns the value of plays
{
    return (plays);
}
void offenseComponents::setPlays(const offensePlaysVecSharedPtr &set)  // sets the value of plays
{
    plays = set;
}

OgreVector3Vec offenseComponents::getStartPositions() const  // retrieves the value of startPositions
{
    return (startPositions);
}
void offenseComponents::setStartPositions(const OgreVector3Vec &set)  // sets the value of startPositions
{
    startPositions = set;
}

std::vector< OgreVector3Vec > offenseComponents::getExecutePositions() const  // retrieves the value of startPositions
{
    return (executePositions);
}
void offenseComponents::setExecutePositions(const std::vector<OgreVector3Vec> &set)  // sets the value of startPositions
{
    executePositions = set;
}

std::string offenseComponents::getPlayName() const  // retrieves the value of playName
{
    return (playName);
}
void offenseComponents::setPlayName(const std::string &set)  // sets the value of playName
{
    playName = set;
}

std::string offenseComponents::getPlayTitle() const  // retrieves the value of playTitle
{
    return (playTitle);
}
void offenseComponents::setPlayTitle(const std::string &set)  // sets the value of playTitle
{
    playTitle = set;
}

std::vector<offensePlays::playerDirectives> offenseComponents::getPlayerDirective() const  // retrieves the value of playerDirective
{
    return (playerDirective);
}
void offenseComponents::setPlayerDirective(const std::vector<offensePlays::playerDirectives> &set)  // sets the value of playerDirective
{
    playerDirective = set;
}
