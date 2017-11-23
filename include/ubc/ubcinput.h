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

#ifndef _UBCINPUT_H_
#define _UBCINPUT_H_

#include "utilities/typedefs.h"

class UBCBase;
class input;
class users;

class UBCInput
{
    public:
    
        UBCInput();  // constructor
        ~UBCInput();  // destructor

        UBCBaseSharedPtr getBase();  // retrieves the value of UBCBase
        void setBase(UBCBaseSharedPtr set);  // sets the value of UBCBase

        inputSharedPtr getInputS();  // retrieves the value of inputS
        void setInputS(inputSharedPtr set);  // sets the value of inputS

        inputGamePadsSharedPtr getInputGamePad();  // retrieves the value of inputGamePad
        void setInputGamePad(inputGamePadsSharedPtr set);  // sets the value of inputGamePad

        inputKeyboardsSharedPtr getInputKeyboard();  // retrieves the value of inputKeyboard
        void setInputKeyboard(inputKeyboardsSharedPtr set);  // sets the value of inputKeyboard

        bool getSetupComplete();  // retrieves the value of setupComplete
        void setSetupComplete(bool set);  // sets the value of setupComplete

        void process(gameEngineSharedPtr gameE);  // processes game input

        bool processKeyboard(gameEngineSharedPtr gameE);  // process keyboard input
        bool processGamePad();  // process gamePad input
        bool processMouse();  // process mouse input
        bool processTouch();  // process touch input

        bool setup();  // sets up the UBCInput object

    private:
    
        static UBCBaseSharedPtr base;  // static copy of base class
        static inputSharedPtr inputS;  // the base input object
        static inputGamePadsSharedPtr inputGamePad;  // the inputGamePads object
        static inputKeyboardsSharedPtr inputKeyboard;  // the inputKeyboards object

        static bool setupComplete;  // stores whether setup has completed successfully
};

#endif
