/***************************************************************************
 *   Copyright (C) 1999 - 2016 by Mike McLean   *
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
#include "state/inputstate.h"
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

// static declarations 
boost::shared_ptr<GUISystem> UBC::gui;  // the GUI object.
  
UBC::UBC()  // constructor
{
//    quitGame = false;
/*    gameEngine *tempGameEObj = new gameEngine;
    boost::shared_ptr<gameEngine> tempGameESharedPtr = boost::shared_ptr<gameEngine>(tempGameEObj);
    setGameE(tempGameESharedPtr);
*/
//    GUISystem *tempGUIObj = new GUISystem;
    boost::shared_ptr<GUISystem> tempGUISharedPtr(new GUISystem);
    gui = tempGUISharedPtr;
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



bool UBC::setupState()  // sets up the UBC game state
{
//    Ogre::Viewport *vp = getRenderE()->getViewPort();
//    setViewPort(*vp);  // sets the viewPort for MyGUI
    logMsg("blah!");
//    exit(0);
    bool stateSetup = true;
//    exit(0);
    
    if (gui->setup())  // sets up the game GUI
    {
        gui->setSetupComplete(true);
        gui->mainMenu();
        gui->backButtons();
    }
    else
    {
        logMsg("Unable to setup GUI!");
        exit(0);
    }
    
    return (stateSetup);
}

void UBC::executeState()  // executes the UBC game code
{
}

void UBC::run()  // runs the game
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    exit(0);
//    boost::shared_ptr<renderEngine> renderTemp = getGameE()->getRenderE();
//    exit(0);
    getGameE()->getRenderE()->initSDL(); // Initializes the SDL Subsystem
//    exit(0);
    getGameE()->getRenderE()->initOgre(); // Initializes the Ogre Subsystem
//    exit(0);
    getGameE()->getRenderE()->createScene(); // creates rendering scene.

//    boost::shared_ptr<entity> gameStateSharedPtr(new entity);

//    exit(0);

    logMsg("pre setupState!");
    if (setupState())  // sets up the game state
    {
        logMsg("UBC state setup successfully!");
    }
    else
    {
        logMsg("Unable to setup UBC state!");
//        return (false);
    }

//    getGameS()->createInstances();  // creates object instances
//    boost::shared_ptr<entity> gameStateSharedPtr(new entity);

    if (getGameE()->getRenderE()->getMWindow() == NULL)
    {
        logMsg("mWindow == NULL!");
//        exit(0);
    }
//    exit(0);
//    setupState();  // sets up the game state

    Ogre::Viewport *vp = getGameE()->getRenderE()->getViewPort();
//    setViewPort(*vp);  // sets the viewPort for MyGUI

//    exit(0);
    logMsg("Initializing Input");
    //inputSystem *input = inputSystem::Instance();
//    boost::shared_ptr<inputSystem> input = getInputE();
//    exit(0);

//    bool quitGame = getGameE()->getQuitGame();
 
    gameLoop();

}

bool UBC::startGame()  // starts the game
{
//    boost::shared_ptr<gameState> gameS = gameState::Instance();

    logMsg("startGame()");

    getGameS()->setupState();
    return (true);
}

void UBC::processInput()  // processes game input
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
//    boost::shared_ptr<GUISystem> gui = GUISystem::Instance();
//    boost::shared_ptr<inputSystem> input = inputSystem::Instance();
//    boost::shared_ptr<networkEngine> network = networkEngine::Instance();
    std::vector<boost::shared_ptr<teamState> > activeTeamInstance = getGameS()->getActiveTeamInstance();
    networkPlayerStateObject netPStateObj;

    logMsg("inputProcess!");
//    exit(0);
    
    if (getInputS()->process())
    {
        if (getGameE()->getMenuActive())
        {
            gui->menuReceiveKeyPress(convert->toString(getGameE()->getInputE()->getKeyPressed())); // sends input to menu key input processing function
        }
        else
        {
            getGameS()->setInputReceived(true);
            
            getGameS()->setInputInGameWorkQueue(getInputS()->getInputInGameWorkQueue());
        }
        getGameE()->getInputE()->setKeyPressed(INKEY_NONE);
    }
    else
    {
        
    }
    
/*    if (getGameE()->getInputE()->processInput())
    {
        if (getGameE()->getInputE()->getInputProcessed())
        {
            logMsg("Input Processed");
//            exit(0);
            if (getGameE()->getMenuActive())
            {
                logMsg("Input Processed menuActive");
//                exit(0);
                logMsg("menuReceiveKeyPress == " +convert->toString(getGameE()->getInputE()->getKeyPressed()));
//                exit(0);
//                getInputS()->setGameE(getGameE());
//                exit(0);
//                getGameE()->getInputE()->setKeyPressed(INKEY_M);
//                exit(0);
                getInputS()->process();
//                 getInputS()->getInputE()->setKeyPressed(INKEY_P);
                logMsg("menuReceiveKeyPressAgain == " +convert->toString(getGameE()->getInputE()->getKeyPressed()));
//                exit(0);
                gui->menuReceiveKeyPress(convert->toString(getGameE()->getInputE()->getKeyPressed())); // sends input to menu key input processing function
//                exit(0);
                if (getGameE()->getInputE()->getKeyPressed() == INKEY_T)
                {
//                    exit(0);
                }
                getGameE()->getInputE()->setKeyPressed(INKEY_NONE);
            }
        }
        if (getGameS()->getActiveTeamInstancesCreated())
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
                        inputWorkQueues inputQueue = getGameE()->getInputE()->getInputWorkQueue();
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
                        int activeBBallInstance = getGameS()->getActiveBBallInstance();
                        std::vector<basketballState> bballInstance = getGameS()->getBasketballInstance();
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
                                        getGameS()->setActiveTeamInstance(activeTeamInstance);
//                                        exit(0);
                                    break;
                                    case INDOWN:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(DOWN);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INLEFT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(LEFT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INRIGHT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(RIGHT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INUPLEFT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(UPLEFT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INUPRIGHT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(UPRIGHT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INDOWNLEFT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(DOWNLEFT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INDOWNRIGHT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(DOWNRIGHT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INSHOOTBLOCK:
                                        activePlayerInstance[humanInstance]->setMovement(false);
                                        activePlayerInstance[humanInstance]->setShootBlock(true);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INPASSSTEAL:
                                        activePlayerInstance[humanInstance]->setMovement(false);
                                        activePlayerInstance[humanInstance]->setPassSteal(true);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        getGameS()->setActiveTeamInstance(activeTeamInstance);
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
                        std::vector<boost::shared_ptr<teamState> > tInstance = getGameS()->getActiveTeamInstance();
                        std::vector<boost::shared_ptr<playerState> > activePInstance = tInstance[inputIterator]->getActivePlayerInstance();
                        logMsg("humanInstance == " +convert->toString(humanInstance));
                        //logMsg("inPassSteal == " +convert->toString(activePInstance[humanInstance]->getPassSteal()));
                        //exit(0);

                        /// FIXME! This if statement should be adapted to work correctly instead of relying on the i variable
                        int i = 0;
                        if (getGameS()->getTeamWithBall() == i)
                        {
                            if (activePlayerInstance[humanInstance]->getMovement())
                            {
                                logMsg("human playerID == " +convert->toString(activePlayerInstance[humanInstance]->getID()));
                                logMsg("ball player == " +convert->toString(activeTeamInstance[inputIterator]->getPlayerWithBallInstance()));
                                logMsg("ball playerID == " +convert->toString(activeTeamInstance[inputIterator]->getPlayerWithBallID()));
                                if (activePlayerInstance[humanInstance]->getID() == activeTeamInstance[inputIterator]->getPlayerWithBallID())
                                {
                                    bballInstance[activeBBallInstance].setMovement(true);
                                    getGameS()->setBasketballInstance(bballInstance);
                                }
                            }
                        }
                        if (getGameS()->getBasketballInstance().size() > 0)
                        {
                            logMsg("basketballmoved == " +convert->toString(bballInstance[activeBBallInstance].getMovement()));
                        }
                        getGameS()->setActiveTeamInstance(activeTeamInstance);

                        if (getGameS()->getGameType() == MULTI)
                        {
                            getNetworkS()->processLocalInput(getGameS()->getActiveTeamInstance());
                        }
                        inputQueue.clear();
                        getGameE()->getInputE()->setInputWorkQueue(inputQueue);
                    }
                    ++inputIterator;
                }
            }
        }

    }   
*/
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
    SDL_StartTextInput();
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

        if (getGameS()->getGameSetupComplete())  // checks to make sure game setup is complete before continuing
        {
            if (!getGameE()->getSceneCreated())
            {
                if (getGameS()->getGameType() == SINGLE)
                {
                    getGameE()->setCreateScene(true);
                }
                else if (getGameS()->getGameType() == MULTI)
                {
                    if (getGameE()->getNetworkE()->getServerReceivedConnection() || getGameE()->getNetworkE()->getClientEstablishedConnection())  // checks if server and client are connected
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
//        lastFPS = getRenderE()->getMWindow()->getLastFPS();
//        exit(0);
//        std::string currFPS = convert->toString(lastFPS);

//        logMsg("FPS = " +currFPS);
        //updateChangeInTime(); // calculates the change in time.
        

//          logMsg("changeInTime = " +toString(changeInTime));
        // updates game logic every 100 milliseconds
        if (getGameE()->getServerRunning() && !getGameE()->getNetworkE()->getIsServer())
        {
            getGameE()->getNetworkE()->setIsServer(true);
        }
        if (getGameE()->getClientRunning() && !getGameE()->getNetworkE()->getIsClient())
        {
            getGameE()->getNetworkE()->setIsClient(true);
        }

        if (getGameS()->getGameType() == MULTI && getGameE()->getNetworkE()->getTeamType() == NOTEAM)
        {
            if (getGameE()->getNetworkE()->getIsServer())
            {
                getGameE()->getNetworkE()->setTeamType(HOMETEAM);
            }
            
            if (getGameE()->getNetworkE()->getIsClient())
            {
                getGameE()->getNetworkE()->setTeamType(AWAYTEAM);
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
                getGameE()->getNetworkE()->networkServer();   // Runs network server code
                
            }
            if (getGameE()->getClientRunning())
            {
                getGameE()->getNetworkE()->networkClient();   // runs network client code
            }


//            logMsg("changeInTime = " +toString(changeInTime));
            if (getGameE()->getRenderScene())
            {
                logMsg("gameS->updateState()");
                getGameS()->updateState();  // updates the state of the game instance
            }
            
            //boost::chrono::system_clock::time_point newT = boost::chrono::system_clock::now();
            //boost::chrono::milliseconds milliSecs = boost::chrono::duration_cast<boost::chrono::milliseconds>(newT);
            //oldTime = milliSecs.count();
            getGameE()->getTimer().setPreviousTime(boost::chrono::system_clock::now());
        }
//        exit(0);
        processInput();
//        exit(0);
        if (!getGameE()->getRenderE()->renderFrame())
        {
            logMsg("Unable to render frame!");
            exit(0);
        }
    }

}

bool UBC::updateGUI()  // updates the gui based on received events
{
    if (getGameE()->getInputE()->getMouseClicked())
    {
        logMsg("updateGUI Mouse Clicked!");
        exit(0);
        gui->getMGUI()->injectMousePress(getGameE()->getInputE()->getMouseX(), getGameE()->getInputE()->getMouseY(), MyGUI::MouseButton::Enum(0));
    }
    else
    {
        gui->getMGUI()->injectMouseRelease(getGameE()->getInputE()->getMouseX(), getGameE()->getInputE()->getMouseY(), MyGUI::MouseButton::Enum(0));
    }
    
    return (true);
}


int main(int argc, char *argv[])
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<UBC> ubc;
    boost::shared_ptr<UBC> ubc(new UBC);
//    boost::shared_ptr<renderEngine> render = ubc.getRenderE();
//    boost::shared_ptr<gameEngine> gameE = gameEngine::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
//    boost::shared_ptr<GUISystem> gui = ubc.getGui();
//    exit(0);
    ubc->run();
//    exit(0);
    logMsg("End Game!");

//    atexit(SDL_Quit);

	return (0);
}

