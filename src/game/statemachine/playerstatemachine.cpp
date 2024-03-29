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

#include "utilities/conversion.h"
#include "statemachine/playerstatemachine.h"
#include "components/playercomponents.h"
#include "data/playerdata.h"
#include "engine/renderengine.h"
#include "flags/playerflags.h"
#include "load/loadplayers.h"
#include "utilities/logging.h"

playerStateMachine::playerStateMachine() :
    StateMachine(ST_MAX_STATES),
    currentSpeed(0),
    currentDirection(NODIRECT),
    currentAction(PNOACTION)
//    currentPosition(Ogre::Vector3(0,0,0)
    
{
}

void playerStateMachine::pLoadModel(playerSMData *data) // Loads the model object
{
    std:: string func = "playerStateMachine::pLoadModel";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_LOAD_MODEL)             // ST_LOAD_MODEL
        TRANSITION_MAP_ENTRY (ST_LOAD_MODEL)             // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (ST_LOAD_MODEL)             // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_LOAD_MODEL)             // ST_STOP
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_START
        TRANSITION_MAP_ENTRY (ST_LOAD_MODEL)             // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_JUMP
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SHOOT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_PASS
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);

}

void playerStateMachine::pCreateNode(playerSMData *data) // sets the model to that of the entity parent object
{
    std:: string func = "playerStateMachine::setPModel";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_CREATE_NODE)             // ST_LOAD_MODEL
        TRANSITION_MAP_ENTRY (ST_CREATE_NODE)             // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (ST_CREATE_NODE)             // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_CREATE_NODE)             // ST_STOP
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_START
        TRANSITION_MAP_ENTRY (ST_CREATE_NODE)             // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_JUMP
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SHOOT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_PASS
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);

}
// set player speed external event
void playerStateMachine::setSpeed(playerSMData *data)
{
    std:: string func = "playerStateMachine::setSpeed";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_START_MOVEMENT)            // ST_LOAD_MODEL
        TRANSITION_MAP_ENTRY (ST_START_MOVEMENT)             // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (ST_START_MOVEMENT)            // ST_IDLE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_STOP
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)              // ST_START
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)              // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_JUMP
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SHOOT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_PASS
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);
}

// halt player external event
void playerStateMachine::halt()
{
    std:: string func = "playerStateMachine::halt";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_LOAD_MODEL
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_IDLE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_STOP
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_START
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_JUMP
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_SHOOT
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_PASS
    END_TRANSITION_MAP(nullptr)

    logMsg(func +" end");

}
    
// jump player external event
void playerStateMachine::pJump(playerSMData *data)
{
    std:: string func = "playerStateMachine::pJump";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_JUMP)                      // ST_LOAD_MODEL
        TRANSITION_MAP_ENTRY (ST_JUMP)                      // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (ST_JUMP)                      // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_JUMP)                      // ST_STOP
        TRANSITION_MAP_ENTRY (ST_JUMP)                      // ST_START
        TRANSITION_MAP_ENTRY (ST_JUMP)                      // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_JUMP)                      // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_JUMP
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SHOOT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_PASS
    END_TRANSITION_MAP(data)
    logMsg(func +" end");
//    exit(0);
}
   
// change direction player external event
void playerStateMachine::pChangeDirection(playerSMData *data)
{
    std:: string func = "playerStateMachine::pChangeDirection";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)          // ST_LOAD_MODEL
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_STOP
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_START
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_JUMP
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)          // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_SHOOT
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_PASS
    END_TRANSITION_MAP(data)

    logMsg(func +" end");

            //    exit(0);
}
    
// change  player position external event
void playerStateMachine::pChangePosition(playerSMData *data)
{
    std:: string func = "playerStateMachine::pChangePosition";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_LOAD_MODEL
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_CREATE_NODE
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_STOP
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_START
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_JUMP
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_SHOOT
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_PASS
    END_TRANSITION_MAP(data)
    logMsg(func +" end");
    
}

// sets the node object
STATE_DEFINE(playerStateMachine, LoadModel, playerSMData)
{
    conversionSharedPtr convert;
    loadPlayersSharedPtr loadPlayer(new loadPlayers);
    playerSMData *lmSMData(new playerSMData);
    std:: string func = "playerStateMachine::LoadModel";

    logMsg(func +" begin");

    lmSMData->component = data->component;
    lmSMData->flag = data->flag;
    lmSMData->render = data->render;

    loadPlayer->loadModel(lmSMData->component, lmSMData->flag, lmSMData->render);
    logMsg(func +" flag->getModelLoaded() == " +convert->toString(lmSMData->flag->getModelLoaded()));
//    exit(0);
    logMsg(func +" end");
}

// sets the model object
STATE_DEFINE(playerStateMachine, CreateNode, playerSMData)
{
    conversionSharedPtr convert;
    Ogre::v1::Entity *activeModel;
    Ogre::SceneNode *tempNode;
    std::string activeEntityName;
    std::string activeNodeNum;
    std::string activeNodeName;
    std:: string func = "playerStateMachine::CreateNode";

    logMsg(func +" begin");
    logMsg(func +" nodeName == " +data->component->getNodeName());
    if (data->component->getNodeName().empty())
    {
        std::string nodeName = data->component->getName() + convert->toString(data->pData->getID());
        data->component->setNodeName(nodeName);
        logMsg(func +" nodeName == " +data->component->getNodeName());
    }
    else
    {
        logMsg(func +" nodeName == " +data->component->getNodeName());
    }
    tempNode = data->render->createNode(data->component->getModel(), data->component->getNodeName());
    logMsg(func +" tempNode!");
//            exit(0);
    if (tempNode != nullptr)
    {
        logMsg(func + " Node created successfully!");
        data->component->setNode(tempNode);
        data->flag->setNodeCreated(true);
    }
    else
    {
        logMsg(func + " Unable to create node!");
        exit(0);
    }

    logMsg(func +" end");

}

// state machine sits here when player is not moving
STATE_DEFINE(playerStateMachine, Idle, NoEventData)
{
    std:: string func = "playerStateMachine::Idle";

    logMsg(func +" begin");

    logMsg("playerStateMachine::ST_Idle");
    logMsg(func +" end");

//    exit(0);
}

// stop the player
STATE_DEFINE(playerStateMachine, StopMovement, NoEventData)
{
    std:: string func = "playerStateMachine::StopMovement";

    logMsg(func +" begin");

    logMsg("playerStateMachine::ST_Stop");
    currentSpeed = 0; 
    currentDirection = NODIRECT;

    // perform the stop motor processing here
    // transition to Idle via an internal event
    InternalEvent(ST_IDLE);
//    exit(0);
    logMsg(func +" end");

}

// start the player moving
STATE_DEFINE(playerStateMachine, StartMovement, playerSMData)
{
    conversionSharedPtr convert ;
    std:: string func = "playerStateMachine::StartMovement";

    logMsg(func +" begin");

    logMsg("playerStateMachine::ST_Start : Speed is " +convert->toString(data->speed));
    currentSpeed = data->speed;
//    exit(0);
    // set initial player speed processing here
    logMsg(func +" end");

}

// changes the player's position on the court
STATE_DEFINE(playerStateMachine, ChangePosition, playerSMData)
{
//    exit(0);
    conversionSharedPtr convert;
    Ogre::SceneNode *node = data->component->getNode();
    std:: string func = "playerStateMachine::ChangePosition";

    logMsg(func +" begin");
//    exit(0);
    logMsg(func +" court position is " +convert->toString(data->position));
    
    currentPosition = data->position;
    
//    logMsg(func +" Node Position == " +convert->toString(data->node->getPosition()));
//    exit(0);
    node->setPosition(currentPosition);
    data->component->setNode(node);
    logMsg(func +" Node Position == " +convert->toString(data->component->getNode()->getPosition()));
    logMsg(func +" end");

//    exit(0);
}
// changes the player's speed once the player is moving
STATE_DEFINE(playerStateMachine, ChangeSpeed, playerSMData)
{
//    exit(0);
    conversionSharedPtr convert ;
    std:: string func = "playerStateMachine::ChangeSpeed";

    logMsg(func +" begin");

    logMsg("playerStateMachine::ST_ChangeSpeed : Speed is " +convert->toString(data->speed));
    currentSpeed = data->speed;

    logMsg(func +" end");

    //    exit(0);
    // perform the change player speed to data->speed here
}

// changes the player's direction once the player is moving
STATE_DEFINE(playerStateMachine, ChangeDirection, playerSMData)
{
    conversionSharedPtr convert;
    Ogre::SceneNode *node = data->component->getNode();
    std:: string func = "playerStateMachine::ChangeDirection";

    logMsg(func +" begin");

//    exit(0);
    logMsg("playerStateMachine::ST_ChangeDirection : Direction is " +convert->toString(data->direction));

    switch (currentDirection)
    {
        case UP:
            switch (data->direction)
            {
                case DOWN:
                    node->yaw(Ogre::Degree (180));
                break;
                case LEFT:
                    node->yaw(Ogre::Degree (270));
                break;
                case RIGHT:
                    node->yaw(Ogre::Degree (90));
//                        exit(0);
                break;
                default:
                break;
            }
//                exit(0);
        break;
        case DOWN:
            switch (data->direction)
            {
                case UP:
                    node->yaw(Ogre::Degree (180));
                break;
                case LEFT:
                    node->yaw(Ogre::Degree (90));
                break;
                case RIGHT:
                    node->yaw(Ogre::Degree (270));
                break;
                default:
                break;
            }
        break;
        case LEFT:
            switch (data->direction)
            {
                case UP:
                    node->yaw(Ogre::Degree (90));
                break;
                case DOWN:
                    node->yaw(Ogre::Degree (270));
                break;
                case RIGHT:
                    node->yaw(Ogre::Degree (180));
                break;
                default:
                break;
            }
        break;
        case RIGHT:
            switch (data->direction)
            {
                case UP:
                    node->yaw(Ogre::Degree (270));
                break;
                case DOWN:
                    node->yaw(Ogre::Degree (90));
                break;
                case LEFT:
                    node->yaw(Ogre::Degree (180));
                break;
                default:
                break;
            }
        break;
        case NODIRECT:
            switch (data->direction)
            {
                case UP:
                    node->yaw(Ogre::Degree (270));
                break;
                case DOWN:
                    node->yaw(Ogre::Degree (90));
                break;
                case LEFT:
                    node->yaw(Ogre::Degree (0));
                break;
                case RIGHT:
                    node->yaw(Ogre::Degree (180));
                break;
                default:
                break;
            }
            break;
            default:
        break;
    }
    logMsg(func +" end");

//    currentSpeed = data->direction;
//    exit(0);
    // perform the change player direction to data->direction here
}

STATE_DEFINE(playerStateMachine, Jump, playerSMData)
{
    std:: string func = "playerStateMachine::Jump";
//    exit(0)

    logMsg(func +" begin");

    logMsg("jump");
    logMsg("flee");
    conversionSharedPtr convert ;
    
    logMsg("playerStateMachine::ST_Jump : Speed is " +convert->toString(data->speed));
    InternalEvent(ST_IDLE);

    logMsg(func +" end");

//    currentSpeed = data->speed;
//    exit(0);
    // set initial player speed processing here
}

STATE_DEFINE(playerStateMachine, Shoot, playerSMData)
{
    conversionSharedPtr convert ;
    std:: string func = "playerStateMachine::Shoot";

    logMsg(func +" begin");

    logMsg("playerStateMachine::ST_Shoot : Speed is " +convert->toString(data->speed));
    currentSpeed = data->speed;

    logMsg(func +" end");

//    exit(0);

    // set initial player shoot processing here
}

STATE_DEFINE(playerStateMachine, Pass, playerSMData)
{
    conversionSharedPtr convert ;
    std:: string func = "playerStateMachine::Pass";


    logMsg(func +" begin");

    logMsg("playerStateMachine::ST_Pass : Speed is " +convert->toString(data->speed));
    currentSpeed = data->speed;

    logMsg(func +" end");

//    exit(0);
    // set initial player pass processing here
}
