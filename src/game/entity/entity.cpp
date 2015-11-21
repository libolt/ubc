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

#include "entity.h"
#include "renderengine.h"

entity::entity()  // constructor
{
    modelNeedsLoaded = false;
    modelLoaded = false;
}

entity::~entity()  // destructor
{
    
}

std::string entity::getModelName()  // retrieves the value of modelName
{
    return (modelName);
}
void entity::setModelName(std::string set)  // sets the value of modelName
{
    modelName = set;
}

Ogre::Entity *entity::getModel()  // retrieves the value of model
{
    return (model);
}
 void entity::setModel(Ogre::Entity *set)  // sets the value of model
{
    model = set;
}

Ogre::SceneNode *entity::getNode()  // retrieves the value of node
{
    return (node);
}
void entity::setNode(Ogre::SceneNode *set)  // sets the value of node
{
    node = set;
}

btRigidBody *entity::getPhysBody()  // retrieves physBody variable
{
    return (physBody);
}

void entity::setPhysBody(btRigidBody *set)  // sets physBody variable
{
    physBody = set;
}

bool entity::getModelNeedsLoaded()  // retrieves the value of modelNeedsLoaded
{
    return (modelNeedsLoaded);
}
void entity::setModelNeedsLoaded(bool set)  // sets the value of modelNeedsLoaded
{
    modelNeedsLoaded = set;
}

bool entity::getModelLoaded()  // retrieves the value of modelLoaded
{
    return (modelLoaded);
}
void entity::setModelLoaded(bool set)  // sets the value of modelLoaded
{
    modelLoaded = set;
}

Ogre::Vector3 entity::getNodePosition()  // retrieves position of basketball node
{
    return (getNode()->getPosition());
}

bool entity::loadModel()  // loads the 3D model
{
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

    model = render->getMSceneMgr()->createEntity("basketball", modelName);  // loads the basketball model

    // creates and instantiates the node object
    node = render->getMSceneMgr()->getRootSceneNode()->createChildSceneNode("basketball");

    // attaches 3D model to the node
    node->attachObject(model);
    // sets the size of the bball node
    node->setScale(0.25f,0.25f,0.25f);
    node->setPosition(0.0f,0.0f,0.0f);

   return true;
}
