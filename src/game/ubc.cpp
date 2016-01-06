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


UBC::UBC()
{
	quitGame = false;
}

UBC::~UBC()
{

}

bool UBC::getQuitGame()
{
	return (quitGame);
}

void UBC::setQuitGame(bool quit)
{
    quitGame = quit;
}


int main(int argc, char *argv[])
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    UBC ubc;
    boost::shared_ptr<renderEngine> render = ubc.getRender();
//    boost::shared_ptr<gameEngine> gameE = gameEngine::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<GUISystem> gui = GUISystem::Instance();

    render->initSDL(); // Initializes the SDL Subsystem

    render->initOgre(); // Initializes the Ogre Subsystem
    render->createScene(); // creates rendering scene.
//    exit(0);
    gameS->createInstances();  // creates object instances
//    exit(0);
    gui->initMyGUI(render); // Initializes MyGUI
    if (!gui->getMainMenuCreated())
    {
        gui->createMainMenuGUI(render); // creates the main menu gui.
		gui->createBackButtons(render); // creates the back buttons.
    }
//    exit(0);
    logMsg("Initializing Input");
    //inputSystem *input = inputSystem::Instance();
    boost::shared_ptr<inputSystem> input = ubc.getInput();
//    exit(0);
    ubc.gameLoop();

    atexit(SDL_Quit);

	return (0);
}

