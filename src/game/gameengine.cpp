/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean   *
 *   libolt@libolt.net   *
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


#include "gameengine.h"
#include "conversion.h"
#include "gamestate.h"
#include "gui.h"
#include "input.h"
#include "logging.h"
#include "network.h"
#include "networkplayerstateobject.h"
#include "renderengine.h"
#include "soundengine.h"


//gameEngine* gameEngine::pInstance = 0;
boost::shared_ptr<gameEngine> gameEngine::pInstance;

//gameEngine* gameEngine::Instance()
boost::shared_ptr<gameEngine> gameEngine::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        //pInstance = new AISystem; // create sole instance
        boost::shared_ptr<gameEngine> tInstance(new gameEngine);
        pInstance = tInstance;
        //return tInstance; // address of sole instance
    }
    return pInstance; // returns the value of pInstance
}


//-------------------------------------------------------------------------------------
gameEngine::gameEngine()
//    : player[0](0),
 // playerNode[0](0)
{
    x = 0;
    y = 0;
    i = 0;
    j = 0;
  
    yOffset = 0.0;

    userInputLoaded = false;
    menuActive = false;
    start = false;
    quitGame = false;
    serverRunning = false;
    clientRunning = false;
    sceneCreated = false;
    createScene = false;
    renderScene = false;
    movePlayer = false;
}
//-------------------------------------------------------------------------------------
gameEngine::~gameEngine()
{
}

timing gameEngine::getTimer()  // retrieves the value of timer
{
    return (timer);
}
void gameEngine::setTimer(timing set)  // sets the value of timer
{
    timer = set;
}

bool gameEngine::getMenuActive()   // retrieves the value of menuActive
{
    return(menuActive);
}
void gameEngine::setMenuActive(bool set)  // sets the value of menuActive
{
    menuActive = set;
}

bool gameEngine::getQuitGame()  // retrieves the value of quitGame
{
    return(quitGame);
}
void gameEngine::setQuitGame(bool set)  // sets the value of quitGame
{
    quitGame = set;
}

bool gameEngine::getServerRunning()  // retrieves the value of serverRunning
{
	return (serverRunning);
}
void gameEngine::setServerRunning(bool set)  // sets the value of serverRunning
{
	serverRunning = set;
}

bool gameEngine::getClientRunning()  // retrieves the value of clientRunning
{
	return (clientRunning);
}
void gameEngine::setClientRunning(bool set)  // sets the value of clientRunning
{
	clientRunning = set;
}

bool gameEngine::getCreateScene()  // retrieves the value of createScene
{
	return (createScene);
}
void gameEngine::setCreateScene(bool set)  // sets the value of createScene
{
	createScene = set;
}

bool gameEngine::getSceneCreated()  // retrieves the value of sceneCreated
{
	return (sceneCreated);
}
void gameEngine::setSceneCreated(bool set)  // sets the value of sceneCreated
{
	sceneCreated = set;
}

bool gameEngine::getRenderScene()  // retrieves the value of renderScene
{
	return (renderScene);
}
void gameEngine::setRenderScene(bool set)  // sets the value of renderScene
{
	renderScene = set;
}

bool gameEngine::getMovePlayer()  // retrieves the value of moviePlayer
{
	return (movePlayer);
}
void gameEngine::setMovePlayer(bool set)  // sets the value of moviePlayer
{
	movePlayer = set;
}

float gameEngine::getYOffset() // returns the value of yOffset
{
    return (yOffset);
}
void gameEngine::setYOffset(float set) // sets the value of yOffset
{
    yOffset = set;
}

bool gameEngine::startGame()
{
//    gameState *gameS = gameState::Instance();
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//    Ogre::LogManager::getSingletonPtr()->logMessage("startGame()");
	logMsg("startGame()");

    gameS->setupState();
//#endif
    return true;
}

void gameEngine::quit()
{
    //inputSystem *input = inputSystem::Instance();
    boost::shared_ptr<inputSystem> input = inputSystem::Instance();

    input->destroy();

}

void gameEngine::processInput()  // processes game input
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    //GUISystem *gui = GUISystem::Instance();
    boost::shared_ptr<GUISystem> gui = GUISystem::Instance();
    //inputSystem *input = inputSystem::Instance();
    boost::shared_ptr<inputSystem> input = inputSystem::Instance();
    //networkEngine *network = networkEngine::Instance();
    boost::shared_ptr<networkEngine> network = networkEngine::Instance();

    std::vector<teamState> teamInstance = gameS->getTeamInstance();
    networkPlayerStateObject netPStateObj;

    logMsg("inputProcess!");
 
    if (input->processInput())
    {
        if (gameS->getTeamInstancesCreated())
        {
            size_t inputIterator = 0;
            while (inputIterator < teamInstance.size())
            {
                if (teamInstance[inputIterator].getPlayerInstancesCreated())
                {
                    std::vector<playerState> activePlayerInstance = teamInstance[inputIterator].getActivePlayerInstance();
                    if (teamInstance[inputIterator].getHumanControlled())
                    {
                        int humanPlayer = teamInstance[inputIterator].getHumanPlayer();
                        logMsg("inputHumanPlayer == " +convert->toString(humanPlayer));
                        //inputMaps inputMap = input->keyMap();
                        inputWorkQueues inputQueue = input->getInputWorkQueue();
        //                              logMsg("INPUT MAP ======== "  +toString(inputMap));
                        std::stringstream ss;
                                  //  exit(0);
                        size_t x = 0;
                        size_t humanInstance = 11;
                        while (x < activePlayerInstance.size())
                        {
                            logMsg("GEPlayerID == " +convert->toString(activePlayerInstance[x].getPlayerID()));
                            logMsg("GEHumanPlayer == " +convert->toString(humanPlayer));
                            if (activePlayerInstance[x].getPlayerID() == humanPlayer)
                            {
                                humanInstance = x;
                                break;
                            }
                            ++x;
                        }
                        logMsg("humanInstance == " +convert->toString(humanInstance));
                        logMsg("inputHumanPlayer == " +convert->toString(humanPlayer));
                        logMsg("inputQueue.size = " +convert->toString(inputQueue.size()));
                        x = 0;
                        int activeBBallInstance = gameS->getActiveBBallInstance();
                        std::vector<basketballs> bballInstance = gameS->getBasketballInstance();
                        logMsg("humanInstance.size() == " +convert->toString(humanInstance));
                        if (humanInstance < 11) // makes sure that the humanInstance is a valid number
                        {
                            while (x < inputQueue.size())
                            {
                                logMsg("inputQueue[" +convert->toString(x) +"] = " +convert->toString(inputQueue[x]));
                                // switch (inputMap)
                                switch (inputQueue[x])
                                {
                                    case INUP:
                                        activePlayerInstance[humanInstance].setMovement(true);
                                        activePlayerInstance[humanInstance].setDirection(UP);
                                        teamInstance[inputIterator].setActivePlayerInstance(activePlayerInstance);
                                        gameS->setTeamInstance(teamInstance);
//                                        exit(0);

                                    break;
                                    case INDOWN:
                                        activePlayerInstance[humanInstance].setMovement(true);
                                        activePlayerInstance[humanInstance].setDirection(DOWN);
                                        teamInstance[inputIterator].setActivePlayerInstance(activePlayerInstance);
                                        gameS->setTeamInstance(teamInstance);
                                    break;
                                    case INLEFT:
                                        activePlayerInstance[humanInstance].setMovement(true);
                                        activePlayerInstance[humanInstance].setDirection(LEFT);
                                        teamInstance[inputIterator].setActivePlayerInstance(activePlayerInstance);
                                        gameS->setTeamInstance(teamInstance);
                                    break;
                                    case INRIGHT:
                                        activePlayerInstance[humanInstance].setMovement(true);
                                        activePlayerInstance[humanInstance].setDirection(RIGHT);
                                        teamInstance[inputIterator].setActivePlayerInstance(activePlayerInstance);
                                        gameS->setTeamInstance(teamInstance);
                                    break;
                                    case INUPLEFT:
                                        activePlayerInstance[humanInstance].setMovement(true);
                                        activePlayerInstance[humanInstance].setDirection(UPLEFT);
                                        teamInstance[inputIterator].setActivePlayerInstance(activePlayerInstance);
                                        gameS->setTeamInstance(teamInstance);
                                    break;
                                    case INUPRIGHT:
                                        activePlayerInstance[humanInstance].setMovement(true);
                                        activePlayerInstance[humanInstance].setDirection(UPRIGHT);
                                        teamInstance[inputIterator].setActivePlayerInstance(activePlayerInstance);
                                        gameS->setTeamInstance(teamInstance);
                                    break;
                                    case INDOWNLEFT:
                                        activePlayerInstance[humanInstance].setMovement(true);
                                        activePlayerInstance[humanInstance].setDirection(DOWNLEFT);
                                        teamInstance[inputIterator].setActivePlayerInstance(activePlayerInstance);
                                        gameS->setTeamInstance(teamInstance);
                                    break;
                                    case INDOWNRIGHT:
                                        activePlayerInstance[humanInstance].setMovement(true);
                                        activePlayerInstance[humanInstance].setDirection(DOWNRIGHT);
                                        teamInstance[inputIterator].setActivePlayerInstance(activePlayerInstance);
                                        gameS->setTeamInstance(teamInstance);
                                    break;
                                    case INSHOOTBLOCK:
                                        activePlayerInstance[humanInstance].setMovement(false);
                                        activePlayerInstance[humanInstance].setShootBlock(true);
                                        teamInstance[inputIterator].setActivePlayerInstance(activePlayerInstance);
                                        gameS->setTeamInstance(teamInstance);
                                    break;
                                    case INPASSSTEAL:
                                        activePlayerInstance[humanInstance].setMovement(false);
                                        activePlayerInstance[humanInstance].setPassSteal(true);
                                        teamInstance[inputIterator].setActivePlayerInstance(activePlayerInstance);
                                        gameS->setTeamInstance(teamInstance);
                                    break;
                                    case INQUIT:
                                        logMsg("Quitting!");
                                        quitGame = true;
                                        exit(0);
                                    break;
                                    default:
                                    break;
                                }

                                ++x;
                            }
                        }
                        std::vector<teamState> tInstance = gameS->getTeamInstance();
                        std::vector<playerState> activePInstance = tInstance[inputIterator].getActivePlayerInstance();
                        logMsg("humanInstance == " +convert->toString(humanInstance));
                        //logMsg("inPassSteal == " +convert->toString(activePInstance[humanInstance].getPassSteal()));
                        //exit(0);
                        if (gameS->getTeamWithBall() == i)
                        {
                            if (activePlayerInstance[humanInstance].getMovement())
                            {
                                logMsg("human playerID == " +convert->toString(activePlayerInstance[humanInstance].getPlayerID()));
                                logMsg("ball player == " +convert->toString(teamInstance[inputIterator].getPlayerWithBallInstance()));
                                logMsg("ball playerID == " +convert->toString(teamInstance[inputIterator].getPlayerWithBallID()));
                                if (activePlayerInstance[humanInstance].getPlayerID() == teamInstance[inputIterator].getPlayerWithBallID())
                                {
                                    bballInstance[activeBBallInstance].setMovement(true);
                                    gameS->setBasketballInstance(bballInstance);
                                }
                            }
                        }
                        if (gameS->getBasketballInstance().size() > 0)
                        {
                            logMsg("basketballmoved == " +convert->toString(bballInstance[activeBBallInstance].getMovement()));
                        }
                        gameS->setTeamInstance(teamInstance);

                        if (gameS->getGameType() == MULTI)
                        {
                            network->processLocalInput();
                        }
                        inputQueue.clear();
                        input->setInputWorkQueue(inputQueue);
                    }
                    ++inputIterator;
                }
            }
        }
    }   
}

void gameEngine::gameLoop()	// Main Game Loop
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<GUISystem> gui = GUISystem::Instance();
    boost::shared_ptr<inputSystem> input = inputSystem::Instance();
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
    boost::shared_ptr<networkEngine> network = networkEngine::Instance();
    boost::shared_ptr<soundEngine> sound = soundEngine::Instance();


    networkPlayerStateObject netPStateObj;


    float lastFPS = 0.0f;	// stores value of last Frames Per Second
//    float changeInTime;		// stores change in time
//    int newTime;	// stores new time
//    unsigned long oldTime = 0;	// stores old time
    // Ogre::Timer loopTime;	// loop timer
//    startLoopTime = boost::chrono::system_clock::now();
    unsigned long changeInTime = 0;
    logMsg("Sound Test!");

	logMsg("main: startup");

/*
    threads thread;
    thread.setGRunning(true);

    boost::thread t1(boost::bind(&threads::producerThread,&thread));
    boost::thread t2(boost::bind(&threads::consumerThread,&thread));

    // Let them run for a while

    boost::posix_time::milliseconds workTime(5000);
    boost::this_thread::sleep(workTime);

    // Stop gracefully and wait

    thread.setGRunning(false);
    t1.join();
    t2.join();
*/
//    boost::thread inputThread(boost::bind(&inputSystem::processInput,input));
//    boost::thread t2(boost::bind(&threads::consumerThread,&thread));

    /*    boost::thread *workerThread;
//	workerThread = new boost::thread(boost::bind(&threading::workerFunc,&threads));
    
	boost::thread *workerThread2;
//	workerThread2 = new boost::thread(boost::bind(&threading::workerFunc2,&threads));

    boost::thread *inputWorkerThread;
//    inputWorkerThread = new boost::thread(boost::bind(&threading::inputWorkerFunc,&threads));

    logMsg("main: waiting for thread");

    workerThread->join();
	workerThread2->join();

    logMsg("main: done");
*/

//    threads *thread = threads::Instance();

/*    threads::Reader reads(100);
    threads::Writer writes1(100, 200);
    threads::Writer writes2(200, 200);

    boost::thread readerThread(reads);
    boost::thread writerThread1(writes1);
//    usleep(100);
    boost::this_thread::sleep(boost::posix_time::microseconds(100));

    boost::thread writerThread2(writes2);

    readerThread.join();
    writerThread1.join();
    writerThread2.join();
*/

//	SDL_StartTextInput();
    while (!quitGame)
	{
			//SDL_SetWindowGrab(render->getSDLWindow(), SDL_TRUE);
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//			std::vector<playerState> activePlayerInstance = gameS->getPlayerInstance();	// stores th player instances

	//        ubc->processUnbufferedKeyInput();

	//        render->frameStarted();
			// run the message pump (Eihort)
	//		Ogre::WindowEventUtilities::messagePump();
//		   exit(0);

/*        if (!sound->getSetupComplete())
        {
            logMsg("Sound setup not complete!");
            if (sound->setup())
            {
                logMsg("Sound setup!");
                sound->setSetupComplete(true);
            }
        }
        else
        {
            logMsg("Loading Sound!");
            sound->loadSound("cbeep.wav");
        }
*/
        if (gameS->getGameSetupComplete())   // checks to make sure game setup is complete before continuing
	    {
            if (!sceneCreated)
            {
                if (gameS->getGameType() == SINGLE)
                {
                    createScene = true;
                }
                else if (gameS->getGameType() == MULTI)
                {
                    if (network->getServerReceivedConnection() || network->getClientEstablishedConnection())    // checks if server and client are connected
                    {
                        createScene = true;
                    }
    //			   exit(0);
                }
            }
        }
        
        if (createScene)	// checks if the scene should be created
        {
//	    		if (render->createScene())
            {
                createScene = false;
                start = true;
//	    			renderScene = true;
                sceneCreated = true;
            }
        }

        if (start)	// checks if it's time to start the game
        {
            if (startGame())
            {
                start = false;
                renderScene = true;
            }
        }
//#else
        lastFPS = render->getMWindow()->getLastFPS();
        std::string currFPS = convert->toString(lastFPS);

        logMsg("FPS = " +currFPS);
        //updateChangeInTime();	// calculates the change in time.

//	        logMsg("changeInTime = " +toString(changeInTime));
        // updates game logic every 100 milliseconds
        if (serverRunning && !network->getIsServer())
        {
            network->setIsServer(true);
        }
        if (clientRunning && !network->getIsClient())
        {
            network->setIsClient(true);
        }

        if (gameS->getGameType() == MULTI && network->getTeamType() == NOTEAM)
        {
            if (network->getIsServer())
            {
                network->setTeamType(HOMETEAM);
            }
            
            if (network->getIsClient())
            {
                network->setTeamType(AWAYTEAM);
            }
        }
        
        logMsg("serverRunning = " +serverRunning);
        logMsg("clientRunning = " +clientRunning);
        
        boost::chrono::microseconds changeInTimeMicro = timer.calcChangeInTimeMicro();
        boost::chrono::milliseconds changeInTimeMill = timer.calcChangeInTimeMill();
        changeInTime = changeInTimeMill.count();
        logMsg ("loopchange = " +convert->toString(changeInTime));
        if (changeInTime >= 10)
        {
//	        	exit(0);
            if (serverRunning)
            {
                network->networkServer();	// Runs network server code
                
            }
            if (clientRunning)
            {
                network->networkClient();	// runs network client code
            }


//            logMsg("changeInTime = " +toString(changeInTime));
            if (renderScene)
            {
                logMsg("gameS->updateState()");
                gameS->updateState();  // updates the state of the game instance
            }
            
            //boost::chrono::system_clock::time_point newT = boost::chrono::system_clock::now();
            //boost::chrono::milliseconds milliSecs = boost::chrono::duration_cast<boost::chrono::milliseconds>(newT);
            //oldTime = milliSecs.count();
            timer.setPreviousTime(boost::chrono::system_clock::now());

        }
    

	        // writes Framerate to Ogre.log
//	                Ogre::LogManager::getSingletonPtr()->logMessage("FPS = " +currFPS);

        processInput();
//          inputWorkerThread->join();
/*	    	else
	    	{
	    	}
*/
	 			//        player->getNode(0)->translate(Pos);
	//        pInstance[bballInstance[0].getPlayer()].getNode()->translate(-0.02f,0.0f,0.0f);

        if (render->getMWindow() != NULL && render->getMWindow()->isActive())
        {
//			Ogre::LogManager::getSingletonPtr()->logMessage("Rendering frame");
            render->getMWindow()->windowMovedOrResized();
            render->getMRoot()->renderOneFrame();
        }
//		#endif
    }

}
