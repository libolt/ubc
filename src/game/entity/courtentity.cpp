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
#include "physics/courtphysics.h"

courtEntity::courtEntity()  // constructor
{
    initialized = false;
//    physics = new courtPhysics;
}
courtEntity::~courtEntity()  // destructor
{

}

sharedPtr<courtPhysics> courtEntity::getPhysics()  // retrieves the value of physics
{
    return (physics);
}
void courtEntity::setPhysics(sharedPtr<courtPhysics> set)  // sets the value of physics
{
    physics = set;
}

bool courtEntity::getInitialized()  // retrieves the value of initialized
{
    return (initialized);
}
void courtEntity::setInitialized(bool set)  // sets the value of initialized
{
    initialized = set;
}

bool courtEntity::initialize()  // initializes the court entity object
{
    sharedPtr<courtPhysics> tempPhysics(new courtPhysics);
    physics = tempPhysics;

    return (true);
}

bool courtEntity::setupPhysicsObject()  // sets up the physics object
{
    OgreEntitySharedPtr tempModel = getModel();
    OgreSceneNodeSharedPtr tempNode = getNode();
    btRigidBody *tempPhysBody = getPhysics()->getPhysBody();
    btScalar restitution = 1.0f;
    btScalar friction = 15.5f;

    if (!getPhysics()->getGameSInitialized())
    {
        getPhysics()->setGameS(getBase()->getGameS());
        getPhysics()->setGameSInitialized(true);
    }
    
    getPhysics()->setMass(0.0f);
    getPhysics()->setRestitution(1.0f);
    getPhysics()->setFriction(15.5f);
    size_t collides = COL_BBALL | COL_PLAYER0 | COL_TEAM1 | COL_TEAM2;
    getPhysics()->setShapeType(BOX);
    getPhysics()->setColObject(COL_COURT);
    getPhysics()->setCollidesWith(collides);
//    exit(0);
    if (getPhysics()->setupPhysics(&tempModel, &tempNode, &tempPhysBody))
    {
//        tempPhysBody->setActivationState(DISABLE_SIMULATION);
        setPhysicsSetup(true);
        setModel(OgreEntitySharedPtr(tempModel));
        setNode(OgreSceneNodeSharedPtr(tempNode));
        getPhysics()->setPhysBody(tempPhysBody);
        return (true);
    }
    else
    {
    } 
//    getPhysics()->getPhysBody()->setActivationState(ACTIVE_TAG);

    return (false);
}
