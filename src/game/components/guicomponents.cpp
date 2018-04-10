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

}

GUIComponents::~GUIComponents()  // destructor
{

}

MyGUIGuiSharedPtr GUIComponents::getMGUI()  // retrieves the value of mGUI
{
    return (mGUI);
}
void GUIComponents::setMGUI(MyGUIGuiSharedPtr set)  // sets the value of mGUI
{
    mGUI = set;
}

MyGUIButtonMSharedPtr GUIComponents::getMainMenuButtons()  // retrieves the value of mainMenuButtons
{
    return(mainMenuButtons);
}
void GUIComponents::setMainMenuButtons(MyGUIButtonMSharedPtr set)  // sets the value of mainMenuButtons
{
     mainMenuButtons = set;
}

MyGUIButtonMSharedPtr GUIComponents::getNetworkMenuButtons()  // retrieves the value of networkMenuButtons
{
    return(networkMenuButtons);
}
void GUIComponents::setNetworkMenuButtons(MyGUIButtonMSharedPtr set)  // sets the value of networkMenuButtons
{
    networkMenuButtons = set;
}

MyGUIButtonMSharedPtr GUIComponents::getOptionsMenuButtons()  // retrieves the value of optionsMenuButtons
{
    return(optionsMenuButtons);
}
void GUIComponents::setOptionsMenuButtons(MyGUIButtonMSharedPtr set)  // sets the value of optionsMenuButtons
{
    optionsMenuButtons = set;
}

MyGUIButtonMSharedPtr GUIComponents::getDisplayMenuButtons()  // retrieves the value of displayMenuButtons
{
    return(displayMenuButtons);
}
void GUIComponents::setDisplayMenuButtons(MyGUIButtonMSharedPtr set)  // sets the value of displayMenuButtons
{
    displayMenuButtons = set;
}

MyGUIButtonMSharedPtr GUIComponents::getInputMenuButtons()  // retrieves the value of inputMenuButtons
{
    return(inputMenuButtons);
}
void GUIComponents::setInputMenuButtons(MyGUIButtonMSharedPtr set)  // sets the value of inputMenuButtons
{
    inputMenuButtons = set;
}

MyGUIButtonMSharedPtr GUIComponents::getAudioMenuButtons()  // retrieves the value of audioMenuButtons
{
    return(audioMenuButtons);
}
void GUIComponents::setAudioMenuButtons(MyGUIButtonMSharedPtr set)  // sets the value of audioMenuButtons
{
    audioMenuButtons = set;
}

MyGUIButtonMSharedPtr GUIComponents::getTeamSelectionMenuButtons()  // retrieves the value of teamSelectionMenuButtons
{
    return(teamSelectionMenuButtons);
}
void GUIComponents::setTeamSelectionMenuButtons(MyGUIButtonMSharedPtr set)  // sets the value of teamSelectionMenuButtons
{
    teamSelectionMenuButtons = set;
}

MyGUIButtonMSharedPtr GUIComponents::getPlayerStartSelectionMenuButtons()  // retrieves the value of playerStartSelectionMenuButtons
{
    return(playerStartSelectionMenuButtons);
}
void GUIComponents::setPlayerStartSelectionMenuButtons(MyGUIButtonMSharedPtr set)  // sets the value of playerStartSelectionMenuButtons
{
    playerStartSelectionMenuButtons = set;
}

MyGUIListBoxMSharedPtr GUIComponents::getTeamSelectBox()  // retrieves the value of teamSelectBox
{
    return(teamSelectBox);
}
void GUIComponents::setTeamSelectBox(MyGUIListBoxMSharedPtr set)  // sets the value of teamSelectBox
{
    teamSelectBox = set;
}

MyGUIListBoxSharedPtr GUIComponents::getNumClientsSelectBox()  // retrieves the value of numClientsSelectBox
{
    return(numClientsSelectBox);
}
void GUIComponents::setNumClientsSelectBox(MyGUIListBoxSharedPtr set)  // sets the value of numClientsSelectBox
{
    numClientsSelectBox = set;
}

sharedPtr<MyGUI::EditBox> GUIComponents::getServerIPAddressBox()  // retrieves the value of serverIPAddressBox
{
    return(serverIPAddressBox);
}
void GUIComponents::setServerIPAddressBox(sharedPtr<MyGUI::EditBox> set)  // sets the value of serverIPAddressBox
{
    serverIPAddressBox = set;
}

MyGUIButtonMSharedPtr GUIComponents::getNetworkServerSetupMenuButtons()  // retrieves the value of networkServerSetupMenuButtons
{
    return(networkServerSetupMenuButtons);
}
void GUIComponents::setNetworkServerSetupMenuButtons(MyGUIButtonMSharedPtr set)  // sets the value of networkServerSetupMenuButtons
{
    networkServerSetupMenuButtons = set;
}

sharedPtr<MyGUI::EditBox> GUIComponents::getClientIPAddressBox()  // retrieves the value of clientIPAddressBox
{
    return(clientIPAddressBox);
}
void GUIComponents::setClientIPAddressBox(sharedPtr<MyGUI::EditBox> set)  // sets the value of clientIPAddressBox
{
    clientIPAddressBox = set;
}

MyGUIButtonMSharedPtr GUIComponents::getNetworkClientSetupMenuButtons()  // retrieves the value of networkClientSetupMenuButtons
{
    return(networkClientSetupMenuButtons);
}
void GUIComponents::setNetworkClientSetupMenuButtons(MyGUIButtonMSharedPtr set)  // sets the value of networkClientSetupMenuButtons
{
    networkClientSetupMenuButtons = set;
}

MyGUIListBoxVecMSharedPtr GUIComponents::getTeamPlayerPosSelectBox()  // retrieves the value of teamPlayerPosSelectBox
{
    return(teamPlayerPosSelectBox);
}
void GUIComponents::setTeamPlayerPosSelectBox(MyGUIListBoxVecMSharedPtr set)  // sets the value of teamPlayerPosSelectBox
{
    teamPlayerPosSelectBox = set;
}

MyGUITextBoxVecMSharedPtr GUIComponents::getTeamPlayerRating()  // retrieves the value of teamPlayerRating
{
    return(teamPlayerRating);
}
void GUIComponents::setTeamPlayerRating(MyGUITextBoxVecMSharedPtr set)  // sets the value of teamPlayerRating
{
    teamPlayerRating = set;
}

MyGUIImageBoxMSharedPtr GUIComponents::getTeamLogo()  // retrieves the value of teamLogo
{
    return(teamLogo);
}
void GUIComponents::setTeamLogo(MyGUIImageBoxMSharedPtr set)  // sets the value of teamLogo
{
    teamLogo = set;
}

MyGUIButtonMSharedPtr GUIComponents::getCourtSelectionMenuButtons()  // retrieves the value of courtSelectionMenuButtons
{
    return(courtSelectionMenuButtons);
}
void GUIComponents::setCourtSelectionMenuButtons(MyGUIButtonMSharedPtr set)  // sets the value of courtSelectionMenuButtons
{
    courtSelectionMenuButtons = set;
}

MyGUIListBoxSharedPtr GUIComponents::getCourtSelectBox()  // retrieves the value of courtSelectBox
{
    return(courtSelectBox);
}
void GUIComponents::setCourtSelectBox(MyGUIListBoxSharedPtr set)  // sets the value of courtSelectBox
{
    courtSelectBox = set;
}

MyGUIImageBoxSharedPtr GUIComponents::getCourtPreviewImgBox()  // retrieves the value of courtPreviewImgBox
{
    return(courtPreviewImgBox);
}
void GUIComponents::setCourtPreviewImgBox(MyGUIImageBoxSharedPtr set)  // sets the value of courtPreviewImgBox
{
    courtPreviewImgBox = set;
}

MyGUITextBoxSharedPtr GUIComponents::getCourtNameTxtBox()  // retrieves the value of courtNameTxtBox
{
    return(courtNameTxtBox);
}
void GUIComponents::setCourtNameTxtBox(MyGUITextBoxSharedPtr set)  // sets the value of courtNameTxtBox  
{
    courtNameTxtBox = set;
}

void GUIComponents::startSingleGameButtonClicked(MyGUI::Widget *_sender)  // handles startSingleGameButton click event
{
//    startSinglePlayerGame(gameE->getRenderE());
}


bool GUIComponents::initMyGUI(renderEngineSharedPtr render)  // Initializes MyGUI
{
//    exit(0);
//    renderEngineSharedPtr render; // = renderEngine::Instance();
    std::string func = "GUIComponents::initMyGUI()";
    
    logMsg(func +" begin");
    logMsg(func +" *** Initializing MyGUI ***");
    MyGUIOgrePlatformSharedPtr tempPlatform(new MyGUI::OgrePlatform());
    mPlatform = tempPlatform;
    logMsg(func +" Crash?");

    mPlatform->initialise(render->getMWindow().get(), render->getMSceneMgr().get(), "UBCData"); // mWindow is Ogre::RenderWindow*, mSceneManager is Ogre::SceneManager*a@aa

    logMsg(func +" Crash??");
    MyGUIGuiSharedPtr tempGUI(new MyGUI::Gui());
//    exit(0);
    mGUI = tempGUI;
//    exit(0);
    logMsg(func +" Crash???");
    mGUI->initialise();
//    exit(0);
    logMsg(func +" *** MyGUI Initialized ***");
    logMsg(func +" end");
    return true;
}

