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

#ifndef _GAMESTATEMACHINE_H_
#define _GAMESTATEMACHINE_H_

#include <cstdio>
#include "statemachine/statemachine.h"
#include "utilities/enums.h"
#include "utilities/typedefs.h"

class gameSMData : public eventData
{
public:
    size_t speed;
    directions direction;
    playerActions action;
    Ogre::Vector3 position;
    OgreEntitySharedPtr model;  // stores 3d model
    OgreSceneNodeSharedPtr node;  // stores node 3d model is attached to
};

class gameStateMachine : public stateMachine
{
public:
    gameStateMachine();

    // External events taken by this state machine
    void pCreateInstances(gameSMData *data);  // sets the node to that of the entity parent object
    void pSetStartPositions(gameSMData *data);  // sets the model to that of the entity parent object
    void pSetupTipOff(gameSMData *data);
    void pExecuteTipOff(gameSMData *data);
    void pPause();
    void pChangeScore(gameSMData *data);
    void pChangeQuarter(gameSMData *data);
    void pSetupFreethrow(gameSMData *data);
    void pExecuteFreethrow(gameSMData *data);
    void pChangePossession(gameSMData *data);

    
private:

    // State enumeration order must match the order of state method entries
    // in the state map.
    enum States
    {
        ST_CREATE_INSTANCES,
        ST_SET_START_POS,
        ST_SETUP_TIPOFF,
        ST_EXECUTE_TIPOFF,
        ST_PAUSE,
        ST_CHANGE_SCORE,  
        ST_CHANGE_QUARTER,
        ST_SETUP_FREETHROW,
        ST_EXECUTE_FREETHROW,
        ST_CHANGE_POSSESSION,
        ST_MAX_STATES
    };

    // Define the state machine state functions with event data type
    STATE_DECLARE(gameStateMachine,    createInstances,         gameSMData)
    STATE_DECLARE(gameStateMachine,    setStartPositions,        gameSMData)
    STATE_DECLARE(gameStateMachine,    setupTipOff,            gameSMData)
    STATE_DECLARE(gameStateMachine,    executeTipOff,    gameSMData)
    STATE_DECLARE(gameStateMachine,    pause,   noEventData)
    STATE_DECLARE(gameStateMachine,    changeScore,  gameSMData)
    STATE_DECLARE(gameStateMachine,    changeQuarter,     gameSMData)
    STATE_DECLARE(gameStateMachine,    setupFreethrow,            gameSMData)
    STATE_DECLARE(gameStateMachine,    executeFreethrow, gameSMData)
    STATE_DECLARE(gameStateMachine,    changePosession,           gameSMData)
//    STATE_DECLARE(gameStateMachine,    Pass,            gameSMData)

    // State map to define state object order. Each state map entry defines a
    // state object.
    BEGIN_STATE_MAP
        STATE_MAP_ENTRY(&createInstances)
        STATE_MAP_ENTRY(&setStartPositions)
        STATE_MAP_ENTRY(&setupTipOff)
        STATE_MAP_ENTRY(&executeTipOff)
        STATE_MAP_ENTRY(&pause)
        STATE_MAP_ENTRY(&changeScore)
        STATE_MAP_ENTRY(&changeQuarter)
        STATE_MAP_ENTRY(&setupFreethrow)
        STATE_MAP_ENTRY(&executeFreethrow)
        STATE_MAP_ENTRY(&changePosession)
//        STATE_MAP_ENTRY(&Pass)       
    END_STATE_MAP   
};

#endif
