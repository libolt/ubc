/***************************************************************************
 *   Copyright (C) 1999 - 2016 by Mike McLean                              *
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
#include <boost/shared_ptr.hpp>
#include <boost/thread/thread.hpp>
#include <boost/date_time.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/thread/locks.hpp>

#include "enums.h"
#include "userinput.h"
//#include "engine/renderengine.h"
//#include "gui/gui.h"

#include "engine.h"

#define EVENT_BUF_SIZE 256

typedef std::vector<inputKeyMaps>   inputWorkQueues;
typedef std::vector<inputTypes> inputTypeQueues;  // stores types of input processed by the engine

//class GUISystem;
class renderEngine;

// input class
class inputEngine : public engine
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

    inputKeyMaps getKeyPressed();  // retrieves the value of keyPressed pressed 
    void setKeyPressed(inputKeyMaps set);  // sets the value of keyPressed 

    bool getInputProcessed();  // retrieves the value of inputProcessed
    void setInputProcessed(bool set);  // sets the value of inputProcessed
    
    inputMaps getInputMap();  // retrieves the value of inputMap 
    void setInputMap(inputMaps set);  // sets the value of inputMap 

    inputWorkQueues getInputWorkQueue();  // retrieves the value of inputWorkQueue
    void setInputWorkQueue(inputWorkQueues set);  // sets the value of inputWorkQueue

    inputTypeQueues getInputTypeQueues();  // retrieves the value of inputTypeQueue
    void setInputTypeQueues(inputTypeQueues set);  // sets the value of inputTypeQueues
    
    std::vector<userInput> getUInput();  // retrieves the value of uInput
    void setUInput(std::vector<userInput> set);  // sets the value of uInput
    
    float getMouseX();  // retrieves the value of mouseX
    void setMouseX(float set);  // sets the value of mouseX
    
    float getMouseY();  // retrieves the value of mouseY
    void setMouseY(float set);  // sets the value of mouseY

    mouseClicks getMouseClick();  // retrieves the value of mouseClick
    void setMouseClicks(mouseClicks set);  // sets the value of mouseClicks
    
    bool getMouseClicked();  // retrieves the value of mouseClicked
    void setMouseClicked(bool set);  // sets the value of mouseClicked
    
    bool setup();   // sets up and initializes the  Input System
    bool destroy(); // destroys the Input system and related objects

    inputMaps keyMap();  // maps value of keyPressed string to inputMap
	
    bool processInput();	// processes all input
    bool processKeyInput(bool textInput);	// reads in key presses
    bool processTextInput();  // reads in text input
    bool processMouseInput();	// reads in mouse input
    bool processTouchInput(); // reads in touch input
    bool processGamepadInput(); // reads in mouse input
	
private:

/*    inputEngine();
    inputEngine(const inputEngine&);
    inputEngine& operator= (const inputEngine&);
*/
    //~inputEngine();
    

    // SDL Input
    static SDL_Event inputEvent;  // stores input events
    SDL_Event events[EVENT_BUF_SIZE];
    int eventWrite;

    static float mouseX; // stores the X coordinate of the mouse.
    static float  mouseY; // stores the Y coordinate of the mouse.
    static mouseClicks mouseClick;  // stores which mouse button has been clicked
    static bool mouseClicked;  // stores whether or not a mouse button has been clicked
    
    static bool mouseLeftClick;	// stores state of Left mouse button
    static bool mouseRightClick; // stores state of Right mouse button;

    static bool textInputStarted;  // determines if text input has started
    
    //static inputEngine *pInstance;
//    static boost::shared_ptr<inputEngine> pInstance;

//    boost::shared_ptr<GUISystem> gui;  // stores the copy of the gui object
    static bool keyInputReceived;  // stores whether a key has been pressed
    inputKeyMaps keyPressed; // stores which key was pressed

    static bool inputProcessed;  // stores whether or not any input has been processed
	
    inputMaps inputMap; // stores user input

    std::vector<userInput> uInput;  // stores user input mapping
 
    inputWorkQueues inputWorkQueue;
    inputWorkQueues internalInputWorkQueue;
    inputTypeQueues inputTypeQueue;  // stores queue of input types to process
    boost::mutex inputWorkQueueMutex;
};


#endif

