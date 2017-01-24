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

#ifndef _PLAYERPHYSICS_H_
#define _PLAYERPHYSICS_H_

#include "physics/physics.h"
#include "typedefs.h"
//#include "state/gamestateshared.h"

//class physics;
class gameState;

class playerPhysics : public physics
{
    public:
        playerPhysics();  // constructor
        ~playerPhysics();  // destructor
    
        gameStateSharedPtr getGameS();  // retrieves the value of gameS
        void setGameS(gameStateSharedPtr set);  // sets the value of gameS
        
/*        bool getPhysicsSetup();  // retrieves the value of physicsSetup
        void setPhysicsSetup(bool set);  // sets the value of physicsSetup
        
        bool getStateSet();  // retrieves the value of stateSet
        void setStateSet(bool set);  // sets the value of stateSet
        
        playerPhysics();  // constructor

        bool setupPhysics();  // sets up player physics

        bool setupState();  // sets up state of player physics
        
        void updateState();  // updates the state of player physics
*/        
    void updatePosition();  // updates the position of player objecgts

    bool jump(teamTypes teamType, int playerID);  // calculates and executes player jumping in the air
    bool shootBasketball(teamTypes teamType, int playerID);  // calculates and executes basketball being shot
   
    private:
    
        static gameStateSharedPtr gameS;  // stores a copy of gameState object
/*        bool physicsSetup;  // determines whether all players' physics bodies have been setup
        bool stateSet;  // if true then the player physics state has been set
*/
};

#endif // PLAYERPHYSICS_H

