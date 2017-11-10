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

#include "gamesetup/gamesetupcourts.h"
#include "state/courtstate.h"
#include "load/loadcourts.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

gameSetupCourts::gameSetupCourts()  // constructor
{
    
}
gameSetupCourts::~gameSetupCourts()  // destructor
{
    
}

courtStateMSharedPtr gameSetupCourts::createCourtInstances()  // creates court Instances
{
    courtStateMSharedPtr courtInstance;
    loadCourtsSharedPtr loadCourt;
    std::string func = "gameSetupCourts::createCourtInstances()";

    logMsg(func +" beginning");

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
    }
    else
    {
        logMsg(func +" Court Instances Not Created!");
    }
//    exit(0);

    logMsg(func +" end");


    return (courtInstance);
}

courtStateMSharedPtr gameSetupCourts::createActiveCourtInstances(courtStateMSharedPtr courtInstance)  // creates active court instances
{
    courtStateMSharedPtr activeCourtInstance;
    conversionSharedPtr convert = conversion::Instance();
    loadCourtsSharedPtr loadCourt(new loadCourts);
//    courtStateMSharedPtr courtInstance = getCourtInstance();
//    courtStateMSharedPtr activeCourtInstance = getActiveCourtInstance();
    std::string func = "gameSetupCourts::createActiveCourtInstances()";

    logMsg(func + " beginning");

    logMsg(func +" courtInstance.size() == " +convert->toString(courtInstance.size()));
    if (courtInstance.size() == 0)
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
    activeCourtInstance.insert(std::pair<size_t, courtStateSharedPtr>(0, courtInstance[0]));
    if (!activeCourtInstance[0]->getInitialized())
    {
        if (activeCourtInstance[0]->initialize())
        {
            activeCourtInstance[0]->setInitialized(true);
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
