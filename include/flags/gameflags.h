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

#ifndef _GAMEFLAGS_H_
#define _GAMEFLAGS_H_

class gameFlags
{
    public: 
    
        gameFlags();  // constructor
        ~gameFlags();  // destructor


        bool getInitialized();  // retrieves the value of initialized
        void setInitialized(bool set);  // sets the value of initialized

        sizeTVec getTeamIDS();  // retrieves the value of teamIDS
        void setTeamIDS(sizeTVec set);  // sets the value of teamIDS
        
        teamStarterIDsVecM getTeamStarterID();  // retrieves value of teamStarterID
        void setTeamStarterID(teamStarterIDsVecM set);  // sets the value of teamStarterID

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

        bool getPlayerHasBasketball();  // retrieves the value of playerHasBasketball
        void setPlayerHasBasketball(bool set);  // setd the value of playerHasBasketball
    
        bool getGameStarted();  // retrieves the gameStarted value
        void setGameStarted(bool set);  // sets gameStarted value

        bool getCourtDataLoaded();  // retrieves the value of courtDataLoaded
        void setCourtDataLoaded(bool set);  // sets the value of courtDataLoaded

        bool getBasketballModelLoaded();  // retrieves the value of basketballModelLoaded
        void setBasketballModelLoaded(bool set);  // sets the value of basketballModelLoaded

        bool getCourtModelLoaded();  // retrieves the value of courtModelLoaded
        void setCourtModelLoaded(bool set);  // sets the value of courtModelLoaded

        bool getHoopModelLoaded();  // retrieves the value of hoopModelLoaded
        void setHoopModelLoaded(bool set);  // sets the value of hoopModelLoaded

        bool getModelsLoaded();  // retrieves the value of modelsLoaded
        void setModelsLoaded(bool set);  // sets the value of modelsLoaded

        bool getTipOffSetupComplete();  // retrieves the value of tipOffSetupComplete
        void setTipOffSetupComplete(bool set);  // sets the value of tipOffSetupComplete

        bool getInputReceived();  // retrieves the value of inputReceived
        void setInputReceived(bool set);  // sets the value of inputReceived

    private:
    
        bool initialized;  // if true then tbe object has been initialized
        bool activeBasketballInstancesCreated;  // stores whether the active basketball instances have been created
        bool activeCourtInstancesCreated;  // stores whether the active court instances have been created
        bool activeHoopInstancesCreated;  // stores whether the active hoop instances have been created
        bool activeTeamInstancesCreated;  // stores whether the active team instances have been created
        bool activeTeamInstancesSetup;  // stores whether or not to setup active team instances
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
        bool jumpBallCreated;  // indicates whether jumpBall object has been created.
        bool tipOffComplete;  // Determines whether or not game Tip Off has completed
        bool finished;  // indicates whether a game is finished.
        bool setupEnvironmentCompleted;  // stores whether environment has been setup
        bool courtDataLoaded;  // stores whether or not the court data has been loaded from file
        bool basketballModelLoaded;  // stores whether basketball model has been loaded
        bool courtModelLoaded;  // stores whether court model has been loaded
        bool hoopModelLoaded;  // stores whether the hoop model has been loaded
        bool modelsLoaded;  // stores whether all models have been loaded
        bool nodesCreated;  // stores whether object scene nodes have been created
        bool sceneCreated;  // stores whether the scene has been created
        bool gameStarted;  // Determines whether or not a basketball game has been started
        bool tipOffSetupComplete;  // Determines whether or not game Tip Off has been setup
        bool inputReceived;  // if true process input    

};

#endif
