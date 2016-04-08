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

#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include <vector>
#include <boost/shared_ptr.hpp>

//#include "state/basketballstate.h"
//#include "data/courtdata.h"
//#include "state/courtstate.h"
//#include "state/hoopstate.h"
//#include "state/playerstate.h"
//#include "state/teamstate.h"
//#include "data/teamdata.h"
//#include "data/playerdata.h"
//#include "jumpballs.h"
#include "state/state.h"
//#include "state/gamestateshared.h"

class basketballState;
class UBC;
class courtData;
class courtState;
class hoopState;
class playerState;
class teamState;
class teamData;
class playerData;
class jumpBalls;
//class state;

class gameState : public state, public gameStateShared
{
public:

    //static gameState *Instance();
//    static boost::shared_ptr<gameState> Instance();

    gameState(); // constructor
    ~gameState();  // destructor

/*    gameTypes getGameType();  // retrieves the value of gameType
    void setGameType(gameTypes set);  // sets the value of gameType
*/
//    quarters getQuarter();  // retrieves the value of quarter
//    void setQuarters(quarters set);  // sets he value of quarter

/*    bool getGameSetupComplete();  // retrieves the value of gameSetupComplete
    void setGameSetupComplete(bool set);  // sets the value of gameSetupComplete
*/

    bool getPlayerHasBasketball();  // retrieves the value of playerHasBasketball
    void setPlayerHasBasketball(bool set);  // setd the value of playerHasBasketball
    
    bool getGameStarted(void);  // retrieves the gameStarted value
    void setGameStarted(bool set);  // sets gameStarted value

/*    boost::shared_ptr<jumpBalls> getJumpBall();  // retrieves the value of jumpBall
    void setJumpBall(boost::shared_ptr<jumpBalls> set);  // sets the value of jumpBall
*/

//    teamTypes getTeamWithBall(void);  // retrieves teamWithBall value
//    void setTeamWithBall(teamTypes set);	 // sets teamWithBall value

    size_t getBballBounce();  // retrieves the value of bballBounce
    void setBballBounce(size_t set);  // sets the value of bballBounce

    bool getCourtDataLoaded();  // retrieves the value of courtDataLoaded
    void setCourtDataLoaded(bool set);  // sets the value of courtDataLoaded

    size_t getSelectedCourtDataInstance();  // retrieves the value of selectedCourtDataInstance
    void setSelectedCourtDataInstance(size_t set);  // sets the value of selectedCourtDataInstance

/*    bool getBasketballInstancesCreated();  // retrieves the value of basketballInstancesCreated
    void setBasketballInstancesCreated(bool set);   // sets the value of basketballInstancesCreated
*/

/*    bool getCourtInstancesCreated();  // retrieves the value of courtInstancesCreated
    void setCourtInstancesCreated(bool created);  // sets the value of courtInstancesCreated
*/

/*    bool getHoopInstancesCreated();  // retrieves the value of hoopInstancesCreated
    void setHoopInstancesCreated(bool created);  // sets the value of hoopInstancesCreated
*/
/*    bool getPlayerInstanceCreated();  // retrieves the value of playerInstancesCreated
    void setPlayerInstanceCreated(bool created);  // sets the value of playerInstancesCreated
*/
/*    bool getTeamInstancesCreated();	 // retrieves the value of teamInstancesCreated
    void setTeamInstancesCreated(bool set);	 // sets the value of teamInstancesCreated
*/
/*    bool getActiveTeamInstancesCreated();	 // retrieves the value of activeTeamInstancesCreated
    void setActiveTeamInstancesCreated(bool set);	 // sets the value of activeTeamInstancesCreated
*/

    bool getBasketballModelLoaded();  // retrieves the value of basketballModelLoaded
    void setBasketballModelLoaded(bool set);  // sets the value of basketballModelLoaded

    bool getCourtModelLoaded();  // retrieves the value of courtModelLoaded
    void setCourtModelLoaded(bool set);  // sets the value of courtModelLoaded

    bool getHoopModelLoaded();  // retrieves the value of hoopModelLoaded
    void setHoopModelLoaded(bool set);  // sets the value of hoopModelLoaded

    bool getModelsLoaded();  // retrieves the value of modelsLoaded
    void setModelsLoaded(bool set);  // sets the value of modelsLoaded

/*    std::vector<teamData> getTeamDataInstance();  // retrieves the value of teamDataInstance
    void setTeamDataInstance(std::vector<teamData> set);  // sets the value of teamDataInstance;
*/

/*    std::vector<boost::shared_ptr<playerState> > getPlayerInstance();  // retrieves the value of playerInstance
    void setPlayerInstances(std::vector<boost::shared_ptr<playerState> > set);  // sets the value of playerInstance;
*/
    std::vector<courtData> getCourtDataInstance();  // retrieves the value of courtDataInstance
    void setCourtDataInstance(std::vector<courtData> set);  // sets the value of courtDataInstance

/*    size_t getActiveBBallInstance();  // retrieves the value of activeBBallInstance
    void setActiveBBallInstance(size_t set);  // sets the value of activeBBallInstance
*/

/*    size_t getActiveCourtInstance();  // retrieves the value of activeCourtInstance
    void setActiveCourtInstance(size_t set);  // sets the value of activeCourtInstance
*/

/*    std::vector<size_t> getTeamID(void);  // retrieves the value of teamID
    void setTeamID(std::vector<size_t> set);  // sets the value of teamID
*/

    std::vector<size_t> getPlayerID(void);  // retrieves the value of playerID
    void setPlayerID(std::vector<size_t> set);  // sets the value of playerID

/*    std::vector< std::vector<size_t> > getTeamStarterID();  // retrieves value of teamStarterID
    void setTeamStarterID(std::vector< std::vector<size_t> > set);  // sets the value of teamStarterID
*/

/*    std::vector <basketballState> getBasketballInstance();  // retrieves the value of basketballInstance
    void setBasketballInstance(std::vector<basketballState> set);  // sets the value of basketballInstance
*/

/*    std::vector<boost::shared_ptr<teamState> > getTeamInstance();  // retireves the value of teamInstance
    void setTeamInstance(std::vector<boost::shared_ptr<teamState> > set);  // sets the value of teamInstance
*/

//    std::vector <courtState> getCourtInstance();  // retrieves the value of courtInstance
//    void setCourtInstance(std::vector<courtState> set);  // sets the value of courtInstance

/*    std::vector <hoopState> getHoopInstance();  // retrieves the value of hoopInstance
    void setHoopInstance(std::vector<hoopState> set);  // sets the value of hoopInstance
*/
//    std::vector <boost::shared_ptr<teamState> > getActiveTeamInstance();  // retireves the value of activeTeamInstance
//    void setActiveTeamInstance(std::vector<boost::shared_ptr<teamState> > set);  // sets the value of activeTeamInstance

    bool getTipOffSetupComplete();  // retrieves the value of tipOffSetupComplete
    void setTipOffSetupComplete(bool set);  // sets the value of tipOffSetupComplete

//    bool getTipOffComplete();  // retrieves the value of tipOffComplete
//    void setTipOffComplete(bool set);  // sets the value of tipOffComplete

//    bool getStateSet();  // retrieves the value of stateSet
//    void setStateSet(bool set);  // sets the value of stateSet

//    void processNetworkEvents();  // processes events received from network connection.
//    void processNetworkPlayerEvents();  // processes player evernts received from network connection
    void updateDirectionsAndMovements();  // updates the movement and directions of game world objecxts
//    void updatePlayerDirections();  // updates the direction players are facing
    bool assignHoopToTeams();  // assigns which hoop belongs to each team
    bool setupEnvironment();  // sets up the 3D environment for the game
    void setBasketballStartPositions();  // sets the initial coordinates for the basketball(s).
    void setCourtStartPositions();  // sets the initial coordinates for the court(s).
    void setHoopStartPositions();  // sets the initial coordinates for the hoop(s).

    // Tip Off execution code.  // Move to proper class
    bool setupTipOff();  // sets up Tip Off conditions
    bool executeTipOff();  // executes the game tip off

    bool createInstances();  // creates object instances
    
    bool createBasketballInstances();  // creates the instances of the basketballs

    bool createTeamInstances();  // creates the instances of the teams

    bool createCourtDataInstances();  // creates instances of court data

    bool createCourtInstances();  // creates court Instances

    bool createHoopInstances();  // creates hoop Instances

    bool createPlayerInstances();  // creates player instances
    
    bool createActiveTeamInstances();  // creates the active team instances

    bool loadBasketballModel();  // loads selected basketball model
    bool loadCourtModel();  // loads selected court model
    bool loadHoopModel();  // loads selected hoop model
    bool loadModels();  // loads all game object models excluding the players

    bool setupState();  // sets up the game condition
    bool updateState();  // updates the state of the game

protected:
    
//    gameState(const gameState&);
//    gameState &operator = (const gameState&);

private:
    //static gameState *pInstance;
//    static boost::shared_ptr<gameState> pInstance;

//    gameTypes gameType;  // Indicates whether a single or multi player game is being played.
//    quarters quarter;  // stores the quarter currently being played

//    bool gameSetupComplete;  // indicates whether initial game setup is complete.

    float gameTimeLeft;  // Indicates the time left in the game
    float quarterTimeLeft;  // incates the time left in the current quarter

    bool finished;  // indicates whether a game is finished.

//    std::vector<teamData> teamDataInstance;	 // stores the vector of teams loaded from the xml files
//    std::vector<playerData> playerDataInstance;  // stores the vector of the players loaded from the xml files
//c    std::vector<boost::shared_ptr<playerState> > playerInstance;  // stores the vector of the players loaded from the xml files
    
    std::vector<courtData> courtDataInstance;  // stores the vector the courts loaded from the xml files

    size_t selectedCourtDataInstance;  // stores which court should be loaded by courtInstance
    
//    std::vector<size_t> teamID;  // std::vector that stores the IDs of the 2 teams currently playing
    std::vector<size_t> playerID;  // std::vector that stores the IDs of the players currently being used.

    std::vector< std::vector<size_t> > teamStarterID;  // stores the selected starters for each team

    // stores all instances of the objects
//    std::vector <basketballState> basketballInstance;  // creates instance of the basketballs class
//    std::vector <courtState> courtInstance;  // creates instance of the courtState class
//    std::vector <hoopState> hoopInstance;  // creates instance of the hoop class
//    std::vector < boost::shared_ptr<teamState> >  teamInstance;  // creates instance of the teamState class

    // stores active instances of objects
//    std::vector<boost::shared_ptr<teamState> > activeTeamInstance;  // stores the active team instances

//    size_t activeBBallInstance;  // stores which instance of the baskteball class is active
//    size_t activeCourtInstance;  // stores which instance of the court is active

    bool setupEnvironmentCompleted;  // stores whether environment has been setup
    bool courtDataLoaded;  // stores whether or not the court data has been loaded from file
//    bool basketballInstancesCreated;  // stores whether basketball instance(s) have been created
//    bool courtInstancesCreated;  // stores whether team instances have been created
//    bool hoopInstancesCreated;  // stores whether team instances have been created
//    bool playerInstancesCreated;  // stores whether player instances have been created
//    bool teamInstancesCreated;  // stores whether team instances have been created
//    bool activeTeamInstancesCreated;  // stores whether the active team instances have been created
    bool basketballModelLoaded;  // stores whether basketball model has been loaded
    bool courtModelLoaded;  // stores whether court model has been loaded
    bool hoopModelLoaded;  // stores whether the hoop model has been loaded
    bool modelsLoaded;  // stores whether all models have been loaded
    bool sceneCreated;  // stores whether the scene has been created
    bool gameStarted;  // Determines whether or not a basketball game has been started
    bool tipOffSetupComplete;  // Determines whether or not game Tip Off has been setup
//    bool tipOffComplete;  // Determines whether or not game Tip Off has completed

//    boost::shared_ptr<jumpBalls> jumpBall; // instance that is used for jumpBall functions.

//    teamTypes teamWithBall;  // stores which team has control of the basketball, valid values are 0 or 1

    size_t bballBounce;  // stores which direction the ball is bouncing;

//    bool stateSet;  // if true then the game state has been set

};


#endif // _GAMESTATE_H_
