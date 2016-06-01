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
 *   MERCH.ANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
 
// Input
#include "conversion.h"

#undef None
#undef Button1
#undef Button2p
#undef Button3
#undef Button4
#undef Button5
#undef Button6
#undef Button7
#include "MyGUI.h"
#include "MyGUI_OgrePlatform.h"

#include "engine/inputengine.h"
#include "engine/gameengine.h"
//#include "state/gamestate.h"
//#include "gui/gui.h"
#include "load.h"
#include "logging.h"
//#include "engine/renderengine.h"


/*boost::shared_ptr<inputEngine> inputEngine::pInstance;

boost::shared_ptr<inputEngine> inputEngine::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        //pInstance = new inputEngine; // create sole instance
        boost::shared_ptr<inputEngine> tInstance(new inputEngine);
        pInstance = tInstance;
    }
    return pInstance; // address of sole instance
}
*/

// static variables 

SDL_Event inputEngine::inputEvent; 
bool inputEngine::keyInputReceived;
bool inputEngine::mouseLeftClick;
bool inputEngine::mouseRightClick;
bool inputEngine::mouseClicked;
float inputEngine::mouseX;
float inputEngine::mouseY;
mouseClicks inputEngine::mouseClick;
//std::string inputEngine::keyPressed; 
bool inputEngine::textInputStarted;

inputEngine::inputEngine()  // constructor
{
    keyInputReceived = false;
    mouseX = 0.0f;
    mouseY = 0.0f;
    mouseClick = NOCLICK;
    mouseClicked = false;
    mouseLeftClick = false;
    mouseRightClick = false;
	inputMap = INNO;
    textInputStarted = false;
    setup();
}

inputEngine::~inputEngine()  // destructor
{
}

/*boost::shared_ptr<GUISystem> inputEngine::getGui()  // retrieves the value of gui
{
  return (gui);
}
void inputEngine::setGui(boost::shared_ptr<GUISystem> set)  // sets the value of gui
{
    gui = set;
}*/

bool inputEngine::getKeyInputReceived()  // retrieves the value of keyInputReceived
{
    return (keyInputReceived);
}
void inputEngine::setKeyInputReceived(bool set)  // sets the value of keyInputReceived
{
   keyInputReceived = set;
}
 
SDL_Event inputEngine::getInputEvent()  // retrieves the value of inputEvent
{
    return (inputEvent);
}
void inputEngine::setInputEvent(SDL_Event set)  // sets the value of inputEvent
{
    inputEvent = set;
}

std::string inputEngine::getKeyPressed()  // retrieves the value of keyPressed
{
    return(keyPressed);
}
void inputEngine::setKeyPressed(std::string set)
{
    keyPressed = set;
}

inputMaps inputEngine::getInputMap()  // retrieves the value of inputMap 
{
    return(inputMap);
}
void inputEngine::setInputMap(inputMaps set)  // sets the value of inputMap 
{
    inputMap = set;
}

inputWorkQueues inputEngine::getInputWorkQueue()  // retrieves the value of inputWorkQueue
{
    return (inputWorkQueue);
}
void inputEngine::setInputWorkQueue(inputWorkQueues set)  // sets the value of inputWorkQueue
{
    inputWorkQueue = set;
}

std::vector<userInput> inputEngine::getUInput()  // retrieves the value of uInput
{
    return (uInput);
}
void inputEngine::setUInput(std::vector<userInput> set)  // sets the value of uInput
{
    uInput = set;
}

float inputEngine::getMouseX()  // retrieves the value of mouseX
{
    return (mouseX);
}
void inputEngine::setMouseX(float set)  // sets the value of mouseX
{
    mouseX = set;
}

float inputEngine::getMouseY()  // retrieves the value of mouseY
{
    return (mouseY);
}
void inputEngine::setMouseY(float set)  // sets the value of mouseY
{
    mouseY = set;
}

mouseClicks inputEngine::getMouseClick()  // retrieves the value of mouseClick
{
    return (mouseClick);
}
void inputEngine::setMouseClicks(mouseClicks set)  // sets the value of mouseClicks
{
    mouseClick = set;
}

bool inputEngine::getMouseClicked()  // retrieves the value of mouseClicked
{
    return (mouseClicked);
}
void inputEngine::setMouseClicked(bool set)  // sets the value of mouseClicked
{
    mouseClicked = set;
}

bool inputEngine::setup()   // sets up and initializes the Input System
{
//  mDebugOverlay = OverlayManager::getSingleton().getByName("Core/DebugOverlay");

    boost::shared_ptr<loader> load = loader::Instance();

    uInput = load->loadUserInputs();  // loads user defined input from file.
    
    uInput[0].setActive(true);
    logMsg("*** Initializing SDL Input System ***");
    SDL_ShowCursor(0);  // Hides the SDL Cursor in favor of the MyGUI Cursor

    return true;
}

bool inputEngine::destroy()  // destroys the OIS Input System and related objects
{
    return true;
}

inputMaps inputEngine::keyMap()  // maps value of keyPressed string to inputMap
{
//    exit(0);
    if (keyPressed == uInput[0].getKeyUp())
    {
//        exit(0);
        return(INUP);
    }
    else if (keyPressed == uInput[0].getKeyDown())
    {
        return(INDOWN);
    }
    else if (keyPressed == uInput[0].getKeyLeft())
    {
        return(INLEFT);
    }
    else if (keyPressed == uInput[0].getKeyRight())
    {
        return(INRIGHT);
    }
    else if (keyPressed == uInput[0].getKeyUpLeft())
    {
        return(INUPLEFT);
    }
    else if (keyPressed == uInput[0].getKeyUpRight())
    {
        return(INUPRIGHT);
    }
    else if (keyPressed == uInput[0].getKeyDownLeft())
    {
        return(INDOWNLEFT);
    }
    else if (keyPressed == uInput[0].getKeyDownRight())
    {
        return(INDOWNRIGHT);
    }
    else if (keyPressed == uInput[0].getKeyPassSteal())
    {
        return(INPASSSTEAL);
    }
    else if (keyPressed == uInput[0].getKeyShootBlock())
    {
        return(INSHOOTBLOCK);
    }
    else if (keyPressed == uInput[0].getKeyPause())
    {
        return(INPAUSE);
    }
    else if (keyPressed == uInput[0].getKeyStartSelect())
    {
        return(INSTARTSELECT);
    }
    else if (keyPressed == uInput[0].getKeyQuit())
    {
        logMsg("keyQuit = " +uInput[0].getKeyQuit());
	return(INQUIT);
    }
    else if (keyPressed == "Backspace")
    {
//        logMsg("keyQuit = " +uInput[0].getKeyQuit());
//        exit(0);
        return(INBACKSPACE);
    }
    else
    {
        return(INNO);
    }
}

bool inputEngine::processInput()  // processes all input
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

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
    int motion = SDL_EventState(SDL_FINGERMOTION, SDL_QUERY);
    logMsg ("motion = " +convert->toString(motion));
//    exit(0);
    if (!textInputStarted)
    {
//        SDL_StartTextInput();
        textInputStarted = true;
    }
    else
    {
        
    }
    
    while (SDL_PollEvent(&inputEvent))
    {
//        exit(0);
        int numTouch = SDL_GetNumTouchDevices();
        logMsg ("numTouch = " +convert->toString(numTouch));
//        exit(0);

//          Ogre::LogManager::getSingletonPtr()->logMessage("Crash??");

        switch (inputEvent.type)
        {
            case SDL_FINGERMOTION:
                logMsg("Motion!");
//                exit(0);
                // processes touch input
                if (processTouchInput())
                {
                    return false;
                }
            break;
            case SDL_FINGERDOWN:
                logMsg("Finger Down!");
//                logMsg("tfinger.x = " +convert->toString(inputEvent.tfinger.x*render->getWindowWidth()));
                logMsg("tfinger.y = " +convert->toString(inputEvent.tfinger.y));
//                exit(0);
                // processes touch input
                if (processTouchInput() == false)
                {
                    return false;
                }
            break;
            case SDL_FINGERUP:
                logMsg("Finger Up!");
//                exit(0);
                // processes touch input
                if (processTouchInput() == false)
                {
                    return false;
                }
            break;
            case SDL_MULTIGESTURE:
                logMsg("Multigesture!");
            //    exit(0);
                // processes touch input
                if (processTouchInput() == false)
                {
                    return false;
                }
            break;
            case SDL_KEYDOWN:
            break;
            case SDL_TEXTINPUT:
                keyPressed = "";
                
                if (processKeyInput(true))
                {
                    
//                    return false;
                }
                logMsg("Key Pressed! == " +keyPressed);
//                exit(0);
                if (keyPressed != "")
                {
                    logMsg("keyPressed == " +keyPressed);
//                    exit(0);
                    inputMaps inputMap = keyMap();
                    inputWorkQueue.push_back(inputMap);
                }
//                exit(0);
            break;

            case SDL_MOUSEMOTION:
            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
            case SDL_MOUSEWHEEL:
                logMsg("Mouse!");
                // processes mouse input
                if (processMouseInput() == false)
                {
                    return false;
                }
               // exit(0);
            break;
            case SDL_CONTROLLERAXISMOTION:
            case SDL_CONTROLLERBUTTONDOWN:
            case SDL_CONTROLLERBUTTONUP:
            case SDL_CONTROLLERDEVICEADDED:
            case SDL_CONTROLLERDEVICEREMOVED:
            case SDL_CONTROLLERDEVICEREMAPPED:
                logMsg("Controller!");
                // processes gamepad input
                if (processGamepadInput() == false)
                {
                    return false;
                }
                //exit(0);
            break;
            case SDL_QUIT:
            break;
            default:
            break;
        }
    }
//    SDL_StopTextInput();
//    exit(0);
    processMouseInput();

    return true;
}

bool inputEngine::processKeyInput(bool textInput)  // processes unbuffered keyboard input
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<GUISystem> gui = GUISystem::Instance();
//	logMsg("Processing keyboard input");

    logMsg("key == " +convert->toString(inputEvent.key.keysym.sym));
    keyPressed = inputEvent.text.text;
    logMsg("key = " +keyPressed);
//    exit(0);
    if (MyGUI::InputManager::getInstance().isFocusKey())	// checks if a MyGUI widget has key focus
    {
        logMsg("Crash?");
//		exit(0);
//        keyPressed = "";
        switch (inputEvent.key.keysym.sym)
        {
            case SDLK_sC:
                logMsg("S!");
                keyPressed = "S";
                exit(0);
            break;
            case SDLK_RETURN:
//            case SDLK_AC_BACK:
                logMsg("Return!");
                keyPressed = "Return";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Return, MyGUI::KeyCode::Return);
            break;
            case SDLK_BACKSPACE:
                logMsg("Backspace!");
//                 exit(0);
                keyPressed = "Backspace";
//                gui->menuReceiveKeyPress(keyPressed); // sends input to menu key input processing function
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Backspace, 0);
            break;
            case SDLK_ESCAPE:
                logMsg("Escape!");
                keyPressed = "Escape";
//              exit(0);
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Escape, 0);
            break;
            case SDLK_TAB:
                logMsg("Tab!");
                keyPressed = "Tab";
//                exit(0);
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Tab, 0);
            break;
            case SDLK_SPACE:
                logMsg("Space!");
                keyPressed = "Space";
//              MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Space, ' ');
            break;
            case SDLK_LSHIFT:
                keyPressed = "LeftShift";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::LeftShift, 0);
            break;
            case SDLK_LCTRL:
                keyPressed = "LeftControl";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::LeftControl, 0);
            break;
            case SDLK_LALT:
                keyPressed = "LeftAlt";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::LeftAlt, 0);
            break;
            case SDLK_LGUI:
                keyPressed = "LeftGUI";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::LeftWindows, 0);
            break;
            case SDLK_RSHIFT:
                keyPressed = "RightShift";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightShift, 0);
            break;
            case SDLK_RCTRL:
                keyPressed = "RightControl";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightControl, 0);
            break;
            case SDLK_RALT:
                keyPressed = "RightAlt";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightAlt, 0);
            break;
            case SDLK_RGUI:
                keyPressed = "RightGUI";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightWindows, 0);
            break;
            case SDLK_MENU:
                keyPressed = "Menu";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightWindow, 0);
            break;
            case SDLK_CAPSLOCK:
                keyPressed = "CapsLock";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Capital, 0);
            break;
            case SDLK_F1:
                keyPressed = "F1";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F1, 0);
            break;
            case SDLK_F2:
                keyPressed = "F2";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F2, 0);
            break;
            case SDLK_F3:
                keyPressed = "F3";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F3, 0);
            break;
            case SDLK_F4:
                keyPressed = "F4";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F4, 0);
            break;
            case SDLK_F5:
                keyPressed = "F5";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F5, 0);
            break;
            case SDLK_F6:
                keyPressed = "F6";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F6, 0);
            break;
            case SDLK_F7:
                keyPressed = "F7";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F7, 0);
            break;
            case SDLK_F8:
                keyPressed = "F8";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F8, 0);
            break;
            case SDLK_F9:
                keyPressed = "F9";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F9, 0);
            break;
            case SDLK_F10:
                keyPressed = "F10";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F10, 0);
            break;
            case SDLK_F11:
                keyPressed = "F11";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F11, 0);
            break;
            case SDLK_F12:
                keyPressed = "F12";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F12, 0);
            break;
            case SDLK_UP:
                keyPressed = "Up";
//                logMsg("Up!");
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ArrowUp, 0);
            break;
            case SDLK_DOWN:
                keyPressed = "Down";
//                 MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ArrowDown, 0);
            break;
            case SDLK_LEFT:
                keyPressed = "Left";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ArrowLeft, 0);
            break;
            case SDLK_RIGHT:
                keyPressed = "Right";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ArrowRight, 0);
            break;
            case SDLK_SCROLLLOCK:
                keyPressed = "ScrollLock";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ScrollLock, 0);
            break;
            case SDLK_HOME:
                keyPressed = "Home";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Home, 0);
            break;
            case SDLK_PAUSE:
                keyPressed = "Pause";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Pause, 0);
            break;
            case SDLK_INSERT:
                keyPressed = "Insert";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Insert, 0);
            break;
            case SDLK_PAGEUP:
                keyPressed = "PageUp";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::PageUp, 0);
            break;
            case SDLK_DELETE:
                keyPressed = "Delete";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Delete, 0);
            break;
            case SDLK_END:
                keyPressed = "End";
//            MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::End, 0);
            break;
            case SDLK_PAGEDOWN:
                keyPressed = "PageDown";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::PageDown, 0);
            break;
            case SDLK_NUMLOCKCLEAR:
                keyPressed = "NumLockClear";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::NumLock, 0);
            break;
            case SDLK_KP_DIVIDE:
                keyPressed = "Divide";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Divide, 0);
            break;
            case SDLK_KP_MULTIPLY:
                keyPressed = "Multiply";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Multiply, 0);
            break;
            case SDLK_KP_MINUS:
                keyPressed = "Minud";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Minus, 0);
            break;
            case SDLK_KP_ENTER:
                keyPressed = "Enter";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::NumpadEnter, 0);
            break;
            case SDLK_KP_0:
                keyPressed = "0";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad0, '0');
            break;
            case SDLK_KP_1:
                keyPressed = "1";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad1, '1');
            break;
            case SDLK_KP_2:
                keyPressed = "2";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad2, '2');
            break;
            case SDLK_KP_3:
                keyPressed = "3";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad3, '3');
            break;
            case SDLK_KP_4:
                keyPressed = "4";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad4, '4');
            break;
            case SDLK_KP_5:
                keyPressed = "5";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad5, '5');
            break;
            case SDLK_KP_6:
                keyPressed = "6";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad6, '6');
            break;
            case SDLK_KP_7:
                keyPressed = "7";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad7, '7');
            break;
            case SDLK_KP_8:
                keyPressed = "8";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad8, '8');
            break;
            case SDLK_KP_9:
                keyPressed = "9";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad9, '9');
            break;
            case SDLK_6:
                keyPressed = "";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Enum(6), '6');
            break;
            default:
            //    MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Enum(inputEvent.key.keysym.sym), inputEvent.key.keysym.sym);
            break;
            
        }
    }
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
    keyInputReceived = true;
//    keyPressed = "";
//	logMsg("Keyboard Input Processed");
    // Return true to continue rendering
    return true;
}

bool inputEngine::processTextInput()  // reads in text input
{
    return (true);
}
bool inputEngine::processMouseInput()  // processes the unbuffered mouse input
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

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
/*    state = SDL_GetMouseState(NULL, NULL)&SDL_TOUCH_MOUSEID;
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
        else if (state == 0 && mouseLeftClick == 1) //if (SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1) == 0)
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
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

    int state = -1;
    SDL_TouchFingerEvent touchMotion;

    SDL_PumpEvents();
    int numDevs = SDL_GetNumTouchDevices();
    logMsg("numTouchDevices = " +convert->toString(numDevs));
    int evtState = 0;
    evtState = SDL_EventState(SDL_FINGERMOTION, SDL_QUERY);
    logMsg("evtState FINGERMOTION = " +convert->toString(evtState));
    evtState = 0;
    evtState = SDL_EventState(SDL_FINGERDOWN, SDL_QUERY);
    logMsg("evtState FINGERDOWN = " +convert->toString(evtState));
    SDL_Finger *finger = SDL_GetTouchFinger(0,0);
//    logMsg("Finger = " +convert->toString(finger));

    evtState = 0;
    evtState = SDL_EventState(SDL_FINGERUP, SDL_QUERY);
    if (evtState > 0)
    {
        logMsg("evtState FINGERUP = " +convert->toString(evtState));
    //    exit(0);
    }
    
//    exit(0);
    mouseX = inputEvent.tfinger.x*getWindowWidth();
    mouseY = inputEvent.tfinger.y*getWindowHeight();
    logMsg("touch X == " +convert->toString(mouseX));
    logMsg("touch Y == " +convert->toString(mouseY));

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
    if (SDL_EventState(SDL_FINGERUP, SDL_QUERY) == 1) //if (SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1) == 0)
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
