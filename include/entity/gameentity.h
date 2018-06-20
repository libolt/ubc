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

#ifndef _GAMEENTITY_H_
#define _GAMEENTITY_H_

#include <vector>
//#include <boost/shared_ptr.hpp>
#include "BulletDynamics/Dynamics/btRigidBody.h"

#include "flags/gameflags.h"
//#include "state/basketballstate.h"
//#include "data/courtdata.h"
//#include "state/courtstate.h"
//#include "state/hoopstate.h"
//#include "state/playerstate.h"
//#include "state/teamstate.h"
//#include "data/teamdata.h"
//#include "data/playerdata.h"
//#include "jumpballs.h"
#include "state/state.h"
#include "state/gamestateshared.h"
#include "engine/inputengine.h"
class basketballState;
class UBC;
class courtData;
class courtState;
//class gameFlags;
class gameComponents;
class gameData;
class gameSMData;
class hoopState;
class playerState;
class teamState;
class teamEntity;
class teamData;
class playerData;
class jumpBalls;
//class state;

class gameEntity //: public state, public gameStateShared, public std::enable_shared_from_this<gameState>
{
    public:

        gameEntity(); // constructor
        ~gameEntity();  // destructor

        gameComponentsSharedPtr getComponent();  // retrieves the value of component
        void setComponent(gameComponentsSharedPtr set);  // sets the value of component

        gameDataSharedPtr getData();  // retrieves the value of data
        void setData(gameDataSharedPtr set);  // sets the value of data

        gameFlagsSharedPtr getFlag();  // retrieves the value of flag
        void setFlag(gameFlagsSharedPtr set);  // sets the value of flag
    
        gameStateMachineSharedPtr getStateMachine();  // retrieves the value of stateMachine
        void setStateMachine(gameStateMachineSharedPtr set);  // sets the value of stateMachine

        bool getComponentInitialized();  // retrieves the value of componentInitialized
        void setComponentInitialized(bool set);  // sets the value of componentInitialized

        bool getDataInitialized();  // retrieves the value of dataInitialized
        void setDataInitialized(bool set);  // sets the value of dataInitialized

        bool getFlagInitialized();  // retrieves the value of flagInitialized
        void setFlagInitialized(bool set);  // sets the value of flagInitialized
    
        bool getStateMachineInitialized();  // retrieves the value of stateMachineInitialized
        void setStateMachineInitialized(bool set);  // sets the value of stateMachineInitialized

        bool checkifJumpBallCreated();  // checks if jumpBall object has been created
     
        bool initializeStateMachine();  // initializes the stateMachine object
    
        bool updateStateMachine(playerActions actionType, gameSMData *SMData);  // updates state machine with external input

        void updateDirectionsAndMovements();  // updates the movement and directions of game world objecxts
        bool assignHoopToTeams();  // assigns which hoop belongs to each team
        bool setupEnvironment();  // sets up the 3D environment for the game
        void setBasketballStartPositions();  // sets the initial coordinates for the basketball(s).
        void setCourtStartPositions();  // sets the initial coordinates for the court(s).
        void setHoopStartPositions();  // sets the initial coordinates for the hoop(s).

    // Tip Off execution code.  // Move to proper class
        bool setupTipOff();  // sets up Tip Off conditions
        bool executeTipOff();  // executes the game tip off

        bool createInstances();  // creates object instances

        bool createTeamInstances();  // creates the instances of the teams

        bool createCourtDataInstances();  // creates instances of court data
    
        bool setupActiveTeamInstances();  // sets up the active team instances

        bool loadModels(renderEngineSharedPtr render);  // loads all game object models excluding the players
        bool createNodes(renderEngineSharedPtr render);  // creates scene nodes for game objects
    
//        bool setupState(renderEngineSharedPtr render);  // sets up the game condition
        bool updateState(renderEngineSharedPtr render);  // updates the state of the game
        bool updateActiveTeamInstances(renderEngineSharedPtr render);  // updates all active team instancesa
        bool updatePlayerCollisionObjects();  // updates the player collision objects for a team instance
        bool processInput();  // processes input received from the inputState object

    private:

        gameComponentsSharedPtr component;  // game component object
        gameDataSharedPtr data; // game data object
        gameFlagsSharedPtr flag;  // boolean flags object
        gameStateMachineSharedPtr stateMachine;  // instance of gameStateMachine object

        bool componentInitialized;  // stores whether the gameComoponents object has been initialized
        bool dataInitialized;  // stores whether the gameData object has been initialized
        bool flagInitialized;  // stores whether the gameFlags object has been initialized
        bool stateMachineInitialized;  // stores whether the gameStateMachine object has been initialized

};

#endif // _GAMEENTITY_H_

