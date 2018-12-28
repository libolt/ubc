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

#include "ai/basketballsteer.h"
#include "statemachine/basketballstatemachine.h"
#include "components/basketballcomponents.h"
#include "components/gamecomponents.h"
#include "data/basketballdata.h"
#include "data/gamedata.h"
#include "flags/basketballflags.h"
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
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_STOP
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_START
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_UPDATE_MOVEMENT
    END_TRANSITION_MAP(nullptr)
}

// set motor speed external event
void basketballStateMachine::setSpeed(basketballSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_START_MOVEMENT)            // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_START_MOVEMENT)            // ST_IDLE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_STOP
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)              // ST_START
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)              // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_MOVEMENT
    END_TRANSITION_MAP(data)
}

// halt motor external event
void basketballStateMachine::halt()
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_IDLE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_STOP
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_START
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_UPDATE_MOVEMENT
    END_TRANSITION_MAP(nullptr)
}

// Update positions external event
void basketballStateMachine::pUpdatePosition(basketballSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_STOP
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_START
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (ST_UPDATE_POSITION)                // ST_UPDATE_MOVEMENT
    END_TRANSITION_MAP(nullptr)
}

// Update movement external event
void basketballStateMachine::pUpdateMovement(basketballSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_STOP
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_START
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_UPDATE_POSITION
        TRANSITION_MAP_ENTRY (ST_UPDATE_MOVEMENT)                // ST_UPDATE_MOVEMENT
    END_TRANSITION_MAP(nullptr)
}

// Initialize the state machine
STATE_DEFINE(basketballStateMachine, Initialize, basketballSMData)
{
    std::string func = "basketballStateMachine::Initialize()";

    logMsg(func +" begin");

    basketballDataSharedPtr tempData(new basketballData);
    data->bData = tempData;

    basketballComponentsSharedPtr tempComponent(new basketballComponents);
    data->component = tempComponent;

    basketballFlagsSharedPtr tempFlag(new basketballFlags);
    data->flag = tempFlag;

    sharedPtr<basketballPhysics> tempPhysics(new basketballPhysics);
    data->physics = tempPhysics;

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

// state machine sits here when motor is not running
STATE_DEFINE(basketballStateMachine, Idle, noEventData)
{
    logMsg("Motor::ST_Idle");
}

// stop the motor 
STATE_DEFINE(basketballStateMachine, StopMovement, noEventData)
{
    logMsg("Motor::ST_Stop");
    m_currentSpeed = 0; 

    // perform the stop motor processing here
    // transition to Idle via an internal event
    internalEvent(ST_IDLE);
}

// start the motor going
STATE_DEFINE(basketballStateMachine, StartMovement, basketballSMData)
{
    conversionSharedPtr convert;
//    logMsg("Motor::ST_Start : Speed is " +convert->toString(data->speed));
//    m_currentSpeed = data->speed;
exit(0);
    // set initial motor speed processing here
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

    data->component = component;
    data->flag = flag;
    data->node = node;
    
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

    data->component = component;
    data->flag = flag;

    logMsg(func + " end");
}
