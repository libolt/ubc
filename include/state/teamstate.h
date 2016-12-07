/***************************************************************************
 *   Copyright (C) 1999 - 2016 by Mike McLean                              *
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

//#include "state/offensestate.h"
//#include "state/defensestate.h"
//#include "state/basketballstate.h"
//#include "state/playerstate.h"
#include "state/state.h"
#include "state/gamestateshared.h"
#include "data/teamdata.h"
#include "typedefs.h"

//#include "ubcbase.h"
class UBCBase;
class offenseState;
class defenseState;
class basketballState;
class playerState;
//class state;
//class teamData;

class teamState : public state, public teamData

{
public:

    teamState();  // constructor
    ~teamState();  // destructor

    boost::shared_ptr<UBCBase> getBase();  // retrieves the value of base
    void setBase(boost::shared_ptr<UBCBase> set);  // sets the value of base
    

///    int getTeamNumber();	// retrieves the value of teamNumber
///    void setTeamNumber(int set);  // sets the value of teamNumber

///    static size_t getID();	 // retrieves the value of teamID
///    void setTeamID(size_t set);	 // sets the value of teamID

    teamTypes getTeamType();  // retrieves the value of teamType
    void setTeamType(teamTypes set);  // sets the value of teamType

    std::string getPlayerType();  // retrieves the value of playerType
    void setPlayerType(std::string set);  // sets the value of playerType

    size_t getAssists();  // retrieves the value of assists
    void setAssists(size_t set);  // sets the value of assists

    size_t getBlocks();  // retrieves the value of blocks
    void setBlocks(size_t set);  // sets the value of blocks

    size_t getFouls();  // retrieves the value of fouls
    void setFouls(size_t set);   // sets the value of fouls

    size_t getRebounds();  // retrieves the value of rebounds
    void setRebounds(size_t set);  // sets the value of rebounds

    size_t getOffensiveRebounds();  // retrieves the value of offensiveRebounds
    void setOffensiveRebounds(size_t set);   // sets the value of offensiveRebounds

    size_t getDefensiveRebounds();  // retrieves the value of defensiveRebounds
    void setDefensiveRebounds(size_t set);  // sets the value of defensiveRebounds

    size_t getSteals();  // retrieves the value of steals
    void setSteals(size_t set);  // sets the value of steals

    size_t getTechnicals();  // retrieves the value of technicals
    void setTechnicals(size_t set);  // sets the value of technicals

    size_t getTimeouts();  // retrieves the value of timeouts
    void setTimeouts(size_t set);  // sets the value of timeouts

    size_t getTurnovers();  // retrieves the value of turnovers
    void setTurnovers(size_t set);  // sets the value of turnovers

    size_t getFieldGoalsAttempted();  // retrieves the value of fieldGoalsAttempted
    void setFieldGoalsAttempted(size_t set);  // sets the value of fieldGoalsAttempted

    size_t getFieldGoalsMade();  // retrieves the value of fieldGoalsMade
    void setFieldGoalsMade(size_t set);  // sets the value of fieldGoalsMade

    size_t getThreePointersAttempted();  // retrieves the value of threePointersAttempted
    void setThreePointersAttempted(size_t set);  // sets the value of threePointersAttempted

    size_t getThreePointersMade();  // retrieves the value of threePointersMade
    void setThreePointersMade(size_t set);  // sets the value of threePointersMade

    size_t getFreeThrowsAttempted();  // retrieves the value of freeThrowsAttempted
    void setFreeThrowsAttempted(size_t set);  // sets the value of freeThrowsAttempted

    size_t getFreeThrowsMade();  // retrieves the value of freeThrowsMade
    void setFreeThrowsMade(size_t set);  // sets the value of freeThrowsMade

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

    std::tr1::unordered_map <size_t, playerStateSharedPtr> getPlayerInstance();  // retrieves the value of playerInstance
    void setPlayerInstance(std::tr1::unordered_map<size_t, playerStateSharedPtr> set);  // sets the value of  playerInstance

    std::tr1::unordered_map <size_t, playerStateSharedPtr> getActivePlayerInstance();  // retrieves the value of activePlayerInstance
    void setActivePlayerInstance(std::tr1::unordered_map <size_t, playerStateSharedPtr> set);  // sets the value of activePlayerInstance

    bool getPlayerInstancesCreated();  // retrieves the value of the playerInstancesCreated
    void setPlayerInstancesCreated(bool set);  // sets the value of the playerInstancesCreated

    size_t getPlayerWithBallID();  // retrieves the value of the playerWithBallID
    void setPlayerWithBallID(size_t set);  // sets the value of the playerWithBallID

    size_t getPlayerWithBallInstance();	 // retrieves the value of the playerWithBall
    void setPlayerWithBallInstance(size_t set);	 // sets the value of the playerWithBall

    bool getPlayerWithBallDribbling();  // retrieves the value of the playerWithBallDribbling
    void setPlayerWithBallDribbling(bool set);  // sets the value of the playerWithBallDribbling

    bool getHumanControlled();  // retrieves the value of the humanControlled
    void setHumanControlled(bool set);  // sets the value of the humanControlled

    size_t getHumanPlayer();  // retrieves the value of the humanPlayer
    void setHumanPlayer(size_t set);  // sets the value of the human player

    size_t getHoop();  // retrieves the value of hoop
    void setHoop(size_t set);  // sets the value of hoop

    boost::shared_ptr<offenseState> getOffenseInstance();  // retrievers the value of offenseInstance
    void setOffenseInstance(boost::shared_ptr<offenseState> set);	 // sets the value of offenseInstance

    boost::shared_ptr<defenseState> getDefenseInstance();	 // retrieves the value of defenseInstance
    void setDefenseInstance(boost::shared_ptr<defenseState> set);	 // sets the value of defenseInstance

    size_t getTeamColObject();  // retrieves the value of teamColObject
    void setTeamColObject(size_t set); // sets the value of teamColObject
    
    size_t getTeamCollidesWith();  // retrieves the value of teamCollidesWith
    void setTeamCollidesWith(size_t set); // sets the value of teamCollidesWith

//    bool getStateSet();  // retrieves the value of stateSet
//    void setStateSet(bool set);  // sets the value of stateSet

    // creates player Instances
    bool createPlayerInstances();  // creates the player instances
    bool createPlayerInstances_old();  // creates the player instances

    void setPlayerStartPositions();	 // sets the initial coordinates for the players.
    void setPlayerStartActivePositions();  // sets the position the players will play at the start of the game

    void updatePlayerStates();  // updates the states of active players
    void updatePlayerDirections();  // updates the direction players are facing
    void updatePlayerMovements();	// updates the movement status of players

    void executePass();  // executes the pass between players

    void updatePositions();  // updates the positions of game world objects

    void setupState();  // sets up the state for teamState object
    void updateState();  // updates the state of the teamState object

        
protected:
private:

    static boost::shared_ptr<UBCBase> base;  // static copy of base class
    size_t teamNumber;  // stores which team number the object is
    teamTypes teamType;  // stores which type of team this object is
//    static size_t teamID;  // stores the ID number of the team;

    std::string playerType;  // stores the type of player in control of the team (human,network,ai) are valid values
    size_t assists;  // stores number of assists team has.
    size_t blocks;  // stores the total number of blocks.
    size_t fouls;  // stores the total number of fouls.
    size_t rebounds;  // stores the total number of rebounds.
    size_t offensiveRebounds;  // stores the total number of offensive rebounds.
    size_t defensiveRebounds;  // stores the total number of defensive rebounds.
    size_t steals;  // stores the total number of steals.
    size_t technicals;  // stores the total number of technical fouls commited.
    size_t timeouts;  // stores the total number of timeouts available.
    size_t turnovers;  // stores the total number turnovers.
    size_t fieldGoalsAttempted;  // stores the total number of field goals attempted.
    size_t fieldGoalsMade;  // stores the total number of field goals made.
    size_t threePointersAttempted;  // stores the total number of 3 pointers attempted.
    size_t threePointersMade;  // stores the total number of 3 pointers made.
    size_t freeThrowsAttempted;  // stores the total number of free throws attempted.
    size_t freeThrowsMade;  // stores the total number of free throws made.

    sizeTVec playerID;  // stores the player IDs from the teams class
    sizeTVec activePlayerID;  // stores which players are currently on the court.
    sizeTVec starterID;  // stores the IDs of which players are listed as starters.

    bool offense;  // if set then the team is on offense
    bool defense;  // if set then the team is on defense

    std::tr1::unordered_map <size_t, playerStateSharedPtr> playerInstance;  // stores instance of the playerState class containing all team players
    std::tr1::unordered_map <size_t, playerStateSharedPtr> activePlayerInstance;  // stores instance of the playerState class containing the active players

    std::vector <std::string> playerModelsLoaded;  // creates a vector of strings that holds the models which are loaded
    bool playerInstancesCreated;  // stores whether player instances have been created
    size_t playerInstanceCreatedCount;  // stores number of playerInstances that have been created
    size_t playerWithBallID;  // stores the ID of the player that has the ball
    size_t playerWithBallInstance;  // stores which player has control of the basketball, valid values are 0 - 4
    bool playerWithBallDribbling;  // stores whether the player with the ball is dribbling

    bool humanControlled;  // stores whether the team object is controlled by a human player;
    size_t humanPlayer;  // stores which player is human controlled

    size_t hoop;  // holds which hoop the team is shooting on
    boost::shared_ptr<offenseState> offenseInstance;  // stores the offenseState instance
    boost::shared_ptr<defenseState> defenseInstance;  // stores the defenseState instance

    size_t teamColObject;  // stores the object that collides with others
    size_t teamCollidesWith;   // stores what team players collides with

//    bool stateSet;  // stores whether or not the class state has been setup correctly

};

#endif // _TEAMSATE_H_
