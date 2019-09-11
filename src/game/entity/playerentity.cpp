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

playerEntity::playerEntity()  // constructor
{
    componentInitialized = false;
    dataInitialized = false;
    flagInitialized = false;
    gameDataInitialized = false;
    objectsInitialized = false;

//    SMData = nullptr;
}
playerEntity::~playerEntity() = default;  // destructor


bool playerEntity::getComponentInitialized() const  // retrieves the value of componentInitialized
{
    return (componentInitialized);
}
void playerEntity::setComponentInotialized(const bool &set)  // sets the value of componentInitialized
{
    componentInitialized = set;
}

bool playerEntity::getDataInitialized() const  // retrieves the value of dataInitialized
{
    return (dataInitialized);
}
void playerEntity::setDataInotialized(const bool &set)  // sets the value of dataInitialized
{
    dataInitialized = set;
}

bool playerEntity::getFlagInitialized() const  // retrieves the value of flagInitialized
{
    return (flagInitialized);
}
void playerEntity::setFlagInotialized(const bool &set)  // sets the value of flagInitialized
{
    flagInitialized = set;
}

bool playerEntity::getGameDataInitialized() const  // retrieves the value of gameDataInitialized
{
    return (gameDataInitialized);
}
void playerEntity::setGameDataInotialized(const bool &set)  // sets the value of gameDataInitialized
{
    gameDataInitialized = set;
}

bool playerEntity::getObjectsInitialized() const  //  retrieves the value of objectsInitialized
{
    return (objectsInitialized);
}
void playerEntity::setObjectsInitialized(const bool &set)  //  sets the value of objectsInitialized
{
    objectsInitialized = set;
}

playerComponentsSharedPtr playerEntity::getComponent() const  // retrieves the value of component
{
    return (component);
}
void playerEntity::setComponent(const playerComponentsSharedPtr &set)  // sets the value of component
{
    component = set;
}

playerDataSharedPtr playerEntity::getData() const  // retrieves the value of data
{
    return (data);
}
void playerEntity::setData(const playerDataSharedPtr &set)  // sets the value of data
{
    data = set;
}

playerFlagsSharedPtr playerEntity::getFlag() const  // retrieves the value of flag
{
    return (flag);
}
void playerEntity::setFlag(const playerFlagsSharedPtr &set)  // sets the value of flag
{
    flag = set;
}

playerGameDataSharedPtr playerEntity::getGameData() const  // retrieves the value of gameData
{
    return (gameData);
}
void playerEntity::setGameData(const playerGameDataSharedPtr &set)  // sets the value of gameData
{
    gameData = set;
}

bool playerEntity::initializeObjects()  // initializes the player entity object
{
    bool retVal = false;
    
    playerComponentsSharedPtr tempComponent(new playerComponents);
    component = tempComponent;
    
    playerPhysicsSharedPtr tempPhysics(new playerPhysics);
    component->setPhysics(tempPhysics);
    
    playerStateMachineSharedPtr tempStateMachine(new playerStateMachine);
    component->setStateMachine(tempStateMachine);
    
    playerStatisticsSharedPtr tempStats(new playerStatistics);
    component->setStatistics(tempStats);

    componentInitialized = true;
    
    playerDataSharedPtr tempData(new playerData);
    data = tempData;
    dataInitialized = true;
    
    playerFlagsSharedPtr tempFlag(new playerFlags);
    flag = tempFlag;
    flagInitialized = true;
    
    playerGameDataSharedPtr tempGameData(new playerGameData);
    gameData = tempGameData;
    gameDataInitialized = true;
    
    if (componentInitialized && dataInitialized && flagInitialized && gameDataInitialized)
    {
        retVal = true;
    }
    
    return (retVal);
}

bool playerEntity::setupPhysicsObject()  // sets up the physics object
{
    std::string func = "playerEntity::setupPhysicsObject()!";
    OgreEntitySharedPtr tempModel = component->getModel();
    OgreSceneNodeSharedPtr tempNode = component->getNode();
    btRigidBody *tempPhysBody = component->getPhysics()->getPhysBody().get();
    bool retVal = false;
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
        

        flag->setPhysicsSetup(true);
        logMsg(func +" setModel");
        component->setModel(OgreEntitySharedPtr(tempModel));
        logMsg(func +" setNode");
        logMsg(func +" tempNode name == " +tempNode->getName());
        component->setNode(OgreSceneNodeSharedPtr(tempNode));
        logMsg(func +" setPhysBody");
        component->getPhysics()->setPhysBody(btRigidBodySharedPtr(tempPhysBody));
//        exit(0);

        retVal = true;
    }
    else
    {
    }
    
    logMsg(func +" end");
    
    return (retVal);
}

bool playerEntity::initializeStateMachine()  // initializes the stateMachine object
{
    auto *initSMData = new playerSMData;
    std::string func = "playerEntity::initializeStateMachine()!";

//    SMData = tempSMData;

    logMsg(func +" begin");

    if (!objectsInitialized)
    {
        logMsg(func +" Initializing objects!");
        objectsInitialized = initializeObjects();
    }
    else
    {
        logMsg(func +" Objects already initialized!");
    }


//    exit(0);
    component->getStateMachine()->setSpeed(initSMData);
    component->getStateMachine()->halt();

    logMsg(func +" end");

    return (true);
}

bool playerEntity::updateStateMachine(renderEngineSharedPtr render)  // updates state machine with external input
{
    conversionSharedPtr convert ;
    
    std::string func = "playerEntity::updateStateMachine()";
//    std::string func = "dah";

//    logMsg(func + " beginning");
//    exit(0);

    if (flag->getStateChanged())
    {
        logMsg(func +" stateAction.size() = " +convert->toString(gameData->getStateAction().size()));
        logMsg(func +" gameData->getStateAction().size() == " +convert->toString(gameData->getStateAction().size()));
//        exit(0);
        for (auto SAIT : gameData->getStateAction())
        {
            auto updateSMData(new playerSMData);

            switch (SAIT)
            {
            case PLOADMODEL:
                logMsg(func + " PLOADMODEL!");
//                exit(0);
                updateSMData->component = component;
                updateSMData->pData = data;
                updateSMData->flag = flag;
                updateSMData->render = render;
                component->getStateMachine()->pLoadModel(updateSMData);
                logMsg(func +" Model loaded == " +convert->toString(flag->getModelLoaded()));
//                exit(0);
            break;
            case PCREATENODE:
                logMsg(func + " PCREATENODE!");
//                updateSMData->model = component->getModel();
                updateSMData->component = component;
                updateSMData->pData = data;
                updateSMData->flag = flag;
                updateSMData->render = render;
                component->getStateMachine()->pCreateNode(updateSMData);
//                exit(0);
            break;
                case CHANGECOURTPOS:
                    logMsg(func + " CHANGECOURTPOS!");
                    logMsg(func + " newCourtPosition == " +convert->toString(gameData->getNewCourtPosition()));
//                    exit(0);
                    updateSMData->position = gameData->getNewCourtPosition();
//                    updateSMData->node = component->getNode();
                    component->getStateMachine()->pChangePosition(updateSMData);

//                    exit(0);o
                break;
                case CHANGEDIRECTION:
                    logMsg(func + " CHANGEDIRECTION!");
                    updateSMData->direction = gameData->getDirection();
//                    component->getStateMachine()->pChangeDirection(updateSMData);
                break;
                case PMOVE:
                break;
                case JUMP:
                break;
                case SHOOT:
                break;
                case PASS:
                break;
                case STEAL:
                break;
                case BLOCK:
                break;
                case PNOACTION:
                break;
            }


        }
//        exit(0);
        gameData->getStateAction().clear();
        getFlag()->setStateChanged(false);  // sets stateChanged back to false now that hte stateMachine has been updated
    }
    else
    {

    }

    if (component->getNode() != nullptr)
    {
        logMsg(func +" playerPos == " +convert->toString(component->getNode()->getPosition()));
    }
    //    component->getNode()->setPosition(Ogre::Vector3(100,100,0));
    logMsg(func + " end");
//    exit(0);
    
    return (true);
}

