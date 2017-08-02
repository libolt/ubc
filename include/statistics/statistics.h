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

 #ifndef _STATISTICS_H_
 #define _STATISTICS_H_
 
 #include "engine/statsengine.h"
 #include <cstdlib>
 
 class statistics : public statsEngine
 {
    public:
    
        statistics();  // constructor
        ~statistics();  // destructor

        size_t getPoints();  // gets the value of points
        void setPoints(size_t set);  // sets the value of points

        size_t getFouls();  // retrieves the value of fouls
        void setFoulds(size_t set);  // sets the value of fouls;

        size_t getOffensiveRebounds();  // retrieves the value of offensiveRebounds
        void setOffensiveRebounds(size_t set);  // sets the value of offensiveRebounds

        size_t getDefensiveRebounds();  // retrieves the value of defensiveRebounds
        void setDefensiveRebounds(size_t set);  // sets the value of defensiveRebounds

        size_t getTotalRebounds();  // retrieves the value of totalRebounds
        void setTotalReboundS(size_t set);  // sets the value of totalRebounds

        size_t getSteals();  // retrieves the value of steals
        void setSteals(size_t set);  // sets the value of steals

        size_t getBlocks();  // retrieves the value of blocks
        void setBlocks(size_t set);  // sets the value of blocks

        size_t getTurnovers();  // retrieves the value of turnovers
        void setTurnovers(size_t set);  // sets the value of turnovers

        size_t getAssists();  // retrieves the values of assists
        void setAssists(size_t set);  // sets the value of assists

        size_t getFieldGoalsAttemped();  // retrieves the value of fieldGoalsAttempted
        void setFieldGoalsAttempted(size_t set);  // sets the value of fieldGoalsAttempted

        size_t getFieldGoalsMade();  // retrieves the value of fieldGoalsMade
        void setFieldGoalsmade(size_t set);  // sets the value of fieldGoalsMade

        size_t getThreePointersAttempted();  // retrieves the value of threePointersMade
        void setThreePointersAttempted(size_t set);  // sets the value of threePointersAttempted

        size_t getThreePointersMade();  // retrieves the value of threePointersMade
        void setThreePointersMade(size_t set);  // sests the value of threePointersMade

        size_t getFreeThrowsAttempted();  // retrieves the value of freeThrowsAttempted
        void setFreeThrowsAttempted(size_t set);  // sets the value of freeThrowsAttempted

        size_t getFreeThrowsMade();  // retrieves the value of freeThrowsMade
        void setFreeThrowsMade(size_t set);  // sest the value of freeThrowsMade

    private:
    
        size_t points;  // Tracks how many points the player has scored

        size_t fouls;  // Tracks how many fouls the player has

        size_t offensiveRebounds;  // Tracks how many rebounds the player has on offense

        size_t defensiveRebounds;  // Tracks how many rebounds the player has on defense

        size_t totalRebounds;  // Tracks how many total rebounds the player has
     
        size_t steals;  // Tracks how many steals the player has

        size_t blocks;  // Tracks how many blocks the player has

        size_t turnovers;  // Tracks how many turnovers the player has

        size_t assists;  // Tracks how many assists the player has

        size_t fieldGoalsAttemped;  // Tracks how many field goals the player has attempted

        size_t fieldGoalsMade;  // Tracks how many field goals the player has made

        size_t threePointersAttempted;  // Tracks how many three pointers the player has attempted

        size_t threePointersMade;  // Tracks how many three pointers the player has made

        size_t freeThrowsAttempted;  // Tracks how many free throws the player has attempted

        size_t freeThrowsMade;  // Tracks how many fere throws the player has made

 };
 #endif 
