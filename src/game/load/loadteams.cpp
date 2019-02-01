/***************************************************************************
 *   Copyright (C) 1999 - 2019 by Mike McLean                              *
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

#include "data/teamdata.h"
#include "entity/teamentity.h"
#include "utilities/conversion.h"
#include "load/loadteams.h"
#include "utilities/logging.h"

loadTeams::loadTeams()  // constructor
{
    teamFilesLoaded = false;
}
loadTeams::~loadTeams() = default;  // destructor

stdStringVec loadTeams::getTeamFiles() const  // retrieves the value of teamFiles
{
    return(teamFiles);
}
void loadTeams::setTeamFiles(const stdStringVec &set)  // sets the value of teamFiles
{
    teamFiles = set;
}

bool loadTeams::getTeamFilesLoaded() const  // retrieves the value of teamFilesLoaded
{
    return (teamFilesLoaded);
}
void loadTeams::setTeamFilesLoaded(const bool &set)  // sets the value of teamFilesLoaded
{
    teamFilesLoaded = set;
}

teamEntityMSharedPtr loadTeams::getTInstance() const  // retrieves the value of tInstance
{
    return(tInstance);
}
void loadTeams::setTInstance(const teamEntityMSharedPtr &set)  // sets the value of tInstance
{
    tInstance = set;
}

bool loadTeams::checkIfTeamsLoaded()  // checks if teams have been loaded into tInstance
{
    conversionSharedPtr convert ;
//    teamStateVec tempT;
    teamEntityMSharedPtr tempTInstance;
    tInstance = tempTInstance;
    bool retVal = false;
    std::string func = "loadTeams::checkIfTeamsLoaded()";
    
    logMsg(func + " begin");
//    exit(0);
    if (teamFilesLoaded)
    {
        logMsg(func +" getTeamFilesLoaded");

        if (!tInstance.empty())
        {
            logMsg(func + " Team Files Loaded!");
            retVal = true;
        }
        else
        {
            logMsg(func +" Team Files not yet Loaded!");

            teamFilesLoaded = false;
            tInstance = loadTeamFiles();
            if (!tInstance.empty())
            {
                logMsg(func +" > 0!");

//                load->setTInstance(tInstance);
                teamFilesLoaded = true;
                retVal = true;
            }
            else
            {
                logMsg(func +" Failed to load Team Files! IF");
                exit(0);
            }
        }
    }
    else 
    {
        logMsg(func +" ELSE");

        if (!tInstance.empty())
        {
            logMsg(func +" load->getTInstance().size() > 0! ELSE");
//            load->setTInstance(tInstance);
            teamFilesLoaded = true;
            retVal = true;
        }
        else
        {
            logMsg(func +" ELSE ELSE!");

            tInstance = loadTeamFiles();
            logMsg(func +" tInstance.size() == " +convert->toString(tInstance.size()));
//            exit(0);
            if (!tInstance.empty())
            {
                logMsg(func +" load->getTInstance().size() > 0! ELSE ELSE");

//                load->setTInstance(tInstance);
                teamFilesLoaded = true;
                retVal = true;
            }
            else
            {
                logMsg(func +" Failed to load Team Files!");
                retVal = false;
            }
        }
    }
    
    logMsg(func +" end");
    
    return (retVal);
}

teamEntityMSharedPtr loadTeams::loadTeamFiles()  // load teams from XML files
{
    conversionSharedPtr convert ;
    teamEntityMSharedPtr teams;

    std::string teamList;
    std::string func = "loadTeams::loadTeams";
    
    logMsg(func +" begin");

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
    logMsg(func +" teamFiles.size() = " +convert->toString(teamFiles.size()));

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
        teams.insert(std::pair<size_t, teamEntitySharedPtr>(it, loadTeamFile("data/teams/" + teamFiles[it])));

#else
//        teams.push_back(loadTeamFile(findFile("teams/" + *it)));
//          loadTeamFile(findFile("teams/" + *it));
        teams.insert(std::pair<size_t, teamEntitySharedPtr>(it, loadTeamFile(findFile("teams/" + teamFiles[it]))));

#endif
    }
//    exit(0);
//    logMsg("teams[0]->getID() ID == " +convert->toString(teams[0]->getID()));
//    exit(0);
//    logMsg("loadTeams() 4 ID == " +convert->toString(teams[4]->getID()));
//    logMsg("loadTeams() 4 Name == " +tInstance[4]->getName());
    for (auto TIIT : teams)
    {
        logMsg(func +" Team == " +TIIT.second->getData()->getCity() +" " +TIIT.second->getData()->getName());
    }
    logMsg(func +"  teams.size() == " +convert->toString(teams.size()));
//    exit(0);
    logMsg(func +" dah");
//    exit(0);
    if (teams.empty())
    {
        logMsg(func +" teams.size() == " +convert->toString(teams.size()));
//        exit(0);
    }
    
    logMsg(func +" end");
    
    return (teams);
}

stdStringVec loadTeams::loadTeamListFile(const std::string &fileName)  // loads the team list file
{
    conversionSharedPtr convert ;
//    renderEngineSharedPtr render = renderEngine::Instance();

    stdStringVec teamName;
    stdStringVec files;

//  players::playerData player;
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//    const char *file = "teams.xml";
//#else
//  const char *file = fileName.c_str();
//#endif 

//  char *fileContents = nullptr;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    std::string func = "loadTeams::loadTeamListFile";
    
    logMsg(func +" begin");

    
    logMsg(fileName);
    logMsg(func +" bate");
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//  Ogre::DataStreamPtr fileData = render->openAPKFile(fileName);
//  fileContents = fileData->getAsString();
//#else
    char *contents = nullptr;
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
    tinyxml2::XMLHandle hRoot(nullptr);
    //tinyxml2::XMLText *textNode = doc.FirstChildElement("Teams")->FirstChildElement("TeamFile")->ToText();
    //logMsg("first element = " +convert->toString(textNode->Value()));
    pElem=hDoc.FirstChildElement().ToElement();
    // should always have a valid root but handle gracefully if it does
    if (!pElem)
    {
        logMsg(func +" Unable to find a valid teamListFile root!");
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
        logMsg(func +" teamFile = " +convert->toString(pElem->GetText()));
    }

    stdStringVec::iterator it;
    for (it = files.begin(); it != files.end(); ++it)
    {
        logMsg(func +" team file = " +*it);
    }

    logMsg(func +" files.size() = " +convert->toString(files.size()));
//    teamFiles = files;  // sets teamFiles = to the std::vector data in files

//    setTeamFiles(teamFiles);

    logMsg(func +" end");
//    return true;
    return (files);
}

teamEntitySharedPtr loadTeams::loadTeamFile(const std::string &fileName)  // loads the team file
{
    conversionSharedPtr convert ;
//    sharedPtr<gameState> gameS = gameState::Instance();
//    renderEngineSharedPtr render = renderEngine::Instance();
//    teamStateVecSharedPtr teamInstance = gameS->getTeamInstance();
  
    teamEntitySharedPtr teamInstance(new teamEntity);
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
//  const char *fileContents = nullptr;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    char *contents = nullptr;
    std::string func = "loadTeams::loadTeamFile";
    
    logMsg(func +" begin");
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
    
    tinyxml2::XMLHandle hRoot(nullptr);
    
    pElem=hDoc.FirstChildElement().ToElement();
    
    // should always have a valid root but handle gracefully if it does
    if (!pElem)
    {
        logMsg(func +" Unable to find valid root. Exiting!");
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
    
    teamDataSharedPtr tempData(new teamData);
    teamInstance->setData(tempData);
    
    teamInstance->getData()->setID(ID);
//    exit(0);
    teamInstance->getData()->setCity(City);
    teamInstance->getData()->setName(Name);
    teamInstance->getData()->setCoach(Coach);
    teamInstance->getData()->setInits(Initials);
    teamInstance->getData()->setLogoFile(Logo);
//    logMsg("ID == " +convert->toString(ID));
//    logMsg("Load Teaminstance ID == " +convert->toString(teamInstance->getID()));
    logMsg(func +" teamInstance->getID() == " +convert->toString(teamInstance->getData()->getID()));
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
