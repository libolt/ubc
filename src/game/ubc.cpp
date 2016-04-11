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
#include "engine/inputengine.h"
#include "engine/renderengine.h"
#include "state/basketballstate.h"
#include "state/gamestate.h"
#include "state/networkstate.h"
#include "state/playerstate.h"
#include "state/teamstate.h"
#include "logging.h"
#include "ubc.h"
#include "network/networkplayerstateobject.h"

#ifdef __ANDROID__
//#if OGRE_PLATFORM == OGRE_PLATm.m...?mmmmFORM_ANDROID
#include "android.h"
#include "SDL.h"
#include "SDL_main.h"
#endif


UBC::UBC()  // constructor
{
//    quitGame = false;
/*    gameEngine *tempGameEObj = new gameEngine;
    boost::shared_ptr<gameEngine> tempGameESharedPtr = boost::shared_ptr<gameEngine>(tempGameEObj);
    setGameE(tempGameESharedPtr);
*/
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


/*bool UBC::getQuitGame()  // retrieves the value of quitGame
{
	return (quitGame);
}
 
void UBC::setQuitGame(bool set)  // sets the value of quitGame
{
    quitGame = set;
}*/

boost::shared_ptr<gameState> UBC::getGameS()  // retrieves the value of gameS
{
    return (gameS);
}
void UBC::setGameS(boost::shared_ptr<gameState> set)  // sets the value of gameS
{
    gameS = set;
}

bool UBC::setupState()  // sets up the UBC game state
{
//    Ogre::Viewport *vp = getRender()->getViewPort();
//    setViewPort(*vp);  // sets the viewPort for MyGUI
    logMsg("blah!");
//    exit(0);
    bool stateSetup = true;
    
    if (gui->initMyGUI()) // Initializes MyGUI
    {
        logMsg ("MyGUI initialized successfully!");
        logMsg("is the main menu created?");
        if (!gui->getMainMenuCreated())
        {
            logMsg("mainMenu not created yet!");
//           exit(0);
            if (gui->createMainMenuGUI()) // creates the main menu gui.
            {
                logMsg("Main Menu created successfully!");
            }
            else
            {
                logMsg("Unable to create Main Menu!");
                stateSetup = false;
            }
        }
        if (!gui->getBackButtonsCreated())
        {
            logMsg("Back buttons not created yet!");
            if (gui->createBackButtons()) // creates the back buttons.
            {
                logMsg("Back Buttons created successfully!");
            }
            else
            {
                logMsg("Unable to create Bsck Buttons!");
                stateSetup = false;
            }
        }
        gui->showMainMenuWidgets();
        getGameE()->setNetwork(getGameE()->getNetwork());
    } 
    else
    {

    }

    
    return (stateSetup);
}

void UBC::executeState()  // executes the UBC game code
{
}

void UBC::run()  // runs the game
{
    boost::shared_ptr<conversion> convert = conversion::Instance();

    
    getGameE()->getRender()->initSDL(); // Initializes the SDL Subsystem
//    exit(0);
    getGameE()->getRender()->initOgre(); // Initializes the Ogre Subsystem
//    exit(0);
    getGameE()->getRender()->createScene(); // creates rendering scene.

//    exit(0);
/*
    logMsg("pre setupState!");
    if (setupState())  // sets up the game state
    {
        logMsg("UBC state setup successfully!");
    }
    else
    {
        logMsg("Unable to setup UBC state!");
        return (false);
    }

    getGameS()->createInstances();  // creates object instances
*/
    if (getGameE()->getRender()->getMWindow() == NULL)
    {
        logMsg("mWindow == NULL!");
//        exit(0);
    }
//    exit(0);
//    setupState();  // sets up the game state

    Ogre::Viewport *vp = getGameE()->getRender()->getViewPort();
//    setViewPort(*vp);  // sets the viewPort for MyGUI

//    exit(0);
    logMsg("Initializing Input");
    //inputSystem *input = inputSystem::Instance();
//    boost::shared_ptr<inputSystem> input = getInput();
//    exit(0);
    
/*    int x = 0;
    while (x < 1)
    {
        
    }
*/
//    bool quitGame = getGameE()->getQuitGame();
 
    gameLoop();
}

bool UBC::startGame()  // starts the game
{
//    boost::shared_ptr<gameState> gameS = gameState::Instance();

    logMsg("startGame()");

    gameS->setupState();
    return true;
}

void UBC::processInput()  // processes game input
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
//    boost::shared_ptr<GUISystem> gui = GUISystem::Instance();
//    boost::shared_ptr<inputSystem> input = inputSystem::Instance();
//    boost::shared_ptr<networkEngine> network = networkEngine::Instance();
    std::vector<boost::shared_ptr<teamState> > activeTeamInstance = gameS->getActiveTeamInstance();
    networkPlayerStateObject netPStateObj;

    logMsg("inputProcess!");
 
    if (getGameE()->getInput()->processInput())
    {
//        exit(0);
        if (getGameE()->getMenuActive())
        {
            logMsg("menuActive!");
//            exit(0);
        }

        if (getGameE()->getInput()->getKeyInputReceived())
        {
            exit(0);
            if (getGameE()->getMenuActive())
            {
                logMsg("menuReceiveKeyPress == " +getGameE()->getInput()->getKeyPressed());
                gui->menuReceiveKeyPress(getGameE()->getInput()->getKeyPressed()); // sends input to menu key input processing function
                if (getGameE()->getInput()->getKeyPressed() == "t")
                {
     //               exit(0);
                }
                getGameE()->getInput()->setKeyPressed("");
            }
        }
        if (gameS->getActiveTeamInstancesCreated())
        {
//            exit(0);
            size_t inputIterator = 0;
            while (inputIterator < activeTeamInstance.size())
            {
                if (activeTeamInstance[inputIterator]->getPlayerInstancesCreated())
                {
                    std::vector<boost::shared_ptr<playerState> > activePlayerInstance = activeTeamInstance[inputIterator]->getActivePlayerInstance();
                    if (activeTeamInstance[inputIterator]->getHumanControlled())
                    {
                        int humanPlayer = activeTeamInstance[inputIterator]->getHumanPlayer();
                        logMsg("inputHumanPlayer == " +convert->toString(humanPlayer));
                        //inputMaps inputMap = input->keyMap();
                        inputWorkQueues inputQueue = getGameE()->getInput()->getInputWorkQueue();
        //                              logMsg("INPUT MAP ======== "  +toString(inputMap));
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
                        logMsg("inputQueue.size = " +convert->toString(inputQueue.size()));
                        x = 0;
                        int activeBBallInstance = gameS->getActiveBBallInstance();
                        std::vector<basketballState> bballInstance = gameS->getBasketballInstance();
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
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(UP);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        gameS->setActiveTeamInstance(activeTeamInstance);
//                                        exit(0);
                                    break;
                                    case INDOWN:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(DOWN);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        gameS->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INLEFT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(LEFT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        gameS->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INRIGHT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(RIGHT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        gameS->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INUPLEFT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(UPLEFT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        gameS->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INUPRIGHT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(UPRIGHT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        gameS->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INDOWNLEFT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(DOWNLEFT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        gameS->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INDOWNRIGHT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(DOWNRIGHT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        gameS->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INSHOOTBLOCK:
                                        activePlayerInstance[humanInstance]->setMovement(false);
                                        activePlayerInstance[humanInstance]->setShootBlock(true);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        gameS->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INPASSSTEAL:
                                        activePlayerInstance[humanInstance]->setMovement(false);
                                        activePlayerInstance[humanInstance]->setPassSteal(true);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        gameS->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INQUIT:
                                        logMsg("Quitting!");
                                        getGameE()->setQuitGame(true);
                                        exit(0);
                                    break;
                                    default:
                                    break;
                                }
                                ++x;
                            }
                        }
                        std::vector<boost::shared_ptr<teamState> > tInstance = gameS->getActiveTeamInstance();
                        std::vector<boost::shared_ptr<playerState> > activePInstance = tInstance[inputIterator]->getActivePlayerInstance();
                        logMsg("humanInstance == " +convert->toString(humanInstance));
                        //logMsg("inPassSteal == " +convert->toString(activePInstance[humanInstance]->getPassSteal()));
                        //exit(0);

                        /// FIXME! This if statement should be adapted to work correctly instead of relying on the i variable
                        int i = 0;
                        if (gameS->getTeamWithBall() == i)
                        {
                            if (activePlayerInstance[humanInstance]->getMovement())
                            {
                                logMsg("human playerID == " +convert->toString(activePlayerInstance[humanInstance]->getID()));
                                logMsg("ball player == " +convert->toString(activeTeamInstance[inputIterator]->getPlayerWithBallInstance()));
                                logMsg("ball playerID == " +convert->toString(activeTeamInstance[inputIterator]->getPlayerWithBallID()));
                                if (activePlayerInstance[humanInstance]->getID() == activeTeamInstance[inputIterator]->getPlayerWithBallID())
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
                        gameS->setActiveTeamInstance(activeTeamInstance);

                        if (gameS->getGameType() == MULTI)
                        {
                            networkS->processLocalInput(gameS->getActiveTeamInstance());
                        }
                        inputQueue.clear();
                        getGameE()->getInput()->setInputWorkQueue(inputQueue);
                    }
                    ++inputIterator;
                }
            }
        }

    }   
//    exit(0);
    
}
void UBC::gameLoop()  // Main Game Loop
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
/*    boost::shared_ptr<gameState> gameS = gameState::Instance();
//    boost::shared_ptr<GUISystem> gui = GUISystem::Instance();
//    boost::shared_ptr<inputSystem> input = inputSystem::Instance();
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    boost::shared_ptr<networkEngine> network = networkEngine::Instance();
//    boost::shared_ptr<soundEngine> sound = soundEngine::Instance();

//    networkPlayerStateObject netPStateObj;

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
*/

    unsigned long changeInTime = 0;

//    render->createScene(); // creates rendering scene.

    int x = 0;
   
//    getGameE()->gameEngine();
    bool quitGame = getGameE()->getQuitGame();
//    exit(0);
//    while (!getQuitGame())
    while (x < 1)
    {

///        if (!sound->getSetupComplete())
///        {
///            logMsg("Sound setup not complete!");
///            if (sound->setup())
///            {
///                logMsg("Sound setup!");
///                sound->setSetupComplete(true);
///            }
///        }
///        else
///        {
///            logMsg("Loading Sound!");
///            sound->loadSound("cbeep.wav");
///        }

        if (gameS->getGameSetupComplete())  // checks to make sure game setup is complete before continuing
        {
            if (!getGameE()->getSceneCreated())
            {
                if (gameS->getGameType() == SINGLE)
                {
                    getGameE()->setCreateScene(true);
                }
                else if (gameS->getGameType() == MULTI)
                {
                    if (getGameE()->getNetwork()->getServerReceivedConnection() || getGameE()->getNetwork()->getClientEstablishedConnection())  // checks if server and client are connected
                    {
                        getGameE()->setCreateScene(true);
                    }
    //             exit(0);
                }
            }
        }
        
        if (getGameE()->getCreateScene())  // checks if the scene should be created
        {
//            exit(0);
//              if (render->createScene())
//            {
                getGameE()->setCreateScene(false);
                getGameE()->setStart(true);
//                  renderScene = true;
                getGameE()->setSceneCreated(true);
//            }
        }
//        exit(0);
        if (getGameE()->getStart())  // checks if it's time to start the game
        {
//            exit(0);
            if (startGame())
            {
                getGameE()->setStart(false);
                getGameE()->setRenderScene(true);
            }
        }
//        exit(0);
//        lastFPS = getRender()->getMWindow()->getLastFPS();
//        exit(0);
//        std::string currFPS = convert->toString(lastFPS);

//        logMsg("FPS = " +currFPS);
        //updateChangeInTime(); // calculates the change in time.
        

//          logMsg("changeInTime = " +toString(changeInTime));
        // updates game logic every 100 milliseconds
        if (getGameE()->getServerRunning() && !getGameE()->getNetwork()->getIsServer())
        {
            getGameE()->getNetwork()->setIsServer(true);
        }
        if (getGameE()->getClientRunning() && !getGameE()->getNetwork()->getIsClient())
        {
            getGameE()->getNetwork()->setIsClient(true);
        }

        if (gameS->getGameType() == MULTI && getGameE()->getNetwork()->getTeamType() == NOTEAM)
        {
            if (getGameE()->getNetwork()->getIsServer())
            {
                getGameE()->getNetwork()->setTeamType(HOMETEAM);
            }
            
            if (getGameE()->getNetwork()->getIsClient())
            {
                getGameE()->getNetwork()->setTeamType(AWAYTEAM);
            }
        }
        
        logMsg("serverRunning = " +getGameE()->getServerRunning());
        logMsg("clientRunning = " +getGameE()->getClientRunning());
        boost::chrono::microseconds changeInTimeMicro = getGameE()->getTimer().calcChangeInTimeMicro();
        
        boost::chrono::milliseconds changeInTimeMill = getGameE()->getTimer().calcChangeInTimeMill();
        changeInTime = getGameE()->getTimer().getChangeInTimeMill().count();
        logMsg ("loopchange = " +convert->toString(changeInTime));
//        exit(0);
        if (changeInTime >= 10)
        {
//              exit(0);
            if (getGameE()->getServerRunning())
            {
                getGameE()->getNetwork()->networkServer();   // Runs network server code
                
            }
            if (getGameE()->getClientRunning())
            {
                getGameE()->getNetwork()->networkClient();   // runs network client code
            }


//            logMsg("changeInTime = " +toString(changeInTime));
            if (getGameE()->getRenderScene())
            {
                logMsg("gameS->updateState()");
                gameS->updateState();  // updates the state of the game instance
            }
            
            //boost::chrono::system_clock::time_point newT = boost::chrono::system_clock::now();
            //boost::chrono::milliseconds milliSecs = boost::chrono::duration_cast<boost::chrono::milliseconds>(newT);
            //oldTime = milliSecs.count();
            getGameE()->getTimer().setPreviousTime(boost::chrono::system_clock::now());
        }

        processInput();

        if (!getGameE()->getRender()->renderFrame())
        {
            logMsg("Unable to render frame!");
            exit(0);
        }
    }

}


int main(int argc, char *argv[])
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<UBC> ubc;
    
//    boost::shared_ptr<renderEngine> render = ubc.getRender();
//    boost::shared_ptr<gameEngine> gameE = gameEngine::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
//    boost::shared_ptr<GUISystem> gui = ubc.getGui();

    ubc->run();
    logMsg("End Game!");
//    atexit(SDL_Quit);

	return (0);
}

