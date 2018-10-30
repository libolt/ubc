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
 
#ifndef _LOAD_COURTS_H_
#define _LOAD_COURTS_H_

#include <string>
#include <vector>
#include <unordered_map>

#include "load/load.h"
#include "utilities/typedefs.h"

class loadCourts : public loader
{
    public:
    
        loadCourts();  // constructor
        ~loadCourts();  // destructor

        stdStringVec getCourtFiles() const;  // retrieves the value of courtFiles
        void setCourtFiles(const stdStringVec &set);  // sets the value of courtFiles
        
        courtEntityMSharedPtr getCInstance() const;  // retrieves the value of cInstance
        void setCInstance(const courtEntityMSharedPtr  &set);  // sets the value of cInstance

        bool getCourtFilesLoaded() const;  // retrieves the value of courtFilesLoaded
        void setCourtFilesLoaded(const bool &set);  // sets the value of courtFilesLoaded

        bool checkIfCourtsLoaded();  // checks if courts have been loaded into cInstance

        // Courts
        courtEntityMSharedPtr  loadCourtFiles();  // load court XML files
        stdStringVec loadCourtListFile(std::string fileName);  // load the list of courts from courts.xml
        courtEntitySharedPtr loadCourtFile(std::string fileName);  // loads data from the court XML files.

        courtEntityMSharedPtr loadModels(courtEntityMSharedPtr activeCourtInstance, renderEngineSharedPtr render);  // loads selected court model

    private:
    
        courtEntityMSharedPtr  cInstance;
        stdStringVec courtFiles;  // stores list of court xml files
        bool courtFilesLoaded;
    
};

#endif
