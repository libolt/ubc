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

#ifndef _PLAYERGAMEDATA_H_
#define _PLAYERGAMEDATA_H_

#include "utilities/enums.h"

#include "OgreVector3.h"

class playerGameData
{
    public:
        playerGameData();  // constructor
        ~playerGameData();  // destructor

        playerPositions getActivePosition() const;  // retrieves the value of activePosition
        void setActivePosition(const playerPositions &set);  // sets the value of activePosition
   
        Ogre::Vector3 getCourtPosition() const;  // retrieves the value of courtPosition
        void setCourtPosition(const Ogre::Vector3 &set);  // sets the value of courtPosition
        
        std::vector<playerActions> getStateAction() const;  // retrieves the value of stateAction
        void setStateAction(const std::vector<playerActions> &set);  // sets the value of stateAction
        
        directions getDirection() const;  // retrieves the value of direction
        void setDirection(const directions &set);  // sets the value of direction

        directions getOldDirection() const;  // retrieves the value of oldDirection
        void setOldDirection(const directions &set);  // sets the value of oldDirection

        Ogre::Vector3 getPosChange() const;  // retrieves the value of posChange
        void setPosChange(const Ogre::Vector3 &set);  // sets the value of posChange

        playerPositions getPassToPlayer() const;  // retrieves the value of passToPlayer
        void setPassToPlayer(const playerPositions &set);  // sets the value of passToPlayer

        Ogre::Vector3 getJumpBeginPos() const;  // retrieves the value of playerJumpBeginPos
        void setJumpBeginPos(const Ogre::Vector3 &set);  // sets the value of playerJumpBeginPos

        Ogre::Vector3 getJumpEndPos() const;  // retrieves the value of playerJumpEndPos
        void setJumpEndPos(const Ogre::Vector3 &set);  // sets the value of playerJumpEndPos

        Ogre::Vector3 getNewCourtPosition() const;  // retrieves the value of newCourtPosition
        void setNewCourtPosition(const Ogre::Vector3 &set);  // sets the value of newCourtPosition

        positionChangedTypes getCourtPositionChangedType() const;  // retrieves the value of courtPositionChangedType
        void setCourtPositionChangedType(const positionChangedTypes &set);  // sets the value of courtPositionChangedType

    private:
    
        playerPositions activePosition;  // stores the active position of the player

        Ogre::Vector3 courtPosition;  // stores the position of the player on the court in an Ogre::Vector3
      
        directions direction;  // stores direction player is moving
        directions oldDirection;  // stores the previous player direction.

        Ogre::Vector3 posChange;  // stores value of players' position changes during logic updates

        playerPositions passToPlayer;  // stores the value of the player to be passed to.

        // player Jump variables
        Ogre::Vector3 jumpBeginPos;  // stores the coordinates of the player at the beginning of the jump
        Ogre::Vector3 jumpEndPos;  // stores the coordinates the player should reach at the end of the jump
    
        Ogre::Vector3 newCourtPosition;  // stores the upfated position of the player on the court in an Ogre::Vector3

        positionChangedTypes courtPositionChangedType;  // stores what subsystem changed the position of the player
    
        std::vector<playerActions> stateAction;  // controls the action performed by stateMachine

};
 
#endif
