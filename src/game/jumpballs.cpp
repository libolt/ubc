/***************************************************************************
 *   Copyright (C) 1999 - 2016 by Mike McLean                              *
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

#include "conversion.h"
#include "state/basketballstate.h"
//#include "state/gamestate.h"
#include "state/courtstate.h"
#include "state/hoopstate.h"
#include "state/teamstate.h"
#include "state/playerstate.h"
#include "comparison.h"
#include "logging.h"
#include "engine/physicsengine.h"
#include "jumpballs.h"

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

bool jumpBalls::updateState(teamTypes teamWithBall, size_t activeBBallInstance, basketballStateVecSharedPtr basketballInstance, teamStateVecSharedPtr activeTeamInstance, quarters quarter)  // updates state of the jumpBalls instance
{
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    logMsg("updating jumpBall state!");
    logMsg("teamWithBall == " +convert->toString(teamWithBall));

//    size_t activeBBallInstance = gameS->getActiveBBallInstance();
//    basketballStateVec basketBallInstance = gameS->getBasketballInstance();
    bool bballPhysicsSetup = basketballInstance[activeBBallInstance]->getPhysicsSetup();
    if (teamWithBall == NOTEAM && bballPhysicsSetup) //&& gameS->getActiveTeamInstancesCreated())
    {

        logMsg("teamWithBall = NOTEAM");
//        exit(0);
        logMsg("jumpBallComplete == " +convert->toString(jumpBallComplete));
        if (!jumpBallComplete)
        {
//            exit(0);
            logMsg("jump ball not complete");
            logMsg("not complete ballTipped == " +convert->toString(ballTipped));
//            tipoff complete!exit(0);
            if (!ballTipped)
            {
                ballTipped = jumpBallExecute(basketballInstance, activeBBallInstance, activeTeamInstance);  // executes jump ball until ball is tipped
                logMsg ("Ball Tippped? " +convert->toString(ballTipped));
//                exit(0);
            }
            else
            {
//                exit(0);
                jumpBallComplete = tipToPlayer(basketballInstance, activeBBallInstance, activeTeamInstance, quarter);

                logMsg("jumpBallComplete == " +convert->toString(jumpBallComplete));
//                exit(0);
            }
        }
        else
        {
            logMsg("teamWithBall = " +convert->toString(teamWithBall));
//            exit(0);
        }
        logMsg("ballTipped == " +convert->toString(ballTipped));
        logMsg("ballTippedToTeam == " +convert->toString(ballTippedToTeam));
    }
    else
    {
        logMsg("teamWithBall == " +convert->toString(teamWithBall));
        return (true);
    }
    
    logMsg("jumpBall return(false)");
    return (false);  // returns false until jump ball has completed
}

bool jumpBalls::jumpBallExecute(basketballStateVecSharedPtr basketballInstance, size_t activeBBallInstance, teamStateVecSharedPtr activeTeamInstance)  // initiates jump ball from jump ball circle
{
//    exit(0);
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
///    boost::shared_ptr<physicsEngine> physEngine = physicsEngine::Instance();
    physicsEngine physEngine;
//    basketballStateVec basketballInstance = gameS->getBasketballInstance();
//    size_t activeBBallInstance = gameS->getActiveBBallInstance();

//    teamStateVecSharedPtr activeTeamInstance = gameS->getActiveTeamInstance();
    std::vector<std::map <size_t, playerStateSharedPtr> > activePlayerInstance;

    sizeTVec jumpPlayerInstance;  // stores playerID of players jumping for the ball
    
    size_t x = 0;
    while (x < activeTeamInstance.size())
    {
        //activePlayerInstance.clear();
//TS        activePlayerInstance.push_back(activeTeamInstance[x]->getActivePlayerInstance());
//        activePlayerInstance->( activeTeamInstance[x]->getActivePlayerInstance();
        
        size_t i = 0;
        logMsg("active player instance size =" +convert->toString(activePlayerInstance[x].size()));
        while (i < activePlayerInstance[x].size()) // loops until the activePlayerInstance is found that is currently playing center
        {
            
//            exit(0);
            logMsg("jump i == " +convert->toString(i));
            if (activePlayerInstance[x][i]->getActivePosition() == C)
            {
                logMsg("jumpPlayerInstance = " +convert->toString(i));
                 // logMsg("PlayerName = " +activePlayerInstance[x][i].getPlayerName());
                logMsg("ModelLoaded = " +convert->toString(activePlayerInstance[x][i]->getModelLoaded()));
    //                    exit(0);
                //jumpPlayerID.push_back(activePlayerInstance[i].getPlayerID());
                jumpPlayerInstance.push_back(i);
            }
            else
            {
            }
            i++;
              //teamTypes teamType = activeTeamInstance[x].getTeamType();
                //size_t player = 4;
                //bool collCheck = collisionCheck(basketballInstance[activeBBallInstance].getPhysBody(), activePlayerInstance[centerID].getPhysBody());
                //logMsg("Team " +convert->toString(teamType) +" player " +convert->toString(player) +" collCheck == " +convert->toString(collCheck));
        }
        ++x;
    }
//    exit(0);
    logMsg("jumpPlayerID.size() = " +convert->toString(jumpPlayerInstance.size()));
//    exit(0);
//    teamTypes teamType = activeTeamInstance[0].getTeamType();
    bool collCheck = false;
//    collCheck = /*physEngine.*/ collisionCheck(basketballInstance[activeBBallInstance].getPhysBody(), activePlayerInstance[0][jumpPlayerInstance[0]].getPhysBody());
    size_t y = 0;
    boost::shared_ptr<playerState> activePInstance;
    while (y < activeTeamInstance.size())
    {
/*TS        switch(activeTeamInstance[y]->getTeamType())
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
            ballTippedToTeam = activeTeamInstance[y]->getTeamType();
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
        ++y;
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
    logMsg("Execute ballTippedToTeam == " +convert->toString(ballTippedToTeam));
    logMsg("Execute ballTippedToPosition == " +convert->toString(ballTippedToPosition));
    return (false);  // executeJumpBall has not completed
}

bool jumpBalls::tipToPlayer(basketballStateVecSharedPtr basketballInstance, size_t activeBBallInstance, teamStateVecSharedPtr activeTeamInstance, quarters quarter)  // tips the basketball to the appropriate player
{
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<physicsEngine> physEngine = physicsEngine::Instance();

    physicsEngine physEngine;
//    basketballStateVec basketballInstance = gameS->getBasketballInstance();
//    teamStateVecSharedPtr activeTeamInstance = gameS->getActiveTeamInstance();
    playerStateVecSharedPtr activePlayerInstance;
//    jumpBalls jumpBall = gameS->getJumpBall();
//    teamTypes ballTippedToTeam = jumpBall.getBallTippedToTeam();
//    quarters quarter = gameS->getQuarter();
//    size_t activeBBallInstance = gameS->getActiveBBallInstance();

//TS    activePlayerInstance = activeTeamInstance[ballTippedToTeam]->getActivePlayerInstance();
    
    size_t y = 0;
    while (y < activePlayerInstance.size())
    {
        if (activePlayerInstance[y]->getActivePosition() == ballTippedToPosition)
        {
            ballTippedToPlayerID = activePlayerInstance[y]->getID();
            ballTippedToPlayerInstance = y;
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
            physEngine.setBasketballVelocity(bballVelocity);
            physEngine.setBasketballVelocitySet(true);
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

            if (physEngine.collisionCheck(basketballInstance[activeBBallInstance]->getPhysBody().get(), activePlayerInstance[ballTippedToPlayerInstance]->getPhysBody().get()))
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
