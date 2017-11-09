
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

#include "ubc/ubcbase.h"
#include "engine/networkengine.h"

#include "gui/gui.h"
#include "utilities/conversion.h"
#include "data/courtdata.h"
#include "data/playerdata.h"
#include "engine/gameengine.h"
#include "entity/playerentity.h"
#include "gamesetup/gamesetupteams.h"
#include "state/courtstate.h"
#include "state/gamestate.h"
#include "state/playerstate.h"
#include "state/teamstate.h"
#include "load/loadteams.h"
#include "utilities/logging.h"
#include "engine/renderengine.h"
#include "data/teamdata.h"

//#include "utilities/easylogging++.h"

#ifdef __ANDROID__
#include "utilities/android-config.h"
#else
#include "config.h"
#endif

bool GUISystem::addCourtSelectionMenuData()  // adds data to Player Start Selection Menu widgets
{
//    sharedPtr<gameState> gameS = gameState::Instance();
    sharedPtr<conversion> convert = conversion::Instance();

    courtStateMSharedPtr  courtInstance;
    stdStringVec courtName;
    stdStringVec::iterator CNIT;
    
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
    for (auto  CIIT : courtInstance)
//    for_each(courtInstance.begin(), courtInstance.end(), [&evenCount] (size_t n)
    {
        courtName.push_back(CIIT.second->getData()->getName());
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
//    auto i = 0;
    for (CNIT = courtName.begin(); CNIT != courtName.end(); ++CNIT)
    {
        courtSelectBox->addItem(*CNIT);
        
    }

    logMsg("Court names added!");
//    exit(0);
    return (true);
}

void GUISystem::addPlayerStartSelectionMenuData()  // adds data to Player Start Selection Menu widgets
{
    sharedPtr<conversion> convert = conversion::Instance();
    teamStateMSharedPtr activeTeamInstance = base->getGameS()->getActiveTeamInstance();
    playerEntityMSharedPtr playerInstance;
    std::string func = "addPlayerStartSelectionMenuData";
    sizeTVec teamIDs = base->getGameS()->getTeamIDS();

    logMsg(func +" beginning");
    
    logMsg(func +" activeTeamInstance.size() == " +convert->toString(activeTeamInstance.size()));
//    exit(0);
    size_t teamNum = 0;
    for (auto ATIIT : activeTeamInstance)
    {
        logMsg(func +" yabadaba");
        logMsg(convert->toString(teamIDs.size()));
        logMsg(convert->toString(ATIIT.second->getPlayerInstancesCreated()));
//        exit(0);

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
                logMsg(func +" activeTeamInstance[" +convert->toString(ATIIT.first) +"]->createPlayerInstances()");
                logMsg(func +" activeTeamInstance[" +convert->toString(ATIIT.first) +"]->getPlayerInstance().size() == " +convert->toString(ATIIT.second->getPlayerInstance().size()));
//                exit(0);

                if (base->getGameS()->getGameType() == SINGLE)
                {
                    logMsg(func +" gameType == SINGLE");
                }
                else if (getBase()->getGameS()->getGameType() == NOGAME)
                {
                    logMsg(func +" gameType == NOGAME");
                }            
                ATIIT.second->setPlayerInstancesCreated(true);   
                base->getGameS()->setActiveTeamInstance(activeTeamInstance);
            }
            else
            {
//                logMsg(func +" Unable to create active team [" +convert->toString(x) +"] playerInstances");
                exit(0);
            }
        }
        playerInstance = ATIIT.second->getPlayerInstance();
        for (auto PIIT : playerInstance)
        {
            std::string playerName = PIIT.second->getData()->getFirstName() +" " +PIIT.second->getData()->getLastName();
            std::string playerOverallRating = convert->toString(PIIT.second->getData()->getOverallRating());
 
            switch (PIIT.second->getData()->getPrimaryPosition())
            {
                case PG:
                    teamPlayerPosSelectBox[teamNum]["PG"]->addItem(playerName);
//                    teamPlayerRating[i]["PG"]->setCaption(playerOverallRating);
                    logMsg(func +" PG playerName == " +playerName);
                    logMsg(func +" PG playerRating == " +playerOverallRating);
                break;
                case SG:
                    teamPlayerPosSelectBox[teamNum]["SG"]->addItem(playerName);         
//                    teamPlayerRating[i]["SG"]->setCaption(playerOverallRating);
                    logMsg(func +" SG playerName == " +playerName);
                    logMsg(func +" SG playerRating == " +playerOverallRating);
 
                break;
                case SF:
                    teamPlayerPosSelectBox[teamNum]["SF"]->addItem(playerName);
//                    teamPlayerRating[i]["SF"]->addItem(playerOverallRating);
                    logMsg(func +" SF playerName == " +playerName);
                    logMsg(func +" SF playerRating == " +playerOverallRating);
                break;
                case PF:
                    teamPlayerPosSelectBox[teamNum]["PF"]->addItem(playerName);
//                    teamPlayerRating[i]["PF"]->addItem(playerOverallRating);
                    logMsg(func +" PF playerName == " +playerName);
                    logMsg(func +" PF playerRating == " +playerOverallRating);
  
                break;
                case C:
                    teamPlayerPosSelectBox[teamNum]["C"]->addItem(playerName);
//                    teamPlayerRating[i]["C"]->addItem(playerOverallRating);
                    logMsg(func +" C playerName == " +playerName);
                    logMsg(func +" C playerRating == " +playerOverallRating);
                break;
//                exit(0);
            }
        }
        ++teamNum;
    }
/*    
    logMsg(func +" playerInstance.size() == " +convert->toString(playerInstance.size()));
    logMsg(func +" playerInstance[0].size() == " +convert->toString(playerInstance[0].size()));
    logMsg(func +" playerInstance[1].size() == " +convert->toString(playerInstance[1].size()));
//    exit(0);
    
    playerEntityVecUMSharedPtr::iterator PEVUIT;
//    auto itx = 0;
    for (PEVUIT = playerInstance.begin(); PEVUIT != playerInstance.end(); ++PEVUIT)
    {
//        logMsg(func +" itx == " +convert->toString(itx));
//        logMsg(func +" playerInstance[" +convert->toString(it.first) +"].size() == " +convert->toString(playerInstance[i].size()));
//        auto j = 0;
        for (auto pInstanceIT : *PEVUIT)
        {
//            std::string playerName = playerInstance[i][1]->getFirstName() +" " +playerInstance[i][1]->getLastName(); // +"            "; // +playerOverallRating;
            std::string playerName = pInstanceIT.second->getData()->getFirstName() +" " +pInstanceIT.second->getData()->getLastName();
//FIXME!            logMsg(func +" team " +convert->toString(itx) + " playerName == " +playerName);

//            logMsg(func +" j == " +convert->toString(j));
//            size_t overallRating = base->getGameS()->getPlayerInstance()[i]->getOverallRating();
            std::string playerOverallRating = convert->toString(pInstanceIT.second->getData()->getOverallRating());
            bool playerNameLengthReached = false;
            std::string playerPosition = convert->toString(pInstanceIT.second->getData()->getPrimaryPosition());
            size_t playerID = pInstanceIT.second->getData()->getID();

//            playerNames[1].push_back(playerName);
//            playerPositionsPlayed[1].push_back(playerPosition);
//            playerIDs[1].push_back(playerID);
//            overallRatings[1].push_back(overallRating);
  
//            exit(0);
            switch (pInstanceIT.second->getData()->getPrimaryPosition())
            {
                case PG:
                pInstanceIT.second->getData()->getTeamID();
                    teamPlayerPosSelectBox[itx]["PG"]->addItem(playerName);
//                    teamPlayerRating[i]["PG"]->setCaption(playerOverallRating);
                    logMsg(func +" PG playerName == " +playerName);
                    logMsg(func +" PG playerRating == " +playerOverallRating);
                break;
                case SG:
                    teamPlayerPosSelectBox[itx]["SG"]->addItem(playerName);         
//                    teamPlayerRating[i]["SG"]->setCaption(playerOverallRating);
                    logMsg(func +" SG playerName == " +playerName);
                    logMsg(func +" SG playerRating == " +playerOverallRating);
 
                break;
                case SF:
                    teamPlayerPosSelectBox[itx]["SF"]->addItem(playerName);
//                    teamPlayerRating[i]["SF"]->addItem(playerOverallRating);
                    logMsg(func +" SF playerName == " +playerName);
                    logMsg(func +" SF playerRating == " +playerOverallRating);
                break;
                case PF:
                    teamPlayerPosSelectBox[itx]["PF"]->addItem(playerName);
//                    teamPlayerRating[i]["PF"]->addItem(playerOverallRating);
                    logMsg(func +" PF playerName == " +playerName);
                    logMsg(func +" PF playerRating == " +playerOverallRating);
  
                break;
                case C:
                    teamPlayerPosSelectBox[itx]["C"]->addItem(playerName);
//                    teamPlayerRating[i]["C"]->addItem(playerOverallRating);
                    logMsg(func +" C playerName == " +playerName);
                    logMsg(func +" C playerRating == " +playerOverallRating);
                break;
//                exit(0);
            }

//            teamPlayerPosSelectBox.insert(ti,playerInstance[i].)
            
//            ++j;
        }
//        ++itx;
    }
    */
    logMsg(func + " end");
//    exit(0);
}


bool GUISystem::addTeamStartSelectionMenuData()  // adds data to Team Start Selection Menu
{
    conversionSharedPtr convert = conversion::Instance();
    gameSetupTeamsSharedPtr gameSetupTeam(new gameSetupTeams);
    loadTeamsSharedPtr loadTeam = base->getLoadTeam();
    teamStateMSharedPtr teamInstance; // = gameS->getTeamDataInstance();

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

    if (loadTeam->checkIfTeamsLoaded())
    {
        teamInstance = loadTeam->getTInstance();
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
        teamInstance = gameSetupTeam->createTeamInstances();  // creates team instances
        if (teamInstance.size() > 0)
        {
             logMsg("GUI ADD TEAM 2 teamInstance.size() == " +convert->toString(base->getGameS()->getTeamInstance().size()));
//            exit(0);
/*            if (base->getGameS()->getTeamInstance().size() > 0)
            {
                teamInstance = base->getGameS()->getTeamInstance();
                logMsg("GUI ADD TEAM 3 teamInstance.size() == " +convert->toString(base->getGameS()->getTeamInstance().size()));
            }
            else
            {
                logMsg("getGameS()->getTeamInstance() is EMPTY! ELSE");
                return (false);                               
            }*/
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
    for (auto TIIT : teamInstance)
    {
        if (TIIT.second->getCity() == "")
        {
            logMsg("City is blank!");
            exit(0);
        }
        std::string teamName = TIIT.second->getCity() + " " +TIIT.second->getName();

        teamSelectBox[0]->addItem(teamName);
        teamSelectBox[1]->addItem(teamName);
    }
    teamSelectBox[0]->setIndexSelected(0);
    teamSelectBox[1]->setIndexSelected(1);
    logMsg("End of addTeamStartSelectionMenuData!");
//    exit(0);

    return (true);
}
