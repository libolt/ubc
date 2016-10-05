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

#ifndef _PLAYERSTEER_H_
#define _PLAYERSTEER_H_

#include "ai/steering.h"
#include "state/gamestateshared.h"
#include "enums.h"

class playerState;

class playerSteer : public steering, public gameStateShared
{
    public:

//	playerSteer(playerSteerVecSharedPtr others, playerSteerVecSharedPtr allplayers, /*Ball* ball,*/ bool isTeamA, int id);
    
    playerSteer();  // constructor
    ~playerSteer();  // destructor

    teamTypes getTeamType();  // retrieves the value of teamType
    void setTeamType(teamTypes set);  // sets the value of teamType

    size_t getID();  // retrieves the value of ID
    void setID(size_t set);  // sets the value of ID

    playerPositions getPlayerPosition();  // retrieves the value of playerPosition
    void setPlayerPosition(playerPositions set);  // sets the value of playerPosition
	
    float getDistToPosition();  // retrieves the value of distToPosition
    void setDistToPosition(float dist);  // sets value of distToPosition
	
    bool getExecute();  // retrieves the value of execute
    void setExecute(bool set);  // sets the value of execute
	
    OpenSteer::Vec3 getSteerCoords();  // retrieves the value of steerCoords
    void setSteerCoords(OpenSteer::Vec3 coords);  // sets the value of steerCoords
	
    boolVec getPositionReached();  // retrieves the value of positionReached
    void setPositionReached(boolVec reached);  // sets the value of positionReached
	
    void reset();  // resets the state
    void update (const float currentTime, const float elapsedTime);  // update steering sim every frame

    void checkCourtPosition();  // checks if the player's position has changed
    void updateOffense(const float currentTime, const float elapsedTime);  // updates the offense steering sim
    void updateDefense(const float currentTime, const float elapsedTime);  // updates the defense steering sim

    private:

    int counter;
    playerSteerVecSharedPtr m_others;  // stores steering object of other players
    playerSteerVecSharedPtr m_AllPlayers;  // stores steering objects of all players
    OpenSteer::Vec3 m_home;  // home point to stear to
    //Ball*	m_Ball;
    teamTypes teamType;  // stores which team the player belongs to
    int	m_MyID;
    int ID; // Stores which player on the team the instance associates with
    playerPositions playerPosition;  // stores which position the player is playing
    float distToPosition; // stores the distance player is from target position
	
    bool execute;  // stores whether or not to execute steering code
	
    OpenSteer::Vec3 steerCoords;  // stores the steering coordinates
	
    boolVec positionReached;  // stores whether or not positions have been reached
};

#endif
