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

#ifndef _OFFENSE_H_
#define _OFFENSE_H_

#include "utilities/typedefs.h"

class offense
{
    public:
        offense();  // constructor
        ~offense();  // destructor

        offenseComponentsSharedPtr getComponent();  // retrieves the value of component
        void setComponent(offenseComponentsSharedPtr set);  // sets the value of component

        offenseFlagsSharedPtr getFlag();  // retrieves the value of flag
        void setFlag(offenseFlagsSharedPtr set);  // sets the value of flag

    private:

        offenseComponentsSharedPtr component;  // offense components object
        offenseFlagsSharedPtr flag;  // offense flgs object
};

#endif // OFFENSE_H

