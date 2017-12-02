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

#ifndef _BASKETBALLS_H_
#define _BASKETBALLS_H_

#ifdef __APPLE__
#include <Ogre/Ogre.h>
#include <Ogre/OgreVector3.h>
#else
#include "Ogre.h"
#include "OgreVector3.h"
#endif

#include <string>

#include "BtOgrePG.h"
#include "BtOgreGP.h"
#include "BtOgreExtras.h"

//#include "entity/basketballentity.h"
//#include "ai/basketballsteer.h"
//#include "physics/basketballphysics.h"
#include "utilities/enums.h"
#include "state/state.h"
#include "state/gamestateshared.h"
//#include "state/playerstate.h"
//#include "state/courtstate.h"
//#include "data/basketballdata.h"

//class basketballEntity;
class basketballData;
class basketballEntity;
class basketballPhysics;
class state;
class playerState;
class courtState;

class basketballState : public state
{
public:

    basketballState();  // constructor
    ~basketballState();	// destructor

    gameStateSharedPtr getGameS();  // retrieves the value of gameS
    void setGameS(gameStateSharedPtr set);  // sets the value of gameS

    sharedPtr<basketballData> getData();  // retrievees the value of data
    void setData(sharedPtr<basketballData> set);  // sets the value of data

    basketballEntitySharedPtr getEntity();  // retrieves the value of entity
    void setEntity(basketballEntitySharedPtr set);  // sets the value of entity

    bool getEntityInitialized();  // retrieves the value of entityInitialized
    void setEntityInitialized(bool set);  // sets the value of entityInitialized

    bool getInitialized();  // retrieves the value of initialized
    void setInitialized(bool set);  // sets the value of initialized

    float getMaxHeight();  //	retrieves the value of maxHeight
    void setMaxHeight(float set);  //	sets the value of maxHeight

    bool getMaxHeightReached();  // retrieves the value of maxHeightReached
    void setMaxHeightReached(bool set);  //	sets the value of maxHeightReached

    float getMinHeight();  // retrieves the value of minHeight
    void setMinHeight(float set);	 //	sets the value of minHeight

    bool getMinHeightReached();  // retrieves the value of minHeightReached
    void setMinHeightReached(bool set);  // sets minHeightReached

    size_t getRotate();  // retrieves the value of rotate
    void setRotate(size_t set);	 // sets the value of rotate

    size_t getTeamNumber();  // retrieves the value of teamNumber
    void setTeamNumber(size_t set);  // sets the value of teamNumber

    size_t getPlayer();  // retrieves the value of player
    void setPlayer(size_t set);	 // sets the value of player

    Ogre::Vector3 getVelocity();  // retrieves xVelocity value
    void setVelocity(Ogre::Vector3 set);  // sets xVelocity value

    Ogre::Vector3 getStartCoords();	 // retreives the value of startCoords
    void setStartCoords(Ogre::Vector3 set);  // sets the value of startCoords

    bool getTipOffStart();  // retrieves the value of tipOffStart
    void setTipOffStart(bool set);  // sets the value of tipOFfStart

    bool getTipOff();  // retrieves the value of tipOff
    void setTipOff(bool set);  // sets the value of tipOff

    bool getDribblingStart();  // retrieves the value of dribblingStart
    void setDribblingStart(bool set);  // sets the value of dribblingStart

    bool getDribbling();  // retrieves the value of dribbling
    void setDribbling(bool set);  // sets the value of dribbling

    bool getMovement();  // retrieves the value of movement
    void setMovement(bool set);  // sets the value of movement

    bool getDirectChange(); // retrieves the value of directChange
    void setDirectChange(bool set);  // sets the value of directChange

    bool getPlayerControlled();  // retrieves the value of player controlled
    void setPlayerControlled(bool set);  // sets the value of playerControlled
    
    playerStateSharedPtr getPlayerWithBall();  // retrieves the value of playerWithBall
    void setPlayerWithBall(playerStateSharedPtr set);  // sets the value of playerWithBall
    
    courtStateSharedPtr getCourtInstance();  // retrieves the value of courtInstance
    void setCourtInstance(courtStateSharedPtr set);  // sets the value of courtInstance
    
    directions getDirection();  // retrieves the value of direction
    void setDirection(directions set);  // sets the value of direction 
    
    directions getOldDirection();  // retrieves the value of oldDirection
    void setOldDirection(directions set);  // sets the value of oldDirection 
  
    bool getNumberSet();  // retrieves the value of numberSet
    void setNumberSet(bool set);  // sets the value of numberSet
    
    Ogre::Vector3 getCourtPosition();  // retrieves the value of courtPosition
    void setCourtPosition(Ogre::Vector3 set);  // sets the value of courtPosition

    Ogre::Vector3 getNewCourtPosition();  // retrieves the value of newCourtPosition
    void setNewCourtPosition(Ogre::Vector3 set);  // sets the value of newCourtPosition

    bool getCourtPositionChanged();  // retrieves the value of courtPositionChanged
    void setCourtPositionChanged(bool set);  // sets the value of courtPositionChanged

    positionChangedTypes getCourtPositionChangedType();  // retrieves the value of courtPositionChangedType
    void setCourtPositionChangedType(positionChangedTypes set);  // sets the value of courtPositionChangedType

    size_t getNumber();  // retrieves the value of number
    void setNumber(size_t set);  // sets the value of number


    bool initialize();  // initializes the basketballState object

    void updateState();  // updates the state of the basketball
    
    void updatePosition();  // updates the position of the basketball

    void updateMovement();  // updates the movement of basketball(s)
    void updateDirection();  // updates the direction of basketball(s)

    
    Ogre::Vector3 calculatePositionChange();  // calculates the change in position of the basketball model in x,y,z coordinates

    bool calculateShot();  // calculates the trajectory the basketball travels when shot
    bool shotLogic();  // handles the shot logic as the ball travels towards the hoop

protected:

private:

    gameStateSharedPtr gameS;  // the gameState object

    sharedPtr<basketballData> data;

    basketballEntitySharedPtr entity;

    bool entityInitialized;  // stores whether the entity has been initialized

    bool initialized;  // stores whether the basketball object has been initialized

    bool numberSet;  // stores whether the the instance number had been set
    
    float maxHeight;  // stores the maximum height pf the basketball
    bool maxHeightReached;  // stores whether the maximum height has been reached

    float minHeight;  // stores the value of the minimum height of the basketball
    bool minHeightReached;  // stores whether the minimum height has been reached

    size_t rotate;  // defines which way the basketball is rotated

    size_t teamNumber;	 // defines which team has the basketball
    size_t player; 	// defines which player has the basketball

    size_t number;  // stores the basketball object number

    Ogre::Vector3 velocity;	 // speed at which the ball travels on x,y,z axes

    Ogre::Vector3 startCoords;  // stores the starting coordinates of the basketball

    //bool maxYReached;

    bool tipOffStart;  // defines whether or not to setup ball position for tip off
    bool tipOff;  // defines whether or not tip off is executing
    bool dribblingStart;  // defines whether or not to start the dribbling animation
    bool dribbling;  // defines whether or not the ball is being dribbled

    bool movement;  // basketball has been moved by an outside force.
    bool directChange; // baskteball has changed direction

    bool playerControlled;  // set to true if human or cpu player has the ball
    
    playerStateSharedPtr playerWithBall;  // stores copy of player that controls ball
    
    courtStateSharedPtr courtInstance;  // storee the active courtInstance
    
    directions direction;  // stores direction the ball has been moved
    directions oldDirection;  // stores the previous direction of the ball
    
    // stores the position of the player on the court in an Ogre::Vector3
    Ogre::Vector3 courtPosition;

    // stores the upfated position of the player on the court in an Ogre::Vector3
    Ogre::Vector3 newCourtPosition;

    // if the court position has changed then this flag is set
    bool courtPositionChanged;

    // stores what subsystem changed the position of the baskteball
    positionChangedTypes courtPositionChangedType;

//    bool stateSet;  // if true then the basketball state is set
};

#endif

