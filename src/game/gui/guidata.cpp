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

#include "easylogging++.h"

#ifdef __ANDROID__
#include "android-config.h"
#else
#include "config.h"
#endif

bool GUISystem::addCourtSelectionMenuData()  // adds data to Player Start Selection Menu widgets
{
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();

    std::tr1::unordered_map <size_t, courtStateSharedPtr>  courtInstance;
    stdStringVec courtName;
//    if (!gameS->getCourtInstancesCreated())
    if (base->getStateSetup())
    {
        logMsg("WOOT Base STATE SETUP!");
    }
    else
    {
//        exit(0);
        logMsg("Base NOT STATE SETUP!!!");
        base->setup();
//        exit(0);
    }

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
    logMsg("fleeart!");
//    exit(0);

//    courtInstance = gameS->getCourtInstance();
    auto evenCount = 0;
    for (auto x=0;x<courtInstance.size();++x)
//    for_each(courtInstance.begin(), courtInstance.end(), [&evenCount] (size_t n)
    {
        courtName.push_back(courtInstance[x]->getName());
    }

//    courtInstance.courtNameFunc(getName());
    logMsg("GUISystem::addCourtSelectionMenuData() courtName.size() == " +convert->toString(courtName.size()));
    if (courtInstance.size() == 0)
    {
        logMsg("courtInstane.size == " +convert->toString(courtInstance.size()));
//        exit(0);
    }
//    exit(0);

    logMsg("courtName = " +courtName[0]);
    logMsg("courtName size = " +convert->toString(courtName.size()));
//    exit(0);u
    auto i = 0;
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
    std::tr1::unordered_map <size_t, teamStateSharedPtr> activeTeamInstance = base->getGameS()->getActiveTeamInstance();
    std::vector<std::tr1::unordered_map <size_t, playerStateSharedPtr> > playerInstance;
    std::string func = "addPlayerStartSelectionMenuData";
    sizeTVec teamIDs = base->getGameS()->getTeamIDS();

    auto x = 0;
    while (x < activeTeamInstance.size())
    {
        logMsg(func +" yabadaba");
        logMsg(convert->toString(teamIDs.size()));
        logMsg(convert->toString(activeTeamInstance[x]->getPlayerInstancesCreated()));
//        exit(0);
//        if (teamInstance[teamIDs[x]]->getPlayerInstancesCreated())
        if (activeTeamInstance[x]->getPlayerInstancesCreated())
        {
//            exit(0);
            logMsg(func +" teamInstance[teamIDs[" +convert->toString(x) +"]] playerInstances crested!");
            logMsg(func +" Team " +convert->toString(x) +" player instances created!");
        }
        else
        {
//            exit(0);
            logMsg(func +" creating team " +convert->toString(x) +" playerInstances!");
//            teamInstance[x]->setBase(base);
            if (activeTeamInstance[x]->createPlayerInstances())
            {
                activeTeamInstance[teamIDs[x]]->setPlayerInstancesCreated(true);
                base->getGameS()->setActiveTeamInstance(activeTeamInstance);
            }
            else
            {
                logMsg("Unable to create active team [" +convert->toString(x) +"] playerInstances");
                exit(0);
            }
        }
        playerInstance.push_back(activeTeamInstance[x]->getPlayerInstance());

       ++x;
    }

    auto i = 0;
    while (i < playerInstance.size())
    {
        auto j = 0;
        while (j < playerInstance[i].size())
        {
            std::string playerName = playerInstance[i][j]->getFirstName() +" " +playerInstance[i][j]->getLastName() +" " +convert->toString(playerInstance[i][i]->getPrimaryPosition()); // +"            "; // +playerOverallRating;
            exit(0);
            switch (playerInstance[i][j]->getPrimaryPosition())
            {
                case PG:
                teamPlayerPosSelectBox[i]["PG"]->addItem(playerName);
                logMsg("playerName == " +playerName);
                exit(0);
            }


//            teamPlayerPosSelectBox.insert(i,playerInstance[i].)
            ++j;
        }
        ++i;
    }
}

void GUISystem::addPlayerStartSelectionMenuData_old()  // adds data to Player Start Selection Menu widgets
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<loader> load(new loader);

//    playerInstance = load->loadPlayers();
//    playerInstance = gameS->getPlayerInstance();
//    gameS->setPlayerInstances(playerInstance);
    sizeTVec teamIDs = base->getGameS()->getTeamIDS();
    std::tr1::unordered_map <size_t, teamStateSharedPtr> teamInstance = base->getGameS()->getActiveTeamInstance();
    std::vector<std::tr1::unordered_map <size_t, playerStateSharedPtr> > playerInstance;
//    std::vector <boost::shared_ptr<playerState> > pInstance;
//    pInstance = teamInstance[teamIDs[0]]->getPlayerInstance();
    auto x = 0;
    std::string func = "addPlayerStartSelectionMenuData";
    logMsg(func);
    logMsg(func +" getGameS()->getTeamIDS().size() == " +convert->toString(base->getGameS()->getTeamIDS().size()));
    logMsg(func +" getGameS()->getTeamIDS()[0] == " +convert->toString(base->getGameS()->getTeamIDS()[0]));
    
//    logMsg("teamIDS[0] == " +convert->toString(teamIDs[0]));
    logMsg(func +" blah");
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
//    logMsg ("addPlayerStartSelectionMenuData");
 

    if (base->getGameS()->checkIfPlayerInstanceCreated())
    {
        logMsg(func +" gameS PlayerInstance Created!");
//        exit(0);
    }
    else
    {
        logMsg(func +" gameS PlayerInstance NOT Created!");
        exit(0);
    }
//    exit(0);
    logMsg(func + " teamInstance.size() = " +convert->toString(teamInstance.size()));
     LOG(INFO) << func + " teamInstance.size() = " +convert->toString(teamInstance.size());
    //FIXME! This should not be hardcoded!
    x = 0;
//    exit(0);
    while (x < 2)
    {
        logMsg(func +" yabadaba");
        LOG(INFO) << convert->toString(teamIDs.size());
        LOG(INFO) << convert->toString(teamInstance[x]->getPlayerInstancesCreated());
//        exit(0);
//        if (teamInstance[teamIDs[x]]->getPlayerInstancesCreated())
        if (teamInstance[x]->getPlayerInstancesCreated())
        {
//            exit(0);
            logMsg(func +" teamInstance[teamIDs[" +convert->toString(x) +"]] playerInstances crested!");
            logMsg(func +" Team " +convert->toString(x) +" player instances created!");
        }
        else
        {
//            exit(0);
            logMsg(func +" creating team " +convert->toString(x) +" playerInstances!");
//            teamInstance[x]->setBase(base);
            if (teamInstance[x]->createPlayerInstances())
            {
//                exit(0);
                teamInstance[teamIDs[x]]->setPlayerInstancesCreated(true);
                base->getGameS()->setTeamInstance(teamInstance);
            }
       }  
       ++x;
    }
    logMsg(func +" Bleert!");
    
//    exit(0);
    logMsg(func +" teamInstance.size() == " +convert->toString(teamInstance.size()));
/*    exit(0);
    logMsg("Team 0 player instances created ==  " +convert->toString(teamInstance[teamIDs[0]]->getPlayerInstancesCreated()));
//    exit(0);
    if (teamInstance[teamIDs[0]]->getPlayerInstancesCreated())
    {
        logMsg("Team 0 player instances created!");
//        exit(0);
    }
    else
    {
        logMsg("Creating Team 0 player instances!");
//        exit(0);
        if (teamInstance[teamIDs[0]]->createPlayerInstances())
        {
//            exit(0);
            logMsg("Team 0 player instances created successfully!");
            teamInstance[teamIDs[0]]->setPlayerInstancesCreated(true);
            base->getGameS()->setTeamInstance(teamInstance);
//            exit(0);
        }
        else
        {
            logMsg("Unable to createTeam 0 player instances!");
            exit(0);
        }
    }
*/
    logMsg(func +" Bleeamb!");
//    exit(0);
/*    if (!teamInstance[teamIDs[1]]->getPlayerInstancesCreated())
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
//    exit(0);
*/
    playerInstance.push_back(teamInstance[teamIDs[0]]->getPlayerInstance());
//    exit(0);

    playerInstance.push_back(teamInstance[teamIDs[1]]->getPlayerInstance());

//    exit(0);
    sizeTVec overAllRatings;
    
    stdStringVec pNames;
    stdStringVec pPositions;
    sizeTVec pIDs;
    std::vector< sizeTVec > overallRatings;
    sizeTVec overall;
//    exit(0);
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
        logMsg(func +" Player Instance Size = " +convert->toString(playerInstance.size()));
//        logMsg("Player Instance 0 Size = " +convert->toString(playerInstance[0].size()));
    
//    exit(0);
//    for (size_t i = 0;i < playerInstance.size(); ++i)
    auto i = 0;
    while (i < playerInstance.size())
    {
        auto j = 0;
        while (j < playerInstance[i].size())
        {
/*            logMsg("playerInstance[i][j].getFirstName() == " +playerInstance[i][j]->getFirstName());
            logMsg(func +" j === ");
            logMsg(func +" j === " +convert->toString(j));
            
        
            logMsg(func +" Player Instance[i] Size = " +convert->toString(playerInstance[i].size()));
    //        logMsg("pDTeam = " +convert->toString(playerInstance[i][0]->getTeamID()));
            logMsg(func +" pDTeam = " +convert->toString(playerInstance[i][0]->getTeamID()));
    //        logMsg("teamID == " +convert->toString(gameS->getTeamID()[1]));
            logMsg(func +" teamID == " +convert->toString(base->getGameS()->getTeamIDS()[1]));
    //        exit(0);
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
                logMsg("playerNames[0] == " +playerNames[0][playerNames[0].size() -1]);
                logMsg("playerPositionsPlayed[0].size() == " +convert->toString(playerPositionsPlayed[0].size()));

            }
*/
/*            if (base->getGameS()->getPlayerInstance()[i]->getTeamID() == base->getGameS()->getTeamIDS()[1])
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
            }*/
            ++j;
        }
        ++i;
    }
    
    exit(0);
    
    overallRatingsSize = overallRatings[0].size();
    flag = 1;
    temp = 0;
    tempID = 0;
    tempName.clear();
    tempPosition.clear();
    logMsg(func +" overallRating before = " +convert->toString(overallRatings[0][0]));
//    exit(0);
    size_t l = 0; 
    while (l<overallRatingsSize && flag)
    {
        flag = 0;
        size_t j = 0;
        while (j < (overallRatingsSize -1))
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
            ++j;
        }
        ++l;
    }

    logMsg(func +" overallRating after = " +convert->toString(overallRatings[0][0]));

    overallRatingsSize = overallRatings[1].size();
    flag = 1;
    temp = 0;
    tempID = 0;
    tempName.clear();
    tempPosition.clear();
    logMsg(func +" overallRating before = " +convert->toString(overallRatings[1][0]));
    l = 0;
    while (l<overallRatingsSize && flag)
    {
        flag = 0;
        
        size_t j = 0;
        while (j < (overallRatingsSize -1))
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
            ++j;
        }
        ++l;
    }
    logMsg(func +" overallRating after = " +convert->toString(overallRatings[1][0]));

    sizeTVec starters; // used for initial creatio  of teamStarterID vector
//    starters.push_back(1);
    i = 0;
    while (i < 5)
    {
        team0IDs.push_back(starters);
        team1IDs.push_back(starters);
        ++i;
    }

    size_t startID = 0;
    logMsg(func +" playerNames[0].size() == " +convert->toString(playerNames[0].size()));
    exit(0);
    i = 0;
    while (i < playerNames[0].size())
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
        logMsg(func +" playerNames[0][i] == " +playerNames[0][i]);

        std::string PName;
//        logMsg("playerPositionsPlayed[0].size() == " +convert->toString(playerPositionsPlayed[0].size()));
        logMsg("playerPositionsPlayed[0][i] == " +playerPositionsPlayed[0][i]);
        if (playerPositionsPlayed[0][i] == "PG")
        {
            teamPlayerPosSelectBox[0]["PG"]->addItem(playerNames[0][i]);
            team0IDs[0].push_back(playerIDs[0][i]);
            logMsg(func +"dasdah");
//            exit(0);
            logMsg(func +" PG == " +teamPlayerPosSelectBox[0]["PG"]->getItemNameAt(0));

//            exit(0);
        }
        else if (playerPositionsPlayed[0][i] == "SG")
        {
            exit(0);
            logMsg(func +" ++");
            teamPlayerPosSelectBox[0]["SG"]->addItem(playerNames[0][i]);
            team0IDs[1].push_back(playerIDs[0][i]);
       }
        else if (playerPositionsPlayed[0][i] == "SF")
        {
            teamPlayerPosSelectBox[0]["SF"]->addItem(playerNames[0][i]);
            team0IDs[2].push_back(playerIDs[0][i]);
        }
        else if (playerPositionsPlayed[0][i] == "PF")
        {
            teamPlayerPosSelectBox[0]["PF"]->addItem(playerNames[0][i]);
            team0IDs[3].push_back(playerIDs[0][i]);
       }
        else if (playerPositionsPlayed[0][i] == "C")
        {
            teamPlayerPosSelectBox[0]["C"]->addItem(playerNames[0][i]);
            team0IDs[4].push_back(playerIDs[0][i]);
       }
        else
        {

        }
        ++i;
    }
//    exit(0);
    i = 0;
    while (i<playerIDs[0].size())
    {
        logMsg(func +" PlayerIDs == " +convert->toString(playerIDs[0][i]));
        ++i;
    }

//    exit(0);

    logMsg(func +" PG == " +teamPlayerPosSelectBox[0]["PG"]->getItemNameAt(0));
    logMsg(func +" PG ID == " +convert->toString(team0IDs[0][0]));
//    exit(0);
    logMsg(func +" SG == " +teamPlayerPosSelectBox[0]["SG"]->getItemNameAt(0));
    logMsg(func +" SG ID == " +convert->toString(team0IDs[1][0]));
    exit(0);
    logMsg(func +" SF == " +teamPlayerPosSelectBox[0]["SF"]->getItemNameAt(0));
    logMsg(func +" SF ID == " +convert->toString(team0IDs[2][0]));
    logMsg(func +" PF == " +teamPlayerPosSelectBox[0]["PF"]->getItemNameAt(0));
    logMsg(func +" PF ID == " +convert->toString(team0IDs[3][0]));
    logMsg(func +" C == " +teamPlayerPosSelectBox[0]["C"]->getItemNameAt(0));
    logMsg(func +" C ID == " +convert->toString(team0IDs[4][0]));
    exit(0);
    
    i = 0;
    while (i < playerNames[1].size())
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
        logMsg(func +" playerNames[1][i] == " +playerNames[1][i]);

        std::string PName;

        if (playerPositionsPlayed[1][i] == "PG")
        {
            teamPlayerPosSelectBox[1]["PG"]->addItem(playerNames[1][i]);
            team1IDs[0].push_back(playerIDs[1][i]);
            logMsg(func +" Adding PG1");
        }
        else if (playerPositionsPlayed[1][i] == "SG")
        {
            teamPlayerPosSelectBox[1]["SG"]->addItem(playerNames[1][i]);
            team1IDs[1].push_back(playerIDs[1][i]);
            logMsg(func +" Adding SG1");
        }
        else if (playerPositionsPlayed[1][i] == "SF")
        {
            teamPlayerPosSelectBox[1]["SF"]->addItem(playerNames[1][i]);
            team1IDs[2].push_back(playerIDs[1][i]);
            logMsg(func +" Adding SF1");
        }
        else if (playerPositionsPlayed[1][i] == "PF")
        {
            teamPlayerPosSelectBox[1]["PF"]->addItem(playerNames[1][i]);
            team1IDs[3].push_back(playerIDs[1][i]);
            logMsg(func +" Adding PF1");
        }
        else if (playerPositionsPlayed[1][i] == "C")
        {
            teamPlayerPosSelectBox[2]["C"]->addItem(playerNames[1][i]);
            team1IDs[4].push_back(playerIDs[1][i]);
            logMsg(func +" Adding C1");
        }
        else
        {

        }
        ++i;
    }

    logMsg(func +" PG1 == " +teamPlayerPosSelectBox[1]["PG"]->getItemNameAt(0));
    logMsg(func +" PG1 ID == " +convert->toString(team1IDs[0][0]));

    logMsg(func +" SG1 == " +teamPlayerPosSelectBox[1]["SG"]->getItemNameAt(0));
    logMsg(func +" SG1 ID == " +convert->toString(team1IDs[1][0]));

    logMsg(func +" SF1 == " +teamPlayerPosSelectBox[1]["SF"]->getItemNameAt(0));
    logMsg(func +" SF1 ID == " +convert->toString(team1IDs[2][0]));

    logMsg(func +" PF1 == " +teamPlayerPosSelectBox[1]["PF"]->getItemNameAt(0));
    logMsg(func +" PF1 ID == " +convert->toString(team1IDs[3][0]));

    logMsg(func +" C1 == " +teamPlayerPosSelectBox[1]["C"]->getItemNameAt(0));
    logMsg(func +" C1 ID == " +convert->toString(team1IDs[4][0]));

//    exit(0);

}

bool GUISystem::addTeamStartSelectionMenuData()  // adds data to Team Start Selection Menu
{
    boost::shared_ptr<conversion> convert = conversion::Instance();

    boost::shared_ptr<loader> load(new loader);

    std::tr1::unordered_map <size_t, teamStateSharedPtr> teamInstance; // = gameS->getTeamDataInstance();

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
    base->getGameS()->setTeamInstance(teamInstance);
    logMsg("GUI ADD TEAM 0 teamInstance.size() == " +convert->toString(teamInstance.size()));
//    exit(0);
    auto x = 0;
    while (x < teamInstance.size())
    {
        logMsg("GUI ADD TEAM teamInstance[" +convert->toString(x) +"]->getID() ID == " +convert->toString(teamInstance[x]->getID()));
        ++x;
    }
     logMsg("GUI ADD TEAM base->getGameS()->getTeamInstance()[3]->getID() ID == " +convert->toString(base->getGameS()->getTeamInstance()[0]->getID()));
    if (base->getGameS()->getTeamInstancesCreated())
    {        
        logMsg("Woot!");
//        exit(0);
        if (base->getGameS()->getTeamInstance().size() > 0)
        {
            teamInstance = base->getGameS()->getTeamInstance();
            logMsg("GUI ADD TEAM 1 teamInstance.size() == " +convert->toString(base->getGameS()->getTeamInstance().size()));
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
             logMsg("GUI ADD TEAM 2 teamInstance.size() == " +convert->toString(base->getGameS()->getTeamInstance().size()));
//            exit(0);
            if (base->getGameS()->getTeamInstance().size() > 0)
            {
                teamInstance = base->getGameS()->getTeamInstance();
                logMsg("GUI ADD TEAM 3 teamInstance.size() == " +convert->toString(base->getGameS()->getTeamInstance().size()));
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
        logMsg("teamInstance is empty!");
        exit(0);
    }
    logMsg(convert->toString(teamInstance.size()));
    logMsg("Team City == a" +teamInstance[0]->getCity() +"b");
    logMsg("Team City == a" +teamInstance[1]->getCity() +"b");
    logMsg("Team City == a" +teamInstance[2]->getCity() +"b");
    logMsg("Team City == a" +teamInstance[3]->getCity() +"b");


//    exit(0);
    for (size_t x=0;x<teamInstance.size(); ++x)
    {
        if (teamInstance[x]->getCity() == "")
        {
            logMsg("City is blank!");
            exit(0);
        }
        std::string teamName = teamInstance[x]->getCity() + " " +teamInstance[x]->getName();

        teamSelectBox[0]->addItem(teamName);
        teamSelectBox[1]->addItem(teamName);
    }
    teamSelectBox[0]->setIndexSelected(0);
    teamSelectBox[1]->setIndexSelected(1);
    logMsg("End of addTeamStartSelectionMenuData!");
//    exit(0);

    return (true);
}
