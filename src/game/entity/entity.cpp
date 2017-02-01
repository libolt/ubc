/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
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
#include "conversion.h"
#include "logging.h"
#include "ubc.h"

// static declarations
UBCBaseSharedPtr entity::base;  // base class object
//std::string entity::entityNodeName;  // stores the name of the scene node

entity::entity()  // constructor
{
    initialized = false;
    baseInitialized = false;

    entityID = 0;
    physicsSetup = false;
    modelNeedsLoaded = false;
    modelLoaded = false;
}

entity::~entity()  // destructor
{
    
}

bool entity::getInitialized()  // retrieves the value of initialized
{
    return (initialized);
}
void entity::setInitialized(bool set)  // sets the value of initialized
{
    initialized = set;
}

UBCBaseSharedPtr entity::getBase()  // retrieves the value of base
{
    return (base);
}
void entity::setBase(UBCBaseSharedPtr set)  // sets the value of base
{
    base = set;
}

bool entity::getBaseInitialized()  // retrieves the value of baseInitialized
{
    return (baseInitialized);
}
void entity::setBaseInitialized(bool set)  // sets the value of baseInitialized
{
    baseInitialized = set;
}

size_t entity::getEntityID()  // retrieves the value of ID
{
    return (entityID);
}
void entity::setEntityID(size_t set)  // sets the value of ID
{
    entityID = set;
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

OgreEntitySharedPtr entity::getModel()  // retrieves the value of model
{
    return (model);
}
 void entity::setModel(OgreEntitySharedPtr set)  // sets the value of model
{
    logMsg("die here?");
    model = set;
}

OgreSceneNodeSharedPtr entity::getNode()  // retrieves the value of node
{
    return (node);
}
void entity::setNode(OgreSceneNodeSharedPtr set)  // sets the value of node
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
    sharedPtr<conversion> convert = conversion::Instance();

//    exit(0);
//    sharedPtr<renderEngine> render = renderEngine::Instance();
    std::string func = "playerEntity::loadModel()";
    logMsg(func +" beginning");
    logMsg(func +" baseInitialized == " +convert->toString(baseInitialized));
    sharedPtr<renderEngine> render = base->getGameE()->getRenderE();
    logMsg(func +" entityName == " +entityName);
    logMsg(func +" entityModelFileName == " +entityModelFileName);
    sharedPtr<Ogre::SceneManager> mSceneMgr = render->getMSceneMgr();
    logMsg(func +" Model");
    Ogre::ResourceGroupManager &rsm = Ogre::ResourceGroupManager::getSingleton();
    
    if (rsm.resourceGroupExists("UBCData"))
    {
        logMsg(func +" UBData exists!");
        if (rsm.resourceExists("UBCData", entityModelFileName))
        {
            logMsg(func +" " +entityModelFileName +" exists!");
        }
        else
        {
            logMsg(func +" " +entityModelFileName +" doesn't exist!");
        }
    }
    else
    {
        logMsg(func +" UBData doesnt exist!");

    }
    
    if (base->getGameE()->getRenderE().get()->getMSceneMgr()->hasCamera("camera"))
    {
        logMsg(func +" mSceneMgr has camera!");
    }
    else
    {
        logMsg(func +" mSceneMgr does not have camera!");
    }
    
    if (entityNodeName == "")
    {
        entityNodeName = entityName + "node";
    }
//    model = render->getMSceneMgr()->createEntity(entityName, entityModelFileName);  // loads the model
    logMsg(func +" Entity Name == " +entityName + " Model File Name == " +entityModelFileName);
    Ogre::Entity *tempModel = base->getGameE()->getRenderE()->getMSceneMgr()->createEntity(entityName, entityModelFileName, "UBCData");  // loads the model
    logMsg(func +" tempModel loaded!");
    
//    render->getMSceneMgr()->
//    Ogre::Entity *tempModel = render->getMSceneMgr()->createEntity("dah!", "Player.mesh");
    
    model = OgreEntitySharedPtr(tempModel);
    logMsg(func +" Entity Created!");
//    exit(0);
    // creates and instantiates the node object
//    node = getRenderE()->getMSceneMgr()->getRootSceneNode()->createChildSceneNode(entityNodeName);
///    if (entityNodeName == "")
///    {
///        entityNodeName = entityName +"node";
//        entityNodeName = "das";
///    }

    logMsg(func +" entityNodeName == " +entityNodeName);
//    exit(0);
    Ogre::SceneNode *tempNode = base->getGameE()->getRenderE()->getMSceneMgr()->getRootSceneNode()->createChildSceneNode(entityNodeName);
//    tempNode->setName(entityNodeName);
    tempNode->attachObject(model.get());
    logMsg(func +" node attached!");
    
    // attaches 3D model to the node
//    node->attachObject(model);
    // sets the size of the bball node
    tempNode->setScale(0.25f,0.25f,0.25f);
    tempNode->setPosition(0.0f,0.0f,0.0f);
    
    node = OgreSceneNodeSharedPtr(tempNode);
///    logMsg("scene node created!");
///    node->attachObject(model);
///    logMsg("node attached!");
    // attaches 3D model to the node
//    node->attachObject(model);
    // sets the size of the bball node
///    node->setScale(0.25f,0.25f,0.25f);
///    node->setPosition(0.0f,0.0f,0.0f);

    logMsg(func +" end");
    
    return (true);
}

/*bool entity::setupPhysics()  // sets up the physics object
{
//    bballInstance.getPhysics().setupPhysics(*model);
    return (false);
}*/
