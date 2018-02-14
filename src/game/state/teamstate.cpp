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

#include "utilities/conversion.h"
#include "components/gamecomponents.h"
#include "components/teamcomponents.h"
#include "data/gamedata.h"
#include "data/playerdata.h"
#include "data/playergamedata.h"
#include "data/teamgamedata.h"
#include "entity/basketballentity.h"
#include "entity/courtentity.h"
#include "entity/playerentity.h"
#include "flags/gameflags.h"
#include "flags/playerflags.h"
#include "flags/teamflags.h"
#include "gamesetup/gamesetupplayers.h"
#include "gamesetup/gamesetupplayerpositions.h"
#include "physics/basketballphysics.h"
#include "state/teamstate.h"
#include "engine/gameengine.h"
#include "state/basketballstate.h"
#include "state/courtstate.h"
#include "state/gamestate.h"
#include "state/hoopstate.h"
#include "state/defensestate.h"
#include "state/playerstate.h"
#include "state/offensestate.h"
#include "statemachine/playerstatemachine.h"
#include "statistics/teamstatistics.h"
#include "utilities/logging.h"
#include "engine/physicsengine.h"
#include "ai/playersteer.h"
#include "utilities/enums.h"
#include "jumpballs.h"

// static declarations

teamState::teamState()  // constructor
{

}

teamState::~teamState()  // destructor
{
}

teamComponentsSharedPtr teamState::getComponent()  // retrieves the value of component
{
    return (component);
}
void teamState::setComponent(teamComponentsSharedPtr set)  // sets the value of component
{
    component = set;
}

teamFlagsSharedPtr teamState::getFlag()  // retrieves the value of flag
{
    return (flag);
}
void teamState::setFlag(teamFlagsSharedPtr set)  // sets the value of flag
{
    flag = set;
}

teamGameDataSharedPtr teamState::getGameData()  // retrieves the value of gameData
{
    return (gameData);
}
void teamState::setGameData(teamGameDataSharedPtr set)  // sets the value of gameData
{
    gameData = set;
}

teamStatisticsSharedPtr teamState::getStatistics()  // retrieves the value of statistics
{
    return (statistics);
}
void teamState::setStatistics(teamStatisticsSharedPtr set)  // sets the value of statistics
{
    statistics = set;
}

void teamState::setupState()  // sets up the state of the object
{
    bool stateSet = this->getStateSet();
    std::string func = "teamState::setupState()";
    
    logMsg(func +" beginning");

    sharedPtr<teamStatistics> tempTeamStats(new teamStatistics);
    statistics = tempTeamStats;

    offenseStateSharedPtr tempOffenseInst(new offenseState);
    offenseInstance = tempOffenseInst;

    defenseStateSharedPtr tempDefenseInst(new defenseState);
    defenseInstance = tempDefenseInst;
    if (!stateSet)
    {
        logMsg(func +" Setting state");
//      sharedPtr<physicsEngine> physEngine = physicsEngine::Instance();
///        if (!playerInstancesCreated) // checks if playerInstances have been created
///        {
///         if (createPlayerInstances()) // creates the ttances based on playerIDS
///         {
///                logMsg("Player instances created!");
///                playerInstancesCreated = true;
//          exit(0);
///         }
///        }

//    playerWithBall = 3; // FIXME! Temporarily ahrd code player controlling ball
//    humanPlayer = 3;  // sets the human controlled player to the center for tip off
///    player->mAnimationState2 =  activePlayerInstance[5].getModel()->getAnimationState("Walk");
///    player->mAnimationState2->setLoop(true);
///    player->mAnimationState2->setEnabled(true);

        stateSet = true;
    }
    logMsg(func +" end");

}
void teamState::updateState(gameComponentsSharedPtr gameComponent, gameFlagsSharedPtr gameFlag, gameDataSharedPtr gameData, renderEngineSharedPtr render)  // updates the state of the object
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
    std::string func = "teamState::updateState()";

    logMsg(func +" begin");
//    exit(0);

//    size_t activeBBallInstance = gameInstance->getActiveBBallInstance();

//  logMsg(func +" Updating team state " +convert->toString(teamNumber));
    if (activePlayerInstancesCreated)
    {
        
        if (!activePlayerInstancesSetup)
        {
            // setup Active Player Instances
            activePlayerInstance = gameSetupPlayer->setupActivePlayerInstances(activePlayerInstance, render);
            if (activePlayerInstance.size() != 0)
            {
                activePlayerInstancesSetup = true;
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
        
        if (!playerStartPositionsSet)
        {
            logMsg(func +" Player Start Positions Not Set!");
            if (setPlayerStartPositions(gameComponent->getCourtInstance(), gameData->getTeamStarterID()))  // sets starting positions for the players
            {
                playerStartPositionsSet = true;
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
        
        if (!playerStartDirectionsSet)
        {
            if (setPlayerStartDirections())  // sets starting directions for the players
            {
                playerStartDirectionsSet = true;
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
    if (gameFlag->getBasketballInstanceCreated() && gameFlag->getPlayerInstanceCreated())
    {
        
        basketballStateMSharedPtr activeBasketballInstance = gameComponent->getActiveBasketballInstance();
//      exit(0);
        // checks whether to execute offense or defense logic
        if (offense == true && defense == false)
        {
            logMsg(func +" offense executing");
//            exit(0);
            offenseInstance->setExecute(true);
            defenseInstance->setExecute(false);
            if (offenseInstance->getTeamType() !=  teamType)  // sets type of team for offense
            {
                offenseInstance->setTeamType(teamType);
            }
        }
        else if (defense == true && offense == false)
        {
            offenseInstance->setExecute(false);
            defenseInstance->setExecute(true);
            if (defenseInstance->getTeamType() !=  teamType)  // sets type of team for defense
            {
                defenseInstance->setTeamType(teamType);
            }
        }
        else
        {

        }

        if (gameFlag->getTipOffComplete())
        {
//          exit(0);
//          logMsg("hTeam with ball ==  "  +convert->toStringi(gameS->getTeamWithBall()));
//          logMsg("Player with ball ==  "  +convert->toString(playerWithBall));

            if (gameData->getTeamWithBall() == teamType) // checks if the team has the basketball
            {
                logMsg(func +" tipoffcomplete playerWithBallInstance == " +convert->toString(playerWithBallInstance));

                size_t x = 0;
                size_t instanceWithBall;
                for (auto APIIT : activePlayerInstance)
                {                    
                    if (APIIT.second->getData()->getID() == playerWithBallID)
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
                            playerWithBallInstance = activePlayerInstance[instanceWithBall]->getGameData()->getPassToPlayer(); // playerWithBall has changed

                            if (humanControlled)
                            {
                                humanPlayer = instanceWithBall;
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
        logMsg(func +" Team type = " +convert->toString(teamType));

        logMsg(func +" Human player = " +humanPlayer);
                                        
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

    if (gameFlag->getTipOffComplete())
    {
        logMsg(func +" tipOff Complete!");
//        exit(0);
        if (gameData->getTeamWithBall() == teamType)
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
            defenseInstance->updateState(teamType, gameComponent, gameData); // updates the state of the defenseInstance object
        }

    }
    else
    {
    }

    
//   logMsg(func +" team state updated = " +convert->toString(teamType));
}

void updateActivePlayerSettings()  // updates the settings of active players
{

}

bool teamState::setPlayerStartPositions(courtStateMSharedPtr courtInstance, teamStarterIDsVecM teamStarterID)  // sets the initial coordinates for the players.
{
    conversionSharedPtr convert = conversion::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
//    sharedPtr<gameEngine> gameE = gameEngine::Instance();
    gameSetupPlayerPositionsSharedPtr gameSetupPlayerPosition(new gameSetupPlayerPositions);
//    std::vector<std::unordered_map<std::string, size_t> > teamStarterID = gameInstance->getTeamStarterID();
    OgreVector3Vec startingPos;
//    directions playerDirection; // stores the direction players face at start
    std::string func = "teamState::setPlayerStartPositions()";
//    courtStateMSharedPtr courtInstance = gameInstance->getCourtInstance();
    Ogre::Vector3 courtPos = courtInstance[0]->getEntity()->getNodePosition();

//    exit(0);
    logMsg(func +" begining");

    logMsg(func +" courtPos.y == " +convert->toString(courtPos.y));
    float yOffset = courtPos.y + 6.0;
    
    logMsg(func +" courtpos.y == " +convert->toString(courtPos.y));
    logMsg(func +" yOffset == " +convert->toString(yOffset));

//    exit(0);

    activePlayerInstance = gameSetupPlayerPosition->setJumpBallPositions(activePlayerInstance, teamType, courtPos);
    // set initial player coordinates for the tipoff

/*    switch (teamType)
    {
        case HOMETEAM:   // assigns the positions and directions for team 1 player
            gameInstance->setYOffset(yOffset);
            // assign positions
            startingPos.push_back(Ogre::Vector3(14.4f,yOffset,352.0f));
            startingPos.push_back(Ogre::Vector3(2.0f,yOffset,347.6f));
            startingPos.push_back(Ogre::Vector3(2.0f,yOffset,360.0f));
            startingPos.push_back(Ogre::Vector3(5.2f,yOffset,351.6f));
            startingPos.push_back(Ogre::Vector3(1.6f,yOffset,352.0f));
        break;
        
        case AWAYTEAM: // assigns the positions and directions for team 2 players       
            // assign positions
            startingPos.push_back(Ogre::Vector3(-13.8f,yOffset,352.0f));
            startingPos.push_back(Ogre::Vector3(-0.8f,yOffset,347.6f));
            startingPos.push_back(Ogre::Vector3(-0.8f,yOffset,360.8f));
            startingPos.push_back(Ogre::Vector3(4.4f,yOffset,348.8f));
            startingPos.push_back(Ogre::Vector3(-0.4f,yOffset,352.0f));
        break;
    }


    if (startingPos.size() > 0)
    {
        logMsg(func +" startingPosition.size > 0");
//        exit(0);
//        for (size_t i=0;i<5;++i)
        size_t i = 0;

        size_t x = 0;
        for (auto APIIT : activePlayerInstance)
        {
            logMsg(func +" activePlayerInstance.size > 0!");
            
            std::vector<playerActions> stateAction = APIIT.second->getStateAction();
            switch (APIIT.second->getActivePosition())
            {
                case PG:
                    APIIT.second->setCourtPositionChanged(true);
                    APIIT.second->setCourtPositionChangedType(STARTCHANGE);
                    APIIT.second->setNewCourtPosition(startingPos[0]);
                    APIIT.second->setStateChanged(true);
                    stateAction.push_back(CHANGECOURTPOS);
                    APIIT.second->setStateAction(stateAction);
                    APIIT.second->getSteer()->setPlayerPosition(PG);
//                    exit(0);
                break;
                case SG:          
                    APIIT.second->setCourtPositionChanged(true);
                    APIIT.second->setCourtPositionChangedType(STARTCHANGE);
                    APIIT.second->setNewCourtPosition(startingPos[1]);
                    APIIT.second->setStateChanged(true);
                    stateAction.push_back(CHANGECOURTPOS);
                    APIIT.second->setStateAction(stateAction);
                    APIIT.second->getSteer()->setPlayerPosition(SG);
                break;
                case SF:           
                    APIIT.second->setCourtPositionChanged(true);
                    APIIT.second->setCourtPositionChangedType(STARTCHANGE);
                    APIIT.second->setNewCourtPosition(startingPos[2]);
                    APIIT.second->setStateChanged(true);
                    stateAction.push_back(CHANGECOURTPOS);
                    APIIT.second->setStateAction(stateAction);
                    APIIT.second->getSteer()->setPlayerPosition(SF);
                break;
                case PF:            
                    APIIT.second->setCourtPositionChanged(true);
                    APIIT.second->setCourtPositionChangedType(STARTCHANGE);
                    APIIT.second->setNewCourtPosition(startingPos[3]);
                    APIIT.second->setStateChanged(true);
                    stateAction.push_back(CHANGECOURTPOS);
                    APIIT.second->setStateAction(stateAction);
                    APIIT.second->getSteer()->setPlayerPosition(PF);
                break;
                case C:
                    APIIT.second->setCourtPositionChanged(true);
                    APIIT.second->setCourtPositionChangedType(STARTCHANGE);
                    APIIT.second->setNewCourtPosition(startingPos[4]);
                    APIIT.second->setStateChanged(true);
                    stateAction.push_back(CHANGECOURTPOS);
                    APIIT.second->setStateAction(stateAction);
                    APIIT.second->getSteer()->setPlayerPosition(C);
                break;
            }
        }
    }*/

    for (auto APIIT : activePlayerInstance)
    {
        logMsg(func +" APIIT.second->getStateAction().size() = " +convert->toString(APIIT.second->getGameData()->getStateAction().size()));
    }
//    exit(0);
        
    size_t x = 0;
    
///    while (x < activePlayerInstance.size())
///    {
        
///        logMsg("Team " +convert->toString(teamType) +" PlayerSteerNode" +convert->toString(x) +" Position == " +convert->toString(activePlayerInstance[x]->getNode()->getPosition()));
//        exit(0);
///        logMsg("Team " +convert->toString(teamType) +" PlayerSteer " +convert->toString(x) +" Position ==  " +convert->toString(activePlayerInstance[x]->getSteer()->position()));
///        ++x;
///    }
    
//    exit(0);
    logMsg(func +" end");
    return (true);
}

void teamState::setPlayerStartActivePositions()  // sets the position the players will play at the start of the game
{
    conversionSharedPtr convert = conversion::Instance();
    std::string func = "teamState::setPlayerStartActivePositions()";

    logMsg(func +" beginning");
    
    logMsg(func + " activePlayerInstance.size() == " +convert->toString(activePlayerInstance.size()));
    if (activePlayerInstance.size() > 0) // checks that activePlayerInstance has data before executing
    {
        activePlayerInstance[0]->getGameData()->setActivePosition(PG);
        activePlayerInstance[1]->getGameData()->setActivePosition(SG);
        activePlayerInstance[2]->getGameData()->setActivePosition(SF);
        activePlayerInstance[3]->getGameData()->setActivePosition(PF);
        activePlayerInstance[4]->getGameData()->setActivePosition(C);
    }
    // set steer IDs
    for (auto APIIT : activePlayerInstance)
    {
        //playerSteer *pSteer = activePlayerInstance[x]->getSteer();
       // pSteer->setID(x);
//FIXME!        APIIT.second->getSteer()->setID(APIIT.second->getID());
    }
    logMsg(func +" end");
}

bool teamState::setPlayerStartDirections()  // sets the initial directions for the players.
{
    conversionSharedPtr convert = conversion::Instance();

    std::vector<directions> playerDirection; // stores the direction players face at start
    std::string func = "teamState::setPlayerStartDirections()";

    logMsg(func +" beginning");
    
    for (auto APIIT : activePlayerInstance)
    {
        logMsg(func +" APIIT.second->getGameData()->getStateAction().size() = " +convert->toString(APIIT.second->getGameData()->getStateAction().size()));
    }
//    exit(0);
    
    switch (teamType)
    {
        case HOMETEAM:   // assigns the positions and directions for team 1 player
            playerDirection.push_back(LEFT);  
            playerDirection.push_back(LEFT);  
            playerDirection.push_back(LEFT);  
            playerDirection.push_back(LEFT);  
            playerDirection.push_back(LEFT);  
        break;
        case AWAYTEAM:   // assigns the positions and directions for team 2 players       
            playerDirection.push_back(RIGHT); 
            playerDirection.push_back(RIGHT); 
            playerDirection.push_back(RIGHT); 
            playerDirection.push_back(RIGHT); 
            playerDirection.push_back(RIGHT); 
        break;
    }
    
    for (auto APIIT : activePlayerInstance)
    {
        playerSMData *SMData = new playerSMData;
        std::vector<playerActions> stateAction = APIIT.second->getGameData()->getStateAction();

        logMsg(func +" activePlayerInstance.size > 0!");
//           exit(0);
        switch (APIIT.second->getGameData()->getActivePosition())
        {
            case PG:
                SMData->direction = playerDirection[0];
                APIIT.second->getFlag()->setStateChanged(true);
                stateAction.push_back(CHANGEDIRECTION);
                APIIT.second->getGameData()->setStateAction(stateAction);
//                exit(0);
            break;       
            case SG:
                SMData->direction = playerDirection[1];
                APIIT.second->getFlag()->setStateChanged(true);
                stateAction.push_back(CHANGEDIRECTION);
                APIIT.second->getGameData()->setStateAction(stateAction);
            break;
            case SF:
                SMData->direction = playerDirection[2];
                APIIT.second->getFlag()->setStateChanged(true);
                stateAction.push_back(CHANGEDIRECTION);
                APIIT.second->getGameData()->setStateAction(stateAction);
            break;
            case PF:
                SMData->direction = playerDirection[3];
                APIIT.second->getFlag()->setStateChanged(true);
                stateAction.push_back(CHANGEDIRECTION);
                APIIT.second->getGameData()->setStateAction(stateAction);
            break;
            case C:
                SMData->direction = playerDirection[4];
                APIIT.second->getFlag()->setStateChanged(true);
                stateAction.push_back(CHANGEDIRECTION);
                APIIT.second->getGameData()->setStateAction(stateAction);
            break;
        }
        
        
/*        if (!APIIT.second->getSMStartDirectionSet())  // sets the start value of direction if it has not been set already
        {                   
//            SMData->node = APIIT.second->getNode();
            APIIT.second->setStateChanged(true);
            if (APIIT.second->updateStateMachine(CHANGEDIRECTION, SMData))
            {
                APIIT.second->setSMStartDirectionSet(true);
                logMsg(func +" stateMachine direction has been set!");
            }
            else
            {
                logMsg(func +" Unable to set stateMachine direction");
                exit(0);
            }
//                    exit(0);
        }
        else
        {
            logMsg(func +" stateMachine direction already set");
        }*/
    }
    
    for (auto APIIT : activePlayerInstance)
    {
        logMsg(func +" APIIT.second->getGameData()->getStateAction().size() = " +convert->toString(APIIT.second->getGameData()->getStateAction().size()));
    }
    
    logMsg(func +" end");
//    exit(0);
    return (true);
}

void teamState::updateActivePlayers()  // updates the states of active players
{
    conversionSharedPtr convert = conversion::Instance();
    std::string func = "teamState::updateActivePlayers()";

    logMsg(func +" beginning");
    
    for (auto APIIT : activePlayerInstance)
    {
        logMsg(func +" APIIT.second->getGameData()->getStateAction().size() = " +convert->toString(APIIT.second->getGameData()->getStateAction().size()));
    }
//    exit(0);
    
    for (auto APIIT : activePlayerInstance)  // executes updates to activePlayerInstances
    {
        APIIT.second->update();
    }
//    exit(0);
//FIXME! Needs refactored after playerStateMachine migration
/*    conversionSharedPtr convert = conversion::Instance();
    std::string func = "teamState::updatePlayerStates()";
    size_t x = 0;
    
    logMsg(func +" beginning");
//    exit(0);
    //    while (x<activePlayerInstance.size())
    for (auto APIIT : activePlayerInstance)
    {
        std::string xString = convert->toString(x);
        APIIT.second->updateState();
        logMsg(func +" " +xString + " Name == " +APIIT.second->getData()->getFirstName() +" " +APIIT.second->getData()->getLastName());
        logMsg(func +" " +xString + " Entity UC Name == " +APIIT.second->getEntityName());
        logMsg(func +" " +xString + " Entity UC Node Name == " +APIIT.second->getEntityNodeName());
        logMsg(func +" " +xString + " UC Node Name == " +APIIT.second->getNode()->getName());




//        APIIT.second->getNode()->setPosition(Ogre::Vector3(-20,15,400));
///        logMsg(func +" APIIT.second->getPlayerEntity()->getNode()->getPosition() == " +convert->toString(APIIT.second->getNode()->getPosition()));
///        logMsg("PlayerSteerNode Position == " +convert->toString(APIIT.second->getNode()->getPosition()));
///        logMsg("PlayerSteer Position == " +convert->toString(APIIT.second->getSteer()->position()));
        ++x;
        
    }

//    exit(0);
*/
    logMsg(func +" end");

}

void teamState::updatePlayerDirections(gameComponentsSharedPtr gameComponent)  // updates the direction players are facing
{
    conversionSharedPtr convert = conversion::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();

    directions playerDirection, oldPlayerDirection;
//    playerStateVec pInstance = getPlayerInstance();
 //   sizeTVec playerDirection = player->getPlayerDirection(); // stores contents of playerDirectdion from players class in local variable
//    sizeTVec oldPlayerDirection = player->getOldPlayerDirection();   // stores contents of oldPlayerDirection form players in local variable
    basketballStateMSharedPtr basketballInstance = gameComponent->getBasketballInstance();
    std::vector<Ogre::SceneNode>::iterator playersIT;

    std::string playerID = convert->toString(playerInstance[4]->getData()->getID());
//    exit(0);
//    logMsg("playerID == " +playerID);
    // checks if a player's direction has changed and rotates the model accordingly.
//    for(playersIT = playerNodes.begin(); playersIT != playerNodes.end(); ++playersIT)

    size_t x = 0;
    size_t y = 0;

    exit(0);
    for (auto APIIT : activePlayerInstance)
    {
        playerDirection = APIIT.second->getGameData()->getDirection();
        oldPlayerDirection = APIIT.second->getGameData()->getOldDirection();
        if (oldPlayerDirection != playerDirection)
        {
            
            
///            std::string oldPlayerDirect = Ogre::SingConverter::toString(oldPlayerDirection[i]);
///            std::string playerDirect = toString(playerDirection[i]);
///            std::string bballPlayer = toString(basketballInstance[activeBBallInstance].getPlayer());
///            logMsg("oldPlayerDirection = " + oldPlayerDirect);
///            logMsg("playerDirection = " + playerDirect);
///            logMsg("bball player = " + bballPlayer);
///            playerInstance[basketballInstance[activeBBallInstance]->getPlayer()] = playerInstance[i];
//            playerNodes.at(basketballInstance[activeBBallInstance]->getPlayer()) = playerNodes.at(i);  // sets the current player node
            
            switch (oldPlayerDirection)
            {
                case UP:
                    switch (playerDirection)
                    {
                        case DOWN:
                            APIIT.second->getNode()->yaw(Ogre::Degree (180));
                            break;
                        case LEFT:
                            APIIT.second->getNode()->yaw(Ogre::Degree (270));
                            break;
                        case RIGHT:
                            APIIT.second->getNode()->yaw(Ogre::Degree (90));
//                            exit(0);
                            break;
                        default:
                            break;
                    }
                    break;
                case DOWN:
                    switch (playerDirection)
                    {
                        case UP:
                            APIIT.second->getNode()->yaw(Ogre::Degree (180));
                            break;
                        case LEFT:
                            APIIT.second->getNode()->yaw(Ogre::Degree (90));
                            break;
                        case RIGHT:
                            APIIT.second->getNode()->yaw(Ogre::Degree (270));
                            break;
                        default:
                            break;
                    }
                    break;
                    case LEFT:
                        switch (playerDirection)
                        {
                            case UP:
                                APIIT.second->getNode()->yaw(Ogre::Degree (90));
                                break;
                            case DOWN:
                                APIIT.second->getNode()->yaw(Ogre::Degree (270));
                                break;
                            case RIGHT:
                                APIIT.second->getNode()->yaw(Ogre::Degree (180));
                                break;
                            default:
                                break;
                        }
                        break;
                    case RIGHT:
                        switch (playerDirection)
                        {
                            case UP:
                                APIIT.second->getNode()->yaw(Ogre::Degree (270));
                                break;
                            case DOWN:
                                APIIT.second->getNode()->yaw(Ogre::Degree (90));
                                break;
                            case LEFT:
                                APIIT.second->getNode()->yaw(Ogre::Degree (180));
                                break;
                            default:
                                break;
                        }
                        break;
                default:
                    break;
            }
        }
        logMsg("directPlayerID == " +convert->toString(APIIT.second->getData()->getID()));
        logMsg("directPlayerWithBallInstance == " +convert->toString(playerWithBallInstance));
        if (APIIT.second->getData()->getID() != playerWithBallID)
        {
            oldPlayerDirection = playerDirection;
            APIIT.second->getGameData()->setOldDirection(oldPlayerDirection);  // copies contents of oldPlayerDirection to the oldDirection variable
        }
        else
        {
        }
///            }
///            ++y;
///        }

//        ++x;
    }

}


void teamState::updatePlayerMovements()  // updates player movements
{
    //conversion *convert = conversion::Instance();
    conversionSharedPtr convert = conversion::Instance();
    
    Ogre::Vector3 posChange;    // stores change in position
    posChange = Ogre::Vector3(0.0f, 0.0f, 0.0f);

    for (auto APIIT : activePlayerInstance)
    {
        if (APIIT.second->getFlag()->getMovement()) // if true sets coordinate change accordingly
        {
//                    exit(0);
            if (APIIT.second->getGameData()->getDirection() == UP)
            {
                posChange = Ogre::Vector3(0.0f, 0.0f, -0.400f);
                logMsg("UP!");
//              exit(0);
            }
            else if (APIIT.second->getGameData()->getDirection() == DOWN)
            {
                posChange = Ogre::Vector3(0.0f, 0.0f, 0.400f);
            }
            else if (APIIT.second->getGameData()->getDirection() == LEFT)
            {
//              exit(0);

                posChange = Ogre::Vector3(-0.400f, 0.0f, 0.0f);
//              playerInstance[i]->getPhysBody()->setLinearVelocity(btVector3(0.4,0,0));
            }
            else if (APIIT.second->getGameData()->getDirection() == RIGHT)
            {
                posChange = Ogre::Vector3(0.400f, 0.0f, 0.0f);
            }
            else if (APIIT.second->getGameData()->getDirection() == UPLEFT)
            {
                posChange = Ogre::Vector3(-0.400f, 0.0f, -0.400f);
            }
            else if (APIIT.second->getGameData()->getDirection() == UPRIGHT)
            {
                posChange = Ogre::Vector3(0.400f, 0.0f, -0.400f);
            }
            else if (APIIT.second->getGameData()->getDirection() == DOWNLEFT)
            {
                posChange = Ogre::Vector3(-0.400f, 0.0f, 0.400f);
            }
            else if (APIIT.second->getGameData()->getDirection() == DOWNRIGHT)
            {
                posChange = Ogre::Vector3(0.400f, 0.0f, 0.400f);
            }

        }
        else if (!APIIT.second->getFlag()->getMovement())   // if false then sets their coordinate changes to 0.0
        {
            posChange = Ogre::Vector3(0.0f, 0.0f, 0.0f);
        }

        if (posChange.x != 0 || posChange.y != 0 || posChange.z != 0)
        {
            APIIT.second->getGameData()->setNewCourtPosition(posChange);    // sets the newCourtPosition for current playerInstance
            APIIT.second->getFlag()->setCourtPositionChanged(true);
            APIIT.second->getGameData()->setCourtPositionChangedType(INPUTCHANGE);
            APIIT.second->getFlag()->setMovement(false);
        }       
//        ++x;
    }

//  exit(0);
}

// FIXME! update for class reorganization

void teamState::executePass()  // executes the pass between players
{

//FIXME! Needs fixed after playerStateMachine is implemented
/*
    //conversion *convert = conversion::Instance();
    conversionSharedPtr convert = conversion::Instance();
    //gameState *gameS = gameState::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
//    size_t activeBBallInstance = gameInstance->getActiveBBallInstance();
    playerPositions passToPlayer = activePlayerInstance[convert->toString(playerWithBallInstance)]->getPassToPlayer();
//    basketballStateVecSharedPtr basketballInstance = gameInstance->getBasketballInstance();
    basketballStateMSharedPtr activeBasketballInstance = gameInstance->getActiveBasketballInstance();
    Ogre::Vector3 playerWithBallCoords = activePlayerInstance[convert->toString(playerWithBallInstance)]->getNode()->getPosition();
    Ogre::Vector3 passToPlayerCoords = activePlayerInstance[convert->toString(passToPlayer)]->getNode()->getPosition();
//  exit(0);
    // FIXME! HARDCODED
    Ogre::Vector3 bballCoords = activeBasketballInstance[0]->getNode()->getPosition();
    btVector3 bballPosChange;
    btVector3 bballPhysCoords;
    btTransform transform;
//  exit(0);
    std::string func = "teamState::executePass()";
    
    logMsg(func +" beginning");

    logMsg(func +" Basketball = " + convert->toString(bballCoords));
    logMsg(func +" passToPlayer = " + convert->toString(passToPlayerCoords));

    if (bballCoords[1] != passToPlayerCoords[1])
    {
        bballCoords[1] = passToPlayerCoords[1];
        // FIXME! HARDCODED
        activeBasketballInstance[0]->getNode()->setPosition(bballCoords);
        bballPhysCoords = BtOgre::Convert::toBullet(bballCoords); // converts from Ogre::Vector3 to btVector3
        transform.setOrigin(bballPhysCoords);
        // FIXME! HARDCODED
        activeBasketballInstance[0]->getPhysics()->getPhysBody()->setWorldTransform(transform);


    }
    if (bballCoords[0] < passToPlayerCoords[0])
    {
        if (bballCoords[2] < passToPlayerCoords[2])
        {
//          basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(15,0,15));
            bballPosChange[0] = 15;
            bballPosChange[2] = 15;
        }
        else if (bballCoords[2] > passToPlayerCoords[2])
        {
//          basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(15,0,-15));
            bballPosChange[0] = 15;
            bballPosChange[2] = -15;

        }
        else
        {
        }
    }
    else if (bballCoords[0] > passToPlayerCoords[0])
    {
        if (bballCoords[2] < passToPlayerCoords[2])
        {
//          basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(-15,0,15));
            bballPosChange[0] = -15;
            bballPosChange[2] = 15;

        }
        else if (bballCoords[2] > passToPlayerCoords[2])
        {
//          basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(-15,0,-15));
            bballPosChange[0] = -15;
            bballPosChange[2] = -15;

        }
        else
        {
        }
    }
    else
    {
    }

    activeBasketballInstance[0]->getPhysics()->getPhysBody()->setLinearVelocity(btVector3(bballPosChange));


    gameInstance->setActiveBasketballInstance(activeBasketballInstance);        // saves changes to the basketballInstance object
*/
}


void teamState::updatePositions()  // updates player on court positions
{
//FIXME! Needs reworked after playerStateMachine migration
/*
    //conversion *convert = conversion::Instance();
    conversionSharedPtr convert = conversion::Instance();
    
//    size_t x = 0;
    // updates the player positions on the court
//    while (x<activePlayerInstance.size())
    for (auto APIIT : activePlayerInstance)
    {
        exit(0);
//      logMsg("updatePositions X = " +convert->toString(x));
        APIIT.second->updateCourtPosition();
//        x++;
    }
    logMsg("courtPosition updated!!");
*/
}


