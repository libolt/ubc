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

#include "data/gamedata.h"

gameData::gameData()  // constructor
{
    numActiveHoops = 2;
    bballBounce = -1;
    gameTimeLeft = 0.0f;
    quarterTimeLeft = 0.0f;
    selectedCourtDataInstance = -1;

}
gameData::~gameData()  // destructor
{
    
}

size_t gameData::getSelectedCourtDataInstance()  // retrieves the value of selectedCourtDataInstance
{
    return (selectedCourtDataInstance);
}
void gameData::setSelectedCourtDataInstance(size_t set)  // sets the value of selectedCourtDataInstance
{
    selectedCourtDataInstance = set;
}

sizeTVec gameData::getPlayerID()  // retrieves the value of playerID
{
    return (playerID);
}
void gameData::setPlayerID(sizeTVec set)  // sets the value of playerID
{
    playerID = set;
}

size_t gameData::getBballBounce()  // retrieves the value of bballBounce
{
    return (bballBounce);
}
void gameData::setBballBounce(size_t set)  // sets the value of bballBounce
{
    bballBounce = set;
}
