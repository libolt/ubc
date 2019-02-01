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

#ifndef _DEFENSESTATEMACHINE_H_
#define _DEFENSESTATEMACHINE_H_

#include "statemachine/statemachine.h"
#include "utilities/enums.h"
#include "utilities/typedefs.h"

class defenseSMData : public eventData
{
    public:
};

class defenseStateMachine : public stateMachine
{
public:
    defenseStateMachine();

    // External events taken by this state machine
    void pSetup(defenseSMData *data);  // creates game object instances
    void pExecute(defenseSMData *data);  // loads the object model
    void pHalt();
    
private:
        // State enumeration order must match the order of state method entries
    // in the state map.
    enum States
    {
        ST_SETUP,
        ST_EXECUTE,      
        ST_IDLE,
        
        ST_MAX_STATES
    };

    // Define the state machine state functions with event data type
    STATE_DECLARE(defenseStateMachine,    setup,    defenseSMData)
    STATE_DECLARE(defenseStateMachine,    execute,    defenseSMData)
    STATE_DECLARE(defenseStateMachine,    Idle,            noEventData)

    // State map to define state object order. Each state map entry defines a
    // state object.
    BEGIN_STATE_MAP
        STATE_MAP_ENTRY(&setup)
        STATE_MAP_ENTRY(&execute)
        STATE_MAP_ENTRY(&Idle)
    END_STATE_MAP
};

#endif // DEFENSESTATEMACHINE_H
