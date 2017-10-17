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

#include "ubcbase.h"
#include "engine/gameengine.h"
#include "state/gamestate.h"
#include "state/networkstate.h"
#include "state/inputstate.h"
#include "load.h"
#include "logging.h"
#include "users/users.h"

// Static Declarations
bool UBCBase::stateSetup;
bool UBCBase::startActiveGame;  // stores whether to begin an active game instance
bool UBCBase::userInstancesCreated;  // stores whether user instances have been created
bool UBCBase::userInstancesInputSetup;  // stores status of input configuration for users
sharedPtr<gameEngine> UBCBase::gameE;  // the gameEngine object
//sharedPtr<gameState> UBCBase::gameS;  // the gameState object
sharedPtr<networkState> UBCBase::networkS;  // the networkState object
sharedPtr<inputState> UBCBase::inputS;  // the inputState object
loaderSharedPtr UBCBase::load;  // the loader object
size_t UBCBase::numUsers;  // stores the number of users playing the game
usersUMSharedPtr UBCBase::usersInstance; // stores the user object instances

UBCBase::UBCBase()  // constructor
{
    stateSetup = false;
    startActiveGame = false;
    userInstancesCreated = false;
    
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

bool UBCBase::getStartActiveGame()  // retrieves the value of startActiveGame
{
    return (startActiveGame);
}
void UBCBase::setStartActiveGame(bool set)  // sets the value of startActiveGame
{
    startActiveGame = set;
}

sharedPtr<gameEngine> UBCBase::getGameE()  // retrieves the value of gameE
{
    return (gameE);
}
void UBCBase::setGameE(sharedPtr<gameEngine> set)  // sets the value of gameE
{
    gameE = set;
}

sharedPtr<gameState> UBCBase::getGameS()  // retrieves the value of gameS
{
    return (gameS);
}
void UBCBase::setGameS(sharedPtr<gameState> set)  // sets the value of gameS
{
    gameS = set;
}

sharedPtr<networkState> UBCBase::getNetworkS()  // retrieves the value of networkS
{
    return (networkS);
}
void UBCBase::setNetworkS(sharedPtr<networkState> set)  // sets the value of networkS
{
    networkS = set;
}

sharedPtr<inputState> UBCBase::getInputS()  // retrieves the value of inputS
{
    return (inputS);
}

void UBCBase::setInputS(sharedPtr<inputState> set)  // sets the value of inputS
{
    inputS = set;
}

loaderSharedPtr UBCBase::getLoad()  // retrieves the value of load
{
    return (load);
}
void UBCBase::setLoad(loaderSharedPtr set)  // sets the value of load
{
    load = set;
}

size_t UBCBase::getNumUsers()  // retrieves the value of numUsers
{
    return (numUsers);
}
void UBCBase::setNumUsers(size_t set)  // sets the value of numUsers
{
    numUsers = set;
}

usersUMSharedPtr UBCBase::getUsersInstance()  // retrieves the value of usersInstance
{
    return (usersInstance);
}
void UBCBase::setUsersInstance(usersUMSharedPtr set)  // sets the value of usersInstance
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
    inputStateSharedPtr tempInputStateSharedPtr(new inputState);
    inputS = tempInputStateSharedPtr;

    inputS->setInputE(gameE->getInputE());
    logMsg(func +" inputS->setup()");
    inputS->setup();  // sets up the inputState object

    stateSetup = true;
    
    logMsg(func +" end");
    
    return (true);
}

