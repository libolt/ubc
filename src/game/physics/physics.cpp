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
#include "conversion.h"
#include "logging.h"
#include "physics/physics.h"

physics::physics()  // constructor
{
//    physicsSetup = false;

    physObjNumber = 999999;

}
physics::~physics()  // destructor
{

}

boost::shared_ptr<btCollisionShape> physics::getShape()  // retrieves the value of shape
{
    return (shape);
}
void physics::setShape(boost::shared_ptr<btCollisionShape> set)  // sets the value of shape
{
    shape = set;
}

boost::shared_ptr<BtOgre::RigidBodyState> physics::getBodyState()  // retrieves the value of bodyState
{
    return (bodyState);
}

void physics::setBodyState(boost::shared_ptr<BtOgre::RigidBodyState> set)  // sets the value of bodyState
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

boost::shared_ptr<btRigidBody> physics::getPhysBody()  // retrieves physBody variable
{
    return (physBody);
}

void physics::setPhysBody(boost::shared_ptr<btRigidBody> set)  // sets physBody variable
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
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
//    boost::shared_ptr<physicsEngine> physEngine = physicsEngine::Instance();

//    std::vector<basketballState> basketballInstance = gameS->getBasketballInstance();
//    size_t activeBBallInstance = gameS->getActiveBBallInstance();

//    Ogre::SceneNode *tempNode = node;
    btScalar mass = 0.62f;
    btVector3 inertia, inertia2;
    inertia = btVector3(0,0,0);
    btRigidBody *physBody;

    
    //Create the basketball shape.
/*    if (getNumber() != 999999 && basketballInstance[getNumber()].getModelLoaded()) //&& gameS->getBasketballInstancesCreated())
    {
        logMsg("bball number == " +convert->toString(getNumber()));
//        exit(0);
*/
        BtOgre::StaticMeshToShapeConverter converter(*model);
        btCollisionShape *tempShape; 
        switch (getShapeType())
        {
            case CAPSULE:
                tempShape = converter.createCapsule();
            break;
            case BOX:
                tempShape = converter.createBox();
            break;
            case CYLINDER:
            break;
            case SPHERE:
                tempShape= converter.createSphere();
            break;
            default:
            break;
        }
//        setShape(converter.createSphere());
        
        tempShape->calculateLocalInertia(mass, inertia);
        shape = boost::shared_ptr<btCollisionShape>(tempShape);
//        exit(0);

        BtOgre::RigidBodyState *tempBodyState = new BtOgre::RigidBodyState(*node);
        bodyState =  boost::shared_ptr<BtOgre::RigidBodyState>(tempBodyState);
//    exit(0);
        btRigidBody::btRigidBodyConstructionInfo info(mass,bodyState.get(),shape.get(),inertia);  //motion state would actually be non-null in most real usages
        info.m_restitution = 0.85f;
//    info.m_friction = 2.0f;
//    exit(0);
    //Create MotionState (no need for BtOgre here, you can use it if you want to though).
//    basketballBodyState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,0,0)));

    //Create BtOgre MotionState (connects Ogre and Bullet).

    //Create the Body.
//    bballBody = new btRigidBody(mass, basketballBodyState, basketballShape, inertia);
        *body = new btRigidBody(info);
//    bballBody->setActivationState(DISABLE_DEACTIVATION);
    //    bballBody->setCollisionFlags(bballBody->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);
//        *physBody = body;

//        static btDynamicsWorld *world = getWorld();
        boost::shared_ptr<btDynamicsWorld> world = getWorld();
        world->addRigidBody(*body, getColObject(), getCollidesWith());
        setWorld(world);
        physBody = *body;

        logMsg("body is in world == " +convert->toString(physBody->isInWorld()));
//    world->addRigidBody(basketballInstance[activeBBallInstance].getPhysBody());

//        gameS->setBasketballInstance(basketballInstance);
        return (true);
/*    }
    else
    {
        basketballInstance[getNumber()].setModelNeedsLoaded(true);
        gameS->setBasketballInstance(basketballInstance);
        logMsg("Model Needs Loaded!");
//        exit(0);
    }
    */
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
