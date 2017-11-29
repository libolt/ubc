/***************************************************************************
 *   Copyright (C) 2013 by Mike McLean                                     *
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

#ifndef _PHYSICSENGINE_H_
#define _PHYSICSENGINE_H_

//#include "engine/gameengine.h"

#include <vector>

#include "BtOgrePG.h"
#include "BtOgreGP.h"
#include "BtOgreExtras.h"
#include "BulletDynamics/Dynamics/btRigidBody.h"
#include "BulletDynamics/Dynamics/btDynamicsWorld.h"
#include <boost/shared_ptr.hpp>

#include "utilities/enums.h"
//#include "engine/renderengine.h"
#include "utilities/timing.h"

#include "engine.h"

class renderEngine;

class physicsEngine : public engine
{
public:
    physicsEngine();  // constructor
    ~physicsEngine();	// destructor

    bool getPairCollided();	 // retrieves value of pairCollided 
    void setPairCollided(bool set);  // sets value of pairCollided 

    bool getPassCollision();  // retrieves the value of passCollision 
    void setPassCollision(bool set);  // sets the value of passCollision 

    sharedPtr<btDynamicsWorld> getWorld();  // retrieves the value of world
    void setWorld(sharedPtr<btDynamicsWorld> set);  // sets the value of world

    bool setup();  // sets up the physicsEngine object

    void setupState(renderEngineSharedPtr render);  // sets up state of physics engine.

    void updateState();  // updates the state of the physics engine.
    void updatePositions();  // updates thr position of objects
    void stepWorld(timing time);  // steps the physics simulation

    void passCollisionCheck();  // checks whether the ball has collided with the player being passed to

    bool collisionCheck(btRigidBodySharedPtr objectA,btRigidBodySharedPtr objectB);  // tests whther or not two objects have collided

protected:

private:

    static sharedPtr<btDynamicsWorld> world;  // stores the physics world
    static sharedPtr<BtOgre::DebugDrawer> debugDraw;  // used to draw debug shapes for objects
    static sharedPtr<btBroadphaseInterface> broadPhase;
    static sharedPtr<btDefaultCollisionConfiguration> collisionConfig;
    static sharedPtr<btCollisionDispatcher> dispatcher;
    static sharedPtr<btSequentialImpulseConstraintSolver> solver;
    static btContactSolverInfo contactInfo;

    // timer variables
    btScalar changeInTime;  // stores the change in time between loops
    btScalar oldTime;  // stores the previous loops time

    bool pairCollided;  // determines if a pair of objects have collided

    bool passCollision;	// stores whether a ball has collided with player during a pass

    // shooting variables
    btVector3 beginShotPos;  // stores position of ball at the beginning of a shot
    btVector3 beginShotDistance;  // stores the distance between ball and hoop at a shot's beginning
    btVector3 beginShotForce;  // stores force applied to ball at beginning of shot
    btVector3 midShotPos;  // stores mid way position of ball during shot
    btVector3 endShotPos;  // stores end position of the ball during shot
    btVector3 forceToApply; // stores force to apply to ball during shot
    float maxShotHeight;  // stores maximum height of shot
    bool shotSet;  // determines whether a shot has been setup
    bool shotComplete;  // determines whethee a shot has been completed
    bool maxShotHeightReached;  // determines whether the maximum height has been reached
    bool forceToApplyXSet;  // determines if the force to apply to ball's x position has been set
    bool beginShotPosSet;  // determines if beginning shot position has been set
    bool midShotPosSet;  // determines if mid way position of shot has been set
    bool midShotPosReached;  // deetermines if mid way position of shot has been reached
    bool midShotXPosReached;  // determines if mid way X position of shot has been reached
    bool endShotPosSet;  // determines if end position of shot has been set
    bool shotCalcComplete;  // determines if shot has been calculated
};

struct MyContactResultCallback : public btCollisionWorld::ContactResultCallback
{
    bool m_connected;
    MyContactResultCallback() :m_connected(false)
    {
    }
//	  btScalar   addSingleResult(btManifoldPoint& cp, const btCollisionObject* colObj0, int partId0, int index0, const btCollisionObject* colObj1, int partId1, int index1)
    btScalar addSingleResult(btManifoldPoint& cp, const btCollisionObjectWrapper* colObj0Wrap, int partId0, int index0, const btCollisionObjectWrapper* colObj1Wrap, int partId1, int index1)
    {
        if (cp.getDistance() <= 0)
        {
            m_connected = true;
        }
        return 1.f;
    }
};


#endif // PHYSICS_H_INCLUDED
