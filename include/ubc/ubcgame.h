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

#ifndef _UBCGAME_H_
#define _UBCGAME_H_

#include "utilities/typedefs.h"

class UBCGame
{
    public:

        UBCGame();  // constructor
        ~UBCGame();  // destructor

        gameEntitySharedPtr getGameInstance() const;  // retrieves the value of gameS
        void setGameInstance(const gameEntitySharedPtr &set);  // sets the value of gameS

        networkStateSharedPtr getNetworkS() const;  // retrieves the value of networkS
        void setNetworkS(const networkStateSharedPtr &set);  // sets the value of networkS

        UBCComponentsSharedPtr getUBCComponent() const;  // retrieves the value of component
        void setUBCComponent(const UBCComponentsSharedPtr &set);  // sets the value of component

        bool getStartActiveGame() const;  // retrieves the value of startActiveGame
        void setStartActiveGame(const bool &set);  // sets the value of startActiveGame

        bool getUsersInstancesCreated() const;  // retrieves the value of userInstancesCreated
        void setUsersInstancesCreated(const bool &set);  // sets the value of userInstancesCreated

        loadBasketballsSharedPtr getLoadBasketball() const;  // retrieves the value of loadBasketball
        void setLoadBasketball(const loadBasketballsSharedPtr &set);  // sets the value of loadBasketball

        loadCourtsSharedPtr getLoadCourt() const;  // retrieves the value of loadCourt
        void setLoadCourt(const loadCourtsSharedPtr &set);  // sets the value of loadCourt

        loadHoopsSharedPtr getLoadHoop() const;  // retrieves the value of loadHoop
        void setLoadHoop(const loadHoopsSharedPtr &set);  // sets the value of loadHoop

        loadOffensePlaysSharedPtr getLoadOffensePlay() const;  // retrieves the value of loadOffensePlay
        void setLoadOffensePlay(const loadOffensePlaysSharedPtr &set);  // sets the value of loadOffensePlay

        loadPlayersSharedPtr getLoadPlayer() const;  // retrieves the value of loadPlayer
        void setLoadPlayer(const loadPlayersSharedPtr &set);  // sets the value of loadPlayer

        loadTeamsSharedPtr getLoadTeam() const;  // retrieves the value of loadTeam
        void setLoadTeam(const loadTeamsSharedPtr &set);  // sets the value of loadTeam

        loadUsersInputsSharedPtr getLoadUsersInput() const;  // retrieves the value of loadUsersInput
        void setLoadUsersInput(const loadUsersInputsSharedPtr &set);  // sets the value of loadUsersInput

        bool getUserInstancesInputSetup() const;  // retrieves the value of userInstancesInputSetup
        void setUserInstancesInputSetup(const bool &set);  // sets the value of userInstancesInputSetup

        usersMSharedPtr getUsersInstance() const;  // retrieves the value of usersInstance
        void setUsersInstance(const usersMSharedPtr &set);  // sets the value of usersInstance

        bool getInputSUInputSetup() const;  // retrieves the value of inputSUInputSetup
        void setInputSUInputSetup(const bool &set);  // sets the value of inputSUInputSetup
        
        size_t getNumUsers() const;  // retrieves the value of numUsers
        void setNumUsers(const size_t &set);  // sets the value of numUsers

        bool setup();  // sets up a game instance

        bool loop(gameEngineSharedPtr gameE, UBCInputSharedPtr input, GUISystemSharedPtr gui);  // runs the Main loop for the game

        bool startGame(renderEngineSharedPtr render);  // starts a game

        bool createUserInstances();  // creates the user instances

        bool setupUserInstancesInput();  // sets up input mapping for each user

        void processNetworkEvents(gameEngineSharedPtr gameE);  // processes events in the network subsyatem

        void processPhysicsEvents(gameEngineSharedPtr gameE);  // processes events in the physics subsyatem

    private:

        gameEntitySharedPtr gameInstance;  // the gameEntity object
        networkStateSharedPtr networkS;  // the gameState object

        UBCComponentsSharedPtr UBCComponent;  // Components object

        bool startActiveGame;  // stores whether to begin an active game instance
        bool userInstancesCreated;  // stores whether user instances have been created
        bool userInstancesInputSetup;  // stores status of input configuration for users
        bool inputSUInputSetup;  // stores whether inputS UInput object has been set
        bool loadUsersInputInitialized;  // stores whether loadUsersInputs object has been initialized
        size_t numUsers; // stores number of users playing the game
        loadBasketballsSharedPtr loadBasketball;  // the loadBasketballs object
        loadCourtsSharedPtr loadCourt;  // the loadCourts object
        loadHoopsSharedPtr loadHoop;  // the loadHoops object
        loadOffensePlaysSharedPtr loadOffensePlay;  // the loadOffensePlays Object
        loadPlayersSharedPtr loadPlayer;  // the loadPlayers Object
        loadTeamsSharedPtr loadTeam;  // the loadTeams Object

        loadUsersInputsSharedPtr loadUsersInput;  // the loadUsersInputs Object
        usersMSharedPtr usersInstance;  // stores the user object instances

};
#endif // _UBCGAME_H_
