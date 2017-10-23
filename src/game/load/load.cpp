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

#ifdef __ANDROID__
#include "android-config.h"
#else
#include "config.h"
#endif

#include "state/teamstate.h"
#include "conversion.h"
#include "load/load.h"
#include "logging.h"
#include "engine/renderengine.h"

//#include "state/gamestate.h"

#include "typedefs.h"

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
#include "android.h"
#endif

// static declarations
usersInputVecSharedPtr loader::uiInstance;
stdStringVec loader::usersInputFiles; 
bool loader::userInputFilesLoaded;

int loader::count;

loader::loader()  // constructor
{

    userInputFilesLoaded = false;

//        pathArray = pathSplit(dataPath);
//      cout << pathArray[2] << endl;
//      exit(0);
}

loader::~loader()  // destructor
{
}

stdStringVec loader::getUsersInputFiles()   // retrieves the value of userInputFiles
{
    return (usersInputFiles);
}
void loader::setUsersInputFiles(stdStringVec set)  // sets the value of userInputFiles
{
    usersInputFiles = set;
}



usersInputVecSharedPtr loader::getUIInstance()  // retrieves the value of uoInstance
{
    return(uiInstance);
}
void loader::setUIInstance(usersInputVecSharedPtr set)  // sets the value of uiInstance
{
    uiInstance = set;
}

bool loader::getUsersInputFilesLoaded()  // retrieves the value of userInputFilesLoaded
{
    return (userInputFilesLoaded);
}
void loader::setUsersInputFilesLoaded(bool set)  // sets the value of userInputFilesLoaded  
{
    userInputFilesLoaded = set;
}

int loader::readFile(const char *sourceFile, char **destination)  // loads an xml file using SDL so that it can be passed to TinyXML
{
    sharedPtr<conversion> convert = conversion::Instance();
//    sharedPtr<renderEngine> render = renderEngine::Instance();
    int BLOCK_SIZE = 8;
    int MAX_BLOCKS = 1024;
    std::string func = "loader::readFile()";

    logMsg(func +" beginning");

///#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//	Ogre::DataStreamPtr fileData = render->openAPKFile("teamInstance.xml");
//	destination = new std::string;
///	destination = (char**)fileData->getAsString().c_str();
//#else
//    char *contents = NULL;
//	readFile(fileName.c_str(), &contents);
//	fileContents = toString(contents);
//#endif
    // Open the file
//    SDL_RWops *file;
    logMsg(func +" sourceFile = " +convert->toString(sourceFile));
//	logMsg(SDL_AndroidGetInternalStoragePath());
//    file = SDL_RWFromFile("teamInstance.xml", "rb");

    SDL_RWops *file;
	file = SDL_RWFromFile(sourceFile, "r");
//	SDL_RWops *file = openAPKFile(filename);
//	if (SDL_RWFromFile(name.c_str(), "r") != 0)
/*	{
		fprintf(stderr,
                "\nUnable to load file:  %s\n",
                SDL_GetError()
               );
	}*/
    logMsg(func +" Seek to beginning of file");
    size_t fileLength = SDL_RWseek(file, 0, SEEK_END);
    (*destination) = new char[fileLength + 1]; // allow an extra characterfor '\0'

//    ASSERT(file, "Opening file using SDL_RWops");
    // resets the file to beginning
    SDL_RWseek(file, 0, SEEK_SET);
    // Read text from file
    std::string *contents = new std::string;
    int n_blocks = SDL_RWread(file, (*destination), 1, fileLength+1);
    logMsg(func +" contents = " +convert->toString(contents));
    (*destination)[fileLength] = '\0';
//    logMsg("destination = " +convert->toString((*destination)));
//    exit(0);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//    logMsg("destination = " +convert->toString(destination));
#endif

    // BLOCK_SIZE = 8, MAX_BLOCKS = 1024
    SDL_RWclose(file);

    logMsg(func +" end");

    return EXIT_SUCCESS;
}

SDL_RWops *loader::readBinaryFile(const char *sourceFile)  // reads in a binary file
{
    //conversion *convert = conversion::Instance();
    sharedPtr<conversion> convert = conversion::Instance();
    
    int BLOCK_SIZE = 8;
    int MAX_BLOCKS = 1024;
    
    logMsg("sourceFile = " +convert->toString(sourceFile));

    SDL_RWops *file;
    file = SDL_RWFromFile(sourceFile, "rb");

    return (file);
}

stdStringVec loader::pathSplit(const std::string paths)  // splits the path data into separate strings
{
    int x = 0;
    stdStringVec stringArray;
    const char delim = ':';
    std::string::const_iterator p = paths.begin(), q;
    stdStringVec::iterator it;

    while (true)
    {
        q = find(p, paths.end(), delim);
        stringArray.push_back(paths.substr(p - paths.begin(), q - p));
        stdStringVec tempArray;
        for (it = stringArray.begin(); it != stringArray.end(); ++it)
        {
            tempArray.push_back(*it);
        }
        if (q == paths.end()) break;
        p = ++q;
        x++;
    }

    return(stringArray);
}

std::string loader::findFile(std::string fileName)  // finds the location of a file
{
    // tries to load file from locations specified in the pathArray
    bool fileLoaded = false;
    std::string filePath = "";        // stores path to a file
    stdStringVec pathArray;
    std::string dataPath;
    
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    dataPath = "";
#else
    dataPath = UBC_DATADIR;
#endif

    logMsg("dataPath = " +dataPath);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    filePath = fileName;
#else
    dataPath += "/";

    pathArray = pathSplit(dataPath);

    logMsg("pathArray[0] = " +pathArray[0]);
 //   logMsg("pathArray[1] = " +pathArray[1]);

    for (int x = 0; x < 3; x++)
    {
        if (!fileLoaded)
        {
            filePath.clear();
            filePath.append(pathArray[x]);
            logMsg("pathArray == " + pathArray[x]);

            filePath.append(fileName);
            logMsg("filePath = " +filePath);
            std::fstream fileOpen;
            // if (!(lineupFont = TTF_OpenFont(file.c_str(), 20)));
            fileOpen.open(filePath.c_str(), std::ios::in);
            if (!fileOpen)
            {
                logMsg("failed to load " + filePath);
//                exit(0);
            }
            else
            {
//                logMsg("File Exists at: " +filePath);
                // opens players.txt
                fileLoaded = true;
            }

        }
        else
        {
            return(filePath);
        }
    }
    if (!fileLoaded)
    {
        logMsg("failed to find file: " + fileName);
        exit(0);
    }
#endif
    return ("");
}

bool loader::checkIfUsersInputsLoaded()  // checks if user inputs have been loaded into pInstance
{
        sharedPtr<conversion> convert = conversion::Instance();
    std::string func = "loader::checkIfUserInputsLoaded()";

    logMsg(func +" beginning");

    if (userInputFilesLoaded)
    {
        logMsg(func +" getUserInputFilesLoaded");

        if (uiInstance.size() > 0)
        {
            logMsg(func +" User Input Files Loaded!");
            return(true);
        }
        else
        {
            logMsg(func +" User Input Files not yet Loaded!");

            userInputFilesLoaded = false;
            uiInstance = loadUsersInputs();
            if (uiInstance.size() > 0)
            {
                logMsg(func +" uiInstance.size() ==" +convert->toString(uiInstance.size()));

//                load->setTInstance(tInstance);
                userInputFilesLoaded = true;
                return(true);
            }
            else
            {
                logMsg(func +" Failed to load User Input Files! IF");
                exit(0);
            }
        }
    }
    else 
    {
        logMsg(func +" ELSE");

        if (uiInstance.size() > 0)
        {
            logMsg(func +" uiInstance.size() ==" +convert->toString(uiInstance.size()));
//            load->setTInstance(tInstance);
            userInputFilesLoaded = true;
            return(true);
        }
        else
        {
            logMsg(func +" ELSE ELSE!");

            uiInstance = loadUsersInputs();
            logMsg("loader::checkIfUserInputsLoaded()");
            if (uiInstance.size() > 0)
            {
                logMsg(func +" uiInstance.size() ==" +convert->toString(uiInstance.size()));

//                load->setTInstance(tInstance);
                userInputFilesLoaded = true;
                return(true);
            }
            else
            {
                logMsg(func +" Failed to load User Input Files!");
                return(false);
            }
            exit(0);
        }
    }

    logMsg(func +" end");

    return (false);
}


