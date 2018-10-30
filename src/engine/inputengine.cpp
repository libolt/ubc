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
 *   MERCH.ANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
 
// Input

#include "utilities/conversion.h"

#undef None
#undef Button1
#undef Button2p
#undef Button3
#undef Button4
#undef Button5
#undef Button6
#undef Button7
#include "MyGUI_OgrePlatform.h"
#include "engine/inputengine.h"
#include "engine/gameengine.h"
#include "load/load.h"
#include "utilities/logging.h"

inputEngine::inputEngine()  // constructor
{
    keyInputReceived = false;
    mouseX = 0.0f;
    mouseY = 0.0f;
    mouseClick = NOCLICK;
    mouseClicked = false;
    mouseLeftClick = false;
    mouseRightClick = false;
    inputProcessed = false;
	
	keyPressed = INKEY_NONE;
    inputType = INNOTYPE;
//    inputGamePadMap = INGP_NONE;
    textInputStarted = false;
//    setup();
}

inputEngine::~inputEngine()  // destructor
{
}

bool inputEngine::getKeyInputReceived() const  // retrieves the value of keyInputReceived
{
    return (keyInputReceived);
}
void inputEngine::setKeyInputReceived(const bool &set)  // sets the value of keyInputReceived
{
   keyInputReceived = set;
}
 
SDL_Event inputEngine::getInputEvent() const  // retrieves the value of inputEvent
{
    return (inputEvent);
}
void inputEngine::setInputEvent(const SDL_Event &set)  // sets the value of inputEvent
{
    inputEvent = set;
}

inputKeyMaps inputEngine::getKeyPressed() const  // retrieves the value of keyPressed
{
    return(keyPressed);
}
void inputEngine::setKeyPressed(const inputKeyMaps &set)
{
    keyPressed = set;
}

std::string inputEngine::getInputText() const  // retrieves the value of inputText
{
    return (inputText);
}
void inputEngine::setInputText(const std::string &set)
{
    inputText = set;
}

inputTypes inputEngine::getInputType() const  // retrieve the value of inputType
{
    return (inputType);
}
void inputEngine::setInputType(const inputTypes &set)  // sets the value of inputType
{
    inputType = set;
}

bool inputEngine::getInputProcessed() const  // retrieves the value of inputProcessed
{
    return (inputProcessed);
}
void inputEngine::setInputProcessed(const bool &set)  // sets the value of inputProcessed
{
    inputProcessed = set;
}
/*
inputInGameMaps inputEngine::getInputInGameMap()  // retrieves the value of inputInGameMap 
{
    return(inputInGameMap);
}
void inputEngine::setInputInGameMap(inputInGameMaps set)  // sets the value of inputInGameMap 
{
    inputInGameMap = set;
}
*/
inputKeyWorkQueues inputEngine::getInputKeyWorkQueue() const  // retrieves the value of inputKeyWorkQueue
{
    return (inputKeyWorkQueue);
}
void inputEngine::setInputKeyWorkQueue(const inputKeyWorkQueues &set)  // sets the value of inputWorkQueue
{
    inputKeyWorkQueue = set;
}

inputGamePadWorkQueues inputEngine::getInputGamePadWorkQueue() const  // retrieves the value of inputGamePadWorkQueue
{
    return (inputGamePadWorkQueue);
}
void inputEngine::setInputGamePadWorkQueue(const inputGamePadWorkQueues &set)  // sets the value of inputGamePadWorkQueue
{
    inputGamePadWorkQueue = set;
}

inputTypeQueues inputEngine::getInputTypeQueue() const  // retrieves the value of inputTypeQueue
{
    return (inputTypeQueue);
}
void inputEngine::setInputTypeQueue(const inputTypeQueues &set)  // sets the value of inputTypeQueue
{
    inputTypeQueue = set;
}

float inputEngine::getMouseX() const  // retrieves the value of mouseX
{
    return (mouseX);
}
void inputEngine::setMouseX(const float &set)  // sets the value of mouseX
{
    mouseX = set;
}

float inputEngine::getMouseY() const  // retrieves the value of mouseY
{
    return (mouseY);
}
void inputEngine::setMouseY(const float &set)  // sets the value of mouseY
{
    mouseY = set;
}

mouseClicks inputEngine::getMouseClick() const  // retrieves the value of mouseClick
{
    return (mouseClick);
}
void inputEngine::setMouseClicks(const mouseClicks &set)  // sets the value of mouseClicks
{
    mouseClick = set;
}

bool inputEngine::getMouseClicked() const  // retrieves the value of mouseClicked
{
    return (mouseClicked);
}
void inputEngine::setMouseClicked(const bool &set)  // sets the value of mouseClicked
{
    mouseClicked = set;
}

bool inputEngine::setup()   // sets up and initializes the Input System
{
//  mDebugOverlay = OverlayManager::getSingleton().getByName("Core/DebugOverlay");

    logMsg("*** Initializing SDL Input System ***");
    SDL_ShowCursor(0);  // Hides the SDL Cursor in favor of the MyGUI Cursor

    return true;
}

bool inputEngine::destroy()  // destroys the OIS Input System and related objects
{
    return true;
}

bool inputEngine::processInput()  // processes all input
{
    conversionSharedPtr convert ;
    std::string func = "inputEngine::processInput()";
    
    logMsg(func +" begin");

//    renderEngineSharedPtr render = renderEngine::Instance();
    
//    keyPressed = "";  // resets value of keyPressed

    // processes keyboard input
/*    if (processUnbufferedKeyInput() == false)
    {
        return false;
    }
//    SDL_StopTextInput();
*/

//    logMsg("sdl grab = " +convert->toString(SDL_GetWindowGrab(render->getSDLWindow())));
/*#ifndef __ANDROID__
    logMsg("input!");
    struct android_app *state = render->getApp();
//	state->onInputEvent = &handleInput;
    logMsg("input??");
    AInputEvent* event;
    struct android_poll_source* source;
    int ident;
    int fdesc;
    int events;

    while((ident = ALooper_pollAll(0, &fdesc, &events, (void**)&source)) >= 0)
    {
        // process this event
        if (source)
            source->process(state, source);
    }

#else
*/
//    SDL_PumpEvents();
//    exit(0);
    size_t motion = SDL_EventState(SDL_FINGERMOTION, SDL_QUERY);
    logMsg (func +" motion = " +convert->toString(motion));
//    exit(0);
    if (!textInputStarted)
    {
        logMsg(func +" Starting Text Input");

        SDL_StartTextInput();
        textInputStarted = true;
        logMsg (func +" textInput Started!");
    }
    else
    {
        logMsg(func +"textInput already started!");
    }

    logMsg(func +" SDL_PollEvent()");

    while (SDL_PollEvent(&inputEvent))
    {
//        exit(0);
        size_t numTouch = SDL_GetNumTouchDevices();
        logMsg (func +" numTouch = " +convert->toString(numTouch));
//        exit(0);

//          Ogre::LogManager::getSingletonPtr()->logMessage("Crash??");

        switch (inputEvent.type)
        {
//            exit(0);
            case SDL_FINGERMOTION:
                logMsg(func +" Motion!");
//                exit(0);
                // processes touch input
                if (processTouchInput())
                {
                    return false;
                }
            break;
            case SDL_FINGERDOWN:
                logMsg(func +" Finger Down!");
//                logMsg("tfinger.x = " +convert->toString(inputEvent.tfinger.x*render->getWindowWidth()));
                logMsg(func +" tfinger.y = " +convert->toString(inputEvent.tfinger.y));
//                exit(0);
                // processes touch input
                if (!processTouchInput())
                {
                    return false;
                }
            break;
            case SDL_FINGERUP:
                logMsg(func +" Finger Up!");
//                exit(0);
                // processes touch input
                if (!processTouchInput())
                {
                    return false;
                }
            break;
            case SDL_MULTIGESTURE:
                logMsg(func +" Multigesture!");
//                exit(0);
                // processes touch input
                if (!processTouchInput())
                {
                    return false;
                }
            break;
            case SDL_KEYDOWN:
                logMsg(func +" KeyDown");
                if (processKeyInput())
                {
                    inputProcessed = true;                  
//                    inputType = KEYBOARD;
//                    inputKeyMaps inputMap = keyMap();
//                    exit(0);
//                    inputWorkQueue.push_back(inputMap);

//                    return false;
                }
//                logMsg(func +" keyDown key == " +keyPressed);
//                exit(0);
            break; 
            case SDL_TEXTINPUT:
                inputText = "";
                
                inputText = inputEvent.text.text;
                logMsg(func +" inputText! == " +inputText);
//                exit(0);
                if (inputText != "")
                {
                    logMsg(func +" inputText == " +convert->toString(keyPressed));
                    if (processTextInput())
                    {
                        inputProcessed = true;
                    }
//                    exit(0);
//                    inputMaps inputMap = keyMap();
//                    exit(0);
//                    inputWorkQueue.push_back(inputMap);
                }
//                logMsg("Blareep!");
//                logMsg("input keyPressed == " +keyPressed);
//                exit(0);
            break;

            case SDL_MOUSEMOTION:
            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
            case SDL_MOUSEWHEEL:
                logMsg(func +" Mouse!");
                // processes mouse input
                if (!processMouseInput())
                {
                    return false;
                }
//                exit(0);
            break;
            case SDL_CONTROLLERAXISMOTION:
            case SDL_CONTROLLERBUTTONDOWN:
            case SDL_CONTROLLERBUTTONUP:
            case SDL_CONTROLLERDEVICEADDED:
            case SDL_CONTROLLERDEVICEREMOVED:
            case SDL_CONTROLLERDEVICEREMAPPED:
                logMsg(func +" Controller!");
                // processes gamepad input
                if (!processGamepadInput())
                {
                    return false;
                }
//                exit(0);
            break;
            case SDL_QUIT:
                exit(0);
            break;
            default:
            break;
        }
    }
//    SDL_StopTextInput();
//    exit(0);
    processMouseInput();

    logMsg(func +" end");

    return (inputProcessed);
}

bool inputEngine::processKeyInput()  // processes unbuffered keyboard input
{
    conversionSharedPtr convert ;
    std::string func = "inputEngine::processKeyInput()";
//    sharedPtr<GUISystem> gui = GUISystem::Instance();
//	logMsg("Processing keyboard input");

    logMsg(func +" key == " +convert->toString(inputEvent.key.keysym.sym));
    logMsg(func +" key = " +convert->toString(keyPressed));
//    exit(0);
//    if (MyGUI::InputManager::getInstance().isFocusKey())	// checks if a MyGUI widget has key focus
//    {
        logMsg(func +" Crash?");
//        exit(0);
//      keyPressed = "";
        
    keyPressed = convert->toInputKey(inputEvent);
    
    if (keyPressed != INKEY_NONE)
    {
        inputTypeQueue.push_back(KEYBOARD);
        inputKeyWorkQueue.push_back(keyPressed);
        keyInputReceived = true;
    }
    else
    {
        logMsg(func +" Unable to match text input to a recognized key! ");
        return (false);
    }
/*        switch (inputEvent.key.keysym.scancode)
        {
            case SDL_SCANCODE_A:
                keyPressed = INKEY_A;
//                logMsg("keyPressedScan === " +keyPressed);
//                exit(0);
            break;
            case SDL_SCANCODE_B:
                keyPressed = INKEY_B;
//                exit(0);
            break;
            case SDL_SCANCODE_C:
                keyPressed = INKEY_C;
//                exit(0);
            break;
            case SDL_SCANCODE_D:
                keyPressed = INKEY_D;
//                exit(0);
            break;
            case SDL_SCANCODE_E:
                keyPressed = INKEY_E;
//                exit(0);
            break;
            case SDL_SCANCODE_F:
                keyPressed = INKEY_F;
                logMsg("F pressed!");
//                exit(0);
            break;  
            case SDL_SCANCODE_G:
                keyPressed = INKEY_G;
//                exit(0);
            break;
            case SDL_SCANCODE_H:
                keyPressed = INKEY_H;
//                exit(0);
            break;
            case SDL_SCANCODE_I:
                keyPressed = INKEY_I;
//                exit(0);
            break;
            case SDL_SCANCODE_J:
                 keyPressed = INKEY_J;
//                exit(0);
            break;   
            case SDL_SCANCODE_K:
                keyPressed = INKEY_K;
//                exit(0);
            break;
            case SDL_SCANCODE_L:
                keyPressed = INKEY_L;
//                exit(0);
            break;
            case SDL_SCANCODE_M:
                keyPressed = INKEY_M;
//                exit(0);
            break;
            case SDL_SCANCODE_N:
                keyPressed = INKEY_N;
//                exit(0);
            break;
            case SDL_SCANCODE_O:
                keyPressed = INKEY_O;
//                exit(0);
            break;
            case SDL_SCANCODE_P:
                keyPressed = INKEY_P;
//                exit(0);
            break;
            case SDL_SCANCODE_Q:
                keyPressed = INKEY_Q;
//                exit(0);
            break;
            case SDL_SCANCODE_R:
                keyPressed = INKEY_R;
//                exit(0);
            break;
            case SDL_SCANCODE_S:
                 keyPressed = INKEY_S;
                 logMsg("key == s!");
                 logMsg("keyPressed == " +convert->toString(keyPressed));
//                exit(0);
            break;
            case SDL_SCANCODE_T:
                keyPressed = INKEY_T;
//                exit(0);
            break;
            case SDL_SCANCODE_U:
                 keyPressed = INKEY_U;
//                exit(0);
            break;
            case SDL_SCANCODE_V:
                keyPressed = INKEY_V;
//                exit(0);
            break;
            case SDL_SCANCODE_W:
                keyPressed = INKEY_W;
//                exit(0);
            break;
            case SDL_SCANCODE_X:
                 keyPressed = INKEY_X;
//                exit(0);
            break;
            case SDL_SCANCODE_Y:
                keyPressed = INKEY_Y;
//                exit(0);
            break;
            case SDL_SCANCODE_Z:
                keyPressed = INKEY_Z;
//                exit(0);
            break;                     
            case SDL_SCANCODE_RETURN:
//            case SDLK_AC_BACK:
                logMsg("Return!");
                keyPressed = INKEY_RETURN;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Return, MyGUI::KeyCode::Return);
            break;
            case SDL_SCANCODE_BACKSPACE:
                logMsg("Backspace!");
//                 exit(0);
                keyPressed = INKEY_BACKSPACE;
//                gui->menuReceiveKeyPress(keyPressed); // sends input to menu key input processing function
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Backspace, 0);
            break;
            case SDL_SCANCODE_ESCAPE:
                logMsg("Escape!");
                keyPressed = INKEY_ESCAPE;
//              exit(0);
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Escape, 0);
            break;
            case SDL_SCANCODE_TAB:
                logMsg("Tab!");
                keyPressed = INKEY_TAB;
//                exit(0);
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Tab, 0);
            break;
            case SDL_SCANCODE_SPACE:
                logMsg("Space!");
                keyPressed = INKEY_SPACE;
//              MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Space, ' ');
            break;
            case SDL_SCANCODE_LSHIFT:
                keyPressed = INKEY_LSHIFT;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::LeftShift, 0);
            break;
            case SDL_SCANCODE_LCTRL:
                keyPressed = INKEY_LCTRL;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::LeftControl, 0);
            break;
            case SDL_SCANCODE_LALT:
                keyPressed = INKEY_LALT;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::LeftAlt, 0);
            break;
            case SDL_SCANCODE_LGUI:
                keyPressed = INKEY_LGUI;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::LeftWindows, 0);
            break;
            case SDL_SCANCODE_RSHIFT:
                keyPressed = INKEY_RSHIFT;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightShift, 0);
            break;
            case SDL_SCANCODE_RCTRL:
                keyPressed = INKEY_RCTRL;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightControl, 0);
            break;
            case SDL_SCANCODE_RALT:
                keyPressed = INKEY_RALT;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightAlt, 0);
            break;
            case SDL_SCANCODE_RGUI:
                keyPressed = INKEY_RGUI;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightWindows, 0);
            break;
            case SDL_SCANCODE_MENU:
                keyPressed = INKEY_MENU;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightWindow, 0);
            break;
            case SDL_SCANCODE_CAPSLOCK:
                keyPressed = INKEY_CAPSLOCK;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Capital, 0);
            break;
            case SDL_SCANCODE_F1:
                keyPressed = INKEY_F1;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F1, 0);
            break;
            case SDL_SCANCODE_F2:
                keyPressed = INKEY_F2;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F2, 0);
            break;
            case SDL_SCANCODE_F3:
                keyPressed = INKEY_F3;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F3, 0);
            break;
            case SDL_SCANCODE_F4:
                keyPressed = INKEY_F4;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F4, 0);
            break;
            case SDL_SCANCODE_F5:
                keyPressed = INKEY_F5;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F5, 0);
            break;
            case SDL_SCANCODE_F6:
                keyPressed = INKEY_F6;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F6, 0);
            break;
            case SDL_SCANCODE_F7:
                keyPressed = INKEY_F7;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F7, 0);
            break;
            case SDL_SCANCODE_F8:
                keyPressed = INKEY_F8;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F8, 0);
            break;
            case SDL_SCANCODE_F9:
                keyPressed = INKEY_F9;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F9, 0);
            break;
            case SDL_SCANCODE_F10:
                keyPressed = INKEY_F10;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F10, 0);
            break;
            case SDL_SCANCODE_F11:
                keyPressed = INKEY_F11;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F11, 0);
            break;
            case SDL_SCANCODE_F12:
                keyPressed = INKEY_F12;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F12, 0);
            break;
            case SDL_SCANCODE_UP:
                keyPressed = INKEY_UP;
//                logMsg("Up!");
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ArrowUp, 0);
            break;
            case SDL_SCANCODE_DOWN:
                keyPressed = INKEY_DOWN;
//                 MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ArrowDown, 0);
            break;
            case SDL_SCANCODE_LEFT:
                keyPressed = INKEY_LEFT;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ArrowLeft, 0);
            break;
            case SDL_SCANCODE_RIGHT:
                keyPressed = INKEY_RIGHT;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ArrowRight, 0);
            break;
            case SDL_SCANCODE_SCROLLLOCK:
                keyPressed = INKEY_SCROLLLOCK;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ScrollLock, 0);
            break;
            case SDL_SCANCODE_HOME:
                keyPressed = INKEY_HOME;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Home, 0);
            break;
            case SDL_SCANCODE_PAUSE:
                keyPressed = INKEY_PAUSE_BREAK;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Pause, 0);
            break;
            case SDL_SCANCODE_INSERT:
                keyPressed = INKEY_INSERT;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Insert, 0);
            break;
            case SDL_SCANCODE_PAGEUP:
                keyPressed = INKEY_PAGEUP;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::PageUp, 0);
            break;
            case SDL_SCANCODE_DELETE:
                keyPressed = INKEY_DELETE;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Delete, 0);
            break;
            case SDL_SCANCODE_END:
                keyPressed = INKEY_END;
//            MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::End, 0);
            break;
            case SDL_SCANCODE_PAGEDOWN:
                keyPressed = INKEY_PAGEDOWN;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::PageDown, 0);
            break;
            case SDL_SCANCODE_NUMLOCKCLEAR:
                keyPressed = INKEY_NUMLOCK;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::NumLock, 0);
            break;
            case SDL_SCANCODE_KP_DIVIDE:
                keyPressed = INKEY_DIVIDE;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Divide, 0);
            break;
            case SDL_SCANCODE_KP_MULTIPLY:
                keyPressed = INKEY_MULTIPLY;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Multiply, 0);
            break;
            case SDL_SCANCODE_KP_MINUS:
                keyPressed = INKEY_MINUS;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Minus, 0);
            break;
            case SDL_SCANCODE_KP_ENTER:
                keyPressed = INKEY_ENTER;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::NumpadEnter, 0);
            break;
            case SDL_SCANCODE_KP_0:
                keyPressed = INKEY_0;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad0, '0');
            break;
            case SDL_SCANCODE_KP_1:
                keyPressed = INKEY_1;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad1, '1');
            break;
            case SDL_SCANCODE_KP_2:
                keyPressed = INKEY_2;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad2, '2');
            break;
            case SDL_SCANCODE_KP_3:
                keyPressed = INKEY_3;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad3, '3');
            break;
            case SDL_SCANCODE_KP_4:
                keyPressed = INKEY_4;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad4, '4');
            break;
            case SDL_SCANCODE_KP_5:
                keyPressed = INKEY_5;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad5, '5');
            break;
            case SDL_SCANCODE_KP_6:
                keyPressed = INKEY_6;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad6, '6');
            break;
            case SDL_SCANCODE_KP_7:
                keyPressed = INKEY_7;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad7, '7');
            break;
            case SDL_SCANCODE_KP_8:
                keyPressed = INKEY_8;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad8, '8');
            break;
            case SDL_SCANCODE_KP_9:
                keyPressed = INKEY_9;
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad9, '9');
            break;
            
            default:
            logMsg("break");
            //    MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Enum(inputEvent.key.keysym.sym), inputEvent.key.keysym.sym);
            break;
        } */
//        logMsg("scancode = " +convert->toString(inputEvent.key.keysym.scancode));
//        switch (inputEvent.key.keysym.sym)
//        {
//            case SDLK_a:
//                keyPressed = "a";
//                exit(0);
//            break;
//        }
            
        
        logMsg("keyInputPressed == " +convert->toString(keyPressed));
  
//    }
//    if (gui->getMenuActive())  // checks if a menu is displayed
/*    if (menuActive)  // checks if a menu is displayed
    {
        logMsg("keyPressed == " +keyPressed);
        gui->menuReceiveKeyPress(keyPressed); // sends input to menu key input processing function
//        exit(0);
    }
    else
    {
        return (true);
    }
*/
    logMsg("keyInputPressed == " +convert->toString(keyPressed));

//    keyInputReceived = true;
//    keyPressed = "";
//	logMsg("Keyboard Input Processed");
    // Return true to continue rendering

	if (keyPressed != INKEY_NONE)
	{
		return (true);
	}
    return (false);
}

bool inputEngine::processTextInput()  // reads in text input
{
    conversionSharedPtr convert ;
    std::string func = "inputEngine::processTextInput()";
    
    logMsg(func +" textInput!");
//    exit(0);
    keyPressed = convert->toInputKey(inputEvent.text.text);
    
    if (keyPressed != INKEY_NONE)
    {
        inputTypeQueue.push_back(KEYBOARD);
        inputKeyWorkQueue.push_back(keyPressed);
        keyInputReceived = true;
//        exit(0);
    }
    else
    {
        logMsg(func +" Unable to match text input to a recognized key! ");
        return (false);
    }
//    exit(0);
    return (true);
}
bool inputEngine::processMouseInput()  // processes the unbuffered mouse input
{
    conversionSharedPtr convert ;
//    renderEngineSharedPtr render = renderEngine::Instance();

    int x, y;
    int state = -1;
    SDL_MouseMotionEvent motion;

    SDL_PumpEvents();
    SDL_GetMouseState(&x,&y);

//	logMsg("Processing mouse input");

/*    int w, h;
    SDL_Window *sdlWindow = render->getSDLWindow();
	
    SDL_GetWindowMaximumSize(sdlWindow,&w,&h);
    logMsg("sdlWindow width = " +convert->toString(w));
    logMsg("sdlWindow height = " +convert->toString(h));
    //SDL_GetGlobalMouseState(&x, &y);
    logMsg("mouse x = " +convert->toString(x));
    logMsg("mouse y = " +convert->toString(y));
*/
/*    state = SDL_GetMouseState(nullptr, nullptr)&SDL_TOUCH_MOUSEID;
    logMsg("Mouse state = " +convert->toString(state));
    if (state == 1)
    {
//      exit(0);
    }
    if (MyGUI::InputManager::getInstance().isFocusMouse())
    {
        if(state == 1)
        {
            mouseLeftClick = true;
            MyGUI::InputManager::getInstance().injectMousePress(x, y, MyGUI::MouseButton::Enum(0));

	//		exit(0);
        }
        else if (state == 0 && mouseLeftClick == 1) //if (SDL_GetMouseState(nullptr, nullptr)&SDL_BUTTON(1) == 0)
        {
            mouseLeftClick = false;
            MyGUI::InputManager::getInstance().injectMouseRelease(x, y, MyGUI::MouseButton::Enum(0));
        }
    }


    logMsg("Mouse x = " +convert->toString(x) + " y = " +convert->toString(y));
    if (mouseX != x || mouseY != y)
    {
        MyGUI::InputManager::getInstance().injectMouseMove(x,y,0);
    }
    */
    return true;
}

bool inputEngine::processTouchInput() // processes the unbuffered touch input
{
    conversionSharedPtr convert ;
//    renderEngineSharedPtr render = renderEngine::Instance();
    std::string func = "inputEngine::processTouchInput()";
    int state = -1;
    SDL_TouchFingerEvent touchMotion;

    SDL_PumpEvents();
    int numDevs = SDL_GetNumTouchDevices();
    logMsg(func +" numTouchDevices = " +convert->toString(numDevs));
    int evtState = 0;
    evtState = SDL_EventState(SDL_FINGERMOTION, SDL_QUERY);
    logMsg(func +" evtState FINGERMOTION = " +convert->toString(evtState));
    evtState = 0;
    evtState = SDL_EventState(SDL_FINGERDOWN, SDL_QUERY);
    logMsg(func +" evtState FINGERDOWN = " +convert->toString(evtState));
    SDL_Finger *finger = SDL_GetTouchFinger(0,0);
//    logMsg("Finger = " +convert->toString(finger));

    evtState = 0;
    evtState = SDL_EventState(SDL_FINGERUP, SDL_QUERY);
    if (evtState > 0)
    {
        logMsg(func +" evtState FINGERUP = " +convert->toString(evtState));
    //    exit(0);
    }
    
//    exit(0);
    mouseX = inputEvent.tfinger.x*getWindowWidth();
    mouseY = inputEvent.tfinger.y*getWindowHeight();
    logMsg(func +" touch X == " +convert->toString(mouseX));
    logMsg(func +" touch Y == " +convert->toString(mouseY));

//    exit(0);
//    if (MyGUI::InputManager::getInstance().isFocusMouse())
//    {
//        exit(0);
//        std::cout << "focused" << std::endl;
    if(SDL_EventState(SDL_FINGERDOWN, SDL_QUERY) == 1)
    {
        mouseLeftClick = true;
        //exit(0);
        mouseClick = LEFTCLICK;
//        exit(0);
        mouseClicked = true;
//        exit(0);
//        MyGUI::InputManager::getInstance().injectMousePress(x, y, MyGUI::MouseButton::Enum(0));
//        exit(0);
    }
    if (SDL_EventState(SDL_FINGERUP, SDL_QUERY) == 1) //if (SDL_GetMouseState(nullptr, nullptr)&SDL_BUTTON(1) == 0)
    {
//            exit(0);
        mouseLeftClick = false;
        mouseClick = NOCLICK;
        mouseClicked = false;
//        MyGUI::InputManager::getInstance().injectMouseRelease(x, y, MyGUI::MouseButton::Enum(0));
    }
        
    //	SDL_GetWindowSize(
/*    while (SDL_PollEvent(&inputEvent) > 0)
    {
        switch (inputEvent.type)
        {
            case SDL_FINGERMOTION:
                logMsg("Motion!");
                exit(0);
            break;
            case SDL_FINGERDOWN:
                logMsg("Finger Down!");
                exit(0);
            break;
            case SDL_FINGERUP:
                logMsg("Finger Up!");
                exit(0);
            break;
            case SDL_MULTIGESTURE:
                logMsg("Multigesture!");
                exit(0);
            break;
            case SDL_KEYDOWN:
                logMsg("Keydown!");
                exit(0);
            break;
            case SDL_MOUSEBUTTONDOWN:
                logMsg("MouseButtondown!");
                exit(0);
            break;
            case SDL_MOUSEMOTION:
                logMsg("MouseMotion!");
                exit(0);
            break;
            case SDL_MOUSEWHEEL:
                logMsg("MouseWheel!");
                exit(0);
            break;
            case SDL_JOYAXISMOTION:
            case SDL_JOYBALLMOTION:
            case SDL_JOYHATMOTION:
            case SDL_JOYBUTTONDOWN:
            case SDL_JOYBUTTONUP:
                logMsg("Joystick!");
                exit(0);
            break;
            case SDL_WINDOWEVENT:
                logMsg("Window!");
                exit(0);
            break;
            default:
            break;
        }
    }
*/
	return true;
}

bool inputEngine::processGamepadInput()  // reads in unbuffered mouse input
{
    return true;
}
