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

#include "components/entitycomponents.h"
#include "physics/basketballphysics.h"

entityComponents::entityComponents()  // constructor
{
    ID = 0;
}

entityComponents::~entityComponents() = default;  // destructor

size_t entityComponents::getID() const  // retrieves the value of ID
{
    return (ID);
}
void entityComponents::setID(const size_t &set)  // sets the value of ID
{
    ID = set;
}

std::string entityComponents::getModelFileName() const  // retrieves the value of modelFileName
{
    return (modelFileName);
}
void entityComponents::setModelFileName(const std::string &set)  // sets the value of modelFileName
{
    modelFileName = set;
}

std::string entityComponents::getName() const  // retrieves the value of name
{
    return (name);
}
void entityComponents::setName(const std::string &set)  // sets the value of name
{
    name = set;
}

std::string entityComponents::getNodeName() const  // retrieves the value of nodeName
{
    return (nodeName);
}
void entityComponents::setNodeName(const std::string &set)  // sets the value of nodeName
{
    nodeName = set;
}

OgreEntitySharedPtr entityComponents::getModel() const  // retrieves the value of model
{
    return (model);
}
 void entityComponents::setModel(const OgreEntitySharedPtr &set)  // sets the value of model
{
    
    model = set;
}

OgreSceneNodeSharedPtr entityComponents::getNode() const  // retrieves the value of node
{
    return (node);
}
void entityComponents::setNode(const OgreSceneNodeSharedPtr &set)  // sets the value of node
{
    node = set;
}

Ogre::Vector3 entityComponents::getNodePosition() const  // retrieves the value of nodePosition
{
    return (nodePosition);
}
void entityComponents::setNodePosition(const Ogre::Vector3 &set)  // sets the value of nodePosition
{
    nodePosition = set;
}

