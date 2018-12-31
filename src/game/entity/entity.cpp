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

#include "entity/entity.h"
#include "engine/gameengine.h"
#include "engine/renderengine.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"
#include "ubc/ubc.h"

entity::entity()  // constructor
{
    initialized = false;
    nameSet = false;
    nodeNameSet = false;

    ID = 0;

    modelNeedsLoaded = false;
    modelLoaded = false;
    nodeCreated = false;
}

entity::~entity() = default;  // destructor

bool entity::getInitialized() const  // retrieves the value of initialized
{
    return (initialized);
}
void entity::setInitialized(const bool &set)  // sets the value of initialized
{
    initialized = set;
}

