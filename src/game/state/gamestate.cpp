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

//#include "boost/shared_array.hpp"
#include "network/network.h"
#include "ai/ai.h"
#include "conversion.h"
#include "state/gamestate.h"
#include "engine/gameengine.h"
#include "load.h"
#include "logging.h"
#include "network/networkplayerstateobject.h"
#include "data/playerdata.h"
#include "physics/physicsengine.h"
#include "engine/renderengine.h"
#include "timing.h"

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

gameState::gameState()  // constructor
{
    basketballInstancesCreated = false;
    courtInstancesCreated = false;
    hoopInstancesCreated = false;
    playerInstancesCreated = false;
    teamInstancesCreated = false;
    courtModelLoaded = false;
    hoopModelLoaded = false;
    setupEnvironmentCompleted = false;
    courtDataLoaded = false;
    gameStarted = false;
    teamWithBall = NOTEAM;
    tipOffSetupComplete = false;
    tipOffComplete = false;
    selectedCourtDataInstance = -1;
    
    activeBBallInstance = -1;

    gameType = NOGAME;
    gameSetupComplete = false;

    //playerHasBasketball = false;
    bballBounce = -1;
    quarter = NOQUARTER;
    gameTimeLeft = 0.0f;
    quarterTimeLeft = 0.0f;
    finished = false;

//    stateSet = false;
}

gameState::~gameState()  // destructor
{
}

gameTypes gameState::getGameType()  // retrieves the value of gameType
{
    return(gameType);
}
void gameState::setGameType(gameTypes set)  // sets the value of gameType
{
    gameType = set;
}

quarters gameState::getQuarter()  // retrieves the value of quarter
{
    return (quarter);
}
void gameState::setQuarters(quarters set)  // sets he value of quarter
{
    quarter = set;
}

bool gameState::getGameSetupComplete()  // retrieves the value of gameSetupComplete
{
    return (gameSetupComplete);
}
void gameState::setGameSetupComplete(bool set)  // sets the value of gameSetupComplete
{
    gameSetupComplete = set;
}

std::vector <courtState> gameState::getCourtInstance()  // retrieves the value of courtInstance
{
    return (courtInstance);
}
void gameState::setCourtInstance(std::vector<courtState> set)  // sest the value of courtInstance
{
    courtInstance = set;
}

std::vector <hoopState> gameState::getHoopInstance()  // retrieves the value of hoopInstance
{
    return (hoopInstance);
}
void gameState::setHoopInstance(std::vector<hoopState> set)  // sets the value of hoopInstance
{
    hoopInstance = set;
}

std::vector<teamData> gameState::getTeamDataInstance()  // retrieves the value of teamDataInstance
{
	return (teamDataInstance);
}
void gameState::setTeamDataInstance(std::vector<teamData> set)  // sets the value of teamDataInstance
{
    teamDataInstance = set;
}

std::vector<playerState> gameState::getPlayerInstance()  // retrieves the value of playerInstance
{
	return (playerInstance);
}
void gameState::setPlayerInstances(std::vector<playerState> set)  // sets the value of playerInstance
{
    playerInstance = set;
}

std::vector<courtData>	gameState::getCourtDataInstance()  // retrieves the value of courtDataInstance
{
	return (courtDataInstance);
}
void gameState::setCourtDataInstance(std::vector<courtData> set)  // sets the value of courtDataInstance
{
    courtDataInstance = set;
}

size_t gameState::getActiveBBallInstance()  // retrieves the value of activeBBallInstance
{
    return (activeBBallInstance);
}
void gameState::setActiveBBallInstance(size_t set)  // sets the value of activeBBallInstance
{
    activeBBallInstance = set;
}

size_t gameState::getSelectedCourtDataInstance()  // retrieves the value of selectedCourtDataInstance
{
    return (selectedCourtDataInstance);
}
void gameState::setSelectedCourtDataInstance(size_t set)  // sets the value of selectedCourtDataInstance
{
    selectedCourtDataInstance = set;
}

std::vector<size_t> gameState::getTeamID()  // retrieves the value of teamID
{
    return (teamID);
}
void gameState::setTeamID(std::vector<size_t> set)  // sets the value of teamID
{
    teamID = set;
}

std::vector<size_t> gameState::getPlayerID()  // retrieves the value of playerID
{
    return (playerID);
}
void gameState::setPlayerID(std::vector<size_t> set)  // sets the value of playerID
{
    playerID = set;
}

std::vector< std::vector<size_t> > gameState::getTeamStarterID()  // retrieves value of teamStarterID
{
    return (teamStarterID);
}
void gameState::setTeamStarterID(std::vector< std::vector<size_t> > set)  // sets the value of teamStarterID
{
    teamStarterID = set;
}

std::vector <teamState> gameState::getTeamInstance()  // retrieves the value of teamInstance
{
    return (teamInstance);
}
void gameState::setTeamInstance(std::vector<teamState> set)  // sets the value of teamInstance
{
    teamInstance = set;
}

std::vector <basketballState> gameState::getBasketballInstance()  // retrieves the value of basketballInstance
{
    return (basketballInstance);
}
void gameState::setBasketballInstance(std::vector<basketballState> set)  // sets the value of basketballInstance
{
    basketballInstance = set;
}

bool gameState::getGameStarted()  // retrieves the value of gameStarted
{
    return(gameStarted);
}
void gameState::setGameStarted(bool set)  // sets the value of gameStarted
{
    gameStarted = set;
}

jumpBalls gameState::getJumpBall()  // retrieves the value of jumpBall
{
 return (jumpBall);
}
void gameState::setJumpBall(jumpBalls &set)  // sets the value of jumpBall
{
    jumpBall = set;
}

bool gameState::getTipOffSetupComplete()  // retrieves the value of tipOffSetupComplete
{
    return (tipOffSetupComplete);
}
void gameState::setTipOffSetupComplete(bool set)  // sets the value of tipOffSetupComplete
{
    tipOffSetupComplete = set;
}

bool gameState::getTipOffComplete()  // retrieves the value of tipOffComplete
{
    return (tipOffComplete);
}
void gameState::setTipOffComplete(bool set)  // sets the value of tipOffComplete
{
    tipOffComplete = set;
}

teamTypes gameState::getTeamWithBall()  // retrieves the value of teamWithBall
{
    return (teamWithBall);
}
void gameState::setTeamWithBall(teamTypes set)  // sets the value of teamWithBall
{
    teamWithBall = set;
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

bool gameState::getBasketballInstancesCreated()  // gets the value of basketballInstancesCreated
{
    return (basketballInstancesCreated);
}
void gameState::setBasketballInstancesCreated(bool set)  // sets the value of basketballInstancesCreated
{
    basketballInstancesCreated = set;
}

bool gameState::getCourtInstanceCreated()  // gets the value of the courtInstanceCreated
{
    return (courtInstanceCreated);
}
void gameState::setCourtInstanceCreated(bool set)  // sets the value of the courtInstanceCreated
{
    courtInstanceCreated = set;
}

bool gameState::getHoopInstancesCreated()  // retrieves the value of hoopInstancesCreated
{
    return (hoopInstancesCreated);
}
void gameState::setHoopInstancesCreated(bool created)  // sets the value of hoopInstancesCreated
{
    hoopInstancesCreated = set;
}

bool gameState::getPlayerInstanceCreated()  // retrieves the value of playerInstancesCreated
{
    return (playerInstancesCreated);
}
void gameState::setPlayerInstanceCreated(bool created)  // sets the value of playerInstancesCreated
{
    playerInstancesCreated = set;
}

bool gameState::getTeamInstancesCreated()  // gets the value of teamInstancesCreated
{
    return (teamInstancesCreated);
}
void gameState::setTeamInstancesCreated(bool set)  // sets the value of teamInstancesCreated
{
    teamInstancesCreated = set;
}

bool gameState::getCourtModelLoaded()  // retrieves the value of courtModelLoaded
{
    return (courtModelLoaded);
}
void gameState::setCourdModelLoaded(bool set)  // sets the value of courtModelLoaded
{
    courtModelLoaded = true;
}

/*bool gameState::getStateSet()  // retrieves the value of stateSet
{
    return (stateSet);
}
void gameState::setStateSet(bool set)  // sets the value of stateSet
{
    stateSet = set;
}
*/

bool gameState::assignHoopToTeams()  // assigns which hoop belongs to each team
{
    teamInstance[0].setHoop(1);
    teamInstance[1].setHoop(0);
    return (true);
}

bool gameState::createInstances()  // creates object instances
{
    if (!playerInstancesCreated)
    {
        if (createPlayerInstances())  // create player instances
        {
            playerInstancesCreated = true;
            return (true);
        }
        else 
        {
            logMsg("Failed to create playerInstances!");
        }
    }
    
    if (!teamInstancesCreated)
    {
        if (createTeamInstances())  // create team instances
        {
            teamInstancesCreated = true;
            return (true);
        }
        else 
        {
            logMsg("Failed to create teamInstances!");
        }
    }
    
    if (!courtInstancesCreated)
    { 
        if (createCourtInstances())  // create court instances
        {
            courtInstancesCreated = true;
            return (true);
        }
        else 
        {
            logMsg("Failed to create courtInstances!");
        }
    }
    
    if (!hoopInstancesCreated)
    {
        if (createHoopInstances())  // create hoop instances
        {
            hoopInstancesCreated = true
            return (true);
        }
        else 
        {
            logMsg("Failed to create hoopInstances!");
        }
    }
    
    if (!basketballInstancesCreated)
    {
        if (createBasketbaInstances())  // create basketball instances
        {
            basketballInstancesCreated = true;
            return (true);
        }
        else 
        {
            logMsg("Failed to create basketballInstances!");
        }
    }
    
    return (false);
}
bool gameState::createBasketballInstances()  // creates basketball Instances
{
    logMsg("creating temporary baskteball instance");
    basketballState bballInstance;  // creates an instance of the basketballs class
    logMsg("setting model name");
    bballInstance.setEntityModelFileName("bball.mesh");
    bballInstance.setEntityName(bballInstance.getModelFileName());
    bballInstance.setEntityNodeName(bballInstance.getModelFileName());

    logMsg("loading model");
    if (bballInstance.loadModel())
    {
        bballInstance.setModelNeedsLoaded(false);
        bballInstance.setModelLoaded(true);
        bballInstance.setupPhysicsObject();
    }
    logMsg("creating steer object");
    basketballSteer *bballSteer = new basketballSteer;  // steer instance
    bballInstance.setSteer(bballSteer);
    logMsg("setting instance number");
    bballInstance.setNumber(0);
    bballInstance.setNumberSet(true);
//    bballInstance.setModelNeedsLoaded(true);
    basketballInstance.push_back(bballInstance);
    return (true);
}

bool gameState::createTeamInstances()  // creates team Instances
{
    teamState tInstance;
    teamInstance.push_back(tInstance);  // adds empty teamState to teamInstance vector
    teamInstance.push_back(tInstance);  // adds empty teamState to teamInstance vector

    teamInstance[0].setTeamID(teamID[0]);
    teamInstance[1].setTeamID(teamID[1]);
    teamInstance[0].setTeamType(HOMETEAM);
    teamInstance[1].setTeamType(AWAYTEAM);
    teamInstance[0].setHumanControlled(true);
    teamInstance[1].setHumanControlled(false);
    teamInstance[0].setTeamColObject(COL_TEAM1);
    teamInstance[1].setTeamColObject(COL_TEAM2);
    teamInstance[0].setTeamCollidesWith(COL_COURT /* | COL_BBALL | COL_TEAM2;   determines what team0 collides with*/);
    teamInstance[1].setTeamCollidesWith(COL_COURT /* | COL_BBALL | COL_TEAM2;   determines what team1 collides with*/);
    teamInstance[0].setupState();
    teamInstance[1].setupState();
//	exit(0);
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
    courtInstance = load->loadCourts();

    return (true);
}

bool gameState::createHoopInstances()  // creates hoop Instances
{
    hoopState *hInstance = new hoopState[2];  // creates an instance of the hoopState class
//    cInstance.setModelFileName("court.mesh");
    hInstance[0].setEntityName("hoop1");
    hInstance[0].setModelFileName("Hoop.mesh");
    hInstance[0].setNodeName("hoopNode1");
    hInstance[0].loadModel();
    hInstance[0].getNode()->setScale(0.8f,0.8f,0.8f);

    hInstance[1].setEntityName("hoop2");
    hInstance[1].setModelFileName("Hoop.mesh");
    hInstance[1].setNodeName("hoopNode2");
    hInstance[1].loadModel();
    hInstance[1].getNode()->setScale(0.8f,0.8f,0.8f);

    hoopInstance.push_back(hInstance[0]);  // loads the first hoop
    hoopInstance.push_back(hInstance[1]);  // loads the second hoop

    return (true);
}
bool gameState::createPlayerInstances()  // creates player instances
{
    boost::shared_ptr<loader> load = loader::Instance();

    playerInstance = load->loadPlayers();
    if (playerInstance.size() > 0)
    {
        logMsg("player name = " +playerInstance[0].getPlayerName());
//        exit(0);
        return (true);
    }
    return (false);
}

bool gameState::setupEnvironment()
{
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
/*
    // Set ambient light
    render->getMSceneMgr()->setAmbientLight(ColourValue(0.5, 0.5, 0.5));

    // Create a light
    Light* l = render->getMSceneMgr()->createLight("MainLight");
    l->setPosition(20,80,56);
*/

    return (true);
}

bool gameState::loadCourtModel()  // loads selected court model
{
    logMsg("Model Name = " +courtInstance[selectedCourtInstance].getModelFileName());

    courtInstance[selectedCourtInstance].setEntityModelFileName(courtInstance[selectedCourtInstance].getModelFileName());
    courtInstance[selectedCourtInstance].setEntityNodeName(courtInstance[selectedCourtInstance].getModelFileName());
    courtInstance[selectedCourtInstance].setEntityName(courtInstance[selectedCourtInstance].getModelFileName());
    if (courtInstance[selectedCourtInstance].loadModel())
    {
        courtInstance[selectedCourtInstance].getNode()->setScale(1.0f,1.0f,1.0f);
        return (true)
    }
    else
    {
        logMsg("Court model not loaded!");
    }
    return (false);
}

void gameState::setBasketballStartPositions()  // sets the initial coordinates for the basketball(s)
{

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    basketballInstance[activeBBallInstance].getNode()->setPosition(0.8f,10.0f,352.0f);
#else
    basketballInstance[activeBBallInstance].getNode()->setPosition(0.8f,-5.0f,352.0f);
#endif
}

void gameState::setCourtStartPositions()  // sets the initial coordinates for the basketball(s)
{
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    courtInstance[0].getNode()->setPosition(0.0f,-6.5f,360.0f);
    courtInstance[0].setNodePosition(Ogre::Vector3(0.0f,-6.5f,360.0f));
    logMsg("courtPosition");
//exit(0);
#else
	courtInstance[0].getNode()->setPosition(0.0f,-27.5f,360.0f);
    courtInstance[0].setNodePosition(Ogre::Vector3(0.0f,-27.5f,360.0f));
#endif
}

void gameState::setHoopStartPositions()  // sets the initial coordinates for the basketball(s)
{
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
}

bool gameState::setupTipOff()  // sets up tip off conditions
{
    teamTypes currentTeam = jumpBall.getBallTippedToTeam();

    std::vector<playerPositions> jumpBallPlayer = jumpBall.getJumpBallPlayer();
    if (teamWithBall == NOTEAM && teamInstancesCreated)
    {
        if (!jumpBall.getSetupComplete())
        {
            jumpBall.setJumpBallLocation(CENTERCIRCLE);
            jumpBallPlayer.clear();
            jumpBallPlayer.push_back(C);
            jumpBallPlayer.push_back(C);
            jumpBall.setJumpBallPlayer(jumpBallPlayer);
            jumpBall.setSetupComplete(true);
            jumpBall.setExecuteJumpBall(true);
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
    if (!jumpBall.updateState())
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
    boost::shared_ptr<AISystem> ai = AISystem::Instance();
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
    boost::shared_ptr<loader> load = loader::Instance();
    //boost::shared_ptr<physicsEngine> physEngine = physicsEngine::Instance();
    physicsEngine physEngine;
    boost::shared_ptr<conversion> convert = conversion::Instance();

    logMsg("Setting up state!");

    if (!courtModelLoaded)
    {
        logMsg("creating court instances!");
        if (createCourtInstances())  // creates the court instances
        {
            courtModelLoaded = true;
            courtInstanceCreated = true;
        }
    }

    if (!basketballInstancesCreated)  // checks if court model has been loaded
    {
        logMsg("creating basketball instances!");
    	if (createBasketballInstances())  // creates the basketball instances
    	{
            basketballInstancesCreated = true;
    	}

        // FIXEME! this should not be hard coded
        activeBBallInstance = 0;  // sets the active basketball instance
    }

    if (!hoopModelLoaded)
    {
        logMsg("creating hoop instances!");
        if (createHoopInstances())  // creates the hoop instances
        {
            hoopModelLoaded = true;
        }
    }

    setBasketballStartPositions();  // sets starting positions for all basketballs that are instantiated
    setCourtStartPositions();  // sets starting positions for all courts that are instantiated
    setHoopStartPositions();  // sets starting positions for all hoops that are instantiated

    logMsg("court y == " +convert->toString(courtInstance[0].getNode()->getPosition().y));
//    exit(0);
    if (!teamInstancesCreated)  // checks if teamInstances have been created
    {
        if(createTeamInstances())  // creates the team instances
        {
            logMsg("TIC!");
            teamInstancesCreated = true;
            assignHoopToTeams();  // assigns proper hoop to the teams that were created.
        }
    }

    // sets the quarter being played to the first one.
    quarter = FIRST;
//    basketballInstance[activeBBallInstance].getNode()->setPosition(1.4f,5.0f,366.0f);


    physEngine.setupState();  // sets up the Physics Engine state
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

    return true;
}

bool gameState::updateState()  // updates the game state
{
//    logMsg("Updating gameState Logic");

    boost::shared_ptr<AISystem> ai = AISystem::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<gameEngine> gameE = gameEngine::Instance();
    boost::shared_ptr<networkEngine> network = networkEngine::Instance();
    //boost::shared_ptr<physicsEngine> physEngine = physicsEngine::Instance();
    physicsEngine physEngine;
    timing timer = gameE->getTimer();
    Ogre::Vector3 playerPos;

    basketballInstance[activeBBallInstance].updateState();

    basketballInstance[activeBBallInstance].setPlayer(5);

    if (gameSetupComplete)
    {
    if (network->getPacketReceived())  // checks if a packet was received by network engine
    {
    	processNetworkEvents();	 // processes data received from the network
    }
    logMsg("network events processed");

    if (!tipOffComplete)  // calls tip off execution
    {
        if (executeTipOff())
        {
            tipOffComplete = true;
//            exit(0);
        }
    }

    if (teamWithBall != NOTEAM)
    {
//		logMsg("teamWithBall is " +convert->toString(teamWithBall));
//        logMsg("playetWithBall is " +convert->toString(teamInstance[teamWithBall].getPlayerWithBall()));
//		float currentTime = static_cast<float>(gameE->getLoopTime().getMilliseconds()/100);
        long currentTime = timer.getLoopTimeMill().count();
        float oldTime = ai->getOldTime();
        float changeInTime = currentTime - oldTime;
   //     ai->update(currentTime, changeInTime);
        logMsg("CHANGE == " +convert->toString(changeInTime));

        if (changeInTime >= .5f)
        {
            logMsg("ELAPSED == " +convert->toString(changeInTime));
//          exit(0);
//          ai->update(aiTimer.getTotalSimulationTime (), aiTimer.getElapsedSimulationTime ());
            ai->update(currentTime, changeInTime);
            ai->setOldTime(currentTime);
        }
    }

    logMsg("Physics");
    physEngine.updateState();	// updates the state of the physics simulation
    logMsg("stepWorld");
    //    exit(0);
    physEngine.stepWorld();  // steps the physics simulation
/*    logMsg("DirectionsAndMovement");
    updateDirectionsAndMovements();
*/
//	exit(0);

    // updates the basketball(s) state
    logMsg("Updated basketball state!");
//    exit(0);
//    renderBall();
//    SceneNode *bball = basketballInstance[activeBBallInstance].getNode();
//    bball->setPosition(basketballInstance[activeBBallInstance].calculatePositionChange());
//    basketballInstance[activeBBallInstance].setNode(bball);

//    Ogre::Vector3 change = basketballInstance[activeBBallInstance].calculatePositionChange();
//    cout << "Calced Pos change = " << basketballInstance[activeBBallInstance].calculatePositionChange() << endl;
//    basketballInstance[activeBBallInstance].nodeChangePosition(basketballInstance[activeBBallInstance].calculatePositionChange());

//    std::vector<size_t> playerDirection = player->getPlayerDirection(); // stores contents of playerDirectdion from players class in local variable
//    std::vector<size_t> oldPlayerDirection = player->getOldPlayerDirection();   // stores contents of oldPlayerDirection form players in local variable

    // Initiates offense or defense for a team depending on value of teamWithBall
    if (teamWithBall == 0)	// if 0 puts team 0 on offense and team 1 on defense
    {
    	teamInstance[0].setOffense(true);
    	teamInstance[0].setDefense(false);

    	teamInstance[1].setOffense(false);
    	teamInstance[1].setDefense(true);
    }
    else if (teamWithBall == 1)  // if 1 puts team 1 on offense and team 0 on defense
    {
    	teamInstance[0].setOffense(false);
    	teamInstance[0].setDefense(true);

    	teamInstance[1].setOffense(true);
    	teamInstance[1].setDefense(false);
    }
    else
    {
    }

    // updates the state of each team
    if (teamInstancesCreated)
    {
        //FIXME crash in updateState code
    	teamInstance[0].updateState();
    	teamInstance[1].updateState();
//    	exit(0);
    }
    else
    {
    }
    }
//	logMsg("gameState logic updated");
//    exit(0);
    return true;
}

void gameState::processNetworkEvents()  // processes events from network code
{
    boost::shared_ptr<networkEngine> network = networkEngine::Instance();

//	std::vector <playerState> playerInstance = gameS->getPlayerInstance();

    if(Ogre::StringUtil::startsWith(network->getReceivedData(), "3" ))
    {
        logMsg("process!ng network player event");
        processNetworkPlayerEvents();
    }

//	std::vector<teamState> teamInstance = teamInstance();
    teamInstance[0].setPlayerType("human");  // sets playerType for teamInstance 0 to human

    // checks if this instance is a server and whether teamInstance 1 is set to be controlled by network player
    if (network->getServerReceivedConnection() && teamInstance[1].getPlayerType() != "network")
    {
        teamInstance[1].setPlayerType("network");  // sets teamInstance 1 playerType to 'network'
    }
    // checks if this instance is a client and whether teamInstance 0 is set to be controlled by network player
    else if (network->getClientEstablishedConnection() && teamInstance[0].getPlayerType() != "network" )
    {
        teamInstance[0].setPlayerType("network");
    }
}

void gameState::processNetworkPlayerEvents()  // processes player events from network code
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<networkEngine> network = networkEngine::Instance();

    networkPlayerStateObject netPStateObj;
    std::stringstream strStream;
    std::vector<playerState> activePlayerInstance;
    std::string receivedData = network->getReceivedData();  // stores receivedData value
    size_t playerNumber = -1;  // stores which player the data is for
    size_t iterator;  // iterator for match loop

    logMsg("received Data === " +receivedData);
    strStream << receivedData;
    strStream >> netPStateObj;
    logMsg("received teamID = " +convert->toString(netPStateObj.getTeamID()));
    logMsg("received playerID = " +convert->toString(netPStateObj.getPlayerID()));

    // sets which team's activePlayerInstance to use
    if (network->getIsClient())
    {
        logMsg("is client");
        activePlayerInstance = teamInstance[1].getActivePlayerInstance();
    }
    else if (network->getIsServer())
    {
        logMsg("is server");
        activePlayerInstance = teamInstance[0].getActivePlayerInstance();
    }
    else
    {
    }
    logMsg("activePlayerInstance size == " +convert->toString(activePlayerInstance.size()));
/*	for (iterator = 0; iterator < 5; ++iterator)
	{
		std::string searchString;	// stores search String
        std::string searchIterator = convert->toString(iterator); // converts iterator to a string
		searchString = "*" +searchIterator + "*";	// creates search string
		if (Ogre::StringUtil::match(receivedData,searchString))	// checks for a match
		{
			playerNumber = iterator;	// sets playerNumber to value of iterator
		}
	}
    logMsg("alive????");
*/
    playerNumber = netPStateObj.getPlayerID();
    if (activePlayerInstance.size() > 0)
    {
        if (netPStateObj.getMovement())
        {
            switch (netPStateObj.getDirection())
            {
                case 0:  // move player up
                    activePlayerInstance[playerNumber].setMovement(true);
                    activePlayerInstance[playerNumber].setDirection(UP);
                break;
                case 1:  // move player down
                    activePlayerInstance[playerNumber].setMovement(true);
                    activePlayerInstance[playerNumber].setDirection(DOWN);
                break;
                case 2:  // move player left
                    activePlayerInstance[playerNumber].setMovement(true);
                    activePlayerInstance[playerNumber].setDirection(LEFT);
                break;
                case 3:  // move player right
                    activePlayerInstance[playerNumber].setMovement(true);
                    activePlayerInstance[playerNumber].setDirection(RIGHT);
                break;
                case 4:  // move player up and left
                    activePlayerInstance[playerNumber].setMovement(true);
                    activePlayerInstance[playerNumber].setDirection(UPLEFT);
                break;
                case 5:  // move player up aned right
                    activePlayerInstance[playerNumber].setMovement(true);
                    activePlayerInstance[playerNumber].setDirection(UPRIGHT);
                break;
                case 6:  // move player down and left
                    activePlayerInstance[playerNumber].setMovement(true);
                    activePlayerInstance[playerNumber].setDirection(DOWNLEFT);
                break;
                case 7:  // move player down and right
                    activePlayerInstance[playerNumber].setMovement(true);
                    activePlayerInstance[playerNumber].setDirection(DOWNRIGHT);
                break;
                default:
                    activePlayerInstance[playerNumber].setMovement(false);
                break;
            }
            if (network->getIsClient())
            {
                teamInstance[1].setActivePlayerInstance(activePlayerInstance);
            }
            else if (network->getIsServer())
            {
                teamInstance[0].setActivePlayerInstance(activePlayerInstance);
            }
        }
        else if (netPStateObj.getShootBlock())
        {
        }
        else if (netPStateObj.getPassSteal())
        {
        }
        else
        {
        }
    }

    logMsg("Survived!");
    network->setReceivedData("");
}


void gameState::updateDirectionsAndMovements()
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    directions playerDirection, oldPlayerDirection;
//   logMsg("Updating Directions and Movements");

    if (teamWithBall >= 0) // && playerHasBasketball)
    {
//		logMsg("teamWithBall ios " +convert->toString(teamWithBall));
//		logMsg("playetWithBall is " +convert->toString(teamInstance[teamWithBall].getPlayerWithBall()));
//        updateBasketballMovements();	// updates the movement of basketball objec(s)
        //updateBasketballDirections(); // updates direction of basketball object(s)
    }
    else
    {
    }
}



