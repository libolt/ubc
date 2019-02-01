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

#ifndef _TEAMDATA_H_
#define _TEAMDATA_H_

#include <string>
#include <vector>

#include "utilities/typedefs.h"

class teamData
{
    public:
    teamData();  // constructor
    ~teamData();  // destructor

    std::string getName() const;  // retrieves the value of name
    void setName(const std::string &set);  // sets the value of name

    std::string getCity() const; // retrieves the value of city
    void setCity(const std::string &set);  // sets the value of city

    std::string getCoach() const;  // retrieves the value of coach
    void setCoach(const std::string &set);  // sets the value of coach

    sizeTVec getRoster() const;  // retrieves the value of roster
    void setRoster(const sizeTVec &set);  // sets the value of roster

    size_t getPlayerNum() const;  // retrieves the value of playerNum
    void setPlayerNum(const size_t &set);  // sets the value of playerNum

    sizeTVec getStarters() const;  // retrieves the value of starters
    void setStarters(const sizeTVec &set); // sets the value of starters

    size_t getID() const;  // retrieves the value of ID
    void setID(const size_t &set);  // sets the value of ID

    std::string getInits() const;  // retrieves the value of inits
    void setInits(const std::string &set);  // sets the vlaue of inits

    std::string getLogoFile() const;  // retrieves the value of logoFile
    void setLogoFile(const std::string &set);  // sets the value of logoFile


private:
    std::string name;  // stores team name
    std::string city;  //  stores home city for team
    std::string coach;  // stores team's coach name
    std::string inits;  // stores initials used for team
    std::string logoFile;  // stores the name of the file used for team logo
    size_t ID;  // stores the team's ID number

    sizeTVec roster;  // stores the list of player IDs associated with the team.
    size_t playerNum;  // stores total number of players on the team

    sizeTVec starters;  // store the IDs of the starting players

};


#endif // _TEAMDATA_H_
