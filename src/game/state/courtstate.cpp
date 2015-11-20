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

#include "courtstate.h"
#include "renderengine.h"

courtState::courtState()
{
//    stateSet = false;
}

courtState::~courtState()
{
}

std::string courtState::getModelName()  // retrieves the value of modelName
{
    return (modelName);
}
void courtState::setModelName(std::string set)  // sets the value of modelName
{
    modelName = set;
}

Ogre::Entity *courtState::getModel()  // retrieves the value of model
{
    return (model);
}
void courtState::setModel(Ogre::Entity *set)  // sets the value of model
{
    model = set;
}

Ogre::SceneNode *courtState::getNode()  // retrieves the value of node
{
    return (node);
}
void courtState::setNode(Ogre::SceneNode *set)  // sets the value of node
{
    node = set;
}

btRigidBody *courtState::getPhysBody()	// retrieves the value of physBody 
{
	return (physBody);
}

void courtState::setPhysBody(btRigidBody *set)	// sets the value of physBody 
{
	physBody = set;
}

Ogre::Vector3 courtState::getNodePosition()  // retrieves the value of nodePosition
{
    return (nodePosition);
}
void courtState::setNodePosition(Ogre::Vector3 set)  // sets the value of nodePosition
{
    nodePosition = set;
}

/*bool courtState::getStateSet()  // retrieves the value of stateSet
{
    return (stateSet);
}
void courtState::setStateSet(bool set)  // sets the value of stateSet
{
    stateSet = set;
}
*/

bool courtState::loadModel()  // loads the 3D Model and attaches it to the node as well as sets coordinates
{
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

    model = render->getMSceneMgr()->createEntity("courtModel", modelName);  // loads the Court model

    // creates the courtNode
    node = render->getMSceneMgr()->getRootSceneNode()->createChildSceneNode("courtSceneNode");

    // attaches the court model to the courtNode
    node->attachObject(model);
    // sets the position of courtNode
//    node->setPosition(0.0f,-20.0f,400.0f);
    node->setScale(1.0f,1.0f,1.0f);

    return true;
}
