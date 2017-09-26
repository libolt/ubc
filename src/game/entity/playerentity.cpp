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

#include "entity/playerentity.h"
#include "logging.h"
#include "conversion.h"
#include "ubcbase.h"
#include "engine/gameengine.h"
#include "engine/renderengine.h"
#include "statistics/playerstatistics.h"
#include "data/playerdata.h"
#include "statemachine/playerstatemachine.h"

// static declarations
//UBCBaseSharedPtr playerEntity::base;  // base class object
    
//playerSteerSharedPtr playerEntity::steer;
//bool playerEntity::steerInitialized;

playerEntity::playerEntity()  // constructor
{
    steerInitialized = false;
    initialized = false;
    activePosition = NONE;
    courtPosition = Ogre::Vector3(0.0f,0.0f,0.0f);
    physBodyInitialized = false;
/*    baseInitialized = false;

    entityID = 0;
    physicsSetup = false;
    modelNeedsLoaded = false;
    modelLoaded = false;
    */
//    physics = new playerPhysics;
        posChange = Ogre::Vector3(0.0f,0.0f,0.0f);
    movement = false;
    startPosReached = false;
    shootBlock = false;
    passSteal = false;
    passBall = false;
    passCalculated = false;
    passToPlayer = NONE;
    shotTaken = false;
    shotSet = false;
    shotComplete = false;
    offenseSet = false;
    defenseSet = false;
//    initialized = false;
    jumpSet = false;
    jumpComplete = false;
//    courtPosition = Ogre::Vector3(0.0f,0.0f,0.0f);
    courtPositionChanged = false;
    physBodyInitialized = false;
    stateMachineInitialized = false;
    
    stateChanged = false;
    
    stateAction = NOACTION;
    
//    stateSet = false;
    // hack
  //  posChangeAmount = 0;
    direction = NODIRECT;
    oldDirection = NODIRECT;
}
playerEntity::~playerEntity()  // destructor
{

}

sharedPtr<playerData> playerEntity::getData()  // retrieves the value of data
{
    return (data);
}
void playerEntity::setData(sharedPtr<playerData> set)  // sets the value of data
{
    data = set;
}

sharedPtr<playerStateMachine> playerEntity::getStateMachine()  // retrieves the value of stateMachine
{
    return (stateMachine);
}
void playerEntity::setStateMachine(sharedPtr<playerStateMachine> set)  // sets the value of stateMachine
{
    stateMachine = set;
}

sharedPtr<playerPhysics> playerEntity::getPhysics()  // retrieves the value of physics
{
    return (physics);
}
void playerEntity::setPhysics(sharedPtr<playerPhysics> set)  // sets the value of physics
{
    physics = set;
}

playerSteerSharedPtr playerEntity::getSteer()  // retrieves the value of steer
{
    return (steer);
}
void playerEntity::setSteer(playerSteerSharedPtr set)  // sets the value of steer
{
    steer = set;
}

sharedPtr<playerStatistics> playerEntity::getStatistics()  // retrieves the value of statistics
{
    return (statistics);
}
void playerEntity::setStatistics(sharedPtr<playerStatistics> set)  // sets the value of statistics
{
    statistics = set;
}

bool playerEntity::getSteerInitialized()  // retrieves the value of steerInitialized
{
    return (steerInitialized);
}
void playerEntity::setSteerInitialized(bool set)  // sets the value of steerInitialized
{
    steerInitialized = set;
}

bool playerEntity::getInitialized()  // retrieves the value of initialized
{
    return (initialized);
}
void playerEntity::setInitialized(bool set)  // sets the value of initialized
{
    initialized = set;
}

playerPositions playerEntity::getActivePosition()  // retrieves the value of activePosition
{
    return (activePosition);
}
void playerEntity::setActivePosition(playerPositions set)  // sets the value of activePosition
{
    activePosition = set;
}

Ogre::Vector3 playerEntity::getCourtPosition()  // retrieves the value of courtPosition
{
    return (courtPosition);
}
void playerEntity::setCourtPosition(Ogre::Vector3 set)  // sets the value of courtPosition
{
    courtPosition = set;
}

bool playerEntity::getPhysBodyInitialized()  // retrieves the value of physBodyInitialized
{
    return (physBodyInitialized);
}
void playerEntity::setPhysBodyInitialized(bool set)  // sets the value of physBodyInitialized
{
    physBodyInitialized = set;
}

bool playerEntity::getStateMachineInitialized()  // retrieves the value of stateMachineInitialized
{
    return (stateMachineInitialized);
}
void playerEntity::setStateMachineInitialized(bool set)  // sets the value of stateMachineInitialized
{
    stateMachineInitialized = set;
}

bool playerEntity::getStateChanged()  // retrieves the value of stateChanged
{
    return (stateChanged);
}
void playerEntity::setStateChanged(bool set)  // sets the value of stateChanged
{
    stateChanged = set;
}

playerActions playerEntity::getStateAction()  // retrieves the value of stateAction
{
    return (stateAction);
}
void playerEntity::setStateAction(playerActions set)  // sets the value of stateAction
{
    stateAction = set; 
}

bool playerEntity::getMovement()  // retrieves the value of movement
{
    return (movement);
}
void playerEntity::setMovement(bool set)  // sets the value of movement
{
    movement = set;
}

directions playerEntity::getDirection()  // retrieves the value of direction
{
    return (direction);
}
void playerEntity::setDirection(directions set)  // sets the value of direction
{
    direction = set;
}

directions playerEntity::getOldDirection()  // retrieves the value of oldDirection
{
    return (oldDirection);
}
void playerEntity::setOldDirection(directions set)  // sets the value of oldDirection
{
    oldDirection = set;
}

Ogre::Vector3 playerEntity::getPosChange()  // retrieves the value of posChange
{
    return (posChange);
}
void playerEntity::setPosChange(Ogre::Vector3 set)  // sets the value of posChange
{
    posChange = set;
}

bool playerEntity::getStartPosReached()  // retrieves the value of startPosReached
{
    return (startPosReached);
}
void playerEntity::setStartPosReached(bool set)  // sets the value of startPosReached
{
    startPosReached = set;
}

bool playerEntity::getShootBlock()  // retrieves the value of shootBlock
{
    return (shootBlock);
}
void playerEntity::setShootBlock(bool set)   // sets the value of shootBlock
{
    shootBlock = set;
}

bool playerEntity::getPassSteal()  // retrieves the value of passSteal
{
    return (passSteal);
}
void playerEntity::setPassSteal(bool set)  // sets the value of passSteal
{
    passSteal = set;
}

bool playerEntity::getPassBall()  // retrieves the value of passBall
{
    return (passBall);
}
void playerEntity::setPassBall(bool set)  // sets the value of passBall
{
    passBall = set;
}

bool playerEntity::getPassCalculated()  // retrieves the value of passCalculated
{
    return (passCalculated);
}
void playerEntity::setPassCalculated(bool set)  // sets the value of passCalculated
{
    passCalculated = set;
}

bool playerEntity::getPassCompleted()  // retrieves the value of passCompleted
{
    return (passCompleted);
}
void playerEntity::setPassCompleted(bool set)  // sets the value of passCompleted
{
    passCompleted = set;
}

playerPositions playerEntity::getPassToPlayer()  // retrieves the value of passToPlayer
{
    return (passToPlayer);
}
void playerEntity::setPassToPlayer(playerPositions set)  // sets the value of passToPlayer
{
    passToPlayer = set;
}

bool playerEntity::getShotTaken()  // retrieves the value of shotTaken
{
    return (shotTaken);
}
void playerEntity::setShotTaken(bool set)  // sets the value of shotTaken
{
    shotTaken = set;
}

bool playerEntity::getShotSet()  // retrieves the value of shotSet
{
    return (shotSet);
}
void playerEntity::setShotSet(bool set)  // sets the value of shotSet
{
    shotSet = set;
}

bool playerEntity::getShotComplete()  // retrieves the value of shotComplete
{
    return (shotComplete);
}
void playerEntity::setShotComplete(bool set)  // sets the value of shotComplete
{
    shotComplete = set;
}

Ogre::Vector3 playerEntity::getJumpBeginPos()  // retrieves the value of playerJumpBeginPos
{
    return (jumpBeginPos);
}
void playerEntity::setJumpBeginPos(Ogre::Vector3 set)  // sets the value of playerJumpBeginPos
{
    jumpBeginPos = set;
}

Ogre::Vector3 playerEntity::getJumpEndPos()  // retrieves the value of playerJumpEndPos
{
    return (jumpEndPos);
}
void playerEntity::setJumpEndPos(Ogre::Vector3 set)  // sets the value of playerJumpEndPos
{
    jumpEndPos = set;
}

bool playerEntity::getJumpSet()  // retrieves the value of jumpSet
{
    return (jumpSet);
}
void playerEntity::setJumpSet(bool set)  // sets the value of jumpSet
{
    jumpSet = set;
}

bool playerEntity::getJumpComplete()  // retrieves the value of jumpComplete
{
    return (jumpComplete);
}
void playerEntity::setJumpComplete(bool set)  // sets the value of jumpComplete
{
    jumpComplete = set;
}

bool playerEntity::getOffenseSet()  // retrieves the value of offenseSet
{
    return (offenseSet);
}
void playerEntity::setOffenseSet(bool set)  // sets the value of offenseSet
{
    offenseSet = set;
}

bool playerEntity::getDefenseSet()  // retrieves the value of defenseSet
{
    return (defenseSet);
}
void playerEntity::setDefenseSet(bool set)  // sets the value of defenseSet
{
    defenseSet = set;
}

/*Ogre::Vector3 playerState::getCourtPosition()  // retrieves the value of courtPosition
{
//    courtPosition = Ogre::Vector3(1,1,1);
    return (courtPosition);
//    return (getNode()->getPosition());
}
void playerState::setCourtPosition(Ogre::Vector3 set)  // sets the value of courtPosition
{
    courtPosition = set;
}*/

Ogre::Vector3 playerEntity::getNewCourtPosition()  // retrieves the value of newCourtPosition
{
    return (newCourtPosition);
}
void playerEntity::setNewCourtPosition(Ogre::Vector3 set)  // sets the value of newCourtPosition
{
    newCourtPosition = set;
}

bool playerEntity::getCourtPositionChanged()  // retrieves the value of courtPositionChanged
{
    return (courtPositionChanged);
}
void playerEntity::setCourtPositionChanged(bool set)  // sets the value of courtPositionChanged
{
    courtPositionChanged = set;
}

positionChangedTypes playerEntity::getCourtPositionChangedType()  // retrieves the value of courtPositionChangedType
{
    return (courtPositionChangedType);
}
void playerEntity::setCourtPositionChangedType(positionChangedTypes set)  // sets the value of courtPositionChangedType
{
    courtPositionChangedType = set;
}
bool playerEntity::initialize()  // initializes the player entity object
{
    sharedPtr<playerPhysics> tempPhysics(new playerPhysics);
    physics = tempPhysics;

    sharedPtr<playerData> tempData(new playerData);
    data = tempData;
    
    sharedPtr<playerStatistics> tempStats(new playerStatistics);
    statistics = tempStats;
    
    sharedPtr<playerStateMachine> tempStateMachine(new playerStateMachine);
    stateMachine = tempStateMachine;
    
    return (true);
}

bool playerEntity::setupPhysicsObject()  // sets up the physics object
{
    std::string func = "playerEntity::setupPhysicsObject()!";
    OgreEntitySharedPtr tempModel = getModel();
    OgreSceneNodeSharedPtr tempNode = getNode();
    btRigidBody *tempPhysBody = getPhysics()->getPhysBody().get();
    
    logMsg(func +" beginning");
    
    if (!getPhysics()->getGameSInitialized())
    {
        getPhysics()->setGameS(getBase()->getGameS());
        getPhysics()->setGameSInitialized(true);
    }

    getPhysics()->setMass(1.0f);
    getPhysics()->setRestitution(0.0f);
    getPhysics()->setFriction(0.0f);
//    exit(0);
    getPhysics()->setShapeType(CAPSULE);
    getPhysics()->setColObject(COL_PLAYER0);
    getPhysics()->setCollidesWith(COL_COURT);

    if (getPhysics()->setupPhysics(&tempModel, &tempNode, &tempPhysBody))
    {
        

        setPhysicsSetup(true);
        logMsg(func +" setModel");
        setModel(OgreEntitySharedPtr(tempModel));
        logMsg(func +" setNode");
        logMsg(func +" tempNode name == " +tempNode->getName());
        setNode(OgreSceneNodeSharedPtr(tempNode));
        logMsg(func +" setPhysBody");
        getPhysics()->setPhysBody(btRigidBodySharedPtr(tempPhysBody));
//        exit(0);

        return (true);
    }
    else
    {
    }
    
    logMsg(func +" end");
    
    return (false);
}

bool playerEntity::initializeStateMachine()  // initializes the stateMachine object
{
    playerSMData *SMData = new playerSMData;
    
//    SMData->speed = 100;
    SMData->model = getModel();  //
    SMData->node = getNode();
    stateMachine->setSpeed(SMData);
    stateMachine->halt();
    return (true);
}

bool playerEntity::updateStateMachine(playerActions actionType, playerSMData *SMData)  // updates state machine with external input
{
    sharedPtr<conversion> convert = conversion::Instance();

    std::string func = "playerEntity::updateStateMachine()";

    logMsg(func + " beginning");
    
    switch (stateAction)
    {
        case CHANGECOURTPOS:
            stateMachine->pChangePosition(SMData);
        break;
        case SETNODEMODEL:
            stateMachine->setPNodeModel(SMData);
        break;
        
    logMsg(func + " end");
    exit(0);
    
    return (true);
}

bool playerEntity::update() // executes any updates that need to be performed
{
    std::string func = "playerEntity::update()";
    playerSMData *stateData
    
    logMsg(func +" beginning");

    if (stateChanged)
    {
        switch (stateAction)
        {
            case CHANGECOURTPOS:
                logMsg(func + " CHANGECOURTPOS!");
                stateData = new playerSMData;
                stateData->position = newCourtPosition;
                updateStateMachine(stateAction,stateData);
            break;
            case SETNODEMODEL:
                logMsg(func + " SETNODEMODEL!");
                stateData = new playerSMData;
                stateData->node = getNode();
                stateData->model = getModel();  
                updateStateMachine(stateAction,stateData);

            break;
        }
    }

    logMsg(func +" end");
}
