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

#include "gamesetup/gamesetupplayers.h"
#include "data/playerdata.h"
#include "entity/playerentity.h"
#include "load/loadplayers.h"
#include "state/gamestate.h"
#include "state/teamstate.h"
#include "statemachine/playerstatemachine.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

gameSetupPlayers::gameSetupPlayers()  // constructor
{

}
gameSetupPlayers::~gameSetupPlayers()  // destructor
{

}

bool gameSetupPlayers::checkIfGamePlayerInstancesCreated(gameStateSharedPtr gameS)  // checks if the gameState Objects Player Instances have been created
{
    conversionSharedPtr convert = conversion::Instance();
    playerEntityMSharedPtr playerInstance = gameS->getPlayerInstance();
    bool returnType = false;
    std::string func = "gameSetupPlayers::checkIfGamePlayerInstanceCreated()";
    
    logMsg(func +" beginning");

    if (gameS->getPlayerInstanceCreated())
    {
        if (playerInstance.size() > 0)
        {
            logMsg(func +" playerInstance.size() == " +convert->toString(gameS->getPlayerInstance().size()));
            returnType = true;
        }
        else
        {
            logMsg(func +" gameState::checkIfPlayerInstanceCreated() player instances not yet created!");
 //           exit(0);
            playerInstance = createPlayerInstances();
            if (playerInstance.size())
            {
            
                logMsg(func +" Player Instances created!");
//                exit(0);
                gameS->setPlayerInstanceCreated(true);
                gameS->setPlayerInstance(playerInstance);
                returnType = true;
//            exit(0);
            }
            else
            {
                logMsg(func +" player instances not created!");
                exit(0);
            }
        }
//        exit(0);
    }
    else
    {
        logMsg(func +" player instances not yet created!");
        playerInstance = createPlayerInstances();
        if (playerInstance.size())
        {

            logMsg(func +" Player Instances created!");

            gameS->setPlayerInstanceCreated(true);
            gameS->setPlayerInstance(playerInstance);
            returnType = true;
//            exit(0);
        }
        else
        {
            logMsg(func +" Player Instances not created!");
            exit(0);
        }
//        return (false);
    }
    logMsg(func +" end");
    return (returnType);
}

bool gameSetupPlayers::checkIfTeamPlayerInstancesCreated(playerEntityMSharedPtr gamePlayerInstance, teamStateMSharedPtr activeTeamInstance)  // checks if the gameState Objects Player Instances have been created
{
    conversionSharedPtr convert = conversion::Instance();
    playerEntityMSharedPtr playerInstance; // = gameS->getPlayerInstance();
    bool returnType = false;
    std::string func = "gameSetupPlayers::checkIfTeamPlayerInstancesCreated()";
  
    logMsg(func +" beginning");
    
    for (auto ATIIT : activeTeamInstance)  // loop through activeTeamInstance
    {
//        logMsg(convert->toString(teamIDs.size()));
        logMsg(convert->toString(ATIIT.second->getPlayerInstancesCreated()));
//        exit(0);

        if (ATIIT.second->getPlayerInstancesCreated())  // check if playerInstances created is true
        {
//            exit(0);
            if (ATIIT.second->getPlayerInstance().size() > 0)
            {
                logMsg(func +" " +ATIIT.second->getCity() +" " +ATIIT.second->getName() + " Player Instances Created!");
            }
            else
            {
                
                playerInstance = createTeamPlayerInstances(gamePlayerInstance, ATIIT.second->getID());
                if (playerInstance.size() > 0)
                {
                    logMsg(func +" " +ATIIT.second->getCity() +" " +ATIIT.second->getName() + " Player Instances Created!");
                    ATIIT.second->setPlayerInstancesCreated(true);
                    ATIIT.second->setPlayerInstance(playerInstance);
                    returnType = true;
                }
                else
                {
                    logMsg(func +" Unable to Create " +ATIIT.second->getCity() +" " +ATIIT.second->getName() + " Player Instances!");
                }
            }
        }
        else  // create team's player instances
        {
            playerInstance = createTeamPlayerInstances(gamePlayerInstance, ATIIT.second->getID());
            if (playerInstance.size() > 0)
            {
                logMsg(func +" " +ATIIT.second->getCity() +" " +ATIIT.second->getName() + " Player Instances Created!");
                ATIIT.second->setPlayerInstancesCreated(true);
                ATIIT.second->setPlayerInstance(playerInstance);
                returnType = true;
            }
            else
            {
                logMsg(func +" Unable to Create " +ATIIT.second->getCity() +" " +ATIIT.second->getName() + " Player Instances!");
            }
        }
    }
    
    logMsg(func +" end");
    
    return (returnType);
}

playerEntityMSharedPtr gameSetupPlayers::createPlayerInstances()  // creates player Instances
{
    conversionSharedPtr convert = conversion::Instance();
    loadPlayersSharedPtr loadPlayer(new loadPlayers);
    playerEntityMSharedPtr playerInstance;
    std::string func = "gameSetupPlayers::createPlayerInstances()";

    logMsg(func +" beginning");

    logMsg(func +" checkIfPlayersLoaded");
    //    exit(0);
    if (loadPlayer->checkIfPlayersLoaded())
    {
        logMsg(func +" checkIfPlayersLoaded True");

        playerInstance = loadPlayer->getPInstance();
        if (playerInstance.size() > 0)
        {
            logMsg(func +" playerInstance Loaded!");
        }
        else
        {
            logMsg(func +" playerInstance NOT Loaded!");
            exit(0);
        }
    }
    else
    {
        logMsg(func +" loading of playerss failed!");
        exit(0);
    }

    for (auto PIIT : playerInstance)
    {
        logMsg(func +" Player " +PIIT.second->getData()->getFirstName() +" " +PIIT.second->getData()->getLastName() +" TeamID == " +convert->toString(PIIT.second->getData()->getTeamID()));
    }

    logMsg(func +" playerInstance.size() == " +convert->toString(playerInstance.size()));
    logMsg(func +" too");

    logMsg(func +" end");

    return (playerInstance);

}

playerEntityMSharedPtr gameSetupPlayers::createTeamPlayerInstances(playerEntityMSharedPtr gamePlayerInstance, size_t teamID)  // creates player instances for a team
{
    playerEntityMSharedPtr playerInstance;  // stores player objects that will be returned when the function completes
    conversionSharedPtr convert = conversion::Instance();
//    playerEntityMSharedPtr gamePlayerInstance;
    std::string func = "gameSetupPlayers::createTeamPlayerInstances()";

    logMsg(func +" beginning");

    if (gamePlayerInstance.size() > 0)
    {

        logMsg(func +"Game Player Instances Created!");
//        gamePlayerInstance = base->getGameS()->getPlayerInstance();
    }
    else
    {
        logMsg(func +"Game Player Instances not created!");
        exit(0);
    }
    logMsg(func + " gamePlayerInstance.size() == " +convert->toString(gamePlayerInstance.size()));
//    exit(0);
    auto i = 0;
    auto ID = 0;
    for (auto GPIIT : gamePlayerInstance)
    {
        logMsg(func +" gamePlayerInstance->getData()->getTeamID() == " +convert->toString(gamePlayerInstance[0]->getData()->getTeamID()));
        logMsg(func +" teamID == " +convert->toString(teamID));

        if (GPIIT.second->getData()->getTeamID() == teamID)  // checks if player is assigned to this team
        {

            logMsg(func + " Team " +convert->toString(teamID) + " GPI Name == " +GPIIT.second->getData()->getFirstName() +" " +GPIIT.second->getData()->getLastName());
            playerInstance.insert(std::pair<size_t, playerEntitySharedPtr>(GPIIT.first, GPIIT.second));    // adds pInstance to the playerInstance std::vector.
//            logMsg(func +"Team ID == " +convert->toString(getID()) +" playerInstance[" +convert->toString(it.first) +"]->getFirstName() == " +playerInstance[it.first]->getFirstName());
            ++ID;
        }
//        ++i;
    }
    for (auto PIIT : playerInstance)
    {
        logMsg(func +"Team ID == " +convert->toString(teamID) +" playerInstance[" +convert->toString(PIIT.first) +"]->getData()->getFirstName() == " +PIIT.second->getData()->getFirstName());

    }
//    exit(0);
///    if (getID() == 1)
///    {
///        logMsg(func +"playerInstance.size() == " +convert->toString(playerInstance.size()));
///        logMsg(func +" ID Count == " +convert->toString(ID));
//        exit(0);
///    }

    logMsg(func +" end");

    return (playerInstance);
}

playerEntityMSharedPtr gameSetupPlayers::createActivePlayerInstances(playerEntityMSharedPtr playerInstance, std::unordered_map<std::string, size_t> activePlayerID)  // creates active court instances
{
    conversionSharedPtr convert = conversion::Instance();
    std::string func = "gameSetupPlayers::createActivePlayerInstances()";

    playerEntityMSharedPtr activePlayerInstance;
    
    for (auto PIIT : playerInstance)
    {
/*        logMsg(func +" ATIIT.first == " +convert->toString(ATIIT.first) +" PIIT.second->getData()->getID() == " +convert->toString(PIIT.second->getData()->getID()) +" primaryPosition == " +convert->toString(PIIT.second->getData()->getPrimaryPosition()));
        std::string teamStarterIDPG = convert->toString(teamStarterID[0]["PG"]);
        logMsg(func +" teamStarterID[ATIIT.first][PG] == " +teamStarterIDPG);
        logMsg(func +" playerInstance ID == " +convert->toString(PIIT.second->getData()->getID()));
*/           
        if (PIIT.second->getData()->getID() == activePlayerID["PG"])
        {
            logMsg(func +" PG");
            activePlayerInstance.insert(std::pair<playerPositions, playerEntitySharedPtr>(PG, PIIT.second));
            activePlayerInstance[PG]->setActivePosition(PG);
            logMsg(func +" WOOT PG!");
        }
        else if (PIIT.second->getData()->getID() == activePlayerID["SG"])
        {
            activePlayerInstance.insert(std::pair<playerPositions, playerEntitySharedPtr>(SG, PIIT.second));
            activePlayerInstance[SG]->setActivePosition(SG);
            logMsg(func +" WOOT SG!");
        }
        else if (PIIT.second->getData()->getID() == activePlayerID["SF"])
        {
            activePlayerInstance.insert(std::pair<playerPositions, playerEntitySharedPtr>(SF, PIIT.second));
            activePlayerInstance[SF]->setActivePosition(SF);
            logMsg(func +" WOOT SF!");
        }
        else if (PIIT.second->getData()->getID() == activePlayerID["PF"])
        {
            activePlayerInstance.insert(std::pair<playerPositions, playerEntitySharedPtr>(PF, PIIT.second));
            activePlayerInstance[PF]->setActivePosition(PF);
            logMsg(func +" WOOT PF!");
        }
        else if (PIIT.second->getData()->getID() == activePlayerID["C"])
        {
            activePlayerInstance.insert(std::pair<playerPositions, playerEntitySharedPtr>(C, PIIT.second));
            activePlayerInstance[C]->setActivePosition(C);
            logMsg(func +" WOOT C!");
        }
        logMsg(func +" WOOT!");
        logMsg(func +" loop activePlayerInstance.size() == " +convert->toString(activePlayerInstance.size()));

    }
    
    return (activePlayerInstance);
}

playerEntityMSharedPtr gameSetupPlayers::createActivePlayerInstances(playerEntityMSharedPtr activePlayerInstance)  // sets up active player instances
{
    conversionSharedPtr convert = conversion::Instance();
    std::string func = "teamState::setupActivePlayerInstances()";
    
    logMsg(func +" beginning");
    for (auto APIIT : activePlayerInstance)
    {
        if (!APIIT.second->getBaseInitialized())
        {
//REMOVE?            APIIT.second->setBase(base);
            APIIT.second->setBaseInitialized(true);
        }
        else
        {
            logMsg(func +" Unable to initialize base!");
            exit(0);
        }
        if (!APIIT.second->getInitialized())
        {
            logMsg("Player Entity not yet Initialized!");
            if (APIIT.second->initialize())
            {
                APIIT.second->setInitialized(true);
            }
            else
            {
                logMsg(func + " Unable to initialize player entity!");
                exit(0);
            }
        }
        else
        {

        }

        if (!APIIT.second->getModelLoaded())
        {
            logMsg(func +" Model not loaded yet!");
            if (APIIT.second->loadModel())
            {
                logMsg(func + " Model loaded successfully!");
                APIIT.second->setModelLoaded(true);
            }
            else
            {
                logMsg(func + " Unable to load model!");
                exit(0);
            }
        }
        else
        {
                        
        }
//        exit(0);

// FIXME! Broken by playerStateMachine work
/*        logMsg(func + " setting up Physics!");
        if (!APIIT.second->getPhysicsSetup())
        {
            if (!APIIT.second->getPhysics()->getGameSInitialized())
            {
                APIIT.second->getPhysics()->setGameS(base->getGameS());
                APIIT.second->getPhysics()->setGameSInitialized(true);
            }
            else
            {
                
            }
            if (APIIT.second->setupPhysicsObject())  // attempts to setup the physics object and sets physBodyInitialized to true if successful
            {
                APIIT.second->setPhysBodyInitialized(true);
            }
//            APIIT.second->setPhysicsSetup(true);
        }
        else
        {
                        
        }*/
        
        if (!APIIT.second->getStateMachineInitialized())
        {
            logMsg(func + " stateMachine not initialized!");
            if (APIIT.second->initializeStateMachine())
            {
                logMsg(func + " stateMachine is now Initialized!");
                
                if (!APIIT.second->getSMNodeSet())  // sets the value of node if it has not been set already
                {
                    playerSMData *SMData = new playerSMData;
                    SMData->node = APIIT.second->getNode();
                    APIIT.second->setStateChanged(true);
                    if (APIIT.second->updateStateMachine(SETNODE, SMData))
                    {
                        APIIT.second->setSMNodeSet(true);
                        logMsg(func +" stateMachine node has been set!");
                    }
                    else
                    {
                        logMsg(func +" Unable to set stateMachine node");
                        exit(0);
                    }
//                    exit(0);
                }
                else
                {
                    logMsg(func +" stateMachine node already set");
                }

                if (!APIIT.second->getSMModelSet())  // sets the value of model if it has not been set already
                {
                    playerSMData *SMData = new playerSMData;
                    SMData->model = APIIT.second->getModel();
                    APIIT.second->setStateChanged(true);
                    if (APIIT.second->updateStateMachine(SETMODEL, SMData))
                    {
                        APIIT.second->setSMModelSet(true);
                        logMsg(func +" stateMachine model has been set!");
                    }
                    else
                    {
                        logMsg(func +" Unable to set stateMachine model");
                        exit(0);
                    }
//                    exit(0);
                }
                else
                {
                    logMsg(func +" stateMachine model already set");
                }
            }
            else
            {
                logMsg(func + " Unable to initialize stateMachine !");
            }
        }
        else
        {
            logMsg(func + " stateMachine already Initialized!");
            if (!APIIT.second->getSMNodeSet())  // sets the value of node if it has not been set already
            {
                playerSMData *SMData = new playerSMData;
                SMData->node = APIIT.second->getNode();
                APIIT.second->setStateChanged(true);
                if (APIIT.second->updateStateMachine(SETNODE, SMData))
                {
                    APIIT.second->setSMNodeSet(true);
                    logMsg(func +" stateMachine node has been set!");
                }
                else
                {
                    logMsg(func +" Unable to set stateMachine node");
                    exit(0);
                }
//                    exit(0);
            }
            else
            {
                logMsg(func +" stateMachine node already set");
            }

            if (!APIIT.second->getSMModelSet())  // sets the value of model if it has not been set already
            {
                playerSMData *SMData = new playerSMData;
                SMData->model = APIIT.second->getModel();
                APIIT.second->setStateChanged(true);
                if (APIIT.second->updateStateMachine(SETMODEL, SMData))
                {
                    APIIT.second->setSMModelSet(true);
                    logMsg(func +" stateMachine model has been set!");
                }
                else
                {
                    logMsg(func +" Unable to set stateMachine model");
                    exit(0);
                }
//                    exit(0);
            }
            else
            {
                logMsg(func +" stateMachine model already set");
            }
        }
//        exit(0);
    }
    
    for (auto APIIT : activePlayerInstance)
    {
        logMsg(func +" Entity Node Name == " +APIIT.second->getEntityNodeName());
        logMsg(func +" Node Name == " +APIIT.second->getNode()->getName());
    }
//    exit(0);
    logMsg(func +" end");
    
    return (activePlayerInstance);
}
