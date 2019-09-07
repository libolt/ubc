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

#ifndef _HOOPENTITY_H_
#define _HOOPENTITY_H_

#include "entity/entity.h"

//class entity;

class hoopComponents;

class hoopEntity : public entity
{
    public:
    hoopEntity();  // constructor
    ~hoopEntity();  // destructor
    
    hoopComponentsSharedPtr getComponent();  // retrieves the value of component
    void setComponent(hoopComponentsSharedPtr set);  // sets the value of component
    
    hoopFlagsSharedPtr getFlag();  // retrieves the value of flag
    void setFlag(hoopFlagsSharedPtr set);  // sets the value of flag
 
    hoopStateMachineSharedPtr getStateMachine() const;  // retrievees the value of stateMachine
    void setStateMachine(const hoopStateMachineSharedPtr &set);  // sets the value of stateMachine


    hoopActions getAction() const;  // retrieves the value of action
    void setAction(const hoopActions &set);  // sets the vlue of action

    bool initializeObjects();  // initializes hoop entity objects
    
    bool initializeStateMachine();  // initializes the basketball stateMachine object

    bool updateStateMachine(renderEngineSharedPtr render);  // updates the stateMahine object

    private:
    
    bool objectsInitialized;  //  stores whether or not objects have been initialized

    hoopComponentsSharedPtr component;  // stores the hoopComponents object
    hoopFlagsSharedPtr flag;  // stores the hoopFlags object
    hoopStateMachineSharedPtr stateMachine; // stores the state machine object

    hoopActions action;  // stores the hoopActions object


};

#endif // _HOOPENTITY_H_
