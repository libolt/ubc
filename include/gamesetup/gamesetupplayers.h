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

#ifndef _GAMESETUPPLAYERS_H_
#define _GAMESETUPPLAYERS_H_

#include "utilities/typedefs.h"

class gameSetupPlayers
{
    public:

        gameSetupPlayers();  // constructor
        ~gameSetupPlayers();  // destructor

        bool checkIfGamePlayerInstancesCreated(gameComponentsSharedPtr gameComponent, gameFlagsSharedPtr gameFlag);  // checks if the gameState Objects Player Instances have been created
        bool checkIfTeamPlayerInstancesCreated(playerEntityMSharedPtr gamePlayerInstance, teamStateMSharedPtr activeTeamInstance);  // checks if the gameState Objects Player Instances have been created
        playerEntityMSharedPtr createPlayerInstances();  // creates player Instances
        playerEntityMSharedPtr createTeamPlayerInstances(playerEntityMSharedPtr gamePlayerInstance, size_t teamID);  // creates player instances for a team
        playerEntityMSharedPtr createActivePlayerInstances(playerEntityMSharedPtr playerInstance,std::unordered_map<std::string, size_t> activePlayerID);  // creates active player instances
        playerEntityMSharedPtr setupActivePlayerInstances(playerEntityMSharedPtr playerInstance);  // sets up active player instances

    private:

};

#endif

