/***************************************************************************
 *   Copyright (C) 1999 - 2016 by Mike McLean                              *
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
 
#include "state/inputstate.h"
#include "logging.h"
#include "engine/inputengine.h"
//#include "engine/gameengine.h"
#include "userinput.h"
#include "load.h"

// static declarations
inputEngineSharedPtr inputState::inputE;  // the inputEngine object
inputInGameWorkQueues inputState::inputInGameWorkQueue; 


inputState::inputState()  // constructor
{   
//    uInput[0].setActive(true);
}
inputState::~inputState()  // destructor
{
    
}

inputEngineSharedPtr inputState::getInputE()  // retrieves the value of inputE
{
    return (inputE);
}
void inputState::setInputE(inputEngineSharedPtr set)  // sets the value of inputE
{
//    inputE = set;
}

userInputVecSharedPtr inputState::getUInput()  // retrieves the value of uInput
{
    return (uInput);
}
void inputState::setUInput(userInputVecSharedPtr set)  // sets the value of uInput
{
    uInput = set;
}

inputInGameWorkQueues inputState::getInputInGameWorkQueue()  // retrieves the value of inputInGameWorkQueue
{
    return (inputInGameWorkQueue);
}
void inputState::setInputInGameWorkQueue(inputInGameWorkQueues set)  // sets the value of inputInGameWorkQueue
{
    inputInGameWorkQueue = set;
}

bool inputState::setup()  // sets up the input state
{

    loaderSharedPtr load = base->getLoad();
    inputEngineSharedPtr tempInputSharedPtr(new inputEngine);
    inputE = tempInputSharedPtr;
//    uInput = load->loadUserInputs();  // loads user defined input from file.
    std::string func = "inputState::setup()";
    
    logMsg(func +" load->checkIfUserInputsLoaded()");

    if (load->checkIfUserInputsLoaded())
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

    return (true);
}

bool inputState::mapInput()  // maps value of keyPressed string to inputMap
{
    
    sharedPtr<conversion> convert = conversion::Instance();
    
    logMsg("Dah");
//    exit(0);
    
    if (inputE->getKeyInputReceived())
    {
//        int x = 0;
        inputKeyWorkQueues inputKeyWorkQueue = inputE->getInputKeyWorkQueue();
        inputKeyWorkQueues::iterator IKWQIIT;
        logMsg("inputKey!");
        logMsg("inputKeyWorkQueue.size() = " +convert->toString(inputKeyWorkQueue.size()));
//        while (x < inputKeyWorkQueue.size())
        for (IKWQIIT = inputKeyWorkQueue.begin(); IKWQIIT != inputKeyWorkQueue.end(); ++IKWQIIT)
        {
            // FIXME! uInput shoulnobe hard coded
            inputInGameWorkQueue.push_back(mapKeyInput(*IKWQIIT, uInput[0]));
//            ++x;
        }
    }
        
/*    switch (type)
    {
        case KEYBOARD:
            return (mapKeyInput());
        break;
    }
*/
return (true);
}

inputInGameMaps inputState::mapKeyInput(inputKeyMaps inKeyMap, sharedPtr<userInput> input)  // maps value of the keyPressed string to inputInGameMaps
{
    int x = 0;
//    while (x < uInput.size())
//    {
//    exit(0);
    
    logMsg("mapKeyInput");
    if (inKeyMap == input->getKeyUp())
    {
//        exit(0);
        return(INUP);
    }
//    exit(0);
    
    else if (inKeyMap == input->getKeyDown())
    {
        return(INDOWN);
    }
    else if (inKeyMap == input->getKeyLeft())
    {
        return(INLEFT);
    }
    else if (inKeyMap == input->getKeyRight())
    {
        return(INRIGHT);
    }
    else if (inKeyMap == input->getKeyUpLeft())
    {
        return(INUPLEFT);
    }
    else if (inKeyMap == input->getKeyUpRight())
    {
        return(INUPRIGHT);
    }
    else if (inKeyMap == input->getKeyDownLeft())
    {
        return(INDOWNLEFT);
    }
    else if (inKeyMap == input->getKeyDownRight())
    {
        return(INDOWNRIGHT);
    }
    else if (inKeyMap == input->getKeyPassSteal())
    {
        return(INPASSSTEAL);
    }
    else if (inKeyMap == input->getKeyShootBlock())
    {
        return(INSHOOTBLOCK);
    }
    else if (inKeyMap == input->getKeyPause())
    {
        return(INPAUSE);
    }
    else if (inKeyMap == input->getKeyStartSelect())
    {
        return(INSTARTSELECT);
    }
    else if (inKeyMap == input->getKeyQuit())
    {
        logMsg("keyQuit = " +input->getKeyQuit());
    return(INQUIT);
    }
    else
    {
        return(INNO);
    }
//    exit(0);
}

bool inputState::process()  // processes input
{
    sharedPtr<conversion> convert = conversion::Instance();
    logMsg("inoutState::process");
    if (inputE->processInput())
    {
//        int x = 0;
        inputTypeQueues inputTypeQueue = inputE->getInputTypeQueue();
        inputKeyWorkQueues inputKeyWorkQueue = inputE->getInputKeyWorkQueue();
        inputKeyWorkQueues::iterator IKWQIIT;

/*        while (x < inputKeyWorkQueue.size())
        {
            inputInGameWorkQueue.push_back(mapKeyInput(inputKeyWorkQueue[x], uInput[0]));
            x++;                            
        }*/
        for (IKWQIIT = inputKeyWorkQueue.begin(); IKWQIIT != inputKeyWorkQueue.end(); ++IKWQIIT)
        {
            // FIXME! uInput shoulnobe hard coded
            inputInGameWorkQueue.push_back(mapKeyInput(*IKWQIIT, uInput[0]));
//            ++x;
        }

    }
    
//        exit(0);

    return (true);
}
