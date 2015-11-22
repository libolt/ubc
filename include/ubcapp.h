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

#ifndef _UBCAPP_H_
#define _UBCAPP_H_

#ifdef __ANDROID__
#include "android-config.h"
#else
#include "config.h"
#endif

#include "network/network.h"

#include "gui/gui.h"
#include "SDL.h"
#include "SDL_syswm.h"
#include "SDL_test_common.h"
#include "Ogre.h"
#include "OgreStringConverter.h" 
#include "OgreString.h"
#include "engine/renderengine.h"
#include "engine/gameengine.h"
#include "state/gamestate.h"
#include "input.h"
#include "playerdata.h"
#include "state/playerstate.h"

class UBC
{
public:
    ~UBC();	// destructor

    bool getQuitGame();
	void setQuitGame(bool quit);
protected:
    UBC();
//    UBC(const UBC&);
//    UBC &operator= (const UBC&);
private:
//    static UBC *pInstance;

    bool quitGame;
};

/* class UBC : public players, gameObjects //, inputSystem, gameObjects, players
{
public:
//	UBC(void);
    ~UBC();

    static UBC *Instance();

    bool getMenuActive();
    void setMenuActive(bool active);

    // starts a game
    bool startGame();

    // quits entire game
    void quit();

    void createScene();
    bool frameStarted();
    bool frameEnded();
    void createSceneManager();

    bool quitGame;

protected:
    UBC();
    UBC(const UBC&);
    UBC& operator= (const UBC&);


//    void loads(string pFilename);	// loads data from XML files

    int x;
    int y;
    int i;
    int j;
    Ogre::Vector3 courtTranslateVector;
    Ogre::Timer loopTime;
    unsigned long oldTime;
private:

    static UBC *pInstance;

    // Flags
    bool menuActive;	// determines whether or not a menu is active


};
*/

#endif

