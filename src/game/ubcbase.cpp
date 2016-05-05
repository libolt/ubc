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

// Static Declarations
boost::shared_ptr<gameEngine> UBCBase::gameE;  // the gameEngine object
boost::shared_ptr<gameState> UBCBase::gameS;  // the gameState object
boost::shared_ptr<networkState> UBCBase::networkS;  // the networkState object

UBCBase::UBCBase()  // constructor
{
//    gameEngine *tempGameEObj = new gameEngine;
    boost::shared_ptr<gameEngine> tempGameESharedPtr = boost::shared_ptr<gameEngine>(new gameEngine);
    gameE = tempGameESharedPtr;

   
//    gameState *tempGameStateObj = new gameState;
    boost::shared_ptr<gameState> tempGameStateSharedPtr = boost::shared_ptr<gameState>(new gameState);
    gameS = tempGameStateSharedPtr;
/*
    
//    exit(0);
//    networkState *tempNetworkStateObj = new networkState;
    boost::shared_ptr<networkState> tempNetworkStateSharedPtr = boost::shared_ptr<networkState>(new networkState);
    networkS = tempNetworkStateSharedPtr;
*/

}

UBCBase::~UBCBase()  // destructor
{
    
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
