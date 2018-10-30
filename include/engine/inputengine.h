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

 
#ifndef _INPUTENGINE_H_
#define _INPUTENGINE_H_

#include "SDL.h"
#include "SDL_syswm.h"
#include "Ogre.h"
/*#include <boost/shared_ptr.hpp>
#include <boost/thread/thread.hpp>
#include <boost/date_time.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/thread/locks.hpp>
*/

#include "utilities/enums.h"

#include "utilities/typedefs.h"

//#include "engine/renderengine.h"
//#include "gui/gui.h"

#include "engine.h"

#define EVENT_BUF_SIZE 256

//class GUISystem;
class renderEngine;

// input class
class inputEngine : public engine
{
public:

    inputEngine();  // constructor
    ~inputEngine();  // destructor
    
    bool getKeyInputReceived() const;  // retrieves the value of keyInputReceived
    void setKeyInputReceived(const bool &set);  // sets the value of keyInputReceived

    SDL_Event getInputEvent() const;  // retrieves the value of inputEvent 
    void setInputEvent(const SDL_Event &set);  // sets the value of inputEvent 

    inputKeyMaps getKeyPressed() const;  // retrieves the value of keyPressed pressed 
    void setKeyPressed(const inputKeyMaps &set);  // sets the value of keyPressed 

    std::string getInputText() const;  // retrieves the value of inputText
    void setInputText(const std::string &set);
    
    inputTypes getInputType() const;  // retrieve the value of inputType
    void setInputType(const inputTypes &set);  // sets the value of inputType
    
    bool getInputProcessed() const;  // retrieves the value of inputProcessed
    void setInputProcessed(const bool &set);  // sets the value of inputProcessed
    
//    inputMaps getInputMap();  // retrieves the value of inputMap 
//    void setInputMap(inputMaps set);  // sets the value of inputMap 

    inputKeyWorkQueues getInputKeyWorkQueue() const;  // retrieves the value of inputKeyWorkQueue
    void setInputKeyWorkQueue(const inputKeyWorkQueues &set);  // sets the value of inputKeyWorkQueue

    inputGamePadWorkQueues getInputGamePadWorkQueue() const;  // retrieves the value of inputGamePadWorkQueue
    void setInputGamePadWorkQueue(const inputGamePadWorkQueues &set);  // sets the value of inputGamePadWorkQueue

    inputTypeQueues getInputTypeQueue() const;  // retrieves the value of inputTypeQueue
    void setInputTypeQueue(const inputTypeQueues &set);  // sets the value of inputTypeQueue
        
    float getMouseX() const;  // retrieves the value of mouseX
    void setMouseX(const float &set);  // sets the value of mouseX
    
    float getMouseY() const;  // retrieves the value of mouseY
    void setMouseY(const float &set);  // sets the value of mouseY

    mouseClicks getMouseClick() const;  // retrieves the value of mouseClick
    void setMouseClicks(const mouseClicks &set);  // sets the value of mouseClicks
    
    bool getMouseClicked() const;  // retrieves the value of mouseClicked
    void setMouseClicked(const bool &set);  // sets the value of mouseClicked
    
    bool setup();   // sets up and initializes the  Input System
    bool destroy(); // destroys the Input system and related objects

    bool processInput();	// processes all input
    bool processKeyInput();	// reads in key presses
    bool processTextInput();  // reads in text input
    bool processMouseInput();	// reads in mouse input
    bool processTouchInput(); // reads in touch input
    bool processGamepadInput(); // reads in mouse input
	
private:

    // SDL Input
    SDL_Event inputEvent;  // stores input events
    SDL_Event events[EVENT_BUF_SIZE];
    int eventWrite;

    float mouseX; // stores the X coordinate of the mouse.
    float  mouseY; // stores the Y coordinate of the mouse.
    mouseClicks mouseClick;  // stores which mouse button has been clicked
    bool mouseClicked;  // stores whether or not a mouse button has been clicked
    
    bool mouseLeftClick;	// stores state of Left mouse button
    bool mouseRightClick; // stores state of Right mouse button;

    bool textInputStarted;  // determines if text input has started
    
    bool keyInputReceived;  // stores whether a key has been pressed
    inputKeyMaps keyPressed; // stores which key was pressed

    std::string inputText;  // stores text inout by user
    
    inputTypes inputType;  // storrs the typee of input that was received
    bool inputProcessed;  // stores whether or not any input has been processed
	
//    inputMaps inputMap; // stores user input

    inputKeyWorkQueues inputKeyWorkQueue;
    inputKeyWorkQueues internalInputKeyWorkQueue;
    inputGamePadWorkQueues inputGamePadWorkQueue;
    inputTypeQueues inputTypeQueue;  // stores queue of input types to process
//    std::mutex inputWorkQueueMutex;
};


#endif

