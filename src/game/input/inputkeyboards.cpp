/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
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
#include "users/usersinputs.h"
#include "logging.h"
#include "conversion.h"
#include "typedefs.h"

inputKeyboards::inputKeyboards()  // constructor
{   

}
inputKeyboards::~inputKeyboards()  // destructor
{
    
}

inputKeyboards mapInput(inputKeyMaps inKeyMap, usersInputsSharedPtr uInput)  // maps value of the keyPressed string to inputInGameMaps
{
    sharedPtr<conversion> convert = conversion::Instance();
    size_t x = 0;
    std::string func = "inputKeyboards::mapInput()";
//    while (x < uInput.size())
//    {
//    exit(0);
    logMsg(func + " begin");
    logMsg(func + " userInput name == " +uInput->getName());
//    exit(0);
    logMsg(func + " mapKeyInput");
    logMsg(func + " inKeyMap = " +convert->toString(inKeyMap));
    logMsg(func +" inKeyMap keyQuit = " +convert->toString(uInput->getKeyQuit()));

    if (inKeyMap == uInput->getKeyUp())
    {
        return(INUP);
    }
    else if (inKeyMap == uInput->getKeyDown())
    {
        return(INDOWN);
    }
    else if (inKeyMap == uInput->getKeyLeft())
    {
        return(INLEFT);
    }
    else if (inKeyMap == uInput->getKeyRight())
    {
        return(INRIGHT);
    }
    else if (inKeyMap == uInput->getKeyUpLeft())
    {
        return(INUPLEFT);
    }
    else if (inKeyMap == uInput->getKeyUpRight())
    {
        return(INUPRIGHT);
    }
    else if (inKeyMap == uInput->getKeyDownLeft())
    {
        return(INDOWNLEFT);
    }
    else if (inKeyMap == uInput->getKeyDownRight())
    {
        return(INDOWNRIGHT);
    }
    else if (inKeyMap == uInput->getKeyPassSteal())
    {
        return(INPASSSTEAL);
    }
    else if (inKeyMap == uInput->getKeyShootBlock())
    {
        return(INSHOOTBLOCK);
    }
    else if (inKeyMap == uInput->getKeyPause())
    {
        return(INPAUSE);
    }
    else if (inKeyMap == uInput->getKeyStartSelect())
    {
        return(INSTARTSELECT);
    }
    else if (inKeyMap == uInput->getKeyQuit())
    {
        logMsg(func +" keyQuit = " +convert->toString(uInput->getKeyQuit()));
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

bool inputKeyboards::process()  // processes input
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
        inputKeyWorkQueues inputKeyWorkQueue = inputE->getInputKeyWorkQueue();
        inputKeyWorkQueues::iterator IKWQIIT;
        inputInGameWorkQueues inputInGameWorkQueue = getInputInGameWorkQueue();

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
                if (mapInput(*IKWQIIT, uInput[x]) != INNO)  // verifies that input has been received
                {
//                    exit(0);                
                    inputInGameWorkQueue.push_back(mapInput(*IKWQIIT, uInput[x]));  // compares each input key against current user input mapping              
                                                                                    // an adds to inputInGameWorkQueue if there's a match
                }       
            }
            ++x;
        }
        setInputInGameWorkQueue(inputInGameWorkQueue);

    }
    
//        exit(0);
    logMsg(func + " end");
//    exit(0);
    return (true);
}
