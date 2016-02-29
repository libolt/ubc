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

#include "ai/steer.h"

steer::steer()  // constructor
{
    bballNodePositionChanged = false;
    teamWithBallChanged = false;
    activeTeamInstanceChanged = false;
}
steer::~steer()  // destructor
{
    
}
        
// getters and setters
bool steer::getBBallNodePositionChanged()  // retrieves the value of bballNodePositionChanged
{
    return (bballNodePositionChanged);
}
void steer::setBBallNodePositionChanged(bool set)  // sets the value of bballNodePositionChanged
{
    bballNodePositionChanged = set;
}
bool steer::getTeamWithBallChanged()  // retrieves the value of bballNodePositionChanged
{
    return (teamWithBallChanged);
}
void steer::setTeamWithBallChanged(bool set)  // sets the value of teamWithBallChanged
{
    teamWithBallChanged = set;
}
bool steer::getActiveTeamInstanceChanged()  // retrieves the value of activeTeamInstanceChanged
{
    return (activeTeamInstanceChanged);
}
void steer::setActiveTeamInstanceChanged(bool set)  // sets the value of activeTeamInstanceChanged
{
    activeTeamInstanceChanged = set;
}

Ogre::Vector3 steer::getBBallNodePosition()  // retrieves the value of bballNodePosition
{
    return (bballNodePosition);
}
void steer::setBBallNodePosition(Ogre::Vector3 set)  // sets the value of bballNodePosition
{
    bballNodePosition = set;
}

teamTypes steer::getTeamWithBall()  // retrieves the value of teamWithBall
{
    return (teamWithBall);
}
void steer::setTeamWithBall(teamTypes set)  // sets the value of teamWithBall
{
    teamWithBall = set;
}

std::vector<boost::shared_ptr<teamState> > steer::getActiveTeamInstance()  // retrieves the value of activeTeamInstance
{
    return (activeTeamInstance);
}
void steer::setActiveTeamInstance(std::vector<boost::shared_ptr<teamState> > set)  // sets the value of activeTeamInstance
{
    activeTeamInstance = set;
}

std::vector<courtState> steer::getCourtInstance()  // retrieves the value of courtInstance
{
    return (courtInstance);
}
void steer::setCourtInstance(std::vector<courtState> set)  // sets the value of courtInstance
{
    courtInstance = set;
}
