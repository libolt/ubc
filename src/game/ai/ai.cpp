/***************************************************************************
 *   Copyright (C) 1999 - 2016 by Mike McLean                              *
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

#include "ai/ai.h"
#include "ai/playersteerplugin.h"
#include "state/basketballstate.h"
#include "state/courtstate.h"
#include "logging.h"
#include <ctime>

//AISystem* AISystem::pInstance = 0;
boost::shared_ptr<AISystem> AISystem::pInstance;

//AISystem* AISystem::Instance()
boost::shared_ptr<AISystem> AISystem::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        //pInstance = new AISystem; // create sole instance
        boost::shared_ptr<AISystem> tInstance(new AISystem);
        pInstance = tInstance;
    }
    return pInstance; // returns the value of pInstance
}

AISystem::AISystem()
{
    selectedVehicle = NULL;
    oldTime = 0.0f;
//    playerSteerPluginInstance = new playerSteerPlugin;

}
AISystem::~AISystem()
{

}

OpenSteer::AbstractVehicle* AISystem::getSelectedVehicle()  // retrieves the value of selectedVehicle
{
    return (selectedVehicle);
}
void AISystem::setSelectedVehicle(OpenSteer::AbstractVehicle* set)  // sets the value of selectedVehicle
{
    selectedVehicle = set;
}

std::vector<playerSteer*> AISystem::getAllPlayerSteers()  // retrieves the value of allPlayerSteers
{
    return (allPlayerSteers);
}
void AISystem::setAllPlayerSteers(std::vector<playerSteer*> set)  // sets the value of allPlayerSteers
{
    allPlayerSteers = set;
}

float AISystem::getOldTime()  // returns the value of oldTime
{
    return oldTime;
}
void AISystem::setOldTime(float set)  // sets the value of oldTime
{
    oldTime = set;
}

void printPlugIn (OpenSteer::PlugIn& pi);

// initial setup of AI state
bool AISystem::setup(void)
{
    playerSteerPlugin* tempPlugin = new playerSteerPlugin;
    playerSteerPluginInstance = tempPlugin;

    // select the default PlugIn
    selectDefaultPlugIn ();
    {
        // XXX this block is for debugging purposes,
        // XXX should it be replaced with something permanent?

/*        std::cout << std::endl << "Known plugins:" << std::endl;   // xxx?
        OpenSteer::PlugIn::applyToAll (printPlugIn);                          // xxx?
        std::cout << std::endl;                                    // xxx?
*/
        // identify default PlugIn
//        if (!selectedPlugIn) errorExit ("no default PlugIn");
/*        std::cout << std::endl << "Default plugin:" << std::endl;  // xxx?
        std::cout << " " << *selectedPlugIn << std::endl;          // xxx?
        std::cout << std::endl;  // xxx?
*/
//        Ogre::LogManager::getSingletonPtr()->logMessage("Default plugin: " +*selectedPlugIn);

    }

    // initialize the default PlugIn
    openSelectedPlugIn ();
	return true;
}


void AISystem::update(const float currentTime, const float elapsedTime) // updates AI state
{
	aiTimer.update();
//	updateSelectedPlugIn( currentTime, elapsedTime);
	updateSelectedPlugIn(aiTimer.getTotalSimulationTime (), aiTimer.getElapsedSimulationTime ());
}

void printPlugIn (OpenSteer::PlugIn& pi)
{
//	Ogre::LogManager::getSingletonPtr()->logMessage(" " << toString(pi));
} // anonymous namespace

void AISystem::selectDefaultPlugIn (void)  // selects the default plugin
{
    OpenSteer::PlugIn::sortBySelectionOrder ();
    selectedPlugIn = OpenSteer::PlugIn::findDefault();
}

void AISystem::selectNextPlugIn (void)  // select the "next" plug-in, cycling through "plug-in selection order"
{
    closeSelectedPlugIn ();
    selectedPlugIn = selectedPlugIn->next();
    openSelectedPlugIn ();
}

const char *AISystem::nameOfSelectedPlugIn (void)  // return name of currently selected plug-in
{
    return (boost::shared_ptr<OpenSteer::PlugIn>(selectedPlugIn) ? boost::shared_ptr<OpenSteer::PlugIn>(selectedPlugIn)->name() : "no PlugIn");
}

void AISystem::openSelectedPlugIn (void)  // open the currently selected plug-in
{
//    camera.reset ();
    selectedVehicle = NULL;
    selectedPlugIn->open ();
}

void AISystem::updateSelectedPlugIn (const float currentTime, const float elapsedTime)  // do a simulation update for the currently selected plug-in
{
    // switch to Update phase
//    pushPhase (updatePhase);

    // service queued reset request, if any
//    doDelayedResetPlugInXXX ();

    // if no vehicle is selected, and some exist, select the first one
    if (selectedVehicle == NULL)
    {
        const OpenSteer::AVGroup& vehicles = allVehiclesOfSelectedPlugIn();
        if (vehicles.size() > 0) selectedVehicle = vehicles.front();
    }

    // invoke selected PlugIn's Update method
    selectedPlugIn->update (currentTime, elapsedTime);

    // return to previous phase
//    popPhase ();
}

void AISystem::closeSelectedPlugIn (void)  // close the currently selected plug-in
{
    selectedPlugIn->close ();
    selectedVehicle = NULL;
}

void AISystem::resetSelectedPlugIn (void)  // reset the currently selected plug-in
{
    selectedPlugIn->reset ();
}



const OpenSteer::AVGroup& AISystem::allVehiclesOfSelectedPlugIn (void)  // return a group (an STL vector of AbstractVehicle pointers) of all
{                                                                       // vehicles(/agents/characters) defined by the currently selected PlugIn
    return selectedPlugIn->allVehicles ();
}



void AISystem::selectNextVehicle (void)  // select the "next" vehicle: the one listed after the currently selected one
{                                        // in allVehiclesOfSelectedPlugIn
    if (selectedVehicle != NULL)
    {
        // get a container of all vehicles
        const OpenSteer::AVGroup& all = allVehiclesOfSelectedPlugIn ();
        const OpenSteer::AVIterator first = all.begin();
        const OpenSteer::AVIterator last = all.end();

        // find selected vehicle in container
        const OpenSteer::AVIterator s = std::find (first, last, selectedVehicle);

        // normally select the next vehicle in container
        selectedVehicle = *(s+1);

        // if we are at the end of the container, select the first vehicle
        if (s == last-1) selectedVehicle = *first;

        // if the search failed, use NULL
        if (s == last) selectedVehicle = NULL;
    }
}
