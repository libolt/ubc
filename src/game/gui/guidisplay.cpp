/***************************************************************************
 *   Copyright (C) 1999 - 2019 by Mike McLean                              *
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

#include "gui/guidisplay.h"
#include "gui/gui.h"
#include "utilities/conversion.h"
#include "components/guicomponents.h"
#include "data/courtdata.h"
#include "engine/gameengine.h"
#include "entity/gameentity.h"
#include "load/load.h"
#include "utilities/logging.h"
#include "engine/renderengine.h"
#include "data/teamdata.h"

#ifdef __ANDROID__
#include "utilities/android-config.h"
#else
#include "config.h"
#endif

guiDisplay::guiDisplay()  // constructor
{
    displayCount = 0;

}
guiDisplay::~guiDisplay() = default;  // destructor

guiComponentsSharedPtr guiDisplay::getComponent() const  // retrieves the value of component
{
    return (component);
}
void guiDisplay::setComponent(const guiComponentsSharedPtr &set)  // sets the value of component
{
    component = set;
}

guiFlagsSharedPtr guiDisplay::getFlag() const  // retrieves the value of flag
{
    return (flag);
}
void guiDisplay::setFlag(const guiFlagsSharedPtr &set)  // sets the value of flag
{
    flag = set;
}

gameEngineSharedPtr guiDisplay::getGamE() const  // retrieves the value of gameE
{
    return (gameE);
}
void guiDisplay::setGameE(const gameEngineSharedPtr &set)  // sets the value of gameE
{
    gameE = set;
}

void guiDisplay::hideMainMenuWidgets()  // hides the widgets tied to the Main Menu
{
    std::string func = "guiDisplay::hideMainMenuWidgets()";
    
    logMsg(func +" begin");
    
    component->getMainMenuButtons()["startSingleGameButton"]->setVisible(false);
    component->getMainMenuButtons()["startMultiGameButton"]->setVisible(false);
    component->getMainMenuButtons()["optionsButton"]->setVisible(false);
    component->getMainMenuButtons()["exitButton"]->setVisible(false);
    component->getMainMenuButtons()["startSingleGameButton"]->setStateSelected(false);
    logMsg(func +" end");
    
}
void guiDisplay::showMainMenuWidgets()  // shows all widgets tied to the Main Menu
{
    conversionSharedPtr convert;
    std::string func = "guiDisplay::showMainMenuWidgets()";
    MyGUIButtonMSharedPtr tempButtons = component->getMainMenuButtons();

    logMsg(func +" begin");
    logMsg(func + " component initialized == " +convert->toString(component->getInitialized()));
    logMsg("tempButtons size == " +convert->toString(tempButtons.size()));
    tempButtons["startSingleGameButton"]->setVisible(true);
    component->getMainMenuButtons()["startSingleGameButton"]->setVisible(true);
    logMsg(func +" startSingleGameButton");
    component->getMainMenuButtons()["startMultiGameButton"]->setVisible(true);
    component->getMainMenuButtons()["optionsButton"]->setVisible(true);
    component->getMainMenuButtons()["exitButton"]->setVisible(true);
    component->getMainMenuButtons()["startSingleGameButton"]->setStateSelected(true);
    MyGUI::InputManager::getInstance().setKeyFocusWidget(component->getMainMenuButtons()["startSingleGameButton"].get());
    logMsg(func +"gameE->setMenuActive(true)");
    gameE->setMenuActive(true);
    logMsg(func +" end");
}
void guiDisplay::hideNetworkSetupWidgets()  // hides the widgets tied to the Network Setup Menu
{
//  ipAddressBox->setVisible(false);
    component->getNetworkMenuButtons()["serverButton"]->setVisible(false);
    component->getNetworkMenuButtons()["clientButton"]->setVisible(false);
    component->getNetworkMenuButtons()["backMainMenuButton"]->setVisible(false);
}
void guiDisplay::showNetworkSetupWidgets()  // shows all widgets tied to the Network Setup Menu
{
    renderEngineSharedPtr render;  // = renderEngine::Instance();
//    Ogre::Viewport *getRenderE()->getViewPort() = render->getgetRenderE()->getViewPort()();

//    ipAddressBox->setVisible(true);
    component->getNetworkMenuButtons()["serverButton"]->setVisible(true);
    component->getNetworkMenuButtons()["clientButton"]->setVisible(true);

    component->getNetworkMenuButtons()["backMainMenuButton"]->setVisible(true);
    component->getNetworkMenuButtons()["backMainMenuButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.22 *render->getViewPort()->getActualHeight()));

}

void guiDisplay::hideNetworkServerSetupWidgets()  // hides all widgets tied to the Network Server Setup Menu
{

    component->getNumClientsSelectBox()->setVisible(false);
    component->getServerIPAddressBox()->setVisible(false);
    component->getNetworkServerSetupMenuButtons()["serverHostButton"]->setVisible(false);
    component->getNetworkServerSetupMenuButtons()["backNetworkSetupButton"]->setVisible(false);
    
    
}
void guiDisplay::showNetworkServerSetupWidgets()  // shows all widgets tied to the Network Server Setup Menu
{
    renderEngineSharedPtr render; // = renderEngine::Instance();
//    Ogre::Viewport *getRenderE()->getViewPort() = render->getViewPort();

    component->getNumClientsSelectBox()->setVisible(true);
    
    component->getServerIPAddressBox()->setVisible(true);
   component->getServerIPAddressBox()->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.10 *render->getViewPort()->getActualHeight()) );

    component->getNetworkServerSetupMenuButtons()["serverHostButton"]->setVisible(true);
    component->getNetworkServerSetupMenuButtons()["serverHostButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.14 *render->getViewPort()->getActualHeight()) );
    
    component->getNetworkServerSetupMenuButtons()["backNetworkSetupButton"]->setVisible(true);
    component->getNetworkServerSetupMenuButtons()["backNetworkSetupButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.18 *render->getViewPort()->getActualHeight()) );
}

void guiDisplay::hideNetworkClientSetupWidgets()  // hides the widgets tied to the Network Setup Menu
{
    component->getClientIPAddressBox()->setVisible(false);
    component->getNetworkClientSetupMenuButtons()["clientConnectButton"]->setVisible(false);
    component->getNetworkClientSetupMenuButtons()["backNetworkSetupButton"]->setVisible(false);
}
void guiDisplay::showNetworkClientSetupWidgets()  // shows all widgets tied to the Network Setup Menu
{
    renderEngineSharedPtr render; // = renderEngine::Instance();

//    Ogre::Viewport *getRenderE()->getViewPort() = render->getViewPort();

    component->getClientIPAddressBox()->setVisible(true);
    component->getClientIPAddressBox()->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.10 *render->getViewPort()->getActualHeight()) );

    component->getNetworkClientSetupMenuButtons()["clientConnectButton"]->setVisible(true);
    component->getNetworkClientSetupMenuButtons()["clientConnectButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.14 *render->getViewPort()->getActualHeight()) );

    component->getNetworkClientSetupMenuButtons()["backNetworkSetupButton"]->setVisible(true);
    component->getNetworkClientSetupMenuButtons()["backNetworkSetupButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.18 *render->getViewPort()->getActualHeight()) );

}

void guiDisplay::hideOptionsMenuWidgets()  // hides all widgets tied to the Options Menu
{
    component->getOptionsMenuButtons()["displayButton"]->setVisible(false);
    component->getOptionsMenuButtons()["inputButton"]->setVisible(false);
    component->getOptionsMenuButtons()["audioButton"]->setVisible(false);
    component->getOptionsMenuButtons()["backMainMenuButton"]->setVisible(false);
}
void guiDisplay::showOptionsMenuWidgets()  // shows all widgets tied to the Options Menu
{
    renderEngineSharedPtr render; // = renderEngine::Instance();

//    Ogre::Viewport *getRenderE()->getViewPort() = render->getViewPort();

    component->getOptionsMenuButtons()["displayButton"]->setVisible(true);
    component->getOptionsMenuButtons()["inputButton"]->setVisible(true);
    component->getOptionsMenuButtons()["audioButton"]->setVisible(true);
    component->getOptionsMenuButtons()["backMainMenuButton"]->setPosition(362, 275);
    component->getOptionsMenuButtons()["backMainMenuButton"]->setVisible(true);

}

void guiDisplay::hideDisplayMenuWidgets()  // hides all widgets tied to the Display Menu
{
    component->getDisplayMenuButtons()["changeResolutionButton"]->setVisible(false);
    component->getDisplayMenuButtons()["backOptionsMenuButton"]->setVisible(false);


}
void guiDisplay::showDisplayMenuWidgets()  // shows all widgets tied to the Display Menu
{
    component->getDisplayMenuButtons()["changeResolutionButton"]->setVisible(true);
    component->getDisplayMenuButtons()["backOptionsMenuButton"]->setVisible(true);

}

void guiDisplay::hideInputMenuWidgets()  // hides all widgets tied to the Input Menu
{
    component->getInputMenuButtons()["changeInputTypeButton"]->setVisible(false);
    component->getInputMenuButtons()["backOptionsMenuButton"]->setVisible(false);

}
void guiDisplay::showInputMenuWidgets()  // shows all widgets tied to the Input Menu
{
    component->getInputMenuButtons()["changeInputTypeButton"]->setVisible(true);
    component->getInputMenuButtons()["backOptionsMenuButton"]->setVisible(true);

}

void guiDisplay::hideAudioMenuWidgets()  // hides all widgets tied to the Audio Menu
{
    component->getAudioMenuButtons()["enableAudioButton"]->setVisible(false);
    component->getAudioMenuButtons()["disableAudioButton"]->setVisible(false);
    component->getAudioMenuButtons()["backOptionsMenuButton"]->setVisible(false);

}
void guiDisplay::showAudioMenuWidgets()  // shows all widgets tied to the Main Menu
{
    component->getAudioMenuButtons()["enableAudioButton"]->setVisible(true);
    component->getAudioMenuButtons()["disableAudioButton"]->setVisible(true);
    component->getAudioMenuButtons()["backOptionsMenuButton"]->setVisible(false);

}

void guiDisplay::hideSetupMenuWidgets()  // hides all widgets tied to the Game Setup Menu
{
    //conversion *convert = conversion::Instance();
    conversionSharedPtr convert ;
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
void guiDisplay::showSetupMenuWidgets()  // shows all widgets tied to the Game Setup Menu
{
    renderEngineSharedPtr render; // = renderEngine::Instance();

//    Ogre::Viewport *getRenderE()->getViewPort() = render->getViewPort();
/*
    teamSelectBox[0]->setVisible(true);
    teamSelectBox[0]->setPosition((0.1 *render->getViewPort()->getActualWidth() ), (0.10 *render->getViewPort()->getActualHeight()) );

    teamSelectBox[1]->setVisible(true);
    teamSelectBox[1]->setPosition((0.5*render->getViewPort()->getActualWidth() ), (0.10 *render->getViewPort()->getActualHeight()) );

    teamSelectionMenuButtons["team0SelectButton"]->setVisible(true);
    teamSelectionMenuButtons["team0SelectButton"]->setPosition((0.1 *render->getViewPort()->getActualWidth() ), (0.14 *render->getViewPort()->getActualHeight()) );

    teamSelectionMenuButtons["team1SelectButton"]->setVisible(true);
    teamSelectionMenuButtons["team1SelectButton"]->setPosition((0.5 *render->getViewPort()->getActualWidth() ), (0.14 *render->getViewPort()->getActualHeight()) );

    teamSelectionMenuButtons["teamsSelectedButton"]->setVisible(true);
    teamSelectionMenuButtons["teamsSelectedButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.18 *render->getViewPort()->getActualHeight()) );
    
    if (previousActiveMenu == MAIN)
    {
        teamSelectionMenuButtons["backMainMenuButton"]->setVisible(true);
        teamSelectionMenuButtons["backMainMenuButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.22 *render->getViewPort()->getActualHeight()) );

    }
    else if (previousActiveMenu == NETWORKCLIENT)
    {
        backNetworkClientButton->setVisible(true);
        backNetworkClientButton->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.22 *render->getViewPort()->getActualHeight()) );
    }
    else if (previousActiveMenu == NETWORK)
    {
        backNetworkSetupButton->setVisible(true);
        backNetworkSetupButton->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.22 *render->getViewPort()->getActualHeight()) );
    }
    */
}

void guiDisplay::hidePlayerStartSelectionMenuWidgets()  // hides all widgets tied to the Player Start Selection Menu
{

    // Team 0 widgets
    component->getTeamPlayerPosSelectBox()[0][PG]->setVisible(false);
    component->getTeamPlayerPosSelectBox()[0][SG]->setVisible(false);
    component->getTeamPlayerPosSelectBox()[0][SF]->setVisible(false);
    component->getTeamPlayerPosSelectBox()[0][PF]->setVisible(false);
    component->getTeamPlayerPosSelectBox()[0][C]->setVisible(false);

    component->getTeamPlayerPosSelectBox()[0][PG]->setVisible(false);
    component->getTeamPlayerPosSelectBox()[0][SG]->setVisible(false);
    component->getTeamPlayerPosSelectBox()[0][SF]->setVisible(false);
    component->getTeamPlayerPosSelectBox()[0][PF]->setVisible(false);
    component->getTeamPlayerPosSelectBox()[0][C]->setVisible(false);

// FIXME! need to fix image loading
//    team0Logo->setVisible(false);

    component->getPlayerStartSelectionMenuButtons()["team0StartingLineupSetButton"]->setVisible(false);

    // Team 1 widgets
    component->getTeamPlayerPosSelectBox()[1][PG]->setVisible(false);
    component->getTeamPlayerPosSelectBox()[1][SG]->setVisible(false);
    component->getTeamPlayerPosSelectBox()[1][SF]->setVisible(false);
    component->getTeamPlayerPosSelectBox()[1][PF]->setVisible(false);
    component->getTeamPlayerPosSelectBox()[1][C]->setVisible(false);

    component->getTeamPlayerPosSelectBox()[1][PG]->setVisible(false);
    component->getTeamPlayerPosSelectBox()[1][SG]->setVisible(false);
    component->getTeamPlayerPosSelectBox()[1][SF]->setVisible(false);
    component->getTeamPlayerPosSelectBox()[1][PF]->setVisible(false);
    component->getTeamPlayerPosSelectBox()[1][C]->setVisible(false);

// FIXME! need to fix image loading
//    team1Logo->setVisible(false);

    component->getPlayerStartSelectionMenuButtons()["team1StartingLineupSetButton"]->setVisible(false);

    component->getPlayerStartSelectionMenuButtons()["startingLineupsSetButton"]->setVisible(false);
    component->getPlayerStartSelectionMenuButtons()["backTeamSelectionMenuButton"]->setVisible(false);

//    backTeamSelectionMenuButton->setVisible(false);

}

void guiDisplay::showPlayerStartSelectionMenuWidgets(const renderEngineSharedPtr &render)  // shows all widgets tied to the Player Start Selection Menu
{

//    renderEngineSharedPtr render; // = renderEngine::Instance();

//    Ogre::Viewport *getRenderE()->getViewPort() = render->getViewPort();

    // Team 0 widgets
    component->getTeamPlayerPosSelectBox()[0][PG]->setVisible(true);
    component->getTeamPlayerPosSelectBox()[0][PG]->setPosition((0.1 *render->getViewPort()->getActualWidth() ), (0.05 *render->getViewPort()->getActualHeight()) );

    component->getTeamPlayerPosSelectBox()[0][SG]->setVisible(true);
    component->getTeamPlayerPosSelectBox()[0][SG]->setPosition((0.1 *render->getViewPort()->getActualWidth() ), (0.09 *render->getViewPort()->getActualHeight()) );

    component->getTeamPlayerPosSelectBox()[0][SF]->setVisible(true);
    component->getTeamPlayerPosSelectBox()[0][SF]->setPosition((0.1 *render->getViewPort()->getActualWidth() ), (0.13 *render->getViewPort()->getActualHeight()) );

    component->getTeamPlayerPosSelectBox()[0][PF]->setVisible(true);
    component->getTeamPlayerPosSelectBox()[0][PF]->setPosition((0.1 *render->getViewPort()->getActualWidth() ), (0.17 *render->getViewPort()->getActualHeight()) );

    component->getTeamPlayerPosSelectBox()[0][C]->setVisible(true);
    component->getTeamPlayerPosSelectBox()[0][C]->setPosition((0.1 *render->getViewPort()->getActualWidth() ), (0.21 *render->getViewPort()->getActualHeight()) );

/*    teamPlayerPosSelectBox[0]["PG"]->setVisible(true);
    teamPlayerPosSelectBox[0]["PG"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.05 *render->getViewPort()->getActualHeight()) );
//    teamPlayerPosSelectBox[0]["PG"]->setTextColour(MyGUI::Colour("Red"));
//    teamPlayerPosSelectBox[0]["PG"]->setCaption("99");

    teamPlayerPosSelectBox[0]["PG"]->setVisible(true);
    teamPlayerPosSelectBox[0]["PG"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.21 *render->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[0]["PG"]->setVisible(true);
    teamPlayerPosSelectBox[0]["PG"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.21 *render->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[0]["PG"]->setVisible(true);
    teamPlayerPosSelectBox[0]["PG"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.21 *render->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[0]["PG"]->setVisible(true);
    teamPlayerPosSelectBox[0]["PG"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.21 *render->getViewPort()->getActualHeight()) );
*/

// FIXME! needs image loaded to work
//    team0Logo->setVisible(true);

    component->getPlayerStartSelectionMenuButtons()["team0StartingLineupSetButton"]->setVisible(true);
    component->getPlayerStartSelectionMenuButtons()["team0StartingLineupSetButton"]->setPosition((0.1 *render->getViewPort()->getActualWidth() ), (0.31 *render->getViewPort()->getActualHeight()) );

    // Team 1 widgets
    component->getTeamPlayerPosSelectBox()[1][PG]->setVisible(true);
    component->getTeamPlayerPosSelectBox()[1][PG]->setPosition((0.5 *render->getViewPort()->getActualWidth() ), (0.05 *render->getViewPort()->getActualHeight()) );

    component->getTeamPlayerPosSelectBox()[1][SG]->setVisible(true);
    component->getTeamPlayerPosSelectBox()[1][SG]->setPosition((0.5 *render->getViewPort()->getActualWidth() ), (0.09 *render->getViewPort()->getActualHeight()) );

    component->getTeamPlayerPosSelectBox()[1][SF]->setVisible(true);
    component->getTeamPlayerPosSelectBox()[1][SF]->setPosition((0.5 *render->getViewPort()->getActualWidth() ), (0.13 *render->getViewPort()->getActualHeight()) );

    component->getTeamPlayerPosSelectBox()[1][PF]->setVisible(true);
    component->getTeamPlayerPosSelectBox()[1][PF]->setPosition((0.5 *render->getViewPort()->getActualWidth() ), (0.17 *render->getViewPort()->getActualHeight()) );

    component->getTeamPlayerPosSelectBox()[1][C]->setVisible(true);
    component->getTeamPlayerPosSelectBox()[1][C]->setPosition((0.5 *render->getViewPort()->getActualWidth() ), (0.21 *render->getViewPort()->getActualHeight()) );

/*    teamPlayerPosSelectBox[1]["PG"]->setVisible(true);
    teamPlayerPosSelectBox[1]["PG"]->setPosition((0.8 *render->getViewPort()->getActualWidth() ), (0.21 *render->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[1]["SG"]->setVisible(true);
    teamPlayerPosSelectBox[1]["SG"]->setPosition((0.8 *render->getViewPort()->getActualWidth() ), (0.21 *render->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[1]["SF"]->setVisible(true);
    teamPlayerPosSelectBox[1]["SF"]->setPosition((0.8 *render->getViewPort()->getActualWidth() ), (0.21 *render->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[1]["PF"]->setVisible(true);
    teamPlayerPosSelectBox[1]["PF"]->setPosition((0.8 *render->getViewPort()->getActualWidth() ), (0.21 *render->getViewPort()->getActualHeight()) );

    teamPlayerPosSelectBox[1]["C"]->setVisible(true);
    teamPlayerPosSelectBox[1]["C"]->setPosition((0.8 *render->getViewPort()->getActualWidth() ), (0.21 *render->getViewPort()->getActualHeight()) );
*/
// FIXME! needs image loaded to work
//    team1Logo->setVisible(true);

    component->getPlayerStartSelectionMenuButtons()["team1StartingLineupSetButton"]->setVisible(true);
    component->getPlayerStartSelectionMenuButtons()["team1StartingLineupSetButton"]->setPosition((0.5 *render->getViewPort()->getActualWidth() ), (0.31 *render->getViewPort()->getActualHeight()) );


    component->getPlayerStartSelectionMenuButtons()["startingLineupsSetButton"]->setVisible(true);
    component->getPlayerStartSelectionMenuButtons()["startingLineupsSetButton"]->setPosition((0.25 *render->getViewPort()->getActualWidth() ), (0.38 *render->getViewPort()->getActualHeight()) );

    component->getPlayerStartSelectionMenuButtons()["backTeamSelectionMenuButton"]->setVisible(true);
    component->getPlayerStartSelectionMenuButtons()["backTeamSelectionMenuButton"]->setPosition((0.25 *render->getViewPort()->getActualWidth() ), (0.43 *render->getViewPort()->getActualHeight()) );

}

void guiDisplay::hideTeamSelectionMenuWidgets()  // hides all widgets tied to the Team Selection Menu
{
    //conversion *convert = conversion::Instance();
    conversionSharedPtr convert ;

    component->getTeamSelectBox()[0]->setVisible(false);
    component->getTeamSelectBox()[1]->setVisible(false);
    component->getTeamSelectionMenuButtons()["team0SelectButton"]->setVisible(false);
    component->getTeamSelectionMenuButtons()["team1SelectButton"]->setVisible(false);
    component->getTeamSelectionMenuButtons()["teamsSelectedButton"]->setVisible(false);
    component->getTeamSelectionMenuButtons()["backMainMenuButton"]->setVisible(false);
    component->getTeamSelectionMenuButtons()["backCourtSelectionMenuButton"]->setVisible(false);

    logMsg("previousActiveMenu = " +convert->toString(component->getPreviousActiveMenu()));

//    backCourtSelectionMenuButton->setVisible(false);
}

void guiDisplay::showTeamSelectionMenuWidgets(const renderEngineSharedPtr &render)  // show all widgets tied to the Team Selection Menu
{
//    renderEngineSharedPtr render; // = renderEngine::Instance();

    std::string func = "guiDisplay::showTeamSelectionMenuWidgets()";

    logMsg(func +" begin");

    component->getTeamSelectBox()[0]->setVisible(true);
    component->getTeamSelectBox()[0]->setPosition((0.1 *render->getViewPort()->getActualWidth() ), (0.10 *render->getViewPort()->getActualHeight()) );
//    exit(0);
    component->getTeamSelectBox()[1]->setVisible(true);
    component->getTeamSelectBox()[1]->setPosition((0.5*render->getViewPort()->getActualWidth() ), (0.10 *render->getViewPort()->getActualHeight()) );

    component->getTeamSelectionMenuButtons()["team0SelectButton"]->setVisible(true);
    component->getTeamSelectionMenuButtons()["team0SelectButton"]->setPosition((0.1 *render->getViewPort()->getActualWidth() ), (0.19 *render->getViewPort()->getActualHeight()) );

    component->getTeamSelectionMenuButtons()["team1SelectButton"]->setVisible(true);
    component->getTeamSelectionMenuButtons()["team1SelectButton"]->setPosition((0.5 *render->getViewPort()->getActualWidth() ), (0.19 *render->getViewPort()->getActualHeight()) );

    component->getTeamSelectionMenuButtons()["teamsSelectedButton"]->setVisible(true);
    component->getTeamSelectionMenuButtons()["teamsSelectedButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.25 *render->getViewPort()->getActualHeight()) );
    
    component->getTeamSelectionMenuButtons()["backCourtSelectionMenuButton"]->setVisible(true);
    component->getTeamSelectionMenuButtons()["backCourtSelectionMenuButton"]->setPosition((0.3 *render->getViewPort()->getActualWidth() ), (0.30 *render->getViewPort()->getActualHeight()) );

    logMsg(func +" end");
//    exit(0);
}

void guiDisplay::hideCourtSelectionMenuWidgets()  // hides all widgets tied to the Court Selection Menu
{
    component->getCourtSelectionMenuButtons()["backMainMenuButton"]->setVisible(false);
    component->getCourtSelectBox()->setVisible(false);
    component->getCourtNameTxtBox()->setVisible(false);
    component->getCourtPreviewImgBox()->setVisible(false);
    component->getCourtSelectionMenuButtons()["courtSelectButton"]->setVisible(false);
//    exit(0);
}
void guiDisplay::showCourtSelectionMenuWidgets(const renderEngineSharedPtr &render)  // show all widgets tied to the Court Selection Menu
{
//    renderEngineSharedPtr render; // = renderEngine::Instance();
    conversionSharedPtr convert ;
    std::string func = "guiDisplay::showCourtSelectionMenuWidgets()";
    displayCount += 1;
//    teamSelectionMenu();

    logMsg(func +" begin");

    logMsg(func +" court displayCount == " +convert->toString(displayCount));
    
    component->getCourtSelectionMenuButtons()["backMainMenuButton"]->setVisible(true);
    component->getCourtSelectionMenuButtons()["backMainMenuButton"]->setPosition((0.25 *render->getViewPort()->getActualWidth() ), (0.4 *render->getViewPort()->getActualHeight()) );
//    exit(0);
    component->getCourtSelectBox()->setVisible(true);
    component->getCourtSelectBox()->setPosition((0.25 *render->getViewPort()->getActualWidth() ), (0.31 *render->getViewPort()->getActualHeight()) );
    
    component->getCourtNameTxtBox()->setVisible(true);
    component->getCourtPreviewImgBox()->setVisible(true);
    component->getCourtSelectionMenuButtons()["courtSelectButton"]->setVisible(true);
    component->getCourtSelectionMenuButtons()["courtSelectButton"]->setPosition((0.25 *render->getViewPort()->getActualWidth() ), (0.36 *render->getViewPort()->getActualHeight()) );

    logMsg(func +" end");
}

void guiDisplay::hideActiveMenuWidgets()  // hides active menus widgets
{
    activeMenus activeMenu = component->getActiveMenu();

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
            hideSetupMenuWidgets();
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

void guiDisplay::showActiveMenuWidgets(const renderEngineSharedPtr &render)  // shows active menus widgets
{

    std::string func = "guiDisplay::showActiveMenuWidgets()";
    
    logMsg(func +" begin");
    
    activeMenus activeMenu = component->getActiveMenu();
    switch (activeMenu)
    {
        case MAIN:
            logMsg(func + " MAIN");
            showMainMenuWidgets();
        break;
        case NETWORK:
            logMsg(func + " NETWORK");
            showNetworkSetupWidgets();
        break;
        case NETWORKCLIENT:
            logMsg(func + " NETWORKCLIENT");
            showNetworkClientSetupWidgets();
        break;
        case NETWORKSERVER:
            logMsg(func + " NETWORKSERVER");
            showNetworkServerSetupWidgets();
        break;
        case OPTIONS:
            logMsg(func + " OPTIONS");
            showOptionsMenuWidgets();
        break;
        case DISPLAY:
            logMsg(func + " DISPLAY");
            showDisplayMenuWidgets();
        break;
        case INPUTMENU:
            logMsg(func + " INPUTMENU");
            showInputMenuWidgets();
        break;
        case AUDIO:
            logMsg(func + " AUDIO");
            showAudioMenuWidgets();
        break;
        case GAMESETUP:
            logMsg(func + " GAMESETUP");
            showSetupMenuWidgets();
        break;
        case PLAYERSTART:
            logMsg(func + " PLAYERSTART");
            showPlayerStartSelectionMenuWidgets(render);
        break;
        case TEAMSELECT:
            logMsg(func + " TEAMSELECT");
//            exit(0);
            showTeamSelectionMenuWidgets(render);
        break;
        case COURTSELECT:
            logMsg(func + " COURTSELECT");
            showCourtSelectionMenuWidgets(render);
        break;
        default:
        break;
    }
    
    logMsg(func +" end");

}

void guiDisplay::changeActiveMenu(activeMenus menu, const renderEngineSharedPtr &render)  // changes the actively displayed menu
{
//    exit(0);
    std::string func = "guiDisplay::changeActiveMenu()";
    
    logMsg(func + " begin");
    
    hideActiveMenuWidgets();
    flag->setMenuActive(true);
    gameE->setMenuActive(true);
    component->setPreviousActiveMenu(component->getActiveMenu());
    component->setActiveMenu(menu);
    showActiveMenuWidgets(render);
    logMsg(func + " end");
}
