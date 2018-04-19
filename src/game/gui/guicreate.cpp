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
    conversionSharedPtr convert = conversion::Instance();

    MyGUIButtonMSharedPtr tempButtons;
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
    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("startSingleGameButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("startSingleGameButton"))));
    
    //component->getMainMenuButtons().insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("startSingleGameButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("startSingleGameButton"))));
    logMsg(func +" Insert Start Single Game Button");
//    logMsg(func +" component->getMainMenuButtons().size() == " +convert->toString(component->getMainMenuButtons().size()));
    logMsg(func +" tempButtons.size() == " +convert->toString(tempButtons.size()));

//    exit(0);
    tempButtons["startSingleGameButton"]->eventMouseButtonClick += MyGUI::newDelegate(component.get(), &component.get()->startSingleGameButtonClicked);
    logMsg(func +" Insert Start Single Game Button Mouse Click");

//    exit(0);
    tempButtons["startSingleGameButton"]->setStateSelected(true);
    logMsg(func +" Insert Start Single Game Button State Selected");

//    exit(0);
    MyGUI::InputManager::getInstance().setKeyFocusWidget(tempButtons["startSingleGameButton"].get());
    logMsg(func +" Insert Start Single Game Button Inpur Manager");

//    exit(0);
    tempButtons["startSingleGameButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.1 *render->getViewPort()->getActualHeight()) );
    tempButtons["startSingleGameButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );
    tempButtons["startSingleGameButton"]->setVisible(false);
//    exit(0);
    
    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("startSingleGameButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("startSingleGameButton"))));
    
    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("startMultiGameButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("startMultiGameButton"))));
//    exit(0);
    tempButtons["startMultiGameButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::startMultiGameButtonClicked);
    tempButtons["startMultiGameButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.14 *render->getViewPort()->getActualHeight()) );
    tempButtons["startMultiGameButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );
    tempButtons["startMultiGameButton"]->setVisible(false);
//  optionsButton =    mGUI->createWidget<MyGUI::Button>("Button", 362, 125, 300, 26, MyGUI::Align::Default, "Main");
//  optionsButton->setCaption(",?ik.??..?llmmmmllml.....l.m. onOptions");
    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("optionsButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("optionsButton"))));
//    exit(0);
    tempButtons["optionsButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::optionsButtonClicked);
    tempButtons["optionsButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.18 *render->getViewPort()->getActualHeight()) );
    tempButtons["optionsButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );
    tempButtons["optionsButton"]->setVisible(false);
//  exitButton = mGUI->createWidget<MyGUI::Button>("Button", 362, 150, 300, 26, MyGUI::Align::Default, "Main");
//  exitButton->setCaption("Exit");mlklkklllmmmmmmm mmllm
    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("exitButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("exitButton"))));
//    exit(0);
    tempButtons["exitButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::exitButtonClicked);
    tempButtons["exitButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.22 *render->getViewPort()->getActualHeight()) );
    tempButtons["exitButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );
    tempButtons["exitButton"]->setVisible(false);
   
    component->setMainMenuButtons(tempButtons);
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
    MyGUIButtonMSharedPtr tempButtons;

    std::string func = "GUISystem::createNetworkSetupGUI()";

    logMsg(func +" begin");

    MyGUI::LayoutManager::getInstance().loadLayout("NetworkSetupMenu.layout");

    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("serverButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("serverButton")))); // loads Server Button
    tempButtons["serverButton"]->setVisible(false);
    tempButtons["serverButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::serverButtonClicked);
    tempButtons["serverButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.14 *render->getViewPort()->getActualHeight()) );
    tempButtons["serverButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("clientButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("clientButton")))); // loads Client Button
    tempButtons["clientButton"]->setVisible(false);
    tempButtons["clientButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::clientButtonClicked);
    tempButtons["clientButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.18 *render->getViewPort()->getActualHeight()) );
    tempButtons["clientButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    
    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backMainMenuButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("networkBackMainMenuButton"))));  // loads Back to Main Menu Button
    tempButtons["backMainMenuButton"]->setVisible(false);
    tempButtons["backMainMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backMainMenuButtonClicked);
    tempButtons["backMainMenuButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    component->setNetworkMenuButtons(tempButtons);

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
    
    MyGUIButtonMSharedPtr tempButtons;

    std::string func = "GUISystem::createNetworkClientSetupGUI()";

    logMsg(func +" begin");

    MyGUI::LayoutManager::getInstance().loadLayout("NetworkClientSetupMenu.layout");

    component->setClientIPAddressBox(sharedPtr<MyGUI::EditBox>(component->getMGUI()->findWidget<MyGUI::EditBox>("clientIPAddressBox")));  // loads IP Address EditBox    clientIPAddressBox->setVisible(false);
    component->getClientIPAddressBox()->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.10 *render->getViewPort()->getActualHeight()) );
    component->getClientIPAddressBox()->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("clientConnectButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("clientConnectButton"))));  // loads Court Selection Button
    tempButtons["clientConnectButton"]->setVisible(false);
    tempButtons["clientConnectButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::clientConnectButtonClicked);
    tempButtons["clientConnectButton"]->setSize((0.4 *render->getViewPort()->getActualWidth()), (0.04 *render->getViewPort()->getActualHeight()));

    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backNetworkSetupButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("serverHostButton"))));  // loads Court Selection Button
    tempButtons["backNetworkSetupButton"]->setVisible(false);
    tempButtons["backNetworkSetupButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::serverHostButtonClicked);
    tempButtons["backNetworkSetupButton"]->setSize((0.4 *render->getViewPort()->getActualWidth()), (0.04 *render->getViewPort()->getActualHeight()));

    component->setNetworkClientSetupMenuButtons(tempButtons);

    flag->setNetworkClientSetupMenuCreated(true);
    
    logMsg(func +" end");
    return true;
}

bool GUISystem::createNetworkServerSetupGUI(renderEngineSharedPtr render)  // creates GUI for network server setup screen.
{
//    renderEngineSharedPtr render; // = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

    MyGUIButtonMSharedPtr tempButtons;

    std::string func = "GUISystem::createNetworkServerSetupGUI()";

    logMsg(func +" begin");

    MyGUI::LayoutManager::getInstance().loadLayout("NetworkServerSetupMenu.layout");

    component->setNumClientsSelectBox(MyGUIListBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::ListBox>("numClientsSelectBox")));  // loads  Selection box for number of clients allowed
    component->getNumClientsSelectBox()->setVisible(false);
    
    component->setServerIPAddressBox(sharedPtr<MyGUI::EditBox>(component->getMGUI()->findWidget<MyGUI::EditBox>("serverIPAddressBox")));  // loads IP Address EditBox
    component->getServerIPAddressBox()->setVisible(false);
    component->getServerIPAddressBox()->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.10 *render->getViewPort()->getActualHeight()) );
    component->getServerIPAddressBox()->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("serverHostButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("serverHostButton"))));  // loads Court Selection Button
    tempButtons["serverHostButton"]->setVisible(false);
    tempButtons["serverHostButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::serverHostButtonClicked);
    tempButtons["serverHostButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backNetworkSetupButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("serverHostButton"))));  // loads Court Selection Button
    tempButtons["backNetworkSetupButton"]->setVisible(false);
    tempButtons["backNetworkSetupButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::serverHostButtonClicked);
    tempButtons["backNetworkSetupButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    component->setNetworkServerSetupMenuButtons(tempButtons);

    flag->setNetworkServerSetupMenuCreated(true);

    logMsg(func +" end");

    return true;
}

bool GUISystem::createCourtSelectionMenuGUI(renderEngineSharedPtr render)  // creates GUI for court selection menu screen.
{
//    renderEngineSharedPtr render; // = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();
    courtStateSharedPtr courtInst(new courtState);
    MyGUIButtonMSharedPtr tempButtons;
    MyGUIListBoxSharedPtr tempSelectBox(new MyGUI::ListBox);
    MyGUITextBoxSharedPtr tempTxtBox;
    MyGUIImageBoxSharedPtr tempPreviewImgBox;
    std::string func = "GUISystem::createCourtSelectionMenuGUI()";

    logMsg(func +" begin");

    MyGUI::LayoutManager::getInstance().loadLayout("CourtSelectionMenu.layout");
    MyGUI::ListBox *tempBox = component->getMGUI()->findWidget<MyGUI::ListBox>("courtSelectBox");
    exit(0);
    tempSelectBox = MyGUIListBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::ListBox>("courtSelectBox"));  // loads Court Selection ListBox
    logMsg(func +" tempSelectBox");
    exit(0);
    tempSelectBox->setVisible(false);
//  courtSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::displayButtonClicked);

    tempTxtBox = MyGUITextBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::TextBox>("courtNameTxtBox"));  // loads Court Name TextBox
    tempTxtBox->setVisible(false);
//  component->getCourtNameTxtBox()->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::displayButtonClicked);

    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("courtSelectButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("courtSelectButton"))));  // loads Court Selection Button
    tempButtons["courtSelectButton"]->setVisible(false);
    tempButtons["courtSelectButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::courtSelectButtonClicked);
    tempButtons["courtSelectButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backMainMenuButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("courtBackMainMenuButton"))));  // loads Back to Main Menu Button
    tempButtons["backMainMenuButton"]->setVisible(false);
    tempButtons["backMainMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backMainMenuButtonClicked);
    tempButtons["backMainMenuButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    tempPreviewImgBox = MyGUIImageBoxSharedPtr(component->getMGUI()->findWidget<MyGUI::ImageBox>("courtPreviewImgBox"));  // loads Court Preview ImageBox
    tempPreviewImgBox->setVisible(false);
//  tempPreviewImgBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::displayButtonClicked);
    tempPreviewImgBox->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    component->setCourtSelectionMenuButtons(tempButtons);
    component->setCourtSelectBox(tempSelectBox);
    component->setCourtNameTxtBox(tempTxtBox);
    component->setCourtPreviewImgBox(tempPreviewImgBox);

    flag->setCourtSelectionMenuCreated(true);

    logMsg(func +" end");

    return true;
}

bool GUISystem::createOptionsMenuGUI(renderEngineSharedPtr render)  // creates GUI for options menu screen.
{
//    renderEngineSharedPtr render; // = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();
    MyGUIButtonMSharedPtr tempButtons;

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

    component->setOptionsMenuButtons(tempButtons);

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
    
    MyGUIButtonMSharedPtr tempButtons;

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
    MyGUIButtonMSharedPtr tempButtons;

    std::string func = "GUISystem::createDisplaySetupGUI()";

    logMsg(func +" begin");


    MyGUI::LayoutManager::getInstance().loadLayout("DispkaySetupMenu.layout");

    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("changeResolutionButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("changeResolutionButton"))));  // loads team 1 Button
    tempButtons["changeResolutionButton"]->setVisible(false);
    tempButtons["changeResolutionButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);

    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backOptionsMenuButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("changeInputTypeButton"))));  // loads team 1 Button
    tempButtons["backOptionsMenuButton"]->setVisible(false);
    tempButtons["backOptionsMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeInputTypeButtonClicked);

    component->setDisplayMenuButtons(tempButtons);

    flag->setDisplaySetupMenuCreated(true);

    logMsg(func +" end");

    return (true);
}

bool GUISystem::createInputSetupGUI()  // creates GUI for input settings screen.
{
//    renderEngineSharedPtr render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();
    MyGUIButtonMSharedPtr tempButtons;

    std::string func = "GUISystem::createCourtInputSetupGUI()";

    logMsg(func +" begin");

    MyGUI::LayoutManager::getInstance().loadLayout("InputSetupMenu.layout");

    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("changeInputTypeButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("changeInputTypeButton"))));  // loads team 1 Button
    tempButtons["changeInputTypeButton"]->setVisible(false);
    tempButtons["changeInputTypeButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeInputTypeButtonClicked);

    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backOptionsMenuButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("changeInputTypeButton"))));  // loads team 1 Button
    tempButtons["backOptionsMenuButton"]->setVisible(false);
    tempButtons["backOptionsMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeInputTypeButtonClicked);

    component->setInputMenuButtons(tempButtons);

    flag->setInputSetupMenuCreated(true);

    logMsg(func + " end");
    return (true);
}

bool GUISystem::createAudioSetupGUI()  // creates GUI for audo settings screen.
{
//    renderEngineSharedPtr render = renderEngine::Instance();
//    Ogre::Viewport *viewPort = render->getViewPort();

    MyGUIButtonMSharedPtr tempButtons;

    std::string func = "GUISystem::createAudioSetupGUI()";

    logMsg(func +" begin");

    MyGUI::LayoutManager::getInstance().loadLayout("AudioSetupMenu.layout");

    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("enableAudioButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("enableAudioButton"))));  // loads team 1 Button
    tempButtons["enableAudioButton"]->setVisible(false);
    tempButtons["enableAudioButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::enableAudioButtonClicked);

    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("disableAudioButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("disableAudioButton")))); // loads team 1 Button
    tempButtons["disableAudioButton"]->setVisible(false);
    tempButtons["disableAudioButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::disableAudioButtonClicked);

    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backOptionsMenuButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("changeInputTypeButton"))));  // loads team 1 Button
    tempButtons["backOptionsMenuButton"]->setVisible(false);
    tempButtons["backOptionsMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeInputTypeButtonClicked);
    
    component->setAudioMenuButtons(tempButtons);

    flag->setAudioSetupMenuCreated(true);

    logMsg(func +" end");

    return (true);
}


bool GUISystem::createSetupMenuGUI()    // creates GUI for game setup menu screen.
{
    conversionSharedPtr convert = conversion::Instance();

    std::string func = "GUISystem::createCourtSetupMenuGUI()";

    logMsg(func +" begin");


    MyGUI::LayoutManager::getInstance().loadLayout("SetupMenu.layout");
    flag->setSetupMenuCreated(true);

    logMsg(func +" end");

    return (true);
}

bool GUISystem::createPlayerStartSelectionMenuGUI(renderEngineSharedPtr render)  // creates GUI for player selection menu screen.
{

    MyGUIButtonMSharedPtr tempButtons;

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


    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("team0StartingLineupSetButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("team0StartingLineupSetButton"))));  // loads team0StartingLineupSetButton
    tempButtons["team0StartingLineupSetButton"]->setVisible(false);
    tempButtons["team0StartingLineupSetButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team0StartingLineupSetButtonClicked);
    tempButtons["team0StartingLineupSetButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("team1StartingLineupSetButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("team1StartinglineupSetButton"))));  // loads team1StartingLineupSetButton
    tempButtons["team1StartingLineupSetButton"]->setVisible(false);
    tempButtons["team1StartingLineupSetButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team1StartingLineupSetButtonClicked);
    tempButtons["team1StartingLineupSetButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("startingLineupsSetButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("startingLineupsSetButton"))));  // loads team1StartingLineupSetButton
    tempButtons["startingLineupsSetButton"]->setVisible(false);
    tempButtons["startingLineupsSetButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::startingLineupSetButtonClicked);
    tempButtons["startingLineupsSetButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()));

    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backTeamSelectionMenuButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("backTeamSelectionMenuButton"))));  // loads Back to Team Selection Menu Button
    tempButtons["backTeamSelectionMenuButton"]->setVisible(false);
    tempButtons["backTeamSelectionMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backTeamSelectionMenuButtonClicked);
    tempButtons["backTeamSelectionMenuButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );
    
    component->setPlayerStartSelectionMenuButtons(tempButtons);

    flag->setPlayerStartSelectionMenuCreated(true);

    logMsg(func +" end");

    return (true);
}

bool GUISystem::createTeamSelectionMenuGUI(renderEngineSharedPtr render)  // creates GUI for team selection menu screen.
{
//    renderEngineSharedPtr render;

    MyGUIButtonMSharedPtr tempButtons;

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
    
    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("team0SelectButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("team0SelectButton"))));  // loads team 0 Select Button  
    tempButtons["team0SelectButton"]->setVisible(false);
    tempButtons["team0SelectButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team0SelectButtonClicked);
    tempButtons["team0SelectButton"]->setSize((0.4 *vpWidth), (0.04 *vpHeight));
    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("team1SelectButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("team1SelectButton"))));  // loads team 1 Button
    tempButtons["team1SelectButton"]->setVisible(false);
    tempButtons["team1SelectButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team1SelectButtonClicked);
    tempButtons["team1SelectButton"]->setSize((0.4 *vpWidth), (0.04 *vpHeight));

    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("teamsSelectedButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("teamsSelectedButton"))));  // loads team 1 Button
    tempButtons["teamsSelectedButton"]->setVisible(false);
    tempButtons["teamsSelectedButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::teamsSelectedButtonClicked);
    tempButtons["teamsSelectedButton"]->setSize((0.4 *vpWidth), (0.04 *vpHeight) );
    
    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backMainMenuButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("teamSelectionBackMainMenuButton"))));  // loads Back to Main Menu Button
    tempButtons["backMainMenuButton"]->setVisible(false);
    tempButtons["backMainMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backMainMenuButtonClicked);
    tempButtons["backMainMenuButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    tempButtons.insert(std::pair<std::string, sharedPtr<MyGUI::Button> >("backCourtSelectionMenuButton", sharedPtr<MyGUI::Button>(component->getMGUI()->findWidget<MyGUI::Button>("backCourtSelectionMenuButton"))));  // loads Back to Team Selection Menu Button
    tempButtons["backCourtSelectionMenuButton"]->setVisible(false);
    tempButtons["backCourtSelectionMenuButton"]->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backCourtSelectionMenuButtonClicked);
    tempButtons["backCourtSelectionMenuButton"]->setSize((0.4 *render->getViewPort()->getActualWidth() ), (0.04 *render->getViewPort()->getActualHeight()) );

    component->setTeamSelectionMenuButtons(tempButtons);

    flag->setTeamSelectionMenuCreated(true);
//    exit(0);

    logMsg(func +" end");

    return (true);
}


