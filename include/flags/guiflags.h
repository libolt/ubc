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

#ifndef _GUIFLAGS_H_
#define _GUIFLAGS_H_

class guiFlags
{
    public:

        guiFlags();  // constructor
        ~guiFlags();  // destructor

        bool getSetupComplete() const;  // retrieves the value of setupComplete
        void setSetupComplete(const bool &set);  // sets the value of setupComplete

        bool getBackButtonsCreated() const;  // retrieves the value of backButtonsCreated
        void setBackButtonsCreated(const bool &set);  // sets the value of backButtonsCreated

        bool getMainMenuCreated() const;  // retrieves the value of mainMenuCreated
        void setMainMenuCreated(const bool &set);  // sets the value of mainMenuCreated

        bool getNetworkSetupMenuCreated() const;  // retrieves the value of networkSetupMenuCreated
        void setNetworkSetupMenuCreated(const bool &set);  // sets the value of networkSetupMenuCreated

        bool getNetworkClientSetupMenuCreated() const;  // retrieves the value of networkClientSetupMenuCreated
        void setNetworkClientSetupMenuCreated(const bool &set);  // sets the value of networkClientSetupMenuCreated

        bool getNetworkServerSetupMenuCreated() const ;  // retrieves the value of networkServerSetupMenuCreated
        void setNetworkServerSetupMenuCreated(const bool &set);  // sets the value of networkServerSetupMenuCreated

        bool getOptionsMenuCreated() const;  // retrieves the value of optionsMenuCreated
        void setOptionsMenuCreated(const bool &set);  // sets the value of optionsMenuCreated

        bool getAudioSetupMenuCreated() const;  // retrieves the value of audioSettingsMenuCreated
        void setAudioSetupMenuCreated(const bool &set);  // sets the value of audioSettingsMenuCreated

        bool getDisplaySetupMenuCreated() const;  // retrieves the value of displaySettingsMenuCreated
        void setDisplaySetupMenuCreated(const bool &set);  // sets the value of displaySettingsMenuCreated

        bool getInputSetupMenuCreated() const;  // retrieves the value of inputSettingsMenuCreated
        void setInputSetupMenuCreated(const bool &set);  // sets the value of inputSettingsMenuCreated

        bool getSetupMenuCreated() const;  // retrieves the value of setupMenuCreated
        void setSetupMenuCreated(const bool &set);  // sets the value of setupMenuCreated

        bool getPlayerStartSelectionMenuCreated() const;  // retrieves the value of playerStartSelectionMenuCreated
        void setPlayerStartSelectionMenuCreated(const bool &set);  // sets the value of playerStartSelectionMenuCreated

        bool getTeamSelectionMenuCreated() const;  // retrieves the value of teamSelectionMenuCreated
        void setTeamSelectionMenuCreated(const bool &set);  // sets the value of teamSelectionMenuCreated

        bool getTeamSelectionMenuDataAdded() const;  // retrieves the value of teamSelectionMenuDataAdded
        void setTeamSelectionMenuDataAdded(const bool &set);  // sets the value of teamSelectionDataAdded

        bool getCourtSelectionMenuCreated() const;  // retrieves the value of courtSelectionMenuCreated
        void setCourtSelectionMenuCreated(const bool &set);  // sets the value of courtSelectionMenuCreated

        bool getCourtSelectionDataLoaded() const;  // retrieves the value of courtSelectionEntriesLoaded
        void setCourtSelectionDataLoaded(const bool &set);  // sets the value of courtSelectionEntriesLoaded

        bool getMenuActive() const;  // retrieves the value of menuActive
        void setMenuActive(const bool &set);  // sets the value of menuActive

        bool getSetupMenuAwaySelected() const;  // retrieves the value of setupMenuAwaySelected
        void setSetupMenuAwaySelected(const bool &set);  // sets the value of setupMenuAwaySelected

        bool getSetupMenuHomeSelected() const;  // retrieves the value of setupMenuHomeSelected
        void setSetupMenuHomeSelected(const bool &set);  // sets the value of setupMenuHomeSelected

        bool getStartActiveGame() const;  // retrieves the value of startActiveGame
        void setStartActiveGame(const bool &set);  // sets the value of startActiveGame

        bool getChangeMenu() const;  // retrieves the value of changeMenu
        void setChangeMenu(const bool &set);  // sets the value of changeMenu
  
    private:

        bool setupComplete;  // determinrs if the gui has been properly setup.
        bool mainMenuCreated;   // determines whether the main menu gui has been created
        bool backButtonsCreated;  // determines whether the back buttons have been created
        bool networkSetupMenuCreated;   // determines whether the network setup gui has been created
        bool networkServerSetupMenuCreated;   // determines whether the network server setup gui has been created
        bool networkClientSetupMenuCreated;   // determines whether the network client setup gui has been created
        bool optionsMenuCreated;   // determines whether the options menu gui has been created
        bool displaySetupMenuCreated;   // determines whether the display settings menu gui has been created
        bool inputSetupMenuCreated;   // determines whether the input settings menu gui has been created
        bool audioSetupMenuCreated;   // determines whether the audio settings menu gui has been created
        bool setupMenuCreated;  // determines whether the game setup menu gui has been created
        bool playerStartSelectionMenuCreated;  // determines whether the player start selection menu gui has been created
        bool teamSelectionMenuCreated;  // determines whether the team selection menu gui has been created
        bool teamSelectionMenuDataAdded;  // determines whether teeam data has been added to the the team selection menu
        bool courtSelectionMenuCreated;  // deteemines whether the court selection menu has been created;
        bool menuActive;  // stores whether a menu is being diplayed
        bool setupMenuAwaySelected;  // determines whether the away team listbox is selected;
        bool setupMenuHomeSelected;  // determines whether the home team listbox is selected;
        bool courtSelectionDataLoaded;  // determines whether court names have been added to the select box

        bool startActiveGame;  // dtermines whetehr or not to start the active game
        bool changeMenu;  // stores whether to change the menu
};

#endif // GUIFLAGS_H
