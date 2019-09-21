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

#ifndef _BASKETBALLSTATEMACHINE_H_
#define _BASKETBALLSTATEMACHINE_H_

#ifdef _MSC_VER
#define NOMINMAX
#include "winsock2.h"
#endif

#include "statemachine/statemachine.h"
#include "utilities/typedefs.h"

class basketballSMData : public eventData
{
public:

    basketballComponentsSharedPtr component;  // stores copy of basketballComponents object
    basketballDataSharedPtr bData;  // stores copy of basketballData object
    basketballFlagsSharedPtr flag;  // stores copy of basketballFlags object
#ifdef BTOGRE_MYGUI_ENABLED
    basketballPhysicsSharedPtr physics;  // stores copy of basketballPhysics object
#endif

    gameComponentsSharedPtr gComponent;  // stores copy of gameComponent object
    gameDataSharedPtr gData;  // stores copy of gameData object
    gameFlagsSharedPtr gFlag;  // stores copy of gameFlag object

    OgreEntitySharedPtr model;  // stores 3d model
    OgreSceneNodeSharedPtr node;  // stores node 3d model is attached to
    renderEngineSharedPtr render; // stores copy of render

};

class basketballStateMachine : public stateMachine
{
public:
    basketballStateMachine();

    // External events taken by this state machine
    void setSpeed(basketballSMData *data);
    void pInitialize(basketballSMData *data);
    void pLoadModel(basketballSMData *data);
    void pCreateNode(basketballSMData *data);
    void pSetupPhysics(basketballSMData *data);
    void pUpdatePosition(basketballSMData *data);
    void pUpdateMovement(basketballSMData *data);
    void pUpdateDirection(basketballSMData *data);
    void halt();

private:
    INT m_currentSpeed; 

    // State enumeration order must match the order of state method entries
    // in the state map.
    enum States
    {
        ST_INITIALIZE,
        ST_LOAD_MODEL,
        ST_CREATE_NODE,
        ST_SETUP_PHYSICS, 
        ST_STOP_MOVEMENT,
        ST_IDLE, 
        ST_CHANGE_SPEED,
        ST_UPDATE_POSITION,
        ST_UPDATE_MOVEMENT,
        ST_UPDATE_DIRECTION, 
        ST_MAX_STATES
    };

    // Define the state machine state functions with event data type
    STATE_DECLARE(basketballStateMachine,    Initialize,      basketballSMData)
    STATE_DECLARE(basketballStateMachine,    LoadModel,       basketballSMData)
    STATE_DECLARE(basketballStateMachine,    CreateNode,      basketballSMData)
    STATE_DECLARE(basketballStateMachine,    SetupPhysics,    basketballSMData)
    STATE_DECLARE(basketballStateMachine,    StopMovement,    noEventData)
    STATE_DECLARE(basketballStateMachine,    Idle,            noEventData)
    STATE_DECLARE(basketballStateMachine,    ChangeSpeed,     basketballSMData)
    STATE_DECLARE(basketballStateMachine,    UpdatePosition,  basketballSMData)
    STATE_DECLARE(basketballStateMachine,    UpdateMovement,  basketballSMData)
    STATE_DECLARE(basketballStateMachine,    UpdateDirection, basketballSMData)

    // State map to define state object order. Each state map entry defines a
    // state object.
    BEGIN_STATE_MAP
        STATE_MAP_ENTRY(&Initialize)
        STATE_MAP_ENTRY(&LoadModel)
        STATE_MAP_ENTRY(&CreateNode)
        STATE_MAP_ENTRY(&SetupPhysics)
        STATE_MAP_ENTRY(&StopMovement)
        STATE_MAP_ENTRY(&Idle)
        STATE_MAP_ENTRY(&ChangeSpeed)
        STATE_MAP_ENTRY(&UpdatePosition)
        STATE_MAP_ENTRY(&UpdateMovement)
        STATE_MAP_ENTRY(&UpdateDirection)
    END_STATE_MAP   
};

#endif
