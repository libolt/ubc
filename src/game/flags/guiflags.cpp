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

#ifdef BTOGRE_MYGUI_ENABLED

#include "flags/guiflags.h"

guiFlags::guiFlags()
{
    setupComplete = false;
    mainMenuCreated = false;
    backButtonsCreated = false;
    networkSetupMenuCreated = false;
    networkServerSetupMenuCreated = false;
    networkClientSetupMenuCreated = false;
    optionsMenuCreated = false;
    displaySetupMenuCreated = false;
    inputSetupMenuCreated = false;
    audioSetupMenuCreated = false;
    setupMenuCreated = false;
    setupMenuAwaySelected = false;
    setupMenuHomeSelected = false;
    playerStartSelectionMenuCreated = false;
    teamSelectionMenuCreated = false;
    teamSelectionMenuDataAdded = false;
    courtSelectionMenuCreated = false;
    courtSelectionDataLoaded = false;
    menuActive = false;
    startActiveGame = false;
    changeMenu = false;
}

guiFlags::~guiFlags()  = default;  // destructor

bool guiFlags::getMenuActive() const  // retrieves the value of menuActive
{
    return (menuActive);
}
void guiFlags::setMenuActive(const bool &set)  // sets the value of menuActive
{
    menuActive = set;
}

bool guiFlags::getSetupComplete() const  // retrieves the value of setupComplete
{
    return (setupComplete);
}
void guiFlags::setSetupComplete(const bool &set)  // sets the value of setupComplete
{
    setupComplete = set;
}

bool guiFlags::getMainMenuCreated() const  // retrieves the value of mainMenuCreated
{
    return (mainMenuCreated);
}
void guiFlags::setMainMenuCreated(const bool &set)  // sets the value of mainMenuCreated
{
    mainMenuCreated = set;
}

bool guiFlags::getBackButtonsCreated() const  // retrieves the value of backButtonsCreated
{
    return (backButtonsCreated);
}
void guiFlags::setBackButtonsCreated(const bool &set)  // sets the value of backButtonsCreated
{
    backButtonsCreated = set;
}

bool guiFlags::getNetworkSetupMenuCreated() const  // retrieves the value of networkSetupMenuCreated
{
    return (networkSetupMenuCreated);
}
void guiFlags::setNetworkSetupMenuCreated(const bool &set)  // sets the value of networkSetupMenuCreated
{
    networkSetupMenuCreated = set;
}

bool guiFlags::getNetworkClientSetupMenuCreated() const  // retrieves the value of networkClientSetupMenuCreated
{
    return (networkClientSetupMenuCreated);
}
void guiFlags::setNetworkClientSetupMenuCreated(const bool &set)  // sets the value of networkClientSetupMenuCreated
{
    networkClientSetupMenuCreated = set;
}

bool guiFlags::getNetworkServerSetupMenuCreated() const  // retrieves the value of networkServerSetupMenuCreated
{
    return (networkServerSetupMenuCreated);
}
void guiFlags::setNetworkServerSetupMenuCreated(const bool &set)  // sets the value of networkServerSetupMenuCreated
{
    networkServerSetupMenuCreated = set;
}

bool guiFlags::getOptionsMenuCreated() const  // retrieves the value of optionsMenuCreated
{
    return (optionsMenuCreated);
}
void guiFlags::setOptionsMenuCreated(const bool &set)  // sets the value of optionsMenuCreated
{
    optionsMenuCreated = set;
}

bool guiFlags::getAudioSetupMenuCreated() const  // retrieves the value of audioSetupMenuCreated
{
    return (audioSetupMenuCreated);
}
void guiFlags::setAudioSetupMenuCreated(const bool &set)  // sets the value of audioSetupMenuCreated
{
    audioSetupMenuCreated = set;
}

bool guiFlags::getDisplaySetupMenuCreated() const  // retrieves the value of displaySettingsMenuCreated
{
    return (displaySetupMenuCreated);
}
void guiFlags::setDisplaySetupMenuCreated(const bool &set)  // sets the value of displaySettingsMenuCreated
{
    displaySetupMenuCreated = set;
}

bool guiFlags::getInputSetupMenuCreated() const  // retrieves the value of inputSettingsMenuCreated
{
    return (inputSetupMenuCreated);
}
void guiFlags::setInputSetupMenuCreated(const bool &set)  // sets the value of inputSettingsMenuCreated
{
    inputSetupMenuCreated = set;
}


bool guiFlags::getSetupMenuCreated() const  // retrieves the value of setupMenuCreated
{
    return (setupMenuCreated);
}
void guiFlags::setSetupMenuCreated(const bool &set)  // sets the value of setupMenuCreated
{
    setupMenuCreated = set;
}

bool guiFlags::getPlayerStartSelectionMenuCreated() const  // retrieves the value of playerStartSelectionMenuCreated
{
    return (playerStartSelectionMenuCreated);
}
void guiFlags::setPlayerStartSelectionMenuCreated(const bool &set)  // sets the value of playerStartSelectionMenuCreated
{
    playerStartSelectionMenuCreated = set;
}

bool guiFlags::getTeamSelectionMenuCreated() const  // retrieves the value of teamSelectionMenuCreated
{
    return (teamSelectionMenuCreated);
}
void guiFlags::setTeamSelectionMenuCreated(const bool &set)  // sets the value of teamSelectionMenuCreated
{
    teamSelectionMenuCreated = set;
}

bool guiFlags::getTeamSelectionMenuDataAdded() const  // retrieves the value of teamSelectionMenuDataAdded
{
    return (teamSelectionMenuDataAdded);
}
void guiFlags::setTeamSelectionMenuDataAdded(const bool &set)  // sets the value of teamSelectionDataAdded
{
    teamSelectionMenuDataAdded = set;
}

bool guiFlags::getCourtSelectionMenuCreated() const  // retrieves the value of courtSelectionMenuCreated
{
    return (courtSelectionMenuCreated);
}
void guiFlags::setCourtSelectionMenuCreated(const bool &set)  // sets the value of courtSelectionMenuCreated
{
    courtSelectionMenuCreated = set;
}

bool guiFlags::getCourtSelectionDataLoaded() const  // retrieves the value of courtSelectionEntriesLoaded
{
    return (courtSelectionDataLoaded);
}
void guiFlags::setCourtSelectionDataLoaded(const bool &set)  // sets the value of courtSelectionEntriesLoaded
{
    courtSelectionDataLoaded = set;
}

bool guiFlags::getSetupMenuAwaySelected() const  // retrieves the value of setupMenuAwaySelected
{
    return (setupMenuAwaySelected);
}
void guiFlags::setSetupMenuAwaySelected(const bool &set)  // sets the value of setupMenuAwaySelected
{
    setupMenuAwaySelected = set;
}

bool guiFlags::getSetupMenuHomeSelected() const  // retrieves the value of setupMenuHomeSelected
{
    return (setupMenuHomeSelected);
}
void guiFlags::setSetupMenuHomeSelected(const bool &set)  // sets the value of setupMenuHomeSelected
{
    setupMenuHomeSelected = set;
}

bool guiFlags::getStartActiveGame() const  // retrieves the value of startActiveGame
{
    return (startActiveGame);
}
void guiFlags::setStartActiveGame(const bool &set)  // sets the value of startActiveGame
{
    startActiveGame = set;
}

bool guiFlags::getChangeMenu() const  // retrieves the value of changeMenu
{
    return (changeMenu);
}
void guiFlags::setChangeMenu(const bool &set)  // sets the value of changeMenu
{
    changeMenu = set;
}
#endif
