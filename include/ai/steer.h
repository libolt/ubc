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

#ifndef _STEER_H_
#define _STEER_H_

#include <boost/shared_ptr.hpp>

#include "enums.h"
#include "OgreVector3.h"
#include "state/teamstate.h"
#include "state/courtstate.h"


//class OgreVector3;
//class teamState:
//class courtState;

class steer
{
    public:
    
        steer();  // constructor
        ~steer();  // destructor
        
        // getters and setters
        bool getBBallNodePositionChanged();  // retrieves the value of bballNodePositionChanged
        void setBBallNodePositionChanged(bool set);  // sets the value of bballNodePositionChanged
        
        bool getTeamWithBallChanged();  // retrieves the value of bballNodePositionChanged
        void setTeamWithBallChanged(bool set);  // sets the value of teamWithBallChanged
        
        bool getActiveTeamInstanceChanged();  // retrieves the value of activeTeamInstanceChanged
        void setActiveTeamInstanceChanged(bool set);  // sets the value of activeTeamInstanceChanged
        
        Ogre::Vector3 getBBallNodePosition();  // retrieves the value of bballNodePosition
        void setBBallNodePosition(Ogre::Vector3 set);  // sets the value of bballNodePosition
        
        teamTypes getTeamWithBall();  // retrieves the value of teamWithBall
        void setTeamWithBall(teamTypes set);  // sets the value of teamWithBall
        
        std::vector<boost::shared_ptr<teamState> > getActiveTeamInstance();  // retrieves the value of activeTeamInstance
        void setActiveTeamInstance(std::vector<boost::shared_ptr<teamState> > set);  // sets the value of activeTeamInstance
        
        std::vector<courtState> getCourtInstance();  // retrieves the value of courtInstance
        void setCourtInstance(std::vector<courtState> set);  // sets the value of courtInstance
        
    private:
    
    Ogre::Vector3 bballNodePosition;  // stores a copy of the basketball node position
    teamTypes teamWithBall;  // store which team has the basketball
    std::vector<boost::shared_ptr<teamState> > activeTeamInstance;  // stores active team instance
    std::vector<courtState> courtInstance;  // stores the court instance
    // used to determine if calling class needs to uldate its copy of the variable
    bool bballNodePositionChanged;
    bool teamWithBallChanged;
    bool activeTeamInstanceChanged;
};

 #endif
 
