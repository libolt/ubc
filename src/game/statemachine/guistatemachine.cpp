/***************************************************************************
 *   Copyright (C) 1999 - 2019 by Mike McLean                              *
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

#include "statemachine/guistatemachine.h"
#include "components/gamecomponents.h"
#include "components/guicomponents.h"
#include "entity/gameentity.h"
#include "flags/gameflags.h"
#include "flags/guiflags.h"
#include "gui/guicreate.h"
#include "gui/guidata.h"
#include "gui/guidisplay.h"
#include "gui/guievents.h"
#include "gui/guiinput.h"
#include "setup/setupteams.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

guiStateMachine::guiStateMachine() :
    stateMachine(ST_MAX_STATES)
{
}

// Initialize state machine external event
void guiStateMachine::pInitialize(const guiSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_MAIN_MENU
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_NETWORK_MENU
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_NETWORKCLIENT_MENU
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_NETWORKSERVER_MENU
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_COURT_MENU
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_TEAM_MENU
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_STARTERS_MENU
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_OPTIONS_MENU
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_AUDIO_MENU
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_DISPLAY_MENU
        TRANSITION_MAP_ENTRY (ST_INITIALIZE)                // ST_INPUT_MENU
    END_TRANSITION_MAP(data)
}

void guiStateMachine::pMainMenu(const guiSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_MAIN_MENU)                // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_MAIN_MENU
        TRANSITION_MAP_ENTRY (ST_MAIN_MENU)                // ST_NETWORK_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_NETWORKCLIENT_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_NETWORKSERVER_MENU
        TRANSITION_MAP_ENTRY (ST_MAIN_MENU)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_MAIN_MENU)                // ST_COURT_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_TEAM_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_STARTERS_MENU
        TRANSITION_MAP_ENTRY (ST_MAIN_MENU)                // ST_OPTIONS_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_AUDIO_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_DISPLAY_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_INPUT_MENU
    END_TRANSITION_MAP(data)
}

void guiStateMachine::pNetworkMenu(const guiSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_NETWORK_MENU)              // ST_MAIN_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_NETWORK_MENU
        TRANSITION_MAP_ENTRY (ST_NETWORK_MENU)              // ST_NETWORKCLIENT_MENU
        TRANSITION_MAP_ENTRY (ST_NETWORK_MENU)              // ST_NETWORKSERVER_MENU
        TRANSITION_MAP_ENTRY (ST_NETWORK_MENU)              // ST_IDLE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_COURT_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_TEAM_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_STARTERS_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_OPTIONS_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_AUDIO_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_DISPLAY_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_INPUT_MENU
    END_TRANSITION_MAP(data)
}

void guiStateMachine::pNetworkClientMenu(const guiSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_MAIN_MENU
        TRANSITION_MAP_ENTRY (ST_NETWORKCLIENT_MENU)                // ST_NETWORK_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_NETWORKCLIENT_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_NETWORKSERVER_MENU
        TRANSITION_MAP_ENTRY (ST_NETWORKCLIENT_MENU)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_NETWORKCLIENT_MENU)                // ST_COURT_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_TEAM_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_STARTERS_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_OPTIONS_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_AUDIO_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_DISPLAY_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_INPUT_MENU
    END_TRANSITION_MAP(data)
}

void guiStateMachine::pNetworkServerMenu(const guiSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_MAIN_MENU
        TRANSITION_MAP_ENTRY (ST_NETWORKSERVER_MENU)                // ST_NETWORK_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_NETWORKCLIENT_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_NETWORKSERVER_MENU
        TRANSITION_MAP_ENTRY (ST_NETWORKSERVER_MENU)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_NETWORKSERVER_MENU)                // ST_COURT_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_TEAM_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_STARTERS_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_OPTIONS_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_AUDIO_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_DISPLAY_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_INPUT_MENU
    END_TRANSITION_MAP(data)
}
void guiStateMachine::pStartSinglePlayerGame(const guiSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (ST_COURT_MENU)                // ST_MAIN_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_NETWORK_MENU
        TRANSITION_MAP_ENTRY (ST_COURT_MENU)                // ST_NETWORKCLIENT_MENU
        TRANSITION_MAP_ENTRY (ST_COURT_MENU)                // ST_NETWORKSERVER_MENU
        TRANSITION_MAP_ENTRY (ST_COURT_MENU)                // ST_IDLE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_COURT_MENU
        TRANSITION_MAP_ENTRY (ST_COURT_MENU)                // ST_TEAM_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_STARTERS_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_OPTIONS_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_AUDIO_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_DISPLAY_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_INPUT_MENU
    END_TRANSITION_MAP(data)
}

void guiStateMachine::pStartersMenu(guiSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_MAIN_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_NETWORK_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_NETWORKCLIENT_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_NETWORKSERVER_MENU
        TRANSITION_MAP_ENTRY (ST_STARTERS_MENU)                // ST_IDLE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_COURT_MENU
        TRANSITION_MAP_ENTRY (ST_STARTERS_MENU)                // ST_TEAM_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_STARTERS_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_OPTIONS_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_AUDIO_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_DISPLAY_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_INPUT_MENU
    END_TRANSITION_MAP(data)
}
void guiStateMachine::pTeamMenu(guiSMData *data)
{
    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_INITIALIZE
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_MAIN_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_NETWORK_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_NETWORKCLIENT_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_NETWORKSERVER_MENU
        TRANSITION_MAP_ENTRY (ST_TEAM_MENU)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_TEAM_MENU)                // ST_COURT_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_TEAM_MENU
        TRANSITION_MAP_ENTRY (ST_TEAM_MENU)                // ST_STARTERS_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_OPTIONS_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_AUDIO_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_DISPLAY_MENU
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_INPUT_MENU
    END_TRANSITION_MAP(data)
}

// Initialize the state machine
STATE_DEFINE(guiStateMachine, Initialize, guiSMData)
{
    std::string func = "guiStateMachine::Initialize()";

    logMsg(func +" begin");


    
    logMsg(func +" end");
}

// Main Menu
STATE_DEFINE(guiStateMachine, MainMenu, guiSMData)
{
    conversionSharedPtr convert;
    std::string func = "guiStateMachine::MainMenu()";

    logMsg(func +" begin");

    guiFlagsSharedPtr flag = data->flag;
    
    logMsg(func +" mainMenu created?");

    if (!flag->getMainMenuCreated())
    {
        logMsg(func + " mainMenu not created yet!");
//        exit(0);
/*        data->create->setFlag(flag);
        logMsg(func +" Flag set!");
        data->create->setComponent(data->component);
        logMsg(func +" Component set!");
*/
        if (data->create->createMainMenuGUI(data->render)) // creates the main menu gui.
        {
            logMsg(func + " Main Menu created successfully!");
            flag->setMainMenuCreated(true);
//            exit(0);
        }
        else
        {
            logMsg(func + " Unable to create Main Menu!");
            exit(0);
        }
    }
    else
    {
        
    }
    logMsg(func +"tempSMData");

    guiSMData *tempSMData(new guiSMData);
    tempSMData->component = data->component;
    tempSMData->create = data->create;
    tempSMData->display = data->display;
    tempSMData->flag= flag;
    data = tempSMData;
    
    logMsg(func +"showMainMenuWidgets?");

    data->display->setComponent(data->component);
    data->display->showMainMenuWidgets();  // displays main menu
    if (!data->flag->getMenuActive())
    {
        data->flag->setMenuActive(true);
    }
    
    data->component->setActiveMenu(MAIN);
    
    logMsg(func +" end");
}

// Network Menu
STATE_DEFINE(guiStateMachine, NetworkMenu, guiSMData)
{
    std::string func = "guiStateMachine::NetworkMenu()";
    guiComponentsSharedPtr component = data->component;
    guiCreateSharedPtr create = data->create;
    guiDataSharedPtr gData = data->gData;
    guiDisplaySharedPtr display = data->display;
    guiFlagsSharedPtr flag = data->flag;
    guiInputSharedPtr input = data->input;
    renderEngineSharedPtr render = data->render;

    logMsg(func +" begin");
    if (!flag->getNetworkSetupMenuCreated())
    {
        create->createNetworkSetupGUI(render);  // creates the GUI for the Network Setup Screen
    }

    display->changeActiveMenu(NETWORK, render);

    guiSMData *tempSMData(new guiSMData);
    tempSMData->component = data->component;
    tempSMData->create = data->create;
    tempSMData->gData = data->gData;
    tempSMData->display = data->display;
    tempSMData->flag = flag;
    tempSMData->input = input;
    tempSMData->render = render;
    data = tempSMData;

    logMsg(func +" end");
}

// Network Client Menu
STATE_DEFINE(guiStateMachine, NetworkClientMenu, guiSMData)
{
    std::string func = "guiStateMachine::NetworkClientMenu()";

    guiComponentsSharedPtr component = data->component;
    guiCreateSharedPtr create = data->create;
    guiDataSharedPtr gData = data->gData;
    guiDisplaySharedPtr display = data->display;
    guiFlagsSharedPtr flag = data->flag;
    guiInputSharedPtr input = data->input;
    renderEngineSharedPtr render = data->render;

    logMsg(func +" begin");

    if (!flag->getNetworkClientSetupMenuCreated())
    {
        create->createNetworkClientSetupGUI(render);
    }
    display->changeActiveMenu(NETWORKCLIENT, render);
    MyGUI::InputManager::getInstance().setKeyFocusWidget(component->getClientIPAddressBox().get());

    guiSMData *tempSMData(new guiSMData);
    tempSMData->component = data->component;
    tempSMData->create = data->create;
    tempSMData->gData = data->gData;
    tempSMData->display = data->display;
    tempSMData->flag = flag;
    tempSMData->input = input;
    tempSMData->render = render;
    data = tempSMData;
    
    logMsg(func +" end");
}

// NetworkServerMenu
STATE_DEFINE(guiStateMachine, NetworkServerMenu, guiSMData)
{
    std::string func = "guiStateMachine::NetworkServerMenu()";

    guiComponentsSharedPtr component = data->component;
    guiCreateSharedPtr create = data->create;
    guiDataSharedPtr gData = data->gData;
    guiDisplaySharedPtr display = data->display;
    guiFlagsSharedPtr flag = data->flag;
    guiInputSharedPtr input = data->input;
    renderEngineSharedPtr render = data->render;

    logMsg(func +" begin");

    if (!flag->getNetworkServerSetupMenuCreated())
    {
        create->createNetworkServerSetupGUI(render);
    }

    display->changeActiveMenu(NETWORKSERVER, render);
    MyGUI::InputManager::getInstance().setKeyFocusWidget(component->getServerIPAddressBox().get());

    guiSMData *tempSMData(new guiSMData);
    tempSMData->component = data->component;
    tempSMData->create = data->create;
    tempSMData->gData = data->gData;
    tempSMData->display = data->display;
    tempSMData->flag = flag;
    tempSMData->input = input;
    tempSMData->render = render;
    data = tempSMData;

    logMsg(func +" end");
}

// Idle
STATE_DEFINE(guiStateMachine, Idle, noEventData)
{
    std::string func = "guiStateMachine::Idle()";

    logMsg(func +" begin");

    logMsg(func +" end");
}

// CourtMenu
STATE_DEFINE(guiStateMachine, CourtMenu, guiSMData)
{
    conversionSharedPtr convert ;
//    sharedPtr<loader> load; // = loader::Instance();
    std::string func = "guiStateMachine::CourtMenu()";
    
    logMsg(func +" begin");
    
    guiComponentsSharedPtr component = data->component;
    guiCreateSharedPtr create = data->create;
    guiDataSharedPtr gData = data->gData;
    guiDisplaySharedPtr display = data->display;
    guiFlagsSharedPtr flag = data->flag;
    guiInputSharedPtr input = data->input;
    renderEngineSharedPtr render = data->render;

    if (!flag->getCourtSelectionMenuCreated())
    {
        create->createCourtSelectionMenuGUI(data->render);
    }
//    exit(0);
    if (!flag->getCourtSelectionDataLoaded())
    {
//        exit(0);
        gData->setGameInstance(data->gameInstance);

        logMsg("gData->addCourtSelectionMenuData = " +convert->toString(gData->addCourtSelectionMenuData()));
//        exit(0);
        if (gData->addCourtSelectionMenuData())
        {
//            exit(0);
            component->getCourtSelectBox()->setIndexSelected(0);
            flag->setCourtSelectionDataLoaded(true);
        }
        else
        {
            exit(0);

        }
//        exit(0);
    }

    guiSMData *tempSMData(new guiSMData);
    tempSMData->component = data->component;
    tempSMData->create = data->create;
    tempSMData->gData = data->gData;
    tempSMData->display = data->display;
    tempSMData->flag = flag;
    tempSMData->input = input;
    tempSMData->render = render;
    data = tempSMData;

    logMsg(func +" component initialized == " +convert->toString(component->getInitialized()));
    display->setComponent(component);
    display->changeActiveMenu(COURTSELECT, data->render);
//    exit(0);
    
    logMsg(func +" end");
}

// TeamMenu
STATE_DEFINE(guiStateMachine, TeamMenu, guiSMData)
{
    conversionSharedPtr convert ;
    setupTeamsSharedPtr setupTeam(new setupTeams);
    bool changeMenu = false;  // determinrs if menu is to be changed
    teamEntityMSharedPtr teamInstance; // = gameS->getTeamDataInstance();
    std::string func = "guiStateMachine::TeamMenu()";

    guiComponentsSharedPtr component = data->component;
    guiCreateSharedPtr create = data->create;
    guiDataSharedPtr gData = data->gData;
    guiDisplaySharedPtr display = data->display;
    guiFlagsSharedPtr flag = data->flag;
    guiInputSharedPtr input = data->input;
    gameEntitySharedPtr gameInstance = data->gameInstance;
    renderEngineSharedPtr render = data->render;
    logMsg(func +" begin");

    if (flag->getTeamSelectionMenuCreated())
    {
        logMsg(func +" teamSelectionMenuCreated");
        exit(0);
        if (gameInstance->getFlag()->getTeamInstancesCreated())
        {
            logMsg(func +" getTeamInstancesCreated");
//            exit(0);
            if (flag->getTeamSelectionMenuDataAdded())
            {
                logMsg(func +" Team Selection Menu Data Added already!");
                changeMenu = true;
            }
            else
            {
                if (gData->addTeamStartSelectionMenuData())
                {
                    flag->setTeamSelectionMenuDataAdded(true);
                    changeMenu = true;

                }
                else
                {
                    logMsg(func +" Unable to add data to Team Selection Menus!");
                    exit(0);
                }
            }
        }
        else
        {
            logMsg(func +" !getTeamInstancesCreated");

            teamInstance = setupTeam->createTeamInstances();  // creates team instances
            if (!teamInstance.empty())
            {
                logMsg(func +" createTeamInstances");

//                exit(0);
                gameInstance->getFlag()->setTeamInstancesCreated(true);
                if (flag->getTeamSelectionMenuDataAdded())
                {
                    logMsg(func +" Team Selection Menu Data Added already!");
                    changeMenu = true;
                }
                else
                {
                    if (gData->addTeamStartSelectionMenuData())
                    {
                        flag->setTeamSelectionMenuDataAdded(true);
                        changeMenu = true;
                    }
                    else
                    {
                        logMsg(func +" Unable to add data to Team Selection Menus!");
                        exit(0);
                    }
                }
            }
            else
            {
                logMsg(func +" feeerrrrappp!");
                exit(0);
            }
        }
    }
    else
    {
        logMsg(func +" teamSelectionMenuGUI Not Yet Created!");

        if (create->createTeamSelectionMenuGUI(render))
        {
            flag->setTeamSelectionMenuCreated(true);

            if (gData->addTeamStartSelectionMenuData())
            {

                logMsg(func +" addTeamStartSelectionMenuData()!");
                logMsg(func +" teamInstance.size() == " +convert->toString(gameInstance->getComponent()->getTeamInstance().size()));
//                exit(0);
                flag->setTeamSelectionMenuDataAdded(true);
                changeMenu = true;
            }
            else
            {
                logMsg(func +" Unable to add data to Team Selection Menus!");
                exit(0);
            }
        }
        else
        {
            logMsg(func +" Unable to create Team Selection Menu!");
            exit(0);
        }
    }

//    hideCourtSelectionMenuWidgets();
    if (changeMenu)
    {
        logMsg(func +" Changing activeMenu to TEAMSELECT!");
//        exit(0);
        display->changeActiveMenu(TEAMSELECT, render);
    }
    else
    {
        logMsg(func +" Failed to change activeMenu to TEAMSELECT!");
        exit(0);
    }

    logMsg(func +" teamInstance.size() == " +convert->toString(gameInstance->getComponent()->getTeamInstance().size()));

    guiSMData *tempSMData(new guiSMData);
    tempSMData->component = data->component;
    tempSMData->create = data->create;
    tempSMData->gData = data->gData;
    tempSMData->display = data->display;
    tempSMData->flag = flag;
    tempSMData->input = input;
    tempSMData->gameInstance = gameInstance;
    tempSMData->render = render;
    data = tempSMData;

    logMsg(func +" end");
}

// StartersMenu
STATE_DEFINE(guiStateMachine, StartersMenu, guiSMData)
{
    std::string func = "guiStateMachine::StartersMenu()";
    guiComponentsSharedPtr component = data->component;
    guiCreateSharedPtr create = data->create;
    guiDataSharedPtr gData = data->gData;
    guiDisplaySharedPtr display = data->display;
    guiEventsSharedPtr event = data->event;
    guiFlagsSharedPtr flag = data->flag;
    guiInputSharedPtr input = data->input;
    renderEngineSharedPtr render = data->render;

    logMsg(func +" begin");
    
    if (!flag->getPlayerStartSelectionMenuCreated())
    {
        logMsg(func +" !playerStartSelectionMenuCreated");
//         exit(0);
        
        if (create->createStartersSelectionMenuGUI(render))
        {
            logMsg(func +" createPlayerStartSelectionMenuGUI!");
            flag->setPlayerStartSelectionMenuCreated(true);
        }
        else
        {
            logMsg(func +" Unable to create playerStartSelectionMenu!!");
            exit(0);
        }       
//        exit(0);
    }
    else
    {       
    }
    
    gData->addStartersSelectionMenuData();

//    exit(0);
    event->setSelectedIndexes();
    
    guiSMData *tempSMData(new guiSMData);
    tempSMData->component = data->component;
    tempSMData->create = data->create;
    tempSMData->gData = data->gData;
    tempSMData->display = data->display;
    tempSMData->event = data->event;
    tempSMData->flag = flag;
    tempSMData->input = input;
    tempSMData->render = render;
    
    display->changeActiveMenu(PLAYERSTART, data->render);
 
    logMsg(func +" end");
}

// OptionsMenu
STATE_DEFINE(guiStateMachine, OptionsMenu, guiSMData)
{
    std::string func = "guiStateMachine::OptionsMenu()";

    logMsg(func +" begin");

    logMsg(func +" end");
}

// AudioMenu
STATE_DEFINE(guiStateMachine, AudioMenu, guiSMData)
{
    std::string func = "guiStateMachine::AudioMenu()";

    logMsg(func +" begin");

    logMsg(func +" end");
}

// DisplayMenu
STATE_DEFINE(guiStateMachine, DisplayMenu, guiSMData)
{
    std::string func = "guiStateMachine::DisplayMenu()";

    logMsg(func +" begin");

    logMsg(func +" end");
}

// InputMenu
STATE_DEFINE(guiStateMachine, InputMenu, guiSMData)
{
    std::string func = "guiStateMachine::InputMenu()";

    logMsg(func +" begin");

    logMsg(func +" end");
}
