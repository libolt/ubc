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

 #include "defense/defense.h"

defense::defense()  // constructor
{

}

defense::~defense() = default;  // destructor

defenseComponentsSharedPtr defense::getComponent()  // retrieves the value of component
{
    return (component);
}
void defense::setComponent(defenseComponentsSharedPtr set)  // sets the value of component
{
    component = set;
}

defenseFlagsSharedPtr defense::getFlag()  // retrieves the value of flag
{
    return (flag);
}
void defense::setFlag(defenseFlagsSharedPtr set)  // sets the value of flag
{
    flag = set;
}

defenseStateMachineSharedPtr defense::getStateMachine()  // retrieves the value of stateMachine
{
    return (stateMachine);
}
void defense::setStateMachine(defenseStateMachineSharedPtr set)  // sets the value of stateMachine
{
    stateMachine = set;
}
