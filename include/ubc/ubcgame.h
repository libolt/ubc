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

        bool getStartActiveGame();  // retrieves the value of startActiveGame
        void setStartActiveGame(bool set);  // sets the value of startActiveGame

        bool getUsersInstancesCreated();  // retrieves the value of userInstancesCreated
        void setUsersInstancesCreated(bool set);  // sets the value of userInstancesCreated

        bool loop(gameEngineSharedPtr game);  // runs the Main loop for the game

    private:

        static bool startActiveGame;  // stores whether to begin an active game instance
        static bool userInstancesCreated;  // stores whether user instances have been created

};
#endif // _UBCGAME_H_
