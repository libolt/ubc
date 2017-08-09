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
#include "conversion.h"
#include "logging.h"
#include "physics/physics.h"
#include "engine/physicsengine.h"

// static declarations
gameStateSharedPtr physics::gameS;
physicsEngineSharedPtr physics::physE;  // physics engine object

//bool physics::gameSInitialized;  // stores whether the gameState object has been initialized

physics::physics()  // constructor
{
    
    gameSInitialized = false;
    physEInitialized = false;
//    physicsSetup = false;

    mass = 0.0f;
    inertia = btVector3(0,0,0);
    restitution = 0.0f;
    friction = 0.0f;
    velocity = 0.0f;
    velocitySet = false;
    colObject = 999999;
    collidesWith = 999999;
    physObjNumber = 999999;

}
physics::~physics()  // destructor
{

}

gameStateSharedPtr physics::getGameS()  // retrieves the value of gameS
{
    return (gameS);
}
void physics::setGameS(gameStateSharedPtr set)  // sets the value of gameS
{
    gameS = set;
}

bool physics::getGameSInitialized() // retrieves the value of gameSInitialized
{
    return (gameSInitialized);
}
void physics::setGameSInitialized(bool set)  // sets the value of gameSInitialized
{
    gameSInitialized = set;
}

physicsEngineSharedPtr physics::getPhysE()  // retrieves the value of physE
{
    return (physE);
}
void physics::setPhysE(physicsEngineSharedPtr set)  // sets the value of physE
{
    physE = set;
}

bool physics::getPhysEInitialized() // retrieves the value of physEInitialized
{
    return (physEInitialized);
}
void physics::setPhysEInitialized(bool set)  // sets the value of physEInitialized
{
    physEInitialized = set;
}

btCollisionShape *physics::getShape()  // retrieves the value of shape
{
    return (shape);
}
void physics::setShape(btCollisionShape *set)  // sets the value of shape
{
    shape = set;
}

BtOgre::RigidBodyState *physics::getBodyState()  // retrieves the value of bodyState
{
    return (bodyState);
}

void physics::setBodyState(BtOgre::RigidBodyState *set)  // sets the value of bodyState
{
    bodyState = set;
}

physicsShapes physics::getShapeType()  // retrieves the value of shapeType
{
    return (shapeType);
}
void physics::setShapeType(physicsShapes set)  // sets the value of shapeType
{
    shapeType = set;
}

btRigidBodySharedPtr physics::getPhysBody()  // retrieves physBody variable
{
    return (physBody);
}

void physics::setPhysBody(btRigidBodySharedPtr set)  // sets physBody variable
{
    physBody = set;
}

std::unordered_map<std::string, btRigidBodySharedPtr> physics::getCollisionBodies()  // retrieves the value of collisionBodies
{
    return (collisionBodies);
}
void physics::setCollisionBodies(std::unordered_map<std::string, btRigidBodySharedPtr> set)  // sets the value of collisionBodies
{
    collisionBodies = set;
}

btScalar physics::getMass()  // retrieves the value of mass
{
    return (mass);
}
void physics::setMass(btScalar set)  // sets the value of mass
{
    mass = set;
}

btVector3 physics::getInertia()  // retrieves the value of inertia
{
    return (inertia);
}
void physics::setInertia(btVector3 set)  // sets the value of inertia
{
    inertia = set;
}

btScalar physics::getRestitution()  // retrieves the value of restitution
{
    return (restitution);
}
void physics::setRestitution(btScalar set)  // sets the value of restitution
{
    restitution = set;
}

btScalar physics::getFriction()  // retrieves the value of friction
{
    return (friction);
}
void physics::setFriction(btScalar set)  // sets the value of friction
{
    friction = set;
}

btScalar physics::getVelocity()  // retrieves the value of velocity
{
    return (velocity);
}
void physics::setVelocity(btScalar set)  // sets the value of velocity
{
    velocity = set;
}

bool physics::getVelocitySet()  // retrieves the value of velocitySet
{
    return (velocitySet);
}
void physics::setVelocitySet(bool set)  // sets the value of velocitySet
{
    velocitySet = set;
}

size_t physics::getColObject()  // retrieves the value of colObject
{
    return (colObject);
}
void physics::setColObject(size_t set)  // sets the value of colObject
{
    colObject = set;
}

size_t physics::getCollidesWith()  // retrieves the value of collidesWith
{
    return (collidesWith);
}
void physics::setCollidesWith(size_t set)  // sets the value of collidesWith
{
    collidesWith = set;
}

size_t physics::getPhysObjNumber()  // retrieves the value of number
{
    return (physObjNumber);
}
void physics::setPhysObjNumber(size_t set)  // sets the value of number
{
    physObjNumber = set;
}

bool physics::setup()  // sets up the state of the object
{
    return (true);
}

bool physics::setupPhysics(OgreEntitySharedPtr *model, OgreSceneNodeSharedPtr *node, btRigidBody **body)  // sets up physics for the object
{

    sharedPtr<conversion> convert = conversion::Instance();
    btRigidBody *physBody;
    btCollisionShape *tempShape; 
    std::string func = "physics::setupPhysics()";
    
    logMsg(func +" beginning");
    
    BtOgre::StaticMeshToShapeConverter converter(model->get());
        
    logMsg(func +" BtOgre::StaticMeshToShapeConverter");
        
    switch (getShapeType())
    {
        case CAPSULE:
            tempShape = converter.createCapsule();
            logMsg(func +" CAPSULE");
        break;
        case BOX:
            tempShape = converter.createBox();
            logMsg(func +" BOX");
        break;
        case CYLINDER:
            logMsg(func +" CYLINDER");
        break;
        case SPHERE:
            tempShape = converter.createSphere();
            logMsg(func +" SPHERE");
        break;
        default:
        break;
    }
//        setShape(converter.createSphere());
        
    tempShape->calculateLocalInertia(mass, inertia);
    logMsg(func +" tempShape->calculateLocalInertia(mass, inertia);");

    shape = tempShape;
    logMsg(func +" shape = btCollisionShapeSharedPtr(tempShape);");

//        exit(0);

    BtOgre::RigidBodyState *tempBodyState = new BtOgre::RigidBodyState(node->get());
    logMsg(func +" BtOgre::RigidBodyState *tempBodyState = new BtOgre::RigidBodyState(*node);");

    bodyState =  tempBodyState;
    logMsg(func +" bodyState =  BtOgreRigidBodyStateSharedPtr(tempBodyState);");

//    exit(0);
    btRigidBody::btRigidBodyConstructionInfo info(mass,bodyState,shape,inertia);  //motion state would actually be non-null in most real usages
    logMsg(func +" btRigidBody::btRigidBodyConstructionInfo info(mass,bodyState.get(),shape.get(),inertia);");

    info.m_restitution = restitution;
    logMsg(func +" info.m_restitution");

    info.m_friction = friction;
//    exit(0);
    //Create MotionState (no need for BtOgre here, you can use it if you want to though).
//    basketballBodyState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,0,0)));

    //Create BtOgre MotionState (connects Ogre and Bullet).

    //Create the Body.
//    bballBody = new btRigidBody(mass, basketballBodyState, basketballShape, inertia);
    physBody = new btRigidBody(info);
    logMsg(func +" *body = new btRigidBody(info);");

//    bballBody->setActivationState(DISABLE_DEACTIVATION);
    //    bballBody->setCollisionFlags(bballBody->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);
//        *physBody = body;

//        static btDynamicsWorld *world = getWorld();
    sharedPtr<btDynamicsWorld> world = physE->getWorld();
    logMsg(func +" sharedPtr<btDynamicsWorld> world = getWorld();");

    logMsg(func +" getColObject() == " +convert->toString(getColObject()));
    logMsg(func +" getCollidesWith() == " +convert->toString(getCollidesWith()));

    world->addRigidBody(physBody, getColObject(), getCollidesWith());
    *body = physBody;

    logMsg(func +" world->addRigidBody(*body, getColObject(), getCollidesWith());");

    physE->setWorld(world);
    logMsg(func +" setWorld(world);");

//        physBody = *body;
    logMsg(func +" physBody = *body;");

    logMsg("body is in world == " +convert->toString(physBody->isInWorld()));
//    world->addRigidBody(basketballInstance[activeBBallInstance].getPhysBody());

//        gameS->setBasketballInstance(basketballInstance);
    return (true);
///    }
///    else
///    {
///        basketballInstance[getNumber()].setModelNeedsLoaded(true);
///        gameS->setBasketballInstance(basketballInstance);
///        logMsg("Model Needs Loaded!");
//        exit(0);
///    }

    logMsg(func +" end");
 
    return (true);
}

void physics::updatePhysObj()  // updates object physics state
{
/*    if (physicsSetup)
    {
        if (setupPhysics())  // sets up physics state for the object
        {
            setupComplete = true;
        }
        else
        {
        }

    }
    else
    {
    }
*/
}
