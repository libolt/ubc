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

#include "components/playercomponents.h"

playerComponents::playerComponents()  // constructor
{
    stateMachine = nullptr;
    physics = nullptr;
    steer = nullptr;
    statistics = nullptr;
}
playerComponents::~playerComponents() = default;  // destructor

playerStateMachineSharedPtr playerComponents::getStateMachine() const  // retrieves the value of stateMachine
{
    return (stateMachine);
}
void playerComponents::setStateMachine(const playerStateMachineSharedPtr &set)  // sets the value of stateMachine
{
    stateMachine = set;
}

playerPhysicsSharedPtr playerComponents::getPhysics() const  // retrieves the value of physics
{
    return (physics);
}
void playerComponents::setPhysics(const playerPhysicsSharedPtr &set)  // sets the value of physics
{
    physics = set;
}

playerSteerSharedPtr playerComponents::getSteer() const  // retrieves the value of steer
{
    return (steer);
}
void playerComponents::setSteer(const playerSteerSharedPtr &set)  // sets the value of steer
{
    steer = set;
}

playerStatisticsSharedPtr playerComponents::getStatistics() const  // retrieves the value of statistics
{
    return (statistics);
}
void playerComponents::setStatistics(const playerStatisticsSharedPtr &set)  // sets the value of statistics
{
    statistics = set;
}


