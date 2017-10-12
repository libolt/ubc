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

 
#include "users/usersinput.h"

// static declarations
inputKeyMaps usersInput::keyUp;
inputKeyMaps usersInput::keyDown;
inputKeyMaps usersInput::keyLeft;
inputKeyMaps usersInput::keyRight;
inputKeyMaps usersInput::keyUpLeft;
inputKeyMaps usersInput::keyUpRight;
inputKeyMaps usersInput::keyDownLeft;
inputKeyMaps usersInput::keyDownRight;
inputKeyMaps usersInput::keyShootBlock;
inputKeyMaps usersInput::keyPassSteal;
inputKeyMaps usersInput::keyPause;
inputKeyMaps usersInput::keyStartSelect;
inputKeyMaps usersInput::keyQuit;
    
    // joystick input strings
inputGamePadMaps usersInput::GPUp;
inputGamePadMaps usersInput::GPDown;
inputGamePadMaps usersInput::GPLeft;
inputGamePadMaps usersInput::GPRight;
inputGamePadMaps usersInput::GPUpLeft;
inputGamePadMaps usersInput::GPUpRight;
inputGamePadMaps usersInput::GPDownLeft;
inputGamePadMaps usersInput::GPDownRight;
inputGamePadMaps usersInput::GPShootBlock;
inputGamePadMaps usersInput::GPPassSteal;
inputGamePadMaps usersInput::GPPause;
inputGamePadMaps usersInput::GPStartSelect;

usersInput::usersInput()
{
    keyUp = INKEY_NONE;
    active = false;
}

usersInput::~usersInput()
{

}

inputKeyMaps usersInput::getKeyUp()  // retrieves the value of keyUp
{
    return (keyUp);
}
void usersInput::setKeyUp(inputKeyMaps set)  // sets the value of keyUp
{
    keyUp = set;
}

inputKeyMaps usersInput::getKeyDown()  // retrieves the value of keyDown
{
    return (keyDown);
}
void usersInput::setKeyDown(inputKeyMaps set)  // sets the value of keyDown
{
    keyDown = set;
}
inputKeyMaps usersInput::getKeyLeft()  // retrieves the value of keyLeft
{
    return (keyLeft);
}
void usersInput::setKeyLeft(inputKeyMaps set)  // sets the value of keyLeft
{
    keyLeft = set;
}

inputKeyMaps usersInput::getKeyRight()  // retrieves the value of keyRight
{
    return (keyRight);
}
void usersInput::setKeyRight(inputKeyMaps set)  // sets the value of keyRight
{
    keyRight = set;
}

inputKeyMaps usersInput::getKeyUpLeft()  // retrieves the value of keyUpLeft
{
    return (keyUpLeft);
}
void usersInput::setKeyUpLeft(inputKeyMaps set)  // sets the value of keyUpLeft
{
    keyUpLeft = set;
}

inputKeyMaps usersInput::getKeyUpRight()  // retrieves the value of keyUpRight
{
    return (keyUpRight);

}
void usersInput::setKeyUpRight(inputKeyMaps set)  // sets the value of keyUpRight
{
    keyUpRight = set;
}

inputKeyMaps usersInput::getKeyDownLeft()  // retrieves the value of keyDownLeft
{
    return (keyDownLeft);
}
void usersInput::setKeyDownLeft(inputKeyMaps set)  // sets the value of keyDownLeft
{
    keyDownLeft = set;
}

inputKeyMaps usersInput::getKeyDownRight()  // retrieves the value of keyDownRight
{
    return (keyDownRight);
}
void usersInput::setKeyDownRight(inputKeyMaps set)  // sets the value of keyDownRight
{
    keyDownRight = set;
}

inputKeyMaps usersInput::getKeyShootBlock()  // retrieves the value of keyShootBlock
{
    return (keyShootBlock);
}
void usersInput::setKeyShootBlock(inputKeyMaps set)  // sets the value of keyShootBlock
{
    keyShootBlock = set;
}

inputKeyMaps usersInput::getKeyPassSteal()  // retrieves the value of keyPassSteal
{
    return (keyPassSteal);
}
void usersInput::setKeyPassSteal(inputKeyMaps set)  // sets the value of keyPassSteal
{
    keyPassSteal = set;
}

inputKeyMaps usersInput::getKeyPause()  // retrieves the value of keyPause
{
    return (keyPause);
}
void usersInput::setKeyPause(inputKeyMaps set)  // sets the value of keyPause
{
    keyPause = set;
}

inputKeyMaps usersInput::getKeyStartSelect()  // retrieves the value of keyStartSelect
{
    return (keyStartSelect);
}
void usersInput::setKeyStartSelect(inputKeyMaps set)  // sets the value of keyStartSelect
{
    keyStartSelect = set;
}

inputKeyMaps usersInput::getKeyQuit()  // retrieves the value of keyStartSelect
{
    return (keyQuit);
}
void usersInput::setKeyQuit(inputKeyMaps set)  // sets the value of keyStartSelect
{
    keyQuit = set;
}
inputGamePadMaps usersInput::getGPUp()  // retrieves the value of GPUp
{
    return (GPUp);
}
void usersInput::setGPUp(inputGamePadMaps set)  // sets the value of GPUp
{
    GPUp = set;
}
    
inputGamePadMaps usersInput::getGPDown()  // retrieves the value of GPDown
{
    return (GPDown);
}
void usersInput::setGPDown(inputGamePadMaps set)  // sets the value of GPDown
{
    GPDown = set;
}

inputGamePadMaps usersInput::getGPLeft()  // retrieves the value of GPLeft
{
    return (GPLeft);
}
void usersInput::setGPLeft(inputGamePadMaps set)  // sets the value of GPLeft
{
    GPLeft = set;
}
    
inputGamePadMaps usersInput::getGPPRight()  // retrieves the value of GPRight
{
    return (GPRight);
}
void usersInput::setGPRight(inputGamePadMaps set)  // sets the value of GPRight
{
    GPRight = set;
}
    
inputGamePadMaps usersInput::getGPUpLeft()  // retrieves the value of GPUpLeft
{
    return (GPUpLeft);
}
void usersInput::setGPUpLeft(inputGamePadMaps set)  // sets the value of GPUpLeft
{
    GPUpLeft = set;
}
    
inputGamePadMaps usersInput::getGPUpRight()  // retrieves the value of GPUpRight
{
    return (GPUpRight);
}
void usersInput::setGPUpRight(inputGamePadMaps set)  // sets the value of GPUpRight
{
    GPUpRight = set;
}
    
inputGamePadMaps usersInput::getGPDownLeft()  // retrieves the value of GPDownLeft
{
    return (GPDownLeft);
}
void usersInput::setGPDownLeft(inputGamePadMaps set)  // sets the value of GPDownLeft
{
    GPDownLeft = set;
} 
    
inputGamePadMaps usersInput::getGPDownRight()  // retrieves the value of GPDownRight
{
    return (GPDownRight); 
}
void usersInput::setGPDownRight(inputGamePadMaps set)  // sets the value of GPDownRight
{
    GPDownRight = set;
}
    
inputGamePadMaps usersInput::getGPShootBlock()  // retrieves the value of GPShootBlock
{
    return (GPShootBlock);
}
void usersInput::setGPShootBlock(inputGamePadMaps set)  // sets the value of GPShootBlock
{
    GPShootBlock = set;
}

inputGamePadMaps usersInput::getGPPassSteal()  // retrieves the value of GPPassSteal
{
    return (GPPassSteal);
}
void usersInput::setGPPassSteal(inputGamePadMaps set)  // sets the value of GPPassSteal
{
    GPPassSteal = set;
}

inputGamePadMaps usersInput::getGPPause()  // retrieves the value of GPPause
{
    return (GPPause);
}
void usersInput::setGPPause(inputGamePadMaps set)  // sets the value of GPPause
{
    GPPause = set;
}

inputGamePadMaps usersInput::getGPStartSelect()  // retrieves the value of GPStartSelect
{
    return (GPStartSelect);
}
void usersInput::setGPStartSelect(inputGamePadMaps set)  // sets the value of GPStartSelect
{
    GPStartSelect = set;
}

bool usersInput::getActive()  // retrieves the value of active
{
    return (active);
}

void usersInput::setActive(bool set)  // sets the value of active
{
    active = set;
}
