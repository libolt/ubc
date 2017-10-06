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

#include "user/user.h"

users::users()  // constructor
{
    
}
users::~users()  // destructor
{
    
}

std::string users::getName()  // retrieves the value of name
{
    return (name);
}
void users::setName(std::string set)  // sets the value of name
{
    name = set;
}

size_t users::getID()  // retrieves the value
{
    return (ID);
}
void users::setID(size_t set)  // sets the value of ID
{
    ID = set;
}

teamTypes users::getTeam()  // retrieves the value of team
{
    return (team);
}

void users::setTeam(teamTypes set)  // sets the value of team
{
    team = set;
}

playerPositions users::getPlayer()  // retrieves the value of player       
{
    return (player);
}
void users::setPlayer(playerPositions set)  // sets the value of player
{
    player = set;
}
