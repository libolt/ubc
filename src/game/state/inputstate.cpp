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
inputState::inputState()  // constructor
{
    boost::shared_ptr<loader> load = loader::Instance();

    uInput = load->loadUserInputs();  // loads user defined input from file.
    
    uInput[0].setActive(true);

}
inputState::~inputState()  // destructor
{
    
}

boost::shared_ptr<inputEngine> inputState::inputE;  // the inputEngine object

boost::shared_ptr<inputEngine> inputState::getInputE()  // retrieves the value of inputE
{
    return (inputE);
}
void inputState::setInputE(boost::shared_ptr<inputEngine> set)  // sets the value of inputE
{
    inputE = set;
}

std::vector<userInput> inputState::getUInput()  // retrieves the value of uInput
{
    return (uInput);
}
void inputState::setUInput(std::vector<userInput> set)  // sets the value of uInput
{
    uInput = set;
}

inputMaps inputState::keyMap()  // maps value of keyPressed string to inputMap
{
//    exit(0);
    if (inputE->getKeyPressed() == uInput[0].getKeyUp())
    {
//        exit(0);
        return(INUP);
    }
    else if (inputE->getKeyPressed() == uInput[0].getKeyDown())
    {
        return(INDOWN);
    }
    else if (inputE->getKeyPressed() == uInput[0].getKeyLeft())
    {
        return(INLEFT);
    }
    else if (inputE->getKeyPressed() == uInput[0].getKeyRight())
    {
        return(INRIGHT);
    }
    else if (inputE->getKeyPressed() == uInput[0].getKeyUpLeft())
    {
        return(INUPLEFT);
    }
    else if (inputE->getKeyPressed() == uInput[0].getKeyUpRight())
    {
        return(INUPRIGHT);
    }
    else if (inputE->getKeyPressed() == uInput[0].getKeyDownLeft())
    {
        return(INDOWNLEFT);
    }
    else if (inputE->getKeyPressed() == uInput[0].getKeyDownRight())
    {
        return(INDOWNRIGHT);
    }
    else if (inputE->getKeyPressed() == uInput[0].getKeyPassSteal())
    {
        return(INPASSSTEAL);
    }
    else if (inputE->getKeyPressed() == uInput[0].getKeyShootBlock())
    {
        return(INSHOOTBLOCK);
    }
    else if (inputE->getKeyPressed() == uInput[0].getKeyPause())
    {
        return(INPAUSE);
    }
    else if (inputE->getKeyPressed() == uInput[0].getKeyStartSelect())
    {
        return(INSTARTSELECT);
    }
    else if (inputE->getKeyPressed() == uInput[0].getKeyQuit())
    {
        logMsg("keyQuit = " +uInput[0].getKeyQuit());
    return(INQUIT);
    }
    else if (inputE->getKeyPressed() == INKEY_BACKSPACE)
    {
//        logMsg("keyQuit = " +uInput[0].getKeyQuit());
//        exit(0);
        return(INBACKSPACE);
    }
    else
    {
        return(INNO);
    }
}

bool inputState::process()  // processes input
{
    logMsg("inputState->process menuReceiveKeyPress == " +inputE->getKeyPressed());
//    exit(0);
    return (true);
}
