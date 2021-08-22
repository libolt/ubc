/***************************************************************************
 *   Copyright (C) 1999 - 2019 by Mike McLean                              *
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

#ifdef _ENABLE_BTOGRE

#include "utilities/conversion.h"
#include "utilities/logging.h"
#include "physics/basketballphysics.h"
#include "engine/physicsengine.h"
//#include "state/gamestate.h"

basketballPhysics::basketballPhysics()  // constructor
{
	bounce = NOBOUNCE;
//    bballCollidesWith = COL_COURT; // | COL_TEAM1 | COL_TEAM2;  // determines what the basketball collides with

/*    physicsSetup = false;

    number = 999999;

    stateSet = false;
    setupState();
*/
}

/*
btCollisionShape *basketballPhysics::getShape()  // retrieves the value of basketballShape
{
    return (shape);
}
void basketballPhysics::setShape(btCollisionShape *set)  // sets the value of basketballShape
{
    shape = set;
}

BtOgre::RigidBodyState *basketballPhysics::getBasketballBodyState()  // retrieves the value of basketballBodyState
{
    return (basketballBodyState);
}

void basketballPhysics::setBasketBallBodyState(BtOgre::RigidBodyState *set)  // sets the value of basketballBodyState
{
    basketballBodyState = set;
}

size_t basketballPhysics::getNumber()  // retrieves the value of number
{
    return (number);
}
void basketballPhysics::setNumber(size_t set)  // sets the value of number
{
    number = set;
}

bool basketballPhysics::getPhysicsSetup()  // retrieves the value of physicsSetup
{
    return (physicsSetup);
}
void basketballPhysics::setPhysicsSetup(bool set)  // sets the value of physicsSetup
{
    physicsSetup = set;
}

bool basketballPhysics::getStateSet()  // retrieves the value of stateSet
{
    return (stateSet);
}
void basketballPhysics::setStateSet(bool set)  // sets the value of stateSet
{
    stateSet = set;
}
*/

bballBounces basketballPhysics::getBounce() const  // retrieves value of bounce
{
    return (bounce);
}
void basketballPhysics::setBounce(const bballBounces &set)  // sets the value of bounce
{
    bounce = set;
}

bool basketballPhysics::setup()  // sets up physics for the basketball
{
    std::string func = "basketballPhysics::setup()";
    logMsg(func +" begin");
    exit(0);
/*    setCollidesWith(COL_COURT);  // collides with the court
    conversionSharedPtr convert ;
    sharedPtr<gameState> gameS = gameState::Instance();
    sharedPtr<physicsEngine> physEngine = physicsEngine::Instance();

    basketballStateVec basketballInstance = gameS->getBasketballInstance();
    size_t activeBBallInstance = gameS->getActiveBBallInstance();
    btScalar mass = 0.62f;
    btVector3 inertia, inertia2;
    inertia = btVector3(0,0,0);
    btRigidBody *bballBody;

    
    //Create the basketball shape.
    if (getNumber() != 999999 && basketballInstance[getNumber()].getModelLoaded()) //&& gameS->getBasketballInstancesCreated())
    {
        logMsg("bball number == " +convert->toString(getNumber()));
//        exit(0);
        BtOgre::StaticMeshToShapeConverter converter(basketballInstance[getNumber()].getModel());
        setShape(converter.createSphere());
        
        getShape()->calculateLocalInertia(mass, inertia);
//        exit(0);

        setBodyState(new BtOgre::RigidBodyState(basketballInstance[getNumber()].getNode()));
//    exit(0);
        btRigidBody::btRigidBodyConstructionInfo info(mass,getBodyState(),getShape(),inertia);  //motion state would actually be non-null in most real usages
        info.m_restitution = 0.85f;
//    info.m_friction = 2.0f;
//    exit(0);
    //Create MotionState (no need for BtOgre here, you can use it if you want to though).
//    basketballBodyState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,0,0)));

    //Create BtOgre MotionState (connects Ogre and Bullet).

    //Create the Body.
//    bballBody = new btRigidBody(mass, basketballBodyState, basketballShape, inertia);
        bballBody = new btRigidBody(info);
//    bballBody->setActivationState(DISABLE_DEACTIVATION);
    //    bballBody->setCollisionFlags(bballBody->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);
        basketballInstance[activeBBallInstance].setPhysBody(bballBody);

        btDynamicsWorld *world = physEngine.getWorld();
        world->addRigidBody(basketballInstance[activeBBallInstance].getPhysBody(), COL_BBALL, getCollidesWith());
        physEngine.setWorld(world);

//    world->addRigidBody(basketballInstance[activeBBallInstance].getPhysBody());

        gameS->setBasketballInstance(basketballInstance);
        return (true);
    }
    else
    {
        basketballInstance[getNumber()].setModelNeedsLoaded(true);
        gameS->setBasketballInstance(basketballInstance);
        logMsg("Model Needs Loaded!");
//        exit(0);
    }
*/
    return false;
}

/*
bool basketballPhysics::setupState()  // sets up the state of the basketballPhysics object
{
    return (true);
}


void basketballPhysics::updateState()  // updates basketball physics state
{
    if (!setup)
    {
        if (setup())  // sets up physics state for basketball
        {
            physicsSetup = true;
        }
        else
        {
        }
    }
    else
    {
    }
}
*/

void basketballPhysics::ballDribbling(Ogre::Vector3 bballPos, const btRigidBodySharedPtr &courtPhysBody, Ogre::Vector3 courtPos)  // simulates basketball dribble
{
    conversionSharedPtr convert ;
    physicsEngine physEngine;
//    sharedPtr<gameState> gameS = gameState::Instance();

//    playerStateVec pInstance = gameS->getPlayerInstance();
//    basketballStateVec basketballInstance = gameS->getBasketballInstance();
//    courtStateVec courtInstance = gameS->getCourtInstance();

//    int activeBBallInstance = gameS->getActiveBBallInstance();

    //MyContactResultCallback courtCollisionResult;

//    Ogre::Vector3 bballPos = basketballInstance[activeBBallInstance].getNode()->getPosition();
//    Ogre::Vector3 courtPos = courtInstance[0].getNode()->getPosition();

//    if (gameS->getBballBounce() == 0 && bballPos[1] < courtPos[1] + 5)  // checks if the ball is set to bounce up and hasn't reached the max height
    if (bounce == BOUNCEUP && bballPos < courtPos + 5)
    {
//        basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(0,10,0));
        getPhysBody()->setLinearVelocity(btVector3(0,10,0));
    }
    else
    {
//        gameS->setBballBounce(1);  // sets the ball to bounce down
        bounce = BOUNCEDOWN;
    }

//    if (gameS->getBballBounce() == 1)  // checks if the ball is set bounce downward
    if (bounce == BOUNCEDOWN)
    {
//        basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(0,-10,0));
        getPhysBody()->setLinearVelocity(btVector3(0,-10,0));
    }
    else
    {
    }

//    pairCollided = false;
//  logMsg("basketballInstance size = " +convert->toString(basketballInstance.size()));
//  logMsg("courtInstance size = " +convert->toString(courtInstance.size()));

//  logMsg("basketballInstance position = " + convert->toString(basketballInstance[activeBBallInstance].getNode()->getPosition()));
//  logMsg("courtInstance position = " + convert->toString(courtInstance[0].getNode()->getPosition()));

//    btRigidBody *bballPhysBody = basketballInstance[activeBBallInstance].getPhysBody();
//    btRigidBody *courtPhysBody = courtInstance[0].getPhysBody();
//  bballPhysBody->checkCollideWith(courtPhysBody);
//    physEngine.getWorld()->contactPairTest(getPhysBody(), courtPhysBody, courtCollisionResult);
    bool bballCourtCollided = physEngine.collisionCheck(getPhysBody(), courtPhysBody);
    //    logMsg("court collision " +convert->toString(courtCollisionResult));
    int numManifolds = physEngine.getWorld()->getDispatcher()->getNumManifolds();
    for (int i = 0; i<numManifolds; i++)
    {
        btPersistentManifold* contactManifold = physEngine.getWorld()->getDispatcher()->getManifoldByIndexInternal(i);
//      btCollisionObject* obA = static_cast<btCollisionObject*>(contactManifold->getBody0());
//      btCollisionObject* obB = static_cast<btCollisionObject*>(contactManifold->getBody1());
        #if BT_BULLET_VERSION>=281
        auto *obA = const_cast<btCollisionObject*>(contactManifold->getBody0());; // For newer Bullet versions
        auto *obB = const_cast<btCollisionObject*>(contactManifold->getBody1()); // For newer Bullet versions
        #else
        auto *obA = static_cast<btCollisionObject*>(contactManifold->getBody0()); // For older Bullet versions (original code)
        auto *obB = static_cast<btCollisionObject*>(contactManifold->getBody1()); // For older Bullet versions (original code)
        #endif
        int numContacts = contactManifold->getNumContacts();
        for (int j = 0; j<numContacts; j++)
        {
            btManifoldPoint& pt = contactManifold->getContactPoint(j);
            if (pt.getDistance()<0.f)
            {
                const btVector3& ptA = pt.getPositionWorldOnA();
                const btVector3& ptB = pt.getPositionWorldOnB();
                const btVector3& normalOnB = pt.m_normalWorldOnB;
                // ZOMG A COLLISIONNNNNNNNNNN ...
                if (dynamic_cast<btRigidBody*>(obA) == getPhysBody().get() || dynamic_cast<btRigidBody*>(obB) == courtPhysBody.get())
                {
                    logMsg("ball collided with court!");
                   // exit(0);
                    // myRigidBodyPtrA totally just collided with something ... if I care what then I have to code more
                }
            }
        }
    }
    int dee = 0;

    logMsg("basketball - court collision tested");
    if (bballCourtCollided)
    {
//      gameS->setPlayerWithBall(gameS->getBallTippedToPlayer());
//      gameS->setBallTipForceApplied(false);
//          basketballInstance[activeBBallInstance].getPhysBody()->applyForce(btVector3(-1.0f, 0.50f, 0.0f),btVector3(0.0f,0.0f,0.0f));
//          basketballInstance[activeBBallInstance].getPhysBody()->forceActivationState(ISLAND_SLEEPING);
//      basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(0,10,0));
//      gameS->setTipOffComplete(true);
//          exit(0);
//        gameS->setBballBounce(0);
        bounce = BOUNCEUP;
    }
    else
    {
    }

}

void basketballPhysics::updatePosition()  // updates the position of basketball object(s)
{
//    sharedPtr<gameState> gameS = gameState::Instance();

//    size_t activeBBallInstance = gameS->getActiveBBallInstance();
//    basketballStateVec basketballInstance = gameS->getBasketballInstance();

    if (getVelocitySet())
    {
//        exit(0);
///        basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(basketballVelocity);
    }
    else
    {
//        basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(0,0,0));

    }
}
#endif
