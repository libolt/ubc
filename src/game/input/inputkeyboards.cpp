/***************************************************************************
 *   Copyright (C) 1999 - 2018 by Mike McLean                              *
 *   libolt@libolt.net                                                     *
 *    v                                                                     *
 *   This program is free software; you can redistribute it and/or modify  *
 *   i?t under the terms of the GNU General Public License as published by  *
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
 
#include "input/inputkeyboards.h"
#include "input/input.h"
#include "users/usersinputs.h"
#include "utilities/logging.h"
#include "utilities/conversion.h"
#include "utilities/typedefs.h"

inputKeyboards::inputKeyboards()  // constructor
{   
    setupComplete = false;
}
inputKeyboards::~inputKeyboards() = default;  // destructor

inputSharedPtr inputKeyboards::getInputInstance() const  // retrieves the value of inputS
{
    return (inputS);
}
void inputKeyboards::setInputInstance(const inputSharedPtr &set)  // sets the value of inputS
{
    inputS = set;
}

bool inputKeyboards::getSetupComplete() const  // retrieves the value of setupComplete
{
    return (setupComplete);
}
void inputKeyboards::setSetupComplete(const bool &set)  // sets the value of setupComplete
{
    setupComplete = set;
}

inputInGameMaps inputKeyboards::mapInput(inputKeyMaps inKeyMap, const usersInputsSharedPtr &uInput)  // maps value of the keyPressed string to inputInGameMaps
{
    conversionSharedPtr convert ;
    size_t x = 0;
    inputInGameMaps retVal;
    std::string func = "inputKeyboards::mapInput()";
    logMsg(func + " begin");
    logMsg(func + " userInput name == " +uInput->getName());
//    exit(0);
    logMsg(func + " mapKeyInput");
    logMsg(func + " inKeyMap = " +convert->toString(inKeyMap));
    logMsg(func +" inKeyMap keyQuit = " +convert->toString(uInput->getKeyQuit()));

    if (inKeyMap == uInput->getKeyUp())
    {
        retVal = INUP;
    }
    else if (inKeyMap == uInput->getKeyDown())
    {
        retVal = INDOWN;
    }
    else if (inKeyMap == uInput->getKeyLeft())
    {
        retVal = INLEFT;
    }
    else if (inKeyMap == uInput->getKeyRight())
    {
        retVal = INRIGHT;
    }
    else if (inKeyMap == uInput->getKeyUpLeft())
    {
        retVal = INUPLEFT;
    }
    else if (inKeyMap == uInput->getKeyUpRight())
    {
        retVal = INUPRIGHT;
    }
    else if (inKeyMap == uInput->getKeyDownLeft())
    {
        retVal = INDOWNLEFT;
    }
    else if (inKeyMap == uInput->getKeyDownRight())
    {
        retVal = INDOWNRIGHT;
    }
    else if (inKeyMap == uInput->getKeyPassSteal())
    {
        retVal = INPASSSTEAL;
    }
    else if (inKeyMap == uInput->getKeyShootBlock())
    {
        retVal = INSHOOTBLOCK;
    }
    else if (inKeyMap == uInput->getKeyPause())
    {
        retVal = INPAUSE;
    }
    else if (inKeyMap == uInput->getKeyStartSelect())
    {
        retVal = INSTARTSELECT;
    }
    else if (inKeyMap == uInput->getKeyQuit())
    {
        logMsg(func +" keyQuit = " +convert->toString(uInput->getKeyQuit()));
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

bool inputKeyboards::process()  // processes input
{
    conversionSharedPtr convert ;
    inputEngineSharedPtr inputE = inputS->getInputE();
    usersInputsVecSharedPtr uInput = inputS->getUInput();
    std::string func = "inputGamePads::process()";
    usersInputsVecSharedPtr::iterator UIIT;
    logMsg(func + " begin");
//    exit(0);
    
    if (inputE->processInput())
    {
//        int x = 0;
        inputTypeQueues inputTypeQueue = inputE->getInputTypeQueue();
        inputKeyWorkQueues inputKeyWorkQueue = inputE->getInputKeyWorkQueue();
        inputKeyWorkQueues::iterator IKWQIIT;
        inputInGameWorkQueues inputInGameWorkQueue = inputS->getInputInGameWorkQueue();

        logMsg(func + " uInput.size == " +convert->toString(uInput.size()));
//        exit(0);
/*        while (x < inputKeyWorkQueue.size())
        {
            inputInGameWorkQueue.push_back(mapKeyInput(inputKeyWorkQueue[x], uInput[0]));
            x++;                            
        }*/
        for (UIIT = uInput.begin(); UIIT != uInput.end(); ++UIIT)  // loop through all user input queues
        {
            for (IKWQIIT = inputKeyWorkQueue.begin(); IKWQIIT != inputKeyWorkQueue.end(); ++IKWQIIT)  // loop through key input queue
            {
                // FIXME! uInput shoulnobe hard coded
                if (mapInput(*IKWQIIT, *UIIT) != INNO)  // verifies that input has been received
                {
//                    exit(0);                
                    inputInGameWorkQueue.push_back(mapInput(*IKWQIIT, *UIIT));  // compares each input key against current user input mapping              
                                                                                    // an adds to inputInGameWorkQueue if there's a match
                }       
            }

        }
        inputS->setInputInGameWorkQueue(inputInGameWorkQueue);

    }
    
//        exit(0);
    logMsg(func + " end");
//    exit(0);
    return (true);
}

bool inputKeyboards::setup()  // sets up the inputGamePads object
{
/*    if (!inputS->getSetupComplete())
    {
        if (inputS->setup())
        {
            inputS->setSetupComplete(true);
        }
        else
        {

        }
    }
    else
    {

    }
*/
    return (true);
}
