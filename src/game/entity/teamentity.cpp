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

#include "entity/teamentity.h"
#include "components/teamcomponents.h"
#include "data/teamdata.h"
#include "data/teamgamedata.h"
#include "flags/teamflags.h"
#include "statistics/teamstatistics.h"
#include "state/offensestate.h"
#include "state/defensestate.h"

#include "utilities/logging.h"

teamEntity::teamEntity()
{
    initialized = false;
}
teamEntity::~teamEntity()
{
}

bool teamEntity::getInitialized()  // retrieves the value of initialized
{
    return (initialized);
}
void teamEntity::setInitialized(bool set) // sets the value of initialized
{
    initialized = set;
}

teamComponentsSharedPtr teamEntity::getComponent()  // retrieves the value of component
{
    return (component);
}
void teamEntity::setComponent(teamComponentsSharedPtr set)  // sets the value of component
{
    component = set;
}

teamDataSharedPtr teamEntity::getData()  // retrieves the value of data
{
    return (data);
}
void teamEntity::setData(teamDataSharedPtr set)  // sets the value of data
{
    data = set;
}

teamFlagsSharedPtr teamEntity::getFlag()  // retrieves the value of flag
{
    return (flag);
}
void teamEntity::setFlag(teamFlagsSharedPtr set)  // sets the value of flag
{
    flag = set;
}

teamGameDataSharedPtr teamEntity::getGameData()  // retrieves the value of gameData
{
    return (gameData);
}
void teamEntity::setGameData(teamGameDataSharedPtr set)  // sets the value of gameData
{
    gameData = set;
}

teamStatisticsSharedPtr teamEntity::getStatistics()  // retrieves the value of statistics
{
    return (statistics);
}
void teamEntity::setStatistics(teamStatisticsSharedPtr set)  // sets the value of statistics
{
    statistics = set;
}

bool teamEntity::initialize()  // initializes the object
{
    std::string func = "teamEntity::setupState()";

    logMsg(func +" begin");

    teamComponentsSharedPtr tempTeamComponent(new teamComponents);
    component = tempTeamComponent;

    teamFlagsSharedPtr tempTeamFlag(new teamFlags);
    flag = tempTeamFlag;

    teamGameDataSharedPtr tempTeamGameData(new teamGameData);
    gameData = tempTeamGameData;

    teamStatisticsSharedPtr tempTeamStats(new teamStatistics);
    statistics = tempTeamStats;

    offenseStateSharedPtr tempOffenseInst(new offenseState);
    component->setOffenseInstance(tempOffenseInst);

    defenseStateSharedPtr tempDefenseInst(new defenseState);
    component->setDefenseInstance(tempDefenseInst);

    logMsg(func +" end");

    return (true);
}
