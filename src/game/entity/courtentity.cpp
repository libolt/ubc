/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
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

#include "entity/courtentity.h"

courtEntity::courtEntity()  // constructor
{
//    physics = new courtPhysics;
}
courtEntity::~courtEntity()  // destructor
{

}

/*courtPhysics *courtEntity::getPhysics()  // retrieves the value of physics
{
    return (physics);
}
void courtEntity::setPhysics(courtPhysics *set)  // sets the value of physics
{
    physics = set;
}*/

bool courtEntity::setupPhysicsObject()  // sets up the physics object
{
    Ogre::Entity *tempModel = getModel().get();
    Ogre::SceneNode *tempNode = getNode().get();
    btRigidBody *tempPhysBody = getPhysBody().get();
    
    int collides = COL_BBALL | COL_TEAM1 | COL_TEAM2;
    setShapeType(BOX);
    setColObject(COL_COURT);
    setCollidesWith(collides);

    if (setupPhysics(&tempModel, &tempNode, &tempPhysBody))
    {
        setPhysicsSetup(true);
        setModel(OgreEntitySharedPtr(tempModel));
        setNode(OgreSceneNodeSharedPtr(tempNode));
        setPhysBody(btRigidBodySharedPtr(tempPhysBody));
        return (true);
    }
    else
    {
    } 
    return (false);
}
