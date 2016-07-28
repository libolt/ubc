/***************************************************************************
 *   Copyright (C) 1999 - 2016 by Mike McLean   *
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

 #include "timing.h"
 
timing::timing()
{
    startTime = boost::chrono::system_clock::now();
    previousTime = startTime;
}

boost::chrono::nanoseconds timing::getChangeInTimeNano()  // retrieves the value of changeInTimeNano
{
    return (changeInTimeNano);
}
void timing::setChangeInTimeNano(boost::chrono::nanoseconds time)  // sets the value of changeInTimeNano
{
    changeInTimeNano = time;
}

boost::chrono::milliseconds timing::getChangeInTimeMill()  // retrieves the value of changeInTimeMill
{
    return (changeInTimeMill);
}
void timing::setChangeInTimeMill(boost::chrono::milliseconds time) // sets the value of changeInTimeMill
{
    changeInTimeNano = time;
}

boost::chrono::system_clock::time_point timing::getPreviousTime()  // retrieves the value of previousTime
{
    return (previousTime);
}
void timing::setPreviousTime(boost::chrono::system_clock::time_point time)  // sets the value of previousTime
{
    previousTime = time;
}

boost::chrono::microseconds timing::calcChangeInTimeMicro()  // calculates change in time in microseconds
{
    currentTime = boost::chrono::system_clock::now();
    changeInTimeNano = currentTime - previousTime;
    changeInTimeMicro = boost::chrono::duration_cast<boost::chrono::microseconds>(changeInTimeNano);
    //previousTime = currentTime;
    
    return (changeInTimeMicro);
}

boost::chrono::milliseconds timing::calcChangeInTimeMill()  // calculates change in time in milliseconds
{
    currentTime = boost::chrono::system_clock::now();
    changeInTimeNano = currentTime - previousTime;
    changeInTimeMill = boost::chrono::duration_cast<boost::chrono::milliseconds>(changeInTimeNano);
    //previousTime = currentTime;
    
    return (changeInTimeMill);
}

boost::chrono::milliseconds timing::getLoopTimeMill()  // returns the current loop time
{
    currentTime = boost::chrono::system_clock::now();
    boost::chrono::nanoseconds loopTimeNano = currentTime - startTime;
    boost::chrono::milliseconds loopTimeMilli = boost::chrono::duration_cast<boost::chrono::milliseconds>(loopTimeNano);
    
    return (loopTimeMilli);
}
