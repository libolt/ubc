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

#ifndef _TEAMSTATISTICS_H_
#define _TEAMSTATISTICS_H_
 
#include "statistics.h"
 
class teamStatistics : public statistics
{
    public:
        teamStatistics();  // constructor
        ~teamStatistics();  // destructor

        size_t getTimeOuts() const;  // retrieves the value of timeOuts
        void setTimeOuts(const size_t &set);  // sets the value of timeOuts

    private:
        size_t timeOuts;  // stores the number of time outs the team has

 };
 
 #endif
