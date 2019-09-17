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
#include "statemachine/hoopstatemachine.h"
#include "components/hoopcomponents.h"
//#include "components/gamecomponents.h"
//#include "data/hoopdata.h"
//#include "data/gamedata.h"
#include "engine/renderengine.h"
#include "flags/hoopflags.h"
//#include "flags/gameflags.h"
#include "load/loadhoops.h"
#include "physics/hoopphysics.h"
#include "utilities/comparison.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

hoopStateMachine::hoopStateMachine() :
    stateMachine(ST_MAX_STATES),
    m_currentSpeed(0)
{
}    

// Initialize state machine external event
void hoopStateMachine::pInitialize(const hoopSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_INITIALIZE       
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_INITIALIZE_COMPONENTS
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_LOAD_MDOEL
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(data)
}

// Initailize Components external event
void hoopStateMachine::pInitializeComponents(hoopSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_INITIALIZE_COMPONENTS)     // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_INITIALIZE_COMPONENTS)     // ST_INITIALIZE_COMPONENTS
        TRANSITION_MAP_ENTRY (ST_INITIALIZE_COMPONENTS)     // ST_LOAD_MDOEL
        TRANSITION_MAP_ENTRY (ST_INITIALIZE_COMPONENTS)     // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_INITIALIZE_COMPONENTS)              // ST_IDLE
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(data)
}

// Initailize Components external event
void hoopStateMachine::pLoadModel(hoopSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_LOAD_MDOEL)     // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_LOAD_MDOEL)     // ST_INITIALIZE_COMPONENTS
        TRANSITION_MAP_ENTRY (ST_LOAD_MDOEL)     // ST_LOAD_MDOEL
        TRANSITION_MAP_ENTRY (ST_LOAD_MDOEL)     // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_LOAD_MDOEL)              // ST_IDLE
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(data)
}

// Initailize Components external event
void hoopStateMachine::pCreateNode(hoopSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_CREATE_NODE)     // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_CREATE_NODE)     // ST_INITIALIZE_COMPONENTS
        TRANSITION_MAP_ENTRY (ST_CREATE_NODE)     // ST_LOAD_MODEL
        TRANSITION_MAP_ENTRY (ST_CREATE_NODE)     // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_CREATE_NODE)              // ST_IDLE
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(data)
}


// halt motor external event
void hoopStateMachine::halt()
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_INITIALIZE_COMPONENTS
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_LOAD_MODEL
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_IDLE
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(nullptr)
}

// Update positions external event
void hoopStateMachine::pUpdatePosition(hoopSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                     // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_INITIALIZE_COMPONENTS
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_LOAD_MODEL
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(data)
}

// Update movement external event
void hoopStateMachine::pUpdateMovement(hoopSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                     // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_INITIALIZE_COMPONENTS
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_LOAD_MODEL
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(data)
}

// Update direction external event
void hoopStateMachine::pUpdateDirection(hoopSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                      // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_INITIALIZE_COMPONENTS
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_LOAD_MODEL
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(data)
}

// Initialize the state machine
STATE_DEFINE(hoopStateMachine, Initialize, hoopSMData)
{
    std::string func = "hoopStateMachine::Initialize()";

    logMsg(func +" begin");

    hoopSMData *tempSMData(new hoopSMData);

    hoopComponentsSharedPtr tempComponent(new hoopComponents);
    tempSMData->component = tempComponent;

//    hoopDataSharedPtr tempData(new hoopData);
//    tempSMData->cData = tempData;

    hoopFlagsSharedPtr tempFlag(new hoopFlags);
    tempSMData->flag = tempFlag;

    data = tempSMData;
    
#ifdef BTOGRE_MYGUI_ENABLED
    hoopPhysicsSharedPtr tempPhysics(new hoopPhysics);
    data->component->setPhysics(tempPhysics);
#endif

    logMsg(func +" end");
    
//    internalEvent(ST_INITIALIZE_COMPONENTS);
}

// Initialize the component objects
STATE_DEFINE(hoopStateMachine, InitializeComponents, hoopSMData)
{
    
    conversionSharedPtr convert;
    std::string func = "hoopStateMachine::InitializeComponents()";

    logMsg(func +" begin");

/*    hoopDataSharedPtr tempData(new hoopData);
    data->cData = tempData;

    hoopComponentsSharedPtr tempComponent(new hoopComponents);
    data->component = tempComponent;

    hoopFlagsSharedPtr tempFlag(new hoopFlags);
    data->flag = tempFlag;
*/


        logMsg(func +" end");

}

// Loads the hoop model
STATE_DEFINE(hoopStateMachine, LoadModel, hoopSMData)
{

    conversionSharedPtr convert;
    loadHoopsSharedPtr loadHoop(new loadHoops);
    hoopSMData *lmSMData(new hoopSMData);
    std::string func = "hoopStateMachine::LoadModel()";

    logMsg(func +" begin");

    lmSMData->component = data->component;
    lmSMData->flag = data->flag;
    lmSMData->render = data->render;

    loadHoop->loadModel(lmSMData->component, lmSMData->flag, lmSMData->render);
    logMsg(func +" end");
//    exit(0);
}
// Creates the hoop node
STATE_DEFINE(hoopStateMachine, CreateNode, hoopSMData)
{

    conversionSharedPtr convert;
    OgreEntitySharedPtr activeModel;
    OgreSceneNodeSharedPtr activeNode;
    std::string activeEntityName;
    std::string activeNodeNum;
    std::string activeNodeName;
    std::string func = "hoopStateMachine::CreateNode()";

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
//    exit(0);
}
// sets up basketball physics object
STATE_DEFINE(hoopStateMachine, SetupPhysics, hoopSMData)
{
#ifdef BTOGRE_MYGUI_ENABLED

    conversionSharedPtr convert;
    std::string func = "hoopStateMachine::setupPhysics()";
    OgreEntitySharedPtr tempModel = data->model;
    OgreSceneNodeSharedPtr tempNode = data->node;
    hoopComponentsSharedPtr component = data->component;
    hoopFlagsSharedPtr flag = data->flag;

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
    component->getPhysics()->setCollidesWith(COL_HOOP);
    logMsg(func +" setCollidesWith!");

    if (component->getPhysics()->setupPhysics(&tempModel, &tempNode, &tempPhysBody))
    {
        
        logMsg(func +" setupPhysics!");
        flag->setPhysicsSetup(true);

        logMsg(func +" modelName == " +tempModel->getName());
        logMsg(func +" nodeName == " +tempNode->getName());

//        exit(0);

        component->getPhysics()->setPhysBody(btRigidBodySharedPtr(tempPhysBody));

        hoopSMData *tempSMData(new hoopSMData);
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
#endif

}

// stops movement of basketball object
STATE_DEFINE(hoopStateMachine, StopMovement, noEventData)
{
    
}

// state machine sits here when motor is not running
STATE_DEFINE(hoopStateMachine, Idle, noEventData)
{
    logMsg("Motor::ST_Idle");
}

// updates position of basketball objects
STATE_DEFINE(hoopStateMachine, UpdatePosition, hoopSMData)
{
/*    conversionSharedPtr convert;
    comparison compare;
    Ogre::Vector3 changePos;
    btVector3 physChange = btVector3(0,0,0);
    basketballComponentsSharedPtr component = data->component;
//    basketballDataSharedPtr bData;  // stores copy of basketballData object
    basketballFlagsSharedPtr flag = data->flag;
    basketballPhysicsSharedPtr physics = data->physics;
    OgreSceneNodeSharedPtr node = data->node;
    std::string func = "hoopStateMachine::updatePosition()";

    
    logMsg(func + " beginning");
    if (flag->gethoopPositionChanged())
    {
        //exit(0);
        switch (component->gethoopPositionChangedType())
        {
            case STARTCHANGE:
                logMsg(func + " Updating basketball hoop position based on start position");
                
                node->translate(component->getNewhoopPosition());
                physChange = BtOgre::Convert::toBullet(component->getNewhoopPosition()); // converts from Ogre::Vector3 to btVector3
                component->getPhysics()->getPhysBody()->translate(physChange); // moves physics body in unison with the model
                component->getSteer()->setPosition(convert->toOpenSteerVec3(component->getNewhoopPosition()));
                flag->sethoopPositionChanged(false);
                component->sethoopPositionChangedType(NOCHANGE);
            break;
            
            case STEERCHANGE:
                logMsg(func + " Updating basketball hoop position based on steering");
                //logMsg("Team " +convert->toString(teamNumber) + " Player " +convert->toString(playerID));
                changePos = compare.OgreVector3ToOgreVector3Result(component->gethoopPosition(), component->getNewhoopPosition());
                node->translate(changePos);
                physChange = BtOgre::Convert::toBullet(changePos); // converts from Ogre::Vector3 to btVector3
                component->getPhysics()->getPhysBody()->translate(physChange); // moves physics body in unison with the model
               
                flag->sethoopPositionChanged(false);
                component->sethoopPositionChangedType(NOCHANGE);
            break;   

            case INPUTCHANGE:
                logMsg(func + " Updating hoop position based on input");
                node->translate(component->getNewhoopPosition());
                physChange = BtOgre::Convert::toBullet(component->getNewhoopPosition()); // converts from Ogre::Vector3 to btVector3
                component->getPhysics()->getPhysBody()->translate(physChange); // moves physics body in unison with the model
                component->getSteer()->setPosition(convert->toOpenSteerVec3(component->getNewhoopPosition()));
                flag->sethoopPositionChanged(false);
                component->sethoopPositionChangedType(NOCHANGE);
                //exit(0);
            break;

            case PHYSICSCHANGE:
                logMsg(func + " Updating basketball hoop position based on physics");
                //exit(0);
            break;
            case PLAYERMOVECHANGE:
                logMsg(func + " Updating basketball hoop position based on player movement");
                node->translate(component->getNewhoopPosition());
                logMsg(func + " bball newhoopPosition = " +convert->toString(component->getNewhoopPosition()));
                logMsg(func + " bball node position" +convert->toString((node->getPosition())));
                //exit(0);
                physChange = BtOgre::Convert::toBullet(component->getNewhoopPosition()); // converts from Ogre::Vector3 to btVector3
                component->getPhysics()->getPhysBody()->translate(physChange); // moves physics body in unison with the model
                //steer->setPosition(convert->toOpenSteerVec3(component->getNewhoopPosition()));
                flag->sethoopPositionChanged(false);
                component->sethoopPositionChangedType(NOCHANGE);
//                exit(0);
            break;
            case PLAYERDIRECTCHANGE:
                logMsg(func + " Updating basketball hoop position based on player movement");
                node->translate(component->getNewhoopPosition());
                logMsg(func + " bball newhoopPosition = " +convert->toString(component->getNewhoopPosition()));
                logMsg(func + " bball node position" +convert->toString((node->getPosition())));
                //exit(0);
                physChange = BtOgre::Convert::toBullet(component->getNewhoopPosition()); // converts from Ogre::Vector3 to btVector3
                component->getPhysics()->getPhysBody()->translate(physChange); // moves physics body in unison with the model
                //steer->setPosition(convert->toOpenSteerVec3(component->getNewhoopPosition()));
                flag->sethoopPositionChanged(false);
                component->sethoopPositionChangedType(NOCHANGE);
            break;
            default:
            break;
        }
        component->sethoopPosition(node->getPosition());
        logMsg("basketball position = " +convert->toString(component->gethoopPosition()));
    }
    
    logMsg("basketball position = " +convert->toString(component->gethoopPosition()));


    data->component = component;
    data->flag = flag;
    data->node = node;
    
    logMsg(func + " end");
    */
}

// updates movement of basketball objects
STATE_DEFINE(hoopStateMachine, UpdateMovement, hoopSMData)
{
    
/*    conversionSharedPtr convert;
    teamEntityMSharedPtr activeTeamInstance = data->gComponent->getActiveTeamInstance();
    size_t teamWithBall = data->gData->getTeamWithBall();

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
    std::string func = "hoopStateMachine:Machine:updateMovement()";

    logMsg(func + " beginning");

    if (component->gethoopPosition().x == 0 && component->gethoopPosition().y == 0 && component->gethoopPosition().z == 0)
    {
        bballCurrentPos = node->getPosition();
    }
    else
    {
        bballCurrentPos = component->gethoopPosition();
    }
//TS    playerPos = activePlayerInstance[playerWithBallInstance]->gethoopPosition();  // stores the current position of player with ball
    //bballPos = bballCurrentPos;
    bballPos = Ogre::Vector3(0,0,0);
    logMsg(func + " bballHere???");
    switch (component->getDirection())
    {
        case UP:
            bballPos.x += 0;
            bballPos.y += 0; // maintains the current height of the basketball on the hoop as the player and ball moves
            bballPos.z -= 0.200;
        break;
        case DOWN:
            bballPos.x += 0;
            bballPos.y += 0; // maintains the current height of the basketball on the hoop as the player and ball moves
            bballPos.z += 0.200;
        break;
        case LEFT:
            bballPos.x -= 0.200;
            bballPos.y = 0;
            bballPos.z = 0;
        break;
        case RIGHT:
            bballPos.x += 0.200;
            bballPos.y += 0; // maintains the current height of the basketball on the hoop as the player and ball moves
            bballPos.z += 0;
        break;
        default:
        break;
    }

    logMsg(func + " bballPos == " +convert->toString(bballPos));
    logMsg(func + " cbballPos == " +convert->toString(bballCurrentPos));
//TS        logMsg("pbballPos == " +convert->toString(activePlayerInstance[x]->gethoopPosition()));
    logMsg(func + " new bball hoop Position == " +convert->toString(bballPos));
    component->setNewhoopPosition(bballPos);
    flag->sethoopPositionChanged(true);
    component->sethoopPositionChangedType(PLAYERMOVECHANGE);
        //basketballInstance[activeBBallInstance].setMovement(false);
        //basketballInstance[activeBBallInstance] = bballInstance;

    data->component = component;
    data->flag = flag;

    logMsg(func + " end");
    */
}

// updates direction of basketball objects
STATE_DEFINE(hoopStateMachine, UpdateDirection, hoopSMData)
{
/*    conversionSharedPtr convert;
    
    gameComponentsSharedPtr gameComponent = data->gComponent;
    gameDataSharedPtr gameData = data->gData;
    gameFlagsSharedPtr gameFlag = data->gFlag;
    
//    sharedPtr<gameState> gameS = gameState::Instance();
    teamEntityMSharedPtr activeTeamInstance = gameComponent->getActiveTeamInstance();
    size_t teamWithBall = gameData->getTeamWithBall();

    jumpBallsSharedPtr jumpBall = gameComponent->getJumpBall();

//TS    logMsg("directplayerwithballInstance == " +convert->toString(playerWithBallInstance));
    bool tipOffComplete = gameFlag->getTipOffComplete();
    size_t x = 0;
    std::string func = "hoopStateMachine::updateDirection()";

    logMsg(func + " beginning");


    gameComponent->setJumpBall(jumpBall);
    
    data->gComponent = gameComponent;
    data->gData = gameData;
    data->gFlag = gameFlag;
    
    logMsg(func + " end");
*/
}
