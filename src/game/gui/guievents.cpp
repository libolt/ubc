/***************************************************************************
 *   Copyright (C) 1999 - 2019 by Mike McLean                              *
 *   libolt@libolt.net                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under thtn fe terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARjTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "gui/guievents.h"

#include "components/gamecomponents.h"
#include "components/guicomponents.h"
#include "components/teamcomponents.h"
#include "data/gamedata.h"
#include "engine/gameengine.h"
#include "engine/renderengine.h"
#include "entity/gameentity.h"
#include "entity/teamentity.h"
#include "flags/gameflags.h"
#include "flags/guiflags.h"
#include "gui/guicreate.h"
#include "gui/guidata.h"
#include "gui/guidisplay.h"
#include "setup/setuplineups.h"
#include "setup/setupplayers.h"
#include "setup/setupteams.h"
#include "statemachine/guistatemachine.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

guiEvents::guiEvents()  // constructor
{

}
guiEvents::~guiEvents() = default;  // destructor

guiComponentsSharedPtr guiEvents::getComponent() const  // retrieves the value of component
{
    return (component);
}
void guiEvents::setComponent(const guiComponentsSharedPtr &set)  // sets the value of component
{
    component = set;
}

guiCreateSharedPtr guiEvents::getCreate() const  // retrieves the value of create
{
    return (create);
}
void guiEvents::setCreate(const guiCreateSharedPtr &set)  // sets the value of create
{
    create = set;
}

guiDataSharedPtr guiEvents::getData() const  // retrieves the value of data
{
    return (data);
}
void guiEvents::setData(const guiDataSharedPtr &set)  // sets the value of data
{
    data = set;
}

guiDisplaySharedPtr guiEvents::getDisplay() const  // retrieves the value of display
{
    return (display);
}
void guiEvents::setDisplay(const guiDisplaySharedPtr &set)  // sets the value of display
{
    display = set;
}

guiFlagsSharedPtr guiEvents::getFlag() const  // retrieves the value of flag
{
    return (flag);
}
void guiEvents::setFlag(const guiFlagsSharedPtr &set)  // sets the value of flag
{
    flag = set;
}

guiStateMachineSharedPtr guiEvents::getStateMachine() const  // retrieves the value of stateMachine
{
    return (stateMachine);
}
void guiEvents::setStateMachine(const guiStateMachineSharedPtr &set)  // sets the value of stateMachine
{
    stateMachine = set;
}

gameEngineSharedPtr guiEvents::getGamE() const  // retrieves the value of gameE
{
    return (gameE);
}
void guiEvents::setGameE(const gameEngineSharedPtr &set)  // sets the value of gameE
{
    gameE = set;
}

gameEntitySharedPtr guiEvents::getGameInstance() const  // retrieves the value of teamInstance
{
    return (gameInstance);
}
void guiEvents::setGameInstance(const gameEntitySharedPtr &set)  // sets the value of teamInstance
{
    gameInstance = set;
}

bool guiEvents::checkCourtMenuSelects()  // checks which courtMenu option was selected
{
    bool retVal = false;
    std::string func = "guiEvents::checkCourtMenuSelects()";

    logMsg(func +" begin");
//    exit(0);
    guiSMData *csSMData(new guiSMData);

    switch (component->getCourtMenuSelect())
    {
        case BACKCOURTMAIN:
        break;
        case COURTSSELECT:
            courtSelected();
            csSMData->component = component;
            csSMData->create = create;
            csSMData->gData = data;
            csSMData->display = display;
            csSMData->flag = flag;
            csSMData->gameInstance = gameInstance;
            csSMData->render = gameE->getRenderE();

            stateMachine->pTeamMenu(csSMData);

//            teamSelectionMenu(render);
        break;
    }

    logMsg(func +" end");

    return (retVal);
}

bool guiEvents::checkMainMenuSelects()  // checks which mainMenu option was selected
{
    bool retVal = false;
    std::string func = "guiEvents::checkMainMenuSelects()";

    logMsg(func +" begin");
    guiSMData *ssSMData(new guiSMData);
    guiSMData *smSMData(new guiSMData);

    switch (component->getMainMenuSelect())
    {
        case STARTSINGLE:
//            exit(0);
            ssSMData->component = component;
            ssSMData->create = create;
            ssSMData->gData = data;
            ssSMData->display = display;
            ssSMData->flag = flag;
            ssSMData->gameInstance = gameInstance;
            ssSMData->render = gameE->getRenderE();

            stateMachine->pStartSinglePlayerGame(ssSMData);
        break;
        case STARTMULTI:
            smSMData->component = component;
            smSMData->create = create;
            smSMData->gData = data;
            smSMData->display = display;
            smSMData->flag = flag;
            smSMData->gameInstance = gameInstance;
            smSMData->render = gameE->getRenderE();

            stateMachine->pNetworkMenu(smSMData);

//            exit(0);
        break;
    }

    logMsg(func +" end");

    return (retVal);
}

bool guiEvents::checkNetworkMenuSelects()  // checks which networkMenu option was selected
{
    bool retVal = false;
    std::string func = "guiEvents::checkNetworkMenuSelects()";

    logMsg(func +" begin");
    guiSMData *ncSMData(new guiSMData);
    guiSMData *nsSMData(new guiSMData);

    switch (component->getNetworkMenuSelect())
    {
        case CLIENTSELECT:
            ncSMData->component = component;
            ncSMData->create = create;
            ncSMData->gData = data;
            ncSMData->display = display;
            ncSMData->flag = flag;
            ncSMData->gameInstance = gameInstance;
            ncSMData->render = gameE->getRenderE();
            stateMachine->pNetworkClientMenu(ncSMData);
        break;
        case SERVERSELECT:
//            exit(0);
            nsSMData->component = component;
            nsSMData->create = create;
            nsSMData->gData = data;
            nsSMData->display = display;
            nsSMData->flag = flag;
            nsSMData->gameInstance = gameInstance;
            nsSMData->render = gameE->getRenderE();

            stateMachine->pNetworkServerMenu(nsSMData);
        break;
        case BACKNETWORKMAIN:
        break;
    }

//    networkServerSetupMenu(gameE->getRenderE());
    logMsg(func +" end");

    return (retVal);
}

bool guiEvents::checkNetworkClientMenuSelects()  // checks which networkMenu option was selected
{
    bool retVal = false;
    std::string func = "guiEvents::checkNetworkClientMenuSelects()";

    logMsg(func +" begin");

    logMsg(func +" end");

    return (retVal);
}

bool guiEvents::checkNetworkServerMenuSelects()  // checks which networkMenu option was selected
{
    bool retVal = false;
    std::string func = "guiEvents::checkNetworkServerMenuSelects()";

    logMsg(func +" begin");

    logMsg(func +" end");

    return (retVal);
}

bool guiEvents::checkOptionsMenuSelects()  // checks which optionsMenu option was selected
{
    bool retVal = false;
    std::string func = "guiEvents::checkOptionsMenuSelects()";

    logMsg(func +" begin");

    logMsg(func +" end");

    return (retVal);
}

bool guiEvents::checkStartersMenuSelects()  // checks which startersMenu option was selected
{
    bool retVal = false;
    std::string func = "guiEvents::checkStartersmMenuSelects()";

    logMsg(func +" begin");

    exit(0);
    switch (component->getStartersMenuSelect())
    {
        case STARTERSSELECT:
            checkTeamInstancesCreated();
            playerStartSelected();
            flag->setStartActiveGame(true);
        break;
    }

    logMsg(func +" end");

    return (retVal);
}

bool guiEvents::checkTeamMenuSelects()  // checks which teamMenu option was selected
{
    bool retVal = false;
    std::string func = "guiEvents::checkTeamMenuSelects()";

    logMsg(func +" begin");
    teamsSelected();
//    exit(0);
    guiSMData *tsSMData(new guiSMData);

    switch (component->getTeamMenuSelect())
    {
        case TEAMSSELECT:
//            exit(0);
            tsSMData->component = component;
            tsSMData->create = create;
            tsSMData->gData = data;
            tsSMData->display = display;
            tsSMData->event = evThis();
            tsSMData->flag = flag;
            tsSMData->gameInstance = gameInstance;
            tsSMData->render = gameE->getRenderE();

            stateMachine->pStartersMenu(tsSMData);
        break;
    }
//        playerStartSelectionMenu(render);

    logMsg(func +" end");

    return (retVal);
}

bool guiEvents::checkTeamInstancesCreated()  // Checks if team instances have been created and if not creates them.
{
    bool retVal = false;
//    exit(0);
    //gameState *gameS = gameState::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();

    if (!gameInstance->getFlag()->getActiveTeamInstancesCreated())
    {
//        base->getGameS()->setActiveTeamInstancesNeedCreated(true);
/*        logMsg("Creating active team instances!");
        gameS->FFFcreateActiveTeamInstances();
        gameS->setActiveTeamInstancesCreated(true);
        gameS->assignHoopToTeams();
        logMsg("Team instances created!");
*/
//        retVal = false;
//        exit(0);
    }
    else
    {
        retVal = true;
    }
    return (retVal);
}

void guiEvents::courtSelected()  // processes court selection
{
    //conversion *convert = conversion::Instance();
    conversionSharedPtr convert ;
    //gameState *gameS = gameState::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
    std::string func = "guiEvents::courtSelected()";

    logMsg(func +" begin");

    logMsg(func +" Selected Court #" +convert->toString(component->getCourtSelectBox()->getIndexSelected()));
//    gameS->setSelectedCourtDataInstance(courtSelectBox->getIndexSelected());
//    gameS->setActiveCourtInstance(courtSelectBox->getIndexSelected());
    //FIXME! needs reworked!
///    base->getGameS()->setActiveCourtInstance(courtSelectBox->getIndexSelected());
//    exit(0);
//    changeActiveMenu(TEAMSELECT);
//    teamSelectionMenu();

    logMsg(func +" end");

}

void guiEvents::teamsSelected()  // processes team selection
{
//    exit(0);
    //gameState *gameS = gameState::Instance();
    conversionSharedPtr convert ;
    teamEntityMSharedPtr activeTeamInstance;
//    teamEntityMSharedPtr teamInstance;
    setupTeamsSharedPtr setupTeam;
    std::string func = "GUISystem::teamsSelected()";

//    teamInstance = base->getGameS()->getTeamInstance();

    logMsg(func +" begin");

    sizeTVec teamID;
    teamID.push_back(component->getTeamSelectBox()[0]->getIndexSelected());
    teamID.push_back(component->getTeamSelectBox()[1]->getIndexSelected());
    logMsg(func +" activeTeamInstance");
    logMsg(func +" setupComplete == " +convert->toString(flag->getSetupComplete()));
    activeTeamInstance = setupTeam->createActiveTeamInstances(gameInstance->getComponent()->getTeamInstance(), teamID);
//    exit(0);
    //    gameS->setTeamID(teamID);
    logMsg(func +" teamSelectBox[0]->getIndexSelected() == " +convert->toString(component->getTeamSelectBox()[0]->getIndexSelected()));
    logMsg(func +" teamID[0] == " +convert->toString(teamID[0]));
//    exit(0);
    gameInstance->getData()->setTeamIDS(teamID);
    gameInstance->getComponent()->setActiveTeamInstance(activeTeamInstance);
    gameInstance->getFlag()->setActiveTeamInstancesCreated(true);

    logMsg(func +" Teams selected");

    logMsg(func +" end");

//    exit(0);
}

void guiEvents::playerStartSelected()  // process player start selection
{
    conversionSharedPtr convert ;
    std::vector<std::map <playerPositions, std::string> > teamStarters;
//    teamStarters.push_back(tempStarters);
    std::map<playerPositions, size_t> tempStarterID; // used for initial creatio  of teamStarterID vector
    teamEntityMSharedPtr activeTeamInstance = gameInstance->getComponent()->getActiveTeamInstance();

//    std::vector<playerStateMSharedPtr > playerInstance;
    playerEntityMSharedPtr gamePlayerInstance = gameInstance->getComponent()->getPlayerInstance();
    playerEntityVecMSharedPtr playerInstance;
//    std::unordered_map<std::string, playerStateSharedPtr> activePlayerInstance;
    playerEntityMSharedPtr activePlayerInstance;
//    std::unordered_map<playerPositions, playerEntitySharedPtr, std::hash<int> > activePlayerInstance;
    size_t IDs = 0;
    std::string func = "guiEvents::playerStartSelected()";

    setupLineupsSharedPtr setupLineup(new setupLineups);
    setupPlayersSharedPtr setupPlayer(new setupPlayers);
    logMsg(func +" begin");

    teamStarters = setupLineup->createTeamStarters(activeTeamInstance);  // create the teamStarters instance

///
/*    for (auto ATIIT : activeTeamInstance)  // loop through activeTeamInstance
    {
        teamStarters.push_back(tempStarters);  // add empty entry to teamStarters

        for (auto it : activeTeamInstance[ATIIT.first]->getPlayerInstance())
        {
            logMsg(func +" team dee " +convert->toString(ATIIT.first) +" " +it.second->getData()->getFirstName() +" " +it.second->getData()->getLastName());
        }
        playerInstance.insert(playerInstance.begin(), activeTeamInstance[ATIIT.first]->getPlayerInstance());  // add activeTeamInstances player instance to playerInstance

    }
*/
///
    logMsg(func +" teamStarters.size() == " +convert->toString(teamStarters.size()));
//    exit(0);

/*    playerEntityVecMSharedPtr::iterator PIIT;

    for (PIIT = playerInstance.begin(); PIIT != playerInstance.end(); ++PIIT)
    {
        for (auto it : *PIIT)
        {
            logMsg(func +" team dah " +it.second->getData()->getFirstName() +" " +it.second->getData()->getLastName());
        }
    }
*/
///
//    exit(0);
//    playerInstance = base->getGameS()->getActiveTeamInstance()[0]->getPlayerInstance();


/*    while (teamStarterID.size() < 2)
    {
        teamStarterID.push_back(starters);
    }
    while (teamStarterID[0].size() <5)
    {
        teamStarterID[0].push_back(IDs);
    }
    while (teamStarterID[1].size() <5)
    {
        teamStarterID[1].push_back(IDs);
    }
*/
    // checks to make sure that all player selectBoxes have a valid index value
    if (component->getTeamPlayerPosSelectBox()[0][PG]->getIndexSelected() < 0 || component->getTeamPlayerPosSelectBox()[0][PG]->getIndexSelected() > component->getTeamPlayerPosSelectBox()[0][PG]->getItemCount())
    {
        component->getTeamPlayerPosSelectBox()[0][PG]->setIndexSelected(0);
    }
    if (component->getTeamPlayerPosSelectBox()[0][SG]->getIndexSelected() < 0 || component->getTeamPlayerPosSelectBox()[0][SG]->getIndexSelected() > component->getTeamPlayerPosSelectBox()[0][SG]->getItemCount())
    {
        component->getTeamPlayerPosSelectBox()[0][SG]->setIndexSelected(0);
    }
    if (component->getTeamPlayerPosSelectBox()[0][SF]->getIndexSelected() < 0 || component->getTeamPlayerPosSelectBox()[0][SF]->getIndexSelected() > component->getTeamPlayerPosSelectBox()[0][SF]->getItemCount())
    {
        component->getTeamPlayerPosSelectBox()[0][SF]->setIndexSelected(0);
    }
    if (component->getTeamPlayerPosSelectBox()[0][PF]->getIndexSelected() < 0 || component->getTeamPlayerPosSelectBox()[0][PF]->getIndexSelected() > component->getTeamPlayerPosSelectBox()[0][PF]->getItemCount())
    {
        component->getTeamPlayerPosSelectBox()[0][PF]->setIndexSelected(0);
    }
    if (component->getTeamPlayerPosSelectBox()[0][C]->getIndexSelected() < 0 || component->getTeamPlayerPosSelectBox()[0][C]->getIndexSelected() > component->getTeamPlayerPosSelectBox()[0][C]->getItemCount())
    {
        component->getTeamPlayerPosSelectBox()[0][C]->setIndexSelected(0);
    }
    if (component->getTeamPlayerPosSelectBox()[1][PG]->getIndexSelected() < 0 || component->getTeamPlayerPosSelectBox()[1][PG]->getIndexSelected() > component->getTeamPlayerPosSelectBox()[1][PG]->getItemCount())
    {
        component->getTeamPlayerPosSelectBox()[1][PG]->setIndexSelected(0);
    }
    if (component->getTeamPlayerPosSelectBox()[1][SG]->getIndexSelected() < 0 || component->getTeamPlayerPosSelectBox()[1][SG]->getIndexSelected() > component->getTeamPlayerPosSelectBox()[1][SG]->getItemCount())
    {
        component->getTeamPlayerPosSelectBox()[1][SG]->setIndexSelected(0);
    }
    if (component->getTeamPlayerPosSelectBox()[1][SF]->getIndexSelected() < 0 || component->getTeamPlayerPosSelectBox()[1][SF]->getIndexSelected() > component->getTeamPlayerPosSelectBox()[1][SF]->getItemCount())
    {
        component->getTeamPlayerPosSelectBox()[1][SF]->setIndexSelected(0);
    }
    if (component->getTeamPlayerPosSelectBox()[1][PF]->getIndexSelected() < 0 || component->getTeamPlayerPosSelectBox()[1][PF]->getIndexSelected() > component->getTeamPlayerPosSelectBox()[1][PF]->getItemCount())
    {
        component->getTeamPlayerPosSelectBox()[1][PF]->setIndexSelected(0);
    }
    if (component->getTeamPlayerPosSelectBox()[1][C]->getIndexSelected() < 0 || component->getTeamPlayerPosSelectBox()[1][C]->getIndexSelected() > component->getTeamPlayerPosSelectBox()[1][C]->getItemCount())
    {
        component->getTeamPlayerPosSelectBox()[1][C]->setIndexSelected(0);
    }

    logMsg(func +" next");
    //FIXME! Should be converted into a loop to iterate

//    teamStarterID[0][0] = team0IDs[0][team0PGSelectBox->getIndexSelected()];
    auto w = 0;
//    std::vector<std::unordered_map <std::string, std::string> >::iterator TSIT;
//    for (TSIT = teamStarters.begin(); TSIT != teamStarters.end(); ++TSIT)

    std::vector<std::map <playerPositions, std::string> >::iterator TSVIT;
    logMsg(func +" teamStareters.size() == " +convert->toString(teamStarters.size()));

    for (TSVIT = teamStarters.begin(); TSVIT != teamStarters.end(); ++TSVIT)
    {
        logMsg(func + " TSVIT begin");
        TSVIT->insert(std::pair<playerPositions, std::string>(PG, component->getTeamPlayerPosSelectBox()[w][PG]->getItemNameAt(component->getTeamPlayerPosSelectBox()[w][PG]->getIndexSelected())));
        TSVIT->insert(std::pair<playerPositions, std::string>(SG, component->getTeamPlayerPosSelectBox()[w][SG]->getItemNameAt(component->getTeamPlayerPosSelectBox()[w][SG]->getIndexSelected())));
        TSVIT->insert(std::pair<playerPositions, std::string>(SF, component->getTeamPlayerPosSelectBox()[w][SF]->getItemNameAt(component->getTeamPlayerPosSelectBox()[w][SF]->getIndexSelected())));
        TSVIT->insert(std::pair<playerPositions, std::string>(PF, component->getTeamPlayerPosSelectBox()[w][PF]->getItemNameAt(component->getTeamPlayerPosSelectBox()[w][PF]->getIndexSelected())));
        TSVIT->insert(std::pair<playerPositions, std::string>(C, component->getTeamPlayerPosSelectBox()[w][C]->getItemNameAt(component->getTeamPlayerPosSelectBox()[w][C]->getIndexSelected())));
        ++w;
        logMsg(func +" TSVIT end");
    }
    logMsg(func +" woo woo");
    logMsg(func +" teamStarters.size() == " +convert->toString(teamStarters.size()));
    logMsg(func +" teamStarters[0][PG] == " +teamStarters[0][PG]);
//    exit(0);
    component->setTeamStarterID(setupLineup->createTeamStarterID(teamStarters,activeTeamInstance));  // creates the object with the each team's starter IDs

    logMsg(func +" teamStarterID.size() == " +convert->toString(component->getTeamStarterID().size()));
//    exit(0);
/*    std::unordered_map<std::string, size_t> tempStarterID;

    while (teamStarterID.size() < 2)
    {
        teamStarterID.push_back(tempStarterID);
    }
    logMsg("teamStarterID.size() == " +convert->toString(teamStarterID.size()));
    exit(0);
    w = 0;
    std::vector<std::unordered_map<std::string, size_t> >::iterator TSIDIT;
    std::vector<std::unordered_map <std::string, std::string> > TSIT;
    for (TSIDIT = teamStarterID.begin(); TSIDIT != teamStarterID.end(); ++TSIDIT)
    {
//        TSIDIT.push_back();
//        TSIDIT.insert(std::pair<std::string, size_t>("PG", PIIT.second->getData()->getID()));

    }
*/

///
/*    for (TSVIT = teamStarters.begin(); TSVIT != teamStarters.end(); ++TSVIT)  // loop that adds starting player IDs to teamStarterID
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
    std::vector<std::unordered_map<std::string, size_t> >::iterator TSIDIT;

    for (TSIDIT = teamStarterID.begin(); TSIDIT != teamStarterID.end(); ++TSIDIT)
    {
        for (auto TSIDUIT : *TSIDIT)
        {
            logMsg(func +" TSIDUIT.first == " +TSIDUIT.first +" TSIDUIT.second == " +convert->toString(TSIDUIT.second));

        }
    }
    logMsg(func +" teamStarterID.size() == " +convert->toString(teamStarterID.size()));
*/
///
    logMsg(func +" dgg");
//    exit(0);
/*        for (auto TSVUIT : *TSVIT)
        {
            for (TSIDIT = teamStarterID.begin(); TSIDIT != teamStarterID.end(); ++TSIDIT)
            {
                for (auto TSIDUIT : *TSIDIT)
                {
            for (auto PIIT : playerInstance[w])
            {
                std::string playerName = PIIT.second->getData()->getFirstName() +" " +PIIT.second->getData()->getLastName();
                logMsg(func +" playerInstance playerName == " +playerName);
                logMsg(func +" Primary Position == " +convert->toString(PIIT.second->getData()->getPrimaryPosition()));
                logMsg(func +" Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                auto y = 0;

                if (playerName == TSVUIT.second && TSVUIT.first == "PG")
                {

                    logMsg(func +" PG Player ID == " +convert->toString(PIIT.second->getData()->getID()));
//                    TSIDUIT.insert(std::pair<std::string, size_t>("PG", PIIT.second->getData()->getID()));
                }
                else if (playerName == TSVUIT.second && TSVUIT.first == "SG")
                {
                    logMsg(func +" SG Player ID == " +convert->toString(PIIT.second->getData()->getID()));

                    teamStarterID[w].insert(std::pair<std::string, size_t>("SG", PIIT.second->getData()->getID()));
    //                logMsg("teamStarterID[w][SG] Player ID == " +convert->toString(teamStarterID[w][SG]));

                }
                else if (playerName == TSVUIT.second && TSVUIT.first == "SF")
                {
                    logMsg(func +" SF Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                    teamStarterID[w].insert(std::pair<std::string, size_t>("SF", PIIT.second->getData()->getID()));
                }
                else if (playerName == TSVUIT.second && TSVUIT.first == "PF")
                {
                    logMsg(func +" PF Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                    teamStarterID[w].insert(std::pair<std::string, size_t>("PF", PIIT.second->getData()->getID()));
                }
                else if (playerName == TSVUIT.second && TSVUIT.first == "C")
                {
                    logMsg(func +" C Player ID == " +convert->toString(PIIT.second->getData()->getID()));
                    teamStarterID[w].insert(std::pair<std::string, size_t>("C", PIIT.second->getData()->getID()));
                }
    //            ++x;
            }
                }
            }
        }
        ++w;
    }
*/
    //    teamStarterID[0][0] = [
                          //team0IDs[0][teamPlayerPosSelectBox[0]["PG"]->getIndexSelected()];

    logMsg(func +" teamStarterID[0][PG] = " +convert->toString(component->getTeamStarterID()[0][PG]));
    logMsg(func +" teamStarterID[0][SG] = " +convert->toString(component->getTeamStarterID()[0][SG]));
    logMsg(func +" teamStarterID[0][SF] = " +convert->toString(component->getTeamStarterID()[0][SF]));
    logMsg(func +" teamStarterID[0][PF] = " +convert->toString(component->getTeamStarterID()[0][PF]));
    logMsg(func +" teamStarterID[0][C] = " +convert->toString(component->getTeamStarterID()[0][C]));

//    exit(0);
/*    team0Starters.push_back(teamPlayerPosSelectBox[0]["SG"]->getItemNameAt(teamPlayerPosSelectBox[0]["SG"]->getIndexSelected()));
    teamStarterID[0][1] = team0IDs[1][teamPlayerPosSelectBox[0]["SG"]->getIndexSelected()];
    logMsg("teamStarterID[0][1] = " +convert->toString(teamStarterID[0][1]));
    team0Starters.push_back(teamPlayerPosSelectBox[0]["SF"]->getItemNameAt(teamPlayerPosSelectBox[0]["SF"]->getIndexSelected()));
    teamStarterID[0][2] = team0IDs[2][teamPlayerPosSelectBox[0]["SF"]->getIndexSelected()];
    logMsg("teamStarterID[0][2] = " +convert->toString(teamStarterID[0][2]));
    team0Starters.push_back(teamPlayerPosSelectBox[0]["PF"]->getItemNameAt(teamPlayerPosSelectBox[0]["PF"]->getIndexSelected()));
    teamStarterID[0][3] = team0IDs[3][teamPlayerPosSelectBox[0]["SF"]->getIndexSelected()];
    logMsg("teamStarterID[0][3] = " +convert->toString(teamStarterID[0][3]));
    team0Starters.push_back(teamPlayerPosSelectBox[0]["C"]->getItemNameAt(teamPlayerPosSelectBox[0]["C"]->getIndexSelected()));
    teamStarterID[0][4] = team0IDs[4][teamPlayerPosSelectBox[0]["C"]->getIndexSelected()];
    logMsg("teamStarterID[0][4] = " +convert->toString(teamStarterID[0][4]));
    team1Starters.push_back(teamPlayerPosSelectBox[1]["PG"]->getItemNameAt(teamPlayerPosSelectBox[1]["PG"]->getIndexSelected()));
    teamStarterID[1][0] = team1IDs[0][teamPlayerPosSelectBox[1]["PG"]->getIndexSelected()];
    logMsg("teamStarterID[1][0] = " +convert->toString(teamStarterID[1][0]));
    team1Starters.push_back(teamPlayerPosSelectBox[1]["SG"]->getItemNameAt(teamPlayerPosSelectBox[1]["SG"]->getIndexSelected()));
    teamStarterID[1][1] = team1IDs[1][teamPlayerPosSelectBox[1]["SG"]->getIndexSelected()];
    logMsg("teamStarterID[1][1] = " +convert->toString(teamStarterID[1][1]));
    team1Starters.push_back(teamPlayerPosSelectBox[1]["SF"]->getItemNameAt(teamPlayerPosSelectBox[1]["SF"]->getIndexSelected()));
    teamStarterID[1][2] = team1IDs[2][teamPlayerPosSelectBox[1]["SF"]->getIndexSelected()];
    logMsg("teamStarterID[1][2] = " +convert->toString(teamStarterID[1][2]));
    team1Starters.push_back(teamPlayerPosSelectBox[1]["PF"]->getItemNameAt(teamPlayerPosSelectBox[1]["PF"]->getIndexSelected()));
    teamStarterID[1][3] = team1IDs[3][teamPlayerPosSelectBox[1]["PF"]->getIndexSelected()];
    logMsg("teamStarterID[1][3] = " +convert->toString(teamStarterID[1][3]));
    team1Starters.push_back(teamPlayerPosSelectBox[1]["C"]->getItemNameAt(teamPlayerPosSelectBox[1]["C"]->getIndexSelected()));
    teamStarterID[1][4] = team1IDs[4][teamPlayerPosSelectBox[1]["C"]->getIndexSelected()];
    logMsg("teamStarterID[1][4] = " +convert->toString(teamStarterID[1][4]));
*/
//    exit(0);
//    gameS->setTeamStarterID(teamStarterID); // sets the selected starters for both teams in gameState class
    gameInstance->getData()->setTeamStarterID(component->getTeamStarterID()); // sets the selected starters for both teams in gameState class

    sizeTVec activePlayerID;
//    x = 0;
    logMsg(func +" activePlayerID!");
/*    while (x < 5)
    {
        activePlayerID.push_back(teamStarterID[0][x]);
        logMsg("activePlayerID = " +convert->toString(activePlayerID[x]));
        ++x;
    }
*/
//    exit(0);

///
/*    base->getGameS()->getActiveTeamInstance()[0]->setActivePlayerID(activePlayerID);

    logMsg(func +" activeTeamInstance.size() == " +convert->toString(activeTeamInstance.size()));
    for (auto ATIIT : activeTeamInstance)
    {
        logMsg("ATIIT.second->getPlayerInstancesCreated() == " +convert->toString(ATIIT.second->getPlayerInstancesCreated()));
        if (!ATIIT.second->getPlayerInstancesCreated())    // checks if playerInstances have been created
        {
            logMsg(func +" activeTeamInstance " +convert->toString(ATIIT.first) +" Player Instances NOT Created!");
//            exit(0);
            if( ATIIT.second->createPlayerInstances())
            {
                ATIIT.second->setPlayerInstancesCreated(true);
                base->getGameS()->setActiveTeamInstance(activeTeamInstance);
                logMsg("activeTeamInstance " +convert->toString(ATIIT.first) + " Player Instances Created Successfully!");
            }
            else
            {
                logMsg("activeTeamInstance " +convert->toString(ATIIT.first) + " Player Instances NOT CREATED!");
                exit(0);
            }
//            base->getGameS()->getActiveTeamInstance()[0]->setBase(base);
//            if (base->getGameS()->getActiveTeamInstance()[0]->createPlayerInstances()) // creates the player instances based on playerIDS
//            {
//                logMsg(func +" Team 0 Player instances created!");
//                base->getGameS()->getActiveTeamInstance()[0]->setPlayerInstancesCreated(true);
    //          exit(0);
//            }

        }
    }
*/
///

    setupPlayer->checkIfTeamPlayerInstancesCreated(gamePlayerInstance, activeTeamInstance);
    // create active player Instancea

///
/*    for (auto ATIIT : activeTeamInstance)
    {
        logMsg(func +" ATIIT.first == " +convert->toString(ATIIT.first));
//        activePlayerInstance.clear();

        for (auto PIIT : ATIIT.second->getPlayerInstance())
        {
            logMsg(func +" ATIIT.first == " +convert->toString(ATIIT.first) +" PIIT.second->getData()->getID() == " +convert->toString(PIIT.second->getData()->getID()) +" primaryPosition == " +convert->toString(PIIT.second->getData()->getPrimaryPosition()));
            std::string teamStarterIDPG = convert->toString(teamStarterID[0]["PG"]);
            logMsg("teamStarterID[ATIIT.first][PG] == " +teamStarterIDPG);
            logMsg("playerInstance ID == " +convert->toString(PIIT.second->getData()->getID()));

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
    }  */
///
    activeTeamInstance = setupLineup->setupStartingLineups(activeTeamInstance, component->getTeamStarterID());

    gameInstance->getComponent()->setActiveTeamInstance(activeTeamInstance);
//    exit(0);
//    playerInstance.clear();
//    activePlayerInstance.clear();
/*    playerInstance = base->getGameS()->getActiveTeamInstance()[0]->getPlayerInstance();
    auto y = 0;
    logMsg("GUI playerInstance.size() = " +convert->toString(playerInstance.size()));

    while (y < playerInstance.size())
    {
        auto z = 0;
        while (z < activePlayerID.size())
        {
            if (playerInstance[y].get()->getID() == activePlayerID[z])
            {
                activePlayerInstance.insert(std::pair<size_t, playerStateSharedPtr>(y,playerInstance[y]));
                logMsg("GUI playerInstance[y] ID  = " +convert->toString(playerInstance[y]->getID()));

            }
            ++z;
        }
        ++y;
    }
//    exit(0);
    logMsg("GUI activePlayerInstance.size() = " +convert->toString(activePlayerInstance.size()));
    base->getGameS()->getActiveTeamInstance()[0]->setActivePlayerInstance(activePlayerInstance);
    base->getGameS()->getActiveTeamInstance()[0]->setPlayerStartActivePositions();

    base->getGameS()->getActiveTeamInstance()[0]->setPlayerStartPositions();
//    logMsg("Team 0 player start positions set");
//    exit(0);
    size_t i = 0;
    //playerStateVec playerInstance;
    playerInstance.clear();
    playerInstance = base->getGameS()->getActiveTeamInstance()[0]->getPlayerInstance();
    while (i<playerInstance.size())
    {
        if (activePlayerID[4] == playerInstance[i]->getID())
        {
            base->getGameS()->getActiveTeamInstance()[0]->setHumanPlayer(i);
            logMsg("human player set!");
        }
        i++;
    }

    activePlayerID.clear();
    for (size_t x=0;x<5;++x)
    {
        activePlayerID.push_back(teamStarterID[1][x]);
    }

    base->getGameS()->getActiveTeamInstance()[1]->setActivePlayerID(activePlayerID);
    if (!base->getGameS()->getActiveTeamInstance()[1]->getPlayerInstancesCreated())  // checks if playerInstances have been created
    {
        logMsg("Creating team 1 player instances");
//            exit(0);
        base->getGameS()->getActiveTeamInstance()[1]->setBase(base);

        if (base->getGameS()->getActiveTeamInstance()[1]->createPlayerInstances())  // creates the player instances based on playerIDS
        {
//            exit(0);

            logMsg("Player instances created!");
            base->getGameS()->getActiveTeamInstance()[1]->setPlayerInstancesCreated(true);
//          exit(0);
        }
//.        exit(0);

    }
    playerInstance.clear();
    playerInstance = base->getGameS()->getActiveTeamInstance()[1]->getPlayerInstance();
    activePlayerInstance.clear();
    y = 0;
    while (y < playerInstance.size())
    {
        size_t z = 0;
        while (z < activePlayerID.size())
        {
            if (playerInstance[y]->getID() == activePlayerID[z])
            {
                activePlayerInstance.insert(std::pair<size_t, playerStateSharedPtr>(y, playerInstance[y]));
            }
            ++z;
        }
        ++y;
    }

    base->getGameS()->getActiveTeamInstance()[1]->setActivePlayerInstance(activePlayerInstance);
    base->getGameS()->getActiveTeamInstance()[1]->setPlayerStartActivePositions();
    base->getGameS()->getActiveTeamInstance()[1]->setPlayerStartPositions();
    logMsg("Team 1 player start positions set");
    playerInstance = base->getGameS()->getActiveTeamInstance()[1]->getPlayerInstance();
    while (i<playerInstance.size())
    {
        if (activePlayerID[4] == playerInstance[i]->getID())
        {
            base->getGameS()->getActiveTeamInstance()[1]->setHumanPlayer(i);
            logMsg("human player set!");
        }
        i++;
    }
    */


///
/*    if (base->getGameS()->getActiveTeamInstance()[0]->getPlayerInstancesCreated() && base->getGameS()->getActiveTeamInstance()[1]->getPlayerInstancesCreated())
    {
///        base->getGameS()->setActiveTeamInstance(activeTeamInstance);  // sets the activeTeamInstance vector
//        base->getGameS()->setSetupComplete(true);
        base->getGameS()->setSetupComplete(true);

    }
    else
    {
        logMsg("Team Instances NOT created!");
        exit(0);
    }*/
///

    for (auto ATIIT : activeTeamInstance)
    {
        logMsg(func +"ATIIT activePlayerInstance size = " +convert->toString(ATIIT.second->getComponent()->getActivePlayerInstance().size()));
    }
//    exit(0);

    if (setupLineup->checkActivePlayerInstancesCreated(activeTeamInstance))
    {
        logMsg("All active player instances created successfully!");
        gameInstance->getFlag()->setSetupComplete(true);

//        exit(0);
    }
    else
    {
        logMsg("Unable to create all active player instances!");
        exit(0);
    }
/*    logMsg("team 0 C selectbox id = " +convert->toString(teamStarterID[0][1]));
    logMsg("team 0 starter 0 = " +convert->toString(teamStarterID[0][0]));
    logMsg("team  0 starter 0 = " +team0Starters[0]);
*/
//        exit(0);

    display->hideActiveMenuWidgets();
    flag->setMenuActive(false);
    gameE->setMenuActive(false);

//    exit(0);

}

void guiEvents::hostGame()  // hosts a network game
{
    std::string func = "guiEvents::hostGame()";

    logMsg(func +" begin");

    gameInstance->getData()->setGameType(MULTINET);
//   hideNetworkSetupWidgets();  // Hides Network Setup Menu widgets
    flag->setMenuActive(false);
    gameE->getNetworkE()->setIPAddress(component->getServerIPAddressBox()->getCaption());  // sets the neworkEngine's ipAddress string to that of the caption
    logMsg("server ip = " +gameE->getNetworkE()->getIPAddress());
    if (gameE->getNetworkE()->serverSetup())  // attempts to setup as a network server
    {
        gameE->getNetworkE()->setIsServer(true);  // if successful sets isServer to true
    }
    logMsg(func +" end");

}
void guiEvents::connectGame()  // connects toa  network game
{
    std::string func = "guiEvents::connectGame()";

    logMsg(func +" begin");

    gameInstance->getData()->setGameType(MULTINET);
//    hideNetworkSetupWidgets();  // Hides Network Setup Menu widgets
    flag->setMenuActive(false);
    gameE->getNetworkE()->setIPAddress(component->getClientIPAddressBox()->getCaption());  // sets the neworkEngine's ipAddress string to that of the caption
//    network->networkClient();
    if (gameE->getNetworkE()->clientConnect()) // attempts to connect to the remote server
    {
        gameE->getNetworkE()->setIsClient(true);  // if successful sets isClient to true
    }
    logMsg(func +" end");

}

void guiEvents::setSelectedIndexes()  // sets all player listbox indexes to zero
{
    MyGUIPlayerListBoxVecMSharedPtr tempPlayerPosSelectBox;
    std::string func = "guiEvents::setSelectedIndexes()";

    logMsg(func +" begin");
    
    tempPlayerPosSelectBox = component->getTeamPlayerPosSelectBox();
//    exit(0);
    tempPlayerPosSelectBox[0][PG]->setIndexSelected(0);
    
    logMsg(func +" PG0");

    tempPlayerPosSelectBox[0][SG]->setIndexSelected(0);
    tempPlayerPosSelectBox[0][SF]->setIndexSelected(0);
    tempPlayerPosSelectBox[0][PF]->setIndexSelected(0);
    tempPlayerPosSelectBox[0][C]->setIndexSelected(0);
    tempPlayerPosSelectBox[1][PG]->setIndexSelected(0);
    tempPlayerPosSelectBox[1][SG]->setIndexSelected(0);
    tempPlayerPosSelectBox[1][SF]->setIndexSelected(0);
    tempPlayerPosSelectBox[1][PF]->setIndexSelected(0);
    tempPlayerPosSelectBox[1][C]->setIndexSelected(0);

    component->setTeamPlayerPosSelectBox(tempPlayerPosSelectBox);

    logMsg(func +" end");

}
