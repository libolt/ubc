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

 
#ifndef _USERSINPUT_H_
#define _USERSINPUT_H_

#include <string>
#include "enums.h"
#include "conversion.h"

class usersInputs
{
    public:
    
        usersInputs();  // constructor
        
        ~usersInputs();  // destructor
        
        std::string getName();  // retrieves the value of name
        void setName(std::string set);  // sets the value of name
        
        inputKeyMaps getKeyUp();  // retrieves the value of keyUp
        void setKeyUp(inputKeyMaps set);  // sets the value of keyUp

        inputKeyMaps getKeyDown();  // retrieves the value of keyDown
        void setKeyDown(inputKeyMaps set);  // sets the value of keyDown
        
        inputKeyMaps getKeyLeft();  // retrieves the value of keyLeft
        void setKeyLeft(inputKeyMaps set);  // sets the value of keyLeft

        inputKeyMaps getKeyRight();  // retrieves the value of keyRight
        void setKeyRight(inputKeyMaps set);  // sets the value of keyRight

        inputKeyMaps getKeyUpLeft();  // retrieves the value of keyUpLeft
        void setKeyUpLeft(inputKeyMaps set);  // sets the value of keyUpLeft

        inputKeyMaps getKeyUpRight();  // retrieves the value of keyUpRight
        void setKeyUpRight(inputKeyMaps set);  // sets the value of keyUpRight

        inputKeyMaps getKeyDownLeft();  // retrieves the value of keyDownLeft
        void setKeyDownLeft(inputKeyMaps set);  // sets the value of keyDownLeft

        inputKeyMaps getKeyDownRight();  // retrieves the value of keyDownRight
        void setKeyDownRight(inputKeyMaps set);  // sets the value of keyDownRight

        inputKeyMaps getKeyShootBlock();  // retrieves the value of keyShootBlock
        void setKeyShootBlock(inputKeyMaps set);  // sets the value of keyShootBlock

        inputKeyMaps getKeyPassSteal();  // retrieves the value of keyPassSteal
        void setKeyPassSteal(inputKeyMaps set);  // sets the value of keyPassSteal

        inputKeyMaps getKeyPause();  // retrieves the value of keyPause
        void setKeyPause(inputKeyMaps set);  // sets the value of keyPause

        inputKeyMaps getKeyStartSelect();  // retrieves the value of keyStartSelect
        void setKeyStartSelect(inputKeyMaps set);  // sets the value of keyStartSelect

        inputKeyMaps getKeyQuit();  // retrieves the value of keyStartSelect
        void setKeyQuit(inputKeyMaps set);  // sets the value of keyStartSelect

        inputGamePadMaps getGPUp();  // retrieves the value of GPUp
        void setGPUp(inputGamePadMaps set);  // sets the value of GPUp

        inputGamePadMaps getGPDown();  // retrieves the value of GPDown
        void setGPDown(inputGamePadMaps set);  // sets the value of GPDown
        
        inputGamePadMaps getGPLeft();  // retrieves the value of GPLeft
        void setGPLeft(inputGamePadMaps set);  // sets the value of GPLeft

        inputGamePadMaps getGPPRight();  // retrieves the value of jLGPRight
        void setGPRight(inputGamePadMaps set);  // sets the value of GPRight

        inputGamePadMaps getGPUpLeft();  // retrieves the value of GPUpLeft
        void setGPUpLeft(inputGamePadMaps set);  // sets the value of GPUpLeft

        inputGamePadMaps getGPUpRight();  // retrieves the value of GPUpRight
        void setGPUpRight(inputGamePadMaps set);  // sets the value of GPUpRight

        inputGamePadMaps getGPDownLeft();  // retrieves the value of GPDownLeft
        void setGPDownLeft(inputGamePadMaps set);  // sets the value of GPDownLeft

        inputGamePadMaps getGPDownRight();  // retrieves the value of GPDownRight
        void setGPDownRight(inputGamePadMaps set);  // sets the value of GPDownRight

        inputGamePadMaps getGPShootBlock();  // retrieves the value of GPShootBlock
        void setGPShootBlock(inputGamePadMaps set);  // sets the value of GPShootBlock

        inputGamePadMaps getGPPassSteal();  // retrieves the value of GPPassSteal
        void setGPPassSteal(inputGamePadMaps set);  // sets the value of GPPassSteal

        inputGamePadMaps getGPPause();  // retrieves the value of GPPause
        void setGPPause(inputGamePadMaps set);  // sets the value of GPPause

        inputGamePadMaps getGPStartSelect();  // retrieves the value of GPStartSelect
        void setGPStartSelect(inputGamePadMaps set);  // sets the value of GPStartSelect

        bool getActive();  // retrieves the value of active
        void setActive(bool set);  // sets the value of active


    private:

    std::string name;  // stores the name of the input map
    // key input strings
    static inputKeyMaps keyUp;
    static inputKeyMaps keyDown;
    static inputKeyMaps keyLeft;
    static inputKeyMaps keyRight;
    static inputKeyMaps keyUpLeft;
    static inputKeyMaps keyUpRight;
    static inputKeyMaps keyDownLeft;
    static inputKeyMaps keyDownRight;
    static inputKeyMaps keyShootBlock;
    static inputKeyMaps keyPassSteal;
    static inputKeyMaps keyPause;
    static inputKeyMaps keyStartSelect;
    static inputKeyMaps keyQuit;
    
    // joystick input strings
    static inputGamePadMaps GPUp;
    static inputGamePadMaps GPDown;
    static inputGamePadMaps GPLeft;
    static inputGamePadMaps GPRight;
    static inputGamePadMaps GPUpLeft;
    static inputGamePadMaps GPUpRight;
    static inputGamePadMaps GPDownLeft;
    static inputGamePadMaps GPDownRight;
    static inputGamePadMaps GPShootBlock;
    static inputGamePadMaps GPPassSteal;
    static inputGamePadMaps GPPause;
    static inputGamePadMaps GPStartSelect;

    bool active;  // determines whether this input map is being used.
    
};

#endif
