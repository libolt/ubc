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

#include "components/teamcomponents.h"

teamComponents::teamComponents()  // constructor
{

}
teamComponents::~teamComponents()  // destructor
{
    
}

playerEntityMSharedPtr teamComponents::getPlayerInstance() const  // retrieves the value of playerInstance
{
    return (playerInstance);
}
void teamComponents::setPlayerInstance(const playerEntityMSharedPtr &set)  // sets the value of playerInstance
{
    playerInstance = set;
}

playerEntityMSharedPtr teamComponents::getActivePlayerInstance() const  // retrieves the value of activePlayerInstance
{
    return (activePlayerInstance);
}
void teamComponents::setActivePlayerInstance(const playerEntityMSharedPtr &set)  // sets the value of activePlayerInstance
{
    activePlayerInstance = set;
}

offenseStateSharedPtr teamComponents::getOffenseInstance() const  // retrievers the value of offenseInstance
{
    return (offenseInstance);
}
void teamComponents::setOffenseInstance(const offenseStateSharedPtr &set)  // sets the value of offenseInstance
{
    offenseInstance = set;
}

defenseStateSharedPtr teamComponents::getDefenseInstance() const  // retrieves the value of defenseInstance
{
    return (defenseInstance);
}
void teamComponents::setDefenseInstance(const defenseStateSharedPtr &set)  // sets the value of defenseInstance
{
    defenseInstance = set;
}

std::map<std::string, btRigidBodySharedPtr> teamComponents::getCollisionBodies() const  // retrieves the value of collisionBodies
{
    return (collisionBodies);
}
void teamComponents::setCollisionBodies(const std::map<std::string, btRigidBodySharedPtr> &set)  // sets the value of collisionBodies
{
    collisionBodies = set;
}
