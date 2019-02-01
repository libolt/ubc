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

#ifndef _GAMESETUPLINEUPS_H_
#define _GAMESETUPLINEUPS_H_

#include "utilities/typedefs.h"

class setupLineups
{
    public:
    
        setupLineups();  // constructor
        ~setupLineups();  // destructor
        
        std::vector<std::map <playerPositions, std::string> > createTeamStarters(teamEntityMSharedPtr activeTeamInstance);  // creates the teamStarters instance
        teamStarterIDsVecM createTeamStarterID(std::vector<std::map <playerPositions, std::string> > teamStarters, teamEntityMSharedPtr activeTeamInstance);  // creates the object with each team's starter IDs

//        bool checkPlayerInstancesCreated(teamEntityMSharedPtr activeTeamInstance);  // checks if player instances have been created
//        teamEntityMSharedPtr createActivePlayerInstances(teamEntityMSharedPtr activeTeamInstance, std::vector<std::unordered_map<std::string, size_t> > teamStarterID);  // creates the active playerInstances
        bool checkActivePlayerInstancesCreated(teamEntityMSharedPtr activeTeamInstance);
        teamEntityMSharedPtr setupStartingLineups(teamEntityMSharedPtr activeTeamInstance, teamStarterIDsVecM teamStarterID);  // sets starting lineups for each team

    private:
    
};

#endif

