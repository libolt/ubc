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

#ifndef _PLAYERCOMPONENTS_H_
#define _PLAYERFLAGS_H_

class playerComponents
{
    public:
        playerComponents();  // constructor
        ~playerComponents();  // destructor
        
        playerPhysicsSharedPtr getPhysics();  // retrieves the value of physics
        void setPhysics(playerPhysicsSharedPtr set);  // sets the value of physics

        playerStateMachineSharedPtr getStateMachine();  // retrieves the value of stateMachine
        void setStateMachine(playerStateMachineSharedPtr set);  // sets the value of stateMachine

        playerStatisticsSharedPtr getStatistics();  // retrieves the value of statistics
        void setStatistics(playerStatisticsSharedPtr set);  // sets the value of statistics

        playerSteerSharedPtr getSteer();  // retrieves the value of steer
        void setSteer(playerSteerSharedPtr set);  // sets the value of steer


    private:
    
        playerStateMachineSharedPtr stateMachine;  // instance of playerStateMachine object

        playerPhysicsSharedPtr physics;  // instance of playerPhysics object

        playerStatisticsSharedPtr statistics;  // instance of playerStatistics object

        playerSteerSharedPtr steer;  // stores the steering objerct that represents the player
    
};

#endif
