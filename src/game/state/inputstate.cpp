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
 
#include "state/inputstate.h"
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
UBCBaseSharedPtr inputState::base;  // static copy of base class
inputEngineSharedPtr inputState::inputE;  // the inputEngine object
inputInGameWorkQueues inputState::inputInGameWorkQueue; 


inputState::inputState()  // constructor
{   
//    uInput[0].setActive(true);
}
inputState::~inputState()  // destructor
{
    
}

UBCBaseSharedPtr inputState::getBase()  // retrieves the value of base
{
    return (base);
}
void inputState::setBase(UBCBaseSharedPtr set)  // sets the value of base
{
    base = set;
}

inputEngineSharedPtr inputState::getInputE()  // retrieves the value of inputE
{
    return (inputE);
}
void inputState::setInputE(inputEngineSharedPtr set)  // sets the value of inputE
{
//    inputE = set;
}

usersInputsVecSharedPtr inputState::getUInput()  // retrieves the value of uInput
{
    return (uInput);
}
void inputState::setUInput(usersInputsVecSharedPtr set)  // sets the value of uInput
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

bool inputState::mapInput()  // maps value of keyPressed string to inputMap
{
    std::string func = "inputState::mapInput()";
    sharedPtr<conversion> convert = conversion::Instance();
    
    logMsg(func + " begin");
    logMsg(func + " Dah");
//    exit(0);
    
    if (inputE->getKeyInputReceived())
    {
//        int x = 0;
        inputKeyWorkQueues inputKeyWorkQueue = inputE->getInputKeyWorkQueue();
        inputKeyWorkQueues::iterator IKWQIIT;
        logMsg(func + " inputKey!");
        logMsg(func + " inputKeyWorkQueue.size() = " +convert->toString(inputKeyWorkQueue.size()));
//        while (x < inputKeyWorkQueue.size())
        for (IKWQIIT = inputKeyWorkQueue.begin(); IKWQIIT != inputKeyWorkQueue.end(); ++IKWQIIT)
        {
            // FIXME! uInput shoulnobe hard coded
            usersInputsVecSharedPtr::iterator UIIT;
            for (UIIT = uInput.begin(); UIIT != uInput.end(); ++UIIT)
            {
                inputInGameWorkQueue.push_back(mapKeyInput(*IKWQIIT, *UIIT));
            }
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
    logMsg(func + " end");
    
return (true);
}

inputInGameMaps inputState::mapKeyInput(inputKeyMaps inKeyMap, usersInputsSharedPtr input)  // maps value of the keyPressed string to inputInGameMaps
{
    sharedPtr<conversion> convert = conversion::Instance();
    size_t x = 0;
    std::string func = "inputState::mapKeyInput()";
//    while (x < uInput.size())
//    {
//    exit(0);
    logMsg(func + " begin");
    logMsg(func + " userInput name == " +input->getName());
//    exit(0);
    logMsg(func + " mapKeyInput");
    logMsg(func + " inKeyMap = " +convert->toString(inKeyMap));
    logMsg(func +" inKeyMap keyQuit = " +convert->toString(input->getKeyQuit()));

    if (inKeyMap == input->getKeyUp())
    {
        return(INUP);
    }
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
        logMsg(func +" keyQuit = " +convert->toString(input->getKeyQuit()));
//        exit(0);
        return(INQUIT);
    }
    else
    {
        return(INNO);
    }
//    exit(0);
    logMsg(func + " end");
}

bool inputState::process()  // processes input
{
    sharedPtr<conversion> convert = conversion::Instance();
    std::string func = "inputState::process()";
    
    logMsg(func + " begin");
//    exit(0);
    
    if (inputE->processInput())
    {
//        int x = 0;
        inputTypeQueues inputTypeQueue = inputE->getInputTypeQueue();
        inputKeyWorkQueues inputKeyWorkQueue = inputE->getInputKeyWorkQueue();
        inputKeyWorkQueues::iterator IKWQIIT;

        logMsg(func + " uInput.size == " +convert->toString(uInput.size()));
//        exit(0);
/*        while (x < inputKeyWorkQueue.size())
        {
            inputInGameWorkQueue.push_back(mapKeyInput(inputKeyWorkQueue[x], uInput[0]));
            x++;                            
        }*/
        for (size_t x=0;x<uInput.size();++x)  // loop through all user input queues
        {
            for (IKWQIIT = inputKeyWorkQueue.begin(); IKWQIIT != inputKeyWorkQueue.end(); ++IKWQIIT)  // loop through key input queue
            {
                // FIXME! uInput shoulnobe hard coded
                if (mapKeyInput(*IKWQIIT, uInput[x]) != INNO)  // verifies that input has been received
                {
//                    exit(0);                
                    inputInGameWorkQueue.push_back(mapKeyInput(*IKWQIIT, uInput[x]));  // compares each input key against current user input mapping              
                                                                                       // an adds to inputInGameWorkQueue if there's a match
                }       
            }
            ++x;
        }

    }
    
//        exit(0);
    logMsg(func + " end");
//    exit(0);
    return (true);
}
