/***************************************************************************
 *   Copyright (C) 1999 - 2019 by Mike McLean                              *
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

#ifndef _GAMEENGINE_H_
#define _GAMEENGINE_H_

//#include "engine/inputengine.h"
//#include "engine/networkengine.h"

#include "OgreTimer.h"
#include "OgreVector3.h"

//#include <boost/chrono/system_clocks.hpp>

//#include "threads.h"
#include "utilities/timing.h"

//#include "engine/renderengine.h"
//#include "input.h"

#include "engine.h" 
#include "utilities/typedefs.h"

class inputEngine;
//class inputSystem;
class networkEngine;
class renderEngine;
class physicsEngine;
class gameEngine : public engine
{

public:

    gameEngine();  // constructor
    ~gameEngine();  // destructor
    
    timing getTimer() const;  // retrieves the value of timer
    void setTimer(const timing &set);  // sets the value of timer
    
    bool getMenuActive() const;  // retrieves the value of menuActive
    void setMenuActive(const bool &set);  // sets the value of menuActive 

        
    bool getQuitGame() const;  // retrieves the value of quitGame
    void setQuitGame(const bool &set);  // sets the value of quitGame

    bool getServerRunning() const;  // retrieves the value of serverRunning 
    void setServerRunning(const bool &set);  // the value of sets serverRunning 

    bool getClientRunning() const ;  // retrieves the value of clientRunning 
    void setClientRunning(const bool &set);  // sets the value of clientRunning 

    bool getCreateScene() const;  // retrieves the value of createScene 
    void setCreateScene(const bool &set);  // sets the value of createScene 

    bool getSceneCreated() const ;  // retrieves the value of sceneCreated
    void setSceneCreated(const bool &set);  // sets the value of sceneCreated 

    bool getRenderScene() const ;  // retrieves the value of renderScene 
    void setRenderScene(const bool &set);  // sets the value of renderScene 

    bool getMovePlayer() const;  // retrieves the value of movePlayer 
    void setMovePlayer(const bool &set);  // sets the value of movePlayer 

    bool getStart() const;  // retrieves the value of start
    void setStart(const bool &set);  // sets the value of start

    float getYOffset() const;  // retrieves the value of yOffset
    void setYOffset(const float &set);  // sets the value of yOffset
    
    renderEngineSharedPtr getRenderE() const;  // retrieves the value of renderE
    void setRenderE(const renderEngineSharedPtr &set);  // sets the value of renderE
    
    inputEngineSharedPtr getInputE() const;  // retrieves the value of inputE
    void setInputE(const inputEngineSharedPtr &set);  // sets the value of inputE
    
    networkEngineSharedPtr getNetworkE() const;  // retrieves the value of networkE
    void setNetworkE(const networkEngineSharedPtr &set);  // sets the value of networkE
    
    physicsEngineSharedPtr getPhysE() const;  // retrieves the value of physE
    void setPhysE(const physicsEngineSharedPtr &set);  // sets the value of physE

    bool setup();  // sets up the engine state
    bool startGame();  // starts a game

    void quit();  // quits the entire game

//    void gameLoop();  // runs the Main loop for the game

//    void processInput();  // processes game input
	

private:

    renderEngineSharedPtr renderE;  // render object
    inputEngineSharedPtr inputE;  // input object
    networkEngineSharedPtr networkE;  // network object
    physicsEngineSharedPtr physE;  // physics engine object

    float yOffset; // stores the y offset for objects on the screen
    
    Ogre::Vector3 courtTranslateVector;

    // time variables
    //Ogre::Timer loopTime;	// loop Timer
/*    boost::chrono::system_clock::time_point startLoopTime; // start loop Timer
    boost::chrono::system_clock::time_point loopTime; // loop Timer
    boost::chrono::milliseconds oldTime;	// stores the last reading of the timer.
    unsigned long changeInTime; // stores the difference between current reading of the timer and the previous reading.
*/
	timing timer;
    

    // Flags
    bool userInputLoaded;  // if set then user input configuration has been loaded from file
    bool menuActive;  // determines whether or not a menu is active
    bool start;  // if set then starts running game logic
    bool quitGame;  // if set then triggers the shutdown process for the game
    bool serverRunning;  // if set triggers the network server code
    bool clientRunning;  // if set triggers the network client code
    bool createScene;  // if set triggers the render system's createScene function
    bool sceneCreated;  // stores whether scene has been created
    bool renderScene;  // if set triggers the render system's scene rendering function
    bool movePlayer;  // if set triggers movement of a player for testing netwoirk code
};

#endif // _GAMEENGINE_H_
