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
#include "ai/steer.h"
#include "enums.h"

class playerState;

class playerSteer : public steering, public steer
{
    public:

//	playerSteer(std::vector<playerSteer*> others, std::vector<playerSteer*> allplayers, /*Ball* ball,*/ bool isTeamA, int id);
    playerSteer()
    {
        std::vector<playerSteer*> others;
        std::vector<playerSteer*> allplayers;
//	    bool isTeamA;
        int id = 0;
        m_others = others;
        m_AllPlayers = allplayers;
	    //m_Ball(ball),
//	    b_ImTeamA = isTeamA;
//        m_MyID = 0;
        m_MyID = id;

//    b_ImTeamA = true;
        teamType = NOTEAM;
        ID = -1;
        counter = 0;
        distToPosition = -1.0f;
        execute = false;
		
        m_home = OpenSteer::Vec3::zero;
//	steering::reset (); // reset the vehicle
        reset();
        setPosition(OpenSteer::Vec3(0,0,0));
        setRadius (0.5f);
        setMass(10.0f);
	/*    setSpeed (0.0f);         // speed along Forward direction.
    setMaxForce (3000.7f);      // steering force is clipped to this magnitude
    setMaxSpeed (10);         // velocity is clipped to this magnitude
    setRadius(1.0f);
    setMass(1.0f);
*/
    }
    
    ~playerSteer();

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
	
    std::vector<bool> getPositionReached();  // retrieves the value of positionReached
    void setPositionReached(std::vector<bool> reached);  // sets the value of positionReached
	
    void reset();  // resets the state
    void update (const float currentTime, const float elapsedTime);  // update steering sim every frame

    void checkCourtPosition();  // checks if the player's position has changed
    void updateOffense(const float currentTime, const float elapsedTime);  // updates the offense steering sim
    void updateDefense(const float currentTime, const float elapsedTime);  // updates the defense steering sim

    private:

    int counter;
    std::vector<playerSteer*> m_others;  // stores steering object of other players
    std::vector<playerSteer*> m_AllPlayers;  // stores steering objects of all players
    OpenSteer::Vec3 m_home;  // home point to stear to
    //Ball*	m_Ball;
    teamTypes teamType;  // stores which team the player belongs to
    int	m_MyID;
    int ID; // Stores which player on the team the instance associates with
    playerPositions playerPosition;  // stores which position the player is playing
    float distToPosition; // stores the distance player is from target position
	
    bool execute;  // stores whether or not to execute steering code
	
    OpenSteer::Vec3 steerCoords;  // stores the steering coordinates
	
    std::vector<bool> positionReached;  // stores whether or not positions have been reached
};

#endif
