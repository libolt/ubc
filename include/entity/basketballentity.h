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

#ifndef _BASKETBALLENTITY_H_
#define _BASKETBALLENTITY_H

#include "entity/entity.h"
//#include "physics/basketballphysics.h"
//#include "ai/basketballsteer.h"

//class entity;
class basketballData;
class basketballPhysics;
class basketballSteer;
class gameEntity;

class basketballEntity : public entity
{
    public:
    
    basketballEntity();  // constructor
    ~basketballEntity();  // destructor
    
    basketballComponentsSharedPtr getComponent() const;  // retrievees the value of component
    void setComponent(const basketballComponentsSharedPtr &set);  // sets the value of component

    basketballDataSharedPtr getData() const;  // retrievees the value of data
    void setData(const basketballDataSharedPtr &set);  // sets the value of data
    
    basketballFlagsSharedPtr getFlag() const;  // retrievees the value of flag
    void setFlag(const basketballFlagsSharedPtr &set);  // sets the value of flag

    basketballStateMachineSharedPtr getStateMachine() const;  // retrievees the value of stateMachine
    void setStateMachine(const basketballStateMachineSharedPtr &set);  // sets the value of stateMachine

    void updateState(const gameComponentsSharedPtr &gameComponent, const gameDataSharedPtr &gameDta, const gameFlagsSharedPtr &gameFlag);  // updates the state of the basketball
    
//    void updatePosition();  // updates the position of the basketball

//    void updateMovement(const gameComponentsSharedPtr &gameComponent, const gameDataSharedPtr &gameDta, const gameFlagsSharedPtr &gameFlag);  // updates the movement of basketball(s)
   
//    void updateDirection(const gameComponentsSharedPtr &gameComponent, const gameDataSharedPtr &gameDta, const gameFlagsSharedPtr &gameFlag);  // updates the direction of basketball(s)
    
    Ogre::Vector3 calculatePositionChange();  // calculates the change in position of the basketball model in x,y,z coordinates

    bool calculateShot();  // calculates the trajectory the basketball travels when shot
    bool shotLogic();  // handles the shot logic as the ball travels towards the hoop

    
    bool initializeStateMachine();  // initializes the basketball stateMachine object

    bool setupPhysicsObject();  // sets up the physics object
    
    private:
    
    basketballComponentsSharedPtr component;  // basketball components object
    basketballDataSharedPtr data;  // basketball data object
    basketballFlagsSharedPtr flag;  // basketball flags object
    basketballStateMachineSharedPtr stateMachine;  // basketball stateMachine object

    
};
 
#endif
