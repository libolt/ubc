/***************************************************************************
 *   Copyright (C) 1999 - 2019 by Mike McLean                              *
 *   libolt@libolt.net                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under tkfvrffuuhe terms of the GNU General Public License as published by  *
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
 
#include "components/guicomponents.h"
#include "engine/gameengine.h"
#include "engine/renderengine.h"
#include "utilities/logging.h"

guiComponents::guiComponents()  // constructor
{
    initialized = false;
    mGUI = nullptr;
    numClientsSelectBox = nullptr;
    serverIPAddressBox = nullptr;
    clientIPAddressBox = nullptr;
    courtSelectBox = nullptr;
    courtPreviewImgBox = nullptr;
    courtNameTxtBox = nullptr;

    activeMenu = NOACTIVEMENU;

    previousActiveMenu = NOACTIVEMENU;

}

guiComponents::~guiComponents() = default;  // destructor


bool guiComponents::getInitialized() const  // retrieves the value of initialized
{
    return (initialized);
}
void guiComponents::setInitialized(const bool &set)  // sets the value of initialized
{
    initialized = set;
}

gameEngineSharedPtr guiComponents::getGamE() const  // retrieves the value of gameE
{
    return (gameE);
}
void guiComponents::setGameE(const gameEngineSharedPtr &set)  // sets the value of gameE
{
    gameE = set;
}

MyGUIGuiSharedPtr guiComponents::getMGUI() const  // retrieves the value of mGUI
{
    return (mGUI);
}
void guiComponents::setMGUI(const MyGUIGuiSharedPtr &set)  // sets the value of mGUI
{
    mGUI = set;
}

MyGUIButtonMSharedPtr guiComponents::getMainMenuButtons() const  // retrieves the value of mainMenuButtons
{
    return(mainMenuButtons);
}
void guiComponents::setMainMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of mainMenuButtons
{
     mainMenuButtons = set;
}

MyGUIButtonMSharedPtr guiComponents::getNetworkMenuButtons() const  // retrieves the value of networkMenuButtons
{
    return(networkMenuButtons);
}
void guiComponents::setNetworkMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of networkMenuButtons
{
    networkMenuButtons = set;
}

MyGUIButtonMSharedPtr guiComponents::getOptionsMenuButtons() const  // retrieves the value of optionsMenuButtons
{
    return(optionsMenuButtons);
}
void guiComponents::setOptionsMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of optionsMenuButtons
{
    optionsMenuButtons = set;
}

MyGUIButtonMSharedPtr guiComponents::getDisplayMenuButtons() const  // retrieves the value of displayMenuButtons
{
    return(displayMenuButtons);
}
void guiComponents::setDisplayMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of displayMenuButtons
{
    displayMenuButtons = set;
}

MyGUIButtonMSharedPtr guiComponents::getInputMenuButtons() const  // retrieves the value of inputMenuButtons
{
    return(inputMenuButtons);
}
void guiComponents::setInputMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of inputMenuButtons
{
    inputMenuButtons = set;
}

MyGUIButtonMSharedPtr guiComponents::getAudioMenuButtons() const  // retrieves the value of audioMenuButtons
{
    return(audioMenuButtons);
}
void guiComponents::setAudioMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of audioMenuButtons
{
    audioMenuButtons = set;
}

MyGUIButtonMSharedPtr guiComponents::getTeamSelectionMenuButtons() const  // retrieves the value of teamSelectionMenuButtons
{
    return(teamSelectionMenuButtons);
}
void guiComponents::setTeamSelectionMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of teamSelectionMenuButtons
{
    teamSelectionMenuButtons = set;
}

MyGUIButtonMSharedPtr guiComponents::getPlayerStartSelectionMenuButtons() const  // retrieves the value of playerStartSelectionMenuButtons
{
    return(playerStartSelectionMenuButtons);
}
void guiComponents::setPlayerStartSelectionMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of playerStartSelectionMenuButtons
{
    playerStartSelectionMenuButtons = set;
}

MyGUIListBoxMSharedPtr guiComponents::getTeamSelectBox() const  // retrieves the value of teamSelectBox
{
    return(teamSelectBox);
}
void guiComponents::setTeamSelectBox(const MyGUIListBoxMSharedPtr &set)  // sets the value of teamSelectBox
{
    teamSelectBox = set;
}

MyGUIListBoxSharedPtr guiComponents::getNumClientsSelectBox() const  // retrieves the value of numClientsSelectBox
{
    return(numClientsSelectBox);
}
void guiComponents::setNumClientsSelectBox(const MyGUIListBoxSharedPtr &set)  // sets the value of numClientsSelectBox
{
    numClientsSelectBox = set;
}

sharedPtr<MyGUI::EditBox> guiComponents::getServerIPAddressBox() const  // retrieves the value of serverIPAddressBox
{
    return(serverIPAddressBox);
}
void guiComponents::setServerIPAddressBox(const sharedPtr<MyGUI::EditBox> &set)  // sets the value of serverIPAddressBox
{
    serverIPAddressBox = set;
}

MyGUIButtonMSharedPtr guiComponents::getNetworkServerSetupMenuButtons() const // retrieves the value of networkServerSetupMenuButtons
{
    return(networkServerSetupMenuButtons);
}
void guiComponents::setNetworkServerSetupMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of networkServerSetupMenuButtons
{
    networkServerSetupMenuButtons = set;
}

sharedPtr<MyGUI::EditBox> guiComponents::getClientIPAddressBox() const  // retrieves the value of clientIPAddressBox
{
    return(clientIPAddressBox);
}
void guiComponents::setClientIPAddressBox(const sharedPtr<MyGUI::EditBox> &set)  // sets the value of clientIPAddressBox
{
    clientIPAddressBox = set;
}

MyGUIButtonMSharedPtr guiComponents::getNetworkClientSetupMenuButtons() const  // retrieves the value of networkClientSetupMenuButtons
{
    return(networkClientSetupMenuButtons);
}
void guiComponents::setNetworkClientSetupMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of networkClientSetupMenuButtons
{
    networkClientSetupMenuButtons = set;
}

MyGUIPlayerListBoxVecMSharedPtr guiComponents::getTeamPlayerPosSelectBox() const  // retrieves the value of teamPlayerPosSelectBox
{
    return(teamPlayerPosSelectBox);
}
void guiComponents::setTeamPlayerPosSelectBox(const MyGUIPlayerListBoxVecMSharedPtr &set)  // sets the value of teamPlayerPosSelectBox
{
    teamPlayerPosSelectBox = set;
}

MyGUITextBoxVecMSharedPtr guiComponents::getTeamPlayerRating() const  // retrieves the value of teamPlayerRating
{
    return(teamPlayerRating);
}
void guiComponents::setTeamPlayerRating(const MyGUITextBoxVecMSharedPtr &set)  // sets the value of teamPlayerRating
{
    teamPlayerRating = set;
}

MyGUIImageBoxMSharedPtr guiComponents::getTeamLogo() const  // retrieves the value of teamLogo
{
    return(teamLogo);
}
void guiComponents::setTeamLogo(const MyGUIImageBoxMSharedPtr &set)  // sets the value of teamLogo
{
    teamLogo = set;
}

MyGUIButtonMSharedPtr guiComponents::getCourtSelectionMenuButtons() const  // retrieves the value of courtSelectionMenuButtons
{
    return(courtSelectionMenuButtons);
}
void guiComponents::setCourtSelectionMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of courtSelectionMenuButtons
{
    courtSelectionMenuButtons = set;
}

MyGUIListBoxSharedPtr guiComponents::getCourtSelectBox() const  // retrieves the value of courtSelectBox
{
    return(courtSelectBox);
}
void guiComponents::setCourtSelectBox(const MyGUIListBoxSharedPtr &set)  // sets the value of courtSelectBox
{
    courtSelectBox = set;
}

MyGUIImageBoxSharedPtr guiComponents::getCourtPreviewImgBox() const  // retrieves the value of courtPreviewImgBox
{
    return(courtPreviewImgBox);
}
void guiComponents::setCourtPreviewImgBox(const MyGUIImageBoxSharedPtr &set)  // sets the value of courtPreviewImgBox
{
    courtPreviewImgBox = set;
}

MyGUITextBoxSharedPtr guiComponents::getCourtNameTxtBox() const  // retrieves the value of courtNameTxtBox
{
    return(courtNameTxtBox);
}
void guiComponents::setCourtNameTxtBox(const MyGUITextBoxSharedPtr &set)  // sets the value of courtNameTxtBox
{
    courtNameTxtBox = set;
}

activeMenus guiComponents::getActiveMenu() const  // retrieves the value of activeMenu
{
    return (activeMenu);
}
void guiComponents::setActiveMenu(const activeMenus &set)  // sets the value of activeMenu
{
    activeMenu = set;
}

activeMenus guiComponents::getPreviousActiveMenu() const  // retrieves the value of previousActiveMenu
{
    return (previousActiveMenu);
}
void guiComponents::setPreviousActiveMenu(const activeMenus &set)  // sets the value of previousActiveMenu
{
    previousActiveMenu = set;
}

mainMenuSelects guiComponents::getMainMenuSelect() const  // retrieves the value of displayedMenu
{
    return (mainMenuSelect);
}
void guiComponents::setMainMenuSelect(const mainMenuSelects &set)  // sets the value of displayedMenu
{
    mainMenuSelect = set;
}

/*  void guiComponents::startSingleGameButtonClicked(MyGUI::Widget *_sender)  // handles startSingleGameButton click event
{
//    startSinglePlayerGame(gameE->getRenderE());
}*/


void guiComponents::startSingleGameButtonClicked(MyGUI::Widget *_sender)  // handles startSingleGameButton click event
{
    mainMenuSelect = STARTSINGLE;
//    startSinglePlayerGame(gameE->getRenderE());
}

void guiComponents::startMultiGameButtonClicked(MyGUI::Widget *_sender)  // handles startMultiGameButton click event
{
    mainMenuSelect = STARTMULTI;
//    startMultiPlayerGame(gameE->getRenderE());
}

void guiComponents::optionsButtonClicked(MyGUI::Widget *_sender)  // handles optionsButton click event
{
    mainMenuSelect = OPTIONSSELECT;
//    optionsMenu(gameE->getRenderE());
}

void guiComponents::exitButtonClicked(MyGUI::Widget *_sender)  // handles exitButton click event
{
    exit(0);
}


bool guiComponents::initMyGUI(const renderEngineSharedPtr &render)  // Initializes MyGUI
{
    std::string func = "GUIComponents::initMyGUI()";
    
    logMsg(func +" begin");
    logMsg(func +" *** Initializing MyGUI ***");
    MyGUIOgrePlatformSharedPtr tempPlatform(new MyGUI::OgrePlatform());
    mPlatform = tempPlatform;
//    logMsg(func +" Crash?");

    mPlatform->initialise(render->getMWindow().get(), render->getMSceneMgr().get(), "UBCData"); // mWindow is Ogre::RenderWindow*, mSceneManager is Ogre::SceneManager*a@aa

    logMsg(func +" Crash??");
    MyGUIGuiSharedPtr tempGUI(new MyGUI::Gui());
//    exit(0);
    mGUI = tempGUI;
//    exit(0);
//    logMsg(func +" Crash???");
    mGUI->initialise();
//    exit(0);
    logMsg(func +" *** MyGUI Initialized ***");
    logMsg(func +" end");
    return true;
}

