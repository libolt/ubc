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
    startSingleGameButton->setVisible(false);
    startMultiGameButton->setVisible(false);
    optionsButton->setVisible(false);
    exitButton->setVisible(false);
    startSingleGameButton->setStateSelected(false);
}
void GUISystem::showMainMenuWidgets()  // shows all widgets tied to the Main Menu
{
    logMsg("showMainMenuWidgets");
//    exit(0);
    startSingleGameButton->setVisible(true);
    startMultiGameButton->setVisible(true);
    optionsButton->setVisible(true);
    exitButton->setVisible(true);
    startSingleGameButton->setStateSelected(true);
    MyGUI::InputManager::getInstance().setKeyFocusWidget(startSingleGameButton.get());
    base->getGameE()->setMenuActive(true);
}
void GUISystem::hideNetworkSetupWidgets()  // hides the widgets tied to the Network Setup Menu
{
//  ipAddressBox->setVisible(false);
    serverButton->setVisible(false);
    clientButton->setVisible(false);
    backMainMenuButton->setVisible(false);
}
void GUISystem::showNetworkSetupWidgets()  // shows all widgets tied to the Network Setup Menu
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *getRenderE()->getViewPort() = render->getgetRenderE()->getViewPort()();

//    ipAddressBox->setVisible(true);
    serverButton->setVisible(true);
    clientButton->setVisible(true);

    backMainMenuButton->setVisible(true);
    backMainMenuButton->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.22 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()));

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
    serverHostButton->setVisible(false);
    backNetworkSetupButton->setVisible(false);
    
    
}
void GUISystem::showNetworkServerSetupWidgets()  // shows all widgets tied to the Network Server Setup Menu
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *getRenderE()->getViewPort() = render->getViewPort();

    numClientsSelectBox->setVisible(true);
    
    serverIPAddressBox->setVisible(true);
    serverIPAddressBox->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.10 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    serverHostButton->setVisible(true);
    serverHostButton->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.14 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    
    backNetworkSetupButton->setVisible(true);
    backNetworkSetupButton->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.18 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
}

void GUISystem::hideNetworkClientSetupWidgets()  // hides the widgets tied to the Network Setup Menu
{
    clientIPAddressBox->setVisible(false);
    clientConnectButton->setVisible(false);
    backNetworkSetupButton->setVisible(false);
}
void GUISystem::showNetworkClientSetupWidgets()  // shows all widgets tied to the Network Setup Menu
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *getRenderE()->getViewPort() = render->getViewPort();

    clientIPAddressBox->setVisible(true);
    clientIPAddressBox->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.10 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    clientConnectButton->setVisible(true);
    clientConnectButton->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.14 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    backNetworkSetupButton->setVisible(true);
    backNetworkSetupButton->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.18 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

}

void GUISystem::hideOptionsMenuWidgets()  // hides all widgets tied to the Options Menu
{
    displayButton->setVisible(false);
    inputButton->setVisible(false);
    audioButton->setVisible(false);
    backMainMenuButton->setVisible(false);
}
void GUISystem::showOptionsMenuWidgets()  // shows all widgets tied to the Options Menu
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *getRenderE()->getViewPort() = render->getViewPort();

    displayButton->setVisible(true);
    inputButton->setVisible(true);
    audioButton->setVisible(true);
    backMainMenuButton->setPosition(362, 275);
    backMainMenuButton->setVisible(true);

}

void GUISystem::hideDisplayMenuWidgets()  // hides all widgets tied to the Display Menu
{
    changeResolutionButton->setVisible(false);

}
void GUISystem::showDisplayMenuWidgets()  // shows all widgets tied to the Display Menu
{
    changeResolutionButton->setVisible(true);
}

void GUISystem::hideInputMenuWidgets()  // hides all widgets tied to the Input Menu
{
    changeInputTypeButton->setVisible(false);
}
void GUISystem::showInputMenuWidgets()  // shows all widgets tied to the Input Menu
{
    changeInputTypeButton->setVisible(true);
}

void GUISystem::hideAudioMenuWidgets()  // hides all widgets tied to the Audio Menu
{
    enableAudioButton->setVisible(false);
    disableAudioButton->setVisible(false);
}
void GUISystem::showAudioMenuWidgets()  // shows all widgets tied to the Main Menu
{
    enableAudioButton->setVisible(true);
    disableAudioButton->setVisible(true);
}

void GUISystem::hideGameSetupMenuWidgets()  // hides all widgets tied to the Game Setup Menu
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();

    teamSelectBox[0]->setVisible(false);
    teamSelectBox[1]->setVisible(false);
    team0SelectButton->setVisible(false);
    team1SelectButton->setVisible(false);
    teamsSelectedButton->setVisible(false);
    logMsg("previousActiveMenu = " +convert->toString(previousActiveMenu));

    if (previousActiveMenu == MAIN)
    {
        backMainMenuButton->setVisible(false);
    }
    else if (previousActiveMenu == NETWORKCLIENT)
    {
        backNetworkClientButton->setVisible(false);
    }
    else if (previousActiveMenu == NETWORK)
    {
        backNetworkSetupButton->setVisible(false);

    }
}
void GUISystem::showGameSetupMenuWidgets()  // shows all widgets tied to the Game Setup Menu
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *getRenderE()->getViewPort() = render->getViewPort();

    teamSelectBox[0]->setVisible(true);
    teamSelectBox[0]->setPosition((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.10 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamSelectBox[1]->setVisible(true);
    teamSelectBox[1]->setPosition((0.5*base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.10 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team0SelectButton->setVisible(true);
    team0SelectButton->setPosition((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.14 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team1SelectButton->setVisible(true);
    team1SelectButton->setPosition((0.5 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.14 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamsSelectedButton->setVisible(true);
    teamsSelectedButton->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.18 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    if (previousActiveMenu == MAIN)
    {
        backMainMenuButton->setVisible(true);
        backMainMenuButton->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.22 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

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
}

void GUISystem::hidePlayerStartSelectionMenuWidgets()  // hides all widgets tied to the Player Start Selection Menu
{

    // Team 0 widgets
    team0PGSelectBox->setVisible(false);
    team0SGSelectBox->setVisible(false);
    team0SFSelectBox->setVisible(false);
    team0PFSelectBox->setVisible(false);
    team0CSelectBox->setVisible(false);

    team0PGRating->setVisible(false);
    team0SGRating->setVisible(false);
    team0SFRating->setVisible(false);
    team0PFRating->setVisible(false);
    team0CRating->setVisible(false);

// FIXME! need to fix image loading
//    team0Logo->setVisible(false);

    team0StartingLineupSetButton->setVisible(false);

    // Team 1 widgets
    team1PGSelectBox->setVisible(false);
    team1SGSelectBox->setVisible(false);
    team1SFSelectBox->setVisible(false);
    team1PFSelectBox->setVisible(false);
    team1CSelectBox->setVisible(false);

    team1PGRating->setVisible(false);
    team1SGRating->setVisible(false);
    team1SFRating->setVisible(false);
    team1PFRating->setVisible(false);
    team1CRating->setVisible(false);

// FIXME! need to fix image loading
//    team1Logo->setVisible(false);

    team1StartingLineupSetButton->setVisible(false);

    startingLineupsSetButton->setVisible(false);
    backTeamSelectionMenuButton->setVisible(false);

}
void GUISystem::showPlayerStartSelectionMenuWidgets()  // shows all widgets tied to the Player Start Selection Menu
{

//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *getRenderE()->getViewPort() = render->getViewPort();

    // Team 0 widgets
    team0PGSelectBox->setVisible(true);
    team0PGSelectBox->setPosition((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.05 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team0SGSelectBox->setVisible(true);
    team0SGSelectBox->setPosition((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.09 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team0SFSelectBox->setVisible(true);
    team0SFSelectBox->setPosition((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.13 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team0PFSelectBox->setVisible(true);
    team0PFSelectBox->setPosition((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.17 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team0CSelectBox->setVisible(true);
    team0CSelectBox->setPosition((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team0PGRating->setVisible(true);
    team0PGRating->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.05 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    team0PGRating->setTextColour(MyGUI::Colour("Red"));
    team0PGRating->setCaption("99");

    team0SGRating->setVisible(true);
    team0SGRating->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team0SFRating->setVisible(true);
    team0SFRating->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team0PFRating->setVisible(true);
    team0PFRating->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team0CRating->setVisible(true);
    team0CRating->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );


// FIXME! needs image loaded to work
//    team0Logo->setVisible(true);

    team0StartingLineupSetButton->setVisible(true);
    team0StartingLineupSetButton->setPosition((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.31 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    // Team 1 widgets
    team1PGSelectBox->setVisible(true);
    team1PGSelectBox->setPosition((0.5 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.05 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team1SGSelectBox->setVisible(true);
    team1SGSelectBox->setPosition((0.5 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.09 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team1SFSelectBox->setVisible(true);
    team1SFSelectBox->setPosition((0.5 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.13 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team1PFSelectBox->setVisible(true);
    team1PFSelectBox->setPosition((0.5 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.17 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team1CSelectBox->setVisible(true);
    team1CSelectBox->setPosition((0.5 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team1PGRating->setVisible(true);
    team1PGRating->setPosition((0.8 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team1SGRating->setVisible(true);
    team1SGRating->setPosition((0.8 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team1SFRating->setVisible(true);
    team1SFRating->setPosition((0.8 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team1PFRating->setVisible(true);
    team1PFRating->setPosition((0.8 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team1CRating->setVisible(true);
    team1CRating->setPosition((0.8 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.21 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

// FIXME! needs image loaded to work
//    team1Logo->setVisible(true);

    team1StartingLineupSetButton->setVisible(true);
    team1StartingLineupSetButton->setPosition((0.5 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.31 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );


    startingLineupsSetButton->setVisible(true);
    startingLineupsSetButton->setPosition((0.25 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.38 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    backTeamSelectionMenuButton->setVisible(true);
    backTeamSelectionMenuButton->setPosition((0.25 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.43 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

}

void GUISystem::hideTeamSelectionMenuWidgets()  // hides all widgets tied to the Team Selection Menu
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();

    teamSelectBox[0]->setVisible(false);
    teamSelectBox[1]->setVisible(false);
    team0SelectButton->setVisible(false);
    team1SelectButton->setVisible(false);
    teamsSelectedButton->setVisible(false);
    logMsg("previousActiveMenu = " +convert->toString(previousActiveMenu));

    backCourtSelectionMenuButton->setVisible(false);
}

void GUISystem::showTeamSelectionMenuWidgets()  // show all widgets tied to the Team Selection Menu
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *getRenderE()->getViewPort() = render->getViewPort();
    logMsg("GUISystem::showTeamSelectionMenuWidgets");
//    logMsg("Blip");
//    exit(0);
    
    teamSelectBox[0]->setVisible(true);
    teamSelectBox[0]->setPosition((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.10 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
//    exit(0);
    teamSelectBox[1]->setVisible(true);
    teamSelectBox[1]->setPosition((0.5*base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.10 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team0SelectButton->setVisible(true);
    team0SelectButton->setPosition((0.1 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.19 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    team1SelectButton->setVisible(true);
    team1SelectButton->setPosition((0.5 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.19 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    teamsSelectedButton->setVisible(true);
    teamsSelectedButton->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.25 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    
    backCourtSelectionMenuButton->setVisible(true);
    backCourtSelectionMenuButton->setPosition((0.3 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.30 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

//    exit(0);
}

void GUISystem::hideCourtSelectionMenuWidgets()  // hides all widgets tied to the Court Selection Menu
{
    backMainMenuButton->setVisible(false);
    courtSelectBox->setVisible(false);
    courtNameTxtBox->setVisible(false);
    courtPreviewImgBox->setVisible(false);
    courtSelectButton->setVisible(false);
//    exit(0);
}
void GUISystem::showCourtSelectionMenuWidgets()  // show all widgets tied to the Court Selection Menu
{
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    Ogre::Viewport *getRenderE()->getViewPort() = render->getViewPort();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    
    displayCount += 1;
//    teamSelectionMenu();

    logMsg("court displayCount == " +convert->toString(displayCount));
    
    backMainMenuButton->setVisible(true);
    backMainMenuButton->setPosition((0.25 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.4 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

    courtSelectBox->setVisible(true);
    courtSelectBox->setPosition((0.25 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.31 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );
    
    courtNameTxtBox->setVisible(true);
    courtPreviewImgBox->setVisible(true);
    courtSelectButton->setVisible(true);
    courtSelectButton->setPosition((0.25 *base->getGameE()->getRenderE()->getViewPort()->getActualWidth() ), (0.36 *base->getGameE()->getRenderE()->getViewPort()->getActualHeight()) );

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
