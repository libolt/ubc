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

#ifndef _BASKETBALLSTEER_H_
#define _BASKETBALLSTEER_H_

#include "ai/steering.h"
//#include "state/gamestateshared.h"
#include "OgreVector3.h"

class basketballSteer : public steering
{
    public:
 
        basketballSteer();
        ~basketballSteer();
        
        int getID(); // retrieves the value of ID
        void setID(int id); // sets the value of ID
 
        void reset(Ogre::Vector3 nodePosition); // resets the state
        void update (const float currentTime, const float elapsedTime); // update steering sim every frame
	
    private:
	 
        int ID; // Stores which player on the team the instance associates with
};
 
#endif
