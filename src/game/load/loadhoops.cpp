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

