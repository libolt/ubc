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
#include "utilities/android-config.h"
#else
#include "config.h"
#endif

#include "utilities/conversion.h"
#include "load/loadhoops.h"
#include "utilities/logging.h"
#include "state/hoopstate.h"

// static declarations
hoopStateMSharedPtr  loadHoops::hInstance;
stdStringVec loadHoops::hoopFiles;  // stores list of hoop xml files
bool loadHoops::hoopFilesLoaded;

loadHoops::loadHoops()  // constructor
{
    hoopFilesLoaded = false;

}
loadHoops::~loadHoops()  // destructor
{
}

hoopStateMSharedPtr loadHoops::getHInstance()  // retrieves the value of hInstance
{
    return (hInstance);
}
void loadHoops::setHInstance(hoopStateMSharedPtr set)  // sets the value of hInstance
{
    hInstance = set;
}

bool loadHoops::checkIfHoopsLoaded()  // checks if the hooops have been loaded into hInstance
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
            hInstance = loadHoopFiles();
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

            hInstance = loadHoopFiles();
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

hoopStateMSharedPtr  loadHoops::loadHoopFiles()  // load hoop XML files
{
//    exit(0);
    hoopStateMSharedPtr  hoops;
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

stdStringVec loadHoops::loadHoopListFile(std::string fileName)  // load the list of hoops from hoops.xml
{
    conversionSharedPtr convert = conversion::Instance();
//    renderEngineSharedPtr render = renderEngine::Instance();
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

hoopStateSharedPtr loadHoops::loadHoopFile(std::string fileName)  // loads data from the hoop XML files.
{
    conversionSharedPtr convert = conversion::Instance();
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

hoopStateMSharedPtr loadHoops::loadModels(hoopStateMSharedPtr activeHoopInstance)  // loads selected hoop model
{
    conversionSharedPtr convert = conversion::Instance();
//    hoopStateMSharedPtr activeHoopInstance = getActiveHoopInstance();
//    loaderSharedPtr load(new loader);
    std::string func = "gameState::loadHoopModel()";
    bool returnType = true;

    logMsg(func +" beginning");

///    if (activeHoopInstance.size() == 0)
///    {
///        if (createActiveHoopInstances())
///        {
///            logMsg(func +" Active Hoop Instances created!");
///        }
///        else
///        {
///            logMsg(func +" Unable to create Active Hoop Instances!");
///            exit(0);
///        }
///    }
///    else
///    {        
///    }

    logMsg(func +" activeHoopInstance.size() == " +convert->toString(activeHoopInstance.size()));
//    logMsg(func + " activeCourtInstance == " +convert->toString(activeCourtInstance));
    for (auto AHIIT : activeHoopInstance)
    {
        logMsg(func + " AHIIT index == " +convert->toString(AHIIT.first));
        std::string name = AHIIT.second->getName();
        std:: string nodeName = name +"node";
        logMsg(func +" blnodeName == " +nodeName);

    }
    
    
    for (auto AHIIT : activeHoopInstance)
    {
        logMsg(func + " wAHIIT index == " +convert->toString(AHIIT.first));
        logMsg(func + " Name == " +AHIIT.second->getName());
        logMsg(func +" Model Name = " +AHIIT.second->getEntityModelFileName());

///        logMsg(func + "Name == " +AHIIT.second->getName());
///        logMsg(func +" Model Name = " +AHIIT.second->getEntityModelFileName());
///        logMsg("AHIIT index == " +convert->toString(AHIIT.second->getEntityID()));

        std::string name = AHIIT.second->getName();
        std:: string nodeName = name +"node";
        logMsg(func +" blnodeName == " +nodeName);
        AHIIT.second->setEntityName(name);
        AHIIT.second->setEntityNodeName(nodeName);
        logMsg("AHIIT.second->loadModel()");
        
        if (AHIIT.second->loadModel())
        {
            logMsg(func +" Model loaded successfully!");
            AHIIT.second->getNode()->setScale(0.8f,0.8f,0.8f);
        }
        else
        {
            
            logMsg(func +" Unable to load model for activeHoopInstance[" +convert->toString(AHIIT.first) +"]");
            returnType = false;
        }
        
    }
///    if (hoopInstance[1]->loadModel())
///    {
///        hoopInstance[1]->getNode()->setScale(0.8f,0.8f,0.8f);
///    }
///    else
///    {
///        logMsg(func +" Unable to load model for hoopInstance[1]");
///        returnType = false;
///    }
    
//    setActiveHoopInstance(activeHoopInstance);
    for (auto AHIIT : activeHoopInstance())
    {
//        logMsg ("blhoop " +convert->toString(AHIIT.first) +" name === " +AHIIT.second->getEntityName());

        logMsg ("blhoop " +convert->toString(AHIIT.first) +" nodename === " +AHIIT.second->getNode()->getName());
        logMsg ("blhoop " +convert->toString(AHIIT.first) +" entityID === " +convert->toString(AHIIT.second->getEntityID()));

    }
    logMsg(func +" end");
//    exit(0);
    
    return (activeHoopInstance);
} 

bool loadHoops::loadModelFile()  // loads the 3D model
{
    conversionSharedPtr convert = conversion::Instance();
    std::string func = "loadBasketballs::loadModelFile()";
//BASEREMOVAL    renderEngineSharedPtr render = base->getGameE()->getRenderE();
    renderEngineSharedPtr render;
    sharedPtr<Ogre::SceneManager> mSceneMgr = render->getMSceneMgr();
    Ogre::ResourceGroupManager &rsm = Ogre::ResourceGroupManager::getSingleton();
    OgreEntitySharedPtr tempModel;
    OgreSceneNodeSharedPtr tempNode; //(new Ogre::SceneNode);

    entityNodeName = entityName + "node";
    logMsg(func +" beginning");
    logMsg(func +" baseInitialized == " +convert->toString(baseInitialized));
    logMsg(func +" ECB entityName == " +entityName);
    logMsg(func +" ECB entityModelFileName == " +entityModelFileName);
    logMsg(func +" ECB entityNodeName == " +entityNodeName);
        
    if (rsm.resourceGroupExists("UBCData"))
    {
        logMsg(func +" UBData exists!");
        if (rsm.resourceExists("UBCData", entityModelFileName))
        {
            logMsg(func +" " +entityModelFileName +" exists!");
        }
        else
        {
            logMsg(func +" " +entityModelFileName +" doesn't exist!");
        }
    }
    else
    {
        logMsg(func +" UBData doesnt exist!");

    }
    
//BASEREMOVAL    if (base->getGameE()->getRenderE().get()->getMSceneMgr()->hasCamera("camera"))
    if (render.get()->getMSceneMgr()->hasCamera("camera"))
    {
        logMsg(func +" mSceneMgr has camera!");
    }
    else
    {
        logMsg(func +" mSceneMgr does not have camera!");
    }
    
    logMsg(func +" Entity Name == " +entityName + " Model File Name == " +entityModelFileName);
//BASEREMOVAL    tempModel = OgreEntitySharedPtr(base->getGameE()->getRenderE()->getMSceneMgr()->createEntity(entityName, entityModelFileName, "UBCData"));  // loads the model
    tempModel = OgreEntitySharedPtr(render->getMSceneMgr()->createEntity(entityName, entityModelFileName, "UBCData"));  // loads the model

    logMsg(func +" tempModel loaded!");
    
//    render->getMSceneMgr()->
//    Ogre::Entity *tempModel = render->getMSceneMgr()->createEntity("dah!", "Player.mesh");
    
    model = OgreEntitySharedPtr(tempModel);
    logMsg(func +" Entity Created!");
//    exit(0);
    // creates and instantiates the node object
//    node = getRenderE()->getMSceneMgr()->getRootSceneNode()->createChildSceneNode(entityNodeName);
///    if (entityNodeName == "")
///    {
///        entityNodeName = entityName +"node";
//        entityNodeName = "das";
///    }

    logMsg(func +" entityNodeName == " +entityNodeName);
//    exit(0);
//BASEREMOVAL    tempNode = OgreSceneNodeSharedPtr(base->getGameE()->getRenderE()->getMSceneMgr()->getRootSceneNode()->createChildSceneNode(entityNodeName));
    tempNode = OgreSceneNodeSharedPtr(render->getMSceneMgr()->getRootSceneNode()->createChildSceneNode(entityNodeName));

//    tempNode->setName(entityNodeName);
    tempNode->attachObject(model.get());
    logMsg(func +" node attached!");
    
    // attaches 3D model to the node
//    node->attachObject(model);
    // sets the size of the bball node
    tempNode->setScale(0.25f,0.25f,0.25f);
    tempNode->setPosition(0.0f,0.0f,0.0f);
    
    node = tempNode;
    logMsg(func +" ECB node name == " +node->getName());
    logMsg(func +" node position == " +convert->toString(node->getPosition()));
//    exit(0);
///    logMsg("scene node created!");
///    node->attachObject(model);
///    logMsg("node attached!");
    // attaches 3D model to the node
//    node->attachObject(model);
    // sets the size of the bball node
///    node->setScale(0.25f,0.25f,0.25f);
///    node->setPosition(0.0f,0.0f,0.0f);

    logMsg(func +" end");
    
    return (true);
}

