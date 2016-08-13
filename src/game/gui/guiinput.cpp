/***************************************************************************
 *   .opyright (C) 1999 - 2015 by Mike McLean                              *
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

#include "gui/gui.h"
#include "data/courtdata.h"
#include "engine/gameengine.h"
#include "state/gamestate.h"
#include "load.h"   
#include "logging.h"
#include "engine/renderengine.h"
#include "data/teamdata.h"
#include "conversion.h"

#ifdef __ANDROID__
#include "android-config.h"
#else
#include "config.h"
#endif

// static variables/functions
//void GUISystem::startSingleGameButtonClicked(MyGUI::Widget *_sender);

void GUISystem::startSingleGameButtonClicked(MyGUI::Widget *_sender)  // handles startSingleGameButton click event
{
    startSinglePlayerGame();
}

void GUISystem::startMultiGameButtonClicked(MyGUI::Widget *_sender)  // handles startMultiGameButton click event
{
    startMultiPlayerGame();
}

void GUISystem::optionsButtonClicked(MyGUI::Widget *_sender)  // handles optionsButton click event
{
    optionsMenu();

}
void GUISystem::exitButtonClicked(MyGUI::Widget *_sender)  // handles exitButton click event
{
    exit(0);
}

void GUISystem::serverButtonClicked(MyGUI::Widget *_sender)  // handles serverButton click event
{
    networkServerSetupMenu();
}

void GUISystem::clientButtonClicked(MyGUI::Widget *_sender)  // handles clientButton click event
{
    networkClientSetupMenu();
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
    backMainMenuSelected();
}

void GUISystem::backNetworkSetupButtonClicked(MyGUI::Widget *_sender)  // handles backNetworkSetupButton click event
{
    backNetworkSetupMenuSelected();
}

void GUISystem::displayButtonClicked(MyGUI::Widget *_sender)  // handles didplayButton click event
{

}

void GUISystem::inputButtonClicked(MyGUI::Widget *_sender)  // handles inputButton click event
{
    inputMenu();
}

void GUISystem::audioButtonClicked(MyGUI::Widget *_sender)  // handles audioButton click event
{
    audioMenu();
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
    gameSetupHomeSelected();
}

void GUISystem::team1SelectButtonClicked(MyGUI::Widget *_sender)  // handles team1SelectButton click event
{
    gameSetupAwaySelected();
}

void GUISystem::teamsSelectedButtonClicked(MyGUI::Widget *_sender)  // handles teamsSelectButton click event
{
    teamsSelected();
    playerStartSelectionMenu();

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
//    exit(0);
}

void GUISystem::backNetworkClientButtonClicked(MyGUI::Widget *_sender)  // handles backNetworkClientButton click event
{
    networkClientSetupMenu();
}

void GUISystem::backOptionsMenuButtonClicked(MyGUI::Widget *_sender)  // handles backOptionsMenuButton click event
{
    optionsMenu();
}

void GUISystem::backPlayerStartSelectionMenuButtonClicked(MyGUI::Widget *_sender)  // handles backPlayerStartSelectionMenuButton click event
{

}

void GUISystem::backTeamSelectionMenuButtonClicked(MyGUI::Widget *_sender)  // handles backTeamSelectionMenuButton click event
{
    teamSelectionMenu();
}

void GUISystem::backCourtSelectionMenuButtonClicked(MyGUI::Widget *_sender)  // handles backCourtSelectionMenuButton click event
{
    courtSelectionMenu();
}

void GUISystem::backGameSetupMenuButtonClicked(MyGUI::Widget *_sender)  // handles backGameSetupMenuButton click event
{
    gameSetupMenu();
}

void GUISystem::courtSelectButtonClicked(MyGUI::Widget *_sender)  // handles courtSelectButton click event
{
     courtSelected();
}


void GUISystem::menuReceiveKeyPress(std::string keyPressed)  // processes key input
{
    boost::shared_ptr<conversion> convert = conversion::Instance();

    logMsg("menuReceiveKeyKeyPress!");
    logMsg("activeMenu == " +convert->toString(activeMenu));
    logMsg("keyPressed == " +keyPressed);
//    exit(0);
    if (keyPressed != "")
    {
        switch (activeMenu)
        {
            case MAIN:
                processMainMenuKeyPress(keyPressed);
                break;
            case NETWORK:
                processNetworkMenuKeyPress(keyPressed);
                break;
            case NETWORKSERVER:
                processNetworkServerMenuKeyPress(keyPressed);
                break;
            case NETWORKCLIENT:
                processNetworkClientMenuKeyPress(keyPressed);
                break;
            case OPTIONS:
                processOptionsMenuKeyPress(keyPressed);
                break;
            case DISPLAY:
                processDisplayMenuKeyPress(keyPressed);
                break;
            case INPUTMENU:
                processInputMenuKeyPress(keyPressed);
                break;
            case AUDIO:
                processAudioMenuKeyPress(keyPressed);
                break;
            case GAMESETUP:
                processGameSetupMenuKeyPress(keyPressed);
                break;
            case PLAYERSTART:
                processPlayerStartSelectionMenuKeyPress(keyPressed);
                break;
            case TEAMSELECT:
                processTeamSelectionMenuKeyPress(keyPressed);
    //            exit(0);
                break;
            case COURTSELECT:
                processCourtSelectionMenuKeyPress(keyPressed);
                break;
            default:
                break;
        }
    }
}

void GUISystem::processMainMenuKeyPress(std::string keyPressed)  // processes main menu key input
{
//    exit(0);
    if (keyPressed == "s")
    {
        startSinglePlayerGame();
    }
    else if (keyPressed == "m")
    {
        startMultiPlayerGame();
    }
    else if (keyPressed == "o")
    {
        optionsMenu();
    }
    else if (keyPressed == "e")
    {
        exit(0);
    }
    else
    {

    }
}
void GUISystem::processNetworkMenuKeyPress(std::string keyPressed)  // processes network menu key input
{
   if (keyPressed == "c")
    {
       networkClientSetupMenu();
    }
    else if (keyPressed == "b")
    {
        backMainMenuSelected();
    }
    else if (keyPressed == "s")
    {
        networkServerSetupMenu();
    }
    else
    {

    }
}

void GUISystem::processNetworkServerMenuKeyPress(std::string keyPressed)  // process network server menu key input
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
        startMultiPlayerGame();
    }
}

void GUISystem::processNetworkClientMenuKeyPress(std::string keyPressed)  // processes network menu key input
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
        startMultiPlayerGame();
    }

}

void GUISystem::processOptionsMenuKeyPress(std::string keyPressed)  // processes options menu key input
{
    if (keyPressed == "d")
    {
       displayMenu();
    }
    else if (keyPressed == "b")
    {
        backMainMenuSelected();
    }
    else if (keyPressed == "i")
    {
        inputMenu();
    }
    else if (keyPressed == "a")
    {
        audioMenu();
    }
    else
    {

    }
}

void GUISystem::processDisplayMenuKeyPress(std::string keyPressed)  // processes display settings menu key input
{

    if (keyPressed == "c")
    {
        // placeholder
    }
    else if (keyPressed == "b")
    {
        optionsMenu();
    }

}

void GUISystem::processInputMenuKeyPress(std::string keyPressed) // processes input settings menu key input
{
    if (keyPressed == "c")
    {
        // placeholder
    }
    else if (keyPressed == "b")
    {
        optionsMenu();
    }
}

void GUISystem::processAudioMenuKeyPress(std::string keyPressed)  // processes audio settings menu key input
{
    if (keyPressed == "c")
    {
        // placeholder
    }
    else if (keyPressed == "b")
    {
        optionsMenu();
    }
}

void GUISystem::processGameSetupMenuKeyPress(std::string keyPressed)  // processes game setup menu key input
{
    //gameState *gameS = gameState::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
//    std::vector<boost::shared_ptr<teamState> > teamInstance = gameS->getTeamInstance();
    logMsg("processGameSetupMenuKeyPress");
    if (keyPressed == "a" && !gameSetupMenuAwaySelected)
    {
        gameSetupAwaySelected();
    }
    else if (keyPressed == "h" && !gameSetupMenuHomeSelected)
    {
        gameSetupHomeSelected();
    }
    else if (keyPressed == "b")
    {
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
    }
    // FIXME!
    else if (keyPressed == "l")
    {
//        exit(0);
        logMsg("yarp");
        teamsSelected();
        playerStartSelectionMenu();
    }
    else if (keyPressed == "x")
    {
        if (gameSetupMenuAwaySelected)
        {
            int x = team1SelectBox->getIndexSelected() +1;
            if (x < getGameS()->getTeamInstance().size())
            {
                team1SelectBox->setIndexSelected(x);
                team1SelectBox->beginToItemAt(x);
            }
            else
            {
                team1SelectBox->setIndexSelected(0);
                team1SelectBox->beginToItemAt(0);
            }
        }
        else if (gameSetupMenuHomeSelected)
        {
            int x = team0SelectBox->getIndexSelected() +1;
            if (x < getGameS()->getTeamInstance().size())
            {
                team0SelectBox->setIndexSelected(x);
                team0SelectBox->beginToItemAt(x);
            }
            else
            {
                team0SelectBox->setIndexSelected(0);
                team0SelectBox->beginToItemAt(0);
            }
        }
        else
        {

        }
    }
    else if (keyPressed == "z")
    {
        if (gameSetupMenuAwaySelected)
        {
            int x = team1SelectBox->getIndexSelected() -1;
            if (x < 0)
            {
                team1SelectBox->setIndexSelected(getGameS()->getTeamInstance().size() -1);
                team1SelectBox->beginToItemAt(getGameS()->getTeamInstance().size() -1);
            }
            else
            {
                //exit(0);
                team1SelectBox->setIndexSelected(x);
                team1SelectBox->beginToItemAt(x);
            }
        }
        else if (gameSetupMenuHomeSelected)
        {
            int x = team0SelectBox->getIndexSelected() -1;
            if (x < 0)
            {
                team0SelectBox->setIndexSelected(getGameS()->getTeamInstance().size() -1);
                team0SelectBox->beginToItemAt(getGameS()->getTeamInstance().size() -1);
            }
            else
            {
                team0SelectBox->setIndexSelected(x);
                team0SelectBox->beginToItemAt(x);
            }
        }
        else
        {

        }
    }
}

void GUISystem::processPlayerStartSelectionMenuKeyPress(std::string keyPressed)  // process player start selection menu key input
{

    //gameState *gameS = gameState::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<loader> load = loader::Instance();

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
    }
    else if (keyPressed == "b")
    {
        teamSelectionMenu();
    }

//    exit(0);
}

void GUISystem::processTeamSelectionMenuKeyPress(std::string keyPressed)  // process team selection menu key input
{
    //gameState *gameS = gameState::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
    
//    std::vector<boost::shared_ptr<teamState> > teamInstance = gameS->getTeamInstance();
    logMsg("processGameSetupMenuKeyPress");
    if (keyPressed == "a" && !gameSetupMenuAwaySelected)
    {
        gameSetupAwaySelected();
    }
    else if (keyPressed == "h" && !gameSetupMenuHomeSelected)
    {
        gameSetupHomeSelected();
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
        courtSelectionMenu();
    }
    else if (keyPressed == "t")
    {
        logMsg("yarp");
        teamsSelected();
        playerStartSelectionMenu();
//        exit(0);
    }
    else if (keyPressed == "x")
    {
        if (gameSetupMenuAwaySelected)
        {
            int x = team1SelectBox->getIndexSelected() +1;
            if (x < getGameS()->getTeamInstance().size())
            {
                team1SelectBox->setIndexSelected(x);
                team1SelectBox->beginToItemAt(x);
            }
            else
            {
                team1SelectBox->setIndexSelected(0);
                team1SelectBox->beginToItemAt(0);
            }
        }
        else if (gameSetupMenuHomeSelected)
        {
            int x = team0SelectBox->getIndexSelected() +1;
            if (x < getGameS()->getTeamInstance().size())
            {
                team0SelectBox->setIndexSelected(x);
                team0SelectBox->beginToItemAt(x);
            }
            else
            {
                team0SelectBox->setIndexSelected(0);
                team0SelectBox->beginToItemAt(0);
            }
        }
        else
        {

        }
    }
    else if (keyPressed == "z")
    {
        if (gameSetupMenuAwaySelected)
        {
            int x = team1SelectBox->getIndexSelected() -1;
            if (x < 0)
            {
                team1SelectBox->setIndexSelected(getGameS()->getTeamInstance().size() -1);
                team1SelectBox->beginToItemAt(getGameS()->getTeamInstance().size() -1);
            }
            else
            {
                //exit(0);
                team1SelectBox->setIndexSelected(x);
                team1SelectBox->beginToItemAt(x);
            }
        }
        else if (gameSetupMenuHomeSelected)
        {
            int x = team0SelectBox->getIndexSelected() -1;
            if (x < 0)
            {
                team0SelectBox->setIndexSelected(getGameS()->getTeamInstance().size() -1);
                team0SelectBox->beginToItemAt(getGameS()->getTeamInstance().size() -1);
            }
            else
            {
                team0SelectBox->setIndexSelected(x);
                team0SelectBox->beginToItemAt(x);
            }
        }
        else
        {

        }
    }

}

void GUISystem::processCourtSelectionMenuKeyPress(std::string keyPressed)  // process court selection menu key input
{
//    exit(0);
    //gameState *gameS = gameState::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();

    if (keyPressed == "b")
    {
        backMainMenuSelected();
    }
    else if (keyPressed == "q")
    {
        exit(0);
    }
    else if (keyPressed == "s")
    {
        courtSelected();
        
    }
}

