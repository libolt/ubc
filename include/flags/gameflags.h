/***************************************************************************
 *   Copyright (C) 1999 - 2019 by Mike McLean                              *
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

#include "utilities/typedefs.h"
class gameFlags
{
    public: 
    
        gameFlags();  // constructor
        ~gameFlags();  // destructor


        bool getInitialized() const;  // retrieves the value of initialized
        void setInitialized(const bool &set);  // sets the value of initialized

        bool getStateMachineInitialized() const;  // retrieves the value of stateMachineInitialized
        void setStateMachineInitialized(const bool &set);  // sets the value of stateMachineInitialized

        bool getActiveBasketballInstancesCreated() const;  // retrieves the value of activeBasketballInstancesCreated
        void setActiveBasketballInstancesCreated(const bool &set);  // sets the value of activeBasketballInstancesCreated

        bool getActiveCourtInstancesCreated() const;  // retrieves the value of activeCourtInstancesCreated
        void setActiveCourtInstancesCreated(const bool $set);  // sets the value of activeCourtInstancesCreated

        bool getActiveHoopInstancesCreated() const;  // retrieves the value of activeHoopInstancesCreated
        void setActiveHoopInstancesCreated(const bool &set);  // sets the value of activeHoopInstancesCreated

        bool getActiveTeamInstancesCreated() const;  // retrieves the value of activeTeamInstancesCreated
        void setActiveTeamInstancesCreated(const bool &set);  // sets the value of activeTeamInstancesCreated

        bool getActiveTeamInstancesSetup() const;  // retrieves the value of activeTeamInstancesSetup
        void setActiveTeamInstancesSetup(const bool &set);  // sets the value of activeTeamInstancesSetup

        bool getBasketballInstanceCreated() const;  // retrieves the value of basketballInstancesCreated
        void setBasketballInstanceCreated(const bool &set);  // sets the value of basketballInstancesCreated

        bool getBasketballInstanceNeedCreated() const;  // retrieves the value of basketballInstancesNeedCreated
        void setBasketballInstanceNeedCreated(const bool &set);  // sets the value of basketballInstancesNeedCreated
        
        bool getCourtInstancesCreated() const;  // retrieves the value of courtInstancesCreated
        void setCourtInstancesCreated(const bool &set);  // sets the value of courtInstancesCreated

        bool getCourtInstancesNeedCreated() const;  // retrieves the value of courtInstancesNeedCreated
        void setCourtInstancesNeedCreated(const bool &set);  // sets the value of courtInstancesNeedCreated

        bool getHoopInstancesCreated() const;  // retrieves the value of hoopInstancesCreated
        void setHoopInstancesCreated(const bool &created);  // sets the value of hoopInstancesCreated

        bool getHoopInstanceNeedCreated() const;  // retrieves the value of hoopInstancesNeedCreated
        void setHoopInstanceNeedCreated(const bool &created);  // sets the value of hoopInstancesNeedCreated

        bool getPlayerInstanceCreated() const;  // retrieves the value of playerInstanceCreated
        void setPlayerInstanceCreated(const bool &set);  // sets the value of playerInstanceCreated

        bool getPlayerInstanceNeedCreated() const;  // retrieves the value of playerInstanceNeedCreated
        void setPlayerInstanceNeedCreated(const bool &set);  // sets the value of playerInstanceNeedCreated

        bool getTeamInstancesCreated() const;  // retrieves the value of teamInstancesCreated
        void setTeamInstancesCreated(const bool &set);  // sets the value of teamInstancesCreated

        bool getTeamInstancesNeedCreated() const;  // retrieves the value of teamInstancesNeedCreated
        void setTeamInstancesNeedCreated(const bool &set);  // sets the value of teamInstancesNeedCreated
        
        bool getBBallNodePositionChanged() const;  // retrieves the value of bballNodePositionChanged
        void setBBallNodePositionChanged(const bool &set);  // sets the value of bballNodePositionChanged
        
        bool getTeamWithBallChanged() const;  // retrieves the value of bballNodePositionChanged
        void setTeamWithBallChanged(const bool &set);  // sets the value of teamWithBallChanged
        
        bool getActiveTeamInstanceChanged() const;  // retrieves the value of activeTeamInstanceChanged
        void setActiveTeamInstanceChanged(const bool &set);  // sets the value of activeTeamInstanceChanged
        
        bool getSetupComplete() const;  // retrieves the value of setupComplete
        void setSetupComplete(const bool &set);  // sets the value of setupComplete

        bool getJumpBallCreated() const;  // retrieves the value of jumpBallCreated
        void setJumpBallCreated(const bool &set);  // sets the value of jumpBallCreated

        bool getJumpBallSetup() const;  // retrieves the value of jumpBallSetup
        void setJumpBallSetup(const bool &set);  // sets the value of jumpBallSetup

        bool getJumpBallExecuteComplete() const;  // retrieves the value of jumpBallExecuteComplete
        void setJumpBallExecuteComplete(const bool &set);  // sets the value of jumpBallExecuteComplete

        bool getTipOffComplete() const;  // retrieves the value of tipOffComplete
        void setTipOffComplete(const bool &set);  // sets the value of tipOffComplet

        bool getPlayerHasBasketball() const;  // retrieves the value of playerHasBasketball
        void setPlayerHasBasketball(const bool &set);  // setd the value of playerHasBasketball
    
        bool getGameStarted() const;  // retrieves the gameStarted value
        void setGameStarted(const bool &set);  // sets gameStarted value

        bool getCourtDataLoaded() const;  // retrieves the value of courtDataLoaded
        void setCourtDataLoaded(const bool &set);  // sets the value of courtDataLoaded

        bool getBasketballModelLoaded() const;  // retrieves the value of basketballModelLoaded
        void setBasketballModelLoaded(const bool &set);  // sets the value of basketballModelLoaded

        bool getCourtModelLoaded() const;  // retrieves the value of courtModelLoaded
        void setCourtModelLoaded(const bool &set);  // sets the value of courtModelLoaded

        bool getHoopModelLoaded() const;  // retrieves the value of hoopModelLoaded
        void setHoopModelLoaded(const bool &set);  // sets the value of hoopModelLoaded

        bool getModelsLoaded() const;  // retrieves the value of modelsLoaded
        void setModelsLoaded(const bool &set);  // sets the value of modelsLoaded

        bool getBasketballNodeCreated() const;  // retrieves the value of basketballNodeCreated
        void setBasketballNodeCreated(const bool &set);  // sets the value of basketballNodeCreated

        bool getCourtNodeCreated() const;  // retrieves the value of courtNodeCreated
        void setCourtNodeCreated(const bool &set);  // sets the value of courtNodeCreated

        bool getHoopNodeCreated() const;  // retrieves the value of hoopNodeCreated
        void setHoopNodeCreated(const bool &set);  // sets the value of hoopNodeCreated

        bool getNodesCreated() const;  // retrieves the value of nodesCreated
        void setNodesCreated(const bool &set);  // sets the value of nodesCreated

        bool getBasketballStartPositionSet() const;  // retrieves the value of basketballStartPositionsSet
        void setBasketballStartPositionSet(const bool &set);  // sets the value of basketballStartPositionsSet

        bool getCourtStartPositionSet() const;  // retrieves the value of courtStartPositionsSet
        void setCourtStartPositionSet(const bool &set);  // sets the value of courtStartPositionsSet

        bool getHoopStartPositionSet() const;  // retrieves the value of hoopStartPositionsSet
        void setHoopStartPositionSet(const bool &set);  // sets the value of hoopStartPositionsSet

        bool getStartPositionsSet() const;  // retrieves the value of startPositionsSet
        void setStartPositionsSet(const bool &set);  // sets the value of startPositionsSet

        bool getTipOffSetupComplete() const;  // retrieves the value of tipOffSetupComplete
        void setTipOffSetupComplete(const bool &set);  // sets the value of tipOffSetupComplete

        bool getInputReceived() const;  // retrieves the value of inputReceived
        void setInputReceived(const bool &set);  // sets the value of inputReceived

        bool getSetupEnvironmentCompleted() const;  // retrieves the value of setupEnvironmentCompleted
        void setSetupEnvironmentCompleted(const bool &set);  // sets the value of setupEnvironmentCompleted

    private:
    
        bool initialized;  // if true then the object has been initialized
        bool stateMachineInitialized;  // stores whether stateMachine has been initialized
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
        bool setupComplete;  // indicates whether initial game setup is complete.
        bool jumpBallCreated;  // indicates whether jumpBall object has been created.
        bool jumpBallSetup;  // indicates whether jump ball has been setup.
        bool jumpBallExecuteComplete;  // indicates whether jump ball execution has completed
        bool tipOffComplete;  // Determines whether or not game Tip Off has completed
        bool finished;  // indicates whether a game is finished.
        bool setupEnvironmentCompleted;  // stores whether environment has been setup
        bool courtDataLoaded;  // stores whether or not the court data has been loaded from file
        bool basketballModelLoaded;  // stores whether basketball model has been loaded
        bool courtModelLoaded;  // stores whether court model has been loaded
        bool hoopModelLoaded;  // stores whether the hoop model has been loaded
        bool modelsLoaded;  // stores whether all models have been loaded
        bool basketballNodeCreated;  // stores whether basketball node has been created
        bool courtNodeCreated;  // stores whether court node has been created
        bool hoopNodeCreated;  // stores whether hoop node has been created
        bool nodesCreated;  // stores whether object scene nodes have been created
        bool basketballStartPositionSet;  // stores whether basketball start position has been set
        bool courtStartPositionSet;  // stores whether court start position has been set
        bool hoopStartPositionSet;  // stores whether hoop start position has been set
        bool startPositionsSet;  // stores whether object start positions have been set
        bool sceneCreated;  // stores whether the scene has been created
        bool gameStarted;  // Determines whether or not a basketball game has been started
        bool tipOffSetupComplete;  // Determines whether or not game Tip Off has been setup
        bool inputReceived;  // if true process input    

};

#endif
