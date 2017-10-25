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
 
#include "input/inputgamepads.h"
#include "users/usersinputs.h"
#include "logging.h"
#include "conversion.h"
#include "typedefs.h"

inputGamePads::inputGamePads()  // constructor
{   

}
inputGamePads::~inputGamePads()  // destructor
{
    
}

inputInGameMaps inputGamePads::mapInput(inputGamePadMaps inGamePadMap, usersInputsSharedPtr uInput)  // maps value of the gamePad string to inputInGameMaps
{
    sharedPtr<conversion> convert = conversion::Instance();
    size_t x = 0;
    std::string func = "inputGamePads::mapInput()";
//    while (x < uInput.size())
//    {
//    exit(0);
    logMsg(func + " begin");
    logMsg(func + " userInput name == " +uInput->getName());
//    exit(0);
    logMsg(func + " mapGamePadInput");
    logMsg(func + " inGamePadMap = " +convert->toString(inGamePadMap));
    logMsg(func +" inGamePadMap ButtonQuit = " +convert->toString(uInput->getGPQuit()));

    if (inGamePadMap == uInput->getGPUp())
    {
        return(INUP);
    }
    else if (inGamePadMap == uInput->getGPDown())
    {
        return(INDOWN);
    }
    else if (inGamePadMap == uInput->getGPLeft())
    {
        return(INLEFT);
    }
    else if (inGamePadMap == uInput->getGPRight())
    {
        return(INRIGHT);
    }
    else if (inGamePadMap == uInput->getGPUpLeft())
    {
        return(INUPLEFT);
    }
    else if (inGamePadMap == uInput->getGPUpRight())
    {
        return(INUPRIGHT);
    }
    else if (inGamePadMap == uInput->getGPDownLeft())
    {
        return(INDOWNLEFT);
    }
    else if (inGamePadMap == uInput->getGPDownRight())
    {
        return(INDOWNRIGHT);
    }
    else if (inGamePadMap == uInput->getGPPassSteal())
    {
        return(INPASSSTEAL);
    }
    else if (inGamePadMap == uInput->getGPShootBlock())
    {
        return(INSHOOTBLOCK);
    }
    else if (inGamePadMap == uInput->getGPPause())
    {
        return(INPAUSE);
    }
    else if (inGamePadMap == uInput->getGPStartSelect())
    {
        return(INSTARTSELECT);
    }
    else if (inGamePadMap == uInput->getGPQuit())
    {
        logMsg(func +" GPQuit = " +convert->toString(uInput->getGPQuit()));
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

bool inputGamePads::process()  // processes input
{
    sharedPtr<conversion> convert = conversion::Instance();
    inputEngineSharedPtr inputE = getInputE(); 
    usersInputsVecSharedPtr uInput = getUInput();
    std::string func = "inputGamePads::process()";
    
    logMsg(func + " begin");
//    exit(0);
    
    if (inputE->processInput())
    {
//        int x = 0;
        inputTypeQueues inputTypeQueue = inputE->getInputTypeQueue();
        inputGamePadWorkQueues inputGamePadWorkQueue = inputE->getInputGamePadWorkQueue();
        inputGamePadWorkQueues::iterator IGPWQIIT;
        inputInGameWorkQueues inputInGameWorkQueue = inputE->getInputInGameWorkQueue();
        
        logMsg(func + " uInput.size == " +convert->toString(uInput.size()));
//        exit(0);
/*        while (x < inputKeyWorkQueue.size())
        {
            inputInGameWorkQueue.push_back(mapKeyInput(inputKeyWorkQueue[x], uInput[0]));
            x++;                            
        }*/
        for (size_t x=0;x<uInput.size();++x)  // loop through all user input queues
        {
            for (IGPWQIIT = inputGamePadWorkQueue.begin(); IGPWQIIT != inputGamePadWorkQueue.end(); ++IGPWQIIT)  // loop through key input queue
            {
                // FIXME! uInput shoulnobe hard coded
                if (mapInput(*IGPWQIIT, uInput[x]) != INNO)  // verifies that input has been received
                {
//                    exit(0);                
                    inputInGameWorkQueue.push_back(mapInput(*IGPWQIIT, uInput[x]));  // compares each input key against current user input mapping              
                                                                                    // an adds to inputInGameWorkQueue if there's a match
                }       
            }
            ++x;
        }
        inputE->setInputInGameWorkQueue(inputInGameWorkQueue);
    }
    
//        exit(0);
    logMsg(func + " end");
//    exit(0);
    return (true);
}
