/***************************************************************************
 *   Copyright (C) 1999 - 2018 by Mike McLean   *
 *   libolt@libolt.net   *
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

#include <chrono>
#include "utilities/timing.h"

timing::timing()
{
    startTime = std::chrono::system_clock::now();
    previousTime = startTime;
}

std::chrono::nanoseconds timing::getChangeInTimeNano() const  // retrieves the value of changeInTimeNano
{
    return (changeInTimeNano);
}
void timing::setChangeInTimeNano(const std::chrono::nanoseconds &time)  // sets the value of changeInTimeNano
{
    changeInTimeNano = time;
}

std::chrono::milliseconds timing::getChangeInTimeMill() const // retrieves the value of changeInTimeMill
{
    return (changeInTimeMill);
}
void timing::setChangeInTimeMill(const std::chrono::milliseconds &time)  // sets the value of changeInTimeMill
{
    changeInTimeNano = time;
}

std::chrono::system_clock::time_point timing::getPreviousTime() const // retrieves the value of previousTime
{
    return (previousTime);
}
void timing::setPreviousTime(const std::chrono::system_clock::time_point &time)  // sets the value of previousTime
{
    previousTime = time;
}

std::chrono::microseconds timing::calcChangeInTimeMicro()  // calculates change in time in microseconds
{
    currentTime = std::chrono::system_clock::now();
    changeInTimeNano = currentTime - previousTime;
    changeInTimeMicro = std::chrono::duration_cast<std::chrono::microseconds>(changeInTimeNano);
    //previousTime = currentTime;
    
    return (changeInTimeMicro);
}

std::chrono::milliseconds timing::calcChangeInTimeMill()  // calculates change in time in milliseconds
{
    currentTime = std::chrono::system_clock::now();
    changeInTimeNano = currentTime - previousTime;
    changeInTimeMill = std::chrono::duration_cast<std::chrono::milliseconds>(changeInTimeNano);
    //previousTime = currentTime;
    
    return (changeInTimeMill);
}

std::chrono::milliseconds timing::getLoopTimeMill()  // returns the current loop time
{
    currentTime = std::chrono::system_clock::now();
    std::chrono::nanoseconds loopTimeNano = currentTime - startTime;
    std::chrono::milliseconds loopTimeMilli = std::chrono::duration_cast<std::chrono::milliseconds>(loopTimeNano);
    
    return (loopTimeMilli);
}
