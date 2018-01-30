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

#ifndef _PHYSICS_H_
#define _PHYSICS_H_

#include "BtOgrePG.h"
#include "BtOgreGP.h"
#include "BtOgreExtras.h"
#include "BulletDynamics/Dynamics/btRigidBody.h"
#include "state/gamestateshared.h"

#include "utilities/enums.h"

class physicsEngine;

class physics
{
    public:
        physics();  // constructor
        ~physics();  // destructor

        gameStateSharedPtr getGameS();  // retrieves the value of gameS
        void setGameS(gameStateSharedPtr set);  // sets the value of gameS
        
        bool getGameSInitialized(); // retrieves the value of gameSInitialized
        void setGameSInitialized(bool set);  // sets the value of gameSInitialized

        physicsEngineSharedPtr getPhysE();  // retrieves the value of physE
        void setPhysE(physicsEngineSharedPtr set);  // sets the value of physE

        bool getPhysEInitialized(); // retrieves the value of physEInitialized
        void setPhysEInitialized(bool set);  // sets the value of physEInitialized

        btCollisionShape *getShape();  // retrieves the value of shape
        void setShape(btCollisionShape *set);  // sets the value of shape

        BtOgre::RigidBodyState *getBodyState();  // retrieves the value of bodyState
        void setBodyState(BtOgre::RigidBodyState *set);  // sets the value of bodyState

        physicsShapes getShapeType();  // retrieves the value of shapeType
        void setShapeType(physicsShapes set);  // sets the value of shapeType
 
        btRigidBodySharedPtr getPhysBody();  // retrieves the value of physBody
        void setPhysBody(btRigidBodySharedPtr set);  // sets the value of physBody

        std::unordered_map<std::string, btRigidBodySharedPtr> getCollisionBodies();  // retrieves the value of collisionBodies
        void setCollisionBodies(std::unordered_map<std::string, btRigidBodySharedPtr> set);  // sets the value of collisionBodies

        btScalar getMass();  // retrieves the value of mass
        void setMass(btScalar set);  // sets the value of mass
        
        btVector3 getInertia();  // retrieves the value of inertia
        void setInertia(btVector3 set);  // sets the value of inertia
  
        btScalar getRestitution();  // retrieves the value of restitution
        void setRestitution(btScalar set);  // sets the value of restitution

        btScalar getFriction();  // retrieves the value of friction
        void setFriction(btScalar set);  // sets the value of friction
      
        btScalar getVelocity();  // retrieves the value of velocity
        void setVelocity(btScalar set);  // sets the value of velocity
        
        bool getVelocitySet();  // retrieves the value of velocitySet
        void setVelocitySet(bool set);  // sets the value of velocitySet

        size_t getColObject();  // retrieves the value of colObject
        void setColObject(size_t set);  // sets the value of colObject
 
        size_t getCollidesWith();  // retrieves the value of collidesWith
        void setCollidesWith(size_t set);  // sets the value of collidesWith

        size_t getPhysObjNumber();  // retrieves the value of number
        void setPhysObjNumber(size_t set);  // sets the value of number

        bool setupPhysics(OgreEntitySharedPtr *model, OgreSceneNodeSharedPtr *node, btRigidBody **body);  // sets up object physics

        bool setup();  // sets up the object

        void updatePhysObj();  // updates the object

    private:

        static gameStateSharedPtr gameS;  // stores a copy of gameState object
        bool gameSInitialized;  // stores whether the gameState object has been initialized

        static physicsEngineSharedPtr physE;  // physics engine object

        bool physEInitialized;  // stores whether the physics engine object has been initialized

        btCollisionShape *shape;  // stores the shape of the object shape
        BtOgre::RigidBodyState *bodyState;  // stores the state of the body objectt

        physicsShapes shapeType;  // stores what type of shape to create 
        
        btRigidBodySharedPtr physBody;  // stores the physics object that represents the player

        std::unordered_map<std::string, btRigidBodySharedPtr> collisionBodies;  // physical bodies to test for collisions with physBody

        btScalar mass;  // stores the mass of the object;
        
        btVector3 inertia;  // stores the inertia of the object  
        
        btScalar restitution;  // stores the restitution of the object
        
        btScalar friction;  // stores the mass of the object
        
        btScalar velocity;  // stores the velocity of the object 
        
        bool velocitySet;  // stores whether object velocity has been set
        
        size_t entityInstance;  // stores which instance of the entity object(s) to use for shape
        
        size_t colObject;  // stores the type of collision object

        size_t collidesWith;	// determines what the object collides with

//        bool setupComplete;  // stores whether the basketblal physics have been setup.

        size_t physObjNumber;  // stores the number of the object

};

#endif // _PHYSICS_H_
