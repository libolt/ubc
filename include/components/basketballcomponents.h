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

#ifndef _BASKETBALLCOMPONENTS_H_
#define _BASKETBALLCOMPONENTS_H_

#include "components/entitycomponents.h"
#include "utilities/enums.h"
#include "utilities/typedefs.h"

class basketballPhysics;

class basketballComponents : public entityComponents
{
    public:

        basketballComponents();  // constructor
        ~basketballComponents();  // destructor

        gameEntitySharedPtr getGameInstance() const;  // retrieves the value of gameS
        void setGameInstance(const gameEntitySharedPtr &set);  // sets the value of gameS

        float getMaxHeight() const;  //   retrieves the value of maxHeight
        void setMaxHeight(const float &set);  //   sets the value of maxHeight

        float getMinHeight()const;  // retrieves the value of minHeight
        void setMinHeight(const float &set);    // sets the value of minHeight

        size_t getRotate() const;  // retrieves the value of rotate
        void setRotate(const size_t &set);  // sets the value of rotate

        size_t getTeamNumber() const;  // retrieves the value of teamNumber
        void setTeamNumber(const size_t &set);  // sets the value of teamNumber

        size_t getPlayer() const;  // retrieves the value of player
        void setPlayer(const size_t &set);  // sets the value of player

        Ogre::Vector3 getVelocity() const;  // retrieves the value of Velocity
        void setVelocity(const Ogre::Vector3 &set);  // sets the value of Velocity

        Ogre::Vector3 getStartCoords() const;  // retreives the value of startCoords
        void setStartCoords(const Ogre::Vector3 &set);  // sets the value of startCoords

        courtEntityMSharedPtr getCourtInstance() const;  // retrieves the value of courtInstance
        void setCourtInstance(const courtEntityMSharedPtr &set);  // sets the value of courtInstance

        directions getDirection() const;  // retrieves the value of direction
        void setDirection(const directions &set);  // sets the value of direction

        directions getOldDirection() const;  // retrieves the value of oldDirection
        void setOldDirection(const directions &set);  // sets the value of oldDirection

        Ogre::Vector3 getCourtPosition() const;  // retrieves the value of courtPosition
        void setCourtPosition(const Ogre::Vector3 &set);  // sets the value of courtPosition

        Ogre::Vector3 getNewCourtPosition() const;  // retrieves the value of newCourtPosition
        void setNewCourtPosition(const Ogre::Vector3 &set);  // sets the value of newCourtPosition

        positionChangedTypes getCourtPositionChangedType() const;  // retrieves the value of courtPositionChangedType
        void setCourtPositionChangedType(const positionChangedTypes &set);  // sets the value of courtPositionChangedType

#ifdef BTOGRE_MYGUI_ENABLE
        sharedPtr<basketballPhysics> getPhysics() const;  // retrieves the value of physics
        void setPhysics(const sharedPtr<basketballPhysics> &set);  // sets the value of physics
#endif

        basketballSteerSharedPtr getSteer() const;  // retrieves the value of steer
        void setSteer(const basketballSteerSharedPtr &set);  // sets the value of steer

        size_t getNumber() const;  // retrieves the value of number
        void setNumber(const size_t &set);  // sets the value of number

    private:

        gameEntitySharedPtr gameInstance;  // the gameState object
        float maxHeight;  // stores the maximum height pf the basketball
        float minHeight;  // stores the value of the minimum height of the basketball
        size_t rotate;  // defines which way the basketball is rotated

        size_t teamNumber;   // defines which team has the basketball
        size_t player;  // defines which player has the basketball

        size_t number;  // stores the basketball object number

        Ogre::Vector3 velocity;  // speed at which the ball travels on x,y,z axes

        Ogre::Vector3 startCoords;  // stores the starting coordinates of the basketball
        courtEntityMSharedPtr courtInstance;  // storee the active courtInstance

        directions direction;  // stores direction the ball has been moved
        directions oldDirection;  // stores the previous direction of the ball

        // stores the position of the player on the court in an Ogre::Vector3
        Ogre::Vector3 courtPosition;

        // stores the upfated position of the player on the court in an Ogre::Vector3
        Ogre::Vector3 newCourtPosition;

        // stores what subsystem changed the position of the baskteball
        positionChangedTypes courtPositionChangedType;

#ifdef BTOGRE_MYGUI_ENABLE
        sharedPtr<basketballPhysics> physics;  // instanciates an object to handle the physics for the basketball
#endif
        basketballSteerSharedPtr steer;  // instance of the basketballSteer class

};

#endif // _BASKETBALLCOMPONENTS_H_
