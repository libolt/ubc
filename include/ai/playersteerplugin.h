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
 
#ifndef _PLAYERSTEERPLUGIN_H_
#define _PLAYERSTEERPLUGIN_H_

#include "ai/steering.h"
//#include "ai/playersteer.h"
#include "state/gamestateshared.h"

// Forward declarations
class playerSteer;


// PlugIn for OpenSteerDemo
class playerSteerPlugin : public OpenSteer::PlugIn, steering
{
    public:
        
    const char* name () {return "Player plugin";}

    // float selectionOrderSortKey () {return 0.06f;}

    // bool requestInitialSelection() { return true;}

    playerSteerPlugin();  // constructor
    ~playerSteerPlugin();  // destructor

    gameEntitySharedPtr getGameInstance();  // retrieves the value of gameInstance
    void setGameInstance(gameEntitySharedPtr set);  // sets the value of gameInstance

    basketballEntityMSharedPtr getActiveBasketballInstance();  // retrieves the value of activeBasketballInstance
    void setActiveBasketballInstance(basketballEntityMSharedPtr set);  // sets the value of activeBasketballInstance

    courtStateMSharedPtr getActiveCourtInstance();  // retrieves the value of activeCourtInstance
    void setActiveCourtInstance(courtStateMSharedPtr set);  // sets the value of activeCourtInstance

    teamEntityMSharedPtr getActiveTeamInstance();  // retrieves the value of activeTeamInstance
    void setActiveTeamInstance(teamEntityMSharedPtr set);  // sets the value of activeTeamInstance

    teamTypes getTeamWithBall();  // retrieves the value of teamWithBall
    void setTeamWithBall(teamTypes set);  // sets the value of teamWithBall

    std::string getHumanPlayer();  // retrieves the value of the humanPlayer
    void setHumanPlayer(std::string set);  // sets the value of the human player

    void open();  // opens the plugin

    void update (const float currentTime, const float elapsedTime);  // updates the plugin state

    void redraw (const float currentTime, const float elapsedTime);

    void close ();  // closes the plugin

    void reset ();  // resets the plugin


    OpenSteer::AVGroup& allVehicles () {return (OpenSteer::AVGroup&) TeamA;} // returns list of all 'vehicles' in the game

    private: 
      
    bool baseInitialized;  // stores whether the base object has been initialized
    
    unsigned int m_PlayerCountA;  // counts number of players on Team A
    unsigned int m_PlayerCountB;  // counts number of playres on Team B
    playerSteerVecSharedPtr TeamA;  // stores steering objects for Team A
    playerSteerVecSharedPtr TeamB;  // stores teering objects for Team B
    playerSteerVecSharedPtr m_AllPlayers;  // stores steering objects for all players

//        Ball	*m_Ball;
    steeringAABBoxSharedPtr courtBBox;  // Axis Aligned Bounding Box for the court

    gameEntitySharedPtr gameInstance;  // stores copy of gameInstance
    basketballEntityMSharedPtr activeBasketballInstance;  // stores copy of activeBasketballInstance
    courtStateMSharedPtr activeCourtInstance;  // stores copy of activeCourtInstance
    teamEntityMSharedPtr activeTeamInstance;  // stores copy of activeTeamInstance
    teamTypes teamWithBall;
    std::string humanPlayer;  // stores which player is human controlled

/*        AABBox	*m_TeamAGoal;
        AABBox	*m_TeamBGoal;

    int junk;
    int	 m_redScore;
    int	 m_blueScore;
*/
};
 
 #endif
