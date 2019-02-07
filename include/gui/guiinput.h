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

#include "utilities/typedefs.h"

class guiInput
{
    public:
        guiInput();  // constructor
        ~guiInput();  // destructor

        guiComponentsSharedPtr getComponent() const;  // retrieves the value of component
        void setComponent(const guiComponentsSharedPtr &set);  // sets the value of component

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
        void backNetworkSetupButtonClicked(MyGUI::Widget *_sender);  // handles backNetworkSetupButton click event

        
    private:
    
        guiComponentsSharedPtr component;  // stores gui related components
    
        guiFlagsSharedPtr flag;  // stores gui related flags

        gameEntitySharedPtr gameInstance;  // stores a copy of the gameInstance

};

#endif
