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

#include "components/basketballcomponents.h"
#include "physics/basketballphysics.h"

basketballComponents::basketballComponents()  // constructor
{
    maxHeight = 0;
    minHeight = 0;
    direction = NODIRECT;
    oldDirection = NODIRECT;

    rotate = 0;

    velocity[0] = 0.0f;
    velocity[1] = 0.0f;
    velocity[2] = 0.0f;

    startCoords[0] = 0.0f;
    startCoords[1] = 0.0f;
    startCoords[2] = 0.0f;
    teamNumber = 0;
    player = 0;
    courtPosition = Ogre::Vector3(0,0,0);
    newCourtPosition = Ogre::Vector3(0,0,0);
    courtPositionChangedType = NOCHANGE;
    number = 999999;


}

basketballComponents::~basketballComponents() = default;  // destructor

sharedPtr<basketballPhysics> basketballComponents::getPhysics() const  // retrieves the value of physics
{
    return (physics);
}
void basketballComponents::setPhysics(const sharedPtr<basketballPhysics> &set)  // sets the value of physics
{
    physics = set;
}

basketballSteerSharedPtr basketballComponents::getSteer() const  // retrieves the value of steer
{
    return (steer);
}
void basketballComponents::setSteer(const basketballSteerSharedPtr &set)  // sets the value of steer
{
    steer = set;
}

gameEntitySharedPtr basketballComponents::getGameInstance() const  // retrieves the value of gameS
{
    return (gameInstance);
}
void basketballComponents::setGameInstance(const gameEntitySharedPtr &set)  // sets the value of gameS
{
    gameInstance = set;
}

float basketballComponents::getMaxHeight() const  // retrieves the value of maxHeight
{
    return(maxHeight);
}
void basketballComponents::setMaxHeight(const float &set)  // sets the value og maxHeight
{
    maxHeight = set;
}

float basketballComponents::getMinHeight() const  // retrieves the value minHeight
{
    return(minHeight);
}
void basketballComponents::setMinHeight(const float &set)  // sets the value of minHeight
{
    minHeight = set;
}

size_t basketballComponents::getRotate() const  // retrieves the value of rotate
{
    return (rotate);
}
void basketballComponents::setRotate(const size_t &set)  // sets the value of rotate
{
    rotate = set;
}

size_t basketballComponents::getTeamNumber() const  // retrieves the value of teamNumber
{
    return(teamNumber);
}
void basketballComponents::setTeamNumber(const size_t &set)  // sets the value of teamNumber
{
    teamNumber = set;
}

size_t basketballComponents::getPlayer() const
{
    return (player);
}

void basketballComponents::setPlayer(const size_t &Player)
{
    player = Player;
}

Ogre::Vector3 basketballComponents::getVelocity() const  // retrieves the value of velocity
{
    return(velocity);
}
void basketballComponents::setVelocity(const Ogre::Vector3 &set)  // sets the value of velocity
{
    velocity = set;
}

Ogre::Vector3 basketballComponents::getStartCoords() const  // retrieves the value of startCoords
{
    return(startCoords);
}
void basketballComponents::setStartCoords(const Ogre::Vector3 &set) // sets the value of startCoords
{
    startCoords = set;
}

courtEntityMSharedPtr basketballComponents::getCourtInstance() const  // retrieves the value of courtInstance
{
    return (courtInstance);
}
void basketballComponents::setCourtInstance(const courtEntityMSharedPtr &set)  // sets the value of courtInstance
{
    courtInstance = set;
}

directions basketballComponents::getDirection() const  // retrieves the value of direction
{
    return (direction);
}
void basketballComponents::setDirection(const directions &set)  // sets the value of direction
{
    direction = set;
}

directions basketballComponents::getOldDirection() const  // retrieves the value of oldDirection
{
    return (oldDirection);
}
void basketballComponents::setOldDirection(const directions &set)  // sets the value of oldDirection
{
    oldDirection = set;
}

Ogre::Vector3 basketballComponents::getCourtPosition() const  // retrieves the value of courtPosition
{
    return (courtPosition);
}
void basketballComponents::setCourtPosition(const Ogre::Vector3 &set)  // sets the value of courtPosition
{
    courtPosition = set;
}

Ogre::Vector3 basketballComponents::getNewCourtPosition() const  // retrieves the value of newCourtPosition
{
    return (newCourtPosition);
}
void basketballComponents::setNewCourtPosition(const Ogre::Vector3 &set)  // sets the value of newCourtPosition
{
    newCourtPosition = set;
}

positionChangedTypes basketballComponents::getCourtPositionChangedType() const  // retrieves the value of courtPositionChangedType
{
    return (courtPositionChangedType);
}
void basketballComponents::setCourtPositionChangedType(const positionChangedTypes &set)  // sets the value of courtPositionChangedType
{
    courtPositionChangedType = set;
}

size_t basketballComponents::getNumber() const  // retrieves the value of number
{
    return (number);
}
void basketballComponents::setNumber(const size_t &set)  // sets the value of number
{
    number = set;
    physics->setPhysObjNumber(set); // sets the physics number as well
//    numberSet = true;
}

