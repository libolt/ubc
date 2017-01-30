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
#include "conversion.h"
#include "logging.h"
#include "physics/physics.h"

physics::physics()  // constructor
{
//    physicsSetup = false;

    colObject = 999999;
    collidesWith = 999999;
    physObjNumber = 999999;

}
physics::~physics()  // destructor
{

}

btCollisionShapeSharedPtr physics::getShape()  // retrieves the value of shape
{
    return (shape);
}
void physics::setShape(btCollisionShapeSharedPtr set)  // sets the value of shape
{
    shape = set;
}

BtOgreRigidBodyStateSharedPtr physics::getBodyState()  // retrieves the value of bodyState
{
    return (bodyState);
}

void physics::setBodyState(BtOgreRigidBodyStateSharedPtr set)  // sets the value of bodyState
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

int physics::getColObject()  // retrieves the value of colObject
{
    return (colObject);
}
void physics::setColObject(int set)  // sets the value of colObject
{
    colObject = set;
}

int physics::getCollidesWith()  // retrieves the value of collidesWith
{
    return (collidesWith);
}
void physics::setCollidesWith(int set)  // sets the value of collidesWith
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

/*bool physics::getSetupComplete()  // retrieves the value of setupComplete
{
    return (setupComplete);
}
void physics::setSetupComplete(bool set)  // sets the value of setupComplete
{
    setupComplete = set;
}*/

bool physics::setup()  // sets up the state of the object
{
    return (true);
}

bool physics::setupPhysics(Ogre::Entity **model, Ogre::SceneNode **node, btRigidBody **body)  // sets up physics for the object
{
    
//    setCollidesWith(COL_COURT);  // collides with the court
    sharedPtr<conversion> convert = conversion::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
//    sharedPtr<physicsEngine> physEngine = physicsEngine::Instance();

//    basketballStateVec basketballInstance = gameS->getBasketballInstance();
//    size_t activeBBallInstance = gameS->getActiveBBallInstance();

//    Ogre::SceneNode *tempNode = node;
    btScalar mass = 0.62f;
    btVector3 inertia, inertia2;
    inertia = btVector3(0,0,0);
    btRigidBody *physBody ;
    btCollisionShape *tempShape; 
    
    std::string func = "physics::setupPhysics()";
    
    logMsg(func +" beginning");
    
    //Create the basketball shape.
///    if (getNumber() != 999999 && basketballInstance[getNumber()].getModelLoaded()) //&& gameS->getBasketballInstancesCreated())
///    {
///        logMsg("bball number == " +convert->toString(getNumber()));
//        exit(0);

        BtOgre::StaticMeshToShapeConverter converter(*model);
        
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
                tempShape= converter.createSphere();
                logMsg(func +" SPHERE");
            break;
            default:
            break;
        }
//        setShape(converter.createSphere());
        
        tempShape->calculateLocalInertia(mass, inertia);
        logMsg(func +" tempShape->calculateLocalInertia(mass, inertia);");

        shape = btCollisionShapeSharedPtr(tempShape);
        logMsg(func +" shape = btCollisionShapeSharedPtr(tempShape);");

//        exit(0);

        BtOgreRigidBodyStateSharedPtr tempBodyState(new BtOgre::RigidBodyState(*node));
        logMsg(func +" BtOgre::RigidBodyState *tempBodyState = new BtOgre::RigidBodyState(*node);");

        bodyState =  BtOgreRigidBodyStateSharedPtr(tempBodyState);
        logMsg(func +" bodyState =  BtOgreRigidBodyStateSharedPtr(tempBodyState);");

//    exit(0);
        btRigidBody::btRigidBodyConstructionInfo info(mass,bodyState.get(),shape.get(),inertia);  //motion state would actually be non-null in most real usages
        logMsg(func +" btRigidBody::btRigidBodyConstructionInfo info(mass,bodyState.get(),shape.get(),inertia);");

        info.m_restitution = 0.85f;
        logMsg(func +" info.m_restitution = 0.85f;");

//    info.m_friction = 2.0f;
//    exit(0);
    //Create MotionState (no need for BtOgre here, you can use it if you want to though).
//    basketballBodyState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,0,0)));

    //Create BtOgre MotionState (connects Ogre and Bullet).

    //Create the Body.
//    bballBody = new btRigidBody(mass, basketballBodyState, basketballShape, inertia);
        *body = new btRigidBody(info);
        logMsg(func +" *body = new btRigidBody(info);");

//    bballBody->setActivationState(DISABLE_DEACTIVATION);
    //    bballBody->setCollisionFlags(bballBody->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);
//        *physBody = body;

//        static btDynamicsWorld *world = getWorld();
        sharedPtr<btDynamicsWorld> world = getWorld();
        logMsg(func +" sharedPtr<btDynamicsWorld> world = getWorld();");

        logMsg(func +" getColObject() == " +convert->toString(getColObject()));
        logMsg(func +" getCollidesWith() == " +convert->toString(getCollidesWith()));

        world->addRigidBody(*body, getColObject(), getCollidesWith());
        logMsg(func +" world->addRigidBody(*body, getColObject(), getCollidesWith());");

        setWorld(world);
        logMsg(func +" setWorld(world);");

        physBody = *body;
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
