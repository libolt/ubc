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

#include "conversion.h"
#include "load.h"
#include "logging.h"
#include "data/basketballdata.h"
#include "data/courtdata.h"
#include "data/playerdata.h"
#include "engine/renderengine.h"
#include "entity/basketballentity.h"
#include "entity/playerentity.h"
#include "state/basketballstate.h"
#include "state/courtstate.h"
#include "state/hoopstate.h"
//#include "state/gamestate.h"
#include "state/playerstate.h"
#include "state/teamstate.h"
#include "offenseplays.h"
#include "typedefs.h"
#include "users/usersinput.h"

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
#include "android.h"
#endif

// static variables

basketballStateVecSharedPtr loader::bInstance;
courtStateUMSharedPtr  loader::cInstance;
hoopStateUMSharedPtr  loader::hInstance;
offensePlaysVecSharedPtr loader::opInstance;
playerEntityUMSharedPtr loader::pInstance;
teamStateUMSharedPtr loader::tInstance;
usersInputVecSharedPtr loader::uiInstance;


stdStringVec loader::basketballFiles;  // stores list of basketball xml files
stdStringVec loader::courtFiles;  // stores list of court xml files
stdStringVec loader::hoopFiles;  // stores list of hoop xml files
stdStringVec loader::offensePlayFiles;  // stores list of offense play xml files
stdStringVec loader::playerFiles;  // stores list of player xml files
stdStringVec loader::teamFiles;  // stores list of team xml files
stdStringVec loader::usersInputFiles; 

bool loader::basketballFilesLoaded;
bool loader::courtFilesLoaded;
bool loader::hoopFilesLoaded;
bool loader::offensePlayFilesLoaded;
bool loader::playerFilesLoaded;
bool loader::teamFilesLoaded;
bool loader::userInputFilesLoaded;

int loader::count;

loader::loader()  // constructor
{
    basketballFilesLoaded = false;
    courtFilesLoaded = false;
    offensePlayFilesLoaded = false;
    playerFilesLoaded = false;
    teamFilesLoaded = false;
    userInputFilesLoaded = false;


//        pathArray = pathSplit(dataPath);
//      cout << pathArray[2] << endl;
//      exit(0);
}

loader::~loader()  // destructor
{
}

stdStringVec loader::getBasketballFiles()  // retrieves the value of basketballFiles
{
    return (basketballFiles);
}
void loader::setBasketballFiles(stdStringVec set)  // sets the value of basketballFiles
{
    basketballFiles = set;
}

stdStringVec loader::getCourtFiles()   // retrieves the value of courtFiles
{
    return (courtFiles);
}
void loader::setCourtFiles(stdStringVec set)  // sets the value of courtFiles
{
    courtFiles = set;
}

stdStringVec loader::getOffensePlayFiles()  // retrieves the value of offensePlayFiles
{
    return (offensePlayFiles);
}
void loader::setOffensePlayFiles(stdStringVec set)  // sets the value of offensePlayFiles
{
    offensePlayFiles = set;
}

stdStringVec loader::getPlayerFiles()  // retrieves the value of playerFiles
{
    return(playerFiles);
}
void loader::setPlayerFiles(stdStringVec set)  // sets the value of playerFiles
{
    playerFiles = set;
}

stdStringVec loader::getTeamFiles()  // retrieves the value of teamFiles
{
    return(teamFiles);
}
void loader::setTeamFiles(stdStringVec set)  // sets the value of teamFiles
{
    teamFiles = set;
}

stdStringVec loader::getUsersInputFiles()   // retrieves the value of userInputFiles
{
    return (usersInputFiles);
}
void loader::setUsersInputFiles(stdStringVec set)  // sets the value of userInputFiles
{
    usersInputFiles = set;
}

basketballStateVecSharedPtr loader::getBInstance()  // retrieves the value of bInstance
{
    return (bInstance);
}
void loader::setBInstance(basketballStateVecSharedPtr set)  // sets the value of bInstance
{
    bInstance = set;
}

std::unordered_map<size_t, courtStateSharedPtr> loader::getCInstance()  // retrieves the value of cInstance
{
    return (cInstance);
}
void loader::setCInstance(std::unordered_map<size_t, courtStateSharedPtr> set)  // sets the value of cInstance
{
    cInstance = set;
}

std::unordered_map<size_t, hoopStateSharedPtr> loader::getHInstance()  // retrieves the value of hInstance
{
    return (hInstance);
}
void loader::setHInstance(std::unordered_map<size_t, hoopStateSharedPtr> set)  // sets the value of hInstance
{
    hInstance = set;
}

offensePlaysVecSharedPtr loader::getOPInstance()  // retrieves the value of opInstance
{
    return (opInstance);
}
void loader::setOPInstance(offensePlaysVecSharedPtr set)  // sets the value of opInstance
{
    opInstance = set;
}

playerEntityUMSharedPtr loader::getPInstance()  // retrieves the value of pInstance
{
    return(pInstance);
}
void loader::setPInstance(playerEntityUMSharedPtr set)  // sets the value of pInstance
{
    pInstance = set;
}

std::unordered_map<size_t, teamStateSharedPtr> loader::getTInstance()  // retrieves the value of tInstance
{
    return(tInstance);
}
void loader::setTInstance(std::unordered_map<size_t, teamStateSharedPtr> set)  // sets the value of tInstance
{
    tInstance = set;
}

usersInputVecSharedPtr loader::getUIInstance()  // retrieves the value of uoInstance
{
    return(uiInstance);
}
void loader::setUIInstance(usersInputVecSharedPtr set)  // sets the value of uiInstance
{
    uiInstance = set;
}

bool loader::getBasketballFilesLoaded()  // retrieves the value of basketballFilesLoaded
{
    return (basketballFilesLoaded);
}
void loader::setBasketballFilesLoaded(bool set)  // sets the value of basketballFilesLoaded
{
    basketballFilesLoaded = set;
}

bool loader::getCourtFilesLoaded()  // retrieves the value of courtFilesLoaded
{
    return (courtFilesLoaded);
}
void loader::setCourtFilesLoaded(bool set)  // sets the value of courtFilesLoaded
{
    courtFilesLoaded = set;
}
bool loader::getOffensePlayFilesLoaded()  // retrieves the value of offensePlayFilesLoaded
{
    return (offensePlayFilesLoaded);
}
void loader::setOffensePlayFilesLoaded(bool set)  // sets the value of offensePlayFilesLoaded
{
    offensePlayFilesLoaded = set;
}

bool loader::getPlayerFilesLoaded()  // retrieves the value of playerFilesLoaded
{
    return (playerFilesLoaded);
}
void loader::setPlayerFilesLoaded(bool set)  // sets the value of playerFilesLoaded
{
    playerFilesLoaded = set;
}

bool loader::getTeamFilesLoaded()  // retrieves the value of teamFilesLoaded
{
    return (teamFilesLoaded);
}
void loader::setTeamFilesLoaded(bool set)  // sets the value of teamFilesLoaded
{
    teamFilesLoaded = set;
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

bool loader::checkIfBasketballsLoaded()  // checks if basketballs have been loaded into bInstance
{
    sharedPtr<conversion> convert = conversion::Instance();
    std::string func = "loader::checkBasketballsLoaded()";
    
    logMsg(func + " beginning");
    
    if (basketballFilesLoaded)
    {
        logMsg(func +" getBasketballFilesLoaded");

        if (bInstance.size() > 0)
        {
            logMsg(func +" Basketball Files Loaded!");
            return(true);
        }
        else
        {
            logMsg(func +" Basketball Files not yet Loaded!");

            basketballFilesLoaded = false;
            bInstance = loadBasketballs();
            if (bInstance.size() > 0)
            {
                logMsg(func +" > 0!");

//                load->setTInstance(tInstance);
                basketballFilesLoaded = true;
                return(true);
            }
            else
            {
                logMsg(func +" Failed to load Basketball Files! IF");
                exit(0);
            }
        }
    }
    else 
    {
        logMsg(func +" ELSE");

        if (bInstance.size() > 0)
        {
            logMsg(func +" load->getBInstance().size() > 0! ELSE");
//            load->setTInstance(tInstance);
            basketballFilesLoaded = true;
            return(true);
        }
        else
        {
            logMsg(func +" ELSE ELSE!");
            bInstance = loadBasketballs();
            logMsg(func +" blah");

            logMsg(func +" bInstance.size() == " +convert->toString(bInstance.size()));

//            logMsg("loader::checkBasketballsLoaded()");
            if (bInstance.size() > 0)
            {
                logMsg(func +" load->getBInstance().size() > 0! ELSE ELSE");

//                load->setTInstance(tInstance);
                basketballFilesLoaded = true;
                return(true);
            }
            else
            {
                logMsg(func +" Failed to load Basketball Files!");
                return(false);
            }
        }
    }
    
    logMsg(func + " end");
    return (false);
}

bool loader::checkIfCourtsLoaded()  // checks if courts have been loaded into cInstance
{
//    exit(0);

    std::string func = "loader::checkIfCourtsLoaded()";
        
    logMsg(func + " beginning");
    
    if (courtFilesLoaded)
    {
        logMsg(func + " getCourtFilesLoaded");
        exit(0);
        if (cInstance.size() > 0)
        {
            logMsg(func + " Court Files Loaded!");
            return(true);
        }
        else
        {
            logMsg(func + " Court Files not yet Loaded!");

            courtFilesLoaded = false;
            cInstance = loadCourts();
            if (cInstance.size() > 0)
            {
                logMsg(func + "  > 0!");

//                load->setTInstance(tInstance);
                courtFilesLoaded = true;
                return(true);
            }
            else
            {
                logMsg(func + " Failed to load Court Files! IF");
                exit(0);
            }
        }
    }
    else 
    {
        logMsg(func + " ELSE");
//        exit(0);
        if (cInstance.size() > 0)
        {
            logMsg(func + " load->getCInstance().size() > 0! ELSE");
//            load->setTInstance(tInstance);
            courtFilesLoaded = true;
            return(true);
        }
        else
        {
            logMsg(func + " ELSE ELSE!");

            cInstance = loadCourts();
            logMsg(func);
            if (cInstance.size() > 0)
            {
                logMsg(func + " load->getCInstance().size() > 0! ELSE ELSE");

//                load->setTInstance(tInstance);
                courtFilesLoaded = true;
                return(true);
            }
            else
            {
                logMsg(func + " Failed to load Court Files!");
                return(false);
            }
        }
    }
//    exit(0);
    
    logMsg(func + " end");
    
    return (false);
}

bool loader::checkIfHoopsLoaded()  // checks if the hooops have been loaded into hInstance
{

    std::string func = "loader::checkIfHoopsLoaded()";
    logMsg(func + " beginning");
    
    if (hoopFilesLoaded)
    {
        logMsg(func + " getHoooFilesLoaded");
//        exit(0);
        if (hInstance.size() > 0)
        {
            logMsg(func + " Hoop Files Loaded!");
            return(true);
        }
        else
        {
            logMsg(func + " Hoop Files not yet Loaded!");

            hoopFilesLoaded = false;
            hInstance = loadHoops();
            if (hInstance.size() > 0)
            {
                logMsg(func + "  > 0!");

//                load->setTInstance(tInstance);
                hoopFilesLoaded = true;
                return(true);
            }
            else
            {
                logMsg(func + " Failed to load Hoop Files! IF");
                exit(0);
            }
        }
    }
    else 
    {
        logMsg(func + " ELSE");
//        exit(0);
        if (hInstance.size() > 0)
        {
            logMsg(func + " load->getHInstance().size() > 0! ELSE");
//            load->setTInstance(tInstance);
            hoopFilesLoaded = true;
            return(true);
        }
        else
        {
            logMsg(func + " ELSE ELSE!");

            hInstance = loadHoops();
            logMsg(func);
            if (hInstance.size() > 0)
            {
                logMsg(func + " load->getHInstance().size() > 0! ELSE ELSE");

//                load->setTInstance(tInstance);
                hoopFilesLoaded = true;
                return(true);
            }
            else
            {
                logMsg(func + " Failed to load Hop Files!");
                return(false);
            }
        }
    }
    
    logMsg(func + " end");
    
    return (false);
}

bool loader::checkIfOffensePlaysLoaded()  // checks if offense plays have been loaded into opInstance
{
    std::string func = "loader::checkIfOffensePlaysLoaded()";
    
    logMsg(func + " beginning");
    if (offensePlayFilesLoaded)
    {
        logMsg(func + " getOffensePlayFilesLoaded");

        if (opInstance.size() > 0)
        {
            logMsg(func + " Offense Play Files Loaded!");
            return(true);
        }
        else
        {
            logMsg(func + " Offense Plays Files not yet Loaded!");

            offensePlayFilesLoaded = false;
            opInstance = loadOffensePlays();
            if (opInstance.size() > 0)
            {
                logMsg(func + " > 0!");

//                load->setTInstance(tInstance);
                offensePlayFilesLoaded = true;
                return(true);
            }
            else
            {
                logMsg(func + " Failed to load Offense Play Files! IF");
                exit(0);
            }
        }
    }
    else 
    {
        logMsg(func + " ELSE");

        if (opInstance.size() > 0)
        {
            logMsg(func + " load->getOPInstance().size() > 0! ELSE");
//            load->setTInstance(tInstance);
            offensePlayFilesLoaded = true;
            return(true);
        }
        else
        {
            logMsg(func + " ELSE ELSE!");

            opInstance = loadOffensePlays();
            if (opInstance.size() > 0)
            {
                logMsg(func + " load->getOPInstance().size() > 0! ELSE ELSE");

//                load->setTInstance(tInstance);
                offensePlayFilesLoaded = true;
                return(true);
            }
            else
            {
                logMsg(func + " Failed to load Offense Play Files!");
                return(false);
            }
        }
    }
    

    logMsg(func + " end");

    return (false);
}

bool loader::checkIfPlayersLoaded()  // checks if players have been loaded into pInstance
{
    std::string func = "loader::checkIfPlayersLoaded()";
    
    logMsg(func + " beginning");

    if (playerFilesLoaded)
    {
        logMsg(func + " getPlayerFilesLoaded");

        if (pInstance.size() > 0)
        {
            logMsg(func + " Player Files Loaded!");
            return(true);
        }
        else
        {
            logMsg(func + " Player Files not yet Loaded!");

            playerFilesLoaded = false;
            pInstance = loadPlayers();
            if (pInstance.size() > 0)
            {
                logMsg(func + " > 0!");

//                load->setTInstance(tInstance);
                playerFilesLoaded = true;
                return(true);
            }
            else
            {
                logMsg(func + " Failed to load Player Files! IF");
                exit(0);
            }
        }
    }
    else
    {
        logMsg(func + " ELSE");

        if (pInstance.size() > 0)
        {
            logMsg(func + " load->getPInstance().size() > 0! ELSE");
//            load->setTInstance(tInstance);
            playerFilesLoaded = true;
            return(true);
        }
        else
        {
            logMsg(func + " ELSE ELSE!");

            pInstance = loadPlayers();

            if (pInstance.size() > 0)
            {
                logMsg(func + " load->getPInstance().size() > 0! ELSE ELSE");

//                load->setTInstance(tInstance);
                playerFilesLoaded = true;
                return(true);
            }
            else
            {
                logMsg(func + " Failed to load Player Files!");
//                return(false);
            }
        }
    }
//    exit(0);
    logMsg(func + " end");

    return (true);
}

bool loader::checkIfTeamsLoaded()  // checks if teams have been loaded into tInstance
{
    sharedPtr<conversion> convert = conversion::Instance();
    teamStateVec tempT;
    teamStateUMSharedPtr tempTInstance;
    tInstance = tempTInstance;
    std::string func = "loader::checkIfTeamsLoaded()";
    
    logMsg(func + " beginning");

    if (teamFilesLoaded)
    {
        logMsg(func + " getTeamFilesLoaded");

        if (tInstance.size() > 0)
        {
            logMsg(func + " Team Files Loaded!");
            return(true);
        }
        else
        {
            logMsg(func + " Team Files not yet Loaded!");

            teamFilesLoaded = false;
            tInstance = loadTeams();
            if (tInstance.size() > 0)
            {
                logMsg(func + " > 0!");

//                load->setTInstance(tInstance);
                teamFilesLoaded = true;
                return(true);
            }
            else
            {
                logMsg(func + " Failed to load Team Files! IF");
                exit(0);
            }
        }
    }
    else 
    {
        logMsg(func + " ELSE");

        if (tInstance.size() > 0)
        {
            logMsg(func + " load->getTInstance().size() > 0! ELSE");
//            load->setTInstance(tInstance);
            teamFilesLoaded = true;
            return(true);
        }
        else
        {
            logMsg(func + " ELSE ELSE!");

            tInstance = loadTeams();
            logMsg(func + " tInstance.size() == " +convert->toString(tInstance.size()));
//            exit(0);
            if (tInstance.size() > 0)
            {
                logMsg(func + " load->getTInstance().size() > 0! ELSE ELSE");

//                load->setTInstance(tInstance);
                teamFilesLoaded = true;
                return(true);
            }
            else
            {
                logMsg(func + " Failed to load Team Files!");
                return(false);
            }
        }
    }
    
    logMsg(func + " end");
    
    return (true);
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


// Hoops

