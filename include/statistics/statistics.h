/***************************************************************************
 *   Copyright (C) 1999 - 2019 by Mike McLean                              *
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

        size_t getPoints() const;  // gets the value of points
        void setPoints(const size_t &set);  // sets the value of points

        size_t getFouls() const;  // retrieves the value of fouls
        void setFouls(const size_t &set);  // sets the value of fouls;

        size_t getTechnicalFouls() const;  // retrieves the value of technicalFouls
        void setTechnicalFoulds(const size_t &set);  // sets the value of technicalFouls

        size_t getOffensiveRebounds() const;  // retrieves the value of offensiveRebounds
        void setOffensiveRebounds(const size_t &set);  // sets the value of offensiveRebounds

        size_t getDefensiveRebounds() const;  // retrieves the value of defensiveRebounds
        void setDefensiveRebounds(const size_t &set);  // sets the value of defensiveRebounds

        size_t getTotalRebounds() const;  // retrieves the value of totalRebounds
        void setTotalReboundS(const size_t &set);  // sets the value of totalRebounds

        size_t getSteals() const;  // retrieves the value of steals
        void setSteals(size_t set);  // sets the value of steals

        size_t getBlocks() const;  // retrieves the value of blocks
        void setBlocks(const size_t &set);  // sets the value of blocks

        size_t getTurnovers() const;  // retrieves the value of turnovers
        void setTurnovers(const size_t &set);  // sets the value of turnovers

        size_t getAssists() const;  // retrieves the values of assists
        void setAssists(const size_t &set);  // sets the value of assists

        size_t getFieldGoalsAttemped() const;  // retrieves the value of fieldGoalsAttempted
        void setFieldGoalsAttempted(const size_t &set);  // sets the value of fieldGoalsAttempted

        size_t getFieldGoalsMade() const;  // retrieves the value of fieldGoalsMade
        void setFieldGoalsmade(const size_t &set);  // sets the value of fieldGoalsMade

        size_t getThreePointersAttempted() const;  // retrieves the value of threePointersMade
        void setThreePointersAttempted(const size_t &set);  // sets the value of threePointersAttempted

        size_t getThreePointersMade() const;  // retrieves the value of threePointersMade
        void setThreePointersMade(const size_t &set);  // sests the value of threePointersMade

        size_t getFreeThrowsAttempted() const;  // retrieves the value of freeThrowsAttempted
        void setFreeThrowsAttempted(const size_t &set);  // sets the value of freeThrowsAttempted

        size_t getFreeThrowsMade() const;  // retrieves the value of freeThrowsMade
        void setFreeThrowsMade(const size_t &set);  // sest the value of freeThrowsMade

    private:
    
        size_t points;  // Tracks how many points have been scored

        size_t fouls;  // Tracks how many fouls have been committed

        size_t technicalFouls;  // tracks how many technical fouls have been commit

        size_t offensiveRebounds;  // Tracks the amount of offensive rebounds

        size_t defensiveRebounds;  // Tracks the amount of defensive rebounds

        size_t totalRebounds;  // Tracks the total number of rebounds
     
        size_t steals;  // Tracks the amount of steals

        size_t blocks;  // Tracks the amount of blocks

        size_t turnovers;  // Tracks the amount of turnovers

        size_t assists;  // Tracks the amount of assists

        size_t fieldGoalsAttemped;  // Tracks how many field goals have been attempted

        size_t fieldGoalsMade;  // Tracks how many field goals have been made

        size_t threePointersAttempted;  // Tracks how many three pointers have been attempted

        size_t threePointersMade;  // Tracks how many three pointers have been made

        size_t freeThrowsAttempted;  // Tracks how many freethrows have been attempted

        size_t freeThrowsMade;  // Tracks how many freethrows have been made

 };
 #endif 
