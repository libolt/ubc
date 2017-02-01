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
#include "load.h"
#include "logging.h"
#include "data/playerdata.h"
#include "engine/renderengine.h"
#include "entity/playerentity.h"
#include "state/basketballstate.h"
#include "state/courtstate.h"
#include "state/hoopstate.h"
//#include "state/gamestate.h"
#include "state/playerstate.h"
#include "state/teamstate.h"
#include "offenseplays.h"
#include "typedefs.h"
#include "userinput.h"

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
#include "android.h"
#endif

// static variables

basketballStateVecSharedPtr loader::bInstance;
courtStateUMSharedPtr  loader::cInstance;
hoopStateUMSharedPtr  loader::hInstance;
offensePlaysVecSharedPtr loader::opInstance;
playerStateUMSharedPtr loader::pInstance;
teamStateUMSharedPtr loader::tInstance;
userInputVecSharedPtr loader::uiInstance;


stdStringVec loader::basketballFiles;  // stores list of basketball xml files
stdStringVec loader::courtFiles;  // stores list of court xml files
stdStringVec loader::hoopFiles;  // stores list of hoop xml files
stdStringVec loader::offensePlayFiles;  // stores list of offense play xml files
stdStringVec loader::playerFiles;  // stores list of player xml files
stdStringVec loader::teamFiles;  // stores list of team xml files
stdStringVec loader::userInputFiles; 

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

stdStringVec loader::getUserInputFiles()   // retrieves the value of userInputFiles
{
    return (userInputFiles);
}
void loader::setUserInputFiles(stdStringVec set)  // sets the value of userInputFiles
{
    userInputFiles = set;
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

playerStateUMSharedPtr loader::getPInstance()  // retrieves the value of pInstance
{
    return(pInstance);
}
void loader::setPInstance(playerStateUMSharedPtr set)  // sets the value of pInstance
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

userInputVecSharedPtr loader::getUIInstance()  // retrieves the value of uoInstance
{
    return(uiInstance);
}
void loader::setUIInstance(userInputVecSharedPtr set)  // sets the value of uiInstance
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

bool loader::getUserInputFilesLoaded()  // retrieves the value of userInputFilesLoaded
{
    return (userInputFilesLoaded);
}
void loader::setUserInputFilesLoaded(bool set)  // sets the value of userInputFilesLoaded  
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

bool loader::checkIfUserInputsLoaded()  // checks if user inputs have been loaded into pInstance
{
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
            uiInstance = loadUserInputs();
            if (uiInstance.size() > 0)
            {
                logMsg(func +"  > 0!");

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
            logMsg(func +" load->getPInstance().size() > 0! ELSE");
//            load->setTInstance(tInstance);
            userInputFilesLoaded = true;
            return(true);
        }
        else
        {
            logMsg(func +" ELSE ELSE!");

            uiInstance = loadUserInputs();
            logMsg("loader::checkIfUserInputsLoaded()");
            if (uiInstance.size() > 0)
            {
                logMsg(func +" load->getPInstance().size() > 0! ELSE ELSE");

//                load->setTInstance(tInstance);
                userInputFilesLoaded = true;
                return(true);
            }
            else
            {
                logMsg(func +" Failed to load User Input Files!");
                return(false);
            }
        }
    }

    logMsg(func +" end");

    return (false);
}

// Basketballs
basketballStateVecSharedPtr loader::loadBasketballs()  // load basketball settings from XML files
{
//    exit(0);
    basketballStateVecSharedPtr basketballs;
    std::string basketballList;
    std::string func = "loader::loadBasketballs()";
    
    logMsg(func +" beginning");
    
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    basketballList = "data/basketballs/basketballs.xml";
#else
    basketballList = findFile("basketballs/basketballs.xml");
#endif
    basketballFiles = loadBasketballListFile(basketballList);
//    stdStringVec playerFiles = load->getPlayerFiles();

    stdStringVec::iterator it;
    for (it = basketballFiles.begin(); it != basketballFiles.end(); ++it)
    {
        logMsg("basketballFile = " +*it);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        basketballs.push_back(loadBasketballFile("data/basketballs/" + *it));
#else
        basketballs.push_back(loadBasketballFile(findFile("basketballs/" + *it)));
#endif
    }
    logMsg(func +" end");
    return (basketballs);
}

stdStringVec loader::loadBasketballListFile(std::string fileName) // loads the list of baskteball list file
{
    sharedPtr<conversion> convert = conversion::Instance();
//    sharedPtr<renderEngine> render = renderEngine::Instance();
    stdStringVec bballFiles;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    std::string func = "loader::loadBasketballListFile()";
    
    logMsg(func +" beginning");

    logMsg(fileName);
    char *contents = NULL;
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
//    logMsg("fileContents = " +fileContents);

    doc.Parse(contents);
    if (doc.Error())
    {
/*        logMsg("Unable to parse basketballs.xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
*/
    }

    tinyxml2::XMLHandle hDoc(&doc);
    tinyxml2::XMLElement *pElem;
    tinyxml2::XMLHandle hRoot(0);
    pElem=hDoc.FirstChildElement().ToElement();
    // should always have a valid root but handle gracefully if it does
    if (!pElem)
    {
        logMsg("Unable to find a valid basketball list root!");
    }

    // save this for later
    hRoot=tinyxml2::XMLHandle(pElem);

    pElem=hRoot.FirstChild().ToElement();
    for( pElem; pElem; pElem=pElem->NextSiblingElement())
    {
        std::string pKey=pElem->Value();
        std::string pText=pElem->GetText();
        bballFiles.push_back(pText);
    }

//    setBasketballFiles(basketballFile);
//    return true;
    logMsg(func +" end");
    return (bballFiles);
}

sharedPtr<basketballState> loader::loadBasketballFile(std::string fileName)  // loads data from the basketball XML files
{
    sharedPtr<conversion> convert = conversion::Instance();
    sharedPtr<basketballState> basketballInstance(new basketballState);
    
//    basketballState *basketball = new basketballState;
    std::string name;
    std::string modelName;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    char *contents = NULL;
    std::string func = "loader::loadBasketballFile()";
    
    logMsg(func +" beginning");

    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
    logMsg(func +" fileContents == " +fileContents);

    doc.Parse(fileContents.c_str(),fileContents.size());
    if (doc.Error())
    {
/*        logMsg(func +" Unable to parse court xml file");
        logMsg(func +" Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(func +" " +convert->toString(doc.GetErrorStr1()));
        logMsg(func +" " +convert->toString(doc.GetErrorStr2()));
        exit(0);
*/
    }

    tinyxml2::XMLHandle hDoc(&doc);
    tinyxml2::XMLElement *rootElement;
    tinyxml2::XMLElement *child;
    tinyxml2::XMLHandle hRoot(0);
   
    logMsg(func + " rootElement?");

    rootElement = hDoc.FirstChildElement().ToElement();
    
    logMsg(func + " rootElement!");
    logMsg(func + " rootElement = " + convert->toString(rootElement));

    // should always have a valid root but handle gracefully if it does
    if (!rootElement)
    {
        logMsg(func +" Unable to load basketball element");
        exit(0);
    }

    logMsg(func + " child?");
    child = rootElement->FirstChild()->ToElement();
    if (child)
    {
        std::string cKey = child->Value();
        if (cKey == "Name")
        {
            logMsg(func +"name!");
            name = child->GetText();
            logMsg(func +" name = " +name);
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            modelName = child->GetText();
            logMsg(func +" modelName = " +modelName);
        }
    }
    basketballInstance->setName(name);
    basketballInstance->setModelFileName(modelName);
    basketballInstance->setEntityModelFileName(modelName);
    
    return (basketballInstance);
}

// Courts
std::unordered_map<size_t, courtStateSharedPtr> loader::loadCourts()  // load court settings from XML files
{
//    exit(0);
    courtStateUMSharedPtr  courts;
    std::string courtList;
    std::string func = "loader::loadCourts()";

    logMsg(func + " beginning");

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    courtList = "data/courts/courts.xml";
#else
    courtList = findFile("courts/courts.xml");
#endif
    courtFiles = loadCourtListFile(courtList);
//    stdStringVec playerFiles = load->getPlayerFiles();

//    stdStringVec::iterator it;
    auto it = 0;
//    for (it = courtFiles.begin(); it != courtFiles.end(); ++it)
    for (it=0;it<courtFiles.size();++it)
    {
//        logMsg("courtFile = " +*it);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        courts.insert(std::pair<size_t, courtStateSharedPtr>(it, loadCourtFile("data/courts/" + courtFiles[it])));
#else
        courts.insert(std::pair<size_t, courtStateSharedPtr>(it, loadCourtFile(findFile("courts/" + courtFiles[it]))));
#endif
    }

    logMsg(func + " end");

    return (courts);
}

stdStringVec loader::loadCourtListFile(std::string fileName)    // loads the list of court list file
{
    sharedPtr<conversion> convert = conversion::Instance();
//    sharedPtr<renderEngine> render = renderEngine::Instance();
    stdStringVec cFiles;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    std::string func = "loader::loadCourtListFile()";

    logMsg(func + " beginning");

    logMsg(func + " " +fileName);
    char *contents = NULL;
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
//    logMsg("fileContents = " +fileContents);

    doc.Parse(contents);
    if (doc.Error())
    {
/*        logMsg("Unable to parse courts.xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
*/
    }

    tinyxml2::XMLHandle hDoc(&doc);
    tinyxml2::XMLElement *pElem;
    tinyxml2::XMLHandle hRoot(0);

    pElem=hDoc.FirstChildElement().ToElement();
    // should always have a valid root but handle gracefully if it does
    if (!pElem)
    {
        logMsg("Unable to find a vlid court list root!");
    } 

    // save this for later
    hRoot=tinyxml2::XMLHandle(pElem);

    pElem=hRoot.FirstChild().ToElement();
    for( pElem; pElem; pElem=pElem->NextSiblingElement())
    {
        std::string pKey=pElem->Value();
        std::string pText=pElem->GetText();
        cFiles.push_back(pText);
    }

    logMsg(func + " end");

//    setCourtFiles(courtFile);
//    return true;
    return (cFiles);
}

courtStateSharedPtr loader::loadCourtFile(std::string fileName)  // loads data from the offense play XML files
{
    sharedPtr<conversion> convert = conversion::Instance();
    courtStateSharedPtr courtInstance(new courtState);
//    courtState *court = new courtState;
    std::string name;
    std::string modelName;
    float length = 0;
    float width = 0;
    float boundaryLength = 0;
    float boundaryWidth = 0;
    float boundaryXPos = 0;
    float boundaryZPos = 0;
    float centerCourt = 0;
    float centerJumpRadius = 0;
    float keyLength = 0;
    float keyWidth = 0;
    float keyJumpRadius = 0;
    float threePointSideLength = 0;
    float threePointSideZPos = 0;
    float threePointArcRadius = 0;
    float baselineInboundXPos = 0;
    float baselineInboundZPos = 0;
    float sidelineInboundXPos = 0;
    float sidelineInboundZPos = 0;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    char *contents = NULL;
    std::string func = "loader::loadCourtFile()";

    logMsg(func + " beginning");


    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
    
    doc.Parse(contents);
    if (doc.Error())
    {
/*        logMsg("Unable to parse court xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
*/
    }

    tinyxml2::XMLHandle hDoc(&doc);
    tinyxml2::XMLElement *rootElement;
    tinyxml2::XMLElement *child;
    tinyxml2::XMLHandle hRoot(0);

    rootElement = hDoc.FirstChildElement().ToElement();
    // should always have a valid root but handle gracefully if it does
    if (!rootElement)
    {
        logMsg("Unable to load court element");
        //exit(0);
    }

    child = rootElement->FirstChild()->ToElement();
    if (child)
    {
        std::string cKey = child->Value();
        if (cKey == "Name")
        {
            name = child->GetText();
//            logMsg("name = " +name);
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            modelName = child->GetText();
//            logMsg("modelName = " +modelName);
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            length = convert->toFloat(child->GetText());
//            logMsg("Length = " +convert->toString(length));
        } 
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            length = convert->toFloat(child->GetText());
//            logMsg("Width = " +convert->toString(width));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            boundaryLength = convert->toFloat(child->GetText());
//            logMsg("Boundary Length = " +convert->toString(boundaryLength));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            boundaryWidth = convert->toFloat(child->GetText());
//            logMsg("Boundary Width = " +convert->toString(boundaryWidth));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            boundaryXPos = convert->toFloat(child->GetText());
//            logMsg("Boundary X Pos = " +convert->toString(boundaryXPos));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            boundaryZPos = convert->toFloat(child->GetText());
//            logMsg("Boundary Z Pos = " +convert->toString(boundaryZPos));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            centerCourt = convert->toFloat(child->GetText());
//            logMsg("Center Court = " +convert->toString(centerCourt));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            centerJumpRadius = convert->toFloat(child->GetText());
//            logMsg("Center Jump Radius = " +convert->toString(centerJumpRadius));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            keyLength = convert->toFloat(child->GetText());
//            logMsg("Key Length = " +convert->toString(keyLength));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            keyWidth = convert->toFloat(child->GetText());
//            logMsg("Key Width = " +convert->toString(keyWidth));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            keyJumpRadius = convert->toFloat(child->GetText());
//            logMsg("Key Jump RAdius = " +convert->toString(keyJumpRadius));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            threePointSideLength = convert->toFloat(child->GetText());
//            logMsg("Three Point Side Length = " +convert->toString(threePointSideLength));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            threePointSideZPos = convert->toFloat(child->GetText());
//            logMsg("Three Point Side Z Pos = " +convert->toString(threePointSideZPos));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            threePointArcRadius = convert->toFloat(child->GetText());
//            logMsg("Three Point Arc Radius = " +convert->toString(threePointArcRadius));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            baselineInboundXPos = convert->toFloat(child->GetText());
//            logMsg("Baseline Inbound X Pos = " +convert->toString(baselineInboundXPos));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            baselineInboundZPos = convert->toFloat(child->GetText());
//            logMsg("Baseline Inbound Z Pos = " +convert->toString(baselineInboundZPos));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            sidelineInboundXPos = convert->toFloat(child->GetText());
//            logMsg("Sideline Inbound X Pos = " +convert->toString(sidelineInboundXPos));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            sidelineInboundZPos = convert->toFloat(child->GetText());
//            logMsg("Sideline Inbound Z Pos = " +convert->toString(sidelineInboundZPos));
        }
    }

    Ogre::Vector2 boundary = Ogre::Vector2(length,width);
    Ogre::Vector2 boundaryPos = Ogre::Vector2(boundaryXPos,boundaryZPos);
    Ogre::Vector2 keyDimensions = Ogre::Vector2(keyLength,keyWidth);
    Ogre::Vector2 baselineInboundPos = Ogre::Vector2(baselineInboundXPos,baselineInboundZPos);
    Ogre::Vector2 sidelineInboundPos = Ogre::Vector2(sidelineInboundXPos,sidelineInboundZPos);

    courtInstance->setName(name);
    courtInstance->setModelFileName(modelName);
    courtInstance->setBoundary(boundary);
    courtInstance->setBoundaryPos(boundaryPos);
    courtInstance->setCenterCourt(centerCourt);
    courtInstance->setCenterJumpRadius(centerJumpRadius);
    courtInstance->setKeyDimensions(keyDimensions);
    courtInstance->setKeyJumpRadius(keyJumpRadius);
    courtInstance->setThreePointSideLength(threePointSideLength);
    courtInstance->setThreePointZPos(threePointSideZPos);
    courtInstance->setThreePointArcRadius(threePointArcRadius);
    courtInstance->setBaselineInboundPos(baselineInboundPos);
    courtInstance->setSidelineInboundPos(sidelineInboundPos);

    logMsg(func + " end");
//    courtInstance = courtStateSharedPtr(court);
    return (courtInstance);
}

// Hoops
hoopStateUMSharedPtr  loader::loadHoops()  // load hoop XML files
{
//    exit(0);
    hoopStateUMSharedPtr  hoops;
    std::string hoopList;
    std::string func = "loader::loadHoops()";

    logMsg(func + " beginning");

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    hoopList = "data/hoops/hoops.xml";
#else
    hoopList = findFile("hoops/hoops.xml");
#endif
    hoopFiles = loadHoopListFile(hoopList);
    auto it = 0;
//    for (it = courtFiles.begin(); it != courtFiles.end(); ++it)
    for (it=0;it<hoopFiles.size();++it)
    {
//        logMsg("hoopFile = " +*it);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        hoops.insert(std::pair<size_t, hoopStateSharedPtr>(it, loadHoopFile("data/hoops/" + hoopFiles[it])));
#else
        hoops.insert(std::pair<size_t, hoopStateSharedPtr>(it, loadHoopFile(findFile("hoops/" + hoopFiles[it]))));
#endif
    }

    logMsg(func + " end");

    return (hoops);
}

stdStringVec loader::loadHoopListFile(std::string fileName)  // load the list of hoops from hoops.xml
{
    sharedPtr<conversion> convert = conversion::Instance();
//    sharedPtr<renderEngine> render = renderEngine::Instance();
    stdStringVec hFiles;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    std::string func = "loader::loadHoopListFile()";

    logMsg(func + " beginning");

    logMsg(func + " " +fileName);
    char *contents = NULL;
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
//    logMsg("fileContents = " +fileContents);

    doc.Parse(contents);
    if (doc.Error())
    {
/*        logMsg("Unable to parse courts.xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
*/
    }

    tinyxml2::XMLHandle hDoc(&doc);
    tinyxml2::XMLElement *pElem;
    tinyxml2::XMLHandle hRoot(0);

    pElem=hDoc.FirstChildElement().ToElement();
    // should always have a valid root but handle gracefully if it does
    if (!pElem)
    {
        logMsg("Unable to find a vlid court list root!");
    }

    // save this for later
    hRoot=tinyxml2::XMLHandle(pElem);

    pElem=hRoot.FirstChild().ToElement();
    for( pElem; pElem; pElem=pElem->NextSiblingElement())
    {
        std::string pKey=pElem->Value();
        std::string pText=pElem->GetText();
        hFiles.push_back(pText);
    }

    logMsg(func + " end");

//    setCourtFiles(courtFile);
//    return true;
    return (hFiles);
}

hoopStateSharedPtr loader::loadHoopFile(std::string fileName)  // loads data from the hoop XML files.
{
    sharedPtr<conversion> convert = conversion::Instance();
    sharedPtr<hoopState> hoopInstance(new hoopState);

//    basketballState *basketball = new basketballState;
    std::string name;
    std::string modelName;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    char *contents = NULL;
    std::string func = "loader::loadHoopFile()";

    logMsg(func +" beginning");

    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
    logMsg(func +" fileContents == " +fileContents);

    doc.Parse(fileContents.c_str(),fileContents.size());
    if (doc.Error())
    {
/*        logMsg(func +" Unable to parse court xml file");
        logMsg(func +" Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(func +" " +convert->toString(doc.GetErrorStr1()));
        logMsg(func +" " +convert->toString(doc.GetErrorStr2()));
        exit(0);
*/
    }

    tinyxml2::XMLHandle hDoc(&doc);
    tinyxml2::XMLElement *rootElement;
    tinyxml2::XMLElement *child;
    tinyxml2::XMLHandle hRoot(0);

    logMsg(func + " rootElement?");

    rootElement = hDoc.FirstChildElement().ToElement();

    logMsg(func + " rootElement!");
    logMsg(func + " rootElement = " + convert->toString(rootElement));

    // should always have a valid root but handle gracefully if it does
    if (!rootElement)
    {
        logMsg(func +" Unable to load basketball element");
        exit(0);
    }

    logMsg(func + " child?");
    child = rootElement->FirstChild()->ToElement();
    if (child)
    {
        std::string cKey = child->Value();
        if (cKey == "Name")
        {
            logMsg(func +"name!");
            name = child->GetText();
            logMsg(func +" name = " +name);
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            modelName = child->GetText();
            logMsg(func +" modelName = " +modelName);
        }
    }
    hoopInstance->setName(name);
//    hoopInstance->setModelFileName(modelName);
//    hoopInstance->setEntityName(name);
    hoopInstance->setEntityModelFileName(modelName);

    return (hoopInstance);
}
//Offense
offensePlaysVecSharedPtr loader::loadOffensePlays()  // load offense plays from XML files
{
    offensePlaysVecSharedPtr plays;
    std::string playList;
    
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    playList = "data/offense/plays/plays.xml";
#else
    playList = findFile("offense/plays/plays.xml");
#endif
    offensePlayFiles = loadOffensePlayListFile(playList);
//    stdStringVec playerFiles = load->getPlayerFiles();

    stdStringVec::iterator it;
    for (it = offensePlayFiles.begin(); it != offensePlayFiles.end(); ++it)
    {
        logMsg("offensePlayFile = " +*it);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        plays.push_back(loadOffensePlayFile("data/offense/plays/" + *it));
#else
        plays.push_back(loadOffensePlayFile(findFile("offense/plays/" + *it)));
#endif
    }
    return (plays);
}

stdStringVec loader::loadOffensePlayListFile(std::string fileName)  // loads the play list file
{
    sharedPtr<conversion> convert = conversion::Instance();
//    sharedPtr<renderEngine> render = renderEngine::Instance();

    stdStringVec playFiles;
    std::string func = "loader::loadOffensePlayListFile()";
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    logMsg(fileName);
    char *contents = NULL;
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);

    doc.Parse(contents);
/*    if (doc.Error())
    {
        logMsg(func +" Unable to parse teams.xml file");
        logMsg(func +" Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(func + " " +convert->toString(doc.GetErrorStr1()));
        logMsg(func + " " +convert->toString(doc.GetErrorStr2()));
        exit(0);

    }
*/
    tinyxml2::XMLHandle hDoc(&doc);

    tinyxml2::XMLElement *pElem;

    tinyxml2::XMLHandle hRoot(0);

    pElem=hDoc.FirstChildElement().ToElement();
    // should always have a valid root but handle gracefully if it does
    if (!pElem)
    {
        logMsg("Unable to find a valid offense play list file root!");
        exit(0);
    }
    
    // save this for later
    hRoot = tinyxml2::XMLHandle(pElem);
    pElem=hRoot.FirstChildElement().ToElement();
    for( pElem; pElem; pElem=pElem->NextSiblingElement())
    {
        std::string pKey=pElem->Value();
        std::string pText=pElem->GetText();
        playFiles.push_back(pText);
    }

//    setOffensePlayFiles(playFiles);
//    return true;
    return (playFiles);
}

sharedPtr<offensePlays> loader::loadOffensePlayFile(std::string fileName)  // loads data from the offense play XML files
{
    sharedPtr<conversion> convert = conversion::Instance();
    
    offensePlaysSharedPtr playInstance(new offensePlays);
//    offensePlays *play = new offensePlays;
    std::string playName;
    int variation;
    std::string title;
    playerPositionsVec playerPosition;
    stdStringVec type;
    std::vector<float> xCoord;
    std::vector<float> yCoord;
    std::vector<float> zCoord;
    OgreVector3Vec startCoords;
    std::vector< OgreVector3Vec > executeCoords;
    playerDirectivesVec playerDirective;

    // stores values read from XML files
    std::string pPlayName;
    int pVariation;
    std::string pTitle;
    std::string pPlayerPosition;
    std::string pType;
    float pXCoord;
    float pYCoord;
    float pZCoord;
    Ogre::Vector3 pCoords;
    OgreVector3Vec pExecuteCoords;
    offensePlays::playerDirectives pPlayerDirective;
    playerPositions pPlayerDirectivePosition;

    std::string fileContents;
    tinyxml2::XMLDocument doc;
    char *contents = NULL;
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);

    doc.Parse(contents);
    if (doc.Error())
    {
/*        logMsg("Unable to parse offense play file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
*/
    }

    tinyxml2::XMLHandle hDoc(&doc);

    tinyxml2::XMLElement *rootElement;

    tinyxml2::XMLElement *pElem;

    tinyxml2::XMLElement *child;

    tinyxml2::XMLNode *rootNode;

    tinyxml2::XMLNode *childNode;

    tinyxml2::XMLHandle hRoot(0);

    rootElement=hDoc.FirstChildElement().ToElement();

    // should always have a valid root but handle gracefully if it does
    if (!rootElement)
    {
        logMsg("Unable to load offense play element");
        exit(0);
    }

    child = rootElement->FirstChildElement()->ToElement();
    if (child)
    {
        std::string cKey = child->Value();
        if (cKey == "PlayName")
        {
            pPlayName = child->GetText();
//            logMsg("pPlayName = " +playName);
            playName = pPlayName;
        }
        child = child->NextSiblingElement()->ToElement();
    if (child)
        {
            pVariation = convert->toInt(child->GetText());
//            logMsg("pVariation = " +convert->toString(pVariation));
            variation = pVariation;
        } 
        child = child->NextSiblingElement()->ToElement(); 
    if (child)
        {
            pTitle = child->GetText();
//            logMsg("pTitle = " +pTitle);
            title = pTitle;
        }
        int numPlayers = 0;
        for (tinyxml2::XMLElement *e = child->NextSiblingElement(); e != NULL; e = e->NextSiblingElement())
        {
        tinyxml2::XMLElement *f;

//            logMsg ("nums = " +convert->toString(numPlayers));
            numPlayers += 1;
            f = e->FirstChildElement()->ToElement();
        if (f)
            {
                pPlayerPosition = f->GetText();
//                logMsg("name = " +pPlayerPosition);
//                playerName.push_back(pPlayerName);

                if (pPlayerPosition == "PG")
                {
                    playerPosition.push_back(PG);
                    pPlayerDirectivePosition = PG;
                }
                else if (pPlayerPosition == "SG")
                {
                    playerPosition.push_back(SG);
                    pPlayerDirectivePosition = SG;
                }
                else if (pPlayerPosition == "SF")
                {
                    playerPosition.push_back(SF);
                    pPlayerDirectivePosition = SF;
                }
                else if (pPlayerPosition == "PF")
                {
                    playerPosition.push_back(PF);
                    pPlayerDirectivePosition = PF;
                }
                else if (pPlayerPosition == "C")
                {
                    playerPosition.push_back(C);
                    pPlayerDirectivePosition = C;
                }
                else
                {

                }
            }
            f = f->NextSiblingElement()->ToElement();
            if (f)
            {
                int numPos = 0;
                pExecuteCoords.clear();  // clears the vector for each player
                for (tinyxml2::XMLElement *g = f->FirstChildElement(); g != NULL; g = g->NextSiblingElement())
                {
//                    logMsg("numPos = " +convert->toString(numPos));
                    numPos += 1;
                   tinyxml2::XMLElement *h;

                    h = g->FirstChildElement()->ToElement();
                    if (h)
                    {
                        pType = h->GetText();
//                        logMsg("pType = " +pType);
                        type.push_back(pType);
                    }
                    h = h->NextSiblingElement()->ToElement();
                    if (h)
                    {
                        pXCoord = convert->toFloat(h->GetText());
//                        logMsg("pXCoord = " +convert->toString(pXCoord));
                        xCoord.push_back(pXCoord);
                    }
                    h = h->NextSiblingElement()->ToElement();
                    if (h)
                    {
                        pYCoord = convert->toFloat(h->GetText());
//                        logMsg("pYCoord = " +convert->toString(pYCoord));
                        yCoord.push_back(pYCoord);
                    }
                    h = h->NextSiblingElement()->ToElement();
                    if (h)
                    {
                        pZCoord = convert->toFloat(h->GetText());
//                        logMsg("pZCoord = " +convert->toString(pZCoord));
                        zCoord.push_back(pZCoord);
                    }

                    pCoords.x = pXCoord;
                    pCoords.y = pYCoord;
                    pCoords.z = pZCoord;

                    if (pType == "Start")
                    {
                        startCoords.push_back(pCoords);
                    }
                    else
                    {
                        pExecuteCoords.push_back(pCoords);
//                        logMsg("pExecuteCoords.size = " +convert->toString(pExecuteCoords.size()));
                    }
                }
                // checks if there are execute coords and puts them in the vector
                if (pExecuteCoords.size() > 0)
                {
                    executeCoords.push_back(pExecuteCoords);
                }
            }
            f = f->NextSiblingElement()->ToElement();
            if (f)
            {
                int numDirectives = 0;
                for (tinyxml2::XMLElement *g = f->FirstChildElement(); g != NULL; g = g->NextSiblingElement())
                {
                    numDirectives += 1;
                    tinyxml2::XMLElement *h;
                    pPlayerDirective.setPlayerPosition(pPlayerDirectivePosition);
                    h = g->FirstChildElement()->ToElement();
                    if (h)
                    {
                        std::string hKey = h->GetText();
//                        logMsg("hKey = " +hKey);
                        if (hKey == "Wait")
                        {
                            pPlayerDirective.setType(WAIT);
                            h = h->NextSiblingElement()->ToElement();
                            if (h)
                            {
//                                logMsg("WaitFor");
                                hKey = h->GetText();
                                if (hKey == "PlayerPositionSet")
                                {
                                    pPlayerDirective.setWaitFor(PLAYERPOSITIONSET);
//                                    logMsg("PlayerPositionSet");

                                    h = h->NextSiblingElement()->ToElement();
                                    if (h)
                                    {
                                        hKey = h->GetText();
//                                        logMsg("PlayerSet = " +hKey);

                                        if (hKey == "PG")
                                        {
                                            pPlayerDirective.setPlayerSet(PG);
                                        }
                                        if (hKey == "SG")
                                        {
                                            pPlayerDirective.setPlayerSet(SG);
                                        }
                                        if (hKey == "SF")
                                        {
                                            pPlayerDirective.setPlayerSet(SF);
                                        }
                                        if (hKey == "PF")
                                        {
                                            pPlayerDirective.setPlayerSet(PF);
                                        }
                                        if (hKey == "C")
                                        {
                                            pPlayerDirective.setPlayerSet(C);
                                        }
                                    }
                                    h = h->NextSiblingElement()->ToElement();
                                    if (h)
                                    {
//                                        logMsg("PositionType");
                                        hKey = h->GetText();
                                        if (hKey == "Start")
                                        {
//                                            logMsg("Start");
                                            pPlayerDirective.setPositionType(START);
                                        }
                                        else if (hKey == "Execute")
                                        {
//                                            logMsg("Execute");
                                            pPlayerDirective.setPositionType(EXECUTE);

                                            h = h->NextSiblingElement("Position");
                                            if (h)
                                            {
//                                                logMsg("Position");
                                                hKey = h->GetText();
                                                pPlayerDirective.setPosition(convert->toInt(hKey.c_str()));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                playerDirective.push_back(pPlayerDirective);
//                logMsg("numDirectives = " +convert->toString(numDirectives));
            }
        }
    }

    playInstance->setPlayName(playName);
    playInstance->setVariation(variation);
    playInstance->setTitle(title);
    playInstance->setPlayerPosition(playerPosition);
    playInstance->setStartPositions(startCoords);
    playInstance->setExecutePositions(executeCoords);
    playInstance->setPlayerDirective(playerDirective);
    
//    playInstance = sharedPtr<offensePlays>(play);
    return (playInstance);
}

playerStateUMSharedPtr loader::loadPlayers()  // loads the players
{
    sharedPtr<conversion> convert = conversion::Instance();

    playerStateUMSharedPtr players;
    playerStateSharedPtr playerInstance; //(new playerState);
    std::string func = "loader::loadPlayers()";

    playerStateSharedPtr player;//(new playerState);
    std::string playerList;
    
    logMsg(func +" beginning");

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    playerList = "data/players/players.xml";
#else
    playerList = findFile("players/players.xml");
#endif
    playerFiles = loadPlayerListFile(playerList);
//    stdStringVec playerFiles = load->getPlayerFiles();

//    stdStringVec::iterator it;
//    for (it = playerFiles.begin(); it != playerFiles.end(); ++it)
    for (size_t it=0;it<playerFiles.size();++it)
    {
        logMsg(func +" it == " +convert->toString(it));
        logMsg("playerFile = " +playerFiles[it]);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//        playerInstance = loadPlayerFile("data/players/" + playerFiles[it]);
        players.insert(std::pair<size_t, playerStateSharedPtr>(it, loadPlayerFile("data/players/" + playerFiles[it])));
//        players.emplace(it, loadPlayerFile(findFile("data/players/" + playerFiles[it])));

#else
//        players.emplace(it, loadPlayerFile(findFile("players/" + playerFiles[it]));

        
        players.insert(std::pair<size_t, playerStateSharedPtr>(it, loadPlayerFile(findFile("players/" + playerFiles[it]))));

#endif 
        logMsg(func +" Player " +players[it]->getData()->getFirstName() +" " +players[it]->getData()->getLastName() +" TeamID == " +convert->toString(players[it]->getData()->getTeamID()));

//    exit(0);
    }
    
//    exit(0);
    
    for (auto PIIT : players)
    {
        logMsg(func +" Player " +PIIT.second->getData()->getFirstName() +" " +PIIT.second->getData()->getLastName() +" TeamID == " +convert->toString(PIIT.second->getData()->getTeamID()));
    }
    logMsg("players.size() == " +convert->toString(players.size()));
//    exit(0);
    logMsg(func +" end");
    return (players);
}

stdStringVec loader::loadPlayerListFile(std::string fileName)  // loads the player list file
{
    sharedPtr<conversion> convert = conversion::Instance();
  //   sharedPtr<renderEngine> render = renderEngine::Instance();
    stdStringVec pFiles;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    logMsg(fileName);
    char *contents = NULL;
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);

    doc.Parse(contents);
    if (doc.Error())
    {
/*        logMsg("Unable to parse teams.xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
*/
    }
    tinyxml2::XMLHandle hDoc(&doc);

    tinyxml2::XMLElement *pElem;
    
    tinyxml2::XMLHandle hRoot(0);

    pElem=hDoc.FirstChildElement().ToElement();
    // should always have a valid root but handle gracefully if it does
//    if (!pElem) return(false);

    // save this for later
    hRoot = tinyxml2::XMLHandle(pElem);

    pElem=hRoot.FirstChild().ToElement();
    for( pElem; pElem; pElem=pElem->NextSiblingElement())
    {
        std::string pKey=pElem->Value();
//        cout << pKey << endl;
        std::string pText=pElem->GetText();
        logMsg("pText == " +pText);
//        cout << pText << endl;
        pFiles.push_back(pText);
    }

/*    stdStringVec::iterator it;
    for (it = playerFiles.begin(); it != playerFiles.end(); ++it)
    {
        cout << *it << endl;
    }
    */

//    setPlayerFiles(playerFiles);
//    return true;
    return (pFiles);
}

playerStateSharedPtr loader::loadPlayerFile(std::string fileName)  // loads the player file
{
    sharedPtr<conversion> convert = conversion::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
//    sharedPtr<renderEngine> render = renderEngine::Instance();
    std::string func = "loader::loadPlayerFile()";
    playerStateSharedPtr playerInstance(new playerState);
    std::string firstName;
    std::string lastName;
    std::string modelName;
    playerPositions primaryPosition;
    playerPositions secondaryPosition;
    int ID = 0;
    int teamID = 0;
    int age = 0;
    int height = 0;
    int weight = 0;
    int shooting = 0;
    int freeThrow = 0;
    int layup = 0;
    int dunk = 0;
    int inside = 0;
    int midRange = 0;
    int threePoint = 0;
    int ballHandling = 0;
    int ballSecurity = 0;
    int passing = 0;
    int pickSetting = 0;
    int offenseAwareness = 0;
    int defenseAwareness = 0;
    int offenseRebound = 0;
    int defenseRebound = 0;   
    int blocking = 0;
    int stealing = 0;
    int interiorDefense = 0;
    int midRangeDefense = 0;
    int perimeterDefense = 0;
    int hustle = 0;
    int speed = 0;
    int quickness = 0;
    int fatigue = 0;
    int durability = 0;
    int demeanor = 0;
    int improvability = 0;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    char *contents = NULL;
    
    logMsg(func +" beginning");
    readFile(fileName.c_str(), &contents);   
    logMsg(func +" loading: "+fileName);
    fileContents = convert->toString(contents);
//    logMsg("fileContents = " +fileContents);
    
    doc.Parse(contents);
    if (doc.Error())
    { 
///        logMsg("Unable to parse player file");
///        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
///        logMsg(convert->toString(doc.GetErrorStr1()));
///        logMsg(convert->toString(doc.GetErrorStr2()));
///        exit(0);
    }
    tinyxml2::XMLHandle hDoc(&doc);
    
    tinyxml2::XMLElement *pElem;
    tinyxml2::XMLElement *rootElement;
    tinyxml2::XMLElement *childElement;

    tinyxml2::XMLHandle hRoot(0);

    pElem=hDoc.FirstChildElement().ToElement();
    // should always have a valid root but handle gracefully if it does
    if (!pElem)
    {
        logMsg(func +" Unable to find a valid player file root!");
        exit(0);
    }

    hRoot = tinyxml2::XMLHandle(pElem);

    pElem=hRoot.FirstChild().ToElement();
    if(pElem)
    {
        ID = convert->toInt(pElem->GetText());
//        logMsg("PlayerID == " +convert->toString(ID));
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        teamID = convert->toInt(pElem->GetText());
//        logMsg("teamID == " +convert->toString(teamID));
    }
//    logMsg("pElem.Name() = " +convert->toString(pElem->GetText()));
    pElem=pElem->NextSiblingElement()->ToElement();
    if(pElem)
    {
        childElement=pElem->FirstChildElement()->ToElement();
        std::string pKey=childElement->Value();
        if (pKey == "First")
        {
            firstName = childElement->GetText();
//            logMsg("First Name: " +firstName);
//            exit(0);
        }
        childElement=childElement->NextSiblingElement()->ToElement();
        pKey=childElement->Value();
        if (pKey == "Last")
        {
            lastName = childElement->GetText();
//            logMsg("Last Name: " +lastName);
        }

    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        age = convert->toInt(pElem->GetText());
//        logMsg("Age = " +convert->toString(age));
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        height = convert->toInt(pElem->GetText());
//        logMsg("Height = " +convert->toString(height));
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        weight = convert->toInt(pElem->GetText());
//        logMsg("Weight = " +convert->toString(weight));
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        modelName = pElem->GetText();
//        logMsg("Model = " +modelName);
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        std::string position = pElem->GetText();
        if (position == "PG")
        {
            primaryPosition = PG;
        }
        else if (position == "SG")
        {
            primaryPosition = SG;
        }
        else if (position == "SF")
        {
            primaryPosition = SF;
        }
        else if (position == "PF")
        {
            primaryPosition = PF;
        }
        else if (position == "C")
        {
            primaryPosition = C;
        }
        else if (position == "NONE")
        {
            primaryPosition = NONE;
        }
        else
        {
            primaryPosition = NONE;
        }
//        logMsg("primaryPosition = " +position);
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        std::string position = pElem->GetText();
        if (position == "PG")
        {
            secondaryPosition = PG;
        }
        else if (position == "SG")
        {
            secondaryPosition = SG;
        }
        else if (position == "SF")
        {
            secondaryPosition = SF;
        }
        else if (position == "PF")
        {
            secondaryPosition = PF;
        }
        else if (position == "C")
        {
            secondaryPosition = C;
        }
        else if (position == "NONE")
        {
            secondaryPosition = NONE;
        }
        else
        {
            secondaryPosition = NONE;
        }
//        logMsg("secondaryPosition = " +position);
    }
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        shooting = convert->toInt(pElem->GetText());
//        logMsg("shooting = " +convert->toString(shooting));
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        freeThrow = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        layup = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        dunk = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        inside = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        midRange = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        threePoint = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        ballHandling = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        ballSecurity = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        passing = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        pickSetting = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        offenseAwareness = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        defenseAwareness = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        offenseRebound = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        defenseRebound = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        blocking = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        stealing = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        interiorDefense = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        midRangeDefense = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        perimeterDefense = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        hustle = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        speed = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        quickness = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        fatigue = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        durability = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        demeanor = convert->toInt(pElem->GetText());
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        improvability = convert->toInt(pElem->GetText());
    }
//    sharedPtr<playerEntity> tempPEnt(new playerEntity);
//    playerInstance->setPlayerEnt(tempPEnt);
    logMsg(func +" name == " +firstName +" " +lastName);

    playerInstance->setup();
    if (firstName == "Xavier")
    {
        if (playerInstance->getPlayerEnt()->getInitialized())
        {
            logMsg(func +" " +firstName +" " +lastName + " playerEnt Initialized!");
        }
        else
        {
            logMsg(func +" " +firstName +" " +lastName + " playerEnt NOT Initialized!");
        }
//        exit(0);
    }
    
    playerInstance->getData()->setFirstName(firstName);
//    exit(0);
    
    playerInstance->getData()->setLastName(lastName);
    playerInstance->getData()->setPlayerName(firstName +" " +lastName);
    playerInstance->getData()->setAge(age);
    playerInstance->getData()->setHeight(height);
    playerInstance->getData()->setWeight(weight);
    playerInstance->getData()->setID(ID);
    playerInstance->getData()->setTeamID(teamID);
    playerInstance->getPlayerEnt()->setEntityName(firstName + lastName);
    playerInstance->getPlayerEnt()->setEntityModelFileName(modelName);
    playerInstance->getData()->setPrimaryPosition(primaryPosition);
    playerInstance->getData()->setSecondaryPosition(secondaryPosition);
    playerInstance->getData()->setShooting(shooting);
    playerInstance->getData()->setFreeThrow(freeThrow);
    playerInstance->getData()->setLayup(layup);
    playerInstance->getData()->setDunk(dunk);
    playerInstance->getData()->setInside(inside);
    playerInstance->getData()->setMidRange(midRange);
    playerInstance->getData()->setThreePoint(threePoint);
    playerInstance->getData()->setBallHandling(ballHandling);
    playerInstance->getData()->setBallSecurity(ballSecurity);
    playerInstance->getData()->setPassing(passing);
    playerInstance->getData()->setPickSetting(pickSetting);
    playerInstance->getData()->setOffenseAwareness(offenseAwareness);
    playerInstance->getData()->setDefenseAwareness(defenseAwareness);
    playerInstance->getData()->setOffenseRebound(offenseRebound);
    playerInstance->getData()->setDefenseRebound(defenseRebound);
    playerInstance->getData()->setBlocking(blocking);
    playerInstance->getData()->setStealing(stealing);
    playerInstance->getData()->setInteriorDefense(interiorDefense);
    playerInstance->getData()->setMidRangeDefense(midRangeDefense);
    playerInstance->getData()->setPerimeterDefense(perimeterDefense);
    playerInstance->getData()->setHustle(hustle);
    playerInstance->getData()->setSpeed(speed);
    playerInstance->getData()->setQuickness(quickness);
    playerInstance->getData()->setFatigue(fatigue);
    playerInstance->getData()->setDurability(durability);
    playerInstance->getData()->setDemeanor(demeanor);
    playerInstance->getData()->setImprovability(improvability);
    playerInstance->getData()->calculateOverallRating();

//    playerInstance = playerStateSharedPtr(player);
    logMsg(func +" player Name == "+playerInstance->getData()->getFirstName() + " " +playerInstance->getData()->getLastName() +" TeamID == " +convert->toString(playerInstance->getData()->getTeamID()));
//    exit(0);
    
    logMsg(func +" end");
    
    return (playerInstance);
}

std::unordered_map<size_t, teamStateSharedPtr> loader::loadTeams()  // load teams from XML files
{
    sharedPtr<conversion> convert = conversion::Instance();
    teamStateUMSharedPtr teams;

    std::string teamList;
    std::string func = "loader::loadTeams";
    
    logMsg(func +" beginning");

//    teamStateSharedPtr tempTeamSharedPtr(new teamState);
    
/*    teamState *tempTeamObj = new teamState;
    teamStateSharedPtr tempTeamSharedPtr = teamStateSharedPtr(tempTeamObj);
    teamStateVecSharedPtr tempTeams;
    tempTeams.push_back(tempTeamSharedPtr);
*/


    //teams = tempTeams;
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    teamList = "data/teams/teams.xml";
#else
    teamList = findFile("teams/teams.xml");
#endif

//    exit(0);
//    logMsg("Bleeep!");
    teamFiles = loadTeamListFile(teamList);
//    stdStringVec playerFiles = load->getPlayerFiles();
    logMsg("teamFiles.size() = " +convert->toString(teamFiles.size()));

//    exit(0);
//    stdStringVec::iterator it;

    auto it = 0;
//    for (it = teamFiles.begin(); it != teamFiles.end(); ++it)
    for (it=0;it<teamFiles.size();++it)
    {
//        logMsg("teamFile = " +*it);

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//        teams.push_back(loadTeamFile("data/teams/" + *it));
//          loadTeamFile("data/teams/" + *it);
        teams.insert(std::pair<size_t, teamStateSharedPtr>(it, loadTeamFile("data/teams/" + teamFiles[it])));

#else
//        teams.push_back(loadTeamFile(findFile("teams/" + *it)));
//          loadTeamFile(findFile("teams/" + *it));
        teams.insert(std::pair<size_t, teamStateSharedPtr>(it, loadTeamFile(findFile("teams/" + teamFiles[it]))));

#endif
    }
//    exit(0);
//    logMsg("teams[0]->getID() ID == " +convert->toString(teams[0]->getID()));
//    exit(0);
//    logMsg("loadTeams() 4 ID == " +convert->toString(teams[4]->getID()));
//    logMsg("loadTeams() 4 Name == " +tInstance[4]->getName());
    for (auto TIIT : teams)
    {
        logMsg(func +" Team == " +TIIT.second->getCity() +" " +TIIT.second->getName());
    }
    logMsg("loadTeams() teams.size() == " +convert->toString(teams.size()));
//    exit(0);
    logMsg("dah");
//    exit(0);
    if (teams.size() == 0)
    {
        logMsg("teams.size() == " +teams.size());
//        exit(0);
    }
    
    logMsg(func +" end");
    
    return (teams);
}

stdStringVec loader::loadTeamListFile(std::string fileName)  // loads the team list file
{
    sharedPtr<conversion> convert = conversion::Instance();
//    sharedPtr<renderEngine> render = renderEngine::Instance();

    stdStringVec teamName;
    stdStringVec files;

//	players::playerData player;
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//    const char *file = "teams.xml";
//#else
//	const char *file = fileName.c_str();
//#endif 

//	char *fileContents = NULL;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    std::string func = "loader::loadTeamListFile";
    
    logMsg(func +" beginning");

    
    logMsg(fileName);
    logMsg("bate");
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//	Ogre::DataStreamPtr fileData = render->openAPKFile(fileName);
//	fileContents = fileData->getAsString();
//#else
    char *contents = NULL;
    readFile(fileName.c_str(), &contents);
//	logMsg("read contents = " +contents);
//	exit(0);
    fileContents = convert->toString(contents);
//#endif
//    readFile(fileName.c_str(), &fileContents);
//    logMsg("barf");
//    logMsg("fileContents == " +fileContents);
    static const char* xml = "<element/>";
    doc.Parse(contents);
    if (doc.Error())
    {
/*        logMsg("Unable to parse teams.xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
*/
    }
    tinyxml2::XMLHandle hDoc(&doc);
    tinyxml2::XMLElement *pElem;
    tinyxml2::XMLHandle hRoot(0);
    //tinyxml2::XMLText *textNode = doc.FirstChildElement("Teams")->FirstChildElement("TeamFile")->ToText();
    //logMsg("first element = " +convert->toString(textNode->Value()));
    pElem=hDoc.FirstChildElement().ToElement();
    // should always have a valid root but handle gracefully if it does
    if (!pElem)
    {
        logMsg("Unable to find a valid teamListFile root!");
        exit(0);
    } 

    // save this for later
    //hRoot=TiXmlHandle(pElem);
    hRoot = tinyxml2::XMLHandle(pElem);
    
    //pElem=hRoot.FirstChild("TeamFile").Element();
    pElem=hRoot.FirstChild().ToElement();
    
    for( pElem; pElem; pElem=pElem->NextSiblingElement())
    {
//      string pText=pElem->GetText();
        files.push_back(pElem->GetText());
        logMsg("teamFile = " +convert->toString(pElem->GetText()));
    }

    stdStringVec::iterator it;
    for (it = files.begin(); it != files.end(); ++it)
    {
        logMsg("team file = " +*it);
    }

    logMsg("files.size() = " +convert->toString(files.size()));
//    teamFiles = files;  // sets teamFiles = to the std::vector data in files

//    setTeamFiles(teamFiles);

    logMsg(func +" end");
//    return true;
    return (files);
}

teamStateSharedPtr loader::loadTeamFile(std::string fileName)  // loads the team file
{
    sharedPtr<conversion> convert = conversion::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
//    sharedPtr<renderEngine> render = renderEngine::Instance();
//    teamStateVecSharedPtr teamInstance = gameS->getTeamInstance();
  
    teamStateSharedPtr teamInstance(new teamState);
//    tInstance = teamStateSharedPtr(new teamState);
//    teamInstance.reset(new teamState);
//    teamState tempTeam; // = new teamState;
//    teamState *tempInst = new teamState;
//    tempTeamObj = new teamState;
//    tInstance = tempInstance;
    static size_t ID;
    std::string City;
    std::string Name;
    std::string Coach;
    std::string Initials;
    std::string Logo;

//    TiXmlDocument doc(fileName.c_str());
//    if (!doc.LoadFile()) return(false);
//	const char *fileContents = NULL;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    char *contents = NULL;
    std::string func = "loader::loadTeamFile";
    
    logMsg(func +" beginning");
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
    doc.Parse(contents);
    if (doc.Error())
    {
/*        logMsg("Unable to parse team file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
*/
    }
    tinyxml2::XMLHandle hDoc(&doc);
    tinyxml2::XMLElement *pElem;
    
    tinyxml2::XMLHandle hRoot(0);
    
    pElem=hDoc.FirstChildElement().ToElement();
    
    // should always have a valid root but handle gracefully if it does
    if (!pElem)
    {
        logMsg("Unable to find valid root. Exiting!");
        exit(0);
    } 

    // save this for later
    hRoot = tinyxml2::XMLHandle(pElem);
    
    pElem=hRoot.FirstChild().ToElement();
    if (pElem)
    {
        ID = convert->toInt(pElem->GetText());
//        logMsg("Team ID == " +convert->toString(ID));
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        City = pElem->GetText();
//        logMsg("City == " +City);
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        Name = pElem->GetText();
//        logMsg("Name == " +Name);
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        Coach = pElem->GetText();
//        logMsg("Coach == " +Coach);
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        Initials = pElem->GetText();
//        logMsg("Initials == " +Initials);
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        Logo = pElem->GetText();
//        logMsg("Logo == " +Logo);
    }
     
//    logMsg("ID == " +convert->toString(ID));
//    exit(0);
    teamInstance->setID(ID);
    teamInstance->setCity(City);
    teamInstance->setName(Name);
    teamInstance->setCoach(Coach);
    teamInstance->setInits(Initials);
    teamInstance->setLogoFile(Logo);
//    logMsg("ID == " +convert->toString(ID));
//    logMsg("Load Teaminstance ID == " +convert->toString(teamInstance->getID()));
    logMsg("teamInstance->getID() == " +convert->toString(teamInstance->getID()));
//    tempInst = &tempTeam;
//    logMsg("Load Teaminstance Name == " +teamInstance->getName());
//    logMsg("lawwl");
//    tInstance.push_back(teamInstance);
//    team->setTeamArray(teamInstance);
//   teamInstance.push_back(teamInstance);
//   gameS->setteamInstance(teamInstance);
//,    exit(0);

    logMsg(func +" end");

    return (teamInstance);
}

// User input
userInputVecSharedPtr loader::loadUserInputs()  // load user input settings from XML files
{
    userInputVecSharedPtr userInputs;
    std::string userInputList;
    std::string func = "loader::loadUserInputs()";

    logMsg(func +" beginning");

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    userInputList = "data/users/inputlist.xml";
#else
    userInputList = findFile("users/inputlist.xml");
#endif
//    exit(0);
    userInputFiles = loadUserInputListFile(userInputList);
//    stdStringVec playerFiles = load->getPlayerFiles();
//    exit(0);
    stdStringVec::iterator it;
    for (it = userInputFiles.begin(); it != userInputFiles.end(); ++it)
    {
        logMsg(func +" userInputFile = " +*it);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        userInputs.push_back(loadUserInputFile("data/users/" + *it));
#else
        userInputs.push_back(loadUserInputFile(findFile("users/" + *it)));
#endif
    }

    logMsg(func +" end");
    return (userInputs);
}

stdStringVec loader::loadUserInputListFile(std::string fileName)  // loads the user input list file
{
    sharedPtr<conversion> convert = conversion::Instance();
//    sharedPtr<renderEngine> render = renderEngine::Instance();
    stdStringVec uInputFiles;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    std::string func = "loader::loadUserInputListFile()";

    logMsg(func +" beginning");

    logMsg(func + " " +fileName);
    char *contents = NULL;
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
    
    doc.Parse(contents);
    if (doc.Error())
    {
/*        logMsg("Unable to parse inputlist.xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
*/
    }
    
    
    tinyxml2::XMLHandle hDoc(&doc);
    tinyxml2::XMLElement *pElem;
    tinyxml2::XMLHandle hRoot(0);

    pElem=hDoc.FirstChildElement().ToElement();
    
    // should always have a valid root but handle gracefully if it does
    if (!pElem)
    {
        logMsg(func +" Unable to find avalid root for user input list file!");
    } 
    
    // save this for later
    hRoot=tinyxml2::XMLHandle(pElem);

    pElem=hRoot.FirstChild().ToElement();
    for( pElem; pElem; pElem=pElem->NextSiblingElement())
    {
        std::string pKey=pElem->Value();
        logMsg(func +" pKey == " +pKey);
	    std::string pText=pElem->GetText();
        logMsg(func +" pText == " +pText);
        uInputFiles.push_back(pText);
    }
    logMsg(func +" uInputFiles.size() == " +convert->toString(uInputFiles.size()));
//    exit(0);
//    setUserInputFiles(userInputFile);
//    return true;

    logMsg(func +" end");
    return (uInputFiles);
}

sharedPtr<userInput> loader::loadUserInputFile(std::string fileName)  // loads data from the user input files
{
    sharedPtr<conversion> convert = conversion::Instance();
    sharedPtr<userInput> uInput(new userInput);
    std::string inputName;
    std::string type;
    std::string up;
    std::string down;
    std::string left;
    std::string right;
    std::string upLeft;
    std::string upRight;
    std::string downLeft;
    std::string downRight;
    std::string shootBlock;
    std::string passSteal;
    std::string pause;
    std::string startSelect;
    std::string quit;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    char *contents = NULL;
    std::string func = "loader::loadUserInputFile()";

    logMsg(func +" beginning");
    logMsg(func +" Load UserInput File");
   
    readFile(fileName.c_str(), &contents);
    logMsg(func +" readFile successful!");

    fileContents = convert->toString(contents);
    logMsg(func +" fileContents = " +fileContents);

    doc.Parse(contents);
    if (doc.Error())
    {
        logMsg(func +" Unable to parse user input file");
/*        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
*/
  }
    
    tinyxml2::XMLHandle hDoc(&doc);
    tinyxml2::XMLElement *rootElement;
    tinyxml2::XMLElement *child;
    tinyxml2::XMLElement *nextChild;
    tinyxml2::XMLHandle hRoot(0);

    logMsg(func +" rootElement=hDoc.FirstChildElement().ToElement()");

    rootElement=hDoc.FirstChildElement().ToElement();   
    // should always have a valid root but handle gracefully if it does
    if (!rootElement)
    {
        logMsg(func +" Unable to load user input element");
        exit(0);
    }

    logMsg(func +" child = rootElement->FirstChild()->ToElement()");

    child = rootElement->FirstChild()->ToElement();
    if (child)
    {
        std::string cKey = child->Value();
        logMsg(func +" if (cKey == 'Name')");
        if (cKey == "Name")
        {
            inputName = child->GetText();
//            logMsg("name = " +inputName);
        }
        
        bool inputTag = false;
        logMsg(func +"while (!inputTag)");
        while (!inputTag)
        {
            logMsg(func +" child = child->NextSiblingElement()->ToElement()");
            child = child->NextSiblingElement()->ToElement();
            if (child)
            {
                logMsg(func +" nextChild = child->FirstChildElement()->ToElement()");
                nextChild = child->FirstChildElement()->ToElement();
                inputTag = true;
                logMsg(func +" for( nextChild; nextChild; nextChild=nextChild->NextSiblingElement())");
                for( nextChild; nextChild; nextChild=nextChild->NextSiblingElement())
                {
                    std::string pKey=nextChild->Value();
//                    logMsg("pKey = " +pKey);
//                    exit(0);
                    if (pKey == "Type")
                    {
                        type = nextChild->GetText();
//                        logMsg("type = " +type);
//                        exit(0);
                    }
                    if (pKey == "Up")
                    {
                        up = nextChild->GetText();
//                        logMsg("up = " +up);

                    }
                    if (pKey == "Down")
                    {
                        down = nextChild->GetText();
                    }
                    if (pKey == "Left")
                    {
                        left = nextChild->GetText();
                    }
                    if (pKey == "Right")
                    {
                        right = nextChild->GetText();
                    }
                    if (pKey == "UpLeft")
                    {
                        upLeft = nextChild->GetText();
                    }
                    if (pKey == "UpRight")
                    {
                        upRight = nextChild->GetText();
                    }
                    if (pKey == "DownLeft")
                    {
                        downLeft = nextChild->GetText();
                    }
                    if (pKey == "DownRight")
                    {
                        downRight = nextChild->GetText();
                    }
                    if (pKey == "ShootBlock")
                    {
                        shootBlock = nextChild->GetText();
                    }
                    if (pKey == "PassSteal")
                    {
                        passSteal = nextChild->GetText();
                    }
                    if (pKey == "Pause")
                    {
                        pause = nextChild->GetText();
                    }
                    if (pKey == "StartSelect")
                    {
                        startSelect = nextChild->GetText();
//                        exit(0);
                    }
                    if (pKey == "Quit")
                    {
                        quit = nextChild->GetText();
//                        exit(0);
                    }
                }
            }
            else
            {
                inputTag = false;
            }
//            modelName = child->GetText();
//            logMsg("modelName = " +modelName);
            if (type == "Keyboard")
            {
                uInput->setKeyUp(convert->toInputKey(up));
                uInput->setKeyDown(convert->toInputKey(down));
                uInput->setKeyLeft(convert->toInputKey(left));
                uInput->setKeyRight(convert->toInputKey(right));
                uInput->setKeyUpLeft(convert->toInputKey(upLeft));
                uInput->setKeyUpRight(convert->toInputKey(upRight));
                uInput->setKeyDownLeft(convert->toInputKey(downLeft));
                uInput->setKeyDownRight(convert->toInputKey(downRight));
                uInput->setKeyShootBlock(convert->toInputKey(shootBlock));
                uInput->setKeyPassSteal(convert->toInputKey(passSteal));
                uInput->setKeyPause(convert->toInputKey(pause));
                uInput->setKeyStartSelect(convert->toInputKey(startSelect));
                uInput->setKeyQuit(convert->toInputKey(quit));
            }
            else if (type == "Joystick" || type == "Gamepad")
            {
                // FIXME! mapping needs to be implemented
/*                uInput->setGPUp(up);
                uInput->setGPDown(down);
                uInput->setGPLeft(left);
                uInput->setGPRight(right);
                uInput->setGPUpLeft(upLeft);
                uInput->setGPUpRight(upRight);
                uInput->setGPDownLeft(downLeft);
                uInput->setGPDownRight(downRight);
                uInput->setGPShootBlock(shootBlock);
                uInput->setGPPassSteal(passSteal);
                uInput->setGPPause(pause);
                uInput->setGPStartSelect(startSelect);
*/
            }
            else
            {
            }
        }
    }

    logMsg(func +" end");

    return (uInput);
}
