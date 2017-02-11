/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean   *
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
#include "engine/physicsengine.h"
#include "state/basketballstate.h"
#include "state/gamestate.h"
#include "state/inputstate.h"
#include "state/networkstate.h"
#include "state/playerstate.h"
#include "state/teamstate.h"
#include "logging.h"
#include "ubc.h"
#include "ubcbase.h"
#include "network/networkplayerstateobject.h"

#ifdef __ANDROID__
//#if OGRE_PLATFORM == OGRE_PLATm.m...?mmmmFORM_ANDROID
#include "android.h"
#include "SDL.h"
#include "SDL_main.h"
#endif

// static declarations 
UBCBaseSharedPtr UBC::base;  // static copy of base class

sharedPtr<GUISystem> UBC::gui;  // the GUI object.

UBC::UBC()  // constructor
{
//    quitGame = false;

}

UBC::~UBC()  // destructor
{

}

UBCBaseSharedPtr UBC::getBase()  // retrieves the value of base
{
    return (base);
}
void UBC::setBase(UBCBaseSharedPtr set)  // sets the value of base
{
    base = set;
}

sharedPtr<GUISystem> UBC::getGui()  // retrieves the value of gui
{
    return (gui);
}
void UBC::setGui(sharedPtr<GUISystem> set)  // sets the value of gui
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

bool UBC::setup()  // sets up UBC object
{
    /*    gameEngine *tempGameEObj = new gameEngine;
        sharedPtr<gameEngine> tempGameESharedPtr = sharedPtr<gameEngine>(tempGameEObj);
        setGameE(tempGameESharedPtr);
    */
//    exit(0);
    UBCBaseSharedPtr tempBaseSharedPtr(new UBCBase);
    base = tempBaseSharedPtr;
    std::string func = "UBC::setup()";

    logMsg(func +" beginning");

    if (!base->getStateSetup())
    {
        if (base->setup())
        {
//            base->getGameS()->setInitialized(true);

            GUISystemSharedPtr tempGUISharedPtr(new GUISystem);
            gui = tempGUISharedPtr;
            gui->setBase(base);
            base->getGameS()->setBase(base);
            base->getInputS()->setBase(base);
//            base->setStateSetup(true);

        }
        else
        {
            logMsg(func +" Unable to setup base!");
            exit(0);
        }
    }
    else
    {
//    exit(0);
    //    GUISystem *tempGUIObj = new GUISystem;
        GUISystemSharedPtr tempGUISharedPtr(new GUISystem);
        gui = tempGUISharedPtr;
        gui->setBase(base);
        base->getGameS()->setBase(base);
        base->setStateSetup(true);

    }

    logMsg(func +" end");
    
//        exit(0);
//        gui->getBase()->setGameS(base->getGameS());
//        exit(0);
}

bool UBC::setupState()  // sets up the UBC game state
{
//    Ogre::Viewport *vp = getRenderE()->getViewPort();
//    setViewPort(*vp);  // sets the viewPort for MyGUI
//    exit(0);
    bool stateSetup = true;
    std::string func = "UBC::setupState()";

    logMsg(func +" beginning");

    if (gui->setup())  // sets up the game GUI
    {
    
//        exit(0);
        gui->setSetupComplete(true);
//        exit(0);
        gui->mainMenu();
//        exit(0);
        gui->backButtons();
    }
    else
    {
        logMsg(func +" Unable to setup GUI!");
        exit(0);
    }
//    exit(0); 
    
    logMsg(func +" end");

    return (stateSetup);
}

void UBC::executeState()  // executes the UBC game code
{
}

void UBC::run()  // runs the game
{
    sharedPtr<conversion> convert = conversion::Instance();
//    exit(0);
//    sharedPtr<renderEngine> renderTemp = base->getGameE()->getRenderE();
//    exit(0);
    std::string func = "UBC::run()";

    logMsg(func +" beginning");

//    exit(0);
    base->setup();
    base->getGameE()->getRenderE()->initSDL(); // Initializes the SDL Subsystem
//    exit(0);
    base->getGameE()->getRenderE()->initOgre(); // Initializes the Ogre Subsystem
//    exit(0);
    base->getGameE()->getRenderE()->createScene(); // creates rendering scene.

//    sharedPtr<entity> gameStateSharedPtr(new entity);

//    exit(0);

    logMsg(func +" pre setupState!");
    if (setupState())  // sets up the game state
    {
        logMsg(func +" UBC state setup successfully!");
    }
    else
    {
        logMsg(func +" Unable to setup UBC state!");
//        return (false);
    }
//    exit(0);
//    base->getGameS()->createInstances();  // creates object instances
//    sharedPtr<entity> gameStateSharedPtr(new entity);

    if (base->getGameE()->getRenderE()->getMWindow() == NULL)
    {
        logMsg(func +" mWindow == NULL!");
//        exit(0);
    }
//    exit(0);
//    setupState();  // sets up the game state

    sharedPtr<Ogre::Viewport> vp = base->getGameE()->getRenderE()->getViewPort();
//    setViewPort(*vp);  // sets the viewPort for MyGUI

//    exit(0);
    logMsg(func +" Initializing Input");
    //inputSystem *input = inputSystem::Instance();
//    sharedPtr<inputSystem> input = getInputE();
//    exit(0);

//    bool quitGame = base->getGameE()->getQuitGame();
       
    gameLoop();

    logMsg(func +" end");

}

bool UBC::startGame()  // starts the game
{
//    sharedPtr<gameState> gameS = gameState::Instance();
    std::string func = "UBC::startGame()";

    logMsg(func +" beginning");

    base->getGameS()->setBase(base);
    base->getGameS()->setupState();
    
    logMsg(func +" end");

    return (true);
}

void UBC::processInput()  // processes game input
{
    sharedPtr<conversion> convert = conversion::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
//    sharedPtr<GUISystem> gui = GUISystem::Instance();
//    sharedPtr<inputSystem> input = inputSystem::Instance();
//    networkEngineSharedPtr network = networkEngine::Instance();
    teamStateUMSharedPtr activeTeamInstance = base->getGameS()->getActiveTeamInstance();
    networkPlayerStateObject netPStateObj;
    std::string func = "UBC::processInput()";

    logMsg(func +" beginning");
    
//    exit(0);
    
    if (base->getInputS()->process())
    {
        if (base->getGameE()->getMenuActive())
        {
            gui->menuReceiveKeyPress(convert->toString(base->getGameE()->getInputE()->getKeyPressed())); // sends input to menu key input processing function
        }
        else
        {
            base->getGameS()->setInputReceived(true);
            
            base->getGameS()->setInputInGameWorkQueue(base->getInputS()->getInputInGameWorkQueue());
        }
        base->getGameE()->getInputE()->setKeyPressed(INKEY_NONE);
    }
    else
    {
        
    }
    
/*    if (base->getGameE()->getInputE()->processInput())
    {
        if (base->getGameE()->getInputE()->getInputProcessed())
        {
            logMsg("Input Processed");
//            exit(0);
            if (base->getGameE()->getMenuActive())
            {
                logMsg("Input Processed menuActive");
//                exit(0);
                logMsg("menuReceiveKeyPress == " +convert->toString(base->getGameE()->getInputE()->getKeyPressed()));
//                exit(0);
//                getInputS()->setGameE(base->getGameE());
//                exit(0);
//                base->getGameE()->getInputE()->setKeyPressed(INKEY_M);
//                exit(0);
                getInputS()->process();
//                 getInputS()->getInputE()->setKeyPressed(INKEY_P);
                logMsg("menuReceiveKeyPressAgain == " +convert->toString(base->getGameE()->getInputE()->getKeyPressed()));
//                exit(0);
                gui->menuReceiveKeyPress(convert->toString(base->getGameE()->getInputE()->getKeyPressed())); // sends input to menu key input processing function
//                exit(0);
                if (base->getGameE()->getInputE()->getKeyPressed() == INKEY_T)
                {
//                    exit(0);
                }
                base->getGameE()->getInputE()->setKeyPressed(INKEY_NONE);
            }
        }
        if (base->getGameS()->getActiveTeamInstancesCreated())
        {
//            exit(0);
            size_t inputIterator = 0;
            while (inputIterator < activeTeamInstance.size())
            {
                if (activeTeamInstance[inputIterator]->getPlayerInstancesCreated())
                {
                    playerStateVecSharedPtr activePlayerInstance = activeTeamInstance[inputIterator]->getActivePlayerInstance();
                    if (activeTeamInstance[inputIterator]->getHumanControlled())
                    {
                        int humanPlayer = activeTeamInstance[inputIterator]->getHumanPlayer();
                        logMsg("inputHumanPlayer == " +convert->toString(humanPlayer));
                        //inputMaps inputMap = input->keyMap();
                        inputWorkQueues inputQueue = base->getGameE()->getInputE()->getInputWorkQueue();
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
                        int activeBBallInstance = base->getGameS()->getActiveBBallInstance();
                        basketballStateVec bballInstance = base->getGameS()->getBasketballInstance();
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
                                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);
//                                        exit(0);
                                    break;
                                    case INDOWN:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(DOWN);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INLEFT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(LEFT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INRIGHT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(RIGHT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INUPLEFT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(UPLEFT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INUPRIGHT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(UPRIGHT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INDOWNLEFT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(DOWNLEFT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INDOWNRIGHT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(DOWNRIGHT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INSHOOTBLOCK:
                                        activePlayerInstance[humanInstance]->setMovement(false);
                                        activePlayerInstance[humanInstance]->setShootBlock(true);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INPASSSTEAL:
                                        activePlayerInstance[humanInstance]->setMovement(false);
                                        activePlayerInstance[humanInstance]->setPassSteal(true);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INQUIT:
                                        logMsg("Quitting!");
                                        base->getGameE()->setQuitGame(true);
                                        exit(0);
                                    break;
                                    default:
                                    break;
                                }
                                ++x;
                            }
                        }
                        teamStateVecSharedPtr tInstance = base->getGameS()->getActiveTeamInstance();
                        playerStateVecSharedPtr activePInstance = tInstance[inputIterator]->getActivePlayerInstance();
                        logMsg("humanInstance == " +convert->toString(humanInstance));
                        //logMsg("inPassSteal == " +convert->toString(activePInstance[humanInstance]->getPassSteal()));
                        //exit(0);

                        /// FIXME! This if statement should be adapted to work correctly instead of relying on the i variable
                        int i = 0;
                        if (base->getGameS()->getTeamWithBall() == i)
                        {
                            if (activePlayerInstance[humanInstance]->getMovement())
                            {
                                logMsg("human playerID == " +convert->toString(activePlayerInstance[humanInstance]->getID()));
                                logMsg("ball player == " +convert->toString(activeTeamInstance[inputIterator]->getPlayerWithBallInstance()));
                                logMsg("ball playerID == " +convert->toString(activeTeamInstance[inputIterator]->getPlayerWithBallID()));
                                if (activePlayerInstance[humanInstance]->getID() == activeTeamInstance[inputIterator]->getPlayerWithBallID())
                                {
                                    bballInstance[activeBBallInstance].setMovement(true);
                                    base->getGameS()->setBasketballInstance(bballInstance);
                                }
                            }
                        }
                        if (base->getGameS()->getBasketballInstance().size() > 0)
                        {
                            logMsg("basketballmoved == " +convert->toString(bballInstance[activeBBallInstance].getMovement()));
                        }
                        base->getGameS()->setActiveTeamInstance(activeTeamInstance);

                        if (base->getGameS()->getGameType() == MULTI)
                        {
                            getNetworkS()->processLocalInput(base->getGameS()->getActiveTeamInstance());
                        }
                        inputQueue.clear();
                        base->getGameE()->getInputE()->setInputWorkQueue(inputQueue);
                    }
                    ++inputIterator;
                }
            }
        }

    }   
*/
//    exit(0);
    logMsg(func +" end");

}

void UBC::processNetworkEvents()  // processes events in the network subsyatem
{
    if (base->getGameE()->getServerRunning())
    {
        base->getGameE()->getNetworkE()->networkServer();   // Runs network server code              
    }
    if (base->getGameE()->getClientRunning())
    {
        base->getGameE()->getNetworkE()->networkClient();   // runs network client code
    }
}

void UBC::processPhysicsEvents()  // processes events in the physics subsyatem
{
    base->getGameE()->getPhysE()->stepWorld(base->getGameE()->getTimer());
}

bool UBC::gameLoop()  // Main Game Loop
{
    sharedPtr<conversion> convert = conversion::Instance();
    bool quitGame = base->getGameE()->getQuitGame();
    unsigned long changeInTime = 0;
    unsigned long CITmic = 0;
    unsigned long CITmil = 0;
    std::string func = "UBC::gameLoop()";
    boost::chrono::microseconds changeInTimeMicro;
    boost::chrono::milliseconds changeInTimeMill;
 
    logMsg(func +" beginning");
    
    SDL_StartTextInput();
    
    while (!quitGame)
    {
        processInput();
        processPhysicsEvents();
/*        if (base->getGameS()->getGameSetupComplete())  // checks to make sure game setup is complete before continuing
        {
            
            if (!base->getGameE()->getSceneCreated())
            {
                logMsg(func +" Scene Not Created!");
//                exit(0);
                if (base->getGameS()->getGameType() == SINGLE)
                {
                    logMsg(func +" getGameType() == SINGLE");
                    base->getGameE()->setCreateScene(true);
                    exit(0);
                }
                else if (base->getGameS()->getGameType() == MULTILOCAL)
                {
                    logMsg(func +" getGameType() == MULTILOCAL");
                    base->getGameE()->setCreateScene(true);
//                    exit(0);
                }
                else if (base->getGameS()->getGameType() == MULTINET)
                {
                    logMsg(func +" getGameType() == MULTINET");

                    if (base->getGameE()->getNetworkE()->getServerReceivedConnection() || base->getGameE()->getNetworkE()->getClientEstablishedConnection())  // checks if server and client are connected
                    {
                        base->getGameE()->setCreateScene(true);
                    }
    //             exit(0);
                }
            }
        }
*/        
        if (base->getStartActiveGame())
        {
            if (startGame())
            {
                base->getGameE()->setStart(false);
                base->getGameE()->setRenderScene(true);
                base->setStartActiveGame(false);
            }
            else
            {
                logMsg(func + " Unable to Start Active Game Instance!");
                exit(0);
            }
        }
        changeInTimeMicro = base->getGameE()->getTimer().calcChangeInTimeMicro();
        changeInTimeMill = base->getGameE()->getTimer().calcChangeInTimeMill();
        CITmic = changeInTimeMicro.count();
        CITmil = changeInTimeMill.count();

        logMsg ("changeInTimeMicro = " +convert->toString(CITmic));
        logMsg ("changeInTimeMill = " +convert->toString(CITmil));
        changeInTime = base->getGameE()->getTimer().getChangeInTimeMill().count();
        logMsg ("loopchange = " +convert->toString(changeInTime));
//        exit(0);
        if (changeInTime >= 10)
        {
            logMsg(func +"changeInTime > 10!");
//            exit(0);
            if (base->getGameS()->getGameType() == MULTINET)
            {
                processNetworkEvents();             
            }

//            logMsg("changeInTime = " +toString(changeInTime));
            if (base->getGameE()->getRenderScene())
            {
                logMsg(func +" gameS->getRenderScene()");
                
                base->getGameS()->updateState();  // updates the state of the game instance
            }
            base->getGameE()->getTimer().setPreviousTime(boost::chrono::system_clock::now());
        }
//        exit(0);
        
        if (!base->getGameE()->getRenderE()->renderFrame())
        {
            logMsg(func +" Unable to render frame!");
            exit(0);
        }
    }
    logMsg(func +" end");

    return (true);
}

void UBC::gameLoop_old()  // Main Game Loop
{
    sharedPtr<conversion> convert = conversion::Instance();
/*    sharedPtr<gameState> gameS = gameState::Instance();
//    sharedPtr<GUISystem> gui = GUISystem::Instance();
//    sharedPtr<inputSystem> input = inputSystem::Instance();
//    sharedPtr<renderEngine> render = renderEngine::Instance();
//    networkEngineSharedPtr network = networkEngine::Instance();
//    sharedPtr<soundEngine> sound = soundEngine::Instance();

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
    SDL_StartTextInput();
//    base->getGameE()->gameEngine();
    bool quitGame = base->getGameE()->getQuitGame();
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

        if (base->getGameS()->getGameSetupComplete())  // checks to make sure game setup is complete before continuing
        {
//            exit(0);
            if (!base->getGameE()->getSceneCreated())
            {
                
                if (base->getGameS()->getGameType() == SINGLE)
                {
                    base->getGameE()->setCreateScene(true);
                    exit(0);
                }
                else if (base->getGameS()->getGameType() == MULTINET)
                {
                    if (base->getGameE()->getNetworkE()->getServerReceivedConnection() || base->getGameE()->getNetworkE()->getClientEstablishedConnection())  // checks if server and client are connected
                    {
                        base->getGameE()->setCreateScene(true);
                    }
    //             exit(0);
                }
            }
        }
//        exit(0);
        if (base->getGameE()->getCreateScene())  // checks if the scene should be created
        {
//            exit(0);
//              if (render->createScene())
//            {
                base->getGameE()->setCreateScene(false);
                base->getGameE()->setStart(true);
//                  renderScene = true;
                base->getGameE()->setSceneCreated(true);
//            }
        }
//        exit(0);
//        if (base->getGameE()->getStart())  // checks if it's time to start the game
//        {
//            exit(0);
            if (startGame())
            {
                base->getGameE()->setStart(false);
                base->getGameE()->setRenderScene(true);
            }
 //       }
//        exit(0);
//        lastFPS = getRenderE()->getMWindow()->getLastFPS();
//        exit(0);
//        std::string currFPS = convert->toString(lastFPS);

//        logMsg("FPS = " +currFPS);
        //updateChangeInTime(); // calculates the change in time.
        

//          logMsg("changeInTime = " +toString(changeInTime));
        // updates game logic every 100 milliseconds
        if (base->getGameE()->getServerRunning() && !base->getGameE()->getNetworkE()->getIsServer())
        {
            base->getGameE()->getNetworkE()->setIsServer(true);
        }
        if (base->getGameE()->getClientRunning() && !base->getGameE()->getNetworkE()->getIsClient())
        {
            base->getGameE()->getNetworkE()->setIsClient(true);
        }

        if (base->getGameS()->getGameType() == MULTINET && base->getGameE()->getNetworkE()->getTeamType() == NOTEAM)
        {
            if (base->getGameE()->getNetworkE()->getIsServer())
            {
                base->getGameE()->getNetworkE()->setTeamType(HOMETEAM);
            }
            
            if (base->getGameE()->getNetworkE()->getIsClient())
            {
                base->getGameE()->getNetworkE()->setTeamType(AWAYTEAM);
            }
        }
        
        logMsg("serverRunning = " +base->getGameE()->getServerRunning());
        logMsg("clientRunning = " +base->getGameE()->getClientRunning());
        boost::chrono::microseconds changeInTimeMicro = base->getGameE()->getTimer().calcChangeInTimeMicro();
        
        boost::chrono::milliseconds changeInTimeMill = base->getGameE()->getTimer().calcChangeInTimeMill();
        changeInTime = base->getGameE()->getTimer().getChangeInTimeMill().count();
        logMsg ("loopchange = " +convert->toString(changeInTime));
//        exit(0);
        if (changeInTime >= 10)
        {
//              exit(0);
            if (base->getGameE()->getServerRunning())
            {
                base->getGameE()->getNetworkE()->networkServer();   // Runs network server code
                
            }
            if (base->getGameE()->getClientRunning())
            {
                base->getGameE()->getNetworkE()->networkClient();   // runs network client code
            }


//            logMsg("changeInTime = " +toString(changeInTime));
            if (base->getGameE()->getRenderScene())
            {
                logMsg("gameS->updateState()");
                base->getGameS()->updateState();  // updates the state of the game instance
            }
            
            //boost::chrono::system_clock::time_point newT = boost::chrono::system_clock::now();
            //boost::chrono::milliseconds milliSecs = boost::chrono::duration_cast<boost::chrono::milliseconds>(newT);
            //oldTime = milliSecs.count();
            base->getGameE()->getTimer().setPreviousTime(boost::chrono::system_clock::now());
        }
//        exit(0);
        processInput();
//        exit(0);
        if (!base->getGameE()->getRenderE()->renderFrame())
        {
            logMsg("Unable to render frame!");
            exit(0);
        }
    }

}

bool UBC::updateGUI()  // updates the gui based on received events
{
    std::string func = "UBC::updateGUI()";

    logMsg(func +" beginning");

    if (base->getGameE()->getInputE()->getMouseClicked())
    {
        logMsg(func +" updateGUI Mouse Clicked!");
        exit(0);
        gui->getMGUI()->injectMousePress(base->getGameE()->getInputE()->getMouseX(), base->getGameE()->getInputE()->getMouseY(), MyGUI::MouseButton::Enum(0));
    }
    else
    {
        gui->getMGUI()->injectMouseRelease(base->getGameE()->getInputE()->getMouseX(), base->getGameE()->getInputE()->getMouseY(), MyGUI::MouseButton::Enum(0));
    }
    
    logMsg(func +" end");

    return (true);
}


int main(int argc, char *argv[])
{
    sharedPtr<conversion> convert = conversion::Instance();
//    sharedPtr<UBC> ubc;
    sharedPtr<UBC> ubc(new UBC);
//    exit(0);
//    sharedPtr<renderEngine> render = ubc.getRenderE();
//    sharedPtr<gameEngine> gameE = gameEngine::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
//    sharedPtr<GUISystem> gui = ubc.getGui();
//    exit(0);   
    std::string func = "main()";

    logMsg(func +" beginning");

//    exit(0);
    ubc->setup();
//    exit(0);
    ubc->run();
//    exit(0);
    logMsg(func +" end");


//    atexit(SDL_Quit);

	return (0);
}

