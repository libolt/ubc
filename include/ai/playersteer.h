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

#ifndef _PLAYERSTEER_H_
#define _PLAYERSTEER_H_

#include "ai/steering.h"
//#include "state/gamestateshared.h"
#include "utilities/enums.h"
#include "utilities/typedefs.h"

class playerState;

class playerSteer : public steering
{
    public:

//	playerSteer(playerSteerVecSharedPtr others, playerSteerVecSharedPtr allplayers, /*Ball* ball,*/ bool isTeamA, int id);
    
    playerSteer();  // constructor
    ~playerSteer();  // destructor

//    gameStateSharedPtr getGameS();  // retrieves the value of gameS
//    void setGameS(gameStateSharedPtr set);  // sets the value of gameS

    teamTypes getTeamType() const;  // retrieves the value of teamType
    void setTeamType(const teamTypes &set);  // sets the value of teamType

    size_t getID() const;  // retrieves the value of ID
    void setID(const size_t &set);  // sets the value of ID

    playerPositions getPlayerPosition() const;  // retrieves the value of playerPosition
    void setPlayerPosition(const playerPositions &set);  // sets the value of playerPosition
	
    float getDistToPosition() const;  // retrieves the value of distToPosition
    void setDistToPosition(const float &dist);  // sets value of distToPosition
	
    bool getExecute() const;  // retrieves the value of execute
    void setExecute(const bool &set);  // sets the value of execute
	
    OpenSteer::Vec3 getSteerCoords() const;  // retrieves the value of steerCoords
    void setSteerCoords(const OpenSteer::Vec3 &coords);  // sets the value of steerCoords
	
    boolVec getPositionReached() const;  // retrieves the value of positionReached
    void setPositionReached(const boolVec &set);  // sets the value of positionReached
	
    AISystemSharedPtr getAI() const;  // retrieves the value of AI
    void setAI(const AISystemSharedPtr &set);  // sets the value of AI

    basketballEntityMSharedPtr getActiveBasketballInstance() const;  // retrieves the value of activeBasketballInstance
    void setActiveBasketballInstance(const basketballEntityMSharedPtr &set);  // sets the value of activeBasketballInstance

    courtEntityMSharedPtr getActiveCourtInstance() const;  // retrieves the value of activeCourtInstance
    void setActiveCourtInstance(const courtEntityMSharedPtr &set);  // sets the value of activeCourtInstance

    teamEntityMSharedPtr getActiveTeamInstance() const;  // retrieves the value of activeTeamInstance
    void setActiveTeamInstance(const teamEntityMSharedPtr &set);  // sets the value of activeTeamInstance

    teamTypes getTeamWithBall() const;  // retrieves the value of teamWithBall
    void setTeamWithBall(const teamTypes &set);  // sets the value of teamWithBall

    std::string getHumanPlayer() const;  // retrieves the value of the humanPlayer
    void setHumanPlayer(const std::string &set);  // sets the value of the human player

    void reset();  // resets the state
    void update(const float currentTime, const float elapsedTime);  // update steering sim every frame

    void checkCourtPosition();  // checks if the player's position has changed
    void updateOffense(const float currentTime, const float elapsedTime);  // updates the offense steering sim
    void updateDefense(const float currentTime, const float elapsedTime);  // updates the defense steering sim

    private:

//    gameStateSharedPtr gameS;  // the gameState object

    int counter;
    playerSteerVecSharedPtr m_others;  // stores steering object of other players
    playerSteerVecSharedPtr m_AllPlayers;  // stores steering objects of all players
    OpenSteer::Vec3 m_home;  // home point to stear to
    //Ball*	m_Ball;

    AISystemSharedPtr AI;  // stores copy of AI Instance
    basketballEntityMSharedPtr activeBasketballInstance;  // stores copy of activeBasketballInstance
    courtEntityMSharedPtr activeCourtInstance;  // stores copy of activeCourtInstance
    teamEntityMSharedPtr activeTeamInstance;  // stores copy of activeTeamInstance

    teamTypes teamType;  // stores which team the player belongs to
    teamTypes teamWithBall;  // stores copy of teamWithBall

    std::string humanPlayer;  // stores which player is human controlled

    int	m_MyID;
    size_t ID; // Stores which player on the team the instance associates with
    playerPositions playerPosition;  // stores which position the player is playing
    float distToPosition; // stores the distance player is from target position
	
    bool execute;  // stores whether or not to execute steering code
	
    OpenSteer::Vec3 steerCoords;  // stores the steering coordinates
	
    boolVec positionReached;  // stores whether or not positions have been reached
};

#endif
