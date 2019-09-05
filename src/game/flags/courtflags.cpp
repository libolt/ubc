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

#include "flags/courtflags.h"

courtFlags::courtFlags()  // constructor
{
    dataInitialized = false;
    stateChanged = false;
}

courtFlags::~courtFlags() = default;  // denstructor


bool courtFlags::getDataInitialized() const  // retrieves the value of dataInitialized
{
    return (dataInitialized);
}
void courtFlags::setDataInitialized(const bool &set)  // sets the value of dataInitialized
{
    dataInitialized = set;
}

bool courtFlags::getStateChanged() const  // retrieves the value of stateChanged
{
    return (stateChanged);
}
void courtFlags::setStateChanged(const bool &set)  // sets the value of stateChanged
{
    stateChanged = set;
}
