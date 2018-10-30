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
//#include <boost/shared_ptr.hpp>

#include "utilities/typedefs.h"

//#include "ai/playersteerplugin.h"

// forward declarations
class playerSteerPlugin;
class playerSteer;
class teamEntity;

class AISystem
{
public:

    AISystem();  // constructor
    ~AISystem();  // destructor

    gameEntitySharedPtr getGameInstance();  // retrieves the value of gameInstance
    void setGameInstance(gameEntitySharedPtr set);  // sets the value of gameInstance

    basketballEntityMSharedPtr getActiveBasketballInstance();  // retrieves the value of activeBasketballInstance
    void setActiveBasketballInstance(basketballEntityMSharedPtr set);  // sets the value of activeBasketballInstance

    courtEntityMSharedPtr getActiveCourtInstance();  // retrieves the value of activeCourtInstance
    void setActiveCourtInstance(courtEntityMSharedPtr set);  // sets the value of activeCourtInstance

    teamEntityMSharedPtr getActiveTeamInstance();  // retrieves the value of activeTeamInstance
    void setActiveTeamInstance(teamEntityMSharedPtr set);  // sets the value of activeTeamInstance

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
    bool setup(basketballEntityMSharedPtr activeBasketballInstance, courtEntityMSharedPtr activeCourtInstance, teamEntityMSharedPtr activeTeamInstance, teamTypes teamWithBall, std::string humanPlayer);

	// updates AI state
	void update(const float currentTime, const float elapsedTime);

	void printPlugIn (OpenSteer::PlugIn& pi);

	// select the default PlugIn
    void selectDefaultPlugIn ();

	// select the "next" plug-in, cycling through "plug-in selection order"
    void selectNextPlugIn (teamEntityMSharedPtr activeTeamInstance);

	// return name of currently selected plug-in
    const char *nameOfSelectedPlugIn ();

	// open the currently selected plug-in
    void openSelectedPlugIn (teamEntityMSharedPtr activeTeamInstance);

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
    
private:

	// currently selected plug-in (user can choose or cycle through them)
//    OpenSteer::PlugIn* selectedPlugIn;
    OpenSteerPluginSharedPtr selectedPlugIn;
    playerSteerVecSharedPtr allPlayerSteers;

    gameEntitySharedPtr gameInstance;  // stores copy of gameInstance
    basketballEntityMSharedPtr activeBasketballInstance;  // stores copy of activeBasketballInstance
    courtEntityMSharedPtr activeCourtInstance;  // stores copy of activeCourtInstance
    teamEntityMSharedPtr activeTeamInstance;  // stores copy of activeTeamInstance
    teamTypes teamWithBall;  // stores copy of teamWithBall
    std::string humanPlayer;  // stores which player is human controlled

	// TIMER
	OpenSteer::Clock aiTimer;
	float oldTime;

};

 #endif

