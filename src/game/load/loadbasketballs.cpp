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
#include "utilities/android.h"
#else
#include "config.h"
#endif

#include "utilities/conversion.h"
#include "load/loadbasketballs.h"
#include "utilities/logging.h"
#include "components/basketballcomponents.h"
#include "data/basketballdata.h"
#include "engine/renderengine.h"
#include "entity/basketballentity.h"
#include "engine/renderengine.h"
#include "flags/basketballflags.h"

#include "statemachine/basketballstatemachine.h"

loadBasketballs::loadBasketballs()  // constructor
{
    basketballFilesLoaded = false;
}
loadBasketballs::~loadBasketballs() = default;  // destructor

stdStringVec loadBasketballs::getBasketballFiles() const  // retrieves the value of basketballFiles
{
    return (basketballFiles);
}
void loadBasketballs::setBasketballFiles(const stdStringVec &set)  // sets the value of basketballFiles
{
    basketballFiles = set;
}

basketballEntityMSharedPtr loadBasketballs::getBInstance() const  // retrieves the value of bInstance
{
    return (bInstance);
}
void loadBasketballs::setBInstance(const basketballEntityMSharedPtr &set)  // sets the value of bInstance
{
    bInstance = set;
}

bool loadBasketballs::getBasketballFilesLoaded() const  // retrieves the value of basketballFilesLoaded
{
    return (basketballFilesLoaded);
}
void loadBasketballs::setBasketballFilesLoaded(const bool &set)  // sets the value of basketballFilesLoaded
{
    basketballFilesLoaded = set;
}

bool loadBasketballs::checkIfBasketballFilesLoaded()  // checks if basketballs have been loaded into bInstance
{
    conversionSharedPtr convert ;
    bool retVal = false;
    std::string func = "loadBasketballs::checkBasketballsLoaded()";
    
    logMsg(func +" begin");
    
    if (basketballFilesLoaded)
    {
        logMsg(func +" getBasketballFilesLoaded");

        if (!bInstance.empty())
        {
            logMsg(func +" Basketball Files Loaded!");
            retVal = true;
        }
        else
        {
            logMsg(func +" Basketball Files not yet Loaded!");

            basketballFilesLoaded = false;
            bInstance = loadFiles();
            if (!bInstance.empty())
            {
                logMsg(func +" > 0!");

//                load->setTInstance(tInstance);
                basketballFilesLoaded = true;
                retVal = true;
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

        if (!bInstance.empty())
        {
            logMsg(func +" load->getBInstance().size() > 0! ELSE");
//            load->setTInstance(tInstance);
            basketballFilesLoaded = true;
            retVal = true;
        }
        else
        {
            logMsg(func +" ELSE ELSE!");
            bInstance = loadFiles();
            logMsg(func +" blah");

            logMsg(func +" bInstance.size() == " +convert->toString(bInstance.size()));

//            logMsg("loader::checkBasketballsLoaded()");
            if (!bInstance.empty())
            {
                logMsg(func +" load->getBInstance().size() > 0! ELSE ELSE");

//                load->setTInstance(tInstance);
                basketballFilesLoaded = true;
                retVal = true;
            }
            else
            {
                logMsg(func +" Failed to load Basketball Files!");
                retVal = false;
            }
        }
    }
    
    logMsg(func + " end");
    return (retVal);
}

// Basketballs
basketballEntityMSharedPtr loadBasketballs::loadFiles()  // load basketball settings from XML files
{
//    exit(0);
    basketballEntityMSharedPtr basketballs;
    std::string basketballList;
    std::string func = "loadBasketballs::loadBasketballs()";
    
    logMsg(func +" begin");
    
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
        basketballs.insert(std::pair<size_t, basketballEntitySharedPtr>(it, loadFile("data/basketballs/" + basketballFiles[it])));

#else
//        basketballs.push_back(loadFile(findFile("basketballs/" + *it)));
        basketballs.insert(std::pair<size_t, basketballEntitySharedPtr>(it, loadFile(findFile("basketballs/" + basketballFiles[it]))));
#endif
    }
    logMsg(func +" end");
    return (basketballs);
}

stdStringVec loadBasketballs::loadListFile(const std::string &fileName) // loads the list of baskteball list file
{
    conversionSharedPtr convert ;
//    renderEngineSharedPtr render = renderEngine::Instance();
    stdStringVec bballFiles;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    std::string func = "loadBasketballs::loadListFile()";
    
    logMsg(func +" begin");

    logMsg(fileName);
    char *contents = nullptr;
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
    tinyxml2::XMLHandle hRoot(nullptr);
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

basketballEntitySharedPtr loadBasketballs::loadFile(const std::string &fileName)  // loads data from the basketball XML files
{
    conversionSharedPtr convert ;
    basketballEntitySharedPtr basketballInstance(new basketballEntity);
    
//    basketballState *basketball = new basketballState;
    std::string name;
    std::string modelName;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    char *contents = nullptr;
    std::string func = "loadBasketballs::loadFile()";
    
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
        logMsg(func +" Unable to load basketball element");
        exit(0);
    }

    logMsg(func +" child?");
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

    if (!basketballInstance->getFlag()->getInitialized())
    {
        if (basketballInstance->initializeStateMachine())
        {
            basketballInstance->getFlag()->setInitialized(true);
        }
        else
        {
//            logMsg(func +" Unable to initialize basketball instance!");
            exit(0);
        }
    }
    basketballInstance->getData()->setName(name);
    basketballInstance->getData()->setModelFileName(modelName);
    basketballInstance->getComponent()->setModelFileName(modelName);
    
    return (basketballInstance);
}

basketballEntityMSharedPtr loadBasketballs::loadModels(basketballEntityMSharedPtr activeBasketballInstance, const renderEngineSharedPtr &render)  // loads selected basketball model
{
    conversionSharedPtr convert ;
    loaderSharedPtr load(new loader);
    setupBasketballsSharedPtr setupBasketball;
//    basketballEntityMSharedPtr activeBasketballInstance = getActiveBasketballInstance();
//    bool activeBasketballInstancesCreated = getActiveBasketballInstancesCreated();
//    size_t activeBBallInstance = getActiveBBallInstance();
//    basketballEntityMSharedPtr basketballInstance = getBasketballInstance();
//    basketballEntitySharedPtr basketballModelInstance(new basketballState);
    OgreEntitySharedPtr model;  // stores the model returned by loadModel() function
    std::string func = "loadBasketballs::loadModels()";
    bool returnType = false;
    
    logMsg(func +" begin");
    
    logMsg(func +" activeBasketballInstance.size() == " +convert->toString(activeBasketballInstance.size()));

    for (auto ABIIT : activeBasketballInstance)
    {
        logMsg(func +" activeBasketballInstance == " +convert->toString(ABIIT.first));
       
        //FIXME! This should be done in a cleaner way!
        ABIIT.second->getComponent()->setModelFileName(ABIIT.second->getData()->getModelFileName());

        if (ABIIT.second->getComponent()->getName().empty())  // checks if entityName has been set
        {
            std::string name = ABIIT.second->getData()->getName();
            ABIIT.second->getComponent()->setName(name);
        }
        logMsg(func +" entityName == " +ABIIT.second->getComponent()->getName());
//        exit(0);
        if (ABIIT.second->getComponent()->getNodeName().empty())  // checks if entityNodeName has been set
        {
            std::string nodeName = ABIIT.second->getData()->getName() +"node";
            ABIIT.second->getComponent()->setNodeName(nodeName);
        }
        logMsg(func +" basketball name == " +ABIIT.second->getData()->getName());
        logMsg(func +" basketball node name == " +ABIIT.second->getComponent()->getNodeName());
//        exit(0);
        logMsg(func +" loading model == " +ABIIT.second->getComponent()->getModelFileName());
        std::string modelFileName = ABIIT.second->getComponent()->getModelFileName();
        std::string entityName = ABIIT.second->getComponent()->getName();
        std::string entityNodeName = ABIIT.second->getComponent()->getNodeName();

        model = loadModelFile(modelFileName, entityName, render);
        ABIIT.second->getFlag()->setModelLoaded(true);
        ABIIT.second->getComponent()->setModel(model);

/*        if (ABIIT.second->loadModel())
        {
            logMsg(func +" modelName == " +ABIIT.second->getModel()->getName());
            logMsg(func +" nodeName == " +ABIIT.second->getNode()->getName());
 
//            exit(0);
            ABIIT.second->setModelNeedsLoaded(false);
            logMsg(func +" blaa!");
            ABIIT.second->setModelLoaded(true);
            logMsg(func +" blii!");
            ABIIT.second->setupPhysicsObject();
///            logMsg(func +" bluu!");
///            setActiveBasketballInstance(activeBasketballInstance);
///            logMsg(func +" Basketball Model Loaded!");

            returnType = true;

        }
        else
        {
            logMsg("Failed to load the basketball model!");
        }
 */       
    }
    logMsg(func +" alive?");
//    setActiveBasketballInstance(activeBasketballInstance);
    logMsg(func +" still alive?");
//    setActiveBasketballInstancesCreated(activeBasketballInstancesCreated);
//    exit(0);
    logMsg(func + " end");
    return (activeBasketballInstance);
}



