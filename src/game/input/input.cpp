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
 *   along with this program; if not, write pppto the                         *
 *   Free Software Foundation, Inc.,            pll                           *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
 
#include "input/input.h"
#include "logging.h"
#include "engine/inputengine.h"
//#include "engine/gameengine.h"
#include "users/usersinputs.h"
#include "load/load.h"
#include "ubcbase.h"
#include "gui/gui.h"
#include "conversion.h"
#undef None

// static declarations
UBCBaseSharedPtr input::base;  // static copy of base class
inputEngineSharedPtr input::inputE;  // the inputEngine object
inputInGameWorkQueues input::inputInGameWorkQueue; 


input::input()  // constructor
{   
//    uInput[0].setActive(true);
}
input::~input()  // destructor
{
    
}

UBCBaseSharedPtr input::getBase()  // retrieves the value of base
{
    return (base);
}
void input::setBase(UBCBaseSharedPtr set)  // sets the value of base
{
    base = set;
}

inputEngineSharedPtr input::getInputE()  // retrieves the value of inputE
{
    return (inputE);
}
void input::setInputE(inputEngineSharedPtr set)  // sets the value of inputE
{
//    inputE = set;
}

usersInputsVecSharedPtr input::getUInput()  // retrieves the value of uInput
{
    return (uInput);
}
void input::setUInput(usersInputsVecSharedPtr set)  // sets the value of uInput
{
    uInput = set;
}

inputInGameWorkQueues input::getInputInGameWorkQueue()  // retrieves the value of inputInGameWorkQueue
{
    return (inputInGameWorkQueue);
}
void input::setInputInGameWorkQueue(inputInGameWorkQueues set)  // sets the value of inputInGameWorkQueue
{
    inputInGameWorkQueue = set;
}

bool input::setup()  // sets up the input state
{

    loaderSharedPtr load = base->getLoad();
    inputEngineSharedPtr tempInputSharedPtr(new inputEngine);
    inputE = tempInputSharedPtr;
//    uInput = load->loadUserInputs();  // loads user defined input from file.
    std::string func = "inputState::setup()";
    
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

