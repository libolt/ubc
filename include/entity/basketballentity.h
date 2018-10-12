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
    
    gameEntitySharedPtr getGameInstance() const;  // retrieves the value of gameS
    void setGameInstance(const gameEntitySharedPtr &set);  // sets the value of gameS

    sharedPtr<basketballData> getData() const;  // retrievees the value of data
    void setData(const sharedPtr<basketballData> &set);  // sets the value of data
    
    bool getInitialized() const;  // retrieves the value of initialized
    void setInitialized(const bool &set);  // sets the value of initialized

    float getMaxHeight() const;  //   retrieves the value of maxHeight
    void setMaxHeight(const float &set);  //   sets the value of maxHeight

    bool getMaxHeightReached() const;  // retrieves the value of maxHeightReached
    void setMaxHeightReached(const bool &set);  // sets the value of maxHeightReached

    float getMinHeight()const;  // retrieves the value of minHeight
    void setMinHeight(const float &set);    // sets the value of minHeight

    bool getMinHeightReached() const;  // retrieves the value of minHeightReached
    void setMinHeightReached(const bool &set);  // sets minHeightReached

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

    bool getTipOffStart() const;  // retrieves the value of tipOffStart
    void setTipOffStart(const bool &set);  // sets the value of tipOFfStart

    bool getTipOff() const;  // retrieves the value of tipOff
    void setTipOff(const bool &set);  // sets the value of tipOff

    bool getDribblingStart() const;  // retrieves the value of dribblingStart
    void setDribblingStart(const bool &set);  // sets the value of dribblingStart

    bool getDribbling() const;  // retrieves the value of dribbling
    void setDribbling(const bool &set);  // sets the value of dribbling

    bool getMovement() const;  // retrieves the value of movement
    void setMovement(const bool &set);  // sets the value of movement

    bool getDirectChange() const;  // retrieves the value of directChange
    void setDirectChange(const bool &set);  // sets the value of directChange

    bool getPlayerControlled() const;  // retrieves the value of player controlled
    void setPlayerControlled(const bool &set);  // sets the value of playerControlled
    
    courtEntityMSharedPtr getCourtInstance() const;  // retrieves the value of courtInstance
    void setCourtInstance(const courtEntityMSharedPtr &set);  // sets the value of courtInstance
    
    directions getDirection() const;  // retrieves the value of direction
    void setDirection(const directions &set);  // sets the value of direction
    
    directions getOldDirection() const;  // retrieves the value of oldDirection
    void setOldDirection(const directions &set);  // sets the value of oldDirection
  
    bool getNumberSet() const;  // retrieves the value of numberSet
    void setNumberSet(const bool &set);  // sets the value of numberSet
    
    Ogre::Vector3 getCourtPosition() const;  // retrieves the value of courtPosition
    void setCourtPosition(const Ogre::Vector3 &set);  // sets the value of courtPosition

    Ogre::Vector3 getNewCourtPosition() const;  // retrieves the value of newCourtPosition
    void setNewCourtPosition(const Ogre::Vector3 &set);  // sets the value of newCourtPosition

    bool getCourtPositionChanged() const;  // retrieves the value of courtPositionChanged
    void setCourtPositionChanged(const bool &set);  // sets the value of courtPositionChanged

    positionChangedTypes getCourtPositionChangedType() const;  // retrieves the value of courtPositionChangedType
    void setCourtPositionChangedType(const positionChangedTypes &set);  // sets the value of courtPositionChangedType

    sharedPtr<basketballPhysics> getPhysics() const;  // retrieves the value of physics
    void setPhysics(const sharedPtr<basketballPhysics> &set);  // sets the value of physics

    basketballSteerSharedPtr getSteer() const;  // retrieves the value of steer
    void setSteer(const basketballSteerSharedPtr &set);  // sets the value of steer

    size_t getNumber() const;  // retrieves the value of number
    void setNumber(const size_t &set);  // sets the value of number

    void updateState(gameComponentsSharedPtr gameComponent, gameDataSharedPtr gameDta, gameFlagsSharedPtr gameFlag);  // updates the state of the basketball
    
    void updatePosition();  // updates the position of the basketball

    void updateMovement(gameComponentsSharedPtr gameComponent, gameDataSharedPtr gameDta, gameFlagsSharedPtr gameFlag);  // updates the movement of basketball(s)
   
    void updateDirection(gameComponentsSharedPtr gameComponent, gameDataSharedPtr gameDta, gameFlagsSharedPtr gameFlag);  // updates the direction of basketball(s)
    
    Ogre::Vector3 calculatePositionChange();  // calculates the change in position of the basketball model in x,y,z coordinates

    bool calculateShot();  // calculates the trajectory the basketball travels when shot
    bool shotLogic();  // handles the shot logic as the ball travels towards the hoop

    
    bool initialize();  // initializes the basketball entity object

    bool setupPhysicsObject();  // sets up the physics object
    
    private:
    
    gameEntitySharedPtr gameInstance;  // the gameState object

    sharedPtr<basketballData> data;



    bool numberSet;  // stores whether the the instance number had been set
    
    float maxHeight;  // stores the maximum height pf the basketball
    bool maxHeightReached;  // stores whether the maximum height has been reached

    float minHeight;  // stores the value of the minimum height of the basketball
    bool minHeightReached;  // stores whether the minimum height has been reached

    size_t rotate;  // defines which way the basketball is rotated

    size_t teamNumber;   // defines which team has the basketball
    size_t player;  // defines which player has the basketball

    size_t number;  // stores the basketball object number

    Ogre::Vector3 velocity;  // speed at which the ball travels on x,y,z axes

    Ogre::Vector3 startCoords;  // stores the starting coordinates of the basketball

    //bool maxYReached;

    bool tipOffStart;  // defines whether or not to setup ball position for tip off
    bool tipOff;  // defines whether or not tip off is executing
    bool dribblingStart;  // defines whether or not to start the dribbling animation
    bool dribbling;  // defines whether or not the ball is being dribbled

    bool movement;  // basketball has been moved by an outside force.
    bool directChange; // baskteball has changed direction

    bool playerControlled;  // set to true if human or cpu player has the ball
    
//    playerStateSharedPtr playerWithBall;  // stores copy of player that controls ball
    
    courtEntityMSharedPtr courtInstance;  // storee the active courtInstance
    
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

    bool initialized;  // stores whether the basketball entity object has been initialized

    sharedPtr<basketballPhysics> physics;  // instanciates an object to handle the physics for the basketball

    basketballSteerSharedPtr steer;  // instance of the basketballSteer class

};
 
#endif
