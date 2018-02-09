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

