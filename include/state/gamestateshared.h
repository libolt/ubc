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

#ifndef _GAMESTATESHARED_H_
#define _GAMESTATESHARED_H_

//#include "state/courtstate.h"

#include "utilities/enums.h"
#include "utilities/typedefs.h"

#include <vector>
#include <cstddef>
#include <unordered_map>
#include "Ogre.h"
//#include "boost/shared_ptr.hpp"

class playerEntity;
class basketballState;
class courtState;
class hoopState;
class playerState;
class teamState;
class jumpBalls;


class gameStateShared
{
    public:
    
        gameStateShared();  // constructor
        ~gameStateShared();  // destructor

        // getters and setters
                   
        
    private:

        // used to determine if calling class needs to uldate its copy of the variable                
};

#endif

