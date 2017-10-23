/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
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
 
#ifndef _LOAD_HOOPS_H_
#define _LOAD_HOOPS_H_

#include <string>
#include <vector>
#include <unordered_map>
#include "load/load.h"

class loadHoops : public loader
{
    public:
    
        loadHoops();  // constructor
        ~loadHoops();  // destructor

        hoopStateUMSharedPtr  getHInstance();  // retrieves the value of hInstance
        void setHInstance(hoopStateUMSharedPtr  set);  // sets the value of hInstance
        bool checkIfHoopsLoaded();  // checks if the hooops have been loaded into hInstance

        // Hoops
        hoopStateUMSharedPtr  loadHoops();  // load hoop XML files
        stdStringVec loadHoopListFile(std::string fileName);  // load the list of hoops from hoops.xml
        hoopStateSharedPtr loadHoopFile(std::string fileName);  // loads data from the hoop XML files.

    private:
    
        static hoopStateUMSharedPtr  hInstance;
        static stdStringVec hoopFiles;  // stores list of hoop xml files
        static bool hoopFilesLoaded;

};

#endif
