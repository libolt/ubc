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

#include <vector>

#include "BtOgrePG.h"
#include "BtOgreGP.h"
#include "BtOgreExtras.h"
#include "BulletDynamics/Dynamics/btRigidBody.h"
#include <boost/shared_ptr.hpp>

#include "enums.h"

class physicsEngine
{
public:
    //static physicsEngine *Instance();
///    static boost::shared_ptr<physicsEngine> Instance();

    physicsEngine();  // constructor
    ~physicsEngine();	// destructor

    
    bool getBasketballlPhysicsSetup();  // retrieves the value of playerPhysicsSetup 
    void setBasketballPhysicsSetup(bool set);	 // sets the value of playerPhysicsSetup 

    bool getCourtPhysicsSetup();  // retrieves the value of courtPhysicsSetup 
    void setCourtPhysicsSetup(bool set);  // sets the value of courtPhysicsSetup 

    bool getHoopPhysicsSetup();	 // retrieves the value of hoopPhysicsSetup 
    void setHoopPhysicsSetup(bool set);  // sets the value of hoopPhysicsSetup 

    bool getPairCollided();	 // retrieves value of pairCollided 
    void setPairCollided(bool set);  // sets value of pairCollided 

    bool getPassCollision();  // retrieves the value of passCollision 
    void setPassCollision(bool set);  // sets the value of passCollision 

    btVector3 getBasketballVelocity();  // retrieves the value of basketballVelocity
    void setBasketballVelocity(const btVector3 &set);  // sets the value of basketballVelocity

    bool getBasketballVelocitySet();  // retrieves the value of basketballVelocitySet
    void setBasketballVelocitySet(bool set);  // sets the value of basketballVelocitySet

    btDynamicsWorld *getWorld();  // retrieves the value of world
    void setWorld(btDynamicsWorld *set);  // sets the value of world


/*    size_t getTeam1CollidesWith();  // retrieves the value of team1CollidesWith
    void setTeam1CollidesWith(size_t set); // sets the vslue of team1CollidesWith
    
    size_t getTeam2CollidesWith();  // retrieves the value of team2CollidesWith
    void setTeam2CollidesWith(size_t set); // sets the vslue of team2CollidesWith
*/

    void setupState();  // sets up state of physics engine.

    // sets up object physics
//    bool setupCourtPhysics();  // sets up court physics
//    bool setupHoopPhysics();  // sets up hoop physics
    
    void updateState();  // updates the state of the physics engine.
    void updatePositions();  // updates thr position of objects
    void updateBasketballPosition();  // updates the position of basketball object(s)
    void updatePlayerPositions();  // updates the position of player objecgts
    void stepWorld();  // steps the physics simulation

//    void ballDribbling();  // simulates basketball dribble
    void passCollisionCheck();  // checks whether the ball has collided with the player being passed to

    bool collisionCheck(btRigidBody *objectA,btRigidBody *objectB);  // tests whther or not two objects have collided

    bool playerJump(teamTypes teamType, int playerID);  // calculates and executes player jumping in the air
    bool shootBasketball(teamTypes teamType, int playerID);  // calculates and executes basketball being shot
   
protected:

///    physicsEngine(const physicsEngine&);
///    physicsEngine &operator = (const physicsEngine&);

private:

    //static physicsEngine *pInstance;
///    static boost::shared_ptr<physicsEngine> pInstance;

    static btDynamicsWorld *world;  // stores the physics world
    BtOgre::DebugDrawer *debugDraw;  // used to draw debug shapes for objects
//    btAxisSweep3 *broadPhase;
    btBroadphaseInterface *broadPhase;  
    btDefaultCollisionConfiguration *collisionConfig;
    btCollisionDispatcher *dispatcher;
    btSequentialImpulseConstraintSolver *solver;
    btContactSolverInfo contactInfo;


    btCollisionShape *courtShape;  // stores the shape of the court object
//	btDefaultMotionState *courtBodyState;
    BtOgre::RigidBodyState *courtBodyState; // stores state of the court object
	
	// hoop
//	btCollisionShape *hoopShape;
//	BtOgre::RigidBodyState *hoopBodyState;
	
    // basketball
//    btRigidBody *basketballBody;
 //   btBvhTriangleMeshShape *basketballShape;

    btVector3 basketballVelocity;  // stores the velocity of the basketball
    bool basketballVelocitySet;  // stores whether the velocity of the basketball has been set

    // timer variables
    btScalar changeInTime;  // stores the change in time between loops
    btScalar oldTime;  // stores the previous loops time

    bool basketballPhysicsSetup; // determines whether all basketballs' physics bodies have been setup
    bool courtPhysicsSetup;  // determines whether the court's physics body has been setup
	bool hoopPhysicsSetup;  // determines whether all hoop' physics bodies have been setup
    bool pairCollided;  // determines if a pair of objects have collided

    bool passCollision;	// stores whether a ball has collided with player during a pass
    // contact result callback

    // collisions
    int courtCollidesWith;	// determines what the court collides with
    int hoopCollidesWith;  // determines what the hoop collides with
//    size_t team1CollidesWith;	// determines what team1 collides with
//    size_t team2CollidesWith;  // | COL_BBALL | COL_TEAM1;	// determiens what team2 collides with


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

    // Collision Callback
/*    struct MyContactResultCallback : public btCollisionWorld::ContactResultCallback
    {
//    	physicsEngine *physE = physicsEngine::Instance();
    	bool collision;
        MyContactResultCallback() : collision(false)
    	{
    	}
    //	btScalar addSingleResult(btManifoldPoint& cp,   const btCollisionObject* colObj0,int partId0,int index0,const btCollisionObject* colObj1,int partId1,int index1)
        btScalar addSingleResult(btManifoldPoint& cp,    const btCollisionObjectWrapper* colObj0Wrap,int partId0,int index0,const btCollisionObjectWrapper* colObj1Wrap,int partId1,int index1)
    	{
			
			Ogre::LogManager::getSingletonPtr()->logMessage("Checking Collision!!");

    		if (cp.getDistance()<=0)
    		{
				Ogre::LogManager::getSingletonPtr()->logMessage("Collision!!");
				collision = true;

//    			physE->setPairCollided(true);
    //		    exit(0);
    		}
    		else
    		{
				Ogre::LogManager::getSingletonPtr()->logMessage("No Collision!!");
				collision = false;
//    			physE->setPairCollided(false);
    		}
    		return 1.f;
    	}
    };*/

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
