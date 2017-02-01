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

#include "entity/playerentity.h"
#include "logging.h"
#include "conversion.h"
#include "ubcbase.h"
#include "engine/gameengine.h"
#include "engine/renderengine.h"


// static declarations
//UBCBaseSharedPtr playerEntity::base;  // base class object
    
//playerSteerSharedPtr playerEntity::steer;
//bool playerEntity::steerInitialized;

playerEntity::playerEntity()  // constructor
{
    steerInitialized = false;
/*    baseInitialized = false;

    entityID = 0;
    physicsSetup = false;
    modelNeedsLoaded = false;
    modelLoaded = false;
    */
//    physics = new playerPhysics;
}
playerEntity::~playerEntity()  // destructor
{

}

sharedPtr<playerPhysics> playerEntity::getPhysics()  // retrieves the value of physics
{
    return (physics);
}
void playerEntity::setPhysics(sharedPtr<playerPhysics> set)  // sets the value of physics
{
    physics = set;
}

playerSteerSharedPtr playerEntity::getSteer()  // retrieves the value of steer
{
    return (steer);
}
void playerEntity::setSteer(playerSteerSharedPtr set)  // sets the value of steer
{
    steer = set;
}

bool playerEntity::getSteerInitialized()  // retrieves the value of steerInitialized
{
    return (steerInitialized);
}
void playerEntity::setSteerInitialized(bool set)  // sets the value of steerInitialized
{
    steerInitialized = set;
}

/*UBCBaseSharedPtr playerEntity::getBase()  // retrieves the value of base
{
    return (base);
}
void playerEntity::setBase(UBCBaseSharedPtr set)  // sets the value of base
{
    base = set;
}

bool playerEntity::getBaseInitialized()  // retrieves the value of baseInitialized
{
    return (baseInitialized);
}
void playerEntity::setBaseInitialized(bool set)  // sets the value of baseInitialized
{
    baseInitialized = set;
}

size_t playerEntity::getEntityID()  // retrieves the value of ID
{
    return (entityID);
}
void playerEntity::setEntityID(size_t set)  // sets the value of ID
{
    entityID = set;
}

std::string playerEntity::getEntityModelFileName()  // retrieves the value of entityModelName
{
    return (entityModelFileName);
}
void playerEntity::setEntityModelFileName(std::string set)  // sets the value of entityNodelName
{
    entityModelFileName = set;
}

std::string playerEntity::getEntityName()  // retrieves the value of entityName
{
    return (entityName);
}
void playerEntity::setEntityName(std::string set)  // sets the value of entityName
{
    entityName = set;
}

std::string playerEntity::getEntityNodeName()  // retrieves the value of entityNodeName
{
    return (entityNodeName);
}
void playerEntity::setEntityNodeName(std::string set)  // sets the value of entityNodeName
{
    entityNodeName = set;
}

OgreEntitySharedPtr playerEntity::getModel()  // retrieves the value of model
{
    return (model);
}
 void playerEntity::setModel(OgreEntitySharedPtr set)  // sets the value of model
{
    logMsg("die here?");
    model = set;
}

OgreSceneNodeSharedPtr playerEntity::getNode()  // retrieves the value of node
{
    return (node);
}
void playerEntity::setNode(OgreSceneNodeSharedPtr set)  // sets the value of node
{
    node = set;
}

bool playerEntity::getPhysicsSetup()  // retrieves the value of physicsSetup
{
    return (physicsSetup);
}
void playerEntity::setPhysicsSetup(bool set)  // sets the value of physicsSetup
{
    physicsSetup = set;
}

bool playerEntity::getModelNeedsLoaded()  // retrieves the value of modelNeedsLoaded
{
    return (modelNeedsLoaded);
}
void playerEntity::setModelNeedsLoaded(bool set)  // sets the value of modelNeedsLoaded
{
    modelNeedsLoaded = set;
}

bool playerEntity::getModelLoaded()  // retrieves the value of modelLoaded
{
    return (modelLoaded);
}
void playerEntity::setModelLoaded(bool set)  // sets the value of modelLoaded
{
    modelLoaded = set;
}

Ogre::Vector3 playerEntity::getNodePosition()  // retrieves the value of nodePosition
{
    return (nodePosition);
}
void playerEntity::setNodePosition(Ogre::Vector3 set)  // sets the value of nodePosition
{
    nodePosition = set;
}

bool playerEntity::loadModel()  // loads the 3D model
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
*/

bool playerEntity::setupPhysicsObject()  // sets up the physics object
{
    std::string func = "playerEntity::setupPhysicsObject()!";
    Ogre::Entity *tempModel = getModel().get();
    Ogre::SceneNode *tempNode = getNode().get();
    btRigidBody *tempPhysBody = getPhysBody().get();
    
    logMsg(func +" beginning");
//    exit(0);
    setShapeType(CAPSULE);
    setColObject(COL_BBALL);
//    getPhysics()->setCollidesWith(COL_COURT);

    if (setupPhysics(&tempModel, &tempNode, &tempPhysBody))
    {
        setPhysicsSetup(true);
        setModel(OgreEntitySharedPtr(tempModel));
        setNode(OgreSceneNodeSharedPtr(tempNode));
        setPhysBody(btRigidBodySharedPtr(tempPhysBody));
//        exit(0);
        return (true);
    }
    else
    {
    }

    logMsg(func +" end");
    
    return (false);
}
