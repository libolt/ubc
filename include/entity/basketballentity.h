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

#ifndef _BASKETBALLENTITY_H_
#define _BASKETBALLENTITY_H

#include "entity/entity.h"
#include "physics/basketballphysics.h"
#include "ai/basketballsteer.h"

class basketballEntity : public entity, public basketballPhysics
{
    public:
    
    basketballEntity();  // constructor
    ~basketballEntity();  // destructor
    
/*    basketballPhysics *getPhysics();  // retrieves the value of physics
    void setPhysics(basketballPhysics *set);  // sets the value of physics
*/
    boost::shared_ptr<basketballSteer> getSteer();  // retrieves the value of steer
    void setSteer(boost::shared_ptr<basketballSteer> set);  // sets the value of steer

    bool setupPhysicsObject();  // sets up the physics object
    
    private:

//    basketballPhysics *physics;  // instanciates an object to handle the physics for the basketball

    boost::shared_ptr<basketballSteer> steer;  // instance of the basketballSteer class

};
 
#endif
