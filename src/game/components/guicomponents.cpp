/***************************************************************************
 *   Copyright (C) 1999 - 2018 by Mike McLean                              *
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
#include "utilities/logging.h"
#include "engine/renderengine.h"

GUIComponents::GUIComponents()  // constructor
{
    initialized = false;
    mGUI = nullptr;
    numClientsSelectBox = nullptr;
    serverIPAddressBox = nullptr;
    clientIPAddressBox = nullptr;
    courtSelectBox = nullptr;
    courtPreviewImgBox = nullptr;
    courtNameTxtBox = nullptr;
}

GUIComponents::~GUIComponents() = default;  // destructor


bool GUIComponents::getInitialized() const  // retrieves the value of initialized
{
    return (initialized);
}
void GUIComponents::setInitialized(const bool &set)  // sets the value of initialized
{
    initialized = set;
}

MyGUIGuiSharedPtr GUIComponents::getMGUI() const  // retrieves the value of mGUI
{
    return (mGUI);
}
void GUIComponents::setMGUI(const MyGUIGuiSharedPtr &set)  // sets the value of mGUI
{
    mGUI = set;
}

MyGUIButtonMSharedPtr GUIComponents::getMainMenuButtons() const  // retrieves the value of mainMenuButtons
{
    return(mainMenuButtons);
}
void GUIComponents::setMainMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of mainMenuButtons
{
     mainMenuButtons = set;
}

MyGUIButtonMSharedPtr GUIComponents::getNetworkMenuButtons() const  // retrieves the value of networkMenuButtons
{
    return(networkMenuButtons);
}
void GUIComponents::setNetworkMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of networkMenuButtons
{
    networkMenuButtons = set;
}

MyGUIButtonMSharedPtr GUIComponents::getOptionsMenuButtons() const  // retrieves the value of optionsMenuButtons
{
    return(optionsMenuButtons);
}
void GUIComponents::setOptionsMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of optionsMenuButtons
{
    optionsMenuButtons = set;
}

MyGUIButtonMSharedPtr GUIComponents::getDisplayMenuButtons() const  // retrieves the value of displayMenuButtons
{
    return(displayMenuButtons);
}
void GUIComponents::setDisplayMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of displayMenuButtons
{
    displayMenuButtons = set;
}

MyGUIButtonMSharedPtr GUIComponents::getInputMenuButtons() const  // retrieves the value of inputMenuButtons
{
    return(inputMenuButtons);
}
void GUIComponents::setInputMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of inputMenuButtons
{
    inputMenuButtons = set;
}

MyGUIButtonMSharedPtr GUIComponents::getAudioMenuButtons() const  // retrieves the value of audioMenuButtons
{
    return(audioMenuButtons);
}
void GUIComponents::setAudioMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of audioMenuButtons
{
    audioMenuButtons = set;
}

MyGUIButtonMSharedPtr GUIComponents::getTeamSelectionMenuButtons() const  // retrieves the value of teamSelectionMenuButtons
{
    return(teamSelectionMenuButtons);
}
void GUIComponents::setTeamSelectionMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of teamSelectionMenuButtons
{
    teamSelectionMenuButtons = set;
}

MyGUIButtonMSharedPtr GUIComponents::getPlayerStartSelectionMenuButtons() const  // retrieves the value of playerStartSelectionMenuButtons
{
    return(playerStartSelectionMenuButtons);
}
void GUIComponents::setPlayerStartSelectionMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of playerStartSelectionMenuButtons
{
    playerStartSelectionMenuButtons = set;
}

MyGUIListBoxMSharedPtr GUIComponents::getTeamSelectBox() const  // retrieves the value of teamSelectBox
{
    return(teamSelectBox);
}
void GUIComponents::setTeamSelectBox(const MyGUIListBoxMSharedPtr &set)  // sets the value of teamSelectBox
{
    teamSelectBox = set;
}

MyGUIListBoxSharedPtr GUIComponents::getNumClientsSelectBox() const  // retrieves the value of numClientsSelectBox
{
    return(numClientsSelectBox);
}
void GUIComponents::setNumClientsSelectBox(const MyGUIListBoxSharedPtr &set)  // sets the value of numClientsSelectBox
{
    numClientsSelectBox = set;
}

sharedPtr<MyGUI::EditBox> GUIComponents::getServerIPAddressBox() const  // retrieves the value of serverIPAddressBox
{
    return(serverIPAddressBox);
}
void GUIComponents::setServerIPAddressBox(const sharedPtr<MyGUI::EditBox> &set)  // sets the value of serverIPAddressBox
{
    serverIPAddressBox = set;
}

MyGUIButtonMSharedPtr GUIComponents::getNetworkServerSetupMenuButtons() const // retrieves the value of networkServerSetupMenuButtons
{
    return(networkServerSetupMenuButtons);
}
void GUIComponents::setNetworkServerSetupMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of networkServerSetupMenuButtons
{
    networkServerSetupMenuButtons = set;
}

sharedPtr<MyGUI::EditBox> GUIComponents::getClientIPAddressBox() const  // retrieves the value of clientIPAddressBox
{
    return(clientIPAddressBox);
}
void GUIComponents::setClientIPAddressBox(const sharedPtr<MyGUI::EditBox> &set)  // sets the value of clientIPAddressBox
{
    clientIPAddressBox = set;
}

MyGUIButtonMSharedPtr GUIComponents::getNetworkClientSetupMenuButtons() const  // retrieves the value of networkClientSetupMenuButtons
{
    return(networkClientSetupMenuButtons);
}
void GUIComponents::setNetworkClientSetupMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of networkClientSetupMenuButtons
{
    networkClientSetupMenuButtons = set;
}

MyGUIPlayerListBoxVecMSharedPtr GUIComponents::getTeamPlayerPosSelectBox() const  // retrieves the value of teamPlayerPosSelectBox
{
    return(teamPlayerPosSelectBox);
}
void GUIComponents::setTeamPlayerPosSelectBox(const MyGUIPlayerListBoxVecMSharedPtr &set)  // sets the value of teamPlayerPosSelectBox
{
    teamPlayerPosSelectBox = set;
}

MyGUITextBoxVecMSharedPtr GUIComponents::getTeamPlayerRating() const  // retrieves the value of teamPlayerRating
{
    return(teamPlayerRating);
}
void GUIComponents::setTeamPlayerRating(const MyGUITextBoxVecMSharedPtr &set)  // sets the value of teamPlayerRating
{
    teamPlayerRating = set;
}

MyGUIImageBoxMSharedPtr GUIComponents::getTeamLogo() const  // retrieves the value of teamLogo
{
    return(teamLogo);
}
void GUIComponents::setTeamLogo(const MyGUIImageBoxMSharedPtr &set)  // sets the value of teamLogo
{
    teamLogo = set;
}

MyGUIButtonMSharedPtr GUIComponents::getCourtSelectionMenuButtons() const  // retrieves the value of courtSelectionMenuButtons
{
    return(courtSelectionMenuButtons);
}
void GUIComponents::setCourtSelectionMenuButtons(const MyGUIButtonMSharedPtr &set)  // sets the value of courtSelectionMenuButtons
{
    courtSelectionMenuButtons = set;
}

MyGUIListBoxSharedPtr GUIComponents::getCourtSelectBox() const  // retrieves the value of courtSelectBox
{
    return(courtSelectBox);
}
void GUIComponents::setCourtSelectBox(const MyGUIListBoxSharedPtr &set)  // sets the value of courtSelectBox
{
    courtSelectBox = set;
}

MyGUIImageBoxSharedPtr GUIComponents::getCourtPreviewImgBox() const  // retrieves the value of courtPreviewImgBox
{
    return(courtPreviewImgBox);
}
void GUIComponents::setCourtPreviewImgBox(const MyGUIImageBoxSharedPtr &set)  // sets the value of courtPreviewImgBox
{
    courtPreviewImgBox = set;
}

MyGUITextBoxSharedPtr GUIComponents::getCourtNameTxtBox() const  // retrieves the value of courtNameTxtBox
{
    return(courtNameTxtBox);
}
void GUIComponents::setCourtNameTxtBox(const MyGUITextBoxSharedPtr &set)  // sets the value of courtNameTxtBox
{
    courtNameTxtBox = set;
}

/*  void GUIComponents::startSingleGameButtonClicked(MyGUI::Widget *_sender)  // handles startSingleGameButton click event
{
//    startSinglePlayerGame(gameE->getRenderE());
}*/


bool GUIComponents::initMyGUI(const renderEngineSharedPtr &render)  // Initializes MyGUI
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

