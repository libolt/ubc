/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean                              *
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
#include "state/gamestate.h"
#include "engine/renderengine.h"
#include "comparison.h"
#include "logging.h"
#include "jumpballs.h"

#include <string>

 basketballs::basketballs()  // constructor
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

    teamNumber = 0;
    player = 0;

//    modelNeedsLoaded = false;
//    modelLoaded = false;
    numberSet = false;
    
    courtPosition = Ogre::Vector3(0,0,0);
    newCourtPosition = Ogre::Vector3(0,0,0);
    courtPositionChanged = false;
    number = 999999;
//    stateSet = false;

}

basketballs::~basketballs()  // destructor
{
}

/*Ogre::Vector3 basketballs::getNodePosition()  // retrieves position of basketball node
{
	return (node->getPosition());
}
*/
float basketballs::getMaxHeight(void)  // retrieves the value of maxHeight
{
    return(maxHeight);
}
void basketballs::setMaxHeight(float set)  // sets the value og maxHeight
{
    maxHeight = set;
}

bool basketballs::getMaxHeightReached(void)  // retrieves the value of maxHeightReached
{
    return(maxHeightReached);
}
void basketballs::setMaxHeightReached(bool set)  // sets the value of maxHeightReachef
{
    maxHeightReached = set;
}

float basketballs::getMinHeight(void)  // retrieves the value minHeight
{
    return(minHeight);
}
void basketballs::setMinHeight(float set)  // sets the value of minHeight
{
    minHeight = set;
}

bool basketballs::getMinHeightReached(void)  // retrieves the value of minHeightReached
{
    return(minHeightReached);
}
void basketballs::setMinHeightReached(bool set)  // sets the value of minHeightReached
{
    minHeightReached = set;
}

size_t basketballs::getRotate(void)  // retrieves the value of rotate
{
    return (rotate);
}
void basketballs::setRotate(size_t set)  // sets the value of rotate
{
    rotate = set;
}

size_t basketballs::getTeamNumber(void)  // retrieves the value of teamNumber
{
    return(teamNumber);
}
void basketballs::setTeamNumber(size_t set)  // sets the value of teamNumber
{
    teamNumber = set;
}

Ogre::Vector3 basketballs::getVelocity(void)  // retrieves the value of velocity
{
    return(velocity);
}
void basketballs::setVelocity(Ogre::Vector3 set)  // sets the value of velocity
{
    velocity = set;
}

Ogre::Vector3 basketballs::getStartCoords(void)  // retrieves the value of startCoords
{
    return(startCoords);
}
void basketballs::setStartCoords(Ogre::Vector3 set) // sets the value of startCoords
{
    startCoords = set;
}

bool basketballs::getTipOffStart()  // retroeves the value of tipOffStart
{
    return (tipOffStart);
}
void basketballs::setTipOffStart(bool set)  // sets the value of tipOffStart
{
    tipOffStart = set;
}

bool basketballs::getTipOff()  // retrieves the value of tipOff
{
    return (tipOff);
}
void basketballs::setTipOff(bool set)  // sets the value of tipOff
{
    tipOff = set;
}

bool basketballs::getDribblingStart(void)  // retrieves the value of dribblingStart
{
    return (dribblingStart);
}
void basketballs::setDribblingStart(bool set)  // sets the value of dribblingStart
{
    dribblingStart = set;
}

bool basketballs::getDribbling(void)  // retrieves the value of dribbling
{
    return (dribbling);
}
void basketballs::setDribbling(bool set)  // sets the value of dribbling
{
    dribbling = set;
}

bool basketballs::getMovement()  // retrieves the value of movement
{
    return (movement);
}
void basketballs::setMovement(bool set)  // sets the value of movement
{
    movement = set;
}

bool basketballs::getDirectChange() // retrieves the value of directChange
{
    return (directChange);
}
void basketballs::setDirectChange(bool set)  // sets the value of directChange
{
    directChange = set;
}
directions basketballs::getDirection()  // retrieves the value of direction
{
    return (direction);
}
void basketballs::setDirection(directions set)  // sets the value of direction 
{
    direction = set;
}

directions basketballs::getOldDirection()  // retrieves the value of oldDirection
{
    return (oldDirection);
}
void basketballs::setOldDirection(directions set)  // sets the value of oldDirection 
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
bool basketballs::getNumberSet()  // retrieves the value of numberSet
{
    return (numberSet);
}
void basketballs::setNumberSet(bool set)  // sets the value of numberSet
{
    numberSet = set;
}

Ogre::Vector3 basketballs::getCourtPosition()  // retrieves the value of courtPosition
{
    return (courtPosition);
}
void basketballs::setCourtPosition(Ogre::Vector3 set)  // sets the value of courtPosition
{
    courtPosition = set;
}

Ogre::Vector3 basketballs::getNewCourtPosition()  // retrieves the value of newCourtPosition
{
    return (newCourtPosition);
}
void basketballs::setNewCourtPosition(Ogre::Vector3 set)  // sets the value of newCourtPosition
{
    newCourtPosition = set;
}

bool basketballs::getCourtPositionChanged()  // retrieves the value of courtPositionChanged
{
    return (courtPositionChanged);
}
void basketballs::setCourtPositionChanged(bool set)  // sets the value of courtPositionChanged
{
    courtPositionChanged = set;
}

positionChangedTypes basketballs::getCourtPositionChangedType()  // retrieves the value of courtPositionChangedType
{
    return (courtPositionChangedType);
}
void basketballs::setCourtPositionChangedType(positionChangedTypes set)  // sets the value of courtPositionChangedType
{
    courtPositionChangedType = set;
}

size_t basketballs::getNumber()  // retrieves the value of number
{
    return (number);
}
void basketballs::setNumber(size_t set)  // sets the value of number
{
    number = set;
    getPhysics().setNumber(set); // sets the physics number as well
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
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

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
Ogre::Vector3 basketballs::calculatePositionChange()
{
    boost::shared_ptr<gameState> gameS = gameState::Instance();

    Ogre::Vector3 changeInPosition;	// stores the calculated change in position
    Ogre::Vector3 pos = getNode()->getPosition();	// stores the basketball nodes position

    // initializes the variable
    changeInPosition[0] = 0.0f;
    changeInPosition[1] = 0.0f;
    changeInPosition[2] = 0.0f;
    return(changeInPosition);
}

void basketballs::updateState()  // updates the state of the basketball
{
    bool modelNeedsLoaded = getModelNeedsLoaded();
    if (getModelNeedsLoaded())
    {
//        exit(0);
        if (loadModel("basketball"))
        {
            setModelNeedsLoaded(false);
            setModelLoaded(true);
            
        }
    }

    if (numberSet)  // runs the physics update code
    {
        getPhysics().updateState();
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

void basketballs::updatePosition() // updates the position of the basketball
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
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

void basketballs::updateMovement()  // updates the basketball(s) movements
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    std::vector<teamState> teamInstance = gameS->getTeamInstance();
    size_t teamWithBall = gameS->getTeamWithBall();
    std::vector<playerState> activePlayerInstance = teamInstance[teamWithBall].getActivePlayerInstance();
    size_t playerWithBallInstance = teamInstance[teamWithBall].getPlayerWithBallInstance();
    size_t playerWithBallID = teamInstance[teamWithBall].getPlayerWithBallID();
    size_t x = 0;
    
    bool shotTaken = activePlayerInstance[playerWithBallInstance].getShotTaken();
    Ogre::Vector3 bballPos;
    Ogre::Vector3 bballCurrentPos;  // stores the current position of the basketball(s)
    Ogre::Vector3 playerPos;
    logMsg("playerWithBallInstance == " +convert->toString(playerWithBallInstance));
    logMsg("playerWithBallID == " +convert->toString(playerWithBallID));

    if (courtPosition.x == 0 && courtPosition.y == 0 && courtPosition.z == 0)
    {
        bballCurrentPos = getNode()->getPosition();
    }
    else
    {
        bballCurrentPos = courtPosition;
    }
    playerPos = activePlayerInstance[playerWithBallInstance].getCourtPosition();  // stores the current position of player with ball
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
        logMsg("pbballPos == " +convert->toString(activePlayerInstance[x].getCourtPosition()));
        logMsg("new bball court Position == " +convert->toString(bballPos));
        newCourtPosition = bballPos;
        courtPositionChanged = true;
        courtPositionChangedType = PLAYERMOVECHANGE;
        //basketballInstance[activeBBallInstance].setMovement(false);
        //basketballInstance[activeBBallInstance] = bballInstance;

}

void basketballs::updateDirection()  // updates basketball direction(s)
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    std::vector<teamState> teamInstance = gameS->getTeamInstance();
    size_t teamWithBall = gameS->getTeamWithBall();
    std::vector<playerState> activePlayerInstance = teamInstance[teamWithBall].getActivePlayerInstance();
    std::vector<size_t> activePlayerID = teamInstance[teamWithBall].getActivePlayerID();
    
    size_t playerWithBallInstance = teamInstance[teamWithBall].getPlayerWithBallInstance();
    size_t playerWithBallID = teamInstance[teamWithBall].getPlayerWithBallID();


    jumpBalls jumpBall = gameS->getJumpBall();

    logMsg("directplayerwithballInstance == " +convert->toString(playerWithBallInstance));
    bool tipOffComplete = gameS->getTipOffComplete();
    size_t x = 0;

    bool shotTaken = activePlayerInstance[playerWithBallInstance].getShotTaken();

    if (!shotTaken)
    {
        
        Ogre::Vector3 posChange;
        while (x < activePlayerInstance.size())
        {
            if (activePlayerInstance[x].getPlayerID() == playerWithBallID)
            {
                playerWithBallInstance = x;
                break;
            }
            ++x;
        }
        
        if (playerWithBallInstance >= 0 && playerWithBallInstance < 10 && tipOffComplete == true)  // verifies that the playerWithBall variable is set to a valid number
        {
            Ogre::Vector3 playerPos= activePlayerInstance[playerWithBallInstance].getNode()->getPosition();
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
    gameS->setJumpBall(jumpBall);
}

size_t basketballs::getPlayer()
{
    return (player);
}

void basketballs::setPlayer(size_t Player)
{
    player = Player;
}

// calculates the trajectory the basketball travels when shot
bool basketballs::calculateShot()
{
    return true;
}

// handles the shot logic as the ball travels towards the hoop
bool basketballs::shotLogic()
{
    return true;
}
