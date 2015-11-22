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

bool physics::setupPhysics()  // sets up physics for the object
{
    return (false);
}

void physics::update()  // updates object physics state
{
    if (!setupComplete)
    {
        if (setupPhysics())  // sets up physics state for the object
        {
            setupComplete = true;
        }
        else
        {
        }
    }
    else
    {
    }
}
