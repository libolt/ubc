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

#include "ubcbase.h"
#include "gui/gui.h"
#include "conversion.h"
#include "data/courtdata.h"
#include "engine/gameengine.h"
#include "state/gamestate.h"
#include "load.h"
#include "logging.h"
#include "engine/renderengine.h"
#include "data/teamdata.h"

#ifdef __ANDROID__
#include "android-config.h"
#else
#include "config.h"
#endif

void GUISystem::hideMainMenuWidgets()  // hides the widgets tied to the Main Menu
{
    mainMenuButtons["startSingleGameButton"]->setVisible(false);
    mainMenuButtons["startMultiGameButton"]->setVisible(false);
    mainMenuButtons["optionsButton"]->setVisible(false);
    mainMenuButtons["exitButton"]->setVisible(false);
    mainMenuButtons["startSingleGameButton"]->setStateSelected(false);
}
void GUISystem::showMainMenuWidgets()  // shows all widgets tied to the Main Menu
{
    logMsg("showMainMenuWidgets");
//    exit(0);
    mainMenuButtons["startSingleGameButton"]->setVisible(true);
    mainMenuButtons["startMultiGameButton"]->setVisible(true);
    mainMenuButtons["optionsButton"]->setVisible(true);
    mainMenuButtons["exitButton"]->setVisible(true);
    mainMenuButtons["startSingleGameButton"]->setStateSelected(true);
    MyGUI::InputManager::getInstance().setKeyFocusWidget(mainMenuButtons["startSingleGameButton"].get());
    base->getGameE()->setMenuActive(true);
}
void GUISystem::hideNetworkSetupWidgets()  // hides the widgets tied to the Network Setup Menu
{
//  ipAddressBox->setVisible(false);
    networkMenuButtons["serverButton"]->setVisible(false);
    networkMenuButtons["clientButton"]->setVisible(false);
    networkMenuButtons["backMainMenuButton"]->setVisible(false);
}
void GUISystem::showNetworkSetupWidgets()  // shows all widgets tied to the Network Setup Menu
{
//    sharedPtr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *getRenderE()->getViewPort() = render->getgetRenderE()->getViewPort()();

//    ipAddressBox->setVisible(true);
    networkMenuButtons["serverButton"]->setVisible(true);
    networkMenuButtons["clientButton"]->setVisible(true);

    networkMenuButtons["backMainMenuButton"]->setVisible(true);
    networkMenuButtons["backMainMenuButton"]->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.22 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

}

void GUISystem::hideNetworkServerSetupWidgets()  // hides all widgets tied to the Network Server Setup Menu
{

    numClientsSelectBox->setVisible(false);
/*    team0Player1SelectBox->setVisible(false);
    team0Player2SelectBox->setVisible(false);
    team0Player3SelectBox->setVisible(false);
    team0Player4SelectBox->setVisible(false);
    team0Player5SelectBox->setVisible(false);
    team1Player1SelectBox->setVisible(false);
    team1Player2SelectBox->setVisible(false);
    team1Player3SelectBox->setVisible(false);
    team1Player4SelectBox->setVisible(false);
    team1Player5SelectBox->setVisible(false);
*/
    serverIPAddressBox->setVisible(false);
    networkServerSetupMenuButtons["serverHostButton"]->setVisible(false);
    networkServerSetupMenuButtons["backNetworkSetupButton"]->setVisible(false);
    
    
}
void GUISystem::showNetworkServerSetupWidgets()  // shows all widgets tied to the Network Server Setup Menu
{
//    sharedPtr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *getRenderE()->getViewPort() = render->getViewPort();

    numClientsSelectBox->setVisible(true);
    
    serverIPAddressBox->setVisible(true);
    serverIPAddressBox->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.10 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    networkServerSetupMenuButtons["serverHostButton"]->setVisible(true);
    networkServerSetupMenuButtons["serverHostButton"]->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.14 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    
    networkServerSetupMenuButtons["backNetworkSetupButton"]->setVisible(true);
    networkServerSetupMenuButtons["backNetworkSetupButton"]->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.18 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
}

void GUISystem::hideNetworkClientSetupWidgets()  // hides the widgets tied to the Network Setup Menu
{
    clientIPAddressBox->setVisible(false);
    networkClientSetupMenuButtons["clientConnectButton"]->setVisible(false);
    networkClientSetupMenuButtons["backNetworkSetupButton"]->setVisible(false);
}
void GUISystem::showNetworkClientSetupWidgets()  // shows all widgets tied to the Network Setup Menu
{
//    sharedPtr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *getRenderE()->getViewPort() = render->getViewPort();

    clientIPAddressBox->setVisible(true);
    clientIPAddressBox->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.10 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    networkClientSetupMenuButtons["clientConnectButton"]->setVisible(true);
    networkClientSetupMenuButtons["clientConnectButton"]->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.14 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    networkClientSetupMenuButtons["backNetworkSetupButton"]->setVisible(true);
    networkClientSetupMenuButtons["backNetworkSetupButton"]->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.18 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

}

void GUISystem::hideOptionsMenuWidgets()  // hides all widgets tied to the Options Menu
{
    optionsMenuButtons["displayButton"]->setVisible(false);
    optionsMenuButtons["inputButton"]->setVisible(false);
    optionsMenuButtons["audioButton"]->setVisible(false);
    optionsMenuButtons["backMainMenuButton"]->setVisible(false);
}
void GUISystem::showOptionsMenuWidgets()  // shows all widgets tied to the Options Menu
{
//    sharedPtr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *getRenderE()->getViewPort() = render->getViewPort();

    optionsMenuButtons["displayButton"]->setVisible(true);
    optionsMenuButtons["inputButton"]->setVisible(true);
    optionsMenuButtons["audioButton"]->setVisible(true);
    optionsMenuButtons["backMainMenuButton"]->setPosition(362, 275);
    optionsMenuButtons["backMainMenuButton"]->setVisible(true);

}

void GUISystem::hideDisplayMenuWidgets()  // hides all widgets tied to the Display Menu
{
    displayMenuButtons["changeResolutionButton"]->setVisible(false);
    displayMenuButtons["backOptionsMenuButton"]->setVisible(false);


}
void GUISystem::showDisplayMenuWidgets()  // shows all widgets tied to the Display Menu
{
    displayMenuButtons["changeResolutionButton"]->setVisible(true);
    displayMenuButtons["backOptionsMenuButton"]->setVisible(true);

}

void GUISystem::hideInputMenuWidgets()  // hides all widgets tied to the Input Menu
{
    inputMenuButtons["changeInputTypeButton"]->setVisible(false);
    inputMenuButtons["backOptionsMenuButton"]->setVisible(false);

}
void GUISystem::showInputMenuWidgets()  // shows all widgets tied to the Input Menu
{
    inputMenuButtons["changeInputTypeButton"]->setVisible(true);
    inputMenuButtons["backOptionsMenuButton"]->setVisible(true);

}

void GUISystem::hideAudioMenuWidgets()  // hides all widgets tied to the Audio Menu
{
    audioMenuButtons["enableAudioButton"]->setVisible(false);
    audioMenuButtons["disableAudioButton"]->setVisible(false);
    audioMenuButtons["backOptionsMenuButton"]->setVisible(false);

}
void GUISystem::showAudioMenuWidgets()  // shows all widgets tied to the Main Menu
{
    audioMenuButtons["enableAudioButton"]->setVisible(true);
    audioMenuButtons["disableAudioButton"]->setVisible(true);
    audioMenuButtons["backOptionsMenuButton"]->setVisible(false);

}

void GUISystem::hideGameSetupMenuWidgets()  // hides all widgets tied to the Game Setup Menu
{
    //conversion *convert = conversion::Instance();
    sharedPtr<conversion> convert = conversion::Instance();
/*
    teamSelectBox[0]->setVisible(false);
    teamSelectBox[1]->setVisible(false);
    teamSelectionMenuButtons["team0SelectButton"]->setVisible(false);
    teamSelectionMenuButtons["team1SelectButton"]->setVisible(false);
    teamSelectionMenuButtons["teamsSelectedButton"]->setVisible(false);
   
    logMsg("previousActiveMenu = " +convert->toString(previousActiveMenu));
    if (previousActiveMenu == MAIN)
    {
        teamSelectionMenuButtons["backMainMenuButton"]->setVisible(false);
    }
    else if (previousActiveMenu == NETWORKCLIENT)
    {
        backNetworkClientButton->setVisible(false);
    }
    else if (previousActiveMenu == NETWORK)
    {
        backNetworkSetupButton->setVisible(false);

    }
    */
}
void GUISystem::showGameSetupMenuWidgets()  // shows all widgets tied to the Game Setup Menu
{
//    sharedPtr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *getRenderE()->getViewPort() = render->getViewPort();
/*
    teamSelectBox[0]->setVisible(true);
    teamSelectBox[0]->setPosition((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.10 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamSelectBox[1]->setVisible(true);
    teamSelectBox[1]->setPosition((0.5*base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.10 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamSelectionMenuButtons["team0SelectButton"]->setVisible(true);
    teamSelectionMenuButtons["team0SelectButton"]->setPosition((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.14 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamSelectionMenuButtons["team1SelectButton"]->setVisible(true);
    teamSelectionMenuButtons["team1SelectButton"]->setPosition((0.5 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.14 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamSelectionMenuButtons["teamsSelectedButton"]->setVisible(true);
    teamSelectionMenuButtons["teamsSelectedButton"]->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.18 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    
    if (previousActiveMenu == MAIN)
    {
        teamSelectionMenuButtons["backMainMenuButton"]->setVisible(true);
        teamSelectionMenuButtons["backMainMenuButton"]->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.22 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    }
    else if (previousActiveMenu == NETWORKCLIENT)
    {
        backNetworkClientButton->setVisible(true);
        backNetworkClientButton->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.22 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    }
    else if (previousActiveMenu == NETWORK)
    {
        backNetworkSetupButton->setVisible(true);
        backNetworkSetupButton->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.22 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    }
    */
}

void GUISystem::hidePlayerStartSelectionMenuWidgets()  // hides all widgets tied to the Player Start Selection Menu
{

    // Team 0 widgets
    teamPlayerPosSelectBox[0]["PG"]->setVisible(false);
    teamPlayerPosSelectBox[0]["SG"]->setVisible(false);
    teamPlayerPosSelectBox[0]["SF"]->setVisible(false);
    teamPlayerPosSelectBox[0]["PF"]->setVisible(false);
    teamPlayerPosSelectBox[0]["C"]->setVisible(false);

    teamPlayerPosSelectBox[0]["PG"]->setVisible(false);
    teamPlayerPosSelectBox[0]["SG"]->setVisible(false);
    teamPlayerPosSelectBox[0]["SF"]->setVisible(false);
    teamPlayerPosSelectBox[0]["PF"]->setVisible(false);
    teamPlayerPosSelectBox[0]["C"]->setVisible(false);

// FIXME! need to fix image loading
//    team0Logo->setVisible(false);

    playerStartSelectionMenuButtons["team0StartingLineupSetButton"]->setVisible(false);

    // Team 1 widgets
    teamPlayerPosSelectBox[1]["PG"]->setVisible(false);
    teamPlayerPosSelectBox[1]["SG"]->setVisible(false);
    teamPlayerPosSelectBox[1]["SF"]->setVisible(false);
    teamPlayerPosSelectBox[1]["PF"]->setVisible(false);
    teamPlayerPosSelectBox[1]["C"]->setVisible(false);

    teamPlayerPosSelectBox[1]["PG"]->setVisible(false);
    teamPlayerPosSelectBox[1]["SG"]->setVisible(false);
    teamPlayerPosSelectBox[1]["SF"]->setVisible(false);
    teamPlayerPosSelectBox[1]["PF"]->setVisible(false);
    teamPlayerPosSelectBox[1]["C"]->setVisible(false);

// FIXME! need to fix image loading
//    team1Logo->setVisible(false);

    playerStartSelectionMenuButtons["team1StartingLineupSetButton"]->setVisible(false);

    playerStartSelectionMenuButtons["startingLineupsSetButton"]->setVisible(false);
    playerStartSelectionMenuButtons["backTeamSelectionMenuButton"]->setVisible(false);

//    backTeamSelectionMenuButton->setVisible(false);

}
void GUISystem::showPlayerStartSelectionMenuWidgets()  // shows all widgets tied to the Player Start Selection Menu
{

//    sharedPtr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *getRenderE()->getViewPort() = render->getViewPort();

    // Team 0 widgets
    teamPlayerPosSelectBox[0]["PG"]->setVisible(true);
    teamPlayerPosSelectBox[0]["PG"]->setPosition((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.05 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[0]["SG"]->setVisible(true);
    teamPlayerPosSelectBox[0]["SG"]->setPosition((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.09 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[0]["SF"]->setVisible(true);
    teamPlayerPosSelectBox[0]["SF"]->setPosition((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.13 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[0]["PF"]->setVisible(true);
    teamPlayerPosSelectBox[0]["PF"]->setPosition((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.17 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[0]["C"]->setVisible(true);
    teamPlayerPosSelectBox[0]["C"]->setPosition((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

/*    teamPlayerPosSelectBox[0]["PG"]->setVisible(true);
    teamPlayerPosSelectBox[0]["PG"]->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.05 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
//    teamPlayerPosSelectBox[0]["PG"]->setTextColour(MyGUI::Colour("Red"));
//    teamPlayerPosSelectBox[0]["PG"]->setCaption("99");

    teamPlayerPosSelectBox[0]["PG"]->setVisible(true);
    teamPlayerPosSelectBox[0]["PG"]->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[0]["PG"]->setVisible(true);
    teamPlayerPosSelectBox[0]["PG"]->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[0]["PG"]->setVisible(true);
    teamPlayerPosSelectBox[0]["PG"]->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[0]["PG"]->setVisible(true);
    teamPlayerPosSelectBox[0]["PG"]->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
*/

// FIXME! needs image loaded to work
//    team0Logo->setVisible(true);

    playerStartSelectionMenuButtons["team0StartingLineupSetButton"]->setVisible(true);
    playerStartSelectionMenuButtons["team0StartingLineupSetButton"]->setPosition((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.31 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    // Team 1 widgets
    teamPlayerPosSelectBox[1]["PG"]->setVisible(true);
    teamPlayerPosSelectBox[1]["PG"]->setPosition((0.5 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.05 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[1]["SG"]->setVisible(true);
    teamPlayerPosSelectBox[1]["SG"]->setPosition((0.5 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.09 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[1]["SF"]->setVisible(true);
    teamPlayerPosSelectBox[1]["SF"]->setPosition((0.5 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.13 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[1]["PF"]->setVisible(true);
    teamPlayerPosSelectBox[1]["PF"]->setPosition((0.5 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.17 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[1]["C"]->setVisible(true);
    teamPlayerPosSelectBox[1]["C"]->setPosition((0.5 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

/*    teamPlayerPosSelectBox[1]["PG"]->setVisible(true);
    teamPlayerPosSelectBox[1]["PG"]->setPosition((0.8 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[1]["SG"]->setVisible(true);
    teamPlayerPosSelectBox[1]["SG"]->setPosition((0.8 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[1]["SF"]->setVisible(true);
    teamPlayerPosSelectBox[1]["SF"]->setPosition((0.8 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[1]["PF"]->setVisible(true);
    teamPlayerPosSelectBox[1]["PF"]->setPosition((0.8 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[1]["C"]->setVisible(true);
    teamPlayerPosSelectBox[1]["C"]->setPosition((0.8 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
*/
// FIXME! needs image loaded to work
//    team1Logo->setVisible(true);

    playerStartSelectionMenuButtons["team1StartingLineupSetButton"]->setVisible(true);
    playerStartSelectionMenuButtons["team1StartingLineupSetButton"]->setPosition((0.5 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.31 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );


    playerStartSelectionMenuButtons["startingLineupsSetButton"]->setVisible(true);
    playerStartSelectionMenuButtons["startingLineupsSetButton"]->setPosition((0.25 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.38 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    playerStartSelectionMenuButtons["backTeamSelectionMenuButton"]->setVisible(true);
    playerStartSelectionMenuButtons["backTeamSelectionMenuButton"]->setPosition((0.25 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.43 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

}

void GUISystem::hideTeamSelectionMenuWidgets()  // hides all widgets tied to the Team Selection Menu
{
    //conversion *convert = conversion::Instance();
    sharedPtr<conversion> convert = conversion::Instance();

    teamSelectBox[0]->setVisible(false);
    teamSelectBox[1]->setVisible(false);
    teamSelectionMenuButtons["team0SelectButton"]->setVisible(false);
    teamSelectionMenuButtons["team1SelectButton"]->setVisible(false);
    teamSelectionMenuButtons["teamsSelectedButton"]->setVisible(false);
    teamSelectionMenuButtons["backMainMenuButton"]->setVisible(false);
    teamSelectionMenuButtons["backCourtSelectionMenuButton"]->setVisible(false);

    logMsg("previousActiveMenu = " +convert->toString(previousActiveMenu));

//    backCourtSelectionMenuButton->setVisible(false);
}

void GUISystem::showTeamSelectionMenuWidgets()  // show all widgets tied to the Team Selection Menu
{
//    sharedPtr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *getRenderE()->getViewPort() = render->getViewPort();
    logMsg("GUISystem::showTeamSelectionMenuWidgets");
//    logMsg("Blip");
//    exit(0);
    
    teamSelectBox[0]->setVisible(true);
    teamSelectBox[0]->setPosition((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.10 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
//    exit(0);
    teamSelectBox[1]->setVisible(true);
    teamSelectBox[1]->setPosition((0.5*base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.10 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamSelectionMenuButtons["team0SelectButton"]->setVisible(true);
    teamSelectionMenuButtons["team0SelectButton"]->setPosition((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.19 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamSelectionMenuButtons["team1SelectButton"]->setVisible(true);
    teamSelectionMenuButtons["team1SelectButton"]->setPosition((0.5 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.19 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamSelectionMenuButtons["teamsSelectedButton"]->setVisible(true);
    teamSelectionMenuButtons["teamsSelectedButton"]->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.25 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    
    teamSelectionMenuButtons["backCourtSelectionMenuButton"]->setVisible(true);
    teamSelectionMenuButtons["backCourtSelectionMenuButton"]->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.30 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

//    exit(0);
}

void GUISystem::hideCourtSelectionMenuWidgets()  // hides all widgets tied to the Court Selection Menu
{
    courtSelectionMenuButtons["backMainMenuButton"]->setVisible(false);
    courtSelectBox->setVisible(false);
    courtNameTxtBox->setVisible(false);
    courtPreviewImgBox->setVisible(false);
    courtSelectionMenuButtons["courtSelectButton"]->setVisible(false);
//    exit(0);
}
void GUISystem::showCourtSelectionMenuWidgets()  // show all widgets tied to the Court Selection Menu
{
//    sharedPtr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *getRenderE()->getViewPort() = render->getViewPort();
    sharedPtr<conversion> convert = conversion::Instance();
    
    displayCount += 1;
//    teamSelectionMenu();

    logMsg("court displayCount == " +convert->toString(displayCount));
    
    courtSelectionMenuButtons["backMainMenuButton"]->setVisible(true);
    courtSelectionMenuButtons["backMainMenuButton"]->setPosition((0.25 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
//    exit(0);
    courtSelectBox->setVisible(true);
    courtSelectBox->setPosition((0.25 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.31 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    
    courtNameTxtBox->setVisible(true);
    courtPreviewImgBox->setVisible(true);
    courtSelectionMenuButtons["courtSelectButton"]->setVisible(true);
    courtSelectionMenuButtons["courtSelectButton"]->setPosition((0.25 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.36 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

}

void GUISystem::hideActiveMenuWidgets()  // hides active menus widgets
{
    switch (activeMenu)
    {
        case MAIN: 
            hideMainMenuWidgets();
            break;
        case NETWORK:
            hideNetworkSetupWidgets();
            break;
        case NETWORKCLIENT:
            hideNetworkClientSetupWidgets();
            break;
            case NETWORKSERVER:
            hideNetworkServerSetupWidgets();
            break;
        case OPTIONS:
            hideOptionsMenuWidgets();
            break;
        case DISPLAY:
            hideDisplayMenuWidgets();
            break;
        case INPUTMENU:
            hideInputMenuWidgets();
            break;
        case AUDIO:
            hideAudioMenuWidgets();
            break;
        case GAMESETUP:
            hideGameSetupMenuWidgets();
            break;
        case PLAYERSTART:
            hidePlayerStartSelectionMenuWidgets();
            break;
        case TEAMSELECT:
            hideTeamSelectionMenuWidgets();
            break;
        case COURTSELECT:
//            exit(0);
            hideCourtSelectionMenuWidgets();
            
            break;
        default:
            break;
    }
}

void GUISystem::showActiveMenuWidgets()  // shows active menus widgets
{
//    exit(0);
    switch (activeMenu)
    {
        case MAIN:
            showMainMenuWidgets();
            break;
        case NETWORK:
            showNetworkSetupWidgets();
            break;
        case NETWORKCLIENT:
            showNetworkClientSetupWidgets();
            break;
        case NETWORKSERVER:
            showNetworkServerSetupWidgets();
            break;
        case OPTIONS:
            showOptionsMenuWidgets();
            break;
        case DISPLAY:
            showDisplayMenuWidgets();
            break;
        case INPUTMENU:
            showInputMenuWidgets();
            break;
        case AUDIO:
            showAudioMenuWidgets();
            break;
        case GAMESETUP:
            showGameSetupMenuWidgets();
            break;
        case PLAYERSTART:
            showPlayerStartSelectionMenuWidgets();
            break;
        case TEAMSELECT:
            logMsg("TEAMSELECT");
//            exit(0);
            showTeamSelectionMenuWidgets();
            break;
        case COURTSELECT:
            showCourtSelectionMenuWidgets();
            break;
        default:
            break;
    }
}

void GUISystem::changeActiveMenu(activeMenus menu)  // changes the actively displayed menu
{
//    exit(0);
    hideActiveMenuWidgets();
    menuActive = true;
    base->getGameE()->setMenuActive(true);
    previousActiveMenu = activeMenu;
    activeMenu = menu;
    showActiveMenuWidgets();
}
