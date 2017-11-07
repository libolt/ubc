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

#include "gamesetup/gamesetupteams.h"
#include "utilities/conversion.h"
#include "state/teamstate.h"
#include "utilities/logging.h"

gameSetupTeams::gameSetupTeams()  // constructor
{
    
}
gameSetupTeams::~gameSetupTeams()  // destructor
{
    
}

teamStateMSharedPtr gameSetupTeams::createActiveTeamInstances(teamStateMSharedPtr teamInstance, sizeTVec teamID)  // creates active team instances
{
    teamStateMSharedPtr activeTeamInstance;
    std::string func = "gameSetupTeams::createActiveTeamInstances()";
       
    logMsg(func +" beginning");
    
    sizeTVec::iterator TIDIT;
    for (TIDIT = teamID.begin(); TIDIT != teamID.end(); ++TIDIT)
    {
        activeTeamInstance.insert(std::pair<size_t, teamStateSharedPtr>(*TIDIT, teamInstance[*TIDIT]));
    }
    
    logMsg(func +" end");
    
    return (activeTeamInstance);
}
