/***************************************************************************
 *   Copyright (C) 1999 - 2019 by Mike McLean                              *
 *   libolt@libolt.net                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under thtn fe terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARjTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

//#ifdef BTOGRE_MYGUI_ENABLED

#include "engine/networkengine.h"

#include "ubc/ubcgame.h"
#include "gui/guiinput.h"
#include "gui/gui.h"
#include "gui/guidata.h"
#include "gui/guidisplay.h"
#include "gui/guievents.h"
#include "components/gamecomponents.h"
#include "components/guicomponents.h"
#include "data/courtdata.h"
#include "data/gamedata.h"
#include "engine/gameengine.h"
#include "entity/gameentity.h"
#include "load/load.h"
#include "utilities/logging.h"
#include "engine/renderengine.h"
#include "data/teamdata.h"
#include "utilities/conversion.h"

#ifdef __ANDROID__
#include "utilities/android-config.h"
#else
#include "config.h"
#endif

guiInput::guiInput()  // constructor
{

}
guiInput::~guiInput() = default;  // destructor

guiComponentsSharedPtr guiInput::getComponent() const  // retrieves the value of component
{
    return (component);
}
void guiInput::setComponent(const guiComponentsSharedPtr &set)  // sets the value of component
{
    component = set;
}

guiEventsSharedPtr guiInput::getEvent() const  // retrieves the value of event
{
    return (event);
}
void guiInput::setEvent(const guiEventsSharedPtr &set)  // sets the value of event
{
    event = set;
}

guiFlagsSharedPtr guiInput::getFlag() const  // retrieves the value of flag
{
    return (flag);
}
void guiInput::setFlag(const guiFlagsSharedPtr &set)  // sets the value of flag
{
    flag = set;
}

gameEntitySharedPtr guiInput::getGameInstance() const  // retrieves the value of teamInstance
{
    return (gameInstance);
}
void guiInput::setGameInstance(const gameEntitySharedPtr &set)  // sets the value of teamInstance
{
    gameInstance = set;
}

void guiInput::startSingleGameButtonClicked(MyGUI::Widget *_sender)  // handles startSingleGameButton click event
{
    component->setMainMenuSelect(STARTSINGLE);
//    startSinglePlayerGame(gameE->getRenderE());
}

void guiInput::startMultiGameButtonClicked(MyGUI::Widget *_sender)  // handles startMultiGameButton click event
{
    component->setMainMenuSelect(STARTMULTI);
//    startMultiPlayerGame(gameE->getRenderE());
}

void guiInput::optionsButtonClicked(MyGUI::Widget *_sender)  // handles optionsButton click event
{
    component->setMainMenuSelect(OPTIONSSELECT);
//    optionsMenu(gameE->getRenderE());
}

void guiInput::exitButtonClicked(MyGUI::Widget *_sender)  // handles exitButton click event
{
    exit(0);
}

void guiInput::backCourtMainMenuButtonClicked(MyGUI::Widget *_sender)  // handles backCourtMainMenuButton click event
{
    component->setCourtMenuSelect(BACKCOURTMAIN);
//    backMainMenuSelected(gameE->getRenderE());
}

void guiInput::backNetworkMainMenuButtonClicked(MyGUI::Widget *_sender)  // handles backNetworkMainMenuButton click event
{
    component->setNetworkMenuSelect(BACKNETWORKMAIN);
//    backMainMenuSelected(gameE->getRenderE());
}

void guiInput::backOptionsMainMenuButtonClicked(MyGUI::Widget *_sender)  // handles backOptionsMainMenuButton click event
{
    component->setOptionsMenuSelect(BACKOPTIONSMAIN);
//    backMainMenuSelected(gameE->getRenderE());
}

void guiInput::backTeamMainMenuButtonClicked(MyGUI::Widget *_sender)  // handles backTeamMainMenuButton click event
{
    component->setTeamMenuSelect(BACKTEAMMAIN);
//    backMainMenuSelected(gameE->getRenderE());
}


void guiInput::courtSelectButtonClicked(MyGUI::Widget *_sender)  // handles courtSelectButton click event
{
    component->setCourtMenuSelect(COURTSSELECT);
//    courtSelected();
}

void guiInput::team0SelectButtonClicked(MyGUI::Widget *_sender)  // handles team0SelectButton click event
{
    component->setTeamMenuSelect(HOMESELECT);
//    setupHomeSelected();
}

void guiInput::team1SelectButtonClicked(MyGUI::Widget *_sender)  // handles team1SelectButton click event
{
    component->setTeamMenuSelect(AWAYSELECT);
//    setupAwaySelected();
}

void guiInput::teamsSelectedButtonClicked(MyGUI::Widget *_sender)  // handles teamsSelectButton click event
{
    logMsg("teamsSelectedButtonClicked");
    component->setTeamMenuSelect(TEAMSSELECT);
//    teamsSelected();
//    playerStartSelectionMenu(gameE->getRenderE());

}

void guiInput::backCourtSelectionMenuButtonClicked(MyGUI::Widget *_sender) // handles backCourtSelectionMenuButton click event
{
//    courtSelectionMenu(gameE->getRenderE());
    component->setTeamMenuSelect(BACKTEAMCOURT);
}

void guiInput::team0StartingLineupSetButtonClicked(MyGUI::Widget *_sender)  // handles team0StartingLineupSetButton click event
{

}

void guiInput::team1StartingLineupSetButtonClicked(MyGUI::Widget *_sender)  // handles team1StartingLineupSetButton click event
{

}

void guiInput::backStartersTeamSelectionMenuButtonClicked(MyGUI::Widget *_sender)  // handles backTeamSelectionMenuButton click event
{

//    teamSelectionMenu(gameE->getRenderE());
}
void guiInput::startingLineupSetButtonClicked(MyGUI::Widget *_sender)  // handles startingLineupSetButton click event
{
    component->setStartersMenuSelect(STARTERSSELECT);
    flag->setChangeMenu(true);

//    checkTeamInstancesCreated();
//    playerStartSelected();
//    flag->setStartActiveGame(true);
//    exit(0);
}

void guiInput::serverButtonClicked(MyGUI::Widget *_sender)  // handles serverButton click event
{
    component->setNetworkMenuSelect(SERVERSELECT);
    flag->setChangeMenu(true);

//    networkServerSetupMenu(gameE->getRenderE());
    
}

void guiInput::clientButtonClicked(MyGUI::Widget *_sender)  // handles clientButton click event
{
    component->setNetworkMenuSelect(CLIENTSELECT);
    flag->setChangeMenu(true);

//    networkClientSetupMenu(gameE->getRenderE());
}

void guiInput::serverHostButtonClicked(MyGUI::Widget *_sender)  // handles serverHostButton click event
{
    component->setNetworkServerMenuSelect(HOSTGAME);
    flag->setChangeMenu(true);

//    networkServer();
}
void guiInput::clientConnectButtonClicked(MyGUI::Widget *_sender)  // handles clientConnectButton click event
{
    component->setNetworkClientMenuSelect(CONNECTGAME);
    flag->setChangeMenu(true);

//    networkClient();
}

void guiInput::backNetClientNetworkSetupButtonClicked(MyGUI::Widget *_sender)  // handles backNetworkSetupButton click event
{
    component->setNetworkClientMenuSelect(BACKNETCLIENTMAIN);
    flag->setChangeMenu(true);

//    backNetworkSetupMenuSelected(gameE->getRenderE());
}

void guiInput::backNetServerNetworkSetupButtonClicked(MyGUI::Widget *_sender)  // handles backNetworkSetupButton click event
{
    component->setNetworkServerMenuSelect(BACKNETSERVMAIN);
    flag->setChangeMenu(true);

//    backNetworkSetupMenuSelected(gameE->getRenderE());
}


void guiInput::displayButtonClicked(MyGUI::Widget *_sender)  // handles didplayButton click event
{
    component->setOptionsMenuSelect(DISPLAYSELECT);
    flag->setChangeMenu(true);
}

void guiInput::inputButtonClicked(MyGUI::Widget *_sender)  // handles inputButton click event
{
    component->setOptionsMenuSelect(INPUTSELECT);
    flag->setChangeMenu(true);

//    inputMenu(gameE->getRenderE());
}

void guiInput::audioButtonClicked(MyGUI::Widget *_sender)  // handles audioButton click event
{
    component->setOptionsMenuSelect(AUDIOSELECT);
    flag->setChangeMenu(true);

//    audioMenu(gameE->getRenderE());
}

void guiInput::changeResolutionButtonClicked(MyGUI::Widget *_sender)  // handles changeResolutionButton click event
{

}

void guiInput::changeInputTypeButtonClicked(MyGUI::Widget *_sender)  // handles changeInputTypeButton click event
{

}

void guiInput::enableAudioButtonClicked(MyGUI::Widget *_sender)  // handles eneableAudioButton click event
{

}

void guiInput::disableAudioButtonClicked(MyGUI::Widget *_sender)  // handles eneableAudioButton click event
{

}

void guiInput::backNetworkClientButtonClicked(MyGUI::Widget *_sender)  // handles backNetworkClientButton click event
{
//    networkClientSetupMenu(gameE->getRenderE());
}

void guiInput::backAudioOptionsMenuButtonClicked(MyGUI::Widget *_sender)  // handles backOptionsMenuButton click event
{
    component->setAudioMenuSelect(BACKAUDIOOPTIONS);
    flag->setChangeMenu(true);
//    optionsMenu(gameE->getRenderE());
}

void guiInput::backDisplayOptionsMenuButtonClicked(MyGUI::Widget *_sender)  // handles backOptionsMenuButton click event
{
    component->setDisplayenuSelect(BACKDISPLAYOPTOINS);
    flag->setChangeMenu(true);

//    optionsMenu(gameE->getRenderE());
}

void guiInput::backInputOptionsMenuButtonClicked(MyGUI::Widget *_sender)  // handles backOptionsMenuButton click event
{
    component->setInputMenuSelect(BACKINPUTOPTIONS);
    flag->setChangeMenu(true);

//    optionsMenu(gameE->getRenderE());
}


void guiInput::backPlayerStartSelectionMenuButtonClicked(MyGUI::Widget *_sender)  // handles backPlayerStartSelectionMenuButton click event
{

}

/*void guiInput::backSetupMenuButtonClicked(MyGUI::Widget *_sender)  // handles backSetupMenuButton click event
{
    setupMenu(gameE->getRenderE());
}*/

void guiInput::menuReceiveKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render)  // processes key input
{
    conversionSharedPtr convert ;

    logMsg("menuReceiveKeyKeyPress!");
    logMsg("activeMenu == " +convert->toString(component->getActiveMenu()));
    logMsg("keyPressed == " +keyPressed);
//    exit(0);
    if (!keyPressed.empty())
    {
        activeMenus activeMenu = component->getActiveMenu();
        switch (activeMenu)
        {
            case MAIN:
                processMainMenuKeyPress(keyPressed, render);
                break;
            case NETWORK:
                processNetworkMenuKeyPress(keyPressed, render);
                break;
            case NETWORKSERVER:
                processNetworkServerMenuKeyPress(keyPressed, render);
                break;
            case NETWORKCLIENT:
                processNetworkClientMenuKeyPress(keyPressed, render);
                break;
            case OPTIONS:
                processOptionsMenuKeyPress(keyPressed, render);
                break;
            case DISPLAY:
                processDisplayMenuKeyPress(keyPressed, render);
                break;
            case INPUTMENU:
                processInputMenuKeyPress(keyPressed, render);
                break;
            case AUDIO:
                processAudioMenuKeyPress(keyPressed, render);
                break;
/*            case GAMESETUP:
                processSetupMenuKeyPress(keyPressed, render);
                break;
*/
            case PLAYERSTART:
                processPlayerStartSelectionMenuKeyPress(keyPressed, render);
                break;
            case TEAMSELECT:
                processTeamSelectionMenuKeyPress(keyPressed, render);
//                exit(0);
                break;
            case COURTSELECT:
                processCourtSelectionMenuKeyPress(keyPressed, render);
                break;
            default:
                break;
        }      
    }
}

void guiInput::processMainMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render)  // processes main menu key input
{
//    exit(0);
    if (keyPressed == "s")
    {
//        exit(0);
//        startSinglePlayerGame(render);
        gameInstance->getData()->setGameType(SINGLE);
        component->setMainMenuSelect(STARTSINGLE);
        flag->setChangeMenu(true);
//        courtSelectionMenu(render);   // displays the menu for selecting which court to use

    }
    else if (keyPressed == "m")
    {
        gameInstance->getData()->setGameType(MULTINET);
        component->setMainMenuSelect(STARTMULTI);
        flag->setChangeMenu(true);

//        startMultiPlayerGame(render);
    }
    else if (keyPressed == "o")
    {
       component->setMainMenuSelect(OPTIONSSELECT);
       flag->setChangeMenu(true);
//        optionsMenu(render);
    }
    else if (keyPressed == "e")
    {
        exit(0);
    }
    else
    {

    }
}
void guiInput::processNetworkMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render)  // processes network menu key input
{
    if (keyPressed == "c")
    {
        component->setNetworkMenuSelect(CLIENTSELECT);
        flag->setChangeMenu(true);
//       networkClientSetupMenu(render);
    }
    else if (keyPressed == "b")
    {
        component->setNetworkMenuSelect(BACKNETWORKMAIN);
        flag->setChangeMenu(true);
//        backMainMenuSelected(render);
    }
    else if (keyPressed == "s")
    {
        component->setNetworkMenuSelect(SERVERSELECT);
        flag->setChangeMenu(true);
//        networkServerSetupMenu(render);
    }
    else
    {

    }
}

void guiInput::processNetworkClientMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render)  // processes network menu key input
{
    if (MyGUI::InputManager::getInstance().getKeyFocusWidget() == component->getClientIPAddressBox().get())
    {
//        logMsg("clientIPAddressBox is focus!");
//        exit(0);
        if (keyPressed == "0")
        {
            component->getClientIPAddressBox()->addText("0");
        }
        else if (keyPressed == "1")
        {
            component->getClientIPAddressBox()->addText("1");
        }
        else if (keyPressed == "2")
        {
            component->getClientIPAddressBox()->addText("2");
        }
        else if (keyPressed == "3")
        {
            component->getClientIPAddressBox()->addText("3");
        }
        else if (keyPressed == "4")
        {
            component->getClientIPAddressBox()->addText("4");
        }
        else if (keyPressed == "5")
        {
            component->getClientIPAddressBox()->addText("5");
        }
        else if (keyPressed == "6")
        {
            component->getClientIPAddressBox()->addText("6");
        }
        else if (keyPressed == "7")
        {
            component->getClientIPAddressBox()->addText("7");
        }
        else if (keyPressed == "8")
        {
            component->getClientIPAddressBox()->addText("8");
        }
        else if (keyPressed == "9")
        {
            component->getClientIPAddressBox()->addText("9");
        }
        else if (keyPressed == ".")
        {
            component->getClientIPAddressBox()->addText(".");
        }
    }
    else
    {

    }

    if (keyPressed == "c")
    {
        component->setNetworkClientMenuSelect(CONNECTGAME);
        flag->setChangeMenu(true);
//        networkClient();
    }
    else if (keyPressed == "b")
    {
        component->setNetworkClientMenuSelect(BACKNETCLIENTMAIN);
        flag->setChangeMenu(true);
//        startMultiPlayerGame(render);
    }

}

void guiInput::processNetworkServerMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render)  // process network server menu key input
{
    if (MyGUI::InputManager::getInstance().getKeyFocusWidget() == component->getServerIPAddressBox().get())
    {
        logMsg("keypress = " +keyPressed);
//        exit(0);
        if (keyPressed == "0")
        {
            component->getServerIPAddressBox()->addText("0");
        }
        else if (keyPressed == "1")
        {
            component->getServerIPAddressBox()->addText("1");
        }
        else if (keyPressed == "2")
        {
            component->getServerIPAddressBox()->addText("2");
        }
        else if (keyPressed == "3")
        {
            component->getServerIPAddressBox()->addText("3");
        }
        else if (keyPressed == "4")
        {
            component->getServerIPAddressBox()->addText("4");
        }
        else if (keyPressed == "5")
        {
            component->getServerIPAddressBox()->addText("5");
        }
        else if (keyPressed == "6")
        {
            component->getServerIPAddressBox()->addText("6");
        }
        else if (keyPressed == "7")
        {
            component->getServerIPAddressBox()->addText("7");
        }
        else if (keyPressed == "8")
        {
            component->getServerIPAddressBox()->addText("8");
        }
        else if (keyPressed == "9")
        {
            component->getServerIPAddressBox()->addText("9");
        }
        else if (keyPressed == ".")
        {
            component->getServerIPAddressBox()->addText(".");
        }
        else if (keyPressed == "Backspace")
        {
            logMsg("Backspace!");
//            exit(0);
        //    component->getServerIPAddressBox()->addText(".");
//            MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Backspace, 0);
        }
    }
    else
    {
        
    }
    
    if (keyPressed == "h")
    {
        component->setNetworkServerMenuSelect(HOSTGAME);
        flag->setChangeMenu(true);
//        networkServer();

    }
    else if (keyPressed == "b")
    {
        component->setNetworkServerMenuSelect(BACKNETSERVMAIN);
        flag->setChangeMenu(true);
//        startMultiPlayerGame(render);
    }
}


void guiInput::processOptionsMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render)  // processes options menu key input
{
    if (keyPressed == "a")
    {
        component->setOptionsMenuSelect(AUDIOSELECT);
        flag->setChangeMenu(true);
//        audioMenu(render);
    }
    else if (keyPressed == "d")
    {
        component->setOptionsMenuSelect(DISPLAYSELECT);
        flag->setChangeMenu(true);
//       displayMenu(render);
    }
    else if (keyPressed == "b")
    {
        component->setOptionsMenuSelect(BACKOPTIONSMAIN);
        flag->setChangeMenu(true);
//        backMainMenuSelected(render);
    }
    else if (keyPressed == "i")
    {
        component->setOptionsMenuSelect(INPUTSELECT);
        flag->setChangeMenu(true);
//        inputMenu(render);
    }
    else
    {

    }
}

void guiInput::processAudioMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render)  // processes audio settings menu key input
{
    if (keyPressed == "c")
    {
        // placeholder
    }
    else if (keyPressed == "b")
    {
        component->setAudioMenuSelect(BACKAUDIOOPTIONS);
        flag->setChangeMenu(true);
//        optionsMenu(render);
    }
}

void guiInput::processDisplayMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render)  // processes display settings menu key input
{

    if (keyPressed == "c")
    {
        // placeholder
    }
    else if (keyPressed == "b")
    {

        component->setDisplayenuSelect(BACKDISPLAYOPTOINS);
        flag->setChangeMenu(true);
//        optionsMenu(render);
    }

}

void guiInput::processInputMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render)  // processes input settings menu key input
{
    if (keyPressed == "c")
    {
        // placeholder
    }
    else if (keyPressed == "b")
    {
        component->setInputMenuSelect(BACKINPUTOPTIONS);
        flag->setChangeMenu(true);
//        optionsMenu(render);
    }
}

/*void GUISystem::processSetupMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render)  // processes game setup menu key input
{
    //gameState *gameS = gameState::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
//    teamStateVecSharedPtr teamInstance = gameS->getTeamInstance();
    std::string func = "GUISystem::processSetupMenuKeyPress()";
    activeMenus previousActiveMenu = component->getPreviousActiveMenu();

    logMsg(func +" begin");
    if (keyPressed == "a" && !flag->getSetupMenuAwaySelected())
    {
        setupAwaySelected();
    }
    else if (keyPressed == "h" && !flag->getSetupMenuHomeSelected())
    {
        setupHomeSelected();
    }
    else if (keyPressed == "b")
    {
        if (previousActiveMenu == MAIN)
        {
            backMainMenuSelected(render);
        }
        else if (previousActiveMenu == NETWORKCLIENT)
        {
            component->setNetworkMenuSelect(CLIENTSELECT);
//            networkClientSetupMenu(render);
        }
        else if (previousActiveMenu == NETWORKSERVER)
        {
            component->setNetworkMenuSelect(SERVERSELECT);
//            networkServerSetupMenu(render);
        }
    }
    // FIXME!
    else if (keyPressed == "t")
    {        
        logMsg("teamsSelected!");
//        exit(0);
//        teamsSelected();

    exit(0);
//        playerStartSelectionMenu(render);
    }
    else if (keyPressed == "x")
    {
        if (flag->getSetupMenuAwaySelected())
        {
            auto x = component->getTeamSelectBox()[1]->getIndexSelected() +1;
            if (x < gameInstance->getComponent()->getTeamInstance().size())
            {
                component->getTeamSelectBox()[1]->setIndexSelected(x);
                component->getTeamSelectBox()[1]->beginToItemAt(x);
            }
            else
            {
                component->getTeamSelectBox()[1]->setIndexSelected(0);
                component->getTeamSelectBox()[1]->beginToItemAt(0);
            }
        }
        else if (flag->getSetupMenuHomeSelected())
        {
            auto x = component->getTeamSelectBox()[0]->getIndexSelected() +1;
            if (x < gameInstance->getComponent()->getTeamInstance().size())
            {
                component->getTeamSelectBox()[0]->setIndexSelected(x);
                component->getTeamSelectBox()[0]->beginToItemAt(x);
            }
            else
            {
                component->getTeamSelectBox()[0]->setIndexSelected(0);
                component->getTeamSelectBox()[0]->beginToItemAt(0);
            }
        }
        else
        {

        }
    }
    else if (keyPressed == "z")
    {
        if (flag->getSetupMenuAwaySelected())
        {
            auto x = component->getTeamSelectBox()[1]->getIndexSelected() -1;
            if (x < 0)
            {
                component->getTeamSelectBox()[1]->setIndexSelected(gameInstance->getComponent()->getTeamInstance().size() -1);
                component->getTeamSelectBox()[1]->beginToItemAt(gameInstance->getComponent()->getTeamInstance().size() -1);
            }
            else
            {
                //exit(0);
                component->getTeamSelectBox()[1]->setIndexSelected(x);
                component->getTeamSelectBox()[1]->beginToItemAt(x);
            }
        }
        else if (flag->getSetupMenuHomeSelected())
        {
            auto x = component->getTeamSelectBox()[0]->getIndexSelected() -1;
            if (x < 0)
            {
                component->getTeamSelectBox()[0]->setIndexSelected(gameInstance->getComponent()->getTeamInstance().size() -1);
                component->getTeamSelectBox()[0]->beginToItemAt(gameInstance->getComponent()->getTeamInstance().size() -1);
            }
            else
            {
                component->getTeamSelectBox()[0]->setIndexSelected(x);
                component->getTeamSelectBox()[0]->beginToItemAt(x);
            }
        }
        else
        {

        }
    }
}
*/

void guiInput::processPlayerStartSelectionMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render)  // process player start selection menu key input
{

    //gameState *gameS = gameState::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();

    event->checkTeamInstancesCreated();
//    teamState testState;
    logMsg("keyPressed == " +keyPressed);
//    exit(0);
    if (keyPressed == "s")
    {
//        exit(0);
        logMsg("processPlayerStart KeyPressed == " +keyPressed);
//        exit(0);
        
        component->setStartersMenuSelect(STARTERSSELECT);
        flag->setChangeMenu(true);

/*        event->playerStartSelected();
        flag->setStartActiveGame(true);
        flag->setMenuActive(false);
*/
    }
    else if (keyPressed == "b")
    {
        component->setStartersMenuSelect(BACKSTARTERSTEAM);
        flag->setChangeMenu(true);
//        teamSelectionMenu(render);
    }

//    exit(0);
}

void guiInput::processTeamSelectionMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render)  // process team selection menu key input
{
    //gameState *gameS = gameState::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
    
//    teamStateVecSharedPtr teamInstance = gameS->getTeamInstance();
    std::string func = "GUISystem::processTeamSelectionMenuKeyPress()";
    
    logMsg(func +" begin");
//    exit(0);
    if (keyPressed == "a" && !flag->getSetupMenuAwaySelected())
    {
        event->setupAwaySelected();
    }
    else if (keyPressed == "h" && !flag->getSetupMenuHomeSelected())
    {
        event->setupHomeSelected();
    }
    else if (keyPressed == "b")
    {
        /*
        if (previousActiveMenu == MAIN)
        {
            backMainMenuSelected();
        }
        else if (previousActiveMenu == NETWORKCLIENT)
        {
            networkClientSetupMenu();
        }
        else if (previousActiveMenu == NETWORKSERVER)
        {
            networkServerSetupMenu();
        }
        */
//        courtSelectionMenu(render);
        component->setTeamMenuSelect(BACKTEAMCOURT);
    }
    else if (keyPressed == "t")
    {
        logMsg("yarp");
//        exit(0);
        component->setTeamMenuSelect(TEAMSSELECT);
        flag->setChangeMenu(true);

//        teamsSelected();  
//        playerStartSelectionMenu(render);
//        exit(0);
    }
    else if (keyPressed == "x")
    {
        if (flag->getSetupMenuAwaySelected())
        {
            auto x = component->getTeamSelectBox()[1]->getIndexSelected() +1;
            if (x < gameInstance->getComponent()->getTeamInstance().size())
            {
                component->getTeamSelectBox()[1]->setIndexSelected(x);
                component->getTeamSelectBox()[1]->beginToItemAt(x);
            }
            else
            {
                component->getTeamSelectBox()[1]->setIndexSelected(0);
                component->getTeamSelectBox()[1]->beginToItemAt(0);
            }
        }
        else if (flag->getSetupMenuHomeSelected())
        {
            auto x = component->getTeamSelectBox()[0]->getIndexSelected() +1;
            if (x < gameInstance->getComponent()->getTeamInstance().size())
            {
                component->getTeamSelectBox()[0]->setIndexSelected(x);
                component->getTeamSelectBox()[0]->beginToItemAt(x);
            }
            else
            {
                component->getTeamSelectBox()[0]->setIndexSelected(0);
                component->getTeamSelectBox()[0]->beginToItemAt(0);
            }
        }
        else
        {

        }
    }
    else if (keyPressed == "z")
    {
        if (flag->getSetupMenuAwaySelected())
        {
            auto x = component->getTeamSelectBox()[1]->getIndexSelected() -1;
            if (x < 0)
            {
                component->getTeamSelectBox()[1]->setIndexSelected(gameInstance->getComponent()->getTeamInstance().size() -1);
                component->getTeamSelectBox()[1]->beginToItemAt(gameInstance->getComponent()->getTeamInstance().size() -1);
            }
            else
            {
                //exit(0);
                component->getTeamSelectBox()[1]->setIndexSelected(x);
                component->getTeamSelectBox()[1]->beginToItemAt(x);
            }
        }
        else if (flag->getSetupMenuHomeSelected())
        {
            auto x = component->getTeamSelectBox()[0]->getIndexSelected() -1;
            if (x < 0)
            {
                component->getTeamSelectBox()[0]->setIndexSelected(gameInstance->getComponent()->getTeamInstance().size() -1);
                component->getTeamSelectBox()[0]->beginToItemAt(gameInstance->getComponent()->getTeamInstance().size() -1);
            }
            else
            {
                component->getTeamSelectBox()[0]->setIndexSelected(x);
                component->getTeamSelectBox()[0]->beginToItemAt(x);
            }
        }
        else
        {

        }
    }

}

void guiInput::processCourtSelectionMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render)  // process court selection menu key input
{
//    exit(0);
    //gameState *gameS = gameState::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();

    if (keyPressed == "b")
    {
        component->setCourtMenuSelect(BACKCOURTMAIN);
        flag->setChangeMenu(true);
//        backMainMenuSelected(render);
    }
    else if (keyPressed == "q")
    {
        exit(0);
    }
    else if (keyPressed == "s")
    {
        component->setCourtMenuSelect(COURTSSELECT);
        flag->setChangeMenu(true);

//        courtSelected();
//        teamSelectionMenu(render);
        
    }
}
//#endif

