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

#include "utilities/conversion.h"
#include "OgrePrerequisites.h"
#include "components/guicomponents.h"
#include "components/ubccomponents.h"
#include "data/gamedata.h"
#include "engine/gameengine.h"
#include "engine/inputengine.h"
#include "engine/renderengine.h"
#include "engine/physicsengine.h"
#include "entity/playerentity.h"
//#include "state/basketballstate.h"
#include "entity/gameentity.h"
#include "input/inputgamepads.h"
#include "input/inputkeyboards.h"
#include "state/networkstate.h"
#include "state/playerstate.h"
//#include "state/teamstate.h"
#include "users/users.h"
#include "users/usersinputs.h"
#include "load/loadusersinputs.h"
#include "utilities/logging.h"
#include "ubc/ubc.h"
#include "ubc/ubcgame.h"
#include "ubc/ubcinput.h"
#include "network/networkplayerstateobject.h"
#include "statemachine/playerstatemachine.h"

#ifdef __ANDROID__
#include "utilities/android.h"
#include "SDL.h"
#include "SDL_main.h"
#endif

UBC::UBC()  // constructor
{
    component = nullptr;
    inputXPos = 0;
    inputYPos = 0;
    inputLeftMouseClick = false;
}

UBC::~UBC() = default;  // destructor


UBCComponentsSharedPtr UBC::getComponent() const  // retrieves the value of component
{
    return (component);
}
void UBC::setComponent(const UBCComponentsSharedPtr &set)  // sets the value of component
{
    component = set;
}

bool UBC::setup()  // sets up UBC object
{
    std::string func = "UBC::setup()";

    UBCComponentsSharedPtr tempComponent(new UBCComponents);
    component = tempComponent;
    //    gameEngine *tempGameEObj = new gameEngine;
    gameEngineSharedPtr tempGameESharedPtr(new gameEngine);
    component->setGameE(tempGameESharedPtr);
//    gameE(new gameEngine);
    logMsg(func +" gameE->setup()");
    component->getGameE()->setup();  // sets up the game engine
    
    logMsg(func +" begin");

    GUISystemSharedPtr tempGUISharedPtr(new GUISystem);
    component->setGui(tempGUISharedPtr);
    
    component->getGui()->setGameE(component->getGameE());
    
    // setup game object
    UBCGameSharedPtr tempGameSharedPtr(new UBCGame);

    component->setGame(tempGameSharedPtr);
    component->getGame()->setUBCComponent(component);
    
    // setup input object
    UBCInputSharedPtr tempInputSharedPtr(new UBCInput);
    component->setInput(tempInputSharedPtr);
//    input->setBase(base);
//    base->getInputKeyboard()->setBase(base);
//    base->getInputGamePad()->setBase(base);
    logMsg(func +" end");
    
//        exit(0);
//        gui->getBase()->setGameS(gameInstance);
//        exit(0);
    return (true);
}

bool UBC::setupState()  // sets up the UBC game state
{
//    Ogre::Viewport *vp = getRenderE()->getViewPort();
//    setViewPort(*vp);  // sets the viewPort for MyGUI
//    exit(0);
    bool stateSetup = true;
    std::string func = "UBC::setupState()";

    logMsg(func +" begin");

//    GUISystemSharedPtr gui = base->getGui();
    if (component->getGui()->setup(component->getGameE()->getRenderE()))  // sets up the game GUI
    {
        component->getGui()->setGameInstance(component->getGame()->getGameInstance());  // shares gameInstance with gui object
//        exit(0);
        component->getGui()->getFlag()->setSetupComplete(true);
//        exit(0);
        component->getGui()->mainMenu(component->getGameE()->getRenderE());
//        exit(0);
        component->getGui()->backButtons();
    }
    else
    {
        logMsg(func +" Unable to setup GUI!");
        exit(0);
    }
    
    logMsg(func +" end");

    return (stateSetup);
}

void UBC::executeState()  // executes the UBC game code
{
}

void UBC::run()  // runs the game
{
    conversionSharedPtr convert ;
//    exit(0);
//    renderEngineSharedPtr renderTemp = gameE->getRenderE();
//    exit(0);
    std::string func = "UBC::run()";

    logMsg(func +" begin");

//    exit(0);
//    base->setup();
    component->getGame()->setup();
    component->getGameE()->getRenderE()->initSDL(); // Initializes the SDL Subsystem
//    exit(0);
    component->getGameE()->getRenderE()->initOgre(); // Initializes the Ogre Subsystem
//    exit(0);
    component->getGameE()->getRenderE()->createScene(); // creates rendering scene.

//    sharedPtr<entity> gameStateSharedPtr(new entity);

//    exit(0);

    logMsg(func +" pre setupState!");
    if (setupState())  // sets up the game state
    {
        logMsg(func +" UBC state setup successfully!");
    }
    else
    {
        logMsg(func +" Unable to setup UBC state!");
//        return (false);
    }
//    exit(0);
//    gameInstance->createInstances();  // creates object instances
//    sharedPtr<entity> gameStateSharedPtr(new entity);

    if (component->getGameE()->getRenderE()->getMWindow() == nullptr)
    {
        logMsg(func +" mWindow == nullptr!");
//        exit(0);
    }
//    exit(0);
//    setupState();  // sets up the game state

    sharedPtr<Ogre::Viewport> vp = component->getGameE()->getRenderE()->getViewPort();
//    setViewPort(*vp);  // sets the viewPort for MyGUI

//    exit(0);
    
    //FIXME! Hard coded until code is restructured
    component->getGame()->setNumUsers(1);
    
    logMsg(func + " Creating Users Instances!");
    if (!component->getGame()->getUsersInstancesCreated())
    {
        if (component->getGame()->createUserInstances())
        {
            component->getGame()->setUsersInstancesCreated(true);
        }
        else
        {
            
        }
    }
    else
    {
        
    }
    
    logMsg(func + "Setting up Users Input");
    // sets up users input
    if (component->getGame()->getUsersInstancesCreated() && !component->getGame()->getUserInstancesInputSetup())
    {
        if (component->getGame()->setupUserInstancesInput())
        {
            component->getGame()->setUserInstancesInputSetup(true);
        }
        else
        {
            
        }
    }
    else
    {
        
    }
    
    logMsg(func +" Setting up input object");
    if (!component->getInput()->getSetupComplete())
    {
        logMsg(func +" setting up UBCInput object");
        if (component->getInput()->setup(component->getGameE()->getInputE()))
        {
            logMsg(func +" Input setup!");
            component->getInput()->setSetupComplete(true);
        }
        else
        {
            logMsg(func +" Unable to setup Input!");
            exit(0);
        }

    }
/*    if (!base->getInputSUInputSetup())
    {
        if (setupInputSObjUserInput())
        {
            base->setInputSUInputSetup(true);
        }
        else
        {
            logMsg(func +" Unable to setup uInput!");
            exit(0);
        }
    }
    else
    {
        
    }
*/
    //inputSystem *input = inputSystem::Instance();
//    sharedPtr<inputSystem> input = getInputE();
//    exit(0);

//    bool quitGame = gameE->getQuitGame();
       
    component->getGame()->loop(component->getGameE(), component->getInput(), component->getGui());

    logMsg(func +" end");

}


bool UBC::updateGUI()  // updates the gui based on received events
{
    std::string func = "UBC::updateGUI()";

    logMsg(func +" begin");
    exit(0);
//    GUISystemSharedPtr gui = base->getGui();
    if (component->getGameE()->getInputE()->getMouseClicked())
    {
        logMsg(func +" updateGUI Mouse Clicked!");
        exit(0);
        component->getGui()->getComponent()->getMGUI()->injectMousePress(component->getGameE()->getInputE()->getMouseX(), component->getGameE()->getInputE()->getMouseY(), MyGUI::MouseButton::Left);
    }
    else
    {
        component->getGui()->getComponent()->getMGUI()->injectMouseRelease(component->getGameE()->getInputE()->getMouseX(), component->getGameE()->getInputE()->getMouseY(), MyGUI::MouseButton::Left);
    }
//    base->setGui(gui);

    logMsg(func +" end");

    return (true);
}

bool UBC::setupInputSObjUserInput()  // sets up user input mapping for inputS object
{
    usersMSharedPtr tempUsersInstance;
    usersInputsVecSharedPtr tempUserInput;
    
    tempUsersInstance = component->getGame()->getUsersInstance();

    
    for ( auto TUIIT : tempUsersInstance)
    {
        tempUserInput.push_back(TUIIT.second->getUserInput());
    }
    
    component->getInput()->getInputGamePad()->getInputInstance()->setUInput(tempUserInput);
    component->getInput()->getInputKeyboard()->getInputInstance()->setUInput(tempUserInput);

    return (true);
}

int main(int argc, char *argv[])
{
    conversionSharedPtr convert ;
    sharedPtr<UBC> ubc(new UBC);
    std::string func = "main()";

    logMsg(func +" begin");
    ubc->setup();
    ubc->run();
    logMsg(func +" end");

	return (0);
}

