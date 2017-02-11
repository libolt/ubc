/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
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

#ifndef _COURTSTATE_H_
#define _COURTSTATE_H_

#include "Ogre.h"

#include "BtOgrePG.h"
#include "BtOgreGP.h"
#include "BtOgreExtras.h"
#include "state/state.h"
#include "typedefs.h"
//#include "entity/courtentity.h"
//#include "data/courtdata.h"

//class state;
class courtEntity;
class courtData;

class courtState : public state
{
    public:

        courtState();   // constructor
        ~courtState();  // destructor


        sharedPtr<courtData> getData();  // retrieves the value of data
        void setData(sharedPtr<courtData> set);  // sets the value of data

        sharedPtr<courtEntity> getEntity();  // retrieves the value of entity
        void setEntity(sharedPtr<courtEntity> set);  // sets the value of entity

        bool getInitialized();  // retrieves the value of initialized
        void setInitialized(bool set);  // sets the value of initialized

        bool initialize();  // initializes the courtState object

    private:

        sharedPtr<courtData> data;  // stores the court data object
        sharedPtr<courtEntity> entity;  // stores the court entity object

        bool initialized;  // stores whether the courtState object has been initialized
};

#endif // COURTSTATE_H_INCLUDED
