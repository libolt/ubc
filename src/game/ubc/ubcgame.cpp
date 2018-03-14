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

#include "ubc/ubcgame.h"
#include "components/gamecomponents.h"
#include "data/gamedata.h"
#include "flags/gameflags.h"
#include "engine/gameengine.h"
#include "engine/physicsengine.h"
#include "engine/renderengine.h"
#include "load/loadusersinputs.h"
#include "state/gamestate.h"
#include "ubc/ubcinput.h"
#include "users/users.h"
#include "users/usersinputs.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

// static declarations
bool UBCGame::startActiveGame;  // stores whether to begin an active game instance
bool UBCGame::userInstancesCreated;  // stores whether user instances have been created
bool UBCGame::userInstancesInputSetup;  // stores status of input configuration for users
bool UBCGame::inputSUInputSetup;  // stores whether inputS UInput object has been set
size_t UBCGame::numUsers;  // stores the number of users playing the game
usersMSharedPtr UBCGame::usersInstance; // stores the user object instances
loadBasketballsSharedPtr UBCGame::loadBasketball;  // the loadBasketballs object
loadCourtsSharedPtr UBCGame::loadCourt;  // the loadCourts object
loadHoopsSharedPtr UBCGame::loadHoop;  // the loadHoops object
loadOffensePlaysSharedPtr UBCGame::loadOffensePlay;  // the loadOffensePlays Object
loadPlayersSharedPtr UBCGame::loadPlayer;  // the loadPlayers Object
loadTeamsSharedPtr UBCGame::loadTeam;  // the loadTeams Object
loadUsersInputsSharedPtr UBCGame::loadUsersInput;  // the loadUsersInputs Object
networkStateSharedPtr UBCGame::networkS;  // the networkState object

UBCGame::UBCGame()  // constructor
{
//    quitGame = false;
    startActiveGame = false;
    userInstancesCreated = false;
    numUsers = 0;
    userInstancesInputSetup = false;

    inputSUInputSetup = false;
}

UBCGame::~UBCGame()  // destructor
{

}

gameStateSharedPtr UBCGame::getGameInstance()  // retrieves the value of gameS
{
    return (gameInstance);
}
void UBCGame::setGameInstance(gameStateSharedPtr set)  // sets the value of gameS
{
    gameInstance = set;
}

networkStateSharedPtr UBCGame::getNetworkS()  // retrieves the value of networkS
{
    return (networkS);
}
void UBCGame::setNetworkS(networkStateSharedPtr set)  // sets the value of networkS
{
    networkS = set;
}

UBCComponentsSharedPtr UBCGame::getUBCComponent()  // retrieves the value of component
{
    return (UBCComponent);
}
void UBCGame::setUBCComponent(UBCComponentsSharedPtr set)  // sets the value of component
{
    UBCComponent = set;
}

bool UBCGame::getStartActiveGame()  // retrieves the value of startActiveGame
{
    return (startActiveGame);
}
void UBCGame::setStartActiveGame(bool set)  // sets the value of startActiveGame
{
    startActiveGame = set;
}

bool UBCGame::getUsersInstancesCreated()  // retrieves the value of userInstancesCreated
{
    return (userInstancesCreated);
}
void UBCGame::setUsersInstancesCreated(bool set)  // sets the value of userInstancesCreated
{
    userInstancesCreated = set;
}

bool UBCGame::getUserInstancesInputSetup()  // retrieves the value of userInstancesInputSetup
{
    return (userInstancesInputSetup);
}
void UBCGame::setUserInstancesInputSetup(bool set)  // sets the value of userInstancesInputSetup
{
    userInstancesInputSetup = set;
}

loadBasketballsSharedPtr UBCGame::getLoadBasketball()  // retrieves the value of loadBasketball
{
    return(loadBasketball);
}
void UBCGame::setLoadBasketball(loadBasketballsSharedPtr set)  // sets the value of loadBasketball
{
    loadBasketball = set;
}

loadCourtsSharedPtr UBCGame::getLoadCourt()  // retrieves the value of loadCourt
{
    return (loadCourt);
}
void UBCGame::setLoadCourt(loadCourtsSharedPtr set)  // sets the value of loadCourt
{
    loadCourt = set;
}

loadHoopsSharedPtr UBCGame::getLoadHoop()  // retrieves the value of loadHoop
{
    return (loadHoop);
}
void UBCGame::setLoadHoop(loadHoopsSharedPtr set)  // sets the value of loadHoop
{
    loadHoop = set;
}

loadOffensePlaysSharedPtr UBCGame::getLoadOffensePlay()  // retrieves the value of loadOffensePlay
{
    return (loadOffensePlay);
}
void UBCGame::setLoadOffensePlay(loadOffensePlaysSharedPtr set)  // sets the value of loadOffensePlay
{
    loadOffensePlay = set;
}

loadPlayersSharedPtr UBCGame::getLoadPlayer()  // retrieves the value of loadPlayer
{
    return (loadPlayer);
}
void UBCGame::setLoadPlayer(loadPlayersSharedPtr set)  // sets the value of loadPlayer
{
    loadPlayer = set;
}

loadTeamsSharedPtr UBCGame::getLoadTeam()  // retrieves the value of loadTeam
{
    return (loadTeam);
}
void UBCGame::setLoadTeam(loadTeamsSharedPtr set)  // sets the value of loadTeam
{
    loadTeam = set;
}

loadUsersInputsSharedPtr UBCGame::getLoadUsersInput()  // retrieves the value of loadUsersInput
{
    return (loadUsersInput);
}
void UBCGame::setLoadUsersInput(loadUsersInputsSharedPtr set)  // sets the value of loadUsersInput
{
    loadUsersInput = set;
}

usersMSharedPtr UBCGame::getUsersInstance()  // retrieves the value of usersInstance
{
    return (usersInstance);
}
void UBCGame::setUsersInstance(usersMSharedPtr set)  // sets the value of usersInstance
{
    usersInstance = set;
}

bool UBCGame::getInputSUInputSetup()  // retrieves the value of inputSUInputSetup
{
    return (inputSUInputSetup);
}
void UBCGame::setInputSUInputSetup(bool set)  // sets the value of inputSUInputSetup
{
    inputSUInputSetup = set;
}

size_t UBCGame::getNumUsers()  // retrieves the value of numUsers
{
    return (numUsers);
}
void UBCGame::setNumUsers(size_t set)  // sets the value of numUsers
{
    numUsers = set;
}

bool UBCGame::setup()  // sets up a game instance
{
//    gameState *tempGameStateObj = new gameState;
    std::string func = "UBCGame::setup()";

    gameStateSharedPtr tempGameStateSharedPtr(new gameState);
    gameInstance = tempGameStateSharedPtr;
    logMsg(func +" getGameS()->setInitialized(true)");
    if (!gameInstance->getComponentInitialized())
    {
        gameComponentsSharedPtr tempComponent(new gameComponents);
        gameInstance->setComponent(tempComponent);
        gameInstance->setComponentInitialized(true);
    }
    else
    {
        gameInstance->setComponentInitialized(true);
    }

    if (!gameInstance->getDataInitialized())
    {
        gameDataSharedPtr tempData(new gameData);
        gameInstance->setData(tempData);
        gameInstance->setDataInitialized(true);
    }
    else
    {
        gameInstance->setDataInitialized(true);
    }
    if (!gameInstance->getFlagInitialized())
    {
        gameFlagsSharedPtr tempFlag(new gameFlags);
        gameInstance->setFlag(tempFlag);
        gameInstance->setFlagInitialized(true);
    }
    else
    {
        gameInstance->setFlagInitialized(true);
    }

    getGameInstance()->getFlag()->setInitialized(true);

/*    for (size_t x=0;x<numUsers;++x)
    {
        usersSharedPtr tempUser(new users);
        usersInstance.insert(std::pair<size_t, usersSharedPtr>(x,tempUser));
    }
*/
    return (true);
}

bool UBCGame::createUserInstances()  // creates the user instances
{
    conversionSharedPtr convert = conversion::Instance();
    usersMSharedPtr tempUserInstance;
    std::string func = "UBC::createUserInstances()";

    logMsg(func +" begin");

    size_t x = 0;

    usersSharedPtr tempUsers(new users);
    for (x=0;x<numUsers;++x)
    {
       std::string userName = "player" +convert->toString(x);
       logMsg(func +" " +userName);
       tempUserInstance.insert(std::pair<size_t, usersSharedPtr>(x, tempUsers));
    }
    usersInstance = tempUserInstance;

    logMsg(func +" end");
//    exit(0);

    return (true);
}

bool UBCGame::setupUserInstancesInput()  // sets up input mapping for each user
{
    conversionSharedPtr convert = conversion::Instance();
//    loadUsersInputsSharedPtr loadUsersInput = loadUsersInput;
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
    tempUsersInstance = usersInstance;
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
    usersInstance = tempUsersInstance;

    return (true);
}

bool UBCGame::loop(gameEngineSharedPtr gameE, UBCInputSharedPtr input, GUISystemSharedPtr gui)  // Main Game Loop
{
    conversionSharedPtr convert = conversion::Instance();
    bool quitGame = gameE->getQuitGame();
    unsigned long changeInTime = 0;
    unsigned long CITmic = 0;
    unsigned long CITmil = 0;
    std::string func = "UBC::gameLoop()";
    boost::chrono::microseconds changeInTimeMicro;
    boost::chrono::milliseconds changeInTimeMill;
/*    playerStateMachine playerSM;
    playerSMData *playerSMD = new playerSMData;
    playerSMData *playerSMD2 = new playerSMData;
    playerSMData *playerSMD3 = new playerSMData;
*/
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
        input->process(gameE, gameInstance->getComponent(), gameInstance->getFlag(), usersInstance, gui);
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

        if (startActiveGame)
        {
            if (startGame(gameE->getRenderE()))
            {
                gameE->setStart(false);
                gameE->setRenderScene(true);
                startActiveGame = false;
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
            if (gameInstance->getData()->getGameType() == MULTINET)
            {
                processNetworkEvents(gameE);
            }

//            logMsg("changeInTime = " +toString(changeInTime));
            if (gameE->getRenderScene())
            {
                logMsg(func +" gameS->getRenderScene()");
                
                gameInstance->updateState(gameE->getRenderE());  // updates the state of the game instance
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
}

bool UBCGame::startGame(renderEngineSharedPtr render)  // starts the game
{
//    sharedPtr<gameState> gameS = gameState::Instance();
    std::string func = "UBC::startGame()";

    logMsg(func +" begin");

//    exit(0);
//BASEREMOVAL    gameInstance->setBase(base);
    gameInstance->setupState(render);

    logMsg(func +" end");
//    exit(0);
    return (true);
}

void UBCGame::processNetworkEvents(gameEngineSharedPtr gameE)  // processes events in the network subsyatem
{
    if (gameE->getServerRunning())
    {
        gameE->getNetworkE()->networkServer();   // Runs network server code
    }
    if (gameE->getClientRunning())
    {
        gameE->getNetworkE()->networkClient();   // runs network client code
    }
}

void UBCGame::processPhysicsEvents(gameEngineSharedPtr gameE)  // processes events in the physics subsyatem
{
    gameE->getPhysE()->stepWorld(gameE->getTimer());
}
