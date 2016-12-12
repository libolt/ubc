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
 
#ifndef _PLAYERSTEERPLUGIN_H_
#define _PLAYERSTEERPLUGIN_H_

#include "ai/steering.h"
#include "ai/playersteer.h"
#include "state/gamestateshared.h"

// PlugIn for OpenSteerDemo
class playerSteerPlugin : public OpenSteer::PlugIn, steering, public gameStateShared
{
    public:
        
    const char* name (void) {return "Player plugin";}

    // float selectionOrderSortKey (void) {return 0.06f;}

    // bool requestInitialSelection() { return true;}

    // be more "nice" to avoid a compiler warning
    ~playerSteerPlugin() {}

    void open();  // opens the plugin

    void update (const float currentTime, const float elapsedTime);  // updates the plugin state

    void redraw (const float currentTime, const float elapsedTime);

    void close ();  // closes the plugin

    void reset ();  // resets the plugin


    OpenSteer::AVGroup& allVehicles () {return (OpenSteer::AVGroup&) TeamA;} // returns list of all 'vehicles' in the game

    unsigned int m_PlayerCountA;  // counts number of players on Team A
    unsigned int m_PlayerCountB;  // counts number of playres on Team B
    playerSteerVecSharedPtr TeamA;  // stores steering objects for Team A
    playerSteerVecSharedPtr TeamB;  // stores teering objects for Team B
    playerSteerVecSharedPtr m_AllPlayers;  // stores steering objects for all players

//        Ball	*m_Ball;
    steeringAABBoxSharedPtr courtBBox;  // Axis Aligned Bounding Box for the court
/*        AABBox	*m_TeamAGoal;
        AABBox	*m_TeamBGoal;

    int junk;
    int	 m_redScore;
    int	 m_blueScore;
*/
};
 
 #endif
