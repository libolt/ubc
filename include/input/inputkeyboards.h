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

#ifndef _INPUTKEYBOARDS_H_
#define _INPUTKEYBOARDS_H_

#include <vector>

//#include "input/input.h"
#include "utilities/enums.h"
#include "utilities/typedefs.h"
//#include "engine/inputengine.h"

// typedefs

// forward declarations
class input;

class inputKeyboards
{
    public:
    
        inputKeyboards();  // constructor
        ~inputKeyboards();  // destructor

        inputSharedPtr getInputInstance() const;  // retrieves the value of inputS
        void setInputInstance(const inputSharedPtr &set);  // sets the value of inputS

        bool getSetupComplete() const;  // retrieves the value of setupComplete
        void setSetupComplete(const bool &set);  // sets the value of setupComplete

        inputInGameMaps mapInput(inputKeyMaps inKeyMap, usersInputsSharedPtr input);  // maps value of the keyPressed string to inputInGameMaps
        bool process();  // processes input
    
        bool setup();  // sets up the inputKeyboards object

    private:
    
        inputSharedPtr inputS;  // input object

        bool setupComplete;  // stores whether setup has completed successfully
};

#endif
