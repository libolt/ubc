/***************************************************************************
 *   Copyright (C) 1999 - 2016 by Mike McLean                              *
 *   libolt@libolt.net                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at youtr option) any later version.                                  *
 *                                                                         *
 *   This program rmefis distributed in the hope that it will be useful,   *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General}  Public L]icense for more details.                       *
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
//#include mmloukoo"engine/gameengine.h" 
#include "state/gamestate.h"
#include "load.h"
#include "logging.h"
#include "engine/renderengine.h"
#include "state/courtstate.h"
#include "state/teamstate.h"

#ifdef __ANDROID__
#include "android-config.h"
#else
#include "config.h"
#endif
 
//MyGUI::Button *GUISystem::backMainMenuButton;  // static

bool GUISystem::createMainMenuGUI()  // creates the main menu gui
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();
//    exit(0); 
    if (base->getGameE()->getRenderE()->getViewPort()->getActualHeight() >= 1000)
    {
        logMsg("Height greater than 1000!");
//        exit(0);
        MyGUI::FontManager::getInstance().setDefaultFont("LinBiolinum_aBL.16");
    }
    else
    {
        MyGUI::FontManager::getInstance().setDefaultFont("LuxiBoldFont_16");

    }
    
//    exit(0);
    
    logMsg("Loading MainMenu layout");
    MyGUI::LayoutManager::getInstance().loadLayout("MainMenu.layout");
//    exit(0);
    logMsg("MainMenu layout loaded");
//  startGameButton = mGUI->createWidget<MyGUI::Button>("Button", 362, 100, 300, 26, MyGUI::Align::Default, "Main");
//  startGameBu  tton->setCaption("Start Game");
    
//    startSingleGameButton = boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("startSingleGameButton"));
    mainMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("startSingleGameButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("startSingleGameButton"))));
//    exit(0);
    mainMenuButtons["startSingleGameButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::startSingleGameButtonClicked);
//    exit(0);
    mainMenuButtons["startSingleGameButton"]->setStateSelected(true);
//    exit(0);
    MyGUI::InputManager::getInstance().setKeyFocusWidget(mainMenuButtons["startSingleGameButton"].get());
//    exit(0);
    mainMenuButtons["startSingleGameButton"]->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    mainMenuButtons["startSingleGameButton"]->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    mainMenuButtons["startSingleGameButton"]->setVisible(false);
//    exit(0);
    mainMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("startMultiGameButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("startMultiGameButton"))));
//    exit(0);
    mainMenuButtons["startMultiGameButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::startMultiGameButtonClicked);
    mainMenuButtons["startMultiGameButton"]->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.14 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    mainMenuButtons["startMultiGameButton"]->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    mainMenuButtons["startMultiGameButton"]->setVisible(false);
//  optionsButton =    mGUI->createWidget<MyGUI::Button>("Button", 362, 125, 300, 26, MyGUI::Align::Default, "Main");
//  optionsButton->setCaption(",?ik.??..?llmmmmllml.....l.m. onOptions");
    mainMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("optionsButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("optionsButton"))));
//    exit(0);
    mainMenuButtons["optionsButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::optionsButtonClicked);
    mainMenuButtons["optionsButton"]->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.18 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    mainMenuButtons["optionsButton"]->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    mainMenuButtons["optionsButton"]->setVisible(false);
//  exitButton = mGUI->createWidget<MyGUI::Button>("Button", 362, 150, 300, 26, MyGUI::Align::Default, "Main");
//  exitButton->setCaption("Exit");mlklkklllmmmmmmm mmllm
    mainMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("exitButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("exitButton"))));
//    exit(0);
    mainMenuButtons["exitButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::exitButtonClicked);
    mainMenuButtons["exitButton"]->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.22 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    mainMenuButtons["exitButton"]->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    mainMenuButtons["exitButton"]->setVisible(false);
//    exit(0);
    mainMenuCreated = true;
//    exit(0);
    menuActive = true;
//    exit(0);
    activeMenu = MAIN;
//    exit(0);
    return true;
}

bool GUISystem::createNetworkSetupGUI()  // loads the GUI for the network setup screen
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

    MyGUI::LayoutManager::getInstance().loadLayout("NetworkSetupMenu.layout");

    networkMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("serverButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("serverButton")))); // loads Server Button
    networkMenuButtons["serverButton"]->setVisible(false);
    networkMenuButtons["serverButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::serverButtonClicked);
    networkMenuButtons["serverButton"]->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.14 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    networkMenuButtons["serverButton"]->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    networkMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("clientButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("clientButton")))); // loads Client Button
    networkMenuButtons["clientButton"]->setVisible(false);
    networkMenuButtons["clientButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::clientButtonClicked);
    networkMenuButtons["clientButton"]->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.18 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    networkMenuButtons["clientButton"]->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    
    networkMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("backMainMenuButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("networkBackMainMenuButton"))));  // loads Back to Main Menu Button
    networkMenuButtons["backMainMenuButton"]->setVisible(false);
    networkMenuButtons["backMainMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backMainMenuButtonClicked);
    networkMenuButtons["backMainMenuButton"]->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    
    networkSetupMenuCreated = true;
/*    menuActive = true;
    previousActiveMenu = activeMenu;
    activeMenu = NETWORK;
*/
    return true;
}

bool GUISystem::createNetworkClientSetupGUI()  // creates GUI for network client setup screen.
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

    MyGUI::LayoutManager::getInstance().loadLayout("NetworkClientSetupMenu.layout");

    clientIPAddressBox = boost::shared_ptr<MyGUI::EditBox>(mGUI->findWidget<MyGUI::EditBox>("clientIPAddressBox"));  // loads IP Address EditBox    clientIPAddressBox->setVisible(false);
    clientIPAddressBox->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.10 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    clientIPAddressBox->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    clientConnectButton = boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("clientConnectButton"));  // loads Court Selection Button
    clientConnectButton->setVisible(false);
    clientConnectButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::clientConnectButtonClicked);
    clientConnectButton->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    networkClientSetupMenuCreated = true;
    
    return true;
}

bool GUISystem::createNetworkServerSetupGUI()  // creates GUI for network server setup screen.
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

    MyGUI::LayoutManager::getInstance().loadLayout("NetworkServerSetupMenu.layout");

    numClientsSelectBox = boost::shared_ptr<MyGUI::ListBox>(mGUI->findWidget<MyGUI::ListBox>("numClientsSelectBox"));  // loads  Selection box for number of clients allowed
    numClientsSelectBox->setVisible(false);
    
    serverIPAddressBox = boost::shared_ptr<MyGUI::EditBox>(mGUI->findWidget<MyGUI::EditBox>("serverIPAddressBox"));  // loads IP Address EditBox
    serverIPAddressBox->setVisible(false);
    serverIPAddressBox->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.10 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    serverIPAddressBox->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    serverHostButton = boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("serverHostButton"));  // loads Court Selection Button
    serverHostButton->setVisible(false);
    serverHostButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::serverHostButtonClicked);
    serverHostButton->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    networkServerSetupMenuCreated = true;
    return true;
}

bool GUISystem::createCourtSelectionMenuGUI()  // creates GUI for court selection menu screen.
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();
    boost::shared_ptr<courtState> courtInst(new courtState);

    MyGUI::LayoutManager::getInstance().loadLayout("CourtSelectionMenu.layout");

    courtSelectBox = boost::shared_ptr<MyGUI::ListBox>(mGUI->findWidget<MyGUI::ListBox>("courtSelectBox"));  // loads Court Selection ListBox
    courtSelectBox->setVisible(false);
//  courtSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::displayButtonClicked);

    courtNameTxtBox = boost::shared_ptr<MyGUI::TextBox>(mGUI->findWidget<MyGUI::TextBox>("courtNameTxtBox"));  // loads Court Name TextBox
    courtNameTxtBox->setVisible(false);
//  courtNameTxtBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::displayButtonClicked);

    courtSelectionMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("courtSelectButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("courtSelectButton"))));  // loads Court Selection Button
    courtSelectionMenuButtons["courtSelectButton"]->setVisible(false);
    courtSelectionMenuButtons["courtSelectButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::courtSelectButtonClicked);
    courtSelectionMenuButtons["courtSelectButton"]->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    courtSelectionMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("backMainMenuButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("courtBackMainMenuButton"))));  // loads Back to Main Menu Button
    courtSelectionMenuButtons["backMainMenuButton"]->setVisible(false);
    courtSelectionMenuButtons["backMainMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backMainMenuButtonClicked);
    courtSelectionMenuButtons["backMainMenuButton"]->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    courtPreviewImgBox = boost::shared_ptr<MyGUI::ImageBox>(mGUI->findWidget<MyGUI::ImageBox>("courtPreviewImgBox"));  // loads Court Preview ImageBox
    courtPreviewImgBox->setVisible(false);
//  courtPreviewImgBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::displayButtonClicked);
    courtPreviewImgBox->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    courtSelectionMenuCreated = true;
    return true;
}

bool GUISystem::createOptionsMenuGUI()  // creates GUI for options menu screen.
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

    MyGUI::LayoutManager::getInstance().loadLayout("OptionsMenu.layout");

    optionsMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("displayButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("displayButton"))));  // loads Display Settings Button
    optionsMenuButtons["displayButton"]->setVisible(false);
    optionsMenuButtons["displayButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::displayButtonClicked);

    optionsMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("inputButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("inputButton"))));  // loads Input Settings Button
    optionsMenuButtons["inputButton"]->setVisible(false);
    optionsMenuButtons["inputButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::inputButtonClicked);

    optionsMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("audioButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("audioButton"))));  // loads Audio Settongs Button
    optionsMenuButtons["audioButton"]->setVisible(false);
    optionsMenuButtons["audioButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::audioButtonClicked);

    optionsMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("backMainMenuButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("optionsBackMainMenuButton"))));  // loads Back to Main Menu Button
    optionsMenuButtons["backMainMenuButton"]->setVisible(false);
    optionsMenuButtons["backMainMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backMainMenuButtonClicked);
    optionsMenuButtons["backMainMenuButton"]->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    optionsMenuCreated = true;
/*    menuActive = true;
    previousActiveMenu = activeMenu;
    activeMenu = OPTIONS;
*/
    return (true);
}

bool GUISystem::createBackButtons()  // creates the back buttons for the menus
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();
//    exit(0);
/*    MyGUI::LayoutManager::getInstance().loadLayout("BackButtons.layout");

///    backMainMenuButton = boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("backMainMenuButton"));  // loads Back to Main Menu Button
///    backMainMenuButton->setVisible(false);
///    backMainMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backMainMenuButtonClicked);
///    backMainMenuButton->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    backNetworkSetupButton = boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("backNetworkSetupButton"));  // loads Back to Network Setup Button
    backNetworkSetupButton->setVisible(false);
    backNetworkSetupButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backNetworkSetupButtonClicked);
    backNetworkSetupButton->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    backNetworkClientButton = boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("backNetworkClientButton"));  // loads Back to Network Client Button
    backNetworkClientButton->setVisible(false);
    backNetworkClientButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backNetworkClientButtonClicked);
    backNetworkClientButton->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    backOptionsMenuButton = boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("backOptionsMenuButton"));  // loads Back to Options Menu Button
    backOptionsMenuButton->setVisible(false);
    backOptionsMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backOptionsMenuButtonClicked);
    backOptionsMenuButton->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

///    backCourtSelectionMenuButton = boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("backCourtSelectionMenuButton"));  // loads Back to Team Selection Menu Button
///    backCourtSelectionMenuButton->setVisible(false);
///    backCourtSelectionMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backCourtSelectionMenuButtonClicked);
///    backCourtSelectionMenuButton->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    backTeamSelectionMenuButton = boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("backTeamSelectionMenuButton"));  // loads Back to Team Selection Menu Button
    backTeamSelectionMenuButton->setVisible(false);
    backTeamSelectionMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backTeamSelectionMenuButtonClicked);
    backTeamSelectionMenuButton->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    
///    backPlayerStartSelectionMenuButton = boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("backPlayerStartSelectionMenuButton"));  // loads Back to Player Start Selection Menu Button
///    backPlayerStartSelectionMenuButton->setVisible(false);
///    backPlayerStartSelectionMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backPlayerStartSelectionMenuButtonClicked);
///    backPlayerStartSelectionMenuButton->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    backGameSetupMenuButton = boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("backGameSetupMenuButton"));  // loads Back to Game Setup Menu Button
    backGameSetupMenuButton->setVisible(false);
    backGameSetupMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backGameSetupMenuButtonClicked);
    backGameSetupMenuButton->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
*/
    backButtonsCreated = true;

    return (true);
}

bool GUISystem::createDisplaySetupGUI()  // creates GUI for display settings screen.
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

    MyGUI::LayoutManager::getInstance().loadLayout("DispkaySetupMenu.layout");

    changeResolutionButton = boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("changeResolutionButton"));  // loads team 1 Button
    changeResolutionButton->setVisible(false);
    changeResolutionButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);

    displaySetupMenuCreated = true;

    return (true);
}

bool GUISystem::createInputSetupGUI()  // creates GUI for input settings screen.
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

    MyGUI::LayoutManager::getInstance().loadLayout("InputSetupMenu.layout");

    changeInputTypeButton = boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("changeInputTypeButton"));  // loads team 1 Button
    changeInputTypeButton->setVisible(false);
    changeInputTypeButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeInputTypeButtonClicked);

    inputSetupMenuCreated = true;

    return (true);
}

bool GUISystem::createAudioSetupGUI()  // creates GUI for audo settings screen.
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

    MyGUI::LayoutManager::getInstance().loadLayout("AudioSetupMenu.layout");

    enableAudioButton = boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("enableAudioButton"));  // loads team 1 Button
    enableAudioButton->setVisible(false);
    enableAudioButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::enableAudioButtonClicked);

    disableAudioButton = boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("disableAudioButton")); // loads team 1 Button
    disableAudioButton->setVisible(false);
    disableAudioButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::disableAudioButtonClicked);

    audioSetupMenuCreated = true;

    return (true);
}


bool GUISystem::createGameSetupMenuGUI()    // creates GUI for game setup menu screen.
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //gameState *gameS = gameState::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
//    boost::shared_ptr<loader> load(new loader);
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

    MyGUI::LayoutManager::getInstance().loadLayout("GameSetupMenu.layout");
    gameSetupMenuCreated = true;

    return (true);
}

bool GUISystem::createPlayerStartSelectionMenuGUI()  // creates GUI for player selection menu screen.
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

//    load->loadTeams();
//    std::vector<teamData> teamDataInstance = gameS->getTeamDataInstance();

//    exit(0);
    MyGUI::LayoutManager::getInstance().loadLayout("PlayerStartSelection.layout");

    if (teamPlayerPosSelectBox.size() == 0)
    {
        std::tr1::unordered_map <std::string, boost::shared_ptr<MyGUI::ListBox> > playerPosSelectBox;
        teamPlayerPosSelectBox.push_back(playerPosSelectBox);
        teamPlayerPosSelectBox.push_back(playerPosSelectBox);
    }
    
    if (teamPlayerRating.size() == 0)
    {
        std::tr1::unordered_map <std::string, boost::shared_ptr<MyGUI::TextBox> > playerRating;
        teamPlayerRating.push_back(playerRating);
        teamPlayerRating.push_back(playerRating);
    }
    
    
    teamPlayerPosSelectBox[0].insert(std::pair<std::string, boost::shared_ptr<MyGUI::ListBox> >("PG", boost::shared_ptr<MyGUI::ListBox>(mGUI->findWidget<MyGUI::ListBox>("team0PGSelectBox"))));  // loads team0PGSelectBox
//    exit(0);
    teamPlayerPosSelectBox[0]["PG"]->setVisible(false);
//    team0PGSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    teamPlayerPosSelectBox[0]["PG"]->setSize((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));
    
    teamPlayerPosSelectBox[0].insert(std::pair<std::string, boost::shared_ptr<MyGUI::ListBox> >("SG", boost::shared_ptr<MyGUI::ListBox>(mGUI->findWidget<MyGUI::ListBox>("team0SGSelectBox"))));  // loads team0SGSelectBox
    teamPlayerPosSelectBox[0]["SG"]->setVisible(false);
//    team0SGSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    teamPlayerPosSelectBox[0]["SG"]->setSize((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    teamPlayerPosSelectBox[0].insert(std::pair<std::string, boost::shared_ptr<MyGUI::ListBox> >("SF", boost::shared_ptr<MyGUI::ListBox>(mGUI->findWidget<MyGUI::ListBox>("team0SFSelectBox"))));  // loads team0SFSelectBox
    teamPlayerPosSelectBox[0]["SF"]->setVisible(false);
//    team0SFSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    teamPlayerPosSelectBox[0]["SF"]->setSize((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    teamPlayerPosSelectBox[0].insert(std::pair<std::string, boost::shared_ptr<MyGUI::ListBox> >("PF", boost::shared_ptr<MyGUI::ListBox>(mGUI->findWidget<MyGUI::ListBox>("team0PFSelectBox"))));  // loads team0PFSelectBox
    teamPlayerPosSelectBox[0]["PF"]->setVisible(false);
//    team0PFSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    teamPlayerPosSelectBox[0]["PF"]->setSize((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    teamPlayerPosSelectBox[0].insert(std::pair<std::string, boost::shared_ptr<MyGUI::ListBox> >("C", boost::shared_ptr<MyGUI::ListBox>(mGUI->findWidget<MyGUI::ListBox>("team0CSelectBox"))));  // loads team0CSelectBox
    teamPlayerPosSelectBox[0]["C"]->setVisible(false);
//    team0CSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    teamPlayerPosSelectBox[0]["C"]->setSize((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    teamPlayerPosSelectBox[1].insert(std::pair<std::string, boost::shared_ptr<MyGUI::ListBox> >("PG", boost::shared_ptr<MyGUI::ListBox>(mGUI->findWidget<MyGUI::ListBox>("team1PGSelectBox"))));  // loads team1PGSelectBox
    teamPlayerPosSelectBox[1]["PG"]->setVisible(false);
//    team1PGSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    teamPlayerPosSelectBox[1]["PG"]->setSize((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    teamPlayerPosSelectBox[1].insert(std::pair<std::string, boost::shared_ptr<MyGUI::ListBox> >("SG", boost::shared_ptr<MyGUI::ListBox>(mGUI->findWidget<MyGUI::ListBox>("team1SGSelectBox"))));  // loads team1SGSelectBox
    teamPlayerPosSelectBox[1]["SG"]->setVisible(false);
//    team1SGSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    teamPlayerPosSelectBox[1]["SG"]->setSize((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    teamPlayerPosSelectBox[1].insert(std::pair<std::string, boost::shared_ptr<MyGUI::ListBox> >("SF", boost::shared_ptr<MyGUI::ListBox>(mGUI->findWidget<MyGUI::ListBox>("team1SFSelectBox"))));  // loads team1SFSelectBox
    teamPlayerPosSelectBox[1]["SF"]->setVisible(false);
//    team1SFSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    teamPlayerPosSelectBox[1]["SF"]->setSize((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    teamPlayerPosSelectBox[1].insert(std::pair<std::string, boost::shared_ptr<MyGUI::ListBox> >("PF", boost::shared_ptr<MyGUI::ListBox>(mGUI->findWidget<MyGUI::ListBox>("team1PFSelectBox"))));  // loads team0PFSelectBox
    teamPlayerPosSelectBox[1]["PF"]->setVisible(false);
//    team1PFSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    teamPlayerPosSelectBox[1]["PF"]->setSize((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    teamPlayerPosSelectBox[1].insert(std::pair<std::string, boost::shared_ptr<MyGUI::ListBox> >("C", boost::shared_ptr<MyGUI::ListBox>(mGUI->findWidget<MyGUI::ListBox>("team1CSelectBox"))));  // loads team1CSelectBox
    teamPlayerPosSelectBox[1]["C"]->setVisible(false);
//    team1CSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    teamPlayerPosSelectBox[1]["C"]->setSize((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    teamPlayerRating[0].insert(std::pair<std::string, boost::shared_ptr<MyGUI::TextBox> > ("PG", boost::shared_ptr<MyGUI::TextBox>(mGUI->findWidget<MyGUI::TextBox>("team0PGRating"))));  // loads team0PGRatimg
    teamPlayerRating[0]["PG"]->setVisible(false);
//    team0PGRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    teamPlayerRating[0]["PG"]->setSize((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    teamPlayerRating[0].insert(std::pair<std::string, boost::shared_ptr<MyGUI::TextBox> > ("SG", boost::shared_ptr<MyGUI::TextBox>(mGUI->findWidget<MyGUI::TextBox>("team0SGRating"))));  // loads team0SGRatimg
    teamPlayerRating[0]["SG"]->setVisible(false);
//    team0SGRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    teamPlayerRating[0]["SG"]->setSize((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    teamPlayerRating[0].insert(std::pair<std::string, boost::shared_ptr<MyGUI::TextBox> > ("SF", boost::shared_ptr<MyGUI::TextBox>(mGUI->findWidget<MyGUI::TextBox>("team0SFRating"))));  // loads team0SFRatimg
    teamPlayerRating[0]["SF"]->setVisible(false);
//    team0SFRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    teamPlayerRating[0]["SF"]->setSize((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    teamPlayerRating[0].insert(std::pair<std::string, boost::shared_ptr<MyGUI::TextBox> > ("PF", boost::shared_ptr<MyGUI::TextBox>(mGUI->findWidget<MyGUI::TextBox>("team0PFRating"))));  // loads team0PFRatimg
    teamPlayerRating[0]["PF"]->setVisible(false);
//    team0PFRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    teamPlayerRating[0]["PF"]->setSize((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    teamPlayerRating[0].insert(std::pair<std::string, boost::shared_ptr<MyGUI::TextBox> > ("C", boost::shared_ptr<MyGUI::TextBox>(mGUI->findWidget<MyGUI::TextBox>("team0CRating"))));  // loads team0CRatimg
    teamPlayerRating[0]["C"]->setVisible(false);
//    team0CRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    teamPlayerRating[0]["C"]->setSize((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    teamPlayerRating[1].insert(std::pair<std::string, boost::shared_ptr<MyGUI::TextBox> > ("PG", boost::shared_ptr<MyGUI::TextBox>(mGUI->findWidget<MyGUI::TextBox>("team1PGRating"))));  // loads team1PGRatimg
    teamPlayerRating[1]["PG"]->setVisible(false);
//    team1PGRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    teamPlayerRating[1]["PG"]->setSize((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    teamPlayerRating[1].insert(std::pair<std::string, boost::shared_ptr<MyGUI::TextBox> > ("SG", boost::shared_ptr<MyGUI::TextBox>(mGUI->findWidget<MyGUI::TextBox>("team1SGRating"))));  // loads team1SGRatimg
    teamPlayerRating[1]["SG"]->setVisible(false);
//    team1SGRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    teamPlayerRating[1]["SG"]->setSize((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    teamPlayerRating[1].insert(std::pair<std::string, boost::shared_ptr<MyGUI::TextBox> > ("SF", boost::shared_ptr<MyGUI::TextBox>(mGUI->findWidget<MyGUI::TextBox>("team1SFRating"))));  // loads team1SFRatimg
    teamPlayerRating[1]["SF"]->setVisible(false);
//    team1SFRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    teamPlayerRating[1]["SF"]->setSize((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    teamPlayerRating[1].insert(std::pair<std::string, boost::shared_ptr<MyGUI::TextBox> > ("PF", boost::shared_ptr<MyGUI::TextBox>(mGUI->findWidget<MyGUI::TextBox>("team1PFRating"))));  // loads team1PFRatimg
    teamPlayerRating[1]["PF"]->setVisible(false);
//    team1PFRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    teamPlayerRating[1]["PF"]->setSize((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    teamPlayerRating[1].insert(std::pair<std::string, boost::shared_ptr<MyGUI::TextBox> > ("C", boost::shared_ptr<MyGUI::TextBox>(mGUI->findWidget<MyGUI::TextBox>("team1CRating"))));  // loads team1CRatimg
    teamPlayerRating[1]["C"]->setVisible(false);
//    team1CRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    teamPlayerRating[1]["C"]->setSize((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));


    playerStartSelectionMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("team0StartingLineupSetButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("team0StartingLineupSetButton"))));  // loads team0StartingLineupSetButton
    playerStartSelectionMenuButtons["team0StartingLineupSetButton"]->setVisible(false);
    playerStartSelectionMenuButtons["team0StartingLineupSetButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team0StartingLineupSetButtonClicked);
    playerStartSelectionMenuButtons["team0StartingLineupSetButton"]->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    playerStartSelectionMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("team1StartingLineupSetButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("team1StartinglineupSetButton"))));  // loads team1StartingLineupSetButton
    playerStartSelectionMenuButtons["team1StartingLineupSetButton"]->setVisible(false);
    playerStartSelectionMenuButtons["team1StartingLineupSetButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team1StartingLineupSetButtonClicked);
    playerStartSelectionMenuButtons["team1StartingLineupSetButton"]->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    playerStartSelectionMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("startingLineupsSetButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("startingLineupsSetButton"))));  // loads team1StartingLineupSetButton
    playerStartSelectionMenuButtons["startingLineupsSetButton"]->setVisible(false);
    playerStartSelectionMenuButtons["startingLineupsSetButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::startingLineupSetButtonClicked);
    playerStartSelectionMenuButtons["startingLineupsSetButton"]->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

    playerStartSelectionMenuCreated = true;

    return (true);
}

bool GUISystem::createTeamSelectionMenuGUI()  // creates GUI for team selection menu screen.
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //
    MyGUI::LayoutManager::getInstance().loadLayout("TeamSelectionMenu.layout");
    
    float vpWidth = base->getGameE()->getRenderE()->getViewPort()->getActualWidth();  // stores view ports width
    float vpHeight = base->getGameE()->getRenderE()->getViewPort()->getActualHeight();  // stores view ports height
    
    teamSelectBox.insert(std::pair<size_t, boost::shared_ptr<MyGUI::ListBox> > (0, boost::shared_ptr<MyGUI::ListBox>(mGUI->findWidget<MyGUI::ListBox>("team0SelectBox"))));  // loads team 0 ListBox
    teamSelectBox[0]->setVisible(false);
    teamSelectBox[0]->setSize((0.4 *vpWidth), (0.04 *vpHeight));
    
    teamSelectBox.insert(std::pair<size_t, boost::shared_ptr<MyGUI::ListBox> > (1, boost::shared_ptr<MyGUI::ListBox>(mGUI->findWidget<MyGUI::ListBox>("team1SelectBox"))));  // loads team 1 ListBox
    teamSelectBox[1]->setVisible(false);
    teamSelectBox[1]->setSize((0.4 *vpWidth), (0.04 *vpHeight));
    
    teamSelectionMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("team0SelectButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("team0SelectButton"))));  // loads team 0 Select Button  
    teamSelectionMenuButtons["team0SelectButton"]->setVisible(false);
    teamSelectionMenuButtons["team0SelectButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team0SelectButtonClicked);
    teamSelectionMenuButtons["team0SelectButton"]->setSize((0.4 *vpWidth), (0.04 *vpHeight));
    teamSelectionMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("team1SelectButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("team1SelectButton"))));  // loads team 1 Button
    teamSelectionMenuButtons["team1SelectButton"]->setVisible(false);
    teamSelectionMenuButtons["team1SelectButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team1SelectButtonClicked);
    teamSelectionMenuButtons["team1SelectButton"]->setSize((0.4 *vpWidth), (0.04 *vpHeight));

    teamSelectionMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("teamsSelectedButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("teamsSelectedButton"))));  // loads team 1 Button
    teamSelectionMenuButtons["teamsSelectedButton"]->setVisible(false);
    teamSelectionMenuButtons["teamsSelectedButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::teamsSelectedButtonClicked);
    teamSelectionMenuButtons["teamsSelectedButton"]->setSize((0.4 *vpWidth), (0.04 *vpHeight) );
    
    teamSelectionMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("backMainMenuButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("teamSelectionBackMainMenuButton"))));  // loads Back to Main Menu Button
    teamSelectionMenuButtons["backMainMenuButton"]->setVisible(false);
    teamSelectionMenuButtons["backMainMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backMainMenuButtonClicked);
    teamSelectionMenuButtons["backMainMenuButton"]->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamSelectionMenuButtons.insert(std::pair<std::string, boost::shared_ptr<MyGUI::Button> >("backCourtSelectionMenuButton", boost::shared_ptr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("backCourtSelectionMenuButton"))));  // loads Back to Team Selection Menu Button
    teamSelectionMenuButtons["backCourtSelectionMenuButton"]->setVisible(false);
    teamSelectionMenuButtons["backCourtSelectionMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backCourtSelectionMenuButtonClicked);
    teamSelectionMenuButtons["backCourtSelectionMenuButton"]->setSize((0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.04 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamSelectionMenuCreated = true;
//    exit(0);
    return (true);
}


