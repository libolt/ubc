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
#include "load/loadoffenseplays.h"
#include "utilities/logging.h"
#include "offenseplays.h"

// static declarations
offensePlaysVecSharedPtr loadOffensePlays::opInstance;
stdStringVec loadOffensePlays::offensePlayFiles;  // stores list of offense play xml files
bool loadOffensePlays::offensePlayFilesLoaded;


loadOffensePlays::loadOffensePlays()  // constructor
{
    offensePlayFilesLoaded = false;
}
loadOffensePlays::~loadOffensePlays()  // destructor
{

}

stdStringVec loadOffensePlays::getOffensePlayFiles() const  // retrieves the value of offensePlayFiles
{
    return (offensePlayFiles);
}
void loadOffensePlays::setOffensePlayFiles(const stdStringVec &set)  // sets the value of offensePlayFiles
{
    offensePlayFiles = set;
}

offensePlaysVecSharedPtr loadOffensePlays::getOPInstance() const  // retrieves the value of opInstance
{
    return (opInstance);
}
void loadOffensePlays::setOPInstance(const offensePlaysVecSharedPtr &set)  // sets the value of opInstance
{
    opInstance = set;
}

bool loadOffensePlays::getOffensePlayFilesLoaded() const  // retrieves the value of offensePlayFilesLoaded
{
    return (offensePlayFilesLoaded);
}
void loadOffensePlays::setOffensePlayFilesLoaded(const bool &set)  // sets the value of offensePlayFilesLoaded
{
    offensePlayFilesLoaded = set;
}

bool loadOffensePlays::checkIfOffensePlaysLoaded()  // checks if offense plays have been loaded into opInstance
{
    std::string func = "loadOffensePlays::checkIfOffensePlaysLoaded()";

    logMsg(func +" begin");
    if (offensePlayFilesLoaded)
    {
        logMsg(func +" getOffensePlayFilesLoaded");

        if (opInstance.size() > 0)
        {
            logMsg(func +" Offense Play Files Loaded!");
            return(true);
        }
        else
        {
            logMsg(func +" Offense Plays Files not yet Loaded!");

            offensePlayFilesLoaded = false;
            opInstance = loadOffensePlayFiles();
            if (opInstance.size() > 0)
            {
                logMsg(func +" > 0!");

//                load->setTInstance(tInstance);
                offensePlayFilesLoaded = true;
                return(true);
            }
            else
            {
                logMsg(func +" Failed to load Offense Play Files! IF");
                exit(0);
            }
        }
    }
    else
    {
        logMsg(func +" ELSE");

        if (opInstance.size() > 0)
        {
            logMsg(func +" load->getOPInstance().size() > 0! ELSE");
//            load->setTInstance(tInstance);
            offensePlayFilesLoaded = true;
            return(true);
        }
        else
        {
            logMsg(func +" ELSE ELSE!");

            opInstance = loadOffensePlayFiles();
            if (opInstance.size() > 0)
            {
                logMsg(func +" load->getOPInstance().size() > 0! ELSE ELSE");

//                load->setTInstance(tInstance);
                offensePlayFilesLoaded = true;
                return(true);
            }
            else
            {
                logMsg(func +" Failed to load Offense Play Files!");
                return(false);
            }
        }
    }


    logMsg(func +" end");

    return (false);
}

//Offense
offensePlaysVecSharedPtr loadOffensePlays::loadOffensePlayFiles()  // load offense plays from XML files
{
    offensePlaysVecSharedPtr plays;
    std::string playList;
    std::string func = "loadOffensePlays::loadOffensePlayFiles()";

    logMsg(func +" begin");
    
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
        logMsg(func +" offensePlayFile = " +*it);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        plays.push_back(loadOffensePlayFile("data/offense/plays/" + *it));
#else
        plays.push_back(loadOffensePlayFile(findFile("offense/plays/" + *it)));
#endif
    }
    
    logMsg(func +" end");
    
    return (plays);
}

stdStringVec loadOffensePlays::loadOffensePlayListFile(std::string fileName)  // loads the play list file
{
    conversionSharedPtr convert ;
//    renderEngineSharedPtr render = renderEngine::Instance();

    stdStringVec playFiles;
    std::string func = "loadOffensePlays::loadOffensePlayListFile()";
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    logMsg(func +" " +fileName);
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
        logMsg(func +" Unable to find a valid offense play list file root!");
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

sharedPtr<offensePlays> loadOffensePlays::loadOffensePlayFile(std::string fileName)  // loads data from the offense play XML files
{
    conversionSharedPtr convert ;
    
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
    std::string func = "loadOffensePlays::loadOffensePlayFile()";

    
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
        logMsg(func +" Unable to load offense play element");
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





