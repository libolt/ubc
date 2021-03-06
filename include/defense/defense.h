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

#ifndef _DEFENSE_H_
#define _DEFENSE_H_

#include "utilities/typedefs.h"

class defense
{
    public:
        defense();  // constructor
        ~defense();  // destructor

        defenseComponentsSharedPtr getComponent();  // retrieves the value of component
        void setComponent(defenseComponentsSharedPtr set);  // sets the value of component

        defenseFlagsSharedPtr getFlag();  // retrieves the value of flag
        void setFlag(defenseFlagsSharedPtr set);  // sets the value of flag

        defenseStateMachineSharedPtr getStateMachine();  // retrieves the value of stateMachine
        void setStateMachine(defenseStateMachineSharedPtr set);  // sets the value of stateMachine

    private:

        defenseComponentsSharedPtr component;  // stores the defense components object
        defenseFlagsSharedPtr flag;  // stores the defense flags object
        defenseStateMachineSharedPtr stateMachine;  // stores the defense stateMachine object

};

#endif // DEFENSE_H
