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
class playerStatistics;
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

    sharedPtr<playerStatistics> getStatistics();  // retrieves the value of statistics
    void setStatistics(sharedPtr<playerStatistics> set);  // sets the value of statistics

    bool getSteerInitialized();  // retrieves the value of steerInitialized
    void setSteerInitialized(bool set);  // sets the value of steerInitialized

    bool getInitialized();  // retrieves the value of initialized
    void setInitialized(bool set);  // sets the value of initialized

    playerPositions getActivePosition();  // retrieves the value of activePosition
    void setActivePosition(playerPositions set);  // sets the value of activePosition
   
    Ogre::Vector3 getCourtPosition();  // retrieves the value of courtPosition
    void setCourtPosition(Ogre::Vector3 set);  // sets the value of courtPosition
    
    bool getPhysBodyInitialized();  // retrieves the value of physBodyInitialized
    void setPhysBodyInitialized(bool set);  // sets the value of physBodyInitialized

    bool initialize();  // initializes the court entity object

    bool setupPhysicsObject();  // sets up the physics object
 
    private:

    sharedPtr<playerData> data;  // instance of playerData object

    sharedPtr<playerStateMachine> stateMachine;  // instance of playerStateMachine object

    sharedPtr<playerPhysics> physics;  // instance of playerPhysics object

    sharedPtr<playerStatistics> statistics;  // instance of playerStatistics object

    playerSteerSharedPtr steer;  // stores the steering objerct that represents the player
    bool steerInitialized; // stores whether the steer object has been initialized
    bool initialized;  // stores whether the player entity object has been initialized

    playerPositions activePosition;  // stores the active position of the player

    Ogre::Vector3 courtPosition;  // stores the position of the player on the court in an Ogre::Vector3
    
        // playerState data that will eventually be refactored
  
    directions direction;  // stores direction player is moving
    directions oldDirection;  // stores the previous player direction.

    Ogre::Vector3 posChange;  // stores value of players' position changes during logic updates

    bool startPosReached;  // stores whether a player is in the starting position for tipoff
       
    // variables for offense and defense;
    bool shootBlock;  // stores whether or not a player attempts to shoot or block a shot
    bool passSteal;  // stores whether a player attempts to pass or steal the ball

    // Passing variables
    bool passBall;  // stores whether a player is to pass the ball to another player or not.
    bool passCalculated;  // stores whether or not the player to pass ball to has been calculated
    bool passCompleted;  // stores whether or not the pass has been completed
    playerPositions passToPlayer;  // stores the value of the player to be passed to.

    // Shooting variables
    bool shotTaken;  // Determines whether or not a player has shot the ball
    bool shotSet;  // Determines if shot has been setup
    bool shotComplete;  // Determine whether or not a player's shot is complete

    // player Jump variables
    Ogre::Vector3 jumpBeginPos;  // stores the coordinates of the player at the beginning of the jump
    Ogre::Vector3 jumpEndPos;  // stores the coordinates the player should reach at the end of the jump
    bool jumpSet;  // determines whether or not the playerJumpBeginPos has been set
    bool jumpComplete;  // determines whether or not the jump has been completed

    bool offenseSet;  // tracks state of player's offense
    bool defenseSet;  // tracks state of player's defense

//        Ogre::Vector3 courtPosition;  // stores the position of the player on the court in an Ogre::Vector3

    Ogre::Vector3 newCourtPosition;  // stores the upfated position of the player on the court in an Ogre::Vector3
        
    bool courtPositionChanged;  // if the court position has changed then this flag is set

    positionChangedTypes courtPositionChangedType;  // stores what subsystem changed the position of the player

//    bool physBodyInitialized;  // Determines whether or not the btRigidBody object has been initialized

};

#endif // _PLAYERENTITY_H_
