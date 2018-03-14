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

#include "setup/setuplineups.h"
#include "setup/setupplayers.h"
#include "utilities/conversion.h"
#include "state/teamstate.h"
#include "state/gamestate.h"
#include "components/teamcomponents.h"
#include "data/playerdata.h"
#include "data/teamgamedata.h"
#include "entity/playerentity.h"
#include "entity/teamentity.h"
#include "flags/teamflags.h"
#include "utilities/logging.h"

setupLineups::setupLineups()  // constructor
{
    
}
setupLineups::~setupLineups()  // destructor
{
    
}

std::vector<std::unordered_map <std::string, std::string> > setupLineups::createTeamStarters(teamEntityMSharedPtr activeTeamInstance)  // creates the teamStarters instance
{
    std::vector<std::unordered_map <std::string, std::string> > teamStarters;
    std::unordered_map <std::string, std::string> tempStarters;  // temporary starters object

    for (auto ATIIT : activeTeamInstance)  // loop through activeTeamInstance
    {
        teamStarters.push_back(tempStarters);  // add empty entry to teamStarters
    }

    return (teamStarters);
}

std::vector<std::unordered_map<std::string, size_t> > setupLineups::createTeamStarterID(std::vector<std::unordered_map <std::string, std::string> > teamStarters, teamEntityMSharedPtr activeTeamInstance)  // creates the object with each team's starter IDs
{
    conversionSharedPtr convert = conversion::Instance();
    std::vector<std::unordered_map<std::string, size_t> > teamStarterID;
    std::unordered_map<std::string, size_t> tempStarterID; // used for initial creatio  of teamStarterID vector
    std::vector<std::unordered_map <std::string, std::string> >::iterator TSVIT;

    std::string func = "setups::createTeamStarterID()";
    for (TSVIT = teamStarters.begin(); TSVIT != teamStarters.end(); ++TSVIT)  // loop that adds starting player IDs to teamStarterID
    {
        tempStarterID.clear();
        logMsg(func +" TSVIT");
        for (auto TSVUIT : *TSVIT)
        {
            logMsg(func +" TSVUIT.first = " +TSVUIT.first);
            for (auto ATIIT : activeTeamInstance)  // loop through activeTeamInstance
            {
                logMsg(func +" ATIIT");
//                std::unordered_map<std::string, size_t> tempStarterID;

                for (auto PIIT : ATIIT.second->getComponent()->getPlayerInstance())
                {
                    logMsg(func +" PIIT");
                    std::string playerName = PIIT.second->getData()->getFirstName() +" " +PIIT.second->getData()->getLastName();
                    if (playerName == TSVUIT.second && TSVUIT.first == "PG")
                    {
                        logMsg(func +" PG Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                        tempStarterID.insert(std::pair<std::string, size_t>("PG", PIIT.second->getData()->getID()));
                    }
                    else if (playerName == TSVUIT.second && TSVUIT.first == "SG")
                    {
                        logMsg(func +" SG Player ID == " +convert->toString(PIIT.second->getData()->getID()));

                        tempStarterID.insert(std::pair<std::string, size_t>("SG", PIIT.second->getData()->getID()));
    //                logMsg("teamStarterID[w][SG] Player ID == " +convert->toString(teamStarterID[w][SG]));

                    }
                    else if (playerName == TSVUIT.second && TSVUIT.first == "SF")
                    {
                        logMsg(func +" SF Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                        tempStarterID.insert(std::pair<std::string, size_t>("SF", PIIT.second->getData()->getID()));
                    }
                    else if (playerName == TSVUIT.second && TSVUIT.first == "PF")
                    {
                        logMsg(func +" PF Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                        tempStarterID.insert(std::pair<std::string, size_t>("PF", PIIT.second->getData()->getID()));
                    }
                    else if (playerName == TSVUIT.second && TSVUIT.first == "C")
                    {
                        logMsg(func +" C Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                        tempStarterID.insert(std::pair<std::string, size_t>("C", PIIT.second->getData()->getID()));
                    }
                }
            }
        }
        logMsg(func +" tempStarterID.size() == " +convert->toString(tempStarterID.size()));
//                exit(0);
        teamStarterID.push_back(tempStarterID);  // add entry to tesmStarterID for every activeTeamInstance
    }

    return (teamStarterID);
}

/*bool setupLineups::checkPlayerInstancesCreated(teamEntityMSharedPtr activeTeamInstance)  // checks if player instances have been created
{
    conversionSharedPtr convert = conversion::Instance();
    setupPlayersSharedPtr setupPlayer(new setupPlayers);
    std::string func = "setups::checkPlayerInstancesCreated()";

    logMsg(func +" activeTeamInstance.size() == " +convert->toString(activeTeamInstance.size()));
    for (auto ATIIT : activeTeamInstance)
    {
        logMsg("ATIIT.second->getPlayerInstancesCreated() == " +convert->toString(ATIIT.second->getPlayerInstancesCreated()));
        if (!ATIIT.second->getPlayerInstancesCreated())    // checks if playerInstances have been created
        {
            logMsg(func +" activeTeamInstance " +convert->toString(ATIIT.first) +" Player Instances NOT Created!");
//            exit(0);
//            if( ATIIT.second->createPlayerInstances())
            playerEntityMSharedPtr gamePlayerInstance = ATIIT.second->getBase()->getGameS()->getPlayerInstance();
            playerEntityMSharedPtr playerInstance = setupPlayer->createTeamPlayerInstances(gamePlayerInstance, ATIIT.second->getID());
            if (playerInstance.size() > 0)
            {
                ATIIT.second->setPlayerInstancesCreated(true);
                ATIIT.second->setPlayerInstance(playerInstance);
//                base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                logMsg("activeTeamInstance " +convert->toString(ATIIT.first) + " Player Instances Created Successfully!");
            }
            else
            {
                logMsg("activeTeamInstance " +convert->toString(ATIIT.first) + " Player Instances NOT CREATED!");
                exit(0);
            }
///            base->getGameS()->getActiveTeamInstance()[0]->setBase(base);
///            if (base->getGameS()->getActiveTeamInstance()[0]->createPlayerInstances()) // creates the player instances based on playerIDS
///            {
///                logMsg(func +" Team 0 Player instances created!");
///                base->getGameS()->getActiveTeamInstance()[0]->setPlayerInstancesCreated(true);
    //          exit(0);
///            }

        }
    }
    return (true);
}*/

/*teamEntityMSharedPtr setupLineups::createActivePlayerInstances(teamEntityMSharedPtr activeTeamInstance, std::vector<std::unordered_map<std::string, size_t> > teamStarterID)  // creates the active playerInstances
{
    conversionSharedPtr convert = conversion::Instance();
    std::string func = "setups::createActivePlayerInstances()";

//    exit(0);

    for (auto ATIIT : activeTeamInstance)
    {
        logMsg(func +" ATIIT.first == " +convert->toString(ATIIT.first));
        logMsg(func +" Team == " +ATIIT.second->getCity() + " " +ATIIT.second->getName());
//        activePlayerInstance.clear();
        playerEntityMSharedPtr activePlayerInstance;
        
        for (auto PIIT : ATIIT.second->getPlayerInstance())
        {
            logMsg(func +" ATIIT.first == " +convert->toString(ATIIT.first) +" PIIT.second->getData()->getID() == " +convert->toString(PIIT.second->getData()->getID()) +" primaryPosition == " +convert->toString(PIIT.second->getData()->getPrimaryPosition()));
            std::string teamStarterIDPG = convert->toString(teamStarterID[0]["PG"]);
            logMsg(func +" teamStarterID[ATIIT.first][PG] == " +teamStarterIDPG);
            logMsg(func +" playerInstance ID == " +convert->toString(PIIT.second->getData()->getID()));
            
            if (PIIT.second->getData()->getID() == teamStarterID[ATIIT.first]["PG"])
            {
                logMsg(func +" PG");
                activePlayerInstance.insert(std::pair<playerPositions, playerEntitySharedPtr>(PG, PIIT.second));
                activePlayerInstance[PG]->setActivePosition(PG);
                logMsg(func +" WOOT PG!");
            }
            else if (PIIT.second->getData()->getID() == teamStarterID[ATIIT.first]["SG"])
            {
                activePlayerInstance.insert(std::pair<playerPositions, playerEntitySharedPtr>(SG, PIIT.second));
                activePlayerInstance[SG]->setActivePosition(SG);
                logMsg(func +" WOOT SG!");
            }
            else if (PIIT.second->getData()->getID() == teamStarterID[ATIIT.first]["SF"])
            {
                activePlayerInstance.insert(std::pair<playerPositions, playerEntitySharedPtr>(SF, PIIT.second));
                activePlayerInstance[SF]->setActivePosition(SF);
                logMsg(func +" WOOT SF!");
            }
            else if (PIIT.second->getData()->getID() == teamStarterID[ATIIT.first]["PF"])
            {
                activePlayerInstance.insert(std::pair<playerPositions, playerEntitySharedPtr>(PF, PIIT.second));
                activePlayerInstance[PF]->setActivePosition(PF);
                logMsg(func +" WOOT PF!");
            }
            else if (PIIT.second->getData()->getID() == teamStarterID[ATIIT.first]["C"])
            {
                activePlayerInstance.insert(std::pair<playerPositions, playerEntitySharedPtr>(C, PIIT.second));
                activePlayerInstance[C]->setActivePosition(C);
                logMsg(func +" WOOT C!");
            }
            logMsg(func +" WOOT!");
            logMsg(func +" loop activePlayerInstance.size() == " +convert->toString(activePlayerInstance.size()));

        }
//        exit(0);
        ATIIT.second->setActivePlayerInstance(activePlayerInstance);
        ATIIT.second->setActivePlayerInstancesCreated(true);
        ATIIT.second->setActivePlayerInstancesChanged(true);

//        ATIIT.second->setPlayerStartActivePositions();
        logMsg(func +" team name == " +ATIIT.second->getName());

        logMsg(func +" activePlayerInstance.size() == " +convert->toString(activePlayerInstance.size()));
    }
    return (activeTeamInstance);
}*/

bool setupLineups::checkActivePlayerInstancesCreated(teamEntityMSharedPtr activeTeamInstance)
{
    bool returnType = false;
    size_t activePlayerInstancesCreated = 0;
    for (auto ATIIT : activeTeamInstance)
    {
        if (ATIIT.second->getFlag()->getActivePlayerInstancesCreated())
        {
            ++activePlayerInstancesCreated;
        }
        else
        {

        }
    }
    if (activePlayerInstancesCreated == activeTeamInstance.size())
    {
        returnType = true;
    }
    return (returnType);
}

teamEntityMSharedPtr setupLineups::setupStartingLineups(teamEntityMSharedPtr activeTeamInstance, std::vector<std::unordered_map<std::string, size_t> > teamStarterID)  // sets starting lineups for each team
{
    setupPlayersSharedPtr setupPlayer(new setupPlayers);
    conversionSharedPtr convert = conversion::Instance();
    std::string func = "setupLineups::setupStartingLineups()";
    size_t teamIDNum = 0;
    
    for (auto ATIIT : activeTeamInstance)
    {
        logMsg(func +" ATIIT.first == " +convert->toString(ATIIT.first));
        logMsg(func +" Team == " +ATIIT.second->getData()->getCity() + " " +ATIIT.second->getData()->getName());
//        activePlayerInstance.clear();
        
        logMsg(func + " Team Type == " +convert->toString(ATIIT.second->getGameData()->getTeamType()));
        switch (ATIIT.second->getGameData()->getTeamType())
        {
            case HOMETEAM:
                teamIDNum = 0;
            break;
            case AWAYTEAM:
                teamIDNum = 1;
            break;
        }
        
        logMsg(func +" teamIDNum == " +convert->toString(teamIDNum));
        playerEntityMSharedPtr activePlayerInstance = setupPlayer->createActivePlayerInstances(ATIIT.second->getComponent()->getPlayerInstance(), teamStarterID[teamIDNum]);
        

        logMsg(func +" activePlayerInstance.size() == " +convert->toString(activePlayerInstance.size()));
//        exit(0);
        ATIIT.second->getComponent()->setActivePlayerInstance(activePlayerInstance);

        ATIIT.second->getFlag()->setActivePlayerInstancesCreated(true);
        ATIIT.second->getFlag()->setActivePlayerInstancesChanged(true);

//        ATIIT.second->setPlayerStartActivePositions();
        logMsg(func +" team name == " +ATIIT.second->getData()->getName());

        logMsg(func +" activePlayerInstance.size() == " +convert->toString(activePlayerInstance.size()));
        
    }
//    exit(0);
    
    for (auto ATIIT : activeTeamInstance)  // loop through activeTeamInstance
    {
        logMsg(func + " activePlayerInstance size() == " +convert->toString(ATIIT.second->getComponent()->getActivePlayerInstance().size()));
    }
    exit(0);
    return (activeTeamInstance);
}

bool setupLineups::setupStartingLineups_old(teamEntityMSharedPtr activeTeamInstance, std::vector<std::unordered_map<std::string, std::string> > teamStarters, std::vector<std::unordered_map<std::string, size_t> > teamStarterID)  // sets starting lineups for each team
{
    conversionSharedPtr convert = conversion::Instance();
//    std::vector<std::unordered_map <std::string, std::string> > teamStarters;
    std::unordered_map <std::string, std::string> tempStarters;
    std::unordered_map<std::string, size_t> tempStarterID; // used for initial creatio  of teamStarterID vector
    playerEntityVecMSharedPtr playerInstance;
    std::vector<std::unordered_map <std::string, std::string> >::iterator TSVIT;
    std::vector<std::unordered_map<std::string, size_t> >::iterator TSIDIT;

    std::string func = "setups::setupStartingLineups()";

/*    for (auto ATIIT : activeTeamInstance)  // loop through activeTeamInstance
    {
        teamStarters.push_back(tempStarters);  // add empty entry to teamStarters

        for (auto PIIT : activeTeamInstance[ATIIT.first]->getPlayerInstance())
        {
            logMsg(func +" team dag " +convert->toString(ATIIT.first) +" " +PIIT.second->getData()->getFirstName() +" " +PIIT.second->getData()->getLastName());
        }
        playerInstance.insert(playerInstance.begin(), activeTeamInstance[ATIIT.first]->getPlayerInstance());  // add activeTeamInstances player instance to playerInstance
    }

    for (TSVIT = teamStarters.begin(); TSVIT != teamStarters.end(); ++TSVIT)  // loop that adds starting player IDs to teamStarterID
    {
        tempStarterID.clear();
        logMsg(func +" TSVIT");
        for (auto TSVUIT : *TSVIT)
        {           
            logMsg(func +" TSVUIT.first = " +TSVUIT.first);
            for (auto ATIIT : activeTeamInstance)  // loop through activeTeamInstance
            {
                logMsg(func +" ATIIT");
//                std::unordered_map<std::string, size_t> tempStarterID;
                
                for (auto PIIT : ATIIT.second->getPlayerInstance())
                {
                    logMsg(func +" PIIT");
                    std::string playerName = PIIT.second->getData()->getFirstName() +" " +PIIT.second->getData()->getLastName();
                    if (playerName == TSVUIT.second && TSVUIT.first == "PG")
                    {
                        logMsg(func +" PG Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                        tempStarterID.insert(std::pair<std::string, size_t>("PG", PIIT.second->getData()->getID()));
                    }
                    else if (playerName == TSVUIT.second && TSVUIT.first == "SG")
                    {
                        logMsg(func +" SG Player ID == " +convert->toString(PIIT.second->getData()->getID()));

                        tempStarterID.insert(std::pair<std::string, size_t>("SG", PIIT.second->getData()->getID()));
    //                logMsg("teamStarterID[w][SG] Player ID == " +convert->toString(teamStarterID[w][SG]));

                    }
                    else if (playerName == TSVUIT.second && TSVUIT.first == "SF")
                    {
                        logMsg(func +" SF Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                        tempStarterID.insert(std::pair<std::string, size_t>("SF", PIIT.second->getData()->getID()));
                    }
                    else if (playerName == TSVUIT.second && TSVUIT.first == "PF")
                    {
                        logMsg(func +" PF Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                        tempStarterID.insert(std::pair<std::string, size_t>("PF", PIIT.second->getData()->getID()));
                    }
                    else if (playerName == TSVUIT.second && TSVUIT.first == "C")
                    {
                        logMsg(func +" C Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                        tempStarterID.insert(std::pair<std::string, size_t>("C", PIIT.second->getData()->getID()));
                    }
                }               
            }          
        }
        logMsg(func +" tempStarterID.size() == " +convert->toString(tempStarterID.size()));
//                exit(0);
        teamStarterID.push_back(tempStarterID);  // add entry to tesmStarterID for every activeTeamInstance
    }
*/
    for (TSIDIT = teamStarterID.begin(); TSIDIT != teamStarterID.end(); ++TSIDIT)
    {
        for (auto TSIDUIT : *TSIDIT)
        {
            logMsg(func +" TSIDUIT.first == " +TSIDUIT.first +" TSIDUIT.second == " +convert->toString(TSIDUIT.second));
        }
    }
    logMsg(func +" dah teamStarterID.size() == " +convert->toString(teamStarters.size()));

//    exit(0);

    for (TSVIT = teamStarters.begin(); TSVIT != teamStarters.end(); ++TSVIT)  // loop that adds starting player IDs to teamStarterID
    {
        tempStarterID.clear();
        logMsg(func +" TSVIT");
        for (auto TSVUIT : *TSVIT)
        {

            logMsg(func +" TSVUIT.first = " +TSVUIT.first);
            for (auto ATIIT : activeTeamInstance)  // loop through activeTeamInstance
            {
                logMsg(func +" ATIIT");
//                std::unordered_map<std::string, size_t> tempStarterID;

                for (auto PIIT : ATIIT.second->getComponent()->getPlayerInstance())
                {
                    logMsg(func +" PIIT");
                    std::string playerName = PIIT.second->getData()->getFirstName() +" " +PIIT.second->getData()->getLastName();
                    if (playerName == TSVUIT.second && TSVUIT.first == "PG")
                    {
                        logMsg(func +" PG Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                        tempStarterID.insert(std::pair<std::string, size_t>("PG", PIIT.second->getData()->getID()));
                    }
                    else if (playerName == TSVUIT.second && TSVUIT.first == "SG")
                    {
                        logMsg(func +" SG Player ID == " +convert->toString(PIIT.second->getData()->getID()));

                        tempStarterID.insert(std::pair<std::string, size_t>("SG", PIIT.second->getData()->getID()));
    //                logMsg("teamStarterID[w][SG] Player ID == " +convert->toString(teamStarterID[w][SG]));

                    }
                    else if (playerName == TSVUIT.second && TSVUIT.first == "SF")
                    {
                        logMsg(func +" SF Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                        tempStarterID.insert(std::pair<std::string, size_t>("SF", PIIT.second->getData()->getID()));
                    }
                    else if (playerName == TSVUIT.second && TSVUIT.first == "PF")
                    {
                        logMsg(func +" PF Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                        tempStarterID.insert(std::pair<std::string, size_t>("PF", PIIT.second->getData()->getID()));
                    }
                    else if (playerName == TSVUIT.second && TSVUIT.first == "C")
                    {
                        logMsg(func +" C Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                        tempStarterID.insert(std::pair<std::string, size_t>("C", PIIT.second->getData()->getID()));
                    }
                }

            }

        }
        logMsg(func +" tempStarterID.size() == " +convert->toString(tempStarterID.size()));
                exit(0);
        teamStarterID.push_back(tempStarterID);  // add entry to tesmStarterID for every activeTeamInstance

    }
//    std::vector<std::unordered_map<std::string, size_t> >::iterator TSIDIT;

    for (TSIDIT = teamStarterID.begin(); TSIDIT != teamStarterID.end(); ++TSIDIT)
    {
        for (auto TSIDUIT : *TSIDIT)
        {
            logMsg(func +" TSIDUIT.first == " +TSIDUIT.first +" TSIDUIT.second == " +convert->toString(TSIDUIT.second));

        }
    }
    logMsg(func +" teamStarterID.size() == " +convert->toString(teamStarterID.size()));

//    exit(0);
    return (true);
}
