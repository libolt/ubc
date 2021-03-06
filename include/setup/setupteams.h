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

#ifndef _GAMESETUPTEAMS_H_
#define _GAMESETUPTEAMS_H_

#include "utilities/typedefs.h"

class setupTeams
{
    public:
    
        setupTeams();  // constructor
        ~setupTeams();  // destructor
        
        teamEntityMSharedPtr createTeamInstances();  // creates team Instances
        teamEntityMSharedPtr createActiveTeamInstances(
                teamEntityMSharedPtr teamInstance, sizeTVec teamID);  // creates active team instances
        
        playerEntityMSharedPtr setPlayerStartPositions(
                playerEntityMSharedPtr activePlayerInstance,
                courtEntityMSharedPtr courtInstance,
                const teamGameDataSharedPtr &gameData,
                const teamStarterIDsVecM &teamStarterID);  // sets the initial coordinates for the players.
        playerEntityMSharedPtr setPlayerStartActivePositions(
                playerEntityMSharedPtr activePlayerInstance);  // sets the position the players will play at the start of the game

        playerEntityMSharedPtr setPlayerStartDirections(
                playerEntityMSharedPtr activePlayerInstance,
                const teamGameDataSharedPtr &gameData);  // sets the initial directions for the players.

    private:
    
};

#endif
