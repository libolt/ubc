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
#include "statemachine/gamestatemachine.h"

#include "utilities/logging.h"

gameStateMachine::gameStateMachine() :
    stateMachine(ST_MAX_STATES)
/*    currentSpeed(0),
    currentDirection(NODIRECT),
    currentAction(NOACTION)
*/
//    currentPosition(Ogre::Vector3(0,0,0)
    
{
}

void gameStateMachine::pCreateInstances(gameSMData *data) // sets the node to that of the entity parent object
{
    std:: string func = "gameStateMachine::setPNode";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_CREATE_INSTANCES)             // ST_SET_NODE
        TRANSITION_MAP_ENTRY (ST_CREATE_INSTANCES)             // ST_SET_MODEL
        TRANSITION_MAP_ENTRY (ST_CREATE_INSTANCES)             // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_CREATE_INSTANCES)             // ST_STOP
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_START
        TRANSITION_MAP_ENTRY (ST_CREATE_INSTANCES)             // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_JUMP
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SHOOT
//        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_PASS
    END_TRANSITION_MAP(NULL)

    logMsg(func +" end");
//    exit(0);

}

void gameStateMachine::pSetStartPositions(gameSMData *data) // sets the model to that of the entity parent object
{
    std:: string func = "gameStateMachine::setPModel";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_SET_START_POS)             // ST_SET_NODE
        TRANSITION_MAP_ENTRY (ST_SET_START_POS)             // ST_SET_MODEL
        TRANSITION_MAP_ENTRY (ST_SET_START_POS)             // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_SET_START_POS)             // ST_STOP
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_START
        TRANSITION_MAP_ENTRY (ST_SET_START_POS)             // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_JUMP
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SHOOT
//        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_PASS
    END_TRANSITION_MAP(NULL)

    logMsg(func +" end");
//    exit(0);

}
// set player speed external event
void gameStateMachine::pSetupTipOff(gameSMData *data)
{
    std:: string func = "gameStateMachine::setSpeed";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_SETUP_TIPOFF)            // ST_SET_NODE
        TRANSITION_MAP_ENTRY (ST_SETUP_TIPOFF)             // ST_SET_MODEL
        TRANSITION_MAP_ENTRY (ST_SETUP_TIPOFF)            // ST_IDLE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_STOP
        TRANSITION_MAP_ENTRY (ST_SETUP_TIPOFF)              // ST_START
        TRANSITION_MAP_ENTRY (ST_SETUP_TIPOFF)              // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_JUMP
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SHOOT
//        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_PASS
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);
}

// halt player external event
void gameStateMachine::pExecuteTipOff(gameSMData *data)
{
    std:: string func = "gameStateMachine::halt";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_EXECUTE_TIPOFF)             // ST_SET_NODE
        TRANSITION_MAP_ENTRY (ST_EXECUTE_TIPOFF)             // ST_SET_MODEL
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_IDLE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_STOP
        TRANSITION_MAP_ENTRY (ST_EXECUTE_TIPOFF)             // ST_START
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_EXECUTE_TIPOFF)             // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_JUMP
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_SHOOT
//        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_PASS
    END_TRANSITION_MAP(data)

    logMsg(func +" end");

}
    
// jump player external event
void gameStateMachine::pPause()
{
    std:: string func = "gameStateMachine::pJump";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_PAUSE)                      // ST_SET_NODE
        TRANSITION_MAP_ENTRY (ST_PAUSE)                      // ST_SET_MODEL
        TRANSITION_MAP_ENTRY (ST_PAUSE)                      // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_PAUSE)                      // ST_STOP
        TRANSITION_MAP_ENTRY (ST_PAUSE)                      // ST_START
        TRANSITION_MAP_ENTRY (ST_PAUSE)                      // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_PAUSE)                      // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_JUMP
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SHOOT
//        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_PASS
    END_TRANSITION_MAP(NULL)
    logMsg(func +" end");
//    exit(0);
}
   
// change direction player external event
void gameStateMachine::pChangeScore(gameSMData *data)
{
    std:: string func = "gameStateMachine::pChangeDirection";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_CHANGE_SCORE)          // ST_SET_NODE
        TRANSITION_MAP_ENTRY (ST_CHANGE_SCORE)          // ST_SET_MODEL
        TRANSITION_MAP_ENTRY (ST_CHANGE_SCORE)          // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_CHANGE_SCORE)          // ST_STOP
        TRANSITION_MAP_ENTRY (ST_CHANGE_SCORE)          // ST_START
        TRANSITION_MAP_ENTRY (ST_CHANGE_SCORE)          // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_CHANGE_SCORE)          // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_CHANGE_SCORE)          // ST_JUMP
        TRANSITION_MAP_ENTRY (ST_CHANGE_SCORE)          // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (ST_CHANGE_SCORE)          // ST_SHOOT
//        TRANSITION_MAP_ENTRY (ST_CHANGE_SCORE)          // ST_PASS
    END_TRANSITION_MAP(data)

    logMsg(func +" end");

            //    exit(0);
}
    
// change  player position external event
void gameStateMachine::pChangeQuarter(gameSMData *data)
{
    std:: string func = "gameStateMachine::pChangePosition";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_CHANGE_QUARTER)           // ST_SET_NODE
        TRANSITION_MAP_ENTRY (ST_CHANGE_QUARTER)           // ST_SET_MODEL
        TRANSITION_MAP_ENTRY (ST_CHANGE_QUARTER)           // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_CHANGE_QUARTER)           // ST_STOP
        TRANSITION_MAP_ENTRY (ST_CHANGE_QUARTER)           // ST_START
        TRANSITION_MAP_ENTRY (ST_CHANGE_QUARTER)           // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_CHANGE_QUARTER)           // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_CHANGE_QUARTER)           // ST_JUMP
        TRANSITION_MAP_ENTRY (ST_CHANGE_QUARTER)           // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (ST_CHANGE_QUARTER)           // ST_SHOOT
//        TRANSITION_MAP_ENTRY (ST_CHANGE_QUARTER)           // ST_PASS
    END_TRANSITION_MAP(data)
    logMsg(func +" end");
//    exit(0);
}

// change  player position external event
void gameStateMachine::pSetupFreethrow(gameSMData *data)
{
    std:: string func = "gameStateMachine::pChangePosition";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_SETUP_FREETHROW)           // ST_SET_NODE
        TRANSITION_MAP_ENTRY (ST_SETUP_FREETHROW)           // ST_SET_MODEL
        TRANSITION_MAP_ENTRY (ST_SETUP_FREETHROW)           // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_SETUP_FREETHROW)           // ST_STOP
        TRANSITION_MAP_ENTRY (ST_SETUP_FREETHROW)           // ST_START
        TRANSITION_MAP_ENTRY (ST_SETUP_FREETHROW)           // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_SETUP_FREETHROW)           // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_SETUP_FREETHROW)           // ST_JUMP
        TRANSITION_MAP_ENTRY (ST_SETUP_FREETHROW)           // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (ST_SETUP_FREETHROW)           // ST_SHOOT
//        TRANSITION_MAP_ENTRY (ST_SETUP_FREETHROW)           // ST_PASS
    END_TRANSITION_MAP(data)
    logMsg(func +" end");
//    exit(0);
}

// change  player position external event
void gameStateMachine::pExecuteFreethrow(gameSMData *data)
{
    std:: string func = "gameStateMachine::pChangePosition";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_EXECUTE_FREETHROW)           // ST_SET_NODE
        TRANSITION_MAP_ENTRY (ST_EXECUTE_FREETHROW)           // ST_SET_MODEL
        TRANSITION_MAP_ENTRY (ST_EXECUTE_FREETHROW)           // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_EXECUTE_FREETHROW)           // ST_STOP
        TRANSITION_MAP_ENTRY (ST_EXECUTE_FREETHROW)           // ST_START
        TRANSITION_MAP_ENTRY (ST_EXECUTE_FREETHROW)           // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_EXECUTE_FREETHROW)           // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_EXECUTE_FREETHROW)           // ST_JUMP
        TRANSITION_MAP_ENTRY (ST_EXECUTE_FREETHROW)           // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (ST_EXECUTE_FREETHROW)           // ST_SHOOT
//        TRANSITION_MAP_ENTRY (ST_EXECUTE_FREETHROW)           // ST_PASS
    END_TRANSITION_MAP(data)
    logMsg(func +" end");
//    exit(0);
}

// change  player position external event
void gameStateMachine::pChangePossession(gameSMData *data)
{
    std:: string func = "gameStateMachine::pChangePosition";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSSESSION)           // ST_SET_NODE
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSSESSION)           // ST_SET_MODEL
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSSESSION)           // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSSESSION)           // ST_STOP
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSSESSION)           // ST_START
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSSESSION)           // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSSESSION)           // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSSESSION)           // ST_JUMP
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSSESSION)           // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSSESSION)           // ST_SHOOT
//        TRANSITION_MAP_ENTRY (ST_CHANGE_POSSESSION)           // ST_PASS
    END_TRANSITION_MAP(NULL)
    logMsg(func +" end");
//    exit(0);
}

// sets the node object
STATE_DEFINE(gameStateMachine, createInstances, gameSMData)
{
    std:: string func = "gameStateMachine::SetNode";

    logMsg(func +" begin");

//    currentNode = data->node;

    logMsg(func +" end");

}

// sets the model object
STATE_DEFINE(gameStateMachine, setStartPositions, gameSMData)
{
    std:: string func = "gameStateMachine::SetModel";

    logMsg(func +" begin");

//    currentModel = data->model;

    logMsg(func +" end");

}

// state machine sits here when player is not moving
STATE_DEFINE(gameStateMachine, setupTipOff, gameSMData)
{
    std:: string func = "gameStateMachine::Idle";

    logMsg(func +" begin");

    logMsg("gameStateMachine::ST_Idle");
    logMsg(func +" end");

//    exit(0);
}

// stop the player
STATE_DEFINE(gameStateMachine, executeTipOff, gameSMData)
{
    std:: string func = "gameStateMachine::StopMovement";

    logMsg(func +" begin");

    logMsg("gameStateMachine::ST_Stop");
//    currentSpeed = 0; 
//    currentDirection = NODIRECT;

    // perform the stop motor processing here
    // transition to Idle via an internal event
///    internalEvent(ST_IDLE);
//    exit(0);
    logMsg(func +" end");

}

// start the player moving
STATE_DEFINE(gameStateMachine, pause, noEventData)
{
    conversionSharedPtr convert = conversion::Instance();
    std:: string func = "gameStateMachine::StartMovement";

    logMsg(func +" begin");

//    logMsg("gameStateMachine::ST_Start : Speed is " +convert->toString(data->speed));
//    currentSpeed = data->speed;
//    exit(0);
    // set initial player speed processing here
    logMsg(func +" end");

}

// changes the player's position on the court
STATE_DEFINE(gameStateMachine, changeScore, gameSMData)
{
//    exit(0);
    conversionSharedPtr convert = conversion::Instance();
    std:: string func = "gameStateMachine::ChangePosition";

    logMsg(func +" begin");

    logMsg("gameStateMachine::ST_ChangePosition : court position is " +convert->toString(data->position));
//    currentPosition = data->position;
//    currentNode->setPosition(currentPosition);
//    logMsg(func +" Node Position == " +convert->toString(currentNode->getPosition()));
    logMsg(func +" end");

//    exit(0);
}
// changes the player's speed once the player is moving
STATE_DEFINE(gameStateMachine, changeQuarter, gameSMData)
{
//    exit(0);
    conversionSharedPtr convert = conversion::Instance();
    std:: string func = "gameStateMachine::ChangeSpeed";

    logMsg(func +" begin");

    logMsg("gameStateMachine::ST_ChangeSpeed : Speed is " +convert->toString(data->speed));
//    currentSpeed = data->speed;

    logMsg(func +" end");

    //    exit(0);
    // perform the change player speed to data->speed here
}

// changes the player's direction once the player is moving
STATE_DEFINE(gameStateMachine, setupFreethrow, gameSMData)
{
    conversionSharedPtr convert = conversion::Instance();
    std:: string func = "gameStateMachine::ChangeDirection";

    logMsg(func +" begin");

//    exit(0);
    logMsg("gameStateMachine::ST_ChangeDirection : Direction is " +convert->toString(data->direction));

/*    switch (currentDirection)
    {
        case UP:
            switch (data->direction)
            {
                case DOWN:
                    currentNode->yaw(Ogre::Degree (180));
                break;
                case LEFT:
                    currentNode->yaw(Ogre::Degree (270));
                break;
                case RIGHT:
                    currentNode->yaw(Ogre::Degree (90));
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
                    currentNode->yaw(Ogre::Degree (180));
                break;
                case LEFT:
                    currentNode->yaw(Ogre::Degree (90));
                break;
                case RIGHT:
                    currentNode->yaw(Ogre::Degree (270));
                break;
                default:
                break;
            }
        break;
        case LEFT:
            switch (data->direction)
            {
                case UP:
                    currentNode->yaw(Ogre::Degree (90));
                break;
                case DOWN:
                    currentNode->yaw(Ogre::Degree (270));
                break;
                case RIGHT:
                    currentNode->yaw(Ogre::Degree (180));
                break;
                default:
                break;
            }
        break;
        case RIGHT:
            switch (data->direction)
            {
                case UP:
                    currentNode->yaw(Ogre::Degree (270));
                break;
                case DOWN:
                    currentNode->yaw(Ogre::Degree (90));
                break;
                case LEFT:
                    currentNode->yaw(Ogre::Degree (180));
                break;
                default:
                break;
            }
        break;
        case NODIRECT:
            switch (data->direction)
            {
                case UP:
                    currentNode->yaw(Ogre::Degree (270));
                break;
                case DOWN:
                    currentNode->yaw(Ogre::Degree (90));
                break;
                case LEFT:
                    currentNode->yaw(Ogre::Degree (0));
                break;
                case RIGHT:
                    currentNode->yaw(Ogre::Degree (180));
                break;
                default:
                break;
            }
            break;
            default:
        break;
    }*/
    logMsg(func +" end");

//    currentSpeed = data->direction;
//    exit(0);
    // perform the change player direction to data->direction here
}

STATE_DEFINE(gameStateMachine, executeFreethrow, gameSMData)
{
    std:: string func = "gameStateMachine::Jump";
//    exit(0)

    logMsg(func +" begin");

    logMsg("jump");
    logMsg("flee");
    conversionSharedPtr convert = conversion::Instance();
    
    logMsg("gameStateMachine::ST_Jump : Speed is " +convert->toString(data->speed));
///    internalEvent(ST_IDLE);

    logMsg(func +" end");

//    currentSpeed = data->speed;
//    exit(0);
    // set initial player speed processing here
}

STATE_DEFINE(gameStateMachine, changePosession, gameSMData)
{
    conversionSharedPtr convert = conversion::Instance();
    std:: string func = "gameStateMachine::Shoot";

    logMsg(func +" begin");

    logMsg("gameStateMachine::ST_Shoot : Speed is " +convert->toString(data->speed));
//    currentSpeed = data->speed;

    logMsg(func +" end");

//    exit(0);

    // set initial player shoot processing here
}

/*STATE_DEFINE(gameStateMachine, Pass, gameSMData)
{
    conversionSharedPtr convert = conversion::Instance();
    std:: string func = "gameStateMachine::Pass";


    logMsg(func +" begin");

    logMsg("gameStateMachine::ST_Pass : Speed is " +convert->toString(data->speed));
//    currentSpeed = data->speed;

    logMsg(func +" end");

//    exit(0);
    // set initial player pass processing here
}*/
