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

#include "jumpballs/jumpballsexecute.h"
#include "jumpballs/jumpballs.h"
#include "components/basketballcomponents.h"
#include "components/gamecomponents.h"
#include "components/playercomponents.h"
#include "components/teamcomponents.h"
#include "data/playerdata.h"
#include "data/playergamedata.h"
#include "engine/physicsengine.h"
#include "entity/basketballentity.h"
#include "entity/playerentity.h"
#include "entity/teamentity.h"
#include "flags/playerflags.h"
#include "physics/basketballphysics.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

jumpBallsExecute::jumpBallsExecute() = default;  // constructor

jumpBallsExecute::~jumpBallsExecute() = default;  // destructor

bool jumpBallsExecute::executeJump(const gameComponentsSharedPtr &component)  // initiates jump ball from jump ball circle
{
    conversionSharedPtr convert ;
    jumpBallsSharedPtr jumpBall = component->getJumpBall();
#ifdef BTOGRE_MYGUI_ENABLED
    physicsEngine physEngine;
#endif

    playerEntityMSharedPtr activePlayerInstance;
    playerEntityMSharedPtr jumpPlayerInstance;  // stores playerID of players jumping for the ball
    teamEntityMSharedPtr activeTeamInstance = component->getActiveTeamInstance();
    teamTypes ballTippedToTeam = jumpBall->getBallTippedToTeam();
    playerPositions ballTippedToPosition = jumpBall->getBallTippedToPosition();
    bool retVal = false;
    size_t x = 0;
    std::string func = "jumpBalls::jumpBallExecute()";
    
    logMsg (func +" begin");
    
    logMsg (func +" activeTeamInstance.size() == " +convert->toString(activeTeamInstance.size()));
    for (auto ATIIT : activeTeamInstance)
    {
        activePlayerInstance.clear();
        activePlayerInstance = ATIIT.second->getComponent()->getActivePlayerInstance();
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
            if (APIIT.second->getGameData()->getActivePosition() == C)
            {
                logMsg(func +" jumpPlayerInstance = " +convert->toString(APIIT.first));
                 // logMsg("PlayerName = " +activePlayerInstance[x][i].getPlayerName());
                logMsg(func +" ModelLoaded = " +convert->toString(APIIT.second->getFlag()->getModelLoaded()));
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
//    playerStateSharedPtr activePInstance;
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
        retVal = true;
    }
    else
    {
//        exit(0);
    }
    //        exit(0);
    logMsg(func +" Execute ballTippedToTeam == " +convert->toString(ballTippedToTeam));
    logMsg(func +" Execute ballTippedToPosition == " +convert->toString(ballTippedToPosition));
    
    logMsg (func +" begin");
    return (retVal);  // executeJumpBall has not completed
}

bool jumpBallsExecute::tipToPlayer(const gameComponentsSharedPtr &component, quarters quarter)  // tips the basketball to the appropriate player
{
    bool retVal = false;  // stores the return value

#ifdef BTOGRE_MYGUI_ENABLED

//    sharedPtr<gameState> gameS = gameState::Instance();
    conversionSharedPtr convert ;
//    sharedPtr<physicsEngine> physEngine = physicsEngine::Instance();
    jumpBallsSharedPtr jumpBall = component->getJumpBall();
    physicsEngine physEngine;

//    basketballStateVec basketballInstance = gameS->getBasketballInstance();
//    teamStateVecSharedPtr activeTeamInstance = gameS->getActiveTeamInstance();
//    playerStateVecSharedPtr activePlayerInstance;
    playerEntityVecSharedPtr activePlayerInstance;
    playerEntityVecSharedPtr::iterator APIIT;
    playerPositions ballTippedToPosition = jumpBall->getBallTippedToPosition();
    size_t ballTippedToPlayerID = jumpBall->getBallTippedToPlayerID();
    bool ballTipForceApplied = jumpBall->getBallTipForceApplied();
    teamTypes ballTippedToTeam = jumpBall->getBallTippedToTeam();
    btVector3 bballVelocity = jumpBall->getBBallVelocity();
    size_t ballTippedToPlayerInstance = jumpBall->getBallTippedToPlayerInstance();
    basketballEntityMSharedPtr activeBasketballInstance = component->getActiveBasketballInstance();
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
        if (APIIT->getGameData()->getActivePosition() == ballTippedToPosition)
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
            if (physEngine.collisionCheck(activeBasketballInstance[0]->getComponent()->getPhysics()->getPhysBody(), activePlayerInstance[ballTippedToPlayerInstance].getComponent()->getPhysics()->getPhysBody()))
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

                retVal = true;
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
#endif

    return (retVal);  // tipToPlayer has not completed
}
