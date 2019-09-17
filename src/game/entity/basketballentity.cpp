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
#include "components/basketballcomponents.h"
#include "components/gamecomponents.h"
#include "data/basketballdata.h"
#include "data/gamedata.h"
#include "entity/basketballentity.h"
#include "flags/basketballflags.h"
#include "flags/gameflags.h"
#include "physics/basketballphysics.h"
#include "statemachine/basketballstatemachine.h"
#include "utilities/comparison.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

basketballEntity::basketballEntity()  // constructor
{
//  physics = new basketballPhysics;

//    stateSet = false;
    
    objectsInitialized = false;

}
basketballEntity::~basketballEntity() = default;  // destructor

basketballComponentsSharedPtr basketballEntity::getComponent() const  // retrievees the value of component
{
    return (component);
}
void basketballEntity::setComponent(const basketballComponentsSharedPtr &set)  // sets the value of component
{
    component = set;
}

basketballDataSharedPtr basketballEntity::getData() const  // retrievees the value of data
{
    return(data);
}
void basketballEntity::setData(const basketballDataSharedPtr &set)  // sets the value of data
{
    data = set;
}

basketballFlagsSharedPtr basketballEntity::getFlag() const  // retrievees the value of flag
{
    return (flag);
}
void basketballEntity::setFlag(const basketballFlagsSharedPtr &set)  // sets the value of flag
{
    flag = set;
}

basketballStateMachineSharedPtr basketballEntity::getStateMachine() const  // retrievees the value of stateMachine
{
    return (stateMachine);
}
void basketballEntity::setStateMachine(const basketballStateMachineSharedPtr &set)  // sets the value of stateMachine
{
    stateMachine = set;
}

basketballActions basketballEntity::getAction() const  // retrieves the value of action
{
    return (action);
}
void basketballEntity::setAction(const basketballActions &set)
{
    action = set;
}

/*bool basketballEntity::initialize()  // initializes the basketball entity object
{
    sharedPtr<basketballPhysics> tempPhysics(new basketballPhysics);
    physics = tempPhysics;

    std::string func = "basketballEntity::initialize()";

    logMsg(func +" begin");

    sharedPtr<basketballData> tempData(new basketballData);
    data = tempData;

    basketballEntitySharedPtr tempEntity(new basketballEntity);
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
    }

    logMsg(func +" end");

    
    return (true);
}
*/

bool basketballEntity::initializeObjects()  // initializes the basketball objects
{
    basketballComponentsSharedPtr tempComponent(new basketballComponents); 
    component = tempComponent;
    
    sharedPtr<basketballPhysics> tempPhysics(new basketballPhysics);
    component->setPhysics(tempPhysics);

    basketballDataSharedPtr tempData(new basketballData);
    data = tempData;
    
    basketballFlagsSharedPtr tempFlag(new basketballFlags);
    flag = tempFlag;
    
    basketballStateMachineSharedPtr tempSM(new basketballStateMachine);
    stateMachine = tempSM;
    
    return (true);
}

bool basketballEntity::initializeStateMachine()  // initializes the basketball stateMachine object
{
    
    std::string func = "basketballEntity::initializeStateMachine()";

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
        
    basketballSMData *initSMData(new basketballSMData);
    
    initSMData->component = component;
    initSMData->bData = data;
    initSMData->flag = flag;
           
    stateMachine->pInitialize(initSMData);
    
    logMsg(func +" end");
    
    return (true);
}

/*bool basketballEntity::setupPhysicsObject()  // sets up the physics object
{
    conversionSharedPtr convert ;
    std::string func = "basketballEntity::setupPhysicsObject()";
    OgreEntitySharedPtr tempModel = getModel();
    OgreSceneNodeSharedPtr tempNode = getNode();
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
        setPhysicsSetup(true);

        logMsg(func +" modelName == " +tempModel->getName());
        logMsg(func +" nodeName == " +tempNode->getName());

//        exit(0);
        setModel(OgreEntitySharedPtr(tempModel));
        setNode(OgreSceneNodeSharedPtr(tempNode));
        component->getPhysics()->setPhysBody(btRigidBodySharedPtr(tempPhysBody));
//        exit(0);
        returnType = true;;

    }
    else
    {
    }

    logMsg(func +" end");

//    exit(0);
    return (returnType);
}*/


/*bool basketballState::initialize()  // initializes the basketballState object
{
    std::string func = "basketballState::initialize()";

    logMsg(func +" begin");

    sharedPtr<basketballData> tempData(new basketballData);
    data = tempData;

    basketballEntitySharedPtr tempEntity(new basketballEntity);
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
    }

    logMsg(func +" end");

    return (true);
}*/

// calculates change in position along the x,y,z axes
Ogre::Vector3 basketballEntity::calculatePositionChange()
{
//    sharedPtr<gameState> gameS = gameState::Instance();

    Ogre::Vector3 changeInPosition; // stores the calculated change in position
    Ogre::Vector3 pos = component->getNode()->getPosition();   // stores the basketball nodes position

    // initializes the variable
    changeInPosition[0] = 0.0f;
    changeInPosition[1] = 0.0f;
    changeInPosition[2] = 0.0f;
    return(changeInPosition);
}

void basketballEntity::updateStateMachine(const gameComponentsSharedPtr &gameComponent, const gameDataSharedPtr &gameDta, const gameFlagsSharedPtr &gameFlag, const renderEngineSharedPtr &render)  // updates the state of the basketball
{
    conversionSharedPtr convert;
    bool modelNeedsLoaded = flag->getModelNeedsLoaded();
    basketballSMData *udSMData(new basketballSMData);
    basketballSMData *umSMData(new basketballSMData);
    basketballSMData *upSMData(new basketballSMData);

    std::string func = "basketballEntity::updateStateMachine()";
    
    logMsg(func + " begin");

    if (objectsInitialized)
    {
        if (component != nullptr && component->getNode() != nullptr)
        {
            logMsg(func +" activeBasketballInstance Pos = " +convert->toString(component->getNode()->getPosition()));
//            exit(0);
        }
    }
//    exit(0);
/*    if (entity->getModelNeedsLoaded())
    {
        
        if (entity->loadModel())
        {
            entity->setModelNeedsLoaded(false);
            entity->setModelLoaded(true);
            
        }
    }
*/
    if (flag->getStateChanged())
    {
        logMsg(func +" State Changed!");
//        exit(0);
        switch (action)
        {
            case BLOADMODEL:
                logMsg(func +" BLOADMODEL");
                udSMData->bData = data;
                udSMData->component = component;
                udSMData->flag = flag;
                udSMData->gComponent = gameComponent;
                udSMData->gData = gameDta;
                udSMData->gFlag = gameFlag;
                udSMData->render = render;
                stateMachine->pLoadModel(udSMData);
//                exit(0);
            break;
            case BCREATENODE:
                logMsg(func +" BCREATENODE");
                udSMData->component = component;
                udSMData->flag = flag;
                udSMData->gComponent = gameComponent;
                udSMData->gData = gameDta;
                udSMData->gFlag = gameFlag;
                udSMData->render = render;
                stateMachine->pCreateNode(udSMData);
            break;
            case BCHANGEDIRECTION:
                logMsg(func +" updating direction!");
        //        updateDirection(gameComponent, gameDta, gameFlag);
                udSMData->flag = flag;
                udSMData->gComponent = gameComponent;
                udSMData->gData = gameDta;
                udSMData->gFlag = gameFlag;
                stateMachine->pUpdateMovement(udSMData);

//            flag->setDirectChange(false);
                logMsg(func + " direction updated!");
                exit(0);
            break;
            case BCHANGEPOS:
                logMsg(func + " updating position!");
                upSMData->component = component;
                upSMData->flag = flag;
                upSMData->node = component->getNode();
                stateMachine->pUpdatePosition(upSMData);
                logMsg(func + " position updated!");
                exit(0);
            break;
            case BMOVE:
                logMsg(func + " updating movement!");
                //updateMovement(gameComponent, gameDta, gameFlag);
                umSMData->component = component;
                umSMData->flag = flag;
                umSMData->gComponent = gameComponent;
                umSMData->gData = gameDta;
                umSMData->node = component->getNode();
                stateMachine->pUpdateMovement(umSMData);
                logMsg(func + " movement updated!");
                exit(0);
            break;

        }
        flag->setStateChanged(false);
        action = BNOACTION;
    }
    if (flag->getNumberSet())  // runs the physics update code
    {
        component->getPhysics()->updatePhysObj();
    }

/*    if (flag->getDirectChange())
    {
    }

    if (flag->getMovement())
    {
     }
*/


    logMsg(func + " end");
    
//    exit(0);
}

/*void basketballEntity::updatePosition() // updates the position of the basketball
{
    conversionSharedPtr convert ;
    comparison compare;
    Ogre::Vector3 changePos;
    btVector3 physChange = btVector3(0,0,0);
    std::string func = "basketballState::updatePosition()";

    logMsg(func + " beginning");
    if (flag->getCourtPositionChanged())
    {
        //exit(0);
        switch (component->getCourtPositionChangedType())
        {
            case STARTCHANGE:
                logMsg(func + " Updating basketball court position based on start position");
                
                getNode()->translate(component->getNewCourtPosition());
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
                getNode()->translate(changePos);
                physChange = BtOgre::Convert::toBullet(changePos); // converts from Ogre::Vector3 to btVector3
                component->getPhysics()->getPhysBody()->translate(physChange); // moves physics body in unison with the model
               
                flag->setCourtPositionChanged(false);
                component->setCourtPositionChangedType(NOCHANGE);
            break;   

            case INPUTCHANGE:
                logMsg(func + " Updating court position based on input");
                getNode()->translate(component->getNewCourtPosition());
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
                getNode()->translate(component->getNewCourtPosition());
                logMsg(func + " bball newCourtPosition = " +convert->toString(component->getNewCourtPosition()));
                logMsg(func + " bball node position" +convert->toString((getNode()->getPosition())));
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
                getNode()->translate(component->getNewCourtPosition());
                logMsg(func + " bball newCourtPosition = " +convert->toString(component->getNewCourtPosition()));
                logMsg(func + " bball node position" +convert->toString((getNode()->getPosition())));
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
        component->setCourtPosition(getNode()->getPosition());
        logMsg("basketball position = " +convert->toString(component->getCourtPosition()));
    }
    
    logMsg("basketball position = " +convert->toString(component->getCourtPosition()));

    node->translate(posChange);
    btVector3 change; // = btVector3(0,0,0);
    change = BtOgre::Convert::toBullet(posChange); // converts from Ogre::Vector3 to btVector3
    physBody->translate(change); // moves physics body in unison with the model

    logMsg(func + " end");
}*/

/*void basketballEntity::updateMovement(const gameComponentsSharedPtr &gameComponent, const gameDataSharedPtr &gameDta, const gameFlagsSharedPtr &gameFlag)  // updates the basketball(s) movements
{
    conversionSharedPtr convert ;
//    sharedPtr<gameState> gameS = gameState::Instance();
    teamEntityMSharedPtr activeTeamInstance = gameComponent->getActiveTeamInstance();
    size_t teamWithBall = gameDta->getTeamWithBall();
///TS    playerStateVecSharedPtr activePlayerInstance = activeTeamInstance[teamWithBall]->getActivePlayerInstance();
///    size_t playerWithBallInstance = activeTeamInstance[teamWithBall]->getPlayerWithBallInstance();
///    size_t playerWithBallID = activeTeamInstance[teamWithBall]->getPlayerWithBallID();
///TS
    size_t x = 0;
    
//TS    bool shotTaken = activePlayerInstance[playerWithBallInstance]->getShotTaken();
    Ogre::Vector3 bballPos;
    Ogre::Vector3 bballCurrentPos;  // stores the current position of the basketball(s)
    Ogre::Vector3 playerPos;
//TS    logMsg("playerWithBallInstance == " +convert->toString(playerWithBallInstance));
//TS logMsg("playerWithBallID == " +convert->toString(playerWithBallID));
    std::string func = "basketballState::updateMovement()";

    logMsg(func + " beginning");

    if (component->getCourtPosition().x == 0 && component->getCourtPosition().y == 0 && component->getCourtPosition().z == 0)
    {
        bballCurrentPos = getNode()->getPosition();
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

    logMsg(func + " end");
}
*/
/*
void basketballEntity::updateDirection(const gameComponentsSharedPtr &gameComponent, const gameDataSharedPtr &gameDta, const gameFlagsSharedPtr &gameFlag)  // updates basketball direction(s)
{
    //conversion *convert = conversion::Instance();
    conversionSharedPtr convert ;
//    sharedPtr<gameState> gameS = gameState::Instance();
    teamEntityMSharedPtr activeTeamInstance = gameComponent->getActiveTeamInstance();
    size_t teamWithBall = gameDta->getTeamWithBall();
TS    playerStateVecSharedPtr activePlayerInstance = activeTeamInstance[teamWithBall]->getActivePlayerInstance();
    sizeTVec activePlayerID = activeTeamInstance[teamWithBall]->getActivePlayerID();
    
    size_t playerWithBallInstance = activeTeamInstance[teamWithBall]->getPlayerWithBallInstance();
    size_t playerWithBallID = activeTeamInstance[teamWithBall]->getPlayerWithBallID();

    jumpBallsSharedPtr jumpBall = gameComponent->getJumpBall();

//TS    logMsg("directplayerwithballInstance == " +convert->toString(playerWithBallInstance));
    bool tipOffComplete = gameFlag->getTipOffComplete();
    size_t x = 0;
    std::string func = "basketballState::updateDirection()";

    logMsg(func + " beginning");

TS    bool shotTaken = activePlayerInstance[playerWithBallInstance]->getShotTaken();

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
TS
    gameComponent->setJumpBall(jumpBall);
    
    logMsg(func + " end");

}
*/

// calculates the trajectory the basketball travels when shot
bool basketballEntity::calculateShot()
{
    return true;
}

// handles the shot logic as the ball travels towards the hoop
bool basketballEntity::shotLogic()
{
    return true;
}
