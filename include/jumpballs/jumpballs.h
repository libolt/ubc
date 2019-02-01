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

#ifndef _JUMPBALLS_H_
#define _JUMPBALLS_H_

#include <vector>
#include <unordered_map>

#include "LinearMath/btVector3.h"

#include "utilities/enums.h"
#include "utilities/typedefs.h"

// forward declarations
class basketballState;
class teamState;

class jumpBalls
{
    public:

    jumpBalls();  // constructor
    ~jumpBalls();  // destructor
    
    jumpBallLocations_t getJumpBallLocation() const;  // retrieves the value of jumpBallLocation
    void setJumpBallLocation(const jumpBallLocations_t &set);  // sets the value of jumpBallLocation

    playerPositionsVec getJumpBallPlayer() const;  // retrieves the value of jumpBallPlayer
    void setJumpBallPlayer(const playerPositionsVec &set);  // sets the value of jumpBallPlayer

    bool getBallTipped() const;  // retrieves the value of the ballTipped
    void setBallTipped(const bool &set);  // sets the value of the ballTipped

    teamTypes getBallTippedToTeam() const;  // retrieves the value of the ballTippedToTeam
    void setBallTippedToTeam(const teamTypes &set);	 // sets the value of the ballTippedToTeam

    size_t getBallTippedToPlayerID() const;  // retrieves the value of the ballTippedToPlayerID
    void setBallTippedToPlayerID(const size_t &set);  // sets the value of the ballTippedToPlayerID

    size_t getBallTippedToPlayerInstance() const;  // retrieves the value of ballTippedToPlayerInstance
    void setBallTippedToPlayerInstance(const size_t &set);  // sets the vlaue of ballTippedToPlayerInstance

    playerPositions getBallTippedToPosition() const;  // retrieves the value of ballTippedToPosition
    void setBallTippedToPosition(const playerPositions &set);  // sets the value of ballTippedToPosition

    bool getBallTipForceApplied() const;  // retrieves the value of ballTipForceApplied
    void setBallTipForceApplied(const bool &set);  // sets the value of ballTipForceApplied

    bool getSetupComplete() const;  // retrieves the value of setup
    void setSetupComplete(const bool &set);  // sets the value of setup

    bool getExecuteJumpBall() const;  // retrieves the value of executeJumpBall
    void setExecuteJumpBall(const bool &set);  // sets the value of executeJumpBall

    bool getJumpBallComplete() const;  // retrieves the value of jumpBallComplete
    void setJumpBallComplete(const bool &set);  // sets the value of jumpBallComplete
    
    btVector3 getBBallVelocity() const;  // retrieves the value of bballVelocity
    void setBBallVelocity(const btVector3 &set);  // sets the value of bballVelocity

//    bool updateState(teamTypes teamWithBall, basketballEntityMSharedPtr activeBasketballInstance, teamEntityMSharedPtr activeTeamInstance, quarters quarter);  // updates state of the jumpBalls instance until jump ball has completed

    private:

    
    jumpBallLocations_t jumpBallLocation;  // sets where the jump ball is to be held
    playerPositionsVec jumpBallPlayer;  // stores which two players will be jumping for the ball
    bool ballTipped;  //	stores whether or not the ball has been tipped
    bool ballTipForceApplied;// stores whether or not force has been applied to tipped ball
    bool playerHasBasketball;  // stores whether or not a player has control of the basketball
    teamTypes ballTippedToTeam;  //  stores which team the ball has been tipped to
    size_t ballTippedToPlayerID;  // stores which player ID the ball has been tipped to
    size_t ballTippedToPlayerInstance;  // stores which player instance the ball has been tipped to
    playerPositions ballTippedToPosition;  // stores position that the ball is tipped to
    bool setupComplete;  // stores whether a jumpBall scenario has been setup.
    bool jumpBallComplete;  // jump ball code has completed and a player is in control of the baskteball
    bool executeJumpBall;  // stores whether or not to execute the jump ball sequence
    btVector3 bballVelocity;  // stores the velocity of the basketball

};

#endif // _JUMPBALLS_H_
