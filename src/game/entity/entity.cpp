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

#include "entity/entity.h"
#include "engine/gameengine.h"
#include "engine/renderengine.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"
#include "ubc/ubc.h"

entity::entity()  // constructor
{
    initialized = false;
    nameSet = false;
    nodeNameSet = false;

    ID = 0;
    physicsSetup = false;
    modelNeedsLoaded = false;
    modelLoaded = false;
    nodeCreated = false;
}

entity::~entity()  // destructor
{
    
}

bool entity::getInitialized() const  // retrieves the value of initialized
{
    return (initialized);
}
void entity::setInitialized(const bool &set)  // sets the value of initialized
{
    initialized = set;
}

bool entity::getNameSet() const  // retrieves the value of nameSet
{
    return (nameSet);
}
void entity::setNameSet(const bool &set)  // sets the value of nameSet
{
    nameSet = set;
}

bool entity::getNodeNameSet() const  // retrieves the value of nodeNameSet
{
    return(nodeNameSet);
}
void entity::setNodeNameSet(const bool &set)  // sets the value of nodeNameSet
{
    nodeNameSet = set;
}

size_t entity::getID() const  // retrieves the value of ID
{
    return (ID);
}
void entity::setID(const size_t &set)  // sets the value of ID
{
    ID = set;
}

std::string entity::getModelFileName() const  // retrieves the value of modelFileName
{
    return (modelFileName);
}
void entity::setModelFileName(const std::string &set)  // sets the value of modelFileName
{
    modelFileName = set;
}

std::string entity::getName() const  // retrieves the value of name
{
    return (name);
}
void entity::setName(const std::string &set)  // sets the value of name
{
    name = set;
}

std::string entity::getNodeName() const  // retrieves the value of nodeName
{
    return (nodeName);
}
void entity::setNodeName(const std::string &set)  // sets the value of nodeName
{
    nodeName = set;
}

OgreEntitySharedPtr entity::getModel() const  // retrieves the value of model
{
    return (model);
}
 void entity::setModel(const OgreEntitySharedPtr &set)  // sets the value of model
{
    
    model = set;
}

OgreSceneNodeSharedPtr entity::getNode() const  // retrieves the value of node
{
    return (node);
}
void entity::setNode(const OgreSceneNodeSharedPtr &set)  // sets the value of node
{
    node = set;
}

bool entity::getPhysicsSetup() const  // retrieves the value of physicsSetup
{
    return (physicsSetup);
}
void entity::setPhysicsSetup(const bool &set)  // sets the value of physicsSetup
{
    physicsSetup = set;
}

bool entity::getModelNeedsLoaded() const  // retrieves the value of modelNeedsLoaded
{
    return (modelNeedsLoaded);
}
void entity::setModelNeedsLoaded(const bool &set)  // sets the value of modelNeedsLoaded
{
    modelNeedsLoaded = set;
}

bool entity::getModelLoaded() const  // retrieves the value of modelLoaded
{
    return (modelLoaded);
}
void entity::setModelLoaded(const bool &set)  // sets the value of modelLoaded
{
    modelLoaded = set;
}

Ogre::Vector3 entity::getNodePosition() const  // retrieves the value of nodePosition
{
    return (nodePosition);
}
void entity::setNodePosition(const Ogre::Vector3 &set)  // sets the value of nodePosition
{
    nodePosition = set;
}

bool entity::getNodeCreated() const  // retrieves the value of nodeaCreated
{
    return (nodeCreated);
}
void entity::setNodeCreated(const bool $set)  // sets the value of nodeCreated
{
    nodeCreated = $set;
}

