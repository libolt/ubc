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

#ifndef _BASKETBALLPHYSICS_H_
#define _BASKETBALLPHYSICS_H_

#include "BtOgrePG.h"
#include "BtOgreGP.h"
#include "BtOgreExtras.h"
#include "BulletDynamics/Dynamics/btRigidBody.h"

#include "OgreVector3.h"
#include "physics/physics.h"

//class physics;

class basketballPhysics : public physics
{
    public:

        basketballPhysics();  // initializer

        bballBounces getBounce() const;  // retrieves value of bounce
        void setBounce(const bballBounces &set);  // sets the value of bounce
        
        bool setup();  // sets up basketball physics


        bool setupState();  // sets up the state of the basketballPhysics object

        void updateState();  // updates the basketball physics state

        void ballDribbling(Ogre::Vector3 bballPos,
                           const btRigidBodySharedPtr &courtPhysBody,
                           Ogre::Vector3 courtPos);  // simulates basketball dribble

        void updatePosition();  // updates the position of basketball object(s)

    private:

        bballBounces bounce;  // stores bounce state of the ball
        
/*        btCollisionShape *shape;  // stores the shape of the basketball shape
        BtOgre::RigidBodyState *basketballBodyState;  // stores the state of the basketball

        int bballCollidesWith;	// determines what the basketball collides with

        bool physicsSetup;  // stores whether the basketblal physics have been setup.

        size_t number;  // stores the number of the object

        bool stateSet;  // if true then the basketball physics state has been set
*/
};
#endif // _BASKETBALLPHYSICS_H_

