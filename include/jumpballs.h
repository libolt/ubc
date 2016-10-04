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

#ifndef _JUMPBALLS_H_
#define _JUMPBALLS_H_

#include <vector>
#include "LinearMath/btVector3.h"

#include "enums.h"
#include "typedefs.h"

// forward declarations
class basketballState;
class teamState;

class jumpBalls
{
    public:

    jumpBalls();  // constructor

    jumpBallLocations_t getJumpBallLocation();  // retrieves the value of jumpBallLocation
    void setJumpBallLocation(jumpBallLocations_t set);  // sets the value of jumpBallLocation

    std::vector<playerPositions> getJumpBallPlayer();  // retrieves the value of jumpBallPlayer
    void setJumpBallPlayer(std::vector<playerPositions> set);  // sets the value of jumpBallPlayer

    bool getBallTipped();  // retrieves the value of the ballTipped
    void setBallTipped(bool tipped);  // sets the value of the ballTipped

    teamTypes getBallTippedToTeam();  // retrieves the value of the ballTippedToTeam
    void setBallTippedToTeam(teamTypes set);	 // sets the value of the ballTippedToTeam

    size_t getBallTippedToPlayerID();  // retrieves the value of the ballTippedToPlayerID
    void setBallTippedToPlayerID(size_t player);  // sets the value of the ballTippedToPlayerID

    playerPositions getBallTippedToPosition();  // retrieves the value of ballTippedToPosition
    void setBallTippedToPosition(playerPositions set);  // sets the value of ballTippedToPosition

    bool getBallTipForceApplied();  // retrieves the value of ballTipForceApplied
    void setBallTipForceApplied(bool tip);  // sets the value of ballTipForceApplied

    bool getSetupComplete();  // retrieves the value of setup
    void setSetupComplete(bool set);  // sets the value of setup

    bool getExecuteJumpBall();  // retrieves the value of executeJumpBall
    void setExecuteJumpBall(bool set);  // sets the value of executeJumpBall

    btVector3 getBBallVelocity();  // retrieves the value of bballVelocity
    void setBBallVelocity(const btVector3 &set);  // sets the value of bballVelocity

    bool updateState(teamTypes teamWithBall, size_t activeBBallInstance, std::vector<basketballStateSharedPtr > basketballInstance, std::vector<boost::shared_ptr<teamState> > activeTeamInstance, quarters quarter);  // updates state of the jumpBalls instance until jump ball has completed

    bool jumpBallExecute(std::vector<basketballStateSharedPtr > basketballInstance, size_t activeBBallInstance, std::vector<boost::shared_ptr<teamState> > activeTeamInstance); // initiates jump ball from jump ball circle

    bool tipToPlayer(std::vector<basketballStateSharedPtr > basketballInstance, size_t activeBBallInstance, std::vector<boost::shared_ptr<teamState> > activeTeamInstance, quarters quarter);  // tips the basketball to the appropriate player

    private:

    
    jumpBallLocations_t jumpBallLocation;  // sets where the jump ball is to be held
    std::vector<playerPositions> jumpBallPlayer;  // stores which two players will be jumping for the ball
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
