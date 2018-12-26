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
    
    sharedPtr<basketballData> getData() const;  // retrievees the value of data
    void setData(const sharedPtr<basketballData> &set);  // sets the value of data
    
    void updateState(const gameComponentsSharedPtr &gameComponent, const gameDataSharedPtr &gameDta, const gameFlagsSharedPtr &gameFlag);  // updates the state of the basketball
    
    void updatePosition();  // updates the position of the basketball

    void updateMovement(const gameComponentsSharedPtr &gameComponent, const gameDataSharedPtr &gameDta, const gameFlagsSharedPtr &gameFlag);  // updates the movement of basketball(s)
   
    void updateDirection(const gameComponentsSharedPtr &gameComponent, const gameDataSharedPtr &gameDta, const gameFlagsSharedPtr &gameFlag);  // updates the direction of basketball(s)
    
    Ogre::Vector3 calculatePositionChange();  // calculates the change in position of the basketball model in x,y,z coordinates

    bool calculateShot();  // calculates the trajectory the basketball travels when shot
    bool shotLogic();  // handles the shot logic as the ball travels towards the hoop

    
    bool initialize();  // initializes the basketball entity object

    bool setupPhysicsObject();  // sets up the physics object
    
    private:
    
    sharedPtr<basketballData> data;

};
 
#endif
