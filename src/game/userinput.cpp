/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean   *
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

// static declarations
inputKeyMaps userInput::keyUp;
inputKeyMaps userInput::keyDown;
inputKeyMaps userInput::keyLeft;
inputKeyMaps userInput::keyRight;
inputKeyMaps userInput::keyUpLeft;
inputKeyMaps userInput::keyUpRight;
inputKeyMaps userInput::keyDownLeft;
inputKeyMaps userInput::keyDownRight;
inputKeyMaps userInput::keyShootBlock;
inputKeyMaps userInput::keyPassSteal;
inputKeyMaps userInput::keyPause;
inputKeyMaps userInput::keyStartSelect;
inputKeyMaps userInput::keyQuit;
    
    // joystick input strings
inputGamePadMaps userInput::GPUp;
inputGamePadMaps userInput::GPDown;
inputGamePadMaps userInput::GPLeft;
inputGamePadMaps userInput::GPRight;
inputGamePadMaps userInput::GPUpLeft;
inputGamePadMaps userInput::GPUpRight;
inputGamePadMaps userInput::GPDownLeft;
inputGamePadMaps userInput::GPDownRight;
inputGamePadMaps userInput::GPShootBlock;
inputGamePadMaps userInput::GPPassSteal;
inputGamePadMaps userInput::GPPause;
inputGamePadMaps userInput::GPStartSelect;

userInput::userInput()
{
    keyUp = INKEY_NONE;
    active = false;
}

inputKeyMaps userInput::getKeyUp()  // retrieves the value of keyUp
{
    return (keyUp);
}
void userInput::setKeyUp(inputKeyMaps set)  // sets the value of keyUp
{
    keyUp = set;
}

inputKeyMaps userInput::getKeyDown()  // retrieves the value of keyDown
{
    return (keyDown);
}
void userInput::setKeyDown(inputKeyMaps set)  // sets the value of keyDown
{
    keyDown = set;
}
inputKeyMaps userInput::getKeyLeft()  // retrieves the value of keyLeft
{
    return (keyLeft);
}
void userInput::setKeyLeft(inputKeyMaps set)  // sets the value of keyLeft
{
    keyLeft = set;
}

inputKeyMaps userInput::getKeyRight()  // retrieves the value of keyRight
{
    return (keyRight);
}
void userInput::setKeyRight(inputKeyMaps set)  // sets the value of keyRight
{
    keyRight = set;
}

inputKeyMaps userInput::getKeyUpLeft()  // retrieves the value of keyUpLeft
{
    return (keyUpLeft);
}
void userInput::setKeyUpLeft(inputKeyMaps set)  // sets the value of keyUpLeft
{
    keyUpLeft = set;
}

inputKeyMaps userInput::getKeyUpRight()  // retrieves the value of keyUpRight
{
    return (keyUpRight);

}
void userInput::setKeyUpRight(inputKeyMaps set)  // sets the value of keyUpRight
{
    keyUpRight = set;
}

inputKeyMaps userInput::getKeyDownLeft()  // retrieves the value of keyDownLeft
{
    return (keyDownLeft);
}
void userInput::setKeyDownLeft(inputKeyMaps set)  // sets the value of keyDownLeft
{
    keyDownLeft = set;
}

inputKeyMaps userInput::getKeyDownRight()  // retrieves the value of keyDownRight
{
    return (keyDownRight);
}
void userInput::setKeyDownRight(inputKeyMaps set)  // sets the value of keyDownRight
{
    keyDownRight = set;
}

inputKeyMaps userInput::getKeyShootBlock()  // retrieves the value of keyShootBlock
{
    return (keyShootBlock);
}
void userInput::setKeyShootBlock(inputKeyMaps set)  // sets the value of keyShootBlock
{
    keyShootBlock = set;
}

inputKeyMaps userInput::getKeyPassSteal()  // retrieves the value of keyPassSteal
{
    return (keyPassSteal);
}
void userInput::setKeyPassSteal(inputKeyMaps set)  // sets the value of keyPassSteal
{
    keyPassSteal = set;
}

inputKeyMaps userInput::getKeyPause()  // retrieves the value of keyPause
{
    return (keyPause);
}
void userInput::setKeyPause(inputKeyMaps set)  // sets the value of keyPause
{
    keyPause = set;
}

inputKeyMaps userInput::getKeyStartSelect()  // retrieves the value of keyStartSelect
{
    return (keyStartSelect);
}
void userInput::setKeyStartSelect(inputKeyMaps set)  // sets the value of keyStartSelect
{
    keyStartSelect = set;
}

inputKeyMaps userInput::getKeyQuit()  // retrieves the value of keyStartSelect
{
    return (keyQuit);
}
void userInput::setKeyQuit(inputKeyMaps set)  // sets the value of keyStartSelect
{
    keyQuit = set;
}
inputGamePadMaps userInput::getGPUp()  // retrieves the value of GPUp
{
    return (GPUp);
}
void userInput::setGPUp(inputGamePadMaps set)  // sets the value of GPUp
{
    GPUp = set;
}
    
inputGamePadMaps userInput::getGPDown()  // retrieves the value of GPDown
{
    return (GPDown);
}
void userInput::setGPDown(inputGamePadMaps set)  // sets the value of GPDown
{
    GPDown = set;
}

inputGamePadMaps userInput::getGPLeft()  // retrieves the value of GPLeft
{
    return (GPLeft);
}
void userInput::setGPLeft(inputGamePadMaps set)  // sets the value of GPLeft
{
    GPLeft = set;
}
    
inputGamePadMaps userInput::getGPPRight()  // retrieves the value of GPRight
{
    return (GPRight);
}
void userInput::setGPRight(inputGamePadMaps set)  // sets the value of GPRight
{
    GPRight = set;
}
    
inputGamePadMaps userInput::getGPUpLeft()  // retrieves the value of GPUpLeft
{
    return (GPUpLeft);
}
void userInput::setGPUpLeft(inputGamePadMaps set)  // sets the value of GPUpLeft
{
    GPUpLeft = set;
}
    
inputGamePadMaps userInput::getGPUpRight()  // retrieves the value of GPUpRight
{
    return (GPUpRight);
}
void userInput::setGPUpRight(inputGamePadMaps set)  // sets the value of GPUpRight
{
    GPUpRight = set;
}
    
inputGamePadMaps userInput::getGPDownLeft()  // retrieves the value of GPDownLeft
{
    return (GPDownLeft);
}
void userInput::setGPDownLeft(inputGamePadMaps set)  // sets the value of GPDownLeft
{
    GPDownLeft = set;
} 
    
inputGamePadMaps userInput::getGPDownRight()  // retrieves the value of GPDownRight
{
    return (GPDownRight); 
}
void userInput::setGPDownRight(inputGamePadMaps set)  // sets the value of GPDownRight
{
    GPDownRight = set;
}
    
inputGamePadMaps userInput::getGPShootBlock()  // retrieves the value of GPShootBlock
{
    return (GPShootBlock);
}
void userInput::setGPShootBlock(inputGamePadMaps set)  // sets the value of GPShootBlock
{
    GPShootBlock = set;
}

inputGamePadMaps userInput::getGPPassSteal()  // retrieves the value of GPPassSteal
{
    return (GPPassSteal);
}
void userInput::setGPPassSteal(inputGamePadMaps set)  // sets the value of GPPassSteal
{
    GPPassSteal = set;
}

inputGamePadMaps userInput::getGPPause()  // retrieves the value of GPPause
{
    return (GPPause);
}
void userInput::setGPPause(inputGamePadMaps set)  // sets the value of GPPause
{
    GPPause = set;
}

inputGamePadMaps userInput::getGPStartSelect()  // retrieves the value of GPStartSelect
{
    return (GPStartSelect);
}
void userInput::setGPStartSelect(inputGamePadMaps set)  // sets the value of GPStartSelect
{
    GPStartSelect = set;
}

bool userInput::getActive()  // retrieves the value of active
{
    return (active);
}

void userInput::setActive(bool set)  // sets the value of active
{
    active = set;
}
