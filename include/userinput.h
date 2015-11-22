/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean                              *
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

 
#ifndef _USERINPUT_H_
#define _USERINPUT_H_

#include <string>

class userInput
{
    public:
    
        userInput();

        std::string getKeyUp();  // retrieves the value of keyUp
        void setKeyUp(std::string set);  // sets the value of keyUp

        std::string getKeyDown();  // retrieves the value of keyDown
        void setKeyDown(std::string set);  // sets the value of keyDown
        
        std::string getKeyLeft();  // retrieves the value of keyLeft
        void setKeyLeft(std::string set);  // sets the value of keyLeft

        std::string getKeyRight();  // retrieves the value of keyRight
        void setKeyRight(std::string set);  // sets the value of keyRight

        std::string getKeyUpLeft();  // retrieves the value of keyUpLeft
        void setKeyUpLeft(std::string set);  // sets the value of keyUpLeft

        std::string getKeyUpRight();  // retrieves the value of keyUpRight
        void setKeyUpRight(std::string set);  // sets the value of keyUpRight

        std::string getKeyDownLeft();  // retrieves the value of keyDownLeft
        void setKeyDownLeft(std::string set);  // sets the value of keyDownLeft

        std::string getKeyDownRight();  // retrieves the value of keyDownRight
        void setKeyDownRight(std::string set);  // sets the value of keyDownRight

        std::string getKeyShootBlock();  // retrieves the value of keyShootBlock
        void setKeyShootBlock(std::string set);  // sets the value of keyShootBlock

        std::string getKeyPassSteal();  // retrieves the value of keyPassSteal
        void setKeyPassSteal(std::string set);  // sets the value of keyPassSteal

        std::string getKeyPause();  // retrieves the value of keyPause
        void setKeyPause(std::string set);  // sets the value of keyPause

        std::string getKeyStartSelect();  // retrieves the value of keyStartSelect
        void setKeyStartSelect(std::string set);  // sets the value of keyStartSelect

        std::string getKeyQuit();  // retrieves the value of keyStartSelect
        void setKeyQuit(std::string set);  // sets the value of keyStartSelect

        std::string getJoyUp();  // retrieves the value of joyUp
        void setJoyUp(std::string set);  // sets the value of joyUp

        std::string getJoyDown();  // retrieves the value of joyDown
        void setJoyDown(std::string set);  // sets the value of joyDown
        
        std::string getJoyLeft();  // retrieves the value of joyLeft
        void setJoyLeft(std::string set);  // sets the value of joyLeft

        std::string getJoyRight();  // retrieves the value of joyRight
        void setJoyRight(std::string set);  // sets the value of joyRight

        std::string getJoyUpLeft();  // retrieves the value of joyUpLeft
        void setJoyUpLeft(std::string set);  // sets the value of joyUpLeft

        std::string getJoyUpRight();  // retrieves the value of joyUpRight
        void setJoyUpRight(std::string set);  // sets the value of joyUpRight

        std::string getJoyDownLeft();  // retrieves the value of joyDownLeft
        void setJoyDownLeft(std::string set);  // sets the value of joyDownLeft

        std::string getJoyDownRight();  // retrieves the value of joyDownRight
        void setJoyDownRight(std::string set);  // sets the value of joyDownRight

        std::string getJoyShootBlock();  // retrieves the value of joyShootBlock
        void setJoyShootBlock(std::string set);  // sets the value of joyShootBlock

        std::string getJoyPassSteal();  // retrieves the value of joyPassSteal
        void setJoyPassSteal(std::string set);  // sets the value of joyPassSteal

        std::string getJoyPause();  // retrieves the value of joyPause
        void setJoyPause(std::string set);  // sets the value of joyPause

        std::string getJoyStartSelect();  // retrieves the value of joyStartSelect
        void setJoyStartSelect(std::string set);  // sets the value of joyStartSelect

        bool getActive();  // retrieves the value of active
        void setActive(bool set);  // sets the value of active


    private:

    // key input strings
    std::string keyUp;
    std::string keyDown;
    std::string keyLeft;
    std::string keyRight;
    std::string keyUpLeft;
    std::string keyUpRight;
    std::string keyDownLeft;
    std::string keyDownRight;
    std::string keyShootBlock;
    std::string keyPassSteal;
    std::string keyPause;
    std::string keyStartSelect;
    std::string keyQuit;
    
    // joystick input strings
    std::string joyUp;
    std::string joyDown;
    std::string joyLeft;
    std::string joyRight;
    std::string joyUpLeft;
    std::string joyUpRight;
    std::string joyDownLeft;
    std::string joyDownRight;
    std::string joyShootBlock;
    std::string joyPassSteal;
    std::string joyPause;
    std::string joyStartSelect;

    bool active;  // determines whether this input map is being used.
    
};

#endif
