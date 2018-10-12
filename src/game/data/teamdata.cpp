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

#include "data/teamdata.h"

// static declarations
//size_t teamData::ID; 

// teamData constructor
teamData::teamData()
{

    name = '\0';	// string array of team names
    city = '\0';
    coach = '\0';
    inits = '\0';
    logoFile = '\0';

    ID = 0;

    playerNum = 0;

    for (int x = 0; x < 5; ++x)
    {
        starters.push_back(-1);
    }
}

teamData::~teamData()
{
//	delete [] teamStarters;
}

std::string teamData::getCity() const  // retrieves the value of city
{
    return(city);
}

void teamData::setCity(const std::string &set)  // sets the value of city
{
    city = set;
}

std::string teamData::getName() const  // retrieves the value of name
{
    return(name);
}

void teamData::setName(const std::string &set)  // sets the value of name
{
    name = set;
}

std::string teamData::getCoach() const  // retrieves the value of coach
{
    return(coach);
}

void teamData::setCoach(const std::string &set)  // sets the value of coach
{
    coach = set;
}

sizeTVec teamData::getRoster() const  // retrieves the value of roster
{
    return(roster);
}

void teamData::setRoster(const sizeTVec &set)  // sets the value of roster
{
    roster = set;
}

size_t teamData::getPlayerNum() const  // retrieves the value of playetNum
{
    return(playerNum);
}

void teamData::setPlayerNum(const size_t &set)  // sets the value of player
{
    playerNum = set;
}

sizeTVec teamData::getStarters() const  // retrieves the value of starters
{
    return(starters);
}

void teamData::setStarters(const sizeTVec &set)  // sets the value of starters
{
    starters = set;
}

size_t teamData::getID() const  // retrieves the value of ID
{
    return(ID);
}
void teamData::setID(const size_t &set)  // sets the value of ID
{
    ID = set;
}

std::string teamData::getInits() const  // retrieves the value of inits
{
    return(inits);
}

void teamData::setInits(const std::string &set)  // sets the value of inits
{
    inits = set;
}

std::string teamData::getLogoFile() const  // retrieves the value of logoFile
{
    return(logoFile);
}

void teamData::setLogoFile(const std::string &set)  // sets the value logoFile
{
    logoFile = set;
}

