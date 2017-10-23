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
 
#ifndef _LOAD_H_
#define _LOAD_H_

#include <string>
#include <vector>
#include <unordered_map>

#include "Ogre.h"
#include "SDL.h"

#include "tinyxml2.h"



//#include "state/basketballstate.h"
//#include "state/courtstate.h"
//#include "state/hoopstate.h"
//#include "state/gamestate.h"
//#include "state/teamstate.h"
//#include "offenseplays.h"
//#include "userinput.h"

class basketballState;
class courtState;
class hoopState;
class gameState;
class playerState;
class teamState;
class offensePlays;
class usersInput;

class loader
{
public:

    loader();  // constructor
    ~loader(); // destructor   
    
    stdStringVec pathSplit(const std::string paths);
    std::string findFile(std::string fileName);
//	string * pathArray;
    
    stdStringVec getUsersInputFiles();  // retrieves the value of userInputFiles
    void setUsersInputFiles(stdStringVec set);  // sets the value of userInputFiles
        
    usersInputVecSharedPtr getUIInstance();  // retrieves the value of uiInstance
    void setUIInstance(usersInputVecSharedPtr set);  // sets the value of uiInstance
              
    bool getUsersInputFilesLoaded();  // retrieves the value of userInputFilesLoaded
    void setUsersInputFilesLoaded(bool set);  // sets the value of userInputFilesLoaded  

    bool loadXMLFile(std::string fileName);

    int readFile(const char *sourceFile, char **destination);  // reads in the XML file

    SDL_RWops *readBinaryFile(const char *sourceFile);
    
        bool checkIfUsersInputsLoaded();  // checks if uset inputs have been loaded into uiInstance
        
    // User input
    usersInputVecSharedPtr loadUsersInputs();  // load user input XML files
    stdStringVec loadUsersInputListFile(std::string fileName);  // load the list of user input configs from userinputs.xml
    usersInputSharedPtr loadUsersInputFile(std::string fileName);  // loads data from the user input XML files.

    
protected:
//    loader();
//    loader(const loader&);
//    loader& operator= (const loader&);

private:

    static usersInputVecSharedPtr uiInstance;

    static stdStringVec teamFiles;	 // stores list of team xml files
    static stdStringVec usersInputFiles;  // stores list of court xml files

    // determines whether files have been loaded successfully
    static bool userInputFilesLoaded;
    static int count;  // counts number of times a function has been called
};


#endif

