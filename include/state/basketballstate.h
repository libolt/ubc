/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean   *
 *   libolt@libolt.net   *
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

#include "entity/basketballentity.h"
//#include "ai/basketballsteer.h"
//#include "physics/basketballphysics.h"
#include "enums.h"
#include "state/state.h"

class basketballs : public state, public basketballEntity
{
public:

    basketballs();
    ~basketballs();	// destructor


// declaration of functions which access/modify private variables in the class

//    Ogre::Vector3 getNodePosition();  // the value of nodePosition

    float getMaxHeight(void);  //	retrieves the value of maxHeight
    void setMaxHeight(float set);  //	sets the value of maxHeight

    bool getMaxHeightReached(void);  // retrieves the value of maxHeightReached
    void setMaxHeightReached(bool set);  //	sets the value of maxHeightReached

    float getMinHeight(void);  // retrieves the value of minHeight
    void setMinHeight(float set);	 //	sets the value of minHeight

    bool getMinHeightReached(void);  // retrieves the value of minHeightReached
    void setMinHeightReached(bool set);  // sets minHeightReached

    size_t getRotate(void);  // retrieves the value of rotate
    void setRotate(size_t set);	 // sets the value of rotate

    size_t getTeamNumber(void);  // retrieves the value of teamNumber
    void setTeamNumber(size_t set);  // sets the value of teamNumber

    size_t getPlayer(void);  // retrieves the value of player
    void setPlayer(size_t set);	 // sets the value of player

    Ogre::Vector3 getVelocity(void);  // retrieves xVelocity value
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

    directions getDirection();  // retrieves the value of direction
    void setDirection(directions set);  // sets the value of direction 
    
    directions getOldDirection();  // retrieves the value of oldDirection
    void setOldDirection(directions set);  // sets the value of oldDirection 
  
/*    std::string getModelName();  // retrieves the value of modelName
    void setModelName(std::string set);  // sets the value of modelName

    Ogre::Entity *getModel();  // retrieves the value of model
    void setModel(Ogre::Entity *set);  // sets the value of model

    Ogre::SceneNode *getNode();  // retrieves the value of node
    void setNode(Ogre::SceneNode *set);  // sets the value of node

    btRigidBody *getPhysBody();	 // retrieves the value of physBody
    void setPhysBody(btRigidBody *set);  // sets the value of physBody

    basketballPhysics getPhysics();  // retrieves the value of physics
    void setPhysics(basketballPhysics set);  // sets the value of physics

    basketballSteer *getSteer();  // retrieves the value of steer
    void setSteer(basketballSteer *set);  // sets the value of steer

    bool getModelNeedsLoaded();  // retrieves the value of modelNeedsLoaded
    void setModelNeedsLoaded(bool set);  // sets the value of modelNeedsLoaded

    bool getModelLoaded();  // retrieves the value of modelLoaded
    void setModelLoaded(bool set);  // sets the value of modelLoaded
*/

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

//    bool getStateSet();  // retrieves the value of stateSet
//    void setStateSet(bool set);  // sets the value of stateSet
        
    
    size_t getNumber();  // retrieves the value of number
    void setNumber(size_t set);  // sets the value of number

//    bool loadModel();  // loads the 3D model from file specified in modelName

    void updateState();  // updates the state of the basketball
    
    void updatePosition();  // updates the position of the basketball

    void updateMovement();  // updates the movement of basketball(s)
    void updateDirection();  // updates the direction of basketball(s)

    
    Ogre::Vector3 calculatePositionChange();  // calculates the change in position of the basketball model in x,y,z coordinates

    bool calculateShot();  // calculates the trajectory the basketball travels when shot
    bool shotLogic();  // handles the shot logic as the ball travels towards the hoop


//    static basketballs *Instance();

protected:
//    basketballs(const basketballs&);
//    basketballs& operator= (const basketballs&);
private:
//    static basketballs *pInstance;

/*    std::string modelName;  // stores the file name of the 3d model

    Ogre::Entity *model;  // stores 3d model

    Ogre::SceneNode *node;  // stores node 3d model is attached to

    // stores the physics object that represents the player
    btRigidBody *physBody;

    basketballPhysics physics;  // instanciates an object to handle the physics for the basketball

    basketballSteer *steer;  // instance of the basketballSteer class

    bool modelNeedsLoaded;  // stores whether or not to load the model

    bool modelLoaded;  // stores whether the 3D model of the basketball has been loaded
*/
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

