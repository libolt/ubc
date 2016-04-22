/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean                              *
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
#include "state/basketballstate.h"
#include "state/courtstate.h"
#include "state/hoopstate.h"
//#include "state/gamestate.h"
#include "state/playerstate.h"
#include "state/teamstate.h"
#include "offenseplays.h"
#include "userinput.h"

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
#include "android.h"
#endif


loader::loader()  // constructor
{

//        pathArray = pathSplit(dataPath);
//      cout << pathArray[2] << endl;
//      exit(0);
}


boost::shared_ptr<loader> loader::pInstance;

boost::shared_ptr<loader> loader::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        boost::shared_ptr<loader> tInstance(new loader);
        pInstance = tInstance;

    }
    return pInstance; // address of sole instance
}

std::vector<std::string> loader::getPlayerFiles()  // retrieves the value of playerFiles
{
    return(playerFiles);
}
void loader::setPlayerFiles(std::vector<std::string> set)  // sets the value of playerFiles
{
    playerFiles = set;
}

std::vector<std::string> loader::getTeamFiles()  // retrieves the value of teamFiles
{
    return(teamFiles);
}
void loader::setTeamFiles(std::vector<std::string> set)  // sets the value of teamFiles
{
    teamFiles = set;
}

std::vector<std::string> loader::getOffensePlayFiles()  // retrieves the value of offensePlayFiles
{
    return (offensePlayFiles);
}
void loader::setOffensePlayFiles(std::vector<std::string> set)  // sets the value of offensePlayFiles
{
    offensePlayFiles = set;
}

std::vector<std::string> loader::getBasketballFiles()  // retrieves the value of basketballFiles
{
    return (basketballFiles);
}
void loader::setBasketballFiles(std::vector<std::string> set)  // sets the value of basketballFiles
{
    basketballFiles = set;
}

std::vector<std::string> loader::getCourtFiles()   // retrieves the value of courtFiles
{
    return (courtFiles);
}
void loader::setCourtFiles(std::vector<std::string> set)  // sets the value of courtFiles
{
    courtFiles = set;
}

std::vector<std::string> loader::getUserInputFiles()   // retrieves the value of userInputFiles
{
    return (userInputFiles);
}
void loader::setUserInputFiles(std::vector<std::string> set)  // sets the value of userInputFiles
{
    userInputFiles = set;
}

int loader::readFile(const char *sourceFile, char **destination)  // loads an xml file using SDL so that it can be passed to TinyXML
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
    int BLOCK_SIZE = 8;
    int MAX_BLOCKS = 1024;

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
    logMsg("sourceFile = " +convert->toString(sourceFile));
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
    logMsg("Seek to beginning of file");
    size_t fileLength = SDL_RWseek(file, 0, SEEK_END);
    (*destination) = new char[fileLength + 1]; // allow an extra characterfor '\0'

//    ASSERT(file, "Opening file using SDL_RWops");
    // resets the file to beginnin
    SDL_RWseek(file, 0, SEEK_SET);
    // Read text from file
    std::string *contents = new std::string;
    int n_blocks = SDL_RWread(file, (*destination), 1, fileLength+1);
    logMsg("contents = " +convert->toString(contents));
    (*destination)[fileLength] = '\0';
    logMsg("destination = " +convert->toString((*destination)));
//    exit(0);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    logMsg("destination = " +convert->toString(destination));
#endif

    // BLOCK_SIZE = 8, MAX_BLOCKS = 1024
    SDL_RWclose(file);

    return EXIT_SUCCESS;
}

SDL_RWops *loader::readBinaryFile(const char *sourceFile)  // reads in a binary file
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    
    int BLOCK_SIZE = 8;
    int MAX_BLOCKS = 1024;
    
    logMsg("sourceFile = " +convert->toString(sourceFile));

    SDL_RWops *file;
    file = SDL_RWFromFile(sourceFile, "rb");

    return (file);
}

std::vector<std::string> loader::pathSplit(const std::string paths)  // splits the path data into separate strings
{
    int x = 0;
    std::vector<std::string> stringArray;
    const char delim = ':';
    std::string::const_iterator p = paths.begin(), q;
    std::vector<std::string>::iterator it;

    while (true)
    {
        q = find(p, paths.end(), delim);
        stringArray.push_back(paths.substr(p - paths.begin(), q - p));
        std::vector<std::string> tempArray;
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
    std::vector<std::string> pathArray;

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    std::string dataPath = "";
#else
    string dataPath = UBC_DATADIR;
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
            fstream fileOpen;
            // if (!(lineupFont = TTF_OpenFont(file.c_str(), 20)));
            fileOpen.open(filePath.c_str(), ios::in);
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

std::vector<boost::shared_ptr<teamState> > loader::loadTeams()  // load teams from XML files
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    std::vector<boost::shared_ptr<teamState> > teams;
    teamState *tempTeamObj = new teamState;
    boost::shared_ptr<teamState> tempTeamSharedPtr = boost::shared_ptr<teamState>(tempTeamObj);
    std::vector<boost::shared_ptr<teamState> > tempTeams;
    tempTeams.push_back(tempTeamSharedPtr);
    teams = tempTeams;
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    std::string teamList = "data/teams/teams.xml";
#else
    string teamList = findFile("teams/teams.xml");
#endif

//    logMsg("Bleeep!");
    teamFiles = loadTeamListFile(teamList);
//    std::vector<std::string> playerFiles = load->getPlayerFiles();
    logMsg("teamFiles.size() = " +convert->toString(teamFiles.size()));

//    exit(0);
    std::vector<std::string>::iterator it;
    for (it = teamFiles.begin(); it != teamFiles.end(); ++it)
    {
        logMsg("teamFile = " +*it);

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        teams.push_back(loadTeamFile("data/teams/" + *it));
#else
        teams.push_back(loadTeamFile(findFile("teams/" + *it)));
#endif
    }
    return (teams);
}

std::vector<std::string> loader::loadTeamListFile(std::string fileName)  // loads the team list file
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

    std::vector<std::string> teamName;
    std::vector<std::string> files;

//	players::playerData player;
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//    const char *file = "teams.xml";
//#else
//	const char *file = fileName.c_str();
//#endif 

//	char *fileContents = NULL;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
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
    logMsg("barf");
    logMsg("fileContents == " +fileContents);
    static const char* xml = "<element/>";
    doc.Parse(contents);
    if (doc.Error())
    {
        logMsg("Unable to parse teams.xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
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

    std::vector<std::string>::iterator it;
    for (it = files.begin(); it != files.end(); ++it)
    {
        logMsg("team file = " +*it);
    }

    logMsg("files.size() = " +convert->toString(files.size()));
//    teamFiles = files;  // sets teamFiles = to the std::vector data in files

//    setTeamFiles(teamFiles);

//    return true;
    return (files);
}

boost::shared_ptr<teamState> loader::loadTeamFile(string fileName)  // loads the team file
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//    std::vector<boost::shared_ptr<teamState> > teamInstance = gameS->getTeamInstance();
    boost::shared_ptr<teamState> tInstance;
    teamState *tempTeamObj = new teamState;
    tInstance = boost::shared_ptr<teamState>(tempTeamObj);

    int ID;
    string City;
    string Name;
    string Coach;
    string Initials;
    string Logo;

//    TiXmlDocument doc(fileName.c_str());
//    if (!doc.LoadFile()) return(false);
//	const char *fileContents = NULL;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    char *contents = NULL;
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
    doc.Parse(contents);
    if (doc.Error())
    {
        logMsg("Unable to parse team file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
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
        logMsg("Team ID == " +convert->toString(ID));
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        City = pElem->GetText();
        logMsg("City == " +City);
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        Name = pElem->GetText();
        logMsg("Name == " +Name);
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        Coach = pElem->GetText();
        logMsg("Coach == " +Coach);
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        Initials = pElem->GetText();
        logMsg("Initials == " +Initials);
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        Logo = pElem->GetText();
        logMsg("Logo == " +Logo);
    }

    tInstance->setID(ID);
    tInstance->setCity(City);
    tInstance->setName(Name);
    tInstance->setCoach(Coach);
    tInstance->setInits(Initials);
    tInstance->setLogoFile(Logo);

//    team->setTeamArray(teamInstance);
//   teamInstance.push_back(teamInstance);
//   gameS->setteamInstance(teamInstance);
//    exit(0);

    return (tInstance);
}

std::vector<boost::shared_ptr<playerState> > loader::loadPlayers()  // loads the players
{
    std::vector<boost::shared_ptr<playerState> > players;

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    string playerList = "data/players/players.xml";
#else
    string playerList = findFile("players/players.xml");
#endif
    playerFiles = loadPlayerListFile(playerList);
//    std::vector<std::string> playerFiles = load->getPlayerFiles();

    std::vector<std::string>::iterator it;
    for (it = playerFiles.begin(); it != playerFiles.end(); ++it)
    {
       
        logMsg("playerFile = " +*it);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        players.push_back(loadPlayerFile("data/players/" + *it));
#else
        players.push_back(loadPlayerFile(findFile("players/" + *it)));
#endif 
//    exit(0);
    }
    return (players);
}

std::vector<std::string> loader::loadPlayerListFile( string fileName)  // loads the player list file
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
  //   boost::shared_ptr<renderEngine> render = renderEngine::Instance();
    std::vector<std::string> pFiles;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    logMsg(fileName);
    char *contents = NULL;
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);

    doc.Parse(contents);
    if (doc.Error())
    {
        logMsg("Unable to parse teams.xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
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
        string pKey=pElem->Value();
//        cout << pKey << endl;
        string pText=pElem->GetText();
        logMsg("pText == " +pText);
//        cout << pText << endl;
        pFiles.push_back(pText);
    }

/*    std::vector<std::string>::iterator it;
    for (it = playerFiles.begin(); it != playerFiles.end(); ++it)
    {
        cout << *it << endl;
    }
    */

//    setPlayerFiles(playerFiles);
//    return true;
    return (pFiles);
}

boost::shared_ptr<playerState> loader::loadPlayerFile(string fileName)  // loads the player file
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

    boost::shared_ptr<playerState> player;
    //playerState *tempPlayerObj = new playerState;
    //player = boost::shared_ptr<playerState>(tempPlayerObj);
    playerState *tempPlayerObj; // = new playerState;
    tempPlayerObj = new playerState;
/*    boost::shared_ptr<playerState> tempPlayerSharedPtr = boost::shared_ptr<playerState>(tempPlayerObj);
    player = tempPlayerSharedPtr;
//    std::vector<boost::shared_ptr<playerState> > playerInstance = gameS->getPlayerInstance();
    string firstName;
    string lastName;
    string modelName;
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
    readFile(fileName.c_str(), &contents);
    logMsg("loading: "+fileName);
    fileContents = convert->toString(contents);
    logMsg("fileContents = " +fileContents);
    
    doc.Parse(contents);
    if (doc.Error())
    { 
        logMsg("Unable to parse player file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
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
        logMsg("Unable to find a valid player file root!");
        exit(0);
    }

    hRoot = tinyxml2::XMLHandle(pElem);

    pElem=hRoot.FirstChild().ToElement();
    if(pElem)
    {
        ID = convert->toInt(pElem->GetText());
        logMsg("PlayerID == " +convert->toString(ID));
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        teamID = convert->toInt(pElem->GetText());
        logMsg("teamID == " +convert->toString(teamID));
    }
    logMsg("pElem.Name() = " +convert->toString(pElem->GetText()));
    pElem=pElem->NextSiblingElement()->ToElement();
    if(pElem)
    {
        childElement=pElem->FirstChildElement()->ToElement();
        string pKey=childElement->Value();
        if (pKey == "First")
        {
            firstName = childElement->GetText();
            logMsg("First Name: " +firstName);
//            exit(0);
        }
        childElement=childElement->NextSiblingElement()->ToElement();
        pKey=childElement->Value();
        if (pKey == "Last")
        {
            lastName = childElement->GetText();
            logMsg("Last Name: " +lastName);
        }

    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        age = convert->toInt(pElem->GetText());
        logMsg("Age = " +convert->toString(age));
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        height = convert->toInt(pElem->GetText());
        logMsg("Height = " +convert->toString(height));
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        weight = convert->toInt(pElem->GetText());
        logMsg("Weight = " +convert->toString(weight));
    }

    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        modelName = pElem->GetText();
        logMsg("Model = " +modelName);
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
        logMsg("primaryPosition = " +position);
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
        logMsg("secondaryPosition = " +position);
    }
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        shooting = convert->toInt(pElem->GetText());
        logMsg("shooting = " +convert->toString(shooting));
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
    
    player->setFirstName(firstName);
//    exit(0);
    player->setLastName(lastName);
    player->setPlayerName(firstName +" " +lastName);
    player->setAge(age);
    player->setHeight(height);
    player->setWeight(weight);
    player->setID(ID);
    player->setTeamID(teamID);
    player->setEntityModelFileName(modelName);
    player->setPrimaryPosition(primaryPosition);
    player->setSecondaryPosition(secondaryPosition);
    player->setShooting(shooting);
    player->setFreeThrow(freeThrow);
    player->setLayup(layup);
    player->setDunk(dunk);
    player->setInside(inside);
    player->setMidRange(midRange);
    player->setThreePoint(threePoint);
    player->setBallHandling(ballHandling);
    player->setBallSecurity(ballSecurity);
    player->setPassing(passing);
    player->setPickSetting(pickSetting);
    player->setOffenseAwareness(offenseAwareness);
    player->setDefenseAwareness(defenseAwareness);
    player->setOffenseRebound(offenseRebound);
    player->setDefenseRebound(defenseRebound);
    player->setBlocking(blocking);
    player->setStealing(stealing);
    player->setInteriorDefense(interiorDefense);
    player->setMidRangeDefense(midRangeDefense);
    player->setPerimeterDefense(perimeterDefense);
    player->setHustle(hustle);
    player->setSpeed(speed);
    player->setQuickness(quickness);
    player->setFatigue(fatigue);
    player->setDurability(durability);
    player->setDemeanor(demeanor);
    player->setImprovability(improvability);
    player->calculateOverallRating();
///    playerInstance.push_back(player);
    logMsg("player First Name == "+player->getFirstName());*/
    //gameS->setPlayerDataInstances(playerDataInstance);
    //	vector<players::playerData> playerN = playerG->getPlayer();
//    exit(0);
    
    return (player);
}

//Offense
std::vector<offensePlays> loader::loadOffensePlays()  // load offense plays from XML files
{
    std::vector<offensePlays> plays;
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    string playList = "data/offense/plays/plays.xml";
#else
    string playList = findFile("offense/plays/plays.xml");
#endif
    offensePlayFiles = loadOffensePlayListFile(playList);
//    std::vector<std::string> playerFiles = load->getPlayerFiles();

    std::vector<std::string>::iterator it;
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

std::vector<std::string> loader::loadOffensePlayListFile(string fileName)  // loads the play list file
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

    std::vector<std::string> playFiles;

    std::string fileContents;
    tinyxml2::XMLDocument doc;
    logMsg(fileName);
    char *contents = NULL;
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);

    doc.Parse(contents);
    if (doc.Error())
    {
        logMsg("Unable to parse teams.xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
    }

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
        string pKey=pElem->Value();
        string pText=pElem->GetText();
        playFiles.push_back(pText);
    }

//    setOffensePlayFiles(playFiles);
//    return true;
    return (playFiles);
}

offensePlays loader::loadOffensePlayFile(string fileName)  // loads data from the offense play XML files
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    
    offensePlays play;
    std::string playName;
    int variation;
    std::string title;
    std::vector<playerPositions> playerPosition;
    std::vector<std::string> type;
    std::vector<float> xCoord;
    std::vector<float> yCoord;
    std::vector<float> zCoord;
    std::vector<Ogre::Vector3> startCoords;
    std::vector< std::vector<Ogre::Vector3> > executeCoords;
    std::vector<offensePlays::playerDirectives> playerDirective;

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
    std::vector<Ogre::Vector3> pExecuteCoords;
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
        logMsg("Unable to parse offense play file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
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
        string cKey = child->Value();
        if (cKey == "PlayName")
        {
            pPlayName = child->GetText();
            logMsg("pPlayName = " +playName);
            playName = pPlayName;
        }
        child = child->NextSiblingElement()->ToElement();
	if (child)
        {
            pVariation = convert->toInt(child->GetText());
            logMsg("pVariation = " +convert->toString(pVariation));
            variation = pVariation;
        } 
        child = child->NextSiblingElement()->ToElement(); 
	if (child)
        {
            pTitle = child->GetText();
            logMsg("pTitle = " +pTitle);
            title = pTitle;
        }
        int numPlayers = 0;
        for (tinyxml2::XMLElement *e = child->NextSiblingElement(); e != NULL; e = e->NextSiblingElement())
	{
	    tinyxml2::XMLElement *f;

            logMsg ("nums = " +convert->toString(numPlayers));
            numPlayers += 1;
            f = e->FirstChildElement()->ToElement();
	    if (f)
            {
                pPlayerPosition = f->GetText();
                logMsg("name = " +pPlayerPosition);
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
                    logMsg("numPos = " +convert->toString(numPos));
                    numPos += 1;
		    tinyxml2::XMLElement *h;

                    h = g->FirstChildElement()->ToElement();
		    if (h)
                    {
                        pType = h->GetText();
                        logMsg("pType = " +pType);
                        type.push_back(pType);
                    }
                    h = h->NextSiblingElement()->ToElement();
		    if (h)
                    {
                        pXCoord = convert->toFloat(h->GetText());
                        logMsg("pXCoord = " +convert->toString(pXCoord));
                        xCoord.push_back(pXCoord);
                    }
                    h = h->NextSiblingElement()->ToElement();
		    if (h)
                    {
                        pYCoord = convert->toFloat(h->GetText());
                        logMsg("pYCoord = " +convert->toString(pYCoord));
                        yCoord.push_back(pYCoord);
                    }
                    h = h->NextSiblingElement()->ToElement();
		    if (h)
                    {
                        pZCoord = convert->toFloat(h->GetText());
                        logMsg("pZCoord = " +convert->toString(pZCoord));
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
                        logMsg("pExecuteCoords.size = " +convert->toString(pExecuteCoords.size()));
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
                        string hKey = h->GetText();
                        logMsg("hKey = " +hKey);
                        if (hKey == "Wait")
                        {
                            pPlayerDirective.setType(WAIT);
                            h = h->NextSiblingElement()->ToElement();
			    if (h)
                            {
                                logMsg("WaitFor");
                                hKey = h->GetText();
                                if (hKey == "PlayerPositionSet")
                                {
                                    pPlayerDirective.setWaitFor(PLAYERPOSITIONSET);
                                    logMsg("PlayerPositionSet");

                                    h = h->NextSiblingElement()->ToElement();
				    if (h)
                                    {
                                        hKey = h->GetText();
                                        logMsg("PlayerSet = " +hKey);

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
                                        logMsg("PositionType");
                                        hKey = h->GetText();
                                        if (hKey == "Start")
                                        {
                                            logMsg("Start");
                                            pPlayerDirective.setPositionType(START);
                                        }
                                        else if (hKey == "Execute")
                                        {
                                            logMsg("Execute");
                                            pPlayerDirective.setPositionType(EXECUTE);

                                            h = h->NextSiblingElement("Position");
                                            if (h)
                                            {
                                                logMsg("Position");
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
                logMsg("numDirectives = " +convert->toString(numDirectives));
            }
        }
    }

    play.setPlayName(playName);
    play.setVariation(variation);
    play.setTitle(title);
    play.setPlayerPosition(playerPosition);
    play.setStartPositions(startCoords);
    play.setExecutePositions(executeCoords);
    play.setPlayerDirective(playerDirective);

    return (play);
}

// Basketballs
std::vector<basketballState> loader::loadBasketballs()  // load basketball settings from XML files
{
    std::vector<basketballState> basketballs;
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    string basketballList = "data/basketballs/basketballs.xml";
#else
    string basketballList = findFile("basketballs/basketballs.xml");
#endif
    basketballFiles = loadBasketballListFile(basketballList);
//    std::vector<std::string> playerFiles = load->getPlayerFiles();

    std::vector<std::string>::iterator it;
    for (it = basketballFiles.begin(); it != basketballFiles.end(); ++it)
    {
        logMsg("basketballFile = " +*it);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        basketballs.push_back(loadBasketballFile("data/basketballs/" + *it));
#else
        basketballs.push_back(loadBasketballFile(findFile("basketballs/" + *it)));
#endif
    }
    return (basketballs);
}

std::vector<std::string> loader::loadBasketballListFile(string fileName) // loads the list of baskteball list file
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
    std::vector<std::string> bballFiles;

    std::string fileContents;
    tinyxml2::XMLDocument doc;

    logMsg(fileName);
    char *contents = NULL;
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
    logMsg("fileContents = " +fileContents);

    doc.Parse(contents);
    if (doc.Error())
    {
        logMsg("Unable to parse basketballs.xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
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
        string pKey=pElem->Value();
        string pText=pElem->GetText();
        bballFiles.push_back(pText);
    }

//    setBasketballFiles(basketballFile);
//    return true;
    return (bballFiles);
}

basketballState loader::loadBasketballFile(string fileName)  // loads data from the basketball XML files
{
    boost::shared_ptr<conversion> convert = conversion::Instance();

    basketballState basketball;
    std::string name;
    std::string modelName;

    std::string fileContents;
    tinyxml2::XMLDocument doc;

    char *contents = NULL;
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);

    doc.Parse(contents);
    if (doc.Error())
    {
        logMsg("Unable to parse basketball xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
    }

    tinyxml2::XMLHandle hDoc(&doc);
    tinyxml2::XMLElement *rootElement;
    tinyxml2::XMLElement *child;
    tinyxml2::XMLHandle hRoot(0);

    rootElement = doc.FirstChildElement()->ToElement();
    // should always have a valid root but handle gracefully if it does
    if (!rootElement)
    {
        logMsg("Unable to load basketball element");
        //exit(0);
    }

    child = rootElement->FirstChild()->ToElement();
    if (child)
    {
        string cKey = child->Value();
        if (cKey == "Name")
        {
            name = child->GetText();
            logMsg("name = " +name);
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            modelName = child->GetText();
            logMsg("modelName = " +modelName);
        }

    }

    basketball.setName(name);
    basketball.setModelFileName(modelName);

    return (basketball);
}

// Courts
std::vector<courtState> loader::loadCourts()  // load court settings from XML files
{
    std::vector<courtState> courts;
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    string courtList = "data/courts/courts.xml";
#else
    string courtList = findFile("courts/courts.xml");
#endif
    courtFiles = loadCourtListFile(courtList);
//    std::vector<std::string> playerFiles = load->getPlayerFiles();

    std::vector<std::string>::iterator it;
    for (it = courtFiles.begin(); it != courtFiles.end(); ++it)
    {
        logMsg("courtFile = " +*it);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        courts.push_back(loadCourtFile("data/courts/" + *it));
#else
        courts.push_back(loadCourtFile(findFile("courts/" + *it)));
#endif
    }
    return (courts);
}

std::vector<std::string> loader::loadCourtListFile(string fileName)	// loads the list of court list file
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
    std::vector<std::string> cFiles;

    std::string fileContents;
    tinyxml2::XMLDocument doc;

    logMsg(fileName);
    char *contents = NULL;
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
    logMsg("fileContents = " +fileContents);

    doc.Parse(contents);
    if (doc.Error())
    {
        logMsg("Unable to parse courts.xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
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
        string pKey=pElem->Value();
        string pText=pElem->GetText();
        cFiles.push_back(pText);
    }

//    setCourtFiles(courtFile);
//    return true;
    return (cFiles);
}

courtState loader::loadCourtFile(string fileName)  // loads data from the offense play XML files
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    
    courtState court;
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
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
    
    doc.Parse(contents);
    if (doc.Error())
    {
        logMsg("Unable to parse court xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
    }

    tinyxml2::XMLHandle hDoc(&doc);
    tinyxml2::XMLElement *rootElement;
    tinyxml2::XMLElement *child;
    tinyxml2::XMLHandle hRoot(0);

    rootElement = doc.FirstChildElement()->ToElement();
    // should always have a valid root but handle gracefully if it does
    if (!rootElement)
    {
        logMsg("Unable to load court element");
        //exit(0);
    }

    child = rootElement->FirstChild()->ToElement();
    if (child)
    {
        string cKey = child->Value();
        if (cKey == "Name")
        {
            name = child->GetText();
            logMsg("name = " +name);
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            modelName = child->GetText();
            logMsg("modelName = " +modelName);
        }
        child = child->NextSiblingElement()->ToElement();
	if (child)
        {
            length = convert->toFloat(child->GetText());
            logMsg("Length = " +convert->toString(length));
        } 
        child = child->NextSiblingElement()->ToElement();
	if (child)
        {
            length = convert->toFloat(child->GetText());
            logMsg("Width = " +convert->toString(width));
        }
        child = child->NextSiblingElement()->ToElement();
	if (child)
        {
            boundaryLength = convert->toFloat(child->GetText());
            logMsg("Boundary Length = " +convert->toString(boundaryLength));
        }
        child = child->NextSiblingElement()->ToElement();
       	if (child)
        {
            boundaryWidth = convert->toFloat(child->GetText());
            logMsg("Boundary Width = " +convert->toString(boundaryWidth));
        }
        child = child->NextSiblingElement()->ToElement();
	if (child)
        {
            boundaryXPos = convert->toFloat(child->GetText());
            logMsg("Boundary X Pos = " +convert->toString(boundaryXPos));
        }
        child = child->NextSiblingElement()->ToElement();
	if (child)
        {
            boundaryZPos = convert->toFloat(child->GetText());
            logMsg("Boundary Z Pos = " +convert->toString(boundaryZPos));
        }
        child = child->NextSiblingElement()->ToElement();
	if (child)
        {
            centerCourt = convert->toFloat(child->GetText());
            logMsg("Center Court = " +convert->toString(centerCourt));
        }
        child = child->NextSiblingElement()->ToElement();
	if (child)
        {
            centerJumpRadius = convert->toFloat(child->GetText());
            logMsg("Center Jump Radius = " +convert->toString(centerJumpRadius));
        }
        child = child->NextSiblingElement()->ToElement();
	if (child)
        {
            keyLength = convert->toFloat(child->GetText());
            logMsg("Key Length = " +convert->toString(keyLength));
        }
        child = child->NextSiblingElement()->ToElement();
	if (child)
        {
            keyWidth = convert->toFloat(child->GetText());
            logMsg("Key Width = " +convert->toString(keyWidth));
        }
        child = child->NextSiblingElement()->ToElement();
	if (child)
        {
            keyJumpRadius = convert->toFloat(child->GetText());
            logMsg("Key Jump RAdius = " +convert->toString(keyJumpRadius));
        }
        child = child->NextSiblingElement()->ToElement();
	if (child)
        {
            threePointSideLength = convert->toFloat(child->GetText());
            logMsg("Three Point Side Length = " +convert->toString(threePointSideLength));
        }
        child = child->NextSiblingElement()->ToElement();
	if (child)
        {
            threePointSideZPos = convert->toFloat(child->GetText());
            logMsg("Three Point Side Z Pos = " +convert->toString(threePointSideZPos));
        }
        child = child->NextSiblingElement()->ToElement();
	if (child)
        {
            threePointArcRadius = convert->toFloat(child->GetText());
            logMsg("Three Point Arc Radius = " +convert->toString(threePointArcRadius));
        }
        child = child->NextSiblingElement()->ToElement();
	if (child)
        {
            baselineInboundXPos = convert->toFloat(child->GetText());
            logMsg("Baseline Inbound X Pos = " +convert->toString(baselineInboundXPos));
        }
        child = child->NextSiblingElement()->ToElement();
	if (child)
        {
            baselineInboundZPos = convert->toFloat(child->GetText());
            logMsg("Baseline Inbound Z Pos = " +convert->toString(baselineInboundZPos));
        }
        child = child->NextSiblingElement()->ToElement();
	if (child)
        {
            sidelineInboundXPos = convert->toFloat(child->GetText());
            logMsg("Sideline Inbound X Pos = " +convert->toString(sidelineInboundXPos));
        }
        child = child->NextSiblingElement()->ToElement();
	if (child)
        {
            sidelineInboundZPos = convert->toFloat(child->GetText());
            logMsg("Sideline Inbound Z Pos = " +convert->toString(sidelineInboundZPos));
        }
    }

    Ogre::Vector2 boundary = Ogre::Vector2(length,width);
    Ogre::Vector2 boundaryPos = Ogre::Vector2(boundaryXPos,boundaryZPos);
    Ogre::Vector2 keyDimensions = Ogre::Vector2(keyLength,keyWidth);
    Ogre::Vector2 baselineInboundPos = Ogre::Vector2(baselineInboundXPos,baselineInboundZPos);
    Ogre::Vector2 sidelineInboundPos = Ogre::Vector2(sidelineInboundXPos,sidelineInboundZPos);

    court.setName(name);
    court.setModelFileName(modelName);
    court.setBoundary(boundary);
    court.setBoundaryPos(boundaryPos);
    court.setCenterCourt(centerCourt);
    court.setCenterJumpRadius(centerJumpRadius);
    court.setKeyDimensions(keyDimensions);
    court.setKeyJumpRadius(keyJumpRadius);
    court.setThreePointSideLength(threePointSideLength);
    court.setThreePointZPos(threePointSideZPos);
    court.setThreePointArcRadius(threePointArcRadius);
    court.setBaselineInboundPos(baselineInboundPos);
    court.setSidelineInboundPos(sidelineInboundPos);

    return (court);
}

// User input
std::vector<userInput> loader::loadUserInputs()  // load user input settings from XML files
{
    std::vector<userInput> userInputs;
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    string userInputList = "data/users/inputlist.xml";
#else
    string userInputList = findFile("users/inputlist.xml");
#endif
    userInputFiles = loadUserInputListFile(userInputList);
//    std::vector<std::string> playerFiles = load->getPlayerFiles();

    std::vector<std::string>::iterator it;
    for (it = userInputFiles.begin(); it != userInputFiles.end(); ++it)
    {
        logMsg("userInputFile = " +*it);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        userInputs.push_back(loadUserInputFile("data/users/" + *it));
#else
        userInputs.push_back(loadUserInputFile(findFile("users/" + *it)));
#endif
    }
    return (userInputs);
}

std::vector<std::string> loader::loadUserInputListFile(string fileName)  // loads the user input list file
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
    std::vector<std::string> uInputFiles;

    std::string fileContents;
    tinyxml2::XMLDocument doc;

    logMsg(fileName);
    char *contents = NULL;
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);

    doc.Parse(contents);
    if (doc.Error())
    {
        logMsg("Unable to parse inputlist.xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
    }

    tinyxml2::XMLHandle hDoc(&doc);
    tinyxml2::XMLElement *pElem;
    tinyxml2::XMLHandle hRoot(0);

    pElem=hDoc.FirstChildElement().ToElement();
    
    // should always have a valid root but handle gracefully if it does
    if (!pElem)
    {
        logMsg("Unable to find avalid root for user input list file!");
    } 

    // save this for later
    hRoot=tinyxml2::XMLHandle(pElem);

    pElem=hRoot.FirstChild().ToElement();
    for( pElem; pElem; pElem=pElem->NextSiblingElement())
    {
        string pKey=pElem->Value();
        logMsg("pKey == " +pKey);
	string pText=pElem->GetText();
	logMsg("pText == " +pText);
        uInputFiles.push_back(pText);
    }
    
//    setUserInputFiles(userInputFile);
//    return true;
    return (uInputFiles);
}

userInput loader::loadUserInputFile(string fileName)  // loads data from the user input files
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    
    logMsg("Load UserInput File");
    userInput uInput;
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
   
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);

    doc.Parse(contents);
    if (doc.Error())
    {
        logMsg("Unable to parse user input file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
    }   
    
    tinyxml2::XMLHandle hDoc(&doc);
    tinyxml2::XMLElement *rootElement;
    tinyxml2::XMLElement *child;
    tinyxml2::XMLElement *nextChild;
    tinyxml2::XMLHandle hRoot(0);

    rootElement=hDoc.FirstChildElement().ToElement();   
    // should always have a valid root but handle gracefully if it does
    if (!rootElement)
    {
        logMsg("Unable to load user input element");
        exit(0);
    }
    
    child = rootElement->FirstChild()->ToElement();
    if (child)
    {
        string cKey = child->Value();
        if (cKey == "Name")
        {
            inputName = child->GetText();
            logMsg("name = " +inputName);
        }
        
        bool inputTag = false;
        while (!inputTag)
        {
            child = child->NextSiblingElement()->ToElement();
            if (child)
            {
                nextChild = child->FirstChildElement()->ToElement();
                inputTag = true;
                for( nextChild; nextChild; nextChild=nextChild->NextSiblingElement())
		{
                    string pKey=nextChild->Value();
                    logMsg("pKey = " +pKey);
//                    exit(0);
                    if (pKey == "Type")
                    {
                        type = nextChild->GetText();
                        logMsg("type = " +type);
//                        exit(0);
                    }
                    if (pKey == "Up")
                    {
                        up = nextChild->GetText();
                        logMsg("up = " +up);

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
                uInput.setKeyUp(up);
                uInput.setKeyDown(down);
                uInput.setKeyLeft(left);
                uInput.setKeyRight(right);
                uInput.setKeyUpLeft(upLeft);
                uInput.setKeyUpRight(upRight);
                uInput.setKeyDownLeft(downLeft);
                uInput.setKeyDownRight(downRight);
                uInput.setKeyShootBlock(shootBlock);
                uInput.setKeyPassSteal(passSteal);
                uInput.setKeyPause(pause);
                uInput.setKeyStartSelect(startSelect);
                uInput.setKeyQuit(quit);
            }
            else if (type == "Joystick")
            {
                uInput.setJoyUp(up);
                uInput.setJoyDown(down);
                uInput.setJoyLeft(left);
                uInput.setJoyRight(right);
                uInput.setJoyUpLeft(upLeft);
                uInput.setJoyUpRight(upRight);
                uInput.setJoyDownLeft(downLeft);
                uInput.setJoyDownRight(downRight);
                uInput.setJoyShootBlock(shootBlock);
                uInput.setJoyPassSteal(passSteal);
                uInput.setJoyPause(pause);
                uInput.setJoyStartSelect(startSelect);
            }
            else
            {
            }
        }
    }
    return (uInput);
}
