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

#include "engine/networkengine.h"

#include "gui/gui.h"
#include "utilities/conversion.h"
#include "components/gamecomponents.h"
#include "components/guicomponents.h"
#include "components/teamcomponents.h"
#include "data/courtdata.h"
#include "data/gamedata.h"
#include "data/playerdata.h"
#include "engine/gameengine.h"
#include "entity/courtentity.h"
#include "entity/playerentity.h"
#include "entity/teamentity.h"
#include "flags/teamflags.h"
#include "setup/setupcourts.h"
#include "setup/setupplayers.h"
#include "setup/setupteams.h"
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
    conversionSharedPtr convert = conversion::Instance();
    setupCourtsSharedPtr setupCourt(new setupCourts);
    courtStateMSharedPtr  courtInstance;
//    courtStateSharedPtr court(new courtState);
//    courtInstance.insert(std::pair<size_t, courtStateSharedPtr>(0, court));
    stdStringVec courtName;
    stdStringVec::iterator CNIT;
    std::string func = "GUISystem::addCourtSelectionMenuData()";
    
    logMsg(func +" begin");
    
//    if (!gameS->getCourtInstancesCreated())

//    exit(0);
    if (gameInstance->getFlag()->getCourtInstancesCreated())
    {
//        exit(0);

        courtInstance = gameInstance->getComponent()->getCourtInstance();
//        exit(0);
        gameInstance->getFlag()->setCourtInstancesNeedCreated(true);
//        exit(0);

    }
    else
    {
//        exit(0);
        courtInstance = setupCourt->createCourtInstances();
        if (courtInstance.size() > 0)
        {
            logMsg(func +" Court Data Initialized == " +convert->toString(courtInstance[0]->getData()->getInitialized()));
            logMsg(func +" Court Data Name == " +courtInstance[0]->getData()->getName());
            logMsg(func +" Court Entity Name == " +courtInstance[0]->getEntity()->getName());
            logMsg(func +" Court Entity modelFileName == " +courtInstance[0]->getEntity()->getModelFileName());
            logMsg(func +" Court Entity Initialized == " +convert->toString(courtInstance[0]->getEntity()->getInitialized()));
            logMsg(func +" Court Initialized == " +convert->toString(courtInstance[0]->getInitialized()));
            logMsg(func +" Game Initialized == " +convert->toString(gameInstance->getFlag()->getInitialized()));

            gameInstance->getComponent()->setCourtInstance(courtInstance);
//            exit(0);
            gameInstance->getFlag()->setCourtInstancesCreated(true);
            logMsg(func +" Court Instances Created!!");
        }
        else
        {
            logMsg(func +" Court Instances NOT Created!");
            exit(0);
        }
    }
    logMsg(func +" fleeart!");
//    exit(0);

//    courtInstance = gameS->getCourtInstance();
    auto evenCount = 0;
    for (auto  CIIT : courtInstance)
//    for_each(courtInstance.begin(), courtInstance.end(), [&evenCount] (size_t n)
    {
        courtName.push_back(CIIT.second->getData()->getName());
    }

//    courtInstance.courtNameFunc(getName());
    logMsg(func +" courtName.size() == " +convert->toString(courtName.size()));
    if (courtInstance.size() == 0)
    {
        logMsg(func +" courtInstane.size == " +convert->toString(courtInstance.size()));
//        exit(0);
    }
//    exit(0);

    logMsg(func +" courtName = " +courtName[0]);
    logMsg(func +" courtName size = " +convert->toString(courtName.size()));
//    exit(0);u
//    auto i = 0;
    for (CNIT = courtName.begin(); CNIT != courtName.end(); ++CNIT)
    {
        component->getCourtSelectBox()->addItem(*CNIT);
        
    }

    logMsg(func +" Court names added!");
//    exit(0);
    return (true);
}

void GUISystem::addPlayerStartSelectionMenuData()  // adds data to Player Start Selection Menu widgets
{
    conversionSharedPtr convert = conversion::Instance();
    setupPlayersSharedPtr setupPlayer(new setupPlayers);
//    gameStateSharedPtr gameS = base->getGameS();
    teamEntityMSharedPtr activeTeamInstance = gameInstance->getComponent()->getActiveTeamInstance();
    playerEntityMSharedPtr gamePlayerInstance;
    playerEntityMSharedPtr playerInstance;
    std::string func = "GUISystem::addPlayerStartSelectionMenuData";
    sizeTVec teamIDs = gameInstance->getData()->getTeamIDS();

    logMsg(func +" begin");
    
    logMsg(func +" activeTeamInstance.size() == " +convert->toString(activeTeamInstance.size()));
//    exit(0);
    size_t teamNum = 0;
    
    if (setupPlayer->checkIfGamePlayerInstancesCreated(gameInstance->getComponent(), gameInstance->getFlag()))
    {
        logMsg(func + " gameState Player Instances Created!");
        gamePlayerInstance = gameInstance->getComponent()->getPlayerInstance();
    }
    else
    {
        logMsg(func + " Unable to Create gameState Player Instances!");

    }
    if (setupPlayer->checkIfTeamPlayerInstancesCreated(gamePlayerInstance, activeTeamInstance))
    {
        logMsg(func + " Team Player Instances Created!");
    }
    else
    {
        logMsg(func + " Unable to Create Team Player Instances!");

    }

    logMsg(func + " gameState Player Instance Size == " +convert->toString(gamePlayerInstance.size()));
    for (auto ATIIT : activeTeamInstance)
    {
        logMsg(func + " gameState Player Instance Size == " +convert->toString(ATIIT.second->getComponent()->getPlayerInstance().size()));
    }
//    exit(0);
    for (auto ATIIT : activeTeamInstance)  // loop through activeTeamInstance
    {
        logMsg(func +" yabadaba");
        logMsg(convert->toString(teamIDs.size()));
        logMsg(convert->toString(ATIIT.second->getFlag()->getPlayerInstancesCreated()));
//        exit(0);

        playerInstance = ATIIT.second->getComponent()->getPlayerInstance();
        for (auto PIIT : playerInstance)
        {
            std::string playerName = PIIT.second->getData()->getFirstName() +" " +PIIT.second->getData()->getLastName();
            std::string playerOverallRating = convert->toString(PIIT.second->getData()->getOverallRating());
 
            switch (PIIT.second->getData()->getPrimaryPosition())
            {
                case PG:
                    component->getTeamPlayerPosSelectBox()[teamNum]["PG"]->addItem(playerName);
//                    teamPlayerRating[i]["PG"]->setCaption(playerOverallRating);
                    logMsg(func +" PG playerName == " +playerName);
                    logMsg(func +" PG playerRating == " +playerOverallRating);
                break;
                case SG:
                    component->getTeamPlayerPosSelectBox()[teamNum]["SG"]->addItem(playerName);         
//                    teamPlayerRating[i]["SG"]->setCaption(playerOverallRating);
                    logMsg(func +" SG playerName == " +playerName);
                    logMsg(func +" SG playerRating == " +playerOverallRating);
 
                break;
                case SF:
                    component->getTeamPlayerPosSelectBox()[teamNum]["SF"]->addItem(playerName);
//                    teamPlayerRating[i]["SF"]->addItem(playerOverallRating);
                    logMsg(func +" SF playerName == " +playerName);
                    logMsg(func +" SF playerRating == " +playerOverallRating);
                break;
                case PF:
                    component->getTeamPlayerPosSelectBox()[teamNum]["PF"]->addItem(playerName);
//                    teamPlayerRating[i]["PF"]->addItem(playerOverallRating);
                    logMsg(func +" PF playerName == " +playerName);
                    logMsg(func +" PF playerRating == " +playerOverallRating);
  
                break;
                case C:
                    component->getTeamPlayerPosSelectBox()[teamNum]["C"]->addItem(playerName);
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
    
    playerEntityVecMSharedPtr::iterator PEVUIT;
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
    setupTeamsSharedPtr setupTeam(new setupTeams);
    loadTeamsSharedPtr loadTeam(new loadTeams); // = base->getLoadTeam();
    teamEntityMSharedPtr teamInstance; // = gameS->getTeamDataInstance();
    std::string func = "GUISystem::addTeamStartSelectionMenuData()";

    logMsg(func +" begin");
    
    if (loadTeam->checkIfTeamsLoaded())
    {
        teamInstance = loadTeam->getTInstance();
    }
//    exit(0);
    gameInstance->getComponent()->setTeamInstance(teamInstance);  // copies data to teamInstance object
    gameInstance->getFlag()->setTeamInstancesCreated(true);
    
    logMsg(func +" GUI ADD TEAM 0 teamInstance.size() == " +convert->toString(teamInstance.size()));
//    exit(0);
    auto x = 0;
//    while (x < teamInstance.size())
    for (auto TIIT : teamInstance)
    {
        logMsg(func +" GUI ADD TEAM teamInstance[" +convert->toString(TIIT.first) +"]->getData()->getID() ID == " +convert->toString(TIIT.second->getData()->getID()));
//        ++x;
    }
//    exit(0);
     logMsg(func +" GUI ADD TEAM gameInstance->getTeamInstance()[3]->getID() ID == " +convert->toString(gameInstance->getComponent()->getTeamInstance()[0]->getData()->getID()));
    if (gameInstance->getFlag()->getTeamInstancesCreated())
    {        
        logMsg(func +" Woot!");
//        exit(0);
        if (gameInstance->getComponent()->getTeamInstance().size() > 0)
        {
            teamInstance = gameInstance->getComponent()->getTeamInstance();
            logMsg(func +" GUI ADD TEAM 1 teamInstance.size() == " +convert->toString(gameInstance->getComponent()->getTeamInstance().size()));
        }
        else
        {
            logMsg(func +" getGameS()->getTeamInstance() is EMPTY! IF");
            return (false);           
        }
//        exit(0);
    }
    else
    {    
        teamInstance = setupTeam->createTeamInstances();  // creates team instances
        if (teamInstance.size() > 0)
        {
             logMsg(func +" GUI ADD TEAM 2 teamInstance.size() == " +convert->toString(gameInstance->getComponent()->getTeamInstance().size()));
//            exit(0);
/*            if (base->getGameS()->getTeamInstance().size() > 0)
            {
                teamInstance = base->getGameS()->getTeamInstance();
                logMsg("GUI ADD TEAM 3 teamInstance.size() == " +convert->toString(gameInstance->getTeamInstance().size()));
            }
            else
            {
                logMsg("getGameS()->getTeamInstance() is EMPTY! ELSE");
                return (false);                               
            }*/
        }
        else
        {
            logMsg(func +" Failed to create teamSelectioMenuGUI");
            return (false);
        }
        
    }



//    gameS->setTeamDataInstance(teamDataInstance);
//
//    teamInstance = gameS->getTeamInstance();
    logMsg(func +" teamInstance.size() == " +convert->toString(gameInstance->getComponent()->getTeamInstance().size()));
    if (teamInstance.size() == 0)
    {
        logMsg(func +" teamInstance is empty!");
        exit(0);
    }
    logMsg(func +" " +convert->toString(teamInstance.size()));
    logMsg(func +" Team City == " +teamInstance[0]->getData()->getCity() +"b");
    logMsg(func +" Team City == " +teamInstance[1]->getData()->getCity() +"b");
    logMsg(func +" Team City == " +teamInstance[2]->getData()->getCity() +"b");
    logMsg(func +" Team City == " +teamInstance[3]->getData()->getCity() +"b");


//    exit(0);
    for (auto TIIT : teamInstance)
    {
        if (TIIT.second->getData()->getCity() == "")
        {
            logMsg(func +" City is blank!");
            exit(0);
        }
        std::string teamName = TIIT.second->getData()->getCity() + " " +TIIT.second->getData()->getName();

        component->getTeamSelectBox()[0]->addItem(teamName);
        component->getTeamSelectBox()[1]->addItem(teamName);
    }
    component->getTeamSelectBox()[0]->setIndexSelected(0);
    component->getTeamSelectBox()[1]->setIndexSelected(1);
    logMsg(func +" end");//    exit(0);

    
    return (true);
}
