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
#include "entity/basketballentity.h"
#include "state/basketballstate.h"

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

    if (!basketballInstance->getInitialized())
    {
        if (basketballInstance->initialize())
        {
            basketballInstance->setInitialized(true);
        }
        else
        {
//            logMsg(func +" Unable to initialize basketball instance!");
            exit(0);
        }
    }
    basketballInstance->getData()->setName(name);
    basketballInstance->getData()->setModelFileName(modelName);
    basketballInstance->getEntity()->setEntityModelFileName(modelName);
    
    return (basketballInstance);
}


