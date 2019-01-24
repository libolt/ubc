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

#include "statemachine/guistatemachine.h"
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
    std::string func = "guiStateMachine::MainMenu()";

    logMsg(func +" begin");

    logMsg(func +" end");
}

// Network Menu
STATE_DEFINE(guiStateMachine, NetworkMenu, guiSMData)
{
    std::string func = "guiStateMachine::NetworkMenu()";

    logMsg(func +" begin");

    logMsg(func +" end");
}

// Network Client Menu
STATE_DEFINE(guiStateMachine, NetworkClientMenu, guiSMData)
{
    std::string func = "guiStateMachine::NetworkClientMenu()";

    logMsg(func +" begin");

    logMsg(func +" end");
}

// NetworkServerMenu
STATE_DEFINE(guiStateMachine, NetworkServerMenu, guiSMData)
{
    std::string func = "guiStateMachine::NetworkServerMenu()";

    logMsg(func +" begin");

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
    std::string func = "guiStateMachine::CourtMenu()";

    logMsg(func +" begin");

    logMsg(func +" end");
}

// TeamMenu
STATE_DEFINE(guiStateMachine, TeamMenu, guiSMData)
{
    std::string func = "guiStateMachine::TeamMenu()";

    logMsg(func +" begin");

    logMsg(func +" end");
}

// StartersMenu
STATE_DEFINE(guiStateMachine, StartersMenu, guiSMData)
{
    std::string func = "guiStateMachine::StartersMenu()";

    logMsg(func +" begin");

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