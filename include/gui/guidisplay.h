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

#ifndef _GUIDISPLAY_H_
#define _GUIDISPLAY_H_

#include "utilities/typedefs.h"

class guiDisplay
{
    public:
        guiDisplay();  // constructor
        ~guiDisplay();  // destructor

        guiComponentsSharedPtr getComponent() const;  // retrieves the value of component
        void setComponent(const guiComponentsSharedPtr &set);  // sets the value of component

        guiFlagsSharedPtr getFlag() const;  // retrieves the value of flag
        void setFlag(const guiFlagsSharedPtr &set);  // sets the value of flag

        gameEngineSharedPtr getGamE() const;  // retrieves the value of gameE
        void setGameE(const gameEngineSharedPtr &set);  // sets the value of gameE

        void hideMainMenuWidgets();	 // hides all widgets tied to the Main Menu
        void showMainMenuWidgets();  // shows all widgets tied to the Main Menu

        void hideNetworkSetupWidgets();  // hides all widgets tied to the Network Setup Menu
        void showNetworkSetupWidgets();  // shows all widgets tied to the Network Setup Menu

        void hideNetworkServerSetupWidgets();  // hides all widgets tied to the Network Server Setup Menu
        void showNetworkServerSetupWidgets();  // shows all widgets tied to the Network Server Setup Menu

        void hideNetworkClientSetupWidgets();  // hides all widgets tied to the Network Client Setup Menu
        void showNetworkClientSetupWidgets();  // shows all widgets tied to the Network Client Setup Menu

        void hideOptionsMenuWidgets();	// hides all widgets tied to the Options Menu
        void showOptionsMenuWidgets();  // shows all widgets tied to the Options Menu

        void hideDisplayMenuWidgets();	// hides all widgets tied to the Display Menu
        void showDisplayMenuWidgets();  // shows all widgets tied to the Display Menu

        void hideInputMenuWidgets();  // hides all widgets tied to the Input Menu
        void showInputMenuWidgets();  // shows all widgets tied to the Input Menu

        void hideAudioMenuWidgets();  // hides all widgets tied to the Audio Menu
        void showAudioMenuWidgets();  // shows all widgets tied to the Audio Menu

        void hideSetupMenuWidgets();  // hides all widgets tied to the Game Setup Menu
        void showSetupMenuWidgets();  // shows all widgets tied to the Game Setup Menu

        void hidePlayerStartSelectionMenuWidgets();  // hides all widgets tied to the Player Start Selection Menu
        void showPlayerStartSelectionMenuWidgets(const renderEngineSharedPtr &render);  // shows all widgets tied to the Player Start Selection Menu

        void hideTeamSelectionMenuWidgets(); // hides all widgets tied to the Team Selection Menu
        void showTeamSelectionMenuWidgets(const renderEngineSharedPtr &render);  // show all widgets tied to the Team Selection Menu

        void hideCourtSelectionMenuWidgets(); // hides all widgets tied to the Court Selection Menu
        void showCourtSelectionMenuWidgets(const renderEngineSharedPtr &render); // show all widgets tied to the Court Selection Menu

        void hideActiveMenuWidgets();  // hides active menus widgets
        void showActiveMenuWidgets(const renderEngineSharedPtr &render);  // shows active menus widgets

        void changeActiveMenu(activeMenus menu, const renderEngineSharedPtr &render);  // changes the actively displayed menu

    private:

        guiComponentsSharedPtr component;  // stores gui related components

        guiFlagsSharedPtr flag;  // stores gui related flags

        gameEngineSharedPtr gameE; // stores a copy of gameE

        size_t displayCount;

};

#endif  // _GUIDISPLAY_H_
