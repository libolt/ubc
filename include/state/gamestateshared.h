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
           
        bool getInitialized();  // retrieves the value of initialized
        void setInitialized(bool set);  // sets the value of initialized

        gameTypes getGameType();  // retrieves the value of gameType
        void setGameType(gameTypes set);  // sets the value of gameType

        sizeTVec getTeamIDS();  // retrieves the value of teamIDS
        void setTeamIDS(sizeTVec set);  // sets the value of teamIDS
        
        std::vector<std::unordered_map<std::string, size_t> > getTeamStarterID();  // retrieves value of teamStarterID
        void setTeamStarterID(std::vector<std::unordered_map<std::string, size_t> > set);  // sets the value of teamStarterID

        bool getActiveBasketballInstancesCreated();  // retrieves the value of activeBasketballInstancesCreated
        void setActiveBasketballInstancesCreated(bool set);  // sets the value of activeBasketballInstancesCreated


        bool getActiveCourtInstancesCreated();  // retrieves the value of activeCourtInstancesCreated
        void setActiveCourtInstancesCreated(bool set);  // sets the value of activeCourtInstancesCreated

        bool getActiveHoopInstancesCreated();  // retrieves the value of activeHoopInstancesCreated
        void setActiveHoopInstancesCreated(bool set);  // sets the value of activeHoopInstancesCreated

        bool getActiveTeamInstancesCreated();  // retrieves the value of activeTeamInstancesCreated
        void setActiveTeamInstancesCreated(bool set);  // sets the value of activeTeamInstancesCreated

        bool getActiveTeamInstancesSetup();  // retrieves the value of activeTeamInstancesSetup
        void setActiveTeamInstancesSetup(bool set);  // sets the value of activeTeamInstancesSetup

        bool getBasketballInstanceCreated();  // retrieves the value of basketballInstancesCreated
        void setBasketballInstanceCreated(bool set);  // sets the value of basketballInstancesCreated

        bool getBasketballInstanceNeedCreated();  // retrieves the value of basketballInstancesNeedCreated
        void setBasketballInstanceNeedCreated(bool set);  // sets the value of basketballInstancesNeedCreated
        
        bool getCourtInstancesCreated();  // retrieves the value of courtInstancesCreated
        void setCourtInstancesCreated(bool set);  // sets the value of courtInstancesCreated

        bool getCourtInstancesNeedCreated();  // retrieves the value of courtInstancesNeedCreated
        void setCourtInstancesNeedCreated(bool set);  // sets the value of courtInstancesNeedCreated

        bool getHoopInstancesCreated();  // retrieves the value of hoopInstancesCreated
        void setHoopInstancesCreated(bool created);  // sets the value of hoopInstancesCreated

        bool getHoopInstanceNeedCreated();  // retrieves the value of hoopInstancesNeedCreated
        void setHoopInstanceNeedCreated(bool created);  // sets the value of hoopInstancesNeedCreated

        bool getPlayerInstanceCreated();  // retrieves the value of playerInstanceCreated
        void setPlayerInstanceCreated(bool set);  // sets the value of playerInstanceCreated

        bool getPlayerInstanceNeedCreated();  // retrieves the value of playerInstanceNeedCreated
        void setPlayerInstanceNeedCreated(bool set);  // sets the value of playerInstanceNeedCreated

        bool getTeamInstancesCreated();  // retrieves the value of teamInstancesCreated
        void setTeamInstancesCreated(bool set);  // sets the value of teamInstancesCreated

        bool getTeamInstancesNeedCreated();  // retrieves the value of teamInstancesNeedCreated
        void setTeamInstancesNeedCreated(bool set);  // sets the value of teamInstancesNeedCreated
        
        bool getBBallNodePositionChanged();  // retrieves the value of bballNodePositionChanged
        void setBBallNodePositionChanged(bool set);  // sets the value of bballNodePositionChanged
        
        bool getTeamWithBallChanged();  // retrieves the value of bballNodePositionChanged
        void setTeamWithBallChanged(bool set);  // sets the value of teamWithBallChanged
        
        bool getActiveTeamInstanceChanged();  // retrieves the value of activeTeamInstanceChanged
        void setActiveTeamInstanceChanged(bool set);  // sets the value of activeTeamInstanceChanged
        
        bool getGameSetupComplete();  // retrieves the value of gameSetupComplete
        void setGameSetupComplete(bool set);  // sets the value of gameSetupComplete

        bool getJumpBallCreated();  // retrieves the value of jumpBallCreated
        void setJumpBallCreated(bool set);  // sets the value of jumpBallCreated

        bool getTipOffComplete();  // retrieves the value of tipOffComplete
        void setTipOffComplete(bool set);  // sets the value of tipOffComplet

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
        static bool initialized;  // if true then tbe object has been initialized
        static bool activeBasketballInstancesCreated;  // stores whether the active basketball instances have been created
        static bool activeCourtInstancesCreated;  // stores whether the active court instances have been created
        static bool activeHoopInstancesCreated;  // stores whether the active hoop instances have been created
        static bool activeTeamInstancesCreated;  // stores whether the active team instances have been created
        static bool activeTeamInstancesSetup;  // stores whether or not to setup active team instances
        static bool basketballInstanceCreated;  // stores whether basketball instance(s) have been created
        static bool basketballInstanceNeedCreated;  // stores whether or not to create basketball instance(s)
        static bool courtInstancesCreated;  // stores whether court instances have been created
        static bool courtInstancesNeedCreated;  // stores whether or not to create court instances
        static bool hoopInstancesCreated;  // stores whether hoop instances have been created
        static bool hoopInstancesNeedCreated;  // stores whether or not to create hoop instances
        static bool playerInstanceCreated;  // stores whether player instances have been created
        static bool playerInstanceNeedCreated;  // stores whether or not to create player instances
        static bool teamInstancesCreated;  // stores whether team instances have been created
        static bool teamInstancesNeedCreated;  // stores whether or not to create team instances
        static bool bballNodePositionChanged;  // stores whether basketball node position has changed
        static bool teamWithBallChanged;  // stores whether team with ball has changed
        static bool activeTeamInstanceChanged;  // stores whether activeTeamInstance has changed
        static bool gameSetupComplete;  // indicates whether initial game setup is complete.
        static bool jumpBallCreated;  // indicates whether jumpBall object has been created.
        static bool tipOffComplete;  // Determines whether or not game Tip Off has completed

        static gameTypes gameType;  // Indicates whether a single or multi player game is being played.
        static quarters quarter;  // stores the quarter currently being played
        static size_t numActiveBasketballs;  // stores the number of active basketballs in the game.
        static sizeTVec teamIDS;  // std::vector that stores the IDs of the 2 teams currently playing
        static std::vector<std::unordered_map<std::string, size_t> > teamStarterID;  // stores the selected starters for each team
        static Ogre::Vector3 bballNodePosition;  // stores a copy of the basketball node position
        static teamTypes teamWithBall;  // store which team has the basketball
        static basketballStateMSharedPtr activeBasketballInstance;  // creates instance of the basketballState class
        static courtStateMSharedPtr activeCourtInstance;  // stores the active court instance
        hoopStateMSharedPtr activeHoopInstance;  // creates instance of the hoopState class
        static teamStateMSharedPtr activeTeamInstance;  // stores active team instance
        
//        static size_t activeBBallInstance;  // stores which instance of the baskteball class is active
        static basketballStateMSharedPtr basketballInstance;  // creates instance of the basketballs class
        static courtStateMSharedPtr courtInstance;  // stores the court instance
        hoopStateMSharedPtr hoopInstance;  // creates instance of the hoop class
        static playerEntityMSharedPtr playerInstance;  // stores the map of the players loaded from the xml files
        static teamStateMSharedPtr  teamInstance;  // creates instance of the teamState class

        static jumpBallsSharedPtr jumpBall; // instance that is used for jumpBall functions.

        static float yOffset; // stores the y offset for objects on the screen

        static std::vector<bool> teamActivePlayersChanged;  // stores whether the active players for each team have changed
                
};

#endif

