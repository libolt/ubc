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

#include "setup/setuphoops.h"
#include "load/loadhoops.h"
#include "components/hoopcomponents.h"
#include "entity/hoopentity.h"
#include "flags/hoopflags.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

setupHoops::setupHoops() = default;  // constructor

setupHoops::~setupHoops() = default;  // destructor

hoopEntityMSharedPtr setupHoops::createHoopInstances()  // creates hoop Instances
{
    hoopEntityMSharedPtr hoopInstance;
    hoopEntitySharedPtr hInstance;
    loadHoopsSharedPtr loadHoop(new loadHoops);
    std::string func = "setupHoops::createHoopInstances()";

    logMsg(func +" begin");
    

    if(loadHoop->checkIfHoopsLoaded())
    {
        hoopInstance = loadHoop->getHInstance();
    }
//    exit(0);
/*
    hoopStateSharedPtr hInstance0(new hoopState);  // creates an instance of the hoopState class
    hoopStateSharedPtr hInstance1(new hoopState);  // creates an instance of the hoopState class

//    cInstance.setModelFileName("court.mesh");
    hInstance0->setEntityName("hoop1");
    hInstance0->setEntityModelFileName("Hoop.mesh");
    hInstance0->setEntityNodeName("hoopNode1");

    hInstance1->setEntityName("hoop2");
    hInstance1->setEntityModelFileName("Hoop.mesh");
    hInstance1->setEntityNodeName("hoopNode2");

    getHoopInstance().insert(std::pair<size_t, hoopStateSharedPtr>(0, hInstance0));  // loads the first hoop
    getHoopInstance().insert(std::pair<size_t, hoopStateSharedPtr>(1, hInstance1));  // loads the second hoop
*/
    logMsg(func +" end");

    return (hoopInstance);
}

hoopEntityMSharedPtr setupHoops::createActiveHoopInstances(hoopEntityMSharedPtr hoopInstance, size_t numActiveHoops)  // creates active hoop instances
{
    hoopEntityMSharedPtr activeHoopInstance;
    conversionSharedPtr convert ;
    loadHoopsSharedPtr loadHoop(new loadHoops);

//    hoopStateMSharedPtr hoopInstance = getHoopInstance();
//    hoopStateMSharedPtr activeHoopInstance = getActiveHoopInstance();
    std::string func = "setupHoops::createActiveHoopInstances()";
    size_t x = 0;
    logMsg(func +" begin");

    logMsg(func +" hoopInstance.size() == " +convert->toString(hoopInstance.size()));
    
    if (hoopInstance.empty())
    {
        if (loadHoop->checkIfHoopsLoaded())
        {
            logMsg(func + " abada!");
            hoopInstance = loadHoop->getHInstance();
            logMsg(func + " abadeeee!");
        }
        else
        {
            logMsg(func +" Failed to load Hoop Instances!");
            exit(0);
        }
    }
    else
    {

    }
    logMsg(func + "name 0 == " +hoopInstance[0]->getComponent()->getName());
//    logMsg(func + "name 1 == " +hoopInstance[1]->getComponent()->getName());

    
    for (x=0;x<numActiveHoops; ++x)
    {
        activeHoopInstance.insert(std::pair<size_t, hoopEntitySharedPtr>(x, hoopInstance[x]));
//        logMsg(func +" glee!");
        logMsg(func + " hoopInstance name == " +hoopInstance[x]->getComponent()->getName());
        logMsg(func + " activeHoopInstance name == " +activeHoopInstance[x]->getComponent()->getName());

    }
//    exit(0);
    x = 0;
///    for (auto AHIIT : activeHoopInstance)
///    {

///        logMsg(func +" flee!");
///        logMsg(func + " AHIIT name == " +AHIIT.second->getName());

///        AHIIT.second->setEntityID(x);
///        AHIIT.second->setEntityName("hoop" +AHIIT.second->getName());
///        ++x;
///        logMsg(func +" entityName == " +AHIIT.second->getEntityName());

///    }

//    exit(0);
//    setActiveHoopInstance(activeHoopInstance);
///    for (auto AHIIT : getActiveHoopInstance())
///    {
///        logMsg(func + " AHIIT name == " +AHIIT.second->getName());
///        logMsg(func + " AHIIT index == " +convert->toString(AHIIT.first));
///    }

//    exit(0);
    logMsg(func +" end");
    return (activeHoopInstance);
}

hoopEntityMSharedPtr setupHoops::setHoopStartPositions(hoopEntityMSharedPtr activeHoopInstance)  // sets the initial coordinates for the basketball(s)
{

//    hoopStateMSharedPtr activeHoopInstance = component->getActiveHoopInstance();
    std::string func = "setupHoops::setHoopStartPositions()";

    logMsg(func +" begin");
#ifdef __ANDROID
    activeHoopInstance[0]->getComponent()->getNode()->setPosition(45.0f,-6.5f,370.0f);
    activeHoopInstance[1]->getComponent()->getNode()->setPosition(-45.0f,-6.5f,370.0f);
#else
    activeHoopInstance[0]->getComponent()->getNode()->setPosition(45.0f,-23.5f,370.0f);
    activeHoopInstance[1]->getComponent()->getNode()->setPosition(-45.0f,-23.5f,370.0f);
#endif

    Ogre::Quaternion hoop0Rotation(Ogre::Degree(-90), Ogre::Vector3::UNIT_Y);
    activeHoopInstance[0]->getComponent()->getNode()->rotate(hoop0Rotation);

    Ogre::Quaternion hoop1Rotation(Ogre::Degree(90), Ogre::Vector3::UNIT_Y);
    activeHoopInstance[1]->getComponent()->getNode()->rotate(hoop1Rotation);

    logMsg(func +" end");
    
    return (activeHoopInstance);
    
}

