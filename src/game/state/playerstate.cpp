/***************************************************************************
 *   Copyright (C) 1999 - 2016 by Mike McLean                              *
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
//#include "engine/physicsengine.h"
//#include "engine/renderengine.h"
//#include "ai/steering.h"
#include "ai/playersteer.h"
#include "state/basketballstate.h"
#include "state/courtstate.h"
#include "state/hoopstate.h"
//#include "state/gamestate.h"
#include "state/playerstate.h"
#include "state/teamstate.h"
#include "comparison.h"
//#include "jumpballs.h"

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
    passToPlayer = -1;
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

size_t playerState::getPassToPlayer()  // retrieves the value of passToPlayer
{
    return (passToPlayer);
}
void playerState::setPassToPlayer(size_t set)  // sets the value of passToPlayer
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

bool playerState::setup()  // initializes the state of the object
{
    
/*    playerSteerSharedPtr tempSteer(new playerSteer);
    setSteer(tempSteer);
    
    logMsg("steer->setTeamType(teamType);");
    
    getSteer()->setTeamType(teamType);
    logMsg("psteer->reset();");
    getSteer()->reset();
//    logMsg("pInstance->setSteer(playerSteerSharedPtr(pSteer);");

//    pInstance->setSteer(playerSteerSharedPtr(pSteer));
*/
    return (true);
}

void playerState::updateState()
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
///    boost::shared_ptr<physicsEngine> physEngine = physicsEngine::Instance();
    physicsEngine physEngine;
    jumpBallsSharedPtr jumpBall = getJumpBall();
    Ogre::Vector3 playerPos;

    if (getPhysicsSetup())
    {
        logMsg("playerState::updateState");
        updateCourtPosition();
//        exit(0);
    }

//    if (shotTaken && !shotComplete)  // checks if a player takes a shot

    
    if (shootBlock)
    {
        if (teamType == getTeamWithBall())
        {
//            shotLogic(playerPos);
//            exit(0);
            if (!shotTaken)
            {
                shotTaken = true;
            }
            shootBasketball(teamType, getID());

        }
        else
        {
            jump(teamType, getID());
        }
        
    }
    
    if (passSteal)
    {
        logMsg("passSteal!!");
        logMsg("passSteal teamType == " +convert->toString(teamType));
        logMsg("passSteal teamWithBall == " +convert->toString(getTeamWithBall()));
        
        if (teamType == getTeamWithBall())
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
    
    if (direction != NODIRECT)  // updates the direction the player is facing if it has changed
    {
        updateDirection();
        updateMovement();
        oldDirection = direction;
        std::unordered_map <size_t, teamStateSharedPtr> activeTeamInstance = getActiveTeamInstance();
        size_t playerWithBallID = activeTeamInstance[teamType]->getPlayerWithBallID();
        if (teamType == getTeamWithBall() && getTipOffComplete())
        {
            logMsg("dplayerWithBallID == " +convert->toString(playerWithBallID));
            if (getID() == playerWithBallID && getID() >= 0)
            {
                logMsg("playerID == " +convert->toString(getID()));
//                int activeBBallInstance = getActiveBBallInstance();
                std::unordered_map <size_t, basketballStateSharedPtr> activeBasketballInstance = getActiveBasketballInstance();
                
                //FIXME! HARDCODED VALUE!
                activeBasketballInstance[0]->setMovement(true);
                setActiveBasketballInstance(activeBasketballInstance);
//                exit(0);
            }
        }        
        direction = NODIRECT;
    }

}

bool playerState::updateCourtPosition()  // updates the XYZ coordinates of the 3D model
{
    logMsg("playerState::updateCourtPosition");

    boost::shared_ptr<conversion> convert = conversion::Instance();
    ///boost::shared_ptr<physicsEngine> physEngine = physicsEngine::Instance();
    physicsEngine physEngine;

        comparison compare;
    btVector3 physChange = btVector3(0,0,0);
    Ogre::Vector3 changePos = Ogre::Vector3(0,0,0);
    
    logMsg("updatePosChange == " +convert->toString(posChange));
    logMsg("newCourtPosition == " +convert->toString(newCourtPosition));
    if (courtPositionChanged)
    {
        
        switch (courtPositionChangedType)
        {
            case STARTCHANGE:
                getNode()->translate(newCourtPosition);
                physChange = BtOgre::Convert::toBullet(newCourtPosition);  // converts from Ogre::Vector3 to btVector3
                getPhysBody()->translate(physChange); // moves physics body in unison with the model
                getSteer()->setPosition(convert->toOpenSteerVec3(newCourtPosition));
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
                startPosReached = true;
                courtPosition = getNode()->getPosition();
                logMsg("start change,");
//                exit(0);
            break;
            
            case STEERCHANGE:
                //logMsg("Updating player court position based on steering");
                //logMsg("Team " +convert->toString(teamType) + " Player " +convert->toString(playerID));
                changePos = compare.OgreVector3ToOgreVector3Result(courtPosition, newCourtPosition);
                //logMsg("change playerCourtPosition = " +convert->toString(changePos));
                getNode()->translate(changePos);
                physChange = BtOgre::Convert::toBullet(changePos);  // converts from Ogre::Vector3 to btVector3
                getPhysBody()->translate(physChange); // moves physics body in unison with the model
                //exit(0);
                
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
                courtPosition = getNode()->getPosition();
            break;   

            case INPUTCHANGE:
                //logMsg("Updating court position based on input");
                getNode()->translate(newCourtPosition);
                physChange = BtOgre::Convert::toBullet(newCourtPosition);  // converts from Ogre::Vector3 to btVector3
                getPhysBody()->translate(physChange);  // moves physics body in unison with the model
                getSteer()->setPosition(convert->toOpenSteerVec3(newCourtPosition));
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
                //exit(0);
                courtPosition = getNode()->getPosition();
            break;

            case PHYSICSCHANGE:
                /*  I have disabled this code until I can fix the conflict with the steering code
                logMsg("Updating court position based on physics");
                logMsg("courtPosition = " +convert->toString(courtPosition));
                logMsg("newCourtPosition = " +convert->toString(newCourtPosition));
                node->translate(newCourtPosition);
                logMsg("node position updated");
                steer->setPosition(convert->toOpenSteerVec3(newCourtPosition));
                logMsg("steer position updated");
                */
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
                courtPosition = getNode()->getPosition();
                // exit(0);
            break;

            default:
            break;
        }
        ++posChangeAmount;
        logMsg("player ID " +convert->toString(getID()) +"change amount = " +convert->toString(posChangeAmount));
        
    }
    
/*    logMsg("posChange = " +convert->toString(posChange));
//  cout << "posChange = " << posChange << endl;
    node->translate(posChange);
    btVector3 change = btVector3(0,0,0);
    change = BtOgre::Convert::toBullet(posChange);  // converts from Ogre::Vector3 to btVector3
//  logMsg("playerPhysicsSetup = " +convert->toString(physEngine.getPlayerPhysicsSetup()));

    physBody->translate(change);  // moves physics body in unison with the model
//  exit(0);
//  physBody->translate(btVector3(0,0,0));
//  logMsg("player position updated.");
*/
    return true;
}


void playerState::updateDirection()
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
    std::unordered_map <size_t, teamStateSharedPtr> activeTeamInstance = getActiveTeamInstance();
    std::unordered_map <size_t, basketballStateSharedPtr> activeBasketballInstance = getActiveBasketballInstance();
//    size_t activeBBallInstance = getActiveBBallInstance();
    size_t playerWithBallID = activeTeamInstance[teamType]->getPlayerWithBallID();

    if (direction != oldDirection)
    {
            
        switch (oldDirection)
        {
            case UP:
                switch (direction)
                {
                    case DOWN:
                        getNode()->yaw(Ogre::Degree (180));
                    break;
                    case LEFT:
                        getNode()->yaw(Ogre::Degree (270));
                    break;
                    case RIGHT:
                        getNode()->yaw(Ogre::Degree (90));
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
                        getNode()->yaw(Ogre::Degree (180));
                    break;
                    case LEFT:
                        getNode()->yaw(Ogre::Degree (90));
                    break;
                    case RIGHT:
                        getNode()->yaw(Ogre::Degree (270));
                    break;
                    default:
                    break;
                }
            break;
            case LEFT:
                switch (direction)
                {
                    case UP:
                        getNode()->yaw(Ogre::Degree (90));
                    break;
                    case DOWN:
                        getNode()->yaw(Ogre::Degree (270));
                    break;
                    case RIGHT:
                        getNode()->yaw(Ogre::Degree (180));
                    break;
                    default:
                    break;
                }
            break;
            case RIGHT:
                switch (direction)
                {
                    case UP:
                        getNode()->yaw(Ogre::Degree (270));
                    break;
                    case DOWN:
                        getNode()->yaw(Ogre::Degree (90));
                    break;
                    case LEFT:
                        getNode()->yaw(Ogre::Degree (180));
                    break;
                    default:
                    break;
                }
            break;
            case NODIRECT:
            switch (direction)
            {
                case UP:
                    getNode()->yaw(Ogre::Degree (270));
                break;
                case DOWN:
                    getNode()->yaw(Ogre::Degree (90));
                break;
                case LEFT:
                    getNode()->yaw(Ogre::Degree (0));
                break;
                case RIGHT:
                    getNode()->yaw(Ogre::Degree (180));
                break;
                default:
                break;
            }
            break;
            default:
            break;
        }
    }
    logMsg("player Team Type == " +convert->toString(teamType));
    logMsg("directplayerWithBallID == " +convert->toString(playerWithBallID));
    logMsg("directplayerID == " +convert->toString(getID()));
    if (getID() == playerWithBallID)
    {
//        exit(0);
        // FIXME! HARDCODED VALUES!
        activeBasketballInstance[0]->setDirectChange(true);
        activeBasketballInstance[0]->setDirection(direction);

        setActiveBasketballInstance(activeBasketballInstance);
    }
    //oldDirection = direction;
    //direction = NODIRECT;

}

void playerState::updateMovement()  // updates movement status of the player
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
    std::unordered_map <size_t, teamStateSharedPtr> activeTeamInstance = getActiveTeamInstance();
//    basketballStateVecSharedPtr bballInstance = getBasketballInstance();
    std::unordered_map <size_t, basketballStateSharedPtr> activeBasketballInstance = getActiveBasketballInstance();
//    size_t activeBBallInstance = getActiveBBallInstance();
    size_t playerWithBallID = activeTeamInstance[teamType]->getPlayerWithBallID();

    Ogre::Vector3 posChange;    // stores change in position
    posChange = Ogre::Vector3(0.0f, 0.0f, 0.0f);

    logMsg("playerTeamType == " +convert->toString(teamType));
    logMsg("passSteal ==  " +convert->toString(passSteal));

    if (movement)   // if true sets coordinate change accordingly
    {
//        exit(0);
        switch (direction)
        {
            case UP:
                posChange = Ogre::Vector3(0.0f, 0.0f, -0.400f);
                logMsg("UP!");
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

        if (getID() == playerWithBallID)
        {
            // FIXME! HARDCODED VALUE
            activeBasketballInstance[0]->setMovement(true);
            setActiveBasketballInstance(activeBasketballInstance);

        }
    }
    else if (!movement)  // if false then sets their coordinate changes to 0.0
    {
        posChange = Ogre::Vector3(0.0f, 0.0f, 0.0f);
    }

    if (posChange.x != 0 || posChange.y != 0 || posChange.z != 0)
    {
        newCourtPosition = posChange;  // sets the newCourtPosition for current playerInstance
        courtPositionChanged = true;
        courtPositionChangedType = INPUTCHANGE;
        movement = false;
    }

//  exit(0);
}

void playerState::calculatePass()   // calculates which player to pass the ball to
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
    
    logMsg("In calculatePass function");

    std::unordered_map <size_t, teamStateSharedPtr> activeTeamInstance = getActiveTeamInstance();
    size_t teamWithBall = getTeamWithBall();
    size_t playerWithBallInstance = activeTeamInstance[teamWithBall]->getPlayerWithBallInstance();
//    if (playerWithBall < 5)  // checks if the player belongs to the first team
//    {
        if (playerWithBallInstance +1 < 5)  // checks if the player + 1 is still on the first team
        {
            passToPlayer = playerWithBallInstance +1;
        }
        else
        {
            passToPlayer = 0;
        }
        
//        }
/*
    else if (playerWithBall > 4)  // checks if the player belongs to the second team
    {
        if (playerWithBall + 1 < 10)  // checks if the player + 1 is still on the second team
        {
            passToPlayer = playerWithBall +1;
        }
        else
        {
            passToPlayer = 5;
        }
    }
    else
    {
    }
*/

    logMsg("Pass to player is now = " +convert->toString(passToPlayer));


    passCalculated = true;
//    logMsg("Player to pass to =   " +convert->toString(passToPlayer));

//    exit(0);
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
