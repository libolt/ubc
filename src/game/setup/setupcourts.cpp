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

#include "setup/setupcourts.h"
#include "data/courtdata.h"
#include "components/courtcomponents.h"
#include "entity/courtentity.h"
#include "flags/courtflags.h"
//#include "state/courtstate.h"
#include "load/loadcourts.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

setupCourts::setupCourts() = default;  // constructor

setupCourts::~setupCourts() = default;  // destructor

courtEntityMSharedPtr setupCourts::createCourtInstances()  // creates court Instances
{
    courtEntityMSharedPtr courtInstance;
    loadCourtsSharedPtr loadCourt(new loadCourts);
    std::string func = "setupCourts::createCourtInstances()";

    logMsg(func +" begin");

//    exit(0);
//    courtState cInstance;  // creates an instance of the courtState class
//    cInstance.setModelFileName("court.mesh");
//    cInstance.setModelFileName("Court.mesh");
//    exit(0);
    if (loadCourt->checkIfCourtsLoaded())
    {
 //       exit(0);
//        setCourtInstance(loadCourt->getCInstance());
        logMsg(func +" Court Instances Created!!");
        courtInstance = loadCourt->getCInstance();
        size_t courtNum = 0;

        for (auto CIIT : courtInstance)
        {
            logMsg("Court Name == " +CIIT.second->getData()->getName());
            CIIT.second->getComponent()->setName(CIIT.second->getData()->getName());
            CIIT.second->getComponent()->setModelFileName(CIIT.second->getData()->getModelFileName());
            CIIT.second->getComponent()->setNumber(courtNum);


            courtNum++;
        }
//        exit(0);
    }
    else
    {
        logMsg(func +" Court Instances Not Created!");
    }
//    exit(0);

    logMsg(func +" end");


    return (courtInstance);
}

courtEntityMSharedPtr setupCourts::createActiveCourtInstances(courtEntityMSharedPtr courtInstance)  // creates active court instances
{
    courtEntityMSharedPtr activeCourtInstance;
    conversionSharedPtr convert ;
    loadCourtsSharedPtr loadCourt(new loadCourts);
//    courtStateMSharedPtr courtInstance = getCourtInstance();
//    courtStateMSharedPtr activeCourtInstance = getActiveCourtInstance();
    std::string func = "setupCourts::createActiveCourtInstances()";

    logMsg(func + " beginning");

    logMsg(func +" courtInstance.size() == " +convert->toString(courtInstance.size()));
    if (courtInstance.empty())
    {
        if (loadCourt->checkIfCourtsLoaded())
        {
            courtInstance = loadCourt->getCInstance();
        }
        else
        {
            logMsg(func +" Failed to load Court Instances!");
            exit(0);
        }
    }
    else
    {

    }

    logMsg(func +" courtInstance.size() == " +convert->toString(courtInstance.size()));
    //FIXME! should not be hard coded
    activeCourtInstance.insert(std::pair<size_t, courtEntitySharedPtr>(0, courtInstance[0]));
    if (!activeCourtInstance[0]->getFlag()->getInitialized())
    {
        if (activeCourtInstance[0]->initializeStateMachine())
        {
            activeCourtInstance[0]->getFlag()->setInitialized(true);
        }
        else
        {
            logMsg(func +" Unable to initialize activeCourtInstance!");
            exit(0);
        }
    }
//    setCourtInstance(courtInstance);
//    setActiveCourtInstance(activeCourtInstance);
//    logMsg(func +" courtInstance.size() == " +convert->toString(courtInstance().size()));
    logMsg(func +" end");
    return (activeCourtInstance);
}

courtEntityMSharedPtr setupCourts::setCourtStartPositions(courtEntityMSharedPtr courtInstance)  // sets the initial coordinates for the basketball(s)
{

//    courtStateMSharedPtr courtInstance = component->getCourtInstance();
    std::string func = "setupCourts::setCourtStartPositions()";

    logMsg(func +" begin");
#ifdef __ANDROID
    courtInstance[0]->getComponent()->getNode()->setPosition(0.0f,-6.5f,360.0f);
    courtInstance[0]->getComponent()->setNodePosition(Ogre::Vector3(0.0f,-6.5f,360.0f));
    logMsg(func +" courtPosition");
//exit(0);
#else
    courtInstance[0]->getComponent()->getNode()->setPosition(0.0f,-27.5f,360.0f);
    courtInstance[0]->getComponent()->setNodePosition(Ogre::Vector3(0.0f,-27.5f,360.0f));
#endif

    return (courtInstance);
    logMsg(func +" end");
}
