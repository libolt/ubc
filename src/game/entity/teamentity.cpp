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
#include "components/gamecomponents.h"
#include "components/teamcomponents.h"
#include "data/gamedata.h"
#include "data/playerdata.h"
#include "data/playergamedata.h"
#include "data/teamdata.h"
#include "data/teamgamedata.h"
#include "engine/physicsengine.h"
#include "entity/basketballentity.h"
#include "entity/playerentity.h"
#include "flags/gameflags.h"
#include "flags/playerflags.h"
#include "flags/teamflags.h"
#include "setup/setupplayers.h"
#include "setup/setupteams.h"
#include "statistics/teamstatistics.h"
//#include "state/basketballstate.h"
#include "state/offensestate.h"
#include "state/defensestate.h"
#include "statemachine/teamstatemachine.h"
#include "update/updateteams.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

teamEntity::teamEntity()
{
    initialized = false;
    offDef = NOOFFDEF;
}
teamEntity::~teamEntity() = default;  // destructor

bool teamEntity::getInitialized() const  // retrieves the value of initialized
{
    return (initialized);
}
void teamEntity::setInitialized(const bool &set) // sets the value of initialized
{
    initialized = set;
}

teamComponentsSharedPtr teamEntity::getComponent() const  // retrieves the value of component
{
    return (component);
}
void teamEntity::setComponent(const teamComponentsSharedPtr &set)  // sets the value of component
{
    component = set;
}

teamDataSharedPtr teamEntity::getData() const  // retrieves the value of data
{
    return (data);
}
void teamEntity::setData(const teamDataSharedPtr &set)  // sets the value of data
{
    data = set;
}

teamFlagsSharedPtr teamEntity::getFlag() const  // retrieves the value of flag
{
    return (flag);
}
void teamEntity::setFlag(const teamFlagsSharedPtr &set)  // sets the value of flag
{
    flag = set;
}

teamGameDataSharedPtr teamEntity::getGameData() const  // retrieves the value of gameData
{
    return (gameData);
}
void teamEntity::setGameData(const teamGameDataSharedPtr &set)  // sets the value of gameData
{
    gameData = set;
}

teamStateMachineSharedPtr teamEntity::getStateMachine() const  // retrieves the value of stateMachine
{
    return (stateMachine);
}
void teamEntity::setStateMachine(const teamStateMachineSharedPtr &set)  // sets the value of stateMachine
{
    stateMachine = set;
}

teamStatisticsSharedPtr teamEntity::getStatistics() const  // retrieves the value of statistics
{
    return (statistics);
}
void teamEntity::setStatistics(teamStatisticsSharedPtr &set)  // sets the value of statistics
{
    statistics = set;
}

offDefs teamEntity::getOffDef() const  // retrieves the value of offDef
{
    return (offDef);
}
void teamEntity::setOffDef(const offDefs &set)  // sets the value of offDef
{
    offDef = set;
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

    initializeStateMachine();
    
    logMsg(func +" end");

    return (true);
}

bool teamEntity::initializeStateMachine()  // initializes teamStateMachine object
{
    std::string func = "teamEntity::initializeStateMachine()";
    auto *SMData(new teamSMData);

    logMsg(func +" begin");
//    exit(0);
    SMData->component = component;
    SMData->gData = gameData;
    SMData->flag = flag;

    
//    SMData->node = getNode();
    
//    component->getStateMachine()->setSpeed(SMData);
//    component->getStateMachin
    teamStateMachineSharedPtr tempSM(new teamStateMachine);
    stateMachine = tempSM;
    auto *tempSMData2(new teamSMData);

    stateMachine->pInit(tempSMData2);
//    exit(0);
    flag->setStateMachineInitialized(true);
    
    logMsg(func +" end");

    return (true);
}

void teamEntity::updateState(const gameComponentsSharedPtr &gameInstanceComponent, const gameFlagsSharedPtr &gameInstanceFlag, const gameDataSharedPtr &gameInstanceData, const renderEngineSharedPtr &render)  // updates the state of the object
{

    conversionSharedPtr convert ;
    physicsEngine physEngine;
    setupPlayersSharedPtr setupPlayer(new setupPlayers);
    setupTeamsSharedPtr setupTeam(new setupTeams);
    updateTeamsSharedPtr updateTeam(new updateTeams);

    std::string func = "teamEntity::updateState()";

    logMsg(func +" begin");
//    exit(0);

//    size_t activeBBallInstance = gameInstance->getActiveBBallInstance();

//  logMsg(func +" Updating team state " +convert->toString(teamNumber));
    if (flag->getActivePlayerInstancesCreated())
    {

        playerEntityMSharedPtr activePlayerInstance = component->getActivePlayerInstance();
        logMsg(func +" activePlayerInstance.size() == " +convert->toString(activePlayerInstance.size()));
//        exit(0);

        if (!flag->getActivePlayerInstancesSetup())
        {
            // setup Active Player Instances
            auto *spSMData = new teamSMData;
            spSMData->component = component;
            spSMData->flag = flag;
            spSMData->render = render;
            stateMachine->pSetupPlayerInstances(spSMData);
/*            activePlayerInstance = setupPlayer->setupActivePlayerInstances(activePlayerInstance, render);
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
*/
        }
        else
        {
            
        }
        
        if (!flag->getPlayerStartPositionsSet())
        {
            auto *spspSMData = new teamSMData;
            spspSMData->component = component;
            spspSMData->flag = flag;
            spspSMData->gData = gameData;
            spspSMData->courtInstance = gameInstanceComponent->getCourtInstance();
            spspSMData->teamStarterID = gameInstanceData->getTeamStarterID();
            stateMachine->pSetPlayerStartPositions(spspSMData);

/*            logMsg(func +" Player Start Positions Not Yet Set!");
            playerEntityMSharedPtr activePlayerInstance;
            logMsg(func +" component->getActivePlayerInstance().size() = " +convert->toString(component->getActivePlayerInstance().size()));
//            exit(0);
            activePlayerInstance = setupTeam->setPlayerStartPositions(component->getActivePlayerInstance(), gameInstanceComponent->getCourtInstance(), gameData, gameInstanceData->getTeamStarterID());
//            if (setPlayerStartPositions(activePlayerInstance, gameInstanceComponent->getCourtInstance(), gameInstanceData->getTeamStarterID()))  // sets starting positions for the players
            if (activePlayerInstance.size() > 0)
            {
                flag->setPlayerStartPositionsSet(true);
                component->setActivePlayerInstance(activePlayerInstance);
                logMsg(func +" Player Start Positions set!");
//                exit(0);
            }
            else
            {
                logMsg(func +" Player Start Positions NOT set!");
                exit(0);
            }          
*/
        }
        else
        {
            logMsg(func +" Player start positions set");
        }
    
//        updateActivePlayers();
        
        if (!flag->getPlayerStartDirectionsSet())
        {
            auto *spsdSMData = new teamSMData;
            spsdSMData->component = component;
            spsdSMData->flag = flag;
            spsdSMData->gData = gameData;
            stateMachine->pSetPlayerStartDirections(spsdSMData);
/*            playerEntityMSharedPtr activePlayerInstance;
            activePlayerInstance = setupTeam->setPlayerStartDirections(component->getActivePlayerInstance(), gameData);
            if (activePlayerInstance.size() > 0)  // sets starting directions for the players
            {
                flag->setPlayerStartDirectionsSet(true);
                component->setActivePlayerInstance(activePlayerInstance);
                logMsg(func +" Player Start Directions set!");
//                    exit(0);
            }
            else
            {
                logMsg("Player Start Directions NOT set!");
                exit(0);
            }
*/
        }
        else
        {
            logMsg(func +" Player start directions set");
        }

        auto *uapSMData = new teamSMData;
        uapSMData->component = component;
        stateMachine->pUpdateActivePlayers(uapSMData);
/*        activePlayerInstance = updateTeam->updateActivePlayers(component->getActivePlayerInstance());
        if (activePlayerInstance.size() > 0)
        {
            exit(0);
            component->setActivePlayerInstance(activePlayerInstance);
        }
        else
        {
            logMsg(func +" Unable to update Active Player Instances!");
            exit(0);
        }
*/
    }
    else
    {
        
    }
//    exit(0);
    if (gameInstanceFlag->getBasketballInstanceCreated() && gameInstanceFlag->getPlayerInstanceCreated())
    {
        
        basketballEntityMSharedPtr activeBasketballInstance = gameInstanceComponent->getActiveBasketballInstance();
//      exit(0);
        auto *odSMData(new teamSMData);
        odSMData->component = component;
        odSMData->gData = gameData;

        // checks whether to execute offense or defense logic
        switch (offDef)
        {
            case OFFENSE:
                stateMachine->pExecuteOffense(odSMData);
            break;
            case DEFENSE:
                stateMachine->pExecuteDefense(odSMData);
            break;
            case NOOFFDEF:
            break;
        }

/*        if (flag->getOffense() && !flag->getDefense())
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
*/
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
                        bballPos = activeBasketballInstance[0]->getNode()->getPosition();
                        playerPos = activePlayerInstance[instanceWithBall]->getNode()->getPosition();
                        bballPos[1] = playerPos[1];
                        // FIXME! activeBasketballInstance HARDCODED
                        activeBasketballInstance[0]->getNode()->setPosition(bballPos);

                    }
                    else if (activePlayerInstance[instanceWithBall]->getFlag()->getPassCalculated())
                    {
//                      exit(0);
///FIXME!
///                        offense->executePass();
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
