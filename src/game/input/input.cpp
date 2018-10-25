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
 *   along with this program; if not, write pppto the                         *
 *   Free Software Foundation, Inc.,            pll                           *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
 
#include "input/input.h"
#include "utilities/logging.h"
#include "engine/inputengine.h"
//#include "engine/gameengine.h"
#include "users/usersinputs.h"
#include "load/load.h"
#include "gui/gui.h"
#include "utilities/conversion.h"
#undef None

// static declarations
inputEngineSharedPtr input::inputE;  // the inputEngine object
inputInGameWorkQueues input::inputInGameWorkQueue; 


input::input()  // constructor
{   
//    uInput[0].setActive(true);
    setupComplete = false;
    inputESet = false;
}
input::~input()  // destructor
{
    
}

inputEngineSharedPtr input::getInputE() const  // retrieves the value of inputE
{
    return (inputE);
}
void input::setInputE(const inputEngineSharedPtr &set)  // sets the value of inputE
{
    inputE = set;
}

usersInputsVecSharedPtr input::getUInput() const  // retrieves the value of uInput
{
    return (uInput);
}
void input::setUInput(const usersInputsVecSharedPtr &set)  // sets the value of uInput
{
    uInput = set;
}

inputInGameWorkQueues input::getInputInGameWorkQueue() const  // retrieves the value of inputInGameWorkQueue
{
    return (inputInGameWorkQueue);
}
void input::setInputInGameWorkQueue(const inputInGameWorkQueues &set)  // sets the value of inputInGameWorkQueue
{
    inputInGameWorkQueue = set;
}

bool input::getSetupComplete() const  // retrieves the value of setupComplete
{
    return (setupComplete);
}
void input::setSetupComplete(const bool &set)  // sets the value of setupComplete
{
    setupComplete = set;
}

bool input::getInputESet() const  // retrieves the value of inputESet
{
    return (inputESet);
}
void input::setInputESet(const bool &set)  // sets the value of inputESet
{
    inputESet = set;
}

bool input::setup(inputEngineSharedPtr inputE)  // sets up the input state
{
//    exit(0);
    loaderSharedPtr load(new loader);
//    inputEngineSharedPtr tempInputESharedPtr(new inputEngine);
//    inputE = tempInputESharedPtr;
//    uInput = load->loadUserInputs();  // loads user defined input from file.
    std::string func = "input::setup()";
    
/* FIXME! Remove once userInput is finished being reworked

    logMsg(func +" load->checkIfUserInputsLoaded()");

    if (load->checkIfUsersInputsLoaded())
    {
        uInput = load->getUIInstance();
        if (uInput.size() > 0)
        {
            logMsg(func +" uInput Loaded!");
        }
        else
        {
            logMsg(func +" uInput NOT Loaded!");
        }
    }
    else
    {
        logMsg(func +" loading of User Inout failed!");
        exit(false);
    }
*/
    return (true);
}

