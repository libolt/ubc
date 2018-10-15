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
 
#ifndef _LOAD_TEAMS_H_
#define _LOAD_TEAMS_H_

#include <string>
#include <vector>
#include <unordered_map>
#include "load/load.h"
#include "utilities/typedefs.h"

class loadTeams : public loader
{
    public:
    
        loadTeams();  // constructor
        ~loadTeams();  // destructor
    
        stdStringVec getTeamFiles() const;  // retrieves the value of teamFiles
        void setTeamFiles(const stdStringVec &set);  // sets the value of teamFiles

        teamEntityMSharedPtr getTInstance() const;  // retrieves the value of tInstance
        void setTInstance(const teamEntityMSharedPtr &set);  // sets the value of tInstance
    
        bool getTeamFilesLoaded() const;  // retrieves the value of teamFilesLoaded
        void setTeamFilesLoaded(const bool &set);  // sets the value of teamFilesLoaded
    
        bool checkIfTeamsLoaded();  // checks if teams have been loaded into tInstance

        // Teams
        teamEntityMSharedPtr loadTeamFiles();  // loads team data from XML files
        stdStringVec loadTeamListFile(std::string fileName);  // loads list of team files from teams.xml
        teamEntitySharedPtr loadTeamFile(std::string fileName);  // loads data from the team XML files
    
    private:
    
        teamEntityMSharedPtr tInstance;
        bool teamFilesLoaded;
        stdStringVec teamFiles;   // stores list of team xml files

};

#endif
