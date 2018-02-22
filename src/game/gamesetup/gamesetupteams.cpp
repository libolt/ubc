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

#include "gamesetup/gamesetupteams.h"
#include "data/teamgamedata.h"
#include "entity/teamentity.h"
#include "utilities/conversion.h"
#include "state/gamestate.h"
#include "state/teamstate.h"
#include "utilities/logging.h"
#include "load/loadteams.h"

gameSetupTeams::gameSetupTeams()  // constructor
{
    
}
gameSetupTeams::~gameSetupTeams()  // destructor
{
    
}

teamEntityMSharedPtr gameSetupTeams::createTeamInstances()  // creates team Instances
{
    conversionSharedPtr convert = conversion::Instance();
    loadTeamsSharedPtr loadTeam; // = base->getLoadTeam();
    std::string func = "gameSetupTeams::createTeamInstances()";
    
    logMsg(func +" beginning");
//    exit(0);
    teamEntityMSharedPtr tInstance;
///    teamStateVecSharedPtr tInstance2;
///    teamStateSharedPtr tempInstance(new teamState);
//    teamState *tempInstance = new teamState;
///    tempInstance->setID(1);
///    tempInstance->setCity("tempCity");
///    tempInstance->setName("tempTeam");
///    tempInstance->setCoach("tempCoach|");
///    tempInstance->setTeamType(HOMETEAM);

///    tInstance2.push_back(tempInstance);

    logMsg(func +" loadTeams");
    if (loadTeam->checkIfTeamsLoaded())
    {
        logMsg(func +" loadTeam->getTInstance().size() == " +convert->toString(loadTeam->getTInstance().size()));
//        exit(0);
        tInstance = loadTeam->getTInstance();
        if (tInstance.size() > 0)
        {
            logMsg(func +" tInstance Loaded!");
//            setTeamInstance(tInstance);
        }
        else
        {
            logMsg(func +" tInstance NOT Loaded!");
        }
    }
    else
    {
        logMsg(func +" loading of teams failed!");
        exit(0);
//        return (false);
    }
    

//    exit(0);
    logMsg(func +" uno");
    

    logMsg(func +" tInstance.size() == " +convert->toString(tInstance.size()));
    logMsg(func +" too");
    
//    exit(0);
    logMsg("tInstance size == " +convert->toString(tInstance.size()));


//    logMsg("teamID.size() == " +convert->toString(getTeamIDS().size()));
//    logMsg("tInstance size = " +convert->toString(tInstance.size()));
//    logMsg("tInstance city 0 = " +tInstance[0]->getCity());

//    exit(0);
///    getTeamInstance()[0]->setID(tInstance[0]->getID());
///    teamInstance[1].setTeamID(teamID[1]);
///    exit(0);
///    teamInstance[0].setTeamType(HOMETEAM);
///    teamInstance[1].setTeamType(AWAYTEAM);
///    teamInstance[0].setHumanControlled(true);
///    teamInstance[1].setHumanControlled(false);
///    teamInstance[0].setTeamColObject(COL_TEAM1);
///    teamInstance[1].setTeamColObject(COL_TEAM2);

//    teamInstance[0].setTeamCollidesWith(COL_COURT); // | COL_BBALL | COL_TEAM2;   determines what team0 collides with);
//    teamInstance[1].setTeamCollidesWith(COL_COURT); // | COL_BBALL | COL_TEAM2;   determines what team1 collides with);
//    teamInstance[0].setupState();
//    teamInstance[1].setupState();
//    exit(0);

    if (tInstance.size() > 0)
    {
//        setTeamInstance(tInstance);
//        setTeamInstancesCreated(true);
        logMsg(func +" teamInstance CREATED!!");
//        exit(0);
    }
    else 
    {
        logMsg(func +" Failed to create Team Instances!");
        exit(0);
//        return (false);
    }

    logMsg(func +" end");
//    exit(0);
    return (tInstance);
}

teamEntityMSharedPtr gameSetupTeams::createActiveTeamInstances(teamEntityMSharedPtr teamInstance, sizeTVec teamID)  // creates active team instances
{
    conversionSharedPtr convert = conversion::Instance();
    teamEntityMSharedPtr activeTeamInstance;
    std::string func = "gameSetupTeams::createActiveTeamInstances()";
       
    logMsg(func +" begin");
//    gameStateSharedPtr gameInstance;
//    logMsg(func +" Team Instances created == " +convert->toString(gameInstance->getTeamInstancesCreated()));
    logMsg(func +" teamInstance size == " +convert->toString(teamInstance.size()));
//    logMsg(func +" gameInstance teamInstance size == " +convert->toString(gameInstance->getTeamInstance().size()));
    
//    exit(0);
    logMsg(func +" teamI");
    sizeTVec::iterator TIDIT;
    for (TIDIT = teamID.begin(); TIDIT != teamID.end(); ++TIDIT)  // creates active team instances
    {
        activeTeamInstance.insert(std::pair<size_t, teamEntitySharedPtr>(*TIDIT, teamInstance[*TIDIT]));
    }
    
    logMsg(func +" teamID.size() == " +convert->toString(teamID.size()));
    logMsg(func +" activeTeamInstance.size() == " +convert->toString(activeTeamInstance.size()));

    teamTypes teamType;
    
    for (auto ATIIT : activeTeamInstance)  // sets team type
    {
        logMsg(func +" ATIIT.first == " +convert->toString(ATIIT.first));

        if (!ATIIT.second->getInitialized())
        {
            if (ATIIT.second->initialize())
            {
                ATIIT.second->setInitialized(true);
            }
            else
            {
                logMsg(func +" Unable to initialize Active Team Instance!");
                exit(0);
            }
        }

        switch (ATIIT.first)
        {
            case 0:
                teamType = HOMETEAM;
                logMsg("HOMETEAM");
            break;
            case 1:
                logMsg("AWAYTEAM");
                teamType = AWAYTEAM;
                
            break;
        }
        ATIIT.second->getGameData()->setTeamType(teamType);
        logMsg(func +" teamType set!");
    }
//    exit(0);
    logMsg(func +" end");
    
    return (activeTeamInstance);
}
