/***************************************************************************
 *   Copyright (C) 1999 - 2018 by Mike McLean   *
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

 
#include "users/usersinputs.h"

/*
// static declarations
inputTypes usersInputs::type;
inputKeyMaps usersInputs::keyUp;
inputKeyMaps usersInputs::keyDown;
inputKeyMaps usersInputs::keyLeft;
inputKeyMaps usersInputs::keyRight;
inputKeyMaps usersInputs::keyUpLeft;
inputKeyMaps usersInputs::keyUpRight;
inputKeyMaps usersInputs::keyDownLeft;
inputKeyMaps usersInputs::keyDownRight;
inputKeyMaps usersInputs::keyShootBlock;
inputKeyMaps usersInputs::keyPassSteal;
inputKeyMaps usersInputs::keyPause;
inputKeyMaps usersInputs::keyStartSelect;
inputKeyMaps usersInputs::keyQuit;
    
 // joystick input strings
inputGamePadMaps usersInputs::GPUp;
inputGamePadMaps usersInputs::GPDown;
inputGamePadMaps usersInputs::GPLeft;
inputGamePadMaps usersInputs::GPRight;
inputGamePadMaps usersInputs::GPUpLeft;
inputGamePadMaps usersInputs::GPUpRight;
inputGamePadMaps usersInputs::GPDownLeft;
inputGamePadMaps usersInputs::GPDownRight;
inputGamePadMaps usersInputs::GPShootBlock;
inputGamePadMaps usersInputs::GPPassSteal;
inputGamePadMaps usersInputs::GPPause;
inputGamePadMaps usersInputs::GPStartSelect;
inputGamePadMaps usersInputs::GPQuit;
*/

usersInputs::usersInputs()
{
    keyUp = INKEY_NONE;
    active = false;
}

usersInputs::~usersInputs()  = default;  // destructor

std::string usersInputs::getName() const // retrieves the value of name
{
    return (name);
}
void usersInputs::setName(const std::string &set)  // sets the value of name
{
    name = set;
}

inputTypes usersInputs::getType() const  // retrieves the value of type
{
    return (type);
}
void usersInputs::setType(const inputTypes &set)  // sets the value of type
{
    type = set;
}

inputKeyMaps usersInputs::getKeyUp() const  // retrieves the value of keyUp
{
    return (keyUp);
}
void usersInputs::setKeyUp(const inputKeyMaps &set)  // sets the value of keyUp
{
    keyUp = set;
}

inputKeyMaps usersInputs::getKeyDown() const  // retrieves the value of keyDown
{
    return (keyDown);
}
void usersInputs::setKeyDown(const inputKeyMaps &set)  // sets the value of keyDown
{
    keyDown = set;
}
inputKeyMaps usersInputs::getKeyLeft() const  // retrieves the value of keyLeft
{
    return (keyLeft);
}
void usersInputs::setKeyLeft(const inputKeyMaps &set)  // sets the value of keyLeft
{
    keyLeft = set;
}

inputKeyMaps usersInputs::getKeyRight() const  // retrieves the value of keyRight
{
    return (keyRight);
}
void usersInputs::setKeyRight(const inputKeyMaps &set)  // sets the value of keyRight
{
    keyRight = set;
}

inputKeyMaps usersInputs::getKeyUpLeft() const  // retrieves the value of keyUpLeft
{
    return (keyUpLeft);
}
void usersInputs::setKeyUpLeft(const inputKeyMaps &set)  // sets the value of keyUpLeft
{
    keyUpLeft = set;
}

inputKeyMaps usersInputs::getKeyUpRight() const  // retrieves the value of keyUpRight
{
    return (keyUpRight);

}
void usersInputs::setKeyUpRight(const inputKeyMaps &set)  // sets the value of keyUpRight
{
    keyUpRight = set;
}

inputKeyMaps usersInputs::getKeyDownLeft() const  // retrieves the value of keyDownLeft
{
    return (keyDownLeft);
}
void usersInputs::setKeyDownLeft(const inputKeyMaps &set)  // sets the value of keyDownLeft
{
    keyDownLeft = set;
}

inputKeyMaps usersInputs::getKeyDownRight() const  // retrieves the value of keyDownRight
{
    return (keyDownRight);
}
void usersInputs::setKeyDownRight(const inputKeyMaps &set)  // sets the value of keyDownRight
{
    keyDownRight = set;
}

inputKeyMaps usersInputs::getKeyShootBlock() const  // retrieves the value of keyShootBlock
{
    return (keyShootBlock);
}
void usersInputs::setKeyShootBlock(const inputKeyMaps &set)  // sets the value of keyShootBlock
{
    keyShootBlock = set;
}

inputKeyMaps usersInputs::getKeyPassSteal() const  // retrieves the value of keyPassSteal
{
    return (keyPassSteal);
}
void usersInputs::setKeyPassSteal(const inputKeyMaps &set)  // sets the value of keyPassSteal
{
    keyPassSteal = set;
}

inputKeyMaps usersInputs::getKeyPause() const  // retrieves the value of keyPause
{
    return (keyPause);
}
void usersInputs::setKeyPause(const inputKeyMaps &set)  // sets the value of keyPause
{
    keyPause = set;
}

inputKeyMaps usersInputs::getKeyStartSelect() const  // retrieves the value of keyStartSelect
{
    return (keyStartSelect);
}
void usersInputs::setKeyStartSelect(const inputKeyMaps &set)  // sets the value of keyStartSelect
{
    keyStartSelect = set;
}

inputKeyMaps usersInputs::getKeyQuit() const  // retrieves the value of keyStartSelect
{
    return (keyQuit);
}
void usersInputs::setKeyQuit(const inputKeyMaps &set)  // sets the value of keyStartSelect
{
    keyQuit = set;
}
inputGamePadMaps usersInputs::getGPUp() const  // retrieves the value of GPUp
{
    return (GPUp);
}
void usersInputs::setGPUp(const inputGamePadMaps &set)  // sets the value of GPUp
{
    GPUp = set;
}
    
inputGamePadMaps usersInputs::getGPDown() const  // retrieves the value of GPDown
{
    return (GPDown);
}
void usersInputs::setGPDown(const inputGamePadMaps &set)  // sets the value of GPDown
{
    GPDown = set;
}

inputGamePadMaps usersInputs::getGPLeft() const  // retrieves the value of GPLeft
{
    return (GPLeft);
}
void usersInputs::setGPLeft(const inputGamePadMaps &set)  // sets the value of GPLeft
{
    GPLeft = set;
}
    
inputGamePadMaps usersInputs::getGPRight() const  // retrieves the value of GPRight
{
    return (GPRight);
}
void usersInputs::setGPRight(const inputGamePadMaps &set)  // sets the value of GPRight
{
    GPRight = set;
}
    
inputGamePadMaps usersInputs::getGPUpLeft() const  // retrieves the value of GPUpLeft
{
    return (GPUpLeft);
}
void usersInputs::setGPUpLeft(const inputGamePadMaps &set)  // sets the value of GPUpLeft
{
    GPUpLeft = set;
}
    
inputGamePadMaps usersInputs::getGPUpRight() const  // retrieves the value of GPUpRight
{
    return (GPUpRight);
}
void usersInputs::setGPUpRight(const inputGamePadMaps &set)  // sets the value of GPUpRight
{
    GPUpRight = set;
}
    
inputGamePadMaps usersInputs::getGPDownLeft() const  // retrieves the value of GPDownLeft
{
    return (GPDownLeft);
}
void usersInputs::setGPDownLeft(const inputGamePadMaps &set)  // sets the value of GPDownLeft
{
    GPDownLeft = set;
} 
    
inputGamePadMaps usersInputs::getGPDownRight() const  // retrieves the value of GPDownRight
{
    return (GPDownRight); 
}
void usersInputs::setGPDownRight(const inputGamePadMaps &set)  // sets the value of GPDownRight
{
    GPDownRight = set;
}
    
inputGamePadMaps usersInputs::getGPShootBlock() const // retrieves the value of GPShootBlock
{
    return (GPShootBlock);
}
void usersInputs::setGPShootBlock(const inputGamePadMaps &set)  // sets the value of GPShootBlock
{
    GPShootBlock = set;
}

inputGamePadMaps usersInputs::getGPPassSteal() const  // retrieves the value of GPPassSteal
{
    return (GPPassSteal);
}
void usersInputs::setGPPassSteal(const inputGamePadMaps &set)  // sets the value of GPPassSteal
{
    GPPassSteal = set;
}

inputGamePadMaps usersInputs::getGPPause() const  // retrieves the value of GPPause
{
    return (GPPause);
}
void usersInputs::setGPPause(const inputGamePadMaps &set)  // sets the value of GPPause
{
    GPPause = set;
}

inputGamePadMaps usersInputs::getGPStartSelect() const  // retrieves the value of GPStartSelect
{
    return (GPStartSelect);
}
void usersInputs::setGPStartSelect(const inputGamePadMaps &set)  // sets the value of GPStartSelect
{
    GPStartSelect = set;
}

inputGamePadMaps usersInputs::getGPQuit() const  // retrieves the value of GPQuit
{
    return (GPQuit);
}
void usersInputs::setGPQuit(const inputGamePadMaps &set)  // sets the value of GPQuit
{
    GPQuit = set;
}

bool usersInputs::getActive() const  // retrieves the value of active
{
    return (active);
}

void usersInputs::setActive(const bool &set)  // sets the value of active
{
    active = set;
}
