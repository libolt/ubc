/***************************************************************************
 *   Copyright (C) 1999 - 2016 by Mike McLean   *
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

std::string teamData::getCity(void)
{
    return(city);
}

void teamData::setCity(std::string set)
{
    city = set;
}

std::string teamData::getName(void)
{
    return(name);
}

void teamData::setName(std::string set)
{
    name = set;
}

std::string teamData::getCoach(void)
{
    return(coach);
}

void teamData::setCoach(std::string set)
{
    coach = set;
}

sizeTVec teamData::getRoster(void)
{
    return(roster);
}

void teamData::setRoster(sizeTVec set)
{
    roster = set;
}

size_t teamData::getPlayerNum(void)
{
    return(playerNum);
}

void teamData::setPlayerNum(size_t set)
{
    playerNum = set;
}

sizeTVec teamData::getStarters(void)
{
    return(starters);
}

void teamData::setStarters(sizeTVec set)
{
    starters = set;
}

size_t teamData::getID(void)
{
    return(ID);
}
void teamData::setID(size_t set)
{
    ID = set;
}

std::string teamData::getInits(void)
{
    return(inits);
}

void teamData::setInits(std::string set)
{
    inits = set;
}

// gets and sets file storing team logo
std::string teamData::getLogoFile(void)
{
    return(logoFile);
}

void teamData::setLogoFile(std::string set)
{
    logoFile = set;
}

