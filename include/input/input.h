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

 
#ifndef _INPUTSTATE_H_
#define _INPUTSTATE_H_

#include <vector>

#include "utilities/enums.h"
#include "engine/inputengine.h"

// typedefs

// forward declarations
//class inputEngine;
class usersInput;
class UBCBase;

class input
{
    public:
    
    input();  // constructor
    ~input();  // destructor
    
    UBCBaseSharedPtr getBase();  // retrieves the value of base
    void setBase(UBCBaseSharedPtr set);  // sets the value of base

    inputEngineSharedPtr getInputE();  // retrieves the value of gameE
    void setInputE(inputEngineSharedPtr set);  // sets the value of gameE
    
    usersInputsVecSharedPtr getUInput();  // retrieves the value of uInput
    void setUInput(usersInputsVecSharedPtr set);  // sets the value of uInput
    
    inputInGameWorkQueues getInputInGameWorkQueue();  // retrieves the value of inputInGameWorkQueue
    void setInputInGameWorkQueue(inputInGameWorkQueues set);  // sets the value of inputInGameWorkQueue
    
    bool setup();  // sets up the input state
    	      
    private:
    
    static UBCBaseSharedPtr base;  // static copy of base class
    static inputEngineSharedPtr inputE;  // the inputEngine object
    usersInputsVecSharedPtr uInput;  // stores user input mapping
    static inputInGameWorkQueues inputInGameWorkQueue;  // stores work queue for in game processing
    
};
#endif


