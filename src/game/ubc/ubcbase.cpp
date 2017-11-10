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
bool UBCBase::startActiveGame;  // stores whether to begin an active game instance
bool UBCBase::userInstancesCreated;  // stores whether user instances have been created
bool UBCBase::userInstancesInputSetup;  // stores status of input configuration for users
bool UBCBase::inputSUInputSetup;  // stores whether inputS UInput object has been set

gameEngineSharedPtr UBCBase::gameE;  // the gameEngine object
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
loadUsersInputsSharedPtr UBCBase::loadUsersInput;  // the loadUsersInputs Object

size_t UBCBase::numUsers;  // stores the number of users playing the game
usersMSharedPtr UBCBase::usersInstance; // stores the user object instances

UBCBase::UBCBase()  // constructor
{
    stateSetup = false;
    startActiveGame = false;
    userInstancesCreated = false;
    userInstancesInputSetup = false;
    inputSUInputSetup = false;
    numUsers = 0;

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

bool UBCBase::getUsersInstancesCreated()  // retrieves the value of userInstancesCreated
{
    return (userInstancesCreated);
}
void UBCBase::setUsersInstancesCreated(bool set)  // sets the value of userInstancesCreated
{
    userInstancesCreated = set;
}

bool UBCBase::getUserInstancesInputSetup()  // retrieves the value of userInstancesInputSetup
{
    return (userInstancesInputSetup);
}
void UBCBase::setUserInstancesInputSetup(bool set)  // sets the value of userInstancesInputSetup
{
    userInstancesInputSetup = set;
}

bool UBCBase::getInputSUInputSetup()  // retrieves the value of inputSUInputSetup
{
    return (inputSUInputSetup);
}
void UBCBase::setInputSUInputSetup(bool set)  // sets the value of inputSUInputSetup
{
    inputSUInputSetup = set;
}

bool UBCBase::getStartActiveGame()  // retrieves the value of startActiveGame
{
    return (startActiveGame);
}
void UBCBase::setStartActiveGame(bool set)  // sets the value of startActiveGame
{
    startActiveGame = set;
}

gameEngineSharedPtr UBCBase::getGameE()  // retrieves the value of gameE
{
    return (gameE);
}
void UBCBase::setGameE(gameEngineSharedPtr set)  // sets the value of gameE
{
    gameE = set;
}

gameStateSharedPtr UBCBase::getGameS()  // retrieves the value of gameS
{
    return (gameS);
}
void UBCBase::setGameS(gameStateSharedPtr set)  // sets the value of gameS
{
    gameS = set;
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

loadUsersInputsSharedPtr UBCBase::getLoadUsersInput()  // retrieves the value of loadUsersInput
{
    return (loadUsersInput);
}
void UBCBase::setLoadUsersInput(loadUsersInputsSharedPtr set)  // sets the value of loadUsersInput
{
    loadUsersInput = set;
}

size_t UBCBase::getNumUsers()  // retrieves the value of numUsers
{
    return (numUsers);
}
void UBCBase::setNumUsers(size_t set)  // sets the value of numUsers
{
    numUsers = set;
}

usersMSharedPtr UBCBase::getUsersInstance()  // retrieves the value of usersInstance
{
    return (usersInstance);
}
void UBCBase::setUsersInstance(usersMSharedPtr set)  // sets the value of usersInstance
{
    usersInstance = set;
}

bool UBCBase::setup()  // sets up the engine and states
{
//    exit(0);
    std::string func = "UBCBase::setup()";
    
    logMsg(func +" beginning");
    
    //    gameEngine *tempGameEObj = new gameEngine;
    gameEngineSharedPtr tempGameESharedPtr(new gameEngine);
    gameE = tempGameESharedPtr;
//    gameE(new gameEngine);
    logMsg(func +" gameE->setup()");
    gameE->setup();  // sets up the game engine

//    gameState *tempGameStateObj = new gameState;
    gameStateSharedPtr tempGameStateSharedPtr(new gameState);
    gameS = tempGameStateSharedPtr;
    logMsg(func +" getGameS()->setInitialized(true)");
    getGameS()->setInitialized(true);

    GUISystemSharedPtr tempGUISharedPtr(new GUISystem);
    gui = tempGUISharedPtr;

    loaderSharedPtr tempLoaderSharedPtr(new loader);
    logMsg(func +" load = tempLoaderSharedPtr");
    load = tempLoaderSharedPtr;

    //FIXME! should not be hard coded
    numUsers = 1;
    for (int x=0;x<numUsers;++x)
    {
        usersSharedPtr tempUser(new users);
        usersInstance.insert(std::pair<size_t, usersSharedPtr>(x,tempUser));
    }
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

