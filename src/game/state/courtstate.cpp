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

#include "state/courtstate.h"
#include "data/courtdata.h"
#include "entity/courtentity.h"
#include "engine/renderengine.h"
#include "utilities/logging.h"

courtState::courtState()
{
    entityInitialized = false;
    initialized = false;
//    stateSet = false;
}

courtState::~courtState()
{
}

sharedPtr<courtData> courtState::getData()  // retrieves the value of data
{
    return (data);
}
void courtState::setData(sharedPtr<courtData> set)  // sets the value of data
{
    data = set;
}

courtEntitySharedPtr courtState::getEntity()  // retrieves the value of entity
{
    return (entity);
}
void courtState::setEntity(courtEntitySharedPtr set)  // sets the value of entity
{
    entity = set;
}

bool courtState::getEntityInitialized()  // retrieves the value of entityInitialized
{
    return (entityInitialized);
}
void courtState::setEntityInitialized(bool set)  // sets the value of entityInitialized
{
    entityInitialized = set;
}

bool courtState::getInitialized()  // retrieves the value of initialized
{
    return (initialized);
}
void courtState::setInitialized(bool set)  // sets the value of initialized
{
    initialized = set;
}

bool courtState::initialize()  // initializes the courtState object
{
    sharedPtr<courtData> tempData(new courtData);
    data = tempData;

    courtEntitySharedPtr temppEntity(new courtEntity);
    entity = temppEntity;

    if (!entity->getInitialized())
    {
        if (entity->initialize())
        {
            entity->setInitialized(true);
        }
        else
        {
            logMsg("Unable to initialize court entity!");
            exit(0);
        }
    }
    else
    {
        
    }
    return (true);
}
