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

 
#ifndef _USERSINPUT_H_
#define _USERSINPUT_H_

#include <string>
#include "utilities/enums.h"
#include "utilities/conversion.h"

class usersInputs
{
    public:
    
        usersInputs();  // constructor
        
        ~usersInputs();  // destructor
        
        std::string getName() const;  // retrieves the value of name
        void setName(const std::string &set);  // sets the value of name
        
        inputTypes getType() const;  // retrieves the value of type
        void setType(const inputTypes &set);  // sets the value of type

        inputKeyMaps getKeyUp() const;  // retrieves the value of keyUp
        void setKeyUp(const inputKeyMaps &set);  // sets the value of keyUp

        inputKeyMaps getKeyDown() const;  // retrieves the value of keyDown
        void setKeyDown(const inputKeyMaps &set);  // sets the value of keyDown
        
        inputKeyMaps getKeyLeft() const;  // retrieves the value of keyLeft
        void setKeyLeft(const inputKeyMaps &set);  // sets the value of keyLeft

        inputKeyMaps getKeyRight() const;  // retrieves the value of keyRight
        void setKeyRight(const inputKeyMaps &set);  // sets the value of keyRight

        inputKeyMaps getKeyUpLeft() const;  // retrieves the value of keyUpLeft
        void setKeyUpLeft(const inputKeyMaps &set);  // sets the value of keyUpLeft

        inputKeyMaps getKeyUpRight() const;  // retrieves the value of keyUpRight
        void setKeyUpRight(const inputKeyMaps &set);  // sets the value of keyUpRight

        inputKeyMaps getKeyDownLeft() const;  // retrieves the value of keyDownLeft
        void setKeyDownLeft(const inputKeyMaps &set);  // sets the value of keyDownLeft

        inputKeyMaps getKeyDownRight() const;  // retrieves the value of keyDownRight
        void setKeyDownRight(const inputKeyMaps &set);  // sets the value of keyDownRight

        inputKeyMaps getKeyShootBlock() const;  // retrieves the value of keyShootBlock
        void setKeyShootBlock(const inputKeyMaps &set);  // sets the value of keyShootBlock

        inputKeyMaps getKeyPassSteal() const;  // retrieves the value of keyPassSteal
        void setKeyPassSteal(const inputKeyMaps &set);  // sets the value of keyPassSteal

        inputKeyMaps getKeyPause() const;  // retrieves the value of keyPause
        void setKeyPause(const inputKeyMaps &set);  // sets the value of keyPause

        inputKeyMaps getKeyStartSelect() const;  // retrieves the value of keyStartSelect
        void setKeyStartSelect(const inputKeyMaps &set);  // sets the value of keyStartSelect

        inputKeyMaps getKeyQuit() const;  // retrieves the value of keyStartSelect
        void setKeyQuit(const inputKeyMaps &set);  // sets the value of keyStartSelect

        inputGamePadMaps getGPUp() const;  // retrieves the value of GPUp
        void setGPUp(const inputGamePadMaps &set);  // sets the value of GPUp

        inputGamePadMaps getGPDown() const;  // retrieves the value of GPDown
        void setGPDown(const inputGamePadMaps &set);  // sets the value of GPDown
        
        inputGamePadMaps getGPLeft() const;  // retrieves the value of GPLeft
        void setGPLeft(const inputGamePadMaps &set);  // sets the value of GPLeft

        inputGamePadMaps getGPRight() const;  // retrieves the value of jLGPRight
        void setGPRight(const inputGamePadMaps &set);  // sets the value of GPRight

        inputGamePadMaps getGPUpLeft() const;  // retrieves the value of GPUpLeft
        void setGPUpLeft(const inputGamePadMaps &set);  // sets the value of GPUpLeft

        inputGamePadMaps getGPUpRight() const;  // retrieves the value of GPUpRight
        void setGPUpRight(const inputGamePadMaps &set);  // sets the value of GPUpRight

        inputGamePadMaps getGPDownLeft() const;  // retrieves the value of GPDownLeft
        void setGPDownLeft(const inputGamePadMaps &set);  // sets the value of GPDownLeft

        inputGamePadMaps getGPDownRight() const;  // retrieves the value of GPDownRight
        void setGPDownRight(const inputGamePadMaps &set);  // sets the value of GPDownRight

        inputGamePadMaps getGPShootBlock() const;  // retrieves the value of GPShootBlock
        void setGPShootBlock(const inputGamePadMaps &set);  // sets the value of GPShootBlock

        inputGamePadMaps getGPPassSteal() const;  // retrieves the value of GPPassSteal
        void setGPPassSteal(const inputGamePadMaps &set);  // sets the value of GPPassSteal

        inputGamePadMaps getGPPause() const;  // retrieves the value of GPPause
        void setGPPause(const inputGamePadMaps &set);  // sets the value of GPPause

        inputGamePadMaps getGPStartSelect() const;  // retrieves the value of GPStartSelect
        void setGPStartSelect(const inputGamePadMaps &set);  // sets the value of GPStartSelect
        
        inputGamePadMaps getGPQuit() const;  // retrieves the value of GPQuit
        void setGPQuit(const inputGamePadMaps &set);  // sets the value of GPQuit

        bool getActive() const;  // retrieves the value of active
        void setActive(const bool &set);  // sets the value of active


    private:

    std::string name;  // stores the name of the input map
    // key input strings
    inputTypes type;  // stores the type of input
    inputKeyMaps keyUp;
    inputKeyMaps keyDown;
    inputKeyMaps keyLeft;
    inputKeyMaps keyRight;
    inputKeyMaps keyUpLeft;
    inputKeyMaps keyUpRight;
    inputKeyMaps keyDownLeft;
    inputKeyMaps keyDownRight;
    inputKeyMaps keyShootBlock;
    inputKeyMaps keyPassSteal;
    inputKeyMaps keyPause;
    inputKeyMaps keyStartSelect;
    inputKeyMaps keyQuit;
    
    // joystick input strings
    inputGamePadMaps GPUp;
    inputGamePadMaps GPDown;
    inputGamePadMaps GPLeft;
    inputGamePadMaps GPRight;
    inputGamePadMaps GPUpLeft;
    inputGamePadMaps GPUpRight;
    inputGamePadMaps GPDownLeft;
    inputGamePadMaps GPDownRight;
    inputGamePadMaps GPShootBlock;
    inputGamePadMaps GPPassSteal;
    inputGamePadMaps GPPause;
    inputGamePadMaps GPStartSelect;
    inputGamePadMaps GPQuit;

    bool active;  // determines whether this input map is being used.
    
};

#endif
