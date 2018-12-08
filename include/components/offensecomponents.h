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

#ifndef _OFFENSECOMPONENTS_H_
#define _OFFENSECOMPONENTS_H_

#include "offense/offenseplays.h"

class offenseComponents
{
    public:
    
        offenseComponents();  // constructor
        ~offenseComponents();  // destructor
        
        teamTypes getTeamType() const;  // retrieves the value of teamType
        void setTeamType(const teamTypes &set);  // sets the value of teamType

        courtSide_t getCourtSide() const;  // retrieves the value of courtSide
        void setCourtSide(const courtSide_t &set);  // sets the value of courtSide

        int getSelectedOffense() const;  // retrieves the  value of selectedOffense
        void setSelectedOffense(const int &set);  // sets the value of selectedOffense

        offensePlaysVecSharedPtr getPlays() const;  // retrieves the value of plays
        void setPlays(const offensePlaysVecSharedPtr &set);  // sets the value of plays

        OgreVector3Vec getStartPositions() const;  // retrieves the value of the startPositions variable
        void setStartPositions(const OgreVector3Vec &set);  // sets the value startPositions variable

        std::vector <OgreVector3Vec > getExecutePositions() const;  // retrieves the value of the executePositions variable
        void setExecutePositions(const std::vector< OgreVector3Vec > &set);  // sets the value executePositions variable

        std::string getPlayName() const;  // retrieves the value of playName
        void setPlayName(const std::string &set);  // sets the value of playName
        
        std::string getPlayTitle() const;  // retrieves the value of playTitle
        void setPlayTitle(const std::string &set);  // sets the value of playTitle

        std::vector<offensePlays::playerDirectives> getPlayerDirective() const;  // retrieves the value of playerDirective
        void setPlayerDirective(const std::vector<offensePlays::playerDirectives> &set);  // sets the value of playerDirective

    private:
    
        teamTypes teamType;  // stores whether the offense is being run by the home or away team.
        courtSide_t courtSide;  // stores which side of the court the offense executes on.
        int selectedOffense; // stores which offense is being run
        std::string playName;  // stores the name of the offense being run
        std::string playTitle;  // stores the type of offense being run
        OgreVector3Vec startPositions;      // stores the positions for players get to in order to execute offense
        std::vector< OgreVector3Vec > executePositions;    // stores the positions where players move when executing offense
        int numStartPositionsReached;  // stores how many startPositions have been set.
        offensePlaysVecSharedPtr plays; // stores the plays for the offense to run
        std::vector<offensePlays::playerDirectives> playerDirective;  // stores values of the playerDirectives class associated with the play being run


};

#endif
