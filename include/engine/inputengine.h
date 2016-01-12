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

 
#ifndef _INPUTENGINE_H_
#define _INPUTENGINE_H_

#include "SDL.h"
#include "SDL_syswm.h"
#include "Ogre.h"
#include <boost/thread/thread.hpp>
#include <boost/date_time.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/thread/locks.hpp>

#include "enums.h"
#include "userinput.h"
#include "engine/renderengine.h"
//#include "gui/gui.h"

#define EVENT_BUF_SIZE 256

typedef std::vector<inputMaps>   inputWorkQueues;

//class GUISystem;
class rendreEngine;

// input class
class inputEngine
{
public:

    inputEngine();  // constructor
    ~inputEngine();  // destructor
    
    //static inputEngine *Instance();
//    static boost::shared_ptr<inputEngine> Instance();

/*    boost::shared_ptr<GUISystem> getGui();  // retrieves the value of gui
    void setGui(boost::shared_ptr<GUISystem> set);  // sets the value of gui
*/
    bool getKeyInputReceived();  // retrieves the value of keyInputReceived
    void setKeyInputReceived(bool set);  // sets the value of keyInputReceived

    SDL_Event getInputEvent();  // retrieves the value of inputEvent 
    void setInputEvent(SDL_Event set);  // sets the value of inputEvent 

    std::string getKeyPressed();  // retrieves the value of keyPressed pressed 
    void setKeyPressed(std::string set);  // sets the value of keyPressed 

    inputMaps getInputMap();  // retrieves the value of inputMap 
    void setInputMap(inputMaps set);  // sets the value of inputMap 

    inputWorkQueues getInputWorkQueue();  // retrieves the value of inputWorkQueue
    void setInputWorkQueue(inputWorkQueues set);  // sets the value of inputWorkQueue

    std::vector<userInput> getUInput();  // retrieves the value of uInput
    void setUInput(std::vector<userInput> set);  // sets the value of uInput
    bool setup();   // sets up and initializes the  Input System
    bool destroy(); // destroys the Input system and related objects

    inputMaps keyMap();  // maps value of keyPressed string to inputMap
	
    bool processInput(bool menuActive, boost::shared_ptr<renderEngine> render);	// processes all input
    bool processUnbufferedKeyInput(bool textInput, bool menuActive);	// reads in unbuffered key presses
    bool processUnbufferedMouseInput();	// reads in unbuffered mouse input
    bool processUnbufferedTouchInput(boost::shared_ptr<renderEngine> render); // reads in unbuffered touch input
    bool processUnbufferedGamepadInput(); // reads in unbuffered mouse input
	
protected:
/*    inputEngine();
    inputEngine(const inputEngine&);
    inputEngine& operator= (const inputEngine&);
*/
    //~inputEngine();
    

    // SDL Input
    SDL_Event inputEvent;  // stores input events
    SDL_Event events[EVENT_BUF_SIZE];
    int eventWrite;

    int mouseX; // stores the X coordinate of the mouse.
    int mouseY; // stores the Y coordinate of the mouse.
    int mouseLeftClick;	// stores state of Left mouse button
    int mouseRightClick; // stores state of Right mouse button;

private:
    //static inputEngine *pInstance;
//    static boost::shared_ptr<inputEngine> pInstance;

//    boost::shared_ptr<GUISystem> gui;  // stores the copy of the gui object
    bool keyInputReceived;  // stores whether a key has been pressed
    std::string keyPressed; // stores which key was pressed

    inputMaps inputMap; // stores user input
 
    std::vector<userInput> uInput;  // stores user input mapping
 
    inputWorkQueues inputWorkQueue;
    inputWorkQueues internalInputWorkQueue;
    boost::mutex inputWorkQueueMutex;
};


#endif

