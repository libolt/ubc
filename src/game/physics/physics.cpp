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

#include "physics/physics.h"
#include "conversion.h"

physics::physics()  // constructor
{
    setupComplete = false;

    number = 999999;

    stateSet = false;
}
physics::~physics()  // destructor
{

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

int physics::getCollidesWith()  // retrieves the value of collidesWith
{
    return (collidesWith);
}
void physics::setCollidesWith(int set)  // sets the value of collidesWith
{
    collidesWith = set;
}

size_t physics::getNumber()  // retrieves the value of number
{
    return (number);
}
void physics::setNumber(size_t set)  // sets the value of number
{
    number = set;
}

bool physics::getSetupComplete()  // retrieves the value of setupComplete
{
    return (setupComplete);
}
void physics::setSetupComplete(bool set)  // sets the value of setupComplete
{
    setupComplete = set;
}

bool physics::getStateSet()  // retrieves the value of stateSet
{
    return (stateSet);
}
void physics::setStateSet(bool set)  // sets the value of stateSet
{
    stateSet = set;
}
bool physics::setup()  // sets up the state of the object
{
    return (true);
}

bool physics::setupPhysics(physicsShapes modelShape, Ogre::Entity **model, Ogre::SceneNode **node, btRigidBody **physBody)  // sets up physics for the object
{
    setCollidesWith(COL_COURT);  // collides with the court
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<physicsEngine> physEngine = physicsEngine::Instance();

//    std::vector<basketballState> basketballInstance = gameS->getBasketballInstance();
//    size_t activeBBallInstance = gameS->getActiveBBallInstance();
    btScalar mass = 0.62f;
    btVector3 inertia, inertia2;
    inertia = btVector3(0,0,0);
    btRigidBody *body;

    
    //Create the basketball shape.
/*    if (getNumber() != 999999 && basketballInstance[getNumber()].getModelLoaded()) //&& gameS->getBasketballInstancesCreated())
    {
        logMsg("bball number == " +convert->toString(getNumber()));
//        exit(0);
*/
        BtOgre::StaticMeshToShapeConverter converter(&model);
        
        switch (modelShape)
        {
            case CAPSULE:
            break;
            case BOX:
            break;
            case CYLINDER:
            break;
            case SPHERE:
                shape= converter.createSphere();
            break;
            default:
            break;
        }
//        setShape(converter.createSphere());
        
        shape().calculateLocalInertia(mass, inertia);
//        exit(0);

        bodyState = new BtOgre::RigidBodyState(node);
//    exit(0);
        btRigidBody::btRigidBodyConstructionInfo info(mass,bodyState,shape,inertia);  //motion state would actually be non-null in most real usages
        info.m_restitution = 0.85f;
//    info.m_friction = 2.0f;
//    exit(0);
    //Create MotionState (no need for BtOgre here, you can use it if you want to though).
//    basketballBodyState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,0,0)));

    //Create BtOgre MotionState (connects Ogre and Bullet).

    //Create the Body.
//    bballBody = new btRigidBody(mass, basketballBodyState, basketballShape, inertia);
        body = new btRigidBody(info);
//    bballBody->setActivationState(DISABLE_DEACTIVATION);
    //    bballBody->setCollisionFlags(bballBody->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);
        physBody = body;

        btDynamicsWorld *world = physEngine->getWorld();
        world->addRigidBody(physBody, COL_BBALL, getCollidesWith());
        physEngine->setWorld(world);

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
    return (false);
}

void physics::update()  // updates object physics state
{
    if (setupComplete)
    {
/*        if (setupPhysics())  // sets up physics state for the object
        {
            setupComplete = true;
        }
        else
        {
        }
*/
    }
    else
    {
    }
}
