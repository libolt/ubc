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

#include "ubcbase.h"
#include "engine/gameengine.h"

boost::shared_ptr<gameEngine> UBCBase::gameE;  // the gameEngine object


UBCBase::UBCBase()  // constructor
{
    
}

UBCBase::~UBCBase()  // destructor
{
    
}

boost::shared_ptr<gameEngine> UBCBase::getGameE()  // retrieves the value of gameE
{
    return (gameE);
}
void UBCBase::setGameE(boost::shared_ptr<gameEngine> set)  // sets the value of gameE
{
    gameE = set;
}
