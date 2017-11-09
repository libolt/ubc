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

#ifndef _LOAD_OFFENSEPLAYS_H_
#define _LOAD_OFFENSEPLAYS_H_

#include <string>
#include <vector>
#include <unordered_map>

#include "load/load.h"
#include "utilities/typedefs.h"

class loadOffensePlays : public loader
{
    public:

        loadOffensePlays();  // constructor
        ~loadOffensePlays();  // destructor

        stdStringVec getOffensePlayFiles();  // retrieves the value of offensePlayFiles
        void setOffensePlayFiles(stdStringVec set);  // sets the value of offensePlayFiles

        offensePlaysVecSharedPtr getOPInstance();  // retrieves the value of opInstance
        void setOPInstance(offensePlaysVecSharedPtr set);  // sets the value of opInstance

        bool getOffensePlayFilesLoaded();  // retrieves the value of offensePlaFilesLoaded
        void setOffensePlayFilesLoaded(bool set);  // sets the value of offensePlayFilesLoaded

        bool checkIfOffensePlaysLoaded();  // checks if offense plays have been loaded into opInstance

        //Offense
        offensePlaysVecSharedPtr loadOffensePlayFiles();  // load offense plays from XML files
        stdStringVec loadOffensePlayListFile(std::string fileName);  // loads the list of offense play files from plays.xml
        offensePlaysSharedPtr loadOffensePlayFile(std::string fileName); // loads data from the offense play XML files


    private:

        static offensePlaysVecSharedPtr opInstance;
        static stdStringVec offensePlayFiles;  // stores list of offense play xml files
        static bool offensePlayFilesLoaded;

};
#endif