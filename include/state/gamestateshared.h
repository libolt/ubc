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

#ifndef _GAMESTATESHARED_H_
#define _GAMESTATESHARED_H_

//#include "state/courtstate.h"

#include "utilities/enums.h"
#include "utilities/typedefs.h"

#include <vector>
#include <cstddef>
#include <unordered_map>
#include "Ogre.h"
#include "boost/shared_ptr.hpp"

class playerEntity;
class basketballState;
class courtState;
class hoopState;
class playerState;
class teamState;
class jumpBalls;


class gameStateShared
{
    public:
    
        gameStateShared();  // constructor
        ~gameStateShared();  // destructor

        // getters and setters
           
        gameTypes getGameType();  // retrieves the value of gameType
        void setGameType(gameTypes set);  // sets the value of gameType

        quarters getQuarter();  // retrieves the value of quarter
        void setQuarter(quarters set);  // sets the value of quarter

        size_t getNumActiveBasketballs();  // retrieves the value of numActiveBasketballs
        void setNumActiveBasketballs(size_t set);  // sets the value of numActiveBasketballs

        Ogre::Vector3 getBBallNodePosition();  // retrieves the value of bballNodePosition
        void setBBallNodePosition(Ogre::Vector3 set);  // sets the value of bballNodePosition
        
        teamTypes getTeamWithBall();  // retrieves the value of teamWithBall
        void setTeamWithBall(teamTypes set);  // sets the value of teamWithBall
        
        basketballStateMSharedPtr getActiveBasketballInstance();  // retrieves the value of activeBasketballInstance
        void setActiveBasketballInstance(basketballStateMSharedPtr set);  // sets the value of activeBasketballInstance

        courtStateMSharedPtr getActiveCourtInstance();  // retrieves the value of activeCourtInstance
        void setActiveCourtInstance(courtStateMSharedPtr set);  // sets the value of activeCourtInstance

        hoopStateMSharedPtr getActiveHoopInstance();  // retrieves the value of activeHoopInstance
        void setActiveHoopInstance(hoopStateMSharedPtr set);  // sets the value of activeHoopInstance

        teamStateMSharedPtr getActiveTeamInstance();  // retrieves the value of activeTeamInstance
        void setActiveTeamInstance(teamStateMSharedPtr set);  // sets the value of activeTeamInstance
               
//        size_t getActiveBBallInstance();  // retrieves the value of activeBBallInstance
//        void setActiveBBallInstance(size_t set);  // sets the value of activeBBallInstance

        basketballStateMSharedPtr getBasketballInstance();  // retrieves the value of basketballInstance
        void setBasketballInstance(basketballStateMSharedPtr set);  // sets the value of basketballInstance

        courtStateMSharedPtr  getCourtInstance();  // retrieves the value of courtInstance
        void setCourtInstance(courtStateMSharedPtr  set);  // sets the value of courtInstance

        hoopStateMSharedPtr getHoopInstance();  // retrieves the value of hoopInstance
        void setHoopInstance(hoopStateMSharedPtr set);  // sets the value of hoopInstance

        playerEntityMSharedPtr getPlayerInstance();  // retrieves the value of playerInstance
        void setPlayerInstance(playerEntityMSharedPtr set);  // sets the value of  playerInstance

        teamStateMSharedPtr getTeamInstance();  // retireves the value of teamInstance
        void setTeamInstance(teamStateMSharedPtr set);  // sets the value of teamInstance

        jumpBallsSharedPtr getJumpBall();  // retrieves the value of jumpBall
        void setJumpBall(jumpBallsSharedPtr set);  // sets the value of jumpBall

        float getYOffset();  // retrieves the value of yOffset
        void setYOffset(float set);  // sets the value of yOffset

        std::vector<bool> getTeamActivePlayersChanged();  // retrieves the value of teamActivePlayersChanged
        void setTeamActivePlayersChanged(std::vector<bool> set);  // sets the value of teamActivePlayersChanged

        
    private:

        // used to determine if calling class needs to uldate its copy of the variable
        gameTypes gameType;  // Indicates whether a single or multi player game is being played.
        quarters quarter;  // stores the quarter currently being played
        size_t numActiveBasketballs;  // stores the number of active basketballs in the game.
        sizeTVec teamIDS;  // std::vector that stores the IDs of the 2 teams currently playing
        teamStarterIDsVecM teamStarterID;  // stores the selected starters for each team
        Ogre::Vector3 bballNodePosition;  // stores a copy of the basketball node position
        teamTypes teamWithBall;  // store which team has the basketball
        basketballStateMSharedPtr activeBasketballInstance;  // creates instance of the basketballState class
        courtStateMSharedPtr activeCourtInstance;  // stores the active court instance
        hoopStateMSharedPtr activeHoopInstance;  // creates instance of the hoopState class
        teamStateMSharedPtr activeTeamInstance;  // stores active team instance
        
//        static size_t activeBBallInstance;  // stores which instance of the baskteball class is active
        basketballStateMSharedPtr basketballInstance;  // creates instance of the basketballs class
        courtStateMSharedPtr courtInstance;  // stores the court instance
        hoopStateMSharedPtr hoopInstance;  // creates instance of the hoop class
        playerEntityMSharedPtr playerInstance;  // stores the map of the players loaded from the xml files
        teamStateMSharedPtr  teamInstance;  // creates instance of the teamState class

        jumpBallsSharedPtr jumpBall; // instance that is used for jumpBall functions.

        float yOffset; // stores the y offset for objects on the screen

        std::vector<bool> teamActivePlayersChanged;  // stores whether the active players for each team have changed
                
};

#endif

