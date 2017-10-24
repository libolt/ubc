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

#ifndef _LOAD_USERSINPUTS_H_
#define _LOAD_USERSINPUTS_H_

#include <string>
#include <vector>
#include <unordered_map>

#include "load/load.h"
#include "typedefs.h"

class loadUsersInputs : public loader
{
    public:

        loadUsersInputs();  // constructor
        ~loadUsersInputs();  // destructor

        stdStringVec getUsersInputFiles();  // retrieves the value of userInputFiles
        void setUsersInputFiles(stdStringVec set);  // sets the value of userInputFiles

        usersInputsVecSharedPtr getUIInstance();  // retrieves the value of uiInstance
        void setUIInstance(usersInputsVecSharedPtr set);  // sets the value of uiInstance

        bool getUsersInputFilesLoaded();  // retrieves the value of userInputFilesLoaded
        void setUsersInputFilesLoaded(bool set);  // sets the value of userInputFilesLoaded

        bool checkIfUsersInputsLoaded();  // checks if uset inputs have been loaded into uiInstance

        // User input
        usersInputsVecSharedPtr loadUsersInputFiles();  // load user input XML files
        stdStringVec loadUsersInputListFile(std::string fileName);  // load the list of user input configs from userinputs.xml
        usersInputsSharedPtr loadUsersInputFile(std::string fileName);  // loads data from the user input XML files.

    private:

        static usersInputsVecSharedPtr uiInstance;
        static stdStringVec usersInputFiles;  // stores list of court xml files
        // determines whether files have been loaded successfully
        static bool userInputFilesLoaded;
};

#endif // _LOAD_USERSINPUTS_H_
