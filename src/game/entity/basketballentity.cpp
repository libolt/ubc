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

#include "entity/basketballentity.h"
#include "physics/basketballphysics.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

basketballEntity::basketballEntity()  // constructor
{
//  physics = new basketballPhysics;
    initialized = false;
}
basketballEntity::~basketballEntity()  // destructor
{
    
}

sharedPtr<basketballPhysics> basketballEntity::getPhysics()  // retrieves the value of physics
{
    return (physics);
}
void basketballEntity::setPhysics(sharedPtr<basketballPhysics> set)  // sets the value of physics
{
    physics = set;
}

basketballSteerSharedPtr basketballEntity::getSteer()  // retrieves the value of steer
{
    return (steer);
}
void basketballEntity::setSteer(basketballSteerSharedPtr set)  // sets the value of steer
{
    steer = set;
}

bool basketballEntity::getInitialized()  // retrieves the value of initialized
{
    return (initialized);
}
void basketballEntity::setInitialized(bool set)  // sets the value of initialized
{
    initialized = set;
}

bool basketballEntity::initialize()  // initializes the basketball entity object
{
    sharedPtr<basketballPhysics> tempPhysics(new basketballPhysics);
    physics = tempPhysics;

    return (true);
}

bool basketballEntity::setupPhysicsObject()  // sets up the physics object
{
    conversionSharedPtr convert = conversion::Instance();
    std::string func = "basketballEntity::setupPhysicsObject()";
    OgreEntitySharedPtr tempModel = getModel();
    OgreSceneNodeSharedPtr tempNode = getNode();
    btRigidBody *tempPhysBody = getPhysics()->getPhysBody().get();
    bool returnType = false;
    
    logMsg(func +" beginning");
    
    if (!getPhysics()->getGameSInitialized())
    {
//BASEREMOVAL        getPhysics()->setGameS(getBase()->getGameS());
        getPhysics()->setGameSInitialized(true);
    }
    
    getPhysics()->setMass(0.05f);
    getPhysics()->setRestitution(0.85f);
    getPhysics()->setFriction(0.0f);
    logMsg("tempNode->getName() == " +tempNode->getName());
    getPhysics()->setShapeType(SPHERE);
    logMsg(func +" setShapeType!");
    getPhysics()->setColObject(COL_BBALL);
    logMsg(func +" setColObject!");
    getPhysics()->setCollidesWith(COL_COURT);
    logMsg(func +" setCollidesWith!");

    if (getPhysics()->setupPhysics(&tempModel, &tempNode, &tempPhysBody))
    {
        
        logMsg(func +" setupPhysics!");
        setPhysicsSetup(true);

        logMsg(func +" modelName == " +tempModel->getName());
        logMsg(func +" nodeName == " +tempNode->getName());

//        exit(0);
        setModel(OgreEntitySharedPtr(tempModel));
        setNode(OgreSceneNodeSharedPtr(tempNode));
        getPhysics()->setPhysBody(btRigidBodySharedPtr(tempPhysBody));
//        exit(0);
        returnType = true;;

    }
    else
    {
    }

    logMsg(func +" end");

//    exit(0);
    return (returnType);
}
