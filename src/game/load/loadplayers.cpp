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

#include "data/playerdata.h"
#include "components/playercomponents.h"
#include "entity/playerentity.h"
#include "flags/playerflags.h"
#include "utilities/conversion.h"
#include "load/loadplayers.h"
#include "utilities/logging.h"

loadPlayers::loadPlayers()  // constructor
{
    playerFilesLoaded = false;
}
loadPlayers::~loadPlayers() = default;  // destructor

stdStringVec loadPlayers::getPlayerFiles() const  // retrieves the value of playerFiles
{
    return(playerFiles);
}
void loadPlayers::setPlayerFiles(const stdStringVec &set)  // sets the value of playerFiles
{
    playerFiles = set;
}

playerEntityMSharedPtr loadPlayers::getPInstance() const  // retrieves the value of pInstance
{
    return(pInstance);
}
void loadPlayers::setPInstance(const playerEntityMSharedPtr &set)  // sets the value of pInstance
{
    pInstance = set;
}

bool loadPlayers::getPlayerFilesLoaded() const  // retrieves the value of playerFilesLoaded
{
    return (playerFilesLoaded);
}
void loadPlayers::setPlayerFilesLoaded(const bool &set)  // sets the value of playerFilesLoaded
{
    playerFilesLoaded = set;
}

bool loadPlayers::checkIfPlayersLoaded()  // checks if players have been loaded into pInstance
{
    bool retVal = false;
    std::string func = "loadPlayers::checkIfPlayersLoaded()";
    
    logMsg(func + " beginning");

    if (playerFilesLoaded)
    {
        logMsg(func + " getPlayerFilesLoaded");

        if (!pInstance.empty())
        {
            logMsg(func + " Player Files Loaded!");
            retVal = true;
        }
        else
        {
            logMsg(func + " Player Files not yet Loaded!");

            playerFilesLoaded = false;
            pInstance = loadPlayerFiles();
            if (!pInstance.empty())
            {
                logMsg(func + " > 0!");

//                load->setTInstance(tInstance);
                playerFilesLoaded = true;
                retVal = true;
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

        if (!pInstance.empty())
        {
            logMsg(func + " load->getPInstance().size() > 0! ELSE");
//            load->setTInstance(tInstance);
            playerFilesLoaded = true;
            retVal = true;
        }
        else
        {
            logMsg(func + " ELSE ELSE!");

            pInstance = loadPlayerFiles();

            if (!pInstance.empty())
            {
                logMsg(func + " load->getPInstance().size() > 0! ELSE ELSE");

//                load->setTInstance(tInstance);
                playerFilesLoaded = true;
                retVal = true;
            }
            else
            {
                logMsg(func + " Failed to load Player Files!");
                retVal = false;
            }
        }
    }
//    exit(0);
    logMsg(func + " end");

    return (retVal);
}

playerEntityMSharedPtr loadPlayers::loadPlayerFiles()  // loads the players
{
    conversionSharedPtr convert ;

    playerEntityMSharedPtr players;
    playerEntitySharedPtr playerInstance; //(new playerState);
    std::string func = "loader::loadPlayers()";

    playerEntitySharedPtr player;//(new playerState);
    std::string playerList;
    
    logMsg(func +" begin");

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
        players.insert(std::pair<size_t, playerEntitySharedPtr>(it, loadPlayerFile("data/players/" + playerFiles[it])));
//        players.emplace(it, loadPlayerFile(findFile("data/players/" + playerFiles[it])));

#else
//        players.emplace(it, loadPlayerFile(findFile("players/" + playerFiles[it]));

        
        players.insert(std::pair<size_t, playerEntitySharedPtr>(it, loadPlayerFile(findFile("players/" + playerFiles[it]))));

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

stdStringVec loadPlayers::loadPlayerListFile(const std::string &fileName)  // loads the player list file
{
    conversionSharedPtr convert ;
  //   renderEngineSharedPtr render = renderEngine::Instance();
    stdStringVec pFiles;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    logMsg(fileName);
    char *contents = nullptr;
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
    
    tinyxml2::XMLHandle hRoot(nullptr);

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

playerEntitySharedPtr loadPlayers::loadPlayerFile(const std::string &fileName)  // loads the player file
{
    conversionSharedPtr convert ;
//    sharedPtr<gameState> gameS = gameState::Instance();
//    renderEngineSharedPtr render = renderEngine::Instance();
    std::string func = "loader::loadPlayerFile()";
    playerEntitySharedPtr playerInstance(new playerEntity);
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
    char *contents = nullptr;
    
    logMsg(func +" begin");
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

    tinyxml2::XMLHandle hRoot(nullptr);

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
//    playerInstance->setEntity(tempPEnt);
    logMsg(func +" name == " +firstName +" " +lastName);

    playerInstance->initializeObjects();
    if (firstName == "Xavier")
    {
        if (playerInstance->getFlag()->getInitialized())
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
    playerInstance->getData()->setLastName(lastName);
    playerInstance->getData()->setPlayerName(firstName +" " +lastName);
    playerInstance->getData()->setAge(age);
    playerInstance->getData()->setHeight(height);
    playerInstance->getData()->setWeight(weight);
    playerInstance->getData()->setID(ID);
    playerInstance->getData()->setTeamID(teamID);
    playerInstance->getComponent()->setName(firstName + lastName);
    playerInstance->getComponent()->setModelFileName(modelName);
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

