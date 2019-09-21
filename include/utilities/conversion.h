/***************************************************************************
 *   Copyright (C) 1999 - 2019 by Mike McLean                              *
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
 
#ifndef _CONVERSION_H_
#define _CONVERSION_H_

#define WIN32_LEAN_AND_MEAN
#include "enet/enet.h"

#include <algorithm>
//#include "Ogre.h"

#include "engine/networkengine.h"

#include <iostream>
#include <sstream>
#include <iomanip>

#include <limits>

//#include <boost/lexical_cast.hpp>
//#include <boost/shared_ptr.hpp>

#include "OgreVector3.h"
#include "SDL.h"
#include "ai/steering.h"
#include "utilities/enums.h"

//template<class T, class TL>
class conversion  // class for conversion between data types
{
    public:
        conversion();  // constructor
        ~conversion();  // destructor

        // convert to string
        std::string toString(char *data);  // converts char * data to string
//        std::string toString(char **data);  // converts char ** data to string
        std::string toString(const char *data);  // converts const char * data to string
        std::string toString(const int &data);  // converts int data to string
        std::string toString(const long &data);  // converts long data to string
        std::string toString(const unsigned int &data); // converts unsigned int data to string
        std::string toString(const unsigned long &data);  // converts unsigned long data to string
        std::string toString(const enet_uint8 *data);  // converts const enet_uint8 * data to string
        std::string toString(const float &data);  // converts float data to string
        std::string toString(const double &data);  // converts double data to string
        std::string toString(void *data);  // converts void * data to string
        std::string toString(const Ogre::Vector3 &data);  // converts Ogre::Vector3 data to string
        std::string toString(const OpenSteer::Vec3 &data);  // converts OpenSteer::Vec3 data to string
#ifdef _WIN64
        std::string toString(const size_t &data);  // converts size_t data to string
#endif
#ifdef BTOGRE_MYGUI_ENABLED
        std::string toString(const btVector3 &data); // converts btVector3 data to string
#endif
        std::string toString(const playerPositions &data); // converts playerPositions data to string
        std::string toString(const teamTypes &data); // converts teamTypes data to string
        std::string toString(const bool &data); // converts bool data to string
        std::string toString(const inputKeyMaps &data); // converts inputKeyMaps data to string
        std::string toString(const inputInGameMaps &data); // converts inputInGameMaps data to string
        std::string toString(const activeMenus &data); // converts activeMenus data to string
        std::string toString(const directions &data); // converts directions data to string
        std::string toString(const inputTypes &data); // converts inputTypes data to string
        std::string toString(const _ENetEventType &data);  // converts ENetEventType data to string

        // convert to char
        char toChar(const std::string &data);  // converts from std::string to char
        char toChar(const char *data);  // converts from char * to char
//        char toChar(char **data);  // converts from char ** to char
        //char toChar(const char *data);  // converts from const char * to char
        char toChar(const int &data);  // converts from int to char
        char toChar(const long &data);  // converts from long to char
        char toChar(const unsigned int &data);  // converts from unsigned int to char
        char toChar(const unsigned long &data);  // converts from unsigned long to char
        char toChar(const enet_uint8 *data);  // converts from enet_uint8 * to char
        char toChar(const float &data);  // converts from float to char
        char toChar(const double &data);  // converts from double to char
        char toChar(void *data);  // converts from void * to char
        
        // convert to char *
/*        char *toCharPtr(const std::string &data);  // converts from std::string to char *
        char *toCharPtr(const char &data);  // converts from char to char *
//        char *toCharPtr(char **data);  // converts from char ** to char *
        char *toCharPtr(const char *data);  // converts from const char * to char *        
        char *toCharPtr(const int &data);  // converts from int to char *
        char *toCharPtr(const long &data);  // converts from long to char *
        char *toCharPtr(const unsigned long &data);  // converts from unsigned long to char *
        char *toCharPtr(const enet_uint8 *data);  // converts from enet_uint8 * to char *
        char *toCharPtr(const float &data);  // converts from float to char *
        char *toCharPtr(const double &data);  // converts from double to char *
        char *toCharPtr(size_t &data);  // converts from size_t to char *
        char *toCharPtr(const void *data);  // converts from void * to char *
*/
        // convert to char **
/*        char **toCharPtrPtr(const std::string &data);  // converts from std::string to char **
        char **toCharPtrPtr(const char &data);  // converts from char to char **
        char **toCharPtrPtr(char *data);  // converts from char * to char **
        char **toCharPtrPtr(const char *data);  // converts from const char * to char **        
        char **toCharPtrPtr(const int &data);  // converts from int to char **
        char **toCharPtrPtr(const long &data);  // converts from long to char **
        char **toCharPtrPtr(const unsigned long &data);  // converts from unsigned long to char **
        char **toCharPtrPtr(const enet_uint8 *data);  // converts from enet_uint8 * to char **
        char **toCharPtrPtr(const float &data);  // converts from float to char **
        char **toCharPtrPtr(const double &data);  // converts from double to char **
        char **toCharPtrPtr(size_t &data);  // converts from size_t to char **
        char **toCharPtrPtr(const void *data);  // converts from void * to char **
*/
        // convert to const char *
/*        const char *toConstCharPtr(const std::string &data);  // converts from std::string to const char *
        const char *toConstCharPtr(const char &data);  // converts from char to const char *
        const char *toConstCharPtr(char *data);  // converts from char * to const char *
//        const char *toConstCharPtr(char **data);  // converts from char ** to const char *
        const char *toConstCharPtr(const int &data);  // converts from int to const char *
        const char *toConstCharPtr(const long &data);  // converts from long to const char *
        const char *toConstCharPtr(const unsigned long &data);  // converts from unsigned long to const char *
        const char *toConstCharPtr(const enet_uint8 *data);  // converts from enet_uint8 * to const char *
        const char *toConstCharPtr(const float &data);  // converts from float to const char *
        const char *toConstCharPtr(const double &data);  // converts from double to const char *
        const char *toConstCharPtr(size_t &data);  // converts from size_t to const char *
        const char *toConstCharPtr(const void *data);  // converts from void * to const char *
*/

        // convert to int
        int toInt(const std::string &data);  // converts from std::string to int
        int toInt(const char &data);  // converts from char to int
        int toInt(char *data);  // converts from char * to int
//        int toInt(char **data);  // converts from char ** to int
        //int toInt(const char *data);  // converts from const char * to int
        int toInt(const long &data);  // converts from long to int
        int toInt(const unsigned int &data);  // converts from unsigned int to int
        int toInt(const unsigned long &data);  // converts from unsigned long to int
        int toInt(const enet_uint8 *data);  // converts from enet_uint8 * to int
        int toInt(const float &data);  // converts from float to int
        int toInt(const double &data);  // converts from double to int
        //int toInt(size_t &data);  // converts from size_t to int
        int toInt(void *data);  // converts from void * to int
        
        // convert to long
        long toLong(const std::string &data);  // converts from std::string to long
        long toLong(const char &data);  // converts from char to long
        long toLong(char *data);  // converts from char * to long
//        long toLong(char **data);  // converts from char ** to long
        //long toLong(const char *data);  // converts from const char * to long
        long toLong(const int &data);  // converts from int to long
        long toLong(const unsigned int &data);  // converts from unsigned int to long
        long toLong(const unsigned long &data);  // converts from unsigned long to long
        long toLong(const enet_uint8 *data);  // converts from enet_uint8 * to long
        long toLong(const float &data);  // converts from float to long
        long toLong(const double &data);  // converts from double to long
        //long toLong(size_t &data);  // converts from size_t to long
        long toLong(void *data);  // converts from void * to long

        // converts to unsigned int
        unsigned int toUnsignedInt(const std::string &data);  // converts from std::string to unsigned int
        unsigned int toUnsignedInt(const char &data);  // converts from char to unsigned int
        unsigned int toUnsignedInt(char *data);  // converts from char * to unsigned int
//        unsigned int toUnsignedInt(char **data);  // converts from char ** to unsigned int
        unsigned int toUnsignedInt(const char *data);  // converts from const char * to unsigned int
        unsigned int toUnsignedInt(const long &data);  // converts from long to unsigned int
        unsigned int toUnsignedInt(const int &data);  // converts from int to unsigned int
        unsigned int toUnsignedInt(const unsigned long &data);  // converts from unsigned long to unsigned int
        unsigned int toUnsignedInt(const enet_uint8 *data);  // converts from enet_uint8 * to unsigned int
        unsigned int toUnsignedInt(const float &data);  // converts from float to unsigned int
        unsigned int toUnsignedInt(const double &data);  // converts from double to unsigned int
        //unsigned int toUnsignedInt(size_t &data);  // converts from size_t to unsigned int
        unsigned int toUnsignedInt(void *data);  // converts from void * to unsigned int

        // converts to unsigned long
        unsigned long toUnsignedLong(const std::string &data);  // converts from std::string to unsigned long
        unsigned long toUnsignedLong(const char &data);  // converts from char to unsigned long
        unsigned long toUnsignedLong(char *data);  // converts from char * to unsigned long
//        unsigned long toUnsignedLong(char **data);  // converts from char ** to unsigned long
        unsigned long toUnsignedLong(const char *data);  // converts from const char * to unsigned long
        unsigned long toUnsignedLong(const long &data);  // converts from long to unsigned long
        unsigned long toUnsignedLong(const int &data);  // converts from int to unsigned long
        unsigned long toUnsignedLong(const unsigned int &data);  // converts from unsigned int to unsigned long
        unsigned long toUnsignedLong(const enet_uint8 *data);  // converts from enet_uint8 * to unsigned long
        unsigned long toUnsignedLong(const float &data);  // converts from float to unsigned long
        unsigned long toUnsignedLong(const double &data);  // converts from double to unsigned long
        //unsigned long toUnsignedLong(size_t &data);  // converts from size_t to unsigned long
        unsigned long toUnsignedLong(void *data);  // converts from void * to unsigned long

        // convert to float
        float toFloat(const std::string &data);  // converts from std::string to float
        float toFloat(const char &data);  // converts from char to float
        float toFloat(char *data);  // converts from char * to float
//        float toFloat(char **data);  // converts from char ** to float
        //float toFloat(const char *data);  // converts from const char * to float
        float toFloat(const int &data);  // converts from int to float
        float toFloat(const long &data);  // converts from long to float
        float toFloat(const unsigned int &data);  // converts from unsigned int to float
        float toFloat(const unsigned long &data);  // converts from unsigned long to float
        float toFloat(const enet_uint8 *data);  // converts from enet_uint8 * to float
        float toFloat(const double &data);  // converts from double to float
        //float toFloat(size_t &data);  // converts from size_t to float
        float toFloat(void *data);  // converts from void * to float
        
        // convert to double
        double toDouble(const std::string &data);  // converts from std::string to double
        double toDouble(const char &data);  // converts from char to double
        double toDouble(char *data);  // converts from char * to double
//        double toDouble(char **data);  // converts from char ** to double
        //double toDouble(const char *data);  // converts from const char * to double
        double toDouble(const int &data);  // converts from int to double
        double toDouble(const long &data);  // converts from long to double
        double toDouble(const unsigned int &data);  // converts from unsigned int to double
        double toDouble(const unsigned long &data);  // converts from unsigned long to double
        double toDouble(const enet_uint8 *data);  // converts from enet_uint8 * to double
        double toDouble(const float &data);  // converts from float to double
        //double toDouble(size_t &data);  // converts from size_t to double
        double toDouble(void *data);  // converts from void * to double
        
        // convert to enet_uint8 *
/*        enet_uint8 * toEnet_uint8Ptr(const std::string &data);  // converts from std::string to enet_uint8 *
        enet_uint8 * toEnet_uint8Ptr(const char &data);  // converts from char to enet_uint8 *
        enet_uint8 * toEnet_uint8Ptr(char *data);  // converts from char * to enet_uint8 *
//        enet_uint8 * toEnet_uint8Ptr(char **data);  // converts from char ** to enet_uint8 *
        enet_uint8 * toEnet_uint8Ptr(const char *data);  // converts from const char * to enet_uint8 *
        enet_uint8 * toEnet_uint8Ptr(const int &data);  // converts from int to enet_uint8 *
        enet_uint8 * toEnet_uint8Ptr(const long &data);  // converts from long to enet_uint8 *
        enet_uint8 * toEnet_uint8Ptr(const unsigned long &data);  // converts from unsigned long to enet_uint8 *
        enet_uint8 * toEnet_uint8Ptr(const double &data);  // converts from double to enet_uint8 *
        enet_uint8 * toEnet_uint8Ptr(const float &data);  // converts from float to enet_uint8 *
        enet_uint8 * toEnet_uint8Ptr(size_t &data);  // converts from size_t to enet_uint8 *
        enet_uint8 * toEnet_uint8Ptr(void *data);  // converts from void * to enet_uint8 *
*/
        // convert to size_t
/*        size_t toSize_t(const std::string &data);  // converts from std::string to size_t
        size_t toSize_t(const char &data);  // converts from char to size_t
        size_t toSize_t(char *data);  // converts from char * to size_t
//        size_t toSize_t(char **data);  // converts from char ** to size_t
        //size_t toSize_t(const char *data);  // converts from const char * to size_t
        size_t toSize_t(const int &data);  // converts from int to size_t
        size_t toSize_t(const long &data);  // converts from long to size_t
        size_t toSize_t(const unsigned long &data);  // converts from unsigned long to size_t
        size_t toSize_t(const enet_uint8 *data);  // converts from enet_uint8 * to size_t
        size_t toSize_t(const float &data);  // converts from float to size_t
        size_t toSize_t(const double &data);  // converts from double to size_t
        size_t toSize_t(const void *data);  // converts from void * to size_t
*/

        // convert to void *
/*        void * voidPtr(const std::string &data);  // converts from std::string to void *
        void * voidPtr(const char &data);  // converts from char to void *
        void * voidPtr(char *data);  // converts from char * to void *
//        void * voidPtr(char **data);  // converts from char ** to void *
        void * voidPtr(const char *data);  // converts from const char * to void *
        void * voidPtr(const int &data);  // converts from int to void *
        void * voidPtr(const long &data);  // converts from long to void *
        void * voidPtr(const unsigned long &data);  // converts from unsigned long to void *
        void * voidPtr(const enet_uint8 *data);  // converts from enet_uint8 * to void *
        void * voidPtr(const float &data);  // converts from float to void *
        void * voidPtr(const double &data);  // converts from double to void *
        void * voidPtr(size_t &data);  // converts from void * to void *
*/
//        template <typename T>



        OpenSteer::Vec3 toOpenSteerVec3(const Ogre::Vector3 &vect);  // converts from Ogre::Vector3 to OpenSteer::Vec3

        Ogre::Vector3 toOgreVector3(const OpenSteer::Vec3 &vect); // converts from OpenSteer::Vec3 to Ogre::Vector3
#ifdef BTOGRE_MYGUI_ENABLED
        Ogre::Vector3 toOgreVector3(const btVector3 &vect); // converts from btVector3 to Ogre::Vector3
#endif

        
        // inputKm Maps conversion
        inputKeyMaps toInputKey(const std::string &data);  // converts from string to inputKeyMaps
        inputKeyMaps toInputKey(const SDL_Event &data);  // converts from SDL Key Scancode to inputKeyMaps
        
        inputGamePadMaps toInputGP(const std::string &data);  // converts from string to inputGamePadMaps
        
        inputTypes toInputType(const std::string &data);  // converts from string to inputTypes

    private:
    
/*    
    T toString(const T& x, TL y)
{
  std::ostringstream out;
  out << x;
  return out.str();
}
*/
};

#endif
