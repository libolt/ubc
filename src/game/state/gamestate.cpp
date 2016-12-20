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

#include <unordered_map>
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
UBCBaseSharedPtr gameState::base;  // static copy of base class
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

UBCBaseSharedPtr gameState::getBase()  // retrieves the value of base
{
    return (base);
}
void gameState::setBase(UBCBaseSharedPtr set)  // sets the value of base
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
    boost::shared_ptr<basketballState> bballInstance;  // creates an instance of the basketballs class
    std::string func = "gameState::createTeamInstances()";
    
    logMsg(func +" beginning");

    logMsg(func +" creating temporary baskteball instance");
    logMsg(func +" setting model name");
//  FIXME! these are currently hard coded
    bballInstance->setEntityModelFileName("bball.mesh");
    bballInstance->setEntityName(bballInstance->getModelFileName());
    bballInstance->setEntityNodeName(bballInstance->getModelFileName());
    if (!bballInstance->getBaseInitialized())
    {
        bballInstance->setBase(getBase());
    }
    logMsg(func +" creating steer object");
    basketballSteer *bballSteer = new basketballSteer;  // steer instance
    bballInstance->setSteer(basketballSteerSharedPtr(bballSteer));
    logMsg(func +" setting instance number");
    bballInstance->setNumber(0);
    bballInstance->setNumberSet(true);
//    bballInstance->setModelNeedsLoaded(true);
    getBasketballInstance().push_back(bballInstance);
    
    logMsg(func +" end");
    
    return (true);
}

bool gameState::createTeamInstances()  // creates team Instances
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<loader> load(new loader);
    std::string func = "gameState::createTeamInstances()";
    
    logMsg(func +" beginning");

    teamStateUMSharedPtr tInstance;
/*    teamStateVecSharedPtr tInstance2;
    teamStateSharedPtr tempInstance(new teamState);
//    teamState *tempInstance = new teamState;
    tempInstance->setID(1);
    tempInstance->setCity("tempCity");
    tempInstance->setName("tempTeam");
    tempInstance->setCoach("tempCoach|");
    tempInstance->setTeamType(HOMETEAM);

    tInstance2.push_back(tempInstance);
*/
    logMsg(func +" loadTeams");
    if (load->checkIfTeamsLoaded())
    {
        logMsg(func +" load->getTInstance().size() == " +convert->toString(load->getTInstance().size()));
//        exit(0);
        tInstance = load->getTInstance();
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
    std::string func = "gameState::createCourtInstances()";
    
    logMsg(func +" beginning");

//    exit(0);
//    courtState cInstance;  // creates an instance of the courtState class
//    cInstance.setModelFileName("court.mesh");
//    cInstance.setModelFileName("Court.mesh");
//    exit(0);
    if (load->checkIfCourtsLoaded())
    {
 //       exit(0);
        setCourtInstance(load->getCInstance());
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
}

bool gameState::createHoopInstances()  // creates hoop Instances
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
}
bool gameState::createPlayerInstances()  // creates player instances
{
//    logMsg("gameState::createTeamInstances()");
    
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<loader> load(new loader);
    playerStateUMSharedPtr pInstance;
    std::string func = "gameState::createPlayerInstances()";
    
    logMsg(func +" beginning");
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
    
    logMsg(func +" end");
    
    return (false);
}

bool gameState::createActiveBasketballInstances()  // creates the active basketball instances
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<loader> load(new loader);
    basketballStateVecSharedPtr basketballInstance = getBasketballInstance();
    std::unordered_map<size_t, basketballStateSharedPtr> activeBasketballInstance = getActiveBasketballInstance();
    std::string func = "gameState::createActiveBasketballInstances()";
    
    logMsg(func +" beginning");

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
    
    //FIXME! should not be hard coded
    activeBasketballInstance.insert(std::pair<size_t, basketballStateSharedPtr>(0, basketballInstance[0]));
    setBasketballInstance(basketballInstance);
    setActiveBasketballInstance(activeBasketballInstance);
    logMsg(func +" end");
    return (true);
}

bool gameState::createActiveCourtInstances()  // creates the active court instances
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<loader> load(new loader);
    std::unordered_map<size_t, courtStateSharedPtr> courtInstance = getCourtInstance();
    std::unordered_map<size_t, courtStateSharedPtr> activeCourtInstance = getActiveCourtInstance();
    std::string func = "gameState::createActiveCourtInstances()";
    
    logMsg(func + " beginning");
    
    logMsg(func +" courtInstance.size() == " +convert->toString(courtInstance.size()));
    if (courtInstance.size() == 0)
    {
        if (load->checkIfCourtsLoaded())
        {
            courtInstance = load->getCInstance();
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
    setCourtInstance(courtInstance);
    setActiveCourtInstance(activeCourtInstance);
    logMsg(func +" getCourtInstance.size() == " +convert->toString(getCourtInstance().size()));
    logMsg(func +" end");
    return (true);
}

bool gameState::createActiveHoopInstances()  // creates the active hoop instances
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<loader> load(new loader);
    hoopStateUMSharedPtr hoopInstance = getHoopInstance();
    hoopStateUMSharedPtr activeHoopInstance = getActiveHoopInstance();
    std::string func = "gameState::createActiveHoopInstances()";
    size_t x = 0;
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
/*    for (auto AHIIT : activeHoopInstance)
    {
        
        logMsg(func +" flee!");
        logMsg(func + " AHIIT name == " +AHIIT.second->getName());

        AHIIT.second->setEntityID(x);
        AHIIT.second->setEntityName("hoop" +AHIIT.second->getName());      
        ++x;
        logMsg(func +" entityName == " +AHIIT.second->getEntityName());

    }
*/   
//    exit(0);
    setActiveHoopInstance(activeHoopInstance);
/*    for (auto AHIIT : getActiveHoopInstance())
    {
        logMsg(func + " AHIIT name == " +AHIIT.second->getName());
        logMsg(func + " AHIIT index == " +convert->toString(AHIIT.first));
    }
*/
//    exit(0);
    logMsg(func +" end");
    return (true);
}

bool gameState::createActiveTeamInstances()  // creates the active team instances
{
    teamStateSharedPtr tInstance;
    teamStateUMSharedPtr activeTeamInstance = getActiveTeamInstance();
    teamStateUMSharedPtr teamInstance = getTeamInstance();
    sizeTVec teamIDS = getTeamIDS();
    std::string func = "gameState::createActiveTeamInstances()";

    logMsg(func +" beginning");
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
    logMsg(func +" end");
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
    basketballStateUMSharedPtr activeBasketballInstance = getActiveBasketballInstance();
    bool activeBasketballInstancesCreated = getActiveBasketballInstancesCreated();
//    size_t activeBBallInstance = getActiveBBallInstance();
    basketballStateVecSharedPtr basketballInstance = getBasketballInstance();
    std::string func = "gameState::loadBasketballModel()";
    
    logMsg(func +" beginning");
    
    
    if (!activeBasketballInstancesCreated && activeBasketballInstance.size() == 0)
    {
        if (createActiveBasketballInstances())
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
    else
    {
        
    }

    logMsg(func +" activeBasketballInstance.size() == " +convert->toString(activeBasketballInstance.size()));

    for (auto ABIIT : activeBasketballInstance)
    {
        logMsg(func +" activeBasketballInstance == " +convert->toString(ABIIT.first));
    

        if (!activeBasketballInstance[0]->getBaseInitialized()) // checks to see if the base object for basketballInstance[activeBBallIntance has been initialized
        {
            logMsg(func +" Initializing base!");
            if (!ABIIT.second->getBaseInitialized())
            {
                ABIIT.second->setBase(base);
            }
        }
        logMsg(func +" loading model == " +ABIIT.second->getEntityModelFileName());
        if (ABIIT.second->loadModel())
        {
            logMsg(func +" blee!");
            ABIIT.second->setModelNeedsLoaded(false);
            logMsg(func +" blaa!");
            ABIIT.second->setModelLoaded(true);
            logMsg(func +" blii!");
            ABIIT.second->setupPhysicsObject();
            logMsg(func +" bluu!");
            setActiveBasketballInstance(activeBasketballInstance);
            logMsg(func +" Basketball Model Loaded!");
            return (true);
        }
        else
        {
            logMsg("Failed to load the basketball model!");
        }
    }
    setActiveBasketballInstance(activeBasketballInstance);
    setActiveBasketballInstancesCreated(activeBasketballInstancesCreated);
    
    return (false);
}

bool gameState::loadCourtModel()  // loads selected court model
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<loader> load(new loader);
    courtStateUMSharedPtr courtInstance = getCourtInstance();
    courtStateUMSharedPtr activeCourtInstance = getActiveCourtInstance();
    bool activeCourtInstancesCreated = getActiveCourtInstancesCreated();
    std::string func = "gameState::loadCourtModel()";

    logMsg(func +" beginning");

    if (!activeCourtInstancesCreated && activeCourtInstance.size() == 0)
    {
        if (createActiveCourtInstances())
        {
            logMsg(func +" Active Court Instances Created!");
            activeCourtInstancesCreated = true;
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
    logMsg(func +" Model Name = " +activeCourtInstance[0]->getModelFileName());

    activeCourtInstance[0]->setEntityModelFileName(activeCourtInstance[0]->getModelFileName());
    activeCourtInstance[0]->setEntityNodeName(activeCourtInstance[0]->getModelFileName());
    activeCourtInstance[0]->setEntityName(activeCourtInstance[0]->getModelFileName());
    if (activeCourtInstance[0]->loadModel())
    {
        activeCourtInstance[0]->getNode()->setScale(1.0f,1.0f,1.0f);
        setActiveCourtInstance(activeCourtInstance);
        return (true);
    }
    else
    {
        logMsg(func +" Court model not loaded!");
    }

    setActiveCourtInstancesCreated(activeCourtInstancesCreated);

    logMsg(func +" end");

    return (false);
}

bool gameState::loadHoopModel()  // loads selected hoop model
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    hoopStateUMSharedPtr activeHoopInstance = getActiveHoopInstance();
    boost::shared_ptr<loader> load(new loader);
    std::string func = "gameState::loadHoopModel()";
    bool returnType = true;

    logMsg(func +" beginning");

/*    if (activeHoopInstance.size() == 0)
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
*/
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

/*        logMsg(func + "Name == " +AHIIT.second->getName());
        logMsg(func +" Model Name = " +AHIIT.second->getEntityModelFileName());
        logMsg("AHIIT index == " +convert->toString(AHIIT.second->getEntityID()));
*/
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

bool gameState::loadModels()  // loads all game object models excluding the players
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    bool returnType = true;
    std::string func = "gameState::loadModels()";
    logMsg(func +" beginning");

    if (!basketballModelLoaded)  // Checks if basketball model has been loaded
    {
//        setActiveBBallInstance(0);  // Sets the active basketball instance
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

    
//    exit(0);
    
    return (returnType);
}

void gameState::setBasketballStartPositions()  // sets the initial coordinates for the basketball(s)
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    size_t activeBBallInstance = getActiveBBallInstance();
//    basketballStateVecSharedPtr basketballInstance = getBasketballInstance();
    basketballStateUMSharedPtr activeBasketballInstance = getActiveBasketballInstance();
    std::string func = "gameState::setBasketballStartPositions()";
    
    logMsg(func +" beginning");

    for (auto ABIIT : activeBasketballInstance)
    {
        
        logMsg(func +" activeBasketballInstance == " +convert->toString(ABIIT.first));
    
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//    exit(0);
        ABIIT.second->getNode()->setPosition(0.8f,10.0f,352.0f);
#else
        ABIIT.second->getNode()->setPosition(0.8f,-5.0f,352.0f);
//    exit(0);
#endif
    }
    setActiveBasketballInstance(activeBasketballInstance);
    logMsg(func +" end");
}

void gameState::setCourtStartPositions()  // sets the initial coordinates for the basketball(s)
{

    courtStateUMSharedPtr courtInstance = getCourtInstance();
    std::string func = "gameState::setCourtStartPositions()";

    logMsg(func +" beginning");
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    courtInstance[0]->getNode()->setPosition(0.0f,-6.5f,360.0f);
    courtInstance[0]->setNodePosition(Ogre::Vector3(0.0f,-6.5f,360.0f));
    logMsg(func +" courtPosition");
//exit(0);
#else
    courtInstance[0]->getNode()->setPosition(0.0f,-27.5f,360.0f);
    courtInstance[0]->setNodePosition(Ogre::Vector3(0.0f,-27.5f,360.0f));
#endif

    setCourtInstance(courtInstance);
    logMsg(func +" end");
}

void gameState::setHoopStartPositions()  // sets the initial coordinates for the basketball(s)
{

    hoopStateUMSharedPtr activeHoopInstance = getActiveHoopInstance();
    std::string func = "gameState::setHoopStartPositions()";

    logMsg(func +" beginning");
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    activeHoopInstance[0]->getNode()->setPosition(45.0f,-6.5f,370.0f);
    activeHoopInstance[1]->getNode()->setPosition(-45.0f,-6.5f,370.0f);
#else
    activeHoopInstance[0]->getNode()->setPosition(45.0f,-23.5f,370.0f);
    activeHoopInstance[1]->getNode()->setPosition(-45.0f,-23.5f,370.0f);
#endif

    Ogre::Quaternion hoop0Rotation(Ogre::Degree(-90), Ogre::Vector3::UNIT_Y);
    activeHoopInstance[0]->getNode()->rotate(hoop0Rotation);

    Ogre::Quaternion hoop1Rotation(Ogre::Degree(90), Ogre::Vector3::UNIT_Y);
    activeHoopInstance[1]->getNode()->rotate(hoop1Rotation);

    setActiveHoopInstance(activeHoopInstance);
    logMsg(func +" end");
}

bool gameState::setupTipOff()  // sets up tip off conditions
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    std::string func = "gameState::setupTipOff()";
    jumpBallsSharedPtr jBall;

    logMsg(func +" beginning");

    if (checkifJumpBallCreated())
    {
        jBall = getJumpBall();
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

    if (getTeamWithBall() == NOTEAM && getActiveTeamInstancesCreated())
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
            setJumpBall(jBall);
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
    basketballStateUMSharedPtr activeBasketballInstance = getActiveBasketballInstance();
    std::string func = "gameState::executeTipOff()";

    logMsg(func +" beginning");

    
    if (!getJumpBall()->updateState(getTeamWithBall(), activeBasketballInstance, getActiveTeamInstance(),getQuarter()))
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

    if (!getActiveBasketballInstancesCreated())
    {
        if (createActiveBasketballInstances())
        {
            setActiveBasketballInstancesCreated(true);
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

    if (!getActiveCourtInstancesCreated())
    {
        if (createActiveCourtInstances())
        {
            setActiveCourtInstancesCreated(true);
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
            logMsg(func +" Unable to load all models!");
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
            logMsg(func +" TIC!");
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
    logMsg(func +" dahdah");
    

    if (!setupEnvironmentCompleted)  // checks if environment has been setup
    {
        logMsg(func +" !setupEnvironmentCompleted");
        if(setupEnvironment())  // sets up environment
        {
            logMsg(func +" Environment setup successfully!");
            setupEnvironmentCompleted = true;
        }
    }
//    loads("../../data/players/players.xml");
    
    if (!tipOffSetupComplete)
    {
        logMsg(func +" !tipOffSetupComplete");
        if (setupTipOff())
        {
            logMsg(func + " Tip Off Setup Complete!");
            tipOffSetupComplete = true;  // sets up tip off conditions
        }
    }
    
    logMsg(func +" end");

    return true;
}

bool gameState::updateState()  // updates the game state
{
    boost::shared_ptr<conversion> convert = conversion::Instance();

    std::string func = "gameState::updateState()";

    logMsg(func +" beginning");


    exit(0);
//    logMsg("Updating gameState Logic");

// BEGINING OF TEST COMMENT
/*    AISystemSharedPtr ai = AISystem::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<gameEngine> gameE = gameEngine::Instance();
//    networkEngineSharedPtr network = networkEngine::Instance();
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

    logMsg(func +" end");

    return true;
}

bool gameState::processInput()  // processes input received from the inputState object
{
    boost::shared_ptr<conversion> convert = conversion::Instance();

    std::string func = "gameState::processInput()";

    logMsg(func +" beginning");


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
    logMsg(func +" end");

}

// These functions check if an object has been created and attmpt to do so if not
bool gameState::checkIfPlayerInstanceCreated()  // check if playerInstance object has been created and loaded
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    std::string func = "gameState::checkIfPlayerInstanceCreated()";

    logMsg(func +" beginning");


    if (getPlayerInstanceCreated())
    {
        if (getPlayerInstance().size() > 0)
        {
            logMsg(func +" getPlayerInstance().size() == " +convert->toString(getPlayerInstance().size()));
            return (true);
        }
        else
        {
            logMsg(func +" gameState::checkIfPlayerInstanceCreated() player instances not yet created!");
 //           exit(0);
            if (createPlayerInstances())
            {
            
                logMsg(func +" player instances created!");
//                exit(0);
                setPlayerInstanceCreated(true);
                return (true);
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
        if (createPlayerInstances())
        {

            logMsg(func +" player instances created!");

            setPlayerInstanceCreated(true);
            return (true);
//            exit(0);
        }
        else
        {
            logMsg(func +" player instances not created!");
            exit(0);
        }
//        return (false);
    }
    
    logMsg(func +" end");

    
    return (true);
}

bool gameState::checkifJumpBallCreated()  // checks if jumpBall object has been created
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    std::string func = "gameState::checkifJumpBallCreated()";

    logMsg(func +" beginning");

    if (getJumpBallCreated())
    {
        return (true);
    }
    else
    {
        boost::shared_ptr<jumpBalls> tempJumpBall(new jumpBalls);
        setJumpBall(tempJumpBall);
        setJumpBallCreated(true);
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
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    directions playerDirection, oldPlayerDirection;
//   logMsg("Updating Directions and Movements");

    std::string func = "gameState::updateDirectionsAndMovements()";

    logMsg(func +" beginning");


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
    
    logMsg(func +" end");

    
}



