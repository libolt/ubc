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

#ifndef _GAMESETUPPLAYERPOSITIONS_H_
#define _GAMESETUPPLAYERPOSITIONS_H_

#include "utilities/typedefs.h"

class setupPlayerPositions
{
    public:

        setupPlayerPositions();  // constructor
        ~setupPlayerPositions();  // destructor
        
        playerEntityMSharedPtr setJumpBallPositions(playerEntityMSharedPtr activePlayerInstance, teamTypes teamType, Ogre::Vector3 courtPos);  // sets player positions for jumpball
        bool setHalfTimePositions();  // sets player positions for start of the second half
        bool setTimeOutPositions();  // sets playerpositions coming out of timeout
        
    private:

};

#endif
