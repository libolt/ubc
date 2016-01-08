/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean   *
 *   libolt@libolt.net   *
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

#include "conversion.h"
#include "OgrePrerequisites.h"
#include "engine/gameengine.h"
#include "state/gamestate.h"
#include "logging.h"
#include "ubc.h"

#ifdef __ANDROID__
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
#include "android.h"
#include "SDL.h"
#include "SDL_main.h"
#endif


UBC::UBC()  // constructor
{
	quitGame = false;
}

UBC::~UBC()  // destructor
{

}

boost::shared_ptr<GUISystem> UBC::getGui()  // retrieves the value of gui
{
    return (gui);
}
void UBC::setGui(boost::shared_ptr<GUISystem> set)  // sets the value of gui
{
    gui = set;
}

bool UBC::getQuitGame()  // retrieves the value of quitGame
{
	return (quitGame);
}

void UBC::setQuitGame(bool set)  // sets the value of quitGame
{
    quitGame = set;
}


bool UBC::setupState()  // sets up the UBC game state
{
    Ogre::Viewport *vp = getRender()->getViewPort();
    gui->setViewPort(*vp);  // sets the viewPort for MyGUI

    gui->initMyGUI(getRender()); // Initializes MyGUI
    if (!gui->getMainMenuCreated())
    {
        gui->createMainMenuGUI(); // creates the main menu gui.
        gui->createBackButtons(); // creates the back buttons.
    }
    gui->setNetwork(getNetwork());
    return (false);
}

void UBC::executeState()  // executes the UBC game code
{
}

int main(int argc, char *argv[])
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    UBC ubc;
    boost::shared_ptr<renderEngine> render = ubc.getRender();
//    boost::shared_ptr<gameEngine> gameE = gameEngine::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<GUISystem> gui = ubc.getGui();

    render->initSDL(); // Initializes the SDL Subsystem

    render->initOgre(); // Initializes the Ogre Subsystem
    render->createScene(); // creates rendering scene.
//    exit(0);
    gameS->createInstances();  // creates object instances
//    exit(0);
    ubc.setupState();  // sets up the game state

/*    Ogre::Viewport *vp = render->getViewPort();
    gui->setViewPort(*vp);  // sets the viewPort for MyGUI
    
    gui->initMyGUI(render); // Initializes MyGUI
    if (!gui->getMainMenuCreated())
    {
        gui->createMainMenuGUI(); // creates the main menu gui.
        gui->createBackButtons(); // creates the back buttons.
    }
*/
//    exit(0);
    logMsg("Initializing Input");
    //inputSystem *input = inputSystem::Instance();
    boost::shared_ptr<inputSystem> input = ubc.getInput();
//    exit(0);
    ubc.gameLoop();

    atexit(SDL_Quit);

	return (0);
}

