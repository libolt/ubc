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

#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include <vector>
#include <boost/shared_ptr.hpp>
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
class hoopState;
class playerState;
class teamState;
class teamData;
class playerData;
class jumpBalls;
//class state;

class gameState : public state, public gameStateShared, public std::enable_shared_from_this<gameState>
{
public:

    //static gameState *Instance();
//    static sharedPtr<gameState> Instance();

    gameState(); // constructor
    ~gameState();  // destructor

    gameFlags getFlag();  // retrieves the value of flag
    void setFlag(gameFlags set);  // sets the value of flag
    
/*    jumpBallsSharedPtr getJumpBall();  // retrieves the value of jumpBall
    void setJumpBall(jumpBallsSharedPtr set);  // sets the value of jumpBall
*/

//    teamTypes getTeamWithBall();  // retrieves teamWithBall value
//    void setTeamWithBall(teamTypes set);	 // sets teamWithBall value

    size_t getBballBounce();  // retrieves the value of bballBounce
    void setBballBounce(size_t set);  // sets the value of bballBounce

    size_t getSelectedCourtDataInstance();  // retrieves the value of selectedCourtDataInstance
    void setSelectedCourtDataInstance(size_t set);  // sets the value of selectedCourtDataInstance

/*    bool getBasketballInstancesCreated();  // retrieves the value of basketballInstancesCreated
    void setBasketballInstancesCreated(bool set);   // sets the value of basketballInstancesCreated
*/

/*    bool getCourtInstancesCreated();  // retrieves the value of courtInstancesCreated
    void setCourtInstancesCreated(bool created);  // sets the value of courtInstancesCreated
*/

/*    bool getHoopInstancesCreated();  // retrieves the value of hoopInstancesCreated
    void setHoopInstancesCreated(bool created);  // sets the value of hoopInstancesCreated
*/
/*    bool getPlayerInstanceCreated();  // retrieves the value of playerInstancesCreated
    void setPlayerInstanceCreated(bool created);  // sets the value of playerInstancesCreated
*/
/*    bool getTeamInstancesCreated();	 // retrieves the value of teamInstancesCreated
    void setTeamInstancesCreated(bool set);	 // sets the value of teamInstancesCreated
*/
/*    bool getActiveTeamInstancesCreated();	 // retrieves the value of activeTeamInstancesCreated
    void setActiveTeamInstancesCreated(bool set);	 // sets the value of activeTeamInstancesCreated
*/

    courtDataVec getCourtDataInstance();  // retrieves the value of courtDataInstance
    void setCourtDataInstance(courtDataVec set);  // sets the value of courtDataInstance

/*    size_t getActiveBBallInstance();  // retrieves the value of activeBBallInstance
    void setActiveBBallInstance(size_t set);  // sets the value of activeBBallInstance
*/

/*    size_t getActiveCourtInstance();  // retrieves the value of activeCourtInstance
    void setActiveCourtInstance(size_t set);  // sets the value of activeCourtInstance
*/

/*    sizeTVec getTeamID();  // retrieves the value of teamID
    void setTeamID(sizeTVec set);  // sets the value of teamID
*/

    sizeTVec getPlayerID();  // retrieves the value of playerID
    void setPlayerID(sizeTVec set);  // sets the value of playerID
    
    inputInGameWorkQueues getInputInGameWorkQueue();  // retrieves the value of inputInGameWorkQueue
    void setInputInGameWorkQueue(inputInGameWorkQueues set);  // sets the value of inputInGameWorkQueue
    
    // These functions check if an object has been created and attmpt to do so if not
//    bool checkIfPlayerInstanceCreated();  // check if playerInstance object has been created and loaded
    
    bool checkifJumpBallCreated();  // checks if jumpBall object has been created
//    void processNetworkEvents();  // processes events received from network connection.
//    void processNetworkPlayerEvents();  // processes player evernts received from network connection
    void updateDirectionsAndMovements();  // updates the movement and directions of game world objecxts
//    void updatePlayerDirections();  // updates the direction players are facing
    bool assignHoopToTeams();  // assigns which hoop belongs to each team
    bool setupEnvironment();  // sets up the 3D environment for the game
    void setBasketballStartPositions();  // sets the initial coordinates for the basketball(s).
    void setCourtStartPositions();  // sets the initial coordinates for the court(s).
    void setHoopStartPositions();  // sets the initial coordinates for the hoop(s).

    // Tip Off execution code.  // Move to proper class
    bool setupTipOff();  // sets up Tip Off conditions
    bool executeTipOff();  // executes the game tip off

    bool createInstances();  // creates object instances
    
//    bool createBasketballInstances();  // creates the instances of the basketballs

    bool createTeamInstances();  // creates the instances of the teams

    bool createCourtDataInstances();  // creates instances of court data

//    bool createCourtInstances();  // creates court Instances

//    bool createHoopInstances();  // creates hoop Instances

//    bool createPlayerInstances();  // creates player instances
    
//    bool createActiveBasketballInstances();  // creates the active basketball instances

//    bool createActiveCourtInstances();  // creates the active court instances

//    bool createActiveHoopInstances();  // creates the active hoop instances
    
    bool setupActiveTeamInstances();  // sets up the active team instances

//    bool loadBasketballModel();  // loads selected basketball model
//    bool loadCourtModel();  // loads selected court model
//    bool loadHoopModel();  // loads selected hoop model
    bool loadModels(renderEngineSharedPtr render);  // loads all game object models excluding the players
    bool createNodes(renderEngineSharedPtr render);  // creates scene nodes for game objects
    
    bool setupState(renderEngineSharedPtr render);  // sets up the game condition
    bool updateState();  // updates the state of the game
    bool updateActiveTeamInstances();  // updates all active team instancesa
    bool updatePlayerCollisionObjects();  // updates the player collision objects for a team instance
    bool processInput();  // processes input received from the inputState object

protected:
    
//    gameState(const gameState&);
//    gameState &operator = (const gameState&);

private:

    gameFlags flag;  // boolean flags object
    float gameTimeLeft;  // Indicates the time left in the game
    float quarterTimeLeft;  // incates the time left in the current quarter

    courtDataVec courtDataInstance;  // stores the vector the courts loaded from the xml files

    size_t selectedCourtDataInstance;  // stores which court should be loaded by courtInstance
    
    sizeTVec playerID;  // std::vector that stores the IDs of the players currently being used.

    std::vector< sizeTVec > teamStarterID;  // stores the selected starters for each team

    inputInGameWorkQueues inputInGameWorkQueue;  // queue of input events for game
    
    size_t bballBounce;  // stores which direction the ball is bouncing;

    size_t numActiveHoops;  // stores the nimber of active hoop instances
};


#endif // _GAMESTATE_H_
