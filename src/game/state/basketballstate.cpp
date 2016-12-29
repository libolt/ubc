/***************************************************************************
 *   Copyright (C) 1999 - 2016 by Mike McLean                              *
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

#include "conversion.h"
#include "ai/basketballsteer.h"
#include "state/basketballstate.h"
//#include "state/gamestate.h"
#include "state/playerstate.h"
#include "state/teamstate.h"
#include "engine/renderengine.h"
#include "comparison.h"
#include "logging.h"
#include "jumpballs.h"

#include <string>

basketballState::basketballState()  // constructor
{
//    playerControlBasketball = -1;
    maxHeight = 0;
    maxHeightReached = false;
    minHeight = 0;
    minHeightReached = false;

    direction = NODIRECT;	
    oldDirection = NODIRECT;

    rotate = 0;

    velocity[0] = 0.0f;
    velocity[1] = 0.0f;
    velocity[2] = 0.0f;

    startCoords[0] = 0.0f;
    startCoords[1] = 0.0f;
    startCoords[2] = 0.0f;

    tipOffStart = false;
    tipOff = false;

    dribblingStart = true;
    dribbling = false;

    movement = false;
    directChange = false;
    
    playerControlled = false;

    teamNumber = 0;
    player = 0;

//    modelNeedsLoaded = false;
//    modelLoaded = false;
    numberSet = false;
    
    courtPosition = Ogre::Vector3(0,0,0);
    newCourtPosition = Ogre::Vector3(0,0,0);
    courtPositionChanged = false;
	courtPositionChangedType = NOCHANGE;
    number = 999999;
//    stateSet = false;

}

basketballState::~basketballState()  // destructor
{
}

/*Ogre::Vector3 basketballs::getNodePosition()  // retrieves position of basketball node
{
	return (node->getPosition());
}
*/
float basketballState::getMaxHeight(void)  // retrieves the value of maxHeight
{
    return(maxHeight);
}
void basketballState::setMaxHeight(float set)  // sets the value og maxHeight
{
    maxHeight = set;
}

bool basketballState::getMaxHeightReached(void)  // retrieves the value of maxHeightReached
{
    return(maxHeightReached);
}
void basketballState::setMaxHeightReached(bool set)  // sets the value of maxHeightReachef
{
    maxHeightReached = set;
}

float basketballState::getMinHeight(void)  // retrieves the value minHeight
{
    return(minHeight);
}
void basketballState::setMinHeight(float set)  // sets the value of minHeight
{
    minHeight = set;
}

bool basketballState::getMinHeightReached(void)  // retrieves the value of minHeightReached
{
    return(minHeightReached);
}
void basketballState::setMinHeightReached(bool set)  // sets the value of minHeightReached
{
    minHeightReached = set;
}

size_t basketballState::getRotate(void)  // retrieves the value of rotate
{
    return (rotate);
}
void basketballState::setRotate(size_t set)  // sets the value of rotate
{
    rotate = set;
}

size_t basketballState::getTeamNumber(void)  // retrieves the value of teamNumber
{
    return(teamNumber);
}
void basketballState::setTeamNumber(size_t set)  // sets the value of teamNumber
{
    teamNumber = set;
}

Ogre::Vector3 basketballState::getVelocity(void)  // retrieves the value of velocity
{
    return(velocity);
}
void basketballState::setVelocity(Ogre::Vector3 set)  // sets the value of velocity
{
    velocity = set;
}

Ogre::Vector3 basketballState::getStartCoords(void)  // retrieves the value of startCoords
{
    return(startCoords);
}
void basketballState::setStartCoords(Ogre::Vector3 set) // sets the value of startCoords
{
    startCoords = set;
}

bool basketballState::getTipOffStart()  // retroeves the value of tipOffStart
{
    return (tipOffStart);
}
void basketballState::setTipOffStart(bool set)  // sets the value of tipOffStart
{
    tipOffStart = set;
}

bool basketballState::getTipOff()  // retrieves the value of tipOff
{
    return (tipOff);
}
void basketballState::setTipOff(bool set)  // sets the value of tipOff
{
    tipOff = set;
}

bool basketballState::getDribblingStart(void)  // retrieves the value of dribblingStart
{
    return (dribblingStart);
}
void basketballState::setDribblingStart(bool set)  // sets the value of dribblingStart
{
    dribblingStart = set;
}

bool basketballState::getDribbling(void)  // retrieves the value of dribbling
{
    return (dribbling);
}
void basketballState::setDribbling(bool set)  // sets the value of dribbling
{
    dribbling = set;
}

bool basketballState::getMovement()  // retrieves the value of movement
{
    return (movement);
}
void basketballState::setMovement(bool set)  // sets the value of movement
{
    movement = set;
}

bool basketballState::getDirectChange() // retrieves the value of directChange
{
    return (directChange);
}
void basketballState::setDirectChange(bool set)  // sets the value of directChange
{
    directChange = set;
}

bool basketballState::getPlayerControlled()  // retrieves the value of player controlled
{
    return (playerControlled);
}
void basketballState::setPlayerControlled(bool set)  // sets the value of playerControlled
{
    playerControlled = set;
}

playerStateSharedPtr basketballState::getPlayerWithBall()  // retrieves the value of playerWithBall
{
    return (playerWithBall);
}
void basketballState::setPlayerWithBall(playerStateSharedPtr set)  // sets the value of playerWithBall
{
    playerWithBall = set;
}

courtStateSharedPtr basketballState::getCourtInstance()  // retrieves the value of courtInstance
{
    return (courtInstance);
}
void basketballState::setCourtInstance(courtStateSharedPtr set)  // sets the value of courtInstance
{
    courtInstance = set;
}

directions basketballState::getDirection()  // retrieves the value of direction
{
    return (direction);
}
void basketballState::setDirection(directions set)  // sets the value of direction
{
    direction = set;
}

directions basketballState::getOldDirection()  // retrieves the value of oldDirection
{
    return (oldDirection);
}
void basketballState::setOldDirection(directions set)  // sets the value of oldDirection
{
    oldDirection = set;
}
/*
std::string basketballs::getModelName()  // retrieves the value of modelName
{
    return (modelName);
}
void basketballs::setModelName(string set)  // sets the value of modelName
{
    modelName = set;
}

Ogre::Entity *basketballs::getModel()  // retrieves the value of model
{
    return (model);
}
 void basketballs::setModel(Ogre::Entity *set)  // sets the value of model
{
    model = set;
}

Ogre::SceneNode *basketballs::getNode()  // retrieves the value of node
{
    return (node);
}
void basketballs::setNode(Ogre::SceneNode *set)  // sets the value of node
{
    node = set;
}

btRigidBody *basketballs::getPhysBody()	 // retrieves physBody variable
{
    return (physBody);
}

void basketballs::setPhysBody(btRigidBody *set)  // sets physBody variable
{
    physBody = set;
}

basketballPhysics basketballs::getPhysics()  // retrieves the value of physics
{
    return (physics);
}
void basketballs::setPhysics(basketballPhysics set)  // sets the value of physics
{
    physics = set;
}

basketballSteer *basketballs::getSteer()  // retrieves the value of steer
{
    return (steer);
}
void basketballs::setSteer(basketballSteer *set)  // sets the value of steer
{
    steer = set;
}

bool basketballs::getModelNeedsLoaded()  // retrieves the value of modelNeedsLoaded
{
    return (modelNeedsLoaded);
}
void basketballs::setModelNeedsLoaded(bool set)  // sets the value of modelNeedsLoaded
{
    modelNeedsLoaded = set;
}

bool basketballs::getModelLoaded()  // retrieves the value of modelLoaded
{
    return (modelLoaded);
}
void basketballs::setModelLoaded(bool set)  // sets the value of modelLoaded
{
    modelLoaded = set;
}
*/
bool basketballState::getNumberSet()  // retrieves the value of numberSet
{
    return (numberSet);
}
void basketballState::setNumberSet(bool set)  // sets the value of numberSet
{
    numberSet = set;
}

Ogre::Vector3 basketballState::getCourtPosition()  // retrieves the value of courtPosition
{
    return (courtPosition);
}
void basketballState::setCourtPosition(Ogre::Vector3 set)  // sets the value of courtPosition
{
    courtPosition = set;
}

Ogre::Vector3 basketballState::getNewCourtPosition()  // retrieves the value of newCourtPosition
{
    return (newCourtPosition);
}
void basketballState::setNewCourtPosition(Ogre::Vector3 set)  // sets the value of newCourtPosition
{
    newCourtPosition = set;
}

bool basketballState::getCourtPositionChanged()  // retrieves the value of courtPositionChanged
{
    return (courtPositionChanged);
}
void basketballState::setCourtPositionChanged(bool set)  // sets the value of courtPositionChanged
{
    courtPositionChanged = set;
}

positionChangedTypes basketballState::getCourtPositionChangedType()  // retrieves the value of courtPositionChangedType
{
    return (courtPositionChangedType);
}
void basketballState::setCourtPositionChangedType(positionChangedTypes set)  // sets the value of courtPositionChangedType
{
    courtPositionChangedType = set;
}

size_t basketballState::getNumber()  // retrieves the value of number
{
    return (number);
}
void basketballState::setNumber(size_t set)  // sets the value of number
{
    number = set;
    setPhysObjNumber(set); // sets the physics number as well
    numberSet = true;
}

/*bool basketballs::getStateSet()  // retrieves the value of stateSet
{
    return (stateSet);
}
void basketballs::setStateSet(bool set)  // sets the value of stateSet
{
    stateSet = set;
}

bool basketballs::loadModel()  // loads the 3D model
{
    sharedPtr<renderEngine> render = renderEngine::Instance();

    model = render->getMSceneMgr()->createEntity("basketball", modelName);	// loads the basketball model

    // creates and instantiates the node object
    node = render->getMSceneMgr()->getRootSceneNode()->createChildSceneNode("basketball");

    // attaches 3D model to the node
    node->attachObject(model);
    // sets the size of the bball node
    node->setScale(0.25f,0.25f,0.25f);
    node->setPosition(0.0f,0.0f,0.0f);

   return true;
}
*/

// calculates change in position along the x,y,z axes
Ogre::Vector3 basketballState::calculatePositionChange()
{
//    sharedPtr<gameState> gameS = gameState::Instance();

    Ogre::Vector3 changeInPosition;	// stores the calculated change in position
    Ogre::Vector3 pos = getNode()->getPosition();	// stores the basketball nodes position

    // initializes the variable
    changeInPosition[0] = 0.0f;
    changeInPosition[1] = 0.0f;
    changeInPosition[2] = 0.0f;
    return(changeInPosition);
}

void basketballState::updateState()  // updates the state of the basketball
{
    bool modelNeedsLoaded = getModelNeedsLoaded();
    if (getModelNeedsLoaded())
    {
//        exit(0);
        if (loadModel())
        {
            setModelNeedsLoaded(false);
            setModelLoaded(true);
            
        }
    }

    if (numberSet)  // runs the physics update code
    {
        updatePhysObj();
    }
    if (directChange)
    {
        logMsg("updating direction!");
        updateDirection();
        directChange = false;
        logMsg("direction updated!");
    }

    if (movement)
    {
        logMsg("updating movement!");
        updateMovement();
        movement = false;
        logMsg("movement updated!");
    }
    logMsg("updating position!");
    updatePosition();
    logMsg("position updated!");
}

void basketballState::updatePosition() // updates the position of the basketball
{
    sharedPtr<conversion> convert = conversion::Instance();
    comparison compare;
    Ogre::Vector3 changePos;
    btVector3 physChange = btVector3(0,0,0);
    
    if (courtPositionChanged)
    {
        //exit(0);
        switch (courtPositionChangedType)
        {
            case STARTCHANGE:
                logMsg("Updating basketball court position based on start position");
                
                getNode()->translate(newCourtPosition);
                physChange = BtOgre::Convert::toBullet(newCourtPosition); // converts from Ogre::Vector3 to btVector3
                getPhysBody()->translate(physChange); // moves physics body in unison with the model
                getSteer()->setPosition(convert->toOpenSteerVec3(newCourtPosition));
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
            break;
            
            case STEERCHANGE:
                logMsg("Updating basketball court position based on steering");
                //logMsg("Team " +convert->toString(teamNumber) + " Player " +convert->toString(playerID));
                changePos = compare.OgreVector3ToOgreVector3Result(courtPosition, newCourtPosition);
                getNode()->translate(changePos);
                physChange = BtOgre::Convert::toBullet(changePos); // converts from Ogre::Vector3 to btVector3
                getPhysBody()->translate(physChange); // moves physics body in unison with the model
               
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
            break;   

            case INPUTCHANGE:
                logMsg("Updating court position based on input");
                getNode()->translate(newCourtPosition);
                physChange = BtOgre::Convert::toBullet(newCourtPosition); // converts from Ogre::Vector3 to btVector3
                getPhysBody()->translate(physChange); // moves physics body in unison with the model
                getSteer()->setPosition(convert->toOpenSteerVec3(newCourtPosition));
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
                //exit(0);
            break;

            case PHYSICSCHANGE:
                logMsg("Updating basketball court position based on physics");
                //exit(0);
            break;
            case PLAYERMOVECHANGE:
                logMsg("Updating basketball court position based on player movement");
                getNode()->translate(newCourtPosition);
                logMsg("bball newCourtPosition = " +convert->toString(newCourtPosition));
                logMsg("bball node position" +convert->toString((getNode()->getPosition())));
                //exit(0);
                physChange = BtOgre::Convert::toBullet(newCourtPosition); // converts from Ogre::Vector3 to btVector3
                getPhysBody()->translate(physChange); // moves physics body in unison with the model
                //steer->setPosition(convert->toOpenSteerVec3(newCourtPosition));
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
//                exit(0);
            break;
            case PLAYERDIRECTCHANGE:
                logMsg("Updating basketball court position based on player movement");
                getNode()->translate(newCourtPosition);
                logMsg("bball newCourtPosition = " +convert->toString(newCourtPosition));
                logMsg("bball node position" +convert->toString((getNode()->getPosition())));
                //exit(0);
                physChange = BtOgre::Convert::toBullet(newCourtPosition); // converts from Ogre::Vector3 to btVector3
                getPhysBody()->translate(physChange); // moves physics body in unison with the model
                //steer->setPosition(convert->toOpenSteerVec3(newCourtPosition));
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
            break;
            default:
            break;
        }
        courtPosition = getNode()->getPosition();
        
    }
    
/*    node->translate(posChange);
	btVector3 change; // = btVector3(0,0,0);
	change = BtOgre::Convert::toBullet(posChange); // converts from Ogre::Vector3 to btVector3
	physBody->translate(change); // moves physics body in unison with the model
*/
}

void basketballState::updateMovement()  // updates the basketball(s) movements
{
    sharedPtr<conversion> convert = conversion::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
    teamStateUMSharedPtr activeTeamInstance = getActiveTeamInstance();
    size_t teamWithBall = getTeamWithBall();
/*TS    playerStateVecSharedPtr activePlayerInstance = activeTeamInstance[teamWithBall]->getActivePlayerInstance();
    size_t playerWithBallInstance = activeTeamInstance[teamWithBall]->getPlayerWithBallInstance();
    size_t playerWithBallID = activeTeamInstance[teamWithBall]->getPlayerWithBallID();
TS*/
    size_t x = 0;
    
//TS    bool shotTaken = activePlayerInstance[playerWithBallInstance]->getShotTaken();
    Ogre::Vector3 bballPos;
    Ogre::Vector3 bballCurrentPos;  // stores the current position of the basketball(s)
    Ogre::Vector3 playerPos;
//TS    logMsg("playerWithBallInstance == " +convert->toString(playerWithBallInstance));
//TS logMsg("playerWithBallID == " +convert->toString(playerWithBallID));

    if (courtPosition.x == 0 && courtPosition.y == 0 && courtPosition.z == 0)
    {
        bballCurrentPos = getNode()->getPosition();
    }
    else
    {
        bballCurrentPos = courtPosition;
    }
//TS    playerPos = activePlayerInstance[playerWithBallInstance]->getCourtPosition();  // stores the current position of player with ball
    //bballPos = bballCurrentPos;
    bballPos = Ogre::Vector3(0,0,0);
    logMsg("bballHere???");
    switch (direction)
    {
        case UP:
            bballPos.x += 0;
            bballPos.y += 0; // maintains the current height of the basketball on the court as the player and ball moves
            bballPos.z -= 0.200;
        break;
        case DOWN:
            bballPos.x += 0;
            bballPos.y += 0; // maintains the current height of the basketball on the court as the player and ball moves
            bballPos.z += 0.200;
        break;
        case LEFT:
            bballPos.x -= 0.200;
            bballPos.y = 0;
            bballPos.z = 0;
        break;
        case RIGHT:
            bballPos.x += 0.200;
            bballPos.y += 0; // maintains the current height of the basketball on the court as the player and ball moves
            bballPos.z += 0;
        break;
        default:
        break;
    }

        logMsg("bballPos == " +convert->toString(bballPos));
        logMsg("cbballPos == " +convert->toString(bballCurrentPos));
//TS        logMsg("pbballPos == " +convert->toString(activePlayerInstance[x]->getCourtPosition()));
        logMsg("new bball court Position == " +convert->toString(bballPos));
        newCourtPosition = bballPos;
        courtPositionChanged = true;
        courtPositionChangedType = PLAYERMOVECHANGE;
        //basketballInstance[activeBBallInstance].setMovement(false);
        //basketballInstance[activeBBallInstance] = bballInstance;

}

void basketballState::updateDirection()  // updates basketball direction(s)
{
    //conversion *convert = conversion::Instance();
    sharedPtr<conversion> convert = conversion::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
    teamStateUMSharedPtr activeTeamInstance = getActiveTeamInstance();
    size_t teamWithBall = getTeamWithBall();
/*TS    playerStateVecSharedPtr activePlayerInstance = activeTeamInstance[teamWithBall]->getActivePlayerInstance();
    sizeTVec activePlayerID = activeTeamInstance[teamWithBall]->getActivePlayerID();
    
    size_t playerWithBallInstance = activeTeamInstance[teamWithBall]->getPlayerWithBallInstance();
    size_t playerWithBallID = activeTeamInstance[teamWithBall]->getPlayerWithBallID();
TS*/

    jumpBallsSharedPtr jumpBall = getJumpBall();

//TS    logMsg("directplayerwithballInstance == " +convert->toString(playerWithBallInstance));
    bool tipOffComplete = getTipOffComplete();
    size_t x = 0;

/*TS    bool shotTaken = activePlayerInstance[playerWithBallInstance]->getShotTaken();

    if (!shotTaken)
    {
        
        Ogre::Vector3 posChange;
        while (x < activePlayerInstance.size())
        {
            if (activePlayerInstance[x]->getID() == playerWithBallID)
            {
                playerWithBallInstance = x;
                break;
            }
            ++x;
        }
        
        if (playerWithBallInstance >= 0 && playerWithBallInstance < 10 && tipOffComplete == true)  // verifies that the playerWithBall variable is set to a valid number
        {
            Ogre::Vector3 playerPos= activePlayerInstance[playerWithBallInstance]->getNode()->getPosition();
            Ogre::Vector3 bballCurrentPos;

            Ogre::Vector3 bballPos = playerPos;
            Ogre::Vector3 bballPosChange = Ogre::Vector3(0.0f,0.0f,0.0f);
            btVector3 change; // = btVector3(0,0,0);
            btTransform transform;
    //      basketballInstance[activeBBallInstance].getPhysBody()->forceActivationState(ISLAND_SLEEPING);
    //        logMsg("playerDirection = " + convert->toString(&playerDirection));
    //        logMsg("oldPlayerDirection = " + convert->toString(&oldPlayerDirection));

            logMsg("playerWithBallInstance = " +convert->toString(playerWithBallInstance));
//            exit(0);

            if (courtPosition.x == 0 && courtPosition.y == 0 && courtPosition.z == 0)
            {
                bballCurrentPos = getNode()->getPosition();
            }
            else
            {
                bballCurrentPos = courtPosition;
            }

            if (direction != oldDirection)
            {
                //exit(0);
                bballPos = Ogre::Vector3(0,0,0);
                switch (direction)
                {
                    case UP:
                        bballPos[0] += 0.200;
                        //bballPos[1] = bballCurrentPos[1]; // maintains the current height of the basketball on the court as the player and ball moves
                        bballPos[2] -= 0.200;
        //              basketballInstance[activeBBallInstance].setPosChange(bballPosChange);   // sets the posChange for current basketballInstance                        
                    case DOWN:
                        bballPos[0] -= 0.200;
                        //bballPos[1] = bballCurrentPos[1]; // maintains the current height of the basketball on the court as the player and ball moves
                        bballPos[2] += 0.200;
        //              basketballInstance[activeBBallInstance].setPosChange(bballPosChange);   // sets the posChange for current basketballInstance
                        break;
                    case LEFT:
                        bballPos[0] -= 0.200;
                        //bballPos[1] = bballCurrentPos[1]; // maintains the current height of the basketball on the court as the player and ball moves
//                      exit(0);
        //              basketballInstance[activeBBallInstance].setPosChange(bballPosChange);   // sets the posChange for current basketballInstance
                        break;
                    case RIGHT:
                        bballPos[0] += 0.200;
                        //bballPos[1] = bballCurrentPos[1]; // maintains the current height of the basketball on the court as the player and ball moves
        //              basketballInstance[activeBBallInstance].setPosChange(bballPosChange);   // sets the posChange for current basketballInstance
                        break;
                    default:
                        break;
                }
                
                newCourtPosition = bballPos;
                courtPositionChanged = true;
                courtPositionChangedType = PLAYERDIRECTCHANGE;
//                exit(0);

    //      basketballInstance[activeBBallInstance].getPhysBody()->forceActivationState(ACTIVE_TAG);
            }
            else
            {
            }
        }
        oldDirection = direction;
    }
    else
    {

    }
TS*/
    setJumpBall(jumpBall);
}

size_t basketballState::getPlayer()
{
    return (player);
}

void basketballState::setPlayer(size_t Player)
{
    player = Player;
}

// calculates the trajectory the basketball travels when shot
bool basketballState::calculateShot()
{
    return true;
}

// handles the shot logic as the ball travels towards the hoop
bool basketballState::shotLogic()
{
    return true;
}
