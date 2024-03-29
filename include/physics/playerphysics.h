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

#ifndef _PLAYERPHYSICS_H_
#define _PLAYERPHYSICS_H_

#ifdef _ENABLE_BTOGRE

#include "physics/physics.h"
#include "utilities/typedefs.h"
//#include "state/gamestateshared.h"

//class physics;
class gameState;

class playerPhysics : public physics
{
    public:
        playerPhysics();  // constructor
        ~playerPhysics();  // destructor
            
        void update();  // updates the player physics object

        void updatePosition();  // updates the position of player objecgts

        bool jump(teamTypes teamType, int playerID);  // calculates and executes player jumping in the air
        bool shootBasketball(teamTypes teamType, int playerID);  // calculates and executes basketball being shot
   
    private:
               
};
#endif
#endif // PLAYERPHYSICS_H

