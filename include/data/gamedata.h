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

#ifndef _GAMEDATA_H_
#define _GAMEDATA_H_

#include "utilities/typedefs.h"

class gameData
{
    public:
        gameData();  // constructor
        ~gameData();  // destructor
    
        size_t getBballBounce() const;  // retrieves the value of bballBounce
        void setBballBounce(const size_t &set);  // sets the value of bballBounce

        size_t getSelectedCourtDataInstance() const;  // retrieves the value of selectedCourtDataInstance
        void setSelectedCourtDataInstance(const size_t &set);  // sets the value of selectedCourtDataInstance

        sizeTVec getPlayerID() const;  // retrieves the value of playerID
        void setPlayerID(const sizeTVec &set);  // sets the value of playerID

        gameTypes getGameType() const;  // retrieves the value of gameType
        void setGameType(const gameTypes &set);  // sets the value of gameType

        sizeTVec getTeamIDS() const;  // retrieves the value of teamIDS
        void setTeamIDS(const sizeTVec &set);  // sets the value of teamIDS

        teamStarterIDsVecM getTeamStarterID() const;  // retrieves value of teamStarterID
        void setTeamStarterID(const teamStarterIDsVecM &set);  // sets the value of teamStarterID

        quarters getQuarter() const;  // retrieves the value of quarter
        void setQuarter(const quarters &set);  // sets the value of quarter

        size_t getNumActiveBasketballs() const;  // retrieves the value of numActiveBasketballs
        void setNumActiveBasketballs(const size_t &set);  // sets the value of numActiveBasketballs

        Ogre::Vector3 getBBallNodePosition() const;  // retrieves the value of bballNodePosition
        void setBBallNodePosition(const Ogre::Vector3 &set);  // sets the value of bballNodePosition
        
        teamTypes getTeamWithBall() const;  // retrieves the value of teamWithBall
        void setTeamWithBall(const teamTypes &set);  // sets the value of teamWithBall

        float getYOffset() const;  // retrieves the value of yOffset
        void setYOffset(const float &set);  // sets the value of yOffset

        std::vector<bool> getTeamActivePlayersChanged() const;  // retrieves the value of teamActivePlayersChanged
        void setTeamActivePlayersChanged(const std::vector<bool> &set);  // sets the value of teamActivePlayersChanged

    private:
    
        float gameTimeLeft;  // Indicates the time left in the game
        float quarterTimeLeft;  // incates the time left in the current quarter
        size_t selectedCourtDataInstance;  // stores which court should be loaded by courtInstance
    
        sizeTVec playerID;  // std::vector that stores the IDs of the players currently being used.

        size_t bballBounce;  // stores which direction the ball is bouncing;

        size_t numActiveHoops;  // stores the nimber of active hoop instances

        gameTypes gameType;  // Indicates whether a single or multi player game is being played.
        quarters quarter;  // stores the quarter currently being played
        size_t numActiveBasketballs;  // stores the number of active basketballs in the game.
        sizeTVec teamIDS;  // std::vector that stores the IDs of the 2 teams currently playing
        teamStarterIDsVecM teamStarterID;  // stores the selected starters for each team
        Ogre::Vector3 bballNodePosition;  // stores a copy of the basketball node position
        teamTypes teamWithBall;  // store which team has the basketball
        float yOffset; // stores the y offset for objects on the screen

        std::vector<bool> teamActivePlayersChanged;  // stores whether the active players for each team have changed

        
};

#endif
