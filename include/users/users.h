/***************************************************************************
 *   Copyright (C) 1999 - 2018 by Mike McLean                              *
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

#ifndef _USERS_H_
#define _USERS_H_

#include "utilities/enums.h"
#include "utilities/typedefs.h"
#include <string>

class usersInput;

class users
{
    public:
    
        users();  // constructor
        ~users();  // destructor
        
        std::string getName() const;  // retrieves the value of name
        void setName(const std::string &set);  // sets the value of name
        
        size_t getID() const;  // retrieves the value
        void setID(const size_t &set);  // sets the value of ID
        
        teamTypes getTeam() const;  // retrieves the value of team
        void setTeam(const teamTypes &set);  // sets the value of team
        
        playerPositions getPlayer() const;  // retrieves the value of player
        void setPlayer(const playerPositions &set);  // sets the value of player
        
        userTypes getType() const;  // retrieves the value of type
        void setType(const userTypes &set);  // sets the value of type
        
        inputTypes getInputType() const;  // retrieves the value of inputType
        void setInputType(const inputTypes &set);  // sets the value of inputType
        
        usersInputsSharedPtr getUserInput() const;  // retrieves the value of userInput
        void setUserInput(const usersInputsSharedPtr &set);  // sets the value of userInput
        
    private:
    
    std::string name;  // stores the user's name
    size_t ID;  // stores the user ID number
    teamTypes team;  // stores which team the user is part of
    playerPositions player;  // stores the player being controlled by the user
    userTypes type;  // stores whether the user is local to the system or connected over a network
    inputTypes inputType;  // stores the type of input used by the user
    usersInputsSharedPtr userInput;  // stores the input mapping for user
};

#endif

