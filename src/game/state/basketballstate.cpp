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

#include "utilities/conversion.h"
#include "ai/basketballsteer.h"
#include "components/gamecomponents.h"
#include "data/gamedata.h"
#include "state/basketballstate.h"
#include "entity/gameentity.h"
#include "state/playerstate.h"
#include "state/teamstate.h"
#include "engine/renderengine.h"
#include "entity/basketballentity.h"
#include "data/basketballdata.h"
#include "physics/basketballphysics.h"
#include "utilities/comparison.h"
#include "utilities/logging.h"
#include "jumpballs.h"

#include <string>

basketballState::basketballState()  // constructor
{
//    playerControlBasketball = -1;
    entityInitialized = false;
    initialized = false;
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


gameEntitySharedPtr basketballState::getGameInstance()  // retrieves the value of gameS
{
    return (gameInstance);
}
void basketballState::setGameInstance(gameEntitySharedPtr set)  // sets the value of gameS
{
    gameInstance = set;
}

sharedPtr<basketballData> basketballState::getData()  // retrievees the value of data
{
    return(data);
}
void basketballState::setData(sharedPtr<basketballData> set)  // sets the value of data
{
    data = set;
}

basketballEntitySharedPtr basketballState::getEntity()  // retrieves the value of entity
{
    return(entity);
}
void basketballState::setEntity(basketballEntitySharedPtr set)  // sets the value of entity
{
    entity = set;
}

bool basketballState::getEntityInitialized()  // retrieves the value of entityInitialized
{
    return (entityInitialized);
}
void basketballState::setEntityInitialized(bool set)  // sets the value of entityInitialized
{
    entityInitialized = set;
}

bool basketballState::getInitialized()  // retrieves the value of initialized
{
    return (initialized);
}
void basketballState::setInitialized(bool set)  // sets the value of initialized
{
    initialized = set;
}

float basketballState::getMaxHeight()  // retrieves the value of maxHeight
{
    return(maxHeight);
}
void basketballState::setMaxHeight(float set)  // sets the value og maxHeight
{
    maxHeight = set;
}

bool basketballState::getMaxHeightReached()  // retrieves the value of maxHeightReached
{
    return(maxHeightReached);
}
void basketballState::setMaxHeightReached(bool set)  // sets the value of maxHeightReachef
{
    maxHeightReached = set;
}

float basketballState::getMinHeight()  // retrieves the value minHeight
{
    return(minHeight);
}
void basketballState::setMinHeight(float set)  // sets the value of minHeight
{
    minHeight = set;
}

bool basketballState::getMinHeightReached()  // retrieves the value of minHeightReached
{
    return(minHeightReached);
}
void basketballState::setMinHeightReached(bool set)  // sets the value of minHeightReached
{
    minHeightReached = set;
}

size_t basketballState::getRotate()  // retrieves the value of rotate
{
    return (rotate);
}
void basketballState::setRotate(size_t set)  // sets the value of rotate
{
    rotate = set;
}

size_t basketballState::getTeamNumber()  // retrieves the value of teamNumber
{
    return(teamNumber);
}
void basketballState::setTeamNumber(size_t set)  // sets the value of teamNumber
{
    teamNumber = set;
}

Ogre::Vector3 basketballState::getVelocity()  // retrieves the value of velocity
{
    return(velocity);
}
void basketballState::setVelocity(Ogre::Vector3 set)  // sets the value of velocity
{
    velocity = set;
}

Ogre::Vector3 basketballState::getStartCoords()  // retrieves the value of startCoords
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

bool basketballState::getDribblingStart()  // retrieves the value of dribblingStart
{
    return (dribblingStart);
}
void basketballState::setDribblingStart(bool set)  // sets the value of dribblingStart
{
    dribblingStart = set;
}

bool basketballState::getDribbling()  // retrieves the value of dribbling
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

/*playerStateSharedPtr basketballState::getPlayerWithBall()  // retrieves the value of playerWithBall
{
    return (playerWithBall);
}
void basketballState::setPlayerWithBall(playerStateSharedPtr set)  // sets the value of playerWithBall
{
    playerWithBall = set;
}*/

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
    getEntity()->getPhysics()->setPhysObjNumber(set); // sets the physics number as well
    numberSet = true;
}

bool basketballState::initialize()  // initializes the basketballState object
{
    std::string func = "basketballState::initialize()";

    logMsg(func +" begin");

    sharedPtr<basketballData> tempData(new basketballData);
    data = tempData;

    basketballEntitySharedPtr tempEntity(new basketballEntity);
    entity = tempEntity;

    if (!entity->getInitialized())
    {
        if (entity->initialize())
        {
            entity->setInitialized(true);
        }
        else
        {
            logMsg(func +"Unable to initialize basketball entity object!");
            exit(0);
        }
    }

    logMsg(func +" end");

    return (true);
}

// calculates change in position along the x,y,z axes
Ogre::Vector3 basketballState::calculatePositionChange()
{
//    sharedPtr<gameState> gameS = gameState::Instance();

    Ogre::Vector3 changeInPosition;	// stores the calculated change in position
    Ogre::Vector3 pos = entity->getNode()->getPosition();	// stores the basketball nodes position

    // initializes the variable
    changeInPosition[0] = 0.0f;
    changeInPosition[1] = 0.0f;
    changeInPosition[2] = 0.0f;
    return(changeInPosition);
}

void basketballState::updateState()  // updates the state of the basketball
{
    bool modelNeedsLoaded = entity->getModelNeedsLoaded();
    std::string func = "basketballState::updateState()";
    
    logMsg(func + " beginning");
/*    if (entity->getModelNeedsLoaded())
    {
        
        if (entity->loadModel())
        {
            entity->setModelNeedsLoaded(false);
            entity->setModelLoaded(true);
            
        }
    }
*/
    if (numberSet)  // runs the physics update code
    {
        entity->getPhysics()->updatePhysObj();
    }
    if (directChange)
    {
        logMsg(func +" updating direction!");
        updateDirection();
        directChange = false;
        logMsg(func + " direction updated!");
    }

    if (movement)
    {
        logMsg(func + " updating movement!");
        updateMovement();
        movement = false;
        logMsg(func + " movement updated!");
    }
    logMsg(func + " updating position!");
    updatePosition();
    logMsg(func + " position updated!");
   
    logMsg(func + " end");
    
//    exit(0);
}

void basketballState::updatePosition() // updates the position of the basketball
{
    conversionSharedPtr convert = conversion::Instance();
    comparison compare;
    Ogre::Vector3 changePos;
    btVector3 physChange = btVector3(0,0,0);
    std::string func = "basketballState::updatePosition()";

    logMsg(func + " beginning");
    if (courtPositionChanged)
    {
        //exit(0);
        switch (courtPositionChangedType)
        {
            case STARTCHANGE:
                logMsg(func + " Updating basketball court position based on start position");
                
                entity->getNode()->translate(newCourtPosition);
                physChange = BtOgre::Convert::toBullet(newCourtPosition); // converts from Ogre::Vector3 to btVector3
                entity->getPhysics()->getPhysBody()->translate(physChange); // moves physics body in unison with the model
                entity->getSteer()->setPosition(convert->toOpenSteerVec3(newCourtPosition));
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
            break;
            
            case STEERCHANGE:
                logMsg(func + " Updating basketball court position based on steering");
                //logMsg("Team " +convert->toString(teamNumber) + " Player " +convert->toString(playerID));
                changePos = compare.OgreVector3ToOgreVector3Result(courtPosition, newCourtPosition);
                entity->getNode()->translate(changePos);
                physChange = BtOgre::Convert::toBullet(changePos); // converts from Ogre::Vector3 to btVector3
                entity->getPhysics()->getPhysBody()->translate(physChange); // moves physics body in unison with the model
               
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
            break;   

            case INPUTCHANGE:
                logMsg(func + " Updating court position based on input");
                entity->getNode()->translate(newCourtPosition);
                physChange = BtOgre::Convert::toBullet(newCourtPosition); // converts from Ogre::Vector3 to btVector3
                entity->getPhysics()->getPhysBody()->translate(physChange); // moves physics body in unison with the model
                entity->getSteer()->setPosition(convert->toOpenSteerVec3(newCourtPosition));
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
                //exit(0);
            break;

            case PHYSICSCHANGE:
                logMsg(func + " Updating basketball court position based on physics");
                //exit(0);
            break;
            case PLAYERMOVECHANGE:
                logMsg(func + " Updating basketball court position based on player movement");
                entity->getNode()->translate(newCourtPosition);
                logMsg(func + " bball newCourtPosition = " +convert->toString(newCourtPosition));
                logMsg(func + " bball node position" +convert->toString((entity->getNode()->getPosition())));
                //exit(0);
                physChange = BtOgre::Convert::toBullet(newCourtPosition); // converts from Ogre::Vector3 to btVector3
                entity->getPhysics()->getPhysBody()->translate(physChange); // moves physics body in unison with the model
                //steer->setPosition(convert->toOpenSteerVec3(newCourtPosition));
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
//                exit(0);
            break;
            case PLAYERDIRECTCHANGE:
                logMsg(func + " Updating basketball court position based on player movement");
                entity->getNode()->translate(newCourtPosition);
                logMsg(func + " bball newCourtPosition = " +convert->toString(newCourtPosition));
                logMsg(func + " bball node position" +convert->toString((entity->getNode()->getPosition())));
                //exit(0);
                physChange = BtOgre::Convert::toBullet(newCourtPosition); // converts from Ogre::Vector3 to btVector3
                entity->getPhysics()->getPhysBody()->translate(physChange); // moves physics body in unison with the model
                //steer->setPosition(convert->toOpenSteerVec3(newCourtPosition));
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
            break;
            default:
            break;
        }
        courtPosition = entity->getNode()->getPosition();
        logMsg("basketball position = " +convert->toString(courtPosition));
    }
    
    logMsg("basketball position = " +convert->toString(courtPosition));

/*    node->translate(posChange);
	btVector3 change; // = btVector3(0,0,0);
	change = BtOgre::Convert::toBullet(posChange); // converts from Ogre::Vector3 to btVector3
	physBody->translate(change); // moves physics body in unison with the model
*/
    logMsg(func + " end");
}

void basketballState::updateMovement()  // updates the basketball(s) movements
{
    conversionSharedPtr convert = conversion::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
    teamEntityMSharedPtr activeTeamInstance = gameInstance->getComponent()->getActiveTeamInstance();
    size_t teamWithBall = gameInstance->getData()->getTeamWithBall();
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
    std::string func = "basketballState::updateMovement()";

    logMsg(func + " beginning");

    if (courtPosition.x == 0 && courtPosition.y == 0 && courtPosition.z == 0)
    {
        bballCurrentPos = entity->getNode()->getPosition();
    }
    else
    {
        bballCurrentPos = courtPosition;
    }
//TS    playerPos = activePlayerInstance[playerWithBallInstance]->getCourtPosition();  // stores the current position of player with ball
    //bballPos = bballCurrentPos;
    bballPos = Ogre::Vector3(0,0,0);
    logMsg(func + " bballHere???");
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

    logMsg(func + " bballPos == " +convert->toString(bballPos));
    logMsg(func + " cbballPos == " +convert->toString(bballCurrentPos));
//TS        logMsg("pbballPos == " +convert->toString(activePlayerInstance[x]->getCourtPosition()));
    logMsg(func + " new bball court Position == " +convert->toString(bballPos));
    newCourtPosition = bballPos;
    courtPositionChanged = true;
    courtPositionChangedType = PLAYERMOVECHANGE;
        //basketballInstance[activeBBallInstance].setMovement(false);
        //basketballInstance[activeBBallInstance] = bballInstance;

    logMsg(func + " end");
}

void basketballState::updateDirection()  // updates basketball direction(s)
{
    //conversion *convert = conversion::Instance();
    conversionSharedPtr convert = conversion::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
    teamEntityMSharedPtr activeTeamInstance = gameInstance->getComponent()->getActiveTeamInstance();
    size_t teamWithBall = gameInstance->getData()->getTeamWithBall();
/*TS    playerStateVecSharedPtr activePlayerInstance = activeTeamInstance[teamWithBall]->getActivePlayerInstance();
    sizeTVec activePlayerID = activeTeamInstance[teamWithBall]->getActivePlayerID();
    
    size_t playerWithBallInstance = activeTeamInstance[teamWithBall]->getPlayerWithBallInstance();
    size_t playerWithBallID = activeTeamInstance[teamWithBall]->getPlayerWithBallID();
TS*/
    jumpBallsSharedPtr jumpBall = gameInstance->getComponent()->getJumpBall();

//TS    logMsg("directplayerwithballInstance == " +convert->toString(playerWithBallInstance));
    bool tipOffComplete = gameInstance->getFlag()->getTipOffComplete();
    size_t x = 0;
    std::string func = "basketballState::updateDirection()";

    logMsg(func + " beginning");

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
    gameInstance->getComponent()->setJumpBall(jumpBall);
    
    logMsg(func + " end");

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
