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

#ifndef _GAMESETUPS_H_
#define _GAMESETUPS_H_

#include "utilities/typedefs.h"

class gameSetups
{
    public:
    
        gameSetups();  // constructor
        ~gameSetups();  // destructor
        
        std::vector<std::unordered_map <std::string, std::string> > createTeamStarters(teamStateUMSharedPtr activeTeamInstance);  // creates the teamStarters instance
        std::vector<std::unordered_map<std::string, size_t> > createTeamStarterID(std::vector<std::unordered_map <std::string, std::string> > teamStarters, teamStateUMSharedPtr activeTeamInstance);  // creates the object with each team's starter IDs

        bool setupStartingLineups(teamStateUMSharedPtr activeTeamInstance, std::vector<std::unordered_map <std::string, std::string> > teamStarters, std::vector<std::unordered_map<std::string, size_t> > teamStarterID);  // sets starting lineups for each team

    private:
    
};

#endif

