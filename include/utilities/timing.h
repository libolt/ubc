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

#ifndef _TIMING_H
#define _TIMING_H

//#include <boost/chrono.hpp>
#include <chrono>

class timing
{
    public:
        timing();
        
        std::chrono::nanoseconds getChangeInTimeNano() const;  // retrieves the value of changeInTimeNano
        void setChangeInTimeNano(const std::chrono::nanoseconds &time);  // sets the value of changeInTimeNano

        std::chrono::milliseconds getChangeInTimeMill() const;  // retrieves the value of changeInTimeMill
        void setChangeInTimeMill(const std::chrono::milliseconds &time);  // sets the value of changeInTimeMill

        std::chrono::system_clock::time_point getPreviousTime() const;  // retrieves the value of previousTime
        void setPreviousTime(const std::chrono::system_clock::time_point &time);  // sets the value of previousTime

        std::chrono::microseconds calcChangeInTimeMicro();  // calculates change in time in microseconds
        std::chrono::milliseconds calcChangeInTimeMill();  // calculates change in time in milliseconds
        
        std::chrono::milliseconds getLoopTimeMill();  // returns the current loop time
    
    private:
    
    std::chrono::system_clock::time_point startTime;  // stores the start time
    std::chrono::system_clock::time_point currentTime;  // stores the current time
    std::chrono::system_clock::time_point previousTime;  // stores the previous time
    std::chrono::nanoseconds changeInTimeNano;  // stores the change in time in nanoseconds
    std::chrono::microseconds changeInTimeMicro;  // stores the change in time in microseconds
    static std::chrono::milliseconds changeInTimeMill;  // stores the change in time in milliseconds
    std::chrono::milliseconds loopTimeMill;  // stores the loop time in milliseconds
    std::chrono::milliseconds previousTimeMill;  // stores the previous time in milliseconds
};

#endif
