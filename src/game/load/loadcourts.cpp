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
#include "load/loadcourts.h"
#include "components/courtcomponents.h"
#include "entity/courtentity.h"
#include "flags/courtflags.h"
#include "utilities/logging.h"
#include "data/courtdata.h"
//#include "state/courtstate.h"

loadCourts::loadCourts()  // constructor
{
    courtFilesLoaded = false;

}
loadCourts::~loadCourts() = default;  // destructor

stdStringVec loadCourts::getCourtFiles() const   // retrieves the value of courtFiles
{
    return (courtFiles);
}
void loadCourts::setCourtFiles(const stdStringVec &set)  // sets the value of courtFiles
{
    courtFiles = set;
}

courtEntityMSharedPtr loadCourts::getCInstance() const  // retrieves the value of cInstance
{
    return (cInstance);
}
void loadCourts::setCInstance(const courtEntityMSharedPtr &set)  // sets the value of cInstance
{
    cInstance = set;
}

bool loadCourts::getCourtFilesLoaded() const  // retrieves the value of courtFilesLoaded
{
    return (courtFilesLoaded);
}
void loadCourts::setCourtFilesLoaded(const bool &set)  // sets the value of courtFilesLoaded
{
    courtFilesLoaded = set;
}

bool loadCourts::checkIfCourtsLoaded()  // checks if courts have been loaded into cInstance
{
//    exit(0);
    bool retVal = false;
    std::string func = "loadCourts::checkIfCourtsLoaded()";

    logMsg(func +" begin");

    if (courtFilesLoaded)
    {
        logMsg(func + " courtFilesLoaded");
//        exit(0);
        if (!cInstance.empty())
        {
            logMsg(func + " Court Files Loaded!");
            retVal = true;
        }
        else
        {
            logMsg(func +" Court Files not yet Loaded!");

            courtFilesLoaded = false;
            cInstance = loadCourtFiles();
            if (!cInstance.empty())
            {
                logMsg(func +"  > 0!");

//                load->setTInstance(tInstance);
                courtFilesLoaded = true;
                retVal = true;
            }
            else
            {
                logMsg(func +" Failed to load Court Files! IF");
                exit(0);
            }
        }
    }
    else
    {
        logMsg(func + " ELSE");
//        exit(0);
        if (!cInstance.empty())
        {
            logMsg(func +" load->getCInstance().size() > 0! ELSE");
//            load->setTInstance(tInstance);
            courtFilesLoaded = true;
            retVal = true;
        }
        else
        {
            logMsg(func +" ELSE ELSE!");

            cInstance = loadCourtFiles();
            logMsg(func);
            if (!cInstance.empty())
            {
                logMsg(func +" load->getCInstance().size() > 0! ELSE ELSE");

//                load->setTInstance(tInstance);
                courtFilesLoaded = true;
                retVal = true;
            }
            else
            {
                logMsg(func +" Failed to load Court Files!");
                retVal = false;
            }
        }
    }
//    exit(0);

    logMsg(func +" end");

    return (retVal);
}

// Courts
courtEntityMSharedPtr loadCourts::loadCourtFiles()  // load court settings from XML files
{
//    exit(0);
    courtEntityMSharedPtr  courts;
    std::string courtList;
    std::string func = "loadCourts::loadCourts()";

    logMsg(func +" begin");

#ifdef __ANDROID
    courtList = "data/courts/courts.xml";
#else
    courtList = findFile("courts/courts.xml");
#endif
    logMsg(func +" courtList == " +courtList);
    courtFiles = loadCourtListFile(courtList);
//    stdStringVec playerFiles = load->getPlayerFiles();

//    stdStringVec::iterator it;
    auto it = 0;
//    for (it = courtFiles.begin(); it != courtFiles.end(); ++it)
    for (it=0;it<courtFiles.size();++it)
    {
//        logMsg("courtFile = " +*it);
#ifdef __ANDROID
        courts.insert(std::pair<size_t, courtEntitySharedPtr>(it, loadCourtFile("data/courts/" + courtFiles[it])));
#else
        courts.insert(std::pair<size_t, courtEntitySharedPtr>(it, loadCourtFile(findFile("courts/" + courtFiles[it]))));
#endif
        ++it;
    }

    logMsg(func + " end");

    return (courts);
}

stdStringVec loadCourts::loadCourtListFile(const std::string &fileName)    // loads the list of court list file
{
    conversionSharedPtr convert ;
//    renderEngineSharedPtr render = renderEngine::Instance();
    stdStringVec cFiles;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    std::string func = "loadCourts::loadCourtListFile()";

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
        cFiles.push_back(pText);
    }

    logMsg(func +" end");

//    setCourtFiles(courtFile);
//    return true;
    return (cFiles);
}

courtEntitySharedPtr loadCourts::loadCourtFile(const std::string &fileName)  // loads data from the offense play XML files
{
    conversionSharedPtr convert ;
    courtEntitySharedPtr courtInstance(new courtEntity);
//    courtState *court = new courtState;
    std::string name;
    std::string modelName;
    float length = 0;
    float width = 0;
    float boundaryLength = 0;
    float boundaryWidth = 0;
    float boundaryXPos = 0;
    float boundaryZPos = 0;
    float centerCourt = 0;
    float centerJumpRadius = 0;
    float keyLength = 0;
    float keyWidth = 0;
    float keyJumpRadius = 0;
    float threePointSideLength = 0;
    float threePointSideZPos = 0;
    float threePointArcRadius = 0;
    float baselineInboundXPos = 0;
    float baselineInboundZPos = 0;
    float sidelineInboundXPos = 0;
    float sidelineInboundZPos = 0;
    std::string fileContents;
    tinyxml2::XMLDocument doc;
    char *contents = nullptr;
    std::string func = "loadCourts::loadCourtFile()";

    logMsg(func + " beginning");


    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
    logMsg(func +" fileContents == " +fileContents);
    doc.Parse(contents);
    logMsg(func +" Contents parsed");
    if (doc.Error())
    {
/*        logMsg("Unable to parse court xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
*/
    }
    logMsg(func +" Root Element!");

    tinyxml2::XMLHandle hDoc(&doc);
    tinyxml2::XMLElement *rootElement;
    tinyxml2::XMLElement *child;
    tinyxml2::XMLHandle hRoot(nullptr);

    rootElement = hDoc.FirstChildElement().ToElement();
    // should always have a valid root but handle gracefully if it does
    if (!rootElement)
    {
        logMsg(func +" Unable to load court element");
        //exit(0);
    }
    
    child = rootElement->FirstChild()->ToElement();
    if (child)
    {
        std::string cKey = child->Value();
        if (cKey == "Name")
        {
            name = child->GetText();
//            logMsg("name = " +name);
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            modelName = child->GetText();
//            logMsg("modelName = " +modelName);
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            length = convert->toFloat(child->GetText());
//            logMsg("Length = " +convert->toString(length));
        } 
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            length = convert->toFloat(child->GetText());
//            logMsg("Width = " +convert->toString(width));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            boundaryLength = convert->toFloat(child->GetText());
//            logMsg("Boundary Length = " +convert->toString(boundaryLength));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            boundaryWidth = convert->toFloat(child->GetText());
//            logMsg("Boundary Width = " +convert->toString(boundaryWidth));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            boundaryXPos = convert->toFloat(child->GetText());
//            logMsg("Boundary X Pos = " +convert->toString(boundaryXPos));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            boundaryZPos = convert->toFloat(child->GetText());
//            logMsg("Boundary Z Pos = " +convert->toString(boundaryZPos));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            centerCourt = convert->toFloat(child->GetText());
//            logMsg("Center Court = " +convert->toString(centerCourt));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            centerJumpRadius = convert->toFloat(child->GetText());
//            logMsg("Center Jump Radius = " +convert->toString(centerJumpRadius));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            keyLength = convert->toFloat(child->GetText());
//            logMsg("Key Length = " +convert->toString(keyLength));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            keyWidth = convert->toFloat(child->GetText());
//            logMsg("Key Width = " +convert->toString(keyWidth));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            keyJumpRadius = convert->toFloat(child->GetText());
//            logMsg("Key Jump RAdius = " +convert->toString(keyJumpRadius));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            threePointSideLength = convert->toFloat(child->GetText());
//            logMsg("Three Point Side Length = " +convert->toString(threePointSideLength));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            threePointSideZPos = convert->toFloat(child->GetText());
//            logMsg("Three Point Side Z Pos = " +convert->toString(threePointSideZPos));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            threePointArcRadius = convert->toFloat(child->GetText());
//            logMsg("Three Point Arc Radius = " +convert->toString(threePointArcRadius));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            baselineInboundXPos = convert->toFloat(child->GetText());
//            logMsg("Baseline Inbound X Pos = " +convert->toString(baselineInboundXPos));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            baselineInboundZPos = convert->toFloat(child->GetText());
//            logMsg("Baseline Inbound Z Pos = " +convert->toString(baselineInboundZPos));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            sidelineInboundXPos = convert->toFloat(child->GetText());
//            logMsg("Sideline Inbound X Pos = " +convert->toString(sidelineInboundXPos));
        }
        child = child->NextSiblingElement()->ToElement();
        if (child)
        {
            sidelineInboundZPos = convert->toFloat(child->GetText());
//            logMsg("Sideline Inbound Z Pos = " +convert->toString(sidelineInboundZPos));
        }
    }

    Ogre::Vector2 boundary = Ogre::Vector2(length,width);
    Ogre::Vector2 boundaryPos = Ogre::Vector2(boundaryXPos,boundaryZPos);
    Ogre::Vector2 keyDimensions = Ogre::Vector2(keyLength,keyWidth);
    Ogre::Vector2 baselineInboundPos = Ogre::Vector2(baselineInboundXPos,baselineInboundZPos);
    Ogre::Vector2 sidelineInboundPos = Ogre::Vector2(sidelineInboundXPos,sidelineInboundZPos);

    courtFlagsSharedPtr tempFlag(new courtFlags);
    courtInstance->setFlag(tempFlag);
    
    if (!courtInstance->getFlag()->getInitialized())
    {
        logMsg(func +" Initalizing courtInstance!");
        if (courtInstance->initializeStateMachine())
        {
            logMsg(func +" Court Initialized!");
            courtInstance->getFlag()->setInitialized(true);
        }
        else
        {
            logMsg(func +" Unable to initialize Court Instance!");
            exit(0);
        }
    }
    else
    {
        logMsg(func +" courtInstance already Initialized!");
    }
    
    courtInstance->getFlag()->setDataInitialized(true);  
    
    courtInstance->getData()->setName(name);
    
//    logMsg(func +" dah");
    courtInstance->getData()->setModelFileName(modelName);
    courtInstance->getData()->setBoundary(boundary);
    courtInstance->getData()->setBoundaryPos(boundaryPos);
    courtInstance->getData()->setCenterCourt(centerCourt);
    courtInstance->getData()->setCenterJumpRadius(centerJumpRadius);
    courtInstance->getData()->setKeyDimensions(keyDimensions);
    courtInstance->getData()->setKeyJumpRadius(keyJumpRadius);
    courtInstance->getData()->setThreePointSideLength(threePointSideLength);
    courtInstance->getData()->setThreePointZPos(threePointSideZPos);
    courtInstance->getData()->setThreePointArcRadius(threePointArcRadius);
    courtInstance->getData()->setBaselineInboundPos(baselineInboundPos);
    courtInstance->getData()->setSidelineInboundPos(sidelineInboundPos);
//    exit(0);
    logMsg(func +" end");
//    courtInstance = courtStateSharedPtr(court);
    return (courtInstance);
}

void loadCourts::loadModel(courtComponentsSharedPtr &component, courtDataSharedPtr &data, courtFlagsSharedPtr &flag, const renderEngineSharedPtr &render)  // loads selected court model
{
    conversionSharedPtr convert ;
    loaderSharedPtr load(new loader);
//    courtStateMSharedPtr courtInstance = getCourtInstance();
//    courtStateMSharedPtr activeCourtInstance = getActiveCourtInstance();
//    setupCourtsSharedPtr setupCourt(new setupCourts);
//    bool activeCourtInstancesCreated = getActiveCourtInstancesCreated();
//    bool returnType = false;
    Ogre::v1::Entity *model;  // stores the model returned by loadModel() function
    std::string func = "loadCourts::loadModels()";

    logMsg(func +" begin");
    
//    logMsg(func +" activeCourtInstance.size() == " +convert->toString(activeCourtInstance.size()));

//    for (auto ACIIT : activeCourtInstance)
//    {
//        logMsg(func +" activeCourtInstance == " +convert->toString(ACIIT.first));

/*        ACIIT.second->getFlag()->setStateChanged(true);
        ACIIT.second->setAction(CLOADMODEL);
        exit(0);
*/
        //FIXME! This should be done in a cleaner way!
        component->setModelFileName(data->getModelFileName());

        if (component->getName().empty())  // checks if entityName has been set
        {
            std::string name = data->getName();
            component->setName(name);
        }
        logMsg(func +" entityName == " +component->getName());
//        exit(0);
        if (component->getNodeName().empty())  // checks if entityNodeName has been set
        {
            std::string nodeName = data->getName() +"node";
            component->setNodeName(nodeName);
        }
        logMsg(func +" court name == " +data->getName());
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
//    }
/*    if (!activeCourtInstancesCreated && activeCourtInstance.size() == 0)
    {
        activeCourtInstance = setupCourt->createActiveCourtInstances(courtInstance);
        if (activeCourtInstance.size() > 0)
        {
            logMsg(func +" Active Court Instances Created!");
            activeCourtInstancesCreated = true;
            setActiveCourtInstance(activeCourtInstance);
        }
        else
        {
            logMsg(func +" Unable to create Active Court Instances!");
            exit(0);
        }
    }
    else
    {

    }
*/
/*    logMsg(func +" courtInstance.size() == " +convert->toString(courtInstance.size()));
    logMsg(func + " activeCourtInstance.size() == " +convert->toString(activeCourtInstance.size()));
    logMsg(func +" Model Name = " +activeCourtInstance[0]->getData()->getModelFileName());
    logMsg(func +" entity initialized == " +convert->toString(activeCourtInstance[0]->getEntity()->getInitialized()));
    activeCourtInstance[0]->getEntity()->setEntityModelFileName(activeCourtInstance[0]->getData()->getModelFileName());
    logMsg(func +" Model Name = " +activeCourtInstance[0]->getEntity()->getEntityModelFileName());
//    exit(0);
    activeCourtInstance[0]->getEntity()->setEntityNodeName(activeCourtInstance[0]->getData()->getModelFileName());
    activeCourtInstance[0]->getEntity()->setEntityName(activeCourtInstance[0]->getData()->getModelFileName());
*/

/*    if (activeCourtInstance[0]->getEntity()->loadModel())
    {
        activeCourtInstance[0]->getEntity()->getNode()->setScale(1.0f,1.0f,1.0f);
        setActiveCourtInstance(activeCourtInstance);
        returnType = true;
    }
    else
    {
        logMsg(func +" Court model not loaded!");
    }
*/
    // sets up the physics object for the court instance
//    activeCourtInstance[0]->getEntity()->setupPhysicsObject();
    
//    setActiveCourtInstancesCreated(activeCourtInstancesCreated);

    logMsg(func +" end");
//    exit(0);
}

