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

#ifndef _OFFENSEFLAGS_H_
#define _OFFENSEFLAGS_H_

#include "utilities/typedefs.h"

class offenseFlags
{
    public:
    
        offenseFlags();  // constructor
        ~offenseFlags();  // destructor
        
        bool getExecute() const;    // retrieves the value of execute variable
        void setExecute(const bool &set);   // sets the value of the execute variable
    
        boolVec getStartXPosSet() const;  // retrieves the value of startXPosSet
        void setStartXPosSet(const boolVec &set);  // sets the value of startXPosSet

        boolVec getStartYPosSet() const;  // retrieves the value of startYPosSet
        void setStartYPosSet(const boolVec &set);  // sets the value of startYPosSet

        boolVec getStartZPosSet() const;  // retrieves the value of startZPosSet
        void setStartZPosSet(const boolVec &set);  // sets the value of startZPosSet

        boolVec getStartPositionReached() const;  // retrieves the value of startPositionReached
        void setStartPositionReached(const boolVec &set);  // sets the value of startPositionReached

        bool getAllStartPositionsReached() const;  // retrieves the value of allStartPositionsSet
        void setAllStartPositionsReached(const bool &set);  // sets the value of allStartPositionsSet

        std::vector< boolVec > getExecutePositionReached() const;  // returns the value of executePositionSet
        void setExecutePositionReached(const std::vector< boolVec > &set);  // sets the value of executePositionSet

        bool getOffenseSetup();  // retrieves the value of offenseSetup
        void setOffenseSetup(bool set);  // sets the value of offenseSetup
        
    private:
    
        bool offenseSet; // if true then run offense
        bool execute;   // If set then execute the offense logic
        boolVec startXPosSet; // stores whether player is at start X position
        boolVec startYPosSet; // stores whether player is at start Y position
        boolVec startZPosSet; // stores whether player is at start Z position
        boolVec startPositionReached; // stores whether player is at start position
        bool allStartPositionsReached;  // stores whether all player start positions have been reached
        bool allExecutePositionsReached;  // stores whether all player execute positions have been reached
    
        std::vector< boolVec > executePositionReached; // stores whether player is at execute position
        bool offenseSetup;

};
#endif
