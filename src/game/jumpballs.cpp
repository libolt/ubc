/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean                              *
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
#include "gamestate.h"
#include "comparison.h"
#include "logging.h"
#include "physicsengine.h"
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
    
}

jumpBallLocations_t jumpBalls::getJumpBallLocation()  // retrieves teh value of jumpBallLocation
{
    return (jumpBallLocation);
}
void jumpBalls::setJumpBallLocation(jumpBallLocations_t set)  // sets the value of jumpBallLocation
{
    jumpBallLocation = set;
}

std::vector<playerPositions> jumpBalls::getJumpBallPlayer()  // retrieves the value of jumpBallPlayer
{
    return (jumpBallPlayer);
}
void jumpBalls::setJumpBallPlayer(std::vector<playerPositions> set)  // sets the value of jumpBallPlayer
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

bool jumpBalls::updateState()  // updates state of the jumpBalls instance
{
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    logMsg("updating jumpBall state!");
    logMsg("gameS->getTeamWithBall() == " +convert->toString(gameS->getTeamWithBall()));

    size_t activeBBallInstance = gameS->getActiveBBallInstance();
    std::vector<basketballs> basketBallInstance = gameS->getBasketballInstance();
    bool bballPhysicsSetup = basketBallInstance[activeBBallInstance].getPhysics().getPhysicsSetup();
    if (gameS->getTeamWithBall() == NOTEAM && bballPhysicsSetup) //&& gameS->getTeamInstancesCreated())
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
                ballTipped = jumpBallExecute();  // executes jump ball until ball is tipped
                logMsg ("Ball Tippped? " +convert->toString(ballTipped));
//                exit(0);
            }
            else
            {
//                exit(0);
                jumpBallComplete = tipToPlayer();

                logMsg("jumpBallComplete == " +convert->toString(jumpBallComplete));
//                exit(0);
            }
        }
        else
        {
            logMsg("teamWithBall = " +convert->toString(gameS->getTeamWithBall()));
//            exit(0);
        }
        logMsg("ballTipped == " +convert->toString(ballTipped));
        logMsg("ballTippedToTeam == " +convert->toString(ballTippedToTeam));
    }
    else
    {
        logMsg("gameS->getTeamWithBall() == " +convert->toString(gameS->getTeamWithBall()));
        return (true);
    }
    
    logMsg("jumpBall return(false)");
    return (false);  // returns false until jump ball has completed
}

bool jumpBalls::jumpBallExecute()  // initiates jump ball from jump ball circle
{
//    exit(0);
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<physicsEngine> physEngine = physicsEngine::Instance();

    std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();
    size_t activeBBallInstance = gameS->getActiveBBallInstance();

    std::vector<teamState> teamInstance = gameS->getTeamInstance();
    std::vector< std::vector<playerState> > activePlayerInstance;

    std::vector<size_t> jumpPlayerInstance;  // stores playerID of players jumping for the ball
    
    size_t x = 0;
    while (x < teamInstance.size())
    {
        //activePlayerInstance.clear();
        activePlayerInstance.push_back(teamInstance[x].getActivePlayerInstance());
        size_t i = 0;

        while (i < activePlayerInstance[x].size()) // loops until the activePlayerInstance is found that is currently playing center
        {
            logMsg("jump i == " +convert->toString(i));
            if (activePlayerInstance[x][i].getActivePosition() == C)
            {
                logMsg("jumpPlayerInstance = " +convert->toString(i));
                 // logMsg("PlayerName = " +activePlayerInstance[x][i].getPlayerName());
                logMsg("ModelLoaded = " +convert->toString(activePlayerInstance[x][i].getModelLoaded()));
    //                    exit(0);
                //jumpPlayerID.push_back(activePlayerInstance[i].getPlayerID());
                jumpPlayerInstance.push_back(i);
            }
            else
            {
            }
            i++;
              //teamTypes teamType = teamInstance[x].getTeamType();
                //size_t player = 4;
                //bool collCheck = collisionCheck(basketballInstance[activeBBallInstance].getPhysBody(), activePlayerInstance[centerID].getPhysBody());
                //logMsg("Team " +convert->toString(teamType) +" player " +convert->toString(player) +" collCheck == " +convert->toString(collCheck));
        }
        ++x;
    }
//    exit(0);
    logMsg("jumpPlayerID.size() = " +convert->toString(jumpPlayerInstance.size()));
//    exit(0);
//    teamTypes teamType = teamInstance[0].getTeamType();
    bool collCheck = false;
//    collCheck = physEngine->collisionCheck(basketballInstance[activeBBallInstance].getPhysBody(), activePlayerInstance[0][jumpPlayerInstance[0]].getPhysBody());
    size_t y = 0;
    playerState activePInstance;
    while (y < teamInstance.size())
    {
        switch(teamInstance[y].getTeamType())
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
        if (physEngine->collisionCheck(basketballInstance[activeBBallInstance].getPhysBody(), activePInstance.getPhysBody()))
        {
            logMsg("team " +convert->toString(y) +" center collided with ball");
            ballTippedToTeam = teamInstance[y].getTeamType();
            ballTippedToPosition = PG;
//            exit(0);
        
        }
        else
        {
        
        }
/*        logMsg("Team " +convert->toString(teamType) +" playerInstance " +convert->toString(jumpPlayerInstance[0]) +" collCheck == " +convert->toString(collCheck));
        teamType = teamInstance[1].getTeamType();
        collCheck = physEngine->collisionCheck(basketballInstance[activeBBallInstance].getPhysBody(), activePlayerInstance[1][jumpPlayerInstance[1]].getPhysBody());
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

bool jumpBalls::tipToPlayer()  // tips the basketball to the appropriate player
{
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<physicsEngine> physEngine = physicsEngine::Instance();

    std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();
    std::vector<teamState> teamInstance = gameS->getTeamInstance();
    std::vector<playerState> activePlayerInstance;
    jumpBalls jumpBall = gameS->getJumpBall();
    teamTypes ballTippedToTeam = jumpBall.getBallTippedToTeam();
    quarters quarter = gameS->getQuarter();
    size_t activeBBallInstance = gameS->getActiveBBallInstance();

    activePlayerInstance = teamInstance[ballTippedToTeam].getActivePlayerInstance();
    
    size_t y = 0;
    while (y < activePlayerInstance.size())
    {
        if (activePlayerInstance[y].getActivePosition() == jumpBall.getBallTippedToPosition())
        {
            ballTippedToPlayerID = activePlayerInstance[y].getPlayerID();
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
            physEngine->setBasketballVelocity(bballVelocity);
            physEngine->setBasketballVelocitySet(true);
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

            if (physEngine->collisionCheck(basketballInstance[activeBBallInstance].getPhysBody(), activePlayerInstance[ballTippedToPlayerInstance].getPhysBody()))
            {
 //               exit(0);
                gameS->setTeamWithBall(ballTippedToTeam);
                logMsg("ballTippedToPlayerID == " +convert->toString(ballTippedToPlayerID));
                teamInstance[ballTippedToTeam].setPlayerWithBallID(ballTippedToPlayerID);
                teamInstance[ballTippedToTeam].setPlayerWithBallInstance(ballTippedToPlayerInstance);
                physEngine->setBasketballVelocitySet(false);
                teamInstance[ballTippedToTeam].setPlayerWithBallDribbling(true);
                if (teamInstance[ballTippedToTeam].getHumanControlled())
                {
                    teamInstance[ballTippedToTeam].setHumanPlayer(ballTippedToPlayerID);
                    logMsg("ball tipped to human playerID == " +convert->toString(jumpBall.getBallTippedToPlayerID()));
        //            exit(0);
                }
                logMsg("jumpBall.getBallTippedToPlayer() = " +convert->toString(jumpBall.getBallTippedToPlayerID()));
                logMsg("playerWithBallInstanceTipped == " +convert->toString(teamInstance[ballTippedToTeam].getPlayerWithBallInstance()));
                int activeDefensivePlayer = 9999;
                switch (ballTippedToTeam)
                {
                    case 0:
                        activeDefensivePlayer = teamInstance[1].getActivePlayerID()[0];
                        teamInstance[AWAYTEAM].setHumanPlayer(activeDefensivePlayer);
                    break;
                    case 1:
                        activeDefensivePlayer = teamInstance[0].getActivePlayerID()[0];
                        teamInstance[HOMETEAM].setHumanPlayer(activeDefensivePlayer);
                    break;
                    default:
                    break;
                }
                gameS->setTeamInstance(teamInstance);

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
