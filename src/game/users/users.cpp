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

#include "users/users.h"
#include "users/usersinputs.h"

users::users()  // constructor
{
    name = "";
    ID = 0;
    team = NOTEAM;
    player = NONE;
    type = NOUSER;
    inputType = INNOTYPE;
    userInput = nullptr;
}
users::~users() = default;  // destructor

std::string users::getName() const  // retrieves the value of name
{
    return (name);
}
void users::setName(const std::string &set)  // sets the value of name
{
    name = set;
}

size_t users::getID() const  // retrieves the value
{
    return (ID);
}
void users::setID(const size_t &set)  // sets the value of ID
{
    ID = set;
}

teamTypes users::getTeam() const  // retrieves the value of team
{
    return (team);
}

void users::setTeam(const teamTypes &set)  // sets the value of team
{
    team = set;
}

playerPositions users::getPlayer() const  // retrieves the value of player
{
    return (player);
}
void users::setPlayer(const playerPositions &set)  // sets the value of player
{
    player = set;
}

userTypes users::getType() const  // retrieves the value of type
{
    return (type);
}
void users::setType(const userTypes &set)  // sets the value of type
{
    type = set;
}

usersInputsSharedPtr users::getUserInput() const  // retrieves the value of userInput
{
    return (userInput);
}
void users::setUserInput(const usersInputsSharedPtr &set)  // sets the value of userInput
{
    userInput = set;
}

inputTypes users::getInputType() const  // retrieves the value of inputType
{
    return (inputType);
}
void users::setInputType(const inputTypes &set)  // sets the value of inputType
{
    inputType = set;
}
