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

#include "utilities/conversion.h"
#include "load/loadteams.h"
#include "utilities/logging.h"
#include "state/teamstate.h"

// static declarations
teamStateMSharedPtr loadTeams::tInstance;
stdStringVec loadTeams::teamFiles;  // stores list of team xml files
bool loadTeams::teamFilesLoaded;

loadTeams::loadTeams()  // constructor
{
    teamFilesLoaded = false;
}
loadTeams::~loadTeams()  // destructor
{
    
}

stdStringVec loadTeams::getTeamFiles()  // retrieves the value of teamFiles
{
    return(teamFiles);
}
void loadTeams::setTeamFiles(stdStringVec set)  // sets the value of teamFiles
{
    teamFiles = set;
}

bool loadTeams::getTeamFilesLoaded()  // retrieves the value of teamFilesLoaded
{
    return (teamFilesLoaded);
}
void loadTeams::setTeamFilesLoaded(bool set)  // sets the value of teamFilesLoaded
{
    teamFilesLoaded = set;
}

teamStateMSharedPtr loadTeams::getTInstance()  // retrieves the value of tInstance
{
    return(tInstance);
}
void loadTeams::setTInstance(teamStateMSharedPtr set)  // sets the value of tInstance
{
    tInstance = set;
}

bool loadTeams::checkIfTeamsLoaded()  // checks if teams have been loaded into tInstance
{
    conversionSharedPtr convert = conversion::Instance();
    teamStateVec tempT;
    teamStateMSharedPtr tempTInstance;
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
            tInstance = loadTeamFiles();
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

            tInstance = loadTeamFiles();
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

teamStateMSharedPtr loadTeams::loadTeamFiles()  // load teams from XML files
{
    conversionSharedPtr convert = conversion::Instance();
    teamStateMSharedPtr teams;

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

stdStringVec loadTeams::loadTeamListFile(std::string fileName)  // loads the team list file
{
    conversionSharedPtr convert = conversion::Instance();
//    renderEngineSharedPtr render = renderEngine::Instance();

    stdStringVec teamName;
    stdStringVec files;

//  players::playerData player;
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//    const char *file = "teams.xml";
//#else
//  const char *file = fileName.c_str();
//#endif 

//  char *fileContents = NULL;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    std::string func = "loader::loadTeamListFile";
    
    logMsg(func +" beginning");

    
    logMsg(fileName);
    logMsg("bate");
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//  Ogre::DataStreamPtr fileData = render->openAPKFile(fileName);
//  fileContents = fileData->getAsString();
//#else
    char *contents = NULL;
    readFile(fileName.c_str(), &contents);
//  logMsg("read contents = " +contents);
//  exit(0);
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

teamStateSharedPtr loadTeams::loadTeamFile(std::string fileName)  // loads the team file
{
    conversionSharedPtr convert = conversion::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
//    renderEngineSharedPtr render = renderEngine::Instance();
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
//  const char *fileContents = NULL;
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
