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

#ifndef _PLAYERENTITY_H_
#define _PLAYERENTITY_H_

#include "entity/entity.h"
#include "physics/playerphysics.h"

class playerData;
class playerFlags;
class playerStateMachine;
class playerSMData;
class playerStatistics;
class playerSteer;


class playerEntity : public entity
{
    public:
    playerEntity();  // constructor
    ~playerEntity();  // destructor
    
    playerDataSharedPtr getData();  // retrieves the value of data
    void setData(playerDataSharedPtr set);  // sets the value of data

    playerFlagsSharedPtr getFlag();  // retrieves the value of flag
    void setFlag(playerFlagsSharedPtr set);  // sets the value of flag

    playerPhysicsSharedPtr getPhysics();  // retrieves the value of physics
    void setPhysics(playerPhysicsSharedPtr set);  // sets the value of physics

    playerStateMachineSharedPtr getStateMachine();  // retrieves the value of stateMachine
    void setStateMachine(playerStateMachineSharedPtr set);  // sets the value of stateMachine

    sharedPtr<playerStatisticsSharedPtr getStatistics();  // retrieves the value of statistics
    void setStatistics(playerStatisticsSharedPtr set);  // sets the value of statistics

    playerSteerSharedPtr getSteer();  // retrieves the value of steer
    void setSteer(playerSteerSharedPtr set);  // sets the value of steer

    playerPositions getActivePosition();  // retrieves the value of activePosition
    void setActivePosition(playerPositions set);  // sets the value of activePosition
   
    Ogre::Vector3 getCourtPosition();  // retrieves the value of courtPosition
    void setCourtPosition(Ogre::Vector3 set);  // sets the value of courtPosition
        
    std::vector<playerActions> getStateAction();  // retrieves the value of stateAction
    void setStateAction(std::vector<playerActions> set);  // sets the value of stateAction
    
    directions getDirection();  // retrieves the value of direction
    void setDirection(directions set);  // sets the value of direction

    directions getOldDirection();  // retrieves the value of oldDirection
    void setOldDirection(directions set);  // sets the value of oldDirection

    Ogre::Vector3 getPosChange();  // retrieves the value of posChange
    void setPosChange(Ogre::Vector3 set);  // sets the value of posChange

    playerPositions getPassToPlayer();  // retrieves the value of passToPlayer
    void setPassToPlayer(playerPositions set);  // sets the value of passToPlayer

    Ogre::Vector3 getJumpBeginPos();  // retrieves the value of playerJumpBeginPos
    void setJumpBeginPos(Ogre::Vector3 set);  // sets the value of playerJumpBeginPos

    Ogre::Vector3 getJumpEndPos();  // retrieves the value of playerJumpEndPos
    void setJumpEndPos(Ogre::Vector3 set);  // sets the value of playerJumpEndPos

    Ogre::Vector3 getNewCourtPosition();  // retrieves the value of newCourtPosition
    void setNewCourtPosition(Ogre::Vector3 set);  // sets the value of newCourtPosition

    positionChangedTypes getCourtPositionChangedType();  // retrieves the value of courtPositionChangedType
    void setCourtPositionChangedType(positionChangedTypes set);  // sets the value of courtPositionChangedType

    bool initialize();  // initializes the court entity object

    bool setupPhysicsObject();  // sets up the physics object
 
    bool initializeStateMachine();  // initializes the stateMachine object
    
    bool updateStateMachine(playerActions actionType, playerSMData *SMData);  // updates state machine with external input
    
    bool update(); // executes any updates that need to be performed

    private:

    playerDataSharedPtr data;  // instance of playerData object
    
    playerFlagsSharedPtr flag;  // instance of playerFlags object

    playerStateMachineSharedPtr stateMachine;  // instance of playerStateMachine object

    playerPhysicsSharedPtr physics;  // instance of playerPhysics object

    playerStatisticsSharedPtr statistics;  // instance of playerStatistics object

    playerSteerSharedPtr steer;  // stores the steering objerct that represents the player

    playerPositions activePosition;  // stores the active position of the player

    Ogre::Vector3 courtPosition;  // stores the position of the player on the court in an Ogre::Vector3
    
    // playerState data that will eventually be refactored
  
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

#endif // _PLAYERENTITY_H_
