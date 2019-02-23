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
    
    bool getComponentInitialized() const;  // retrieves the value of componentInitialized
    void setComponentInotialized(const bool &set);  // sets the value of componentInitialized
    
    bool getDataInitialized() const;  // retrieves the value of dataInitialized
    void setDataInotialized(const bool &set);  // sets the value of dataInitialized
 
    bool getFlagInitialized() const;  // retrieves the value of flagInitialized
    void setFlagInotialized(const bool &set);  // sets the value of flagInitialized
 
    bool getGameDataInitialized() const;  // retrieves the value of gameDataInitialized
    void setGameDataInotialized(const bool &set);  // sets the value of gameDataInitialized
    
    bool getObjectsInitialized() const;  //  retrieves the value of objectsInitialized
    void setObjectsInitialized(const bool &set);  //  sets the value of objectsInitialized

    playerComponentsSharedPtr getComponent() const;  // retrieves the value of component
    void setComponent(const playerComponentsSharedPtr &set);  // sets the value of component

    playerDataSharedPtr getData() const;  // retrieves the value of data
    void setData(const playerDataSharedPtr &set);  // sets the value of data

    playerFlagsSharedPtr getFlag() const;  // retrieves the value of flag
    void setFlag(const playerFlagsSharedPtr &set);  // sets the value of flag

    playerGameDataSharedPtr getGameData() const;  // retrieves the value of gameData
    void setGameData(const playerGameDataSharedPtr &set);  // sets the value of gameData

    bool initializeObjects();  // initializes the court entity object

    bool setupPhysicsObject();  // sets up the physics object
 
    bool initializeStateMachine();  // initializes the stateMachine object
    
    bool updateStateMachine(playerActions actionType, playerSMData *SMData);  // updates state machine with external input
    
    bool update(); // executes any updates that need to be performed

    private:

    bool componentInitialized;  // stores whether component object has been initialized
    
    bool dataInitialized;  // stores whether data object has been initialized
  
    bool flagInitialized;  // stores whether flag object has been initialized
  
    bool gameDataInitialized;  // stores whether gameData object has been initialized
  
    bool objectsInitialized;  //  stores whether or not objects have been initialized

    playerComponentsSharedPtr component;  // instance of playerData object

    playerDataSharedPtr data;  // instance of playerData object
    
    playerFlagsSharedPtr flag;  // instance of playerFlags object

    playerGameDataSharedPtr gameData;  // instance of playerGameData object
    
//    playerSMData *SMData; // state machine data object

};

#endif // _PLAYERENTITY_H_
