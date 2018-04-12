/***************************************************************************
 *   Copyright (C) 1999 - 2018 by Mike McLean                              *
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
#include "utilities/conversion.h"
#include "components/guicomponents.h"
#include "data/courtdata.h"
//#include mmloukoo"engine/gameengine.h" 
#include "state/gamestate.h"
#include "load/load.h"
#include "utilities/logging.h"
#include "engine/gameengine.h"
#include "engine/renderengine.h"
#include "state/courtstate.h"
#include "state/teamstate.h"

#ifdef __ANDROID__
#include "utilities/android-config.h"
#else
#include "config.h"
#endif
 
//MyGUI::Button *GUISystem::backMainMenuButton;  // static

bool GUISystem::createMainMenuGUI(renderEngineSharedPtr render)  // creates the main menu gui
{
//    renderEngineSharedPtr render; // = renderEngine::Instance();
    std::string func = "GUISystem::createMainMenuGUI()";
//    Ogre::Viewport *viewPort = render->getViewPort();
//    exit(0); 
//    if (render->getViewPort()->getActualHeight() >= 1000)
    logMsg(func +" begin");
    if (render->getViewPort()->getActualHeight() >= 1000)
    {
        logMsg(func +" Height greater than 1000!");
//        exit(0);
        MyGUI::FontManager::getInstance().setDefaultFont("LinBiolinum_aBL.16");
    }
    else
    {
        logMsg(func +" Height less than 1000!");
        MyGUI::FontManager::getInstance().setDefaultFont("LuxiBoldFont_16");

    }
    
//    exit(0);
    
    logMsg(func +" Loading MainMenu layout");
    MyGUI::LayoutManager::getInstance().loadLayout("MainMenu.layout");
//    exit(0);
    logMsg(func +" MainMenu layout loaded");
//  startGameButton = mGUI->createWidget<MyGUI::Button>("Button", 362, 100, 300, 26, MyGUI::Align::Default, "Main");
//  startGameBu  tton->setCaption("Start Game");
    
//    startSingleGameButton = sharedPtr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("startSingleGameButton"));
    component->getMainMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("startSingleGameButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("startSingleGameButton"))));
    logMsg(func +" Insert Start Single Game Button");
//    exit(0);
    component->getMainMenuButtons()["startSingleGameButton"]->eventMouseButtonClick += MyGUI::newDelegate(component.get(), &GUIComponents::startSingleGameButtonClicked);
    logMsg(func +" Insert Start Single Game Button Mouse Click");

//    exit(0);
    component->getMainMenuButtons()["startSingleGameButton"]->setStateSelected(true);
    logMsg(func +" Insert Start Single Game Button State Selected");

//    exit(0);
    MyGUI::InputManager::getInstance().setKeyFocusWidget(component->getMainMenuButtons()["startSingleGameButton"].get());
    logMsg(func +" Insert Start Single Game Button Inpur Manager");

//    exit(0);
    component->getMainMenuButtons()["startSingleGameButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.1 *render->getViewPort()->getActualHeight()) );
    component->getMainMenuButtons()["startSingleGameButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );
    component->getMainMenuButtons()["startSingleGameButton"]->setVisible(false);
//    exit(0);
    component->getMainMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("startMultiGameButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("startMultiGameButton"))));
//    exit(0);
    component->getMainMenuButtons()["startMultiGameButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::startMultiGameButtonClicked);
    component->getMainMenuButtons()["startMultiGameButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.14 *render->getViewPort()->getActualHeight()) );
    component->getMainMenuButtons()["startMultiGameButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );
    component->getMainMenuButtons()["startMultiGameButton"]->setVisible(false);
//  optionsButton =    mGUI->createWidget<MyGUI::Button>("Button", 362, 125, 300, 26, MyGUI::Align::Default, "Main");
//  optionsButton->setCaption(",?ik.??..?llmmmmllml.....l.m. onOptions");
    component->getMainMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("optionsButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("optionsButton"))));
//    exit(0);
    component->getMainMenuButtons()["optionsButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::optionsButtonClicked);
    component->getMainMenuButtons()["optionsButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.18 *render->getViewPort()->getActualHeight()) );
    component->getMainMenuButtons()["optionsButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );
    component->getMainMenuButtons()["optionsButton"]->setVisible(false);
//  exitButton = mGUI->createWidget<MyGUI::Button>("Button", 362, 150, 300, 26, MyGUI::Align::Default, "Main");
//  exitButton->setCaption("Exit");mlklkklllmmmmmmm mmllm
    component->getMainMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("exitButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("exitButton"))));
//    exit(0);
    component->getMainMenuButtons()["exitButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::exitButtonClicked);
    component->getMainMenuButtons()["exitButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.22 *render->getViewPort()->getActualHeight()) );
    component->getMainMenuButtons()["exitButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );
    component->getMainMenuButtons()["exitButton"]->setVisible(false);
//    exit(0);
    flag->setMainMenuCreated(true);
//    exit(0);
//    menuActive = true;
//    exit(0);
    activeMenu = MAIN;
//    exit(0);
    logMsg(func +" end");
    return (true);
}

bool GUISystem::createNetworkSetupGUI(renderEngineSharedPtr render)  // loads the GUI for the network setup screen
{
//    renderEngineSharedPtr render; // = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();
    std::string func = "GUISystem::createNetworkSetupGUI()";

    logMsg(func +" begin");

    MyGUI::LayoutManager::getInstance().loadLayout("NetworkSetupMenu.layout");

    component->getNetworkMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("serverButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("serverButton")))); // loads Server Button
    component->getNetworkMenuButtons()["serverButton"]->setVisible(false);
    component->getNetworkMenuButtons()["serverButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::serverButtonClicked);
    component->getNetworkMenuButtons()["serverButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.14 *render->getViewPort()->getActualHeight()) );
    component->getNetworkMenuButtons()["serverButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    component->getNetworkMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("clientButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("clientButton")))); // loads Client Button
    component->getNetworkMenuButtons()["clientButton"]->setVisible(false);
    component->getNetworkMenuButtons()["clientButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::clientButtonClicked);
    component->getNetworkMenuButtons()["clientButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.18 *render->getViewPort()->getActualHeight()) );
    component->getNetworkMenuButtons()["clientButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    
    component->getNetworkMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backMainMenuButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("networkBackMainMenuButton"))));  // loads Back to Main Menu Button
    component->getNetworkMenuButtons()["backMainMenuButton"]->setVisible(false);
    component->getNetworkMenuButtons()["backMainMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backMainMenuButtonClicked);
    component->getNetworkMenuButtons()["backMainMenuButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    
    flag->setNetworkSetupMenuCreated(true);
/*    menuActive = true;
    previousActiveMenu = activeMenu;
    activeMenu = NETWORK;
*/
    logMsg(func +" end");
    return true;
}

bool GUISystem::createNetworkClientSetupGUI(renderEngineSharedPtr render)  // creates GUI for network client setup screen.
{
//    renderEngineSharedPtr render; // = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();
    std::string func = "GUISystem::createNetworkClientSetupGUI()";

    logMsg(func +" begin");

    MyGUI::LayoutManager::getInstance().loadLayout("NetworkClientSetupMenu.layout");

    component->setClientIPAddressBox(sharedPtr<MyGUI::EditBox>(component->getMGUI()->findWidget<MyGUI::EditBox>("clientIPAddressBox")));  // loads IP Address EditBox    clientIPAddressBox->setVisible(false);
    component->getClientIPAddressBox()->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.10 *render->getViewPort()->getActualHeight()) );
    component->getClientIPAddressBox()->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    component->getNetworkClientSetupMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("clientConnectButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("clientConnectButton"))));  // loads Court Selection Button
    component->getNetworkClientSetupMenuButtons()["clientConnectButton"]->setVisible(false);
    component->getNetworkClientSetupMenuButtons()["clientConnectButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::clientConnectButtonClicked);
    component->getNetworkClientSetupMenuButtons()["clientConnectButton"]->setSize((0.4 *render->getViewPort()->getActualWidth()), (0.04 *render->getViewPort()->getActualHeight()));

    component->getNetworkClientSetupMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backNetworkSetupButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("serverHostButton"))));  // loads Court Selection Button
    component->getNetworkClientSetupMenuButtons()["backNetworkSetupButton"]->setVisible(false);
    component->getNetworkClientSetupMenuButtons()["backNetworkSetupButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::serverHostButtonClicked);
    component->getNetworkClientSetupMenuButtons()["backNetworkSetupButton"]->setSize((0.4 *render->getViewPort()->getActualWidth()), (0.04 *render->getViewPort()->getActualHeight()));

    
    flag->setNetworkClientSetupMenuCreated(true);
    
    logMsg(func +" end");
    return true;
}

bool GUISystem::createNetworkServerSetupGUI(renderEngineSharedPtr render)  // creates GUI for network server setup screen.
{
//    renderEngineSharedPtr render; // = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

    std::string func = "GUISystem::createNetworkServerSetupGUI()";

    logMsg(func +" begin");

    MyGUI::LayoutManager::getInstance().loadLayout("NetworkServerSetupMenu.layout");

    component->setNumClientsSelectBox(MyGUIListBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::ListBox>("numClientsSelectBox")));  // loads  Selection box for number of clients allowed
    component->getNumClientsSelectBox()->setVisible(false);
    
    component->setServerIPAddressBox(sharedPtr<MyGUI::EditBox>(component->getMGUI()->findWidget<MyGUI::EditBox>("serverIPAddressBox")));  // loads IP Address EditBox
    component->getServerIPAddressBox()->setVisible(false);
    component->getServerIPAddressBox()->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.10 *render->getViewPort()->getActualHeight()) );
    component->getServerIPAddressBox()->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    component->getNetworkServerSetupMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("serverHostButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("serverHostButton"))));  // loads Court Selection Button
    component->getNetworkServerSetupMenuButtons()["serverHostButton"]->setVisible(false);
    component->getNetworkServerSetupMenuButtons()["serverHostButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::serverHostButtonClicked);
    component->getNetworkServerSetupMenuButtons()["serverHostButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getNetworkServerSetupMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backNetworkSetupButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("serverHostButton"))));  // loads Court Selection Button
    component->getNetworkServerSetupMenuButtons()["backNetworkSetupButton"]->setVisible(false);
    component->getNetworkServerSetupMenuButtons()["backNetworkSetupButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::serverHostButtonClicked);
    component->getNetworkServerSetupMenuButtons()["backNetworkSetupButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    flag->setNetworkServerSetupMenuCreated(true);

    logMsg(func +" end");

    return true;
}

bool GUISystem::createCourtSelectionMenuGUI(renderEngineSharedPtr render)  // creates GUI for court selection menu screen.
{
//    renderEngineSharedPtr render; // = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();
    courtStateSharedPtr courtInst(new courtState);
    std::string func = "GUISystem::createCourtSelectionMenuGUI()";

    logMsg(func +" begin");

    MyGUI::LayoutManager::getInstance().loadLayout("CourtSelectionMenu.layout");

    component->setCourtSelectBox(MyGUIListBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::ListBox>("courtSelectBox")));  // loads Court Selection ListBox
    component->getCourtSelectBox()->setVisible(false);
//  courtSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::displayButtonClicked);

    component->setCourtNameTxtBox(MyGUITextBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::TextBox>("courtNameTxtBox")));  // loads Court Name TextBox
    component->getCourtNameTxtBox()->setVisible(false);
//  component->getCourtNameTxtBox()->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::displayButtonClicked);

    component->getCourtSelectionMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("courtSelectButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("courtSelectButton"))));  // loads Court Selection Button
    component->getCourtSelectionMenuButtons()["courtSelectButton"]->setVisible(false);
    component->getCourtSelectionMenuButtons()["courtSelectButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::courtSelectButtonClicked);
    component->getCourtSelectionMenuButtons()["courtSelectButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    component->getCourtSelectionMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backMainMenuButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("courtBackMainMenuButton"))));  // loads Back to Main Menu Button
    component->getCourtSelectionMenuButtons()["backMainMenuButton"]->setVisible(false);
    component->getCourtSelectionMenuButtons()["backMainMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backMainMenuButtonClicked);
    component->getCourtSelectionMenuButtons()["backMainMenuButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    component->getCourtPreviewImgBox() = MyGUIImageBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::ImageBox>("courtPreviewImgBox"));  // loads Court Preview ImageBox
    component->getCourtPreviewImgBox()->setVisible(false);
//  component->getCourtPreviewImgBox()->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::displayButtonClicked);
    component->getCourtPreviewImgBox()->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    flag->setCourtSelectionMenuCreated(true);

    logMsg(func +" end");

    return true;
}

bool GUISystem::createOptionsMenuGUI(renderEngineSharedPtr render)  // creates GUI for options menu screen.
{
//    renderEngineSharedPtr render; // = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();
    std::string func = "GUISystem::createOptionsMenuGUI()";

    logMsg(func +" begin");


    MyGUI::LayoutManager::getInstance().loadLayout("OptionsMenu.layout");

    component->getOptionsMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("displayButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("displayButton"))));  // loads Display Settings Button
    component->getOptionsMenuButtons()["displayButton"]->setVisible(false);
    component->getOptionsMenuButtons()["displayButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::displayButtonClicked);

    component->getOptionsMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("inputButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("inputButton"))));  // loads Input Settings Button
    component->getOptionsMenuButtons()["inputButton"]->setVisible(false);
    component->getOptionsMenuButtons()["inputButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::inputButtonClicked);

    component->getOptionsMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("audioButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("audioButton"))));  // loads Audio Settongs Button
    component->getOptionsMenuButtons()["audioButton"]->setVisible(false);
    component->getOptionsMenuButtons()["audioButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::audioButtonClicked);

    component->getOptionsMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backMainMenuButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("optionsBackMainMenuButton"))));  // loads Back to Main Menu Button
    component->getOptionsMenuButtons()["backMainMenuButton"]->setVisible(false);
    component->getOptionsMenuButtons()["backMainMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backMainMenuButtonClicked);
    component->getOptionsMenuButtons()["backMainMenuButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    flag->setOptionsMenuCreated(true);
/*    menuActive = true;
    previousActiveMenu = activeMenu;
    activeMenu = OPTIONS;
*/
    logMsg(func +" end");

    return (true);
}

bool GUISystem::createBackButtons()  // creates the back buttons for the menus
{
//    renderEngineSharedPtr render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();
//    exit(0);
    std::string func = "GUISystem::createBackButtons()";

    logMsg(func +" begin");


    MyGUI::LayoutManager::getInstance().loadLayout("BackButtons.layout");

///    backMainMenuButton = sharedPtr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("backMainMenuButton"));  // loads Back to Main Menu Button
///    backMainMenuButton->setVisible(false);
///    backMainMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backMainMenuButtonClicked);
///    backMainMenuButton->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

///    backNetworkSetupButton = sharedPtr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("backNetworkSetupButton"));  // loads Back to Network Setup Button
///    backNetworkSetupButton->setVisible(false);
///    backNetworkSetupButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backNetworkSetupButtonClicked);
///    backNetworkSetupButton->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

///    backNetworkClientButton = sharedPtr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("backNetworkClientButton"));  // loads Back to Network Client Button
///    backNetworkClientButton->setVisible(false);
///    backNetworkClientButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backNetworkClientButtonClicked);
///    backNetworkClientButton->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

///    backOptionsMenuButton = sharedPtr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("backOptionsMenuButton"));  // loads Back to Options Menu Button
///    backOptionsMenuButton->setVisible(false);
///    backOptionsMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backOptionsMenuButtonClicked);
///    backOptionsMenuButton->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

///    backCourtSelectionMenuButton = sharedPtr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("backCourtSelectionMenuButton"));  // loads Back to Team Selection Menu Button
///    backCourtSelectionMenuButton->setVisible(false);
///    backCourtSelectionMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backCourtSelectionMenuButtonClicked);
///    backCourtSelectionMenuButton->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

///    backTeamSelectionMenuButton = sharedPtr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("backTeamSelectionMenuButton"));  // loads Back to Team Selection Menu Button
///    backTeamSelectionMenuButton->setVisible(false);
///    backTeamSelectionMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backTeamSelectionMenuButtonClicked);
///    backTeamSelectionMenuButton->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );
    
///    backPlayerStartSelectionMenuButton = sharedPtr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("backPlayerStartSelectionMenuButton"));  // loads Back to Player Start Selection Menu Button
///    backPlayerStartSelectionMenuButton->setVisible(false);
///    backPlayerStartSelectionMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backPlayerStartSelectionMenuButtonClicked);
///    backPlayerStartSelectionMenuButton->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

///    backSetupMenuButton = sharedPtr<MyGUI::Button>(mGUI->findWidget<MyGUI::Button>("backSetupMenuButton"));  // loads Back to Game Setup Menu Button
///    backSetupMenuButton->setVisible(false);
///    backSetupMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backSetupMenuButtonClicked);
///    backSetupMenuButton->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    flag->setBackButtonsCreated(true);

    logMsg(func +" end");

    return (true);
}

bool GUISystem::createDisplaySetupGUI()  // creates GUI for display settings screen.
{
//    renderEngineSharedPtr render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();
    std::string func = "GUISystem::createDisplaySetupGUI()";

    logMsg(func +" begin");


    MyGUI::LayoutManager::getInstance().loadLayout("DispkaySetupMenu.layout");

    component->getDisplayMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("changeResolutionButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("changeResolutionButton"))));  // loads team 1 Button
    component->getDisplayMenuButtons()["changeResolutionButton"]->setVisible(false);
    component->getDisplayMenuButtons()["changeResolutionButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);

    component->getDisplayMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backOptionsMenuButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("changeInputTypeButton"))));  // loads team 1 Button
    component->getDisplayMenuButtons()["backOptionsMenuButton"]->setVisible(false);
    component->getDisplayMenuButtons()["backOptionsMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeInputTypeButtonClicked);

    flag->setDisplaySetupMenuCreated(true);

    logMsg(func +" end");

    return (true);
}

bool GUISystem::createInputSetupGUI()  // creates GUI for input settings screen.
{
//    renderEngineSharedPtr render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();
    std::string func = "GUISystem::createCourtInputSetupGUI()";

    logMsg(func +" begin");


    MyGUI::LayoutManager::getInstance().loadLayout("InputSetupMenu.layout");

    component->getInputMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("changeInputTypeButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("changeInputTypeButton"))));  // loads team 1 Button
    component->getInputMenuButtons()["changeInputTypeButton"]->setVisible(false);
    component->getInputMenuButtons()["changeInputTypeButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeInputTypeButtonClicked);

    component->getInputMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backOptionsMenuButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("changeInputTypeButton"))));  // loads team 1 Button
    component->getInputMenuButtons()["backOptionsMenuButton"]->setVisible(false);
    component->getInputMenuButtons()["backOptionsMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeInputTypeButtonClicked);

    flag->setInputSetupMenuCreated(true);

    logMsg(func + " end");
    return (true);
}

bool GUISystem::createAudioSetupGUI()  // creates GUI for audo settings screen.
{
//    renderEngineSharedPtr render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

    std::string func = "GUISystem::createAudioSetupGUI()";

    logMsg(func +" begin");


    MyGUI::LayoutManager::getInstance().loadLayout("AudioSetupMenu.layout");

    component->getAudioMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("enableAudioButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("enableAudioButton"))));  // loads team 1 Button
    component->getAudioMenuButtons()["enableAudioButton"]->setVisible(false);
    component->getAudioMenuButtons()["enableAudioButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::enableAudioButtonClicked);

    component->getAudioMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("disableAudioButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("disableAudioButton")))); // loads team 1 Button
    component->getAudioMenuButtons()["disableAudioButton"]->setVisible(false);
    component->getAudioMenuButtons()["disableAudioButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::disableAudioButtonClicked);

    component->getAudioMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backOptionsMenuButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("changeInputTypeButton"))));  // loads team 1 Button
    component->getAudioMenuButtons()["backOptionsMenuButton"]->setVisible(false);
    component->getAudioMenuButtons()["backOptionsMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeInputTypeButtonClicked);
    
    flag->setAudioSetupMenuCreated(true);

    logMsg(func +" end");

    return (true);
}


bool GUISystem::createSetupMenuGUI()    // creates GUI for game setup menu screen.
{
    //conversion *convert = conversion::Instance();
    conversionSharedPtr convert = conversion::Instance();
    //gameState *gameS = gameState::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
//    sharedPtr<loader> load(new loader);
//    renderEngineSharedPtr render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

    std::string func = "GUISystem::createCourtSetupMenuGUI()";

    logMsg(func +" begin");


    MyGUI::LayoutManager::getInstance().loadLayout("SetupMenu.layout");
    flag->setSetupMenuCreated(true);

    logMsg(func +" end");

    return (true);
}

bool GUISystem::createPlayerStartSelectionMenuGUI(renderEngineSharedPtr render)  // creates GUI for player selection menu screen.
{

    std::string func = "GUISystem::createPlayerStartSelectionMenuGUI()";
    
    logMsg(func + " beginning");
    
    MyGUI::LayoutManager::getInstance().loadLayout("PlayerStartSelection.layout");

    if (component->getTeamPlayerPosSelectBox().size() == 0)
    {
        std::map <std::string, MyGUIListBoxSharedPtr > playerPosSelectBox;
        component->getTeamPlayerPosSelectBox().push_back(playerPosSelectBox);
        component->getTeamPlayerPosSelectBox().push_back(playerPosSelectBox);
    }
    
    if (component->getTeamPlayerRating().size() == 0)
    {
        std::map <std::string, MyGUITextBoxSharedPtr > playerRating;
        component->getTeamPlayerRating().push_back(playerRating);
        component->getTeamPlayerRating().push_back(playerRating);
    }
    
    
    component->getTeamPlayerPosSelectBox()[0].insert(std::pair<std::string, MyGUIListBoxSharedPtr >("PG", MyGUIListBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::ListBox>("team0PGSelectBox"))));  // loads team0PGSelectBox
//    exit(0);
    component->getTeamPlayerPosSelectBox()[0]["PG"]->setVisible(false);
//    team0PGSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    component->getTeamPlayerPosSelectBox()[0]["PG"]->setSize((0.3 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));
    
    component->getTeamPlayerPosSelectBox()[0].insert(std::pair<std::string, MyGUIListBoxSharedPtr >("SG", MyGUIListBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::ListBox>("team0SGSelectBox"))));  // loads team0SGSelectBox
    component->getTeamPlayerPosSelectBox()[0]["SG"]->setVisible(false);
//    team0SGSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    component->getTeamPlayerPosSelectBox()[0]["SG"]->setSize((0.3 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getTeamPlayerPosSelectBox()[0].insert(std::pair<std::string, MyGUIListBoxSharedPtr >("SF", MyGUIListBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::ListBox>("team0SFSelectBox"))));  // loads team0SFSelectBox
    component->getTeamPlayerPosSelectBox()[0]["SF"]->setVisible(false);
//    team0SFSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    component->getTeamPlayerPosSelectBox()[0]["SF"]->setSize((0.3 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getTeamPlayerPosSelectBox()[0].insert(std::pair<std::string, MyGUIListBoxSharedPtr >("PF", MyGUIListBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::ListBox>("team0PFSelectBox"))));  // loads team0PFSelectBox
    component->getTeamPlayerPosSelectBox()[0]["PF"]->setVisible(false);
//    team0PFSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    component->getTeamPlayerPosSelectBox()[0]["PF"]->setSize((0.3 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getTeamPlayerPosSelectBox()[0].insert(std::pair<std::string, MyGUIListBoxSharedPtr >("C", MyGUIListBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::ListBox>("team0CSelectBox"))));  // loads team0CSelectBox
    component->getTeamPlayerPosSelectBox()[0]["C"]->setVisible(false);
//    team0CSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    component->getTeamPlayerPosSelectBox()[0]["C"]->setSize((0.3 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getTeamPlayerPosSelectBox()[1].insert(std::pair<std::string, MyGUIListBoxSharedPtr >("PG", MyGUIListBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::ListBox>("team1PGSelectBox"))));  // loads team1PGSelectBox
    component->getTeamPlayerPosSelectBox()[1]["PG"]->setVisible(false);
//    team1PGSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    component->getTeamPlayerPosSelectBox()[1]["PG"]->setSize((0.3 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getTeamPlayerPosSelectBox()[1].insert(std::pair<std::string, MyGUIListBoxSharedPtr >("SG", MyGUIListBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::ListBox>("team1SGSelectBox"))));  // loads team1SGSelectBox
    component->getTeamPlayerPosSelectBox()[1]["SG"]->setVisible(false);
//    team1SGSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    component->getTeamPlayerPosSelectBox()[1]["SG"]->setSize((0.3 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getTeamPlayerPosSelectBox()[1].insert(std::pair<std::string, MyGUIListBoxSharedPtr >("SF", MyGUIListBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::ListBox>("team1SFSelectBox"))));  // loads team1SFSelectBox
    component->getTeamPlayerPosSelectBox()[1]["SF"]->setVisible(false);
//    team1SFSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    component->getTeamPlayerPosSelectBox()[1]["SF"]->setSize((0.3 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getTeamPlayerPosSelectBox()[1].insert(std::pair<std::string, MyGUIListBoxSharedPtr >("PF", MyGUIListBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::ListBox>("team1PFSelectBox"))));  // loads team0PFSelectBox
    component->getTeamPlayerPosSelectBox()[1]["PF"]->setVisible(false);
//    team1PFSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    component->getTeamPlayerPosSelectBox()[1]["PF"]->setSize((0.3 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getTeamPlayerPosSelectBox()[1].insert(std::pair<std::string, MyGUIListBoxSharedPtr >("C", MyGUIListBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::ListBox>("team1CSelectBox"))));  // loads team1CSelectBox
    component->getTeamPlayerPosSelectBox()[1]["C"]->setVisible(false);
//    team1CSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    component->getTeamPlayerPosSelectBox()[1]["C"]->setSize((0.3 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getTeamPlayerRating()[0].insert(std::pair<std::string, MyGUITextBoxSharedPtr> ("PG", MyGUITextBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::TextBox>("team0PGRating"))));  // loads team0PGRatimg
    component->getTeamPlayerRating()[0]["PG"]->setVisible(false);
//    team0PGRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    component->getTeamPlayerRating()[0]["PG"]->setSize((0.1 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getTeamPlayerRating()[0].insert(std::pair<std::string, MyGUITextBoxSharedPtr> ("SG", MyGUITextBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::TextBox>("team0SGRating"))));  // loads team0SGRatimg
    component->getTeamPlayerRating()[0]["SG"]->setVisible(false);
//    team0SGRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    component->getTeamPlayerRating()[0]["SG"]->setSize((0.1 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getTeamPlayerRating()[0].insert(std::pair<std::string, MyGUITextBoxSharedPtr> ("SF", MyGUITextBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::TextBox>("team0SFRating"))));  // loads team0SFRatimg
    component->getTeamPlayerRating()[0]["SF"]->setVisible(false);
//    team0SFRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    component->getTeamPlayerRating()[0]["SF"]->setSize((0.1 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getTeamPlayerRating()[0].insert(std::pair<std::string, MyGUITextBoxSharedPtr> ("PF", MyGUITextBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::TextBox>("team0PFRating"))));  // loads team0PFRatimg
    component->getTeamPlayerRating()[0]["PF"]->setVisible(false);
//    team0PFRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    component->getTeamPlayerRating()[0]["PF"]->setSize((0.1 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getTeamPlayerRating()[0].insert(std::pair<std::string, MyGUITextBoxSharedPtr> ("C", MyGUITextBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::TextBox>("team0CRating"))));  // loads team0CRatimg
    component->getTeamPlayerRating()[0]["C"]->setVisible(false);
//    team0CRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    component->getTeamPlayerRating()[0]["C"]->setSize((0.1 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getTeamPlayerRating()[1].insert(std::pair<std::string, MyGUITextBoxSharedPtr> ("PG", MyGUITextBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::TextBox>("team1PGRating"))));  // loads team1PGRatimg
    component->getTeamPlayerRating()[1]["PG"]->setVisible(false);
//    team1PGRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    component->getTeamPlayerRating()[1]["PG"]->setSize((0.1 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getTeamPlayerRating()[1].insert(std::pair<std::string, MyGUITextBoxSharedPtr> ("SG", MyGUITextBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::TextBox>("team1SGRating"))));  // loads team1SGRatimg
    component->getTeamPlayerRating()[1]["SG"]->setVisible(false);
//    team1SGRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    component->getTeamPlayerRating()[1]["SG"]->setSize((0.1 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getTeamPlayerRating()[1].insert(std::pair<std::string, MyGUITextBoxSharedPtr> ("SF", MyGUITextBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::TextBox>("team1SFRating"))));  // loads team1SFRatimg
    component->getTeamPlayerRating()[1]["SF"]->setVisible(false);
//    team1SFRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    component->getTeamPlayerRating()[1]["SF"]->setSize((0.1 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getTeamPlayerRating()[1].insert(std::pair<std::string, MyGUITextBoxSharedPtr> ("PF", MyGUITextBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::TextBox>("team1PFRating"))));  // loads team1PFRatimg
    component->getTeamPlayerRating()[1]["PF"]->setVisible(false);
//    team1PFRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    component->getTeamPlayerRating()[1]["PF"]->setSize((0.1 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getTeamPlayerRating()[1].insert(std::pair<std::string, MyGUITextBoxSharedPtr> ("C", MyGUITextBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::TextBox>("team1CRating"))));  // loads team1CRatimg
    component->getTeamPlayerRating()[1]["C"]->setVisible(false);
//    team1CRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
    component->getTeamPlayerRating()[1]["C"]->setSize((0.1 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));


    component->getPlayerStartSelectionMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("team0StartingLineupSetButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("team0StartingLineupSetButton"))));  // loads team0StartingLineupSetButton
    component->getPlayerStartSelectionMenuButtons()["team0StartingLineupSetButton"]->setVisible(false);
    component->getPlayerStartSelectionMenuButtons()["team0StartingLineupSetButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team0StartingLineupSetButtonClicked);
    component->getPlayerStartSelectionMenuButtons()["team0StartingLineupSetButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getPlayerStartSelectionMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("team1StartingLineupSetButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("team1StartinglineupSetButton"))));  // loads team1StartingLineupSetButton
    component->getPlayerStartSelectionMenuButtons()["team1StartingLineupSetButton"]->setVisible(false);
    component->getPlayerStartSelectionMenuButtons()["team1StartingLineupSetButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team1StartingLineupSetButtonClicked);
    component->getPlayerStartSelectionMenuButtons()["team1StartingLineupSetButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getPlayerStartSelectionMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("startingLineupsSetButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("startingLineupsSetButton"))));  // loads team1StartingLineupSetButton
    component->getPlayerStartSelectionMenuButtons()["startingLineupsSetButton"]->setVisible(false);
    component->getPlayerStartSelectionMenuButtons()["startingLineupsSetButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::startingLineupSetButtonClicked);
    component->getPlayerStartSelectionMenuButtons()["startingLineupsSetButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->getPlayerStartSelectionMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backTeamSelectionMenuButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("backTeamSelectionMenuButton"))));  // loads Back to Team Selection Menu Button
    component->getPlayerStartSelectionMenuButtons()["backTeamSelectionMenuButton"]->setVisible(false);
    component->getPlayerStartSelectionMenuButtons()["backTeamSelectionMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backTeamSelectionMenuButtonClicked);
    component->getPlayerStartSelectionMenuButtons()["backTeamSelectionMenuButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );
    
    flag->setPlayerStartSelectionMenuCreated(true);

    logMsg(func +" end");

    return (true);
}

bool GUISystem::createTeamSelectionMenuGUI(renderEngineSharedPtr render)  // creates GUI for team selection menu screen.
{
//    renderEngineSharedPtr render;

    conversionSharedPtr convert = conversion::Instance();
    //
    MyGUI::LayoutManager::getInstance().loadLayout("TeamSelectionMenu.layout");
    
    float vpWidth = render->getViewPort()->getActualWidth();  // stores view ports width
    float vpHeight = render->getViewPort()->getActualHeight();  // stores view ports height
    
    std::string func = "GUISystem::createTeamSelectionMenuGUI()";

    logMsg(func +" begin");


    component->getTeamSelectBox().insert(std::pair<size_t, MyGUIListBoxSharedPtr > (0, MyGUIListBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::ListBox>("team0SelectBox"))));  // loads team 0 ListBox
    component->getTeamSelectBox()[0]->setVisible(false);
    component->getTeamSelectBox()[0]->setSize((0.4 *vpWidth), (0.04 *vpHeight));
    
    component->getTeamSelectBox().insert(std::pair<size_t, MyGUIListBoxSharedPtr > (1, MyGUIListBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::ListBox>("team1SelectBox"))));  // loads team 1 ListBox
    component->getTeamSelectBox()[1]->setVisible(false);
    component->getTeamSelectBox()[1]->setSize((0.4 *vpWidth), (0.04 *vpHeight));
    
    component->getTeamSelectionMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("team0SelectButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("team0SelectButton"))));  // loads team 0 Select Button  
    component->getTeamSelectionMenuButtons()["team0SelectButton"]->setVisible(false);
    component->getTeamSelectionMenuButtons()["team0SelectButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team0SelectButtonClicked);
    component->getTeamSelectionMenuButtons()["team0SelectButton"]->setSize((0.4 *vpWidth), (0.04 *vpHeight));
    component->getTeamSelectionMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("team1SelectButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("team1SelectButton"))));  // loads team 1 Button
    component->getTeamSelectionMenuButtons()["team1SelectButton"]->setVisible(false);
    component->getTeamSelectionMenuButtons()["team1SelectButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team1SelectButtonClicked);
    component->getTeamSelectionMenuButtons()["team1SelectButton"]->setSize((0.4 *vpWidth), (0.04 *vpHeight));

    component->getTeamSelectionMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("teamsSelectedButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("teamsSelectedButton"))));  // loads team 1 Button
    component->getTeamSelectionMenuButtons()["teamsSelectedButton"]->setVisible(false);
    component->getTeamSelectionMenuButtons()["teamsSelectedButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::teamsSelectedButtonClicked);
    component->getTeamSelectionMenuButtons()["teamsSelectedButton"]->setSize((0.4 *vpWidth), (0.04 *vpHeight) );
    
    component->getTeamSelectionMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backMainMenuButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("teamSelectionBackMainMenuButton"))));  // loads Back to Main Menu Button
    component->getTeamSelectionMenuButtons()["backMainMenuButton"]->setVisible(false);
    component->getTeamSelectionMenuButtons()["backMainMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backMainMenuButtonClicked);
    component->getTeamSelectionMenuButtons()["backMainMenuButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    component->getTeamSelectionMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backCourtSelectionMenuButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("backCourtSelectionMenuButton"))));  // loads Back to Team Selection Menu Button
    component->getTeamSelectionMenuButtons()["backCourtSelectionMenuButton"]->setVisible(false);
    component->getTeamSelectionMenuButtons()["backCourtSelectionMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backCourtSelectionMenuButtonClicked);
    component->getTeamSelectionMenuButtons()["backCourtSelectionMenuButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    flag->setTeamSelectionMenuCreated(true);
//    exit(0);

    logMsg(func +" end");

    return (true);
}


