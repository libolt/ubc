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

#include "components/courtcomponents.h"
#include "physics/courtphysics.h"

courtComponents::courtComponents()  // constructor
{
    number = 99999;
}

courtComponents::~courtComponents() = default;  // destructor

size_t courtComponents::getNumber() const  // retrieves the value of number
{
    return (number);
}
void courtComponents::setNumber(const size_t &set)  // sets the value of number
{
    number = set;
#ifdef BTOGRE_MYGUI_ENABLED
    physics->setPhysObjNumber(set); // sets the physics number as well
#endif
//    numberSet = true;
}

#ifdef BTOGRE_MYGUI_ENABLED
courtPhysicsSharedPtr courtComponents::getPhysics() const  // retrieves the value of physics
{
    return (physics);
}
void courtComponents::setPhysics(const courtPhysicsSharedPtr &set)  // sets the value of physics
{
    physics = set;
}

#endif
