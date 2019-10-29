/***************************************************************************
 *   Copyright (C) 1999 - 2019 by Mike McLean                              *
 *   libolt@libolt.net                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under tkfvrffuuhe terms of the GNU General Public License as published by  *
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

#ifndef _GUIEVENTS_H_
#define _GUIEVENTS_H_


#include "utilities/typedefs.h"

class guiEvents : public std::enable_shared_from_this<guiEvents>
{
    public:
        guiEvents();  // constructor
        ~guiEvents();  // destructor

        std::shared_ptr<guiEvents> evThis()
        {
            return shared_from_this();
        }
        
        guiComponentsSharedPtr getComponent() const;  // retrieves the value of component
        void setComponent(const guiComponentsSharedPtr &set);  // sets the value of component

        guiCreateSharedPtr getCreate() const;  // retrieves the value of create
        void setCreate(const guiCreateSharedPtr &set);  // sets the value of create

        guiDataSharedPtr getData() const;  // retrieves the value of data
        void setData(const guiDataSharedPtr &set);  // sets the value of data

        guiDisplaySharedPtr getDisplay() const;  // retrieves the value of display
        void setDisplay(const guiDisplaySharedPtr &set);  // sets the value of display

        guiFlagsSharedPtr getFlag() const;  // retrieves the value of flag
        void setFlag(const guiFlagsSharedPtr &set);  // sets the value of flag

        guiStateMachineSharedPtr getStateMachine() const;  // retrieves the value of stateMachine
        void setStateMachine(const guiStateMachineSharedPtr &set);  // sets the value of stateMachine

        gameEngineSharedPtr getGamE() const;  // retrieves the value of gameE
        void setGameE(const gameEngineSharedPtr &set);  // sets the value of gameE

        gameEntitySharedPtr getGameInstance() const;  // retrieves the value of teamInstance
        void setGameInstance(const gameEntitySharedPtr &set);  // sets the value of teamInstance

        bool checkAudioMenuSelects();  // checks which audioMenu option was selected
        bool checkCourtMenuSelects();  // checks which courtMenu option was selected
        bool checkDisplayMenuSelects();  // checks which displayMenu option was selected
        bool checkInputMenuSelects();  // checks which inputMenu option was selected
        bool checkMainMenuSelects();  // checks which mainMenu option was selected
        bool checkNetworkMenuSelects();  // checks which networkMenu option was selected
        bool checkNetworkClientMenuSelects();  // checks which networkMenu option was selected
        bool checkNetworkServerMenuSelects();  // checks which networkMenu option was selected
        bool checkOptionsMenuSelects();  // checks which optionsMenu option was selected
        bool checkStartersMenuSelects();  // checks which startersMenu option was selected
        bool checkTeamMenuSelects();  // checks which teamMenu option was selected

        bool checkTeamInstancesCreated();  // Checks if team instances have been created and if not creates them.

        void courtSelected();  // processes court selection
        void teamsSelected();  // processes team selection
        void playerStartSelected();  // process player start selection

        void hostGame();  // hosts a network game
        void connectGame();  // connects toa  network game

        void setSelectedIndexes();  // sets all player listbox indexes to zero

        void setupAwaySelected();  // processes away team selectdion on game setup menu
        void setupHomeSelected();  // process home team selection on game setup menu

        void audioMenu();  // switches to the audioMenu
        void courtMenu();  // starts a single player gamr
        void displayMenu();  // switches to the displayMenu
        void inputMenu();  // switches to the inputMenu
        void mainMenu();  // switches to the mainMenu
        void networkMenu();  // starts a multi player game
        void networkClientMenu();  // switches to the networkClientMenu
        void networkServerMenu();  // switches to the networkServerMenu
        void startersMenu();  // switches to the startersMenu
        void optionsMenu();  // switches to optionsMenu
        void teamMenu();  // switches to the teamMenu
        
    private:

        guiComponentsSharedPtr component;  // stores gui related components

        guiCreateSharedPtr create;  // stores gui create functions

        guiDataSharedPtr data;  // stores gui data functions

        guiDisplaySharedPtr display;  // stores gui display functions        guiFlagsSharedPtr flag;  // stores gui related flags

        guiFlagsSharedPtr flag;  // stores gui related flags

        guiStateMachineSharedPtr stateMachine;  // stores gui stateMachine object

        gameEngineSharedPtr gameE; // stores a copy of gameE

        gameEntitySharedPtr gameInstance;  // stores a copy of the gameInstance

};

#endif // _GUIEVENTS_H_
