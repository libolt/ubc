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
    activePlayerInstancesCreated = false;
    activePlayerInstancesSetup = false;
    activePlayerInstancesChanged = false;
    playerInstancesCreated = false;
    playerStartPositionsSet = false;
    playerStartDirectionsSet = false;
    playerWithBallDribbling = false;
    humanControlled = false;
    stateMachineInitialized = false;

}
teamFlags::~teamFlags()  // destructor
{
    
}

bool teamFlags::getStateMachineInitialized() const  // retrieves the value of stateMachineInitialized
{
    return (stateMachineInitialized);
}
void teamFlags::setStateMachineInitialized(const bool &set)  // sets the value of stateMachineInitialized
{
    stateMachineInitialized = set;
}

bool teamFlags::getActivePlayerInstancesSetup() const  // retrieves the value of activePlayerInstancesSetup
{
    return (activePlayerInstancesSetup);
}
void teamFlags::setActivePlayerInstancesSetup(const bool &set)  // sets the value of activePlayerInstancesSetup
{
    activePlayerInstancesSetup = set;
}

bool teamFlags::getActivePlayerInstancesChanged() const  // retrieves the value of activePlayerInstancesChanged
{
    return (activePlayerInstancesChanged);
}
void teamFlags::setActivePlayerInstancesChanged(const bool &set)  // sets the value of activePlayerInstancesChanged
{
    activePlayerInstancesChanged = set;
}

bool teamFlags::getActivePlayerInstancesCreated() const  // retrieves the value of activePlayerInstancesCreated
{
    return (activePlayerInstancesCreated);
}
void teamFlags::setActivePlayerInstancesCreated(const bool &set)  // sets the value of activePlayerInstancesCreated
{
    activePlayerInstancesCreated = set;
}

bool teamFlags::getPlayerInstancesCreated() const  // retrieves the value of playerInstancesCreated
{
    return (playerInstancesCreated);
}
void teamFlags::setPlayerInstancesCreated(const bool &set)  // sets the value of playerInstancesCreated
{
    playerInstancesCreated = set;
}

bool teamFlags::getPlayerStartPositionsSet() const  // retrieves the value of the playerStartPositionsSet
{
    return (playerStartPositionsSet);
}
void teamFlags::setPlayerStartPositionsSet(const bool &set)  // sets the value of the playerStartPositionsSet
{
    playerStartPositionsSet = set;
}

bool teamFlags::getPlayerStartDirectionsSet() const  // retrieves the value of the playerStartDirectionsSet
{
    return (playerStartDirectionsSet);
}
void teamFlags::setPlayerStartDirectionsSet(const bool &set)  // sets the value of the playerStartDirectionsSet
{
    playerStartDirectionsSet = set;
}

bool teamFlags::getPlayerWithBallDribbling() const  // retrieves the value of playerWithBallDribbling
{
    return (playerWithBallDribbling);
}
void teamFlags::setPlayerWithBallDribbling(const bool &set)  // sets the value of playerWithBallDribbling
{
    playerWithBallDribbling = set;
}

bool teamFlags::getHumanControlled() const  // retrieves the value of humanControlled
{
    return (humanControlled);
}
void teamFlags::setHumanControlled(const bool &set)  // sets the value of humanControlled
{
    humanControlled = set;
}


