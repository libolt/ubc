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

#ifndef _TEAMDATA_H_
#define _TEAMDATA_H_

#include <string>
#include <vector>

#include "typedefs.h"

class teamData
{
    public:
    teamData();  // constructor
    ~teamData();  // destructor

    std::string getName();  // retrieves the value of name
    void setName(std::string set);  // sets the value of name

    std::string getCity();  // retrieves the value of city
    void setCity(std::string set);  // sets the value of city

    std::string getCoach();  // retrieves the value of coach
    void setCoach(std::string set);  // sets the value of coach

    sizeTVec getRoster();  // retrieves the value of roster
    void setRoster(sizeTVec set);  // sets the value of roster

    size_t getPlayerNum();  // retrieves the value of playerNum
    void setPlayerNum(size_t set);  // sets the value of playerNum

    sizeTVec getStarters();  // retrieves the value of starters
    void setStarters(sizeTVec set); // sets the value of starters

    size_t getID();  // retrieves the value of ID
    void setID(size_t set);  // sets the value of ID

    std::string getInits();  // retrieves the value of inits
    void setInits(std::string Inits);  // sets the vlaue of inits

    std::string getLogoFile();  // retrieves the value of logoFile
    void setLogoFile(std::string set);  // sets the value of logoFile


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
