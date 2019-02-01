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
#include "statemachine/courtstatemachine.h"
#include "components/courtcomponents.h"
//#include "components/gamecomponents.h"
#include "data/courtdata.h"
//#include "data/gamedata.h"
#include "flags/courtflags.h"
//#include "flags/gameflags.h"
#include "physics/courtphysics.h"
#include "utilities/comparison.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

courtStateMachine::courtStateMachine() :
    stateMachine(ST_MAX_STATES),
    m_currentSpeed(0)
{
}    

// Initialize state machine external event
void courtStateMachine::pInitialize(const courtSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_INITIALIZE       
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_INITIALIZE_COMPONENTS
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(data)
}

// set motor speed external event
void courtStateMachine::pInitializeComponents(courtSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_INITIALIZE_COMPONENTS)     // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_INITIALIZE_COMPONENTS)     // ST_INITIALIZE_COMPONENTS
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_INITIALIZE_COMPONENTS)              // ST_IDLE
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(data)
}

// halt motor external event
void courtStateMachine::halt()
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_INITIALIZE_COMPONENTS
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_IDLE
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(nullptr)
}

// Update positions external event
void courtStateMachine::pUpdatePosition(courtSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                     // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_INITIALIZE_COMPONENTS
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(data)
}

// Update movement external event
void courtStateMachine::pUpdateMovement(courtSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                     // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_INITIALIZE_COMPONENTS
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(data)
}

// Update direction external event
void courtStateMachine::pUpdateDirection(courtSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                      // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_INITIALIZE_COMPONENTS
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_SETUP_PHYSICS
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_UPDATE_MOVEMENT
        TRANSITION_MAP_ENTRY (ST_UPDATE_DIRECTION)                // ST_UPDATE_DIRECTION
    END_TRANSITION_MAP(data)
}

// Initialize the state machine
STATE_DEFINE(courtStateMachine, Initialize, courtSMData)
{
    std::string func = "courtStateMachine::Initialize()";

    logMsg(func +" begin");

    courtSMData *tempSMData(new courtSMData);

    courtComponentsSharedPtr tempComponent(new courtComponents);
    tempSMData->component = tempComponent;

    courtDataSharedPtr tempData(new courtData);
    tempSMData->cData = tempData;

    courtFlagsSharedPtr tempFlag(new courtFlags);
    tempSMData->flag = tempFlag;

    data = tempSMData;
    
    sharedPtr<courtPhysics> tempPhysics(new courtPhysics);
    data->component->setPhysics(tempPhysics);

    logMsg(func +" end");
    
//    internalEvent(ST_INITIALIZE_COMPONENTS);
}

// Initialize the component objects
STATE_DEFINE(courtStateMachine, InitializeComponents, courtSMData)
{
    
    conversionSharedPtr convert;
    std::string func = "courtStateMachine::InitializeComponents()";

    logMsg(func +" begin");

/*    courtDataSharedPtr tempData(new courtData);
    data->cData = tempData;

    courtComponentsSharedPtr tempComponent(new courtComponents);
    data->component = tempComponent;

    courtFlagsSharedPtr tempFlag(new courtFlags);
    data->flag = tempFlag;
*/


        logMsg(func +" end");

}

// sets up basketball physics object
STATE_DEFINE(courtStateMachine, SetupPhysics, courtSMData)
{
    conversionSharedPtr convert;
    std::string func = "courtStateMachine::setupPhysics()";
    OgreEntitySharedPtr tempModel = data->model;
    OgreSceneNodeSharedPtr tempNode = data->node;
    courtComponentsSharedPtr component = data->component;
    courtFlagsSharedPtr flag = data->flag;
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

        courtSMData *tempSMData(new courtSMData);
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
STATE_DEFINE(courtStateMachine, StopMovement, noEventData)
{
    
}

// state machine sits here when motor is not running
STATE_DEFINE(courtStateMachine, Idle, noEventData)
{
    logMsg("Motor::ST_Idle");
}

// updates position of basketball objects
STATE_DEFINE(courtStateMachine, UpdatePosition, courtSMData)
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
    std::string func = "courtStateMachine::updatePosition()";

    
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


    data->component = component;
    data->flag = flag;
    data->node = node;
    
    logMsg(func + " end");
    */
}

// updates movement of basketball objects
STATE_DEFINE(courtStateMachine, UpdateMovement, courtSMData)
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
    std::string func = "courtStateMachine:Machine:updateMovement()";

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

    data->component = component;
    data->flag = flag;

    logMsg(func + " end");
    */
}

// updates direction of basketball objects
STATE_DEFINE(courtStateMachine, UpdateDirection, courtSMData)
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
    std::string func = "courtStateMachine::updateDirection()";

    logMsg(func + " beginning");


    gameComponent->setJumpBall(jumpBall);
    
    data->gComponent = gameComponent;
    data->gData = gameData;
    data->gFlag = gameFlag;
    
    logMsg(func + " end");
*/
}
