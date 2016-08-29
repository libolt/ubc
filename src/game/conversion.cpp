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

#include "conversion.h"
#include "logging.h"

boost::shared_ptr<conversion> conversion::pInstance;

boost::shared_ptr<conversion> conversion::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        boost::shared_ptr<conversion> tInstance(new conversion);
        pInstance = tInstance;
    }
    return pInstance; // returns the value of pInstance
}

conversion::conversion()  // constructor
{
    
}

/*conversion::~conversion()
{
}*/

// conversion to std::string
std::string conversion::toString( char *data)  // converts char * data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}
/*std::string conversion::toString(char **data)  // converts char ** data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}*/
std::string conversion::toString(const char *data)  // converts const char * data to string
{
    std::string strData;
//    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}
std::string conversion::toString(const int &data)  // converts int data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}
std::string conversion::toString(const enet_uint8 *data)  // converts enet_uint8 data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}
std::string conversion::toString(const long &data)  // converts long data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}
std::string conversion::toString(const unsigned int &data)  // converts unsigned int data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}

std::string conversion::toString(const unsigned long &data)  // converts unsigned long data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}
std::string conversion::toString(const float &data)  // converts float data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}
std::string conversion::toString(const double &data)  // converts double data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}
#ifdef _WIN64
std::string conversion::toString(const size_t &data)  // converts size_t data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}
#endif
std::string conversion::toString(const Ogre::Vector3 &data)  // converts Ogre::Vector3 data to string
{
    std::string strData;
    strData = "OgreVector3(" +boost::lexical_cast<std::string>(data.x) +"," +boost::lexical_cast<std::string>(data.y) +"," + boost::lexical_cast<std::string>(data.z) +")";
    return(strData);
}
std::string conversion::toString(const OpenSteer::Vec3 &data)  // converts Ogre::Vector3 data to string
{
    std::string strData;
    strData = "OpenSteerVec3(" +boost::lexical_cast<std::string>(data.x) +"," +boost::lexical_cast<std::string>(data.y) +"," + boost::lexical_cast<std::string>(data.z) +")";
    return(strData);
}
std::string conversion::toString(const btVector3 &data) // converts btVector3 data to string
{
    std::string strData;
    strData = "btVector3(" +boost::lexical_cast<std::string>(data.getX()) +"," +boost::lexical_cast<std::string>(data.getY()) +"," + boost::lexical_cast<std::string>(data.getZ()) +")";
    return(strData);
}
std::string conversion::toString(void *data)  // converts void * data to string
{
    std::string strData;
    return(strData);
}
std::string conversion::toString(const playerPositions &data) // converts playerPositions data to string
{
    std::string strData;
    switch (data)
    {
        case NONE:
            strData = "NONE";
        break;
        case PG:
            strData = "PG";
        break;
        case SG:
            strData = "SG";
        break;
        case SF:
            strData = "SF";
        break;
        case PF:
            strData = "PF";
        break;
        case C:
            strData = "C";
        break;
        default:
            strData = "";
        break;
    }
    
    return(strData);
}

std::string conversion::toString(const teamTypes &data) // converts teamTypes data to string
{
    std::string strData;
    switch (data)
    {
        case NOTEAM:
            strData = "No Team";
        break;
        case HOMETEAM:
            strData = "Home Team";
        break;
        case AWAYTEAM:
            strData = "Away Team";
        break;
        default:
            strData = "";
        break;
    }

    return (strData);
}

std::string conversion::toString(const bool &data) // converts bool data to string
{
    std::string strData;

    switch (data)
    {
        case true:
            strData = "True";
        break;
        case false:
            strData = "False";
        break;
        default:
            strData = "";
        break;
    }

    return (strData);
}

std::string conversion::toString(const inputKeyMaps &data) // converts bool data to string
{
    std::string strData;
    
    switch (data)
    {
        case INKEY_A:
                strData = "a";
//                logMsg("keyPressedScan === " +keyPressed);
//                exit(0);
            break;
            case INKEY_B:
                strData = "b";
//                exit(0);
            break;
            case INKEY_C:
                strData = "c";
//                exit(0);
            break;
            case INKEY_D:
                strData = "d";
//                exit(0);
            break;
            case INKEY_E:
                strData = "e";
//                exit(0);
            break;
            case INKEY_F:
                strData = "f";
                logMsg("F pressed!");
//                exit(0);
            break;  
            case INKEY_G:
                strData = "g";
//                exit(0);
            break;
            case INKEY_H:
                strData = "h";
//                exit(0);
            break;
            case INKEY_I:
                strData = "i";
//                exit(0);
            break;
            case INKEY_J:
                 strData = "j";
//                exit(0);
            break;   
            case INKEY_K:
                strData = "k";
//                exit(0);
            break;
            case INKEY_L:
                strData = "l";
//                exit(0);
            break;
            case INKEY_M:
                strData = "m";
//                exit(0);
            break;
            case INKEY_N:
                strData = "n";
//                exit(0);
            break;
            case INKEY_O:
                strData = "o";
//                exit(0);
            break;
            case INKEY_P:
                strData = "p";
//                exit(0);
            break;
            case INKEY_Q:
                strData = "q";
//                exit(0);
            break;
            case INKEY_R:
                strData = "r";
//                exit(0);
            break;
            case INKEY_S:
                 strData = "s";
//                exit(0);
            break;
            case INKEY_T:
                strData = "t";
//                exit(0);
            break;
            case INKEY_U:
                 strData = "u";
//                exit(0);
            break;
            case INKEY_V:
                strData = "v";
//                exit(0);
            break;
            case INKEY_W:
                strData = "w";
//                exit(0);
            break;
            case INKEY_X:
                 strData = "x";
//                exit(0);
            break;
            case INKEY_Y:
                strData = "y";
//                exit(0);
            break;
            case INKEY_Z:
                strData = "z";
//                exit(0);
            break;                     
            case INKEY_RETURN:
//            case SDLK_AC_BACK:
                logMsg("Return!");
                strData = "return";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Return, MyGUI::KeyCode::Return);
            break;
            case INKEY_BACKSPACE:
                logMsg("Backspace!");
//                 exit(0);
                strData = "backspace";
//                gui->menuReceiveKeyPress(keyPressed); // sends input to menu key input processing function
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Backspace, 0);
            break;
            case INKEY_ESCAPE:
                logMsg("Escape!");
                strData = "escape";
//              exit(0);
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Escape, 0);
            break;
            case INKEY_TAB:
                logMsg("Tab!");
                strData = "tab";
//                exit(0);
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Tab, 0);
            break;
            case INKEY_SPACE:
                logMsg("Space!");
                strData = "space";
//              MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Space, ' ');
            break;
            case INKEY_LSHIFT:
                strData = "lshift";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::LeftShift, 0);
            break;
            case INKEY_LCTRL:
                strData = "lctrl";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::LeftControl, 0);
            break;
            case INKEY_LALT:
                strData = "lalt";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::LeftAlt, 0);
            break;
            case INKEY_LGUI:
                strData = "lgui";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::LeftWindows, 0);
            break;
            case INKEY_RSHIFT:
                strData = "rshift";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightShift, 0);
            break;
            case INKEY_RCTRL:
                strData = "rctrl";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightControl, 0);
            break;
            case INKEY_RALT:
                strData = "ralt";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightAlt, 0);
            break;
            case INKEY_RGUI:
                strData = "rgui";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightWindows, 0);
            break;
            case INKEY_MENU:
                strData = "menu";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightWindow, 0);
            break;
            case INKEY_CAPSLOCK:
                strData = "capslock";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Capital, 0);
            break;
            case INKEY_F1:
                strData = "f1";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F1, 0);
            break;
            case INKEY_F2:
                strData = "f2";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F2, 0);
            break;
            case INKEY_F3:
                strData = "f3";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F3, 0);
            break;
            case INKEY_F4:
                strData = "f4";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F4, 0);
            break;
            case INKEY_F5:
                strData = "f5";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F5, 0);
            break;
            case INKEY_F6:
                strData = "f6";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F6, 0);
            break;
            case INKEY_F7:
                strData = "f7";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F7, 0);
            break;
            case INKEY_F8:
                strData = "f8";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F8, 0);
            break;
            case INKEY_F9:
                strData = "f9";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F9, 0);
            break;
            case INKEY_F10:
                strData = "f10";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F10, 0);
            break;
            case INKEY_F11:
                strData = "f11";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F11, 0);
            break;
            case INKEY_F12:
                strData = "f12";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F12, 0);
            break;
            case INKEY_UP:
                strData = "up";
//                logMsg("Up!");
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ArrowUp, 0);
            break;
            case INKEY_DOWN:
                strData = "down";
//                 MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ArrowDown, 0);
            break;
            case INKEY_LEFT:
                strData = "left";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ArrowLeft, 0);
            break;
            case INKEY_RIGHT:
                strData = "right";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ArrowRight, 0);
            break;
            case INKEY_SCROLLLOCK:
                strData = "scrolllock";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ScrollLock, 0);
            break;
            case INKEY_HOME:
                strData = "home";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Home, 0);
            break;
            case INKEY_PAUSE_BREAK:
                strData = "pause/break";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Pause, 0);
            break;
            case INKEY_INSERT:
                strData = "insert";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Insert, 0);
            break;
            case INKEY_PAGEUP:
                strData = "pageup";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::PageUp, 0);
            break;
            case INKEY_DELETE:
                strData = "delete";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Delete, 0);
            break;
            case INKEY_END:
                strData = "end";
//            MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::End, 0);
            break;
            case INKEY_PAGEDOWN:
                strData = "pagedown";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::PageDown, 0);
            break;
            case INKEY_NUMLOCK:
                strData = "numlock";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::NumLock, 0);
            break;
            case INKEY_DIVIDE:
                strData = "divide";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Divide, 0);
            break;
            case INKEY_MULTIPLY:
                strData = "multiply";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Multiply, 0);
            break;
            case INKEY_MINUS:
                strData = "minus";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Minus, 0);
            break;
            case INKEY_PLUS:
                strData = "plus";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Minus, 0);
            break;
            case INKEY_ENTER:
                strData = "enter";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::NumpadEnter, 0);
            break;
            case INKEY_0:
                strData = "0";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad0, '0');
            break;
            case INKEY_1:
                strData = "1";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad1, '1');
            break;
            case INKEY_2:
                strData = "2";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad2, '2');
            break;
            case INKEY_3:
                strData = "3";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad3, '3');
            break;
            case INKEY_4:
                strData = "4";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad4, '4');
            break;
            case INKEY_5:
                strData = "5";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad5, '5');
            break;
            case INKEY_6:
                strData = "6";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad6, '6');
            break;
            case INKEY_7:
                strData = "7";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad7, '7');
            break;
            case INKEY_8:
                strData = "8";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad8, '8');
            break;
            case INKEY_9:
                strData = "9";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad9, '9');
            break;
            
            default:
            logMsg("break");
            //    MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Enum(inputEvent.key.keysym.sym), inputEvent.key.keysym.sym);
            break;
        
    }
    logMsg("strData == " +strData);
//    exit(0);
    return (strData);
}

std::string conversion::toString(const activeMenus &data) // converts activeMenus data to string
{
    std::string strData;
    return (strData);
}

// convert to char
char conversion::toChar(const std::string &data)  // converts from std::string to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}
char conversion::toChar(const char *data)  // converts from char * to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}
/*char conversion::toChar(char **data)  // converts from char ** to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}*/
/*char conversion::toChar(const char *data)  // converts from const char * to char
{
    char charData;
//    charData = boost::lexical_cast<char>(data);
    return (charData);
}*/
char conversion::toChar(const int &data)  // converts from int to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}
char conversion::toChar(const long &data)  // converts from long to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}
char conversion::toChar(const unsigned int &data)  // converts from unsigned int to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}
char conversion::toChar(const unsigned long &data)  // converts from unsigned long to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}
char conversion::toChar(const enet_uint8 *data)  // converts from enet_uint8 * to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}
char conversion::toChar(const float &data)  // converts from float to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}
char conversion::toChar(const double &data)  // converts from double to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}
/*char conversion::toChar(size_t &data)  // converts from size_t to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}*/
char conversion::toChar(void  *data)  // converts from void * to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}

// convert to char *
/*char *conversion::toCharPtr(const std::string &data)  // converts from std::string to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(const char &data)  // converts from char to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(char **data)  // converts from char ** to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(const char *data)  // converts from const char * to char *
{
    char *charPtrData;
//    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(const int &data)  // converts from int to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(const long &data)  // converts from long to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(const unsigned long &data)  // converts from unsigned long to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(const enet_uint8 *data)  // converts from enet_uint8 * to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(const float &data)  // converts from float to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(const double &data)  // converts from double to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(size_t &data)  // converts from size_t to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(const void  *data)  // converts from void * to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}*/

// convert to char **
/*char **conversion::toCharPtrPtr(const std::string &data)  // converts from std::string to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(const char &data)  // converts from char to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(char *data)  // converts from char * to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(const char *data)  // converts from const char * to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(const int &data)  // converts from int to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(const long &data)  // converts from long to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(const unsigned long &data)  // converts from unsigned long to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(const enet_uint8 *data)  // converts from enet_uint8 * to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(const float &data)  // converts from float to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(const double &data)  // converts from double to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(size_t &data)  // converts from size_t to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(const void  *data)  // converts from void * to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
*/

// convert to const char *
/*const char *conversion::toConstCharPtr(const std::string &data)  // converts from std::string to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(const char &data)  // converts from char to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(char *data)  // converts from char * to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(char **data)  // converts from char ** to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(const int &data)  // converts from int to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(const long &data)  // converts from long to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(const unsigned long &data)  // converts from unsigned long to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(const enet_uint8 *data)  // converts from enet_uint8 * to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(const float &data)  // converts from float to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(const double &data)  // converts from double to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(size_t &data)  // converts from size_t to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(const void  *data)  // converts from void * to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}*/

// convert to int
int conversion::toInt(const std::string &data)  // converts from std::string to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}
int conversion::toInt(const char &data)  // converts from char to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}
int conversion::toInt(char *data)  // converts from char * to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}
/*int conversion::toInt(char **data)  // converts from char ** to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}*/
/*int conversion::toInt(const char *data)  // converts from const char * to int
{
    int intData;
//    intData = boost::lexical_cast<int>(data);
    return (intData);
}*/
int conversion::toInt(const long &data)  // converts from long to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}
int conversion::toInt(const unsigned int &data)  // converts from unsigned int to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}
int conversion::toInt(const unsigned long &data)  // converts from unsigned long to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}
int conversion::toInt(const enet_uint8 *data)  // converts from enet_uint8 * to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}
int conversion::toInt(const float &data)  // converts from float to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}
int conversion::toInt(const double &data)  // converts from double to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}
/*int conversion::toInt(size_t &data)  // converts from size_t to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}*/
int conversion::toInt(void  *data)  // converts from void * to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}

// convert to long
long toLong(const std::string &data)  // converts from std::string to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}
long toLong(const char &data)  // converts from char to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}
long toLong(char *data)  // converts from char * to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}
/*long toLong(char **data)  // converts from char ** to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}*/
/*long toLong(const char *data)  // converts from const char * to long
{
    long longData;
//    longData = boost::lexical_cast<long>(data);
    return (longData);
}*/
long toLong(const int &data)  // converts from int to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}
long toLong(const unsigned int &data)  // converts from unsigned int to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}
long toLong(const unsigned long &data)  // converts from unsigned long to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}
long toLong(const enet_uint8 *data)  // converts from enet_uint8 * to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}
long toLong(const float &data)  // converts from float to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}
long toLong(const double &data)  // converts from double to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}
/*long toLong(size_t &data)  // converts from size_t to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}*/
long toLong(void  *data)  // converts from void * to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}

// convert to unsigned int
unsigned int toUnsignedInt(const std::string &data)  // converts from std::string to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned int>(data);
    return (unsignedIntData);
}
unsigned int toUnsignedInt(const char &data)  // converts from char to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}
unsigned long toUnsignedInt(char *data)  // converts from char * to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}
/*unsigned int toUnsignedInt(char **data)  // converts from char ** to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}*/
/*unsigned int toUnsignedInt(const char *data)  // converts from const char * to unsigned int
{
    unsigned int unsignedIntData;
//    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}*/
unsigned int toUnsignedInt(const long &data)  // converts from long to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}
unsigned int toUnsignedInt(const int &data)  // converts from int to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}
unsigned int toUnsignedInt(const unsigned int &data)  // converts from unsigned int to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}

unsigned int toUnsignedInt(const enet_uint8 *data)  // converts from enet_uint8 * to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}
unsigned int toUnsignedInt(const float &data)  // converts from float to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}
unsigned int toUnsignedInt(const double &data)  // converts from double to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}
/*unsigned int toUnsignedInt(size_t &data)  // converts from size_t to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}*/
unsigned int toUnsignedInt(void  *data)  // converts from void * to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}

// convert to unsigned long
unsigned long toUnsignedLong(const std::string &data)  // converts from std::string to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}
unsigned long toUnsignedLong(const char &data)  // converts from char to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}
unsigned long toUnsignedLong(char *data)  // converts from char * to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}
/*unsigned long toUnsignedLong(char **data)  // converts from char ** to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}*/
/*unsigned long toUnsignedLong(const char *data)  // converts from const char * to unsigned long
{
    unsigned long unsignedLongData;
//    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}*/
unsigned long toUnsignedLong(const long &data)  // converts from long to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}
unsigned long toUnsignedLong(const int &data)  // converts from int to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}
unsigned long toUnsignedLong(const unsigned int &data)  // converts from unsigned int to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}

unsigned long toUnsignedLong(const enet_uint8 *data)  // converts from enet_uint8 * to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}
unsigned long toUnsignedLong(const float &data)  // converts from float to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}
unsigned long toUnsignedLong(const double &data)  // converts from double to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}
/*unsigned long toUnsignedLong(size_t &data)  // converts from size_t to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}*/
unsigned long toUnsignedLong(void  *data)  // converts from void * to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}

// convert to float
float conversion::toFloat(const std::string &data)  // converts from std::string to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}
float conversion::toFloat(const char &data)  // converts from char to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}
float conversion::toFloat(char *data)  // converts from char * to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}
/*float conversion::toFloat(char **data)  // converts from char ** to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}*/
/*float conversion::toFloat(const char *data)  // converts from const char * to float
{
    float floatData;
//    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}*/
float conversion::toFloat(const int &data)  // converts from int to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}
float conversion::toFloat(const long &data)  // converts from long to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}
float conversion::toFloat(const unsigned int &data)  // converts from unsigned int to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}
float conversion::toFloat(const unsigned long &data)  // converts from unsigned long to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}
float conversion::toFloat(const enet_uint8 *data)  // converts from enet_uint8 * to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}
float conversion::toFloat(const double &data)  // converts from double to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}
/*float conversion::toFloat(size_t &data)  // converts from size_t to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}*/
float conversion::toFloat(void  *data)  // converts from void * to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}

// convert to double
double conversion::toDouble(const std::string &data)  // converts from std::string to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}
double conversion::toDouble(const char &data)  // converts from char to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}
double conversion::toDouble(char *data)  // converts from char * to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}
/*double conversion::toDouble(char **data)  // converts from char ** to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}*/
/*double conversion::toDouble(const char *data)  // converts from const char * to double
{
    double doubleData;
//    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}*/
double conversion::toDouble(const int &data)  // converts from int to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}
double conversion::toDouble(const long &data)  // converts from long to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}
double conversion::toDouble(const unsigned int &data)  // converts from unsigned int to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}
double conversion::toDouble(const unsigned long &data)  // converts from unsigned long to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}
double conversion::toDouble(const enet_uint8 *data)  // converts from enet_uint8 * to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}
double conversion::toDouble(const float &data)  // converts from float to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}
/*double conversion::toDouble(size_t &data)  // converts from size_t to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}*/
double conversion::toDouble(void  *data)  // converts from void * to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}

// convert to enet_uint8 *
/*enet_uint8 * conversion::toEnet_uint8Ptr(const std::string &data)  // converts from std::string to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(const char &data)  // converts from char to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(char *data)  // converts from char * to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(char **data)  // converts from char ** to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(const char *data)  // converts from const char * to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
//    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(const int &data)  // converts from int to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(const long &data)  // converts from long to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(const unsigned long &data)  // converts from unsigned long to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(const double &data)  // converts from double to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(const float &data)  // converts from float to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(size_t &data)  // converts from size_t to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(const void  *data)  // converts from void * to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}*/

// convert to size_t

/*size_t conversion::toSize_t(const std::string &data)  // converts from std::string to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(const char &data)  // converts from char to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(char *data)  // converts from char * to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(char **data)  // converts from char ** to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(const char *data)  // converts from const char * to size_t
{
    size_t size_tData;
//    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(const int &data)  // converts from int to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(const long &data)  // converts from long to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(const unsigned long &data)  // converts from unsigned long to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(const enet_uint8 *data)  // converts from enet_uint8 * to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(const float &data)  // converts from float to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(const double &data)  // converts from double to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(const void  *data)  // converts from void * to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
*/

// convert to void *
/*void * conversion::voidPtr(const std::string &data)  // converts from std::string to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (const void PtrData);
}
void * conversion::voidPtr(const char &data)  // converts from char to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (const void PtrData);
}
void * conversion::voidPtr(char *data)  // converts from char * to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (const void PtrData);
}
void * conversion::voidPtr(char **data)  // converts from char ** to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (const void PtrData);
}
void * conversion::voidPtr(const char *data)  // converts from const char * to void *
{
    void *voidPtrData;
//    voidPtrData = boost::lexical_cast<void *>(data);
    return (const void PtrData);
}
void * conversion::voidPtr(const int &data)  // converts from int to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (const void PtrData);
}
void * conversion::voidPtr(const long &data)  // converts from long to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (const void PtrData);
}
void * conversion::voidPtr(const unsigned long &data)  // converts from unsigned long to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (const void PtrData);
}
void * conversion::voidPtr(const enet_uint8 *data)  // converts from enet_uint8 * to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (const void PtrData);
}
void * conversion::voidPtr(const float &data)  // converts from float to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (const void PtrData);
}
void * conversion::voidPtr(const double &data)  // converts from double to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (const void PtrData);
}
void * conversion::voidPtr(size_t &data)  // converts from void * to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (const void PtrData);
}*/

OpenSteer::Vec3 conversion::toOpenSteerVec3(const Ogre::Vector3 &vect)  // converts from Ogre::Vector3 to OpenSteer::Vec3
{

    OpenSteer::Vec3 vec3;

    vec3.x = vect[0];
    vec3.y = vect[1];
    vec3.z = vect[2];

    return (vec3);
}
Ogre::Vector3 conversion::toOgreVector3(const OpenSteer::Vec3 &vect) // converts from OpenSteer::Vec3 to Ogre::Vector3
{
    Ogre::Vector3 vector3;
    vector3[0] = vect.x;
    vector3[1] = vect.y;
    vector3[2] = vect.z;

    return (vector3);
}

Ogre::Vector3 conversion::toOgreVector3(const btVector3 &vect) // converts from btVector3 to Ogre::Vector3
{
    Ogre::Vector3 vector3;
    vector3[0] = vect.getX();
    vector3[1] = vect.getY();
    vector3[2] = vect.getZ();

    return (vector3);
}

inputKeyMaps conversion::toInputKey(const std::string &data)  // converts from string to inputKey
{
    inputKeyMaps inputKey;
    
    if (data == "a")
    {
        inputKey = INKEY_A;
    }
    else if (data == "b")
    {
        inputKey = INKEY_B;
    }
    else if (data == "c")
    {
        inputKey = INKEY_C;
    }
    else if (data == "d")
    {
        inputKey = INKEY_D;
    }
    else if (data == "e")
    {
        inputKey = INKEY_E;
    }
    else if (data == "f")
    {
        inputKey = INKEY_F;
    }
    else if (data == "g")
    {
        inputKey = INKEY_G;
    }
    else if (data == "h")
    {
        inputKey = INKEY_H;
    }
    else if (data == "i")
    {
        inputKey = INKEY_I;
    }
    else if (data == "j")
    {
        inputKey = INKEY_J;
    }
    else if (data == "k")
    {
        inputKey = INKEY_K;
    }
    else if (data == "l")
    {
        inputKey = INKEY_L;
    }
    else if (data == "m")
    {
        inputKey = INKEY_M;
    }
    else if (data == "n")
    {
        inputKey = INKEY_N;
    }
    else if (data == "o")
    {
        inputKey = INKEY_O;
    }
    else if (data == "p")
    {
        inputKey = INKEY_P;
    }
    else if (data == "q")
    {
        inputKey = INKEY_Q;
    }
    else if (data == "r")
    {
        inputKey = INKEY_R;
    }
    else if (data == "s")
    {
        inputKey = INKEY_S;
    }
    else if (data == "t")
    {
        inputKey = INKEY_T;
    }
    else if (data == "u")
    {
        inputKey = INKEY_U;
    }
    else if (data == "v")
    {
        inputKey = INKEY_V;
    }
    else if (data == "w")
    {
        inputKey = INKEY_W;
    }
    else if (data == "x")
    {
        inputKey = INKEY_X;
    }
    else if (data == "y")
    {
        inputKey = INKEY_Y;
    }
    else if (data == "z")
    {
        inputKey = INKEY_Z;
    }
    else if (data == "return")
    {
        inputKey = INKEY_RETURN;
    }
    else if (data == "backspace")
    {
        inputKey = INKEY_BACKSPACE;
    }
    else if (data == "escape")
    {
        inputKey = INKEY_ESCAPE;
    }
    else if (data == "tab")
    {
        inputKey = INKEY_TAB;
    }
    else if (data == "space")
    {
        inputKey = INKEY_SPACE;
    }
    else if (data == "lshift")
    {
        inputKey = INKEY_LSHIFT;
    }
    else if (data == "lctrl")
    {
        inputKey = INKEY_LCTRL;
    }
    else if (data == "lalt")
    {
        inputKey = INKEY_LALT;
    }
    else if (data == "lgui")
    {
        inputKey = INKEY_LGUI;
    }
    else if (data == "rshift")
    {
        inputKey = INKEY_RSHIFT;
    }
    else if (data == "rctrl")
    {
        inputKey = INKEY_RCTRL;
    }
    else if (data == "ralt")
    {
        inputKey = INKEY_RALT;
    }
    else if (data == "rgui")
    {
        inputKey = INKEY_RGUI;
    }
    else if (data == "menu")
    {
        inputKey = INKEY_MENU;
    }
    else if (data == "capslock")
    {
        inputKey = INKEY_CAPSLOCK;
    }
    else if (data == "f1")
    {
        inputKey = INKEY_F1;
    }
    else if (data == "f2")
    {
        inputKey = INKEY_F2;
    }
    else if (data == "f3")
    {
        inputKey = INKEY_F3;
    }
    else if (data == "f4")
    {
        inputKey = INKEY_F4;
    }
    else if (data == "f5")
    {
        inputKey = INKEY_F5;
    }
    else if (data == "f6")
    {
        inputKey = INKEY_F6;
    }
    else if (data == "f7")
    {
        inputKey = INKEY_F7;
    }
    else if (data == "f8")
    {
        inputKey = INKEY_F8;
    }
    else if (data == "f9")
    {
        inputKey = INKEY_F9;
    }
    else if (data == "f10")
    {
        inputKey = INKEY_F10;
    }
    else if (data == "f11")
    {
        inputKey = INKEY_F11;
    }
    else if (data == "f12")
    {
        inputKey = INKEY_F12;
    }
    else if (data == "up")
    {
        inputKey = INKEY_UP;
    }
    else if (data == "down")
    {
        inputKey = INKEY_DOWN;
    }
    else if (data == "left")
    {
        inputKey = INKEY_LEFT;
    }
    else if (data == "right")
    {
        inputKey = INKEY_RIGHT;
    }
    else if (data == "scrolllock")
    {
        inputKey = INKEY_SCROLLLOCK;
    }
    else if (data == "home")
    {
        inputKey = INKEY_HOME;
    }
    else if (data == "pause/break")
    {
        inputKey = INKEY_PAUSE_BREAK;
    }
    else if (data == "insert")
    {
        inputKey = INKEY_INSERT;
    }
    else if (data == "pageup")
    {
        inputKey = INKEY_PAGEUP;
    }
    else if (data == "delete")
    {
        inputKey = INKEY_DELETE;
    }
    else if (data == "end")
    {
        inputKey = INKEY_END;
    }
    else if (data == "pagedown")
    {
        inputKey = INKEY_PAGEDOWN;
    }
    else if (data == "divide")
    {
        inputKey = INKEY_DIVIDE;
    }
    else if (data == "multiply")
    {
        inputKey = INKEY_MULTIPLY;
    }
    else if (data == "minus")
    {
        inputKey = INKEY_MINUS;
    }
    else if (data == "plus")
    {
        inputKey = INKEY_PLUS;
    }
    else if (data == "enter")
    {
        inputKey = INKEY_ENTER;
    }
    else if (data == "0")
    {
        inputKey = INKEY_0;
    }
    else if (data == "1")
    {
        inputKey = INKEY_1;
    }
    else if (data == "2")
    {
        inputKey = INKEY_2;
    }
    else if (data == "3")
    {
        inputKey = INKEY_3;
    }
    else if (data == "4")
    {
        inputKey = INKEY_4;
    }
    else if (data == "5")
    {
        inputKey = INKEY_5;
    }
    else if (data == "6")
    {
        inputKey = INKEY_6;
    }
    else if (data == "7")
    {
        inputKey = INKEY_7;
    }
    else if (data == "8")
    {
        inputKey = INKEY_8;
    }
    else if (data == "9")
    {
        inputKey = INKEY_9;
    }
    
    return (inputKey);
}

inputGamePadMaps conversion::toInputGP(const std::string &data)  // converts from string to inputGamePadMaps
{
    inputGamePadMaps GPMap;
    // FIXME! Mapping is only stubbed out
/*        AXISUP0, 
        AXISDOWN0, 
        AXISLEFT0, 
        AXISRIGHT0, 
        AXISUPLEFT0, 
        AXISUPRIGHT0, 
        AXISDOWNLEFT0,
        AXISUP1, 
        AXISDOWN1, 
        AXISLEFT1, 
        AXISRIGHT1, 
        AXISUPLEFT1, 
        AXISUPRIGHT1, 
        AXISDOWNLEFT1,
        BUTTON0,
        BUTTON1,
        BUTTON2,
        BUTTON3,
        BUTTON4,
        BUTTON5,
        BUTTON6,
        BUTTON7,
        BUTTON8,
        INGP_NONE
*/
    return (GPMap); 
}
