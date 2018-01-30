/***************************************************************************
 *   Copyright (C) 1999 - 2018 by Mike McLean                              *
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
#include "utilities/android-config.h"
#else
#include "config.h"
#endif

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
#include "gui/gui.h"
//class GUISystem;
class gameEngine;
class UBCGame;

#include "utilities/typedefs.h"


class UBC 
{
public: 
    UBC(); // constructor
    ~UBC();	// destructor

    gameEngineSharedPtr getGameE();  // retrieves the value of gameE
    void setGameE(gameEngineSharedPtr set);  // sets the value of gameE

    GUISystemSharedPtr getGui();  // retrieves the value of gui
    void setGui(GUISystemSharedPtr set);  // sets the value of gui

    UBCGameSharedPtr getGame();  // retrieves the value of game
    void setGame(UBCGameSharedPtr set);  // sets the value of game

    UBCInputSharedPtr getInput();  // retrieves the value of input
    void setInput(UBCInputSharedPtr set);  // sets the value of input

/*    bool getQuitGame();  // retrieves the value of quitGame
    void setQuitGame(bool quit);  // sets the value of quitGame
*/

    bool setup();  // sets up UBC object

    bool setupState();  // sets up the UBC game state
    void executeState();  // executes the UBC game code

    void run();  // runs the game
        
//    bool gameLoop();  // runs the Main loop for the game

    void gameLoop_old();  // runs the Main loop for the game

    bool updateGUI();  // updates the gui based on received events
    

    
    bool setupInputSObjUserInput();  // sets up user input mapping for inputS object
    
protected:
  
private:

    static gameEngineSharedPtr gameE;  // the gameEngine object

    static GUISystemSharedPtr gui;  // the GUI object.


    static UBCGameSharedPtr game;  // static copy of game class

    static UBCInputSharedPtr input;  // static copy of input class
        
    float inputXPos;  // stores the x coordinate of input
    float inputYPos;  // stores the y coordinate of input
    bool inputLeftMouseClick;  // stores
//    bool quitGame;
};

#endif

