/***************************************************************************
 *   Copyright (C) 1999 - 2018 by Mike McLean                              *
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
#include "components/ubccomponents.h"
#include "data/gamedata.h"
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

UBC::UBC()  // constructor
{


}

UBC::~UBC()  // destructor
{

}


UBCComponentsSharedPtr UBC::getComponent()  // retrieves the value of component
{
    return (component);
}
void UBC::setComponent(UBCComponentsSharedPtr set)  // sets the value of component
{
    component = set;
}

bool UBC::setup()  // sets up UBC object
{
    std::string func = "UBC::setup()";

    UBCComponentsSharedPtr tempComponent(new UBCComponents);
    component = tempComponent;
    //    gameEngine *tempGameEObj = new gameEngine;
    gameEngineSharedPtr tempGameESharedPtr(new gameEngine);
    component->setGameE(tempGameESharedPtr);
//    gameE(new gameEngine);
    logMsg(func +" gameE->setup()");
    component->getGameE()->setup();  // sets up the game engine
    
    logMsg(func +" begin");

    GUISystemSharedPtr tempGUISharedPtr(new GUISystem);
    component->setGui(tempGUISharedPtr);
    
    component->getGui()->setGameE(component->getGameE());
    
    // setup game object
    UBCGameSharedPtr tempGameSharedPtr(new UBCGame);

    component->setGame(tempGameSharedPtr);
    component->getGame()->setUBCComponent(component);
    
    // setup input object
    UBCInputSharedPtr tempInputSharedPtr(new UBCInput);
    component->setInput(tempInputSharedPtr);
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
    if (component->getGui()->setup(component->getGameE()->getRenderE()))  // sets up the game GUI
    {
        component->getGui()->setGameInstance(component->getGame()->getGameInstance());  // shares gameInstance with gui object
//        exit(0);
        component->getGui()->getFlag()->setSetupComplete(true);
//        exit(0);
        component->getGui()->mainMenu(component->getGameE()->getRenderE());
//        exit(0);
        component->getGui()->backButtons();
    }
    else
    {
        logMsg(func +" Unable to setup GUI!");
        exit(0);
    }
    
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

    logMsg(func +" begin");

//    exit(0);
//    base->setup();
    component->getGame()->setup();
    component->getGameE()->getRenderE()->initSDL(); // Initializes the SDL Subsystem
//    exit(0);
    component->getGameE()->getRenderE()->initOgre(); // Initializes the Ogre Subsystem
//    exit(0);
    component->getGameE()->getRenderE()->createScene(); // creates rendering scene.

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

    if (component->getGameE()->getRenderE()->getMWindow() == NULL)
    {
        logMsg(func +" mWindow == NULL!");
//        exit(0);
    }
//    exit(0);
//    setupState();  // sets up the game state

    sharedPtr<Ogre::Viewport> vp = component->getGameE()->getRenderE()->getViewPort();
//    setViewPort(*vp);  // sets the viewPort for MyGUI

//    exit(0);
    
    //FIXME! Hard coded until code is restructured
    component->getGame()->setNumUsers(1);
    
    logMsg(func + " Creating Users Instances!");
    if (!component->getGame()->getUsersInstancesCreated())
    {
        if (component->getGame()->createUserInstances())
        {
            component->getGame()->setUsersInstancesCreated(true);
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
    if (component->getGame()->getUsersInstancesCreated() && !component->getGame()->getUserInstancesInputSetup())
    {
        if (component->getGame()->setupUserInstancesInput())
        {
            component->getGame()->setUserInstancesInputSetup(true);
        }
        else
        {
            
        }
    }
    else
    {
        
    }
    
    logMsg(func +" Setting up input object");
    if (!component->getInput()->getSetupComplete())
    {
        logMsg(func +" setting up UBCInput object");
        if (component->getInput()->setup())
        {
            logMsg(func +" Input setup!");
            component->getInput()->setSetupComplete(true);
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
       
    component->getGame()->loop(component->getGameE(), component->getInput(), component->getGui());

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

    logMsg(func +" begin");
    
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
        
///        if (gameInstance->getSetupComplete())  // checks to make sure game setup is complete before continuing
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
    bool quitGame = component->getGameE()->getQuitGame();
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

        if (gameInstance->getFlag()->getSetupComplete())  // checks to make sure game setup is complete before continuing
        {
//            exit(0);
            if (!component->getGameE()->getSceneCreated())
            {
                
                if (gameInstance->getData()->getGameType() == SINGLE)
                {
                    component->getGameE()->setCreateScene(true);
                    exit(0);
                }
                else if (gameInstance->getData()->getGameType() == MULTINET)
                {
                    if (component->getGameE()->getNetworkE()->getServerReceivedConnection() || component->getGameE()->getNetworkE()->getClientEstablishedConnection())  // checks if server and client are connected
                    {
                        component->getGameE()->setCreateScene(true);
                    }
    //             exit(0);
                }
            }
        }
//        exit(0);
        if (component->getGameE()->getCreateScene())  // checks if the scene should be created
        {
//            exit(0);
//              if (render->createScene())
//            {
                component->getGameE()->setCreateScene(false);
                component->getGameE()->setStart(true);
//                  renderScene = true;
                component->getGameE()->setSceneCreated(true);
//            }
        }
//        exit(0);
//        if (component->getGameE()->getStart())  // checks if it's time to start the game
//        {
//            exit(0);
/*            if (startGame())
            {
                component->getGameE()->setStart(false);
                component->getGameE()->setRenderScene(true);
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
        if (component->getGameE()->getServerRunning() && !component->getGameE()->getNetworkE()->getIsServer())
        {
            component->getGameE()->getNetworkE()->setIsServer(true);
        }
        if (component->getGameE()->getClientRunning() && !component->getGameE()->getNetworkE()->getIsClient())
        {
            component->getGameE()->getNetworkE()->setIsClient(true);
        }

        if (gameInstance->getData()->getGameType() == MULTINET && component->getGameE()->getNetworkE()->getTeamType() == NOTEAM)
        {
            if (component->getGameE()->getNetworkE()->getIsServer())
            {
                component->getGameE()->getNetworkE()->setTeamType(HOMETEAM);
            }
            
            if (component->getGameE()->getNetworkE()->getIsClient())
            {
                component->getGameE()->getNetworkE()->setTeamType(AWAYTEAM);
            }
        }
        
        logMsg("serverRunning = " +component->getGameE()->getServerRunning());
        logMsg("clientRunning = " +component->getGameE()->getClientRunning());
        boost::chrono::microseconds changeInTimeMicro = component->getGameE()->getTimer().calcChangeInTimeMicro();
        
        boost::chrono::milliseconds changeInTimeMill = component->getGameE()->getTimer().calcChangeInTimeMill();
        changeInTime = component->getGameE()->getTimer().getChangeInTimeMill().count();
        logMsg ("loopchange = " +convert->toString(changeInTime));
//        exit(0);
        if (changeInTime >= 10)
        {
//              exit(0);
            if (component->getGameE()->getServerRunning())
            {
                component->getGameE()->getNetworkE()->networkServer();   // Runs network server code
                
            }
            if (component->getGameE()->getClientRunning())
            {
                component->getGameE()->getNetworkE()->networkClient();   // runs network client code
            }


//            logMsg("changeInTime = " +toString(changeInTime));
            if (component->getGameE()->getRenderScene())
            {
                logMsg("gameS->updateState()");
                gameInstance->updateState(component->getGameE()->getRenderE());  // updates the state of the game instance
            }
            
            //boost::chrono::system_clock::time_point newT = boost::chrono::system_clock::now();
            //boost::chrono::milliseconds milliSecs = boost::chrono::duration_cast<boost::chrono::milliseconds>(newT);
            //oldTime = milliSecs.count();
            component->getGameE()->getTimer().setPreviousTime(boost::chrono::system_clock::now());
        }
//        exit(0);
//        input->process(gameE, gameInstance);
//        exit(0);
        if (!component->getGameE()->getRenderE()->renderFrame())
        {
            logMsg("Unable to render frame!");
            exit(0);
        }
    }

}

bool UBC::updateGUI()  // updates the gui based on received events
{
    std::string func = "UBC::updateGUI()";

    logMsg(func +" begin");

//    GUISystemSharedPtr gui = base->getGui();
    if (component->getGameE()->getInputE()->getMouseClicked())
    {
        logMsg(func +" updateGUI Mouse Clicked!");
        exit(0);
        component->getGui()->getMGUI()->injectMousePress(component->getGameE()->getInputE()->getMouseX(), component->getGameE()->getInputE()->getMouseY(), MyGUI::MouseButton::Enum(0));
    }
    else
    {
        component->getGui()->getMGUI()->injectMouseRelease(component->getGameE()->getInputE()->getMouseX(), component->getGameE()->getInputE()->getMouseY(), MyGUI::MouseButton::Enum(0));
    }
//    base->setGui(gui);

    logMsg(func +" end");

    return (true);
}



bool UBC::setupInputSObjUserInput()  // sets up user input mapping for inputS object
{
    usersMSharedPtr tempUsersInstance;
    usersInputsVecSharedPtr tempUserInput;
    
    tempUsersInstance = component->getGame()->getUsersInstance();

    
    for ( auto TUIIT : tempUsersInstance)
    {
        tempUserInput.push_back(TUIIT.second->getUserInput());
    }
    
    component->getInput()->getInputGamePad()->getInputInstance()->setUInput(tempUserInput);
    component->getInput()->getInputKeyboard()->getInputInstance()->setUInput(tempUserInput);

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

    logMsg(func +" begin");

//    exit(0);
    ubc->setup();
//    exit(0);
    ubc->run();
//    exit(0);
    logMsg(func +" end");


//    atexit(SDL_Quit);

	return (0);
}

