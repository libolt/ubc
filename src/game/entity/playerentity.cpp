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

#include "entity/playerentity.h"
#include "utilities/logging.h"
#include "utilities/conversion.h"
#include "engine/gameengine.h"
#include "engine/renderengine.h"
#include "statistics/playerstatistics.h"
#include "components/playercomponents.h"
#include "data/playerdata.h"
#include "data/playergamedata.h"

#include "flags/playerflags.h"

#include "statemachine/playerstatemachine.h"

// static declarations
    
//playerSteerSharedPtr playerEntity::steer;
//bool playerEntity::steerInitialized;

playerEntity::playerEntity()  // constructor
{
    
}
playerEntity::~playerEntity()  // destructor
{

}

playerComponentsSharedPtr playerEntity::getComponent()  // retrieves the value of component
{
    return (component);
}
void playerEntity::setComponent(playerComponentsSharedPtr set)  // sets the value of component
{
    component = set;
}

playerDataSharedPtr playerEntity::getData()  // retrieves the value of data
{
    return (data);
}
void playerEntity::setData(playerDataSharedPtr set)  // sets the value of data
{
    data = set;
}

playerFlagsSharedPtr playerEntity::getFlag()  // retrieves the value of flag
{
    return (flag);
}
void playerEntity::setFlag(playerFlagsSharedPtr set)  // sets the value of flag
{
    flag = set;
}

playerGameDataSharedPtr playerEntity::getGameData()  // retrieves the value of gameData
{
    return (gameData);
}
void playerEntity::setGameData(playerGameDataSharedPtr set)  // sets the value of gameData
{
    gameData = set;
}

bool playerEntity::initialize()  // initializes the player entity object
{
    
    playerComponentsSharedPtr tempComponent(new playerComponents);
    component = tempComponent;

    playerDataSharedPtr tempData(new playerData);
    data = tempData;

    playerFlagsSharedPtr tempFlag(new playerFlags);
    flag = tempFlag;
    
    playerGameDataSharedPtr tempGameData(new playerGameData);
    gameData = tempGameData;

    playerPhysicsSharedPtr tempPhysics(new playerPhysics);
    component->setPhysics(tempPhysics);
    
    playerStateMachineSharedPtr tempStateMachine(new playerStateMachine);
    component->setStateMachine(tempStateMachine);
    
    playerStatisticsSharedPtr tempStats(new playerStatistics);
    component->setStatistics(tempStats);

    return (true);
}

bool playerEntity::setupPhysicsObject()  // sets up the physics object
{
    std::string func = "playerEntity::setupPhysicsObject()!";
    OgreEntitySharedPtr tempModel = getModel();
    OgreSceneNodeSharedPtr tempNode = getNode();
    btRigidBody *tempPhysBody = component->getPhysics()->getPhysBody().get();
    
    logMsg(func +" begin");
//    exit(0);
    
    if (!component->getPhysics()->getGameInstanceInitialized())
    {
        component->getPhysics()->setGameInstanceInitialized(true);
    }

    component->getPhysics()->setMass(1.0f);
    component->getPhysics()->setRestitution(0.0f);
    component->getPhysics()->setFriction(0.0f);
//    exit(0);
    component->getPhysics()->setShapeType(CAPSULE);
    component->getPhysics()->setColObject(COL_PLAYER0);
    component->getPhysics()->setCollidesWith(COL_COURT);

    if (component->getPhysics()->setupPhysics(&tempModel, &tempNode, &tempPhysBody))
    {
        

        setPhysicsSetup(true);
        logMsg(func +" setModel");
        setModel(OgreEntitySharedPtr(tempModel));
        logMsg(func +" setNode");
        logMsg(func +" tempNode name == " +tempNode->getName());
        setNode(OgreSceneNodeSharedPtr(tempNode));
        logMsg(func +" setPhysBody");
        component->getPhysics()->setPhysBody(btRigidBodySharedPtr(tempPhysBody));
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
    std::string func = "playerEntity::initializeStateMachine()!";

//    SMData->speed = 100;
    SMData->model = getModel();  //
    SMData->node = getNode();
    logMsg(func +" begin");

//    exit(0);
    component->getStateMachine()->setSpeed(SMData);
    component->getStateMachine()->halt();
    return (true);
}

bool playerEntity::updateStateMachine(playerActions actionType, playerSMData *SMData)  // updates state machine with external input
{
    conversionSharedPtr convert = conversion::Instance();

    std::string func = "playerEntity::updateStateMachine()";

    logMsg(func + " beginning");
//    exit(0);
    switch (actionType)
    {
        case CHANGECOURTPOS:
            logMsg(func + " CHANGECOURTPOS");
            component->getStateMachine()->pChangePosition(SMData);
        break;
        case CHANGEDIRECTION:
            logMsg(func + " CHANGEDIRECTION");
//            stateMachine->pChangeDirection(SMData);
        break;
        case SETNODE:
            logMsg(func +" SETNODE");
            component->getStateMachine()->setPNode(SMData);
            logMsg(func +" NODESET");
            
        break;
        case SETMODEL:
            logMsg(func +" SETMODEL");
            component->getStateMachine()->setPModel(SMData);
            logMsg(func +" MODELSET");
            
        break;
    }
    logMsg(func + " end");
//    exit(0);
    
    return (true);
}

bool playerEntity::update() // executes any updates that need to be performed
{
    conversionSharedPtr convert = conversion::Instance();

    std::string func = "playerEntity::update()";
    playerSMData *stateData = new playerSMData;
    
    logMsg(func +" begin");

/*    if (getPhysicsSetup())
    {
        logMsg(func + " Updating player physics");

        getPhysics()->update();
        logMsg(func +" Updating Court Position");
//        updateCourtPosition();
        logMsg(func +" Court Position Updated!");
//        exit(0);
    }
    else
    {
        logMsg(func +" " +data->getFirstName() + " " +data->getLastName() +" physics NOT SETUP!");

    }*/
//    exit(0);
    
    if (flag->getStateChanged())
    {
        logMsg(func +" stateAction.size() = " +convert->toString(gameData->getStateAction().size()));
        for (auto SAIT : gameData->getStateAction())
        {
            switch (SAIT)
            {
                case CHANGECOURTPOS:
                    logMsg(func + " CHANGECOURTPOS!");
                    stateData->position = gameData->getNewCourtPosition();
//                    exit(0);o
                break;
                case CHANGEDIRECTION:
                    logMsg(func + " CHANGEDIRECTION!");
                    stateData->direction = gameData->getDirection();
                break;
                case SETNODE:
                    logMsg(func + " SETNODE!");
                    stateData->node = getNode();
                break;
                case SETMODEL:
                    logMsg(func + " SETMODEL!");
                    stateData->model = getModel();  
                break;
            }
        
            if(updateStateMachine(SAIT,stateData)) // attempts to update the stateMachine and returns true if successful
            {
//                stateChanged = false;  // sets stateChanged back to false now that hte stateMachine has been updated
            }
            else
            {
                logMsg(func +" Unable to update stateMachine!");
            }
        }
        gameData->getStateAction().clear();
        getFlag()->setStateChanged(false);  // sets stateChanged back to false now that hte stateMachine has been updated
    }
    else
    {
        
    }
    
    logMsg(func +" end");
}
