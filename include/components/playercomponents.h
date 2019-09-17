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

#ifndef _PLAYERCOMPONENTS_H_
#define _PLAYERCOMPONENTS_H_

#include "utilities/typedefs.h"

#include "components/entitycomponents.h"

class playerComponents : public entityComponents
{
    public:
        playerComponents();  // constructor
        ~playerComponents();  // destructor

#ifdef BTOGRE_MYGUI_ENABLED
        playerPhysicsSharedPtr getPhysics() const;  // retrieves the value of physics
        void setPhysics(const playerPhysicsSharedPtr &set);  // sets the value of physics
#endif

        playerStateMachineSharedPtr getStateMachine() const;  // retrieves the value of stateMachine
        void setStateMachine(const playerStateMachineSharedPtr &set);  // sets the value of stateMachine

        playerStatisticsSharedPtr getStatistics() const;  // retrieves the value of statistics
        void setStatistics(const playerStatisticsSharedPtr &set);  // sets the value of statistics

        playerSteerSharedPtr getSteer() const;  // retrieves the value of steer
        void setSteer(const playerSteerSharedPtr &set);  // sets the value of steer

    private:
    
        playerStateMachineSharedPtr stateMachine;  // instance of playerStateMachine object

#ifdef BTOGRE_MYGUI_ENABLED
        playerPhysicsSharedPtr physics;  // instance of playerPhysics object
#endif

        playerStatisticsSharedPtr statistics;  // instance of playerStatistics object

        playerSteerSharedPtr steer;  // stores the steering objerct that represents the player
    
};

#endif
