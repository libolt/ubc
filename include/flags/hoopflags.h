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

#ifndef _HOOPFLAGS_H_
#define _HOOPFLAGS_H_

#include "flags/entityflags.h"

class hoopFlags : public entityFlags
{
    public:
    
        hoopFlags();  // constructor
        ~hoopFlags();  // destructor

        bool getNumberSet() const;  // retrieves the value of numberSet
        void setNumberSet(const bool &set);  // sets the value of numberSet

        bool getStateChanged() const;  // retrieves the value of stateChanged
        void setStateChanged(const bool &set);  // sets the value of stateChanged

    private:
        bool numberSet;  // stores whether the the instance number had been set
        bool stateChanged;  // Determines if the stateMachine needs to be updated


};

#endif
