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

#ifndef _UBCINPUT_H_
#define _UBCINPUT_H_

#include "utilities/typedefs.h"

class input;
class users;

class UBCInput
{
    public:
    
        UBCInput();  // constructor
        ~UBCInput();  // destructor

        inputSharedPtr getInputInstance() const;  // retrieves the value of inputS
        void setInputInstance(const inputSharedPtr &set);  // sets the value of inputS

        inputGamePadsSharedPtr getInputGamePad() const;  // retrieves the value of inputGamePad
        void setInputGamePad(const inputGamePadsSharedPtr &set);  // sets the value of inputGamePad

        inputKeyboardsSharedPtr getInputKeyboard() const;  // retrieves the value of inputKeyboard
        void setInputKeyboard(const inputKeyboardsSharedPtr &set);  // sets the value of inputKeyboard

        bool getSetupComplete() const;  // retrieves the value of setupComplete
        void setSetupComplete(const bool &set);  // sets the value of setupComplete

        void process(gameEngineSharedPtr gameE, gameComponentsSharedPtr gameComponent, gameFlagsSharedPtr gameFlag, usersMSharedPtr usersInstance, GUISystemSharedPtr gui);  // processes game input

        bool processKeyboard(gameEngineSharedPtr gameE, gameComponentsSharedPtr gameComponent, gameFlagsSharedPtr gameFlag, GUISystemSharedPtr gui);  // process keyboard input
        bool processGamePad();  // process gamePad input
        bool processMouse();  // process mouse input
        bool processTouch();  // process touch input

        bool setup(inputEngineSharedPtr inputE);  // sets up the UBCInput object

    private:
    
        inputSharedPtr inputInstance;  // the base input object
        inputGamePadsSharedPtr inputGamePad;  // the inputGamePads object
        inputKeyboardsSharedPtr inputKeyboard;  // the inputKeyboards object

        bool setupComplete;  // stores whether setup has completed successfully
};

#endif
