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

#include "flags/teamflags.h"

teamFlags::teamFlags()  // constructor
{

}
teamFlags::~teamFlags()  // destructor
{
    activePlayerInstancesCreated = false;
    activePlayerInstancesSetup = false;
    activePlayerInstancesChanged = false;
    playerInstancesCreated = false;
    playerStartPositionsSet = false;
    playerStartDirectionsSet = false;
    playerWithBallDribbling = false;
    humanControlled = false;
    
}

bool teamFlags::getStateMachineInitialized()  // retrieves the value of stateMachineInitialized
{
    return (stateMachineInitialized);
}
void teamFlags::setStateMachineInitialized(bool set)  // sets the value of stateMachineInitialized
{
    stateMachineInitialized = set;
}

/*bool teamFlags::getOffense()  // returns the value of offense
{
    return (offense);
}
void teamFlags::setOffense(bool set)  // sets the value of offense
{
    offense = set;
}
bool teamFlags::getDefense()  // returns the value of defense
{
    return (defense);
}
void teamFlags::setDefense(bool set)  // sets the value of defense
{
    defense = set;
}*/

bool teamFlags::getActivePlayerInstancesSetup()  // retrieves the value of activePlayerInstancesSetup
{
    return (activePlayerInstancesSetup);
}
void teamFlags::setActivePlayerInstancesSetup(bool set)  // sets the value of activePlayerInstancesSetup
{
    activePlayerInstancesSetup = set;
}

bool teamFlags::getActivePlayerInstancesChanged()  // retrieves the value of activePlayerInstancesChanged
{
    return (activePlayerInstancesChanged);
}
void teamFlags::setActivePlayerInstancesChanged(bool set)  // sets the value of activePlayerInstancesChanged
{
    activePlayerInstancesChanged = set;
}

bool teamFlags::getActivePlayerInstancesCreated()  // retrieves the value of activePlayerInstancesCreated
{
    return (activePlayerInstancesCreated);
}
void teamFlags::setActivePlayerInstancesCreated(bool set)  // sets the value of activePlayerInstancesCreated
{
    activePlayerInstancesCreated = set;
}

bool teamFlags::getPlayerInstancesCreated()  // retrieves the value of playerInstancesCreated
{
    return (playerInstancesCreated);
}
void teamFlags::setPlayerInstancesCreated(bool set)  // sets the value of playerInstancesCreated
{
    playerInstancesCreated = set;
}

bool teamFlags::getPlayerStartPositionsSet()  // retrieves the value of the playerStartPositionsSet
{
    return (playerStartPositionsSet);
}
void teamFlags::setPlayerStartPositionsSet(bool set)  // sets the value of the playerStartPositionsSet
{
    playerStartPositionsSet = set;
}

bool teamFlags::getPlayerStartDirectionsSet()  // retrieves the value of the playerStartDirectionsSet
{
    return (playerStartDirectionsSet);
}
void teamFlags::setPlayerStartDirectionsSet(bool set)  // sets the value of the playerStartDirectionsSet
{
    playerStartDirectionsSet = set;
}

bool teamFlags::getPlayerWithBallDribbling()  // retrieves the value of playerWithBallDribbling
{
    return (playerWithBallDribbling);
}
void teamFlags::setPlayerWithBallDribbling(bool set)  // sets the value of playerWithBallDribbling
{
    playerWithBallDribbling = set;
}

bool teamFlags::getHumanControlled()  // retrieves the value of humanControlled
{
    return (humanControlled);
}
void teamFlags::setHumanControlled(bool set)  // sets the value of humanControlled
{
    humanControlled = set;
}


