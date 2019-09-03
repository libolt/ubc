/***************************************************************************
 *   Copyright (C) 1999 - 2019 by Mike McLean                              *
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

#include "ai/basketballsteer.h"
#include "statemachine/basketballstatemachine.h"
#include "components/basketballcomponents.h"
#include "components/gamecomponents.h"
#include "data/basketballdata.h"
#include "data/gamedata.h"
#include "engine/renderengine.h"
#include "flags/basketballflags.h"
#include "flags/gameflags.h"
#include "physics/basketballphysics.h"
#include "utilities/comparison.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

basketballStateMachine::basketballStateMachine() :
    stateMachine(ST_MAX_STATES),
    m_currentSpeed(0)
{
}
    
// Initialize state machine external event
void basketballStateMachine::pInitialize(basketballSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_LOAD_MODEL
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(data)
}

// Load Model external event
void basketballStateMachine::pLoadModel(basketballSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_LOAD_MODEL)                // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_LOAD_MODEL
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (ST_LOAD_MODEL)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_LOAD_MODEL)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_LOAD_MODEL)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_LOAD_MODEL)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_LOAD_MODEL)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (ST_LOAD_MODEL)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (ST_LOAD_MODEL)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(data)
}

// Create Node state machine external event
void basketballStateMachine::pCreateNode(basketballSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_CREATE_NODE)                // ST_LOAD_MODEL
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (ST_CREATE_NODE)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_CREATE_NODE)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_CREATE_NODE)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_CREATE_NODE)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_CREATE_NODE)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (ST_CREATE_NODE)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (ST_CREATE_NODE)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(data)
}

// set motor speed external event
void basketballStateMachine::setSpeed(basketballSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)              // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)              // ST_LOAD_MODEL
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)              // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)              // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)              // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(data)
}

// halt motor external event
void basketballStateMachine::halt()
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_LOAD_MODEL
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(nullptr)
}

// Update positions external event
void basketballStateMachine::pUpdatePosition(basketballSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_LOAD_MODEL
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(data)
}

// Update movement external event
void basketballStateMachine::pUpdateMovement(basketballSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                     // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                     // ST_LOAD_MODEL
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                     // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(data)
}

// Update direction external event
void basketballStateMachine::pUpdateDirection(basketballSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                      // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                      // ST_LOAD_MODEL
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                      // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(data)
}

// Initialize the state machine
STATE_DEFINE(basketballStateMachine, Initialize, basketballSMData)
{
    std::string func = "basketballStateMachine::Initialize()";

    logMsg(func +" begin");
//    exit(0);

    basketballSMData *tempSMData(new basketballSMData);

    basketballDataSharedPtr tempData(new basketballData);
    tempSMData->bData = tempData;

    basketballComponentsSharedPtr tempComponent(new basketballComponents);
    tempSMData->component = tempComponent;

    basketballFlagsSharedPtr tempFlag(new basketballFlags);
    tempSMData->flag = tempFlag;

    sharedPtr<basketballPhysics> tempPhysics(new basketballPhysics);
    tempSMData->physics = tempPhysics;
//    exit(0);
    data = tempSMData;
/*    basketballEntitySharedPtr tempEntity(new basketballEntity);
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
    }*/

    logMsg(func +" end");

}


// Initialize the state machine
STATE_DEFINE(basketballStateMachine, LoadModel, basketballSMData)
{
    conversionSharedPtr convert;


    std::string func = "basketballStateMachine::LoadModel()";

    logMsg(func +" begin");


    logMsg(func +" end");
}

// Initialize the state machine
STATE_DEFINE(basketballStateMachine, CreateNode, basketballSMData)
{
    conversionSharedPtr convert;

    OgreEntitySharedPtr activeModel;
    OgreSceneNodeSharedPtr activeNode;
    std::string activeEntityName;
    std::string activeNodeNum;
    std::string activeNodeName;

    std::string func = "basketballStateMachine::CreateNode()";

    logMsg(func +" begin");

    activeModel = data->component->getModel();
    activeEntityName = data->component->getName();
    activeNodeNum = convert->toString(data->component->getNumber());
    activeNodeName = data->component->getNodeName();
    if (activeNodeName.empty())
    {
        activeNodeName = activeEntityName + activeNodeNum;
        data->component->setNodeName(activeNodeName);
    }
    else
    {

    }
    activeNode = data->render->createNode(activeModel, activeNodeName);  // creates node
    data->component->setNode(activeNode);  // saves node to current instance

    logMsg(func +" end");

}

// sets up basketball physics object
STATE_DEFINE(basketballStateMachine, SetupPhysics, basketballSMData)
{
    conversionSharedPtr convert;
    std::string func = "basketballStateMachine::setupPhysics()";
    OgreEntitySharedPtr tempModel = data->model;
    OgreSceneNodeSharedPtr tempNode = data->node;
    basketballComponentsSharedPtr component = data->component;
    basketballFlagsSharedPtr flag = data->flag;
    btRigidBody *tempPhysBody = component->getPhysics()->getPhysBody().get();
    bool returnType = false;
    
    logMsg(func +" begin");
    
    if (!component->getPhysics()->getGameInstanceInitialized())
    {
        component->getPhysics()->setGameInstanceInitialized(true);
    }
    
    component->getPhysics()->setMass(0.05f);
    component->getPhysics()->setRestitution(0.85f);
    component->getPhysics()->setFriction(0.0f);
    logMsg("tempNode->getName() == " +tempNode->getName());
    component->getPhysics()->setShapeType(SPHERE);
    logMsg(func +" setShapeType!");
    component->getPhysics()->setColObject(COL_BBALL);
    logMsg(func +" setColObject!");
    component->getPhysics()->setCollidesWith(COL_COURT);
    logMsg(func +" setCollidesWith!");

    if (component->getPhysics()->setupPhysics(&tempModel, &tempNode, &tempPhysBody))
    {
        
        logMsg(func +" setupPhysics!");
        flag->setPhysicsSetup(true);

        logMsg(func +" modelName == " +tempModel->getName());
        logMsg(func +" nodeName == " +tempNode->getName());

//        exit(0);
        component->getPhysics()->setPhysBody(btRigidBodySharedPtr(tempPhysBody));

        basketballSMData *tempSMData(new basketballSMData);

        tempSMData->model = OgreEntitySharedPtr(tempModel);
        tempSMData->node = OgreSceneNodeSharedPtr(tempNode);
        tempSMData->component = component;

        data = tempSMData;
//        exit(0);
        returnType = true;;

    }
    else
    {
    }

    logMsg(func +" end");
}

// stops movement of basketball object
STATE_DEFINE(basketballStateMachine, StopMovement, noEventData)
{
    
}

// state machine sits here when motor is not running
STATE_DEFINE(basketballStateMachine, Idle, noEventData)
{
    logMsg("Motor::ST_Idle");
}


// changes the motor speed once the motor is moving
STATE_DEFINE(basketballStateMachine, ChangeSpeed, basketballSMData)
{
    conversionSharedPtr convert;

//    logMsg("Motor::ST_ChangeSpeed : Speed is " +convert->toString(data->speed));
//    m_currentSpeed = data->speed;

    // perform the change motor speed to data->speed here
}

// updates position of basketball objects
STATE_DEFINE(basketballStateMachine, UpdatePosition, basketballSMData)
{
    conversionSharedPtr convert;
    comparison compare;
    Ogre::Vector3 changePos;
    btVector3 physChange = btVector3(0,0,0);
    basketballComponentsSharedPtr component = data->component;
//    basketballDataSharedPtr bData;  // stores copy of basketballData object
    basketballFlagsSharedPtr flag = data->flag;
    basketballPhysicsSharedPtr physics = data->physics;
    OgreSceneNodeSharedPtr node = data->node;
    std::string func = "basketballStateMachine::updatePosition()";

    
    logMsg(func + " beginning");
    if (flag->getCourtPositionChanged())
    {
        //exit(0);
        switch (component->getCourtPositionChangedType())
        {
            case STARTCHANGE:
                logMsg(func + " Updating basketball court position based on start position");
                
                node->translate(component->getNewCourtPosition());
                physChange = BtOgre::Convert::toBullet(component->getNewCourtPosition()); // converts from Ogre::Vector3 to btVector3
                component->getPhysics()->getPhysBody()->translate(physChange); // moves physics body in unison with the model
                component->getSteer()->setPosition(convert->toOpenSteerVec3(component->getNewCourtPosition()));
                flag->setCourtPositionChanged(false);
                component->setCourtPositionChangedType(NOCHANGE);
            break;
            
            case STEERCHANGE:
                logMsg(func + " Updating basketball court position based on steering");
                //logMsg("Team " +convert->toString(teamNumber) + " Player " +convert->toString(playerID));
                changePos = compare.OgreVector3ToOgreVector3Result(component->getCourtPosition(), component->getNewCourtPosition());
                node->translate(changePos);
                physChange = BtOgre::Convert::toBullet(changePos); // converts from Ogre::Vector3 to btVector3
                component->getPhysics()->getPhysBody()->translate(physChange); // moves physics body in unison with the model
               
                flag->setCourtPositionChanged(false);
                component->setCourtPositionChangedType(NOCHANGE);
            break;   

            case INPUTCHANGE:
                logMsg(func + " Updating court position based on input");
                node->translate(component->getNewCourtPosition());
                physChange = BtOgre::Convert::toBullet(component->getNewCourtPosition()); // converts from Ogre::Vector3 to btVector3
                component->getPhysics()->getPhysBody()->translate(physChange); // moves physics body in unison with the model
                component->getSteer()->setPosition(convert->toOpenSteerVec3(component->getNewCourtPosition()));
                flag->setCourtPositionChanged(false);
                component->setCourtPositionChangedType(NOCHANGE);
                //exit(0);
            break;

            case PHYSICSCHANGE:
                logMsg(func + " Updating basketball court position based on physics");
                //exit(0);
            break;
            case PLAYERMOVECHANGE:
                logMsg(func + " Updating basketball court position based on player movement");
                node->translate(component->getNewCourtPosition());
                logMsg(func + " bball newCourtPosition = " +convert->toString(component->getNewCourtPosition()));
                logMsg(func + " bball node position" +convert->toString((node->getPosition())));
                //exit(0);
                physChange = BtOgre::Convert::toBullet(component->getNewCourtPosition()); // converts from Ogre::Vector3 to btVector3
                component->getPhysics()->getPhysBody()->translate(physChange); // moves physics body in unison with the model
                //steer->setPosition(convert->toOpenSteerVec3(component->getNewCourtPosition()));
                flag->setCourtPositionChanged(false);
                component->setCourtPositionChangedType(NOCHANGE);
//                exit(0);
            break;
            case PLAYERDIRECTCHANGE:
                logMsg(func + " Updating basketball court position based on player movement");
                node->translate(component->getNewCourtPosition());
                logMsg(func + " bball newCourtPosition = " +convert->toString(component->getNewCourtPosition()));
                logMsg(func + " bball node position" +convert->toString((node->getPosition())));
                //exit(0);
                physChange = BtOgre::Convert::toBullet(component->getNewCourtPosition()); // converts from Ogre::Vector3 to btVector3
                component->getPhysics()->getPhysBody()->translate(physChange); // moves physics body in unison with the model
                //steer->setPosition(convert->toOpenSteerVec3(component->getNewCourtPosition()));
                flag->setCourtPositionChanged(false);
                component->setCourtPositionChangedType(NOCHANGE);
            break;
            default:
            break;
        }
        component->setCourtPosition(node->getPosition());
        logMsg("basketball position = " +convert->toString(component->getCourtPosition()));
    }
    
    logMsg("basketball position = " +convert->toString(component->getCourtPosition()));

/*    node->translate(posChange);
    btVector3 change; // = btVector3(0,0,0);
    change = BtOgre::Convert::toBullet(posChange); // converts from Ogre::Vector3 to btVector3
    physBody->translate(change); // moves physics body in unison with the model
*/

    basketballSMData *tempSMData(new basketballSMData);

    tempSMData->component = component;
    tempSMData->flag = flag;
    tempSMData->node = node;
    
    data = tempSMData;

    logMsg(func + " end");
    
}

// updates movement of basketball objects
STATE_DEFINE(basketballStateMachine, UpdateMovement, basketballSMData)
{
    
    conversionSharedPtr convert;
    teamEntityMSharedPtr activeTeamInstance = data->gComponent->getActiveTeamInstance();
    size_t teamWithBall = data->gData->getTeamWithBall();
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
    
    basketballComponentsSharedPtr component = data->component;
    basketballFlagsSharedPtr flag = data->flag;
    OgreSceneNodeSharedPtr node = data->node;
    std::string func = "basketballState:Machine:updateMovement()";

    logMsg(func + " beginning");

    if (component->getCourtPosition().x == 0 && component->getCourtPosition().y == 0 && component->getCourtPosition().z == 0)
    {
        bballCurrentPos = node->getPosition();
    }
    else
    {
        bballCurrentPos = component->getCourtPosition();
    }
//TS    playerPos = activePlayerInstance[playerWithBallInstance]->getCourtPosition();  // stores the current position of player with ball
    //bballPos = bballCurrentPos;
    bballPos = Ogre::Vector3(0,0,0);
    logMsg(func + " bballHere???");
    switch (component->getDirection())
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
    component->setNewCourtPosition(bballPos);
    flag->setCourtPositionChanged(true);
    component->setCourtPositionChangedType(PLAYERMOVECHANGE);
        //basketballInstance[activeBBallInstance].setMovement(false);
        //basketballInstance[activeBBallInstance] = bballInstance;

    basketballSMData *tempSMData(new basketballSMData);

    tempSMData->component = component;
    tempSMData->flag = flag;
    data = tempSMData;
    logMsg(func + " end");
}

// updates direction of basketball objects
STATE_DEFINE(basketballStateMachine, UpdateDirection, basketballSMData)
{
    conversionSharedPtr convert;
    
    gameComponentsSharedPtr gameComponent = data->gComponent;
    gameDataSharedPtr gameData = data->gData;
    gameFlagsSharedPtr gameFlag = data->gFlag;
    
//    sharedPtr<gameState> gameS = gameState::Instance();
    teamEntityMSharedPtr activeTeamInstance = gameComponent->getActiveTeamInstance();
    size_t teamWithBall = gameData->getTeamWithBall();
/*TS    playerStateVecSharedPtr activePlayerInstance = activeTeamInstance[teamWithBall]->getActivePlayerInstance();
    sizeTVec activePlayerID = activeTeamInstance[teamWithBall]->getActivePlayerID();
    
    size_t playerWithBallInstance = activeTeamInstance[teamWithBall]->getPlayerWithBallInstance();
    size_t playerWithBallID = activeTeamInstance[teamWithBall]->getPlayerWithBallID();
TS*/
    jumpBallsSharedPtr jumpBall = gameComponent->getJumpBall();

//TS    logMsg("directplayerwithballInstance == " +convert->toString(playerWithBallInstance));
    bool tipOffComplete = gameFlag->getTipOffComplete();
    size_t x = 0;
    std::string func = "basketballStateMachine::updateDirection()";

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
    gameComponent->setJumpBall(jumpBall);
    
    basketballSMData *tempSMData(new basketballSMData);

    tempSMData->gComponent = gameComponent;
    tempSMData->gData = gameData;
    tempSMData->gFlag = gameFlag;
    
    data = tempSMData;

    logMsg(func + " end");

}
