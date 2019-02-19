/***************************************************************************
 *   Copyright (C) 1999 - 2019 by Mike McLean                              *
 *   libolt@libolt.net                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed".  .  " in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "entity/gameentity.h"
#include <unordered_map>
#include "engine/networkengine.h"
#include "ai/ai.h"
#include "ai/basketballsteer.h"
#include "components/basketballcomponents.h"
#include "components/gamecomponents.h"
#include "components/playercomponents.h"
#include "components/teamcomponents.h"
#include "data/gamedata.h"
#include "data/teamgamedata.h"
#include "entity/playerentity.h"
#include "entity/teamentity.h"
#include "utilities/conversion.h"
#include "entity/basketballentity.h"
#include "entity/courtentity.h"
#include "entity/hoopentity.h"
#include "flags/gameflags.h"
#include "flags/playerflags.h"
#include "flags/teamflags.h"
#include "jumpballs/jumpballs.h"
#include "setup/setupbasketballs.h"
#include "setup/setupcourts.h"
#include "setup/setuphoops.h"
#include "setup/setupplayers.h"
#include "setup/setupteams.h"
#include "statemachine/gamestatemachine.h"
#include "entity/gameentity.h"
#include "state/networkstate.h"
#include "engine/gameengine.h"
#include "load/loadbasketballs.h"
#include "load/loadcourts.h"
#include "load/loadhoops.h"
#include "load/loadplayers.h"
#include "load/loadteams.h"
#include "utilities/logging.h"
#include "utilities/typedefs.h"
#include "network/networkplayerstateobject.h"
#include "data/basketballdata.h"
#include "data/courtdata.h"
#include "data/gamedata.h"
#include "data/playerdata.h"
#include "engine/physicsengine.h"
#include "engine/renderengine.h"
#include "utilities/timing.h"
#include "ubc/ubc.h"
#include "users/users.h"

gameEntity::gameEntity()  // constructor
{
//    stateSet = false;
    objectsInitialized = false;
    componentInitialized = false;
    dataInitialized = false;
    flagInitialized = false;
    SMData = nullptr;
    stateMachineInitialized = false;

}

gameEntity::~gameEntity() = default;  // destructor

bool gameEntity::getObjectsInitialized() const  //  retrieves the value of objectsInitialized
{
    return (objectsInitialized);
}
void gameEntity::setObjectsInitialized(const bool &set)  //  sets the value of objectsInitialized
{
    objectsInitialized = set;
}

bool gameEntity::assignHoopToTeams()  // assigns which hoop belongs to each team
{
//TS    getActiveTeamInstance()[0]->setHoop(1);
//TS    getActiveTeamInstance()[1]->setHoop(0);
    return (true);
}

bool gameEntity::getComponentInitialized() const  // retrieves the value of componentInitialized
{
    return (componentInitialized);
}
void gameEntity::setComponentInitialized(const bool &set)  // sets the value of componentInitialized
{
    componentInitialized = set;
}

bool gameEntity::getDataInitialized() const  // retrieves the value of dataInitialized
{
    return (dataInitialized);
}
void gameEntity::setDataInitialized(const bool &set)  // sets the value of dataInitialized
{
    dataInitialized = set;
}

bool gameEntity::getFlagInitialized() const  // retrieves the value of flagInitialized
{
    return (flagInitialized);
}
void gameEntity::setFlagInitialized(const bool &set)  // sets the value of flagInitialized
{
    flagInitialized = set;
}

bool gameEntity::getStateMachineInitialized() const  // retrieves the value of stateMachineInitialized
{
    return (stateMachineInitialized);
}
void gameEntity::setStateMachineInitialized(const bool &set)  // sets the value of stateMachineInitialized
{
    stateMachineInitialized = set;
}

gameComponentsSharedPtr gameEntity::getComponent() const  // retrieves the value of component
{
    return (component);
}
void gameEntity::setComponent(const gameComponentsSharedPtr &set)  // sets the value of component
{
    component = set;
}

gameDataSharedPtr gameEntity::getData() const  // retrieves the value of data
{
    return (data);
}
void gameEntity::setData(const gameDataSharedPtr &set)  // sets the value of data
{
    data = set;
}

gameFlagsSharedPtr gameEntity::getFlag() const  // retrieves the value of flag
{
    return (flag);
}
void gameEntity::setFlag(const gameFlagsSharedPtr &set)  // sets the value of flag
{
    flag = set;
}

gameStateMachineSharedPtr gameEntity::getStateMachine() const  // retrieves the value of stateMachine
{
    return (stateMachine);
}
void gameEntity::setStateMachine(const gameStateMachineSharedPtr &set)  // sets the value of stateMachine
{
    stateMachine = set;
}

bool gameEntity::setupActiveTeamInstances()  // sets up the active team instances
{
//    teamStateSharedPtr tInstance;
    teamEntityMSharedPtr activeTeamInstance = component->getActiveTeamInstance();
    teamEntityMSharedPtr teamInstance = component->getTeamInstance();
    sizeTVec teamIDS = data->getTeamIDS();
    std::string func = "gameEntity::setupActiveTeamInstances()";

    logMsg(func +" begin");
    exit(0);
//    activeTeamInstance.insert(std::pair<size_t, teamStateSharedPtr>(0, tInstance));  // adds empty teamState to activeTeamInstance vector
//    activeTeamInstance.insert(std::pair<size_t, teamStateSharedPtr>(1, tInstance));  // adds empty teamState to activeTeamInstance vector
//    exit(0);
/*TS    activeTeamInstance[0] = teamInstance[teamIDS[0]];
    activeTeamInstance[1] = teamInstance[teamIDS[1]];
    activeTeamInstance[0]->setID(teamIDS[0]);
    activeTeamInstance[1]->setID(teamIDS[1]);
*/    
    activeTeamInstance[0]->getGameData()->setTeamType(HOMETEAM);
    activeTeamInstance[1]->getGameData()->setTeamType(AWAYTEAM);
    activeTeamInstance[0]->getFlag()->setHumanControlled(true);
    activeTeamInstance[1]->getFlag()->setHumanControlled(false);
    activeTeamInstance[0]->getGameData()->setTeamColObject(COL_TEAM1);
    activeTeamInstance[1]->getGameData()->setTeamColObject(COL_TEAM2);
    activeTeamInstance[0]->getGameData()->setTeamCollidesWith(COL_COURT); // | COL_BBALL | COL_TEAM2;   determines what team0 collides with
    activeTeamInstance[1]->getGameData()->setTeamCollidesWith(COL_COURT); // | COL_BBALL | COL_TEAM2;   determines what team1 collides with

    activeTeamInstance[0]->setObjectsInitialized(activeTeamInstance[0]->initializeObjects());  // initializes active team 0's objects
    activeTeamInstance[1]->setObjectsInitialized(activeTeamInstance[1]->initializeObjects());  // initializes active team 1's objects

    component->setActiveTeamInstance(activeTeamInstance);
    std::vector<bool> teamActivePlayersChanged;
    // hard coded.  Shood be changed

    for (int x=0;x<activeTeamInstance.size();++x)
    {
        teamActivePlayersChanged.push_back(false);
    }
    data->setTeamActivePlayersChanged(teamActivePlayersChanged);
    logMsg(func +" end");
    return (true);
}

bool gameEntity::initializeObjects()  // initializes the basketball objects
{
    bool retVal = false;
    
    if (!componentInitialized)
    {
        gameComponentsSharedPtr tempComponent(new gameComponents);
        component = tempComponent;
        componentInitialized = true;
    }
    else
    {
    }

    if (!dataInitialized)
    {
        gameDataSharedPtr tempData(new gameData);
        data = tempData;
        dataInitialized = true;
    }
    else
    {
    }
    
    if (!flagInitialized)
    {
        gameFlagsSharedPtr tempFlag(new gameFlags);
        flag = tempFlag;
        flagInitialized = true;
        
    }
    else
    {
    }
    
    if (!stateMachineInitialized)
    {
        gameStateMachineSharedPtr tempStateMachine(new gameStateMachine);
        stateMachine = tempStateMachine;       
        stateMachineInitialized = true;
    }
    else
    {
    }
    
    if (componentInitialized && dataInitialized  && flagInitialized && stateMachineInitialized )
    {
        retVal = true;
    }
    
    return (retVal);
}


bool gameEntity::initializeStateMachine(const renderEngineSharedPtr &render)  // sets up the game condition
{
    std::string func = "gameEntity::initializeStateMachine()";
    auto *tempSMData(new gameSMData);

    logMsg(func +" begin");

    if (!objectsInitialized)
    {
        logMsg(func +" Initializing objects!");
        objectsInitialized = initializeObjects();
    }
    else
    {
        logMsg(func +" Objects already initialized!");
    }
    
    SMData = tempSMData;
    SMData->component = component;
    SMData->flag = flag;
//    SMData->node = getNode();
    
//    component->getStateMachine()->setSpeed(SMData);
//    component->getStateMachin
    gameStateMachineSharedPtr tempSM(new gameStateMachine);
    stateMachine = tempSM;
    stateMachine->pCreateInstances(SMData);
//    exit(0);
    logMsg(func +" end");

    return (true);
}

// sets up the game condition
/*bool gameEntity::setupState(renderEngineSharedPtr render)  // sets up the game condition
{
//    exit(0);

    AISystemSharedPtr ai = AISystem::Instance();
//    renderEngineSharedPtr render = renderEngine::Instance();
//    sharedPtr<loader> load = loader::Instance();
    //sharedPtr<physicsEngine> physEngine = physicsEngine::Instance();
    physicsEngine physEngine;
    conversionSharedPtr convert ;
    setupBasketballsSharedPtr setupBasketball(new setupBasketballs);
    setupCourtsSharedPtr setupCourt(new setupCourts);
    setupHoopsSharedPtr setupHoop(new setupHoops);
    setupTeamsSharedPtr setupTeam(new setupTeams);
//    courtStateMSharedPtr courtInstance = getCourtInstance();
//    hoopStateMSharedPtr hoopInstance = getHoopInstance();

    std::string func = "gameEntity::setupState()";
   
    logMsg(func +" begin");
    

//    logMsg("court y == " +convert->toString(getCourtInstance()[0].getNode()->getPosition().y));
//    exit(0);
    component->setTeamInstance(setupTeam->createTeamInstances());  // creates team instances
    if (component->getTeamInstance().size() > 0)
    {
        
//        if(createTeamInstances())  // creates the team instances
//        {
            logMsg(func +" TIC!");
            getFlag()->setTeamInstancesCreated(true);
//            assignHoopToTeams();  // assigns proper hoop to the teams that were created.
//        }
    }

    // sets the quarter being played to the first one.
    data->setQuarter(FIRST);
//    basketballInstance[activeBBallInstance].getNode()->setPosition(1.4f,5.0f,366.0f);


/// FIXME    physEngine.setupState();  // sets up the Physics Engine state
//    exit(0);
    
    if (!getFlag()->getActiveTeamInstancesSetup())
    {
        if (setupActiveTeamInstances())
        {
            logMsg(func +" Team instances setup!");
            getFlag()->setActiveTeamInstancesSetup(true);
        }
        else
        {
            logMsg(func +" Unable to setup team instances!");
            exit(0);
        }
    }
    else
    {
        
    }
    
    for (auto ATIIT : component->getActiveTeamInstance())
    {
        if (ATIIT.second->getFlag()->getActivePlayerInstancesCreated())
        {
            logMsg(func +" activePlayerInstances Created!");
//            exit(0);
        }
        else
        {
            logMsg(func + " activePlayerInstances NOT Created!!");
            exit(0);
        }
        logMsg(func +" team name == " +ATIIT.second->getData()->getName());
        logMsg(func +" ATIIT.second->getActivePlayerInstance().size() == " +convert->toString(ATIIT.second->getComponent()->getActivePlayerInstance().size()));
    }
//    exit(0);

//FIXME!AI    ai->setup(getActiveBasketballInstance(), getActiveCourtInstance(), getActiveTeamInstance(), getTeamWithBall(), getHumanPlayer());

//        Ogre::Entity *ent;
//        ent = player->getModel(0);
//        player->mAnimationState2 = ent->getAnimationState("Walk");
//        std::vector<Ogre::Entity*> playerModels = player->getModel();
//        std::vector<Ogre::SceneNode*> playerNodes = player->getNode();
//    playerStateVec pInstance = getPlayerInstance();
//        player->setModel(playerModels);
//    Ogre::Vector3 playerPos = playerNodes.at(0)->getPosition();
//    Ogre::Vector3 offset;
//    offset[0] = 2.0f;
//    offset[1] = 2.0f;
//    offset[2] = 2.0f;
//  bball->setAutoTracking(true,playerNode[0],playerNode[0]->getPosition(),offset);
//  bball->setPosition(playerPos[0] +2.0f, playerPos[1] + 4.0f, playerPos[2] - 1.0f);
    logMsg(func +" dahdah");
    

    if (!getFlag()->getSetupEnvironmentCompleted())  // checks if environment has been setup
    {
        logMsg(func +" !setupEnvironmentCompleted");
        if(setupEnvironment())  // sets up environment
        {
            logMsg(func +" Environment setup successfully!");
            getFlag()->setSetupEnvironmentCompleted(true);
        }
    }
//    loads("../../data/players/players.xml");
    
    if (!getFlag()->getTipOffSetupComplete())
    {
        logMsg(func +" !tipOffSetupComplete");
        if (setupTipOff())
        {
            logMsg(func + " Tip Off Setup Complete!");
            getFlag()->setTipOffSetupComplete(true);  // sets up tip off conditions
        }
    }
    
    logMsg(func +" end");

    return true;
}*/

bool gameEntity::updateState(const renderEngineSharedPtr &render)  // updates the game state
{
    conversionSharedPtr convert ;
//    AISystemSharedPtr ai = AISystem::Instance();
    timing timer; 
    Ogre::Vector3 playerPos;
    basketballEntityMSharedPtr activeBasketballInstance = component->getActiveBasketballInstance();
    
//    teamEntityMSharedPtr activeTeamInstance = getActiveTeamInstance();
    std::string func = "gameEntity::updateState()";

//    SMData = tempSMData;
//    exit(0);
    logMsg(func +" begin");
    
    if (flag->getStateMachineInitialized())
    {
        exit(0);
        if (!flag->getModelsLoaded())
        {
            logMsg(func +" Models Not Loaded yet!");
            
            // copies required objects to SMData
            auto *modelsSMData(new gameSMData);
            modelsSMData->component = component;
            exit(0);
            modelsSMData->flag = flag;
            modelsSMData->render = render;

            stateMachine->pLoadModels(modelsSMData);
//            stateMachine->pCreateNodes(SMData);

        }
        else
        {
            logMsg(func +" Models Already Loaded!");
            logMsg(func +" activeBasketballInstance.size() == " +convert->toString(activeBasketballInstance.size()));
 
        }
        if (flag->getModelsLoaded() && !flag->getNodesCreated())
        {
            logMsg(func +" Nodea Not Created yet!");
            auto *nodesSMData(new gameSMData);

            nodesSMData->component = component;
//            exit(0);
            nodesSMData->flag = flag;
            nodesSMData->render = render;
            stateMachine->pCreateNodes(nodesSMData);

//            stateMachine->pCreateNodes(SMData);
            exit(0);
        }
        else
        {
            
        }
        
        if (flag->getNodesCreated() && !flag->getStartPositionsSet())
        {
            logMsg(func +" Start Positions Not Set yet!");
            auto *startPosSMData(new gameSMData);

            startPosSMData->component = component;
            startPosSMData->flag = flag;
            startPosSMData->render = render;
            stateMachine->pSetStartPositions(startPosSMData);
            exit(0);
        }
        else
        {
            for (auto ABIIT : activeBasketballInstance)
            {          
                logMsg(func +"Active Basketball Pos == " +convert->toString(ABIIT.second->getComponent()->getNode()->getPosition()));
                exit(0);
            }
  
        }
        if (flag->getStartPositionsSet() && !flag->getJumpBallSetup())  // calls tip off execution
        {
            logMsg(func +" Jump Ball Not Setup yet!");
            auto *jumpBallSetupSMData(new gameSMData);

            jumpBallSetupSMData->component = component;
            jumpBallSetupSMData->gData = data;
            jumpBallSetupSMData->flag = flag;
            jumpBallSetupSMData->render = render;
            stateMachine->pSetupJumpBall(jumpBallSetupSMData);
            if (component->getJumpBall()->getSetupComplete())
            {
                flag->setJumpBallSetup(true);
            }
            else
            {
                
            }
        }
        else
        {
            logMsg(func +" Jump Ball Already Setup!");
        }
        
        if (flag->getJumpBallSetup() && !flag->getTipOffComplete())  // calls tip off execution
        {
            logMsg(func +" Tip Off Not Complete yet!");
//            exit(0);
            auto *jumpBallExecuteSMData(new gameSMData);

            jumpBallExecuteSMData->component = component;
            jumpBallExecuteSMData->gData = data;
            jumpBallExecuteSMData->flag = flag;
            jumpBallExecuteSMData->render = render;
            stateMachine->pExecuteJumpBall(jumpBallExecuteSMData);
            if (flag->getJumpBallExecuteComplete())
            {
                flag->setTipOffComplete(true);
                flag->setJumpBallExecuteComplete(false);
            }
            else
            {
                
            }
        }
        else
        {
            logMsg(func +" Jump Ball ExecutionComplete!");
        }
    }
    
    if (getFlag()->getInputReceived())
    {
        logMsg(func +" received input!");
        for (auto IIGWQ : component->getInputInGameWorkQueue())
        {
            logMsg (func +" INQ = " +convert->toString(IIGWQ));
        }
//        exit(0);
    }
//    exit(0);
//    logMsg("Updating gameEntity Logic");

// BEGINING OF TEST COMMENT
    
//    conversionSharedPtr convert ;
//    sharedPtr<gameEngine> gameE = gameEngine::Instance();
//    networkEngineSharedPtr network = networkEngine::Instance();
    //sharedPtr<physicsEngine> physEngine = physicsEngine::Instance();
//    physicsEngine physEngine;
    
    for (auto ABIIT : activeBasketballInstance)
    {
        ABIIT.second->updateState(component, data, flag);
        ABIIT.second->getComponent()->setPlayer(5);
    }
  
    component->setActiveBasketballInstance(activeBasketballInstance);
    if (data->getGameType() == SINGLE)
    {
        logMsg(func +" gameType == SINGLE");
    }
    else if (data->getGameType() == NOGAME)
    {
        logMsg(func +" gameType == NOGAME");
    }
    logMsg(func +" blah");
//    exit(0);
    if (getFlag()->getSetupComplete())
    {

        logMsg(func + " Game Setup Complete!");
//        exit(0);
//       FIXME!        
/*        if (getBase()->getNetworkS()->getPacketReceived())  // checks if a packet was received by network engine
        {
            getBase()->getNetworkS()->processNetworkEvents(getAcyiveTeamInstance());  // processes data received from the network
        }
        else
        {
            
        }
 */     
        logMsg(func +" network events processed");

        logMsg(func +" getActiveTeamInstance().size() == " +convert->toString(component->getActiveTeamInstance().size()));

        teamEntityMSharedPtr activeTeamInstance = component->getActiveTeamInstance();
        if (!activeTeamInstance.empty())
        {
            logMsg(func + " activeTeamInstance.size() == " +convert->toString(activeTeamInstance.size()));
            for (auto ATIIT : activeTeamInstance)
            {
                playerEntityMSharedPtr activePlayerInstance = ATIIT.second->getComponent()->getActivePlayerInstance();
                if (ATIIT.second->getFlag()->getActivePlayerInstancesCreated())
                {
                    logMsg(func +" Wiot!");
                    logMsg(func + " activePlayerInstance.size() == " +convert->toString(activePlayerInstance.size()));
        
                    for (auto APIIT : activePlayerInstance)
                    {
                        if (APIIT.second->getFlag()->getSMNodeSet())
                        {
                            logMsg(func +" Wioooot!");
                            Ogre::Vector3 pos = APIIT.second->getComponent()->getNode()->getPosition();
                            logMsg(func +" pos = " +convert->toString(pos));
                        }
                    }
                }
            }
            
        }
//        exit(0);
        
/*FIXME!AI        if (getTeamWithBall() != NOTEAM)
        {
//          logMsg("teamWithBall is " +convert->toString(teamWithBall));
//          logMsg("playetWithBall is " +convert->toString(teamInstance[teamWithBall].getPlayerWithBall()));
//          float currentTime = static_cast<float>(gameE->getLoopTime().getMilliseconds()/100);
            long currentTime = timer.getLoopTimeMill().count();
            float oldTime = ai->getOldTime();
            float changeInTime = currentTime - oldTime;
   //         ai->update(currentTime, changeInTime);
            logMsg("CHANGE == " +convert->toString(changeInTime));

            if (changeInTime >= .5f)
            {
                logMsg("ELAPSED == " +convert->toString(changeInTime));
//              exit(0);
//              ai->update(aiTimer.getTotalSimulationTime (), aiTimer.getElapsedSimulationTime ());
                ai->update(currentTime, changeInTime);
                ai->setOldTime(currentTime);
            }
            else
            {
                
            }
        }
        else
        {
            
        }*/

        if (updateActiveTeamInstances(render))
        {
            logMsg(func +" active team instances updated!");
        }
        else
        {
            logMsg(func +" active team instances NOT updated!");          
        }
        
        logMsg(func +" Physics");
//      FIXME! physics engine needs some reworking
//        physEngine.updateState();   // updates the state of the physics simulation
        logMsg(func +" stepWorld");
//        exit(0);
//        physEngine.stepWorld(getTimer());  // steps the physics simulation
///    logMsg("DirectionsAndMovement");
///    updateDirectionsAndMovements();

//    exit(0);

        // updates the basketball(s) state
//        logMsg("Updated basketball state!");
//        exit(0);
//        renderBall();
//        SceneNode *bball = basketballInstance[activeBBallInstance].getNode();
//        bball->setPosition(basketballInstance[activeBBallInstance].calculatePositionChange());
//        basketballInstance[activeBBallInstance].setNode(bball);

//        Ogre::Vector3 change = basketballInstance[activeBBallInstance].calculatePositionChange();
//        cout << "Calced Pos change = " << basketballInstance[activeBBallInstance].calculatePositionChange() << endl;
//        basketballInstance[activeBBallInstance].nodeChangePosition(basketballInstance[activeBBallInstance].calculatePositionChange());

//        sizeTVec playerDirection = player->getPlayerDirection(); // stores contents of playerDirectdion from players class in local variable
//        sizeTVec oldPlayerDirection = player->getOldPlayerDirection();   // stores contents of oldPlayerDirection form players in local variable

        // Initiates offense or defense for a team depending on value of teamWithBall

    }

//  logMsg("gameEntity logic updated");
//    exit(0);

    logMsg(func +" end");

    return true;
}

bool gameEntity::updateActiveTeamInstances(const renderEngineSharedPtr &render)  // updates all active team instances
{
    teamEntityMSharedPtr activeTeamInstance = component->getActiveTeamInstance();
    conversionSharedPtr convert ;
    gameEntitySharedPtr gameInstance;
    std::string func = "gameEntity::updateActiveTeamInstances()";

    logMsg(func +" begin");
//    exit(0);
    // temporary hack
    logMsg(func +" activeTeamInstance.size() == " +convert->toString(activeTeamInstance.size()));
    
    for (auto ATIIT : activeTeamInstance)
    {
        ATIIT.second->updateState(component, flag, data, render);
//        exit(0);
    }
//FIXME! Needs fixed for playerStateMachine refactoring
/*
    std::vector<bool> tActivePlayersChanged = getTeamActivePlayersChanged();
    bool activePlayersChanged = false;
//    tActivePlayersChanged.assign();
//    tActivePlayersChanged.insert(activePlayersChanged);

    // updates the state of each team
    if (getActiveTeamInstancesCreated())
    {
        if (getTeamWithBallChanged())
        {
            if (getTeamWithBall() == HOMETEAM)  // if 0 puts team 0 on offense and team 1 on defense
            {
                activeTeamInstance[HOMETEAM]->setOffense(true);
                activeTeamInstance[HOMETEAM]->setDefense(false);

                activeTeamInstance[AWAYTEAM]->setOffense(false);
                activeTeamInstance[AWAYTEAM]->setDefense(true);
            }
            else if (getTeamWithBall() == AWAYTEAM)  // if 1 puts team 1 on offense and team 0 on defense
            {
                activeTeamInstance[HOMETEAM]->setOffense(false);
                activeTeamInstance[HOMETEAM]->setDefense(true);

                activeTeamInstance[AWAYTEAM]->setOffense(true);
                activeTeamInstance[AWAYTEAM]->setDefense(false);
            }
            else
            {
            }
        }
        else
        {
        }

        for (auto ATIIT : activeTeamInstance)
        {
            ATIIT.second->updateState();

            if (ATIIT.second->getActivePlayerInstancesChanged())
            {
                logMsg(func +" activePlayerInstancesChanged!");
//                exit(0);
                if (ATIIT.second->getTeamType() == HOMETEAM)
                {
                    tActivePlayersChanged[0] =  true;
                    logMsg(func +" HOMETEAM");
                    logMsg(func +" " +convert->toString(tActivePlayersChanged[0]));

                }
                else if (ATIIT.second->getTeamType() == AWAYTEAM)
                {
                    tActivePlayersChanged[1] = true;
                    setTeamActivePlayersChanged(tActivePlayersChanged);
                    logMsg(func +" AWAYTEAM");
                    logMsg(func +" " +convert->toString(tActivePlayersChanged[1]));

                }
                else
                {
                }
                logMsg("dah");
//                setTeamActivePlayersChanged(tActivePlayersChanged);
                std::vector<bool> activeChange = getTeamActivePlayersChanged();
                logMsg(func +" h " +convert->toString(activeChange[0]));
                logMsg(func +" a " +convert->toString(activeChange[1]));
//                exit(0);
            }
            else
            {

            }
            // Update Team Active Player Instances
            for (auto APIIT : ATIIT.second->getActivePlayerInstance())
            {
                logMsg(func +" player model loaded == " +convert->toString(APIIT.second->getModelLoaded()));
    //                logMsg(func +"activePlayerInstance coords == " +convert->toString(APIIT.second->getEntity()->getNode()->getPosition()));
            }
        }
        updatePlayerCollisionObjects();  // updates collision objects for each player
//          exit(0);
    }
    else
    {
    }
    setActiveTeamInstance(activeTeamInstance);
*/
    logMsg(func +" end");

    return (true);
}

bool gameEntity::updatePlayerCollisionObjects()  // updates the player collision objects for a team instance
{
    teamEntityMSharedPtr activeTeamInstance = component->getActiveTeamInstance();
    conversionSharedPtr convert ;
 
    std::unordered_map<std::string, btRigidBodySharedPtr> collisionBodies;  // physical bodies to test for collisions with players physBody objects

    std::vector<bool> teamActivePlayersChanged = data->getTeamActivePlayersChanged();
    size_t teamNumber = 0;
    std::string func = "gameEntity::updatePlayerCollisionObjects()";

    logMsg(func +" begin");
//        exit(0);
    while (teamNumber < teamActivePlayersChanged.size())
    {
        if (teamActivePlayersChanged[teamNumber])
        {
            logMsg(func +" team " +convert->toString(teamNumber)+" wahoo!");
            teamTypes teamType;
            switch (teamNumber)
            {
                case 0:
                    teamType = HOMETEAM;
                break;
                case 1:
                    teamType = AWAYTEAM;
                break;   
            }
            bool loopDone = false;
            while (!loopDone)
            {
                playerEntityMSharedPtr activePlayerInstance;
                playerEntityMSharedPtr collisionPlayerInstance;
                std::map<std::string, btRigidBodySharedPtr> activeCollisionBodies;
                std::map<std::string, btRigidBodySharedPtr> newCollisionBodies;
//                std::unordered_map<std::string, btRigidBodySharedPtr> newCollisionBodies;
                btRigidBodySharedPtr tempBody;
                for (auto ATIIT : activeTeamInstance)
                {
                    if (ATIIT.second->getGameData()->getTeamType() == teamType)
                    {
                        logMsg(func +" woot woot!");
                        activePlayerInstance = ATIIT.second->getComponent()->getActivePlayerInstance();
                        activeCollisionBodies = ATIIT.second->getComponent()->getCollisionBodies();

                        
                    }
                    else
                    {
                        logMsg(func +" toot toot!");
                        collisionPlayerInstance = ATIIT.second->getComponent()->getActivePlayerInstance();
                        std::string position;
                        btRigidBodySharedPtr physBody;
                        for (auto CPIIT : collisionPlayerInstance)  // loops through the other team's activePlayerInstance
                        {
                            if (CPIIT.second->getFlag()->getPhysBodyInitialized())  // verifies that each player's physBody has been initialized
                            {  // inserts the player's position and their collisionBody into newCollisionBodies
                                logMsg(func +" physBody Initialized!");
                                position = convert->toString(CPIIT.first);
                                physBody = CPIIT.second->getComponent()->getPhysics()->getPhysBody();
                                newCollisionBodies.insert(std::pair<std::string, btRigidBodySharedPtr>(position, physBody));  // loads the second hoop
//                                tempBody = physBody;
                                logMsg(func +" position = " +=position);
                            }
                            else
                            {
                                logMsg(func +" physBody Not Initialized!");
                            }
                        }                      
                    }
                }
                std::string tempPos = "C";
// Test code to verify that the code to change a collisionBody works
//                activeCollisionBodies.insert(std::pair<std::string, btRigidBodySharedPtr>(tempPos, tempBody));  // loads the second hoop
//                activeCollisionBodies.insert(std::pair<std::string, btRigidBodySharedPtr>("PG", tempBody));  // loads the second hoop

                if (!activeCollisionBodies.empty())
                {    
                    std::unordered_map<std::string, bool> ACBFound;  // stores whether an active collision body entry has been found
                    
                    for (auto ACBIT : activeCollisionBodies)
                    {
                        ACBFound.insert(std::pair<std::string, bool>(ACBIT.first, true));

                        logMsg(func +" newCollisionBodies.size() before = " +convert->toString(newCollisionBodies.size()));
                        for (auto NCBIT : newCollisionBodies)
                        {                           
                            if (ACBIT.first == NCBIT.first)  // changes collision bodies that have the same string
                            {
                                ACBIT.second = NCBIT.second;
                                newCollisionBodies.erase(NCBIT.first);
                            }
                            else
                            {
                            }
                        }
                        logMsg(func +" newCollisionBodies.size() after = " +convert->toString(newCollisionBodies.size()));
                    }
                    size_t i = 0;
                    for (auto NCBIT : newCollisionBodies)  // inserts the remaining collision bodies
                    {   
                        activeCollisionBodies.insert(NCBIT);
                        ++i;
                        logMsg(func +" activeCollisionBodies + " +convert->toString(i));
                    }
                }
                else
                {
                    logMsg(func +" activeCollisionBodies is empty!");
                    activeCollisionBodies = newCollisionBodies;
                }
                for (auto NCBIT : newCollisionBodies)
                {
                    logMsg(func +" NCB position = " +NCBIT.first);
                }
                for (auto ATIIT : activeTeamInstance) // updates collisionBodies with the new data
                {
                    if (ATIIT.second->getGameData()->getTeamType() == teamType)
                    {
                        ATIIT.second->getComponent()->setCollisionBodies(activeCollisionBodies);
                        loopDone = true;
                    }
                    else
                    {
                    }
                }
            }
        }
        ++teamNumber;
    }

    logMsg(func +" end");

    return (true);
}

bool gameEntity::processInput()  // processes input received from the inputState object
{
    conversionSharedPtr convert ;

    std::string func = "gameEntity::processInput()";

    logMsg(func +" begin");
/*    exit(0);

        if (getActiveTeamInstancesCreated())
        {
//            exit(0);
            size_t inputIterator = 0;
//            while (inputIterator < getActiveTeamInstance().size())
            for (auto ATIIT : getActiveTeamInstance())
            {
               if (getActiveTeamInstance()[inputIterator]->getPlayerInstancesCreated())
                {
                    playerEntityMSharedPtr activePlayerInstance = getActiveTeamInstance()[inputIterator]->getActivePlayerInstance();
                    if (getActiveTeamInstance()[inputIterator]->getHumanControlled())
                    {
                        std::string humanPlayer = getActiveTeamInstance()[inputIterator]->getHumanPlayer();
                        logMsg("inputHumanPlayer == " +humanPlayer);
                        //inputMaps inputMap = input->keyMap();
//                        inputWorkInGameQueues inputInGameQueue = base->getGameE()->getInputE()->getInputWorkQueue();
//                      logMsg("INPUT MAP ======== "  +toString(inputMap));
                        std::stringstream ss;
//                      exit(0);
                        size_t x = 0;
                        size_t humanInstance = 11;
                        while (x < activePlayerInstance.size())
                        {
//                            logMsg("GEPlayerID == " +convert->toString(activePlayerInstance[x]->getID()));
                            logMsg("GEHumanPlayer == " +humanPlayer);

                            if (activePlayerInstance[x]->getID() == humanPlayer)
                            {
                                humanInstance = x;
                                break;
                            }
                            ++x;
                        }
                        logMsg("humanInstance == " +convert->toString(humanInstance));
                        logMsg("inputHumanPlayer == " +humanPlayer);
                        logMsg("inputInGameWorkQueue.size = " +convert->toString(inputInGameWorkQueue.size()));
                        x = 0;
//                        int activeBBallInstance = getActiveBBallInstance();
                        basketballStateVecSharedPtr bballInstance = getBasketballInstance();
                        logMsg("humanInstance.size() == " +convert->toString(humanInstance));
                        if (humanInstance < 11) // makes sure that the humanInstance is a valid number
                        {
                            while (x < inputInGameWorkQueue.size())
                            {
                                logMsg("inputInGameWorkQueue[" +convert->toString(x) +"] = " +convert->toString(inputInGameWorkQueue[x]));
                                // switch (inputMap)
                                switch (inputInGameWorkQueue[x])
                                {
                                    case INUP:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(UP);
                                        getActiveTeamInstance()[inputIterator]->setActivePlayerInstance(activePlayerInstance);
//                                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);
//                                        exit(0);
                                    break;
                                    case INDOWN:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(DOWN);
                                        getActiveTeamInstance()[inputIterator]->setActivePlayerInstance(activePlayerInstance);
//                                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INLEFT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(LEFT);
                                        getActiveTeamInstance()[inputIterator]->setActivePlayerInstance(activePlayerInstance);
//                                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INRIGHT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(RIGHT);
                                        getActiveTeamInstance()[inputIterator]->setActivePlayerInstance(activePlayerInstance);
//                                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INUPLEFT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(UPLEFT);
                                        getActiveTeamInstance()[inputIterator]->setActivePlayerInstance(activePlayerInstance);
//                                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INUPRIGHT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(UPRIGHT);
                                        getActiveTeamInstance()[inputIterator]->setActivePlayerInstance(activePlayerInstance);
//                                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INDOWNLEFT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(DOWNLEFT);
                                        getActiveTeamInstance()[inputIterator]->setActivePlayerInstance(activePlayerInstance);
//                                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INDOWNRIGHT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(DOWNRIGHT);
                                        getActiveTeamInstance()[inputIterator]->setActivePlayerInstance(activePlayerInstance);
//                                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INSHOOTBLOCK:
                                        activePlayerInstance[humanInstance]->setMovement(false);
                                        activePlayerInstance[humanInstance]->setShootBlock(true);
                                        getActiveTeamInstance()[inputIterator]->setActivePlayerInstance(activePlayerInstance);
//                                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INPASSSTEAL:
                                        activePlayerInstance[humanInstance]->setMovement(false);
                                        activePlayerInstance[humanInstance]->setPassSteal(true);
                                        getActiveTeamInstance()[inputIterator]->setActivePlayerInstance(activePlayerInstance);
//                                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INQUIT:
                                        logMsg("Quitting!");
//                                        base->getGameE()->setQuitGame(true);
                                        exit(0);
                                    break;
                                    default:
                                    break;
                                }
                                ++x;
                            }
                        }
//                        teamStateVecSharedPtr tInstance = base->getGameS()->getActiveTeamInstance();
                        playerEntityMSharedPtr activePInstance = getTeamInstance()[inputIterator]->getActivePlayerInstance();
                        logMsg("humanInstance == " +convert->toString(humanInstance));
                        //logMsg("inPassSteal == " +convert->toString(activePInstance[humanInstance]->getPassSteal()));
                        //exit(0);

                        /// FIXME! This if statement should be adapted to work correctly instead of relying on the i variable
                        int i = 0;
                        if (getTeamWithBall() == i)
                        {
                            if (activePlayerInstance[humanInstance]->getMovement())
                            {
//                                logMsg("human playerID == " +convert->toString(activePlayerInstance[humanInstance]->getID()));
                                logMsg("ball player == " +convert->toString(getActiveTeamInstance()[inputIterator]->getPlayerWithBallInstance()));
                                logMsg("ball playerID == " +convert->toString(getActiveTeamInstance()[inputIterator]->getPlayerWithBallID()));
//                                if (activePlayerInstance[humanInstance]->getID() == getActiveTeamInstance()[inputIterator]->getPlayerWithBallID())
                                {
                                    bballInstance[activeBBallInstance]->setMovement(true);
                                    setBasketballInstance(bballInstance);
                                }
                            }
                        }
                        if (getBasketballInstance().size() > 0)
                        {
                            logMsg("basketballmoved == " +convert->toString(bballInstance[activeBBallInstance]->getMovement()));
                        }
//                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);

                        if (getGameType() == MULTI)
                        {
//  FIXME!                            
///                            getNetworkS()->processLocalInput(getActiveTeamInstance());
                        }

                        inputInGameWorkQueue.clear();
///                        base->getGameE()->getInputE()->setInputWorkQueue(inputQueue);
                    }
                    ++inputIterator;
                }
            
            }            
        }*/
    logMsg(func +" end");
    return (true);
}

void gameEntity::updateDirectionsAndMovements()
{
    //conversion *convert = conversion::Instance();
    conversionSharedPtr convert ;
//    directions playerDirection, oldPlayerDirection;
//   logMsg("Updating Directions and Movements");

    std::string func = "gameEntity::updateDirectionsAndMovements()";

    logMsg(func +" begin");


    if (data->getTeamWithBall() != NOTEAM) // && playerHasBasketball)
    {
//      logMsg("teamWithBall ios " +convert->toString(teamWithBall));
//      logMsg("playetWithBall is " +convert->toString(activeTeamInstance[teamWithBall].getPlayerWithBall()));
//        updateBasketballMovements();  // updates the movement of basketball objec(s)
        //updateBasketballDirections(); // updates direction of basketball object(s)
    }
    else
    {
    }
    
    logMsg(func +" end");

    
}
