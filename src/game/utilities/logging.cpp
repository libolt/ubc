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

#include "Ogre.h"

#include "utilities/easylogging++.h"

//#include <boost/shared_ptr.hpp>

#include "utilities/logging.h"
#include "utilities/conversion.h"

#include "engine/renderengine.h"
INITIALIZE_EASYLOGGINGPP

sharedPtr<logging> logging::pInstance;

sharedPtr<logging> logging::Instance()
{
    if (pInstance == nullptr)  // is it the first call?
    {
        sharedPtr<logging> tInstance(new logging);
        pInstance = tInstance;

    }
    return pInstance; // address of sole instance
}

logging::logging()  // constructor
{
    ogreRootInitialized = false;
}
 
logging::~logging() = default;  // destructor

bool logging::getOgreRootInitialized() const  // retrieves the value of ogreRootInitialized
{
    return(ogreRootInitialized);
}
void logging::setOgreRootInitialized(const bool &set)  // sets the value of ogreRootInitialized
{
    ogreRootInitialized = set;
}
 
void logging::logMessage(const std::string &msg)  // logs a message to appropriate output
{
//    renderEngineSharedPtr render = renderEngine::Instance();

#ifdef __ANDROID__
    __android_log_print(ANDROID_LOG_DEBUG, "com.libolt.ubc", msg.c_str());
#else

/*    if (ogreRootInitialized)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage(msg);
    }
*/
    LOG(INFO) << msg;
#endif

}

