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
#include "utilities/android.h"
#else
#include "config.h"
#endif

#include "utilities/conversion.h"
#include "load/loadbasketballs.h"
#include "utilities/logging.h"
#include "data/basketballdata.h"
#include "entity/basketballentity.h"
#include "state/basketballstate.h"

// static declarations

basketballStateMSharedPtr loadBasketballs::bInstance;
stdStringVec loadBasketballs::basketballFiles;  // stores list of basketball xml files
bool loadBasketballs::basketballFilesLoaded;

loadBasketballs::loadBasketballs()  // constructor
{
    basketballFilesLoaded = false;
}
loadBasketballs::~loadBasketballs()  // destructor
{
    
}

stdStringVec loadBasketballs::getBasketballFiles()  // retrieves the value of basketballFiles
{
    return (basketballFiles);
}
void loadBasketballs::setBasketballFiles(stdStringVec set)  // sets the value of basketballFiles
{
    basketballFiles = set;
}

basketballStateMSharedPtr loadBasketballs::getBInstance()  // retrieves the value of bInstance
{
    return (bInstance);
}
void loadBasketballs::setBInstance(basketballStateMSharedPtr set)  // sets the value of bInstance
{
    bInstance = set;
}

bool loadBasketballs::getBasketballFilesLoaded()  // retrieves the value of basketballFilesLoaded
{
    return (basketballFilesLoaded);
}
void loadBasketballs::setBasketballFilesLoaded(bool set)  // sets the value of basketballFilesLoaded
{
    basketballFilesLoaded = set;
}

bool loadBasketballs::checkIfBasketballFilesLoaded()  // checks if basketballs have been loaded into bInstance
{
    conversionSharedPtr convert = conversion::Instance();
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
            bInstance = loadFiles();
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
            bInstance = loadFiles();
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

// Basketballs
basketballStateMSharedPtr loadBasketballs::loadFiles()  // load basketball settings from XML files
{
//    exit(0);
    basketballStateMSharedPtr basketballs;
    std::string basketballList;
    std::string func = "loader::loadBasketballs()";
    
    logMsg(func +" beginning");
    
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    basketballList = "data/basketballs/basketballs.xml";
#else
    basketballList = findFile("basketballs/basketballs.xml");
#endif
    basketballFiles = loadListFile(basketballList);
//    stdStringVec playerFiles = load->getPlayerFiles();

//    stdStringVec::iterator it;
    auto it = 0;
    //    for (it = basketballFiles.begin(); it != basketballFiles.end(); ++it)
    {
        logMsg("basketballFile = " +basketballFiles[it]);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//        basketballs.push_back(loadFile("data/basketballs/" + *it));
        basketballs.insert(std::pair<size_t, basketballStateSharedPtr>(it, loadFile("data/basketballs/" + basketballFiles[it])));

#else
//        basketballs.push_back(loadFile(findFile("basketballs/" + *it)));
        basketballs.insert(std::pair<size_t, basketballStateSharedPtr>(it, loadFile(findFile("basketballs/" + basketballFiles[it]))));
#endif
    }
    logMsg(func +" end");
    return (basketballs);
}

stdStringVec loadBasketballs::loadListFile(std::string fileName) // loads the list of baskteball list file
{
    conversionSharedPtr convert = conversion::Instance();
//    renderEngineSharedPtr render = renderEngine::Instance();
    stdStringVec bballFiles;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    std::string func = "loader::loadListFile()";
    
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

basketballStateSharedPtr loadBasketballs::loadFile(std::string fileName)  // loads data from the basketball XML files
{
    conversionSharedPtr convert = conversion::Instance();
    sharedPtr<basketballState> basketballInstance(new basketballState);
    
//    basketballState *basketball = new basketballState;
    std::string name;
    std::string modelName;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    char *contents = NULL;
    std::string func = "loader::loadFile()";
    
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

basketballStateMSharedPtr loadBasketballs::loadModels(basketballStateMSharedPtr activeBasketballInstance)  // loads selected basketball model
{
    conversionSharedPtr convert = conversion::Instance();
    loaderSharedPtr load(new loader);
    gameSetupBasketballsSharedPtr gameSetupBasketball;
//    basketballStateMSharedPtr activeBasketballInstance = getActiveBasketballInstance();
//    bool activeBasketballInstancesCreated = getActiveBasketballInstancesCreated();
//    size_t activeBBallInstance = getActiveBBallInstance();
//    basketballStateMSharedPtr basketballInstance = getBasketballInstance();
    std::string func = "loadBasketballs::loadModels()";
    bool returnType = false;
    
    logMsg(func +" beginning");
    
/*    if (!activeBasketballInstancesCreated && activeBasketballInstance.size() == 0)
    {
        if (basketballInstance.size() == 0)
        {
            basketballInstance = gameSetupBasketball->createBasketballInstances();
            activeBasketballInstance = gameSetupBasketball->createActiveBasketballInstances(basketballInstance, getNumActiveBasketballs());
            if (activeBasketballInstance.size() > 0)
            {
                logMsg(func +" Active Basketball Instances Created!");
                activeBasketballInstancesCreated = true;
            }
            else
            {
                logMsg(func +" Unable to create Active Basketball Instances!");
                exit(0);
            }
        }
    }
    else
    {
        
    }
*/
    logMsg(func +" activeBasketballInstance.size() == " +convert->toString(activeBasketballInstance.size()));

    for (auto ABIIT : activeBasketballInstance)
    {
        logMsg(func +" activeBasketballInstance == " +convert->toString(ABIIT.first));
    

/*        if (!activeBasketballInstance[0]->getEntity()->getBaseInitialized()) // checks to see if the base object for basketballInstance[activeBBallIntance has been initialized
        {
            logMsg(func +" Initializing base!");
            if (!ABIIT.second->getEntity()->getBaseInitialized())
            {
                ABIIT.second->getEntity()->setBase(base);
            }
        }*/
       
        if (ABIIT.second->getEntity()->getEntityName() == "")
        {
            std::string name = ABIIT.second->getData()->getName();
            ABIIT.second->getEntity()->setEntityName(name);
        }
        logMsg(func +" entityName == " +ABIIT.second->getEntity()->getEntityName());
//        exit(0);
        if (ABIIT.second->getEntity()->getEntityNodeName() == "")
        {
            std::string nodeName = ABIIT.second->getData()->getName() +"node";
            ABIIT.second->getEntity()->setEntityNodeName(nodeName);
        }
        logMsg(func +" basketball name == " +ABIIT.second->getData()->getName());
        logMsg(func + " basketball node name == " +ABIIT.second->getEntity()->getEntityNodeName());
//        exit(0);
        logMsg(func +" loading model == " +ABIIT.second->getEntity()->getEntityModelFileName());
        if (ABIIT.second->getEntity()->loadModel())
        {
            logMsg(func +" modelName == " +ABIIT.second->getEntity()->getModel()->getName());
            logMsg(func +" nodeName == " +ABIIT.second->getEntity()->getNode()->getName());
 
//            exit(0);
            ABIIT.second->getEntity()->setModelNeedsLoaded(false);
            logMsg(func +" blaa!");
            ABIIT.second->getEntity()->setModelLoaded(true);
            logMsg(func +" blii!");
            ABIIT.second->getEntity()->setupPhysicsObject();
/*            logMsg(func +" bluu!");
            setActiveBasketballInstance(activeBasketballInstance);
            logMsg(func +" Basketball Model Loaded!");
*/
            returnType = true;

        }
        else
        {
            logMsg("Failed to load the basketball model!");
        }
        
    }
    logMsg(func +" alive?");
//    setActiveBasketballInstance(activeBasketballInstance);
    logMsg(func +" still alive?");
//    setActiveBasketballInstancesCreated(activeBasketballInstancesCreated);
//    exit(0);
    logMsg(func + " end");
    return (activeBasketballInstance);
}

bool loadBasketballs::loadModelFile()  // loads the 3D model
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

