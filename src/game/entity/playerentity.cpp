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
#include "flags/playerflags.h"
#include "statemachine/playerstatemachine.h"

// static declarations
    
//playerSteerSharedPtr playerEntity::steer;
//bool playerEntity::steerInitialized;

playerEntity::playerEntity()  // constructor
{
    activePosition = NONE;
    courtPosition = Ogre::Vector3(0.0f,0.0f,0.0f);
    posChange = Ogre::Vector3(0.0f,0.0f,0.0f);
    passToPlayer = NONE;
    direction = NODIRECT;
    oldDirection = NODIRECT;
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


std::vector<playerActions> playerEntity::getStateAction()  // retrieves the value of stateAction
{
    return (stateAction);
}
void playerEntity::setStateAction(std::vector<playerActions> set)  // sets the value of stateAction
{
    stateAction = set; 
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

playerPositions playerEntity::getPassToPlayer()  // retrieves the value of passToPlayer
{
    return (passToPlayer);
}
void playerEntity::setPassToPlayer(playerPositions set)  // sets the value of passToPlayer
{
    passToPlayer = set;
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

Ogre::Vector3 playerEntity::getNewCourtPosition()  // retrieves the value of newCourtPosition
{
    return (newCourtPosition);
}
void playerEntity::setNewCourtPosition(Ogre::Vector3 set)  // sets the value of newCourtPosition
{
    newCourtPosition = set;
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
    
    playerComponentsSharedPtr tempComponent(new playerComponents);
    component = tempComponent;

    playerDataSharedPtr tempData(new playerData);
    data = tempData;

    playerFlagsSharedPtr tempFlag(new playerFlags);
    flag = tempFlag;
    
    playerPhysicsSharedPtr tempPhysics(new playerPhysics);
    physics = tempPhysics;
    
    playerStateMachineSharedPtr tempStateMachine(new playerStateMachine);
    stateMachine = tempStateMachine;
    
    playerStatisticsSharedPtr tempStats(new playerStatistics);
    statistics = tempStats;

    return (true);
}

bool playerEntity::setupPhysicsObject()  // sets up the physics object
{
    std::string func = "playerEntity::setupPhysicsObject()!";
    OgreEntitySharedPtr tempModel = getModel();
    OgreSceneNodeSharedPtr tempNode = getNode();
    btRigidBody *tempPhysBody = getPhysics()->getPhysBody().get();
    
    logMsg(func +" beginning");
//    exit(0);
    
    if (!getPhysics()->getGameSInitialized())
    {
//BASEREMOVAL        getPhysics()->setGameS(getBase()->getGameS());
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
    conversionSharedPtr convert = conversion::Instance();

    std::string func = "playerEntity::updateStateMachine()";

    logMsg(func + " beginning");
//    exit(0);
    switch (actionType)
    {
        case CHANGECOURTPOS:
            logMsg(func + " CHANGECOURTPOS");
            stateMachine->pChangePosition(SMData);
        break;
        case CHANGEDIRECTION:
            logMsg(func + " CHANGEDIRECTION");
//            stateMachine->pChangeDirection(SMData);
        break;
        case SETNODE:
            logMsg(func +" SETNODE");
            stateMachine->setPNode(SMData);
            logMsg(func +" NODESET");
            
        break;
        case SETMODEL:
            logMsg(func +" SETMODEL");
            stateMachine->setPModel(SMData);
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
    
    logMsg(func +" beginning");

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
        logMsg(func +" stateAction.size() = " +convert->toString(stateAction.size()));
        for (auto SAIT : stateAction)
        {
            switch (SAIT)
            {
                case CHANGECOURTPOS:
                    logMsg(func + " CHANGECOURTPOS!");
                    stateData->position = newCourtPosition;
//                    exit(0);
                break;
                case CHANGEDIRECTION:
                    logMsg(func + " CHANGEDIRECTION!");
                    stateData->direction = direction;
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
        stateAction.clear();
        getFlag()->setStateChanged(false);  // sets stateChanged back to false now that hte stateMachine has been updated
    }
    else
    {
        
    }
    
    logMsg(func +" end");
}
