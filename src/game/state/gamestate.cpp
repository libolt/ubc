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

#include <unordered_map>
//#include "boost/shared_array.hpp"
#include "engine/networkengine.h"
#include "ai/ai.h"
#include "ai/basketballsteer.h"
#include "data/gamedata.h"
#include "components/gamecomponents.h"
#include "entity/playerentity.h"
#include "utilities/conversion.h"
#include "entity/basketballentity.h"
#include "entity/courtentity.h"
#include "flags/gameflags.h"
#include "flags/playerflags.h"
#include "gamesetup/gamesetupbasketballs.h"
#include "gamesetup/gamesetupcourts.h"
#include "gamesetup/gamesetuphoops.h"
#include "gamesetup/gamesetupplayers.h"
#include "gamesetup/gamesetupteams.h"
#include "state/basketballstate.h"
#include "state/courtstate.h"
#include "state/gamestate.h"
#include "state/hoopstate.h"
#include "state/networkstate.h"
#include "state/playerstate.h"
#include "state/teamstate.h"
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
#include "jumpballs.h"
#include "users/users.h"

// static declarations
gameState::gameState()  // constructor
{
//    stateSet = false;
    componentInitialized = false;
    dataInitialized = false;
    flagInitialized = false;
}

gameState::~gameState()  // destructor
{
}

gameComponentsSharedPtr gameState::getComponent()  // retrieves the value of component
{
    return (component);
}
void gameState::setComponent(gameComponentsSharedPtr set)  // sets the value of component
{
    component = set;
}

gameDataSharedPtr gameState::getData()  // retrieves the value of data
{
    return (data);
}
void gameState::setData(gameDataSharedPtr set)  // sets the value of data
{
    data = set;
}

gameFlagsSharedPtr gameState::getFlag()  // retrieves the value of flag
{
    return (flag);
}
void gameState::setFlag(gameFlagsSharedPtr set)  // sets the value of flag
{
    flag = set;
}

bool gameState::assignHoopToTeams()  // assigns which hoop belongs to each team
{
//TS    getActiveTeamInstance()[0]->setHoop(1);
//TS    getActiveTeamInstance()[1]->setHoop(0);
    return (true);
}

bool gameState::getComponentInitialized()  // retrieves the value of componentInitialized
{
    return (componentInitialized);
}
void gameState::setComponentInitialized(bool set)  // sets the value of componentInitialized
{
    componentInitialized = set;
}

bool gameState::getDataInitialized()  // retrieves the value of dataInitialized
{
    return (dataInitialized);
}
void gameState::setDataInitialized(bool set)  // sets the value of dataInitialized
{
    dataInitialized = set;
}

bool gameState::getFlagInitialized()  // retrieves the value of flagInitialized
{
    return (flagInitialized);
}
void gameState::setFlagInitialized(bool set)  // sets the value of flagInitialized
{
    flagInitialized = set;
}

bool gameState::createInstances()  // creates object instances
{
    /*
    bool returnType = true;
    logMsg("gameState creating instances!");
    if (!getPlayerInstanceCreated())
    {
        logMsg("player Instances not created!");
//        exit(0);
        if (createPlayerInstances())  // create player instances
        {
            logMsg("Player instances created!");
//            exit(0);
            setPlayerInstanceCreated(true);
//            return (true);
        }
        else 
        {
            logMsg("Failed to create playerInstances!");
            returnType = false;
        }
    }
//    exit(0);
    if (!getTeamInstancesCreated())
    {
        logMsg("Creating Team Instances!");
//        exit(0);
        if (createTeamInstances())  // create team instances
        {
            
            logMsg("Team instances created!");
//            exit(0);
            setTeamInstancesCreated(true);
//            return (true);
        }
        else 
        {
            logMsg("Failed to create teamInstances!");
            returnType = false;
        }
//        exit(0);
    }
//    exit(0);
    if (!getCourtInstancesCreated())
    { 
        if (createCourtInstances())  // create court instances
        {
            logMsg("Court instances created!");
//            exit(0);
            setCourtInstancesCreated(true);
//            return (true);
        }
        else 
        {
            logMsg("Failed to create courtInstances!");
            returnType = false;
        }
    }
    
    if (!getHoopInstancesCreated())
    {
        if (createHoopInstances())  // create hoop instances
        {
            setHoopInstancesCreated(true);
//            return (true);
        }
        else 
        {
            logMsg("Failed to create hoopInstances!");
            returnType = false;
        }
    }
    
    if (!getBasketballInstanceCreated())
    {
        if (createBasketballInstances())  // create basketball instances
        {
            setBasketballInstanceCreated(true);
//            return (true);
        }
        else 
        {
            logMsg("Failed to create basketballInstances!");
            returnType = false;
        }
    }
//    exit(0);
    return (returnType);*/
}
/*bool gameState::createBasketballInstances()  // creates basketball Instances
{
    sharedPtr<basketballState> bballInstance;  // creates an instance of the basketballs class
    std::string func = "gameState::createTeamInstances()";
    
    logMsg(func +" beginning");
    exit(0);
    logMsg(func +" creating temporary baskteball instance");
    logMsg(func +" setting model name");
//  FIXME! these are currently hard coded
    bballInstance->getEntity()->setEntityModelFileName("bball.mesh");
    bballInstance->getEntity()->setEntityName(bballInstance->getData()->getModelFileName());
    bballInstance->getEntity()->setEntityNodeName(bballInstance->getData()->getModelFileName());
    if (!bballInstance->getEntity()->getBaseInitialized())
    {
        bballInstance->getEntity()->setBase(getBase());
    }
    logMsg(func +" creating steer object");
    basketballSteer *bballSteer = new basketballSteer;  // steer instance
    bballInstance->getEntity()->setSteer(basketballSteerSharedPtr(bballSteer));
    logMsg(func +" setting instance number");
    bballInstance->setNumber(0);
    bballInstance->setNumberSet(true);
//    bballInstance->setModelNeedsLoaded(true);
    getBasketballInstance().push_back(bballInstance);
    
    logMsg(func +" end");
    
    return (true);
}*/

/*bool gameState::createTeamInstances()  // creates team Instances
{
    conversionSharedPtr convert = conversion::Instance();
    loadTeamsSharedPtr loadTeam = base->getLoadTeam();
    std::string func = "gameState::createTeamInstances()";
    
    logMsg(func +" beginning");
    exit(0);
    teamStateMSharedPtr tInstance;
///    teamStateVecSharedPtr tInstance2;
///    teamStateSharedPtr tempInstance(new teamState);
//    teamState *tempInstance = new teamState;
///    tempInstance->setID(1);
///    tempInstance->setCity("tempCity");
///    tempInstance->setName("tempTeam");
///    tempInstance->setCoach("tempCoach|");
///    tempInstance->setTeamType(HOMETEAM);

///    tInstance2.push_back(tempInstance);

    logMsg(func +" loadTeams");
    if (loadTeam->checkIfTeamsLoaded())
    {
        logMsg(func +" loadTeam->getTInstance().size() == " +convert->toString(loadTeam->getTInstance().size()));
//        exit(0);
        tInstance = loadTeam->getTInstance();
        if (tInstance.size() > 0)
        {
            logMsg(func +" tInstance Loaded!");
            setTeamInstance(tInstance);
        }
        else
        {
            logMsg(func +" tInstance NOT Loaded!");
        }
    }
    else
    {
        logMsg(func +" loading of teams failed!");
        return (false);
    }
    

//    exit(0);
    logMsg(func +" uno");
    

    logMsg(func +" tInstance.size() == " +convert->toString(tInstance.size()));
    logMsg(func +" too");
    
//    exit(0);
    logMsg("tInstance size == " +convert->toString(tInstance.size()));


//    logMsg("teamID.size() == " +convert->toString(getTeamIDS().size()));
//    logMsg("tInstance size = " +convert->toString(tInstance.size()));
//    logMsg("tInstance city 0 = " +tInstance[0]->getCity());

//    exit(0);
///    getTeamInstance()[0]->setID(tInstance[0]->getID());
///    teamInstance[1].setTeamID(teamID[1]);
///    exit(0);
///    teamInstance[0].setTeamType(HOMETEAM);
///    teamInstance[1].setTeamType(AWAYTEAM);
///    teamInstance[0].setHumanControlled(true);
///    teamInstance[1].setHumanControlled(false);
///    teamInstance[0].setTeamColObject(COL_TEAM1);
///    teamInstance[1].setTeamColObject(COL_TEAM2);

//    teamInstance[0].setTeamCollidesWith(COL_COURT); // | COL_BBALL | COL_TEAM2;   determines what team0 collides with);
//    teamInstance[1].setTeamCollidesWith(COL_COURT); // | COL_BBALL | COL_TEAM2;   determines what team1 collides with);
//    teamInstance[0].setupState();
//    teamInstance[1].setupState();
//    exit(0);

    if (tInstance.size() > 0)
    {
        setTeamInstance(tInstance);
        setTeamInstancesCreated(true);
        logMsg(func +" teamInstance CREATED!!");
//        exit(0);
    }
    else 
    {
        logMsg(func +" Failed to create Team Instances!");
        exit(0);
        return (false);
    }

    logMsg(func +" end");
    
    return (true);
}*/

/*bool gameState::createCourtDataInstances()  // creates instances of court data
{
    sharedPtr<loader> load = loader::Instance();
    courtDataInstance = load->loadCourts();
    return (true);
}*/

/*bool gameState::createCourtInstances()  // creates court Instances
{
    loadCourtsSharedPtr loadCourt = base->getLoadCourt();
    std::string func = "gameState::createCourtInstances()";
    
    logMsg(func +" beginning");

//    exit(0);
//    courtState cInstance;  // creates an instance of the courtState class
//    cInstance.setModelFileName("court.mesh");
//    cInstance.setModelFileName("Court.mesh");
//    exit(0);
    if (loadCourt->checkIfCourtsLoaded())
    {
 //       exit(0);
        setCourtInstance(loadCourt->getCInstance());
        logMsg(func +" Court Instances SET!");
        return (true);
    }
    else
    {
//        exit(0);
//        logMsg("Court Instances NOT SET!!");
//        exit(0);
        return (false);
    }
//    exit(0);
    
    logMsg(func +" end");

    
    return (true);
}*/

/*bool gameState::createHoopInstances()  // creates hoop Instances
{
    std::string func = "gameState::createHoopInstances()";
    
    logMsg(func +" beginning");
    exit(0);
    hoopStateSharedPtr hInstance0(new hoopState);  // creates an instance of the hoopState class
    hoopStateSharedPtr hInstance1(new hoopState);  // creates an instance of the hoopState class

//    cInstance.setModelFileName("court.mesh");
    hInstance0->setEntityName("hoop1");
    hInstance0->setEntityModelFileName("Hoop.mesh");
    hInstance0->setEntityNodeName("hoopNode1");

    hInstance1->setEntityName("hoop2");
    hInstance1->setEntityModelFileName("Hoop.mesh");
    hInstance1->setEntityNodeName("hoopNode2");

    getHoopInstance().insert(std::pair<size_t, hoopStateSharedPtr>(0, hInstance0));  // loads the first hoop
    getHoopInstance().insert(std::pair<size_t, hoopStateSharedPtr>(1, hInstance1));  // loads the second hoop

    logMsg(func +" end");

    return (true);
}*/

/*bool gameState::createPlayerInstances()  // creates player instances
{
//    logMsg("gameState::createTeamInstances()");
    
    conversionSharedPtr convert = conversion::Instance();
    loadPlayersSharedPtr loadPlayer = base->getLoadPlayer();
    playerEntityMSharedPtr pInstance;
    std::string func = "gameState::createPlayerInstances()";
    
    logMsg(func +" beginning");
     
    if (base->getGameS()->getInitialized())
    {
        logMsg(func +" gameS Initialized == True!");
    }
    else
    {
        logMsg(func +" gameS Initialized == False!");
    }
    logMsg(func +" checkIfPlayersLoaded");
//    exit(0);
    if (loadPlayer->checkIfPlayersLoaded())
    {
        logMsg(func +" checkIfPlayersLoaded True");

        pInstance = loadPlayer->getPInstance();
        if (pInstance.size() > 0)
        {
            logMsg(func +" pInstance Loaded!");
        }
        else
        {
            logMsg(func +" pInstance NOT Loaded!");
        }
    }
    else
    {
        logMsg(func +" loading of playerss failed!");
        return (false);
    }

    for (auto PIIT : pInstance)
    {
        logMsg(func +" Player " +PIIT.second->getData()->getFirstName() +" " +PIIT.second->getData()->getLastName() +" TeamID == " +convert->toString(PIIT.second->getData()->getTeamID()));       
    }
    
//    exit(0);
    logMsg(func +" uno");

    logMsg(func +" pInstance.size() == " +convert->toString(pInstance.size()));
    logMsg(func +" too");
//    setPlayerInstances(load->loadPlayers());
//   exit(0);
    setPlayerInstance(pInstance);
    setPlayerInstanceCreated(true);
    if (getPlayerInstance().size() > 0)
    {
        logMsg(func +" playerInstance size == " +convert->toString(getPlayerInstance().size()));
//        logMsg("player name = " +getPlayerInstance()[0]->getPlayerName());
//        exit(0);
        return (true);
    }
    
    logMsg(func +" end");
    
    return (false);
}*/

/*bool gameState::createActiveBasketballInstances()  // creates the active basketball instances
{
    conversionSharedPtr convert = conversion::Instance();
    loadBasketballsSharedPtr loadBasketball;  // = base->getLoad();
    basketballStateMSharedPtr basketballInstance = getBasketballInstance();
    basketballStateMSharedPtr activeBasketballInstance = getActiveBasketballInstance();
    std::string func = "gameState::createActiveBasketballInstances()";
    
    logMsg(func +" beginning");

    logMsg(func +" basketballInstance.size() == " +convert->toString(basketballInstance.size()));
    if (basketballInstance.size() == 0)
    {
        if (loadBasketball->checkIfBasketballFilesLoaded())
        {
            basketballInstance = loadBasketball->getBInstance();
        }
        else
        {
            logMsg(func +" Failed to load Basketball Instances!");
            exit(0);
        }
    }
    else
    {

    }
    
    //FIXME! should not be hard coded
    setNumActiveBasketballs(1);
    logMsg("Creating Active Basketball Instances!");
    for (auto x=0; x<getNumActiveBasketballs(); ++x)
    {
        activeBasketballInstance.insert(std::pair<size_t, basketballStateSharedPtr>(x, basketballInstance[x]));
        activeBasketballInstance[x]->setGameS(base->getGameS());
    }
    setBasketballInstance(basketballInstance);
    setActiveBasketballInstance(activeBasketballInstance);
    logMsg(func +" end");
    return (true);
}*/

/*bool gameState::createActiveCourtInstances()  // creates the active court instances
{
    conversionSharedPtr convert = conversion::Instance();
    loadCourtsSharedPtr loadCourt = base->getLoadCourt();
    courtStateMSharedPtr courtInstance = getCourtInstance();
    courtStateMSharedPtr activeCourtInstance = getActiveCourtInstance();
    std::string func = "gameState::createActiveCourtInstances()";
    
    logMsg(func + " beginning");
    
    logMsg(func +" courtInstance.size() == " +convert->toString(courtInstance.size()));
    if (courtInstance.size() == 0)
    {
        if (loadCourt->checkIfCourtsLoaded())
        {
            courtInstance = loadCourt->getCInstance();
        }
        else
        {
            logMsg(func +" Failed to load Court Instances!");
            exit(0);
        }
    }
    else
    {

    }

    logMsg(func +" courtInstance.size() == " +convert->toString(courtInstance.size()));
    //FIXME! should not be hard coded
    activeCourtInstance.insert(std::pair<size_t, courtStateSharedPtr>(0, courtInstance[0]));
    if (!activeCourtInstance[0]->getInitialized())
    {
        if (activeCourtInstance[0]->initialize())
        {
            activeCourtInstance[0]->setInitialized(true);
        }
        else
        {
            logMsg(func +" Unable to initialize activeCourtInstance!");
            exit(0);
        }
    }
    setCourtInstance(courtInstance);
    setActiveCourtInstance(activeCourtInstance);
    logMsg(func +" getCourtInstance.size() == " +convert->toString(getCourtInstance().size()));
    logMsg(func +" end");
    return (true);
}*/

/*bool gameState::createActiveHoopInstances()  // creates the active hoop instances
{
    conversionSharedPtr convert = conversion::Instance();
    loadHoopsSharedPtr loadHoop = base->getLoadHoop();
    hoopStateMSharedPtr hoopInstance = getHoopInstance();
    hoopStateMSharedPtr activeHoopInstance = getActiveHoopInstance();
    std::string func = "gameState::createActiveHoopInstances()";
    size_t x = 0;
    logMsg(func +" beginning");
    
    if (hoopInstance.size() == 0)
    {
        if (loadHoop->checkIfHoopsLoaded())
        {
            logMsg(func + " abada!");
            hoopInstance = loadHoop->getHInstance();
            logMsg(func + " abadeeee!");
        }
        else
        {
            logMsg(func +" Failed to load Hoop Instances!");
            exit(0);
        }
    }
    else
    {

    }
//    logMsg(func + "name 0 == " +hoopInstance[0]->getName());
//    logMsg(func + "name 1 == " +hoopInstance[1]->getName());

//    exit(0);
    for (x=0;x<numActiveHoops; ++x)
    {
        activeHoopInstance.insert(std::pair<size_t, hoopStateSharedPtr>(x, hoopInstance[x]));
        logMsg(func +" glee!");
        logMsg(func + "name == " +hoopInstance[x]->getName());
    }
    x = 0;
///    for (auto AHIIT : activeHoopInstance)
///    {
        
///        logMsg(func +" flee!");
///        logMsg(func + " AHIIT name == " +AHIIT.second->getName());

///        AHIIT.second->setEntityID(x);
///        AHIIT.second->setEntityName("hoop" +AHIIT.second->getName());
///        ++x;
///        logMsg(func +" entityName == " +AHIIT.second->getEntityName());

///    }

//    exit(0);
    setActiveHoopInstance(activeHoopInstance);
///    for (auto AHIIT : getActiveHoopInstance())
///    {
///        logMsg(func + " AHIIT name == " +AHIIT.second->getName());
///        logMsg(func + " AHIIT index == " +convert->toString(AHIIT.first));
///    }

//    exit(0);
    logMsg(func +" end");
    return (true);
}*/

bool gameState::setupActiveTeamInstances()  // sets up the active team instances
{
    teamStateSharedPtr tInstance;
    teamStateMSharedPtr activeTeamInstance = component->getActiveTeamInstance();
    teamStateMSharedPtr teamInstance = component->getTeamInstance();
    sizeTVec teamIDS = data->getTeamIDS();
    std::string func = "gameState::setupActiveTeamInstances()";

    logMsg(func +" beginning");
//    activeTeamInstance.insert(std::pair<size_t, teamStateSharedPtr>(0, tInstance));  // adds empty teamState to activeTeamInstance vector
//    activeTeamInstance.insert(std::pair<size_t, teamStateSharedPtr>(1, tInstance));  // adds empty teamState to activeTeamInstance vector
//    exit(0);
/*TS    activeTeamInstance[0] = teamInstance[teamIDS[0]];
    activeTeamInstance[1] = teamInstance[teamIDS[1]];
    activeTeamInstance[0]->setID(teamIDS[0]);
    activeTeamInstance[1]->setID(teamIDS[1]);
*/    
    activeTeamInstance[0]->setTeamType(HOMETEAM);
    activeTeamInstance[1]->setTeamType(AWAYTEAM);
    activeTeamInstance[0]->setHumanControlled(true);
    activeTeamInstance[1]->setHumanControlled(false);
    activeTeamInstance[0]->setTeamColObject(COL_TEAM1);
    activeTeamInstance[1]->setTeamColObject(COL_TEAM2);
    activeTeamInstance[0]->setTeamCollidesWith(COL_COURT); // | COL_BBALL | COL_TEAM2;   determines what team0 collides with
    activeTeamInstance[1]->setTeamCollidesWith(COL_COURT); // | COL_BBALL | COL_TEAM2;   determines what team1 collides with
    activeTeamInstance[0]->setupState();
    activeTeamInstance[1]->setupState();

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

bool gameState::setupEnvironment()
{
//    renderEngineSharedPtr render = renderEngine::Instance();
    
/*
    // Set ambient light
    render->getMSceneMgr()->setAmbientLight(ColourValue(0.5, 0.5, 0.5));

    // Create a light
    Light* l = render->getMSceneMgr()->createLight("MainLight");
    l->setPosition(20,80,56);
*/

    return (true);
}

/*bool gameState::loadBasketballModel()  // loads selected basketball model
{
    conversionSharedPtr convert = conversion::Instance();
    loaderSharedPtr load(new loader);
    gameSetupBasketballsSharedPtr gameSetupBasketball;
    basketballStateMSharedPtr activeBasketballInstance = getActiveBasketballInstance();
    bool activeBasketballInstancesCreated = getActiveBasketballInstancesCreated();
//    size_t activeBBallInstance = getActiveBBallInstance();
    basketballStateMSharedPtr basketballInstance = getBasketballInstance();
    std::string func = "gameState::loadBasketballModel()";
    bool returnType = false;
    
    logMsg(func +" beginning");
    
    if (!activeBasketballInstancesCreated && activeBasketballInstance.size() == 0)
    {
        if (basketballInstance.size() == 0)
        {
            basketballInstance = gameSetupBasketball->createBasketballInstances();
            activeBasketballInstance = gameSetupBasketball->createActiveBasketballInstances(basketballInstance, getNumActiveBasketballs());
            if (activeBasketballInstance.size() > 0)
            {
                logMsg(func +" Active Basketball Instances Created!");
                activeBasketballInstancesCreated = true;
            }
            else
            {
                logMsg(func +" Unable to create Active Basketball Instances!");
                exit(0);
            }
        }
    }
    else
    {
        
    }

    logMsg(func +" activeBasketballInstance.size() == " +convert->toString(activeBasketballInstance.size()));

    for (auto ABIIT : activeBasketballInstance)
    {
        logMsg(func +" activeBasketballInstance == " +convert->toString(ABIIT.first));
    

///        if (!activeBasketballInstance[0]->getEntity()->getBaseInitialized()) // checks to see if the base object for basketballInstance[activeBBallIntance has been initialized
///        {
///            logMsg(func +" Initializing base!");
///            if (!ABIIT.second->getEntity()->getBaseInitialized())
///            {
///                ABIIT.second->getEntity()->setBase(base);
///            }
///        }
       
        if (ABIIT.second->getEntity()->getEntityName() == "")
        {
            std::string name = ABIIT.second->getData()->getName();
            ABIIT.second->getEntity()->setEntityName(name);
        }
        logMsg(func +" entityName == " +ABIIT.second->getEntity()->getEntityName());
//        exit(0);
        if (ABIIT.second->getEntity()->getEntityNodeName() == "")
        {
            std::string nodeName = ABIIT.second->getData()->getName() +"node";
            ABIIT.second->getEntity()->setEntityNodeName(nodeName);
        }
        logMsg(func +" basketball name == " +ABIIT.second->getData()->getName());
        logMsg(func + " basketball node name == " +ABIIT.second->getEntity()->getEntityNodeName());
//        exit(0);
        logMsg(func +" loading model == " +ABIIT.second->getEntity()->getEntityModelFileName());
        if (ABIIT.second->getEntity()->loadModel())
        {
            logMsg(func +" modelName == " +ABIIT.second->getEntity()->getModel()->getName());
            logMsg(func +" nodeName == " +ABIIT.second->getEntity()->getNode()->getName());
 
//            exit(0);
            ABIIT.second->getEntity()->setModelNeedsLoaded(false);
            logMsg(func +" blaa!");
            ABIIT.second->getEntity()->setModelLoaded(true);
            logMsg(func +" blii!");
            ABIIT.second->getEntity()->setupPhysicsObject();
///            logMsg(func +" bluu!");
///            setActiveBasketballInstance(activeBasketballInstance);
///            logMsg(func +" Basketball Model Loaded!");

            returnType = true;

        }
        else
        {
            logMsg("Failed to load the basketball model!");
        }
        
    }
    logMsg(func +" alive?");
    setActiveBasketballInstance(activeBasketballInstance);
    logMsg(func +" still alive?");
    setActiveBasketballInstancesCreated(activeBasketballInstancesCreated);
//    exit(0);
    logMsg(func + " end");
    return (returnType);
}*/

/* bool gameState::loadCourtModel()  // loads selected court model
{
    conversionSharedPtr convert = conversion::Instance();
    loaderSharedPtr load(new loader);
    courtStateMSharedPtr courtInstance = getCourtInstance();
    courtStateMSharedPtr activeCourtInstance = getActiveCourtInstance();
    gameSetupCourtsSharedPtr gameSetupCourt(new gameSetupCourts);
    bool activeCourtInstancesCreated = getActiveCourtInstancesCreated();
    bool returnType = false;
    std::string func = "gameState::loadCourtModel()";

    logMsg(func +" beginning");
    
    if (!activeCourtInstancesCreated && activeCourtInstance.size() == 0)
    {
        activeCourtInstance = gameSetupCourt->createActiveCourtInstances(courtInstance);
        if (activeCourtInstance.size() > 0)
        {
            logMsg(func +" Active Court Instances Created!");
            activeCourtInstancesCreated = true;
            setActiveCourtInstance(activeCourtInstance);
        }
        else
        {
            logMsg(func +" Unable to create Active Court Instances!");
            exit(0);
        }
    }
    else
    {

    }

    logMsg(func +" courtInstance.size() == " +convert->toString(courtInstance.size()));
    logMsg(func + " activeCourtInstance.size() == " +convert->toString(activeCourtInstance.size()));
    logMsg(func +" Model Name = " +activeCourtInstance[0]->getData()->getModelFileName());
    logMsg(func +" entity initialized == " +convert->toString(activeCourtInstance[0]->getEntity()->getInitialized()));
    activeCourtInstance[0]->getEntity()->setEntityModelFileName(activeCourtInstance[0]->getData()->getModelFileName());
    logMsg(func +" Model Name = " +activeCourtInstance[0]->getEntity()->getEntityModelFileName());
//    exit(0);
    activeCourtInstance[0]->getEntity()->setEntityNodeName(activeCourtInstance[0]->getData()->getModelFileName());
    activeCourtInstance[0]->getEntity()->setEntityName(activeCourtInstance[0]->getData()->getModelFileName());
    if (activeCourtInstance[0]->getEntity()->loadModel())
    {
        activeCourtInstance[0]->getEntity()->getNode()->setScale(1.0f,1.0f,1.0f);
        setActiveCourtInstance(activeCourtInstance);
        returnType = true;
    }
    else
    {
        logMsg(func +" Court model not loaded!");
    }

    // sets up the physics object for the court instance
    activeCourtInstance[0]->getEntity()->setupPhysicsObject();
    
    setActiveCourtInstancesCreated(activeCourtInstancesCreated);

    logMsg(func +" end");
//    exit(0);
    return (returnType);
} */

/*bool gameState::loadHoopModel()  // loads selected hoop model
{
    conversionSharedPtr convert = conversion::Instance();
    hoopStateMSharedPtr activeHoopInstance = getActiveHoopInstance();
    loaderSharedPtr load(new loader);
    std::string func = "gameState::loadHoopModel()";
    bool returnType = true;

    logMsg(func +" beginning");

///    if (activeHoopInstance.size() == 0)
///    {
///        if (createActiveHoopInstances())
///        {
///            logMsg(func +" Active Hoop Instances created!");
///        }
///        else
///        {
///            logMsg(func +" Unable to create Active Hoop Instances!");
///            exit(0);
///        }
///    }
///    else
///    {        
///    }

    logMsg(func +" activeHoopInstance.size() == " +convert->toString(activeHoopInstance.size()));
//    logMsg(func + " activeCourtInstance == " +convert->toString(activeCourtInstance));
    for (auto AHIIT : getActiveHoopInstance())
    {
        logMsg(func + " AHIIT index == " +convert->toString(AHIIT.first));
        std::string name = AHIIT.second->getName();
        std:: string nodeName = name +"node";
        logMsg(func +" blnodeName == " +nodeName);

    }
    
    
    for (auto AHIIT : activeHoopInstance)
    {
        logMsg(func + " wAHIIT index == " +convert->toString(AHIIT.first));
        logMsg(func + " Name == " +AHIIT.second->getName());
        logMsg(func +" Model Name = " +AHIIT.second->getEntityModelFileName());

///        logMsg(func + "Name == " +AHIIT.second->getName());
///        logMsg(func +" Model Name = " +AHIIT.second->getEntityModelFileName());
///        logMsg("AHIIT index == " +convert->toString(AHIIT.second->getEntityID()));

        std::string name = AHIIT.second->getName();
        std:: string nodeName = name +"node";
        logMsg(func +" blnodeName == " +nodeName);
        AHIIT.second->setEntityName(name);
        AHIIT.second->setEntityNodeName(nodeName);
        logMsg("AHIIT.second->loadModel()");
        
        if (AHIIT.second->loadModel())
        {
            logMsg(func +" Model loaded successfully!");
            AHIIT.second->getNode()->setScale(0.8f,0.8f,0.8f);
        }
        else
        {
            
            logMsg(func +" Unable to load model for activeHoopInstance[" +convert->toString(AHIIT.first) +"]");
            returnType = false;
        }
        
    }
///    if (hoopInstance[1]->loadModel())
///    {
///        hoopInstance[1]->getNode()->setScale(0.8f,0.8f,0.8f);
///    }
///    else
///    {
///        logMsg(func +" Unable to load model for hoopInstance[1]");
///        returnType = false;
///    }
    
    setActiveHoopInstance(activeHoopInstance);
    for (auto AHIIT : getActiveHoopInstance())
    {
//        logMsg ("blhoop " +convert->toString(AHIIT.first) +" name === " +AHIIT.second->getEntityName());

        logMsg ("blhoop " +convert->toString(AHIIT.first) +" nodename === " +AHIIT.second->getNode()->getName());
        logMsg ("blhoop " +convert->toString(AHIIT.first) +" entityID === " +convert->toString(AHIIT.second->getEntityID()));

    }
    logMsg(func +" end");
//    exit(0);
    
    return (returnType);
} 
*/

bool gameState::loadModels(renderEngineSharedPtr render)  // loads all game object models excluding the players
{
    conversionSharedPtr convert = conversion::Instance();
    bool returnType = true;
    std::string func = "gameState::loadModels()";
    logMsg(func +" beginning");

    if (!getFlag()->getBasketballModelLoaded())  // Checks if basketball model has been loaded
    {
//        setActiveBBallInstance(0);  // Sets the active basketball instance
        loadBasketballsSharedPtr loadBasketball(new loadBasketballs);
        basketballStateMSharedPtr activeBasketballInstance;
        logMsg("Loading basketball Model!");
        activeBasketballInstance = loadBasketball->loadModels(component->getActiveBasketballInstance(), render);  // Loads the basketball model
        if (activeBasketballInstance.size() >0)
        {          
            getFlag()->setBasketballModelLoaded(true);
            component->setActiveBasketballInstance(activeBasketballInstance);          
//            return (true);
        }
        else
        {
            logMsg(func +" Unable to load basketball model!");
            returnType = false;
        }

        // FIXEME! this should not be hard coded
    }
    logMsg(func +" weeee");
//    exit(0);

    if (!getFlag()->getCourtModelLoaded())  // Checks if the court model has been loaded
    {
        loadCourtsSharedPtr loadCourt(new loadCourts);
        courtStateMSharedPtr activeCourtInstance;
        
        logMsg(func +" Loading court model!");
        activeCourtInstance = loadCourt->loadModels(component->getActiveCourtInstance(), render);  // load the court model
        if (activeCourtInstance.size() > 0)
        {
            getFlag()->setCourtModelLoaded(true);
            component->setActiveCourtInstance(activeCourtInstance);
//            return (true);
        }
        else
        {
            logMsg(func +" Unable to load the court model!");
            returnType = false;
        }
    }


    if (!getFlag()->getHoopModelLoaded())  // Checks if the hoop model(s) have been loaded
    {
        loadHoopsSharedPtr loadHoop(new loadHoops);
        hoopStateMSharedPtr activeHoopInstance;
        
        logMsg(func +" Loading hoop model(s)!");
        activeHoopInstance = loadHoop->loadModels(component->getActiveHoopInstance(), render);  // Creates the hoop instances
        if (activeHoopInstance.size() > 0)
        {
            getFlag()->setHoopModelLoaded(true);
            component->setActiveHoopInstance(activeHoopInstance);
//            return (true);
        }
        else
        {
            logMsg(func +" Unable to load the hoop model(s)!");
            returnType = false;
        }
    }

    logMsg(func +" end");
//    exit(0);
    
    return (returnType);
}

bool gameState::createNodes(renderEngineSharedPtr render)  // creates scene nodes for game objects
{
    conversionSharedPtr convert = conversion::Instance();
    bool returnType = true;
    OgreEntitySharedPtr activeModel;
    OgreSceneNodeSharedPtr activeNode;
    std::string activeEntityName;
    std::string activeNodeNum;
    std::string activeNodeName;

    std::string func = "gameState::createNodes()";
    
    logMsg(func +" beginning");

    if (getFlag()->getBasketballModelLoaded())  // Checks if basketball model has been loaded
    {
        for (auto ABIIT : component->getActiveBasketballInstance())  // loop through active basketball instances
        {
            activeModel = ABIIT.second->getEntity()->getModel();
            activeEntityName = ABIIT.second->getEntity()->getName();
            activeNodeNum = convert->toString(ABIIT.first);
            activeNodeName = ABIIT.second->getEntity()->getNodeName();
            if (activeNodeName == "")
            {
                activeNodeName = activeEntityName + activeNodeNum;
                ABIIT.second->getEntity()->setNodeName(activeNodeName);
            }
            else
            {
                
            }
            activeNode = render->createNode(activeModel, activeNodeName);  // creates node
            ABIIT.second->getEntity()->setNode(activeNode);  // saves node to current instance
        }
    }
    else
    {
        logMsg(func + " Basketball Models Not Loaded!");
    }
    
    if (getFlag()->getCourtModelLoaded())  // Checks if court model has been loaded
    {
        for (auto ACIIT : component->getActiveCourtInstance())  // loop through active court instances
        {
            activeModel = ACIIT.second->getEntity()->getModel();
            activeEntityName = ACIIT.second->getEntity()->getName();
            activeNodeNum = convert->toString(ACIIT.first);
            activeNodeName = ACIIT.second->getEntity()->getNodeName();
            if (activeNodeName == "")
            {
                activeNodeName = activeEntityName + activeNodeNum;
                ACIIT.second->getEntity()->setNodeName(activeNodeName);
            }
            else
            {
                
            }
            activeNode = render->createNode(activeModel, activeNodeName);  // creates node
            ACIIT.second->getEntity()->setNode(activeNode);  // saves node to current instance
        }
    }
    else
    {
        logMsg(func + " Court Models Not Loaded!");
    }
    
    if (getFlag()->getHoopModelLoaded())  // Checks if hoop model has been loaded
    {
        for (auto AHIIT : component->getActiveHoopInstance())  // loop through active hoop instances
        {
            activeModel = AHIIT.second->getEntity()->getModel();
            activeEntityName = AHIIT.second->getEntity()->getModel()->getName();
            logMsg(func +" activeEntityName == " +activeEntityName);
            activeNodeNum = convert->toString(AHIIT.first);
            activeNodeName = AHIIT.second->getEntity()->getNodeName();
            if (activeNodeName == "")
            {
                activeNodeName = activeEntityName + activeNodeNum;
                AHIIT.second->getEntity()->setNodeName(activeNodeName);
            }
            else
            {
                
            }
            activeNode = render->createNode(activeModel, activeNodeName);  // creates node
            AHIIT.second->getEntity()->setNode(activeNode);  // saves node to current instance

        }
//        exit(0);
    }
    else
    {
        logMsg(func + " Hoop Models Not Loaded!");
    }
    
    logMsg(func + " end");
    
    return (returnType);
}

void gameState::setBasketballStartPositions()  // sets the initial coordinates for the basketball(s)
{
    conversionSharedPtr convert = conversion::Instance();
//    size_t activeBBallInstance = getActiveBBallInstance();
//    basketballStateVecSharedPtr basketballInstance = getBasketballInstance();
    basketballStateMSharedPtr activeBasketballInstance = component->getActiveBasketballInstance();
    std::string func = "gameState::setBasketballStartPositions()";
    
    logMsg(func +" beginning");

    for (auto ABIIT : activeBasketballInstance)
    {
        
        logMsg(func +" activeBasketballInstance == " +convert->toString(ABIIT.first));
    
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//    exit(0);
        ABIIT.second->getEntity()->getNode()->setPosition(0.8f,10.0f,352.0f);
#else
        ABIIT.second->getEntity()->getNode()->setPosition(0.8f,-5.0f,352.0f);
//    exit(0);
#endif
    }
    component->setActiveBasketballInstance(activeBasketballInstance);
    logMsg(func +" end");
}

void gameState::setCourtStartPositions()  // sets the initial coordinates for the basketball(s)
{

    courtStateMSharedPtr courtInstance = component->getCourtInstance();
    std::string func = "gameState::setCourtStartPositions()";

    logMsg(func +" beginning");
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    courtInstance[0]->getEntity()->getNode()->setPosition(0.0f,-6.5f,360.0f);
    courtInstance[0]->getEntity()->setNodePosition(Ogre::Vector3(0.0f,-6.5f,360.0f));
    logMsg(func +" courtPosition");
//exit(0);
#else
    courtInstance[0]->getEntity()->getNode()->setPosition(0.0f,-27.5f,360.0f);
    courtInstance[0]->getEntity()->setNodePosition(Ogre::Vector3(0.0f,-27.5f,360.0f));
#endif

    component->setCourtInstance(courtInstance);
    logMsg(func +" end");
}

void gameState::setHoopStartPositions()  // sets the initial coordinates for the basketball(s)
{

    hoopStateMSharedPtr activeHoopInstance = component->getActiveHoopInstance();
    std::string func = "gameState::setHoopStartPositions()";

    logMsg(func +" beginning");
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    activeHoopInstance[0]->getEntity()->getNode()->setPosition(45.0f,-6.5f,370.0f);
    activeHoopInstance[1]->getEntity()->getNode()->setPosition(-45.0f,-6.5f,370.0f);
#else
    activeHoopInstance[0]->getEntity()->getNode()->setPosition(45.0f,-23.5f,370.0f);
    activeHoopInstance[1]->getEntity()->getNode()->setPosition(-45.0f,-23.5f,370.0f);
#endif

    Ogre::Quaternion hoop0Rotation(Ogre::Degree(-90), Ogre::Vector3::UNIT_Y);
    activeHoopInstance[0]->getEntity()->getNode()->rotate(hoop0Rotation);

    Ogre::Quaternion hoop1Rotation(Ogre::Degree(90), Ogre::Vector3::UNIT_Y);
    activeHoopInstance[1]->getEntity()->getNode()->rotate(hoop1Rotation);

    component->setActiveHoopInstance(activeHoopInstance);
    logMsg(func +" end");
}

bool gameState::setupTipOff()  // sets up tip off conditions
{
    conversionSharedPtr convert = conversion::Instance();
    std::string func = "gameState::setupTipOff()";
    jumpBallsSharedPtr jBall;

    logMsg(func +" beginning");

    if (checkifJumpBallCreated())
    {
        jBall = component->getJumpBall();
    }
    else
    {
        logMsg("Unable to create Jump Ball!");
        exit(0);
    }
    logMsg(func +" jumpBall");
    logMsg(func +"current Team == " +convert->toString(jBall->getBallTippedToTeam()));
    teamTypes currentTeam = jBall->getBallTippedToTeam();
    logMsg(func +" currentTeam");

    playerPositionsVec jumpBallPlayer = jBall->getJumpBallPlayer();
    logMsg(func +" jumpBallPlayer");

    if (data->getTeamWithBall() == NOTEAM && flag->getActiveTeamInstancesCreated())
    {
        if (!jBall->getSetupComplete())
        {
            jBall->setJumpBallLocation(CENTERCIRCLE);
            jumpBallPlayer.clear();
            jumpBallPlayer.push_back(C);
            jumpBallPlayer.push_back(C);
            jBall->setJumpBallPlayer(jumpBallPlayer);
            jBall->setSetupComplete(true);
            jBall->setExecuteJumpBall(true);
            component->setJumpBall(jBall);
            return (true);
        }
        else
        {
            
        }
    }
    
    logMsg(func +" end");
    
    return (false);
}

bool gameState::executeTipOff()  // executes tip off
{
    basketballStateMSharedPtr activeBasketballInstance = component->getActiveBasketballInstance();
    std::string func = "gameState::executeTipOff()";

    logMsg(func +" beginning");

    
    if (!component->getJumpBall()->updateState(data->getTeamWithBall(), activeBasketballInstance, component->getActiveTeamInstance(), data->getQuarter()))
    {
        logMsg("tipOff not complete!");
//        exit(0);
    }
    else
    {
        return (true);
    }
    
    logMsg(func +" end");

    return (false);
}

// sets up the game condition
bool gameState::setupState(renderEngineSharedPtr render)  // sets up the game condition
{
//    exit(0);

    AISystemSharedPtr ai = AISystem::Instance();
//    renderEngineSharedPtr render = renderEngine::Instance();
//    sharedPtr<loader> load = loader::Instance();
    //sharedPtr<physicsEngine> physEngine = physicsEngine::Instance();
    physicsEngine physEngine;
    conversionSharedPtr convert = conversion::Instance();
    gameSetupBasketballsSharedPtr gameSetupBasketball(new gameSetupBasketballs);
    gameSetupCourtsSharedPtr gameSetupCourt(new gameSetupCourts);
    gameSetupHoopsSharedPtr gameSetupHoop(new gameSetupHoops);
    gameSetupTeamsSharedPtr gameSetupTeam(new gameSetupTeams);
//    courtStateMSharedPtr courtInstance = getCourtInstance();
//    hoopStateMSharedPtr hoopInstance = getHoopInstance();

    std::string func = "gameState::setupState()";
   
    logMsg(func +" beginning");
    
    if (!getFlag()->getBasketballInstanceCreated())
    {
        basketballStateMSharedPtr basketballInstance = gameSetupBasketball->createBasketballInstances();
        if (basketballInstance.size() > 0)
        {
            logMsg("Basketball Instances Created!");
            getFlag()->setBasketballInstanceCreated(true);
            component->setBasketballInstance(basketballInstance);

        }
        else
        {
            logMsg("Unsable to create Basketball Instances!");
            exit(0);
        }
    }

    //FIXME! Should not be hard coded
    data->setNumActiveBasketballs(1);
    if (!getFlag()->getActiveBasketballInstancesCreated())
    {
        basketballStateMSharedPtr activeBasketballInstance = gameSetupBasketball->createBasketballInstances();
        if (activeBasketballInstance.size() > 0)
        {
            logMsg("activeBasketballInstances Created!");
            basketballEntitySharedPtr tempBasketball(new basketballEntity);

            for (auto ABIIT : activeBasketballInstance) // loop that checks if each active hoop instance's entity has been initialized
            {
                if (!ABIIT.second->getEntityInitialized()) // if not initialized it initializes the entity
                {
                    ABIIT.second->setEntity(tempBasketball);
                    ABIIT.second->setEntityInitialized(true);
                }
                else
                {

                }
            }
            getFlag()->setActiveBasketballInstancesCreated(true);
            component->setActiveBasketballInstance(activeBasketballInstance);
        }
        else
        {
            logMsg(func +" Unable to create Active Basketball Instances!");
            exit(0);
        }
    }
    else
    {
        
    }

    if (!getFlag()->getCourtInstancesCreated())
    {
        courtStateMSharedPtr courtInstance = gameSetupCourt->createCourtInstances();
        if (courtInstance.size() > 0)
        {
            logMsg(func +" Court Instances Created!!");
            getFlag()->setCourtInstancesCreated(true);
            component->setCourtInstance(courtInstance);
        }
        else
        {
            logMsg(func +" Unable to Create Court Instances!");
            exit(0);
        }
    }
    if (!getFlag()->getActiveCourtInstancesCreated())
    {
        courtStateMSharedPtr courtInstance = component->getCourtInstance();
        courtStateMSharedPtr activeCourtInstance;
        activeCourtInstance = gameSetupCourt->createActiveCourtInstances(courtInstance);
        if (activeCourtInstance.size() > 0)
        {
            logMsg(func +" Active Court Instances Created!!");

            courtEntitySharedPtr tempCourt(new courtEntity);

            for (auto ACIIT : activeCourtInstance) // loop that checks if each active hoop instance's entity has been initialized
            {
                if (!ACIIT.second->getEntity()->getInitialized()) // if not initialized it initializes the entity
                {
                    ACIIT.second->setEntity(tempCourt);
                    ACIIT.second->getEntity()->setInitialized(true);
                }
                else
                {

                }
            }
            getFlag()->setActiveCourtInstancesCreated(true);
            component->setActiveCourtInstance(activeCourtInstance);
        }
        else
        {
            logMsg(func +" Unable to create Active Court Instances!");
            exit(0);
        }
    }
    else
    {

    }
    
    if (!getFlag()->getHoopInstancesCreated())
    {
        hoopStateMSharedPtr hoopInstance = gameSetupHoop->createHoopInstances();
        if (hoopInstance.size() > 0)
        {
            logMsg(func +"Hoop Instances Created!");
            getFlag()->setHoopInstancesCreated(true);
            component->setHoopInstance(hoopInstance);
        }
        else
        {
            logMsg(func +" Unable to Create Hoop Instances!");
            exit(0);
        }

    }
    logMsg(func +" hoop instance size == " +convert->toString(component->getHoopInstance().size()));
    logMsg(func +" hoop instance name == " +component->getHoopInstance()[0]->getEntity()->getName());
        
    if (!getFlag()->getActiveHoopInstancesCreated())
    {
        //FIXME! Should not be hard coded!
        size_t numActiveHoops = 2;
        hoopStateMSharedPtr hoopInstance = component->getHoopInstance();
        hoopStateMSharedPtr activeHoopInstance = gameSetupHoop->createActiveHoopInstances(hoopInstance, numActiveHoops);
        logMsg(func +" active hoop instance size == " +convert->toString(activeHoopInstance.size()));
        logMsg(func +" active hoop instance name == " +activeHoopInstance[0]->getEntity()->getName());
//        exit(0);
        
        if (activeHoopInstance.size() > 0)
        {
            logMsg(func +"Active Hoop Instances Created!");
//            exit(0);
            hoopEntitySharedPtr tempHoop(new hoopEntity);

            for (auto AHIIT : activeHoopInstance) // loop that checks if each active hoop instance's entity has been initialized
            {
                if (!AHIIT.second->getEntityInitialized()) // if not initialized it initializes the entity
                {
                    AHIIT.second->setEntity(tempHoop);
                    AHIIT.second->setEntityInitialized(true);
                }
                else
                {
                    logMsg(func +"Entity already initialized!");
                }
                
                logMsg(func +" active hoop instance name == " +AHIIT.second->getEntity()->getName());

            }          
//            exit(0);

        }
        else
        {
            logMsg(func +" Unable to create Active Hoop Instances!");
            exit(0);
        }
        getFlag()->setActiveHoopInstancesCreated(true);
        component->setActiveHoopInstance(activeHoopInstance);

    }
    else
    {
        
    }
    
    logMsg(func +" active hoop instance size == " +convert->toString(component->getActiveHoopInstance().size()));
    logMsg(func +" active hoop instance name == " +component->getActiveHoopInstance()[0]->getEntity()->getName());

//    exit(0);
    if (!getFlag()->getModelsLoaded())
    {
//        exit(0);
        if (loadModels(render))
        {
            getFlag()->setModelsLoaded(true);
            
        }
        else
        {
            logMsg(func +" Unable to load all models!");
        }
    }
    else
    {

    }
    if (!getFlag()->getNodesCreated() && getFlag()->getModelsLoaded())
    {
        if (createNodes(render))
        {
            getFlag()->setNodesCreated(true);
        }
        else
        {
            logMsg(func + "Unable to Create Nodes!");
        }
    }
    else
    {
        
    }
    setBasketballStartPositions();  // sets starting positions for all basketballs that are instantiated
    setCourtStartPositions();  // sets starting positions for all courts that are instantiated
    setHoopStartPositions();  // sets starting positions for all hoops that are instantiated

//    logMsg("court y == " +convert->toString(getCourtInstance()[0].getNode()->getPosition().y));
//    exit(0);
    component->setTeamInstance(gameSetupTeam->createTeamInstances());  // creates team instances
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
        if (ATIIT.second->getActivePlayerInstancesCreated())
        {
            logMsg(func +" activePlayerInstances Created!");
//            exit(0);
        }
        else
        {
            logMsg(func + " activePlayerInstances NOT Created!!");
            exit(0);
        }
        logMsg(func +" team name == " +ATIIT.second->getName());
        logMsg(func +" ATIIT.second->getActivePlayerInstance().size() == " +convert->toString(ATIIT.second->getActivePlayerInstance().size()));
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
}

bool gameState::updateState(renderEngineSharedPtr render)  // updates the game state
{
    conversionSharedPtr convert = conversion::Instance();
    AISystemSharedPtr ai = AISystem::Instance();
    timing timer; 
    Ogre::Vector3 playerPos;
    basketballStateMSharedPtr activeBasketballInstance = component->getActiveBasketballInstance();
//    teamStateMSharedPtr activeTeamInstance = getActiveTeamInstance();
    std::string func = "gameState::updateState()";

    logMsg(func +" beginning");
   
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
//    logMsg("Updating gameState Logic");

// BEGINING OF TEST COMMENT
    
//    conversionSharedPtr convert = conversion::Instance();
//    sharedPtr<gameEngine> gameE = gameEngine::Instance();
//    networkEngineSharedPtr network = networkEngine::Instance();
    //sharedPtr<physicsEngine> physEngine = physicsEngine::Instance();
//    physicsEngine physEngine;
    
    for (auto ABIIT : activeBasketballInstance)
    {
        ABIIT.second->updateState();
        ABIIT.second->setPlayer(5);
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
    if (getFlag()->getGameSetupComplete())
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

        teamStateMSharedPtr activeTeamInstance = component->getActiveTeamInstance();
        if (activeTeamInstance.size() > 0)
        {
            logMsg(func + " activeTeamInstance.size() == " +convert->toString(activeTeamInstance.size()));
            for (auto ATIIT : activeTeamInstance)
            {
                playerEntityMSharedPtr activePlayerInstance = ATIIT.second->getActivePlayerInstance();
                if (ATIIT.second->getActivePlayerInstancesCreated())
                {
                    logMsg(func +" Wiot!");
                    logMsg(func + " activePlayerInstance.size() == " +convert->toString(activePlayerInstance.size()));
        
                    for (auto APIIT : activePlayerInstance)
                    {
                        if (APIIT.second->getFlag()->getSMNodeSet())
                        {
                            logMsg(func +" Wioooot!");
                            Ogre::Vector3 pos = APIIT.second->getNode()->getPosition();
                            logMsg(func +" pos = " +convert->toString(pos));
                        }
                    }
                }
            }
            
        }
//        exit(0);
        if (!getFlag()->getTipOffComplete())  // calls tip off execution
        {
            if (executeTipOff())
            {
                getFlag()->setTipOffComplete(true);
//                exit(0);
            }
            else
            {
            
            }
        }
        else
        {
            
        }
        
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

//  logMsg("gameState logic updated");
//    exit(0);

    logMsg(func +" end");

    return true;
}

bool gameState::updateActiveTeamInstances(renderEngineSharedPtr render)  // updates all active team instances
{
    teamStateMSharedPtr activeTeamInstance = component->getActiveTeamInstance();
    conversionSharedPtr convert = conversion::Instance();
    gameStateSharedPtr gameInstance;
    std::string func = "gameState::updateActiveTeamInstances()";

    logMsg(func +" beginning");
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

bool gameState::updatePlayerCollisionObjects()  // updates the player collision objects for a team instance
{
    teamStateMSharedPtr activeTeamInstance = component->getActiveTeamInstance();
    conversionSharedPtr convert = conversion::Instance();
 
    std::unordered_map<std::string, btRigidBodySharedPtr> collisionBodies;  // physical bodies to test for collisions with players physBody objects

    std::vector<bool> teamActivePlayersChanged = data->getTeamActivePlayersChanged();
    size_t teamNumber = 0;
    std::string func = "gameState::updatePlayerCollisionObjects()";

    logMsg(func +" beginning");
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
                std::unordered_map<std::string, btRigidBodySharedPtr> activeCollisionBodies;
                std::unordered_map<std::string, btRigidBodySharedPtr> newCollisionBodies;
//                std::unordered_map<std::string, btRigidBodySharedPtr> newCollisionBodies;
                btRigidBodySharedPtr tempBody;
                for (auto ATIIT : activeTeamInstance)
                {
                    if (ATIIT.second->getTeamType() == teamType)
                    {
                        logMsg(func +" woot woot!");
                        activePlayerInstance = ATIIT.second->getActivePlayerInstance();
                        activeCollisionBodies = ATIIT.second->getCollisionBodies();

                        
                    }
                    else
                    {
                        logMsg(func +" toot toot!");
                        collisionPlayerInstance = ATIIT.second->getActivePlayerInstance();
                        std::string position;
                        btRigidBodySharedPtr physBody;
                        for (auto CPIIT : collisionPlayerInstance)  // loops through the other team's activePlayerInstance
                        {
                            if (CPIIT.second->getFlag()->getPhysBodyInitialized())  // verifies that each player's physBody has been initialized
                            {  // inserts the player's position and their collisionBody into newCollisionBodies
                                logMsg(func +" physBody Initialized!");
                                position = CPIIT.first;
                                physBody = CPIIT.second->getPhysics()->getPhysBody();
                                newCollisionBodies.insert(std::pair<std::string, btRigidBodySharedPtr>(position, physBody));  // loads the second hoop
//                                tempBody = physBody;
                                logMsg(func +" position = " +position);
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

                if (activeCollisionBodies.size() > 0)
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
                    if (ATIIT.second->getTeamType() == teamType)
                    {
                        ATIIT.second->setCollisionBodies(activeCollisionBodies);
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

bool gameState::processInput()  // processes input received from the inputState object
{
    conversionSharedPtr convert = conversion::Instance();

    std::string func = "gameState::processInput()";

    logMsg(func +" beginning");
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

}

// These functions check if an object has been created and attmpt to do so if not
/*bool gameState::checkIfPlayerInstanceCreated()  // check if playerInstance object has been created and loaded
{
    conversionSharedPtr convert = conversion::Instance();
    gameSetupPlayersSharedPtr gameSetupPlayer(new gameSetupPlayers);
    playerEntityMSharedPtr playerInstance = getPlayerInstance();
    bool returnType = false;
    std::string func = "gameState::checkIfPlayerInstanceCreated()";
    
    logMsg(func +" beginning");

    if (getPlayerInstanceCreated())
    {
        if (playerInstance.size() > 0)
        {
            logMsg(func +" playerInstance.size() == " +convert->toString(getPlayerInstance().size()));
            returnType = true;
        }
        else
        {
            logMsg(func +" gameState::checkIfPlayerInstanceCreated() player instances not yet created!");
 //           exit(0);
            playerInstance = gameSetupPlayer->createPlayerInstances();
            if (playerInstance.size())
            {
            
                logMsg(func +" Player Instances created!");
//                exit(0);
                setPlayerInstanceCreated(true);
                setPlayerInstance(playerInstance);
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
        playerInstance = gameSetupPlayer->createPlayerInstances();
        if (playerInstance.size())
        {

            logMsg(func +" Player Instances created!");

            setPlayerInstanceCreated(true);
            setPlayerInstance(playerInstance);
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
}*/

bool gameState::checkifJumpBallCreated()  // checks if jumpBall object has been created
{
    conversionSharedPtr convert = conversion::Instance();
    std::string func = "gameState::checkifJumpBallCreated()";

    logMsg(func +" beginning");

    if (getFlag()->getJumpBallCreated())
    {
        return (true);
    }
    else
    {
        sharedPtr<jumpBalls> tempJumpBall(new jumpBalls);
        component->setJumpBall(tempJumpBall);
        getFlag()->setJumpBallCreated(true);
        if (tempJumpBall != nullptr)
        {
            return (true);

        }
    }


    logMsg(func +" end");

    return (false);
}

void gameState::updateDirectionsAndMovements()
{
    //conversion *convert = conversion::Instance();
    conversionSharedPtr convert = conversion::Instance();
//    directions playerDirection, oldPlayerDirection;
//   logMsg("Updating Directions and Movements");

    std::string func = "gameState::updateDirectionsAndMovements()";

    logMsg(func +" beginning");


    if (data->getTeamWithBall() >= 0) // && playerHasBasketball)
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



