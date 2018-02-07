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

// static declarations

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

bool entity::getInitialized()  // retrieves the value of initialized
{
    return (initialized);
}
void entity::setInitialized(bool set)  // sets the value of initialized
{
    initialized = set;
}

bool entity::getNameSet()  // retrieves the value of nameSet
{
    return (nameSet);
}
void entity::setNameSet(bool set)  // sets the value of nameSet
{
    nameSet = set;
}

bool entity::getNodeNameSet()  // retrieves the value of nodeNameSet
{
    return(nodeNameSet);
}
void entity::setNodeNameSet(bool set)  // sets the value of nodeNameSet
{
    nodeNameSet = set;
}

size_t entity::getID()  // retrieves the value of ID
{
    return (ID);
}
void entity::setID(size_t set)  // sets the value of ID
{
    ID = set;
}

std::string entity::getModelFileName()  // retrieves the value of modelFileName
{
    return (modelFileName);
}
void entity::setModelFileName(std::string set)  // sets the value of modelFileName
{
    modelFileName = set;
}

std::string entity::getName()  // retrieves the value of name
{
    return (name);
}
void entity::setName(std::string set)  // sets the value of name
{
    name = set;
}

std::string entity::getNodeName()  // retrieves the value of nodeName
{
    return (nodeName);
}
void entity::setNodeName(std::string set)  // sets the value of nodeName
{
    nodeName = set;
}

OgreEntitySharedPtr entity::getModel()  // retrieves the value of model
{
    return (model);
}
 void entity::setModel(OgreEntitySharedPtr set)  // sets the value of model
{
    
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

bool entity::getNodeCreated()  // retrieves the value of nodeaCreated
{
    return (nodeCreated);
}
void entity::setNodeCreated(bool set)  // sets the value of nodeCreated
{
    nodeCreated = set;
}

/*bool entity::loadModel()  // loads the 3D model
{
    conversionSharedPtr convert = conversion::Instance();
    std::string func = "entity::loadModel()";
//BASEREMOVAL    renderEngineSharedPtr render = base->getGameE()->getRenderE();
    renderEngineSharedPtr render;
    sharedPtr<Ogre::SceneManager> mSceneMgr = render->getMSceneMgr();
    Ogre::ResourceGroupManager &rsm = Ogre::ResourceGroupManager::getSingleton();
    OgreEntitySharedPtr tempModel;
    OgreSceneNodeSharedPtr tempNode; //(new Ogre::SceneNode);

    entityNodeName = entityName + "node";
    logMsg(func +" beginning");
    logMsg(func +" baseInitialized == " +convert->toString(baseInitialized));
    logMsg(func +" ECB entityName == " +entityName);
    logMsg(func +" ECB entityModelFileName == " +entityModelFileName);
    logMsg(func +" ECB entityNodeName == " +entityNodeName);
        
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
    
//BASEREMOVAL    if (base->getGameE()->getRenderE().get()->getMSceneMgr()->hasCamera("camera"))
    if (render.get()->getMSceneMgr()->hasCamera("camera"))
    {
        logMsg(func +" mSceneMgr has camera!");
    }
    else
    {
        logMsg(func +" mSceneMgr does not have camera!");
    }
    
    logMsg(func +" Entity Name == " +entityName + " Model File Name == " +entityModelFileName);
//BASEREMOVAL    tempModel = OgreEntitySharedPtr(base->getGameE()->getRenderE()->getMSceneMgr()->createEntity(entityName, entityModelFileName, "UBCData"));  // loads the model
    tempModel = OgreEntitySharedPtr(render->getMSceneMgr()->createEntity(entityName, entityModelFileName, "UBCData"));  // loads the model

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
//BASEREMOVAL    tempNode = OgreSceneNodeSharedPtr(base->getGameE()->getRenderE()->getMSceneMgr()->getRootSceneNode()->createChildSceneNode(entityNodeName));
    tempNode = OgreSceneNodeSharedPtr(render->getMSceneMgr()->getRootSceneNode()->createChildSceneNode(entityNodeName));

//    tempNode->setName(entityNodeName);
    tempNode->attachObject(model.get());
    logMsg(func +" node attached!");
    
    // attaches 3D model to the node
//    node->attachObject(model);
    // sets the size of the bball node
    tempNode->setScale(0.25f,0.25f,0.25f);
    tempNode->setPosition(0.0f,0.0f,0.0f);
    
    node = tempNode;
    logMsg(func +" ECB node name == " +node->getName());
    logMsg(func +" node position == " +convert->toString(node->getPosition()));
//    exit(0);
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
}*/

/*bool entity::setupPhysics()  // sets up the physics object
{
//    bballInstance.getPhysics().setupPhysics(*model);
    return (false);
}*/
