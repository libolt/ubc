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

#ifdef __ANDROID__
#include "utilities/android-config.h"
#else
#include "config.h"
#endif

#include "state/teamstate.h"
#include "utilities/conversion.h"
#include "load/load.h"
#include "utilities/logging.h"
#include "engine/renderengine.h"

//#include "state/gamestate.h"

#include "utilities/typedefs.h"

// static declarations
int loader::count;

loader::loader()  // constructor
{
//        pathArray = pathSplit(dataPath);
//      cout << pathArray[2] << endl;
//      exit(0);
}

loader::~loader()  // destructor
{
}

int loader::readFile(const char *sourceFile, char **destination)  // loads an xml file using SDL so that it can be passed to TinyXML
{
    conversionSharedPtr convert = conversion::Instance();
//    renderEngineSharedPtr render = renderEngine::Instance();
    int BLOCK_SIZE = 8;
    int MAX_BLOCKS = 1024;
    std::string func = "loader::readFile()";

    logMsg(func +" begin");

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
    conversionSharedPtr convert = conversion::Instance();
    std::string func = "loader::readBinaryFile()";
    int BLOCK_SIZE = 8;
    int MAX_BLOCKS = 1024;
    
    logMsg(func +" begin");
    logMsg(func +" sourceFile = " +convert->toString(sourceFile));

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
    std::string func = "loader::findFile()";
    
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    dataPath = "";
#else
    dataPath = UBC_DATADIR;
#endif

    logMsg(func +" begin");
    
    logMsg(func +" dataPath = " +dataPath);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    filePath = fileName;
#else
    dataPath += "/";

    pathArray = pathSplit(dataPath);

    logMsg(func +" pathArray[0] = " +pathArray[0]);
 //   logMsg("pathArray[1] = " +pathArray[1]);

    for (int x = 0; x < 3; x++)
    {
        if (!fileLoaded)
        {
            filePath.clear();
            filePath.append(pathArray[x]);
            logMsg(func + " pathArray == " + pathArray[x]);

            filePath.append(fileName);
            logMsg(func + " filePath = " +filePath);
            std::fstream fileOpen;
            // if (!(lineupFont = TTF_OpenFont(file.c_str(), 20)));
            fileOpen.open(filePath.c_str(), std::ios::in);
            if (!fileOpen)
            {
                logMsg(func +" failed to load " + filePath);
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
        logMsg(func +" failed to find file: " + fileName);
        exit(0);
    }
#endif
    logMsg(func + " end");
    
    return ("");
}

OgreEntitySharedPtr loader::loadModelFile(std::string modelFileName, std::string entityName, renderEngineSharedPtr render)  // loads the 3D model
{
    conversionSharedPtr convert = conversion::Instance();
    std::string func = "loader::loadModelFile()";
    sharedPtr<Ogre::SceneManager> mSceneMgr = render->getMSceneMgr();
    Ogre::ResourceGroupManager &rsm = Ogre::ResourceGroupManager::getSingleton();
    OgreEntitySharedPtr tempModel;
    std::string entityNodeName;
    entityNodeName = entityName + "node";
    
    logMsg(func +" begin");
    logMsg(func +" entityName == " +entityName);
    logMsg(func +" modelFileName == " +modelFileName);
//    logMsg(func +" entityNodeName == " +entityNodeName);
        
    if (rsm.resourceGroupExists("UBCData"))
    {
        logMsg(func +" UBData exists!");
        if (rsm.resourceExists("UBCData", modelFileName))
        {
            logMsg(func +" " +modelFileName +" exists!");
        }
        else
        {
            logMsg(func +" " +modelFileName +" doesn't exist!");
        }
    }
    else
    {
        logMsg(func +" UBData doesnt exist!");

    }
    
//BASEREMOVAL    if (base->getGameE()->getRenderE().get()->getMSceneMgr()->hasCamera("camera"))
    if (render.get()->getMSceneMgr()->hasCamera("camera"))
    {
        logMsg(func +" mSceneMgr has camera!");
    }
    else
    {
        logMsg(func +" mSceneMgr does not have camera!");
    }
    
//    logMsg(func +" Entity Name == " +entityName + " Model File Name == " +modelFileName);
//BASEREMOVAL    tempModel = OgreEntitySharedPtr(base->getGameE()->getRenderE()->getMSceneMgr()->createEntity(entityName, entityModelFileName, "UBCData"));  // loads the model
    tempModel = OgreEntitySharedPtr(render->getMSceneMgr()->createEntity(entityName, modelFileName, "UBCData"));  // loads the model

//    logMsg(func +" tempModel loaded!");
//    logMsg(func +" tempModel name == " +tempModel->getName());

//    model = OgreEntitySharedPtr(tempModel);
//    logMsg(func +" Entity Created!");


    logMsg(func +" end");
    
    return (tempModel);
}

