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

#include "ai/ai.h"
#include "ai/playersteerplugin.h"
#include "state/basketballstate.h"
#include "state/courtstate.h"
#include "utilities/logging.h"
#include "utilities/typedefs.h"
#include "utilities/conversion.h"
#include "state/gamestate.h"
#include "state/teamstate.h"
#include <ctime>

// static declarations

//AISystem* AISystem::pInstance = 0;
AISystemSharedPtr AISystem::pInstance;

//AISystem* AISystem::Instance()
AISystemSharedPtr AISystem::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        //pInstance = new AISystem; // create sole instance
        AISystemSharedPtr tInstance(new AISystem);
        pInstance = tInstance;
    }
    return pInstance; // returns the value of pInstance
}

AISystem::AISystem()
{
//    baseInitialized = false;
    selectedVehicle = NULL;
    oldTime = 0.0f;
//    playerSteerPluginInstance = new playerSteerPlugin;

}
AISystem::~AISystem()
{

}

gameStateSharedPtr AISystem::getGameInstance()  // retrieves the value of gameInstance
{
    return (gameInstance);
}
void AISystem::setGameInstance(gameStateSharedPtr set)  // sets the value of gameInstance
{
    gameInstance = set;
}

basketballStateMSharedPtr AISystem::getActiveBasketballInstance()  // retrieves the value of activeBasketballInstance
{
    return (activeBasketballInstance);
}
void AISystem::setActiveBasketballInstance(basketballStateMSharedPtr set)  // sets the value of activeBasketballInstance
{
    activeBasketballInstance = set;
}

courtStateMSharedPtr AISystem::getActiveCourtInstance()  // retrieves the value of activeCourtInstance
{
    return (activeCourtInstance);
}
void AISystem::setActiveCourtInstance(courtStateMSharedPtr set)  // sets the value of activeCourtInstance
{
    activeCourtInstance = set;
}

teamStateMSharedPtr AISystem::getActiveTeamInstance()  // retrieves the value of activeTeamInstance
{
    return (activeTeamInstance);
}
void AISystem::setActiveTeamInstance(teamStateMSharedPtr set)  // sets the value of activeTeamInstance
{
    activeTeamInstance = set;
}

teamTypes AISystem::getTeamWithBall()  // retrieves the value of teamWithBall
{
    return (teamWithBall);
}
void AISystem::setTeamWithBall(teamTypes set)  // sets the value of teamWithBall
{
    teamWithBall = set;
}

std::string AISystem::getHumanPlayer()  // retrieves the value of the humanPlayer
{
    return (humanPlayer);
}
void AISystem::setHumanPlayer(std::string set)  // sets the value of human player
{
    humanPlayer = set;
}

OpenSteerAbstractVehicleSharedPtr AISystem::getSelectedVehicle()  // retrieves the value of selectedVehicle
{
    return (selectedVehicle);
}
void AISystem::setSelectedVehicle(OpenSteerAbstractVehicleSharedPtr set)  // sets the value of selectedVehicle
{
    selectedVehicle = set;
}

playerSteerVecSharedPtr AISystem::getAllPlayerSteers()  // retrieves the value of allPlayerSteers
{
    return (allPlayerSteers);
}
void AISystem::setAllPlayerSteers(playerSteerVecSharedPtr set)  // sets the value of allPlayerSteers
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

void printPlugIn(OpenSteer::PlugIn& pi);

// initial setup of AI state
bool AISystem::setup(basketballStateMSharedPtr activeBasketballInstance, courtStateMSharedPtr activeCourtInstance, teamStateMSharedPtr activeTeamInstance, teamTypes teamWithBall, std::string humanPlayer)
{
    conversionSharedPtr convert = conversion::Instance();

    std::string func = "AISystem::setup()";
    setActiveTeamInstance(activeTeamInstance);
    logMsg(func +" beginning");
    playerSteerPluginSharedPtr tempPlugin(new playerSteerPlugin);
    playerSteerPluginInstance = tempPlugin;

    for (auto ATIIT : activeTeamInstance)
    {
        if (ATIIT.second->getActivePlayerInstancesCreated())
        {
            logMsg(func +" activePlayerInstances Created!");
//            exit(0);
        }
        else
        {
            logMsg(func + " activePlayerInstances NOT Created!!");
            exit(0);
        }
        logMsg(func +" team name == " +ATIIT.second->getName());
        logMsg(func +" ATIIT.second->getActivePlayerInstance().size() == " +convert->toString(ATIIT.second->getActivePlayerInstance().size()));
    }
//    exit(0);
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
    openSelectedPlugIn(activeTeamInstance);

    logMsg(func +" end");

	return true;
}


void AISystem::update(const float currentTime, const float elapsedTime) // updates AI state
{
    std::string func = "AISystem::update()";

    logMsg(func +" beginning");
	aiTimer.update();
//	updateSelectedPlugIn( currentTime, elapsedTime);
    updateSelectedPlugIn(aiTimer.getTotalSimulationTime(), aiTimer.getElapsedSimulationTime());
    logMsg(func +" end");
}

void printPlugIn(OpenSteer::PlugIn& pi)
{
//	Ogre::LogManager::getSingletonPtr()->logMessage(" " << toString(pi));
} // anonymous namespace

void AISystem::selectDefaultPlugIn()  // selects the default plugin
{
    std::string func = "AISystem::selectDefaultPlugIn()";

    logMsg(func +" beginning");
    OpenSteer::PlugIn::sortBySelectionOrder();
    logMsg(func +" alive?");
    selectedPlugIn = OpenSteerPluginSharedPtr(OpenSteer::PlugIn::findDefault());
    logMsg(func +" end");
}

void AISystem::selectNextPlugIn(teamStateMSharedPtr activeTeamInstance)  // select the "next" plug-in, cycling through "plug-in selection order"
{
    std::string func = "AISystem::selectNextPlugIn()";

    logMsg(func +" beginning");
    closeSelectedPlugIn();
    selectedPlugIn = OpenSteerPluginSharedPtr(selectedPlugIn->next());
    openSelectedPlugIn(activeTeamInstance);
    logMsg(func +" end");
}

const char *AISystem::nameOfSelectedPlugIn()  // return name of currently selected plug-in
{
    std::string func = "AISystem::nameOfSelectedPlugIn()";

    logMsg(func +" beginning");
    logMsg(func +" end");
    return (OpenSteerPluginSharedPtr(selectedPlugIn) ? OpenSteerPluginSharedPtr(selectedPlugIn)->name() : "no PlugIn");
}

void AISystem::openSelectedPlugIn(teamStateMSharedPtr activeTeamInstance)  // open the currently selected plug-in
{
    std::string func = "AISystem::openSelectedPlugIn()";

    logMsg(func +" beginning");
//    camera.reset ();
    selectedVehicle = NULL;
/*    if (!selectedPlugIn->getBaseInitialized())
    {
        logMsg(func + " selectedPlugIn base not initialized!");
        exit(0);
    }*/
//    selectedPlugIn->setActiveTeamInstance(activeTeamInstance);
    selectedPlugIn->open();
    logMsg(func +" end");
}

void AISystem::updateSelectedPlugIn(const float currentTime, const float elapsedTime)  // do a simulation update for the currently selected plug-in
{
    std::string func = "AISystem::updateSelectedPlugIn()";

    logMsg(func +" beginning");
    // switch to Update phase
//    pushPhase (updatePhase);

    // service queued reset request, if any
//    doDelayedResetPlugInXXX ();

    // if no vehicle is selected, and some exist, select the first one
    if (selectedVehicle == NULL)
    {
        const OpenSteer::AVGroup& vehicles = allVehiclesOfSelectedPlugIn();
        if (vehicles.size() > 0)
        {
            selectedVehicle = OpenSteerAbstractVehicleSharedPtr(vehicles.front());
        }
    }

    // invoke selected PlugIn's Update method
    selectedPlugIn->update(currentTime, elapsedTime);
    logMsg(func +" end");

    // return to previous phase
//    popPhase ();
}

void AISystem::closeSelectedPlugIn()  // close the currently selected plug-in
{
    std::string func = "AISystem::closeSelectedPlugIn()";

    logMsg(func +" beginning");
    selectedPlugIn->close();
    selectedVehicle = NULL;
    logMsg(func +" end");
}

void AISystem::resetSelectedPlugIn()  // reset the currently selected plug-in
{
    std::string func = "AISystem::resetSelectedPlugIn()";

    logMsg(func +" beginning");
    selectedPlugIn->reset();
    logMsg(func +" end");
}

const OpenSteer::AVGroup& AISystem::allVehiclesOfSelectedPlugIn()  // return a group (an STL vector of AbstractVehicle pointers) of all
{                                                                       // vehicles(/agents/characters) defined by the currently selected PlugIn
    std::string func = "AISystem::allVehiclesOfSelectedPlugIn()";

    logMsg(func +" beginning");
    logMsg(func +" end");
    return selectedPlugIn->allVehicles();
}

void AISystem::selectNextVehicle()  // select the "next" vehicle: the one listed after the currently selected one
{                                        // in allVehiclesOfSelectedPlugIn
    std::string func = "AISystem::selectNextVehicle()";

    logMsg(func +" beginning");
    if (selectedVehicle != NULL)
    {
        // get a container of all vehicles
        const OpenSteer::AVGroup& all = allVehiclesOfSelectedPlugIn ();
        const OpenSteer::AVIterator first = all.begin();
        const OpenSteer::AVIterator last = all.end();

        // find selected vehicle in container
        const OpenSteer::AVIterator s = std::find(first, last, selectedVehicle.get());

        // normally select the next vehicle in container
        selectedVehicle = OpenSteerAbstractVehicleSharedPtr(*(s+1));

        // if we are at the end of the container, select the first vehicle
        if (s == last-1)
        {
            selectedVehicle = OpenSteerAbstractVehicleSharedPtr(*first);
        }
        // if the search failed, use NULL
        if (s == last)
        {
            selectedVehicle = NULL;
        }
    }
    logMsg(func +" end");
}
