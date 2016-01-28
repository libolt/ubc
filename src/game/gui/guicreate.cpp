 /***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean                              *
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
//#include "engine/gameengine.h" 
#include "state/gamestate.h"
#include "load.h"
#include "logging.h"
#include "engine/renderengine.h"
#include "state/teamstate.h"

#ifdef __ANDROID__
#include "android-config.h"
#else
#include "config.h"
#endif
 
bool GUISystem::createMainMenuGUI()  // creates the main menu gui
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

    if (getRender()->getViewPort()->getActualHeight() >= 1000)
    {  
        MyGUI::FontManager::getInstance().setDefaultFont("LuxiBoldFont_18");
    }
    else
    {
        MyGUI::FontManager::getInstance().setDefaultFont("LuxiBoldFont_16");

    }
    logMsg("Loading MainMenu layout");
    MyGUI::LayoutManager::getInstance().loadLayout("MainMenu.layout");

    logMsg("MainMenu layout loaded");
//  startGameButton = mGUI->createWidget<MyGUI::Button>("Button", 362, 100, 300, 26, MyGUI::Align::Default, "Main");
//  startGameBu  tton->setCaption("Start Game");
    startSingleGameButton = mGUI->findWidget<MyGUI::Button>("startSingleGameButton");
    startSingleGameButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::startSingleGameButtonClicked);
    startSingleGameButton->setStateSelected(true);
    MyGUI::InputManager::getInstance().setKeyFocusWidget(startSingleGameButton);
    startSingleGameButton->setPosition((0.3 *getRender()->getViewPort()->getActualWidth() ), (0.1 *getRender()->getViewPort()->getActualHeight()) );
    startSingleGameButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    startMultiGameButton = mGUI->findWidget<MyGUI::Button>("startMultiGameButton");
    startMultiGameButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::startMultiGameButtonClicked);
    startMultiGameButton->setPosition((0.3 *getRender()->getViewPort()->getActualWidth() ), (0.14 *getRender()->getViewPort()->getActualHeight()) );
    startMultiGameButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

//  optionsButton =    mGUI->createWidget<MyGUI::Button>("Button", 362, 125, 300, 26, MyGUI::Align::Default, "Main");
//  optionsButton->setCaption("Options");
    optionsButton = mGUI->findWidget<MyGUI::Button>("optionsButton");
    optionsButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::optionsButtonClicked);
    optionsButton->setPosition((0.3 *getRender()->getViewPort()->getActualWidth() ), (0.18 *getRender()->getViewPort()->getActualHeight()) );
    optionsButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

//  exitButton = mGUI->createWidget<MyGUI::Button>("Button", 362, 150, 300, 26, MyGUI::Align::Default, "Main");
//  exitButton->setCaption("Exit");
    exitButton = mGUI->findWidget<MyGUI::Button>("exitButton");
    exitButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::exitButtonClicked);
    exitButton->setPosition((0.3 *getRender()->getViewPort()->getActualWidth() ), (0.22 *getRender()->getViewPort()->getActualHeight()) );
    exitButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );
 
    mainMenuCreated = true;
    menuActive = true;
    activeMenu = MAIN;

    return true;
}

bool GUISystem::createNetworkSetupGUI()  // loads the GUI for the network setup screen
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

    MyGUI::LayoutManager::getInstance().loadLayout("NetworkSetupMenu.layout");

    serverButton = mGUI->findWidget<MyGUI::Button>("serverButton"); // loads Server Button
    serverButton->setVisible(false);
    serverButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::serverButtonClicked);
    serverButton->setPosition((0.3 *getRender()->getViewPort()->getActualWidth() ), (0.14 *getRender()->getViewPort()->getActualHeight()) );
    serverButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    clientButton = mGUI->findWidget<MyGUI::Button>("clientButton"); // loads Client Button
    clientButton->setVisible(false);
    clientButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::clientButtonClicked);
    clientButton->setPosition((0.3 *getRender()->getViewPort()->getActualWidth() ), (0.18 *getRender()->getViewPort()->getActualHeight()) );
    clientButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    
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

    clientIPAddressBox = mGUI->findWidget<MyGUI::EditBox>("clientIPAddressBox");  // loads IP Address EditBox
    clientIPAddressBox->setVisible(false);
    clientIPAddressBox->setPosition((0.3 *getRender()->getViewPort()->getActualWidth() ), (0.10 *getRender()->getViewPort()->getActualHeight()) );
    clientIPAddressBox->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    clientConnectButton = mGUI->findWidget<MyGUI::Button>("clientConnectButton");  // loads Court Selection Button
    clientConnectButton->setVisible(false);
    clientConnectButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::clientConnectButtonClicked);
    clientConnectButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    networkClientSetupMenuCreated = true;
    
    return true;
}
bool GUISystem::createNetworkServerSetupGUI()  // creates GUI for network server setup screen.
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

    MyGUI::LayoutManager::getInstance().loadLayout("NetworkServerSetupMenu.layout");

    numClientsSelectBox = mGUI->findWidget<MyGUI::ListBox>("numClientsSelectBox");  // loads  Selection box for number of clients allowed
    numClientsSelectBox->setVisible(false);
    
    serverIPAddressBox = mGUI->findWidget<MyGUI::EditBox>("serverIPAddressBox");  // loads IP Address EditBox
    serverIPAddressBox->setVisible(false);
    serverIPAddressBox->setPosition((0.3 *getRender()->getViewPort()->getActualWidth() ), (0.10 *getRender()->getViewPort()->getActualHeight()) );
    serverIPAddressBox->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    serverHostButton = mGUI->findWidget<MyGUI::Button>("serverHostButton");  // loads Court Selection Button
    serverHostButton->setVisible(false);
    serverHostButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::serverHostButtonClicked);
    serverHostButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    networkServerSetupMenuCreated = true;
    return true;
}

bool GUISystem::createCourtSelectionMenuGUI()  // creates GUI for court selection menu screen.
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

    MyGUI::LayoutManager::getInstance().loadLayout("CourtSelectionMenu.layout");

    courtSelectBox = mGUI->findWidget<MyGUI::ListBox>("courtSelectBox");  // loads Court Selection ListBox
    courtSelectBox->setVisible(false);
//  courtSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::displayButtonClicked);

    courtNameTxtBox = mGUI->findWidget<MyGUI::TextBox>("courtNameTxtBox");  // loads Court Name TextBox
    courtNameTxtBox->setVisible(false);
//  courtNameTxtBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::displayButtonClicked);

    courtSelectButton = mGUI->findWidget<MyGUI::Button>("courtSelectButton");  // loads Court Selection Button
    courtSelectButton->setVisible(false);
    courtSelectButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::courtSelectButtonClicked);
    courtSelectButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    courtPreviewImgBox = mGUI->findWidget<MyGUI::ImageBox>("courtPreviewImgBox");  // loads Court Preview ImageBox
    courtPreviewImgBox->setVisible(false);
//  courtPreviewImgBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::displayButtonClicked);
    courtPreviewImgBox->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    courtSelectionMenuCreated = true;
    return true;
}

bool GUISystem::createOptionsMenuGUI()  // creates GUI for options menu screen.
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

    MyGUI::LayoutManager::getInstance().loadLayout("OptionsMenu.layout");

    displayButton = mGUI->findWidget<MyGUI::Button>("displayButton");  // loads Display Settings Button
    displayButton->setVisible(false);
    displayButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::displayButtonClicked);

    inputButton = mGUI->findWidget<MyGUI::Button>("inputButton");  // loads Input Settings Button
    inputButton->setVisible(false);
    inputButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::inputButtonClicked);

    audioButton = mGUI->findWidget<MyGUI::Button>("audioButton");  // loads Audio Settongs Button
    audioButton->setVisible(false);
    audioButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::audioButtonClicked);

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

    MyGUI::LayoutManager::getInstance().loadLayout("BackButtons.layout");

    backMainMenuButton = mGUI->findWidget<MyGUI::Button>("backMainMenuButton");  // loads Back to Main Menu Button
    backMainMenuButton->setVisible(false);
    backMainMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backMainMenuButtonClicked);
    backMainMenuButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    backNetworkSetupButton = mGUI->findWidget<MyGUI::Button>("backNetworkSetupButton");  // loads Back to Network Setup Button
    backNetworkSetupButton->setVisible(false);
    backNetworkSetupButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backNetworkSetupButtonClicked);
    backNetworkSetupButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    backNetworkClientButton = mGUI->findWidget<MyGUI::Button>("backNetworkClientButton");  // loads Back to Network Client Button
    backNetworkClientButton->setVisible(false);
    backNetworkClientButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backNetworkClientButtonClicked);
    backNetworkClientButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    backOptionsMenuButton = mGUI->findWidget<MyGUI::Button>("backOptionsMenuButton");  // loads Back to Options Menu Button
    backOptionsMenuButton->setVisible(false);
    backOptionsMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backOptionsMenuButtonClicked);
    backOptionsMenuButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    backCourtSelectionMenuButton = mGUI->findWidget<MyGUI::Button>("backCourtSelectionMenuButton");  // loads Back to Team Selection Menu Button
    backCourtSelectionMenuButton->setVisible(false);
    backCourtSelectionMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backCourtSelectionMenuButtonClicked);
    backCourtSelectionMenuButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    backTeamSelectionMenuButton = mGUI->findWidget<MyGUI::Button>("backTeamSelectionMenuButton");  // loads Back to Team Selection Menu Button
    backTeamSelectionMenuButton->setVisible(false);
    backTeamSelectionMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backTeamSelectionMenuButtonClicked);
    backTeamSelectionMenuButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    backPlayerStartSelectionMenuButton = mGUI->findWidget<MyGUI::Button>("backPlayerStartSelectionMenuButton");  // loads Back to Player Start Selection Menu Button
    backPlayerStartSelectionMenuButton->setVisible(false);
    backPlayerStartSelectionMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backPlayerStartSelectionMenuButtonClicked);
    backPlayerStartSelectionMenuButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    backGameSetupMenuButton = mGUI->findWidget<MyGUI::Button>("backGameSetupMenuButton");  // loads Back to Game Setup Menu Button
    backGameSetupMenuButton->setVisible(false);
    backGameSetupMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backGameSetupMenuButtonClicked);
    backGameSetupMenuButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    backButtonsCreated = true;

    return (true);
}

bool GUISystem::createDisplaySetupGUI()  // creates GUI for display settings screen.
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

    MyGUI::LayoutManager::getInstance().loadLayout("DispkaySetupMenu.layout");

    changeResolutionButton = mGUI->findWidget<MyGUI::Button>("changeResolutionButton");  // loads team 1 Button
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

    changeInputTypeButton = mGUI->findWidget<MyGUI::Button>("changeInputTypeButton");  // loads team 1 Button
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

    enableAudioButton = mGUI->findWidget<MyGUI::Button>("enableAudioButton");  // loads team 1 Button
    enableAudioButton->setVisible(false);
    enableAudioButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::enableAudioButtonClicked);

    disableAudioButton = mGUI->findWidget<MyGUI::Button>("disableAudioButton"); // loads team 1 Button
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
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<loader> load = loader::Instance();
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

    MyGUI::LayoutManager::getInstance().loadLayout("PlayerStartSelection.layout");

    team0PGSelectBox = mGUI->findWidget<MyGUI::ListBox>("team0PGSelectBox");  // loads team0PGSelectBox
    team0PGSelectBox->setVisible(false);
//    team0PGSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    team0PGSelectBox->setSize((0.3 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );
    team0SGSelectBox = mGUI->findWidget<MyGUI::ListBox>("team0SGSelectBox");  // loads team0SGSelectBox
    team0SGSelectBox->setVisible(false);
//    team0SGSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    team0SGSelectBox->setSize((0.3 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team0SFSelectBox = mGUI->findWidget<MyGUI::ListBox>("team0SFSelectBox");  // loads team0SFSelectBox
    team0SFSelectBox->setVisible(false);
//    team0SFSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    team0SFSelectBox->setSize((0.3 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team0PFSelectBox = mGUI->findWidget<MyGUI::ListBox>("team0PFSelectBox");  // loads team0PFSelectBox
    team0PFSelectBox->setVisible(false);
//    team0PFSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    team0PFSelectBox->setSize((0.3 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team0CSelectBox = mGUI->findWidget<MyGUI::ListBox>("team0CSelectBox");  // loads team0CSelectBox
    team0CSelectBox->setVisible(false);
//    team0CSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    team0CSelectBox->setSize((0.3 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team1PGSelectBox = mGUI->findWidget<MyGUI::ListBox>("team1PGSelectBox");  // loads team1PGSelectBox
    team1PGSelectBox->setVisible(false);
//    team1PGSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    team1PGSelectBox->setSize((0.3 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team1SGSelectBox = mGUI->findWidget<MyGUI::ListBox>("team1SGSelectBox");  // loads team1SGSelectBox
    team1SGSelectBox->setVisible(false);
//    team1SGSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    team1SGSelectBox->setSize((0.3 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team1SFSelectBox = mGUI->findWidget<MyGUI::ListBox>("team1SFSelectBox");  // loads team1SFSelectBox
    team1SFSelectBox->setVisible(false);
//    team1SFSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    team1SFSelectBox->setSize((0.3 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team1PFSelectBox = mGUI->findWidget<MyGUI::ListBox>("team1PFSelectBox");  // loads team0PFSelectBox
    team1PFSelectBox->setVisible(false);
//    team1PFSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    team1PFSelectBox->setSize((0.3 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team1CSelectBox = mGUI->findWidget<MyGUI::ListBox>("team1CSelectBox");  // loads team1CSelectBox
    team1CSelectBox->setVisible(false);
//    team1CSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    team1CSelectBox->setSize((0.3 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team0PGRating = mGUI->findWidget<MyGUI::TextBox>("team0PGRating");  // loads team0PGRatimg
    team0PGRating->setVisible(false);
//    team0PGRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    team0PGRating->setSize((0.1 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team0SGRating = mGUI->findWidget<MyGUI::TextBox>("team0SGRating");  // loads team0SGRatimg
    team0SGRating->setVisible(false);
//    team0SGRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    team0SGRating->setSize((0.1 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team0SFRating = mGUI->findWidget<MyGUI::TextBox>("team0SFRating");  // loads team0SFRatimg
    team0SFRating->setVisible(false);
//    team0SFRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    team0SFRating->setSize((0.1 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team0PFRating = mGUI->findWidget<MyGUI::TextBox>("team0PFRating");  // loads team0PFRatimg
    team0PFRating->setVisible(false);
//    team0PFRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    team0PFRating->setSize((0.1 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team0CRating = mGUI->findWidget<MyGUI::TextBox>("team0CRating");  // loads team0CRatimg
    team0CRating->setVisible(false);
//    team0CRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    team0CRating->setSize((0.1 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team1PGRating = mGUI->findWidget<MyGUI::TextBox>("team1PGRating");  // loads team1PGRatimg
    team1PGRating->setVisible(false);
//    team1PGRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    team1PGRating->setSize((0.1 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team1SGRating = mGUI->findWidget<MyGUI::TextBox>("team1SGRating");  // loads team1SGRatimg
    team1SGRating->setVisible(false);
//    team1SGRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    team1SGRating->setSize((0.1 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team1SFRating = mGUI->findWidget<MyGUI::TextBox>("team1SFRating");  // loads team1SFRatimg
    team1SFRating->setVisible(false);
//    team1SFRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    team1SFRating->setSize((0.1 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team1PFRating = mGUI->findWidget<MyGUI::TextBox>("team1PFRating");  // loads team1PFRatimg
    team1PFRating->setVisible(false);
//    team1PFRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    team1PFRating->setSize((0.1 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team1CRating = mGUI->findWidget<MyGUI::TextBox>("team1CRating");  // loads team1CRatimg
    team1CRating->setVisible(false);
//    team1CRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    team1CRating->setSize((0.1 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );


    team0StartingLineupSetButton = mGUI->findWidget<MyGUI::Button>("team0StartingLineupSetButton");  // loads team0StartingLineupSetButton
    team0StartingLineupSetButton->setVisible(false);
    team0StartingLineupSetButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team0StartingLineupSetButtonClicked);
    team0StartingLineupSetButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team1StartingLineupSetButton = mGUI->findWidget<MyGUI::Button>("team1StartinglineupSetButton");  // loads team1StartingLineupSetButton
    team1StartingLineupSetButton->setVisible(false);
    team1StartingLineupSetButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team1StartingLineupSetButtonClicked);
    team1StartingLineupSetButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    startingLineupsSetButton = mGUI->findWidget<MyGUI::Button>("startingLineupsSetButton");  // loads team1StartingLineupSetButton
    startingLineupsSetButton->setVisible(false);
    startingLineupsSetButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::startingLineupSetButtonClicked);
    startingLineupsSetButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    playerStartSelectionMenuCreated = true;

    return (true);
}

bool GUISystem::createTeamSelectionMenuGUI()  // creates GUI for team selection menu screen.
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<loader> load = loader::Instance();
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

    //load->loadTeams();
    std::vector<boost::shared_ptr<teamState> > teamInstance; // = gameS->getTeamDataInstance();

/*    teamInstance = load->loadTeams();
    gameS->setTeamDataInstance(teamDataInstance);
*/
    teamInstance = gameS->getTeamInstance();
    logMsg("teamInstance.size() == " +convert->toString(teamInstance.size()));
//    exit(0);
    MyGUI::LayoutManager::getInstance().loadLayout("TeamSelectionMenu.layout");
    
    team0SelectBox = mGUI->findWidget<MyGUI::ListBox>("team0SelectBox");  // loads team 0 ListBox
    team0SelectBox->setVisible(false);
    team0SelectBox->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team1SelectBox = mGUI->findWidget<MyGUI::ListBox>("team1SelectBox");  // loads team 1 ListBox
    team1SelectBox->setVisible(false);
    team1SelectBox->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    logMsg(convert->toString(teamInstance.size()));

    for (size_t x=0;x<teamInstance.size(); ++x)
    {
        std::string teamName = teamInstance[x]->getCity() + " " +teamInstance[x]->getName();

        team0SelectBox->addItem(teamName);
        team1SelectBox->addItem(teamName);
    }
    team0SelectBox->setIndexSelected(0);
    team1SelectBox->setIndexSelected(1);

    team0SelectButton = mGUI->findWidget<MyGUI::Button>("team0SelectButton");  // loads team 0 Select Button
    team0SelectButton->setVisible(false);
    team0SelectButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team0SelectButtonClicked);
    team0SelectButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    team1SelectButton = mGUI->findWidget<MyGUI::Button>("team1SelectButton");  // loads team 1 Button
    team1SelectButton->setVisible(false);
    team1SelectButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team1SelectButtonClicked);
    team1SelectButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    teamsSelectedButton = mGUI->findWidget<MyGUI::Button>("teamsSelectedButton");  // loads team 1 Button
    teamsSelectedButton->setVisible(false);
    teamsSelectedButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::teamsSelectedButtonClicked);
    teamsSelectedButton->setSize((0.4 *getRender()->getViewPort()->getActualWidth() ), (0.04 *getRender()->getViewPort()->getActualHeight()) );

    teamSelectionMenuCreated = true;

    return (true);
}

