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
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
 
#include "state/inputstate.h"
#include "logging.h"
#include "engine/inputengine.h"
//#include "engine/gameengine.h"
#include "userinput.h"
#include "load.h"

// static declarations
boost::shared_ptr<inputEngine> inputState::inputE;  // the inputEngine object
inputInGameWorkQueues inputState::inputInGameWorkQueue; 


inputState::inputState()  // constructor
{
    boost::shared_ptr<loader> load = loader::Instance();

    boost::shared_ptr<inputEngine> tempInputSharedPtr(new inputEngine);
    inputE = tempInputSharedPtr;
    uInput = load->loadUserInputs();  // loads user defined input from file.
    
    uInput[0].setActive(true);

}
inputState::~inputState()  // destructor
{
    
}

boost::shared_ptr<inputEngine> inputState::getInputE()  // retrieves the value of inputE
{
    return (inputE);
}
void inputState::setInputE(boost::shared_ptr<inputEngine> set)  // sets the value of inputE
{
//    inputE = set;
}

std::vector<userInput> inputState::getUInput()  // retrieves the value of uInput
{
    return (uInput);
}
void inputState::setUInput(std::vector<userInput> set)  // sets the value of uInput
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

bool inputState::mapInput()  // maps value of keyPressed string to inputMap
{
    
    boost::shared_ptr<conversion> convert = conversion::Instance();

//    exit(0);
    
    if (inputE->getKeyInputReceived())
    {
        int x = 0;
        inputKeyWorkQueues inputKeyWorkQueue = inputE->getInputKeyWorkQueue();
        logMsg("inputKeyWorkQueue.size() = " +convert->toString(inputKeyWorkQueue.size()));
        while (x < inputKeyWorkQueue.size())
        {
            inputInGameWorkQueue.push_back(mapKeyInput(inputKeyWorkQueue[x]));
            ++x;
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

inputInGameMaps inputState::mapKeyInput(inputKeyMaps inKeyMap)  // maps value of the keyPressed string to inputInGameMaps
{
    int x = 0;
//    while (x < uInput.size())
//    {
    logMsg("mapKeyInput");
    if (inKeyMap == uInput[0].getKeyUp())
    {
//        exit(0);
        return(INUP);
    }
    exit(0);
/*    
    else if (inKeyMap == uInput[0].getKeyDown())
    {
        return(INDOWN);
    }
    else if (inKeyMap == uInput[0].getKeyLeft())
    {
        return(INLEFT);
    }
    else if (inKeyMap == uInput[0].getKeyRight())
    {
        return(INRIGHT);
    }
    else if (inKeyMap == uInput[0].getKeyUpLeft())
    {
        return(INUPLEFT);
    }
    else if (inKeyMap == uInput[0].getKeyUpRight())
    {
        return(INUPRIGHT);
    }
    else if (inKeyMap == uInput[0].getKeyDownLeft())
    {
        return(INDOWNLEFT);
    }
    else if (inKeyMap == uInput[0].getKeyDownRight())
    {
        return(INDOWNRIGHT);
    }
    else if (inKeyMap == uInput[0].getKeyPassSteal())
    {
        return(INPASSSTEAL);
    }
    else if (inKeyMap == uInput[0].getKeyShootBlock())
    {
        return(INSHOOTBLOCK);
    }
    else if (inKeyMap == uInput[0].getKeyPause())
    {
        return(INPAUSE);
    }
    else if (inKeyMap == uInput[0].getKeyStartSelect())
    {
        return(INSTARTSELECT);
    }
    else if (inKeyMap == uInput[0].getKeyQuit())
    {
        logMsg("keyQuit = " +uInput[0].getKeyQuit());
    return(INQUIT);
    }
    else
    {
        return(INNO);
    }*/
    exit(0);
}

bool inputState::process()  // processes input
{
    boost::shared_ptr<conversion> convert = conversion::Instance();

    if (inputE->processInput())
    {
        int x = 0;
        inputTypeQueues inputTypeQueue = inputE->getInputTypeQueue();
        inputKeyWorkQueues inputKeyWorkQueue = inputE->getInputKeyWorkQueue();
        while (x < inputKeyWorkQueue.size())
        {
            inputInGameWorkQueue.push_back(mapKeyInput(inputKeyWorkQueue[x]));
            x++;                            
        }
    }
//        exit(0);

    return (true);
}
