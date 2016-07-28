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

#include "state/hoopstate.h"
#include "engine/renderengine.h"

hoopState::hoopState()  // constructor
{
//    stateSet = false;
}

hoopState::~hoopState()  // destructor
{
}

/*
std::string hoopState::getModelName()  // retrieves the value of modelName
{
    return (modelName);
}
void hoopState::setModelName(std::string set)  // sets the value of modelName
{
    modelName = set;
}

std::string hoopState::getEntityName()  // retrieves the value of entityName
{
    return (entityName);
}
void hoopState::setEntityName(std::string set)  // sets the value of entityName
{
    entityName = set;
}

std::string hoopState::getNodeName()  // retrieves the value of nodeName
{
    return (nodeName);
}
void hoopState::setNodeName(std::string set)  // sets the value of nodeName
{
    nodeName = set;
}

Ogre::Entity *hoopState::getModel()  // retrieves the value of model
{
    return (model);
}
void hoopState::setModel(Ogre::Entity *set)  // sets the value of model
{
    model = set;
}

Ogre::SceneNode *hoopState::getNode()  // retrieves the value of node
{
    return (node);
}
void hoopState::setNode(Ogre::SceneNode *set)  // sets the value of node
{
    node = set;
}

btRigidBody *hoopState::getPhysBody()  // retrieves physBody variable
{
    return (physBody);
}

void hoopState::setPhysBody(btRigidBody *set)	// sets physBody variable
{
    physBody = set;
}

bool hoopState::getStateSet()  // retrieves the value of stateSet
{
    return (stateSet);
}
void hoopState::setStateSet(bool set)  // sets the value of stateSet
{
    stateSet = set;
}

bool hoopState::loadModel()  // loads the 3D Model and attaches it to the node as well as sets coordinates
{
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

    model = render->getMSceneMgr()->createEntity(entityName, modelName);  // loads the hoop model

    // creates the hoopNode
    node = render->getMSceneMgr()->getRootSceneNode()->createChildSceneNode(nodeName);

    // attaches the hoop model to the hoopNode
    node->attachObject(model);
    // sets the position of hoopNode
//    node->setPosition(0.0f,-20.0f,400.0f);
    node->setScale(0.8f,0.8f,0.8f);

    return true;
}
*/
