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

#ifndef _PHYSICS_H_
#define _PHYSICS_H_

#include "BtOgrePG.h"
#include "BtOgreGP.h"
#include "BtOgreExtras.h"
#include "BulletDynamics/Dynamics/btRigidBody.h"

#include "physics/physicsengine.h"
#include "enums.h"

class physics : public physicsEngine
{
    public:
        physics();  // constructor
        ~physics();  // destructor

        btCollisionShape *getShape();  // retrieves the value of shape
        void setShape(btCollisionShape *set);  // sets the value of shape

        BtOgre::RigidBodyState *getBodyState();  // retrieves the value of bodyState
        void setBodyState(BtOgre::RigidBodyState *set);  // sets the value of bodyState

        physicsShapes getShapeType();  // retrieves the value of shapeType
        void setShapeType(physicsShapes set);  // sets the value of shapeType
       
        int getColObject();  // retrieves the value of colObject
        void setColObject(int set);  // sets the value of colObject
 
        int getCollidesWith();  // retrieves the value of collidesWith
        void setCollidesWith(int set);  // sets the value of collidesWith

        size_t getNumber();  // retrieves the value of number
        void setNumber(size_t set);  // sets the value of number

        bool getSetupComplete();  // retrieves the value of physicsSetup
        void setSetupComplete(bool set);  // sets the value of physicsSetup

        bool setupPhysics(Ogre::Entity **model, Ogre::SceneNode **node, btRigidBody **physBody);  // sets up object physics

        bool setup();  // sets up the object

        void update();  // updates the object

    private:

        btCollisionShape *shape;  // stores the shape of the object shape
        BtOgre::RigidBodyState *bodyState;  // stores the state of the body objectt

        physicsShapes shapeType;  // stores what type of shape to create 
        
        size_t entityInstance;  // stores which instance of the entity object(s) to use for shape
        
        int colObject;  // stores the type of collision object

        int collidesWith;	// determines what the object collides with

        bool setupComplete;  // stores whether the basketblal physics have been setup.

        size_t number;  // stores the number of the object

};

#endif // _PHYSICS_H_