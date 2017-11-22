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
#include "utilities/conversion.h"

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

bool UBCGame::loop()  // Main Game Loop
{
    conversionSharedPtr convert = conversion::Instance();
    bool quitGame = base->getGameE()->getQuitGame();
    unsigned long changeInTime = 0;
    unsigned long CITmic = 0;
    unsigned long CITmil = 0;
    std::string func = "UBC::gameLoop()";
    boost::chrono::microseconds changeInTimeMicro;
    boost::chrono::milliseconds changeInTimeMill;
    playerStateMachine playerSM;
    playerSMData *playerSMD = new playerSMData;
    playerSMData *playerSMD2 = new playerSMData;
    playerSMData *playerSMD3 = new playerSMData;

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
        input->process();
//        processPhysicsEvents();
        
///        if (base->getGameS()->getGameSetupComplete())  // checks to make sure game setup is complete before continuing
///        {
            
///            if (!base->getGameE()->getSceneCreated())
///            {
///                logMsg(func +" Scene Not Created!");
//                exit(0);
///                if (base->getGameS()->getGameType() == SINGLE)
///                {
///                    logMsg(func +" getGameType() == SINGLE");
///                    base->getGameE()->setCreateScene(true);
///                    exit(0);
///                }
///                else if (base->getGameS()->getGameType() == MULTILOCAL)
///                {
///                    logMsg(func +" getGameType() == MULTILOCAL");
///                    base->getGameE()->setCreateScene(true);
//                    exit(0);
///                }
///                else if (base->getGameS()->getGameType() == MULTINET)
///                {
///                    logMsg(func +" getGameType() == MULTINET");
///
///                    if (base->getGameE()->getNetworkE()->getServerReceivedConnection() || base->getGameE()->getNetworkE()->getClientEstablishedConnection())  // checks if server and client are connected
///                    {
///                        base->getGameE()->setCreateScene(true);
///                    }
    //             exit(0);
///                }
///            }
///        }
        
       // exit(0);

        if (game->getStartActiveGame())
        {
            if (startGame())
            {
                base->getGameE()->setStart(false);
                base->getGameE()->setRenderScene(true);
                game->setStartActiveGame(false);
            }
            else
            {
                logMsg(func + " Unable to Start Active Game Instance!");
                exit(0);
            }
        }
        changeInTimeMicro = base->getGameE()->getTimer().calcChangeInTimeMicro();
        changeInTimeMill = base->getGameE()->getTimer().calcChangeInTimeMill();
        CITmic = changeInTimeMicro.count();
        CITmil = changeInTimeMill.count();

        logMsg ("changeInTimeMicro = " +convert->toString(CITmic));
        logMsg ("changeInTimeMill = " +convert->toString(CITmil));
        changeInTime = base->getGameE()->getTimer().getChangeInTimeMill().count();
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
            if (base->getGameE()->getRenderScene())
            {
                logMsg(func +" gameS->getRenderScene()");
                
                base->getGameS()->updateState();  // updates the state of the game instance
            }
            base->getGameE()->getTimer().setPreviousTime(boost::chrono::system_clock::now());
        }
//        exit(0);
        
        if (!base->getGameE()->getRenderE()->renderFrame())
        {
            logMsg(func +" Unable to render frame!");
            exit(0);
        }
    }
    logMsg(func +" end");

    return (true);
}
