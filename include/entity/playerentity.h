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

#ifndef _PLAYERENTITY_H_
#define _PLAYERENTITY_H_

//#include "ai/playersteer.h"
#include "entity/entity.h"
#include "physics/playerphysics.h"
//class entity;
//class playerPhysics;

class playerData;
class playerStateMachine;
class playerSteer;


class playerEntity : public entity
{
    public:
    playerEntity();  // constructor
    ~playerEntity();  // destructor

    sharedPtr<playerStateMachine> getStateMachine();  // retrieves the value of stateMachine
    void setStateMachine(sharedPtr<playerStateMachine> set);  // sets the value of stateMachine
    
    sharedPtr<playerData> getData();  // retrieves the value of data
    void setData(sharedPtr<playerData> set);  // sets the value of data

    sharedPtr<playerPhysics> getPhysics();  // retrieves the value of physics
    void setPhysics(sharedPtr<playerPhysics> set);  // sets the value of physics

    playerSteerSharedPtr getSteer();  // retrieves the value of steer
    void setSteer(playerSteerSharedPtr set);  // sets the value of steer

    bool getSteerInitialized();  // retrieves the value of steerInitialized
    void setSteerInitialized(bool set);  // sets the value of steerInitialized

    bool getInitialized();  // retrieves the value of initialized
    void setInitialized(bool set);  // sets the value of initialized

    playerPositions getActivePosition();  // retrieves the value of activePosition
    void setActivePosition(playerPositions set);  // sets the value of activePosition
   
    Ogre::Vector3 getCourtPosition();  // retrieves the value of courtPosition
    void setCourtPosition(Ogre::Vector3 set);  // sets the value of courtPosition
    
    bool initialize();  // initializes the court entity object

    bool setupPhysicsObject();  // sets up the physics object
 
    private:

    sharedPtr<playerData> data;  // instance of playerData object

    sharedPtr<playerStateMachine> stateMachine;  // instance of playerStateMachine object

    sharedPtr<playerPhysics> physics;  // instance of playerPhysics object

    playerSteerSharedPtr steer;  // stores the steering objerct that represents the player
    bool steerInitialized; // stores whether the steer object has been initialized
    bool initialized;  // stores whether the player entity object has been initialized

    playerPositions activePosition;  // stores the active position of the player

    Ogre::Vector3 courtPosition;  // stores the position of the player on the court in an Ogre::Vector3

};

#endif // _PLAYERENTITY_H_
