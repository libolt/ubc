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

#ifndef _HOOPSTATEMACHINE_H_
#define _HOOPSTATEMACHINE_H_

#ifdef _MSC_VER
#define NOMINMAX
#include "winsock2.h"
#endif

#include "statemachine/statemachine.h"
#include "utilities/typedefs.h"

class renderEngine;

class hoopSMData : public eventData
{
public:

    hoopComponentsSharedPtr component;  // stores copy of hoopComponents object
//    hoopDataSharedPtr cData;  // stores copy of hoopData object
    hoopFlagsSharedPtr flag;  // stores copy of hoopFlags object

    OgreEntitySharedPtr model;  // stores 3d model
    OgreSceneNodeSharedPtr node;  // stores node 3d model is attached to
    renderEngineSharedPtr render;  // stores copy of render

private:
//    hoopPhysicsSharedPtr physics;  // stores copy of hoopPhysics object
/*    gameComponentsSharedPtr gComponent;  // stores copy of gameComponent object
    gameDataSharedPtr gData;  // stores copy of gameData object
    gameFlagsSharedPtr gFlag;  // stores copy of gameFlag object
*/

};

class hoopStateMachine : public stateMachine
{
public:
    hoopStateMachine();

    // External events taken by this state machine
    void pInitialize(const hoopSMData *data);
    void pInitializeComponents(hoopSMData *data);
    void pLoadModel(hoopSMData *data);
    void pCreateNode(hoopSMData *data);
    void pSetupPhysics(hoopSMData *data);
    void pUpdatePosition(hoopSMData *data);
    void pUpdateMovement(hoopSMData *data);
    void pUpdateDirection(hoopSMData *data);
    void halt();

private:
    INT m_currentSpeed; 

    // State enumeration order must match the order of state method entries
    // in the state map.
    enum States
    {
        ST_INITIALIZE,
        ST_INITIALIZE_COMPONENTS,
        ST_LOAD_MDOEL,
        ST_CREATE_NODE,
        ST_SETUP_PHYSICS, 
        ST_STOP_MOVEMENT,
        ST_IDLE,        
        ST_UPDATE_POSITION,
        ST_UPDATE_MOVEMENT,
        ST_UPDATE_DIRECTION, 
        ST_MAX_STATES
    };

    // Define the state machine state functions with event data type
    STATE_DECLARE(hoopStateMachine,    Initialize,     hoopSMData)
    STATE_DECLARE(hoopStateMachine,    InitializeComponents,    hoopSMData)
    STATE_DECLARE(hoopStateMachine,    LoadModel,     hoopSMData)
    STATE_DECLARE(hoopStateMachine,    CreateNode,     hoopSMData)
    STATE_DECLARE(hoopStateMachine,    SetupPhysics,   hoopSMData)
    STATE_DECLARE(hoopStateMachine,    StopMovement,   noEventData)
    STATE_DECLARE(hoopStateMachine,    Idle,           noEventData)
    STATE_DECLARE(hoopStateMachine,    UpdatePosition, hoopSMData)
    STATE_DECLARE(hoopStateMachine,    UpdateMovement, hoopSMData)
    STATE_DECLARE(hoopStateMachine,    UpdateDirection, hoopSMData)

    // State map to define state object order. Each state map entry defines a
    // state object.
    BEGIN_STATE_MAP
        STATE_MAP_ENTRY(&Initialize)
        STATE_MAP_ENTRY(&InitializeComponents)
        STATE_MAP_ENTRY(&LoadModel)
        STATE_MAP_ENTRY(&CreateNode)
        STATE_MAP_ENTRY(&SetupPhysics)
        STATE_MAP_ENTRY(&StopMovement)
        STATE_MAP_ENTRY(&Idle)
        STATE_MAP_ENTRY(&UpdatePosition)
        STATE_MAP_ENTRY(&UpdateMovement)
        STATE_MAP_ENTRY(&UpdateDirection)
    END_STATE_MAP   
};

#endif
