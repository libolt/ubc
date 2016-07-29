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
    return (inputKey);
}
