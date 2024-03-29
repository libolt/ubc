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

#include "utilities/conversion.h"
#include "load/loadhoops.h"
#include "engine/renderengine.h"
#include "utilities/logging.h"
#include "components/hoopcomponents.h"
#include "entity/hoopentity.h"
#include "flags/hoopflags.h"

loadHoops::loadHoops()  // constructor
{
    hoopFilesLoaded = false;

}
loadHoops::~loadHoops() = default;  // destructor

hoopEntityMSharedPtr loadHoops::getHInstance() const  // retrieves the value of hInstance
{
    return (hInstance);
}
void loadHoops::setHInstance(const hoopEntityMSharedPtr &set)  // sets the value of hInstance
{
    hInstance = set;
}

bool loadHoops::checkIfHoopsLoaded()  // checks if the hooops have been loaded into hInstance
{
    bool retVal = false;
    std::string func = "loadHoops::checkIfHoopsLoaded()";
    
    logMsg(func +" begin");
    
    if (hoopFilesLoaded)
    {
        logMsg(func +" getHoooFilesLoaded");
//        exit(0);
        if (!hInstance.empty())
        {
            logMsg(func +" Hoop Files Loaded!");
            retVal = true;
        }
        else
        {
            logMsg(func +" Hoop Files not yet Loaded!");

            hoopFilesLoaded = false;
            hInstance = loadHoopFiles();
//            exit(0);
            if (!hInstance.empty())
            {
                logMsg(func +"  > 0!");

//                load->setTInstance(tInstance);
                hoopFilesLoaded = true;
                retVal = true;
            }
            else
            {
                logMsg(func +" Failed to load Hoop Files! IF");
                exit(0);
            }
        }
    }
    else 
    {
        logMsg(func +" ELSE");
//        exit(0);
        if (!hInstance.empty())
        {
            logMsg(func +" load->getHInstance().size() > 0! ELSE");
//            load->setTInstance(tInstance);
            hoopFilesLoaded = true;
            retVal = true;
        }
        else
        {
            logMsg(func +" ELSE ELSE!");

            hInstance = loadHoopFiles();
            logMsg(func);
            if (!hInstance.empty())
            {
                logMsg(func +" load->getHInstance().size() > 0! ELSE ELSE");

//                load->setTInstance(tInstance);
                hoopFilesLoaded = true;
                retVal = true;
            }
            else
            {
                logMsg(func +" Failed to load Hop Files!");
                retVal = false;
            }
        }
    }
    
    logMsg(func +" end");
    
    return (retVal);
}

hoopEntityMSharedPtr  loadHoops::loadHoopFiles()  // load hoop XML files
{
//    exit(0);
    hoopEntityMSharedPtr  hoops;
    std::string hoopList;
    std::string func = "loadHoops::loadHoops()";

    logMsg(func +" begin");

#ifdef __ANDROID
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
#ifdef __ANDROID
        hoops.insert(std::pair<size_t, hoopEntitySharedPtr>(it, loadHoopFile("data/hoops/" + hoopFiles[it])));
#else
        hoops.insert(std::pair<size_t, hoopEntitySharedPtr>(it, loadHoopFile(findFile("hoops/" + hoopFiles[it]))));
#endif
    }

    logMsg(func +" end");

    return (hoops);
}

stdStringVec loadHoops::loadHoopListFile(const std::string &fileName)  // load the list of hoops from hoops.xml
{
    conversionSharedPtr convert ;
//    renderEngineSharedPtr render = renderEngine::Instance();
    stdStringVec hFiles;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    std::string func = "loadHoops::loadHoopListFile()";

    logMsg(func +" begin");

    logMsg(func +" " +fileName);
    char *contents = nullptr;
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
    tinyxml2::XMLHandle hRoot(nullptr);

    pElem=hDoc.FirstChildElement().ToElement();
    // should always have a valid root but handle gracefully if it does
    if (!pElem)
    {
        logMsg(func +" Unable to find a vlid court list root!");
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

    logMsg(func +" end");

//    setCourtFiles(courtFile);
//    return true;
    return (hFiles);
}

hoopEntitySharedPtr loadHoops::loadHoopFile(const std::string &fileName)  // loads data from the hoop XML files.
{
    conversionSharedPtr convert ;
    hoopEntitySharedPtr hoopInstance(new hoopEntity);
//    hoopEntitySharedPtr entity(new hoopEntity);
    
//    hoopState *hoop = new hoopState;
    std::string name;
    std::string modelName;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    char *contents = nullptr;
    std::string func = "loadHoops::loadHoopFile()";

    logMsg(func +" begin");

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
    tinyxml2::XMLHandle hRoot(nullptr);

    logMsg(func +" rootElement?");

    rootElement = hDoc.FirstChildElement().ToElement();

    logMsg(func +" rootElement!");
    logMsg(func +" rootElement = " + convert->toString(rootElement));

    // should always have a valid root but handle gracefully if it does
    if (!rootElement)
    {
        logMsg(func +" Unable to load hoop element");
        exit(0);
    }

    logMsg(func +" child?");
    child = rootElement->FirstChild()->ToElement();
    if (child)
    {
        std::string cKey = child->Value();
        if (cKey == "Name")
        {
            logMsg(func +" name!");
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
    hoopInstance->initializeObjects();

    if (!hoopInstance->getFlag()->getInitialized())
    {
        if (hoopInstance->initializeStateMachine())
        {
            hoopInstance->getFlag()->setInitialized(true);
        }
        else
        {
//            logMsg(func +" Unable to initialize basketball instance!");
            exit(0);
        }
    }
    hoopInstance->getComponent()->setName(name);
//    exit(0);
//    hoopInstance->setModelFileName(modelName);
//    hoopInstance->setEntityName(name);
    hoopInstance->getComponent()->setModelFileName(modelName);
//    hoopInstance->setEntity(entity);
//    hoopInstance->setEntityInitialized(true);
    logMsg(func +" Entity Model Name = " +hoopInstance->getComponent()->getModelFileName());
//    exit(0);
    return (hoopInstance);
}

/*hoopEntityMSharedPtr loadHoops::loadModels(hoopEntityMSharedPtr activeHoopInstance, const renderEngineSharedPtr &render)  // loads selected hoop model
{
    conversionSharedPtr convert ;
//    hoopStateMSharedPtr activeHoopInstance = getActiveHoopInstance();
//    loaderSharedPtr load(new loader);
    Ogre::v1::Entity model;  // stores the model returned by loadModel() function

    std::string func = "loadHoops::loadModels()";
    bool returnType = true;

    logMsg(func +" begin");

    logMsg(func +" activeHoopInstance.size() == " +convert->toString(activeHoopInstance.size()));
    
    for (auto AHIIT : activeHoopInstance)
    {
        bool modelLoaded = AHIIT.second->getFlag()->getModelLoaded();
        if (!modelLoaded)
        {
        logMsg(func +" activeHoopInstance == " +convert->toString(AHIIT.first));
        //FIXME! This should be done in a cleaner way!
//        AHIIT.second->getEntity()->setEntityModelFileName(AHIIT.second->getEntityModelFileName());

//        logMsg(func + " name = " +AHIIT.second->getName());
//        logMsg(func + " entity name = " +AHIIT.second->getEntity()->getEntityName());
        if (!AHIIT.second->getFlag()->getNameSet())  // checks if entityName has been set
        {
            std::string name = AHIIT.second->getComponent()->getName();
            logMsg(func +" name == " +=name);
            AHIIT.second->getComponent()->setName(name);
        }
        else
        {
///            logMsg(func +" entityName == " +AHIIT.second->getEntity()->getEntityName());
//            exit(0);
        }
 

        logMsg(func +" entityName == " +AHIIT.second->getComponent()->getName());
//        exit(0);
        if (!AHIIT.second->getFlag()->getNodeNameSet())  // checks if entityNodeName has been set
        {
            std::string nodeName = AHIIT.second->getComponent()->getName() +"node";
            AHIIT.second->getComponent()->setNodeName(nodeName);
        }
        else
        {
            
        }
        logMsg(func +"nodeName == " +AHIIT.second->getComponent()->getNodeName());
        
//        logMsg(func +" hoop name == " +AHIIT.second->getName());
//        logMsg(func + " hoop node name == " +AHIIT.second->getEntity()->getEntityNodeName());
//        exit(0);
        logMsg(func +" loading model == " +AHIIT.second->getComponent()->getModelFileName());
        std::string modelFileName = AHIIT.second->getComponent()->getModelFileName();
        std::string entityName = AHIIT.second->getComponent()->getName() +convert->toString(AHIIT.first);
        std::string entityNodeName = AHIIT.second->getComponent()->getNodeName();
        logMsg(func +" modelFileName == " +=modelFileName);
//        exit(0);
        logMsg(func +"load entityName == "  +=entityName);
//        logMsg(func +" entityNodeName == " +entityNodeName);

        model = loadModelFile(modelFileName, entityName, render);
        AHIIT.second->getFlag()->setModelLoaded(true);
        AHIIT.second->getComponent()->setModel(model);
        
        }
        
    }
//    exit(0);
    for (auto AHIIT : activeHoopInstance)
    {
        logMsg(func +" model name == " +AHIIT.second->getComponent()->getModel()->getName());
    }

    logMsg(func +" end");
//    exit(0);
    
    return (activeHoopInstance);
} */

void loadHoops::loadModel(hoopComponentsSharedPtr &component, hoopFlagsSharedPtr &flag, const renderEngineSharedPtr &render)  // loads selected court model
{
    conversionSharedPtr convert ;
    loaderSharedPtr load(new loader);
    Ogre::v1::Entity *model;  // stores the model returned by loadModel() function
    std::string func = "loadHoops::loadModels()";

    logMsg(func +" begin");

    //FIXME! This should be done in a cleaner way!
///        component->setModelFileName(data->getModelFileName());

///        if (component->getName().empty())  // checks if entityName has been set
///        {
///            std::string name = data->getName();
///            component->setName(name);
///        }
    logMsg(func +" entityName == " +component->getName());
//        exit(0);
///        if (component->getNodeName().empty())  // checks if entityNodeName has been set
///        {
///            std::string nodeName = data->getName() +"node";
///            component->setNodeName(nodeName);
///        }
///        logMsg(func +" court name == " +data->getName());
    logMsg(func + " court node name == " +component->getNodeName());
//        exit(0);
    logMsg(func +" loading model == " +component->getModelFileName());
//        exit(0);
    std::string modelFileName = component->getModelFileName();
    std::string entityName = component->getName();
    std::string entityNodeName = component->getNodeName();

    model = loadModelFile(modelFileName, entityName, render);
    flag->setModelLoaded(true);
    component->setModel(model);

    logMsg(func +" end");
//    exit(0);
}
