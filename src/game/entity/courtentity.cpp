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

#include "components/courtcomponents.h"
#include "entity/courtentity.h"
#include "data/courtdata.h"
#include "flags/courtflags.h"
#include "physics/courtphysics.h"
#include "statemachine/courtstatemachine.h"
#include "utilities/logging.h"

courtEntity::courtEntity()  // constructor
{

//    physics = new courtPhysics;
    objectsInitialized = false;
}
courtEntity::~courtEntity() = default;  // destructor

courtComponentsSharedPtr courtEntity::getComponent() const  // retrieves the value of component
{
    return (component);
}
void courtEntity::setComponent(const courtComponentsSharedPtr &set)  // sets the value of component
{
    component = set;
}

courtDataSharedPtr courtEntity::getData() const  // retrieves the value of data
{
    return (data);
}
void courtEntity::setData(const courtDataSharedPtr &set)  // sets the value of data
{
    data = set;
}

courtFlagsSharedPtr courtEntity::getFlag() const  // retrieves the value of data
{
    return (flag);
}
void courtEntity::setFlag(const courtFlagsSharedPtr &set)  // sets the value of data
{
    flag = set;
}

bool courtEntity::initializeObjects()  // initializes the basketball objects
{
    courtComponentsSharedPtr tempComponent(new courtComponents);
    component = tempComponent;
          
    courtDataSharedPtr tempData(new courtData);
    data = tempData;
    
    courtFlagsSharedPtr tempFlag(new courtFlags);
    flag = tempFlag;
    
    courtStateMachineSharedPtr tempStateMachine(new courtStateMachine);
    stateMachine = tempStateMachine;

    courtPhysicsSharedPtr tempPhysics(new courtPhysics);
    component->setPhysics(tempPhysics);

    return (true);
}

bool courtEntity::initializeStateMachine()  // initializes the court entity object
{
    
    std::string func = "courtEntity::initializeStateMachine()";

    logMsg(func +" begin");
    
    if (!objectsInitialized)
    {
        logMsg(func +" Initializing objects!");
        objectsInitialized = initializeObjects();
    }
    else
    {
        logMsg(func +" Objects already initialized!");
    }
    
    courtSMData *initSMData(new courtSMData);
    
    initSMData->component = component;
    initSMData->cData = data;
    initSMData->flag = flag;
    
    stateMachine->pInitialize(initSMData);
    
    courtSMData *initCSMData(new courtSMData);
    
    initCSMData->component = component;
    stateMachine->pInitializeComponents(initCSMData);

    return (true);
}

bool courtEntity::setupPhysicsObject()  // sets up the physics object
{
    OgreEntitySharedPtr tempModel = component->getModel();
    OgreSceneNodeSharedPtr tempNode = component->getNode();
    btRigidBody *tempPhysBody = component->getPhysics()->getPhysBody().get();
    btScalar restitution = 1.0f;
    btScalar friction = 15.5f;
    bool retVal = false;
    if (!component->getPhysics()->getGameInstanceInitialized())
    {
        component->getPhysics()->setGameInstanceInitialized(true);
    }
    
    component->getPhysics()->setMass(0.0f);
    component->getPhysics()->setRestitution(1.0f);
    component->getPhysics()->setFriction(15.5f);
    size_t collides = COL_BBALL | COL_PLAYER0 | COL_TEAM1 | COL_TEAM2;
    component->getPhysics()->setShapeType(BOX);
    component->getPhysics()->setColObject(COL_COURT);
    component->getPhysics()->setCollidesWith(collides);
//    exit(0);
    if (component->getPhysics()->setupPhysics(&tempModel, &tempNode, &tempPhysBody))
    {
//        tempPhysBody->setActivationState(DISABLE_SIMULATION);
        flag->setPhysicsSetup(true);
        component->setModel(OgreEntitySharedPtr(tempModel));
        component->setNode(OgreSceneNodeSharedPtr(tempNode));
        component->getPhysics()->setPhysBody(btRigidBodySharedPtr(tempPhysBody));
        retVal = true;
    }
    else
    {
    } 
//    getPhysics()->getPhysBody()->setActivationState(ACTIVE_TAG);

    return (retVal);
}
