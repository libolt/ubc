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
}

guiFlags::~guiFlags()
{

}

bool guiFlags::getMenuActive()  // retrieves the value of menuActive
{
    return (menuActive);
}
void guiFlags::setMenuActive(bool set)  // sets the value of menuActive
{
    menuActive = set;
}

bool guiFlags::getSetupComplete()  // retrieves the value of setupComplete
{
    return (setupComplete);
}
void guiFlags::setSetupComplete(bool set)  // sets the value of setupComplete
{
    setupComplete = set;
}

bool guiFlags::getMainMenuCreated()  // retrieves the value of mainMenuCreated
{
    return (mainMenuCreated);
}
void guiFlags::setMainMenuCreated(bool set)  // sets the value of mainMenuCreated
{
    mainMenuCreated = set;
}

bool guiFlags::getBackButtonsCreated()  // retrieves the value of backButtonsCreated
{
    return (backButtonsCreated);
}
void guiFlags::setBackButtonsCreated(bool set)  // sets the value of backButtonsCreated
{
    backButtonsCreated = set;
}

bool guiFlags::getNetworkSetupMenuCreated()  // retrieves the value of networkSetupMenuCreated
{
    return (networkSetupMenuCreated);
}
void guiFlags::setNetworkSetupMenuCreated(bool set)  // sets the value of networkSetupMenuCreated
{
    networkSetupMenuCreated = set;
}

bool guiFlags::getOptionsMenuCreated()  // retrieves the value of optionsMenuCreated
{
    return (optionsMenuCreated);
}
void guiFlags::setOptionsMenuCreated(bool set)  // sets the value of optionsMenuCreated
{
    optionsMenuCreated = set;
}

bool guiFlags::getDisplaySetupMenuCreated()  // retrieves the value of displaySettingsMenuCreated
{
    return (displaySetupMenuCreated);
}
void guiFlags::setDisplaySetupMenuCreated(bool set)  // sets the value of displaySettingsMenuCreated
{
    displaySetupMenuCreated = set;
}

bool guiFlags::getInputSetupMenuCreated()  // retrieves the value of inputSettingsMenuCreated
{
    return (inputSetupMenuCreated);
}
void guiFlags::setInputSetupMenuCreated(bool set)  // sets the value of inputSettingsMenuCreated
{
    inputSetupMenuCreated = set;
}

bool guiFlags::getAuduoSetupMenuCreated()  // retrieves the value of audioSettingsMenuCreated
{
    return (audioSetupMenuCreated);
}

void guiFlags::setAudioSetupMenuCreated(bool set)  // sets the value of audioSettingsMenuCreated
{
    audioSetupMenuCreated = set;
}

bool guiFlags::getSetupMenuCreated()  // retrieves the value of setupMenuCreated
{
    return (setupMenuCreated);
}
void guiFlags::setSetupMenuCreated(bool set)  // sets the value of setupMenuCreated
{
    setupMenuCreated = set;
}

bool guiFlags::getPlayerStartSelectionMenuCreated()  // retrieves the value of playerStartSelectionMenuCreated
{
    return (playerStartSelectionMenuCreated);
}
void guiFlags::setPlayerStartSelectionMenuCreated(bool set)  // sets the value of playerStartSelectionMenuCreated
{
    playerStartSelectionMenuCreated = set;
}

bool guiFlags::getTeamSelectionMenuCreated()  // retrieves the value of teamSelectionMenuCreated
{
    return (teamSelectionMenuCreated);
}
void guiFlags::setTeamSelectionMenuCreated(bool set)  // sets the value of teamSelectionMenuCreated
{
    teamSelectionMenuCreated = set;
}

bool guiFlags::getTeamSelectionMenuDataAdded()  // retrieves the value of teamSelectionMenuDataAdded
{
    return (teamSelectionMenuDataAdded);
}
void guiFlags::setTeamSelectionMenuDataAdded(bool set)  // sets the value of teamSelectionDataAdded
{
    teamSelectionMenuDataAdded = set;
}

bool guiFlags::getCourtSelectionMenuCreated()  // retrieves the value of courtSelectionMenuCreated
{
    return (courtSelectionMenuCreated);
}
void guiFlags::setCourtSelectionMenuCreated(bool set)  // sets the value of courtSelectionMenuCreated
{
    courtSelectionMenuCreated = set;
}

bool guiFlags::getCourtSelectionDataLoaded()  // retrieves the value of courtSelectionEntriesLoaded
{
    return (courtSelectionDataLoaded);
}
void guiFlags::setCourtSelectionDataLoaded(bool set)  // sets the value of courtSelectionEntriesLoaded
{
    courtSelectionDataLoaded = set;
}

bool guiFlags::getSetupMenuAwaySelected() // retrieves the value of setupMenuAwaySelected
{
    return (setupMenuAwaySelected);
}
void guiFlags::setSetupMenuAwaySelected(bool set)  // sets the value of setupMenuAwaySelected
{
    setupMenuAwaySelected = set;
}
