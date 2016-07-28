/**************************************p*************************************
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

#include "entity/basketballentity.h"

basketballEntity::basketballEntity()  // constructor
{
//  physics = new basketballPhysics;
}
basketballEntity::~basketballEntity()  // destructor
{
    
}

/*basketballPhysics *basketballEntity::getPhysics()  // retrieves the value of physics
{
    return (physics);
}
void basketballEntity::setPhysics(basketballPhysics *set)  // sets the value of physics
{
    physics = set;
}*/

boost::shared_ptr<basketballSteer> basketballEntity::getSteer()  // retrieves the value of steer
{
    return (steer);
}
void basketballEntity::setSteer(boost::shared_ptr<basketballSteer> set)  // sets the value of steer
{
    steer = set;
}

bool basketballEntity::setupPhysicsObject()  // sets up the physics object
{
    Ogre::Entity *tempModel = getModel().get();
    Ogre::SceneNode *tempNode = getNode().get();
    btRigidBody *tempPhysBody = getPhysBody().get();
    setShapeType(SPHERE);
    setColObject(COL_BBALL);
    setCollidesWith(COL_COURT);

    if (setupPhysics(&tempModel, &tempNode, &tempPhysBody))
    {
        setPhysicsSetup(true);
        
        setModel(boost::shared_ptr<Ogre::Entity>(tempModel));
        setNode(boost::shared_ptr<Ogre::SceneNode>(tempNode));
        setPhysBody(boost::shared_ptr<btRigidBody>(tempPhysBody));
//        exit(0);
        return (true);
    }
    else
    {
    }

    return (false);
}
