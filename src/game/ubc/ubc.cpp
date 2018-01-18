/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
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

#include "utilities/conversion.h"
#include "OgrePrerequisites.h"
#include "engine/gameengine.h"
#include "engine/inputengine.h"
#include "engine/renderengine.h"
#include "engine/physicsengine.h"
#include "entity/playerentity.h"
#include "state/basketballstate.h"
#include "state/gamestate.h"
#include "input/inputgamepads.h"
#include "input/inputkeyboards.h"
#include "state/networkstate.h"
#include "state/playerstate.h"
#include "state/teamstate.h"
#include "users/users.h"
#include "users/usersinputs.h"
#include "load/loadusersinputs.h"
#include "utilities/logging.h"
#include "ubc/ubc.h"
#include "ubc/ubcgame.h"
#include "ubc/ubcinput.h"
#include "network/networkplayerstateobject.h"
#include "statemachine/playerstatemachine.h"

#ifdef __ANDROID__
#include "utilities/android.h"
#include "SDL.h"
#include "SDL_main.h"
#endif

// static declarations 
gameEngineSharedPtr UBC::gameE;  // the gameEngine object
GUISystemSharedPtr UBC::gui;  // the GUI object.
UBCGameSharedPtr UBC::game;  // static copy of UBCGame class
UBCInputSharedPtr UBC::input;  // static copy of UBCInput class


UBC::UBC()  // constructor
{
//    quitGame = false;

}

UBC::~UBC()  // destructor
{

}

gameEngineSharedPtr UBC::getGameE()  // retrieves the value of gameE
{
    return (gameE);
}
void UBC::setGameE(gameEngineSharedPtr set)  // sets the value of gameE
{
    gameE = set;
}

GUISystemSharedPtr UBC::getGui()  // retrieves the value of gui
{
    return (gui);
}
void UBC::setGui(GUISystemSharedPtr set)  // sets the value of gui
{
    gui = set;
}

UBCGameSharedPtr UBC::getGame()  // retrieves the value of game
{
    return (game);
}
void UBC::setGame(UBCGameSharedPtr set)  // sets the value of game
{
    game = set;
}

UBCInputSharedPtr UBC::getInput()  // retrieves the value of input
{
    return (input);
}
void UBC::setInput(UBCInputSharedPtr set)  // sets the value of input
{
    input = set;
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
    std::string func = "UBC::setup()";

    //    gameEngine *tempGameEObj = new gameEngine;
    gameEngineSharedPtr tempGameESharedPtr(new gameEngine);
    gameE = tempGameESharedPtr;
//    gameE(new gameEngine);
    logMsg(func +" gameE->setup()");
    gameE->setup();  // sets up the game engine
    
    logMsg(func +" beginning");

    GUISystemSharedPtr tempGUISharedPtr(new GUISystem);
    gui = tempGUISharedPtr;
    
    gui->setGameE(gameE);
    
    // setup game object
    UBCGameSharedPtr tempGameSharedPtr(new UBCGame);

    game = tempGameSharedPtr;

    // setup input object
    UBCInputSharedPtr tempInputSharedPtr(new UBCInput);
    input = tempInputSharedPtr;
//    input->setBase(base);
//    base->getInputKeyboard()->setBase(base);
//    base->getInputGamePad()->setBase(base);
    logMsg(func +" end");
    
//        exit(0);
//        gui->getBase()->setGameS(gameInstance);
//        exit(0);
}

bool UBC::setupState()  // sets up the UBC game state
{
//    Ogre::Viewport *vp = getRenderE()->getViewPort();
//    setViewPort(*vp);  // sets the viewPort for MyGUI
//    exit(0);
    bool stateSetup = true;
    std::string func = "UBC::setupState()";

    logMsg(func +" begin");

//    GUISystemSharedPtr gui = base->getGui();
    if (gui->setup(gameE->getRenderE()))  // sets up the game GUI
    {
        gui->setGameInstance(game->getGameInstance());  // shares gameInstance with gui object
//        exit(0);
        gui->setSetupComplete(true);
//        exit(0);
        gui->mainMenu(gameE->getRenderE());
//        exit(0);
        gui->backButtons();
    }
    else
    {
        logMsg(func +" Unable to setup GUI!");
        exit(0);
    }
//    base->setGui(gui);
//    exit(0); 
    
    logMsg(func +" end");

    return (stateSetup);
}

void UBC::executeState()  // executes the UBC game code
{
}

void UBC::run()  // runs the game
{
    conversionSharedPtr convert = conversion::Instance();
//    exit(0);
//    renderEngineSharedPtr renderTemp = gameE->getRenderE();
//    exit(0);
    std::string func = "UBC::run()";

    logMsg(func +" beginning");

//    exit(0);
//    base->setup();
    game->setup();
    gameE->getRenderE()->initSDL(); // Initializes the SDL Subsystem
//    exit(0);
    gameE->getRenderE()->initOgre(); // Initializes the Ogre Subsystem
//    exit(0);
    gameE->getRenderE()->createScene(); // creates rendering scene.

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
//    gameInstance->createInstances();  // creates object instances
//    sharedPtr<entity> gameStateSharedPtr(new entity);

    if (gameE->getRenderE()->getMWindow() == NULL)
    {
        logMsg(func +" mWindow == NULL!");
//        exit(0);
    }
//    exit(0);
//    setupState();  // sets up the game state

    sharedPtr<Ogre::Viewport> vp = gameE->getRenderE()->getViewPort();
//    setViewPort(*vp);  // sets the viewPort for MyGUI

//    exit(0);
    
    //FIXME! Hard coded until code is restructured
    game->setNumUsers(1);
    
    logMsg(func + " Creating Users Instances!");
    if (!game->getUsersInstancesCreated())
    {
        if (game->createUserInstances())
        {
            game->setUsersInstancesCreated(true);
        }
        else
        {
            
        }
    }
    else
    {
        
    }
    
    logMsg(func + "Setting up Users Input");
    // sets up users input
    if (game->getUsersInstancesCreated() && !game->getUserInstancesInputSetup())
    {
        if (game->setupUserInstancesInput())
        {
            game->setUserInstancesInputSetup(true);
        }
        else
        {
            
        }
    }
    else
    {
        
    }
    
    logMsg(func +" Setting up input object");
    if (!input->getSetupComplete())
    {
        logMsg(func +" setting up UBCInput object");
        if (input->setup())
        {
            logMsg(func +" Input setup!");
            input->setSetupComplete(true);
        }
        else
        {
            logMsg(func +" Unable to setup Input!");
            exit(0);
        }

    }
/*    if (!base->getInputSUInputSetup())
    {
        if (setupInputSObjUserInput())
        {
            base->setInputSUInputSetup(true);
        }
        else
        {
            logMsg(func +" Unable to setup uInput!");
            exit(0);
        }
    }
    else
    {
        
    }
*/
    //inputSystem *input = inputSystem::Instance();
//    sharedPtr<inputSystem> input = getInputE();
//    exit(0);

//    bool quitGame = gameE->getQuitGame();
       
    game->loop(gameE, input, gui);

    logMsg(func +" end");

}



/*bool UBC::gameLoop()  // Main Game Loop
{
    conversionSharedPtr convert = conversion::Instance();
    bool quitGame = gameE->getQuitGame();
    unsigned long changeInTime = 0;
    unsigned long CITmic = 0;
    unsigned long CITmil = 0;
    std::string func = "UBC::gameLoop()";
    boost::chrono::microseconds changeInTimeMicro;
    boost::chrono::milliseconds changeInTimeMill;
    playerStateMachine playerSM;
    playerSMData *playerSMD = new playerSMData;
    playerSMData *playerSMD2 = new playerSMData;
    playerSMData *playerSMD3 = new playerSMData;

    logMsg(func +" beginning");
    
///    playerSMD->speed = 100;
///    playerSM.setSpeed(playerSMD);
///    playerSM.halt();
///    logMsg(func +" dah");
///    playerSMD2->speed = 200;
///    playerSM.pJump(playerSMD2);
///    playerSMD3->direction = UP;
///    playerSM.pChangeDirection(playerSMD3);

    logMsg(func +" Wootio!");
//    exit(0);
    
    SDL_StartTextInput();
    
    while (!quitGame)
    {
        input->process();
//        processPhysicsEvents();
        
///        if (gameInstance->getGameSetupComplete())  // checks to make sure game setup is complete before continuing
///        {
            
///            if (!gameE->getSceneCreated())
///            {
///                logMsg(func +" Scene Not Created!");
//                exit(0);
///                if (gameInstance->getGameType() == SINGLE)
///                {
///                    logMsg(func +" getGameType() == SINGLE");
///                    gameE->setCreateScene(true);
///                    exit(0);
///                }
///                else if (gameInstance->getGameType() == MULTILOCAL)
///                {
///                    logMsg(func +" getGameType() == MULTILOCAL");
///                    gameE->setCreateScene(true);
//                    exit(0);
///                }
///                else if (gameInstance->getGameType() == MULTINET)
///                {
///                    logMsg(func +" getGameType() == MULTINET");
///
///                    if (gameE->getNetworkE()->getServerReceivedConnection() || gameE->getNetworkE()->getClientEstablishedConnection())  // checks if server and client are connected
///                    {
///                        gameE->setCreateScene(true);
///                    }
    //             exit(0);
///                }
///            }
///        }
        
       // exit(0);

        if (game->getStartActiveGame())
        {
            if (startGame())
            {
                gameE->setStart(false);
                gameE->setRenderScene(true);
                game->setStartActiveGame(false);
            }
            else
            {
                logMsg(func + " Unable to Start Active Game Instance!");
                exit(0);
            }
        }
        changeInTimeMicro = gameE->getTimer().calcChangeInTimeMicro();
        changeInTimeMill = gameE->getTimer().calcChangeInTimeMill();
        CITmic = changeInTimeMicro.count();
        CITmil = changeInTimeMill.count();

        logMsg ("changeInTimeMicro = " +convert->toString(CITmic));
        logMsg ("changeInTimeMill = " +convert->toString(CITmil));
        changeInTime = gameE->getTimer().getChangeInTimeMill().count();
        logMsg ("loopchange = " +convert->toString(changeInTime));
//        exit(0);
        if (changeInTime >= 10)
        {
            logMsg(func +"changeInTime > 10!");
//            exit(0);
            if (gameInstance->getGameType() == MULTINET)
            {
                processNetworkEvents();             
            }

//            logMsg("changeInTime = " +toString(changeInTime));
            if (gameE->getRenderScene())
            {
                logMsg(func +" gameS->getRenderScene()");
                
                gameInstance->updateState();  // updates the state of the game instance
            }
            gameE->getTimer().setPreviousTime(boost::chrono::system_clock::now());
        }
//        exit(0);
        
        if (!gameE->getRenderE()->renderFrame())
        {
            logMsg(func +" Unable to render frame!");
            exit(0);
        }
    }
    logMsg(func +" end");

    return (true);
}*/

void UBC::gameLoop_old()  // Main Game Loop
{
    conversionSharedPtr convert = conversion::Instance();
    gameStateSharedPtr gameInstance; // only done to fix build error
    bool startGame;  // only done to fix build error
/*    sharedPtr<gameState> gameS = gameState::Instance();
//    sharedPtr<GUISystem> gui = GUISystem::Instance();
//    sharedPtr<inputSystem> input = inputSystem::Instance();
//    renderEngineSharedPtr render = renderEngine::Instance();
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
//    gameE->gameEngine();
    bool quitGame = gameE->getQuitGame();
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

        if (gameInstance->getGameSetupComplete())  // checks to make sure game setup is complete before continuing
        {
//            exit(0);
            if (!gameE->getSceneCreated())
            {
                
                if (gameInstance->getGameType() == SINGLE)
                {
                    gameE->setCreateScene(true);
                    exit(0);
                }
                else if (gameInstance->getGameType() == MULTINET)
                {
                    if (gameE->getNetworkE()->getServerReceivedConnection() || gameE->getNetworkE()->getClientEstablishedConnection())  // checks if server and client are connected
                    {
                        gameE->setCreateScene(true);
                    }
    //             exit(0);
                }
            }
        }
//        exit(0);
        if (gameE->getCreateScene())  // checks if the scene should be created
        {
//            exit(0);
//              if (render->createScene())
//            {
                gameE->setCreateScene(false);
                gameE->setStart(true);
//                  renderScene = true;
                gameE->setSceneCreated(true);
//            }
        }
//        exit(0);
//        if (gameE->getStart())  // checks if it's time to start the game
//        {
//            exit(0);
/*            if (startGame())
            {
                gameE->setStart(false);
                gameE->setRenderScene(true);
            }
*/
 //       }
//        exit(0);
//        lastFPS = getRenderE()->getMWindow()->getLastFPS();
//        exit(0);
//        std::string currFPS = convert->toString(lastFPS);

//        logMsg("FPS = " +currFPS);
        //updateChangeInTime(); // calculates the change in time.
        

//          logMsg("changeInTime = " +toString(changeInTime));
        // updates game logic every 100 milliseconds
        if (gameE->getServerRunning() && !gameE->getNetworkE()->getIsServer())
        {
            gameE->getNetworkE()->setIsServer(true);
        }
        if (gameE->getClientRunning() && !gameE->getNetworkE()->getIsClient())
        {
            gameE->getNetworkE()->setIsClient(true);
        }

        if (gameInstance->getGameType() == MULTINET && gameE->getNetworkE()->getTeamType() == NOTEAM)
        {
            if (gameE->getNetworkE()->getIsServer())
            {
                gameE->getNetworkE()->setTeamType(HOMETEAM);
            }
            
            if (gameE->getNetworkE()->getIsClient())
            {
                gameE->getNetworkE()->setTeamType(AWAYTEAM);
            }
        }
        
        logMsg("serverRunning = " +gameE->getServerRunning());
        logMsg("clientRunning = " +gameE->getClientRunning());
        boost::chrono::microseconds changeInTimeMicro = gameE->getTimer().calcChangeInTimeMicro();
        
        boost::chrono::milliseconds changeInTimeMill = gameE->getTimer().calcChangeInTimeMill();
        changeInTime = gameE->getTimer().getChangeInTimeMill().count();
        logMsg ("loopchange = " +convert->toString(changeInTime));
//        exit(0);
        if (changeInTime >= 10)
        {
//              exit(0);
            if (gameE->getServerRunning())
            {
                gameE->getNetworkE()->networkServer();   // Runs network server code
                
            }
            if (gameE->getClientRunning())
            {
                gameE->getNetworkE()->networkClient();   // runs network client code
            }


//            logMsg("changeInTime = " +toString(changeInTime));
            if (gameE->getRenderScene())
            {
                logMsg("gameS->updateState()");
                gameInstance->updateState();  // updates the state of the game instance
            }
            
            //boost::chrono::system_clock::time_point newT = boost::chrono::system_clock::now();
            //boost::chrono::milliseconds milliSecs = boost::chrono::duration_cast<boost::chrono::milliseconds>(newT);
            //oldTime = milliSecs.count();
            gameE->getTimer().setPreviousTime(boost::chrono::system_clock::now());
        }
//        exit(0);
//        input->process(gameE, gameInstance);
//        exit(0);
        if (!gameE->getRenderE()->renderFrame())
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

//    GUISystemSharedPtr gui = base->getGui();
    if (gameE->getInputE()->getMouseClicked())
    {
        logMsg(func +" updateGUI Mouse Clicked!");
        exit(0);
        gui->getMGUI()->injectMousePress(gameE->getInputE()->getMouseX(), gameE->getInputE()->getMouseY(), MyGUI::MouseButton::Enum(0));
    }
    else
    {
        gui->getMGUI()->injectMouseRelease(gameE->getInputE()->getMouseX(), gameE->getInputE()->getMouseY(), MyGUI::MouseButton::Enum(0));
    }
//    base->setGui(gui);

    logMsg(func +" end");

    return (true);
}



bool UBC::setupInputSObjUserInput()  // sets up user input mapping for inputS object
{
    usersMSharedPtr tempUsersInstance;
    usersInputsVecSharedPtr tempUserInput;
    
    tempUsersInstance = game->getUsersInstance();

    
    for ( auto TUIIT : tempUsersInstance)
    {
        tempUserInput.push_back(TUIIT.second->getUserInput());
    }
    
    input->getInputGamePad()->getInputInstance()->setUInput(tempUserInput);
    input->getInputKeyboard()->getInputInstance()->setUInput(tempUserInput);

    return (true);
}

int main(int argc, char *argv[])
{
    conversionSharedPtr convert = conversion::Instance();
//    sharedPtr<UBC> ubc;
    sharedPtr<UBC> ubc(new UBC);
//    exit(0);
//    renderEngineSharedPtr render = ubc.getRenderE();
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

