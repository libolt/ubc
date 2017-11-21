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
#include "ubc/ubcbase.h"
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
UBCBaseSharedPtr UBC::base;  // static copy of UBCBase class
UBCGameSharedPtr UBC::game;  // static copy of UBCGame class
UBCInputSharedPtr UBC::input;  // static copy of UBCInput class

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

    UBCBaseSharedPtr tempBaseSharedPtr(new UBCBase);
    base = tempBaseSharedPtr;
    
    logMsg(func +" beginning");

    if (!base->getStateSetup())
    {
        if (base->setup())
        {
//            base->getGameS()->setInitialized(true);

//BASEREMOVAL            base->getGameS()->setBase(base);

//            base->getGui()->setBase(base);

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
        base->setGui(tempGUISharedPtr);
//BASEREMOVAL        base->getGui()->setBase(base);
//BASEREMOVAL        base->getGameS()->setBase(base);
        base->setStateSetup(true);

    }

    // setup game object
    UBCGameSharedPtr tempGameSharedPtr(new UBCGame);

    game = tempGameSharedPtr;

    // setup input object
    UBCInputSharedPtr tempInputSharedPtr(new UBCInput);
    input = tempInputSharedPtr;
    input->setBase(base);
//    base->getInputKeyboard()->setBase(base);
//    base->getInputGamePad()->setBase(base);
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

    GUISystemSharedPtr gui = base->getGui();
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
    base->setGui(gui);
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
    
    //FIXME! Hard coded until code is restructured
    base->setNumUsers(1);
    
    logMsg(func + " Creating Users Instances!");
    if (!game->getUsersInstancesCreated())
    {
        if (createUserInstances())
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
    if (game->getUsersInstancesCreated() && !base->getUserInstancesInputSetup())
    {
        if (setupUserInstancesInput())
        {
            base->setUserInstancesInputSetup(true);
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

//    bool quitGame = base->getGameE()->getQuitGame();
       
    gameLoop();

    logMsg(func +" end");

}

bool UBC::startGame()  // starts the game
{
//    sharedPtr<gameState> gameS = gameState::Instance();
    std::string func = "UBC::startGame()";

    logMsg(func +" beginning");

//    exit(0);
//BASEREMOVAL    base->getGameS()->setBase(base);
    base->getGameS()->setupState();
    
    logMsg(func +" end");
//    exit(0);
    return (true);
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

/*bool UBC::gameLoop()  // Main Game Loop
{
    conversionSharedPtr convert = conversion::Instance();
    bool quitGame = base->getGameE()->getQuitGame();
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
        
///        if (base->getGameS()->getGameSetupComplete())  // checks to make sure game setup is complete before continuing
///        {
            
///            if (!base->getGameE()->getSceneCreated())
///            {
///                logMsg(func +" Scene Not Created!");
//                exit(0);
///                if (base->getGameS()->getGameType() == SINGLE)
///                {
///                    logMsg(func +" getGameType() == SINGLE");
///                    base->getGameE()->setCreateScene(true);
///                    exit(0);
///                }
///                else if (base->getGameS()->getGameType() == MULTILOCAL)
///                {
///                    logMsg(func +" getGameType() == MULTILOCAL");
///                    base->getGameE()->setCreateScene(true);
//                    exit(0);
///                }
///                else if (base->getGameS()->getGameType() == MULTINET)
///                {
///                    logMsg(func +" getGameType() == MULTINET");
///
///                    if (base->getGameE()->getNetworkE()->getServerReceivedConnection() || base->getGameE()->getNetworkE()->getClientEstablishedConnection())  // checks if server and client are connected
///                    {
///                        base->getGameE()->setCreateScene(true);
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
                base->getGameE()->setStart(false);
                base->getGameE()->setRenderScene(true);
                game->setStartActiveGame(false);
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
}*/

void UBC::gameLoop_old()  // Main Game Loop
{
    conversionSharedPtr convert = conversion::Instance();
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
        input->process();
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

    GUISystemSharedPtr gui = base->getGui();
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
    base->setGui(gui);

    logMsg(func +" end");

    return (true);
}

bool UBC::createUserInstances()  // creates the user instances
{
    conversionSharedPtr convert = conversion::Instance();
    usersMSharedPtr tempUserInstance;
    std::string func = "UBC::createUserInstances()";

    logMsg(func +" beginning");
    
    size_t x = 0;
    
    usersSharedPtr tempUsers(new users);
    for (x=0;x<base->getNumUsers();++x)
    {
       std::string userName = "player" +convert->toString(x);
       logMsg(func +" " +userName);
       tempUserInstance.insert(std::pair<size_t, usersSharedPtr>(x, tempUsers));
    }
    
    logMsg(func +" end");
//    exit(0);
    
    return (true);
}

bool UBC::setupUserInstancesInput()  // sets up input mapping for each user
{
    conversionSharedPtr convert = conversion::Instance();
    loadUsersInputsSharedPtr loadUsersInput = base->getLoadUsersInput();
//    inputEngineSharedPtr tempInputSharedPtr(new inputEngine);
//    inputE = tempInputSharedPtr;
    usersInputsVecSharedPtr tempUserInput;
    
    tempUserInput = loadUsersInput->loadUsersInputFiles();  // loads user defined input from file.
    std::string func = "UBC::setupUserInstancesInput()";
    
    logMsg(func +" load->checkIfUserInputsLoaded()");

    if (loadUsersInput->checkIfUsersInputsLoaded())
    {
        tempUserInput = loadUsersInput->getUIInstance();
        if (tempUserInput.size() > 0)
        {
            logMsg(func +" tempUserInput Loaded!");
        }
        else
        {
            logMsg(func +" tempUserInput NOT Loaded!");
        }
    }
    else
    {
        logMsg(func +" loading of User Input failed!");
        exit(false);
    }

    usersMSharedPtr tempUsersInstance;
    tempUsersInstance = base->getUsersInstance();
    size_t x = 0;
    // sets the default input for the users
    for ( auto TUIIT : tempUsersInstance)
    {
        TUIIT.second->setUserInput(tempUserInput[x]);
        TUIIT.second->setInputType(tempUserInput[x]->getType());
        ++x;
    }
    logMsg(func +" keyQuit == " +convert->toString(tempUserInput[0]->getKeyQuit()));
//    exit(0);
    base->setUsersInstance(tempUsersInstance);
    
    return (true);
}

bool UBC::setupInputSObjUserInput()  // sets up user input mapping for inputS object
{
    usersMSharedPtr tempUsersInstance;
    usersInputsVecSharedPtr tempUserInput;
    
    tempUsersInstance = base->getUsersInstance();

    
    for ( auto TUIIT : tempUsersInstance)
    {
        tempUserInput.push_back(TUIIT.second->getUserInput());
    }
    
    input->getInputGamePad()->getInputS()->setUInput(tempUserInput);
    input->getInputKeyboard()->getInputS()->setUInput(tempUserInput);

    return (true);
}

int main(int argc, char *argv[])
{
    conversionSharedPtr convert = conversion::Instance();
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

