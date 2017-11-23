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

#include "ubc/ubcgame.h"
#include "engine/gameengine.h"
#include "ubc/ubcinput.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

// static declarations
bool UBCGame::startActiveGame;  // stores whether to begin an active game instance
bool UBCGame::userInstancesCreated;  // stores whether user instances have been created

UBCGame::UBCGame()  // constructor
{
//    quitGame = false;
    startActiveGame = false;
    userInstancesCreated = false;

}

UBCGame::~UBCGame()  // destructor
{

}

gameStateSharedPtr UBCGame::getGameS()  // retrieves the value of gameS
{
    return (gameS);
}
void UBCGame::setGameS(gameStateSharedPtr set)  // sets the value of gameS
{
    gameS = set;
}

bool UBCGame::getStartActiveGame()  // retrieves the value of startActiveGame
{
    return (startActiveGame);
}
void UBCGame::setStartActiveGame(bool set)  // sets the value of startActiveGame
{
    startActiveGame = set;
}

bool UBCGame::getUsersInstancesCreated()  // retrieves the value of userInstancesCreated
{
    return (userInstancesCreated);
}
void UBCGame::setUsersInstancesCreated(bool set)  // sets the value of userInstancesCreated
{
    userInstancesCreated = set;
}

bool UBCGame::setup()  // sets up a game instance
{
//    gameState *tempGameStateObj = new gameState;
    gameStateSharedPtr tempGameStateSharedPtr(new gameState);
    gameS = tempGameStateSharedPtr;
    logMsg(func +" getGameS()->setInitialized(true)");
    getGameS()->setInitialized(true);

    return (true);
}


bool UBCGame::loop(gameEngineSharedPtr gameE, UBCInputSharedPtr input)  // Main Game Loop
{
    conversionSharedPtr convert = conversion::Instance();
    bool quitGame = gameE->getQuitGame();
    unsigned long changeInTime = 0;
    unsigned long CITmic = 0;
    unsigned long CITmil = 0;
    std::string func = "UBC::gameLoop()";
    boost::chrono::microseconds changeInTimeMicro;
    boost::chrono::milliseconds changeInTimeMill;
/*    playerStateMachine playerSM;
    playerSMData *playerSMD = new playerSMData;
    playerSMData *playerSMD2 = new playerSMData;
    playerSMData *playerSMD3 = new playerSMData;
*/
    logMsg(func +" beginning");
    
///    playerSMD->speed = 100;
///    playerSM.setSpeed(playerSMD);
///    playerSM.halt();
///    logMsg(func +" dah");
///    playerSMD2->speed = 200;
///    playerSM.pJump(playerSMD2);
///    playerSMD3->direction = UP;
///    playerSM.pChangeDirection(playerSMD3);

    logMsg(func +" Wootio!");
//    exit(0);
    
    SDL_StartTextInput();
    
    while (!quitGame)
    {
        input->process(gameE);
//        processPhysicsEvents();
        
///        if (base->getGameS()->getGameSetupComplete())  // checks to make sure game setup is complete before continuing
///        {
            
///            if (!gameE->getSceneCreated())
///            {
///                logMsg(func +" Scene Not Created!");
//                exit(0);
///                if (base->getGameS()->getGameType() == SINGLE)
///                {
///                    logMsg(func +" getGameType() == SINGLE");
///                    gameE->setCreateScene(true);
///                    exit(0);
///                }
///                else if (base->getGameS()->getGameType() == MULTILOCAL)
///                {
///                    logMsg(func +" getGameType() == MULTILOCAL");
///                    gameE->setCreateScene(true);
//                    exit(0);
///                }
///                else if (base->getGameS()->getGameType() == MULTINET)
///                {
///                    logMsg(func +" getGameType() == MULTINET");
///
///                    if (gameE->getNetworkE()->getServerReceivedConnection() || gameE->getNetworkE()->getClientEstablishedConnection())  // checks if server and client are connected
///                    {
///                        gameE->setCreateScene(true);
///                    }
    //             exit(0);
///                }
///            }
///        }
        
       // exit(0);

        if (startActiveGame)
        {
            if (startGame())
            {
                gameE->setStart(false);
                gameE->setRenderScene(true);
                startActiveGame = false;
            }
            else
            {
                logMsg(func + " Unable to Start Active Game Instance!");
                exit(0);
            }
        }
        changeInTimeMicro = gameE->getTimer().calcChangeInTimeMicro();
        changeInTimeMill = gameE->getTimer().calcChangeInTimeMill();
        CITmic = changeInTimeMicro.count();
        CITmil = changeInTimeMill.count();

        logMsg ("changeInTimeMicro = " +convert->toString(CITmic));
        logMsg ("changeInTimeMill = " +convert->toString(CITmil));
        changeInTime = gameE->getTimer().getChangeInTimeMill().count();
        logMsg ("loopchange = " +convert->toString(changeInTime));
//        exit(0);
        if (changeInTime >= 10)
        {
            logMsg(func +"changeInTime > 10!");
//            exit(0);
            if (base->getGameS()->getGameType() == MULTINET)
            {
                processNetworkEvents();             
            }

//            logMsg("changeInTime = " +toString(changeInTime));
            if (gameE->getRenderScene())
            {
                logMsg(func +" gameS->getRenderScene()");
                
                base->getGameS()->updateState();  // updates the state of the game instance
            }
            gameE->getTimer().setPreviousTime(boost::chrono::system_clock::now());
        }
//        exit(0);
        
        if (!gameE->getRenderE()->renderFrame())
        {
            logMsg(func +" Unable to render frame!");
            exit(0);
        }
    }
    logMsg(func +" end");

    return (true);
}

bool UBCGame::startGame()  // starts the game
{
//    sharedPtr<gameState> gameS = gameState::Instance();
    std::string func = "UBC::startGame()";

    logMsg(func +" beginning");

//    exit(0);
//BASEREMOVAL    base->getGameS()->setBase(base);
    base->getGameS()->setupState();

    logMsg(func +" end");
//    exit(0);
    return (true);
}
