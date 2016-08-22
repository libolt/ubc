/***************************************************************************
 *   Copyright (C) 1999 - 2016 by Mike McLean                              *
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

#include "engine/networkengine.h"

#include "gui/gui.h"
#include "conversion.h"
#include "data/courtdata.h"
#include "engine/gameengine.h"
#include "state/basketballstate.h"
#include "state/courtstate.h"
#include "state/gamestate.h"
#include "state/teamstate.h"
#include "state/playerstate.h"
#include "load.h"
#include "logging.h"
#include "engine/renderengine.h"
#include "data/teamdata.h"

#ifdef __ANDROID__
#include "android-config.h"
#else
#include "config.h"
#endif

/*
boost::shared_ptr<GUISystem> GUISystem::pInstance;
i
boost::shared_ptr<GUISystem> GUISystem::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        //pInstance = new GUISystkem; // cn sole instance
        
        boost::shared_ptr<GUISystem> tInstance(new GUISystem);
        pInstance = tInstance;
    }kmmmmkkkkko|mm
    return pInstance; // address of sole instance
}
*/

// static declarations

boost::shared_ptr<MyGUI::Gui> GUISystem::mGUI;
boost::shared_ptr<MyGUI::OgrePlatform> GUISystem::mPlatform;
bool GUISystem::mainMenuCreated; 
boost::shared_ptr<MyGUI::Button> GUISystem::startSingleGameButton;
//void GUISystem::startSingleGameButtonClicked(MyGUI::Widget *_sender);

GUISystem::GUISystem()  // Initialmizes the GUISystem class
{
//    mGUIRenderer = 0;
//    mGUISystem = 0;
//    mEditorGuiSheet =m
//    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
//    QuickGUI::registerScriptParser()m;
    setupComplete = false;
    mainMenuCreated = false;
    backButtonsCreated = false;
    networkSetupMenuCreated = false;
    networkServerSetupMenuCreated = false;
    networkClientSetupMenuCreated = false;
    optionsMenuCreated = false;
    displaySetupMenuCreated = false;
    inputSetupMenuCreated = false;
    audioSetupMenuCreated = false;
    gameSetupMenuCreated = false;
    gameSetupMenuAwaySelected = false;
    gameSetupMenuHomeSelected = false;
    playerStartSelectionMenuCreated = false;
    teamSelectionMenuCreated = false;
    teamSelectionMenuDataAdded = false;
    courtSelectionMenuCreated = false;
    courtSelectionDataLoaded = false;
    
    menuActive = false;

    //activeMenu = NULL;mm
    //previousActiveMenu = NULL;
    displayCount = 0;

}

GUISystem::~GUISystem()
{

}


/*boost::shared_ptr<networkEngimmnmne> GUISystem::getNetworkG()  // retrieves the value of network
{
    return (networkG);
}
void GUISystem::setNetworkG(boost::shared_ptr<networkEngine> set)  // sets the value of network
{
    networkG = set;
}

boost::shared_ptr<renderEngine> GUISystem::getRenderE()  // retrieves the value of render
{
    return (render);
}
void GUISystem::setRender(boost::shared_ptr<renderEngine> set)  // sets the value of render
{
    render = set;
}
*/


bool GUISystem::getSetupComplete()  // retrieves the value of setupComplete
{
    return (setupComplete);
}
void GUISystem::setSetupComplete(bool set)  // sets the value of setupComplete
{
    setupComplete = set;
}

bool GUISystem::getMainMenuCreated()  // retrieves the value of mainMenuCreated
{
    return (mainMenuCreated);
}
void GUISystem::setMainMenuCreated(bool set)  // sets the value of mainMenuCreated
{
    mainMenuCreated = set;
}

bool GUISystem::getBackButtonsCreated()  // retrieves the value of backButtonsCreated
{
	return (backButtonsCreated);
}
void GUISystem::setBackButtonsCreated(bool set)  // sets the value of backButtonsCreated
{
	backButtonsCreated = set;
}

bool GUISystem::getNetworkSetupMenuCreated()  // retrieves the value of networkSetupMenuCreated
{
    return (networkSetupMenuCreated);
}
void GUISystem::setNetworkSetupMenuCreated(bool set)  // sets the value of networkSetupMenuCreated
{
    networkSetupMenuCreated = set;
}

bool GUISystem::getOptionsMenuCreated()  // retrieves the value of optionsMenuCreated
{
	return (optionsMenuCreated);
}
void GUISystem::setOptionsMenuCreated(bool set)  // sets the value of optionsMenuCreated
{
	optionsMenuCreated = set;
}

bool GUISystem::getDisplaySetupMenuCreated()  // retrieves the value of displaySettingsMenuCreated
{
	return (displaySetupMenuCreated);
}
void GUISystem::setDisplaySetupMenuCreated(bool set)  // sets the value of displaySettingsMenuCreated
{
	displaySetupMenuCreated = set;
}

bool GUISystem::getInputSetupMenuCreated()  // retrieves the value of inputSettingsMenuCreated
{
	return (inputSetupMenuCreated);
}
void GUISystem::setInputSetupMenuCreated(bool set)  // sets the value of inputSettingsMenuCreated
{
	inputSetupMenuCreated = set;
}

bool GUISystem::getAuduoSetupMenuCreated()  // retrieves the value of audioSettingsMenuCreated
{
	return (audioSetupMenuCreated);
}

void GUISystem::setAudioSetupMenuCreated(bool set)  // sets the value of audioSettingsMenuCreated
{
	audioSetupMenuCreated = set;
}

bool GUISystem::getGameSetupMenuCreated()  // retrieves the value of gameSetupMenuCreated
{
	return (gameSetupMenuCreated);
}
void GUISystem::setGameSetupMenuCreated(bool set)  // sets the value of gameSetupMenuCreated
{
	gameSetupMenuCreated = set;
}

bool GUISystem::getPlayerStartSelectionMenuCreated()  // retrieves the value of playerStartSelectionMenuCreated
{
    return (playerStartSelectionMenuCreated);
}
void GUISystem::setPlayerStartSelectionMenuCreated(bool set)  // sets the value of playerStartSelectionMenuCreated
{
    playerStartSelectionMenuCreated = set;
}

bool GUISystem::getTeamSelectionMenuCreated()  // retrieves the value of teamSelectionMenuCreated
{
    return (teamSelectionMenuCreated);
}
void GUISystem::setTeamSelectionMenuCreated(bool set)  // sets the value of teamSelectionMenuCreated
{
    teamSelectionMenuCreated = set;
}

bool GUISystem::getTeamSelectionMenuDataAdded()  // retrieves the value of teamSelectionMenuDataAdded
{
    return (teamSelectionMenuDataAdded);
}
void GUISystem::setTeamSelectionMenuDataAdded(bool set)  // sets the value of teamSelectionDataAdded
{
    teamSelectionMenuDataAdded = set;
}

bool GUISystem::getCourtSelectionMenuCreated()  // retrieves the value of courtSelectionMenuCreated
{
	return (courtSelectionMenuCreated);
}
void GUISystem::setCourtSelectionMenuCreated(bool set)  // sets the value of courtSelectionMenuCreated
{
	courtSelectionMenuCreated = set;
}

bool GUISystem::getCourtSelectionDataLoaded()  // retrieves the value of courtSelectionEntriesLoaded
{
    return (courtSelectionDataLoaded);
}
void GUISystem::setCourtSelectionDataLoaded(bool set)  // sets the value of courtSelectionEntriesLoaded
{
    courtSelectionDataLoaded = set;
}

bool GUISystem::getMenuActive()  // retrieves the value of menuActive
{
	return (menuActive);
}
void GUISystem::setMenuActive(bool set)  // sets the value of menuActive
{
	menuActive = set;
}
activeMenus GUISystem::getActiveMenu()  // retrieves the value of activeMenu
{
	return (activeMenu);
}
void GUISystem::setActiveMenu(activeMenus set)  // sets the value of activeMenu
{
	activeMenu = set;
}

activeMenus GUISystem::getPreviousActiveMenu()  // retrieves the value of previousActiveMenu
{
	return (previousActiveMenu);
}
void GUISystem::setPreviousActiveMenu(activeMenus set)  // sets the value of previousActiveMenu
{
	previousActiveMenu = set;
}


boost::shared_ptr<MyGUI::Gui> GUISystem::getMGUI()  // retrieves the value of mGUI
{
    return (mGUI);
}
void GUISystem::setMGUI(boost::shared_ptr<MyGUI::Gui> set)  // sets the value of mGUI
{
    mGUI = set;
}

/*Ogre::Viewport *GUISystem::getViewPort()  // retrieves the value of viewPort
{
    return (viewPort);
}
void GUISystem::setViewPort(const Ogre::Viewport &set)  // sets the value of viewPort
{
    *viewPort = set;
}*/

bool GUISystem::setup()  // sets up the in game gui
{
    if (initMyGUI()) // Initializes MyGUI
    {
        logMsg ("MyGUI initialized successfully!");
        logMsg("is the main menu created?");
//        exit(0);
    }
    else
    {
        logMsg("Unable to initialize MyGUI!");
        exit(0);
    }
    return (true);
}

bool GUISystem::initMyGUI()  // Initializes MyGUI
{
//    exit(0);
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::RenderWindow *mWindow = render->getMWindow();
//    Ogre::SceneManager *mSceneMgr = render->getMSceneMgr();

    logMsg("*** Initializing MyGUI ***");
    boost::shared_ptr<MyGUI::OgrePlatform> tempPlatform(new MyGUI::OgrePlatform());
    mPlatform = tempPlatform;
    logMsg("Crash?");

/*#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    mPlatform->initialise(mWindow, mSceneMgr, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
#else
*/
    mPlatform->initialise(getGameE()->getRenderE()->getMWindow(), getGameE()->getRenderE()->getMSceneMgr(), "UBCData"); // mWindow is Ogre::RenderWindow*, mSceneManager is Ogre::SceneManager*
//#endif

    logMsg("Crash??");
    boost::shared_ptr<MyGUI::Gui> tempGUI(new MyGUI::Gui());
    mGUI = tempGUI;
    logMsg("Crash???");
    mGUI->initialise();
    logMsg("*** MyGUI Initialized ***");
    return true;
}

void GUISystem::mainMenu()  // msin in game menu
{
    if (!mainMenuCreated)
    {
        logMsg("mainMenu not created yet!");
//            exit(0);
        if (createMainMenuGUI()) // creates the main menu gui.
        {
            logMsg("Main Menu created successfully!");
            mainMenuCreated = true;
//                exit(0);
        }
        else
        {
            logMsg("Unable to create Main Menu!");
            exit(0);
        }
    }
    else
    {
        
    }
    showMainMenuWidgets();  // displays main menu
    activeMenu = MAIN;
//    exit(0);
}

void GUISystem::backButtons()  // handles the back buttons
{
    if (!backButtonsCreated)
    {
        logMsg("Back buttons not created yet!");
        if (createBackButtons()) // creates the back buttons.
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
        }
    }
    else
    {
        
    }
}

void GUISystem::startSinglePlayerGame()  // starts single player game
{
//    boost::shared_ptr<gameState> gameS = gameState::Instance();

//    gameS->setGameType(SINGLE);
    getGameS()->setGameType(SINGLE);
//	hideMainMenuWidgets();	// Hides the widgets from the main menu
    courtSelectionMenu();   // displays the menu for selecting which court to use
    //   gameSetupMenu();
//	menuActive = false;
}

void GUISystem::startMultiPlayerGame()  // starts multiplayer game
{
    if (!networkSetupMenuCreated)
    {
        createNetworkSetupGUI();  // creates the GUI for the Network Setup Screen
    }

    changeActiveMenu(NETWORK);
}

void GUISystem::optionsMenu()  // displays options menu
{
    if (!optionsMenuCreated)
    {
        createOptionsMenuGUI();
    }

    changeActiveMenu(OPTIONS);
}

void GUISystem::displayMenu()  // displays display menu
{
    if (!displaySetupMenuCreated)
    {
        createDisplaySetupGUI();
    }

    changeActiveMenu(DISPLAY);
}

void GUISystem::inputMenu()  // displays the input menu
{
    if (!inputSetupMenuCreated)
    {
        createInputSetupGUI();
    }

    changeActiveMenu(INPUTMENU);
}
void GUISystem::audioMenu()  // displays the audio menu
{
    if (!audioSetupMenuCreated)
    {
        createAudioSetupGUI();
    }

    changeActiveMenu(AUDIO);
}

void GUISystem::gameSetupMenu()  // displays game setup menu
{
    if (!gameSetupMenuCreated)
    {
        createGameSetupMenuGUI();
        gameSetupMenuCreated = true;
    }
	
    changeActiveMenu(GAMESETUP);
}

void GUISystem::playerStartSelectionMenu()  // displays player start selection menu
{
//    exit(0);
    if (!playerStartSelectionMenuCreated)
    {
        createPlayerStartSelectionMenuGUI();	
        addPlayerStartSelectionMenuData();
//        exit(0);
        playerStartSelectionMenuCreated = true;
    }
    setSelectedIndexes();
    changeActiveMenu(PLAYERSTART);
}

void GUISystem::teamSelectionMenu()  // displays team selection menu
{
    hideCourtSelectionMenuWidgets();
    createTeamSelectionMenuGUI();
    showTeamSelectionMenuWidgets();
//    changeActiveMenu(TEAMSELECT);
    boost::shared_ptr<loader> load = loader::Instance();
    bool changeMenu = false;  // determinrs if menu is to be changed
//    std::vector<boost::shared_ptr<teamState> > teamInstance; // = gameS->getTeamDataInstance();

    logMsg("teamSelectionMenu");

//    teamInstance = load->loadTeams();

    if (teamSelectionMenuCreated)
    {
        if (getGameS()->getTeamInstancesCreated())
        {
            if (teamSelectionMenuDataAdded)
            {
                logMsg("Team Selection Menu Data Added already!");
                changeMenu = true;
            }
            else
            {
                if (addTeamStartSelectionMenuData())
                {
                    teamSelectionMenuDataAdded = true;
                   changeMenu = true;
                }
                else
                {
                    logMsg("unable to add data to Team Selection Menus!");
                    exit(0);
                }
            }
        }
        else
        {
            if (getGameS()->createTeamInstances())
            {
                getGameS()->setTeamInstancesCreated(true);
                if (teamSelectionMenuDataAdded)
                {
                    logMsg("Team Selection Menu Data Added already!");
                    changeMenu = true;
                }
                else
                {
                    if (addTeamStartSelectionMenuData())
                    {
                        teamSelectionMenuDataAdded = true;
                        changeMenu = true;
                    }
                    else
                    {
                        logMsg("unable to add data to Team Selection Menus!");
                        exit(0);
                    }
                }
            }
            else
            {
                logMsg("feeerrrrappp!");         
                exit(0);
            }
        }
    }
    else
    {
        if (createTeamSelectionMenuGUI())
        {            
            teamSelectionMenuCreated = true;
            if (addTeamStartSelectionMenuData())
            {
                
                teamSelectionMenuDataAdded = true;
                changeMenu = true;
            }
            else 
            {
                logMsg("unable to add data to Team Selection Menus!");
                exit(0);
            }

        }
        else
        {
            logMsg("Unable to create Team Selection Menu!");
        }
    }
    
//    hideCourtSelectionMenuWidgets();
    if (changeMenu = true)
    {
        logMsg("Changing activeMenu to TEAMSELECT!");
//        exit(0);
        changeActiveMenu(TEAMSELECT);
    }
    else
    {
        logMsg("Failed to change activeMenu to TEAMSELECT!");
        exit(0);
    }

//    exit(0);
}

void GUISystem::courtSelectionMenu() // displays court selection menu
{
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<loader> load = loader::Instance();

    if (!courtSelectionMenuCreated)
    {
        createCourtSelectionMenuGUI();
    }
    
    if (!courtSelectionDataLoaded)
    {
        logMsg("addCourtSelectionMenuData = " +convert->toString(addCourtSelectionMenuData()));
//        exit(0);
        if (addCourtSelectionMenuData())
        {
//            exit(0);
            courtSelectBox->setIndexSelected(0);
            courtSelectionDataLoaded = true;
        }
//        exit(0);
    }
    changeActiveMenu(COURTSELECT);
    
}


void GUISystem::setSelectedIndexes()  // sets all player listbox indexes to zero
{
    team0PGSelectBox->setIndexSelected(0);
    team0SGSelectBox->setIndexSelected(0);
    team0SFSelectBox->setIndexSelected(0);
    team0PFSelectBox->setIndexSelected(0);
    team0CSelectBox->setIndexSelected(0);
    team1PGSelectBox->setIndexSelected(0);
    team1SGSelectBox->setIndexSelected(0);
    team1SFSelectBox->setIndexSelected(0);
    team1PFSelectBox->setIndexSelected(0);
    team1CSelectBox->setIndexSelected(0);
}

void GUISystem::networkClientSetupMenu() // sets up the client connection
{
    if (!networkClientSetupMenuCreated)
    {
        createNetworkClientSetupGUI();
    }
    changeActiveMenu(NETWORKCLIENT);
    MyGUI::InputManager::getInstance().setKeyFocusWidget(clientIPAddressBox.get());
//    mGUI::InputManager->getInstance().setKeyFocusWidget(clientIPAddressBox);
}

void GUISystem::networkServerSetupMenu()  // sets up the networkServer instance
{
    if (!networkServerSetupMenuCreated)
    {
        createNetworkServerSetupGUI();
    }

    changeActiveMenu(NETWORKSERVER);
    MyGUI::InputManager::getInstance().setKeyFocusWidget(serverIPAddressBox.get());

}

void GUISystem::networkServer()  // sets up  game as a network server
{
    //networkEngine * network = networkEngine::Instance();
//    boost::shared_ptr<networkEngine> network = networkEngine::Instance();
    //gameEngine * gameE = gameEngine::Instance();
//    boost::shared_ptr<gameEngine> gameE = gameEngine::Instance();
    //gameState *gameS = gameState::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();

//    gameS->setGameType(MULTI);
    getGameS()->setGameType(MULTI);
//   hideNetworkSetupWidgets();  // Hides Network Setup Menu widgets
    menuActive = false;
    getGameE()->getNetworkE()->setIPAddress(serverIPAddressBox->getCaption());  // sets the neworkEngine's ipAddress string to that of the caption
    logMsg("server ip = " +getGameE()->getNetworkE()->getIPAddress());
    if (getGameE()->getNetworkE()->serverSetup())  // attempts to setup as a network server
    {
        getGameE()->getNetworkE()->setIsServer(true);  // if successful sets isServer to true
    }

//    gameE->setCreateScene(true); // sets variable true that tells gameEngine to start rendering the scene

}
void GUISystem::networkClient()  // sets up game as a network client
{
//    boost::shared_ptr<networkEngine> network = networkEngine::Instance();
//    boost::shared_ptr<gameEngine> gameE = gameEngine::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();

//    gameS->setGameType(MULTI);
    getGameS()->setGameType(MULTI);
//    hideNetworkSetupWidgets();  // Hides Network Setup Menu widgets
    menuActive = false;
    getGameE()->getNetworkE()->setIPAddress(clientIPAddressBox->getCaption());  // sets the neworkEngine's ipAddress string to that of the caption
//    network->networkClient();
    if (getGameE()->getNetworkE()->clientConnect()) // attempts to connect to the remote server
    {
        getGameE()->getNetworkE()->setIsClient(true);  // if successful sets isClient to true
    }
//    gameE->setCreateScene(true); // sets variable true that tells gameEngine to start rendering the scenetop

}

void GUISystem::courtSelected()  // processes court selection
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //gameState *gameS = gameState::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
    
    logMsg("Selected Court #" +convert->toString(courtSelectBox->getIndexSelected()));
//    gameS->setSelectedCourtDataInstance(courtSelectBox->getIndexSelected());
//    gameS->setActiveCourtInstance(courtSelectBox->getIndexSelected());
    getGameS()->setActiveCourtInstance(courtSelectBox->getIndexSelected());
//    exit(0);
//    changeActiveMenu(TEAMSELECT);
//    teamSelectionMenu();
}

void GUISystem::teamsSelected()  // processes team selection
{
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    
    std::vector<size_t> teamID;
    teamID.push_back(team0SelectBox->getIndexSelected());
    teamID.push_back(team1SelectBox->getIndexSelected());
//    gameS->setTeamID(teamID);
    logMsg("team0SelectBox->getIndexSelected() == " +convert->toString(team0SelectBox->getIndexSelected()));
    logMsg("teamID[0] == " +convert->toString(teamID[0]));

    getGameS()->setTeamIDS(teamID);
    logMsg("Teams selected");
//    exit(0);
}

void GUISystem::playerStartSelected()  // process player start selection
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //gameState *gameS = gameState::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();

//    std::vector<boost::shared_ptr<teamState> >  activeTeamInstance = gameS->getActiveTeamInstance();

    logMsg("S");
//        exit(0);
    std::vector<std::string> team0Starters;
    std::vector<std::string> team1Starters;
    std::vector<size_t> starters; // used for initial creatio  of teamStarterID vector
    std::vector<boost::shared_ptr<playerState> > playerInstance;
    std::vector<boost::shared_ptr<playerState> > activePlayerInstance;

    size_t IDs = 0;
    while (teamStarterID.size() < 2)
    {
        teamStarterID.push_back(starters);
    }
    while (teamStarterID[0].size() <5)
    {
        teamStarterID[0].push_back(IDs);
    }
    while (teamStarterID[1].size() <5)
    {
        teamStarterID[1].push_back(IDs);
    }
    
    // checks to make sure that all player selectBoxes have a valid index value
    if (team0PGSelectBox->getIndexSelected() < 0 || team0PGSelectBox->getIndexSelected() > team0PGSelectBox->getItemCount())
    {
        team0PGSelectBox->setIndexSelected(0);
    }
    if (team0SGSelectBox->getIndexSelected() < 0 || team0SGSelectBox->getIndexSelected() > team0SGSelectBox->getItemCount())
    {
        team0SGSelectBox->setIndexSelected(0);
    }
    if (team0SFSelectBox->getIndexSelected() < 0 || team0SFSelectBox->getIndexSelected() > team0SFSelectBox->getItemCount())
    {
        team0SFSelectBox->setIndexSelected(0);
    }
    if (team0PFSelectBox->getIndexSelected() < 0 || team0PFSelectBox->getIndexSelected() > team0PFSelectBox->getItemCount())
    {
        team0PFSelectBox->setIndexSelected(0);
    }
    if (team0CSelectBox->getIndexSelected() < 0 || team0CSelectBox->getIndexSelected() > team0CSelectBox->getItemCount())
    {
        team0CSelectBox->setIndexSelected(0);
    }
    if (team1PGSelectBox->getIndexSelected() < 0 || team1PGSelectBox->getIndexSelected() > team1PGSelectBox->getItemCount())
    {
        team1PGSelectBox->setIndexSelected(0);
    }
    if (team1SGSelectBox->getIndexSelected() < 0 || team1SGSelectBox->getIndexSelected() > team1SGSelectBox->getItemCount())
    {
        team1SGSelectBox->setIndexSelected(0);
    }
    if (team1SFSelectBox->getIndexSelected() < 0 || team1SFSelectBox->getIndexSelected() > team1SFSelectBox->getItemCount())
    {
        team1SFSelectBox->setIndexSelected(0);
    }
    if (team1PFSelectBox->getIndexSelected() < 0 || team1PFSelectBox->getIndexSelected() > team1PFSelectBox->getItemCount())
    {
        team1PFSelectBox->setIndexSelected(0);
    }
    if (team1CSelectBox->getIndexSelected() < 0 || team1CSelectBox->getIndexSelected() > team1CSelectBox->getItemCount())
    {
        team1CSelectBox->setIndexSelected(0);
    }
    
//    teamStarterID[0][0] = team0IDs[0][team0PGSelectBox->getIndexSelected()];
    team0Starters.push_back(team0PGSelectBox->getItemNameAt(team0PGSelectBox->getIndexSelected()));
    teamStarterID[0][0] = team0IDs[0][team0PGSelectBox->getIndexSelected()];
    logMsg("teamStarterID[0][0] = " +convert->toString(teamStarterID[0][0]));
    team0Starters.push_back(team0SGSelectBox->getItemNameAt(team0SGSelectBox->getIndexSelected()));
    teamStarterID[0][1] = team0IDs[1][team0SGSelectBox->getIndexSelected()];
    logMsg("teamStarterID[0][1] = " +convert->toString(teamStarterID[0][1]));
    team0Starters.push_back(team0SFSelectBox->getItemNameAt(team0SFSelectBox->getIndexSelected()));
    teamStarterID[0][2] = team0IDs[2][team0SFSelectBox->getIndexSelected()];
    logMsg("teamStarterID[0][2] = " +convert->toString(teamStarterID[0][2]));
    team0Starters.push_back(team0PFSelectBox->getItemNameAt(team0PFSelectBox->getIndexSelected()));
    teamStarterID[0][3] = team0IDs[3][team0PFSelectBox->getIndexSelected()];
    logMsg("teamStarterID[0][3] = " +convert->toString(teamStarterID[0][3]));
    team0Starters.push_back(team0CSelectBox->getItemNameAt(team0CSelectBox->getIndexSelected()));
    teamStarterID[0][4] = team0IDs[4][team0CSelectBox->getIndexSelected()];
    logMsg("teamStarterID[0][4] = " +convert->toString(teamStarterID[0][4]));
    team1Starters.push_back(team1PGSelectBox->getItemNameAt(team1PGSelectBox->getIndexSelected()));
    teamStarterID[1][0] = team1IDs[0][team1PGSelectBox->getIndexSelected()];
    logMsg("teamStarterID[1][0] = " +convert->toString(teamStarterID[1][0]));
    team1Starters.push_back(team1SGSelectBox->getItemNameAt(team1SGSelectBox->getIndexSelected()));
    teamStarterID[1][1] = team1IDs[1][team1SGSelectBox->getIndexSelected()];
    logMsg("teamStarterID[1][1] = " +convert->toString(teamStarterID[1][1]));
    team1Starters.push_back(team1SFSelectBox->getItemNameAt(team0SFSelectBox->getIndexSelected()));
    teamStarterID[1][2] = team1IDs[2][team1SFSelectBox->getIndexSelected()];
    logMsg("teamStarterID[1][2] = " +convert->toString(teamStarterID[1][2]));
    team1Starters.push_back(team1PFSelectBox->getItemNameAt(team1PFSelectBox->getIndexSelected()));
    teamStarterID[1][3] = team1IDs[3][team1PFSelectBox->getIndexSelected()];
    
    logMsg("teamStarterID[1][3] = " +convert->toString(teamStarterID[1][3]));
    team1Starters.push_back(team1CSelectBox->getItemNameAt(team1CSelectBox->getIndexSelected()));
    teamStarterID[1][4] = team1IDs[4][team1CSelectBox->getIndexSelected()];
    logMsg("teamStarterID[1][4] = " +convert->toString(teamStarterID[1][4]));

//    gameS->setTeamStarterID(teamStarterID); // sets the selected starters for both teams in gameState class
    getGameS()->setTeamStarterID(teamStarterID); // sets the selected starters for both teams in gameState class
    
    std::vector<size_t> activePlayerID;

    for (size_t x=0;x<5;++x)
    {
        activePlayerID.push_back(teamStarterID[0][x]);
        logMsg("activePlayerID = " +convert->toString(activePlayerID[x]));
    }
    
    getGameS()->getActiveTeamInstance()[0]->setActivePlayerID(activePlayerID);
    if (!getGameS()->getActiveTeamInstance()[0]->getPlayerInstancesCreated())    // checks if playerInstances have been created
    {
        logMsg("player instances created!");
        
        if (getGameS()->getActiveTeamInstance()[0]->createPlayerInstances()) // creates the player instances based on playerIDS
        {
            logMsg("Team 0 Player instances created!");
            getGameS()->getActiveTeamInstance()[0]->setPlayerInstancesCreated(true);
//          exit(0);
        }
    }
    playerInstance.clear();
    activePlayerInstance.clear();
    playerInstance = getGameS()->getActiveTeamInstance()[0]->getPlayerInstance();
    size_t y = 0;
    logMsg("GUI playerInstance.size() = " +convert->toString(playerInstance.size()));
    
    while (y < playerInstance.size())
    {
        size_t z = 0;
        while (z < activePlayerID.size())
        {
            if (playerInstance[y]->getID() == activePlayerID[z])
            {
                activePlayerInstance.push_back(playerInstance[y]);
                logMsg("GUI playerInstance[y] ID  = " +convert->toString(playerInstance[y]->getID()));
    
            }
            ++z;
        }
        ++y;
    }
//    exit(0);
    logMsg("GUI activePlayerInstance.size() = " +convert->toString(activePlayerInstance.size()));
    getGameS()->getActiveTeamInstance()[0]->setActivePlayerInstance(activePlayerInstance);
    getGameS()->getActiveTeamInstance()[0]->setPlayerStartActivePositions();
    
    getGameS()->getActiveTeamInstance()[0]->setPlayerStartPositions();
//    logMsg("Team 0 player start positions set");
//    exit(0);
    size_t i = 0;
    //std::vector<playerState> playerInstance;
    playerInstance.clear();
    playerInstance = getGameS()->getActiveTeamInstance()[0]->getPlayerInstance();
    while (i<playerInstance.size())
    {
        if (activePlayerID[4] == playerInstance[i]->getID())
        {
            getGameS()->getActiveTeamInstance()[0]->setHumanPlayer(i);
            logMsg("human player set!");
        }
        i++;
    }
    activePlayerID.clear();
    for (size_t x=0;x<5;++x)
    {
        activePlayerID.push_back(teamStarterID[1][x]);
    }

    getGameS()->getActiveTeamInstance()[1]->setActivePlayerID(activePlayerID);
    if (!getGameS()->getActiveTeamInstance()[1]->getPlayerInstancesCreated())  // checks if playerInstances have been created
    {
        logMsg("Creating team 1 player instances");
//            exit(0);
        if (getGameS()->getActiveTeamInstance()[1]->createPlayerInstances())  // creates the player instances based on playerIDS
        {
//            exit(0);

            logMsg("Player instances created!");
            getGameS()->getActiveTeamInstance()[1]->setPlayerInstancesCreated(true);
//          exit(0);
        }
//.        exit(0);

    }
    playerInstance.clear();
    playerInstance = getGameS()->getActiveTeamInstance()[1]->getPlayerInstance();
    activePlayerInstance.clear();
    y = 0;
    while (y < playerInstance.size())
    {
        size_t z = 0;
        while (z < activePlayerID.size())
        {
            if (playerInstance[y]->getID() == activePlayerID[z])
            {
                activePlayerInstance.push_back(playerInstance[y]);
            }
            ++z;
        }
        ++y;
    }

    getGameS()->getActiveTeamInstance()[1]->setActivePlayerInstance(activePlayerInstance);
    getGameS()->getActiveTeamInstance()[1]->setPlayerStartActivePositions();
    getGameS()->getActiveTeamInstance()[1]->setPlayerStartPositions();
    logMsg("Team 1 player start positions set");
    playerInstance = getGameS()->getActiveTeamInstance()[1]->getPlayerInstance();
    while (i<playerInstance.size())
    {
        if (activePlayerID[4] == playerInstance[i]->getID())
        {
            getGameS()->getActiveTeamInstance()[1]->setHumanPlayer(i);
            logMsg("human player set!");
        }
        i++;
    }

    if (getGameS()->getActiveTeamInstance()[0]->getPlayerInstancesCreated() && getGameS()->getActiveTeamInstance()[1]->getPlayerInstancesCreated())
    {
///        getGameS()->setActiveTeamInstance(activeTeamInstance);  // sets the activeTeamInstance vector
//        getGameS()->setGameSetupComplete(true);
        getGameS()->setGameSetupComplete(true);
    }
    else
    {
        logMsg("Team Instances NOT created!");
        exit(0);
    }

    logMsg("team 0 C selectbox id = " +convert->toString(teamStarterID[0][1]));
    logMsg("team 0 starter 0 = " +convert->toString(teamStarterID[0][0]));
    logMsg("team  0 starter 0 = " +team0Starters[0]);
//        exit(0);
    hideActiveMenuWidgets();
    menuActive = false;
//    exit(0);

}

void GUISystem::gameSetupAwaySelected()  // processes away team selectdion on game setup menu
{
    MyGUI::InputManager::getInstance().setKeyFocusWidget(team1SelectBox.get());
    gameSetupMenuAwaySelected = true;
    gameSetupMenuHomeSelected = false;
}

void GUISystem::gameSetupHomeSelected()  // process home team selection on game setup menu
{
    MyGUI::InputManager::getInstance().setKeyFocusWidget(team0SelectBox.get());
    gameSetupMenuHomeSelected = true;
    gameSetupMenuAwaySelected = false;
}

void GUISystem::backNetworkSetupMenuSelected()  // returns back to network setup screen
{
    changeActiveMenu(NETWORK);
}

void GUISystem::backMainMenuSelected()  // processes back to main menu selection
{
    changeActiveMenu(MAIN);
}

void GUISystem::backNetworkClientMenuSelected()  // returns back to the network client menu
{
    changeActiveMenu(NETWORKCLIENT);
}

bool GUISystem::checkTeamInstancesCreated()  // Checks if team instances have been created and if not creates them.
{
//    exit(0);
    //gameState *gameS = gameState::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();

    if (!getGameS()->getActiveTeamInstancesCreated())
    {
        getGameS()->setActiveTeamInstancesNeedCreated(true);
/*        logMsg("Creating active team instances!");
        gameS->createActiveTeamInstances();
        gameS->setActiveTeamInstancesCreated(true);
        gameS->assignHoopToTeams();
        logMsg("Team instances created!");
*/
        return (false);
//        exit(0);
    }
    else 
    {
        return (true);
    }
}
