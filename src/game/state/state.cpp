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

#include "state/state.h"

state::state()  // constructor
{
//    initialized = false;
    stateSet = false;
}

state::~state() = default;  // destructor

/*bool state::getInitialized()  // retrieves the value of initialized
{
    return (initialized);
}
void state::setInitialized(bool set)  // sets the value of initialized
{
    initialized = set;
}*/
 
bool state::getStateSet()  // retrieves the value of stateSet
{
    return (stateSet);
}
void state::setStateSet(bool set)  // sets the value of stateSet
{
    stateSet = set;
}

bool state::setupState()  // sets up initial state of the object
{
    return (false);
}

bool state::updateState()  // updates the state of the object
{
    return (false);
}

bool resetState()  // resets the state of the object
{
    return (false);
}
