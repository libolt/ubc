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

#ifndef _UBCBASE_H_
#define _UBCBASE_H_

#include <boost/shared_ptr.hpp>

#include "typedefs.h"

class gameEngine;
class gameState;
class networkState;
class inputState;
class loader;

class UBCBase
{
    public:
    
        UBCBase();  // constructor
        ~UBCBase();  // destructor

        bool getStateSetup();  // retrieves the value of stateSetup
        void setStateSetup(bool set);  // sets the value of stateSetup
    
        bool getStartActiveGame();  // retrieves the value of startActiveGame
        void setStartActiveGame(bool set);  // sets the value of startActiveGame
        
        gameEngineSharedPtr getGameE();  // retrieves the value of gameE
        void setGameE(gameEngineSharedPtr set);  // sets the value of gameE
    
        gameStateSharedPtr getGameS();  // retrieves the value of gameS
        void setGameS(gameStateSharedPtr set);  // sets the value of gameS
    
        networkStateSharedPtr getNetworkS();  // retrieves the value of networkS
        void setNetworkS(networkStateSharedPtr set);  // sets the value of networkS
    
        inputStateSharedPtr getInputS();  // retrieves the value of inputS
        void setInputS(inputStateSharedPtr set);  // sets the value of inputS

        loaderSharedPtr getLoad();  // retrieves the value of load
        void setLoad(loaderSharedPtr set);  // sets the value of load
        
        bool setup();  // sets up the engine and states
    
    private:
        static bool stateSetup;  // stores whether or not the initial state setup has completed
        static bool startActiveGame;  // stores whether to begin an active game instance
        static gameEngineSharedPtr gameE;  // the gameEngine object
        gameStateSharedPtr gameS;  // the gameState object
        static networkStateSharedPtr networkS;  // the gameState object
        static inputStateSharedPtr inputS;  // the gameState object
        static loaderSharedPtr load;  // the loader object
};

#endif
