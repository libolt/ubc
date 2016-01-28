/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean                              *
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

#ifndef _COURTENTITY_H_
#define _COURTENTITY_H_

#include "entity/entity.h"
#include "physics/courtphysics.h"

//class entity;
//class courtPhysics;

class courtEntity : public entity, public courtPhysics
{
    public:
        courtEntity();  // constructor
        ~courtEntity();  // destructor

/*        courtPhysics *getPhysics();  // retrieves the value of physics
        void setPhysics(courtPhysics *set);  // sets the value of physics
*/
        bool setupPhysicsObject();  // sets up the physics object

    private:
//        courtPhysics *physics;  // instanciates an object to handle the physics for the court
};

#endif // _COURTENTITY_H_
