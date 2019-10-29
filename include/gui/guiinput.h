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

#ifndef _GUIINPUT_H_
#define _GUIINPUT_H_

//#ifdef BTOGRE_MYGUI_ENABLED

#include "utilities/typedefs.h"

class guiInput
{
    public:
        guiInput();  // constructor
        ~guiInput();  // destructor

        guiComponentsSharedPtr getComponent() const;  // retrieves the value of component
        void setComponent(const guiComponentsSharedPtr &set);  // sets the value of component

        guiEventsSharedPtr getEvent() const;  // retrieves the value of event
        void setEvent(const guiEventsSharedPtr &set);  // sets the value of event

        guiFlagsSharedPtr getFlag() const;  // retrieves the value of flag
        void setFlag(const guiFlagsSharedPtr &set);  // sets the value of flag

        gameEntitySharedPtr getGameInstance() const;  // retrieves the value of teamInstance
        void setGameInstance(const gameEntitySharedPtr &set);  // sets the value of teamInstance

        void startSingleGameButtonClicked(MyGUI::Widget *_sender);  // handles startSingleGameButton click event
        void startMultiGameButtonClicked(MyGUI::Widget *_sender);  // hands startMultiGameButton click event
        void optionsButtonClicked(MyGUI::Widget *_sender);  // handles optionsButton click event
        void exitButtonClicked(MyGUI::Widget *_sender);  // handles exitButton click event
        void courtSelectButtonClicked(MyGUI::Widget *_sender);  // handles courtSelectButton click event
        void backCourtMainMenuButtonClicked(MyGUI::Widget *_sender);  // handles backCourtMainMenuButton click event
        void backNetworkMainMenuButtonClicked(MyGUI::Widget *_sender);  // handles backNetworkMainMenuButton click event
        void backOptionsMainMenuButtonClicked(MyGUI::Widget *_sender);  // handles backOptoinsMainMenuButton click event
        void backTeamMainMenuButtonClicked(MyGUI::Widget *_sender);  // handles backTeamMainMenuButton click event
        void team0SelectButtonClicked(MyGUI::Widget *_sender);  // handles team0SelectButton click event
        void team1SelectButtonClicked(MyGUI::Widget *_sender);  // handles team1SelectButton click event
        void teamsSelectedButtonClicked(MyGUI::Widget *_sender);  // handles teamsSelectedButton click event
        void backCourtSelectionMenuButtonClicked(MyGUI::Widget *_sender);  // handles backCourtSelectionMenuButton click event
        void team0StartingLineupSetButtonClicked(MyGUI::Widget *_sender);  // handles team0StartingLineupSetButton click event
        void team1StartingLineupSetButtonClicked(MyGUI::Widget *_sender);  // handles team1StartingLineupSetButton click event
        void startingLineupSetButtonClicked(MyGUI::Widget *_sender);  // handles startingLineupSetButton click event
        void backStartersTeamSelectionMenuButtonClicked(MyGUI::Widget *_sender);  // handles backPlayerStartSelectionMenuButton click event
        void serverButtonClicked(MyGUI::Widget *_sender);  // handles serverButton click event
        void clientButtonClicked(MyGUI::Widget *_sender);  // handles clientButton click event
        void serverHostButtonClicked(MyGUI::Widget *_sender);  // handles hostGameButton click event
        void clientConnectButtonClicked(MyGUI::Widget *_sender);  // handles connectButton click event
        void backNetClientNetworkSetupButtonClicked(MyGUI::Widget *_sender);  // handles backNetClientNetworkSetupButton click event
        void backNetServerNetworkSetupButtonClicked(MyGUI::Widget *_sender);  // handles backNetServerNetworkSetupButton click event
        void backAudioOptionsMenuButtonClicked(MyGUI::Widget *_sender);  // handles backOptionsMenuButton click event
        void backDisplayOptionsMenuButtonClicked(MyGUI::Widget *_sender);  // handles backOptionsMenuButton click event
        void backInputOptionsMenuButtonClicked(MyGUI::Widget *_sender);  // handles backOptionsMenuButton click event
        void displayButtonClicked(MyGUI::Widget *_sender);  // handles didplayButton click event
        void inputButtonClicked(MyGUI::Widget *_sender);  // handles inputButton click event
        void audioButtonClicked(MyGUI::Widget *_sender);  // handles audioButton click event
        void changeResolutionButtonClicked(MyGUI::Widget *_sender);  // handles changeResolutionButton click event
        void enableAudioButtonClicked(MyGUI::Widget *_sender);  // handles eneableAudioButton click event
        void disableAudioButtonClicked(MyGUI::Widget *_sender);  // handles eneableAudioButton click event
        void changeInputTypeButtonClicked(MyGUI::Widget *_sender);  // handles changeInputTypeButton click event
        void backNetworkClientButtonClicked(MyGUI::Widget *_sender);  // handles backNetworkClientButton click event
        void backPlayerStartSelectionMenuButtonClicked(MyGUI::Widget *_sender);  // handles backPlayerStartSelectionMenuButton click event
//        void backSetupMenuButtonClicked(MyGUI::Widget *_sender);  // handles backSetupMenuButton click event

        void menuReceiveKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // processes key input
        void processMainMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // processes main menu key input
        void processNetworkMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // processes network menu key input
        void processNetworkServerMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // process network server menu key input
        void processNetworkClientMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // process network client menu key input
        void processOptionsMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // processes options menu key input
        void processDisplayMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // processes display settings menu key input
        void processInputMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // processes input settings menu key input
        void processAudioMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // processes audio settings menu key input
    //    void processSetupMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // processes game setup menu key input
        void processPlayerStartSelectionMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // process player start selection menu key input
        void processTeamSelectionMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // process team selection menu key input
        void processCourtSelectionMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // process court selection menu key input

    private:
    
        guiComponentsSharedPtr component;  // stores gui related components
    
        guiEventsSharedPtr event;  // stores gui related events

        guiFlagsSharedPtr flag;  // stores gui related flags

        gameEntitySharedPtr gameInstance;  // stores a copy of the gameInstance

};
//#endif

#endif
