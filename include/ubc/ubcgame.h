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

#ifndef _UBCGAME_H_
#define _UBCGAME_H_

#include "utilities/typedefs.h"

class UBCGame
{
    public:

        UBCGame();  // constructor
        ~UBCGame();  // destructor

        gameStateSharedPtr getGameInstance();  // retrieves the value of gameS
        void setGameInstance(gameStateSharedPtr set);  // sets the value of gameS

        bool getStartActiveGame();  // retrieves the value of startActiveGame
        void setStartActiveGame(bool set);  // sets the value of startActiveGame

        bool getUsersInstancesCreated();  // retrieves the value of userInstancesCreated
        void setUsersInstancesCreated(bool set);  // sets the value of userInstancesCreated

        loadUsersInputsSharedPtr getLoadUsersInput();  // retrieves the value of loadUsersInput
        void setLoadUsersInput(loadUsersInputsSharedPtr set);  // sets the value of loadUsersInput

        bool getUserInstancesInputSetup();  // retrieves the value of userInstancesInputSetup
        void setUserInstancesInputSetup(bool set);  // sets the value of userInstancesInputSetup

        usersMSharedPtr getUsersInstance();  // retrieves the value of usersInstance
        void setUsersInstance(usersMSharedPtr set);  // sets the value of usersInstance

        size_t getNumUsers();  // retrieves the value of numUsers
        void setNumUsers(size_t set);  // sets the value of numUsers

        bool setup();  // sets up a game instance

        bool loop(gameEngineSharedPtr gameE, UBCInputSharedPtr input);  // runs the Main loop for the game

        bool startGame();  // starts a game

        bool createUserInstances();  // creates the user instances

        bool setupUserInstancesInput();  // sets up input mapping for each user

        void processNetworkEvents(gameEngineSharedPtr gameE);  // processes events in the network subsyatem

        void processPhysicsEvents(gameEngineSharedPtr gameE);  // processes events in the physics subsyatem

    private:

        gameStateSharedPtr gameInstance;  // the gameState object

        static bool startActiveGame;  // stores whether to begin an active game instance
        static bool userInstancesCreated;  // stores whether user instances have been created
        static bool userInstancesInputSetup;  // stores status of input configuration for users
        static size_t numUsers; // stores number of users playing the game
        static loadUsersInputsSharedPtr loadUsersInput;  // the loadUsersInputs Object
        static usersMSharedPtr usersInstance;  // stores the user object instances

};
#endif // _UBCGAME_H_
