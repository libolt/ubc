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

#include "flags/basketballflags.h"

basketballFlags::basketballFlags()  // constructor
{
    initialized = false;
    maxHeightReached = false;
    minHeightReached = false;

    tipOffStart = false;
    tipOff = false;

    dribblingStart = true;
    dribbling = false;

    movement = false;
    directChange = false;

    playerControlled = false;
    numberSet = false;

    courtPositionChanged = false;
}

basketballFlags::~basketballFlags() = default;  // destructor

bool basketballFlags::getInitialized() const  // retrieves the value of initialized
{
    return (initialized);
}
void basketballFlags::setInitialized(const bool &set)  // sets the value of initialized
{
    initialized = set;
}

bool basketballFlags::getMaxHeightReached() const  // retrieves the value of maxHeightReached
{
    return(maxHeightReached);
}
void basketballFlags::setMaxHeightReached(const bool &set)  // sets the value of maxHeightReachef
{
    maxHeightReached = set;
}

bool basketballFlags::getMinHeightReached() const  // retrieves the value of minHeightReached
{
    return(minHeightReached);
}
void basketballFlags::setMinHeightReached(const bool &set)  // sets the value of minHeightReached
{
    minHeightReached = set;
}

bool basketballFlags::getTipOffStart() const  // retroeves the value of tipOffStart
{
    return (tipOffStart);
}
void basketballFlags::setTipOffStart(const bool &set)  // sets the value of tipOffStart
{
    tipOffStart = set;
}

bool basketballFlags::getTipOff() const  // retrieves the value of tipOff
{
    return (tipOff);
}
void basketballFlags::setTipOff(const bool &set)  // sets the value of tipOff
{
    tipOff = set;
}

bool basketballFlags::getDribblingStart() const  // retrieves the value of dribblingStart
{
    return (dribblingStart);
}
void basketballFlags::setDribblingStart(const bool &set)  // sets the value of dribblingStart
{
    dribblingStart = set;
}

bool basketballFlags::getDribbling() const  // retrieves the value of dribbling
{
    return (dribbling);
}
void basketballFlags::setDribbling(const bool &set)  // sets the value of dribbling
{
    dribbling = set;
}

bool basketballFlags::getMovement() const  // retrieves the value of movement
{
    return (movement);
}
void basketballFlags::setMovement(const bool &set)  // sets the value of movement
{
    movement = set;
}

bool basketballFlags::getDirectChange() const  // retrieves the value of directChange
{
    return (directChange);
}
void basketballFlags::setDirectChange(const bool &set)  // sets the value of directChange
{
    directChange = set;
}

bool basketballFlags::getPlayerControlled() const  // retrieves the value of player controlled
{
    return (playerControlled);
}
void basketballFlags::setPlayerControlled(const bool &set)  // sets the value of playerControlled
{
    playerControlled = set;
}

bool basketballFlags::getNumberSet() const  // retrieves the value of numberSet
{
    return (numberSet);
}
void basketballFlags::setNumberSet(const bool &set)  // sets the value of numberSet
{
    numberSet = set;
}

bool basketballFlags::getCourtPositionChanged() const  // retrieves the value of courtPositionChanged
{
    return (courtPositionChanged);
}
void basketballFlags::setCourtPositionChanged(const bool &set)  // sets the value of courtPositionChanged
{
    courtPositionChanged = set;
}
