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

#include "entity/entity.h"
#include "engine/renderengine.h"
#include "logging.h"
#include "ubc.h"

entity::entity()  // constructor
{
    physicsSetup = false;
    modelNeedsLoaded = false;
    modelLoaded = false;
}

entity::~entity()  // destructor
{
    
}

std::string entity::getEntityModelFileName()  // retrieves the value of entityModelName
{
    return (entityModelFileName);
}
void entity::setEntityModelFileName(std::string set)  // sets the value of entityNodelName
{
    entityModelFileName = set;
}

std::string entity::getEntityName()  // retrieves the value of entityName
{
    return (entityName);
}
void entity::setEntityName(std::string set)  // sets the value of entityName
{
    entityName = set;
}

std::string entity::getEntityNodeName()  // retrieves the value of entityNodeName
{
    return (entityNodeName);
}
void entity::setEntityNodeName(std::string set)  // sets the value of entityNodeName
{
    entityNodeName = set;
}

boost::shared_ptr<Ogre::Entity> entity::getModel()  // retrieves the value of model
{
    return (model);
}
 void entity::setModel(boost::shared_ptr<Ogre::Entity> set)  // sets the value of model
{
    logMsg("die here?");
    model = set;
}

boost::shared_ptr<Ogre::SceneNode> entity::getNode()  // retrieves the value of node
{
    return (node);
}
void entity::setNode(boost::shared_ptr<Ogre::SceneNode> set)  // sets the value of node
{
    node = set;
}

bool entity::getPhysicsSetup()  // retrieves the value of physicsSetup
{
    return (physicsSetup);
}
void entity::setPhysicsSetup(bool set)  // sets the value of physicsSetup
{
    physicsSetup = set;
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

Ogre::Vector3 entity::getNodePosition()  // retrieves the value of nodePosition
{
    return (nodePosition);
}
void entity::setNodePosition(Ogre::Vector3 set)  // sets the value of nodePosition
{
    nodePosition = set;
}

bool entity::loadModel()  // loads the 3D model
{
//    exit(0);
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
    boost::shared_ptr<renderEngine> render = base->getGameE()->getRenderE();
    logMsg("entity::loadModel");
    logMsg("entityName == " +entityName);
    logMsg("entityModelFileName == " +entityModelFileName);
    Ogre::SceneManager *mSceneMgr = render->getMSceneMgr();
    logMsg("Model");
    Ogre::ResourceGroupManager &rsm = Ogre::ResourceGroupManager::getSingleton();
    
    if (rsm.resourceGroupExists("UBCData"))
    {
        logMsg("UBData exists!");
        if (rsm.resourceExists("UBCData", entityModelFileName))
        {
            logMsg(entityModelFileName +" exists!");
        }
        else
        {
            logMsg(entityModelFileName +" doesn't exist!");
        }
    }
    else
    {
        logMsg("UBData doesnt exist!");

    }
    
    if (base->getGameE()->getRenderE().get()->getMSceneMgr()->hasCamera("camera"))
    {
        logMsg("mSceneMgr has camera!");
    }
    else
    {
        logMsg("mSceneMgr does not have camera!");
    }
//    model = render->getMSceneMgr()->createEntity(entityName, entityModelFileName);  // loads the model
    Ogre::Entity *tempModel = base->getGameE()->getRenderE()->getMSceneMgr()->createEntity(entityName, entityModelFileName, "UBCData");  // loads the model
    logMsg("tempModel loaded!");
//    render->getMSceneMgr()->
//    Ogre::Entity *tempModel = render->getMSceneMgr()->createEntity("dah!", "Player.mesh");
    
    model = boost::shared_ptr<Ogre::Entity>(tempModel);
    logMsg("Entity Created!");
    // creates and instantiates the node object
//    node = getRenderE()->getMSceneMgr()->getRootSceneNode()->createChildSceneNode(entityNodeName);
    Ogre::SceneNode *tempNode = base->getGameE()->getRenderE()->getMSceneMgr()->getRootSceneNode()->createChildSceneNode(entityNodeName);
    tempNode->attachObject(model.get());
    logMsg("node attached!");
    // attaches 3D model to the node
//    node->attachObject(model);
    // sets the size of the bball node
    tempNode->setScale(0.25f,0.25f,0.25f);
    tempNode->setPosition(0.0f,0.0f,0.0f);

    node = boost::shared_ptr<Ogre::SceneNode>(tempNode);
/*    logMsg("scene node created!");
    node->attachObject(model);
    logMsg("node attached!");
    // attaches 3D model to the node
//    node->attachObject(model);
    // sets the size of the bball node
    node->setScale(0.25f,0.25f,0.25f);
    node->setPosition(0.0f,0.0f,0.0f);
*/
   return true;
}

/*bool entity::setupPhysics()  // sets up the physics object
{
//    bballInstance.getPhysics().setupPhysics(*model);
    return (false);
}*/
