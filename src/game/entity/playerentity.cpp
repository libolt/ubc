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
        logMsg(func +" setModel");
        setModel(OgreEntitySharedPtr(tempModel));
        logMsg(func +" setNode");
        setNode(OgreSceneNodeSharedPtr(tempNode));
        logMsg(func +" setPhysBody");
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
