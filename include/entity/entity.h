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

#ifndef _ENTITY_H_
#define _ENTITY_H_

//#include "utilities/conversion.h"

#include <string>
#include "Ogre.h"
#include "OgreEntity.h"
#include "OgreVector3.h"
#include "BtOgrePG.h"
#include "BtOgreGP.h"
#include "BtOgreExtras.h"
#include "utilities/typedefs.h"

class entity
{
    public:
    
    entity();  // constructor
    ~entity();  // destructor
    
/*    bool getInitialized() const;  // retrieves the value of initialized
    void setInitialized(const bool &set);  // sets the value of initialized
*/
    private:
    
//    bool initialized;  // stores whether entity object has been initialized
        
};

#endif

