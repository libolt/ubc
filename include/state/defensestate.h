/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean                              *
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

#ifndef _DEFENSESTATE_H_
#define _DEFENSESTATE_H_

#include "enums.h"
#include "state/state.h"

//class state;

class defenseState : public state
{
public:

    defenseState();	// constructor

    teamTypes getTeamType();  // retrieves the value of teamType
    void setTeamType(teamTypes set);  // sets the value of teamType
    
    courtSide_t getCourtSide();  // retrieves the value of courtSide
    void setCourtSide(courtSide_t set);  // sets the value of courtSide

    bool getExecute();	// retrieves the value of execute variable
    void setExecute(bool ex);	// sets the value of the execute variable

    void setupState();  // sets up initial state of the object

    void updateState(teamTypes teamType);  // updates the state of the object

private:

    teamTypes teamType;  // stores the type of team on defense
    courtSide_t courtSide;  // stores which side of the court the defense executes on.
    bool execute;	// If set then execute the defense logic

};

#endif
