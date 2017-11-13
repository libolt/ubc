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

#include "gamesetup/gamesetupplayers.h"
#include "data/playerdata.h"
#include "entity/playerentity.h"
#include "load/loadplayers.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

gameSetupPlayers::gameSetupPlayers()  // constructor
{

}
gameSetupPlayers::~gameSetupPlayers()  // destructor
{

}

playerEntityMSharedPtr gameSetupPlayers::createPlayerInstances()  // creates player Instances
{
    conversionSharedPtr convert = conversion::Instance();
    loadPlayersSharedPtr loadPlayer(new loadPlayers);
    playerEntityMSharedPtr playerInstance;
    std::string func = "gameState::createPlayerInstances()";

    logMsg(func +" beginning");

    logMsg(func +" checkIfPlayersLoaded");
    //    exit(0);
    if (loadPlayer->checkIfPlayersLoaded())
    {
        logMsg(func +" checkIfPlayersLoaded True");

        playerInstance = loadPlayer->getPInstance();
        if (playerInstance.size() > 0)
        {
            logMsg(func +" playerInstance Loaded!");
        }
        else
        {
            logMsg(func +" playerInstance NOT Loaded!");
            exit(0);
        }
    }
    else
    {
        logMsg(func +" loading of playerss failed!");
        exit(0);
    }

    for (auto PIIT : playerInstance)
    {
        logMsg(func +" Player " +PIIT.second->getData()->getFirstName() +" " +PIIT.second->getData()->getLastName() +" TeamID == " +convert->toString(PIIT.second->getData()->getTeamID()));
    }

    logMsg(func +" playerInstance.size() == " +convert->toString(playerInstance.size()));
    logMsg(func +" too");

    logMsg(func +" end");

    return (playerInstance);

}

playerEntityMSharedPtr gameSetupPlayers::createTeamPlayerInstances(playerEntityMSharedPtr gamePlayerInstance, size_t teamID)  // creates player instances for a team
{
    playerEntityMSharedPtr playerInstance;  // stores player objects that will be returned when the function completes
    conversionSharedPtr convert = conversion::Instance();
//    playerEntityMSharedPtr gamePlayerInstance;
    std::string func = "gameSetupPlayers::createTeamPlayerInstances()";

    logMsg(func +" beginning");

    if (gamePlayerInstance.size() > 0)
    {

        logMsg(func +"Game Player Instances Created!");
//        gamePlayerInstance = base->getGameS()->getPlayerInstance();
    }
    else
    {
        logMsg(func +"Game Player Instances not created!");
        exit(0);
    }
    logMsg(func + " gamePlayerInstance.size() == " +convert->toString(gamePlayerInstance.size()));
//    exit(0);
    auto i = 0;
    auto ID = 0;
    for (auto GPIIT : gamePlayerInstance)
    {
        logMsg(func +" gamePlayerInstance->getData()->getTeamID() == " +convert->toString(gamePlayerInstance[0]->getData()->getTeamID()));
        logMsg(func +" teamID == " +convert->toString(teamID));

        if (GPIIT.second->getData()->getTeamID() == teamID)  // checks if player is assigned to this team
        {

            logMsg(func + " Team " +convert->toString(teamID) + " GPI Name == " +GPIIT.second->getData()->getFirstName() +" " +GPIIT.second->getData()->getLastName());
            playerInstance.insert(std::pair<size_t, playerEntitySharedPtr>(GPIIT.first, GPIIT.second));    // adds pInstance to the playerInstance std::vector.
//            logMsg(func +"Team ID == " +convert->toString(getID()) +" playerInstance[" +convert->toString(it.first) +"]->getFirstName() == " +playerInstance[it.first]->getFirstName());
            ++ID;
        }
//        ++i;
    }
    for (auto PIIT : playerInstance)
    {
        logMsg(func +"Team ID == " +convert->toString(teamID) +" playerInstance[" +convert->toString(PIIT.first) +"]->getData()->getFirstName() == " +PIIT.second->getData()->getFirstName());

    }
    exit(0);
///    if (getID() == 1)
///    {
///        logMsg(func +"playerInstance.size() == " +convert->toString(playerInstance.size()));
///        logMsg(func +" ID Count == " +convert->toString(ID));
//        exit(0);
///    }

    logMsg(func +" end");

    return (playerInstance);
}

playerEntityMSharedPtr gameSetupPlayers::createActivePlayerInstances(playerEntityMSharedPtr playerInstance)  // creates active court instances
{

}

