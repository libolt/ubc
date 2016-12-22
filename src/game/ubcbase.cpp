/***************************************************************************
 *   Copyright (C) 1999 - 2016 by Mike McLean                              *
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

// Static Declarations
bool UBCBase::stateSetup;
bool UBCBase::startActiveGame;  // stores whether to begin an active game instance
boost::shared_ptr<gameEngine> UBCBase::gameE;  // the gameEngine object
boost::shared_ptr<gameState> UBCBase::gameS;  // the gameState object
boost::shared_ptr<networkState> UBCBase::networkS;  // the networkState object
boost::shared_ptr<inputState> UBCBase::inputS;  // the inputState object

UBCBase::UBCBase()  // constructor
{
    stateSetup = false;
    startActiveGame = false;
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

bool UBCBase::getStartActiveGame()  // retrieves the value of startActiveGame
{
    return (startActiveGame);
}
void UBCBase::setStartActiveGame(bool set)  // sets the value of startActiveGame
{
    startActiveGame = set;
}

boost::shared_ptr<gameEngine> UBCBase::getGameE()  // retrieves the value of gameE
{
    return (gameE);
}
void UBCBase::setGameE(boost::shared_ptr<gameEngine> set)  // sets the value of gameE
{
    gameE = set;
}

boost::shared_ptr<gameState> UBCBase::getGameS()  // retrieves the value of gameS
{
    return (gameS);
}
void UBCBase::setGameS(boost::shared_ptr<gameState> set)  // sets the value of gameS
{
    gameS = set;
}

boost::shared_ptr<networkState> UBCBase::getNetworkS()  // retrieves the value of networkS
{
    return (networkS);
}
void UBCBase::setNetworkS(boost::shared_ptr<networkState> set)  // sets the value of networkS
{
    networkS = set;
}

boost::shared_ptr<inputState> UBCBase::getInputS()  // retrieves the value of inputS
{
    return (inputS);
}

void UBCBase::setInputS(boost::shared_ptr<inputState> set)  // sets the value of inputS
{
    inputS = set;
}

bool UBCBase::setup()  // sets up the engine and states
{
//    exit(0);
    //    gameEngine *tempGameEObj = new gameEngine;
    gameEngineSharedPtr tempGameESharedPtr(new gameEngine);
    gameE = tempGameESharedPtr;
//    gameE(new gameEngine);
    gameE->setup();  // sets up the game engine

//    gameState *tempGameStateObj = new gameState;
    gameStateSharedPtr tempGameStateSharedPtr(new gameState);
    gameS = tempGameStateSharedPtr;
    gameS->setInitialized(true);
    
//    exit(0);
//    networkState *tempNetworkStateObj = new networkState;
///    boost::shared_ptr<networkState> tempNetworkStateSharedPtr = boost::shared_ptr<networkState>(new networkState);
///    networkS = tempNetworkStateSharedPtr;
    inputStateSharedPtr tempInputStateSharedPtr(new inputState);
    inputS = tempInputStateSharedPtr;

    inputS->setInputE(gameE->getInputE());
    inputS->setup();  // sets up the inputState object

    return (true);
}

