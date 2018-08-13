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

#ifndef _PLAYERENTITY_H_
#define _PLAYERENTITY_H_

#include "entity/entity.h"
#include "physics/playerphysics.h"

class playerComponents;
class playerData;
class playerFlags;
class playerGameData;
class playerStateMachine;
class playerSMData;
class playerStatistics;
class playerSteer;


class playerEntity : public entity
{
    public:
    playerEntity();  // constructor
    ~playerEntity();  // destructor
    
    playerComponentsSharedPtr getComponent();  // retrieves the value of component
    void setComponent(playerComponentsSharedPtr set);  // sets the value of component

    playerDataSharedPtr getData();  // retrieves the value of data
    void setData(playerDataSharedPtr set);  // sets the value of data

    playerFlagsSharedPtr getFlag();  // retrieves the value of flag
    void setFlag(playerFlagsSharedPtr set);  // sets the value of flag

    playerGameDataSharedPtr getGameData();  // retrieves the value of gameData
    void setGameData(playerGameDataSharedPtr set);  // sets the value of gameData

    bool initialize();  // initializes the court entity object

    bool setupPhysicsObject();  // sets up the physics object
 
    bool initializeStateMachine();  // initializes the stateMachine object
    
    bool updateStateMachine(playerActions actionType, playerSMData *SMData);  // updates state machine with external input
    
    bool update(); // executes any updates that need to be performed

    private:

    playerComponentsSharedPtr component;  // instance of playerData object

    playerDataSharedPtr data;  // instance of playerData object
    
    playerFlagsSharedPtr flag;  // instance of playerFlags object

    playerGameDataSharedPtr gameData;  // instance of playerGameData object
    
    playerSMData *SMData; // state machine data object

};

#endif // _PLAYERENTITY_H_
