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

#include "entity/teamentity.h"
#include "components/teamcomponents.h"
#include "data/teamdata.h"
#include "data/teamgamedata.h"
#include "flags/teamflags.h"
#include "statistics/teamstatistics.h"
#include "state/offensestate.h"
#include "state/defensestate.h"

#include "utilities/logging.h"

teamEntity::teamEntity()
{
    initialized = false;
}
teamEntity::~teamEntity()
{
}

bool teamEntity::getInitialized()  // retrieves the value of initialized
{
    return (initialized);
}
void teamEntity::setInitialized(bool set) // sets the value of initialized
{
    initialized = set;
}

teamComponentsSharedPtr teamEntity::getComponent()  // retrieves the value of component
{
    return (component);
}
void teamEntity::setComponent(teamComponentsSharedPtr set)  // sets the value of component
{
    component = set;
}

teamDataSharedPtr teamEntity::getData()  // retrieves the value of data
{
    return (data);
}
void teamEntity::setData(teamDataSharedPtr set)  // sets the value of data
{
    data = set;
}

teamFlagsSharedPtr teamEntity::getFlag()  // retrieves the value of flag
{
    return (flag);
}
void teamEntity::setFlag(teamFlagsSharedPtr set)  // sets the value of flag
{
    flag = set;
}

teamGameDataSharedPtr teamEntity::getGameData()  // retrieves the value of gameData
{
    return (gameData);
}
void teamEntity::setGameData(teamGameDataSharedPtr set)  // sets the value of gameData
{
    gameData = set;
}

teamStatisticsSharedPtr teamEntity::getStatistics()  // retrieves the value of statistics
{
    return (statistics);
}
void teamEntity::setStatistics(teamStatisticsSharedPtr set)  // sets the value of statistics
{
    statistics = set;
}

bool teamEntity::initialize()  // initializes the object
{
    std::string func = "teamEntity::setupState()";

    logMsg(func +" begin");

    teamComponentsSharedPtr tempTeamComponent(new teamComponents);
    component = tempTeamComponent;

    teamFlagsSharedPtr tempTeamFlag(new teamFlags);
    flag = tempTeamFlag;

    teamGameDataSharedPtr tempTeamGameData(new teamGameData);
    gameData = tempTeamGameData;

    teamStatisticsSharedPtr tempTeamStats(new teamStatistics);
    statistics = tempTeamStats;

    offenseStateSharedPtr tempOffenseInst(new offenseState);
    component->setOffenseInstance(tempOffenseInst);

    defenseStateSharedPtr tempDefenseInst(new defenseState);
    component->setDefenseInstance(tempDefenseInst);

    logMsg(func +" end");

    return (true);
}

void teamEntity::updateState(gameComponentsSharedPtr gameInstanceComponent, gameFlagsSharedPtr gameInstanceFlag, gameDataSharedPtr gameInstanceData, renderEngineSharedPtr render)  // updates the state of the object
{

    //conversion *convert = conversion::Instance();
    conversionSharedPtr convert = conversion::Instance();
    //gameEngine *gameE = gameEngine::Instance();
//    sharedPtr<gameEngine> gameE = gameEngine::Instance();
    //gameState *gameS = gameState::Instance();
//  sharedPtr<gameState> gameS = gameState::Instance();
    ///sharedPtr<physicsEngine> physEngine = physicsEngine::Instance();
    physicsEngine physEngine;
    gameSetupPlayersSharedPtr gameSetupPlayer(new gameSetupPlayers);
//    jumpBallsSharedPtr jumpBall = gameInstance->getJumpBall();
    std::string func = "teamEntity::updateState()";

    logMsg(func +" begin");
//    exit(0);

//    size_t activeBBallInstance = gameInstance->getActiveBBallInstance();

//  logMsg(func +" Updating team state " +convert->toString(teamNumber));
    if (flag->getActivePlayerInstancesCreated())
    {
        playerEntityMSharedPtr activePlayerInstance = component->getActivePlayerInstance();
        if (!flag->getActivePlayerInstancesSetup())
        {
            // setup Active Player Instances
            activePlayerInstance = gameSetupPlayer->setupActivePlayerInstances(activePlayerInstance, render);
            if (activePlayerInstance.size() != 0)
            {
                component->setActivePlayerInstance(activePlayerInstance);
                flag->setActivePlayerInstancesSetup(true);
            }
            else 
            {
                logMsg(func +"Unable to setup playerInstances!");
                exit(0);
            }
        }
        else
        {
            
        }
        
        if (!flag->getPlayerStartPositionsSet())
        {
            logMsg(func +" Player Start Positions Not Set!");
            if (setPlayerStartPositions(gameInstanceComponent->getCourtInstance(), gameInstanceData->getTeamStarterID()))  // sets starting positions for the players
            {
                flag->setPlayerStartPositionsSet(true);
                logMsg(func +" Player Start Positions set!");
//                exit(0);
            }
            else
            {
                logMsg(func +" Player Start Positions NOT set!");
                exit(0);
            }          
        }
        else
        {
            logMsg(func +" Player start positions set");
        }
    
//        updateActivePlayers();
        
        if (!flag->getPlayerStartDirectionsSet())
        {
            if (setPlayerStartDirections())  // sets starting directions for the players
            {
                flag->setPlayerStartDirectionsSet(true);
                logMsg(func +" Player Start Directions set!");
//                    exit(0);
            }
            else
            {
                logMsg("Player Start Directions NOT set!");
                exit(0);
            }
        }
        else
        {
            logMsg(func +" Player start directions set");
        }
        
        updateActivePlayers();
        
    }
    else
    {
        
    }
//    exit(0);
    if (gameInstanceFlag->getBasketballInstanceCreated() && gameInstanceFlag->getPlayerInstanceCreated())
    {
        
        basketballStateMSharedPtr activeBasketballInstance = gameInstanceComponent->getActiveBasketballInstance();
//      exit(0);
        // checks whether to execute offense or defense logic
        if (flag->getOffense() && !flag->getDefense())
        {
            logMsg(func +" offense executing");
//            exit(0);
            component->getOffenseInstance()->setExecute(true);
            component->getDefenseInstance()->setExecute(false);
            if (component->getOffenseInstance()->getTeamType() != gameData->getTeamType())  // sets type of team for offense
            {
                component->getOffenseInstance()->setTeamType(gameData->getTeamType());
            }
        }
        else if (flag->getDefense() && !flag->getOffense())
        {
            component->getOffenseInstance()->setExecute(false);
            component->getDefenseInstance()->setExecute(true);
            if (component->getDefenseInstance()->getTeamType() !=  gameData->getTeamType())  // sets type of team for defense
            {
                component->getDefenseInstance()->setTeamType(gameData->getTeamType());
            }
        }
        else
        {

        }

        if (gameInstanceFlag->getTipOffComplete())
        {
//          exit(0);
//          logMsg("hTeam with ball ==  "  +convert->toStringi(gameS->getTeamWithBall()));
//          logMsg("Player with ball ==  "  +convert->toString(playerWithBall));

            if (gameInstanceData->getTeamWithBall() == gameData->getTeamType()) // checks if the team has the basketball
            {
                logMsg(func +" tipoffcomplete playerWithBallInstance == " +convert->toString(gameData->getPlayerWithBallInstance()));

                size_t x = 0;
                size_t instanceWithBall;
                playerEntityMSharedPtr activePlayerInstance = component->getActivePlayerInstance();
                for (auto APIIT : activePlayerInstance)
                {                    
                    if (APIIT.second->getData()->getID() == gameData->getPlayerWithBallID())
                    {
                        instanceWithBall = APIIT.first;
                        break;
                    }
//                    ++x;
                }
                if (!activePlayerInstance[instanceWithBall]->getFlag()->getPassBall()) // checks if the player with ball is passing it.
                {
    //              exit(0);
                }
                else if (activePlayerInstance[instanceWithBall]->getFlag()->getPassBall())
                {
                    logMsg(func +" Calculating Pass");
    //              exit(0);
                    if (!activePlayerInstance[instanceWithBall]->getFlag()->getPassCalculated())
                    {
    //                  exit(0);
                        Ogre::Vector3 bballPos;
                        Ogre::Vector3 playerPos;
//                        activePlayerInstance[instanceWithBall]->calculatePass();

                        //sets the basketball Height;
                        // FIXME! activeBasketballInstance HARDCODED
                        bballPos = activeBasketballInstance[0]->getEntity()->getNode()->getPosition();
                        playerPos = activePlayerInstance[instanceWithBall]->getNode()->getPosition();
                        bballPos[1] = playerPos[1];
                        // FIXME! activeBasketballInstance HARDCODED
                        activeBasketballInstance[0]->getEntity()->getNode()->setPosition(bballPos);

                    }
                    else if (activePlayerInstance[instanceWithBall]->getFlag()->getPassCalculated())
                    {
//                      exit(0);
                        executePass();
                        if (physEngine.getPassCollision())  // checks if ball has collided with player being passed to.
                        {
//                          exit(0);
                            activePlayerInstance[instanceWithBall]->getFlag()->setPassBall(false); // player is no longer passing the ball
                            gameData->setPlayerWithBallInstance(activePlayerInstance[instanceWithBall]->getGameData()->getPassToPlayer()); // playerWithBall has changed

                            if (flag->getHumanControlled())
                            {
                                gameData->setHumanPlayer(instanceWithBall);
                            }
                            physEngine.setPassCollision(false); // resets the pass collision state

                        }
                        else
                        {
                        }

                    }
                }
//              logMsg(func +" Player with ball ==  "  +convert->toString(playerWithBall));
//              logMsg(func +" Player with ball's name: "  +activePlayerInstance[playerWithBall]->getPlayerName());
//              logMsg(func +" Player with ball's current position: "  +convert->toString(activePlayerInstance[playerWithBall]->getNode()->getPosition()));
            }
        }
        logMsg(func +" Team type = " +convert->toString(gameData->getTeamType()));

        logMsg(func +" Human player = " +convert->toString(gameData->getHumanPlayer()));
                                        
        //updatePlayerMovements();  // updates movement of player objects
        //updatePlayerDirections(); // updates the direction the players are facing
//      exit(0);


///        if (physEngine.getPlayerPhysicsSetup())  // makes sure player physics are setup before modifying physics positions
///        {
///            updatePositions();
//            exit(0);
///        }
///        else
///        {
///        }

//    logMsg(func +" Team ==  "  +toString(teamType));

        //      exit(0);
    }
    else
    {
    }
//  exit(0);

    if (gameInstanceFlag->getTipOffComplete())
    {
        logMsg(func +" tipOff Complete!");
//        exit(0);
        if (gameInstanceData->getTeamWithBall() == gameData->getTeamType())
        {
/*            if (!offenseInstance->getGameSInitialized())
            {
                offenseInstance->setGameS(gameInstance);
                offenseInstance->setGameSInitialized(true);            
            }
            else
            {              
            }
            offenseInstance->updateState(teamType); // updates the state of the offenseInstance object
*/
        }
        else
        {
/*            if (!defenseInstance->getGameSInitialized())
            {
                defenseInstance->setGameS(gameInstance);
                defenseInstance->setGameSInitialized(true);            
            }
            else
            {              
            }
*/          
            component->getDefenseInstance()->updateState(gameData->getTeamType(), gameInstanceComponent, gameInstanceData); // updates the state of the defenseInstance object
        }

    }
    else
    {
    }

    
//   logMsg(func +" team state updated = " +convert->toString(teamType));
}
