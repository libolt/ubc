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

#ifndef _DEFENSECOMPONENTS_H_
#define _DEFENSECOMPONENTS_H_

#include "utilities/enums.h"

class defenseComponents
{
    public:
    
        defenseComponents();  // constructor
        ~defenseComponents();  // destructor

        teamTypes getTeamType() const;  // retrieves the value of teamType
        void setTeamType(const teamTypes &set);  // sets the value of teamType
    
        courtSide_t getCourtSide() const;  // retrieves the value of courtSide
        void setCourtSide(const courtSide_t &set);  // sets the value of courtSide

    private:
        teamTypes teamType;  // stores the type of team on defense
        courtSide_t courtSide;  // stores which side of the court the defense executes on.

};

#endif
