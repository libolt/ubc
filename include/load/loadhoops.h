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
 
#ifndef _LOAD_HOOPS_H_
#define _LOAD_HOOPS_H_

#include <string>
#include <vector>
#include <unordered_map>
#include "load/load.h"
#include "utilities/typedefs.h"

class loadHoops : public loader
{
    public:
    
        loadHoops();  // constructor
        ~loadHoops();  // destructor

        hoopEntityMSharedPtr  getHInstance() const;  // retrieves the value of hInstance
        void setHInstance(const hoopEntityMSharedPtr  &set);  // sets the value of hInstance
        bool checkIfHoopsLoaded();  // checks if the hooops have been loaded into hInstance

        // Hoops
        hoopEntityMSharedPtr  loadHoopFiles();  // load hoop XML files
        stdStringVec loadHoopListFile(const std::string &fileName);  // load the list of hoops from hoops.xml
        hoopEntitySharedPtr loadHoopFile(const std::string &fileName);  // loads data from the hoop XML files.

        hoopEntityMSharedPtr loadModels(hoopEntityMSharedPtr activeHoopInstance, const renderEngineSharedPtr &render);  // loads selected hoop model

    private:
    
        hoopEntityMSharedPtr  hInstance;
        stdStringVec hoopFiles;  // stores list of hoop xml files
        bool hoopFilesLoaded;

};

#endif
