/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
 *   libolt@libolt.net                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any latier version.                                  *
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

#include "conversion.h"

#include "Ogre.h"

#include "logging.h"
#include "engine/physicsengine.h"
//#include "engine/renderengine.h"
//#include "ai/steering.h"
#include "ai/playersteer.h"
#include "data/playerdata.h"
#include "entity/playerentity.h"
#include "state/basketballstate.h"
#include "state/courtstate.h"
#include "state/gamestate.h"
#include "state/hoopstate.h"
//#include "state/gamestate.h"
#include "state/playerstate.h"
#include "state/teamstate.h"
#include "comparison.h"
//#include "jumpballs.h"

// static declarations
//sharedPtr<playerData> playerState::data;  // instance of playerData object
//sharedPtr<playerEntity> playerState::playerEnt;  // instance of playerEntity object
//sharedPtr<playerPhysics> playerState::physics;  // instance of physics object
UBCBaseSharedPtr playerState::base;  // base class object

playerState::playerState()
{
//    playerID = 0;
    teamType = NOTEAM;
    isActive = false;
//    modelLoaded = false;
    networkControlled = false;
    offDef = 0;
    defending = -1;
//    primaryPosition = NONE;
//    secondaryPosition = NONE;
    activePosition = NONE;
    userControlled = false;
    user = -1;
    points = 0;
    fouls = 0;
    offensiveRebounds = 0;
    defensiveRebounds = 0;
    totalRebounds = 0;
    stamina = 0;
    steals = 0;
    blocks = 0;
    turnovers = 0;
    assists = 0;
    fieldGoalsAttemped = 0;
    fieldGoalsMade = 0;
    threePointersAttempted = 0;
    threePointersMade = 0;
    freeThrowsAttempted = 0;
    freeThrowsMade = 0;
    posChange = Ogre::Vector3(0.0f,0.0f,0.0f);
    movement = false;
    startPosReached = false;
    shootBlock = false;
    passSteal = false;
    passBall = false;
    passCalculated = false;
    passToPlayer = NONE;
    shotTaken = false;
    shotSet = false;
    shotComplete = false;
    offenseSet = false;
    defenseSet = false;
    initialized = false;
    jumpSet = false;
    jumpComplete = false;
    courtPosition = Ogre::Vector3(0.0f,0.0f,0.0f);
    courtPositionChanged = false;
//    stateSet = false;
    // hack
    posChangeAmount = 0;
    direction = NODIRECT;
    oldDirection = NODIRECT;
}

playerState::~playerState() // destructor
{
}

sharedPtr<playerData> playerState::getData()  // retrieves the value of data
{
    return (data);
}
void playerState::setData(sharedPtr<playerData> set)  // sets the value of data
{
    data = set;
}

sharedPtr<playerEntity> playerState::getEntity()  // retrieves the value of entity
{
    return (entity);
}
void playerState::setEntity(sharedPtr<playerEntity> set)  // sets the value of entity
{
    entity = set;
}

UBCBaseSharedPtr playerState::getBase()  // retrieves the value of base
{
    return (base);
}
void playerState::setBase(UBCBaseSharedPtr set)  // sets the value of base
{
    base = set;
}

bool playerState::getBaseInitialized()  // retrieves the value of baseInitialized
{
    return (baseInitialized);
}
void playerState::setBaseInitialized(bool set)  // sets the value of baseInitialized
{
    baseInitialized = set;
}

teamTypes playerState::getTeamType()  // retrieves the value of teamType
{
    return (teamType);
}
void playerState::setTeamType(teamTypes set)  // sets the value of teamType
{
    teamType = set;
}

playerPositions playerState::getActivePosition()  // retrieves the value of activePosition
{
    return (activePosition);
}
void playerState::setActivePosition(playerPositions set)  // sets the value of activePosition
{
    activePosition = set;
}

bool playerState::getIsActive() // retrieves the value of isActive
{
    return (isActive);
}
void playerState::setIsActive(bool set) // sets the value of isActive
{
    isActive = set;
}

size_t playerState::getOffDef()  // retrieves the value of offDef
{
    return(offDef);
}
void playerState::setOffDef(size_t set)  // sets the value of offDef
{
    offDef = set;
}

size_t playerState::getDefending()  // retrieves the value of defending
{
    return (defending);
}
void playerState::setDefending(size_t set)  // sets the value of defending
{
    defending = set;
}

bool playerState::getUserControlled()  // retrieves the value of userControlled
{
    return(userControlled);
}
void playerState::setUserControlled(bool set)  // sets the value of userControlled
{
    userControlled = set;
}

size_t playerState::getUser()  // retrieves the value of user
{
    return(user);
}
void playerState::setUser(size_t set)  // sets the value of user
{
    user = set;
}

size_t playerState::getPoints()  // retrieves the value of points
{
    return(points);
}
void playerState::setPoints(size_t set)  // sets the vlaue of points
{
    points = set;
}

size_t playerState::getFouls()  // retrieves the value of fouls
{
    return(fouls);
}
void playerState::setFoulds(size_t set)  // sets the value of fouls
{
    fouls = set;
}

size_t playerState::getOffensiveRebounds()  // retrieves the value of offensiveRebounds
{
    return(offensiveRebounds);
}
void playerState::setOffensiveRebounds(size_t set)  // sets the value of offensiveRebounds
{
    offensiveRebounds = set;
}

size_t playerState::getDefensiveRebounds()  // retrieves the value of defensiveRebounds
{
    return(defensiveRebounds);
}
void playerState::setDefensiveRebounds(size_t set)  // sets the value of defensiveRebounds
{
    defensiveRebounds = set;
}

size_t playerState::getTotalRebounds()  // retrieves the value of totalRebounds
{
    return(totalRebounds);
}
void playerState::setTotalReboundS(size_t set)  // sets the value of totalRebounds
{
    totalRebounds = set;
}

size_t playerState::getStamina()  // retrieves the value of stamina
{
    return(stamina);
}
void playerState::setStamina(size_t set)  // sets the value of stamina
{
    stamina = set;
}

size_t playerState::getSteals()  // retrieves the value of steals
{
    return(steals);
}
void playerState::setSteals(size_t set)  // sets the value of steals
{
    steals = set;
}

size_t playerState::getBlocks()  // retrieves the value of blocks
{
    return(blocks);
}
void playerState::setBlocks(size_t set)  // sets the value of blocks
{
    blocks = set;
}

size_t playerState::getTurnovers()  // retrieves the value of turnovers
{
    return(turnovers);
}
void playerState::setTurnovers(size_t set)  // sets the value of turnovers
{
    turnovers = set;
}

size_t playerState::getAssists()  // retrieves the value of assist
{
    return(assists);
}
void playerState::setAssists(size_t set)  // sets the value of assists
{
    assists = set;
}

size_t playerState::getFieldGoalsAttemped()  // retrieves the value of fieldGoalsAttempted
{
    return(fieldGoalsAttemped);
}
void playerState::setFieldGoalsAttempted(size_t set)  // sets the value of fieldGoalsAttempted
{
    fieldGoalsAttemped = set;
}

size_t playerState::getFieldGoalsMade()  // retrieved the value of fieldGoalsMade
{
    return(fieldGoalsMade);
}
void playerState::setFieldGoalsmade(size_t set)  // sets the value of fieldGoalsMade
{
    fieldGoalsMade = set;
}

size_t playerState::getThreePointersAttempted()  // retrieves the value of threePointersAttempted
{
    return(threePointersAttempted);
}
void playerState::setThreePointersAttempted(size_t set)  // sets the value of threePointersAttempted
{
    threePointersAttempted = set;
}

size_t playerState::getThreePointersMade()  // retrieves the value of threePointersMade
{
    return(threePointersMade);
}
void playerState::setThreePointersMade(size_t set)  // sets the value of threePointersMade
{
    threePointersMade = set;
}

size_t playerState::getFreeThrowsAttempted()  // retrieves the value of freeThrowsAttempted
{
    return(freeThrowsAttempted);
}
void playerState::setFreeThrowsAttempted(size_t set)  // sets the value of freeThrowsAttempted
{
    freeThrowsAttempted = set;
}

size_t playerState::getFreeThrowsMade()  // retrieves the value of freeThrowsMade
{
    return(freeThrowsMade);
}
void playerState::setFreeThrowsMade(size_t set)  // sets the value of freeThrowsMade
{
    freeThrowsMade = set;
}

bool playerState::getMovement()  // retrieves the value of movement
{
    return (movement);
}
void playerState::setMovement(bool set)  // sets the value of movement
{
    movement = set;
}

directions playerState::getDirection()  // retrieves the value of direction
{
    return (direction);
}
void playerState::setDirection(directions set)  // sets the value of direction
{
    direction = set;
}

directions playerState::getOldDirection()  // retrieves the value of oldDirection
{
    return (oldDirection);
}
void playerState::setOldDirection(directions set)  // sets the value of oldDirection
{
    oldDirection = set;
}

Ogre::Vector3 playerState::getPosChange()  // retrieves the value of posChange
{
    return (posChange);
}
void playerState::setPosChange(Ogre::Vector3 set)  // sets the value of posChange
{
    posChange = set;
}

bool playerState::getStartPosReached()  // retrieves the value of startPosReached
{
    return (startPosReached);
}
void playerState::setStartPosReached(bool set)  // sets the value of startPosReached
{
    startPosReached = set;
}

bool playerState::getShootBlock()  // retrieves the value of shootBlock
{
    return (shootBlock);
}
void playerState::setShootBlock(bool set)   // sets the value of shootBlock
{
    shootBlock = set;
}

bool playerState::getPassSteal()  // retrieves the value of passSteal
{
    return (passSteal);
}
void playerState::setPassSteal(bool set)  // sets the value of passSteal
{
    passSteal = set;
}

bool playerState::getPassBall()  // retrieves the value of passBall
{
    return (passBall);
}
void playerState::setPassBall(bool set)  // sets the value of passBall
{
    passBall = set;
}

bool playerState::getPassCalculated()  // retrieves the value of passCalculated
{
    return (passCalculated);
}
void playerState::setPassCalculated(bool set)  // sets the value of passCalculated
{
    passCalculated = set;
}

bool playerState::getPassCompleted()  // retrieves the value of passCompleted
{
    return (passCompleted);
}
void playerState::setPassCompleted(bool set)  // sets the value of passCompleted
{
    passCompleted = set;
}

playerPositions playerState::getPassToPlayer()  // retrieves the value of passToPlayer
{
    return (passToPlayer);
}
void playerState::setPassToPlayer(playerPositions set)  // sets the value of passToPlayer
{
    passToPlayer = set;
}

bool playerState::getShotTaken()  // retrieves the value of shotTaken
{
    return (shotTaken);
}
void playerState::setShotTaken(bool set)  // sets the value of shotTaken
{
    shotTaken = set;
}

bool playerState::getShotSet()  // retrieves the value of shotSet
{
    return (shotSet);
}
void playerState::setShotSet(bool set)  // sets the value of shotSet
{
    shotSet = set;
}

bool playerState::getShotComplete()  // retrieves the value of shotComplete
{
    return (shotComplete);
}
void playerState::setShotComplete(bool set)  // sets the value of shotComplete
{
    shotComplete = set;
}

Ogre::Vector3 playerState::getJumpBeginPos()  // retrieves the value of playerJumpBeginPos
{
    return (jumpBeginPos);
}
void playerState::setJumpBeginPos(Ogre::Vector3 set)  // sets the value of playerJumpBeginPos
{
    jumpBeginPos = set;
}

Ogre::Vector3 playerState::getJumpEndPos()  // retrieves the value of playerJumpEndPos
{
    return (jumpEndPos);
}
void playerState::setJumpEndPos(Ogre::Vector3 set)  // sets the value of playerJumpEndPos
{
    jumpEndPos = set;
}

bool playerState::getJumpSet()  // retrieves the value of jumpSet
{
    return (jumpSet);
}
void playerState::setJumpSet(bool set)  // sets the value of jumpSet
{
    jumpSet = set;
}

bool playerState::getJumpComplete()  // retrieves the value of jumpComplete
{
    return (jumpComplete);
}
void playerState::setJumpComplete(bool set)  // sets the value of jumpComplete
{
    jumpComplete = set;
}

bool playerState::getOffenseSet()  // retrieves the value of offenseSet
{
    return (offenseSet);
}
void playerState::setOffenseSet(bool set)  // sets the value of offenseSet
{
    offenseSet = set;
}

bool playerState::getDefenseSet()  // retrieves the value of defenseSet
{
    return (defenseSet);
}
void playerState::setDefenseSet(bool set)  // sets the value of defenseSet
{
    defenseSet = set;
}

Ogre::Vector3 playerState::getCourtPosition()  // retrieves the value of courtPosition
{
//    courtPosition = Ogre::Vector3(1,1,1);
    return (courtPosition);
//    return (getNode()->getPosition());
}
void playerState::setCourtPosition(Ogre::Vector3 set)  // sets the value of courtPosition
{
    courtPosition = set;
}

Ogre::Vector3 playerState::getNewCourtPosition()  // retrieves the value of newCourtPosition
{
    return (newCourtPosition);
}
void playerState::setNewCourtPosition(Ogre::Vector3 set)  // sets the value of newCourtPosition
{
    newCourtPosition = set;
}

bool playerState::getCourtPositionChanged()  // retrieves the value of courtPositionChanged
{
    return (courtPositionChanged);
}
void playerState::setCourtPositionChanged(bool set)  // sets the value of courtPositionChanged
{
    courtPositionChanged = set;
}

positionChangedTypes playerState::getCourtPositionChangedType()  // retrieves the value of courtPositionChangedType
{
    return (courtPositionChangedType);
}
void playerState::setCourtPositionChangedType(positionChangedTypes set)  // sets the value of courtPositionChangedType
{
    courtPositionChangedType = set;
}

bool playerState::getInitialized()  // retreives the value of initialized
{
    return (initialized);
}

void playerState::setInitialized(bool set)  // sets the value of initialized
{
    initialized = set;
}

bool playerState::initialize()  // initializes the state of the object
{
    std::string func = "playerState::initialize()";
    
    logMsg(func +" beginning");
        sharedPtr<playerData> tempData(new playerData);
    data = tempData;
    sharedPtr<playerEntity> tempPEnt(new playerEntity);
    entity = tempPEnt;
//    entity->setInitialized(true);
/*
    playerSteerSharedPtr tempSteer(new playerSteer);
    setSteer(tempSteer);
    
    logMsg("steer->setTeamType(teamType);");
    
    getSteer()->setTeamType(teamType);
    logMsg("psteer->reset();");
    getSteer()->reset();
//    logMsg("pInstance->setSteer(playerSteerSharedPtr(pSteer);");

//    pInstance->setSteer(playerSteerSharedPtr(pSteer));
*/
    logMsg(func +" end");

    return (true);
}

void playerState::updateState()
{
    sharedPtr<conversion> convert = conversion::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
///    sharedPtr<physicsEngine> physEngine = physicsEngine::Instance();
    physicsEngine physEngine;
    jumpBallsSharedPtr jumpBall = base->getGameS()->getJumpBall();
    Ogre::Vector3 playerPos;
    std::string func = "playerState::updateState()";
    
    logMsg(func +" beginning");
    logMsg(func +" " +data->getFirstName() + " " +data->getLastName() +" PSUPDATE!");
    logMsg(func +" " +entity->getEntityName() +" PSUPDATE!!");

    if (entity->getPhysicsSetup())
    {
        logMsg(func +" Updating Court Position");
        updateCourtPosition();
        logMsg(func +" Court Position Updated!");
//        exit(0);
    }
    else
    {
        logMsg(func +" " +data->getFirstName() + " " +data->getLastName() +" physics NOT SETUP!");

    }

//    if (shotTaken && !shotComplete)  // checks if a player takes a shot

    
    if (shootBlock)
    {
        if (teamType == base->getGameS()->getTeamWithBall())
        {
//            shotLogic(playerPos);
//            exit(0);
            if (!shotTaken)
            {
                shotTaken = true;
            }
            entity->getPhysics()->shootBasketball(teamType, data->getID());

        }
        else
        {
            entity->getPhysics()->jump(teamType, data->getID());
        }
        
    }
    
    if (passSteal)
    {
        logMsg(func +" passSteal!!");
        logMsg(func +" passSteal teamType == " +convert->toString(teamType));
        logMsg(func +" passSteal teamWithBall == " +convert->toString(base->getGameS()->getTeamWithBall()));
        
        if (teamType == base->getGameS()->getTeamWithBall())
        {
            calculatePass();
        }
        else
        {
            
        }
        
    }
    else
    {
    }
    
    logMsg(func + " Direction?");
    if (direction != NODIRECT)  // updates the direction the player is facing if it has changed
    {
        logMsg(func + " Updating Direction");
        updateDirection();
        logMsg(func + " Updating Movement");
        updateMovement();
        logMsg(func + " oldDirection = direction");
        oldDirection = direction;
        logMsg(func + " activeTeamInstance = base->getGameS()->getActiveTeamInstance()");
        teamStateUMSharedPtr activeTeamInstance = base->getGameS()->getActiveTeamInstance();
//        size_t playerWithBallID = activeTeamInstance[teamType]->getPlayerWithBallID();
        logMsg(func + " Team Type == " +convert->toString(teamType));
        if (teamType == base->getGameS()->getTeamWithBall() && base->getGameS()->getTipOffComplete())
        {
//            logMsg(func +" dplayerWithBallID == " +convert->toString(playerWithBallID));
            if (/*data->getID() == playerWithBallID &&*/ data->getID() >= 0)
            {
//                logMsg(func +" playerID == " +convert->toString(data->getID()));
//                int activeBBallInstance = getActiveBBallInstance();
                basketballStateUMSharedPtr activeBasketballInstance = base->getGameS()->getActiveBasketballInstance();
                
                //FIXME! HARDCODED VALUE!
                activeBasketballInstance[0]->setMovement(true);
                base->getGameS()->setActiveBasketballInstance(activeBasketballInstance);
//                exit(0);
            }
        }        
        direction = NODIRECT;
    }

    logMsg(func +" end");
}

bool playerState::updateCourtPosition()  // updates the XYZ coordinates of the 3D model
{
    std::string func = "playerState::updateCourtPosition() ";
    sharedPtr<conversion> convert = conversion::Instance();
    ///sharedPtr<physicsEngine> physEngine = physicsEngine::Instance();
    physicsEngine physEngine;
    comparison compare;
    btVector3 physChange = btVector3(0,0,0);
    Ogre::Vector3 changePos = Ogre::Vector3(0,0,0);
    
    logMsg(func + " beginning");
//    logMsg(func + " updatePosChange == " +convert->toString(posChange));
    logMsg(func + " Name == " +data->getFirstName() + " " +data->getLastName());
    logMsg(func + " newCourtPosition == " +convert->toString(newCourtPosition));
//    exit(0);
    if (courtPositionChanged)
    {
        btTransform transform;
        btVector3 physPos;
        switch (courtPositionChangedType)
        {
            case STARTCHANGE:
/*                logMsg(func + " STARTCHANGE");              
                logMsg(func +" Node Position == " +convert->toString(entity->getNode()->getPosition()));
                logMsg(func +" Node Scale == " +convert->toString(entity->getNode()->getScale()));

                logMsg(func +" New Court Position == " +convert->toString(newCourtPosition));
*/
                logMsg(func + " Name == " +data->getFirstName() +" " +data->getLastName());
                logMsg(func + " UC Entity Name == " +entity->getEntityName());
                logMsg(func + "Entity UC Node Name == " +entity->getEntityNodeName());
                logMsg(func + " UC Node Name == " +entity->getNode()->getName());
                logMsg(func + " Node Translate");     
                entity->getNode()->translate(newCourtPosition);
                logMsg(func + " Convert to Bullet");
                physChange = BtOgre::Convert::toBullet(newCourtPosition);  // converts from Ogre::Vector3 to btVector3
                logMsg("physChange == " +convert->toString(physChange));
                transform = entity->getPhysics()->getPhysBody()->getWorldTransform();
                physPos = transform.getOrigin();
                logMsg("physPos == " +convert->toString(physPos));

                logMsg(func + " PhysBody Translate");
                entity->getPhysics()->getPhysBody()->translate(physChange); // moves physics body in unison with the model
                logMsg(func + " Steer set Position Changed");
                entity->getSteer()->setPosition(convert->toOpenSteerVec3(newCourtPosition));
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
                startPosReached = true;
                courtPosition = entity->getNode()->getPosition();
//                exit(0);
            break;
            
            case STEERCHANGE:
                //logMsg("Updating player court position based on steering");
                //logMsg("Team " +convert->toString(teamType) + " Player " +convert->toString(playerID));
                changePos = compare.OgreVector3ToOgreVector3Result(courtPosition, newCourtPosition);
                //logMsg("change playerCourtPosition = " +convert->toString(changePos));
                entity->getNode()->translate(changePos);
                physChange = BtOgre::Convert::toBullet(changePos);  // converts from Ogre::Vector3 to btVector3
                entity->getPhysics()->getPhysBody()->translate(physChange); // moves physics body in unison with the model
                exit(0);
                
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
                courtPosition = entity->getNode()->getPosition();
            break;   

            case INPUTCHANGE:
                //logMsg("Updating court position based on input");
                entity->getNode()->translate(newCourtPosition);
                physChange = BtOgre::Convert::toBullet(newCourtPosition);  // converts from Ogre::Vector3 to btVector3
                entity->getPhysics()->getPhysBody()->translate(physChange);  // moves physics body in unison with the model
                entity->getSteer()->setPosition(convert->toOpenSteerVec3(newCourtPosition));
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
                //exit(0);
                courtPosition = entity->getNode()->getPosition();
            break;

            case PHYSICSCHANGE:
                /*  I have disabled this code until I can fix the conflict with the steering code
                logMsg("Updating court position based on physics");
                logMsg("courtPosition = " +convert->toString(courtPosition));
                logMsg("newCourtPosition = " +convert->toString(newCourtPosition));
                entity->getNode()->translate(newCourtPosition);
                logMsg("node position updated");
                entity->getSteer->setPosition(convert->toOpenSteerVec3(newCourtPosition));
                logMsg("steer position updated");
                */
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
                courtPosition = entity->getNode()->getPosition();
                // exit(0);
            break;

            default:
            break;
        }
        ++posChangeAmount;
//        logMsg(func + " player ID " +convert->toString(data->getID()) +"change amount = " +convert->toString(posChangeAmount));
        
    }
    
/*    logMsg("posChange = " +convert->toString(posChange));
//  cout << "posChange = " << posChange << endl;
    entity->getNode->translate(posChange);
    btVector3 change = btVector3(0,0,0);
    change = BtOgre::Convert::toBullet(posChange);  // converts from Ogre::Vector3 to btVector3
//  logMsg("playerPhysicsSetup = " +convert->toString(physEngine.getPlayerPhysicsSetup()));

    physBody->translate(change);  // moves physics body in unison with the model
//  exit(0);
//  physBody->translate(btVector3(0,0,0));
//  logMsg("player position updated.");
*/

    logMsg(func + " end");
    
    return true;
}


void playerState::updateDirection()
{
    
    sharedPtr<conversion> convert = conversion::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
    teamStateUMSharedPtr activeTeamInstance = base->getGameS()->getActiveTeamInstance();
    basketballStateUMSharedPtr activeBasketballInstance = base->getGameS()->getActiveBasketballInstance();   
//    size_t activeBBallInstance = getActiveBBallInstance();
//    size_t playerWithBallID = activeTeamInstance[teamType]->getPlayerWithBallID();
    
//    exit(0);
    std::string func = "playerState::updateDirection()";
    
    logMsg(func +" beginning");
    
    if (direction != oldDirection)
    {        
        switch (oldDirection)
        {
            case UP:
                switch (direction)
                {
                    case DOWN:
                        entity->getNode()->yaw(Ogre::Degree (180));
                    break;
                    case LEFT:
                        entity->getNode()->yaw(Ogre::Degree (270));
                    break;
                    case RIGHT:
                        entity->getNode()->yaw(Ogre::Degree (90));
//                        exit(0);
                    break;
                    default:
                    break;
                }
//                exit(0);
            break;
            case DOWN:
                switch (direction)
                {
                    case UP:
                        entity->getNode()->yaw(Ogre::Degree (180));
                    break;
                    case LEFT:
                        entity->getNode()->yaw(Ogre::Degree (90));
                    break;
                    case RIGHT:
                        entity->getNode()->yaw(Ogre::Degree (270));
                    break;
                    default:
                    break;
                }
            break;
            case LEFT:
                switch (direction)
                {
                    case UP:
                        entity->getNode()->yaw(Ogre::Degree (90));
                    break;
                    case DOWN:
                        entity->getNode()->yaw(Ogre::Degree (270));
                    break;
                    case RIGHT:
                        entity->getNode()->yaw(Ogre::Degree (180));
                    break;
                    default:
                    break;
                }
            break;
            case RIGHT:
                switch (direction)
                {
                    case UP:
                        entity->getNode()->yaw(Ogre::Degree (270));
                    break;
                    case DOWN:
                        entity->getNode()->yaw(Ogre::Degree (90));
                    break;
                    case LEFT:
                        entity->getNode()->yaw(Ogre::Degree (180));
                    break;
                    default:
                    break;
                }
            break;
            case NODIRECT:
            switch (direction)
            {
                case UP:
                    entity->getNode()->yaw(Ogre::Degree (270));
                break;
                case DOWN:
                    entity->getNode()->yaw(Ogre::Degree (90));
                break;
                case LEFT:
                    entity->getNode()->yaw(Ogre::Degree (0));
                break;
                case RIGHT:
                    entity->getNode()->yaw(Ogre::Degree (180));
                break;
                default:
                break;
            }
            break;
            default:
            break;
        }
    }
    logMsg(func +" player Team Type == " +convert->toString(teamType));
//    logMsg(func +" directplayerWithBallID == " +convert->toString(playerWithBallID));
    logMsg(func +" directplayerID == " +convert->toString(data->getID()));
/*    if (data->getID() == playerWithBallID)
    {
//        exit(0);
        // FIXME! HARDCODED VALUES!
        activeBasketballInstance[0]->setDirectChange(true);
        activeBasketballInstance[0]->setDirection(direction);

        base->getGameS()->setActiveBasketballInstance(activeBasketballInstance);
    }
*/    
    //oldDirection = direction;
    //direction = NODIRECT;
    logMsg(func +" end");
//    exit(0);
}

void playerState::updateMovement()  // updates movement status of the player
{
    sharedPtr<conversion> convert = conversion::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
    teamStateUMSharedPtr activeTeamInstance = base->getGameS()->getActiveTeamInstance();
//    basketballStateVecSharedPtr bballInstance = getBasketballInstance();
    basketballStateUMSharedPtr activeBasketballInstance = base->getGameS()->getActiveBasketballInstance();
//    size_t activeBBallInstance = getActiveBBallInstance();
//    size_t playerWithBallID = activeTeamInstance[teamType]->getPlayerWithBallID();
    Ogre::Vector3 posChange;    // stores change in position
    posChange = Ogre::Vector3(0.0f, 0.0f, 0.0f);
    std::string func = "playerState::updateMovement()";
    
    logMsg(func +" beginning");
    logMsg(func +" playerTeamType == " +convert->toString(teamType));
    logMsg(func +" passSteal ==  " +convert->toString(passSteal));
    
    if (movement)   // if true sets coordinate change accordingly
    {
        logMsg(func +" movement!");
        exit(0);
        switch (direction)
        {
            case UP:
                posChange = Ogre::Vector3(0.0f, 0.0f, -0.400f);
                logMsg(func +" UP!");
//                exit(0);
            break;
            case DOWN:
                posChange = Ogre::Vector3(0.0f, 0.0f, 0.400f);
            break;
            case LEFT:
                posChange = Ogre::Vector3(-0.400f, 0.0f, 0.0f);
            break;
            case RIGHT:
                posChange = Ogre::Vector3(0.400f, 0.0f, 0.0f);
            break;
            case UPLEFT:
                posChange = Ogre::Vector3(-0.400f, 0.0f, -0.400f);
            break;
            case UPRIGHT:
                posChange = Ogre::Vector3(0.400f, 0.0f, -0.400f);
            break;
            case DOWNLEFT:
                posChange = Ogre::Vector3(-0.400f, 0.0f, 0.400f);
            break;
            case DOWNRIGHT:
                posChange = Ogre::Vector3(0.400f, 0.0f, 0.400f);
            break;
        }

/*        if (data->getID() == playerWithBallID)
        {
            // FIXME! HARDCODED VALUE
            activeBasketballInstance[0]->setMovement(true);
            base->getGameS()->setActiveBasketballInstance(activeBasketballInstance);

        }*/
    }
    else // if false then sets their coordinate changes to 0.0
    {
        logMsg(func +" No movement!");
        posChange = Ogre::Vector3(0.0f, 0.0f, 0.0f);
    }

    if (posChange.x != 0 || posChange.y != 0 || posChange.z != 0)
    {
        logMsg(func +" Setting newCourtPosition!");
        newCourtPosition = posChange;  // sets the newCourtPosition for current playerInstance
        courtPositionChanged = true;
        courtPositionChangedType = INPUTCHANGE;
        movement = false;
    }
    logMsg(func +" end");

//  exit(0);
}

void playerState::calculatePass()   // calculates which player to pass the ball to
{
    sharedPtr<conversion> convert = conversion::Instance();
    std::string func = "playerState::calculatepass()";

    logMsg(func +" beginning");
/*    logMsg("In calculatePass function");

    teamStateUMSharedPtr activeTeamInstance = getActiveTeamInstance();
    size_t teamWithBall = getTeamWithBall();
    playerPositions playerWithBallInstance = activeTeamInstance[teamWithBall]->getPlayerWithBallInstance();
    passToPlayer = playerWithBallInstance++;


    logMsg("Pass to player is now = " +convert->toString(passToPlayer));


    passCalculated = true;
//    logMsg("Player to pass to =   " +convert->toString(passToPlayer));
*/
//    exit(0);

    logMsg(func +" end");
}

void playerState::shotLogic(Ogre::Vector3 playerPos)
{
    /*S

    //    Ogre::Vector3 playerPos;
    std::vector<basketballs> basketballInstance = getBasketballInstance();
    playerStateVec pInstance = getPlayerInstance();

    // checks if a player has taken a shot
    if (getShotTaken())
    {

        basketballInstance[activeBBallInstance].setDribbling(false);
//          basketballInstance[activeBBallInstance].getNode()->setParent(mSceneMgr->getRootSceneNode());
        Ogre::Vector3 pos = basketballInstance[activeBBallInstance].getNode()->getPosition();
        basketballInstance[activeBBallInstance].setMaxHeight(pos[1] + 10.0f);
        basketballInstance[activeBBallInstance].setMinHeight(pos[1] - 10.0f);
        Ogre::Vector3 velocity;
        Ogre::Vector3 startCoords;
        startCoords[0] = playerPos[0] + 1.0f;
        startCoords[1] = playerPos[1] + 1.0f;
        startCoords[2] = playerPos[2] + 1.0f;
        velocity[0] = 0.90f;
        velocity[1] = 0.80f;
        velocity[2] = 0.0f;
        basketballInstance[activeBBallInstance].setVelocity(velocity);
        basketballInstance[activeBBallInstance].setStartCoords(startCoords);
        basketballInstance[activeBBallInstance].getNode()->setPosition(startCoords);
        setShotTaken(false);
        setShotComplete(false);
        basketballInstance[activeBBallInstance].setMaxHeightReached(false);
        basketballInstance[activeBBallInstance].setMinHeightReached(false);
    //      basketballInstance[activeBBallInstance].setPlayer(-1);
    }

    if (getShotComplete())
    {

        basketballInstance[activeBBallInstance].setPlayer(5);
        basketballInstance[activeBBallInstance].setDribblingStart(true);
        playerPos = pInstance[basketballInstance[activeBBallInstance].getPlayer()].getNode()->getPosition();
        basketballInstance[activeBBallInstance].getNode()->setPosition(playerPos[0] +2.0f, playerPos[1] + 4.0f, playerPos[2] - 1.0f);
        setShotComplete(false);
    }
*/
}
