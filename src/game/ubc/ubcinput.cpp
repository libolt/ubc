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
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "ubc/ubc.h"
#include "ubc/ubcinput.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"
#include "utilities/typedefs.h"
#include "state/gamestate.h"
#include "state/teamstate.h"
#include "network/networkplayerstateobject.h"
#include "users/users.h"
#include "input/inputgamepads.h"
#include "input/inputkeyboards.h"
#include "input/input.h"
#include "engine/gameengine.h"

// static declarations
inputSharedPtr UBCInput::inputInstance;  // the input object
inputKeyboardsSharedPtr UBCInput::inputKeyboard;  // the inputKeyboards object
inputGamePadsSharedPtr UBCInput::inputGamePad;  // the inputGamePads object
bool UBCInput::setupComplete;  // stores whether setup has completed successfully


UBCInput::UBCInput()  // constructor
{
    setupComplete = false;
}
UBCInput::~UBCInput()  // destructor
{
    
}

inputSharedPtr UBCInput::getInputInstance()  // retrieves the value of inputS
{
    return (inputInstance);
}
void UBCInput::setInputInstance(inputSharedPtr set)  // sets the value of inputS
{
    inputInstance = set;
}

inputGamePadsSharedPtr UBCInput::getInputGamePad()  // retrieves the value of inputGamePad
{
    return (inputGamePad);
}
void UBCInput::setInputGamePad(inputGamePadsSharedPtr set)  // sets the value of inputGamePad
{
    inputGamePad = set;
}

inputKeyboardsSharedPtr UBCInput::getInputKeyboard()  // retrieves the value of inputKeyboard
{
    return (inputKeyboard);
}
void UBCInput::setInputKeyboard(inputKeyboardsSharedPtr set)  // sets the value of inputKeyboard
{
    inputKeyboard = set;
}

bool UBCInput::getSetupComplete()  // retrieves the value of setupComplete
{
    return (setupComplete);
}
void UBCInput::setSetupComplete(bool set)  // sets the value of setupComplete
{
    setupComplete = set;
}

void UBCInput::process(gameEngineSharedPtr gameE, gameStateSharedPtr gameInstance, usersMSharedPtr usersInstance, GUISystemSharedPtr gui)  // processes game input
{
    conversionSharedPtr convert = conversion::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
//    sharedPtr<GUISystem> gui = GUISystem::Instance();
//    sharedPtr<inputSystem> input = inputSystem::Instance();
//    networkEngineSharedPtr network = networkEngine::Instance();
    teamStateMSharedPtr activeTeamInstance = gameInstance->getActiveTeamInstance();
    networkPlayerStateObject netPStateObj;
    std::string func = "UBCInput::process()";

    logMsg(func +" begin");

    logMsg(func +" userInstance.size() == " +convert->toString(usersInstance.size()));
    logMsg(func +" user 0 inputType == " +convert->toString(usersInstance[0]->getInputType()));
//    exit(0);
    usersMSharedPtr uInstance = usersInstance;
    for (auto UIIT : uInstance)
    {
        inputTypes inType = UIIT.second->getInputType();       
        switch (inType)
        {
            case KEYBOARD:
                logMsg(func +" Keyboard Input!");
                processKeyboard(gameE, gameInstance, gui);
            break;
            case GAMEPAD:
                logMsg(func +" GamePad Input!");
                processGamePad();
            break;
            case MOUSE:
                logMsg(func +" Mouse Input!");
                processMouse();
            break;
            case TOUCH:
                logMsg(func +" Touch Input!");
                processTouch();
            break;
        }
    }
//    exit(0);
        
/*    if (base->getInputS()->process())
    {

        if (gameE->getMenuActive())
        {
            gui->menuReceiveKeyPress(convert->toString(gameE->getInputE()->getKeyPressed())); // sends input to menu key input processing function
//            exit(0);
        }
        else
        {
//            exit(0);
            gameInstance->setInputReceived(true);

            gameInstance->setInputInGameWorkQueue(base->getInputS()->getInputInGameWorkQueue());

        }
        gameE->getInputE()->setKeyPressed(INKEY_NONE);
    }
    else
    {

    }
*/
    logMsg("INQ Size = " +convert->toString(gameInstance->getInputInGameWorkQueue().size()));
    for (auto IIGWQ : gameInstance->getInputInGameWorkQueue())
    {
        logMsg ("INQ = " +convert->toString(IIGWQ));
    }

//    exit(0);
/*    if (gameE->getInputE()->processInput())
    {
        if (gameE->getInputE()->getInputProcessed())
        {
            logMsg("Input Processed");
//            exit(0);
            if (gameE->getMenuActive())
            {
                logMsg("Input Processed menuActive");
//                exit(0);
                logMsg("menuReceiveKeyPress == " +convert->toString(gameE->getInputE()->getKeyPressed()));
//                exit(0);
//                getInputS()->setGameE(gameE);
//                exit(0);
//                gameE->getInputE()->setKeyPressed(INKEY_M);
//                exit(0);
                getInputS()->process();
//                 getInputS()->getInputE()->setKeyPressed(INKEY_P);
                logMsg("menuReceiveKeyPressAgain == " +convert->toString(gameE->getInputE()->getKeyPressed()));
//                exit(0);
                gui->menuReceiveKeyPress(convert->toString(gameE->getInputE()->getKeyPressed())); // sends input to menu key input processing function
//                exit(0);
                if (gameE->getInputE()->getKeyPressed() == INKEY_T)
                {
//                    exit(0);
                }
                gameE->getInputE()->setKeyPressed(INKEY_NONE);
            }
        }
        if (gameInstance->getActiveTeamInstancesCreated())
        {
//            exit(0);
            size_t inputIterator = 0;
            while (inputIterator < activeTeamInstance.size())
            {
                if (activeTeamInstance[inputIterator]->getPlayerInstancesCreated())
                {
                    playerStateVecSharedPtr activePlayerInstance = activeTeamInstance[inputIterator]->getActivePlayerInstance();
                    if (activeTeamInstance[inputIterator]->getHumanControlled())
                    {
                        int humanPlayer = activeTeamInstance[inputIterator]->getHumanPlayer();
                        logMsg("inputHumanPlayer == " +convert->toString(humanPlayer));
                        //inputMaps inputMap = input->keyMap();
                        inputWorkQueues inputQueue = gameE->getInputE()->getInputWorkQueue();
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
                        int activeBBallInstance = gameInstance->getActiveBBallInstance();
                        basketballStateVec bballInstance = gameInstance->getBasketballInstance();
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
                                        gameInstance->setActiveTeamInstance(activeTeamInstance);
//                                        exit(0);
                                    break;
                                    case INDOWN:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(DOWN);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        gameInstance->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INLEFT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(LEFT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        gameInstance->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INRIGHT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(RIGHT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        gameInstance->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INUPLEFT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(UPLEFT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        gameInstance->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INUPRIGHT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(UPRIGHT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        gameInstance->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INDOWNLEFT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(DOWNLEFT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        gameInstance->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INDOWNRIGHT:
                                        activePlayerInstance[humanInstance]->setMovement(true);
                                        activePlayerInstance[humanInstance]->setDirection(DOWNRIGHT);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        gameInstance->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INSHOOTBLOCK:
                                        activePlayerInstance[humanInstance]->setMovement(false);
                                        activePlayerInstance[humanInstance]->setShootBlock(true);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        gameInstance->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INPASSSTEAL:
                                        activePlayerInstance[humanInstance]->setMovement(false);
                                        activePlayerInstance[humanInstance]->setPassSteal(true);
                                        activeTeamInstance[inputIterator]->setActivePlayerInstance(activePlayerInstance);
                                        gameInstance->setActiveTeamInstance(activeTeamInstance);
                                    break;
                                    case INQUIT:
                                        logMsg("Quitting!");
                                        gameE->setQuitGame(true);
                                        exit(0);
                                    break;
                                    default:
                                    break;
                                }
                                ++x;
                            }
                        }
                        teamStateVecSharedPtr tInstance = gameInstance->getActiveTeamInstance();
                        playerStateVecSharedPtr activePInstance = tInstance[inputIterator]->getActivePlayerInstance();
                        logMsg("humanInstance == " +convert->toString(humanInstance));
                        //logMsg("inPassSteal == " +convert->toString(activePInstance[humanInstance]->getPassSteal()));
                        //exit(0);

                        /// FIXME! This if statement should be adapted to work correctly instead of relying on the i variable
                        int i = 0;
                        if (gameInstance->getTeamWithBall() == i)
                        {
                            if (activePlayerInstance[humanInstance]->getMovement())
                            {
                                logMsg("human playerID == " +convert->toString(activePlayerInstance[humanInstance]->getID()));
                                logMsg("ball player == " +convert->toString(activeTeamInstance[inputIterator]->getPlayerWithBallInstance()));
                                logMsg("ball playerID == " +convert->toString(activeTeamInstance[inputIterator]->getPlayerWithBallID()));
                                if (activePlayerInstance[humanInstance]->getID() == activeTeamInstance[inputIterator]->getPlayerWithBallID())
                                {
                                    bballInstance[activeBBallInstance].setMovement(true);
                                    gameInstance->setBasketballInstance(bballInstance);
                                }
                            }
                        }
                        if (gameInstance->getBasketballInstance().size() > 0)
                        {
                            logMsg("basketballmoved == " +convert->toString(bballInstance[activeBBallInstance].getMovement()));
                        }
                        gameInstance->setActiveTeamInstance(activeTeamInstance);

                        if (gameInstance->getGameType() == MULTI)
                        {
                            getNetworkS()->processLocalInput(gameInstance->getActiveTeamInstance());
                        }
                        inputQueue.clear();
                        gameE->getInputE()->setInputWorkQueue(inputQueue);
                    }
                    ++inputIterator;
                }
            }
        }

    }
*/
//    exit(0);
    logMsg(func +" end");

}

bool UBCInput::processKeyboard(gameEngineSharedPtr gameE, gameStateSharedPtr gameInstance, GUISystemSharedPtr gui)  // process keyboard input
{
    conversionSharedPtr convert;

    std::string func = "UBCInput::processKeyboard()";

    logMsg(func +" begin");

    if (inputKeyboard->process())
    {
        logMsg(func +" inputKeyboard->process()");

        if (gameE->getMenuActive())  // sends key input to the GUI system if menu is active
        {
            logMsg(func +" gameE->getMenuActive()");
            gui->menuReceiveKeyPress(convert->toString(gameE->getInputE()->getKeyPressed())); // sends input to menu key input processing function
            logMsg(func +" base->getGui");
            //            exit(0);
        }
        else
        {
//            exit(0);
            gameInstance->setInputReceived(true);

            gameInstance->setInputInGameWorkQueue(inputKeyboard->getInputInstance()->getInputInGameWorkQueue());

        }
        gameE->getInputE()->setKeyPressed(INKEY_NONE);
    }
    else
    {

    }
    logMsg(func +" end");
    return (true);
}

bool UBCInput::processGamePad()  // process gamePad input
{
    return (true);
}

bool UBCInput::processMouse()  // process mouse input
{
    return (true);
}

bool UBCInput::processTouch()  // process touch input
{
    return (true);
}

bool UBCInput::setup()  // sets up the UBCInput object
{
    std::string func = "UBCInput::setup()";

    logMsg(func +" begin");

//    exit(0);

    // instantiate the inputS Object
    inputSharedPtr tempInputInstance(new input);
    inputInstance = tempInputInstance;
    // instantiate the inputGamePad Object
    inputGamePadsSharedPtr tempInputGPSharedPtr(new inputGamePads);
    logMsg(func +" tempInputGPSharedPtr");

    inputGamePad = tempInputGPSharedPtr;
    logMsg(func +" inputGamePad");
    inputGamePad->setInputInstance(inputInstance);
    logMsg(func + " inputGamePad->setInputS(inputS)");

    if (inputGamePad->setup())
    {
        logMsg(func +" inputGamePad->setup()");
        inputGamePad->setSetupComplete(true);
    }
    else
    {

    }

    inputKeyboardsSharedPtr tempinputKBSharedPtr(new inputKeyboards);
    logMsg(func + " tempInputKBSharedPtr");

    inputKeyboard = tempinputKBSharedPtr;
    logMsg(func + " inputKeyboard");
    inputKeyboard->setInputInstance(inputInstance);

    logMsg(func + " inputKeyboard->setInputS(inputS)");

    if (inputKeyboard->setup())
    {
        logMsg(func + " inputKeyboard->setup()");

        inputKeyboard->setSetupComplete(true);
    }
    else
    {

    }



/*    inputSharedPtr tempInputStateSharedPtr(new input);
    inputS = tempInputStateSharedPtr;

    inputS->setInputE(gameE->getInputE());

    logMsg(func +" inputS->setup()");
    inputS->setup();  // sets up the inputState object

*/

    logMsg(func + " end");

    return (true);
}
