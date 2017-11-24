/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
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

//#include "ubc/ubcbase.h"
class UBCBase;
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

    sharedPtr<teamStatistics> getStatistics();  // retrieves the value of statistics
    void setStatistics(sharedPtr<teamStatistics> set);  // sets the value of statistics

    UBCBaseSharedPtr getBase();  // retrieves the value of base
    void setBase(UBCBaseSharedPtr set);  // sets the value of base

///    int getTeamNumber();	// retrieves the value of teamNumber
///    void setTeamNumber(int set);  // sets the value of teamNumber

///    static size_t getID();	 // retrieves the value of teamID
///    void setTeamID(size_t set);	 // sets the value of teamID

    teamTypes getTeamType();  // retrieves the value of teamType
    void setTeamType(teamTypes set);  // sets the value of teamType

    std::string getPlayerType();  // retrieves the value of playerType
    void setPlayerType(std::string set);  // sets the value of playerType

    sizeTVec getPlayerID();  // retrieves the value of playerID
    void setPlayerID(sizeTVec set);  // sets the value of playerID

    sizeTVec getActivePlayerID();  // retrieves the value of activePlayerID
    void setActivePlayerID(sizeTVec set);  // sets the value of activePlayerID

    sizeTVec getStarterID();  // retrieves the value of starterID
    void setStarterID(sizeTVec set);  // sets the value of starterID

    bool getOffense();	// retrieves the value of offense
    void setOffense(bool set);  // sets the value of offense

    bool getDefense();  // retrieves the value of defense
    void setDefense(bool set);  // sets the value of defense

    playerEntityMSharedPtr getPlayerInstance();  // retrieves the value of playerInstance
    void setPlayerInstance(playerEntityMSharedPtr set);  // sets the value of  playerInstance

    playerEntityMSharedPtr getActivePlayerInstance();  // retrieves the value of activePlayerInstance
    void setActivePlayerInstance(playerEntityMSharedPtr set);  // sets the value of activePlayerInstance

    bool getActivePlayerInstancesCreated();  // retrieves the value of activePlayerInstancesCreated
    void setActivePlayerInstancesCreated(bool set);  // sets the value of activePlayerInstancesCreated

    bool getActivePlayerInstancesSetup();  // retrieves the value of activePlayerInstancesSetup
    void setActivePlayerInstancesSetup(bool set);  // sets the value of activePlayerInstancesSetup

    bool getActivePlayerInstancesChanged();  // retrieves the value of activePlayerInstancesChanged
    void setActivePlayerInstancesChanged(bool set);  // sets the value of activePlayerInstancesChanged

    bool getPlayerInstancesCreated();  // retrieves the value of the playerInstancesCreated
    void setPlayerInstancesCreated(bool set);  // sets the value of the playerInstancesCreated

    bool getPlayerStartPositionsSet();  // retrieves the value of the playerStartPositionsSet
    void setPlayerStartPositionsSet(bool set);  // sets the value of the playerStartPositionsSet

    bool getPlayerStartDirectionsSet();  // retrieves the value of the playerStartDirectionsSet
    void setPlayerStartDirectionsSet(bool set);  // sets the value of the playerStartDirectionsSet

    size_t getPlayerWithBallID();  // retrieves the value of the playerWithBallID
    void setPlayerWithBallID(size_t set);  // sets the value of the playerWithBallID

    playerPositions getPlayerWithBallInstance();  // retrieves the value of the playerWithBall
    void setPlayerWithBallInstance(playerPositions set);  // sets the value of the playerWithBall

    bool getPlayerWithBallDribbling();  // retrieves the value of the playerWithBallDribbling
    void setPlayerWithBallDribbling(bool set);  // sets the value of the playerWithBallDribbling

    bool getHumanControlled();  // retrieves the value of the humanControlled
    void setHumanControlled(bool set);  // sets the value of the humanControlled

    std::string getHumanPlayer();  // retrieves the value of the humanPlayer
    void setHumanPlayer(std::string set);  // sets the value of the human player

    size_t getHoop();  // retrieves the value of hoop
    void setHoop(size_t set);  // sets the value of hoop

    offenseStateSharedPtr getOffenseInstance();  // retrievers the value of offenseInstance
    void setOffenseInstance(offenseStateSharedPtr set);	 // sets the value of offenseInstance

    defenseStateSharedPtr getDefenseInstance();	 // retrieves the value of defenseInstance
    void setDefenseInstance(defenseStateSharedPtr set);	 // sets the value of defenseInstance

    size_t getTeamColObject();  // retrieves the value of teamColObject
    void setTeamColObject(size_t set); // sets the value of teamColObject
    
    size_t getTeamCollidesWith();  // retrieves the value of teamCollidesWith
    void setTeamCollidesWith(size_t set); // sets the value of teamCollidesWith

    std::unordered_map<std::string, btRigidBodySharedPtr> getCollisionBodies();  // retrieves the value of collisionBodies
    void setCollisionBodies(std::unordered_map<std::string, btRigidBodySharedPtr> set);  // sets the value of collisionBodies

//    bool getStateSet();  // retrieves the value of stateSet
//    void setStateSet(bool set);  // sets the value of stateSet

    // creates player Instances
//    bool createPlayerInstances();  // creates the player instances

    bool setPlayerStartPositions(gameStateSharedPtr gameInstance);	 // sets the initial coordinates for the players.
    void setPlayerStartActivePositions();  // sets the position the players will play at the start of the game

    bool setPlayerStartDirections();  // sets the initial directions for the players.

    bool setupActivePlayerInstances();  // sets up active player objects
    
    void updateActivePlayers();  // updates the states of active players
    void updatePlayerDirections(gameStateSharedPtr gameInstance);  // updates the direction players are facing
    void updatePlayerMovements();	// updates the movement status of players

    void executePass();  // executes the pass between players

    void updatePositions();  // updates player on court positionss

    void setupState();  // sets up the state for teamState object
    void updateState(gameStateSharedPtr gameInstance);  // updates the state of the teamState object
    void updateActivePlayerSettings();  // updates the settings of active players
        
protected:
private:

    sharedPtr<teamStatistics> statistics;  // instance of teamStatistics object

    static UBCBaseSharedPtr base;  // static copy of base class
    size_t teamNumber;  // stores which team number the object is
    teamTypes teamType;  // stores which type of team this object is
//    static size_t teamID;  // stores the ID number of the team;

    std::string playerType;  // stores the type of player in control of the team (human,network,ai) are valid values

    sizeTVec playerID;  // stores the player IDs from the teams class
    sizeTVec activePlayerID;  // stores which players are currently on the court.
    sizeTVec starterID;  // stores the IDs of which players are listed as starters.

    bool offense;  // if set then the team is on offense
    bool defense;  // if set then the team is on defense

    playerEntityMSharedPtr playerInstance;  // stores instance of the playerState class containing all team players
    playerEntityMSharedPtr activePlayerInstance;  // stores instance of the playerState class containing the active players

    std::vector <std::string> playerModelsLoaded;  // creates a vector of strings that holds the models which are loaded

    bool activePlayerInstancesCreated;  // stores whether the active player instances have been created
    bool activePlayerInstancesSetup;  // stores whether the active player instances have been configured
    bool activePlayerInstancesChanged;  // stores whether the active player instances have been changed
    bool playerInstancesCreated;  // storea whethet player instances have been created.
    bool playerStartPositionsSet;  // stores whether player starting positions have been set
    bool playerStartDirectionsSet;  // stores whether player starting directions have been set
    size_t playerInstanceCreatedCount;  // stores number of playerInstances that have been created
    size_t playerWithBallID;  // stores the ID of the player that has the ball
    playerPositions playerWithBallInstance;  // stores which player has control of the basketball, valid values are 0 - 4
    bool playerWithBallDribbling;  // stores whether the player with the ball is dribbling

    bool humanControlled;  // stores whether the team object is controlled by a human player;
    std::string humanPlayer;  // stores which player is human controlled

    size_t hoop;  // holds which hoop the team is shooting on
    offenseStateSharedPtr offenseInstance;  // stores the offenseState instance
    defenseStateSharedPtr defenseInstance;  // stores the defenseState instance

    size_t teamColObject;  // stores the object that collides with others
    size_t teamCollidesWith;   // stores what team players collides with

//    bool stateSet;  // stores whether or not the class state has been setup correctly
    std::unordered_map<std::string, btRigidBodySharedPtr> collisionBodies;  // physical bodies to test for collisions with players physBody objects

};

#endif // _TEAMSATE_H_
