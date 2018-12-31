/***************************************************************************
 *   Copyright (C) 1999 - 2018 by Mike McLean                              *
 *   libolt@libolt.net                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) anyh later version.                                   *
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

#ifndef _PLAYERFLAGS_H_
#define _PLAYERFLAGS_H_

#include "flags/entityflags.h"

class playerFlags : public entityFlags
{
    public:
        playerFlags();  // constructor
        ~playerFlags();  // destructor
    
        bool getSteerInitialized() const;  // retrieves the value of steerInitialized
        void setSteerInitialized(const bool &set);  // sets the value of steerInitialized

        bool getInitialized() const;  // retrieves the value of initialized
        void setInitialized(const bool &set);  // sets the value of initialized

        bool getPhysBodyInitialized() const;  // retrieves the value of physBodyInitialized
        void setPhysBodyInitialized(const bool &set);  // sets the value of physBodyInitialized

        bool getStateMachineInitialized() const;  // retrieves the value of stateMachineInitialized
        void setStateMachineInitialized(const bool &set);  // sets the value of stateMachineInitialized
    
        bool getStateChanged() const;  // retrieves the value of stateChanged
        void setStateChanged(const bool &set);  // sets the value of stateChanged

        bool getSMNodeSet() const;  // retrieves the value of SMNodeSet
        void setSMNodeSet(const bool &set);  // sets the value of SMNodeSet

        bool getSMModelSet() const;  // retrieves the value of SMModelSet
        void setSMModelSet(const bool &set);  // sets the value of SMModelSet

        bool getSMStartDirectionSet() const;  // retrieves the value of SMStartDirectionSet
        void setSMStartDirectionSet(const bool &set);  // sets the value of SMStartDirectionSet
    
        bool getMovement() const;  // retrieves the value of movement
        void setMovement(const bool &set);  // sets the value of movement

        bool getStartPosReached() const;  // retrieves the value of startPosReached
        void setStartPosReached(const bool &set);  // sets the value of startPosReached

        bool getShootBlock() const;  // retrieves the value of shootBlock
        void setShootBlock(const bool &set);  // sets the value of shootBlock

        bool getPassSteal() const;  // retrieves the value of passSteal
        void setPassSteal(const bool &set);  // sets the value of passSteal

        bool getPassBall() const;  // retrieves the value of passBall
        void setPassBall(const bool &set);  // sets the value of passBall

        bool getPassCalculated() const;  // retrieves the value of passCalculated
        void setPassCalculated(const bool &set);  // sets the value of passCalculated

        bool getPassCompleted() const;  // retrieves the value of passCompleted
        void setPassCompleted(const bool &set);  // sets the value of passCompleted

        bool getShotTaken() const;  // retrieves the value of shotTaken
        void setShotTaken(const bool &set);  // sets the value of shotTaken

        bool getShotSet() const;  // retrieves the value of shotSet
        void setShotSet(bool set);  // sets the value of shotSet

        bool getShotComplete();  // retrieves the value of shotComplete
        void setShotComplete(bool set);  // sets the value of shotComplete

        bool getJumpSet();  // retrieves the value of jumpSet
        void setJumpSet(const bool &set);  // sets the value of jumpSet

        bool getJumpComplete() const;  // retrieves the value of jumpComplete
        void setJumpComplete(const bool &set);  // sets the value of jumpComplete

        bool getOffenseSet() const;  // retrieves the value of offenseSet
        void setOffenseSet(const bool &set);  // sets the value of offenseSet

        bool getDefenseSet() const;  // retrieves the value of defenseSet
        void setDefenseSet(const bool &set);  // sets the value of defenseSet

        bool getCourtPositionChanged() const;  // retrieves the value of courtPositionChanged
        void setCourtPositionChanged(const bool &set);  // sets the value of courtPositionChanged

    private:
    
        bool steerInitialized; // stores whether the steer object has been initialized
        bool initialized;  // stores whether the player entity object has been initialized

        bool movement; // if true then player is moving

        bool startPosReached;  // stores whether a player is in the starting position for tipoff
       
        // variables for offense and defense;
        bool shootBlock;  // stores whether or not a player attempts to shoot or block a shot
        bool passSteal;  // stores whether a player attempts to pass or steal the ball

        // Passing variables
        bool passBall;  // stores whether a player is to pass the ball to another player or not.
        bool passCalculated;  // stores whether or not the player to pass ball to has been calculated
        bool passCompleted;  // stores whether or not the pass has been completed

        // Shooting variables
        bool shotTaken;  // Determines whether or not a player has shot the ball
        bool shotSet;  // Determines if shot has been setup
        bool shotComplete;  // Determine whether or not a player's shot is complete

        bool jumpSet;  // determines whether or not the playerJumpBeginPos has been set
        bool jumpComplete;  // determines whether or not the jump has been completed

        bool offenseSet;  // tracks state of player's offense
        bool defenseSet;  // tracks state of player's defense

        bool courtPositionChanged;  // if the court position has changed then this flag is set

        bool physBodyInitialized;  // Determines whether or not the btRigidBody object has been initialized

        bool stateMachineInitialized;   // Determines whether or not the stateMachine object has been initialized

        bool stateChanged;  // Determines if the stateMachine needs to be updated
    
        bool SMNodeSet; // Determines if the stateMachine's node value has been set
        bool SMModelSet; // Determines if the stateMachine's model value has been set
        bool SMStartDirectionSet;  // Determines if the stateMachine's direction value has been set for startvof game

};

#endif
