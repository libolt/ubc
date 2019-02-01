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

#include "flags/entityflags.h"

entityFlags::entityFlags()  // constructor
{
    initialized = false;
    physicsSetup = false;
    nameSet = false;
    nodeNameSet = false;
    modelNeedsLoaded = false;
    modelLoaded = false;
    nodeCreated = false;

}

entityFlags::~entityFlags() = default;  // denstructor

bool entityFlags::getPhysicsSetup() const  // retrieves the value of physicsSetup
{
    return (physicsSetup);
}
void entityFlags::setPhysicsSetup(const bool &set)  // sets the value of physicsSetup
{
    physicsSetup = set;
}

bool entityFlags::getInitialized() const  // retrieves the value of initialized
{
    return (initialized);
}
void entityFlags::setInitialized(const bool &set)  // sets the value of initialized
{
    initialized = set;
}

bool entityFlags::getNameSet() const  // retrieves the value of nameSet
{
    return (nameSet);
}
void entityFlags::setNameSet(const bool &set)  // sets the value of nameSet
{
    nameSet = set;
}

bool entityFlags::getNodeNameSet() const  // retrieves the value of nodeNameSet
{
    return(nodeNameSet);
}
void entityFlags::setNodeNameSet(const bool &set)  // sets the value of nodeNameSet
{
    nodeNameSet = set;
}

bool entityFlags::getModelNeedsLoaded() const  // retrieves the value of modelNeedsLoaded
{
    return (modelNeedsLoaded);
}
void entityFlags::setModelNeedsLoaded(const bool &set)  // sets the value of modelNeedsLoaded
{
    modelNeedsLoaded = set;
}

bool entityFlags::getModelLoaded() const  // retrieves the value of modelLoaded
{
    return (modelLoaded);
}
void entityFlags::setModelLoaded(const bool &set)  // sets the value of modelLoaded
{
    modelLoaded = set;
}

bool entityFlags::getNodeCreated() const  // retrieves the value of nodeCreated
{
    return (nodeCreated);
}
void entityFlags::setNodeCreated(const bool &set)  // sets the value of nodeCreated
{
    nodeCreated = set;
}
