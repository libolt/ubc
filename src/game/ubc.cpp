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

#include "conversion.h"
#include "OgrePrerequisites.h"
#include "engine/gameengine.h"
#include "state/gamestate.h"
#include "logging.h"
#include "ubc.h"

#ifdef __ANDROID__
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
#include "android.h"
#include "SDL.h"
#include "SDL_main.h"
#endif


UBC::UBC()  // constructor
{
	quitGame = false;
}

UBC::~UBC()  // destructor
{

}

boost::shared_ptr<GUISystem> UBC::getGui()  // retrieves the value of gui
{
    return (gui);
}
void UBC::setGui(boost::shared_ptr<GUISystem> set)  // sets the value of gui
{
    gui = set;
}

bool UBC::getQuitGame()  // retrieves the value of quitGame
{
	return (quitGame);
}

void UBC::setQuitGame(bool set)  // sets the value of quitGame
{
    quitGame = set;
}


bool UBC::setupState()  // sets up the UBC game state
{
    Ogre::Viewport *vp = getRender()->getViewPort();
    gui->setViewPort(*vp);  // sets the viewPort for MyGUI

    gui->initMyGUI(getRender()); // Initializes MyGUI
    if (!gui->getMainMenuCreated())
    {
        gui->createMainMenuGUI(); // creates the main menu gui.
        gui->createBackButtons(); // creates the back buttons.
    }
    gui->setNetwork(getNetwork());
    return (false);
}

void UBC::executeState()  // executes the UBC game code
{
}

bool UBC::startGame()  // starts the game
{
    boost::shared_ptr<gameState> gameS = gameState::Instance();

    logMsg("startGame()");

    gameS->setupState();
    return true;
}

void UBC::gameLoop()  // Main Game Loop
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
//    boost::shared_ptr<GUISystem> gui = GUISystem::Instance();
//    boost::shared_ptr<inputSystem> input = inputSystem::Instance();
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    boost::shared_ptr<networkEngine> network = networkEngine::Instance();
    boost::shared_ptr<soundEngine> sound = soundEngine::Instance();

    networkPlayerStateObject netPStateObj;

    float lastFPS = 0.0f;   // stores value of last Frames Per Second
//    float changeInTime;       // stores change in time
//    int newTime;  // stores new time
//    unsigned long oldTime = 0;    // stores old time
    // Ogre::Timer loopTime;    // loop timer
//    startLoopTime = boost::chrono::system_clock::now();
    unsigned long changeInTime = 0;
    logMsg("Sound Test!");

    logMsg("main: startup");
//    exit(0);
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
//  workerThread = new boost::thread(boost::bind(&threading::workerFunc,&threads));
    
    boost::thread *workerThread2;
//  workerThread2 = new boost::thread(boost::bind(&threading::workerFunc2,&threads));

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

//  SDL_StartTextInput();
    while (!quitGame)
    {

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
        if (gameS->getGameSetupComplete())  // checks to make sure game setup is complete before continuing
        {
            if (!sceneCreated)
            {
                if (gameS->getGameType() == SINGLE)
                {
                    createScene = true;
                }
                else if (gameS->getGameType() == MULTI)
                {
                    if (network->getServerReceivedConnection() || network->getClientEstablishedConnection())  // checks if server and client are connected
                    {
                        createScene = true;
                    }
    //             exit(0);
                }
            }
        }
        if (createScene)  // checks if the scene should be created
        {
//              if (render->createScene())
//            {
                createScene = false;
                start = true;
//                  renderScene = true;
                sceneCreated = true;
//            }
        }

        if (start)  // checks if it's time to start the game
        {
            if (startGame())
            {
                start = false;
                renderScene = true;
            }
        }

        lastFPS = render->getMWindow()->getLastFPS();
        std::string currFPS = convert->toString(lastFPS);

        logMsg("FPS = " +currFPS);
        //updateChangeInTime(); // calculates the change in time.
//        exit(0);

//          logMsg("changeInTime = " +toString(changeInTime));
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
//              exit(0);
            if (serverRunning)
            {
                network->networkServer();   // Runs network server code
                
            }
            if (clientRunning)
            {
                network->networkClient();   // runs network client code
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
//                  Ogre::LogManager::getSingletonPtr()->logMessage("FPS = " +currFPS);

        processInput();
//          inputWorkerThread->join();
/*          else
            {
            }
*/
                //        player->getNode(0)->translate(Pos);
    //        pInstance[bballInstance[0].getPlayer()].getNode()->translate(-0.02f,0.0f,0.0f);

        if (render->getMWindow() != NULL && render->getMWindow()->isActive())
        {
//          Ogre::LogManager::getSingletonPtr()->logMessage("Rendering frame");
            render->getMWindow()->windowMovedOrResized();
//            exit(0);
            render->getMRoot()->renderOneFrame();
//            exit(0);

        }
    }

}


int main(int argc, char *argv[])
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    UBC ubc;
    boost::shared_ptr<renderEngine> render = ubc.getRender();
//    boost::shared_ptr<gameEngine> gameE = gameEngine::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<GUISystem> gui = ubc.getGui();

    render->initSDL(); // Initializes the SDL Subsystem

    render->initOgre(); // Initializes the Ogre Subsystem
    render->createScene(); // creates rendering scene.
//    exit(0);
    gameS->createInstances();  // creates object instances
//    exit(0);
    ubc.setupState();  // sets up the game state

/*    Ogre::Viewport *vp = render->getViewPort();
    gui->setViewPort(*vp);  // sets the viewPort for MyGUI
    
    gui->initMyGUI(render); // Initializes MyGUI
    if (!gui->getMainMenuCreated())
    {
        gui->createMainMenuGUI(); // creates the main menu gui.
        gui->createBackButtons(); // creates the back buttons.
    }
*/
//    exit(0);
    logMsg("Initializing Input");
    //inputSystem *input = inputSystem::Instance();
    boost::shared_ptr<inputSystem> input = ubc.getInput();
//    exit(0);
    ubc.gameLoop();

    atexit(SDL_Quit);

	return (0);
}

