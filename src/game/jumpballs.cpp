/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
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
#include "data/playerdata.h"
#include "entity/basketballentity.h"
#include "entity/playerentity.h"
#include "physics/basketballphysics.h"
#include "state/basketballstate.h"
//#include "state/gamestate.h"
#include "state/courtstate.h"
#include "state/hoopstate.h"
#include "state/teamstate.h"
#include "state/playerstate.h"
#include "utilities/comparison.h"
#include "utilities/logging.h"
#include "engine/physicsengine.h"
#include "jumpballs.h"

// static declarations
jumpBallLocations_t jumpBalls::jumpBallLocation;  // sets where the jump ball is to be held
playerPositionsVec jumpBalls::jumpBallPlayer;  // stores which two players will be jumping for the ball
bool jumpBalls::ballTipped;  // stores whether or not the ball has been tipped
bool jumpBalls::ballTipForceApplied;// stores whether or not force has been applied to tipped ball
bool jumpBalls::playerHasBasketball;  // stores whether or not a player has control of the basketball
teamTypes jumpBalls::ballTippedToTeam;  //  stores which team the ball has been tipped to
size_t jumpBalls::ballTippedToPlayerID;  // stores which player ID the ball has been tipped to
size_t jumpBalls::ballTippedToPlayerInstance;  // stores which player instance the ball has been tipped to
playerPositions jumpBalls::ballTippedToPosition;  // stores position that the ball is tipped to
bool jumpBalls::jumpBalls::setupComplete;  // stores whether a jumpBall scenario has been setup.l
bool jumpBalls::jumpBallComplete;  // jump ball code has completed and a player is in control of the baskteball
bool jumpBalls::executeJumpBall;  // stores whether or not to execute the jump ball sequence
btVector3 jumpBalls::bballVelocity;  // stores the velocity of the basketball

jumpBalls::jumpBalls()  // constructor
{
    ballTipped = false;
    ballTippedToTeam = NOTEAM;
    ballTippedToPlayerID = 9999;
    ballTippedToPlayerInstance = 9999;
    ballTippedToPosition = NONE;
    ballTipForceApplied = false;
    setupComplete = false;
    executeJumpBall = false;
    jumpBallComplete = false;
	jumpBallLocation = NOLOCATION;
	playerHasBasketball = false;
    
}

jumpBallLocations_t jumpBalls::getJumpBallLocation()  // retrieves teh value of jumpBallLocation
{
    return (jumpBallLocation);
}
void jumpBalls::setJumpBallLocation(jumpBallLocations_t set)  // sets the value of jumpBallLocation
{
    jumpBallLocation = set;
}

playerPositionsVec jumpBalls::getJumpBallPlayer()  // retrieves the value of jumpBallPlayer
{
    return (jumpBallPlayer);
}
void jumpBalls::setJumpBallPlayer(playerPositionsVec set)  // sets the value of jumpBallPlayer
{
    jumpBallPlayer = set;
}

bool jumpBalls::getBallTipped()	 // retrieves the value of ballTipped
{
    return (ballTipped);
}
void jumpBalls::setBallTipped(bool tipped)  // sets the value of ballTipped
{
    ballTipped = tipped;
}

teamTypes jumpBalls::getBallTippedToTeam()  // retrieves the value of ballTippedToTeam
{
    return (ballTippedToTeam);
}
void jumpBalls::setBallTippedToTeam(teamTypes set)  // sets the value of ballTippedToTeam
{
    ballTippedToTeam = set;
}

size_t jumpBalls::getBallTippedToPlayerID()  // retrieves the value of ballTippedToPlayerID
{
    return (ballTippedToPlayerID);
}
void jumpBalls::setBallTippedToPlayerID(size_t player)	 // sets the value of ballTippedToPlayerID
{
    ballTippedToPlayerID = player;
}

playerPositions jumpBalls::getBallTippedToPosition()  // retrieves the value of ballTippedToPosition
{
    return (ballTippedToPosition);
}
void jumpBalls::setBallTippedToPosition(playerPositions set)  // sets the value of ballTippedToPosition
{
    ballTippedToPosition = set;
}

bool jumpBalls::getBallTipForceApplied()  // retrieves the value of ballTipForceApplied
{
    return (ballTipForceApplied);
}
void jumpBalls::setBallTipForceApplied(bool tip)  // sets the value of ballTipForceApplied
{
    ballTipForceApplied = tip;
}

bool jumpBalls::getSetupComplete()  // retrieves the value of setup
{
    return (setupComplete);
}
void jumpBalls::setSetupComplete(bool set)  // sets the value of setup
{
    setupComplete = set;
}

bool jumpBalls::getExecuteJumpBall()  // retrieves the value of executeJumpBall
{
    return (executeJumpBall);
}
void jumpBalls::setExecuteJumpBall(bool set)  // sets the value of executeJumpBall
{
    executeJumpBall = set;
}

btVector3 jumpBalls::getBBallVelocity()  // retrieves the value of bballVelocity
{
    return (bballVelocity);
}
void jumpBalls::setBBallVelocity(const btVector3 &set)  // sets the value of bballVelocity
{
    bballVelocity = set;
}

bool jumpBalls::updateState(teamTypes teamWithBall, basketballStateMSharedPtr activeBasketballInstance, teamStateMSharedPtr activeTeamInstance, quarters quarter)  // updates state of the jumpBalls instance
{
//    sharedPtr<gameState> gameS = gameState::Instance();
    conversionSharedPtr convert = conversion::Instance();
    std::string func = "jumpBalls::updateState()";
    
    logMsg(func +" updating jumpBall state!");
    logMsg(func +" teamWithBall == " +convert->toString(teamWithBall));

//    size_t activeBBallInstance = gameS->getActiveBBallInstance();
//    basketballStateVec basketBallInstance = gameS->getBasketballInstance();
   // FIXME! Do NOT hard code activeBasketballInstance in the future
    bool bballPhysicsSetup = activeBasketballInstance[0]->getEntity()->getPhysicsSetup();
    if (teamWithBall == NOTEAM && bballPhysicsSetup) //&& gameS->getActiveTeamInstancesCreated())
    {

        logMsg(func +" teamWithBall = NOTEAM");
//        exit(0);
        logMsg(func +" jumpBallComplete == " +convert->toString(jumpBallComplete));
        if (!jumpBallComplete)
        {
//            exit(0);
            logMsg(func +" jump ball not complete");
            logMsg(func +" not complete ballTipped == " +convert->toString(ballTipped));
            
//            tipoff complete!exit(0);
            if (!ballTipped)
            {
                ballTipped = jumpBallExecute(activeBasketballInstance, activeTeamInstance);  // executes jump ball until ball is tipped
                logMsg (func +" Ball Tippped? " +convert->toString(ballTipped));
//                exit(0);
            }
            else
            {
//                exit(0);
                jumpBallComplete = tipToPlayer(activeBasketballInstance, activeTeamInstance, quarter);

                logMsg(func +" jumpBallComplete == " +convert->toString(jumpBallComplete));
//                exit(0);
            }
//            exit(0);
        }
        else
        {
            logMsg(func +" teamWithBall = " +convert->toString(teamWithBall));
//            exit(0);
        }
        logMsg(func +" ballTipped == " +convert->toString(ballTipped));
        logMsg(func +" ballTippedToTeam == " +convert->toString(ballTippedToTeam));
    }
    else
    {
        logMsg(func +" teamWithBall == " +convert->toString(teamWithBall));
        return (true);
    }
    
    logMsg(func +" jumpBall return(false)");
    
    return (false);  // returns false until jump ball has com=pleted
}

bool jumpBalls::jumpBallExecute(basketballStateMSharedPtr activeBasketballInstance, teamStateMSharedPtr activeTeamInstance)  // initiates jump ball from jump ball circle
{
//    exit(0);
    conversionSharedPtr convert = conversion::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
///    sharedPtr<physicsEngine> physEngine = physicsEngine::Instance();
    physicsEngine physEngine;
//    basketballStateVec basketballInstance = gameS->getBasketballInstance();
//    size_t activeBBallInstance = gameS->getActiveBBallInstance();

//    teamStateVecSharedPtr activeTeamInstance = gameS->getActiveTeamInstance();
//    std::unordered_map<std::string, playerStateSharedPtr> activePlayerInstance;
//    std::unordered_map<std::string, playerStateSharedPtr> jumpPlayerInstance;  // stores playerID of players jumping for the ball
    playerEntityMSharedPtr activePlayerInstance;
    playerEntityMSharedPtr jumpPlayerInstance;  // stores playerID of players jumping for the ball

    size_t x = 0;
    std::string func = "jumpBalls::jumpBallExecute()";
    
    logMsg (func +" beginning");
    
    logMsg (func +" activeTeamInstance.size() == " +convert->toString(activeTeamInstance.size()));
    for (auto ATIIT : activeTeamInstance)
    {
        activePlayerInstance.clear();
        activePlayerInstance = ATIIT.second->getActivePlayerInstance();
//TS        activePlayerInstance.push_back(activeTeamInstance[x]->getActivePlayerInstance());
//        activePlayerInstance->( activeTeamInstance[x]->getActivePlayerInstance();
        
        size_t i = 0;
        logMsg(func +" ATIIT");
        logMsg(func +" active player instance size = " +convert->toString(activePlayerInstance.size()));
//        while (i < activePlayerInstance[x].size()) // loops until the activePlayerInstance is found that is currently playing center
        for (auto APIIT : activePlayerInstance)
        {
            
//            exit(0);
            logMsg(func +" jump i == " +convert->toString(APIIT.first));
            if (APIIT.second->getActivePosition() == C)
            {
                logMsg(func +" jumpPlayerInstance = " +convert->toString(APIIT.first));
                 // logMsg("PlayerName = " +activePlayerInstance[x][i].getPlayerName());
                logMsg(func +" ModelLoaded = " +convert->toString(APIIT.second->getModelLoaded()));
    //                    exit(0);
                //jumpPlayerID.push_back(activePlayerInstance[i].getPlayerID());
                jumpPlayerInstance.insert(std::pair<size_t, playerEntitySharedPtr>(APIIT.first, APIIT.second));
            }
            else
            {
            }
//            i++;
              //teamTypes teamType = activeTeamInstance[x].getTeamType();
                //size_t player = 4;
                //bool collCheck = collisionCheck(basketballInstance[activeBBallInstance].getPhysBody(), activePlayerInstance[centerID].getPhysBody());
                //logMsg("Team " +convert->toString(teamType) +" player " +convert->toString(player) +" collCheck == " +convert->toString(collCheck));
        }
//        ++x;
    }
//    exit(0);
    logMsg(func +" jumpPlayerID.size() = " +convert->toString(jumpPlayerInstance.size()));
//    exit(0);
//    teamTypes teamType = activeTeamInstance[0].getTeamType();
    bool collCheck = false;
//    collCheck = /*physEngine.*/ collisionCheck(basketballInstance[activeBBallInstance].getPhysBody(), activePlayerInstance[0][jumpPlayerInstance[0]].getPhysBody());
//    size_t y = 0;
    playerStateSharedPtr activePInstance;
    for (auto ATIIT : activeTeamInstance)
    {
/*TS        switch(ATIIT.second->getTeamType())
        {
            case HOMETEAM:
                activePInstance = activePlayerInstance[0][jumpPlayerInstance[0]];
            break;
            case AWAYTEAM:
                activePInstance = activePlayerInstance[1][jumpPlayerInstance[1]];
            break;
            default:
            break;
        }
//        exit(0);
        logMsg("active basketball instance == " +convert->toString(activeBBallInstance));
        logMsg("bball physics setup complete == " +convert->toString(basketballInstance[activeBBallInstance]->getPhysicsSetup()));
        logMsg("bball physbody isinworld == " +convert->toString(basketballInstance[activeBBallInstance]->getPhysBody()->isInWorld()));
        logMsg("player physics setup complete == " +convert->toString(activePInstance->getPhysicsSetup()));
//        exit(0);
        if (physEngine.collisionCheck(basketballInstance[activeBBallInstance]->getPhysBody().get(), activePInstance->getPhysBody().get()))
        {
            logMsg("team " +convert->toString(y) +" center collided with ball");
            ballTippedToTeam = ATIIT.second->getTeamType();
            ballTippedToPosition = PG;
//            exit(0);
        
        }
        else
        {
        
        }
TS*/
/*        logMsg("Team " +convert->toString(teamType) +" playerInstance " +convert->toString(jumpPlayerInstance[0]) +" collCheck == " +convert->toString(collCheck));
        teamType = activeTeamInstance[1].getTeamType();
        collCheck = physEngine.collisionCheck(basketballInstance[activeBBallInstance].getPhysBody(), activePlayerInstance[1][jumpPlayerInstance[1]].getPhysBody());
        if (collCheck)
        {
            logMsg("team 1 center collided with ball");
            ballTippedToTeam = AWAYTEAM;
            ballTippedToPosition = PG;
        }
        else
        {
        
        }*/
//        ++y;
    }
//    logMsg("Team " +convert->toString(teamType) +" playerInstance " +convert->toString(jumpPlayerInstance[1]) +" collCheck == " +convert->toString(collCheck));

    if (ballTippedToTeam != NOTEAM)
    {
//        exit(0);
        return (true);
    }
    else
    {
//        exit(0);
    }
    //        exit(0);
    logMsg(func +" Execute ballTippedToTeam == " +convert->toString(ballTippedToTeam));
    logMsg(func +" Execute ballTippedToPosition == " +convert->toString(ballTippedToPosition));
    
    logMsg (func +" beginning");
    return (false);  // executeJumpBall has not completed
}

bool jumpBalls::tipToPlayer(basketballStateMSharedPtr activeBasketballInstance, teamStateMSharedPtr activeTeamInstance, quarters quarter)  // tips the basketball to the appropriate player
{
//    sharedPtr<gameState> gameS = gameState::Instance();
    conversionSharedPtr convert = conversion::Instance();
//    sharedPtr<physicsEngine> physEngine = physicsEngine::Instance();

    physicsEngine physEngine;
//    basketballStateVec basketballInstance = gameS->getBasketballInstance();
//    teamStateVecSharedPtr activeTeamInstance = gameS->getActiveTeamInstance();
//    playerStateVecSharedPtr activePlayerInstance;
    playerEntityVecSharedPtr activePlayerInstance;
    playerEntityVecSharedPtr::iterator APIIT;
//    jumpBalls jumpBall = gameS->getJumpBall();
//    teamTypes ballTippedToTeam = jumpBall.getBallTippedToTeam();
//    quarters quarter = gameS->getQuarter();
//    size_t activeBBallInstance = gameS->getActiveBBallInstance();

//TS    activePlayerInstance = activeTeamInstance[ballTippedToTeam]->getActivePlayerInstance();
    
    auto y = 0;
//    while (y < activePlayerInstance.size())
//    playerStateVecSharedPtr::iterator APIIT;
//    for (APIIT = activePlayerInstance.begin(); APIIT != activePlayerInstance.end(); ++APIIT)
    for (APIIT = activePlayerInstance.begin(); APIIT != activePlayerInstance.end(); ++APIIT)
    {
        if (APIIT->getActivePosition() == ballTippedToPosition)
        {
            ballTippedToPlayerID = APIIT->getData()->getID();
//FIXME!            ballTippedToPlayerInstance = *APIIT->;
            break;
        }
        ++y;
    }

    if (!ballTipForceApplied)
    {
        if (ballTippedToTeam != NOTEAM)
        {
//            exit(0);
        }
        switch (quarter)
        {
            case FIRST:
            case SECOND:
                logMsg("jump First/Second quarter");
                logMsg("quarter ballTippedToTeam == " +convert->toString(ballTippedToTeam));
//                    exit(0);
                switch (ballTippedToTeam)
                {
                    case HOMETEAM:
                        bballVelocity.setX(20);
                        bballVelocity.setY(-1);
                        bballVelocity.setZ(0);
                        logMsg("jump HOMETEAM bballVelocity == " +convert->toString(bballVelocity));
//                        exit(0);
//                        return (true);
                    break;
                    case AWAYTEAM:
                        bballVelocity.setX(-20);
                        bballVelocity.setY(-1);
                        bballVelocity.setZ(0);
                        logMsg("jump AWAYTEAM bballVelocity == " +convert->toString(bballVelocity));
//                        return (true);
                    break;
                    default:
                    break;
                }
            break;
            case THIRD:
            case FOURTH:
                logMsg("jump Third/Fourth quarter");
                switch (ballTippedToTeam)
                {
                    case HOMETEAM:
                        bballVelocity.setX(-20);
                        bballVelocity.setY(-1);
                        bballVelocity.setZ(0);
//                        return (true);
                    break;
                    case AWAYTEAM:
                        bballVelocity.setX(20);
                        bballVelocity.setY(-1);
                        bballVelocity.setZ(0);
//                        return (true);
                    break;
                    default:
                    break;
                }
            break;
            default:
            break;
        }
        if (bballVelocity.getX() != 0 || bballVelocity.getY() != 0 || bballVelocity.getZ() != 0)
        {
            // FIXME! NEEDS moved to basketball physics code!
///            physEngine.setBasketballVelocity(bballVelocity);
///            physEngine.setBasketballVelocitySet(true);
            ballTipForceApplied = true;
//            exit(0);
        }
        else
        {
        }
    }
    else
    {
        logMsg("ballTipForceApplied!");
        if (ballTippedToPlayerInstance != 9999)
        {
            logMsg("ballTippedToPlayerInstance == " +convert->toString(ballTippedToPlayerInstance));

            // FIXME! Do NOT hardcode activeBasketballInstance
            if (physEngine.collisionCheck(activeBasketballInstance[0]->getEntity()->getPhysics()->getPhysBody(), activePlayerInstance[ballTippedToPlayerInstance].getPhysics()->getPhysBody()))
            {
 //               exit(0);
///                gameS->setTeamWithBall(ballTippedToTeam);
                logMsg("ballTippedToPlayerID == " +convert->toString(ballTippedToPlayerID));
/*TS                activeTeamInstance[ballTippedToTeam]->setPlayerWithBallID(ballTippedToPlayerID);
                activeTeamInstance[ballTippedToTeam]->setPlayerWithBallInstance(ballTippedToPlayerInstance);
                physEngine.setBasketballVelocitySet(false);
                activeTeamInstance[ballTippedToTeam]->setPlayerWithBallDribbling(true);
                if (activeTeamInstance[ballTippedToTeam]->getHumanControlled())
                {
                    activeTeamInstance[ballTippedToTeam]->setHumanPlayer(ballTippedToPlayerID);
                    logMsg("ball tipped to human playerID == " +convert->toString(ballTippedToPlayerID));
        //            exit(0);
                }
                logMsg("jumpBall.getBallTippedToPlayer() = " +convert->toString(ballTippedToPlayerID));
                logMsg("playerWithBallInstanceTipped == " +convert->toString(activeTeamInstance[ballTippedToTeam]->getPlayerWithBallInstance()));
                int activeDefensivePlayer = 9999;
                switch (ballTippedToTeam)
                {
                    case 0:
                        activeDefensivePlayer = activeTeamInstance[1]->getActivePlayerID()[0];
                        activeTeamInstance[AWAYTEAM]->setHumanPlayer(activeDefensivePlayer);
                    break;
                    case 1:
                        activeDefensivePlayer = activeTeamInstance[0]->getActivePlayerID()[0];
                        activeTeamInstance[HOMETEAM]->setHumanPlayer(activeDefensivePlayer);
                    break;
                    default:
                    break;
                }
TS*/
///                gameS->setActiveTeamInstance(activeTeamInstance);

                return(true);
            }
            else
            {
            }
//            exit(0);
        }
        else
        {
        }
//        exit(0);
    }
 
    logMsg("jump bballVelocity == " +convert->toString(bballVelocity));
    return (false);  // tipToPlayer has not completed
}
