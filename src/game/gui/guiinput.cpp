/***************************************************************************
 *   Copyright (C) 1999 - 2018 by Mike McLean                              *
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

#include "engine/networkengine.h"

#include "ubc/ubcgame.h"
#include "gui/gui.h"
#include "components/gamecomponents.h"
#include "data/courtdata.h"
#include "engine/gameengine.h"
#include "state/gamestate.h"
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

// static variables/functions
//void GUISystem::startSingleGameButtonClicked(MyGUI::Widget *_sender);

void GUISystem::startSingleGameButtonClicked(MyGUI::Widget *_sender)  // handles startSingleGameButton click event
{
    startSinglePlayerGame(gameE->getRenderE());
}

void GUISystem::startMultiGameButtonClicked(MyGUI::Widget *_sender)  // handles startMultiGameButton click event
{
    startMultiPlayerGame(gameE->getRenderE());
}

void GUISystem::optionsButtonClicked(MyGUI::Widget *_sender)  // handles optionsButton click event
{
    optionsMenu(gameE->getRenderE());

}
void GUISystem::exitButtonClicked(MyGUI::Widget *_sender)  // handles exitButton click event
{
    exit(0);
}

void GUISystem::serverButtonClicked(MyGUI::Widget *_sender)  // handles serverButton click event
{
    networkServerSetupMenu(gameE->getRenderE());
}

void GUISystem::clientButtonClicked(MyGUI::Widget *_sender)  // handles clientButton click event
{
    networkClientSetupMenu(gameE->getRenderE());
}

void GUISystem::serverHostButtonClicked(MyGUI::Widget *_sender)  // handles serverHostButton click event
{
    networkServer();
}
void GUISystem::clientConnectButtonClicked(MyGUI::Widget *_sender)  // handles clientConnectButton click event
{
    networkClient();
}

void GUISystem::backMainMenuButtonClicked(MyGUI::Widget *_sender)  // handles backMainMenuButton click event
{
    backMainMenuSelected(gameE->getRenderE());
}

void GUISystem::backNetworkSetupButtonClicked(MyGUI::Widget *_sender)  // handles backNetworkSetupButton click event
{
    backNetworkSetupMenuSelected(gameE->getRenderE());
}

void GUISystem::displayButtonClicked(MyGUI::Widget *_sender)  // handles didplayButton click event
{

}

void GUISystem::inputButtonClicked(MyGUI::Widget *_sender)  // handles inputButton click event
{
    inputMenu(gameE->getRenderE());
}

void GUISystem::audioButtonClicked(MyGUI::Widget *_sender)  // handles audioButton click event
{
    audioMenu(gameE->getRenderE());
}

void GUISystem::changeResolutionButtonClicked(MyGUI::Widget *_sender)  // handles changeResolutionButton click event
{

}

void GUISystem::changeInputTypeButtonClicked(MyGUI::Widget *_sender)  // handles changeInputTypeButton click event
{

}

void GUISystem::enableAudioButtonClicked(MyGUI::Widget *_sender)  // handles eneableAudioButton click event
{

}

void GUISystem::disableAudioButtonClicked(MyGUI::Widget *_sender)  // handles eneableAudioButton click event
{

}

void GUISystem::team0SelectButtonClicked(MyGUI::Widget *_sender)  // handles team0SelectButton click event
{
    setupHomeSelected();
}

void GUISystem::team1SelectButtonClicked(MyGUI::Widget *_sender)  // handles team1SelectButton click event
{
    setupAwaySelected();
}

void GUISystem::teamsSelectedButtonClicked(MyGUI::Widget *_sender)  // handles teamsSelectButton click event
{
    logMsg("teamsSelectedButtonClicked");
    teamsSelected();
    playerStartSelectionMenu(gameE->getRenderE());

}

void GUISystem::team0StartingLineupSetButtonClicked(MyGUI::Widget *_sender)  // handles team0StartingLineupSetButton click event
{

}

void GUISystem::team1StartingLineupSetButtonClicked(MyGUI::Widget *_sender)  // handles team1StartingLineupSetButton click event
{

}

void GUISystem::startingLineupSetButtonClicked(MyGUI::Widget *_sender)  // handles startingLineupSetButton click event
{
    checkTeamInstancesCreated();
    playerStartSelected();
    game->setStartActiveGame(true);
//    exit(0);
}

void GUISystem::backNetworkClientButtonClicked(MyGUI::Widget *_sender)  // handles backNetworkClientButton click event
{
    networkClientSetupMenu(gameE->getRenderE());
}

void GUISystem::backOptionsMenuButtonClicked(MyGUI::Widget *_sender)  // handles backOptionsMenuButton click event
{
    optionsMenu(gameE->getRenderE());
}

void GUISystem::backPlayerStartSelectionMenuButtonClicked(MyGUI::Widget *_sender)  // handles backPlayerStartSelectionMenuButton click event
{

}

void GUISystem::backTeamSelectionMenuButtonClicked(MyGUI::Widget *_sender)  // handles backTeamSelectionMenuButton click event
{
    teamSelectionMenu(gameE->getRenderE());
}

void GUISystem::backCourtSelectionMenuButtonClicked(MyGUI::Widget *_sender) // handles backCourtSelectionMenuButton click event
{
    courtSelectionMenu(gameE->getRenderE());
}

void GUISystem::backSetupMenuButtonClicked(MyGUI::Widget *_sender)  // handles backSetupMenuButton click event
{
    setupMenu(gameE->getRenderE());
}

void GUISystem::courtSelectButtonClicked(MyGUI::Widget *_sender)  // handles courtSelectButton click event
{
     courtSelected();
}


void GUISystem::menuReceiveKeyPress(std::string keyPressed, renderEngineSharedPtr render)  // processes key input
{
    conversionSharedPtr convert = conversion::Instance();

    logMsg("menuReceiveKeyKeyPress!");
    logMsg("activeMenu == " +convert->toString(activeMenu));
    logMsg("keyPressed == " +keyPressed);
//    exit(0);
    if (keyPressed != "")
    {
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
            case GAMESETUP:
                processSetupMenuKeyPress(keyPressed, render);
                break;
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

void GUISystem::processMainMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render)  // processes main menu key input
{
//    exit(0);
    if (keyPressed == "s")
    {
//        exit(0);
        startSinglePlayerGame(render);
    }
    else if (keyPressed == "m")
    {
        startMultiPlayerGame(render);
    }
    else if (keyPressed == "o")
    {
        optionsMenu(render);
    }
    else if (keyPressed == "e")
    {
        exit(0);
    }
    else
    {

    }
}
void GUISystem::processNetworkMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render)  // processes network menu key input
{
   if (keyPressed == "c")
    {
       networkClientSetupMenu(render);
    }
    else if (keyPressed == "b")
    {
        backMainMenuSelected(render);
    }
    else if (keyPressed == "s")
    {
        networkServerSetupMenu(render);
    }
    else
    {

    }
}

void GUISystem::processNetworkServerMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render)  // process network server menu key input
{
    if (MyGUI::InputManager::getInstance().getKeyFocusWidget() == serverIPAddressBox.get())
    {
        logMsg("keypress = " +keyPressed);
//        exit(0);
        if (keyPressed == "0")
        {
            serverIPAddressBox->addText("0");
        }
        else if (keyPressed == "1")
        {
            serverIPAddressBox->addText("1");
        }
        else if (keyPressed == "2")
        {
            serverIPAddressBox->addText("2");
        }
        else if (keyPressed == "3")
        {
            serverIPAddressBox->addText("3");
        }
        else if (keyPressed == "4")
        {
            serverIPAddressBox->addText("4");
        }
        else if (keyPressed == "5")
        {
            serverIPAddressBox->addText("5");
        }
        else if (keyPressed == "6")
        {
            serverIPAddressBox->addText("6");
        }
        else if (keyPressed == "7")
        {
            serverIPAddressBox->addText("7");
        }
        else if (keyPressed == "8")
        {
            serverIPAddressBox->addText("8");
        }
        else if (keyPressed == "9")
        {
            serverIPAddressBox->addText("9");
        }
        else if (keyPressed == ".")
        {
            serverIPAddressBox->addText(".");
        }
        else if (keyPressed == "Backspace")
        {
            logMsg("Backspace!");
//            exit(0);
        //    serverIPAddressBox->addText(".");
//            MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Backspace, 0);
        }
    }
    else
    {
        
    }
    
    if (keyPressed == "h")
    {
        hideNetworkServerSetupWidgets();
        networkServer();
    }
    else if (keyPressed == "b")
    {
        startMultiPlayerGame(render);
    }
}

void GUISystem::processNetworkClientMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render)  // processes network menu key input
{
    if (MyGUI::InputManager::getInstance().getKeyFocusWidget() == clientIPAddressBox.get())
    {
//        logMsg("clientIPAddressBox is focus!");
//        exit(0);
        if (keyPressed == "0")
        {
            clientIPAddressBox->addText("0");
        }
        else if (keyPressed == "1")
        {
            clientIPAddressBox->addText("1");
        }
        else if (keyPressed == "2")
        {
            clientIPAddressBox->addText("2");
        }
        else if (keyPressed == "3")
        {
            clientIPAddressBox->addText("3");
        }
        else if (keyPressed == "4")
        {
            clientIPAddressBox->addText("4");
        }
        else if (keyPressed == "5")
        {
            clientIPAddressBox->addText("5");
        }
        else if (keyPressed == "6")
        {
            clientIPAddressBox->addText("6");
        }
        else if (keyPressed == "7")
        {
            clientIPAddressBox->addText("7");
        }
        else if (keyPressed == "8")
        {
            clientIPAddressBox->addText("8");
        }
        else if (keyPressed == "9")
        {
            clientIPAddressBox->addText("9");
        }
        else if (keyPressed == ".")
        {
            clientIPAddressBox->addText(".");
        }
    }
    else
    {
        
    }
    
    if (keyPressed == "c")
    {
        hideNetworkClientSetupWidgets();
        networkClient();
    }
    else if (keyPressed == "b")
    {
        startMultiPlayerGame(render);
    }

}

void GUISystem::processOptionsMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render)  // processes options menu key input
{
    if (keyPressed == "d")
    {
       displayMenu(render);
    }
    else if (keyPressed == "b")
    {
        backMainMenuSelected(render);
    }
    else if (keyPressed == "i")
    {
        inputMenu(render);
    }
    else if (keyPressed == "a")
    {
        audioMenu(render);
    }
    else
    {

    }
}

void GUISystem::processDisplayMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render)  // processes display settings menu key input
{

    if (keyPressed == "c")
    {
        // placeholder
    }
    else if (keyPressed == "b")
    {
        optionsMenu(render);
    }

}

void GUISystem::processInputMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render) // processes input settings menu key input
{
    if (keyPressed == "c")
    {
        // placeholder
    }
    else if (keyPressed == "b")
    {
        optionsMenu(render);
    }
}

void GUISystem::processAudioMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render)  // processes audio settings menu key input
{
    if (keyPressed == "c")
    {
        // placeholder
    }
    else if (keyPressed == "b")
    {
        optionsMenu(render);
    }
}

void GUISystem::processSetupMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render)  // processes game setup menu key input
{
    //gameState *gameS = gameState::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
//    teamStateVecSharedPtr teamInstance = gameS->getTeamInstance();
    std::string func = "GUISystem::processSetupMenuKeyPress()";
    
    logMsg(func +" begin");
    if (keyPressed == "a" && !setupMenuAwaySelected)
    {
        setupAwaySelected();
    }
    else if (keyPressed == "h" && !setupMenuHomeSelected)
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
            networkClientSetupMenu(render);
        }
        else if (previousActiveMenu == NETWORKSERVER)
        {
            networkServerSetupMenu(render);
        }
    }
    // FIXME!
    else if (keyPressed == "t")
    {        
        logMsg("teamsSelected!");
//        exit(0);
        teamsSelected();

    exit(0);
        playerStartSelectionMenu(render);
    }
    else if (keyPressed == "x")
    {
        if (setupMenuAwaySelected)
        {
            auto x = teamSelectBox[1]->getIndexSelected() +1;
            if (x < gameInstance->getComponent()->getTeamInstance().size())
            {
                teamSelectBox[1]->setIndexSelected(x);
                teamSelectBox[1]->beginToItemAt(x);
            }
            else
            {
                teamSelectBox[1]->setIndexSelected(0);
                teamSelectBox[1]->beginToItemAt(0);
            }
        }
        else if (setupMenuHomeSelected)
        {
            auto x = teamSelectBox[0]->getIndexSelected() +1;
            if (x < gameInstance->getComponent()->getTeamInstance().size())
            {
                teamSelectBox[0]->setIndexSelected(x);
                teamSelectBox[0]->beginToItemAt(x);
            }
            else
            {
                teamSelectBox[0]->setIndexSelected(0);
                teamSelectBox[0]->beginToItemAt(0);
            }
        }
        else
        {

        }
    }
    else if (keyPressed == "z")
    {
        if (setupMenuAwaySelected)
        {
            auto x = teamSelectBox[1]->getIndexSelected() -1;
            if (x < 0)
            {
                teamSelectBox[1]->setIndexSelected(gameInstance->getComponent()->getTeamInstance().size() -1);
                teamSelectBox[1]->beginToItemAt(gameInstance->getComponent()->getTeamInstance().size() -1);
            }
            else
            {
                //exit(0);
                teamSelectBox[1]->setIndexSelected(x);
                teamSelectBox[1]->beginToItemAt(x);
            }
        }
        else if (setupMenuHomeSelected)
        {
            auto x = teamSelectBox[0]->getIndexSelected() -1;
            if (x < 0)
            {
                teamSelectBox[0]->setIndexSelected(gameInstance->getComponent()->getTeamInstance().size() -1);
                teamSelectBox[0]->beginToItemAt(gameInstance->getComponent()->getTeamInstance().size() -1);
            }
            else
            {
                teamSelectBox[0]->setIndexSelected(x);
                teamSelectBox[0]->beginToItemAt(x);
            }
        }
        else
        {

        }
    }
}

void GUISystem::processPlayerStartSelectionMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render)  // process player start selection menu key input
{

    //gameState *gameS = gameState::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();

    checkTeamInstancesCreated();
//    teamState testState;
    logMsg("keyPressed == " +keyPressed);
//    exit(0);
    if (keyPressed == "s")
    {
//        exit(0);
        logMsg("processPlayerStart KeyPressed == " +keyPressed);
//        exit(0);
        playerStartSelected();
        game->setStartActiveGame(true);
        menuActive = false;

    }
    else if (keyPressed == "b")
    {
        teamSelectionMenu(render);
    }

//    exit(0);
}

void GUISystem::processTeamSelectionMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render)  // process team selection menu key input
{
    //gameState *gameS = gameState::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
    
//    teamStateVecSharedPtr teamInstance = gameS->getTeamInstance();
    std::string func = "GUISystem::processTeamSelectionMenuKeyPress()";
    
    logMsg(func +" begin");
//    exit(0);
    if (keyPressed == "a" && !setupMenuAwaySelected)
    {
        setupAwaySelected();
    }
    else if (keyPressed == "h" && !setupMenuHomeSelected)
    {
        setupHomeSelected();
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
        courtSelectionMenu(render);
    }
    else if (keyPressed == "t")
    {
        logMsg("yarp");
//        exit(0);
        teamsSelected();
    
        playerStartSelectionMenu(render);
//        exit(0);
    }
    else if (keyPressed == "x")
    {
        if (setupMenuAwaySelected)
        {
            auto x = teamSelectBox[1]->getIndexSelected() +1;
            if (x < gameInstance->getComponent()->getTeamInstance().size())
            {
                teamSelectBox[1]->setIndexSelected(x);
                teamSelectBox[1]->beginToItemAt(x);
            }
            else
            {
                teamSelectBox[1]->setIndexSelected(0);
                teamSelectBox[1]->beginToItemAt(0);
            }
        }
        else if (setupMenuHomeSelected)
        {
            auto x = teamSelectBox[0]->getIndexSelected() +1;
            if (x < gameInstance->getComponent()->getTeamInstance().size())
            {
                teamSelectBox[0]->setIndexSelected(x);
                teamSelectBox[0]->beginToItemAt(x);
            }
            else
            {
                teamSelectBox[0]->setIndexSelected(0);
                teamSelectBox[0]->beginToItemAt(0);
            }
        }
        else
        {

        }
    }
    else if (keyPressed == "z")
    {
        if (setupMenuAwaySelected)
        {
            auto x = teamSelectBox[1]->getIndexSelected() -1;
            if (x < 0)
            {
                teamSelectBox[1]->setIndexSelected(gameInstance->getComponent()->getTeamInstance().size() -1);
                teamSelectBox[1]->beginToItemAt(gameInstance->getComponent()->getTeamInstance().size() -1);
            }
            else
            {
                //exit(0);
                teamSelectBox[1]->setIndexSelected(x);
                teamSelectBox[1]->beginToItemAt(x);
            }
        }
        else if (setupMenuHomeSelected)
        {
            auto x = teamSelectBox[0]->getIndexSelected() -1;
            if (x < 0)
            {
                teamSelectBox[0]->setIndexSelected(gameInstance->getComponent()->getTeamInstance().size() -1);
                teamSelectBox[0]->beginToItemAt(gameInstance->getComponent()->getTeamInstance().size() -1);
            }
            else
            {
                teamSelectBox[0]->setIndexSelected(x);
                teamSelectBox[0]->beginToItemAt(x);
            }
        }
        else
        {

        }
    }

}

void GUISystem::processCourtSelectionMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render)  // process court selection menu key input
{
//    exit(0);
    //gameState *gameS = gameState::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();

    if (keyPressed == "b")
    {
        backMainMenuSelected(render);
    }
    else if (keyPressed == "q")
    {
        exit(0);
    }
    else if (keyPressed == "s")
    {
        courtSelected();
        teamSelectionMenu(render);
        
    }
}

