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

#ifndef _LOGGING_H_
#define _LOGGING_H_
 
#include <string>
//#include "boost/shared_ptr.hpp"

#include "utilities/typedefs.h"

class logging
{
public:

	~logging();
//    static logging *Instance();
    static loggingSharedPtr Instance();

    bool getOgreRootInitialized() const;  // retrieves the value of ogreRootInitialized
    void setOgreRootInitialized(const bool &set);  // sets the value of ogreRootInitialized

    void logMessage(const std::string &msg);
protected:
    logging();
    bool ogreRootInitialized;
    logging(const logging&);
    logging& operator= (const logging&);
private:
//    static logging *pInstance;
    static loggingSharedPtr pInstance;
	 
};
 
#ifndef logMsg
#define logMsg logging::Instance()->logMessage
#endif

#endif
