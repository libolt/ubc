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
#include "components/gamecomponents.h"
#include "entity/basketballentity.h"
#include "entity/courtentity.h"
#include "entity/hoopentity.h"
#include "flags/gameflags.h"
#include "load/loadbasketballs.h"
#include "load/loadcourts.h"
#include "load/loadhoops.h"
#include "setup/setupbasketballs.h"
#include "setup/setupcourts.h"
#include "setup/setuphoops.h"
#include "setup/setupteams.h"
#include "state/basketballstate.h"
#include "state/courtstate.h"
#include "state/hoopstate.h"
#include "utilities/logging.h"

gameStateMachine::gameStateMachine() :
    stateMachine(ST_MAX_STATES),
    currentSpeed(0),
    currentDirection(NODIRECT),
    currentAction(NOACTION)
//    currentPosition(Ogre::Vector3(0,0,0)
    
{
}

void gameStateMachine::pCreateInstances(gameSMData *data) // creates the object instances
{
    std:: string func = "gameStateMachine::pCreateInstances";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_CREATE_INSTANCES)          // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_CREATE_INSTANCES)          // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_CREATE_INSTANCES)          // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (ST_CREATE_INSTANCES)          // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_CREATE_INSTANCES)          // ST_STOP
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_START
        TRANSITION_MAP_ENTRY (ST_CREATE_INSTANCES)          // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_JUMP
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SHOOT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_PASS
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);

}

void gameStateMachine::pLoadModels(gameSMData *data) // loads the object models
{
    std:: string func = "gameStateMachine::pLoadModels";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_LOAD_MODELS)               // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_LOAD_MODELS)               // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_LOAD_MODELS)               // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (ST_LOAD_MODELS)               // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_LOAD_MODELS)               // ST_STOP
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_START
        TRANSITION_MAP_ENTRY (ST_LOAD_MODELS)               // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_JUMP
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SHOOT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_PASS
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);

}
void gameStateMachine::pSetStartPositions(gameSMData *data) // sets the object start positions
{
    std:: string func = "playerStateMachine::setPModel";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_SET_START_POS)             // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_SET_START_POS)             // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_SET_START_POS)             // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (ST_SET_START_POS)             // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_SET_START_POS)             // ST_STOP
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_START
        TRANSITION_MAP_ENTRY (ST_SET_START_POS)             // ST_CHANGE_POSITION
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
void gameStateMachine::setSpeed(gameSMData *data)
{
    std:: string func = "playerStateMachine::setSpeed";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_START_MOVEMENT)            // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_START_MOVEMENT)            // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_START_MOVEMENT)            // ST_SET_START_POS
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
void gameStateMachine::halt()
{
    std:: string func = "playerStateMachine::halt";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_IDLE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_STOP
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_START
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_JUMP
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_SHOOT
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_PASS
    END_TRANSITION_MAP(NULL)

    logMsg(func +" end");

}
    
// jump player external event
void gameStateMachine::pJump(gameSMData *data)
{
    std:: string func = "playerStateMachine::pJump";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_JUMP)                      // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_JUMP)                      // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_JUMP)                      // ST_SET_START_POS
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
void gameStateMachine::pChangeDirection(gameSMData *data)
{
    std:: string func = "playerStateMachine::pChangeDirection";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_STOP
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_START
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_JUMP
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_CHANGE_DIRECTION
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_SHOOT
        TRANSITION_MAP_ENTRY (ST_CHANGE_DIRECTION)          // ST_PASS
    END_TRANSITION_MAP(data)

    logMsg(func +" end");

            //    exit(0);
}
    
// change  player position external event
void gameStateMachine::pChangePosition(gameSMData *data)
{
    std:: string func = "playerStateMachine::pChangePosition";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_SET_START_POS
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
//    exit(0);
}

// creates game object instances
STATE_DEFINE(gameStateMachine, createInstances, gameSMData)
{
    conversionSharedPtr convert = conversion::Instance();
    setupBasketballsSharedPtr setupBasketball(new setupBasketballs);
    setupCourtsSharedPtr setupCourt(new setupCourts);
    setupHoopsSharedPtr setupHoop(new setupHoops);
    setupTeamsSharedPtr setupTeam(new setupTeams);
    std:: string func = "gameStateMachine::createInstances";

    logMsg(func +" begin");

    if (!data->flag->getActiveBasketballInstancesCreated())
    {
        basketballStateMSharedPtr activeBasketballInstance = setupBasketball->createBasketballInstances();
        if (activeBasketballInstance.size() > 0)
        {
            logMsg("activeBasketballInstances Created!");
            basketballEntitySharedPtr tempBasketball(new basketballEntity);

            for (auto ABIIT : activeBasketballInstance) // loop that checks if each active hoop instance's entity has been initialized
            {
                if (!ABIIT.second->getEntityInitialized()) // if not initialized it initializes the entity
                {
                    ABIIT.second->setEntity(tempBasketball);
                    ABIIT.second->setEntityInitialized(true);
                }
                else
                {

                }
            }
            data->flag->setActiveBasketballInstancesCreated(true);
            data->component->setActiveBasketballInstance(activeBasketballInstance);
        }
        else
        {
            logMsg(func +" Unable to create Active Basketball Instances!");
            exit(0);
        }
    }
    else
    {
        
    }

    if (!data->flag->getCourtInstancesCreated())
    {
        courtStateMSharedPtr courtInstance = setupCourt->createCourtInstances();
        if (courtInstance.size() > 0)
        {
            logMsg(func +" Court Instances Created!!");
            data->flag->setCourtInstancesCreated(true);
            data->component->setCourtInstance(courtInstance);
        }
        else
        {
            logMsg(func +" Unable to Create Court Instances!");
            exit(0);
        }
    }
    if (!data->flag->getActiveCourtInstancesCreated())
    {
        courtStateMSharedPtr courtInstance = data->component->getCourtInstance();
        courtStateMSharedPtr activeCourtInstance;
        activeCourtInstance = setupCourt->createActiveCourtInstances(courtInstance);
        if (activeCourtInstance.size() > 0)
        {
            logMsg(func +" Active Court Instances Created!!");

            courtEntitySharedPtr tempCourt(new courtEntity);

            for (auto ACIIT : activeCourtInstance) // loop that checks if each active hoop instance's entity has been initialized
            {
                if (!ACIIT.second->getEntity()->getInitialized()) // if not initialized it initializes the entity
                {
                    ACIIT.second->setEntity(tempCourt);
                    ACIIT.second->getEntity()->setInitialized(true);
                }
                else
                {

                }
            }
            data->flag->setActiveCourtInstancesCreated(true);
            data->component->setActiveCourtInstance(activeCourtInstance);
        }
        else
        {
            logMsg(func +" Unable to create Active Court Instances!");
            exit(0);
        }
    }
    else
    {

    }
    
    if (!data->flag->getHoopInstancesCreated())
    {
        hoopStateMSharedPtr hoopInstance = setupHoop->createHoopInstances();
        if (hoopInstance.size() > 0)
        {
            logMsg(func +"Hoop Instances Created!");
            data->flag->setHoopInstancesCreated(true);
            data->component->setHoopInstance(hoopInstance);
        }
        else
        {
            logMsg(func +" Unable to Create Hoop Instances!");
            exit(0);
        }

    }
    logMsg(func +" hoop instance size == " +convert->toString(data->component->getHoopInstance().size()));
    logMsg(func +" hoop instance name == " +data->component->getHoopInstance()[0]->getEntity()->getName());
        
    if (!data->flag->getActiveHoopInstancesCreated())
    {
        //FIXME! Should not be hard coded!
        size_t numActiveHoops = 2;
        hoopStateMSharedPtr hoopInstance = data->component->getHoopInstance();
        hoopStateMSharedPtr activeHoopInstance = setupHoop->createActiveHoopInstances(hoopInstance, numActiveHoops);
        logMsg(func +" active hoop instance size == " +convert->toString(activeHoopInstance.size()));
        logMsg(func +" active hoop instance name == " +activeHoopInstance[0]->getEntity()->getName());
//        exit(0);
        
        if (activeHoopInstance.size() > 0)
        {
            logMsg(func +"Active Hoop Instances Created!");
//            exit(0);
            hoopEntitySharedPtr tempHoop(new hoopEntity);

            for (auto AHIIT : activeHoopInstance) // loop that checks if each active hoop instance's entity has been initialized
            {
                if (!AHIIT.second->getEntityInitialized()) // if not initialized it initializes the entity
                {
                    AHIIT.second->setEntity(tempHoop);
                    AHIIT.second->setEntityInitialized(true);
                }
                else
                {
                    logMsg(func +"Entity already initialized!");
                }
                
                logMsg(func +" active hoop instance name == " +AHIIT.second->getEntity()->getName());

            }          
//            exit(0);

        }
        else
        {
            logMsg(func +" Unable to create Active Hoop Instances!");
            exit(0);
        }
        data->flag->setActiveHoopInstancesCreated(true);
        data->component->setActiveHoopInstance(activeHoopInstance);

    }
    else
    {
        
    }
    logMsg(func +" end");
//    exit(0);
}

// loads the model object
STATE_DEFINE(gameStateMachine, loadModels, gameSMData)
{
    conversionSharedPtr convert = conversion::Instance();
    std:: string func = "gameStateMachine::loadModels";

    logMsg(func +" begin");

    if (!data->flag->getBasketballModelLoaded())  // Checks if basketball model has been loaded
    {
//        setActiveBBallInstance(0);  // Sets the active basketball instance
        loadBasketballsSharedPtr loadBasketball(new loadBasketballs);
        basketballStateMSharedPtr activeBasketballInstance;
        logMsg("Loading basketball Model!");
        activeBasketballInstance = loadBasketball->loadModels(data->component->getActiveBasketballInstance(), data->render);  // Loads the basketball model
        if (activeBasketballInstance.size() >0)
        {          
            data->flag->setBasketballModelLoaded(true);
            data->component->setActiveBasketballInstance(activeBasketballInstance);          
//            return (true);
        }
        else
        {
            logMsg(func +" Unable to load basketball model!");
//            returnType = false;
        }

        // FIXEME! this should not be hard coded
    }
    logMsg(func +" weeee");
//    exit(0);

    if (!data->flag->getCourtModelLoaded())  // Checks if the court model has been loaded
    {
        loadCourtsSharedPtr loadCourt(new loadCourts);
        courtStateMSharedPtr activeCourtInstance;
        
        logMsg(func +" Loading court model!");
        activeCourtInstance = loadCourt->loadModels(data->component->getActiveCourtInstance(), data->render);  // load the court model
        if (activeCourtInstance.size() > 0)
        {
            data->flag->setCourtModelLoaded(true);
            data->component->setActiveCourtInstance(activeCourtInstance);
//            return (true);
        }
        else
        {
            logMsg(func +" Unable to load the court model!");
//            returnType = false;
        }
    }


    if (!data->flag->getHoopModelLoaded())  // Checks if the hoop model(s) have been loaded
    {
        loadHoopsSharedPtr loadHoop(new loadHoops);
        hoopStateMSharedPtr activeHoopInstance;
        
        logMsg(func +" Loading hoop model(s)!");
        activeHoopInstance = loadHoop->loadModels(data->component->getActiveHoopInstance(), data->render);  // Creates the hoop instances
        if (activeHoopInstance.size() > 0)
        {
            data->flag->setHoopModelLoaded(true);
            data->component->setActiveHoopInstance(activeHoopInstance);
//            return (true);
        }
        else
        {
            logMsg(func +" Unable to load the hoop model(s)!");
//            returnType = false;
        }
    }

    logMsg(func +" end");
//    exit(0);
}
// sets the model object
STATE_DEFINE(gameStateMachine, setStartPositions, gameSMData)
{
    std:: string func = "gameStateMachine::setStartPositions";

    logMsg(func +" begin");

    currentModel = data->model;

    logMsg(func +" end");

}

// state machine sits here when player is not moving
STATE_DEFINE(gameStateMachine, Idle, noEventData)
{
    std:: string func = "playerStateMachine::Idle";

    logMsg(func +" begin");

    logMsg("playerStateMachine::ST_Idle");
    logMsg(func +" end");

//    exit(0);
}

// stop the player
STATE_DEFINE(gameStateMachine, StopMovement, noEventData)
{
    std:: string func = "playerStateMachine::StopMovement";

    logMsg(func +" begin");

    logMsg("playerStateMachine::ST_Stop");
    currentSpeed = 0; 
    currentDirection = NODIRECT;

    // perform the stop motor processing here
    // transition to Idle via an internal event
    internalEvent(ST_IDLE);
//    exit(0);
    logMsg(func +" end");

}

// start the player moving
STATE_DEFINE(gameStateMachine, StartMovement, gameSMData)
{
    conversionSharedPtr convert = conversion::Instance();
    std:: string func = "playerStateMachine::StartMovement";

    logMsg(func +" begin");

    logMsg("playerStateMachine::ST_Start : Speed is " +convert->toString(data->speed));
    currentSpeed = data->speed;
//    exit(0);
    // set initial player speed processing here
    logMsg(func +" end");

}

// changes the player's position on the court
STATE_DEFINE(gameStateMachine, ChangePosition, gameSMData)
{
//    exit(0);
    conversionSharedPtr convert = conversion::Instance();
    std:: string func = "playerStateMachine::ChangePosition";

    logMsg(func +" begin");

    logMsg("playerStateMachine::ST_ChangePosition : court position is " +convert->toString(data->position));
    currentPosition = data->position;
    currentNode->setPosition(currentPosition);
    logMsg(func +" Node Position == " +convert->toString(currentNode->getPosition()));
    logMsg(func +" end");

//    exit(0);
}
// changes the player's speed once the player is moving
STATE_DEFINE(gameStateMachine, ChangeSpeed, gameSMData)
{
//    exit(0);
    conversionSharedPtr convert = conversion::Instance();
    std:: string func = "playerStateMachine::ChangeSpeed";

    logMsg(func +" begin");

    logMsg("playerStateMachine::ST_ChangeSpeed : Speed is " +convert->toString(data->speed));
    currentSpeed = data->speed;

    logMsg(func +" end");

    //    exit(0);
    // perform the change player speed to data->speed here
}

// changes the player's direction once the player is moving
STATE_DEFINE(gameStateMachine, ChangeDirection, gameSMData)
{
    conversionSharedPtr convert = conversion::Instance();
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
    }
    logMsg(func +" end");

//    currentSpeed = data->direction;
//    exit(0);
    // perform the change player direction to data->direction here
}

STATE_DEFINE(gameStateMachine, Jump, gameSMData)
{
    std:: string func = "playerStateMachine::Jump";
//    exit(0)

    logMsg(func +" begin");

    logMsg("jump");
    logMsg("flee");
    conversionSharedPtr convert = conversion::Instance();
    
    logMsg("playerStateMachine::ST_Jump : Speed is " +convert->toString(data->speed));
    internalEvent(ST_IDLE);

    logMsg(func +" end");

//    currentSpeed = data->speed;
//    exit(0);
    // set initial player speed processing here
}

STATE_DEFINE(gameStateMachine, Shoot, gameSMData)
{
    conversionSharedPtr convert = conversion::Instance();
    std:: string func = "playerStateMachine::Shoot";

    logMsg(func +" begin");

    logMsg("playerStateMachine::ST_Shoot : Speed is " +convert->toString(data->speed));
    currentSpeed = data->speed;

    logMsg(func +" end");

//    exit(0);

    // set initial player shoot processing here
}

STATE_DEFINE(gameStateMachine, Pass, gameSMData)
{
    conversionSharedPtr convert = conversion::Instance();
    std:: string func = "playerStateMachine::Pass";


    logMsg(func +" begin");

    logMsg("playerStateMachine::ST_Pass : Speed is " +convert->toString(data->speed));
    currentSpeed = data->speed;

    logMsg(func +" end");

//    exit(0);
    // set initial player pass processing here
}
