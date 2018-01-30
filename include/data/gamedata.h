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

#ifndef _GAMEDATA_H_
#define _GAMEDATA_H_

#include "utilities/typedefs.h"

class gameData
{
    public:
        gameData();  // constructor
        ~gameData();  // destructor
    
        size_t getBballBounce();  // retrieves the value of bballBounce
        void setBballBounce(size_t set);  // sets the value of bballBounce

        size_t getSelectedCourtDataInstance();  // retrieves the value of selectedCourtDataInstance
        void setSelectedCourtDataInstance(size_t set);  // sets the value of selectedCourtDataInstance

        sizeTVec getPlayerID();  // retrieves the value of playerID
        void setPlayerID(sizeTVec set);  // sets the value of playerID

    private:
    
        float gameTimeLeft;  // Indicates the time left in the game
        float quarterTimeLeft;  // incates the time left in the current quarter
        size_t selectedCourtDataInstance;  // stores which court should be loaded by courtInstance
    
        sizeTVec playerID;  // std::vector that stores the IDs of the players currently being used.

        std::vector< sizeTVec > teamStarterID;  // stores the selected starters for each team
        size_t bballBounce;  // stores which direction the ball is bouncing;

        size_t numActiveHoops;  // stores the nimber of active hoop instances

};

#endif
