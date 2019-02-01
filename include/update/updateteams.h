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

#ifndef _UPDATETEAMS_H_
#define _UPDATETEAMS_H_

#include "utilities/typedefs.h"

class updateTeams
{
    public:
    
        updateTeams();  // constructor
        ~updateTeams();  // destructor
        
        playerEntityMSharedPtr updateActivePlayers(playerEntityMSharedPtr activePlayerInstance);  // updates the states of active players
        playerEntityMSharedPtr updatePlayerDirections(playerEntityMSharedPtr activePlayerInstance, const gameComponentsSharedPtr &gameComponent, const teamGameDataSharedPtr &gameData);  // updates the direction players are facing
        playerEntityMSharedPtr updatePlayerMovements(playerEntityMSharedPtr activePlayerInstance);   // updates the movement status of players
        playerEntityMSharedPtr updatePositions(playerEntityMSharedPtr activePlayerInstance);  // updates player on court positionss
        playerEntityMSharedPtr updateActivePlayerSettings(playerEntityMSharedPtr activePlayerInstance);  // updates the settings of active players

    private:
    
};

#endif
