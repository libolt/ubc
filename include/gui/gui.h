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

#ifndef _GUI_H_
#define _GUI_H_

//#include "boost/shared_ptr.hpp"

#include "flags/guiflags.h"
#include "gui/guidefines.h"

#include "MyGUI_Gui.h"
#include "MyGUI_OgrePlatform.h"
#include "MyGUI_IItemContainer.h"
#include "MyGUI_ListBox.h"
#include "MyGUI_InputManager.h"
#include "MyGUI_EditBox.h"
#include "MyGUI_FontManager.h"
#include "MyGUI_LayoutManager.h"
#include "MyGUI_ImageBox.h"



#include "utilities/enums.h"
#include "utilities/typedefs.h"

class guiComponents;
class UBCGame;

class GUISystem
{
public:
    GUISystem();  // constructor
    ~GUISystem();  // destructor
	
    bool getObjectsInitialized() const;  // retrieves the value of objectsInitialized
    void setObjectsInitialized(const bool &set);  // sets the value of objectsInitialized
    
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

    guiInputSharedPtr getInput() const;  // retrieves the value of input
    void setInput(const guiInputSharedPtr &set);  // sets the value of input

    guiStateMachineSharedPtr getStateMachine() const;  // retrieves the value of stateMachine
    void setStateMachine(const guiStateMachineSharedPtr &set);  // sets the value of stateMachine

    gameEngineSharedPtr getGamE() const;  // retrieves the value of gameE
    void setGameE(const gameEngineSharedPtr &set);  // sets the value of gameE
    
    gameEntitySharedPtr getGameInstance() const;  // retrieves the value of teamInstance
    void setGameInstance(const gameEntitySharedPtr &set);  // sets the value of teamInstance

/*    activeMenus getActiveMenu() const;  // retrieves the value of activeMenu
    void setActiveMenu(const activeMenus &set);  // sets the value of activeMenu

    activeMenus getPreviousActiveMenu() const;  // retrieves the value of previousActiveMenu
    void setPreviousActiveMenu(const activeMenus &set);  // sets the value of previousActiveMenu
*/
    bool initializeObjects(const renderEngineSharedPtr &render);  // initializes gui objects
    bool initializeStateMachine(const renderEngineSharedPtr &render);  // initializes gui stateMachine

//    bool createMainMenuGUI(const renderEngineSharedPtr &render);  // creates GUI gor main menu screen.
    bool createNetworkSetupGUI(const renderEngineSharedPtr &render);  // creates GUI for network setup screen.
    bool createNetworkClientSetupGUI(const renderEngineSharedPtr &render);  // creates GUI for network client setup screen.
    bool createNetworkServerSetupGUI(const renderEngineSharedPtr &render);  // creates GUI for network server setup screen.
    bool createOptionsMenuGUI(const renderEngineSharedPtr &render);  // creates GUI for options menu screen.
    bool createDisplaySetupGUI();  // creates GUI for display settings screen.
    bool createInputSetupGUI();  // creates GUI for input settings screen.
    bool createAudioSetupGUI();	 // creates GUI for audo settings screen.
    bool createSetupMenuGUI();  // creates GUI for game setup menu screen.
    bool createPlayerStartSelectionMenuGUI(const renderEngineSharedPtr &render);  // creates GUI for player start selection menu screen.
    bool createTeamSelectionMenuGUI(const renderEngineSharedPtr &render);	// creates GUI for team selection menu screen.
//    bool createCourtSelectionMenuGUI(const renderEngineSharedPtr &render);  // creates GUI for court selection menu screen.
    bool createBackButtons();  // creates the back buttons for the menus

    void menuReceiveKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // processes key input
    void processMainMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // processes main menu key input
    void processNetworkMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // processes network menu key input
    void processNetworkServerMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // process network server menu key input
    void processNetworkClientMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // process network client menu key input
    void processOptionsMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // processes options menu key input
    void processDisplayMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // processes display settings menu key input
    void processInputMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // processes input settings menu key input
    void processAudioMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // processes audio settings menu key input
    void processSetupMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // processes game setup menu key input
    void processPlayerStartSelectionMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // process player start selection menu key input
    void processTeamSelectionMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // process team selection menu key input
    void processCourtSelectionMenuKeyPress(const std::string &keyPressed, const renderEngineSharedPtr &render);  // process court selection menu key input
	
//    void mainMenu(const renderEngineSharedPtr &render);  // msin in game menu
    void backButtons();  // handles the back buttons
//    void startSinglePlayerGame(const renderEngineSharedPtr &render);  // starts single player game
    void startMultiPlayerGame(const renderEngineSharedPtr &render);  // starts multiplayer game
    void optionsMenu(const renderEngineSharedPtr &render);  // displays options menu
    void displayMenu(const renderEngineSharedPtr &render);  // displays display menu
    void inputMenu(const renderEngineSharedPtr &render);  // displays the input menu
    void audioMenu(const renderEngineSharedPtr &render);  // displays the audio menu
    void setupMenu(const renderEngineSharedPtr &render);  // displays game setup menu
    void playerStartSelectionMenu(const renderEngineSharedPtr &render);  // displays player start selection menu
    void teamSelectionMenu(const renderEngineSharedPtr &render);  // displays team selection menu
//    void courtSelectionMenu(const renderEngineSharedPtr &render);  // displays court selection menu
    void networkClientSetupMenu(const renderEngineSharedPtr &render);  // sets up the network client connection
    void networkServerSetupMenu(const renderEngineSharedPtr &render);  // sets up the networkServer instance
    
//    bool addCourtSelectionMenuData();  // adds data to Court Selection Menu widgets

    void addPlayerStartSelectionMenuData();  // adds data to Player Start Selection Menu widgets
    void addPlayerStartSelectionMenuData_old();  // adds data to Player Start Selection Menu widgets

    bool addTeamStartSelectionMenuData();  // adds data to Team Start Selection Menu
    
    void setSelectedIndexes();  // sets all player listbox indexes to zero
    void networkServer();  // sets up  game as a network server
    void networkClient();  // sets up game as a network client

    void courtSelected();  // processes court selection
    void teamsSelected();  // processes team selection
    void playerStartSelected();  // process player start selection
    void setupAwaySelected();  // processes away team selectdion on game setup menu
    void setupHomeSelected();  // process home team selection on game setup menu
    void backMainMenuSelected(const renderEngineSharedPtr &render);  // processes back to main menu selection
    void backNetworkSetupMenuSelected(const renderEngineSharedPtr &render);  // returns back to network setup screen
    void backNetworkClientMenuSelected(const renderEngineSharedPtr &render);  // returns back to the network client menu
    
    bool checkTeamInstancesCreated();  // Checks if team instances have been created and if not creates them.


    // MyGUI functions
    void serverButtonClicked(MyGUI::Widget *_sender);  // handles serverButton click event
    void clientButtonClicked(MyGUI::Widget *_sender);  // handles clientButton click event
    void serverHostButtonClicked(MyGUI::Widget *_sender);  // handles hostGameButton click event
    void clientConnectButtonClicked(MyGUI::Widget *_sender);  // handles connectButton click event
    void backNetworkSetupButtonClicked(MyGUI::Widget *_sender);  // handles backNetworkSetupButton click event
    void displayButtonClicked(MyGUI::Widget *_sender);  // handles didplayButton click event
    void inputButtonClicked(MyGUI::Widget *_sender);  // handles inputButton click event
    void audioButtonClicked(MyGUI::Widget *_sender);  // handles audioButton click event
    void changeResolutionButtonClicked(MyGUI::Widget *_sender);  // handles changeResolutionButton click event
    void changeInputTypeButtonClicked(MyGUI::Widget *_sender);  // handles changeInputTypeButton click event
    void enableAudioButtonClicked(MyGUI::Widget *_sender);  // handles eneableAudioButton click event
    void disableAudioButtonClicked(MyGUI::Widget *_sender);  // handles eneableAudioButton click event
    void team0SelectButtonClicked(MyGUI::Widget *_sender);  // handles team0SelectButton click event
    void team1SelectButtonClicked(MyGUI::Widget *_sender);  // handles team1SelectButton click event
    void teamsSelectedButtonClicked(MyGUI::Widget *_sender);  // handles teamsSelectedButton click event
    void team0StartingLineupSetButtonClicked(MyGUI::Widget *_sender);  // handles team0StartingLineupSetButton click event
    void team1StartingLineupSetButtonClicked(MyGUI::Widget *_sender);  // handles team1StartingLineupSetButton click event
    void startingLineupSetButtonClicked(MyGUI::Widget *_sender);  // handles startingLineupSetButton click event
    void backNetworkClientButtonClicked(MyGUI::Widget *_sender);  // handles backNetworkClientButton click event
    void backOptionsMenuButtonClicked(MyGUI::Widget *_sender);  // handles backOptionsMenuButton click event
    void backPlayerStartSelectionMenuButtonClicked(MyGUI::Widget *_sender);  // handles backPlayerStartSelectionMenuButton click event
    void backTeamSelectionMenuButtonClicked(MyGUI::Widget *_sender);  // handles backPlayerStartSelectionMenuButton click event
    void backCourtSelectionMenuButtonClicked(MyGUI::Widget *_sender);  // handles backCourtSelectionMenuButton click event
    void backSetupMenuButtonClicked(MyGUI::Widget *_sender);  // handles backSetupMenuButton click event
        
private:

    bool objectsInitialized;  // stores whether gui objects have been initialized
    
    guiComponentsSharedPtr component;  // stores gui related components
    
    guiCreateSharedPtr create;  // stores gui create functions
    
    guiDataSharedPtr data;  // stores gui data functions

    guiDisplaySharedPtr display;  // stores gui display functions

    guiFlagsSharedPtr flag;  // stores gui related flags

    guiInputSharedPtr input;  // stores gui input functions

    guiStateMachineSharedPtr stateMachine;  // stores gui stateMachine object

//    UBCGameSharedPtr game;  // stores a copy of the game object
    gameEntitySharedPtr gameInstance;  // stores a copy of the gameInstance
//    teamEntityMSharedPtr teamInstance;  // stores a copy of the teamInstance
    
    gameEngineSharedPtr gameE; // stores a copy of gameE
    
    std::vector<stdStringVec> playerNames;
    std::vector<stdStringVec> playerPositionsPlayed;
    std::vector<sizeTVec> playerIDs;  // stores player IDs for each team
    std::vector<sizeTVec> team0IDs;
    std::vector<sizeTVec> team1IDs;
    teamStarterIDsVecM teamStarterID; // stores the selected starters for each team 

};

#endif // GUI_H_INCLUDED
