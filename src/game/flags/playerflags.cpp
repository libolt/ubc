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

#include "flags/playerflags.h"
#include "utilities/logging.h"
#include "utilities/conversion.h"

playerFlags::playerFlags()  // constructor
{
    steerInitialized = false;
    initialized = false;
    physBodyInitialized = false;
    movement = false;
    startPosReached = false;
    shootBlock = false;
    passSteal = false;
    passBall = false;
    passCalculated = false;
    shotTaken = false;
    shotSet = false;
    shotComplete = false;
    offenseSet = false;
    defenseSet = false;
//    initialized = false;
    jumpSet = false;
    jumpComplete = false;
    courtPositionChanged = false;
    physBodyInitialized = false;
    stateMachineInitialized = false;
    
    stateChanged = false;
    SMNodeSet = false;
    SMModelSet = false;
}
playerFlags::~playerFlags()  // destructor
{

}

bool playerFlags::getSteerInitialized()  // retrieves the value of steerInitialized
{
    return (steerInitialized);
}
void playerFlags::setSteerInitialized(bool set)  // sets the value of steerInitialized
{
    steerInitialized = set;
}

bool playerFlags::getInitialized()  // retrieves the value of initialized
{
    return (initialized);
}
void playerFlags::setInitialized(bool set)  // sets the value of initialized
{
    initialized = set;
}

bool playerFlags::getPhysBodyInitialized()  // retrieves the value of physBodyInitialized
{
    return (physBodyInitialized);
}
void playerFlags::setPhysBodyInitialized(bool set)  // sets the value of physBodyInitialized
{
    physBodyInitialized = set;
}

bool playerFlags::getStateMachineInitialized()  // retrieves the value of stateMachineInitialized
{
    return (stateMachineInitialized);
}
void playerFlags::setStateMachineInitialized(bool set)  // sets the value of stateMachineInitialized
{
    stateMachineInitialized = set;
}

bool playerFlags::getStateChanged()  // retrieves the value of stateChanged
{
    return (stateChanged);
}
void playerFlags::setStateChanged(bool set)  // sets the value of stateChanged
{
    stateChanged = set;
}

bool playerFlags::getSMNodeSet()  // retrieves the value of SMNodeSet
{
    return (SMNodeSet);
}
void playerFlags::setSMNodeSet(bool set)  // sets the value of SMNodeSet
{
    SMNodeSet = set;
}

bool playerFlags::getSMModelSet()  // retrieves the value of SMModelSet
{
    return (SMModelSet);
}
void playerFlags::setSMModelSet(bool set)  // sets the value of SMModelSet
{
    SMModelSet = set;
}

bool playerFlags::getSMStartDirectionSet()  // retrieves the value of SMStartDirectionSet
{
    return (SMStartDirectionSet);
}
void playerFlags::setSMStartDirectionSet(bool set)  // sets the value of SMStartDirectionSet
{
    SMStartDirectionSet = set;
}

bool playerFlags::getMovement()  // retrieves the value of movement
{
    return (movement);
}
void playerFlags::setMovement(bool set)  // sets the value of movement
{
    movement = set;
}

bool playerFlags::getStartPosReached()  // retrieves the value of startPosReached
{
    return (startPosReached);
}
void playerFlags::setStartPosReached(bool set)  // sets the value of startPosReached
{
    startPosReached = set;
}

bool playerFlags::getShootBlock()  // retrieves the value of shootBlock
{
    return (shootBlock);
}
void playerFlags::setShootBlock(bool set)   // sets the value of shootBlock
{
    shootBlock = set;
}

bool playerFlags::getPassSteal()  // retrieves the value of passSteal
{
    return (passSteal);
}
void playerFlags::setPassSteal(bool set)  // sets the value of passSteal
{
    passSteal = set;
}

bool playerFlags::getPassBall()  // retrieves the value of passBall
{
    return (passBall);
}
void playerFlags::setPassBall(bool set)  // sets the value of passBall
{
    passBall = set;
}

bool playerFlags::getPassCalculated()  // retrieves the value of passCalculated
{
    return (passCalculated);
}
void playerFlags::setPassCalculated(bool set)  // sets the value of passCalculated
{
    passCalculated = set;
}

bool playerFlags::getPassCompleted()  // retrieves the value of passCompleted
{
    return (passCompleted);
}
void playerFlags::setPassCompleted(bool set)  // sets the value of passCompleted
{
    passCompleted = set;
}

bool playerFlags::getShotTaken()  // retrieves the value of shotTaken
{
    return (shotTaken);
}
void playerFlags::setShotTaken(bool set)  // sets the value of shotTaken
{
    shotTaken = set;
}

bool playerFlags::getShotSet()  // retrieves the value of shotSet
{
    return (shotSet);
}
void playerFlags::setShotSet(bool set)  // sets the value of shotSet
{
    shotSet = set;
}

bool playerFlags::getShotComplete()  // retrieves the value of shotComplete
{
    return (shotComplete);
}
void playerFlags::setShotComplete(bool set)  // sets the value of shotComplete
{
    shotComplete = set;
}

bool playerFlags::getJumpSet()  // retrieves the value of jumpSet
{
    return (jumpSet);
}
void playerFlags::setJumpSet(bool set)  // sets the value of jumpSet
{
    jumpSet = set;
}

bool playerFlags::getJumpComplete()  // retrieves the value of jumpComplete
{
    return (jumpComplete);
}
void playerFlags::setJumpComplete(bool set)  // sets the value of jumpComplete
{
    jumpComplete = set;
}

bool playerFlags::getOffenseSet()  // retrieves the value of offenseSet
{
    return (offenseSet);
}
void playerFlags::setOffenseSet(bool set)  // sets the value of offenseSet
{
    offenseSet = set;
}

bool playerFlags::getDefenseSet()  // retrieves the value of defenseSet
{
    return (defenseSet);
}
void playerFlags::setDefenseSet(bool set)  // sets the value of defenseSet
{
    defenseSet = set;
}

bool playerFlags::getCourtPositionChanged()  // retrieves the value of courtPositionChanged
{
    return (courtPositionChanged);
}
void playerFlags::setCourtPositionChanged(bool set)  // sets the value of courtPositionChanged
{
    courtPositionChanged = set;
}


