/***************************************************************************
 *   . . opyright (C) 1999 - 2015 by Mike McLean                              *
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

//#include "boost/shared_array.hpp"
#include "engine/networkengine.h"
#include "ai/ai.h"
#include "ai/basketballsteer.h"
#include "conversion.h"
#include "state/basketballstate.h"
#include "state/courtstate.h"
#include "state/gamestate.h"
#include "state/hoopstate.h"
#include "state/playerstate.h"
#include "state/teamstate.h"
#include "engine/gameengine.h"
#include "load.h"
#include "logging.h"
#include "network/networkplayerstateobject.h"
#include "data/playerdata.h"
#include "engine/physicsengine.h"
#include "engine/renderengine.h"
#include "timing.h"
#include "ubc.h"
#include "jumpballs.h"

/*
boost::shared_ptr<gameState> gameState::pInstance;

boost::shared_ptr<gameState> gameState::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        
        boost::shared_ptr<gameState> tInstance(new gameState);
        pInstance = tInstance;
    }
    return pInstance; // address of sole instance
}
*/

// static declarations
boost::shared_ptr<UBCBase> gameState::base;  // static copy of base class
gameState::gameState()  // constructor
{
    inputReceived = true;
    
//    basketballInstancesCreated = false;
//    courtInstancesCreated = false;
//    hoopInstancesCreated = false;
//    playerInstancesCreated = false;
//    teamInstancesCreated = false;
//    activeTeamInstancesCreated = false;
    basketballModelLoaded = false;
    courtModelLoaded = false;
    hoopModelLoaded = false;
    modelsLoaded = false;
    setupEnvironmentCompleted = false;
    courtDataLoaded = false;
    gameStarted = false;
//    teamWithBall = NOTEAM;
    tipOffSetupComplete = false;
//    tipOffComplete = false;
    selectedCourtDataInstance = -1;
    sceneCreated = false;
//    activeBBallInstance = -1;
//    activeCourtInstance = -1;

//    gameType = NOGAME;
//    gameSetupComplete = false;

    //playerHasBasketball = false;
    bballBounce = -1;
//    quarter = NOQUARTER;
    gameTimeLeft = 0.0f;
    quarterTimeLeft = 0.0f;
    finished = false;

    numActiveHoops = 2;
    
//    stateSet = false;
    
}

gameState::~gameState()  // destructor
{
}

boost::shared_ptr<UBCBase> gameState::getBase()  // retrieves the value of base
{
    return (base);
}
void gameState::setBase(boost::shared_ptr<UBCBase> set)  // sets the value of base
{
    base = set;
}

courtDataVec  gameState::getCourtDataInstance()  // retrieves the value of courtDataInstance
{
    return (courtDataInstance);
}
void gameState::setCourtDataInstance(courtDataVec set)  // sets the value of courtDataInstance
{
    courtDataInstance = set;
}

size_t gameState::getSelectedCourtDataInstance()  // retrieves the value of selectedCourtDataInstance
{
    return (selectedCourtDataInstance);
}
void gameState::setSelectedCourtDataInstance(size_t set)  // sets the value of selectedCourtDataInstance
{
    selectedCourtDataInstance = set;
}

sizeTVec gameState::getPlayerID()  // retrieves the value of playerID
{
    return (playerID);
}
void gameState::setPlayerID(sizeTVec set)  // sets the value of playerID
{
    playerID = set;
}

bool gameState::getGameStarted()  // retrieves the value of gameStarted
{
    return(gameStarted);
}
void gameState::setGameStarted(bool set)  // sets the value of gameStarted
{
    gameStarted = set;
}

bool gameState::getTipOffSetupComplete()  // retrieves the value of tipOffSetupComplete
{
    return (tipOffSetupComplete);
}
void gameState::setTipOffSetupComplete(bool set)  // sets the value of tipOffSetupComplete
{
    tipOffSetupComplete = set;
}

size_t gameState::getBballBounce()  // retrieves the value of bballBounce
{
    return (bballBounce);
}
void gameState::setBballBounce(size_t set)  // sets the value of bballBounce
{
    bballBounce = set;
}

bool gameState::getCourtDataLoaded()  // retrieves the value of courtDataLoaded
{
    return (courtDataLoaded);
}
void gameState::setCourtDataLoaded(bool set)  // sets the value of courtDataLoaded
{
    courtDataLoaded = set;
}

bool gameState::getModelsLoaded()  // retrieves the value of modelsLoaded
{
    return (modelsLoaded);
}
void gameState::setModelsLoaded(bool set)  // sets the value of modelsLoaded
{
    modelsLoaded = set;
}

bool gameState::getInputReceived()  // retrieves the value of inputReceived
{
    return (inputReceived);
}
void gameState::setInputReceived(bool set)  // sets the value of inputReceived
{
    inputReceived = set;
}

inputInGameWorkQueues gameState::getInputInGameWorkQueue()  // retrieves the value of inputInGameWorkQueue
{
    return (inputInGameWorkQueue);
}
void gameState::setInputInGameWorkQueue(inputInGameWorkQueues set)  // sets the value of inputInGameWorkQueue
{
    inputInGameWorkQueue = set;
}

bool gameState::assignHoopToTeams()  // assigns which hoop belongs to each team
{
//TS    getActiveTeamInstance()[0]->setHoop(1);
//TS    getActiveTeamInstance()[1]->setHoop(0);
    return (true);
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
    
    if (!getHoopInstanceCreated())
    {
        if (createHoopInstances())  // create hoop instances
        {
            setHoopInstanceCreated(true);
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
bool gameState::createBasketballInstances()  // creates basketball Instances
{
    logMsg("creating temporary baskteball instance");
    boost::shared_ptr<basketballState> bballInstance;  // creates an instance of the basketballs class
    logMsg("setting model name");
//  FIXME! these are currently hard coded
    bballInstance->setEntityModelFileName("bball.mesh");
    bballInstance->setEntityName(bballInstance->getModelFileName());
    bballInstance->setEntityNodeName(bballInstance->getModelFileName());
    if (!bballInstance->getBaseInitialized())
    {
        bballInstance->setBase(getBase());
    }
    logMsg("creating steer object");
    basketballSteer *bballSteer = new basketballSteer;  // steer instance
    bballInstance->setSteer(boost::shared_ptr<basketballSteer>(bballSteer));
    logMsg("setting instance number");
    bballInstance->setNumber(0);
    bballInstance->setNumberSet(true);
//    bballInstance->setModelNeedsLoaded(true);
    getBasketballInstance().push_back(bballInstance);
    return (true);
}

bool gameState::createTeamInstances()  // creates team Instances
{
    logMsg("gameState::createTeamInstances()");
    
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<loader> load(new loader);
    
    std::tr1::unordered_map <size_t, teamStateSharedPtr> tInstance;
/*    teamStateVecSharedPtr tInstance2;
    boost::shared_ptr<teamState> tempInstance(new teamState);
//    teamState *tempInstance = new teamState;
    tempInstance->setID(1);
    tempInstance->setCity("tempCity");
    tempInstance->setName("tempTeam");
    tempInstance->setCoach("tempCoach|");
    tempInstance->setTeamType(HOMETEAM);

    tInstance2.push_back(tempInstance);
*/
    logMsg("gameState::createTeamInstances() loadTeams");
    if (load->checkIfTeamsLoaded())
    {
        logMsg("gameState::createTeamInstances() load->getTInstance().size() == " +convert->toString(load->getTInstance().size()));
//        exit(0);
        tInstance = load->getTInstance();
        if (tInstance.size() > 0)
        {
            logMsg("gameState::createTeamInstances() tInstance Loaded!");
            setTeamInstance(tInstance);
        }
        else
        {
            logMsg("gameState::createTeamInstances() tInstance NOT Loaded!");
        }
    }
    else
    {
        logMsg("gameState::createTeamInstances() loading of teams failed!");
        return (false);
    }
    

//    exit(0);
    logMsg("gameState::createTeamInstances() uno");
    

    logMsg("gameState::createTeamInstances() tInstance.size() == " +convert->toString(tInstance.size()));
    logMsg("gameState::createTeamInstances() too");
    
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
        logMsg("teamInstance CREATED!!");
//        exit(0);
    }
    else 
    {
        logMsg("Failed to create Team Instances!");
        exit(0);
        return (false);
    }

    return (true);
}

/*bool gameState::createCourtDataInstances()  // creates instances of court data
{
    boost::shared_ptr<loader> load = loader::Instance();
    courtDataInstance = load->loadCourts();
    return (true);
}*/

bool gameState::createCourtInstances()  // creates court Instances
{
    boost::shared_ptr<loader> load(new loader);
//    exit(0);
//    courtState cInstance;  // creates an instance of the courtState class
//    cInstance.setModelFileName("court.mesh");
//    cInstance.setModelFileName("Court.mesh");
//    exit(0);
    if (load->checkIfCourtsLoaded())
    {
 //       exit(0);
        setCourtInstance(load->getCInstance());
        logMsg("Court Instances SET!");
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
    return (true);
}

bool gameState::createHoopInstances()  // creates hoop Instances
{
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

    return (true);
}
bool gameState::createPlayerInstances()  // creates player instances
{
//    logMsg("gameState::createTeamInstances()");
    
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<loader> load(new loader);
    std::tr1::unordered_map<size_t, playerStateSharedPtr> pInstance;
    std::string func = "gameState::createPlayerInstances()";
    
    logMsg(func +" checkIfPlayersLoaded");
//    exit(0);
    if (load->checkIfPlayersLoaded())
    {
        logMsg(func +" checkIfPlayersLoaded true");

        pInstance = load->getPInstance();
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
    return (false);
}

bool gameState::createActiveHoopInstances()  // creates the active hoop instances
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<loader> load(new loader);
    std::tr1::unordered_map <size_t, hoopStateSharedPtr> hoopInstance = getHoopInstance();
    std::tr1::unordered_map <size_t, hoopStateSharedPtr> activeHoopInstance = getActiveHoopInstance();
    std::string func = "gameState::createActiveHoopInstances()";

    logMsg(func +" beginning");
    
    if (hoopInstance.size() == 0)
    {
        if (load->checkIfHoopsLoaded())
        {
            logMsg(func + " abada!");
            hoopInstance = load->getHInstance();
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
    
    for (auto x=0;x<numActiveHoops; ++x)
    {
        activeHoopInstance.insert(std::pair<size_t, hoopStateSharedPtr>(x, hoopInstance[0]));
    }
    
    for (auto AHIIT : activeHoopInstance)
    {
        AHIIT.second->setEntityName("hoop" +convert->toString(AHIIT.first));

        logMsg("entityName == " +AHIIT.second->getEntityName());
    }
//    exit(0);
    setActiveHoopInstance(activeHoopInstance);
    
    return (true);
}

bool gameState::createActiveTeamInstances()  // creates the active team instances
{
    teamStateSharedPtr tInstance;
    std::tr1::unordered_map <size_t, teamStateSharedPtr> activeTeamInstance = getActiveTeamInstance();
    std::tr1::unordered_map <size_t, teamStateSharedPtr> teamInstance = getTeamInstance();
    sizeTVec teamIDS = getTeamIDS();
//    exit(0);

    activeTeamInstance.insert(std::pair<size_t, teamStateSharedPtr>(0, tInstance));  // adds empty teamState to activeTeamInstance vector
    activeTeamInstance.insert(std::pair<size_t, teamStateSharedPtr>(1, tInstance));  // adds empty teamState to activeTeamInstance vector

/*TS    activeTeamInstance[0] = teamInstance[teamIDS[0]];
    activeTeamInstance[1] = teamInstance[teamIDS[1]];
    activeTeamInstance[0]->setID(teamIDS[0]);
    activeTeamInstance[1]->setID(teamIDS[1]);
    activeTeamInstance[0]->setTeamType(HOMETEAM);
    activeTeamInstance[1]->se0tTeamType(AWAYTEAM);
    activeTeamInstance[0]->setHumanControlled(true);
    activeTeamInstance[1]->setHumanControlled(false);
    activeTeamInstance[0]->setTeamColObject(COL_TEAM1);
    activeTeamInstance[1]->setTeamColObject(COL_TEAM2);
    activeTeamInstance[0]->setTeamCollidesWith(COL_COURT); // | COL_BBALL | COL_TEAM2;   determines what team0 collides with
    activeTeamInstance[1]->setTeamCollidesWith(COL_COURT); // | COL_BBALL | COL_TEAM2;   determines what team1 collides with
    activeTeamInstance[0]->setupState();
    activeTeamInstance[1]->setupState();
TS*/
    setActiveTeamInstance(activeTeamInstance);
    return (true);
}

bool gameState::setupEnvironment()
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
    
/*
    // Set ambient light
    render->getMSceneMgr()->setAmbientLight(ColourValue(0.5, 0.5, 0.5));

    // Create a light
    Light* l = render->getMSceneMgr()->createLight("MainLight");
    l->setPosition(20,80,56);
*/

    return (true);
}
bool gameState::loadBasketballModel()  // loads selected basketball model
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<loader> load(new loader);

    size_t activeBBallInstance = getActiveBBallInstance();
    basketballStateVecSharedPtr basketballInstance = getBasketballInstance();
    std::string func = "gameState::loadBasketballModel()";
    
    logMsg(func +" beginning");
    
    logMsg("loading bball");
    logMsg(func +" activeBBallInstance == " +convert->toString(activeBBallInstance));
    logMsg(func +" basketballInstance.size() == " +convert->toString(basketballInstance.size()));
    if (basketballInstance.size() == 0)
    {
        if (load->checkIfBasketballsLoaded())
        {
            basketballInstance = load->getBInstance();
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
    logMsg(func +" basketballInstance.size() == " +convert->toString(basketballInstance.size()));
    if (!basketballInstance[activeBBallInstance]->getBaseInitialized()) // checks to see if the base object for basketballInstance[activeBBallIntance has been initialized
    {
        logMsg(func +" Initializing base!");
        if (!basketballInstance[activeBBallInstance]->getBaseInitialized())
        {
            basketballInstance[activeBBallInstance]->setBase(base);
        }
    }
    logMsg(func +" loading model == " +basketballInstance[activeBBallInstance]->getEntityModelFileName());
    if (basketballInstance[activeBBallInstance]->loadModel())
    {
        logMsg(func +" blee!");
        basketballInstance[activeBBallInstance]->setModelNeedsLoaded(false);
        logMsg(func +" blaa!");
        basketballInstance[activeBBallInstance]->setModelLoaded(true);
        logMsg(func +" blii!");
        basketballInstance[activeBBallInstance]->setupPhysicsObject();
        logMsg(func +" bluu!");
        setBasketballInstance(basketballInstance);
        logMsg(func +" Basketball Model Loaded!");
        return (true);
    }
    else
    {
        logMsg("Failed to load the basketball model!");
    }
    return (false);
}

bool gameState::loadCourtModel()  // loads selected court model
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<loader> load(new loader);
    std::tr1::unordered_map <size_t, courtStateSharedPtr> courtInstance = getCourtInstance();
    size_t activeCourtInstance = getActiveCourtInstance();

    std::string func = "gameState::loadCourtModel()";

    logMsg(func +" beginning");

    if (courtInstance.size() == 0)
    {
        if (load->checkIfCourtsLoaded())
        {
            logMsg(func + " abada!");
            courtInstance = load->getCInstance();
            logMsg(func + " abadeeee!");
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
    logMsg(func + " activeCourtInstance == " +convert->toString(activeCourtInstance));
    logMsg(func +" Model Name = " +courtInstance[activeCourtInstance]->getModelFileName());

    courtInstance[activeCourtInstance]->setEntityModelFileName(courtInstance[activeCourtInstance]->getModelFileName());
    courtInstance[activeCourtInstance]->setEntityNodeName(courtInstance[activeCourtInstance]->getModelFileName());
    courtInstance[activeCourtInstance]->setEntityName(courtInstance[activeCourtInstance]->getModelFileName());
    if (courtInstance[activeCourtInstance]->loadModel())
    {
        courtInstance[activeCourtInstance]->getNode()->setScale(1.0f,1.0f,1.0f);
        setCourtInstance(courtInstance);
        return (true);
    }
    else
    {
        logMsg(func +" Court model not loaded!");
    }
    return (false);
}

bool gameState::loadHoopModel()  // loads selected hoop model
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    std::tr1::unordered_map <size_t, hoopStateSharedPtr> activeHoopInstance = getActiveHoopInstance();
    boost::shared_ptr<loader> load(new loader);
    std::string func = "gameState::loadHoopModel()";
    bool returnType = true;

    logMsg(func +" beginning");

    if (activeHoopInstance.size() == 0)
    {
        if (createActiveHoopInstances())
        {
            logMsg(func +" Active Hoop Instances created!");
        }
        else
        {
            logMsg(func +" Unable to create Active Hoop Instances!");
            exit(0);
        }
    }
    else
    {
        
    }
    
    logMsg(func +" activeHoopInstance.size() == " +convert->toString(activeHoopInstance.size()));
//    logMsg(func + " activeCourtInstance == " +convert->toString(activeCourtInstance));
    
    for (auto AHIIT : activeHoopInstance)
    {
        logMsg(func +" Model Name = " +AHIIT.second->getEntityModelFileName());
        std::string name = "hoop" +convert->toString(AHIIT.first);
        std:: string nodeName = name +"node";
        logMsg(func +" nodeName == " +nodeName);
        AHIIT.second->setEntityName(name);
        AHIIT.second->setEntityNodeName(nodeName);
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
/*    if (hoopInstance[1]->loadModel())
    {
        hoopInstance[1]->getNode()->setScale(0.8f,0.8f,0.8f);
    }
    else
    {
        logMsg(func +" Unable to load model for hoopInstance[1]");
        returnType = false;
    }
    */
    setActiveHoopInstance(activeHoopInstance);

    logMsg(func +" end");

    return (returnType);
}

bool gameState::loadModels()  // loads all game object models excluding the players
{
    bool returnType = true;
    std::string func = "gameState::loadModels()";
    logMsg(func +" beginning");

    if (!basketballModelLoaded)  // Checks if basketball model has been loaded
    {
        setActiveBBallInstance(0);  // Sets the active basketball instance
        logMsg("Loading basketball Model!");
        if (loadBasketballModel())  // Loads the basketball model
        {
            basketballModelLoaded = true;
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
    if (!courtModelLoaded)  // Checks if the court model has been loaded
    {
        logMsg(func +" Loading court model!");
        if (loadCourtModel())  // load the court model
        {
            courtModelLoaded = true;
//            return (true);
        }
        else
        {
            logMsg(func +" Unable to load the court model!");
            returnType = false;
        }
    }


    if (!hoopModelLoaded)  // Checks if the hoop model(s) have been loaded
    {
        logMsg(func +" Loading hoop model(s)!");
        if (loadHoopModel())  // Creates the hoop instances
        {
            hoopModelLoaded = true;
//            return (true);
        }
        else
        {
            logMsg(func +" Unable to load the hoop model(s)!");
            returnType = false;
        }
    }

    return (returnType);
}

void gameState::setBasketballStartPositions()  // sets the initial coordinates for the basketball(s)
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    size_t activeBBallInstance = getActiveBBallInstance();
    basketballStateVecSharedPtr basketballInstance = getBasketballInstance();

    std::string func = "gameState::setBasketballStartPositions()";
    logMsg(func +" activeBBallInstance == " +convert->toString(activeBBallInstance));
    
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//    exit(0);
    basketballInstance[activeBBallInstance]->getNode()->setPosition(0.8f,10.0f,352.0f);
#else
    basketballInstance[activeBBallInstance]->getNode()->setPosition(0.8f,-5.0f,352.0f);
//    exit(0);
#endif
    setBasketballInstance(basketballInstance);
}

void gameState::setCourtStartPositions()  // sets the initial coordinates for the basketball(s)
{

    static std::tr1::unordered_map <size_t, courtStateSharedPtr> courtInstance = getCourtInstance();

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    courtInstance[0]->getNode()->setPosition(0.0f,-6.5f,360.0f);
    courtInstance[0]->setNodePosition(Ogre::Vector3(0.0f,-6.5f,360.0f));
    logMsg("courtPosition");
//exit(0);
#else
    courtInstance[0]->getNode()->setPosition(0.0f,-27.5f,360.0f);
    courtInstance[0]->setNodePosition(Ogre::Vector3(0.0f,-27.5f,360.0f));
#endif

    setCourtInstance(courtInstance);
}

void gameState::setHoopStartPositions()  // sets the initial coordinates for the basketball(s)
{

    std::tr1::unordered_map <size_t, hoopStateSharedPtr> hoopInstance = getHoopInstance();

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    hoopInstance[0]->getNode()->setPosition(45.0f,-6.5f,370.0f);
    hoopInstance[1]->getNode()->setPosition(-45.0f,-6.5f,370.0f);
#else
    hoopInstance[0]->getNode()->setPosition(45.0f,-23.5f,370.0f);
   hoopInstance[1]->getNode()->setPosition(-45.0f,-23.5f,370.0f);
#endif

    Ogre::Quaternion hoop0Rotation(Ogre::Degree(-90), Ogre::Vector3::UNIT_Y);
    hoopInstance[0]->getNode()->rotate(hoop0Rotation);

    Ogre::Quaternion hoop1Rotation(Ogre::Degree(90), Ogre::Vector3::UNIT_Y);
    hoopInstance[1]->getNode()->rotate(hoop1Rotation);

    setHoopInstance(hoopInstance);
}

bool gameState::setupTipOff()  // sets up tip off conditions
{
    jumpBallsSharedPtr jumpBall = getJumpBall();

    teamTypes currentTeam = jumpBall->getBallTippedToTeam();

    playerPositionsVec jumpBallPlayer = jumpBall->getJumpBallPlayer();
    if (getTeamWithBall() == NOTEAM && getActiveTeamInstancesCreated())
    {
        if (!jumpBall->getSetupComplete())
        {
            jumpBall->setJumpBallLocation(CENTERCIRCLE);
            jumpBallPlayer.clear();
            jumpBallPlayer.push_back(C);
            jumpBallPlayer.push_back(C);
            jumpBall->setJumpBallPlayer(jumpBallPlayer);
            jumpBall->setSetupComplete(true);
            jumpBall->setExecuteJumpBall(true);
            setJumpBall(jumpBall);
            return (true);
        }
        else
        {
            
        }
    }
    return (false);
}

bool gameState::executeTipOff()  // executes tip off
{
    if (!getJumpBall()->updateState(getTeamWithBall(), getActiveBBallInstance(), getBasketballInstance(), getActiveTeamInstance(),getQuarter()))
    {
        logMsg("tipOff not complete!");
//        exit(0);
    }
    else
    {
        return (true);
    }
    return (false);
}

// sets up the game condition
bool gameState::setupState()  // sets up the game condition
{
//    exit(0);

    AISystemSharedPtr ai = AISystem::Instance();
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    boost::shared_ptr<loader> load = loader::Instance();
    //boost::shared_ptr<physicsEngine> physEngine = physicsEngine::Instance();
    physicsEngine physEngine;
    boost::shared_ptr<conversion> convert = conversion::Instance();
    std::string func = "gameState::setupState()";
   
    logMsg(func +" beginning");

    if (!getActiveHoopInstancesCreated())
    {
        if (createActiveHoopInstances())
        {
            setActiveHoopInstancesCreated(true);
        }
        else
        {
            logMsg(func +" Unable to create Active Hoop Instances!");
            exit(0);
        }
    }
    else
    {
        
    }
    
    if (!modelsLoaded)
    {
//        exit(0);
        if (loadModels())
        {
            modelsLoaded = true;
        }
        else
        {
            logMsg("Unable to load all models!");
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
    if (!getTeamInstancesCreated())  // checks if teamInstances have been created
    {
        if(createTeamInstances())  // creates the team instances
        {
            logMsg("TIC!");
            setTeamInstancesCreated(true);
//            assignHoopToTeams();  // assigns proper hoop to the teams that were created.
        }
    }

    // sets the quarter being played to the first one.
    setQuarter(FIRST);
//    basketballInstance[activeBBallInstance].getNode()->setPosition(1.4f,5.0f,366.0f);


///FIXME    physEngine.setupState();  // sets up the Physics Engine state
//    exit(0);
    ai->setup();

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
//    exit(0);

    if (!setupEnvironmentCompleted)  // checks if environment has been setup
    {
        if(setupEnvironment())  // sets up environment
        {
            setupEnvironmentCompleted = true;
        }
    }
//    loads("../../data/players/players.xml");

    if (!tipOffSetupComplete)
    {
        tipOffSetupComplete = setupTipOff();  // sets up tip off conditions
    }

    logMsg(func +" end");

    return true;
}

bool gameState::updateState()  // updates the game state
{
    boost::shared_ptr<conversion> convert = conversion::Instance();

    
    exit(0);
//    logMsg("Updating gameState Logic");

// BEGINING OF TEST COMMENT
/*    AISystemSharedPtr ai = AISystem::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<gameEngine> gameE = gameEngine::Instance();
//    boost::shared_ptr<networkEngine> network = networkEngine::Instance();
    //boost::shared_ptr<physicsEngine> physEngine = physicsEngine::Instance();
    physicsEngine physEngine;
    
    if (!getBasketballInstanceCreated() && getBasketballInstanceNeedCreated())
    {
        logMsg("Creating Basketball Instances!");
        if (createBasketballInstances())
        {
            setBasketballInstanceCreated(true);
            setBasketballInstanceNeedCreated(false);
//            assignHoopToTeams();
            logMsg("Basketball Instances Created!");
        }
        else
        {
            logMsg("Unable to Create Basketball Instances!");
            exit(0);
        }
    }
    
    if (!getCourtInstancesCreated() && getCourtInstancesNeedCreated())
    {
        logMsg("Creating Cpurt Instances!");
        if (createBasketballInstances())
        {
            setCourtInstancesCreated(true);
            setCourtInstancesNeedCreated(false);
//            assignHoopToTeams();
            logMsg("Court Instances Created!");
        }
        else
        {
            logMsg("Unable to Create Cpurt Instances!");
            exit(0);
        }
    }
    
    if (!getHoopInstanceCreated() && getHoopInstanceNeedCreated())
    {
        logMsg("Creating Hoop Instances!");
        if (createHoopInstances())
        {
            setHoopInstanceCreated(true);
            setHoopInstanceNeedCreated(false);
//            assignHoopToTeams();
            logMsg("Hoop Instances Created!");
        }
        else
        {
            logMsg("Unable to Create Hoop Instances!");
            exit(0);
        }
    }
    
    if (!getActiveTeamInstancesCreated() && getActiveTeamInstancesNeedCreated())
    {
        logMsg("Creating active team instances!");
        if (createActiveTeamInstances())
        {
            setActiveTeamInstancesCreated(true);
            assignHoopToTeams();
            logMsg("Team instances created!");
        }
        else
        {
            logMsg("Unable to create Active Team Instances!");
            exit(0);
        }
    }
*/
// END OF TEST COMMENT    
/*    timing timer = gameE->getTimer();
    Ogre::Vector3 playerPos;

    basketballInstance[activeBBallInstance].updateState();

    basketballInstance[activeBBallInstance].setPlayer(5);

    if (gameSetupComplete)
    {

        if (network->getPacketReceived())  // checks if a packet was received by network engine
        {
            processNetworkEvents();  // processes data received from the network
        }
        else
        {
            
        }
        
        logMsg("network events processed");

        if (!tipOffComplete)  // calls tip off execution
        {
            if (executeTipOff())
            {
                tipOffComplete = true;
//                exit(0);
            }
            else
            {
            
            }
        }
        else
        {
            
        }
        
        if (teamWithBall != NOTEAM)
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
            
        }

        logMsg("Physics");
        physEngine.updateState();   // updates the state of the physics simulation
        logMsg("stepWorld");
//        exit(0);
        physEngine.stepWorld(getTimer());  // steps the physics simulation
///    logMsg("DirectionsAndMovement");
///    updateDirectionsAndMovements();

//    exit(0);

        // updates the basketball(s) state
        logMsg("Updated basketball state!");
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
        if (teamWithBall == 0)  // if 0 puts team 0 on offense and team 1 on defense
        {
            activeTeamInstance[0].setOffense(true);
            activeTeamInstance[0].setDefense(false);

            activeTeamInstance[1].setOffense(false);
            activeTeamInstance[1].setDefense(true);
        }
        else if (teamWithBall == 1)  // if 1 puts team 1 on offense and team 0 on defense
        {
            activeTeamInstance[0].setOffense(false);
            activeTeamInstance[0].setDefense(true);

            activeTeamInstance[1].setOffense(true);
            activeTeamInstance[1].setDefense(false);
        }
        else
        {
        }

        // updates the state of each team
        if (activeTeamInstancesCreated)
        {
            //FIXME crash in updateState code
            activeTeamInstance[0].updateState();
            activeTeamInstance[1].updateState();
//          exit(0);
        }
        else
        {
        }

    }

//  logMsg("gameState logic updated");
//    exit(0);
*/
    return true;
}

bool gameState::processInput()  // processes input received from the inputState object
{
    boost::shared_ptr<conversion> convert = conversion::Instance();

        if (getActiveTeamInstancesCreated())
        {
//            exit(0);
            size_t inputIterator = 0;
//            while (inputIterator < getActiveTeamInstance().size())
            for (auto ATIIT : getActiveTeamInstance())
            {
/*TS                if (getActiveTeamInstance()[inputIterator]->getPlayerInstancesCreated())
                {
                    playerStateVecSharedPtr activePlayerInstance = getActiveTeamInstance()[inputIterator]->getActivePlayerInstance();
                    if (getActiveTeamInstance()[inputIterator]->getHumanControlled())
                    {
                        int humanPlayer = getActiveTeamInstance()[inputIterator]->getHumanPlayer();
                        logMsg("inputHumanPlayer == " +convert->toString(humanPlayer));
                        //inputMaps inputMap = input->keyMap();
//                        inputWorkInGameQueues inputInGameQueue = base->getGameE()->getInputE()->getInputWorkQueue();
//                      logMsg("INPUT MAP ======== "  +toString(inputMap));
                        std::stringstream ss;
//                      exit(0);
                        size_t x = 0;
                        size_t humanInstance = 11;
                        while (x < activePlayerInstance.size())
                        {
                            logMsg("GEPlayerID == " +convert->toString(activePlayerInstance[x]->getID()));
                            logMsg("GEHumanPlayer == " +convert->toString(humanPlayer));

                            if (activePlayerInstance[x]->getID() == humanPlayer)
                            {
                                humanInstance = x;
                                break;
                            }
                            ++x;
                        }
                        logMsg("humanInstance == " +convert->toString(humanInstance));
                        logMsg("inputHumanPlayer == " +convert->toString(humanPlayer));
                        logMsg("inputInGameWorkQueue.size = " +convert->toString(inputInGameWorkQueue.size()));
                        x = 0;
                        int activeBBallInstance = getActiveBBallInstance();
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
                        playerStateVecSharedPtr activePInstance = getTeamInstance()[inputIterator]->getActivePlayerInstance();
                        logMsg("humanInstance == " +convert->toString(humanInstance));
                        //logMsg("inPassSteal == " +convert->toString(activePInstance[humanInstance]->getPassSteal()));
                        //exit(0);

                        /// FIXME! This if statement should be adapted to work correctly instead of relying on the i variable
                        int i = 0;
                        if (getTeamWithBall() == i)
                        {
                            if (activePlayerInstance[humanInstance]->getMovement())
                            {
                                logMsg("human playerID == " +convert->toString(activePlayerInstance[humanInstance]->getID()));
                                logMsg("ball player == " +convert->toString(getActiveTeamInstance()[inputIterator]->getPlayerWithBallInstance()));
                                logMsg("ball playerID == " +convert->toString(getActiveTeamInstance()[inputIterator]->getPlayerWithBallID()));
                                if (activePlayerInstance[humanInstance]->getID() == getActiveTeamInstance()[inputIterator]->getPlayerWithBallID())
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
TS*/                
            }            
        }
}

// These functions check if an object has been created and attmpt to do so if not
bool gameState::checkIfPlayerInstanceCreated()  // check if playerInstance object has been created and loaded
{
    boost::shared_ptr<conversion> convert = conversion::Instance();

    if (getPlayerInstanceCreated())
    {
        if (getPlayerInstance().size() > 0)
        {
            logMsg("getPlayerInstance().size() == " +convert->toString(getPlayerInstance().size()));
            return (true);
        }
        else
        {
            logMsg("gameState::checkIfPlayerInstanceCreated() player instances not yet created!");
 //           exit(0);
            if (createPlayerInstances())
            {
            
                logMsg("player instances created!");
//                exit(0);
                setPlayerInstanceCreated(true);
                return (true);
//            exit(0);
            }
            else
            {
                logMsg("player instances not created!");
                exit(0);
            }
        }
//        exit(0);
    }
    else
    {
        logMsg("player instances not yet created!");
        if (createPlayerInstances())
        {

            logMsg("player instances created!");

            setPlayerInstanceCreated(true);
            return (true);
//            exit(0);
        }
        else
        {
            logMsg("player instances not created!");
            exit(0);
        }
//        return (false);
    }
    return (true);
}

void gameState::updateDirectionsAndMovements()
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    directions playerDirection, oldPlayerDirection;
//   logMsg("Updating Directions and Movements");

    if (getTeamWithBall() >= 0) // && playerHasBasketball)
    {
//      logMsg("teamWithBall ios " +convert->toString(teamWithBall));
//      logMsg("playetWithBall is " +convert->toString(activeTeamInstance[teamWithBall].getPlayerWithBall()));
//        updateBasketballMovements();  // updates the movement of basketball objec(s)
        //updateBasketballDirections(); // updates direction of basketball object(s)
    }
    else
    {
    }
}



