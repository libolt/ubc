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

#ifndef _TEAMGAMEDATA_H_
#define _TEAMGAMEDATA_H_

#include "utilities/typedefs.h"

class teamGameData
{
    public:
        teamGameData();  // constructor
        ~teamGameData();  // destructor

        teamTypes getTeamType() const;  // retrieves the value of teamType
        void setTeamType(const teamTypes &set);  // sets the value of teamType

        std::string getPlayerType() const;  // retrieves the value of playerType
        void setPlayerType(const std::string &set);  // sets the value of playerType

        sizeTVec getPlayerID() const;  // retrieves the value of playerID
        void setPlayerID(const sizeTVec &set);  // sets the value of playerID

        sizeTVec getActivePlayerID() const;  // retrieves the value of activePlayerID
        void setActivePlayerID(const sizeTVec &set);  // sets the value of activePlayerID

        sizeTVec getStarterID() const;  // retrieves the value of starterID
        void setStarterID(const sizeTVec &set);  // sets the value of starterID

        size_t getPlayerWithBallID() const;  // retrieves the value of playerWithBallID
        void setPlayerWithBallID(const size_t &set);  // sets the value of playerWithBallID

        playerPositions getPlayerWithBallInstance() const;  // retrieves the value of playerWithBall
        void setPlayerWithBallInstance(const playerPositions &set);  // sets the value of playerWithBall

        size_t getHumanPlayer() const;  // retrieves the value of humanPlayer
        void setHumanPlayer(const size_t &set);  // sets the value of humanPlayer

        size_t getHoop() const;  // retrieves the value of hoop
        void setHoop(const size_t &set);  // sets the value of hoop

        size_t getTeamColObject() const;  // retrieves the value of teamColObject
        void setTeamColObject(const size_t &set); // sets the value of teamColObject
    
        size_t getTeamCollidesWith() const;  // retrieves the value of teamCollidesWith
        void setTeamCollidesWith(const size_t &set); // sets the value of teamCollidesWith

    private:
    
        size_t teamNumber;  // stores which team number the object is
        teamTypes teamType;  // stores which type of team this object is
//    static size_t teamID;  // stores the ID number of the team;

        std::string playerType;  // stores the type of player in control of the team (human,network,ai) are valid values

        sizeTVec playerID;  // stores the player IDs from the teams class
        sizeTVec activePlayerID;  // stores which players are currently on the court.
        sizeTVec starterID;  // stores the IDs of which players are listed as starters.

        std::vector <std::string> playerModelsLoaded;  // creates a vector of strings that holds the models which are loaded

        size_t playerInstanceCreatedCount;  // stores number of playerInstances that have been created
        size_t playerWithBallID;  // stores the ID of the player that has the ball
        playerPositions playerWithBallInstance;  // stores which player has control of the basketball, valid values are 0 - 4
        size_t humanPlayer;  // stores which player is human controlled

        size_t hoop;  // holds which hoop the team is shooting on
        size_t teamColObject;  // stores the object that collides with others
        size_t teamCollidesWith;   // stores what team players collides with

};

#endif
