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

//#include "easylogging++.h"

#ifdef __ANDROID__
#include "android-config.h"
#else
#include "config.h"
#endif

bool GUISystem::addCourtSelectionMenuData()  // adds data to Player Start Selection Menu widgets
{
//    sharedPtr<gameState> gameS = gameState::Instance();
    sharedPtr<conversion> convert = conversion::Instance();

    courtStateUMSharedPtr  courtInstance;
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
    sharedPtr<conversion> convert = conversion::Instance();
    teamStateUMSharedPtr activeTeamInstance = base->getGameS()->getActiveTeamInstance();
    std::vector<playerStateUMSharedPtr > playerInstance;
    std::string func = "addPlayerStartSelectionMenuData";
    sizeTVec teamIDs = base->getGameS()->getTeamIDS();

    auto x = 0;
/*    while (x < activeTeamInstance.size())
    {
        logMsg("activeTeamInstance[" +convert->toString(x) +"] ID == " +convert->toString(activeTeamInstance[x]->getID()));
        ++x;
    }
*/
//    exit(0);
    x = 0;
//    while (x < activeTeamInstance.size())
    logMsg("activeTeamInstance.size() == " +convert->toString(activeTeamInstance.size()));
//    exit(0);
    for (auto ATIIT : activeTeamInstance)
    {
        logMsg(func +" yabadaba");
        logMsg(convert->toString(teamIDs.size()));
        logMsg(convert->toString(ATIIT.second->getPlayerInstancesCreated()));
//        exit(0);
//        if (teamInstance[teamIDs[x]]->getPlayerInstancesCreated())
        if (ATIIT.second->getPlayerInstancesCreated())
        {
//            exit(0);
            logMsg(func +" teamInstance[teamIDs[" +convert->toString(ATIIT.first) +"]] playerInstances crested!");
            logMsg(func +" Team " +convert->toString(ATIIT.first) +" player instances created!");
        }
        else
        {
//            exit(0);
            logMsg(func +" creating team " +convert->toString(ATIIT.first) +" playerInstances!");
//            teamInstance[x]->setBase(base);
            if (ATIIT.second->createPlayerInstances())
            {
                logMsg("activeTeamInstance[" +convert->toString(ATIIT.first) +"]->createPlayerInstances()");
                logMsg("activeTeamInstance[" +convert->toString(ATIIT.first) +"]->getPlayerInstance().size() == " +convert->toString(ATIIT.second->getPlayerInstance().size()));
//                exit(0);
                ATIIT.second->setPlayerInstancesCreated(true);
                base->getGameS()->setActiveTeamInstance(activeTeamInstance);
            }
            else
            {
                logMsg("Unable to create active team [" +convert->toString(x) +"] playerInstances");
                exit(0);
            }
        }
//        playerInstance.push_back(ATIIT.second->getPlayerInstance());
        playerInstance.insert(playerInstance.begin(), ATIIT.second->getPlayerInstance());
       ++x;
    }
    logMsg("playerInstance.size() == " +convert->toString(playerInstance.size()));
    logMsg("playerInstance[0].size() == " +convert->toString(playerInstance[0].size()));
    logMsg("playerInstance[1].size() == " +convert->toString(playerInstance[1].size()));
//    exit(0);
/*    for (auto pInstanceIT : activeTeamInstance[0]->getPlayerInstance())
    {
//            std::string playerName = playerInstance[i][1]->getFirstName() +" " +playerInstance[i][1]->getLastName(); // +"            "; // +playerOverallRating;
        std::string playerName = pInstanceIT.second->getFirstName() +" " +pInstanceIT.second->getLastName();
        logMsg(func +" team " +convert->toString(0) + " playerName == " +playerName);
    }
*/
//    exit(0);
    std::vector<playerStateUMSharedPtr >::iterator it;
    auto itx = 0;
//    while (it < playerInstance.size())
    for (it = playerInstance.begin(); it != playerInstance.end(); ++it)
    {
        logMsg(func +" itx == " +convert->toString(itx));
//        logMsg(func +" playerInstance[" +convert->toString(it.first) +"].size() == " +convert->toString(playerInstance[i].size()));
//        auto j = 0;
//        while (j < playerInstance[i].size())
        for (auto pInstanceIT : *it)
//        for (auto pInstanceIT : playerInstance[1])
        {
//            std::string playerName = playerInstance[i][1]->getFirstName() +" " +playerInstance[i][1]->getLastName(); // +"            "; // +playerOverallRating;
            std::string playerName = pInstanceIT.second->getFirstName() +" " +pInstanceIT.second->getLastName();
            logMsg(func +" team " +convert->toString(itx) + " playerName == " +playerName);

//            logMsg(func +" j == " +convert->toString(j));
//            size_t overallRating = base->getGameS()->getPlayerInstance()[i]->getOverallRating();
            std::string playerOverallRating = convert->toString(pInstanceIT.second->getOverallRating());
            bool playerNameLengthReached = false;
            std::string playerPosition = convert->toString(pInstanceIT.second->getPrimaryPosition());
            size_t playerID = pInstanceIT.second->getID();

//            playerNames[1].push_back(playerName);
//            playerPositionsPlayed[1].push_back(playerPosition);
//            playerIDs[1].push_back(playerID);
//            overallRatings[1].push_back(overallRating);
  
//            exit(0);
            switch (pInstanceIT.second->getPrimaryPosition())
            {
                case PG:
                    teamPlayerPosSelectBox[itx]["PG"]->addItem(playerName);
//                    teamPlayerRating[i]["PG"]->setCaption(playerOverallRating);
                    logMsg("PG playerName == " +playerName);
                    logMsg("PG playerRating == " +playerOverallRating);
                break;
                case SG:
                    teamPlayerPosSelectBox[itx]["SG"]->addItem(playerName);         
//                    teamPlayerRating[i]["SG"]->setCaption(playerOverallRating);
                    logMsg("SG playerName == " +playerName);
                    logMsg("SG playerRating == " +playerOverallRating);
 
                break;
                case SF:
                    teamPlayerPosSelectBox[itx]["SF"]->addItem(playerName);
//                    teamPlayerRating[i]["SF"]->addItem(playerOverallRating);
                    logMsg("SF playerName == " +playerName);
                    logMsg("SF playerRating == " +playerOverallRating);
                break;
                case PF:
                    teamPlayerPosSelectBox[itx]["PF"]->addItem(playerName);
//                    teamPlayerRating[i]["PF"]->addItem(playerOverallRating);
                    logMsg("PF playerName == " +playerName);
                    logMsg("PF playerRating == " +playerOverallRating);
  
                break;
                case C:
                    teamPlayerPosSelectBox[itx]["C"]->addItem(playerName);
//                    teamPlayerRating[i]["C"]->addItem(playerOverallRating);
                    logMsg("C playerName == " +playerName);
                    logMsg("C playerRating == " +playerOverallRating);
                break;
//                exit(0);
            }

//            teamPlayerPosSelectBox.insert(ti,playerInstance[i].)
            
//            ++j;
        }
        ++itx;
    }
    logMsg(func + " end");
//    exit(0);
}

void GUISystem::addPlayerStartSelectionMenuData_old()  // adds data to Player Start Selection Menu widgets
{
    sharedPtr<conversion> convert = conversion::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
    sharedPtr<loader> load(new loader);

//    playerInstance = load->loadPlayers();
//    playerInstance = gameS->getPlayerInstance();
//    gameS->setPlayerInstances(playerInstance);
    sizeTVec teamIDs = base->getGameS()->getTeamIDS();
    teamStateUMSharedPtr teamInstance = base->getGameS()->getActiveTeamInstance();
    std::vector<playerStateUMSharedPtr > playerInstance;
//    playerStateVecSharedPtr pInstance;
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
    //FIXME! This should not be hardcoded!
    x = 0;
//    exit(0);
//    while (x < 2)
    for (auto TIIT : teamInstance)
    {
        logMsg(func +" yabadaba");
        logMsg(convert->toString(teamIDs.size()));
        logMsg(convert->toString(TIIT.second->getPlayerInstancesCreated()));
//        exit(0);
//        if (teamInstance[teamIDs[x]]->getPlayerInstancesCreated())
        if (TIIT.second->getPlayerInstancesCreated())
        {
//            exit(0);
            logMsg(func +" teamInstance[teamIDs[" +convert->toString(TIIT.first) +"]] playerInstances crested!");
            logMsg(func +" Team " +convert->toString(TIIT.first) +" player instances created!");
        }
        else
        {
//            exit(0);
            logMsg(func +" creating team " +convert->toString(TIIT.first) +" playerInstances!");
//            teamInstance[x]->setBase(base);
            if (TIIT.second->createPlayerInstances())
            {
//                exit(0);
                TIIT.second->setPlayerInstancesCreated(true);
//                base->getGameS()->setTeamInstance(teamInstance);
            }
       }  
       ++x;
    }
    base->getGameS()->setTeamInstance(teamInstance);
    logMsg(func +" Bleert!");
    
    exit(0);
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
            logMsg("playerInstance[i][j].getFirstName() == " +playerInstance[i][j]->getFirstName());
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
    sharedPtr<conversion> convert = conversion::Instance();

    sharedPtr<loader> load(new loader);

    teamStateUMSharedPtr teamInstance; // = gameS->getTeamDataInstance();

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
//    while (x < teamInstance.size())
    for (auto TIIT : teamInstance)
    {
        logMsg("GUI ADD TEAM teamInstance[" +convert->toString(TIIT.first) +"]->getID() ID == " +convert->toString(TIIT.second->getID()));
//        ++x;
    }
//    exit(0);
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
