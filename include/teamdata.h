/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean   *
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

#ifndef _TEAMDATA_H_
#define _TEAMDATA_H_

#include <string>
#include <vector>

using namespace std;

class teamData
{
    public:
    teamData();  // constructor
    ~teamData();  // destructor

    string getName(void);  // retrieves the value of name
    void setName(string Name);  // sets the value of name

    string getCity(void);  // retrieves the value of city
    void setCity(string City);  // sets the value of city

    string getCoach(void);  // retrieves the value of coach
    void setCoach(string Coach);  // sets the value of coach

    std::vector<int> getRoster(void);  // retrieves the value of roster
    void setRoster(std::vector<int> Roster);  // sets the value of roster

    int getPlayerNum(void);  // retrieves the value of playerNum
    void setPlayerNum(int num);  // sets the value of playerNum

    std::vector<int> getStarters(void);  // retrieves the value of starters
    void setStarters(std::vector<int> Starters); // sets the value of starters

    int getID(void);  // retrieves the value of ID
    void setID(int teams);  // sets the value of ID

    string getInits(void);  // retrieves the value of inits
    void setInits(string Inits);  // sets the vlaue of inits

    string getLogoFile(void);  // retrieves the value of logoFile
    void setLogoFile(string file);  // sets the value of logoFile


private:
    string name;  // stores team name
    string city;  //  stores home city for team
    string coach;  // stores team's coach name
    string inits;  // stores initials used for team
    string logoFile;  // stores the name of the file used for team logo
    int ID;  // stores the team's ID number

    std::vector<int> roster;  // stores the list of player IDs associated with the team.
    int playerNum;  // stores total number of players on the team

    std::vector<int> starters;  // store the IDs of the starting players

};


#endif // _TEAMDATA_H_
