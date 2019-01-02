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

#include "utilities/conversion.h"
#include "components/playercomponents.h"
#include "components/teamcomponents.h"
#include "data/playerdata.h"
#include "data/playergamedata.h"
#include "data/teamgamedata.h"
#include "entity/basketballentity.h"
#include "entity/playerentity.h"
#include "entity/teamentity.h"
#include "physics/basketballphysics.h"
#include "utilities/comparison.h"
#include "utilities/logging.h"
#include "engine/physicsengine.h"
#include "jumpballs/jumpballs.h"

jumpBalls::jumpBalls()  // constructor
{
    ballTipped = false;
    ballTippedToTeam = NOTEAM;
    ballTippedToPlayerID = 9999;
    ballTippedToPlayerInstance = 9999;
    ballTippedToPosition = NONE;
    ballTipForceApplied = false;
    setupComplete = false;
    executeJumpBall = false;
    jumpBallComplete = false;
	jumpBallLocation = NOLOCATION;
	playerHasBasketball = false;
    
}

jumpBalls::~jumpBalls() = default;  // destructor

jumpBallLocations_t jumpBalls::getJumpBallLocation() const  // retrieves teh value of jumpBallLocation
{
    return (jumpBallLocation);
}
void jumpBalls::setJumpBallLocation(const jumpBallLocations_t &set)  // sets the value of jumpBallLocation
{
    jumpBallLocation = set;
}

playerPositionsVec jumpBalls::getJumpBallPlayer() const  // retrieves the value of jumpBallPlayer
{
    return (jumpBallPlayer);
}
void jumpBalls::setJumpBallPlayer(const playerPositionsVec &set)  // sets the value of jumpBallPlayer
{
    jumpBallPlayer = set;
}

bool jumpBalls::getBallTipped() const	 // retrieves the value of ballTipped
{
    return (ballTipped);
}
void jumpBalls::setBallTipped(const bool &set)  // sets the value of ballTipped
{
    ballTipped = set;
}

teamTypes jumpBalls::getBallTippedToTeam() const  // retrieves the value of ballTippedToTeam
{
    return (ballTippedToTeam);
}
void jumpBalls::setBallTippedToTeam(const teamTypes &set)  // sets the value of ballTippedToTeam
{
    ballTippedToTeam = set;
}

size_t jumpBalls::getBallTippedToPlayerID() const  // retrieves the value of ballTippedToPlayerID
{
    return (ballTippedToPlayerID);
}
void jumpBalls::setBallTippedToPlayerID(const size_t &set)  // sets the value of ballTippedToPlayerID
{
    ballTippedToPlayerID = set;
}

size_t jumpBalls::getBallTippedToPlayerInstance() const  // retrieves the value of ballTippedToPlayerInstance
{
    return (ballTippedToPlayerInstance);
}
void jumpBalls::setBallTippedToPlayerInstance(const size_t &set)  // sets the vlaue of ballTippedToPlayerInstance
{
    ballTippedToPlayerInstance = set;
}

playerPositions jumpBalls::getBallTippedToPosition() const  // retrieves the value of ballTippedToPosition
{
    return (ballTippedToPosition);
}
void jumpBalls::setBallTippedToPosition(const playerPositions &set)  // sets the value of ballTippedToPosition
{
    ballTippedToPosition = set;
}

bool jumpBalls::getBallTipForceApplied() const  // retrieves the value of ballTipForceApplied
{
    return (ballTipForceApplied);
}
void jumpBalls::setBallTipForceApplied(const bool &set)  // sets the value of ballTipForceApplied
{
    ballTipForceApplied = set;
}

bool jumpBalls::getSetupComplete() const  // retrieves the value of setup
{
    return (setupComplete);
}
void jumpBalls::setSetupComplete(const bool &set)  // sets the value of setup
{
    setupComplete = set;
}

bool jumpBalls::getExecuteJumpBall() const  // retrieves the value of executeJumpBall
{
    return (executeJumpBall);
}
void jumpBalls::setExecuteJumpBall(const bool &set)  // sets the value of executeJumpBall
{
    executeJumpBall = set;
}

bool jumpBalls::getJumpBallComplete() const  // retrieves the value of jumpBallComplete
{
    return (jumpBallComplete);
}
void jumpBalls::setJumpBallComplete(const bool &set)  // sets the value of jumpBallComplete
{
    jumpBallComplete = set;
}

btVector3 jumpBalls::getBBallVelocity() const  // retrieves the value of bballVelocity
{
    return (bballVelocity);
}
void jumpBalls::setBBallVelocity(const btVector3 &set)  // sets the value of bballVelocity
{
    bballVelocity = set;
}

/*bool jumpBalls::updateState(teamTypes teamWithBall, basketballEntityMSharedPtr activeBasketballInstance, teamEntityMSharedPtr activeTeamInstance, quarters quarter)  // updates state of the jumpBalls instance
{
//    sharedPtr<gameState> gameS = gameState::Instance();
    conversionSharedPtr convert ;
    std::string func = "jumpBalls::updateState()";
    
    logMsg(func +" updating jumpBall state!");
    logMsg(func +" teamWithBall == " +convert->toString(teamWithBall));

//    size_t activeBBallInstance = gameS->getActiveBBallInstance();
//    basketballStateVec basketBallInstance = gameS->getBasketballInstance();
   // FIXME! Do NOT hard code activeBasketballInstance in the future
    bool bballPhysicsSetup = activeBasketballInstance[0]->getPhysicsSetup();
    if (teamWithBall == NOTEAM && bballPhysicsSetup) //&& gameS->getActiveTeamInstancesCreated())
    {

        logMsg(func +" teamWithBall = NOTEAM");
//        exit(0);
        logMsg(func +" jumpBallComplete == " +convert->toString(jumpBallComplete));
        if (!jumpBallComplete)
        {
//            exit(0);
            logMsg(func +" jump ball not complete");
            logMsg(func +" not complete ballTipped == " +convert->toString(ballTipped));
            
//            tipoff complete!exit(0);
            if (!ballTipped)
            {
                ballTipped = jumpBallExecute(activeBasketballInstance, activeTeamInstance);  // executes jump ball until ball is tipped
                logMsg (func +" Ball Tippped? " +convert->toString(ballTipped));
//                exit(0);
            }
            else
            {
//                exit(0);
                jumpBallComplete = tipToPlayer(activeBasketballInstance, activeTeamInstance, quarter);

                logMsg(func +" jumpBallComplete == " +convert->toString(jumpBallComplete));
//                exit(0);
            }
//            exit(0);
        }
        else
        {
            logMsg(func +" teamWithBall = " +convert->toString(teamWithBall));
//            exit(0);
        }
        logMsg(func +" ballTipped == " +convert->toString(ballTipped));
        logMsg(func +" ballTippedToTeam == " +convert->toString(ballTippedToTeam));
    }
    else
    {
        logMsg(func +" teamWithBall == " +convert->toString(teamWithBall));
        return (true);
    }
    
    logMsg(func +" jumpBall return(false)");
    
    return (false);  // returns false until jump ball has com=pleted
}*/



