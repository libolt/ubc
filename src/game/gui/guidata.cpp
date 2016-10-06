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

#include "engine/networkengine.h"

#include "gui/gui.h"
#include "conversion.h"
#include "data/courtdata.h"
#include "engine/gameengine.h"
#include "state/courtstate.h"
#include "state/gamestate.h"
#include "state/playerstate.h"
#include "state/teamstate.h"
#include "load.h"
#include "logging.h"
#include "engine/renderengine.h"
#include "data/teamdata.h"

#ifdef __ANDROID__
#include "android-config.h"
#else
#include "config.h"
#endif

bool GUISystem::addCourtSelectionMenuData()  // adds data to Player Start Selection Menu widgets
{
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    
    courtStateVecSharedPtr courtInstance;
    stdStringVec courtName;
//    if (!gameS->getCourtInstancesCreated())
    if (base->getStateSetup())
    {
        logMsg("WOOT Base STATE SETUP!");
    }
    else
    {
        logMsg("Base NOT STATE SETUP!!!");
        exit(0);
    }
    base->setup();
//    exit(0);
    if (base->getGameS()->getCourtInstancesCreated())
    {
//        exit(0);

        courtInstance = base->getGameS()->getCourtInstance();
//        exit(0);
        base->getGameS()->setCourtInstancesNeedCreated(true);
//        exit(0);

    }
    else
    {
//        exit(0);
        if (base->getGameS()->createCourtInstances())
        {
//            exit(0);
            courtInstance = base->getGameS()->getCourtInstance();
            base->getGameS()->setCourtInstancesCreated(true);
        }
        else
        {
            logMsg("Court Instances NOT Created!");
        }
    }
//    exit(0);
//    courtInstance = gameS->getCourtInstance();

    for (size_t x=0;x<courtInstance.size();++x)
    {
        courtName.push_back(courtInstance[x]->getName());
    }
    if (courtInstance.size() == 0)
    {
        logMsg("courtInstane.size == " +convert->toString(courtInstance.size()));
//        exit(0);
    }
    
    logMsg("courtName = " +courtName[0]);
    logMsg("courtName size = " +convert->toString(courtName.size()));
//    exit(0);u
    size_t i = 0;
    while (i<courtName.size())
    {
        courtSelectBox->addItem(courtName[i]);
        ++i;
    }
    logMsg("Court names added!");
//    exit(0);
    return (true);
}

void GUISystem::addPlayerStartSelectionMenuData()  // adds data to Player Start Selection Menu widgets
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<loader> load;

//    playerInstance = load->loadPlayers();
//    playerInstance = gameS->getPlayerInstance();
//    gameS->setPlayerInstances(playerInstance);
    sizeTVec teamIDs = base->getGameS()->getTeamIDS();
    teamStateVecSharedPtr teamInstance = base->getGameS()->getTeamInstance();
    std::vector<playerStateVecSharedPtr > playerInstance;
//    std::vector <boost::shared_ptr<playerState> > pInstance;
//    pInstance = teamInstance[teamIDs[0]]->getPlayerInstance();
    size_t x = 0;
    logMsg("addPlayerStartSelectionMenuData");
    logMsg("getGameS()->getTeamIDS().size() == " +convert->toString(base->getGameS()->getTeamIDS().size()));
    logMsg("getGameS()->getTeamIDS()[0] == " +convert->toString(base->getGameS()->getTeamIDS()[0]));
    
    logMsg("teamIDS[0] == " +convert->toString(teamIDs[0]));
    logMsg("blah");
//    exit(0);
    
/*
    if (!base->getGameS()->getPlayerInstanceCreated())
    {
        logMsg("GUISystem::addPlayerStartSelectionMenuData() player instances not yet created!");
        if (base->getGameS()->createPlayerInstances())
        {
            logMsg("GUISystem::addPlayerStartSelectionMenuData() player instances created!");
        }
        else
        {
            logMsg("GUISystem::addPlayerStartSelectionMenuData() player instances not created!");
        }
//        exit(0);
    }
    if (!teamInstance[teamIDs[0]]->getPlayerInstancesCreated())
    {
        teamInstance[teamIDs[0]]->createPlayerInstances();
        base->getGameS()->setTeamInstance(teamInstance);
    }
*/
    logMsg ("addPlayerStartSelectionMenuData");
 

    if (base->getGameS()->checkIfPlayerInstanceCreated())
    {
        logMsg("gameS PlayerInstance Created!");
//        exit(0);
    }
    else
    {
        logMsg("gameS PlayerInstance NOT Created!");
        exit(0);
    }
    
    
 
    if (!teamInstance[teamIDs[0]]->getPlayerInstancesCreated())
    {
        teamInstance[teamIDs[0]]->createPlayerInstances();
        base->getGameS()->setTeamInstance(teamInstance);
    }
    
    logMsg("Bleert!");
    
    exit(0);
    logMsg("teamInstance.size() == " +convert->toString(teamInstance.size()));
    
    logMsg("Team 0 player instances created ==  " +convert->toString(teamInstance[teamIDs[0]]->getPlayerInstancesCreated()));
//    exit(0);
    if (teamInstance[teamIDs[0]]->getPlayerInstancesCreated())
    {
        logMsg("Team 0 player instances created!");
    }
    else
    {
        logMsg("Creating Team 0 player instances!");
//        exit(0);
        if (teamInstance[teamIDs[0]]->createPlayerInstances())
        {
//            exit(0);
            logMsg("Team 0 player instances created successfully!");

            base->getGameS()->setTeamInstance(teamInstance);
        }
        else
        {
            logMsg("Unable to createTeam 0 player instances!");
            exit(0);
        }
    }
    exit(0);
    if (!teamInstance[teamIDs[1]]->getPlayerInstancesCreated())
    {
        teamInstance[teamIDs[1]]->createPlayerInstances();
        base->getGameS()->setTeamInstance(teamInstance);
    }
//    exit(0);
    logMsg("Team 0");
//    exit(0);
    logMsg("TeamInstance size == " +convert->toString(teamInstance.size()));

    logMsg("Team 0 playerInstance size == " +convert->toString(teamInstance[0]->getPlayerInstance().size()));
    logMsg("teamIDs[0] == " +convert->toString(teamIDs[0]));
    exit(0);
    playerInstance.push_back(teamInstance[teamIDs[0]]->getPlayerInstance());
    exit(0);
    playerInstance.push_back(teamInstance[teamIDs[1]]->getPlayerInstance());

    exit(0);
    sizeTVec overAllRatings;
    
    stdStringVec pNames;
    stdStringVec pPositions;
    sizeTVec pIDs;
    std::vector< sizeTVec > overallRatings;
    sizeTVec overall;
    exit(0);
    size_t overallRatingsSize = 0;
    size_t flag = 1;
    size_t temp = 0;
    size_t tempID = 0;
    std::string tempName;
    std::string tempPosition;

    playerNames.push_back(pNames);
    playerNames.push_back(pNames);
    
    playerPositionsPlayed.push_back(pPositions);
    playerPositionsPlayed.push_back(pPositions);

    playerIDs.push_back(pIDs);
    playerIDs.push_back(pIDs);

    overallRatings.push_back(overall);
    overallRatings.push_back(overall);

    if (!base->getGameS()->getPlayerInstanceCreated())
    {
//        base->getGameS()->createPlayerInstance();
    }
    logMsg("Player Instance Size = " +convert->toString(playerInstance.size()));
//    exit(0);
//    for (size_t i = 0;i < playerInstance.size(); ++i)
    size_t i = 0;
    while (i < playerInstance.size())
    {
        
        logMsg("Player Instance[i] Size = " +convert->toString(playerInstance[i].size()));
//        logMsg("pDTeam = " +convert->toString(playerInstance[i][0]->getTeamID()));
        logMsg("pDTeam = " +convert->toString(playerInstance[i][0]->getTeamID()));
//        logMsg("teamID == " +convert->toString(gameS->getTeamID()[1]));
        logMsg("teamID == " +convert->toString(base->getGameS()->getTeamIDS()[1]));
        exit(0);
//        if (playerInstance[i]->getTeamID() == gameS->getTeamID()[0])
       if (base->getGameS()->getPlayerInstance()[i]->getTeamID() == base->getGameS()->getTeamIDS()[0])

        {
//            size_t overallRating = playerInstance[i]->getOverallRating();
            size_t overallRating = base->getGameS()->getPlayerInstance()[i]->getOverallRating();
            std::string playerOverallRating = convert->toString(overallRating);
//            std::string playerName = playerInstance[i]->getFirstName() +" " +playerInstance[i]->getLastName() +" " +convert->toString(playerInstance[i]->getPrimaryPosition()); // +"            "; // +playerOverallRating;
            std::string playerName = base->getGameS()->getPlayerInstance()[i]->getFirstName() +" " +base->getGameS()->getPlayerInstance()[i]->getLastName() +" " +convert->toString(base->getGameS()->getPlayerInstance()[i]->getPrimaryPosition()); // +"            "; // +playerOverallRating;
//            std::string playerName = getPlayerInstance()[i]->getFirstName() +" " +getPlayerInstance()([i]->getLastName() +" " +convert->toString(getPlayerInstance()[i]->getPrimaryPosition()); // +"            "; // +playerOverallRating;
//            std::string playerPosition = convert->toString(playerInstance[i]->getPrimaryPosition());
            std::string playerPosition = convert->toString(base->getGameS()->getPlayerInstance()[i]->getPrimaryPosition());
//            size_t playerID = getPlayerInstance()[i]->getID();
            size_t playerID = base->getGameS()->getPlayerInstance()[i]->getID();

            playerNames[0].push_back(playerName);
            playerPositionsPlayed[0].push_back(playerPosition);
            playerIDs[0].push_back(playerID);
            overallRatings[0].push_back(overallRating);
        }

        if (base->getGameS()->getPlayerInstance()[i]->getTeamID() == base->getGameS()->getTeamIDS()[1])
        {
            size_t overallRating = base->getGameS()->getPlayerInstance()[i]->getOverallRating();
            std::string playerOverallRating = convert->toString(overallRating);
            std::string playerName = base->getGameS()->getPlayerInstance()[i]->getFirstName() +" " +base->getGameS()->getPlayerInstance()[i]->getLastName() +" " +convert->toString(base->getGameS()->getPlayerInstance()[i]->getPrimaryPosition()); // +"            "; // +playerOverallRating;
            bool playerNameLengthReached = false;
            std::string playerPosition = convert->toString(base->getGameS()->getPlayerInstance()[i]->getPrimaryPosition());
            size_t playerID = base->getGameS()->getPlayerInstance()[i]->getID();

            playerNames[1].push_back(playerName);
            playerPositionsPlayed[1].push_back(playerPosition);
            playerIDs[1].push_back(playerID);
            overallRatings[1].push_back(overallRating);
        }
        ++i;
    }

//    exit(0);

    overallRatingsSize = overallRatings[0].size();
    flag = 1;
    temp = 0;
    tempID = 0;
    tempName.clear();
    tempPosition.clear();
    logMsg("overallRating before = " +convert->toString(overallRatings[0][0]));
    exit(0);
    for (size_t l=0; l<overallRatingsSize && flag; ++l)
    {
        flag = 0;
        for (size_t j=0; j < (overallRatingsSize -1); ++j)
        {
            if (overallRatings[0][j+1] > overallRatings[0][j])  // ascending order simply changes to <
            {
                temp = overallRatings[0][j];  // swap elements
                tempName = playerNames[0][j];
                tempPosition = playerPositionsPlayed[0][j];
                tempID = playerIDs[0][j];

                overallRatings[0][j] = overallRatings[0][j+1];
                playerNames[0][j] = playerNames[0][j+1];
                playerPositionsPlayed[0][j] = playerPositionsPlayed[0][j+1];
                playerIDs[0][j] = playerIDs[0][j+1];

                overallRatings[0][j+1] = temp;
                playerNames[0][j+1] = tempName;
                playerPositionsPlayed[0][j+1] = tempPosition;
                playerIDs[0][j+1] = tempID;

                flag = 1;               // indicates that a swap occurred.
            }
        }

    }

    logMsg("overallRating after = " +convert->toString(overallRatings[0][0]));

    overallRatingsSize = overallRatings[1].size();
    flag = 1;
    temp = 0;
    tempID = 0;
    tempName.clear();
    tempPosition.clear();
    logMsg("overallRating before = " +convert->toString(overallRatings[1][0]));
    for (size_t l=0; l<overallRatingsSize && flag; ++l)
    {
        flag = 0;
        for (size_t j=0; j < (overallRatingsSize -1); ++j)
        {
            if (overallRatings[1][j+1] > overallRatings[1][j])  // ascending order simply changes to <
            {
                temp = overallRatings[1][j];  // swap elements
                tempName = playerNames[1][j];
                tempPosition = playerPositionsPlayed[1][j];
                tempID = playerIDs[1][j];

                overallRatings[1][j] = overallRatings[1][j+1];
                playerNames[1][j] = playerNames[1][j+1];
                playerPositionsPlayed[1][j] = playerPositionsPlayed[1][j+1];
                playerIDs[1][j] = playerIDs[1][j+1];

                overallRatings[1][j+1] = temp;
                playerNames[1][j+1] = tempName;
                playerPositionsPlayed[1][j+1] = tempPosition;
                playerIDs[1][j+1] = tempID;

                flag = 1;  // indicates that a swap occurred.
            }
        }

    }
    logMsg("overallRating after = " +convert->toString(overallRatings[1][0]));

    sizeTVec starters; // used for initial creatio  of teamStarterID vector
//    starters.push_back(1);
    for (size_t i=0;i<5;++i)
    {
        team0IDs.push_back(starters);
        team1IDs.push_back(starters);
    }

    size_t startID = 0;
    for (size_t i = 0;i < playerNames[0].size(); ++i)
    {
       bool playerNameLengthReached = false;
        while (!playerNameLengthReached)
        {
            if (playerNames[0][i].length() >= 18)
            {
                playerNameLengthReached = true;
            }
            else
            {
                playerNames[0][i] += " ";
            }
        }
        playerNames[0][i] += " " +convert->toString(overallRatings[0][i]);
        logMsg("playerNames[0][i] == " +playerNames[0][i]);

        std::string PName;
        if (playerPositionsPlayed[0][i] == "PG")
        {
            team0PGSelectBox->addItem(playerNames[0][i]);
            team0IDs[0].push_back(playerIDs[0][i]);
//            exit(0);
        }
        else if (playerPositionsPlayed[0][i] == "SG")
        {
            team0SGSelectBox->addItem(playerNames[0][i]);
            team0IDs[1].push_back(playerIDs[0][i]);
       }
        else if (playerPositionsPlayed[0][i] == "SF")
        {
            team0SFSelectBox->addItem(playerNames[0][i]);
            team0IDs[2].push_back(playerIDs[0][i]);
        }
        else if (playerPositionsPlayed[0][i] == "PF")
        {
            team0PFSelectBox->addItem(playerNames[0][i]);
            team0IDs[3].push_back(playerIDs[0][i]);
       }
        else if (playerPositionsPlayed[0][i] == "C")
        {
            team0CSelectBox->addItem(playerNames[0][i]);
            team0IDs[4].push_back(playerIDs[0][i]);
       }
        else
        {

        }
    }

    for (size_t i=0;i<playerIDs[0].size();++i)
    {
        logMsg("PlayerIDs == " +convert->toString(playerIDs[0][i]));
    }

//    exit(0);

    logMsg("PG == " +team0PGSelectBox->getItemNameAt(0));
    logMsg("PG ID == " +convert->toString(team0IDs[0][0]));
//    exit(0);
    logMsg("SG == " +team0SGSelectBox->getItemNameAt(0));
    logMsg("SG ID == " +convert->toString(team0IDs[1][0]));
    logMsg("SF == " +team0SFSelectBox->getItemNameAt(0));
    logMsg("SF ID == " +convert->toString(team0IDs[2][0]));
    logMsg("PF == " +team0PFSelectBox->getItemNameAt(0));
    logMsg("PF ID == " +convert->toString(team0IDs[3][0]));
    logMsg("C == " +team0CSelectBox->getItemNameAt(0));
    logMsg("C ID == " +convert->toString(team0IDs[4][0]));
//    exit(0);

    for (size_t i = 0;i < playerNames[1].size(); ++i)
    {
       bool playerNameLengthReached = false;
        while (!playerNameLengthReached)
        {
            if (playerNames[1][i].length() >= 18)
            {
                playerNameLengthReached = true;
            }
            else
            {
                playerNames[1][i] += " ";
            }
        }
        playerNames[1][i] += " " +convert->toString(overallRatings[1][i]);
        logMsg("playerNames[1][i] == " +playerNames[1][i]);

        std::string PName;

        if (playerPositionsPlayed[1][i] == "PG")
        {
            team1PGSelectBox->addItem(playerNames[1][i]);
            team1IDs[0].push_back(playerIDs[1][i]);
            logMsg("Adding PG1");
        }
        else if (playerPositionsPlayed[1][i] == "SG")
        {
            team1SGSelectBox->addItem(playerNames[1][i]);
            team1IDs[1].push_back(playerIDs[1][i]);
            logMsg("Adding SG1");
        }
        else if (playerPositionsPlayed[1][i] == "SF")
        {
            team1SFSelectBox->addItem(playerNames[1][i]);
            team1IDs[2].push_back(playerIDs[1][i]);
            logMsg("Adding SF1");
        }
        else if (playerPositionsPlayed[1][i] == "PF")
        {
            team1PFSelectBox->addItem(playerNames[1][i]);
            team1IDs[3].push_back(playerIDs[1][i]);
            logMsg("Adding PF1");
        }
        else if (playerPositionsPlayed[1][i] == "C")
        {
            team1CSelectBox->addItem(playerNames[1][i]);
            team1IDs[4].push_back(playerIDs[1][i]);
            logMsg("Adding C1");
        }
        else
        {

        }
    }

    logMsg("PG1 == " +team1PGSelectBox->getItemNameAt(0));
    logMsg("PG1 ID == " +convert->toString(team1IDs[0][0]));

    logMsg("SG1 == " +team1SGSelectBox->getItemNameAt(0));
    logMsg("SG1 ID == " +convert->toString(team1IDs[1][0]));

    logMsg("SF1 == " +team1SFSelectBox->getItemNameAt(0));
    logMsg("SF1 ID == " +convert->toString(team1IDs[2][0]));

    logMsg("PF1 == " +team1PFSelectBox->getItemNameAt(0));
    logMsg("PF1 ID == " +convert->toString(team1IDs[3][0]));

    logMsg("C1 == " +team1CSelectBox->getItemNameAt(0));
    logMsg("C1 ID == " +convert->toString(team1IDs[4][0]));

//    exit(0);

}

bool GUISystem::addTeamStartSelectionMenuData()  // adds data to Team Start Selection Menu
{
    boost::shared_ptr<conversion> convert = conversion::Instance();

    boost::shared_ptr<loader> load;

    teamStateVecSharedPtr teamInstance; // = gameS->getTeamDataInstance();

//    if (!base->getGameS()->getTeamInstancesCreated())
//    {
//        logMsg("Team Instances not Created!");
//        exit(0);
//    }

//    teamInstance = load->loadTeams();
//    if (teamInstance.size() > 0)
//    {
//        base->getGameS()->setTeamInstance(teamInstance);
//    }
//    else
//    {
//        logMsg("Unable to load Team data!");
//        return (false);
//    }

    if (load->checkIfTeamsLoaded())
    {
        teamInstance = load->getTInstance();
    }
    
    logMsg("GUI ADD TEAMteamInstance.size() == " +convert->toString(teamInstance.size()));
    int x = 0;
    while (x < teamInstance.size())
    {
        logMsg("GUI ADD TEAM teamInstance[" +convert->toString(x) +"]->getID() ID == " +convert->toString(teamInstance[x]->getID()));
        ++x;
    }
     logMsg("GUI ADD TEAM base->getGameS()->getTeamInstance()[3]->getID() ID == " +convert->toString(base->getGameS()->getTeamInstance()[3]->getID()));
//    exit(0);
    if (base->getGameS()->getTeamInstancesCreated())
    {        
        logMsg("Woot!");
//        exit(0);
        if (base->getGameS()->getTeamInstance().size() > 0)
        {
            teamInstance = base->getGameS()->getTeamInstance();
            logMsg("teamInstance.size() == " +convert->toString(base->getGameS()->getTeamInstance().size()));
        }
        else
        {
            logMsg("getGameS()->getTeamInstance() is EMPTY! IF");
            return (false);           
        }
//        exit(0);
    }
    else
    {    
        if (base->getGameS()->createTeamInstances())
        {
             logMsg("teamInstance.size() == " +convert->toString(base->getGameS()->getTeamInstance().size()));
            exit(0);
            if (base->getGameS()->getTeamInstance().size() > 0)
            {
                teamInstance = base->getGameS()->getTeamInstance();
                logMsg("teamInstance.size() == " +convert->toString(base->getGameS()->getTeamInstance().size()));
            }
            else
            {
                logMsg("getGameS()->getTeamInstance() is EMPTY! ELSE");
                return (false);                               
            }

        }
        else
        {
            logMsg("Failed to create teamSelectioMenuGUI");
            return (false);
        }
        
    }

    

//    gameS->setTeamDataInstance(teamDataInstance);
//
//    teamInstance = gameS->getTeamInstance();
    logMsg("teamInstance.size() == " +convert->toString(base->getGameS()->getTeamInstance().size()));
    logMsg("BLEEET!");
    if (teamInstance.size() == 0)
    {
        exit(0);
    }
    logMsg(convert->toString(teamInstance.size()));
    logMsg("Team City == a" +teamInstance[0]->getCity() +"b");
    logMsg("Team City == a" +teamInstance[0]->getCity() +"b");
    logMsg("Team City == a" +teamInstance[0]->getCity() +"b");
    logMsg("Team City == a" +teamInstance[0]->getCity() +"b");

//    exit(0);
    for (size_t x=0;x<teamInstance.size(); ++x)
    {
        if (teamInstance[x]->getCity() == "")
        {
            logMsg("City is blank!");
            exit(0);
        }
        std::string teamName = teamInstance[x]->getCity() + " " +teamInstance[x]->getName();

        team0SelectBox->addItem(teamName);
        team1SelectBox->addItem(teamName);
    }
    team0SelectBox->setIndexSelected(0);
    team1SelectBox->setIndexSelected(1);
    logMsg("End of addTeamStartSelectionMenuData!");
//    exit(0);

    return (true);
}
