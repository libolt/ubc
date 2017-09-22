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
class playerSMData;
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

    bool getStateMachineInitialized();  // retrieves the value of stateMachineInitialized
    void setStateMachineInitialized(bool set);  // sets the value of stateMachineInitialized
    
    bool getStateChanged();  // retrieves the value of stateChanged
    void setStateChanged(bool set);  // sets the value of stateChanged
    
    playerActions getStateAction();  // retrieves the value of stateAction
    void setStateAction(playerActions set);  // sets the value of stateAction
    
    // playerState code that will likely be refactored
    bool getMovement();  // retrieves the value of movement
    void setMovement(bool set);  // sets the value of movement

    directions getDirection();  // retrieves the value of direction
    void setDirection(directions set);  // sets the value of direction

    directions getOldDirection();  // retrieves the value of oldDirection
    void setOldDirection(directions set);  // sets the value of oldDirection

    Ogre::Vector3 getPosChange();  // retrieves the value of posChange
    void setPosChange(Ogre::Vector3 set);  // sets the value of posChange

    bool getStartPosReached();  // retrieves the value of startPosReached
    void setStartPosReached(bool set);  // sets the value of startPosReached

    bool getShootBlock();  // retrieves the value of shootBlock
    void setShootBlock(bool set);  // sets the value of shootBlock

    bool getPassSteal();  // retrieves the value of passSteal
    void setPassSteal(bool set);  // sets the value of passSteal

    bool getPassBall();  // retrieves the value of passBall
    void setPassBall(bool set);  // sets the value of passBall

    bool getPassCalculated();  // retrieves the value of passCalculated
    void setPassCalculated(bool set);  // sets the value of passCalculated

    bool getPassCompleted();  // retrieves the value of passCompleted
    void setPassCompleted(bool set);  // sets the value of passCompleted

    playerPositions getPassToPlayer();  // retrieves the value of passToPlayer
    void setPassToPlayer(playerPositions set);  // sets the value of passToPlayer

    bool getShotTaken();  // retrieves the value of shotTaken
    void setShotTaken(bool set);  // sets the value of shotTaken

    bool getShotSet();  // retrieves the value of shotSet
    void setShotSet(bool set);  // sets the value of shotSet

    bool getShotComplete();  // retrieves the value of shotComplete
    void setShotComplete(bool set);  // sets the value of shotComplete

    Ogre::Vector3 getJumpBeginPos();  // retrieves the value of playerJumpBeginPos
    void setJumpBeginPos(Ogre::Vector3 set);  // sets the value of playerJumpBeginPos

    Ogre::Vector3 getJumpEndPos();  // retrieves the value of playerJumpEndPos
    void setJumpEndPos(Ogre::Vector3 set);  // sets the value of playerJumpEndPos

    bool getJumpSet();  // retrieves the value of jumpSet
    void setJumpSet(bool set);  // sets the value of jumpSet

    bool getJumpComplete();  // retrieves the value of jumpComplete
    void setJumpComplete(bool set);  // sets the value of jumpComplete

    bool getOffenseSet();  // retrieves the value of offenseSet
    void setOffenseSet(bool set);  // sets the value of offenseSet

    bool getDefenseSet();  // retrieves the value of defenseSet
    void setDefenseSet(bool set);  // sets the value of defenseSet

/*        Ogre::Vector3 getCourtPosition();  // retrieves the value of courtPosition
    void setCourtPosition(Ogre::Vector3 set);  // sets the value of courtPosition
*/
    Ogre::Vector3 getNewCourtPosition();  // retrieves the value of newCourtPosition
    void setNewCourtPosition(Ogre::Vector3 set);  // sets the value of newCourtPosition

    bool getCourtPositionChanged();  // retrieves the value of courtPositionChanged
    void setCourtPositionChanged(bool set);  // sets the value of courtPositionChanged

    positionChangedTypes getCourtPositionChangedType();  // retrieves the value of courtPositionChangedType
    void setCourtPositionChangedType(positionChangedTypes set);  // sets the value of courtPositionChangedType

    bool initialize();  // initializes the court entity object

    bool setupPhysicsObject();  // sets up the physics object
 
    bool initializeStateMachine();  // initializes the stateMachine object
    
    bool updateStateMachine(playerActions actionType, playerSMData *SMData);  // updates state machine with external input
    
    bool update(); // executes any updates that need to be performed
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
  
    bool movement; // if true then player is moving

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

    bool physBodyInitialized;  // Determines whether or not the btRigidBody object has been initialized

    bool stateMachineInitialized;   // Determines whether or not the stateMachine object has been initialized

    bool stateChanged;  // determines if the stateMachine needs to be updated
    
    playerActions stateAction;  // controls the action performed by stateMachine
};

#endif // _PLAYERENTITY_H_
