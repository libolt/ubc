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

        void process();  // processes game input

        bool processKeyboard();  // process keyboard input
        bool processGamePad();  // process gamePad input
        bool processMouse();  // process mouse input
        bool processTouch();  // process touch input

    private:
    
        static UBCBaseSharedPtr base;  // static copy of base class

};

#endif
