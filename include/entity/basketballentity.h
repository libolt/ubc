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

#ifndef _BASKETBALLENTITY_H_
#define _BASKETBALLENTITY_H

#include "entity/entity.h"
//#include "physics/basketballphysics.h"
//#include "ai/basketballsteer.h"

//class entity;
class basketballPhysics;
class basketballSteer;

class basketballEntity : public entity
{
    public:
    
    basketballEntity();  // constructor
    ~basketballEntity();  // destructor
    
    sharedPtr<basketballPhysics> getPhysics();  // retrieves the value of physics
    void setPhysics(sharedPtr<basketballPhysics> set);  // sets the value of physics

    basketballSteerSharedPtr getSteer();  // retrieves the value of steer
    void setSteer(basketballSteerSharedPtr set);  // sets the value of steer

    bool getInitialized();  // retrieves the value of initialized
    void setInitialized(bool set);  // sets the value of initialized

    bool initialize();  // initializes the basketball entity object

    bool setupPhysicsObject();  // sets up the physics object
    
    private:

    bool initialized;  // stores whether the basketball entity object has been initialized

    sharedPtr<basketballPhysics> physics;  // instanciates an object to handle the physics for the basketball

    basketballSteerSharedPtr steer;  // instance of the basketballSteer class

};
 
#endif
