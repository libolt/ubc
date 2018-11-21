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

#include "flags/offenseflags.h"

offenseFlags::offenseFlags()  // constructor
{
    execute = false;
    offenseSet = false;
    allStartPositionsReached = false;
    allExecutePositionsReached = false;
    offenseSetup = false;

}
offenseFlags::~offenseFlags() = default;  // destructor

bool offenseFlags::getExecute() const  // retrieves the value of execute variable
{
    return (execute);
}
void offenseFlags::setExecute(const bool &set)  // sets the value of the execute variable
{
    execute = set;
}

boolVec offenseFlags::getStartXPosSet() const  // returns the value of startXPosSet
{
    return (startXPosSet);
}
void offenseFlags::setStartXPosSet(const boolVec &set)  // sets the value of startXPosSet
{
    startXPosSet = set;
}

boolVec offenseFlags::getStartYPosSet() const  // returns the value of startYPosSet
{
    return (startYPosSet);
}
void offenseFlags::setStartYPosSet(const boolVec &set) // sets the value of startYPosSet
{
    startYPosSet = set;
}

boolVec offenseFlags::getStartZPosSet() const  // returns the value of startZPosSet
{
    return (startZPosSet);
}
void offenseFlags::setStartZPosSet(const boolVec &set)  // sets the value of startZPosSet
{
    startZPosSet = set;
}

boolVec offenseFlags::getStartPositionReached() const  // returns the value of startPositionReached
{
    return (startPositionReached);
}
void offenseFlags::setStartPositionReached(const boolVec &set) // sets the value of startPositionReached
{
    startPositionReached = set;
}

bool offenseFlags::getAllStartPositionsReached() const  // retrieves the value of allStartPositionsReached
{
    return (allStartPositionsReached);
}
void offenseFlags::setAllStartPositionsReached(const bool &set)  // sets the value of allStartPositionsReached
{
    allStartPositionsReached = set;
}

std::vector< boolVec > offenseFlags::getExecutePositionReached() const  // returns the value of executePositionSet
{
    return (executePositionReached);
}
void offenseFlags::setExecutePositionReached(const std::vector<boolVec> &set) // sets the value of executePositionSet
{
    executePositionReached = set;
}

bool offenseFlags::getOffenseSetup()  // retrieves the value of offenseSetup
{
    return (offenseSetup);
}
void offenseFlags::setOffenseSetup(bool set)  // sets the value of offenseSetup
{
    offenseSetup = set;
}
