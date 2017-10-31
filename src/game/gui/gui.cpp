/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
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

#include "ubc/ubcbase.h"

#include "engine/networkengine.h"

#include "gui/gui.h"
#include "utilities/conversion.h"
#include "data/courtdata.h"
#include "data/playerdata.h"
#include "engine/gameengine.h"
#include "entity/playerentity.h"
#include "state/basketballstate.h"
#include "state/courtstate.h"
#include "state/gamestate.h"
#include "state/teamstate.h"
#include "state/playerstate.h"
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

/*
sharedPtr<GUISystem> GUISystem::pInstance;
i
sharedPtr<GUISystem> GUISystem::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        //pInstance = new GUISystkem; // cn sole instance
        
        sharedPtr<GUISystem> tInstance(new GUISystem);
        pInstance = tInstance;
    }kmmmmkkkkko|mm
    return pInstance; // address of sole instance
}
*/

// static declarations

UBCBaseSharedPtr GUISystem::base;

bool GUISystem::setupComplete;
bool GUISystem::mainMenuCreated; 
bool GUISystem::menuActive;  // stores whether a menu is being diplayed
bool GUISystem::backButtonsCreated;  // determines whether the back buttons have been created
bool GUISystem::networkSetupMenuCreated;   // determines whether the network setup gui has been created
bool GUISystem::networkServerSetupMenuCreated;   // determines whether the network server setup gui has been created
bool GUISystem::networkClientSetupMenuCreated;   // determines whether the network client setup gui has been created
bool GUISystem::optionsMenuCreated;   // determines whether the options menu gui has been created
bool GUISystem::displaySetupMenuCreated;   // determines whether the display settings menu gui has been created
bool GUISystem::inputSetupMenuCreated;   // determines whether the input settings menu gui has been created
bool GUISystem::audioSetupMenuCreated;   // determines whether the audio settings menu gui has been created
bool GUISystem::gameSetupMenuCreated;  // determines whether the game setup menu gui has been created
bool GUISystem::playerStartSelectionMenuCreated;  // determines whether the player start selection menu gui has been created
bool GUISystem::teamSelectionMenuCreated;  // determines whether the team selection menu gui has been created
bool GUISystem::teamSelectionMenuDataAdded;  // determines whether teeam data has been added to the the team selection menu
bool GUISystem::courtSelectionMenuCreated;  // deteemines whether the court selection menu has been created;
bool GUISystem::gameSetupMenuAwaySelected;  // determines whether the away team listbox is selected;
bool GUISystem::gameSetupMenuHomeSelected;  // determines whether the home team listbox is selected;
bool GUISystem::courtSelectionDataLoaded;  // determines whether court names have been added to the select box

activeMenus GUISystem::activeMenu;  // stores which menu is being displayed
activeMenus GUISystem::previousActiveMenu;  // stores which menu was last displayed

MyGUIGuiSharedPtr GUISystem::mGUI;
MyGUIOgrePlatformSharedPtr GUISystem::mPlatform;

MyGUIButtonUMSharedPtr GUISystem::mainMenuButtons;

MyGUIButtonUMSharedPtr GUISystem::networkMenuButtons;

MyGUIButtonUMSharedPtr GUISystem::playerStartSelectionMenuButtons;
/*sharedPtr<MyGUI::Button> uexitButton;
sharedPtr<MyGUI::Button> GUISystem::startSingleGameButton;
sharedPtr<MyGUI::Button> GUISystem::startMultiGameButton;
sharedPtr<MyGUI::Button> GUISystem::optionsButton;
sharedPtr<MyGUI::Button> GUISystem::serverButton;
sharedPtr<MyGUI::Button> GUISystem::clientButton;
sharedPtr<MyGUI::Button> GUISystem::backMainMenuButton;
*/
//sharedPtr<MyGUI::Button> GUISystem::backNetworkSetupButton;

MyGUIButtonUMSharedPtr GUISystem::optionsMenuButtons;
/*sharedPtr<MyGUI::Button> GUISystem::displayButton;
sharedPtr<MyGUI::Button> GUISystem::inputButton;
sharedPtr<MyGUI::Button> GUISystem::audioButton;
*/

//sharedPtr<MyGUI::Button> GUISystem::startGameButton;
//sharedPtr<MyGUI::Button> GUISystem::backNetworkClientButton;
//sharedPtr<MyGUI::Button> GUISystem::changeResolutionButton;
//sharedPtr<MyGUI::Button> GUISystem::changeInputTypeButton;
//sharedPtr<MyGUI::Button> GUISystem::enableAudioButton;
//sharedPtr<MyGUI::Button> GUISystem::disableAudioButton;
//sharedPtr<MyGUI::Button> GUISystem::backOptionsMenuButton;
//sharedPtr<MyGUI::Button> GUISystem::backGameSetupMenuButton;
//sharedPtr<MyGUI::Button> GUISystem::backTeamSelectionMenuButton;
//sharedPtr<MyGUI::Button> GUISystem::backCourtSelectionMenuButton;

MyGUIButtonUMSharedPtr GUISystem::displayMenuButtons;
MyGUIButtonUMSharedPtr GUISystem::inputMenuButtons;
MyGUIButtonUMSharedPtr GUISystem::audioMenuButtons;


// Team Selection Menu
MyGUIButtonUMSharedPtr GUISystem::teamSelectionMenuButtons;

/*sharedPtr<MyGUI::Button> GUISystem::teamsSelectedButton;
sharedPtr<MyGUI::Button> GUISystem::team0SelectButton;
sharedPtr<MyGUI::Button> GUISystem::team1SelectButton;
*/

// Player Start Selection Menu
/*sharedPtr<MyGUI::Button> GUISystem::team0StartingLineupSetButton;
sharedPtr<MyGUI::Button> GUISystem::team1StartingLineupSetButton;
sharedPtr<MyGUI::Button> GUISystem::startingLineupsSetButton;
*/

// listbox widgets
//MyGUIListBoxSharedPtr GUISystem::team0SelectBox;
//MyGUIListBoxSharedPtr GUISystem::team1SelectBox;
MyGUIListBoxUMSharedPtr GUISystem::teamSelectBox;

// Network Server Setup Widgets
MyGUIListBoxSharedPtr GUISystem::numClientsSelectBox;  // allows you to select the number of network players
//sharedPtr<MyGUI::Button> GUISystem::serverHostButton;
sharedPtr<MyGUI::EditBox> GUISystem::serverIPAddressBox;
MyGUIButtonUMSharedPtr GUISystem::networkServerSetupMenuButtons;
    
// Network Client Setup Widgets
sharedPtr<MyGUI::EditBox> GUISystem::clientIPAddressBox;
//sharedPtr<MyGUI::Button> GUISystem::clientConnectButton;
MyGUIButtonUMSharedPtr GUISystem::networkClientSetupMenuButtons;
    
MyGUIListBoxVecUMSharedPtr GUISystem::teamPlayerPosSelectBox;

/*    MyGUIListBoxSharedPtr GUISystem::team0Player1SelectBox;
MyGUIListBoxSharedPtr GUISystem::team0Player2SelectBox;
MyGUIListBoxSharedPtr GUISystem::team0Player3SelectBox;
MyGUIListBoxSharedPtr GUISystem::team0Player4SelectBox;
MyGUIListBoxSharedPtr GUISystem::team0Player5SelectBox;
MyGUIListBoxSharedPtr GUISystem::team1Player1SelectBox;
MyGUIListBoxSharedPtr GUISystem::team1Player2SelectBox;
MyGUIListBoxSharedPtr GUISystem::team1Player3SelectBox;
MyGUIListBoxSharedPtr GUISystem::team1Player4SelectBox;
MyGUIListBoxSharedPtr GUISystem::team1Player5SelectBox;

    
// Player Selection Menu widgets
MyGUIListBoxSharedPtr GUISystem::team0PGSelectBox;
MyGUIListBoxSharedPtr GUISystem::team0SGSelectBox;
MyGUIListBoxSharedPtr GUISystem::team0SFSelectBox;
MyGUIListBoxSharedPtr GUISystem::team0PFSelectBox;
MyGUIListBoxSharedPtr GUISystem::team0CSelectBox;
MyGUIListBoxSharedPtr GUISystem::team1PGSelectBox;
MyGUIListBoxSharedPtr GUISystem::team1SGSelectBox;
MyGUIListBoxSharedPtr GUISystem::team1SFSelectBox;
MyGUIListBoxSharedPtr GUISystem::team1PFSelectBox;
MyGUIListBoxSharedPtr GUISystem::team1CSelectBox;
*/

MyGUITextBoxVecUMSharedPtr GUISystem::teamPlayerRating;
MyGUIImageBoxUMSharedPtr GUISystem::teamLogo;

/*
MyGUITextBoxSharedPtr> GUISystem::team0PGRating;
MyGUITextBoxSharedPtr> GUISystem::team0SGRating;
MyGUITextBoxSharedPtr> GUISystem::team0SFRating;
MyGUITextBoxSharedPtr> GUISystem::team0PFRating;
MyGUITextBoxSharedPtr> GUISystem::team0CRating;
MyGUITextBoxSharedPtr> GUISystem::team1PGRating;
MyGUITextBoxSharedPtr> GUISystem::team1SGRating;
MyGUITextBoxSharedPtr> GUISystem::team1SFRating;
MyGUITextBoxSharedPtr> GUISystem::team1PFRating;
MyGUITextBoxSharedPtr> GUISystem::team1CRating;
MyGUIImageBoxSharedPtr GUISystem::team0Logo;
MyGUIImageBoxSharedPtr GUISystem::team1Logo;
*/

// Court selection menu widgets
MyGUIButtonUMSharedPtr GUISystem::courtSelectionMenuButtons;
//sharedPtr<MyGUI::Button> GUISystem::backPlayerStartSelectionMenuButton;
//sharedPtr<MyGUI::Button> GUISystem::courtSelectButton;
MyGUIListBoxSharedPtr GUISystem::courtSelectBox;  
MyGUIImageBoxSharedPtr GUISystem::courtPreviewImgBox;
MyGUITextBoxSharedPtr GUISystem::courtNameTxtBox;

std::vector< stdStringVec > GUISystem::playerNames;
std::vector< stdStringVec > GUISystem::playerPositionsPlayed;
std::vector< sizeTVec > GUISystem::playerIDs;  // stores player IDs for each team
std::vector< sizeTVec > GUISystem::team0IDs;
std::vector< sizeTVec > GUISystem::team1IDs;
std::vector<std::unordered_map<std::string, size_t> > GUISystem::teamStarterID; // stores the selected starters for each team 

size_t GUISystem::displayCount;

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


UBCBaseSharedPtr GUISystem::getBase()  // retrieves the value of base
{
    return(base);
}
void GUISystem::setBase(UBCBaseSharedPtr set)  // sets the value of base
{
    base = set;
}

/*sharedPtr<networkEngimmnmne> GUISystem::getNetworkG()  // retrieves the value of network
{
    return (networkG);
}
void GUISystem::setNetworkG(networkEngineSharedPtr set)  // sets the value of network
{
    networkG = set;
}

sharedPtr<renderEngine> GUISystem::getRenderE()  // retrieves the value of render
{
    return (render);
}
void GUISystem::setRender(sharedPtr<renderEngine> set)  // sets the value of render
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


MyGUIGuiSharedPtr GUISystem::getMGUI()  // retrieves the value of mGUI
{
    return (mGUI);
}
void GUISystem::setMGUI(MyGUIGuiSharedPtr set)  // sets the value of mGUI
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
//    exit(0);
    if (base->getGameS() == NULL)
    {
        exit(0);
    }
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
//    sharedPtr<renderEngine> render = renderEngine::Instance();
//    Ogre::RenderWindow *mWindow = render->getMWindow();
//    Ogre::SceneManager *mSceneMgr = render->getMSceneMgr();

    logMsg("*** Initializing MyGUI ***");
    MyGUIOgrePlatformSharedPtr tempPlatform(new MyGUI::OgrePlatform());
    mPlatform = tempPlatform;
    logMsg("Crash?");
//    exit(0);
/*#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    mPlatform->initialise(mWindow, mSceneMgr, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
#else
*/
    mPlatform->initialise(base->getGameE()->getRenderE()->getMWindow().get(), base->getGameE()->getRenderE()->getMSceneMgr().get(), "UBCData"); // mWindow is Ogre::RenderWindow*, mSceneManager is Ogre::SceneManager*
//#endif
//    exit(0);
    logMsg("Crash??");
    MyGUIGuiSharedPtr tempGUI(new MyGUI::Gui());
//    exit(0);
    mGUI = tempGUI;
//    exit(0);
    logMsg("Crash???");
    mGUI->initialise();
//    exit(0);
    logMsg("*** MyGUI Initialized ***");
    return true;
}

void GUISystem::mainMenu()  // msin in game menu
{
//    exit(0);
    std::string func = "GUISystem::mainMenu()";
    
    logMsg(func + " beginning");
    

    if (!mainMenuCreated)
    {
        logMsg("mainMenu not created yet!");
//        exit(0);
        if (createMainMenuGUI()) // creates the main menu gui.
        {
            logMsg("Main Menu created successfully!");
            mainMenuCreated = true;
//            exit(0);
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
    logMsg(func +" beginning");

    activeMenu = MAIN;
    
    logMsg(func + " end");
    
//    exit(0);
}

void GUISystem::backButtons()  // handles the back buttons
{

    if (!backButtonsCreated)
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

void GUISystem::startSinglePlayerGame()  // starts single player game
{
//    sharedPtr<gameState> gameS = gameState::Instance();
//    exit(0);
//    gameS->setGameType(SINGLE);
    
    std::string func = "GUISystem::startSinglePlayerGame()";

    base->getGameS()->setGameType(SINGLE);

//    exit(0);
//    hideMainMenuWidgets();	// Hides the widgets from the main menu
    courtSelectionMenu();   // displays the menu for selecting which court to use
    //   gameSetupMenu();
//	menuActive = false;
    
    logMsg(func +" end");
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
    std::string func = "GUISystem::playerStartSelectionMenu()";
    
    logMsg(func +" beginning");
    

    if (!playerStartSelectionMenuCreated)
    {
        logMsg(func +" !playerStartSelectionMenuCreated");
//         exit(0);
        
        if (createPlayerStartSelectionMenuGUI())
        {
            logMsg(func +" createPlayerStartSelectionMenuGUI!");
            playerStartSelectionMenuCreated = true;
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
    changeActiveMenu(PLAYERSTART);
    logMsg(func +" end");
//    exit(0);
}

void GUISystem::teamSelectionMenu()  // displays team selection menu
{
/*    exit(0);
    hideCourtSelectionMenuWidgets();
    createTeamSelectionMenuGUI();
    showTeamSelectionMenuWidgets();
//    changeActiveMenu(TEAMSELECT);
    sharedPtr<loader> load; // = loader::Instance();
*/
    bool changeMenu = false;  // determinrs if menu is to be changed
//    teamStateVecSharedPtr teamInstance; // = gameS->getTeamDataInstance();

    logMsg("teamSelectionMenu");

//    teamInstance = load->loadTeams();
//    exit(0);
    if (teamSelectionMenuCreated)
    {      
//        exit(0);
        if (base->getGameS()->getTeamInstancesCreated())
        {
            logMsg("getTeamInstancesCreated");
//            exit(0);
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
            logMsg("!getTeamInstancesCreated");
//            exit(0);
            if (base->getGameS()->createTeamInstances())
            {
                logMsg("createTeamInstances");

//                exit(0);
                base->getGameS()->setTeamInstancesCreated(true);
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
//            exit(0);
            if (addTeamStartSelectionMenuData())
            {
                
                logMsg("GUI teamSelectionMenu() addTeamStartSelectionMenuData()!");
//                exit(0);
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
            exit(0);
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
//    sharedPtr<gameState> gameS = gameState::Instance();
    sharedPtr<conversion> convert = conversion::Instance();
//    sharedPtr<loader> load; // = loader::Instance();
    std::string func = "GUISystem::courtSelectionMenu()";
    
    logMsg(func +" beginning");
    
    
    if (!courtSelectionMenuCreated)
    {
        createCourtSelectionMenuGUI();
    }
//    exit(0);
    if (!courtSelectionDataLoaded)
    {
//        exit(0);
        logMsg("addCourtSelectionMenuData = " +convert->toString(addCourtSelectionMenuData()));
//        exit(0);
        if (addCourtSelectionMenuData())
        {
//            exit(0);
            courtSelectBox->setIndexSelected(0);
            courtSelectionDataLoaded = true;
        }
        else
        {
            exit(0);

        }
//        exit(0);
    }

    changeActiveMenu(COURTSELECT);
//    exit(0);
    
    logMsg(func +" end");
}


void GUISystem::setSelectedIndexes()  // sets all player listbox indexes to zero
{
    std::string func = "GUISystem::setSelectedIndexes()";
    
    logMsg(func +" beginning");
    
    teamPlayerPosSelectBox[0]["PG"]->setIndexSelected(0);
    logMsg(func +" PG0");
    
    teamPlayerPosSelectBox[0]["SG"]->setIndexSelected(0);
    teamPlayerPosSelectBox[0]["SF"]->setIndexSelected(0);
    teamPlayerPosSelectBox[0]["PF"]->setIndexSelected(0);
    teamPlayerPosSelectBox[0]["C"]->setIndexSelected(0);
    teamPlayerPosSelectBox[1]["PG"]->setIndexSelected(0);
    teamPlayerPosSelectBox[1]["SG"]->setIndexSelected(0);
    teamPlayerPosSelectBox[1]["SF"]->setIndexSelected(0);
    teamPlayerPosSelectBox[1]["PF"]->setIndexSelected(0);
    teamPlayerPosSelectBox[1]["C"]->setIndexSelected(0);
    
    logMsg(func +" end");

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
//    networkEngineSharedPtr network = networkEngine::Instance();
    //gameEngine * gameE = gameEngine::Instance();
//    sharedPtr<gameEngine> gameE = gameEngine::Instance();
    //gameState *gameS = gameState::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();

//    gameS->setGameType(MULTI);
    base->getGameS()->setGameType(MULTINET);
//   hideNetworkSetupWidgets();  // Hides Network Setup Menu widgets
    menuActive = false;
    base->getGameE()->getNetworkE()->setIPAddress(serverIPAddressBox->getCaption());  // sets the neworkEngine's ipAddress string to that of the caption
    logMsg("server ip = " +base->getGameE()->getNetworkE()->getIPAddress());
    if (base->getGameE()->getNetworkE()->serverSetup())  // attempts to setup as a network server
    {
        base->getGameE()->getNetworkE()->setIsServer(true);  // if successful sets isServer to true
    }

//    gameE->setCreateScene(true); // sets variable true that tells gameEngine to start rendering the scene

}
void GUISystem::networkClient()  // sets up game as a network client
{
//    networkEngineSharedPtr network = networkEngine::Instance();
//    sharedPtr<gameEngine> gameE = gameEngine::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();

//    gameS->setGameType(MULTI);
    base->getGameS()->setGameType(MULTINET);
//    hideNetworkSetupWidgets();  // Hides Network Setup Menu widgets
    menuActive = false;
    base->getGameE()->getNetworkE()->setIPAddress(clientIPAddressBox->getCaption());  // sets the neworkEngine's ipAddress string to that of the caption
//    network->networkClient();
    if (base->getGameE()->getNetworkE()->clientConnect()) // attempts to connect to the remote server
    {
        base->getGameE()->getNetworkE()->setIsClient(true);  // if successful sets isClient to true
    }
//    gameE->setCreateScene(true); // sets variable true that tells gameEngine to start rendering the scenetop

}

void GUISystem::courtSelected()  // processes court selection
{
    //conversion *convert = conversion::Instance();
    sharedPtr<conversion> convert = conversion::Instance();
    //gameState *gameS = gameState::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
    std::string func = "GUISystem::courtSelected()";
    
    logMsg(func +" beginning");

    logMsg(func +" Selected Court #" +convert->toString(courtSelectBox->getIndexSelected()));
//    gameS->setSelectedCourtDataInstance(courtSelectBox->getIndexSelected());
//    gameS->setActiveCourtInstance(courtSelectBox->getIndexSelected());
    //FIXME! needs reworked!
///    base->getGameS()->setActiveCourtInstance(courtSelectBox->getIndexSelected());
//    exit(0);
//    changeActiveMenu(TEAMSELECT);
//    teamSelectionMenu();

    logMsg(func +" end");

}

void GUISystem::teamsSelected()  // processes team selection
{
//    exit(0);
    //gameState *gameS = gameState::Instance();
    sharedPtr<conversion> convert = conversion::Instance();
    teamStateUMSharedPtr activeTeamInstance;
    teamStateUMSharedPtr teamInstance;
    std::string func = "GUISystem::teamsSelected()";
  
    teamInstance = base->getGameS()->getTeamInstance();
    
    logMsg(func +" beginning");

    sizeTVec teamID;
    teamID.push_back(teamSelectBox[0]->getIndexSelected());
    teamID.push_back(teamSelectBox[1]->getIndexSelected());
    activeTeamInstance.insert(std::pair<size_t, teamStateSharedPtr>(teamID[0], teamInstance[teamID[0]]));
    activeTeamInstance.insert(std::pair<size_t, teamStateSharedPtr>(teamID[1], teamInstance[teamID[1]]));
    // sets the base class of the teamInstance objects to the same as the GUI which avoids crashes due to uninitialized sharedPtrs
    activeTeamInstance[0]->setBase(base);
    activeTeamInstance[1]->setBase(base);
    
    //    gameS->setTeamID(teamID);
    logMsg(func +" teamSelectBox[0]->getIndexSelected() == " +convert->toString(teamSelectBox[0]->getIndexSelected()));
    logMsg(func +" teamID[0] == " +convert->toString(teamID[0]));
//    exit(0);
    base->getGameS()->setTeamIDS(teamID);
    base->getGameS()->setActiveTeamInstance(activeTeamInstance);
    base->getGameS()->setActiveTeamInstancesCreated(true);
 
    logMsg(func +" Teams selected");
    
    logMsg(func +" end");

//    exit(0);
}

void GUISystem::playerStartSelected()  // process player start selection
{
    conversionSharedPtr convert = conversion::Instance();
    std::vector<std::unordered_map <std::string, std::string> > teamStarters;
    std::unordered_map <std::string, std::string> tempStarters;
//    teamStarters.push_back(tempStarters);
    std::unordered_map<std::string, size_t> tempStarterID; // used for initial creatio  of teamStarterID vector
    teamStateUMSharedPtr activeTeamInstance = base->getGameS()->getActiveTeamInstance();
  
//    std::vector<playerStateUMSharedPtr > playerInstance;
    playerEntityVecUMSharedPtr playerInstance;
//    std::unordered_map<std::string, playerStateSharedPtr> activePlayerInstance;
    playerEntityUMSharedPtr activePlayerInstance;
//    std::unordered_map<playerPositions, playerEntitySharedPtr, std::hash<int> > activePlayerInstance;
    size_t IDs = 0;
    std::string func = "GUISystem::playerStartSelected()";


    for (auto ATIIT : activeTeamInstance)  // loop through activeTeamInstance
    {
        teamStarters.push_back(tempStarters);  // add empty entry to teamStarters

        for (auto it : activeTeamInstance[ATIIT.first]->getPlayerInstance())
        {
            logMsg(func +" team dee " +convert->toString(ATIIT.first) +" " +it.second->getData()->getFirstName() +" " +it.second->getData()->getLastName());
        }
        playerInstance.insert(playerInstance.begin(), activeTeamInstance[ATIIT.first]->getPlayerInstance());  // add activeTeamInstances player instance to playerInstance
    }
    
    playerEntityVecUMSharedPtr::iterator PIIT;
    
    for (PIIT = playerInstance.begin(); PIIT != playerInstance.end(); ++PIIT)
    {
        for (auto it : *PIIT)
        {
            logMsg(func +" team dah " +it.second->getData()->getFirstName() +" " +it.second->getData()->getLastName());
        }
    }
//    exit(0);
//    playerInstance = base->getGameS()->getActiveTeamInstance()[0]->getPlayerInstance();

    
/*    while (teamStarterID.size() < 2)
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
*/
    // checks to make sure that all player selectBoxes have a valid index value
    if (teamPlayerPosSelectBox[0]["PG"]->getIndexSelected() < 0 || teamPlayerPosSelectBox[0]["PG"]->getIndexSelected() > teamPlayerPosSelectBox[0]["PG"]->getItemCount())
    {
        teamPlayerPosSelectBox[0]["PG"]->setIndexSelected(0);
    }
    if (teamPlayerPosSelectBox[0]["SG"]->getIndexSelected() < 0 || teamPlayerPosSelectBox[0]["SG"]->getIndexSelected() > teamPlayerPosSelectBox[0]["SG"]->getItemCount())
    {
        teamPlayerPosSelectBox[0]["SG"]->setIndexSelected(0);
    }
    if (teamPlayerPosSelectBox[0]["SF"]->getIndexSelected() < 0 || teamPlayerPosSelectBox[0]["SF"]->getIndexSelected() > teamPlayerPosSelectBox[0]["SF"]->getItemCount())
    {
        teamPlayerPosSelectBox[0]["SF"]->setIndexSelected(0);
    }
    if (teamPlayerPosSelectBox[0]["PF"]->getIndexSelected() < 0 || teamPlayerPosSelectBox[0]["PF"]->getIndexSelected() > teamPlayerPosSelectBox[0]["PF"]->getItemCount())
    {
        teamPlayerPosSelectBox[0]["PF"]->setIndexSelected(0);
    }
    if (teamPlayerPosSelectBox[0]["C"]->getIndexSelected() < 0 || teamPlayerPosSelectBox[0]["C"]->getIndexSelected() > teamPlayerPosSelectBox[0]["C"]->getItemCount())
    {
        teamPlayerPosSelectBox[0]["C"]->setIndexSelected(0);
    }
    if (teamPlayerPosSelectBox[1]["PG"]->getIndexSelected() < 0 || teamPlayerPosSelectBox[1]["PG"]->getIndexSelected() > teamPlayerPosSelectBox[1]["PG"]->getItemCount())
    {
        teamPlayerPosSelectBox[1]["PG"]->setIndexSelected(0);
    }
    if (teamPlayerPosSelectBox[1]["SG"]->getIndexSelected() < 0 || teamPlayerPosSelectBox[1]["SG"]->getIndexSelected() > teamPlayerPosSelectBox[1]["SG"]->getItemCount())
    {
        teamPlayerPosSelectBox[1]["SG"]->setIndexSelected(0);
    }
    if (teamPlayerPosSelectBox[1]["SF"]->getIndexSelected() < 0 || teamPlayerPosSelectBox[1]["SF"]->getIndexSelected() > teamPlayerPosSelectBox[1]["SF"]->getItemCount())
    {
        teamPlayerPosSelectBox[1]["SF"]->setIndexSelected(0);
    }
    if (teamPlayerPosSelectBox[1]["PF"]->getIndexSelected() < 0 || teamPlayerPosSelectBox[1]["PF"]->getIndexSelected() > teamPlayerPosSelectBox[1]["PF"]->getItemCount())
    {
        teamPlayerPosSelectBox[1]["PF"]->setIndexSelected(0);
    }
    if (teamPlayerPosSelectBox[1]["C"]->getIndexSelected() < 0 || teamPlayerPosSelectBox[1]["C"]->getIndexSelected() > teamPlayerPosSelectBox[1]["C"]->getItemCount())
    {
        teamPlayerPosSelectBox[1]["C"]->setIndexSelected(0);
    }
    
    //FIXME! Should be converted into a loop to iterate 
    
//    teamStarterID[0][0] = team0IDs[0][team0PGSelectBox->getIndexSelected()];
    auto w = 0;
//    std::vector<std::unordered_map <std::string, std::string> >::iterator TSIT;
//    for (TSIT = teamStarters.begin(); TSIT != teamStarters.end(); ++TSIT)

    std::vector<std::unordered_map <std::string, std::string> >::iterator TSVIT;
    for (TSVIT = teamStarters.begin(); TSVIT != teamStarters.end(); ++TSVIT)
    {

        TSVIT->insert(std::pair<std::string, std::string>("PG", teamPlayerPosSelectBox[w]["PG"]->getItemNameAt(teamPlayerPosSelectBox[w]["PG"]->getIndexSelected())));
        TSVIT->insert(std::pair<std::string, std::string>("SG", teamPlayerPosSelectBox[w]["SG"]->getItemNameAt(teamPlayerPosSelectBox[w]["SG"]->getIndexSelected())));
        TSVIT->insert(std::pair<std::string, std::string>("SF", teamPlayerPosSelectBox[w]["SF"]->getItemNameAt(teamPlayerPosSelectBox[w]["SF"]->getIndexSelected())));
        TSVIT->insert(std::pair<std::string, std::string>("PF", teamPlayerPosSelectBox[w]["PF"]->getItemNameAt(teamPlayerPosSelectBox[w]["PF"]->getIndexSelected())));
        TSVIT->insert(std::pair<std::string, std::string>("C", teamPlayerPosSelectBox[w]["C"]->getItemNameAt(teamPlayerPosSelectBox[w]["C"]->getIndexSelected())));
        ++w;
    }
    logMsg(func +" teamStarters[0][PG] == " +teamStarters[0]["PG"]);
//    exit(0);
/*    std::unordered_map<std::string, size_t> tempStarterID;

    while (teamStarterID.size() < 2)
    {
        teamStarterID.push_back(tempStarterID);
    }
    logMsg("teamStarterID.size() == " +convert->toString(teamStarterID.size()));
    exit(0);
    w = 0;
    std::vector<std::unordered_map<std::string, size_t> >::iterator TSIDIT;
    std::vector<std::unordered_map <std::string, std::string> > TSIT;
    for (TSIDIT = teamStarterID.begin(); TSIDIT != teamStarterID.end(); ++TSIDIT)
    {
//        TSIDIT.push_back();
//        TSIDIT.insert(std::pair<std::string, size_t>("PG", PIIT.second->getData()->getID()));

    }
*/
    for (TSVIT = teamStarters.begin(); TSVIT != teamStarters.end(); ++ TSVIT)  // loop that adds starting player IDs to teamStarterID
    {
        for (auto TSVUIT : *TSVIT)
        {
            teamStarterID.push_back(tempStarterID);  // add entry to tesmStarterID for every activeTeamInstance

            for (auto ATIIT : activeTeamInstance)  // loop through activeTeamInstance
            {
                        
                for (auto PIIT : ATIIT.second->getPlayerInstance())
                {
                    std::string playerName = PIIT.second->getData()->getFirstName() +" " +PIIT.second->getData()->getLastName();
                    if (playerName == TSVUIT.second && TSVUIT.first == "PG")
                    {
                        logMsg(func +" PG Player ID == " +convert->toString(PIIT.second->getData()->getID()));
///                    TSIDUIT.insert(std::pair<std::string, size_t>("PG", PIIT.second->getData()->getID()));
                    }
                    else if (playerName == TSVUIT.second && TSVUIT.first == "SG")
                    {
                        logMsg(func +" SG Player ID == " +convert->toString(PIIT.second->getData()->getID()));

///                    teamStarterID[w].insert(std::pair<std::string, size_t>("SG", PIIT.second->getData()->getID()));
    //                logMsg("teamStarterID[w][SG] Player ID == " +convert->toString(teamStarterID[w][SG]));

                    }
                    else if (playerName == TSVUIT.second && TSVUIT.first == "SF")
                    {
                        logMsg(func +" SF Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                        teamStarterID[w].insert(std::pair<std::string, size_t>("SF", PIIT.second->getData()->getID()));
                    }
                    else if (playerName == TSVUIT.second && TSVUIT.first == "PF")
                    {
                        logMsg(func +" PF Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                        teamStarterID[w].insert(std::pair<std::string, size_t>("PF", PIIT.second->getData()->getID()));
                    }
                    else if (playerName == TSVUIT.second && TSVUIT.first == "C")
                    {
                        logMsg(func +" C Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                        teamStarterID[w].insert(std::pair<std::string, size_t>("C", PIIT.second->getData()->getID()));
                    }
                }
            }
        }
    }
/*        for (auto TSVUIT : *TSVIT)
        {
            for (TSIDIT = teamStarterID.begin(); TSIDIT != teamStarterID.end(); ++TSIDIT)
            {
                for (auto TSIDUIT : *TSIDIT)
                {
            for (auto PIIT : playerInstance[w])
            {
                std::string playerName = PIIT.second->getData()->getFirstName() +" " +PIIT.second->getData()->getLastName();
                logMsg(func +" playerInstance playerName == " +playerName);
                logMsg(func +" Primary Position == " +convert->toString(PIIT.second->getData()->getPrimaryPosition()));
                logMsg(func +" Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                auto y = 0;

                if (playerName == TSVUIT.second && TSVUIT.first == "PG")
                {

                    logMsg(func +" PG Player ID == " +convert->toString(PIIT.second->getData()->getID()));
//                    TSIDUIT.insert(std::pair<std::string, size_t>("PG", PIIT.second->getData()->getID()));
                }
                else if (playerName == TSVUIT.second && TSVUIT.first == "SG")
                {
                    logMsg(func +" SG Player ID == " +convert->toString(PIIT.second->getData()->getID()));

                    teamStarterID[w].insert(std::pair<std::string, size_t>("SG", PIIT.second->getData()->getID()));
    //                logMsg("teamStarterID[w][SG] Player ID == " +convert->toString(teamStarterID[w][SG]));

                }
                else if (playerName == TSVUIT.second && TSVUIT.first == "SF")
                {
                    logMsg(func +" SF Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                    teamStarterID[w].insert(std::pair<std::string, size_t>("SF", PIIT.second->getData()->getID()));
                }
                else if (playerName == TSVUIT.second && TSVUIT.first == "PF")
                {
                    logMsg(func +" PF Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                    teamStarterID[w].insert(std::pair<std::string, size_t>("PF", PIIT.second->getData()->getID()));
                }
                else if (playerName == TSVUIT.second && TSVUIT.first == "C")
                {
                    logMsg(func +" C Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                    teamStarterID[w].insert(std::pair<std::string, size_t>("C", PIIT.second->getData()->getID()));
                }
    //            ++x;
            }
                }
            }
        }
        ++w;
    }
*/
    //    teamStarterID[0][0] = [
                          //team0IDs[0][teamPlayerPosSelectBox[0]["PG"]->getIndexSelected()];
    
    logMsg(func +" teamStarterID[0][PG] = " +convert->toString(teamStarterID[0]["PG"]));
    logMsg(func +" teamStarterID[0][SG] = " +convert->toString(teamStarterID[0]["SG"]));
    logMsg(func +" teamStarterID[0][SF] = " +convert->toString(teamStarterID[0]["SF"]));
    logMsg(func +" teamStarterID[0][PF] = " +convert->toString(teamStarterID[0]["PF"]));
    logMsg(func +" teamStarterID[0][C] = " +convert->toString(teamStarterID[0]["C"]));

    exit(0);
/*    team0Starters.push_back(teamPlayerPosSelectBox[0]["SG"]->getItemNameAt(teamPlayerPosSelectBox[0]["SG"]->getIndexSelected()));
    teamStarterID[0][1] = team0IDs[1][teamPlayerPosSelectBox[0]["SG"]->getIndexSelected()];
    logMsg("teamStarterID[0][1] = " +convert->toString(teamStarterID[0][1]));
    team0Starters.push_back(teamPlayerPosSelectBox[0]["SF"]->getItemNameAt(teamPlayerPosSelectBox[0]["SF"]->getIndexSelected()));
    teamStarterID[0][2] = team0IDs[2][teamPlayerPosSelectBox[0]["SF"]->getIndexSelected()];
    logMsg("teamStarterID[0][2] = " +convert->toString(teamStarterID[0][2]));
    team0Starters.push_back(teamPlayerPosSelectBox[0]["PF"]->getItemNameAt(teamPlayerPosSelectBox[0]["PF"]->getIndexSelected()));
    teamStarterID[0][3] = team0IDs[3][teamPlayerPosSelectBox[0]["SF"]->getIndexSelected()];
    logMsg("teamStarterID[0][3] = " +convert->toString(teamStarterID[0][3]));
    team0Starters.push_back(teamPlayerPosSelectBox[0]["C"]->getItemNameAt(teamPlayerPosSelectBox[0]["C"]->getIndexSelected()));
    teamStarterID[0][4] = team0IDs[4][teamPlayerPosSelectBox[0]["C"]->getIndexSelected()];
    logMsg("teamStarterID[0][4] = " +convert->toString(teamStarterID[0][4]));
    team1Starters.push_back(teamPlayerPosSelectBox[1]["PG"]->getItemNameAt(teamPlayerPosSelectBox[1]["PG"]->getIndexSelected()));
    teamStarterID[1][0] = team1IDs[0][teamPlayerPosSelectBox[1]["PG"]->getIndexSelected()];
    logMsg("teamStarterID[1][0] = " +convert->toString(teamStarterID[1][0]));
    team1Starters.push_back(teamPlayerPosSelectBox[1]["SG"]->getItemNameAt(teamPlayerPosSelectBox[1]["SG"]->getIndexSelected()));
    teamStarterID[1][1] = team1IDs[1][teamPlayerPosSelectBox[1]["SG"]->getIndexSelected()];
    logMsg("teamStarterID[1][1] = " +convert->toString(teamStarterID[1][1]));
    team1Starters.push_back(teamPlayerPosSelectBox[1]["SF"]->getItemNameAt(teamPlayerPosSelectBox[1]["SF"]->getIndexSelected()));
    teamStarterID[1][2] = team1IDs[2][teamPlayerPosSelectBox[1]["SF"]->getIndexSelected()];
    logMsg("teamStarterID[1][2] = " +convert->toString(teamStarterID[1][2]));
    team1Starters.push_back(teamPlayerPosSelectBox[1]["PF"]->getItemNameAt(teamPlayerPosSelectBox[1]["PF"]->getIndexSelected()));
    teamStarterID[1][3] = team1IDs[3][teamPlayerPosSelectBox[1]["PF"]->getIndexSelected()];
    logMsg("teamStarterID[1][3] = " +convert->toString(teamStarterID[1][3]));
    team1Starters.push_back(teamPlayerPosSelectBox[1]["C"]->getItemNameAt(teamPlayerPosSelectBox[1]["C"]->getIndexSelected()));
    teamStarterID[1][4] = team1IDs[4][teamPlayerPosSelectBox[1]["C"]->getIndexSelected()];
    logMsg("teamStarterID[1][4] = " +convert->toString(teamStarterID[1][4]));
*/
//    exit(0);
//    gameS->setTeamStarterID(teamStarterID); // sets the selected starters for both teams in gameState class
    base->getGameS()->setTeamStarterID(teamStarterID); // sets the selected starters for both teams in gameState class
    
    sizeTVec activePlayerID;
//    x = 0;
    logMsg(func +" activePlayerID!");
/*    while (x < 5)
    {
        activePlayerID.push_back(teamStarterID[0][x]);
        logMsg("activePlayerID = " +convert->toString(activePlayerID[x]));
        ++x;
    }
*/
//    exit(0);
    base->getGameS()->getActiveTeamInstance()[0]->setActivePlayerID(activePlayerID);

    logMsg(func +" activeTeamInstance.size() == " +convert->toString(activeTeamInstance.size()));
    for (auto ATIIT : activeTeamInstance)
    {
        logMsg("ATIIT.second->getPlayerInstancesCreated() == " +convert->toString(ATIIT.second->getPlayerInstancesCreated()));
        if (!ATIIT.second->getPlayerInstancesCreated())    // checks if playerInstances have been created
        {
            logMsg(func +" activeTeamInstance " +convert->toString(ATIIT.first) +" Player Instances NOT Created!");
//            exit(0);
            if( ATIIT.second->createPlayerInstances())
            {
                ATIIT.second->setPlayerInstancesCreated(true);
                base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                logMsg("activeTeamInstance " +convert->toString(ATIIT.first) + " Player Instances Created Successfully!");
            }
            else
            {
                logMsg("activeTeamInstance " +convert->toString(ATIIT.first) + " Player Instances NOT CREATED!");
                exit(0);
            }
/*            base->getGameS()->getActiveTeamInstance()[0]->setBase(base);
            if (base->getGameS()->getActiveTeamInstance()[0]->createPlayerInstances()) // creates the player instances based on playerIDS
            {
                logMsg(func +" Team 0 Player instances created!");
                base->getGameS()->getActiveTeamInstance()[0]->setPlayerInstancesCreated(true);
    //          exit(0);
            }
*/
        }
    }
    
    // create active player Instancea
    for (auto ATIIT : activeTeamInstance)
    {
        logMsg(func +" ATIIT.first == " +convert->toString(ATIIT.first));
        activePlayerInstance.clear();

        for (auto PIIT : ATIIT.second->getPlayerInstance())
        {
            logMsg(func +" ATIIT.first == " +convert->toString(ATIIT.first) +" PIIT.second->getData()->getID() == " +convert->toString(PIIT.second->getData()->getID()) +" primaryPosition == " +convert->toString(PIIT.second->getData()->getPrimaryPosition()));
            std::string teamStarterIDPG = convert->toString(teamStarterID[1]["PG"]);
//            logMsg("teamStarterID[ATIIT.first][PG] == " +teamStarterIDPG);
  
            if (PIIT.second->getData()->getID() == teamStarterID[ATIIT.first]["PG"])
            {
                logMsg(func +" PG");
                activePlayerInstance.insert(std::pair<playerPositions, playerEntitySharedPtr>(PG, PIIT.second));
                activePlayerInstance[PG]->setActivePosition(PG);
                logMsg(func +" WOOT PG!");
            }
            else if (PIIT.second->getData()->getID() == teamStarterID[ATIIT.first]["SG"])
            {
                activePlayerInstance.insert(std::pair<playerPositions, playerEntitySharedPtr>(SG, PIIT.second));
                activePlayerInstance[SG]->setActivePosition(SG);
                logMsg(func +" WOOT SG!");
            }
            else if (PIIT.second->getData()->getID() == teamStarterID[ATIIT.first]["SF"])
            {
                activePlayerInstance.insert(std::pair<playerPositions, playerEntitySharedPtr>(SF, PIIT.second));
                activePlayerInstance[SF]->setActivePosition(SF);
                logMsg(func +" WOOT SF!");
            }
            else if (PIIT.second->getData()->getID() == teamStarterID[ATIIT.first]["PF"])
            {
                activePlayerInstance.insert(std::pair<playerPositions, playerEntitySharedPtr>(PF, PIIT.second));
                activePlayerInstance[PF]->setActivePosition(PF);
                logMsg(func +" WOOT PF!");
            }
            else if (PIIT.second->getData()->getID() == teamStarterID[ATIIT.first]["C"])
            {
                activePlayerInstance.insert(std::pair<playerPositions, playerEntitySharedPtr>(C, PIIT.second));
                activePlayerInstance[C]->setActivePosition(C);
                logMsg(func +" WOOT C!");
            }
            logMsg(func +" WOOT!");
        }
        ATIIT.second->setActivePlayerInstance(activePlayerInstance);
        ATIIT.second->setActivePlayerInstancesCreated(true);
        ATIIT.second->setActivePlayerInstancesChanged(true);

//        ATIIT.second->setPlayerStartActivePositions();
        logMsg(func +" team name == " +ATIIT.second->getName());

        logMsg(func +" activePlayerInstance.size() == " +convert->toString(activePlayerInstance.size()));
    }
    base->getGameS()->setActiveTeamInstance(activeTeamInstance);
//    exit(0);
//    playerInstance.clear();
//    activePlayerInstance.clear();
/*    playerInstance = base->getGameS()->getActiveTeamInstance()[0]->getPlayerInstance();
    auto y = 0;
    logMsg("GUI playerInstance.size() = " +convert->toString(playerInstance.size()));
    
    while (y < playerInstance.size())
    {
        auto z = 0;
        while (z < activePlayerID.size())
        {
            if (playerInstance[y].get()->getID() == activePlayerID[z])
            {
                activePlayerInstance.insert(std::pair<size_t, playerStateSharedPtr>(y,playerInstance[y]));
                logMsg("GUI playerInstance[y] ID  = " +convert->toString(playerInstance[y]->getID()));
    
            }
            ++z;
        }
        ++y;
    }
//    exit(0);
    logMsg("GUI activePlayerInstance.size() = " +convert->toString(activePlayerInstance.size()));
    base->getGameS()->getActiveTeamInstance()[0]->setActivePlayerInstance(activePlayerInstance);
    base->getGameS()->getActiveTeamInstance()[0]->setPlayerStartActivePositions();
    
    base->getGameS()->getActiveTeamInstance()[0]->setPlayerStartPositions();
//    logMsg("Team 0 player start positions set");
//    exit(0);
    size_t i = 0;
    //playerStateVec playerInstance;
    playerInstance.clear();
    playerInstance = base->getGameS()->getActiveTeamInstance()[0]->getPlayerInstance();
    while (i<playerInstance.size())
    {
        if (activePlayerID[4] == playerInstance[i]->getID())
        {
            base->getGameS()->getActiveTeamInstance()[0]->setHumanPlayer(i);
            logMsg("human player set!");
        }
        i++;
    }
    
    activePlayerID.clear();
    for (size_t x=0;x<5;++x)
    {
        activePlayerID.push_back(teamStarterID[1][x]);
    }

    base->getGameS()->getActiveTeamInstance()[1]->setActivePlayerID(activePlayerID);
    if (!base->getGameS()->getActiveTeamInstance()[1]->getPlayerInstancesCreated())  // checks if playerInstances have been created
    {
        logMsg("Creating team 1 player instances");
//            exit(0);
        base->getGameS()->getActiveTeamInstance()[1]->setBase(base);

        if (base->getGameS()->getActiveTeamInstance()[1]->createPlayerInstances())  // creates the player instances based on playerIDS
        {
//            exit(0);

            logMsg("Player instances created!");
            base->getGameS()->getActiveTeamInstance()[1]->setPlayerInstancesCreated(true);
//          exit(0);
        }
//.        exit(0);

    }
    playerInstance.clear();
    playerInstance = base->getGameS()->getActiveTeamInstance()[1]->getPlayerInstance();
    activePlayerInstance.clear();
    y = 0;
    while (y < playerInstance.size())
    {
        size_t z = 0;
        while (z < activePlayerID.size())
        {
            if (playerInstance[y]->getID() == activePlayerID[z])
            {
                activePlayerInstance.insert(std::pair<size_t, playerStateSharedPtr>(y, playerInstance[y]));
            }
            ++z;
        }
        ++y;
    }

    base->getGameS()->getActiveTeamInstance()[1]->setActivePlayerInstance(activePlayerInstance);
    base->getGameS()->getActiveTeamInstance()[1]->setPlayerStartActivePositions();
    base->getGameS()->getActiveTeamInstance()[1]->setPlayerStartPositions();
    logMsg("Team 1 player start positions set");
    playerInstance = base->getGameS()->getActiveTeamInstance()[1]->getPlayerInstance();
    while (i<playerInstance.size())
    {
        if (activePlayerID[4] == playerInstance[i]->getID())
        {
            base->getGameS()->getActiveTeamInstance()[1]->setHumanPlayer(i);
            logMsg("human player set!");
        }
        i++;
    }
    */
    if (base->getGameS()->getActiveTeamInstance()[0]->getPlayerInstancesCreated() && base->getGameS()->getActiveTeamInstance()[1]->getPlayerInstancesCreated())
    {
///        base->getGameS()->setActiveTeamInstance(activeTeamInstance);  // sets the activeTeamInstance vector
//        base->getGameS()->setGameSetupComplete(true);
        base->getGameS()->setGameSetupComplete(true);
        
    }
    else
    {
        logMsg("Team Instances NOT created!");
        exit(0);
    }

/*    logMsg("team 0 C selectbox id = " +convert->toString(teamStarterID[0][1]));
    logMsg("team 0 starter 0 = " +convert->toString(teamStarterID[0][0]));
    logMsg("team  0 starter 0 = " +team0Starters[0]);
*/
//        exit(0);

    hideActiveMenuWidgets();
    menuActive = false;
    base->getGameE()->setMenuActive(false);

//    exit(0);

}

void GUISystem::gameSetupAwaySelected()  // processes away team selectdion on game setup menu
{
    MyGUI::InputManager::getInstance().setKeyFocusWidget(teamSelectBox[1].get());
    gameSetupMenuAwaySelected = true;
    gameSetupMenuHomeSelected = false;
}

void GUISystem::gameSetupHomeSelected()  // process home team selection on game setup menu
{
    MyGUI::InputManager::getInstance().setKeyFocusWidget(teamSelectBox[1].get());
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
//    sharedPtr<gameState> gameS = gameState::Instance();

    if (!base->getGameS()->getActiveTeamInstancesCreated())
    {
//        base->getGameS()->setActiveTeamInstancesNeedCreated(true);
/*        logMsg("Creating active team instances!");
        gameS->FFFcreateActiveTeamInstances();
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
