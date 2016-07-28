/***************************************************************************
 *   Copyright (C) 1999 - 2016 by Mike McLean                              *
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

#ifndef _STATE_H_
#define _STATE_H_

//#include "ubcbase.h"

//class UBC;

class state //: public UBCBase
{
    public:
    
    state();  // constructor
    
    bool getStateSet();  // retrieves the value of stateSet
    void setStateSet(bool set);  // sets the value of stateSet

    bool setupState();		// sets up initial state of the object

    bool updateState();  // updates the state of the object

    bool resetState();  // resets the state of the object
    
    private:
    bool stateSet;  // if true then the basketball state is set

};
#endif
