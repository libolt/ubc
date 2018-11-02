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
 
#include "input/inputgamepads.h"
#include "users/usersinputs.h"
#include "utilities/logging.h"
#include "utilities/conversion.h"
#include "utilities/typedefs.h"

inputGamePads::inputGamePads()  // constructor
{   
    setupComplete = false;
}
inputGamePads::~inputGamePads() = default;  // destructor

inputSharedPtr inputGamePads::getInputInstance() const  // retrieves the value of inputInstance
{
    return (inputInstance);
}
void inputGamePads::setInputInstance(const inputSharedPtr &set)  // sets the value of inputInstance
{
    inputInstance = set;
}

bool inputGamePads::getSetupComplete() const  // retrieves the value of setupComplete
{
    return (setupComplete);
}
void inputGamePads::setSetupComplete(const bool &set)  // sets the value of setupComplete
{
    setupComplete = set;
}

inputInGameMaps inputGamePads::mapInput(inputGamePadMaps inGamePadMap, const usersInputsSharedPtr &uInput)  // maps value of the gamePad string to inputInGameMaps
{
    conversionSharedPtr convert ;
    size_t x = 0;
    inputInGameMaps retVal;
    std::string func = "inputGamePads::mapInput()";

    logMsg(func + " begin");
    logMsg(func + " userInput name == " +uInput->getName());
//    exit(0);
    logMsg(func + " mapGamePadInput");
    logMsg(func + " inGamePadMap = " +convert->toString(inGamePadMap));
    logMsg(func +" inGamePadMap ButtonQuit = " +convert->toString(uInput->getGPQuit()));

    if (inGamePadMap == uInput->getGPUp())
    {
        retVal = INUP;
    }
    else if (inGamePadMap == uInput->getGPDown())
    {
        retVal = INDOWN;
    }
    else if (inGamePadMap == uInput->getGPLeft())
    {
        retVal = INLEFT;
    }
    else if (inGamePadMap == uInput->getGPRight())
    {
        retVal = INRIGHT;
    }
    else if (inGamePadMap == uInput->getGPUpLeft())
    {
        retVal = INUPLEFT;
    }
    else if (inGamePadMap == uInput->getGPUpRight())
    {
        retVal = INUPRIGHT;
    }
    else if (inGamePadMap == uInput->getGPDownLeft())
    {
        retVal = INDOWNLEFT;
    }
    else if (inGamePadMap == uInput->getGPDownRight())
    {
        retVal = INDOWNRIGHT;
    }
    else if (inGamePadMap == uInput->getGPPassSteal())
    {
        retVal = INPASSSTEAL;
    }
    else if (inGamePadMap == uInput->getGPShootBlock())
    {
        retVal = INSHOOTBLOCK;
    }
    else if (inGamePadMap == uInput->getGPPause())
    {
        retVal = INPAUSE;
    }
    else if (inGamePadMap == uInput->getGPStartSelect())
    {
        retVal = INSTARTSELECT;
    }
    else if (inGamePadMap == uInput->getGPQuit())
    {
        logMsg(func +" GPQuit = " +convert->toString(uInput->getGPQuit()));
//        exit(0);
        retVal = INQUIT;
    }
    else
    {
        retVal = INNO;
    }
//    exit(0);
    logMsg(func + " end");
    return (retVal);
}

bool inputGamePads::process()  // processes input
{
    conversionSharedPtr convert ;
    inputEngineSharedPtr inputE = getInputE(); 
    usersInputsVecSharedPtr uInput = getUInput();
    std::string func = "inputGamePads::process()";
    usersInputsVecSharedPtr::iterator UIIT;

    logMsg(func + " begin");
//    exit(0);
    
    if (inputE->processInput())
    {
//        int x = 0;
        inputTypeQueues inputTypeQueue = inputE->getInputTypeQueue();
        inputGamePadWorkQueues inputGamePadWorkQueue = inputE->getInputGamePadWorkQueue();
        inputGamePadWorkQueues::iterator IGPWQIIT;
        inputInGameWorkQueues inputInGameWorkQueue = getInputInGameWorkQueue();
        
        logMsg(func + " uInput.size == " +convert->toString(uInput.size()));
//        exit(0);
/*        while (x < inputKeyWorkQueue.size())
        {
            inputInGameWorkQueue.push_back(mapKeyInput(inputKeyWorkQueue[x], uInput[0]));
            x++;                            
        }*/
        for (UIIT = uInput.begin(); UIIT != uInput.end(); ++UIIT)  // loop through all user input queues
        {
            for (IGPWQIIT = inputGamePadWorkQueue.begin(); IGPWQIIT != inputGamePadWorkQueue.end(); ++IGPWQIIT)  // loop through key input queue
            {
                // FIXME! uInput shoulnobe hard coded
                if (mapInput(*IGPWQIIT, *UIIT) != INNO)  // verifies that input has been received
                {
//                    exit(0);                
                    inputInGameWorkQueue.push_back(mapInput(*IGPWQIIT, *UIIT));  // compares each input key against current user input mapping              
                                                                                    // an adds to inputInGameWorkQueue if there's a match
                }       
            }
            
        }
        setInputInGameWorkQueue(inputInGameWorkQueue);
    }
    
//        exit(0);
    logMsg(func + " end");
//    exit(0);
    return (true);
}

bool inputGamePads::setup()  // sets up the inputGamePads object
{
    std::string func = "inputGamePads::setup()";

    logMsg(func +" begin");

/*    if (!inputInstance->getSetupComplete())
    {
        logMsg(func +" !inputInstance->getSetupComplete()");
        if (inputInstance->setup(inputE))
        {
            inputInstance->setSetupComplete(true);
        }
        else
        {

        }
    }
    else
    {

    }
*/
    logMsg(func +" end");

    return (true);
}

