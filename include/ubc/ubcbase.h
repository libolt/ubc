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

#ifndef _UBCBASE_H_
#define _UBCBASE_H_

#include "utilities/typedefs.h"

class gameEngine;
class gameState;
class networkState;
class input;
class loader;
class users;

class UBCBase
{
    public:
    
        UBCBase();  // constructor
        ~UBCBase();  // destructor

        bool getStateSetup();  // retrieves the value of stateSetup
        void setStateSetup(bool set);  // sets the value of stateSetup
    
        
        bool getUsersInstancesCreated();  // retrieves the value of userInstancesCreated
        void setUsersInstancesCreated(bool set);  // sets the value of userInstancesCreated

        bool getUserInstancesInputSetup();  // retrieves the value of userInstancesInputSetup
        void setUserInstancesInputSetup(bool set);  // sets the value of userInstancesInputSetup
        
        bool getInputSUInputSetup();  // retrieves the value of inputSUInputSetup
        void setInputSUInputSetup(bool set);  // sets the value of inputSUInputSetup

        gameEngineSharedPtr getGameE();  // retrieves the value of gameE
        void setGameE(gameEngineSharedPtr set);  // sets the value of gameE
    
        gameStateSharedPtr getGameS();  // retrieves the value of gameS
        void setGameS(gameStateSharedPtr set);  // sets the value of gameS
    
        GUISystemSharedPtr getGui();  // retrieves the value of gui
        void setGui(GUISystemSharedPtr set);  // sets the value of gui

        networkStateSharedPtr getNetworkS();  // retrieves the value of networkS
        void setNetworkS(networkStateSharedPtr set);  // sets the value of networkS
    
        loaderSharedPtr getLoad();  // retrieves the value of load
        void setLoad(loaderSharedPtr set);  // sets the value of load
        
        loadBasketballsSharedPtr getLoadBasketball();  // retrieves the value of loadBasketball
        void setLoadBasketball(loadBasketballsSharedPtr set);  // sets the value of loadBasketball

        loadCourtsSharedPtr getLoadCourt();  // retrieves the value of loadCourt
        void setLoadCourt(loadCourtsSharedPtr set);  // sets the value of loadCourt

        loadHoopsSharedPtr getLoadHoop();  // retrieves the value of loadHoop
        void setLoadHoop(loadHoopsSharedPtr set);  // sets the value of loadHoop

        loadOffensePlaysSharedPtr getLoadOffensePlay();  // retrieves the value of loadOffensePlay
        void setLoadOffensePlay(loadOffensePlaysSharedPtr set);  // sets the value of loadOffensePlay

        loadPlayersSharedPtr getLoadPlayer();  // retrieves the value of loadPlayer
        void setLoadPlayer(loadPlayersSharedPtr set);  // sets the value of loadPlayer

        loadTeamsSharedPtr getLoadTeam();  // retrieves the value of loadTeam
        void setLoadTeam(loadTeamsSharedPtr set);  // sets the value of loadTeam

        loadUsersInputsSharedPtr getLoadUsersInput();  // retrieves the value of loadUsersInput
        void setLoadUsersInput(loadUsersInputsSharedPtr set);  // sets the value of loadUsersInput

        size_t getNumUsers();  // retrieves the value of numUsers
        void setNumUsers(size_t set);  // sets the value of numUsers
        
        usersMSharedPtr getUsersInstance();  // retrieves the value of usersInstance
        void setUsersInstance(usersMSharedPtr set);  // sets the value of usersInstance
        
        bool setup();  // sets up the engine and states
    
    private:
        static bool stateSetup;  // stores whether or not the initial state setup has completed
        static bool userInstancesCreated;  // stores whether user instances have been created
        static bool userInstancesInputSetup;  // stores status of input configuration for users
        static bool inputSUInputSetup;  // stores whether inputS UInput object has been set
        static gameEngineSharedPtr gameE;  // the gameEngine object
        gameStateSharedPtr gameS;  // the gameState object
        static GUISystemSharedPtr gui;  // the GUI object.
        static networkStateSharedPtr networkS;  // the gameState object
        static loaderSharedPtr load;  // the loader object
        static loadBasketballsSharedPtr loadBasketball;  // the loadBasketballs object
        static loadCourtsSharedPtr loadCourt;  // the loadCourts object
        static loadHoopsSharedPtr loadHoop;  // the loadHoops object
        static loadOffensePlaysSharedPtr loadOffensePlay;  // the loadOffensePlays Object
        static loadPlayersSharedPtr loadPlayer;  // the loadPlayers Object
        static loadTeamsSharedPtr loadTeam;  // the loadTeams Object
        static loadUsersInputsSharedPtr loadUsersInput;  // the loadUsersInputs Object

        static usersMSharedPtr usersInstance;  // stores the user object instances
        static size_t numUsers; // stores number of users playing the game

};

#endif
