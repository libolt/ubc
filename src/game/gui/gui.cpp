/***************************************************************************
 *   Copyright (C) 1999 - 2019 by Mike McLean                              *
 *   libolt@libolt.net                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms oh.f   the GNU General Public License as published by  *
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
 *   Free Software F oundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#include "engine/networkengine.h"

#include "gui/gui.h"
#include "gui/guicreate.h"
#include "gui/guidata.h"
#include "gui/guidisplay.h"
#include "gui/guievents.h"
#include "gui/guiinput.h"
#include "utilities/conversion.h"
#include "components/gamecomponents.h"
#include "components/guicomponents.h"
#include "components/teamcomponents.h"
#include "data/courtdata.h"
#include "data/gamedata.h"
#include "data/playerdata.h"
#include "engine/gameengine.h"
#include "flags/gameflags.h"
#include "entity/playerentity.h"
#include "entity/teamentity.h"
#include "setup/setuplineups.h"
#include "setup/setupplayers.h"
#include "setup/setupteams.h"
#include "statemachine/guistatemachine.h"
#include "entity/courtentity.h"
#include "entity/gameentity.h"
#include "load/load.h"
#include "utilities/logging.h"
#include "engine/renderengine.h"
#include "data/teamdata.h"
#include "utilities/enums.h"

#ifdef __ANDROID__
#include "utilities/android-config.h"
#else
#include "config.h"
#endif

GUISystem::GUISystem()  // Initialmizes the GUISystem class
{

    //activeMenu = nullptr;mm
    
    objectsInitialized = false;
    

}

GUISystem::~GUISystem() = default;  // destructor

bool GUISystem::getObjectsInitialized() const  // retrieves the value of objectsInitialized
{
    return (objectsInitialized);
}
void GUISystem::setObjectsInitialized(const bool &set)  // sets the value of objectsInitialized
{
    objectsInitialized = set;
}

guiComponentsSharedPtr GUISystem::getComponent() const  // retrieves the value of component
{
    return (component);
}
void GUISystem::setComponent(const guiComponentsSharedPtr &set)  // sets the value of component
{
    component = set;
}

guiCreateSharedPtr GUISystem::getCreate() const  // retrieves the value of create
{
    return (create);
}
void GUISystem::setCreate(const guiCreateSharedPtr &set)  // sets the value of create
{
    create = set;
}

guiDataSharedPtr GUISystem::getData() const  // retrieves the value of data
{
    return (data);
}
void GUISystem::setData(const guiDataSharedPtr &set)  // sets the value of data
{
    data = set;
}

guiDisplaySharedPtr GUISystem::getDisplay() const  // retrieves the value of display
{
    return (display);
}
void GUISystem::setDisplay(const guiDisplaySharedPtr &set)  // sets the value of display
{
    display = set;
}

guiEventsSharedPtr GUISystem::getEvent() const  // retrieves the value of event
{
    return (event);
}
void GUISystem::setEvent(const guiEventsSharedPtr &set)  // sets the value of event
{
    event = set;
}

guiFlagsSharedPtr GUISystem::getFlag() const  // retrieves the value of flag
{
    return (flag);
}
void GUISystem::setFlag(const guiFlagsSharedPtr &set)  // sets the value of flag
{
    flag = set;
}

guiInputSharedPtr GUISystem::getInput() const  // retrieves the value of input
{
    return (input);
}
void GUISystem::setInput(const guiInputSharedPtr &set)  // sets the value of input
{
    input = set;
}

guiStateMachineSharedPtr GUISystem::getStateMachine() const  // retrieves the value of stateMachine
{
    return (stateMachine);
}
void GUISystem::setStateMachine(const guiStateMachineSharedPtr &set)  // sets the value of stateMachine
{
    stateMachine = set;
}

gameEngineSharedPtr GUISystem::getGamE() const  // retrieves the value of gameE
{
    return (gameE);
}
void GUISystem::setGameE(const gameEngineSharedPtr &set)  // sets the value of gameE
{
    gameE = set;
}

gameEntitySharedPtr GUISystem::getGameInstance() const  // retrieves the value of teamInstance
{
    return (gameInstance);
}
void GUISystem::setGameInstance(const gameEntitySharedPtr &set)  // sets the value of teamInstance
{
    gameInstance = set;
}


/*activeMenus GUISystem::getActiveMenu() const  // retrieves the value of activeMenu
{
	return (activeMenu);
}
void GUISystem::setActiveMenu(const activeMenus &set)  // sets the value of activeMenu
{
	activeMenu = set;
}

activeMenus GUISystem::getPreviousActiveMenu() const  // retrieves the value of previousActiveMenu
{
	return (previousActiveMenu);
}
void GUISystem::setPreviousActiveMenu(const activeMenus &set)  // sets the value of previousActiveMenu
{
	previousActiveMenu = set;
}
*/

bool GUISystem::initializeObjects(const renderEngineSharedPtr &render)  // initializes gui objects
{

    std::string func = "GUISystem::initializeObjects()";
    
    logMsg(func +" begin");
    
    guiFlagsSharedPtr tempFlag(new guiFlags);
    flag = tempFlag;

    guiComponentsSharedPtr tempComponent(new guiComponents);
    component = tempComponent;
    component->setInitialized(true);
    
    component->setGameE(gameE);

    if (component->initMyGUI(gameE->getRenderE())) // Initializes MyGUI
//    if (data->component->initMyGUI(data->render)) // Initializes MyGUI
    {
        logMsg (func +" MyGUI initialized successfully!");
        component->setMyguiInitialized(true);
//        exit(0);
    }
    else
    {
        logMsg(func +" Unable to initialize MyGUI!");
        exit(0);
    }
    
    guiInputSharedPtr tempInput(new guiInput);
    input = tempInput;
    input->setComponent(component);
    input->setFlag(flag);
    input->setGameInstance(gameInstance);

    guiCreateSharedPtr tempCreate(new guiCreate);
    create = tempCreate;
    create->setComponent(component);
    create->setFlag(flag);
    create->setInput(input);

    guiDataSharedPtr tempData(new guiData);
    data = tempData;
    data->setComponent(component);
    data->setFlag(flag);
    data->setGameInstance(gameInstance);
    
    guiDisplaySharedPtr tempDisplay(new guiDisplay);
    display = tempDisplay;
    display->setComponent(component);
    display->setFlag(flag);
    display->setGameE(gameE);
    display->setInitialized(true);

    guiStateMachineSharedPtr tempStateMachine(new guiStateMachine);
    stateMachine = tempStateMachine;
    
    guiEventsSharedPtr tempEvent(new guiEvents);
    event = tempEvent;
    event->setComponent(component);
    event->setCreate(create);
    event->setData(data);
    event->setDisplay(display);
    event->setFlag(flag);
    event->setStateMachine(stateMachine);
    event->setGameE(gameE);
    event->setGameInstance(gameInstance);

    logMsg(func +" end");

    return (true);
}


bool GUISystem::initializeStateMachine(const renderEngineSharedPtr &render)  // initializes gui stateMachine
{
    std::string func = "GUISystem::initializeStateMachine()";
    
    logMsg(func +" begin");
  
    if (!objectsInitialized)
    {
        logMsg(func +" Initializing objects!");
        objectsInitialized = initializeObjects(render);
    }
    else
    {
        logMsg(func +" Objects already initialized!");
    }
    
    
    guiSMData *initSMData(new guiSMData);
    
    initSMData->component = component;
    initSMData->create = create;
    initSMData->display = display;
    initSMData->flag = flag;
    initSMData->render = render;
    
    stateMachine->pInitialize(initSMData);
    
    logMsg(func +" end");

}

bool GUISystem::updateStateMachine(const renderEngineSharedPtr &render)  // updates gui stateMachine
{
    bool retVal = false;
    std::string func = "GUISystem::updateStateMachine()";
    
    logMsg(func +" begin");
  
    if (flag->getMenuActive())
    {
        logMsg(func +" menuActive!");
        
        if (flag->getChangeMenu())
        {
            
            switch (component->getActiveMenu())
            {
                case MAIN:
                    event->checkMainMenuSelects();
                break;
                case COURTSELECT:                    
                    event->checkCourtMenuSelects();
                break;
                case PLAYERSTART:
                    event->checkStartersMenuSelects();
                break;
                case TEAMSELECT:                  
                    event->checkTeamMenuSelects();
                break;
            }
            flag->setChangeMenu(false);
        }
    }
    guiSMData *uSMData(new guiSMData);
    logMsg(func +" end");
    
    return (retVal);
}


/*void GUISystem::mainMenu(const renderEngineSharedPtr &render)  // msin in game menu
{
//    exit(0);
    std::string func = "GUISystem::mainMenu()";
    
    logMsg(func + " beginning");
    

    if (!flag->getMainMenuCreated())
    {
        logMsg(func + " mainMenu not created yet!");
//        exit(0);
        if (createMainMenuGUI(render)) // creates the main menu gui.
        {
            logMsg(func + " Main Menu created successfully!");
            flag->setMainMenuCreated(true);
//            exit(0);
        }
        else
        {
            logMsg(func + " Unable to create Main Menu!");
            exit(0);
        }
    }
    else
    {
        
    }
    showMainMenuWidgets();  // displays main menu
    logMsg(func +" begin");

    activeMenu = MAIN;
    
    logMsg(func + " end");
    
//    exit(0);
}*/

void GUISystem::backButtons()  // handles the back buttons
{

    if (!flag->getBackButtonsCreated())
    {
        logMsg("Back buttons not created yet!");
/*        if (createBackButtons()) // creates the back buttons.
        {
            logMsg("Back Buttons created successfully!");
            backButtonsCreated = true;
//                exit(0);
        }
        else
        {
            logMsg("Unable to create Bsck Buttons!");
//            return (false);
            exit(0);
        }*/
    }
    else
    {
        
    }

}

/*void GUISystem::startSinglePlayerGame(const renderEngineSharedPtr &render)  // starts single player game
{
//    sharedPtr<gameState> gameS = gameState::Instance();
//    exit(0);
//    gameS->setGameType(SINGLE);
    
    std::string func = "GUISystem::startSinglePlayerGame()";

    gameInstance->getData()->setGameType(SINGLE);
    courtSelectionMenu(render);   // displays the menu for selecting which court to use
    //   setupMenu();
//	menuActive = false;
    
    logMsg(func +" end");
}
*/

void GUISystem::startMultiPlayerGame(const renderEngineSharedPtr &render)  // starts multiplayer game
{
    if (!flag->getNetworkSetupMenuCreated())
    {
        create->createNetworkSetupGUI(render);  // creates the GUI for the Network Setup Screen
    }

    display->changeActiveMenu(NETWORK, render);
}

void GUISystem::optionsMenu(const renderEngineSharedPtr &render)  // displays options menu
{
    if (!flag->getOptionsMenuCreated())
    {
        createOptionsMenuGUI(render);
    }

    display->changeActiveMenu(OPTIONS, render);
}

void GUISystem::displayMenu(const renderEngineSharedPtr &render)  // displays display menu
{
    if (!flag->getDisplaySetupMenuCreated())
    {
        createDisplaySetupGUI();
    }

    display->changeActiveMenu(DISPLAY, render);
}

void GUISystem::inputMenu(const renderEngineSharedPtr &render)  // displays the input menu
{
    if (!flag->getInputSetupMenuCreated())
    {
        createInputSetupGUI();
    }

    display->changeActiveMenu(INPUTMENU, render);
}
void GUISystem::audioMenu(const renderEngineSharedPtr &render)  // displays the audio menu
{
    if (!flag->getAudioSetupMenuCreated())
    {
        createAudioSetupGUI();
    }

    display->changeActiveMenu(AUDIO, render);
}

void GUISystem::setupMenu(const renderEngineSharedPtr &render)  // displays game setup menu
{
    if (!flag->getSetupMenuCreated())
    {
        createSetupMenuGUI();
        flag->setSetupMenuCreated(true);
    }
	
    display->changeActiveMenu(GAMESETUP, render);
}

/*void GUISystem::playerStartSelectionMenu(const renderEngineSharedPtr &render)  // displays player start selection menu
{
    std::string func = "GUISystem::playerStartSelectionMenu()";
    
    logMsg(func +" begin");
    

    if (!flag->getPlayerStartSelectionMenuCreated())
    {
        logMsg(func +" !playerStartSelectionMenuCreated");
//         exit(0);
        
        if (createPlayerStartSelectionMenuGUI(render))
        {
            logMsg(func +" createPlayerStartSelectionMenuGUI!");
            flag->setPlayerStartSelectionMenuCreated(true);
        }
        else
        {
            logMsg(func +" Unable to create playerStartSelectionMenu!!");
            exit(0);
        }       
//        exit(0);
    }
    else
    {       
    }
    
    addPlayerStartSelectionMenuData();

//    exit(0);
    setSelectedIndexes();
    display->changeActiveMenu(PLAYERSTART, render);
    
    logMsg(func +" end");
//    exit(0);
}
*/

/*void GUISystem::teamSelectionMenu(const renderEngineSharedPtr &render)  // displays team selection menu
{
    conversionSharedPtr convert ;
    setupTeamsSharedPtr setupTeam(new setupTeams);
    bool changeMenu = false;  // determinrs if menu is to be changed
    teamEntityMSharedPtr teamInstance; // = gameS->getTeamDataInstance();
    std::string func = "GUISystem::teamSelectionMenu()";
    logMsg(func +" begin");

//    teamInstance = load->loadTeams();
//    exit(0);
    if (flag->getTeamSelectionMenuCreated())
    {      
        logMsg(func +" teamSelectionMenuCreated");
        exit(0);
        if (gameInstance->getFlag()->getTeamInstancesCreated())
        {
            logMsg(func +" getTeamInstancesCreated");
//            exit(0);
            if (flag->getTeamSelectionMenuDataAdded())
            {
                logMsg(func +" Team Selection Menu Data Added already!");
                changeMenu = true;
            }
            else
            {
                if (addTeamStartSelectionMenuData())
                {
                    flag->setTeamSelectionMenuDataAdded(true);
                    changeMenu = true;
                   
                }
                else
                {
                    logMsg(func +" Unable to add data to Team Selection Menus!");
                    exit(0);
                }
            }
        }
        else
        {
            logMsg(func +" !getTeamInstancesCreated");
            
            teamInstance = setupTeam->createTeamInstances();  // creates team instances
            if (!teamInstance.empty())
            {
                logMsg(func +" createTeamInstances");

//                exit(0);
                gameInstance->getFlag()->setTeamInstancesCreated(true);
                if (flag->getTeamSelectionMenuDataAdded())
                {
                    logMsg(func +" Team Selection Menu Data Added already!");
                    changeMenu = true;
                }
                else
                {
                    if (addTeamStartSelectionMenuData())
                    {
                        flag->setTeamSelectionMenuDataAdded(true);
                        changeMenu = true;
                    }
                    else
                    {
                        logMsg(func +" Unable to add data to Team Selection Menus!");
                        exit(0);
                    }
                }
            }
            else
            {
                logMsg(func +" feeerrrrappp!");
                exit(0);
            }
        }
    }
    else
    {
        logMsg(func +" teamSelectionMenuGUI Not Yet Created!");
        
        if (createTeamSelectionMenuGUI(render))
        {            
            flag->setTeamSelectionMenuCreated(true);
            
            if (addTeamStartSelectionMenuData())
            {
                
                logMsg(func +" addTeamStartSelectionMenuData()!");
                logMsg(func +" teamInstance.size() == " +convert->toString(gameInstance->getComponent()->getTeamInstance().size()));
//                exit(0);
                flag->setTeamSelectionMenuDataAdded(true);
                changeMenu = true;
            }
            else 
            {
                logMsg(func +" Unable to add data to Team Selection Menus!");
                exit(0);
            }
        }
        else
        {
            logMsg(func +" Unable to create Team Selection Menu!");
            exit(0);
        }
    }
    
//    hideCourtSelectionMenuWidgets();
    if (changeMenu)
    {
        logMsg(func +" Changing activeMenu to TEAMSELECT!");
//        exit(0);
        display->changeActiveMenu(TEAMSELECT, render);
    }
    else
    {
        logMsg(func +" Failed to change activeMenu to TEAMSELECT!");
        exit(0);
    }

    logMsg(func +" teamInstance.size() == " +convert->toString(gameInstance->getComponent()->getTeamInstance().size()));
//    exit(0);
    
    logMsg(func +" end");

//    exit(0);

}
*/

/*void GUISystem::courtSelectionMenu(const renderEngineSharedPtr &render) // displays court selection menu
{
//    sharedPtr<gameState> gameS = gameState::Instance();
    conversionSharedPtr convert ;
//    sharedPtr<loader> load; // = loader::Instance();
    std::string func = "GUISystem::courtSelectionMenu()";
    
    logMsg(func +" begin");
    
    
    if (!flag->getCourtSelectionMenuCreated())
    {
        createCourtSelectionMenuGUI(render);
    }
//    exit(0);
    if (!flag->getCourtSelectionDataLoaded())
    {
//        exit(0);
        logMsg("addCourtSelectionMenuData = " +convert->toString(addCourtSelectionMenuData()));
//        exit(0);
        if (addCourtSelectionMenuData())
        {
//            exit(0);
            component->getCourtSelectBox()->setIndexSelected(0);
            flag->setCourtSelectionDataLoaded(true);
        }
        else
        {
            exit(0);

        }
//        exit(0);
    }

    display->changeActiveMenu(COURTSELECT, render);
//    exit(0);
    
    logMsg(func +" end");
}
*/


/*void GUISystem::networkClientSetupMenu(const renderEngineSharedPtr &render) // sets up the client connection
{
    if (!flag->getNetworkClientSetupMenuCreated())
    {
        createNetworkClientSetupGUI(render);
    }
    display->changeActiveMenu(NETWORKCLIENT, render);
    MyGUI::InputManager::getInstance().setKeyFocusWidget(component->getClientIPAddressBox().get());
//    mGUI::InputManager->getInstance().setKeyFocusWidget(component->getClientIPAddressBox());
}

void GUISystem::networkServerSetupMenu(const renderEngineSharedPtr &render)  // sets up the networkServer instance
{
    if (!flag->getNetworkServerSetupMenuCreated())
    {
        createNetworkServerSetupGUI(render);
    }

    display->changeActiveMenu(NETWORKSERVER, render);
    MyGUI::InputManager::getInstance().setKeyFocusWidget(component->getServerIPAddressBox().get());

}
*/

void GUISystem::networkServer()  // sets up  game as a network server
{
    //networkEngine * network = networkEngine::Instance();
//    networkEngineSharedPtr network = networkEngine::Instance();
    //gameEngine * gameE = gameEngine::Instance();
//    sharedPtr<gameEngine> gameE = gameEngine::Instance();
    //gameState *gameS = gameState::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();

//    gameS->setGameType(MULTI);
    gameInstance->getData()->setGameType(MULTINET);
//   hideNetworkSetupWidgets();  // Hides Network Setup Menu widgets
    flag->setMenuActive(false);
    gameE->getNetworkE()->setIPAddress(component->getServerIPAddressBox()->getCaption());  // sets the neworkEngine's ipAddress string to that of the caption
    logMsg("server ip = " +gameE->getNetworkE()->getIPAddress());
    if (gameE->getNetworkE()->serverSetup())  // attempts to setup as a network server
    {
        gameE->getNetworkE()->setIsServer(true);  // if successful sets isServer to true
    }

//    gameE->setCreateScene(true); // sets variable true that tells gameEngine to start rendering the scene

}
void GUISystem::networkClient()  // sets up game as a network client
{
//    networkEngineSharedPtr network = networkEngine::Instance();
//    sharedPtr<gameEngine> gameE = gameEngine::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();

//    gameS->setGameType(MULTI);
    gameInstance->getData()->setGameType(MULTINET);
//    hideNetworkSetupWidgets();  // Hides Network Setup Menu widgets
    flag->setMenuActive(false);
    gameE->getNetworkE()->setIPAddress(component->getClientIPAddressBox()->getCaption());  // sets the neworkEngine's ipAddress string to that of the caption
//    network->networkClient();
    if (gameE->getNetworkE()->clientConnect()) // attempts to connect to the remote server
    {
        gameE->getNetworkE()->setIsClient(true);  // if successful sets isClient to true
    }
//    gameE->setCreateScene(true); // sets variable true that tells gameEngine to start rendering the scenetop

}


void GUISystem::setupAwaySelected()  // processes away team selectdion on game setup menu
{
    MyGUI::InputManager::getInstance().setKeyFocusWidget(component->getTeamSelectBox()[1].get());
    flag->setSetupMenuAwaySelected(true);
    flag->setSetupMenuHomeSelected(false);
}

void GUISystem::setupHomeSelected()  // process home team selection on game setup menu
{
    MyGUI::InputManager::getInstance().setKeyFocusWidget(component->getTeamSelectBox()[1].get());
    flag->setSetupMenuHomeSelected(true);
    flag->setSetupMenuAwaySelected(false);
}

void GUISystem::backNetworkSetupMenuSelected(const renderEngineSharedPtr &render)  // returns back to network setup screen
{
    display->changeActiveMenu(NETWORK, render);
}

void GUISystem::backMainMenuSelected(const renderEngineSharedPtr &render)  // processes back to main menu selection
{
    display->changeActiveMenu(MAIN, render);
}

void GUISystem::backNetworkClientMenuSelected(const renderEngineSharedPtr &render)  // returns back to the network client menu
{
    display->changeActiveMenu(NETWORKCLIENT, render);
}
