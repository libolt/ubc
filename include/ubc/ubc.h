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

#ifndef _UBC_H_
#define _UBC_H_

#ifdef __ANDROID__
#include "utilities/android-config.h"
#else
#include "config.h"
#endif

//#include "engine/networkengine.h"

//#include "ubc/ubcbase.h"
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
class UBCBase;
#include "utilities/typedefs.h"


class UBC 
{
public: 
    UBC(); // constructor
    ~UBC();	// destructor

    UBCBaseSharedPtr getBase();  // retrieves the value of UBCBase
    void setBase(UBCBaseSharedPtr set);  // sets the value of UBCBase
 
    UBCInputSharedPtr getInput();  // retrieves the value of UBCInput
    void setInput(UBCInputSharedPtr set);  // sets the value of UBCInput

    GUISystemSharedPtr getGui();  // retrieves the value of gui
    void setGui(GUISystemSharedPtr set);  // sets the value of gui


/*    bool getQuitGame();  // retrieves the value of quitGame
    void setQuitGame(bool quit);  // sets the value of quitGame
*/

    bool setup();  // sets up UBC object

    bool setupState();  // sets up the UBC game state
    void executeState();  // executes the UBC game code

    void run();  // runs the game
    
    bool startGame();  // starts a game

    void processNetworkEvents();  // processes events in the network subsyatem
    
    void processPhysicsEvents();  // processes events in the physics subsyatem
    
    bool gameLoop();  // runs the Main loop for the game

    void gameLoop_old();  // runs the Main loop for the game

    bool updateGUI();  // updates the gui based on received events
    
    bool createUserInstances();  // creates the user instances

    bool setupUserInstancesInput();  // sets up input mapping for each user
    
    bool setupInputSObjUserInput();  // sets up user input mapping for inputS object
    
protected:
  
private:

    static UBCBaseSharedPtr base;  // static copy of base class

    static UBCInputSharedPtr input;  // static copy of base class

    static GUISystemSharedPtr gui;  // the GUI object.
        
    float inputXPos;  // stores the x coordinate of input
    float inputYPos;  // stores the y coordinate of input
    bool inputLeftMouseClick;  // stores
//    bool quitGame;
};

#endif

