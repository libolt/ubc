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

#ifndef _TEAMFLAGS_H_
#define _TEAMFLAGS_H_

#include "utilities/typedefs.h"

class teamFlags
{
    public:
        teamFlags();  // constructor
        ~teamFlags();  // destructor

        bool getStateMachineInitialized() const;  // retrieves the value of stateMachineInitialized
        void setStateMachineInitialized(const bool &set);  // sets the value of stateMachineInitialized

        bool getActivePlayerInstancesCreated() const;  // retrieves the value of activePlayerInstancesCreated
        void setActivePlayerInstancesCreated(const bool &set);  // sets the value of activePlayerInstancesCreated

        bool getActivePlayerInstancesSetup() const;  // retrieves the value of activePlayerInstancesSetup
        void setActivePlayerInstancesSetup(const bool &set);  // sets the value of activePlayerInstancesSetup

        bool getActivePlayerInstancesChanged() const;  // retrieves the value of activePlayerInstancesChanged
        void setActivePlayerInstancesChanged(const bool &set);  // sets the value of activePlayerInstancesChanged

        bool getPlayerInstancesCreated() const;  // retrieves the value of the playerInstancesCreated
        void setPlayerInstancesCreated(const bool &set);  // sets the value of the playerInstancesCreated

        bool getPlayerStartPositionsSet() const;  // retrieves the value of the playerStartPositionsSet
        void setPlayerStartPositionsSet(const bool &set);  // sets the value of the playerStartPositionsSet

        bool getPlayerStartDirectionsSet() const;  // retrieves the value of the playerStartDirectionsSet
        void setPlayerStartDirectionsSet(const bool &set);  // sets the value of the playerStartDirectionsSet

        bool getPlayerWithBallDribbling() const;  // retrieves the value of the playerWithBallDribbling
        void setPlayerWithBallDribbling(const bool &set);  // sets the value of the playerWithBallDribbling

        bool getHumanControlled() const;  // retrieves the value of the humanControlled
        void setHumanControlled(const bool &set);  // sets the value of the humanControlled

    private:
    
        bool stateMachineInitialized;  // stores whether stateMachine has been initialized
        
//        bool offense;  // if set then the team is on offense
//        bool defense;  // if set then the team is on defense

        bool activePlayerInstancesCreated;  // stores whether the active player instances have been created
        bool activePlayerInstancesSetup;  // stores whether the active player instances have been configured
        bool activePlayerInstancesChanged;  // stores whether the active player instances have been changed
        bool playerInstancesCreated;  // storea whethet player instances have been created.
        bool playerStartPositionsSet;  // stores whether player starting positions have been set
        bool playerStartDirectionsSet;  // stores whether player starting directions have been set

        bool playerWithBallDribbling;  // stores whether the player with the ball is dribbling

        bool humanControlled;  // stores whether the team object is controlled by a human player;

};

#endif
