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
#include "state/hoopstate.h".
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

gameState::gameState()  // constructor
{
/*    
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

//    stateSet = false;
    */
}

gameState::~gameState()  // destructor
{
}

std::vector<courtData>	gameState::getCourtDataInstance()  // retrieves the value of courtDataInstance
{
	return (courtDataInstance);
}
void gameState::setCourtDataInstance(std::vector<courtData> set)  // sets the value of courtDataInstance
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

std::vector<size_t> gameState::getPlayerID()  // retrieves the value of playerID
{
    return (playerID);
}
void gameState::setPlayerID(std::vector<size_t> set)  // sets the value of playerID
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

bool gameState::assignHoopToTeams()  // assigns which hoop belongs to each team
{
    getActiveTeamInstance()[0]->setHoop(1);
    getActiveTeamInstance()[1]->setHoop(0);
    return (true);
}

bool gameState::createInstances()  // creates object instances
{
    bool returnType = true;
    logMsg("gameState creating instances!");
    if (!getPlayerInstanceCreated())
    {
        logMsg("player Instances not created!");
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
/*    if (!getTeamInstancesCreated())
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
    }*/
//    exit(0);
    return (returnType);
}
bool gameState::createBasketballInstances()  // creates basketball Instances
{
    logMsg("creating temporary baskteball instance");
    basketballState bballInstance;  // creates an instance of the basketballs class
    logMsg("setting model name");
    bballInstance.setEntityModelFileName("bball.mesh");
    bballInstance.setEntityName(bballInstance.getModelFileName());
    bballInstance.setEntityNodeName(bballInstance.getModelFileName());

    logMsg("creating steer object");
    basketballSteer *bballSteer = new basketballSteer;  // steer instance
    bballInstance.setSteer(boost::shared_ptr<basketballSteer>(bballSteer));
    logMsg("setting instance number");
    bballInstance.setNumber(0);
    bballInstance.setNumberSet(true);
//    bballInstance.setModelNeedsLoaded(true);
    getBasketballInstance().push_back(bballInstance);
    return (true);
}

bool gameState::createTeamInstances()  // creates team Instances
{
//    exit(0);
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<loader> load = loader::Instance();
    
    std::vector<boost::shared_ptr<teamState> > tInstance;
    tInstance = load->loadTeams();
    logMsg("tInstance size == " +convert->toString(tInstance.size()));
//    exit(0);
/*    logMsg("teamID.size() == " +convert->toString(getTeamIDS().size()));
    logMsg("tInstance size = " +convert->toString(tInstance.size()));
    logMsg("tInstance city 0 = " +tInstance[0]->getCity());

//    exit(0);
///    teamInstance[0].setTeamID(teamID[0]);
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
*/
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
    boost::shared_ptr<loader> load = loader::Instance();

//    courtState cInstance;  // creates an instance of the courtState class
//    cInstance.setModelFileName("court.mesh");
//    cInstance.setModelFileName("Court.mesh");
    setCourtInstance(load->loadCourts());

    if (getCourtInstance().size() > 0)
    {
        logMsg("Court Instances SET!");
        return (true);
    }
    else
    {
        logMsg("Court Instances NOT SET!!");
//        exit(0);
        return (false);
    }

    return (true);
}

bool gameState::createHoopInstances()  // creates hoop Instances
{
    hoopState *hInstance = new hoopState[2];  // creates an instance of the hoopState class
//    cInstance.setModelFileName("court.mesh");
    hInstance[0].setEntityName("hoop1");
    hInstance[0].setEntityModelFileName("Hoop.mesh");
    hInstance[0].setEntityNodeName("hoopNode1");

    hInstance[1].setEntityName("hoop2");
    hInstance[1].setEntityModelFileName("Hoop.mesh");
    hInstance[1].setEntityNodeName("hoopNode2");

    getHoopInstance().push_back(hInstance[0]);  // loads the first hoop
    getHoopInstance().push_back(hInstance[1]);  // loads the second hoop

    return (true);
}
bool gameState::createPlayerInstances()  // creates player instances
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<loader> load = loader::Instance();
    boost::shared_ptr<playerState> playerStateSharedPtr = boost::shared_ptr<playerState>(new playerState);
//    gameS = tempGameStateSharedPtr;

//    boost::shared_ptr<playerState> pState(new playerState);
    setPlayerInstances(load->loadPlayers());
    if (getPlayerInstance().size() > 0)
    {
        logMsg("playerInstance size == " +convert->toString(getPlayerInstance().size()));
//        logMsg("player name = " +getPlayerInstance()[0]->getPlayerName());
//        exit(0);
        return (true);
    }
    return (false);
}

bool gameState::createActiveTeamInstances()  // creates the active team instances
{
    boost::shared_ptr<teamState> tInstance;
    std::vector<boost::shared_ptr<teamState> > activeTeamInstance = getActiveTeamInstance();
    std::vector<boost::shared_ptr<teamState> > teamInstance = getTeamInstance();
    std::vector<size_t> teamIDS = getTeamIDS();
//    exit(0);

    activeTeamInstance.push_back(tInstance);  // adds empty teamState to activeTeamInstance vector
    activeTeamInstance.push_back(tInstance);  // adds empty teamState to activeTeamInstance vector

    activeTeamInstance[0] = teamInstance[teamIDS[0]];
    activeTeamInstance[1] = teamInstance[teamIDS[1]];
    activeTeamInstance[0]->setTeamID(teamIDS[0]);
    activeTeamInstance[1]->setTeamID(teamIDS[1]);
    activeTeamInstance[0]->setTeamType(HOMETEAM);
    activeTeamInstance[1]->setTeamType(AWAYTEAM);
    activeTeamInstance[0]->setHumanControlled(true);
    activeTeamInstance[1]->setHumanControlled(false);
    activeTeamInstance[0]->setTeamColObject(COL_TEAM1);
    activeTeamInstance[1]->setTeamColObject(COL_TEAM2);
    activeTeamInstance[0]->setTeamCollidesWith(COL_COURT /* | COL_BBALL | COL_TEAM2;   determines what team0 collides with*/);
    activeTeamInstance[1]->setTeamCollidesWith(COL_COURT /* | COL_BBALL | COL_TEAM2;   determines what team1 collides with*/);
    activeTeamInstance[0]->setupState();
    activeTeamInstance[1]->setupState();

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
    size_t activeBBallInstance = getActiveBBallInstance();
    std::vector<basketballState> basketballInstance = getBasketballInstance();
    logMsg("loading bball");
    logMsg("activeBBallInstance == " +convert->toString(activeBBallInstance));
    logMsg("loading model " +basketballInstance[activeBBallInstance].getEntityModelFileName());
    if (basketballInstance[activeBBallInstance].loadModel())
    {
        basketballInstance[activeBBallInstance].setModelNeedsLoaded(false);
        basketballInstance[activeBBallInstance].setModelLoaded(true);
        basketballInstance[activeBBallInstance].setupPhysicsObject();
        setBasketballInstance(basketballInstance);
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
    std::vector<courtState> courtInstance = getCourtInstance();
    size_t activeCourtInstance = getActiveCourtInstance();
    logMsg("Model Name = " +courtInstance[activeCourtInstance].getModelFileName());

    courtInstance[activeCourtInstance].setEntityModelFileName(courtInstance[activeCourtInstance].getModelFileName());
    courtInstance[activeCourtInstance].setEntityNodeName(courtInstance[activeCourtInstance].getModelFileName());
    courtInstance[activeCourtInstance].setEntityName(courtInstance[activeCourtInstance].getModelFileName());
    if (courtInstance[activeCourtInstance].loadModel())
    {
        courtInstance[activeCourtInstance].getNode()->setScale(1.0f,1.0f,1.0f);
        setCourtInstance(courtInstance);
        return (true);
    }
    else
    {
        logMsg("Court model not loaded!");
    }
    return (false);
}

bool gameState::loadHoopModel()  // loads selected hoop model
{
    bool returnType = true;

    std::vector<hoopState> hoopInstance = getHoopInstance();

    if (hoopInstance[0].loadModel())
    {
        hoopInstance[0].getNode()->setScale(0.8f,0.8f,0.8f);
    }
    else
    {
        logMsg("Unable to load model for hoopInstance[0]");
        returnType = false;
    }
    if (hoopInstance[1].loadModel())
    {
        hoopInstance[1].getNode()->setScale(0.8f,0.8f,0.8f);
    }
    else
    {
        logMsg("Unable to load model for hoopInstance[1]");
        returnType = false;
    }
    setHoopInstance(hoopInstance);
    return (returnType);
}

bool gameState::loadModels()  // loads all game object models excluding the players
{
    bool returnType = true;
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
            logMsg("Unable to load basketball model!");
            returnType = false;
        }

        // FIXEME! this should not be hard coded
    }

    if (!courtModelLoaded)  // Checks if the court model has been loaded
    {
        logMsg("Loading court model!");
        if (loadCourtModel())  // load the court model
        {
            courtModelLoaded = true;
//            return (true);
        }
        else
        {
            logMsg("Unable to load the court model!");
            returnType = false;
        }
    }


    if (!hoopModelLoaded)  // Checks if the hoop model(s) have been loaded
    {
        logMsg("Loading hoop model(s)!");
        if (loadHoopModel())  // Creates the hoop instances
        {
            hoopModelLoaded = true;
//            return (true);
        }
        else
        {
            logMsg("Unable to load the hoop model(s)!");
            returnType = false;
        }
    }


    return (returnType);
}

void gameState::setBasketballStartPositions()  // sets the initial coordinates for the basketball(s)
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    size_t activeBBallInstance = getActiveBBallInstance();
    std::vector<basketballState> basketballInstance = getBasketballInstance();

    logMsg("activeBBallInstance == " +convert->toString(activeBBallInstance));
    
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    exit(0);
    basketballInstance[activeBBallInstance].getNode()->setPosition(0.8f,10.0f,352.0f);
#else
    basketballInstance[activeBBallInstance].getNode()->setPosition(0.8f,-5.0f,352.0f);
//    exit(0);
#endif
    setBasketballInstance(basketballInstance);
}

void gameState::setCourtStartPositions()  // sets the initial coordinates for the basketball(s)
{

    std::vector<courtState> courtInstance = getCourtInstance();

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    courtInstance[0].getNode()->setPosition(0.0f,-6.5f,360.0f);
    courtInstance[0].setNodePosition(Ogre::Vector3(0.0f,-6.5f,360.0f));
    logMsg("courtPosition");
//exit(0);
#else
	courtInstance[0].getNode()->setPosition(0.0f,-27.5f,360.0f);
    courtInstance[0].setNodePosition(Ogre::Vector3(0.0f,-27.5f,360.0f));
#endif

    setCourtInstance(courtInstance);
}

void gameState::setHoopStartPositions()  // sets the initial coordinates for the basketball(s)
{

    std::vector<hoopState> hoopInstance = getHoopInstance();

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    hoopInstance[0].getNode()->setPosition(45.0f,-6.5f,370.0f);
    hoopInstance[1].getNode()->setPosition(-45.0f,-6.5f,370.0f);
#else
    hoopInstance[0].getNode()->setPosition(45.0f,-23.5f,370.0f);
   hoopInstance[1].getNode()->setPosition(-45.0f,-23.5f,370.0f);
#endif

    Ogre::Quaternion hoop0Rotation(Ogre::Degree(-90), Ogre::Vector3::UNIT_Y);
    hoopInstance[0].getNode()->rotate(hoop0Rotation);

    Ogre::Quaternion hoop1Rotation(Ogre::Degree(90), Ogre::Vector3::UNIT_Y);
    hoopInstance[1].getNode()->rotate(hoop1Rotation);

    setHoopInstance(hoopInstance);
}

bool gameState::setupTipOff()  // sets up tip off conditions
{
    boost::shared_ptr<jumpBalls> jumpBall = getJumpBall();

    teamTypes currentTeam = jumpBall->getBallTippedToTeam();

    std::vector<playerPositions> jumpBallPlayer = jumpBall->getJumpBallPlayer();
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
/*
    boost::shared_ptr<AISystem> ai = AISystem::Instance();
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
    boost::shared_ptr<loader> load = loader::Instance();
    //boost::shared_ptr<physicsEngine> physEngine = physicsEngine::Instance();
    physicsEngine physEngine;
    boost::shared_ptr<conversion> convert = conversion::Instance();

    logMsg("Setting up state!");

    if (!modelsLoaded)
    {
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

    logMsg("court y == " +convert->toString(getCourtInstance()[0].getNode()->getPosition().y));
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
//    std::vector<playerState> pInstance = getPlayerInstance();
//        player->setModel(playerModels);
//    Ogre::Vector3 playerPos = playerNodes.at(0)->getPosition();
//    Ogre::Vector3 offset;
//    offset[0] = 2.0f;
//    offset[1] = 2.0f;
//    offset[2] = 2.0f;
//	bball->setAutoTracking(true,playerNode[0],playerNode[0]->getPosition(),offset);
//	bball->setPosition(playerPos[0] +2.0f, playerPos[1] + 4.0f, playerPos[2] - 1.0f);
//    exit(0);

    if (!setupEnvironmentCompleted)  // checks if environment has been setup
    {
    	if(setupEnvironment())	// sets up environment
    	{
            setupEnvironmentCompleted = true;
    	}
    }
//    loads("../../data/players/players.xml");

    if (!tipOffSetupComplete)
    {
        tipOffSetupComplete = setupTipOff();  // sets up tip off conditions
    }
*/
    return true;
}

bool gameState::updateState()  // updates the game state
{
//    logMsg("Updating gameState Logic");

// BEGINING OF TEST COMMENT
/*    boost::shared_ptr<AISystem> ai = AISystem::Instance();
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
        	processNetworkEvents();	 // processes data received from the network
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
//		    logMsg("teamWithBall is " +convert->toString(teamWithBall));
//          logMsg("playetWithBall is " +convert->toString(teamInstance[teamWithBall].getPlayerWithBall()));
//		    float currentTime = static_cast<float>(gameE->getLoopTime().getMilliseconds()/100);
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
        physEngine.updateState();	// updates the state of the physics simulation
        logMsg("stepWorld");
//        exit(0);
        physEngine.stepWorld(getTimer());  // steps the physics simulation
///    logMsg("DirectionsAndMovement");
///    updateDirectionsAndMovements();

//	  exit(0);

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

//        std::vector<size_t> playerDirection = player->getPlayerDirection(); // stores contents of playerDirectdion from players class in local variable
//        std::vector<size_t> oldPlayerDirection = player->getOldPlayerDirection();   // stores contents of oldPlayerDirection form players in local variable

        // Initiates offense or defense for a team depending on value of teamWithBall
        if (teamWithBall == 0)	// if 0 puts team 0 on offense and team 1 on defense
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
//    	    exit(0);
        }
        else
        {
        }

    }

//	logMsg("gameState logic updated");
//    exit(0);
*/
    return true;
}

void gameState::updateDirectionsAndMovements()
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    directions playerDirection, oldPlayerDirection;
//   logMsg("Updating Directions and Movements");

    if (getTeamWithBall() >= 0) // && playerHasBasketball)
    {
//		logMsg("teamWithBall ios " +convert->toString(teamWithBall));
//		logMsg("playetWithBall is " +convert->toString(activeTeamInstance[teamWithBall].getPlayerWithBall()));
//        updateBasketballMovements();	// updates the movement of basketball objec(s)
        //updateBasketballDirections(); // updates direction of basketball object(s)
    }
    else
    {
    }
}



