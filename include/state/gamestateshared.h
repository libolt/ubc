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
           
        gameTypes getGameType();  // retrieves the value of gameType
        void setGameType(gameTypes set);  // sets the value of gameType

        std::vector<size_t> getTeamIDS(void);  // retrieves the value of teamIDS
        void setTeamIDS(std::vector<size_t> set);  // sets the value of teamIDS
        
        std::vector< std::vector<size_t> > getTeamStarterID();  // retrieves value of teamStarterID
        void setTeamStarterID(std::vector< std::vector<size_t> > set);  // sets the value of teamStarterID

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
        
        std::vector<boost::shared_ptr<teamState> > getActiveTeamInstance();  // retrieves the value of activeTeamInstance
        void setActiveTeamInstance(std::vector<boost::shared_ptr<teamState> > set);  // sets the value of activeTeamInstance
        
        size_t getActiveBBallInstance();  // retrieves the value of activeBBallInstance
        void setActiveBBallInstance(size_t set);  // sets the value of activeBBallInstance

        size_t getActiveCourtInstance();  // retrieves the value of activeCourtInstance
        void setActiveCourtInstance(size_t set);  // sets the value of activeCourtInstance

        std::vector <basketballState> getBasketballInstance();  // retrieves the value of basketballInstance
        void setBasketballInstance(std::vector<basketballState> set);  // sets the value of basketballInstance

        std::vector<courtState> getCourtInstance();  // retrieves the value of courtInstance
        void setCourtInstance(std::vector<courtState> set);  // sets the value of courtInstance

        std::vector <hoopState> getHoopInstance();  // retrieves the value of hoopInstance
        void setHoopInstance(std::vector<hoopState> set);  // sets the value of hoopInstance

        std::vector<boost::shared_ptr<playerState> > getPlayerInstance();  // retrieves the value of playerInstance
        void setPlayerInstances(std::vector<boost::shared_ptr<playerState> > set);  // sets the value of playerInstance;

        std::vector<boost::shared_ptr<teamState> > getTeamInstance();  // retireves the value of teamInstance
        void setTeamInstance(std::vector<boost::shared_ptr<teamState> > set);  // sets the value of teamInstance

        boost::shared_ptr<jumpBalls> getJumpBall();  // retrieves the value of jumpBall
        void setJumpBall(boost::shared_ptr<jumpBalls> set);  // sets the value of jumpBall

        float getYOffset();  // retrieves the value of yOffset
        void setYOffset(float set);  // sets the value of yOffset

    private:
    
        // used to determine if calling class needs to uldate its copy of the variable
        bool activeTeamInstancesCreated;  // stores whether the active team instances have been created
        bool activeTeamInstancesNeedCreated;  // stores whether or not to create active team instances
        bool basketballInstanceCreated;  // stores whether basketball instance(s) have been created
        bool basketballInstanceNeedCreated;  // stores whether or not to create basketball instance(s)
        bool courtInstancesCreated;  // stores whether court instances have been created
        bool courtInstancesNeedCreated;  // stores whether or not to create court instances
        bool hoopInstancesCreated;  // stores whether hoop instances have been created
        bool hoopInstancesNeedCreated;  // stores whether or not to create hoop instances
        bool playerInstanceCreated;  // stores whether player instances have been created
        bool playerInstanceNeedCreated;  // stores whether or not to create player instances
        bool teamInstancesCreated;  // stores whether team instances have been created
        bool teamInstancesNeedCreated;  // stores whether or not to create team instances
        bool bballNodePositionChanged;  // stores whether basketball node position has changed
        bool teamWithBallChanged;  // stores whether team with ball has changed
        bool activeTeamInstanceChanged;  // stores whether activeTeamInstance has changed
        bool gameSetupComplete;  // indicates whether initial game setup is complete.
        bool tipOffComplete;  // Determines whether or not game Tip Off has completed

        gameTypes gameType;  // Indicates whether a single or multi player game is being played.
        quarters quarter;  // stores the quarter currently being played
        std::vector<size_t> teamIDS;  // std::vector that stores the IDs of the 2 teams currently playing
        std::vector< std::vector<size_t> > teamStarterID;  // stores the selected starters for each team
        Ogre::Vector3 bballNodePosition;  // stores a copy of the basketball node position
        teamTypes teamWithBall;  // store which team has the basketball
        std::vector<boost::shared_ptr<teamState> > activeTeamInstance;  // stores active team instance
        size_t activeBBallInstance;  // stores which instance of the baskteball class is active
        size_t activeCourtInstance;  // stores which instance of the court is active
        std::vector <basketballState> basketballInstance;  // creates instance of the basketballs class
        std::vector<courtState> courtInstance;  // stores the court instance
        std::vector <hoopState> hoopInstance;  // creates instance of the hoop class
        std::vector<boost::shared_ptr<playerState> > playerInstance;  // stores the vector of the players loaded from the xml files
        std::vector <boost::shared_ptr<teamState> >  teamInstance;  // creates instance of the teamState class

        boost::shared_ptr<jumpBalls> jumpBall; // instance that is used for jumpBall functions.

        float yOffset; // stores the y offset for objects on the screen



};

#endif

