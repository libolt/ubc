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

#include "statistics/statistics.h"
 
statistics::statistics()
{
    points = 0;
    fouls = 0;
    offensiveRebounds = 0;
    defensiveRebounds = 0;
    totalRebounds = 0;
    steals = 0;
    blocks = 0;
    turnovers = 0;
    assists = 0;
    fieldGoalsAttemped = 0;
    fieldGoalsMade = 0;
    threePointersAttempted = 0;
    threePointersMade = 0;
    freeThrowsAttempted = 0;
    freeThrowsMade = 0;
    technicalFouls = 0;
}

statistics::~statistics() = default;  // destructor

size_t statistics::getPoints() const  // retrieves the value of points
{
    return(points);
}
void statistics::setPoints(const size_t &set)  // sets the vlaue of points
{
    points = set;
}

size_t statistics::getFouls() const  // retrieves the value of fouls
{
    return(fouls);
}
void statistics::setFouls(const size_t &set)  // sets the value of fouls
{
    fouls = set;
}

size_t statistics::getTechnicalFouls() const  // retrieves the value of technicalFouls
{
    return (technicalFouls);
}
void statistics::setTechnicalFoulds(const size_t &set)  // sets the value of technicalFouls
{
    technicalFouls = set;
}

size_t statistics::getOffensiveRebounds() const  // retrieves the value of offensiveRebounds
{
    return(offensiveRebounds);
}
void statistics::setOffensiveRebounds(const size_t &set)  // sets the value of offensiveRebounds
{
    offensiveRebounds = set;
}

size_t statistics::getDefensiveRebounds() const  // retrieves the value of defensiveRebounds
{
    return(defensiveRebounds);
}
void statistics::setDefensiveRebounds(const size_t &set)  // sets the value of defensiveRebounds
{
    defensiveRebounds = set;
}

size_t statistics::getTotalRebounds() const  // retrieves the value of totalRebounds
{
    return(totalRebounds);
}
void statistics::setTotalReboundS(const size_t &set)  // sets the value of totalRebounds
{
    totalRebounds = set;
}

size_t statistics::getSteals() const  // retrieves the value of steals
{
    return(steals);
}
void statistics::setSteals(size_t set)  // sets the value of steals
{
    steals = set;
}

size_t statistics::getBlocks() const  // retrieves the value of blocks
{
    return(blocks);
}
void statistics::setBlocks(const size_t &set)  // sets the value of blocks
{
    blocks = set;
}

size_t statistics::getTurnovers() const  // retrieves the value of turnovers
{
    return(turnovers);
}
void statistics::setTurnovers(const size_t &set)  // sets the value of turnovers
{
    turnovers = set;
}

size_t statistics::getAssists() const  // retrieves the value of assist
{
    return(assists);
}
void statistics::setAssists(const size_t &set)  // sets the value of assists
{
    assists = set;
}

size_t statistics::getFieldGoalsAttemped() const  // retrieves the value of fieldGoalsAttempted
{
    return(fieldGoalsAttemped);
}
void statistics::setFieldGoalsAttempted(const size_t &set)  // sets the value of fieldGoalsAttempted
{
    fieldGoalsAttemped = set;
}

size_t statistics::getFieldGoalsMade() const  // retrieved the value of fieldGoalsMade
{
    return(fieldGoalsMade);
}
void statistics::setFieldGoalsmade(const size_t &set)  // sets the value of fieldGoalsMade
{
    fieldGoalsMade = set;
}

size_t statistics::getThreePointersAttempted() const  // retrieves the value of threePointersAttempted
{
    return(threePointersAttempted);
}
void statistics::setThreePointersAttempted(const size_t &set)  // sets the value of threePointersAttempted
{
    threePointersAttempted = set;
}

size_t statistics::getThreePointersMade() const  // retrieves the value of threePointersMade
{
    return(threePointersMade);
}
void statistics::setThreePointersMade(const size_t &set)  // sets the value of threePointersMade
{
    threePointersMade = set;
}

size_t statistics::getFreeThrowsAttempted() const  // retrieves the value of freeThrowsAttempted
{
    return(freeThrowsAttempted);
}
void statistics::setFreeThrowsAttempted(const size_t &set)  // sets the value of freeThrowsAttempted
{
    freeThrowsAttempted = set;
}

size_t statistics::getFreeThrowsMade() const  // retrieves the value of freeThrowsMade
{
    return(freeThrowsMade);
}
void statistics::setFreeThrowsMade(const size_t &set)  // sets the value of freeThrowsMade
{
    freeThrowsMade = set;
}

