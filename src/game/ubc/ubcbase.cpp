/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
 *   libolt@libolt.net               'uu                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Fre8e Swhat are you doing my phoneoftware Foundation; either version 2 of the License, or     *
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

#include "ubc/ubcbase.h"
#include "engine/gameengine.h"
#include "state/gamestate.h"
#include "state/networkstate.h"
#include "input/inputkeyboards.h"
#include "input/inputgamepads.h"
#include "load/load.h"
#include "load/loadplayers.h"
#include "gui/gui.h"
#include "utilities/logging.h"
#include "users/users.h"

// Static Declarations
//bool UBCBase::stateSetup;


//sharedPtr<gameState> UBCBase::gameS;  // the gameState object
//loaderSharedPtr UBCBase::load;  // the loader object


/*UBCBase::UBCBase()  // constructor
{
    stateSetup = false;



}

UBCBase::~UBCBase()  // destructor
{
    
}*/

/*bool UBCBase::getStateSetup()  // retrieves the value of stateSetup
{
    return (stateSetup);
}

void UBCBase::setStateSetup(bool set)  // sets the value of stateSetup
{
    stateSetup = set;
}


        
loaderSharedPtr UBCBase::getLoad()  // retrieves the value of load
{
    return (load);
}
void UBCBase::setLoad(loaderSharedPtr set)  // sets the value of load
{
    load = set;
}




bool UBCBase::setup()  // sets up the engine and states
{
//    exit(0);
    std::string func = "UBCBase::setup()";
    
    logMsg(func +" beginning");
    

    GUISystemSharedPtr tempGUISharedPtr(new GUISystem);
    gui = tempGUISharedPtr;

    loaderSharedPtr tempLoaderSharedPtr(new loader);
    logMsg(func +" load = tempLoaderSharedPtr");
    load = tempLoaderSharedPtr;

    //FIXME! should not be hard coded
//    numUsers = 1;
//    exit(0);
//    networkState *tempNetworkStateObj = new networkState;
///    sharedPtr<networkState> tempNetworkStateSharedPtr = sharedPtr<networkState>(new networkState);
///    networkS = tempNetworkStateSharedPtr;
///    inputSharedPtr tempInputStateSharedPtr(new input);
///    inputS = tempInputStateSharedPtr;

///    inputS->setInputE(gameE->getInputE());
///    logMsg(func +" inputS->setup()");
///    inputS->setup();  // sets up the inputState object

    stateSetup = true;
    
    logMsg(func +" end");
    
    return (true);
}
*/
