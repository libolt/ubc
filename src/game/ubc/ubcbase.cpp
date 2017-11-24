/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
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

#include "ubc/ubcbase.h"
#include "engine/gameengine.h"
#include "state/gamestate.h"
#include "state/networkstate.h"
#include "input/inputkeyboards.h"
#include "input/inputgamepads.h"
#include "load/load.h"
#include "load/loadplayers.h"
#include "gui/gui.h"
#include "utilities/logging.h"
#include "users/users.h"

// Static Declarations
bool UBCBase::stateSetup;
bool UBCBase::inputSUInputSetup;  // stores whether inputS UInput object has been set

//sharedPtr<gameState> UBCBase::gameS;  // the gameState object
GUISystemSharedPtr UBCBase::gui;  // the GUI object.
networkStateSharedPtr UBCBase::networkS;  // the networkState object
loaderSharedPtr UBCBase::load;  // the loader object
loadBasketballsSharedPtr UBCBase::loadBasketball;  // the loadBasketballs object
loadCourtsSharedPtr UBCBase::loadCourt;  // the loadCourts object
loadHoopsSharedPtr UBCBase::loadHoop;  // the loadHoops object
loadOffensePlaysSharedPtr UBCBase::loadOffensePlay;  // the loadOffensePlays Object
loadPlayersSharedPtr UBCBase::loadPlayer;  // the loadPlayers Object
loadTeamsSharedPtr UBCBase::loadTeam;  // the loadTeams Object


UBCBase::UBCBase()  // constructor
{
    stateSetup = false;

    inputSUInputSetup = false;

}

UBCBase::~UBCBase()  // destructor
{
    
}

bool UBCBase::getStateSetup()  // retrieves the value of stateSetup
{
    return (stateSetup);
}

void UBCBase::setStateSetup(bool set)  // sets the value of stateSetup
{
    stateSetup = set;
}

bool UBCBase::getInputSUInputSetup()  // retrieves the value of inputSUInputSetup
{
    return (inputSUInputSetup);
}
void UBCBase::setInputSUInputSetup(bool set)  // sets the value of inputSUInputSetup
{
    inputSUInputSetup = set;
}

GUISystemSharedPtr UBCBase::getGui()  // retrieves the value of gui
{
    return (gui);
}
void UBCBase::setGui(GUISystemSharedPtr set)  // sets the value of gui
{
    gui = set;
}

networkStateSharedPtr UBCBase::getNetworkS()  // retrieves the value of networkS
{
    return (networkS);
}
void UBCBase::setNetworkS(networkStateSharedPtr set)  // sets the value of networkS
{
    networkS = set;
}
        
loaderSharedPtr UBCBase::getLoad()  // retrieves the value of load
{
    return (load);
}
void UBCBase::setLoad(loaderSharedPtr set)  // sets the value of load
{
    load = set;
}

loadBasketballsSharedPtr UBCBase::getLoadBasketball()  // retrieves the value of loadBasketball
{
    return(loadBasketball);
}
void UBCBase::setLoadBasketball(loadBasketballsSharedPtr set)  // sets the value of loadBasketball
{
    loadBasketball = set;
}

loadCourtsSharedPtr UBCBase::getLoadCourt()  // retrieves the value of loadCourt
{
    return (loadCourt);
}
void UBCBase::setLoadCourt(loadCourtsSharedPtr set)  // sets the value of loadCourt
{
    loadCourt = set;
}

loadHoopsSharedPtr UBCBase::getLoadHoop()  // retrieves the value of loadHoop
{
    return (loadHoop);
}
void UBCBase::setLoadHoop(loadHoopsSharedPtr set)  // sets the value of loadHoop
{
    loadHoop = set;
}

loadOffensePlaysSharedPtr UBCBase::getLoadOffensePlay()  // retrieves the value of loadOffensePlay
{
    return (loadOffensePlay);
}
void UBCBase::setLoadOffensePlay(loadOffensePlaysSharedPtr set)  // sets the value of loadOffensePlay
{
    loadOffensePlay = set;
}

loadPlayersSharedPtr UBCBase::getLoadPlayer()  // retrieves the value of loadPlayer
{
    return (loadPlayer);
}
void UBCBase::setLoadPlayer(loadPlayersSharedPtr set)  // sets the value of loadPlayer
{
    loadPlayer = set;
}

loadTeamsSharedPtr UBCBase::getLoadTeam()  // retrieves the value of loadTeam
{
    return (loadTeam);
}
void UBCBase::setLoadTeam(loadTeamsSharedPtr set)  // sets the value of loadTeam
{
    loadTeam = set;
}



bool UBCBase::setup()  // sets up the engine and states
{
//    exit(0);
    std::string func = "UBCBase::setup()";
    
    logMsg(func +" beginning");
    

    GUISystemSharedPtr tempGUISharedPtr(new GUISystem);
    gui = tempGUISharedPtr;

    loaderSharedPtr tempLoaderSharedPtr(new loader);
    logMsg(func +" load = tempLoaderSharedPtr");
    load = tempLoaderSharedPtr;

    //FIXME! should not be hard coded
//    numUsers = 1;
//    exit(0);
//    networkState *tempNetworkStateObj = new networkState;
///    sharedPtr<networkState> tempNetworkStateSharedPtr = sharedPtr<networkState>(new networkState);
///    networkS = tempNetworkStateSharedPtr;
/*    inputSharedPtr tempInputStateSharedPtr(new input);
    inputS = tempInputStateSharedPtr;

    inputS->setInputE(gameE->getInputE());
    logMsg(func +" inputS->setup()");
    inputS->setup();  // sets up the inputState object
*/
    stateSetup = true;
    
    logMsg(func +" end");
    
    return (true);
}

