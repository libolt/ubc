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

#ifndef _TEAMSATE_H_
#define _TEAMSATE_H_

#include <vector>
#include "OgreString.h"
#include "BulletDynamics/Dynamics/btRigidBody.h"

//#include "state/offensestate.h"
//#include "state/defensestate.h"
//#include "state/basketballstate.h"
//#include "state/playerstate.h"
#include "state/state.h"
#include "state/gamestateshared.h"
#include "data/teamdata.h"
#include "utilities/typedefs.h"

class gameFlags;
class gameData;
class offenseState;
class defenseState;
class basketballState;
class playerState;
class teamStatistics;
//class state;
//class teamData;

class teamState : public state, public teamData

{
public:

    teamState();  // constructor
    ~teamState();  // destructor

    bool setPlayerStartPositions(courtStateMSharedPtr courtInstance, teamStarterIDsVecM teamStarterID);	 // sets the initial coordinates for the players.
    void setPlayerStartActivePositions();  // sets the position the players will play at the start of the game

    bool setPlayerStartDirections();  // sets the initial directions for the players.

    void updateActivePlayers();  // updates the states of active players
    void updatePlayerDirections(gameComponentsSharedPtr gameComponent);  // updates the direction players are facing
    void updatePlayerMovements();	// updates the movement status of players

    void executePass();  // executes the pass between players

    void updatePositions();  // updates player on court positionss


    void updateState(gameComponentsSharedPtr gameComponent, gameFlagsSharedPtr gameFlag, gameDataSharedPtr gameData, renderEngineSharedPtr render);  // updates the state of the teamState object
    void updateActivePlayerSettings();  // updates the settings of active players
        
protected:
private:
    
};

#endif // _TEAMSATE_H_
