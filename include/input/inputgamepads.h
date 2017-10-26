/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
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

#ifndef _INPUTGAMEPADS_H_
#define _INPUTGAMEPADS_H_

#include <vector>

#include "input/input.h"
#include "utilities/enums.h"
//#include "engine/inputengine.h"

// typedefs

// forward declarations
//class inputEngine;
//class usersInput;
//class UBCBase;

class inputGamePads : public input
{
    public:
    
        inputGamePads();  // constructor
        ~inputGamePads();  // destructor

        inputInGameMaps mapInput(inputGamePadMaps inGamePadMap, usersInputsSharedPtr input);  // maps value of the keyPressed string to inputInGameMaps
        bool process();  // processes input

    private:
    
};

#endif
