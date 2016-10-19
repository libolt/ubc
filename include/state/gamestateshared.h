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

#ifndef _GAMESTATESHARED_H_
#define _GAMESTATESHARED_H_

//#include "state/courtstate.h"

#include "enums.h"
#include "typedefs.h"

#include <vector>
#include <cstddef>
#include "Ogre.h"
#include "boost/shared_ptr.hpp"

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

        static sizeTVec getTeamIDS(void);  // retrieves the value of teamIDS
        void setTeamIDS(sizeTVec set);  // sets the value of teamIDS
        
        std::vector< sizeTVec > getTeamStarterID();  // retrieves value of teamStarterID
        void setTeamStarterID(std::vector< sizeTVec > set);  // sets the value of teamStarterID

        bool getActiveTeamInstancesCreated();    // retrieves the value of activeTeamInstancesCreated
        void setActiveTeamInstancesCreated(bool set);    // sets the value of activeTeamInstancesCreated

        bool getActiveTeamInstancesNeedCreated();    // retrieves the value of activeTeamInstancesNeedCreated
        void setActiveTeamInstancesNeedCreated(bool set);    // sets the value of activeTeamInstancesNeedCreated

        bool getBasketballInstanceCreated();  // retrieves the value of basketballInstancesCreated
        void setBasketballInstanceCreated(bool set);   // sets the value of basketballInstancesCreated

        bool getBasketballInstanceNeedCreated();  // retrieves the value of basketballInstancesNeedCreated
        void setBasketballInstanceNeedCreated(bool set);   // sets the value of basketballInstancesNeedCreated
        
        bool getCourtInstancesCreated();  // retrieves the value of courtInstancesCreated
        void setCourtInstancesCreated(bool set);  // sets the value of courtInstancesCreated

        bool getCourtInstancesNeedCreated();  // retrieves the value of courtInstancesNeedCreated
        void setCourtInstancesNeedCreated(bool set);  // sets the value of courtInstancesNeedCreated

        bool getHoopInstanceCreated();  // retrieves the value of hoopInstancesCreated
        void setHoopInstanceCreated(bool created);  // sets the value of hoopInstancesCreated

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

        bool getTipOffComplete();  // retrieves the value of tipOffComplete
        void setTipOffComplete(bool set);  // sets the value of tipOffComplet

        quarters getQuarter();  // retrieves the value of quarter
        void setQuarter(quarters set);  // sets he value of quarter

        Ogre::Vector3 getBBallNodePosition();  // retrieves the value of bballNodePosition
        void setBBallNodePosition(Ogre::Vector3 set);  // sets the value of bballNodePosition
        
        teamTypes getTeamWithBall();  // retrieves the value of teamWithBall
        void setTeamWithBall(teamTypes set);  // sets the value of teamWithBall
        
        teamStateVecSharedPtr getActiveTeamInstance();  // retrieves the value of activeTeamInstance
        void setActiveTeamInstance(teamStateVecSharedPtr set);  // sets the value of activeTeamInstance
        
        size_t getActiveBBallInstance();  // retrieves the value of activeBBallInstance
        void setActiveBBallInstance(size_t set);  // sets the value of activeBBallInstance

        size_t getActiveCourtInstance();  // retrieves the value of activeCourtInstance
        void setActiveCourtInstance(size_t set);  // sets the value of activeCourtInstance

        basketballStateVecSharedPtr getBasketballInstance();  // retrieves the value of basketballInstance
        void setBasketballInstance(basketballStateVecSharedPtr set);  // sets the value of basketballInstance

        courtStateVecSharedPtr getCourtInstance();  // retrieves the value of courtInstance
        void setCourtInstance(courtStateVecSharedPtr set);  // sets the value of courtInstance

        hoopStateVecSharedPtr getHoopInstance();  // retrieves the value of hoopInstance
        void setHoopInstance(hoopStateVecSharedPtr set);  // sets the value of hoopInstance

        std::map <playerStateVecSharedPtr, size_t> getPlayerInstance();  // retrieves the value of playerInstance
        void setPlayerInstance(size_t ID, playerStateVecSharedPtr set);  // sets the value of  playerInstance

        static teamStateVecSharedPtr getTeamInstance();  // retireves the value of teamInstance
        void setTeamInstance(teamStateVecSharedPtr set);  // sets the value of teamInstance

        jumpBallsSharedPtr getJumpBall();  // retrieves the value of jumpBall
        void setJumpBall(jumpBallsSharedPtr set);  // sets the value of jumpBall

        float getYOffset();  // retrieves the value of yOffset
        void setYOffset(float set);  // sets the value of yOffset

    private:

        // used to determine if calling class needs to uldate its copy of the variable
        static bool activeTeamInstancesCreated;  // stores whether the active team instances have been created
        static bool activeTeamInstancesNeedCreated;  // stores whether or not to create active team instances
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
        static bool tipOffComplete;  // Determines whether or not game Tip Off has completed

        static gameTypes gameType;  // Indicates whether a single or multi player game is being played.
        static quarters quarter;  // stores the quarter currently being played
        static sizeTVec teamIDS;  // std::vector that stores the IDs of the 2 teams currently playing
        static std::vector< sizeTVec > teamStarterID;  // stores the selected starters for each team
        static Ogre::Vector3 bballNodePosition;  // stores a copy of the basketball node position
        static teamTypes teamWithBall;  // store which team has the basketball
        static teamStateVecSharedPtr activeTeamInstance;  // stores active team instance
        static size_t activeBBallInstance;  // stores which instance of the baskteball class is active
        static size_t activeCourtInstance;  // stores which instance of the court is active
        static basketballStateVecSharedPtr basketballInstance;  // creates instance of the basketballs class
        static courtStateVecSharedPtr courtInstance;  // stores the court instance
        static hoopStateVecSharedPtr hoopInstance;  // creates instance of the hoop class
        static std::map <size_t, playerStateVecSharedPtr> playerInstance;  // stores the vector of the players loaded from the xml files
        static teamStateVecSharedPtr  teamInstance;  // creates instance of the teamState class

        static jumpBallsSharedPtr jumpBall; // instance that is used for jumpBall functions.

        static float yOffset; // stores the y offset for objects on the screen



};

#endif

