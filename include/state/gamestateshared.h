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
           
        static gameTypes getGameType();  // retrieves the value of gameType
        static void setGameType(gameTypes set);  // sets the value of gameType

        static std::vector<size_t> getTeamIDS(void);  // retrieves the value of teamIDS
        static void setTeamIDS(std::vector<size_t> set);  // sets the value of teamIDS
        
        static std::vector< std::vector<size_t> > getTeamStarterID();  // retrieves value of teamStarterID
        static void setTeamStarterID(std::vector< std::vector<size_t> > set);  // sets the value of teamStarterID

        static bool getActiveTeamInstancesCreated();    // retrieves the value of activeTeamInstancesCreated
        static void setActiveTeamInstancesCreated(bool set);    // sets the value of activeTeamInstancesCreated

        static bool getActiveTeamInstancesNeedCreated();    // retrieves the value of activeTeamInstancesNeedCreated
        static void setActiveTeamInstancesNeedCreated(bool set);    // sets the value of activeTeamInstancesNeedCreated

        static bool getBasketballInstanceCreated();  // retrieves the value of basketballInstancesCreated
        static void setBasketballInstanceCreated(bool set);   // sets the value of basketballInstancesCreated

        static bool getBasketballInstanceNeedCreated();  // retrieves the value of basketballInstancesNeedCreated
        static void setBasketballInstanceNeedCreated(bool set);   // sets the value of basketballInstancesNeedCreated
        
        bool getCourtInstancesCreated();  // retrieves the value of courtInstancesCreated
        void setCourtInstancesCreated(bool set);  // sets the value of courtInstancesCreated

        static bool getCourtInstancesNeedCreated();  // retrieves the value of courtInstancesNeedCreated
        static void setCourtInstancesNeedCreated(bool set);  // sets the value of courtInstancesNeedCreated

        static bool getHoopInstanceCreated();  // retrieves the value of hoopInstancesCreated
        static void setHoopInstanceCreated(bool created);  // sets the value of hoopInstancesCreated

        static bool getHoopInstanceNeedCreated();  // retrieves the value of hoopInstancesNeedCreated
        static void setHoopInstanceNeedCreated(bool created);  // sets the value of hoopInstancesNeedCreated

        static bool getPlayerInstanceCreated();  // retrieves the value of playerInstanceCreated
        static void setPlayerInstanceCreated(bool set);  // sets the value of playerInstanceCreated

        static bool getPlayerInstanceNeedCreated();  // retrieves the value of playerInstanceNeedCreated
        static void setPlayerInstanceNeedCreated(bool set);  // sets the value of playerInstanceNeedCreated

        static bool getTeamInstancesCreated();  // retrieves the value of teamInstancesCreated
        static void setTeamInstancesCreated(bool set);  // sets the value of teamInstancesCreated

        static bool getTeamInstancesNeedCreated();  // retrieves the value of teamInstancesNeedCreated
        static void setTeamInstancesNeedCreated(bool set);  // sets the value of teamInstancesNeedCreated

        static bool getBBallNodePositionChanged();  // retrieves the value of bballNodePositionChanged
        static void setBBallNodePositionChanged(bool set);  // sets the value of bballNodePositionChanged
        
        static bool getTeamWithBallChanged();  // retrieves the value of bballNodePositionChanged
        static void setTeamWithBallChanged(bool set);  // sets the value of teamWithBallChanged
        
        static bool getActiveTeamInstanceChanged();  // retrieves the value of activeTeamInstanceChanged
        static void setActiveTeamInstanceChanged(bool set);  // sets the value of activeTeamInstanceChanged
        
        static bool getGameSetupComplete();  // retrieves the value of gameSetupComplete
        static void setGameSetupComplete(bool set);  // sets the value of gameSetupComplete

        static bool getTipOffComplete();  // retrieves the value of tipOffComplete
        static void setTipOffComplete(bool set);  // sets the value of tipOffComplet

        static quarters getQuarter();  // retrieves the value of quarter
        static void setQuarter(quarters set);  // sets he value of quarter

        static Ogre::Vector3 getBBallNodePosition();  // retrieves the value of bballNodePosition
        static void setBBallNodePosition(Ogre::Vector3 set);  // sets the value of bballNodePosition
        
        static teamTypes getTeamWithBall();  // retrieves the value of teamWithBall
        static void setTeamWithBall(teamTypes set);  // sets the value of teamWithBall
        
        static std::vector<boost::shared_ptr<teamState> > getActiveTeamInstance();  // retrieves the value of activeTeamInstance
        static void setActiveTeamInstance(std::vector<boost::shared_ptr<teamState> > set);  // sets the value of activeTeamInstance
        
        static size_t getActiveBBallInstance();  // retrieves the value of activeBBallInstance
        static void setActiveBBallInstance(size_t set);  // sets the value of activeBBallInstance

        static size_t getActiveCourtInstance();  // retrieves the value of activeCourtInstance
        void setActiveCourtInstance(size_t set);  // sets the value of activeCourtInstance

        static std::vector <basketballState> getBasketballInstance();  // retrieves the value of basketballInstance
        static void setBasketballInstance(std::vector<basketballState> set);  // sets the value of basketballInstance

        static std::vector<courtState> getCourtInstance();  // retrieves the value of courtInstance
        static void setCourtInstance(std::vector<courtState> set);  // sets the value of courtInstance

        static std::vector <hoopState> getHoopInstance();  // retrieves the value of hoopInstance
        static void setHoopInstance(std::vector<hoopState> set);  // sets the value of hoopInstance

        std::vector<boost::shared_ptr<playerState> > getPlayerInstance();  // retrieves the value of playerInstance
        void setPlayerInstances(std::vector<boost::shared_ptr<playerState> > set);  // sets the value of playerInstance;

        static std::vector<boost::shared_ptr<teamState> > getTeamInstance();  // retireves the value of teamInstance
        static void setTeamInstance(std::vector<boost::shared_ptr<teamState> > set);  // sets the value of teamInstance

        static boost::shared_ptr<jumpBalls> getJumpBall();  // retrieves the value of jumpBall
        static void setJumpBall(boost::shared_ptr<jumpBalls> set);  // sets the value of jumpBall

        static float getYOffset();  // retrieves the value of yOffset
        static void setYOffset(float set);  // sets the value of yOffset

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
        static std::vector<size_t> teamIDS;  // std::vector that stores the IDs of the 2 teams currently playing
        static std::vector< std::vector<size_t> > teamStarterID;  // stores the selected starters for each team
        static Ogre::Vector3 bballNodePosition;  // stores a copy of the basketball node position
        static teamTypes teamWithBall;  // store which team has the basketball
        static std::vector<boost::shared_ptr<teamState> > activeTeamInstance;  // stores active team instance
        static size_t activeBBallInstance;  // stores which instance of the baskteball class is active
        static size_t activeCourtInstance;  // stores which instance of the court is active
        static std::vector <basketballState> basketballInstance;  // creates instance of the basketballs class
        static std::vector<courtState> courtInstance;  // stores the court instance
        static std::vector <hoopState> hoopInstance;  // creates instance of the hoop class
        static std::vector<boost::shared_ptr<playerState> > playerInstance;  // stores the vector of the players loaded from the xml files
        static std::vector <boost::shared_ptr<teamState> >  teamInstance;  // creates instance of the teamState class

        static boost::shared_ptr<jumpBalls> jumpBall; // instance that is used for jumpBall functions.

        static float yOffset; // stores the y offset for objects on the screen



};

#endif

