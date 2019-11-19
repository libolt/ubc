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

#ifndef _COURTCOMPONENTS_H_
#define _COURTCOMPONENTS_H_

#include "utilities/typedefs.h"

#include "components/entitycomponents.h"

class courtComponents : public entityComponents
{
    public:
        courtComponents();  // constructor
        ~courtComponents();  // destructor

        size_t getNumber() const;  // retrieves the value of number
        void setNumber(const size_t &set);  // sets the value of number

        courtPhysicsSharedPtr getPhysics() const;  // retrieves the value of physics
        void setPhysics(const courtPhysicsSharedPtr &set);  // sets the value of physics

    private:
    
        size_t number;  // stores the court object number

        courtPhysicsSharedPtr physics;  // instanciates an object to handle the physics for the court

};

#endif
