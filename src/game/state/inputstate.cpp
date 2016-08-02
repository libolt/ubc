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
    boost::shared_ptr<conversion> convert = conversion::Instance();

    if (inputE->processInput())
    {
//        exit(0);
        if (inputE->getInputProcessed())
        {
            logMsg("Input Processed");
            exit(0);
            if (getGameE()->getMenuActive())
            {
                logMsg("Input Processed menuActive");
//                exit(0);
                logMsg("menuReceiveKeyPress == " +convert->toString(getGameE()->getInputE()->getKeyPressed()));
//                exit(0);
//                getInputS()->setGameE(getGameE());
//                exit(0);
//                getGameE()->getInputE()->setKeyPressed(INKEY_M);
//                exit(0);
///                getInputS()->process();
//                 getIunputS()->getInputE()->setKeyPressed(INKEY_P);
                logMsg("menuReceiveKeyPressAgain == " +convert->toString(getGameE()->getInputE()->getKeyPressed()));
//                exit(0);
///                gui->menuReceiveKeyPress(convert->toString(getGameE()->getInputE()->getKeyPressed())); // sends input to menu key input processing function
//                exit(0);
                if (getGameE()->getInputE()->getKeyPressed() == INKEY_T)
                {
//                    exit(0);
                }
                getGameE()->getInputE()->setKeyPressed(INKEY_NONE);
            }
        }
        if (getGameS()->getActiveTeamInstancesCreated())
        {
//            exit(0);
            size_t inputIterator = 0;
            while (inputIterator < activeTeamInstance.size())
            {
                if (activeTeamInstance[inputIterator]->getPlayerInstancesCreated())
                {
                    std::vector<boost::shared_ptr<playerState> > activePlayerInstance = activeTeamInstance[inputIterator]->getActivePlayerInstance();
                    if (activeTeamInstance[inputIterator]->getHumanControlled())
                    {
                        int humanPlayer = activeTeamInstance[inputIterator]->getHumanPlayer();
                        logMsg("inputHumanPlayer == " +convert->toString(humanPlayer));
                        //inputMaps inputMap = input->keyMap();
                        inputWorkQueues inputQueue = getGameE()->getInputE()->getInputWorkQueue();
        //                              logMsg("INPUT MAP ======== "  +toString(inputMap));
                        std::stringstream ss;
//                      exit(0);
                        size_t x = 0;
                        size_t humanInstance = 11;
                        while (x < activePlayerInstance.size())
                        {
                            logMsg("GEPlayerID == " +convert->toString(activePlayerInstance[x]->getID()));
                            logMsg("GEHumanPlayer == " +convert->toString(humanPlayer));

                            if (activePlayerInstance[x]->getID() == humanPlayer)
                            {
                                humanInstance = x;
                                break;
                            }
                            ++x;
                        }
                        logMsg("humanInstance == " +convert->toString(humanInstance));
                        logMsg("inputHumanPlayer == " +convert->toString(humanPlayer));
                        logMsg("inputQueue.size = " +convert->toString(inputQueue.size()));
                        x = 0;
                        int activeBBallInstance = getGameS()->getActiveBBallInstance();
                        std::vector<basketballState> bballInstance = getGameS()->getBasketballInstance();
                        logMsg("humanInstance.size() == " +convert->toString(humanInstance));
                        if (humanInstance < 11) // makes sure that the humanInstance is a valid number
                        {
                            while (x < inputQueue.size())
                            {
                                logMsg("inputQueue[" +convert->toString(x) +"] = " +convert->toString(inputQueue[x]));
                                // switch (inputMap)
                                switch (inputQueue[x])
                                {
                                    case INUP:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(UP);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        getGameS()->setActiveTeamInstance(activeTeamInstance);
//                                        exit(0);
                                    break;
                                    case INDOWN:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(DOWN);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INLEFT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(LEFT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INRIGHT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(RIGHT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INUPLEFT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(UPLEFT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INUPRIGHT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(UPRIGHT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INDOWNLEFT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(DOWNLEFT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INDOWNRIGHT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(DOWNRIGHT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INSHOOTBLOCK:
                                        activePlayerInstance[humanInstance]->setMovement(false);
                                        activePlayerInstance[humanInstance]->setShootBlock(true);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INPASSSTEAL:
                                        activePlayerInstance[humanInstance]->setMovement(false);
                                        activePlayerInstance[humanInstance]->setPassSteal(true);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        getGameS()->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INQUIT:
                                        logMsg("Quitting!");
                                        getGameE()->setQuitGame(true);
                                        exit(0);
                                    break;
                                    default:
                                    break;
                                }
                                ++x;
                            }
                        }
                        std::vector<boost::shared_ptr<teamState> > tInstance = getGameS()->getActiveTeamInstance();
                        std::vector<boost::shared_ptr<playerState> > activePInstance = tInstance[inputIterator]->getActivePlayerInstance();
                        logMsg("humanInstance == " +convert->toString(humanInstance));
                        //logMsg("inPassSteal == " +convert->toString(activePInstance[humanInstance]->getPassSteal()));
                        //exit(0);

                        /// FIXME! This if statement should be adapted to work correctly instead of relying on the i variable
                        int i = 0;
                        if (getGameS()->getTeamWithBall() == i)
                        {
                            if (activePlayerInstance[humanInstance]->getMovement())
                            {
                                logMsg("human playerID == " +convert->toString(activePlayerInstance[humanInstance]->getID()));
                                logMsg("ball player == " +convert->toString(activeTeamInstance[inputIterator]->getPlayerWithBallInstance()));
                                logMsg("ball playerID == " +convert->toString(activeTeamInstance[inputIterator]->getPlayerWithBallID()));
                                if (activePlayerInstance[humanInstance]->getID() == activeTeamInstance[inputIterator]->getPlayerWithBallID())
                                {
                                    bballInstance[activeBBallInstance].setMovement(true);
                                    getGameS()->setBasketballInstance(bballInstance);
                                }
                            }
                        }
                        if (getGameS()->getBasketballInstance().size() > 0)
                        {
                            logMsg("basketballmoved == " +convert->toString(bballInstance[activeBBallInstance].getMovement()));
                        }
                        getGameS()->setActiveTeamInstance(activeTeamInstance);

                        if (getGameS()->getGameType() == MULTI)
                        {
                            getNetworkS()->processLocalInput(getGameS()->getActiveTeamInstance());
                        }
                        inputQueue.clear();
                        getGameE()->getInputE()->setInputWorkQueue(inputQueue);
                    }
                    ++inputIterator;
                }
            }
        }

    }   
    return (true);
}
