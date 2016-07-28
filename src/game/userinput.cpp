/***************************************************************************
 *   Copyright (C) 1999 - 2016 by Mike McLean   *
 *   libolt@libolt.net   *
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

 
#include "userinput.h"

userInput::userInput()
{
    active = false;
}

std::string userInput::getKeyUp()  // retrieves the value of keyUp
{
    return (keyUp);
}
void userInput::setKeyUp(std::string set)  // sets the value of keyUp
{
    keyUp = set;
}

std::string userInput::getKeyDown()  // retrieves the value of keyDown
{
    return (keyDown);
}
void userInput::setKeyDown(std::string set)  // sets the value of keyDown
{
    keyDown = set;
}
std::string userInput::getKeyLeft()  // retrieves the value of keyLeft
{
    return (keyLeft);
}
void userInput::setKeyLeft(std::string set)  // sets the value of keyLeft
{
    keyLeft = set;
}

std::string userInput::getKeyRight()  // retrieves the value of keyRight
{
    return (keyRight);
}
void userInput::setKeyRight(std::string set)  // sets the value of keyRight
{
    keyRight = set;
}

std::string userInput::getKeyUpLeft()  // retrieves the value of keyUpLeft
{
    return (keyUpLeft);
}
void userInput::setKeyUpLeft(std::string set)  // sets the value of keyUpLeft
{
    keyUpLeft = set;
}

std::string userInput::getKeyUpRight()  // retrieves the value of keyUpRight
{
    return (keyUpRight);//pElem=hRoot.FirstChild("Name").FirstChild().Element();

}
void userInput::setKeyUpRight(std::string set)  // sets the value of keyUpRight
{
    keyUpRight = set;
}

std::string userInput::getKeyDownLeft()  // retrieves the value of keyDownLeft
{
    return (keyDownLeft);
}
void userInput::setKeyDownLeft(std::string set)  // sets the value of keyDownLeft
{
    keyDownLeft = set;
}

std::string userInput::getKeyDownRight()  // retrieves the value of keyDownRight
{
    return (keyDownRight);
}
void userInput::setKeyDownRight(std::string set)  // sets the value of keyDownRight
{
    keyDownRight = set;
}

std::string userInput::getKeyShootBlock()  // retrieves the value of keyShootBlock
{
    return (keyShootBlock);
}
void userInput::setKeyShootBlock(std::string set)  // sets the value of keyShootBlock
{
    keyShootBlock = set;
}

std::string userInput::getKeyPassSteal()  // retrieves the value of keyPassSteal
{
    return (keyPassSteal);
}
void userInput::setKeyPassSteal(std::string set)  // sets the value of keyPassSteal
{
    keyPassSteal = set;
}

std::string userInput::getKeyPause()  // retrieves the value of keyPause
{
    return (keyPause);
}
void userInput::setKeyPause(std::string set)  // sets the value of keyPause
{
    keyPause = set;
}

std::string userInput::getKeyStartSelect()  // retrieves the value of keyStartSelect
{
    return (keyStartSelect);
}
void userInput::setKeyStartSelect(std::string set)  // sets the value of keyStartSelect
{
    keyStartSelect = set;
}

std::string userInput::getKeyQuit()  // retrieves the value of keyStartSelect
{
    return (keyQuit);
}
void userInput::setKeyQuit(std::string set)  // sets the value of keyStartSelect
{
    keyQuit = set;
}
std::string userInput::getJoyUp()  // retrieves the value of keyUp
{
    return (joyUp);
}
void userInput::setJoyUp(std::string set)  // sets the value of keyUp
{
    joyUp = set;
}
    
std::string userInput::getJoyDown()  // retrieves the value of keyDown
{
    return (joyDown);
}
void userInput::setJoyDown(std::string set)  // sets the value of keyDown
{
    joyDown = set;
}

std::string userInput::getJoyLeft()  // retrieves the value of keyLeft
{
    return (joyLeft);
}
void userInput::setJoyLeft(std::string set)  // sets the value of keyLeft
{
    joyLeft = set;
}
    
std::string userInput::getJoyRight()  // retrieves the value of keyRight
{
    return (joyRight);
}
void userInput::setJoyRight(std::string set)  // sets the value of keyRight
{
    joyRight = set;
}
    
std::string userInput::getJoyUpLeft()  // retrieves the value of keyUpLeft
{
    return (joyUpLeft);
}
void userInput::setJoyUpLeft(std::string set)  // sets the value of keyUpLeft
{
    joyUpLeft = set;
}
    
std::string userInput::getJoyUpRight()  // retrieves the value of keyUpRight
{
    return (joyUpRight);
}
void userInput::setJoyUpRight(std::string set)  // sets the value of keyUpRight
{
    joyUpRight = set;
}
    
std::string userInput::getJoyDownLeft()  // retrieves the value of keyDownLeft
{
    return (joyDownLeft);
}
void userInput::setJoyDownLeft(std::string set)  // sets the value of keyDownLeft
{
    joyDownLeft = set;
} 
    
std::string userInput::getJoyDownRight()  // retrieves the value of keyDownRight
{
    return (joyDownRight); 
}
void userInput::setJoyDownRight(std::string set)  // sets the value of keyDownRight
{
    joyDownRight = set;
}
    
std::string userInput::getJoyShootBlock()  // retrieves the value of keyShootBlock
{
    return (joyShootBlock);
}
void userInput::setJoyShootBlock(std::string set)  // sets the value of keyShootBlock
{
    joyShootBlock = set;
}

std::string userInput::getJoyPassSteal()  // retrieves the value of keyPassSteal
{
    return (joyPassSteal);
}
void userInput::setJoyPassSteal(std::string set)  // sets the value of keyPassSteal
{
    joyPassSteal = set;
}

std::string userInput::getJoyPause()  // retrieves the value of keyPause
{
    return (joyPause);
}
void userInput::setJoyPause(std::string set)  // sets the value of keyPause
{
    joyPause = set;
}

std::string userInput::getJoyStartSelect()  // retrieves the value of keyStartSelect
{
    return (joyStartSelect);
}
void userInput::setJoyStartSelect(std::string set)  // sets the value of keyStartSelect
{
    joyStartSelect = set;
}

bool userInput::getActive()  // retrieves the value of active
{
    return (active);
}

void userInput::setActive(bool set)  // sets the value of active
{
    active = set;
}
