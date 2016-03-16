/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean                              *
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

#ifndef _UBC_H_
#define _UBC_H_

#ifdef __ANDROID__
#include "android-config.h"
#else
#include "config.h"
#endif

//#include "engine/networkengine.h"

#include "gui/gui.h"
#include "SDL.h"
#include "SDL_syswm.h"
#include "SDL_test_common.h"
#include "Ogre.h"
#include "OgreStringConverter.h" 
#include "OgreString.h"
//#include "engine/renderengine.h"
//#include "engine/gameengine.h"
//#include "state/gamestate.h"
//#include "input.h"
//#include "playerdata.h"
//#include "state/playerstate.h"

//class GUISystem;
class gameEngine;
class gameState;
class networkState;


class UBC : public GUISystem
{
public: 
    UBC(); // constructor
    ~UBC();	// destructor

/*    boost::shared_ptr<GUISystem> getGui();  // retrieves the value of gui
    void setGui(boost::shared_ptr<GUISystem> set);  // sets the value of gui
*/

/*    bool getQuitGame();  // retrieves the value of quitGame
    void setQuitGame(bool quit);  // sets the value of quitGame
*/
    boost::shared_ptr<gameState> getGameS();  // retrieves the value of gameS
    void setGameS(boost::shared_ptr<gameState> set);  // sets the value of gameS
    
    bool setupState();  // sets up the UBC game state
    void executeState();  // executes the UBC game code

    void run();  // runs the game
    
    bool startGame();  // starts a game

    void processInput();  // processes game input
	
    void gameLoop();  // runs the Main loop for the game

protected:
  
private:

//    boost::shared_ptr<GUISystem> gui;  // the GUI object.
    boost::shared_ptr<gameState> gameS;  // the gameState object
    boost::shared_ptr<networkState> networkS;  // the gameState object
    
    
//    bool quitGame;
};

#endif

