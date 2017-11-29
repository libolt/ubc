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

#include "utilities/conversion.h"

#include "engine/gameengine.h"
#include "engine/inputengine.h"
#include "utilities/logging.h"
#include "network/networkplayerstateobject.h"
#include "engine/renderengine.h"
#include "engine/physicsengine.h"
//#include "engine/sound/soundengine.h"


/*bool gameEngine::userInputLoaded;
bool gameEngine::menuActive;
bool gameEngine::start;
bool gameEngine::quitGame;
bool gameEngine::serverRunning;
bool gameEngine::clientRunning;
bool gameEngine::createScene;
bool gameEngine::sceneCreated;
bool gameEngine::renderScene;
bool gameEngine::movePlayer;
timing gameEngine::timer;*/

// static declarations
//renderEngineSharedPtr gameEngine::renderE;

gameEngine::gameEngine()  // constructor
//    : player[0](0),
 // playerNode[0](0)
{

//    yOffset = 0.0;

    userInputLoaded = false;
    menuActive = false;
    start = false;
    quitGame = false;
    serverRunning = false;
    clientRunning = false;
    sceneCreated = false;
    createScene = false;
    renderScene = false;
    movePlayer = false;

}

gameEngine::~gameEngine()  // destructor
{
}

timing gameEngine::getTimer()  // retrieves the value of timer
{
    return (timer);
}
void gameEngine::setTimer(timing set)  // sets the value of timer
{
    timer = set;
}

bool gameEngine::getMenuActive()   // retrieves the value of menuActive
{
    return(menuActive);
}
void gameEngine::setMenuActive(bool set)  // sets the value of menuActive
{
 
    menuActive = set;
}

bool gameEngine::getStart()  // retrieves the value of start
{
    return (start);
}
void gameEngine::setStart(bool set)  // sets the value of start
{
    start = set;
}

bool gameEngine::getQuitGame()  // retrieves the value of quitGame
{
    return(quitGame);
}
void gameEngine::setQuitGame(bool set)  // sets the value of quitGame
{
    quitGame = set;
}

bool gameEngine::getServerRunning()  // retrieves the value of serverRunning
{
	return (serverRunning);
}
void gameEngine::setServerRunning(bool set)  // sets the value of serverRunning
{
	serverRunning = set;
}

bool gameEngine::getClientRunning()  // retrieves the value of clientRunning
{
	return (clientRunning);
}
void gameEngine::setClientRunning(bool set)  // sets the value of clientRunning
{
	clientRunning = set;
}

bool gameEngine::getCreateScene()  // retrieves the value of createScene
{
	return (createScene);
}
void gameEngine::setCreateScene(bool set)  // sets the value of createScene
{
	createScene = set;
}

bool gameEngine::getSceneCreated()  // retrieves the value of sceneCreated
{
	return (sceneCreated);
}
void gameEngine::setSceneCreated(bool set)  // sets the value of sceneCreated
{
	sceneCreated = set;
}
bool gameEngine::getRenderScene()  // retrieves the value of renderScene
{
	return (renderScene);
}
void gameEngine::setRenderScene(bool set)  // sets the value of renderScene
{
	renderScene = set;
}

bool gameEngine::getMovePlayer()  // retrieves the value of moviePlayer
{
	return (movePlayer);
}
void gameEngine::setMovePlayer(bool set)  // sets the value of moviePlayer
{
	movePlayer = set;
}

float gameEngine::getYOffset()  // returns the value of yOffset
{
    return (yOffset);
}
void gameEngine::setYOffset(float set)  // sets the value of yOffset
{
    yOffset = set;
}

renderEngineSharedPtr gameEngine::getRenderE()  // retrieves the value of renderE
{
    return (renderE);
}
void gameEngine::setRenderE(renderEngineSharedPtr set)  // sets the value of renderE
{
//    renderE = set;
}
inputEngineSharedPtr gameEngine::getInputE()  // retrieves the value of inputE
{
    return (inputE);
}
void gameEngine::setInputE(inputEngineSharedPtr set)  // sets the value of inputE
{
    inputE = set;
}

networkEngineSharedPtr gameEngine::getNetworkE()  // retrieves the value of networkE
{
    return (networkE);
}
void gameEngine::setNetworkE(networkEngineSharedPtr set)  // sets the value of networkE
{
    networkE = set;
}

physicsEngineSharedPtr gameEngine::getPhysE()  // retrieves the value of physE
{
    return (physE);
}
void gameEngine::setPhysE(physicsEngineSharedPtr set)  // sets the value of physE
{
    physE = set;
}

bool gameEngine::setup()  // sets up engine state
{
    // initialize subclasses

    // renderEngine
    renderEngineSharedPtr tempRenderSharedPtr(new renderEngine);
    renderE = tempRenderSharedPtr;

    inputEngineSharedPtr tempInputSharedPtr(new inputEngine);
    inputE = tempInputSharedPtr;

    // networkEngine
    networkEngineSharedPtr tempNetworkSharedPtr(new networkEngine);
    networkE = tempNetworkSharedPtr;
    networkE->initialize();

    // physicsEngine
    sharedPtr<physicsEngine> tempPhysicsSharedPtr(new physicsEngine);
    physE = tempPhysicsSharedPtr;
    physE->setup();
///    physE->setup();

// inputEngine
//    inputEngine *tempInputObj = new inputEngine;

    return (true);
}

void gameEngine::quit()  // quits the game
{
//    sharedPtr<inputSystem> input = inputSystem::Instance();

    inputE->destroy();

}

