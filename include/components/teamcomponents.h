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

#ifndef _TEAMCOMPONENTS_H_
#define _TEAMCOMPONENTS_H_

#include "utilities/typedefs.h"

class teamComponents
{
    public:
        teamComponents();  // constructor
        ~teamComponents();  // destructor

        playerEntityMSharedPtr getPlayerInstance();  // retrieves the value of playerInstance
        void setPlayerInstance(playerEntityMSharedPtr set);  // sets the value of  playerInstance

        playerEntityMSharedPtr getActivePlayerInstance();  // retrieves the value of activePlayerInstance
        void setActivePlayerInstance(playerEntityMSharedPtr set);  // sets the value of activePlayerInstance

        offenseStateSharedPtr getOffenseInstance();  // retrievers the value of offenseInstance
        void setOffenseInstance(offenseStateSharedPtr set);  // sets the value of offenseInstance

        defenseStateSharedPtr getDefenseInstance();  // retrieves the value of defenseInstance
        void setDefenseInstance(defenseStateSharedPtr set);  // sets the value of defenseInstance

        std::unordered_map<std::string, btRigidBodySharedPtr> getCollisionBodies();  // retrieves the value of collisionBodies
        void setCollisionBodies(std::unordered_map<std::string, btRigidBodySharedPtr> set);  // sets the value of collisionBodies

    private:
    
        playerEntityMSharedPtr playerInstance;  // stores instance of the playerState class containing all team players
        playerEntityMSharedPtr activePlayerInstance;  // stores instance of the playerState class containing the active players

        offenseStateSharedPtr offenseInstance;  // stores the offenseState instance
        defenseStateSharedPtr defenseInstance;  // stores the defenseState instance

        std::unordered_map<std::string, btRigidBodySharedPtr> collisionBodies;  // physical bodies to test for collisions with players physBody objects

};

#endif
