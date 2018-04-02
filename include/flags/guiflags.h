/***************************************************************************
 *   Copyright (C) 1999 - 2018 by Mike McLean                              *
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

        bool getSetupComplete();  // retrieves the value of setupComplete
        void setSetupComplete(bool set);  // sets the value of setupComplete

        bool getMainMenuCreated();   // retrieves the value of mainMenuCreated
        void setMainMenuCreated(bool set); // sets the value of mainMenuCreated

        bool getBackButtonsCreated(); // retrieves the value of backButtonsCreated
        void setBackButtonsCreated(bool set); // sets the value of backButtonsCreated

        bool getNetworkSetupMenuCreated();  // retrieves the value of networkSetupMenuCreated
        void setNetworkSetupMenuCreated(bool set);  // sets the value of networkSetupMenuCreated

        bool getNetworkClientSetupMenuCreated();  // retrieves the value of networkClientSetupMenuCreated
        void setNetworkClientSetupMenuCreated(bool set);  // sets the value of networkClientSetupMenuCreated

        bool getNetworkServerSetupMenuCreated();  // retrieves the value of networkServerSetupMenuCreated
        void setNetworkServerSetupMenuCreated(bool set);  // sets the value of networkServerSetupMenuCreated

        bool getOptionsMenuCreated();  // retrieves the value of optionsMenuCreated
        void setOptionsMenuCreated(bool set);  // sets the value of optionsMenuCreated

        bool getAudioSetupMenuCreated();  // retrieves the value of audioSettingsMenuCreated
        void setAudioSetupMenuCreated(bool set);  // sets the value of audioSettingsMenuCreated

        bool getDisplaySetupMenuCreated();  // retrieves the value of displaySettingsMenuCreated
        void setDisplaySetupMenuCreated(bool set);  // sets the value of displaySettingsMenuCreated

        bool getInputSetupMenuCreated();  // retrieves the value of inputSettingsMenuCreated
        void setInputSetupMenuCreated(bool set);  // sets the value of inputSettingsMenuCreated


        bool getSetupMenuCreated();  // retrieves the value of setupMenuCreated
        void setSetupMenuCreated(bool set);  // sets the value of setupMenuCreated

        bool getPlayerStartSelectionMenuCreated();  // retrieves the value of playerStartSelectionMenuCreated
        void setPlayerStartSelectionMenuCreated(bool set);  // sets the value of playerStartSelectionMenuCreated

        bool getTeamSelectionMenuCreated();  // retrieves the value of teamSelectionMenuCreated
        void setTeamSelectionMenuCreated(bool set);  // sets the value of teamSelectionMenuCreated

        bool getTeamSelectionMenuDataAdded();  // retrieves the value of teamSelectionMenuDataAdded
        void setTeamSelectionMenuDataAdded(bool set);  // sets the value of teamSelectionDataAdded

        bool getCourtSelectionMenuCreated();  // retrieves the value of courtSelectionMenuCreated
        void setCourtSelectionMenuCreated(bool set);  // sets the value of courtSelectionMenuCreated

        bool getCourtSelectionDataLoaded();  // retrieves the value of courtSelectionEntriesLoaded
        void setCourtSelectionDataLoaded(bool set);  // sets the value of courtSelectionEntriesLoaded

        bool getMenuActive();  // retrieves the value of menuActive
        void setMenuActive(bool set);  // sets the value of menuActive

        bool getSetupMenuAwaySelected();  // retrieves the value of setupMenuAwaySelected
        void setSetupMenuAwaySelected(bool set);  // sets the value of setupMenuAwaySelected

        bool getSetupMenuHomeSelected();  // retrieves the value of setupMenuHomeSelected
        void setSetupMenuHomeSelected(bool set);  // sets the value of setupMenuHomeSelected

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


};

#endif // GUIFLAGS_H
