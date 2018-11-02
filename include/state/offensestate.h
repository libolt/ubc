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

#ifndef _OFFENSESTATE_H_
#define _OFFENSESTATE_H_

#include "OgreVector3.h"

#include "utilities/enums.h"
#include "offenseplays.h"
#include "state/state.h"
//#include "state/gamestateshared.h"

//class offensePlays:
//class offensePlays::playerDirectives;
//class state;

class offenseState : public state
{
public:

    offenseState(); // constructor

/*    gameStateSharedPtr getGameS();  // retrieves the value of gameS
    void setGameS(gameStateSharedPtr set);  // sets the value of gameS

    bool getGameSInitialized();  // retrieves the value of gameSInitialized
    void setGameSInitialized(bool set);  // sets the value of gameSInitialized
*/
    teamTypes getTeamType() const;  // retrieves the value of teamType
    void setTeamType(const teamTypes &set);  // sets the value of teamType

    courtSide_t getCourtSide() const;  // retrieves the value of courtSide
    void setCourtSide(const courtSide_t &set);  // sets the value of courtSide

    int getSelectedOffense() const;  // retrieves the  value of selectedOffense
    void setSelectedOffense(const int &set);  // sets the value of selectedOffense

    bool getExecute() const;	// retrieves the value of execute variable
    void setExecute(const bool &set);	// sets the value of the execute variable

    offensePlaysVecSharedPtr getPlays() const;  // retrieves the value of plays
    void setPlays(const offensePlaysVecSharedPtr &set);  // sets the value of plays

    OgreVector3Vec getStartPositions() const;  // retrieves the value of the startPositions variable
    void setStartPositions(const OgreVector3Vec &set);  // sets the value startPositions variable

    std::vector <OgreVector3Vec > getExecutePositions() const;  // retrieves the value of the executePositions variable
    void setExecutePositions(const std::vector< OgreVector3Vec > &set);  // sets the value executePositions variable

    boolVec getStartXPosSet() const;  // retrieves the value of startXPosSet
    void setStartXPosSet(const boolVec &set);  // sets the value of startXPosSet

    boolVec getStartYPosSet() const;  // retrieves the value of startYPosSet
    void setStartYPosSet(const boolVec &set);  // sets the value of startYPosSet

    boolVec getStartZPosSet() const;  // retrieves the value of startZPosSet
    void setStartZPosSet(const boolVec &set);  // sets the value of startZPosSet

    boolVec getStartPositionReached() const;  // retrieves the value of startPositionReached
    void setStartPositionReached(const boolVec &set);  // sets the value of startPositionReached

    bool getAllStartPositionsReached() const;  // retrieves the value of allStartPositionsSet
    void setAllStartPositionsReached(const bool &set);  // sets the value of allStartPositionsSet

    std::vector< boolVec > getExecutePositionReached() const;  // returns the value of executePositionSet
    void setExecutePositionReached(const std::vector< boolVec > &set);  // sets the value of executePositionSet

    void setupState();  // sets up initial state of the object

    void updateState(teamTypes teamType, const gameComponentsSharedPtr &gameComponent, const gameDataSharedPtr &gameData);  // updates the state of the object

    void loadPlays();  // loads offense plays from file

    void setupOffense(const gameDataSharedPtr &gameData);  // sets up box offense
    void executeOffense(const gameComponentsSharedPtr &gameComponent, const gameDataSharedPtr &gameData);  // executes box offense
    bool checkForDirective(playerPositions set);  // checks if a directive needs to be completed before execution

    void executePass();  // executes the pass between players

private:

//    gameStateSharedPtr gameS;  // the gameState object
//    bool gameSInitialized;  // stores whether or not the gameState object has been initialized

    teamTypes teamType;  // stores whether the offense is being run by the home or away team.
    courtSide_t courtSide;  // stores which side of the court the offense executes on.
    int selectedOffense; // stores which offense is being run
    std::string playName;  // stores the name of the offense being run
    std::string playTitle;  // stores the type of offense being run
    bool offenseSet; // if true then run offense
    bool execute;	// If set then execute the offense logic

    OgreVector3Vec startPositions;		// stores the positions for players get to in order to execute offense
    std::vector< OgreVector3Vec > executePositions;    // stores the positions where players move when executing offense
    std::vector<bool> startXPosSet; // stores whether player is at start X position
    std::vector<bool> startYPosSet; // stores whether player is at start Y position
    std::vector<bool> startZPosSet; // stores whether player is at start Z position
    boolVec startPositionReached; // stores whether player is at start position
    int numStartPositionsReached;  // stores how many startPositions have been set.

    bool allStartPositionsReached;  // stores whether all player start positions have been reached
    bool allExecutePositionsReached;  // stores whether all player execute positions have been reached
    
    std::vector< boolVec > executePositionReached; // stores whether player is at execute position

    offensePlaysVecSharedPtr plays;	// stores the plays for the offense to run
    std::vector<offensePlays::playerDirectives> playerDirective;  // stores values of the playerDirectives class associated with the play being run
	
    // offense type variables
    bool offenseSetup;
};

#endif

