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

#include "components/hoopcomponents.h"
#include "entity/hoopentity.h"
#include "flags/hoopflags.h"

hoopEntity::hoopEntity() = default;  // constructor

hoopEntity::~hoopEntity()  = default;  // destructor

hoopComponentsSharedPtr hoopEntity::getComponent()  // retrieves the value of component
{
    return (component);
}
void hoopEntity::setComponent(hoopComponentsSharedPtr set)  // sets the value of component
{
    component = set;
}

hoopFlagsSharedPtr hoopEntity::getFlag()  // retrieves the value of flag
{
    return (flag);
}
void hoopEntity::setFlag(hoopFlagsSharedPtr set)  // sets the value of flag
{
    flag = set;
}

bool hoopEntity::initializeObjects()  // initializes hoop entity objects
{
    
    hoopComponentsSharedPtr tempComponent(new hoopComponents);
    component = tempComponent;
    
    hoopFlagsSharedPtr tempFlag(new hoopFlags);
    flag = tempFlag;

    return (true);
}
