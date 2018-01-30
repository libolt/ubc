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

#ifndef _AI_H_
#define _AI_H_

#include "ai/steering.h"
#include "OpenSteer/Clock.h"
#include <boost/shared_ptr.hpp>

#include "utilities/typedefs.h"

//#include "ai/playersteerplugin.h"

// forward declarations
class playerSteerPlugin;
class playerSteer;

class AISystem
{
public:

    //static AISystem *Instance();
    static sharedPtr<AISystem> Instance();
	~AISystem();

    gameStateSharedPtr getGameInstance();  // retrieves the value of gameInstance
    void setGameInstance(gameStateSharedPtr set);  // sets the value of gameInstance

    basketballStateMSharedPtr getActiveBasketballInstance();  // retrieves the value of activeBasketballInstance
    void setActiveBasketballInstance(basketballStateMSharedPtr set);  // sets the value of activeBasketballInstance

    courtStateMSharedPtr getActiveCourtInstance();  // retrieves the value of activeCourtInstance
    void setActiveCourtInstance(courtStateMSharedPtr set);  // sets the value of activeCourtInstance

    teamStateMSharedPtr getActiveTeamInstance();  // retrieves the value of activeTeamInstance
    void setActiveTeamInstance(teamStateMSharedPtr set);  // sets the value of activeTeamInstance

    teamTypes getTeamWithBall();  // retrieves the value of teamWithBall
    void setTeamWithBall(teamTypes set);  // sets the value of teamWithBall

    std::string getHumanPlayer();  // retrieves the value of the humanPlayer
    void setHumanPlayer(std::string set);  // sets the value of the human player

//    OpenSteer::AbstractVehicle* getSelectedVehicle(); // retrieves the value of selectedVehicle
    OpenSteerAbstractVehicleSharedPtr getSelectedVehicle(); // retrieves the value of selectedVehicle

    void setSelectedVehicle(OpenSteerAbstractVehicleSharedPtr vehicle);  // sets the value of selectedVehicle
//    void setSelectedVehicle(OpenSteer::AbstractVehicle vehicle);  // sets the value of selectedVehicle

    
//    playerSteerVecSharedPtr getAllPlayerSteers();	// retrieves the value of allPlayerSteers
//    void setAllPlayerSteers(const playerSteerVecSharedPtr steers);	// sets the value of allPlayerSteers

    playerSteerVecSharedPtr getAllPlayerSteers(); // retrieves the value of allPlayerSteers
    void setAllPlayerSteers(const playerSteerVecSharedPtr steers);    // sets the value of allPlayerSteers

    float getOldTime(); // returns the value of oldTime
    void setOldTime(float time); // sets the value of oldTime

    // initial setup of AI state
    bool setup(basketballStateMSharedPtr activeBasketballInstance, courtStateMSharedPtr activeCourtInstance, teamStateMSharedPtr activeTeamInstance, teamTypes teamWithBall, std::string humanPlayer);

	// updates AI state
	void update(const float currentTime, const float elapsedTime);

	void printPlugIn (OpenSteer::PlugIn& pi);

	// select the default PlugIn
    void selectDefaultPlugIn ();

	// select the "next" plug-in, cycling through "plug-in selection order"
    void selectNextPlugIn (teamStateMSharedPtr activeTeamInstance);

	// return name of currently selected plug-in
    const char *nameOfSelectedPlugIn ();

	// open the currently selected plug-in
    void openSelectedPlugIn (teamStateMSharedPtr activeTeamInstance);

	// do a simulation update for the currently selected plug-in
    void updateSelectedPlugIn (const float currentTime, const float elapsedTime);

	// close the currently selected plug-in
    void closeSelectedPlugIn ();

    // reset the currently selected plug-in
    void resetSelectedPlugIn ();

    // select the "next" vehicle: cycle through the registry
    void selectNextVehicle ();

    const OpenSteer::AVGroup& allVehiclesOfSelectedPlugIn();

	// currently selected vehicle
//    OpenSteer::AbstractVehicle* selectedVehicle;
    OpenSteerAbstractVehicleSharedPtr selectedVehicle;

//	playerSteerPlugin *playerSteerPluginInstance;
    playerSteerPluginSharedPtr playerSteerPluginInstance;
    
protected:
    AISystem();
    AISystem(const AISystem&);
    AISystem& operator= (const AISystem&);
private:
    //static AISystem *pInstance;
    static sharedPtr<AISystem> pInstance;
        
	// currently selected plug-in (user can choose or cycle through them)
//    OpenSteer::PlugIn* selectedPlugIn;
    OpenSteerPluginSharedPtr selectedPlugIn;
    playerSteerVecSharedPtr allPlayerSteers;

    gameStateSharedPtr gameInstance;  // stores copy of gameInstance
    basketballStateMSharedPtr activeBasketballInstance;  // stores copy of activeBasketballInstance
    courtStateMSharedPtr activeCourtInstance;  // stores copy of activeCourtInstance
    teamStateMSharedPtr activeTeamInstance;  // stores copy of activeTeamInstance
    teamTypes teamWithBall;  // stores copy of teamWithBall
    std::string humanPlayer;  // stores which player is human controlled

	// TIMER
	OpenSteer::Clock aiTimer;
	float oldTime;

};

 #endif

