/***************************************************************************
 *   Copyright (C) 1999 - 2019 by Mike McLean                              *
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
#include "gui/gui.h"
#include "flags/guiflags.h"
#include "load/loadbasketballs.h"
#include "load/loadusersinputs.h"
#include "entity/gameentity.h"
#include "statemachine/gamestatemachine.h"
#ifndef BTOGRE_MYGUI_ENALBED
#include "components/basketballcomponents.h"
#include "data/basketballdata.h"
#include "entity/basketballentity.h"
#include "flags/basketballflags.h"
#include "setup/setupbasketballs.h"
#include "Compositor/OgreCompositorManager2.h"
#endif
#include "ubc/ubcinput.h"
#include "users/users.h"
#include "users/usersinputs.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"


UBCGame::UBCGame()  // constructor
{
//    quitGame = false;
    startActiveGame = false;
    userInstancesCreated = false;
    numUsers = 0;
    userInstancesInputSetup = false;

    inputSUInputSetup = false;
    loadUsersInputInitialized = false;

#ifndef BTOGRE_MYGUI_ENABLED
    basketballLoaded = false;
#endif
}

UBCGame::~UBCGame() = default;  // destructor

gameEntitySharedPtr UBCGame::getGameInstance() const  // retrieves the value of gameS
{
    return (gameInstance);
}
void UBCGame::setGameInstance(const gameEntitySharedPtr &set)  // sets the value of gameS
{
    gameInstance = set;
}

networkStateSharedPtr UBCGame::getNetworkS() const  // retrieves the value of networkS
{
    return (networkS);
}
void UBCGame::setNetworkS(const networkStateSharedPtr &set)  // sets the value of networkS
{
    networkS = set;
}

UBCComponentsSharedPtr UBCGame::getUBCComponent() const  // retrieves the value of component
{
    return (UBCComponent);
}
void UBCGame::setUBCComponent(const UBCComponentsSharedPtr &set)  // sets the value of component
{
    UBCComponent = set;
}

bool UBCGame::getStartActiveGame() const  // retrieves the value of startActiveGame
{
    return (startActiveGame);
}
void UBCGame::setStartActiveGame(const bool &set)  // sets the value of startActiveGame
{
    startActiveGame = set;
}

bool UBCGame::getUsersInstancesCreated() const  // retrieves the value of userInstancesCreated
{
    return (userInstancesCreated);
}
void UBCGame::setUsersInstancesCreated(const bool &set)  // sets the value of userInstancesCreated
{
    userInstancesCreated = set;
}

bool UBCGame::getUserInstancesInputSetup() const  // retrieves the value of userInstancesInputSetup
{
    return (userInstancesInputSetup);
}
void UBCGame::setUserInstancesInputSetup(const bool &set)  // sets the value of userInstancesInputSetup
{
    userInstancesInputSetup = set;
}

loadBasketballsSharedPtr UBCGame::getLoadBasketball() const  // retrieves the value of loadBasketball
{
    return(loadBasketball);
}
void UBCGame::setLoadBasketball(const loadBasketballsSharedPtr &set)  // sets the value of loadBasketball
{
    loadBasketball = set;
}

loadCourtsSharedPtr UBCGame::getLoadCourt() const  // retrieves the value of loadCourt
{
    return (loadCourt);
}
void UBCGame::setLoadCourt(const loadCourtsSharedPtr &set)  // sets the value of loadCourt
{
    loadCourt = set;
}

loadHoopsSharedPtr UBCGame::getLoadHoop() const  // retrieves the value of loadHoop
{
    return (loadHoop);
}
void UBCGame::setLoadHoop(const loadHoopsSharedPtr &set)  // sets the value of loadHoop
{
    loadHoop = set;
}

loadOffensePlaysSharedPtr UBCGame::getLoadOffensePlay() const  // retrieves the value of loadOffensePlay
{
    return (loadOffensePlay);
}
void UBCGame::setLoadOffensePlay(const loadOffensePlaysSharedPtr &set)  // sets the value of loadOffensePlay
{
    loadOffensePlay = set;
}

loadPlayersSharedPtr UBCGame::getLoadPlayer() const  // retrieves the value of loadPlayer
{
    return (loadPlayer);
}
void UBCGame::setLoadPlayer(const loadPlayersSharedPtr &set)  // sets the value of loadPlayer
{
    loadPlayer = set;
}

loadTeamsSharedPtr UBCGame::getLoadTeam() const  // retrieves the value of loadTeam
{
    return (loadTeam);
}
void UBCGame::setLoadTeam(const loadTeamsSharedPtr &set)  // sets the value of loadTeam
{
    loadTeam = set;
}

loadUsersInputsSharedPtr UBCGame::getLoadUsersInput() const  // retrieves the value of loadUsersInput
{
    return (loadUsersInput);
}
void UBCGame::setLoadUsersInput(const loadUsersInputsSharedPtr &set)  // sets the value of loadUsersInput
{
    loadUsersInput = set;
}

usersMSharedPtr UBCGame::getUsersInstance() const  // retrieves the value of usersInstance
{
    return (usersInstance);
}
void UBCGame::setUsersInstance(const usersMSharedPtr &set)  // sets the value of usersInstance
{
    usersInstance = set;
}

bool UBCGame::getInputSUInputSetup() const  // retrieves the value of inputSUInputSetup
{
    return (inputSUInputSetup);
}
void UBCGame::setInputSUInputSetup(const bool &set)  // sets the value of inputSUInputSetup
{
    inputSUInputSetup = set;
}

size_t UBCGame::getNumUsers() const  // retrieves the value of numUsers
{
    return (numUsers);
}
void UBCGame::setNumUsers(const size_t &set)  // sets the value of numUsers
{
    numUsers = set;
}

bool UBCGame::setup()  // sets up a game instance
{
//    gameState *tempGameStateObj = new gameState;
    std::string func = "UBCGame::setup()";
    gameEntitySharedPtr tempGameInstance(new gameEntity);
    gameInstance = tempGameInstance;
    logMsg(func +" getGameS()->setInitialized(true)");
    
    if (!gameInstance->getObjectsInitialized())
    {
        logMsg(func +" Initializing objects!");
        gameInstance->setObjectsInitialized(gameInstance->initializeObjects());
    }
    else
    {
        logMsg(func +" Objects already initialized!");
    }
    /*    if (!gameInstance->getComponentInitialized())
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

    if (!gameInstance->getFlag()->getStateMachineInitialized())
    {
        gameComponentsSharedPtr tempComponent;
        tempComponent = gameInstance->getComponent();
        gameStateMachineSharedPtr tempStateMachine(new gameStateMachine);
//        tempComponent->setStateMachine(tempStateMachine);
        gameInstance->setComponent(tempComponent);
        gameInstance->getFlag()->setStateMachineInitialized(true);
    }
    else
    {
//        gameInstance->setFlagInitialized(true);
    }
*/
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
    conversionSharedPtr convert ;
    usersMSharedPtr tempUserInstance;
    std::string func = "UBCGame::createUserInstances()";

    logMsg(func +" begin");
    logMsg(func +" numUsers = " +convert->toString(numUsers));

    usersSharedPtr tempUsers(new users);
    for (size_t x=0;x<numUsers;++x)
    {
        logMsg(func +" x = " +convert->toString(x));
        std::string userName = "player" +convert->toString(x);
        logMsg(func +" " +=userName);
        tempUserInstance.insert(std::pair<size_t, usersSharedPtr>(x, tempUsers));
    }
    usersInstance = tempUserInstance;

    logMsg(func +" end");
//    exit(0);

    return (true);
}

bool UBCGame::setupUserInstancesInput()  // sets up input mapping for each user
{
    conversionSharedPtr convert ;
//    loadUsersInputsSharedPtr loadUsersInput = loadUsersInput;
//    inputEngineSharedPtr tempInputSharedPtr(new inputEngine);
//    inputE = tempInputSharedPtr;
    if (!loadUsersInputInitialized)
    {
        loadUsersInputsSharedPtr tempLoadUI(new loadUsersInputs);
        loadUsersInput = tempLoadUI;
        loadUsersInputInitialized = true;
    }

    usersInputsVecSharedPtr tempUserInput;
    tempUserInput = loadUsersInput->loadUsersInputFiles();  // loads user defined input from file.

    std::string func = "UBCGame::setupUserInstancesInput()";

    logMsg(func =" begin");

    logMsg(func +" load->checkIfUserInputsLoaded()");

    if (loadUsersInput->checkIfUsersInputsLoaded())
    {
        tempUserInput = loadUsersInput->getUIInstance();
        if (!tempUserInput.empty())
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

    logMsg(func +" end");

    return (true);
}

bool UBCGame::loop(const gameEngineSharedPtr &gameE, const UBCInputSharedPtr &input)  // Main Game Loop
{
    conversionSharedPtr convert ;
    bool quitGame = gameE->getQuitGame();
    unsigned long changeInTime = 0;
    unsigned long CITmic = 0;
    unsigned long CITmil = 0;
    std::string func = "UBCGame::loop()";
    std::chrono::microseconds changeInTimeMicro;
    std::chrono::milliseconds changeInTimeMill;
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
#ifdef BTOGRE_MYGUI_ENABLED
        input->process(gameE, gameInstance->getComponent(), gameInstance->getFlag(), usersInstance, gui);
#endif
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
        
//        exit(0);

#ifdef BTOGRE_MYGUI_ENABLED
        if (gui->getFlag()->getMenuActive())
        {
            if (gui->updateStateMachine(gameE->getRenderE()))
            {
                logMsg(func +" GUI State updated!");
            }
        
            if (gui->getFlag()->getStartActiveGame())
            {
                logMsg(func +" GUI Flag startActiveGame!");
                startActiveGame = true;
                gui->getFlag()->setStartActiveGame(false);
//            exit(0);
            }
        }
#endif

#ifndef BTOGRE_MYGUI_ENABLED
        if (!basketballLoaded)
        {
            setupBasketballs setupbasketball;
            basketballEntityMSharedPtr basketballInstance = setupbasketball.createBasketballInstances();
            basketballEntityMSharedPtr activeBasketballInstance;
            logMsg(func +" basketballInstance.size == " +convert->toString(basketballInstance.size()));
            activeBasketballInstance = setupbasketball.createActiveBasketballInstances(basketballInstance, 1);
            for (auto ABIIT : activeBasketballInstance)
            {
                OgreEntitySharedPtr model;  // stores the model returned by loadModel() function
                loaderSharedPtr load(new loader);

                logMsg(func +" begin");


                ABIIT.second->getComponent()->setModelFileName(ABIIT.second->getData()->getModelFileName());

                if (ABIIT.second->getComponent()->getName().empty())  // checks if entityName has been set
                {
                    std::string name = ABIIT.second->getData()->getName();
                    ABIIT.second->getComponent()->setName(name);
                }
                logMsg(func +" entityName == " +ABIIT.second->getComponent()->getName());
            //        exit(0);
                if (ABIIT.second->getComponent()->getNodeName().empty())  // checks if entityNodeName has been set
                {
                    std::string nodeName = ABIIT.second->getData()->getName() +"node";
                    ABIIT.second->getComponent()->setNodeName(nodeName);
                }
                logMsg(func +" basketball name == " +ABIIT.second->getData()->getName());
                logMsg(func +" basketball node name == " +ABIIT.second->getComponent()->getNodeName());
            //        exit(0);
                logMsg(func +" loading model == " +ABIIT.second->getComponent()->getModelFileName());
                std::string modelFileName = ABIIT.second->getComponent()->getModelFileName();
                std::string entityName = ABIIT.second->getComponent()->getName();
                std::string entityNodeName = ABIIT.second->getComponent()->getNodeName();

                model = load->loadModelFile(modelFileName, entityName, gameE->getRenderE());
                ABIIT.second->getFlag()->setModelLoaded(true);
                ABIIT.second->getComponent()->setModel(model);


            OgreEntitySharedPtr activeModel;
            OgreSceneNodeSharedPtr activeNode;
            std::string activeEntityName;
            std::string activeNodeNum;
            std::string activeNodeName;

                activeModel = ABIIT.second->getComponent()->getModel();
                activeEntityName = ABIIT.second->getComponent()->getName();
                activeNodeNum = convert->toString(ABIIT.second->getComponent()->getNumber());
                activeNodeName = ABIIT.second->getComponent()->getNodeName();
                if (activeNodeName.empty())
                {
                    activeNodeName = activeEntityName + activeNodeNum;
                    ABIIT.second->getComponent()->setNodeName(activeNodeName);
                }
                else
                {

                }
                activeNode = gameE->getRenderE()->createNode(activeModel, activeNodeName);  // creates node

                sharedPtr<Ogre::CompositorManager2> compositorManagerr = gameE->getRenderE()->getCompositorManager();
                compositorManagerr->addNodeDefinition(activeNodeName);
//                        ->addNodeDefinition(activeNodeName);
                gameE->getRenderE()->setCompositorManager(compositorManagerr);
                ABIIT.second->getComponent()->setNode(activeNode);  // saves node to current instance
                ABIIT.second->getComponent()->getNode()->setPosition(0.8f,-5.0f,352.0f);

            }

            basketballLoaded = true;
        }
#endif

        if (startActiveGame)
        {
//            exit(0);
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
        logMsg(func + " startGame complete!");
//        exit(0);
        
        changeInTimeMicro = gameE->getTimer().calcChangeInTimeMicro();
        changeInTimeMill = gameE->getTimer().calcChangeInTimeMill();
        CITmic = changeInTimeMicro.count();
        CITmil = changeInTimeMill.count();

        logMsg ("changeInTimeMicro = " +convert->toString(CITmic));
        logMsg ("changeInTimeMill = " +convert->toString(CITmil));
//        gameE->getTimer().setChangeInTimeMill(changeInTimeMill);
        changeInTime = changeInTimeMill.count();
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
//        exit(0);
//            logMsg("changeInTime = " +toString(changeInTime));
            if (gameE->getRenderScene())
            {
                logMsg(func +" gameS->getRenderScene()");
//                exit(0);
                gameInstance->updateState(gameE->getRenderE());  // updates the state of the game instance
            }
            gameE->getTimer().setPreviousTime(std::chrono::system_clock::now());
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

bool UBCGame::startGame(const renderEngineSharedPtr &render)  // starts the game
{
//    sharedPtr<gameState> gameS = gameState::Instance();
    std::string func = "UBCGame::startGame()";

    logMsg(func +" begin");

    

//    gameInstance->setupState(render);

    if (gameInstance->initializeStateMachine(render))
    {
        gameInstance->getFlag()->setStateMachineInitialized(true);
    }
    else
    {
        logMsg(func +" Unable to initialize gameInstance stateMachine!");
        exit(0);
    }
    
    logMsg(func +" end");
//    exit(0);
    return (true);
}

void UBCGame::processNetworkEvents(const gameEngineSharedPtr &gameE)  // processes events in the network subsyatem
{
    std::string func = "UBCGame::processNetworkEvents()";

    logMsg(func +" begin");

    if (gameE->getServerRunning())
    {
        gameE->getNetworkE()->networkServer();   // Runs network server code
    }
    if (gameE->getClientRunning())
    {
        gameE->getNetworkE()->networkClient();   // runs network client code
    }

    logMsg(func +" end");
}

#ifdef BTOGRE_MYGUI_ENABLED
void UBCGame::processPhysicsEvents(const gameEngineSharedPtr &gameE)  // processes events in the physics subsyatem
{
    std::string func = "UBCGame::processPhysicsEvents()";

    logMsg(func +" begin");

    gameE->getPhysE()->stepWorld(gameE->getTimer());

    logMsg(func +" end");
}
#endif
