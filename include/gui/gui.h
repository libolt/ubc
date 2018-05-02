/***************************************************************************
 *   Copyright (C) 1999 - 2018 by Mike McLean                              *
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

#include "boost/shared_ptr.hpp"

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

class GUIComponents;
class UBCGame;

class GUISystem
{
public:
    GUISystem();  // constructor
    ~GUISystem();  // destructor
	
    GUIComponentsSharedPtr getComponent();  // retrieves the value of component
    void setComponent(GUIComponentsSharedPtr set);  // sets the value of component

    guiFlagsSharedPtr getFlag();  // retrieves the value of flag
    void setFlag(guiFlagsSharedPtr set);  // sets the value of flag

    gameEngineSharedPtr getGamE();  // retrieves the value of gameE
    void setGameE(gameEngineSharedPtr set);  // sets the value of gameE
    
    gameEntitySharedPtr getGameInstance();  // retrieves the value of teamInstance
    void setGameInstance(gameEntitySharedPtr set);  // sets the value of teamInstance

    activeMenus getActiveMenu(); // retrieves the value of activeMenu
    void setActiveMenu(activeMenus set); // sets the value of activeMenu

    activeMenus getPreviousActiveMenu(); // retrieves the value of previousActiveMenu
    void setPreviousActiveMenu(activeMenus set); // sets the value of previousActiveMenu

    bool setup(renderEngineSharedPtr render);  // sets up the in game gui
    bool createMainMenuGUI(renderEngineSharedPtr render);  // creates GUI gor main menu screen.
    bool createNetworkSetupGUI(renderEngineSharedPtr render);  // creates GUI for network setup screen.
    bool createNetworkClientSetupGUI(renderEngineSharedPtr render);  // creates GUI for network client setup screen.
    bool createNetworkServerSetupGUI(renderEngineSharedPtr render);  // creates GUI for network server setup screen.
    bool createOptionsMenuGUI(renderEngineSharedPtr render);  // creates GUI for options menu screen.
    bool createDisplaySetupGUI();  // creates GUI for display settings screen.
    bool createInputSetupGUI();  // creates GUI for input settings screen.
    bool createAudioSetupGUI();	 // creates GUI for audo settings screen.
    bool createSetupMenuGUI();  // creates GUI for game setup menu screen.
    bool createPlayerStartSelectionMenuGUI(renderEngineSharedPtr render);  // creates GUI for player start selection menu screen.
    bool createTeamSelectionMenuGUI(renderEngineSharedPtr render);	// creates GUI for team selection menu screen.
    bool createCourtSelectionMenuGUI(renderEngineSharedPtr render);  // creates GUI for court selection menu screen.
    bool createBackButtons();  // creates the back buttons for the menus

    void menuReceiveKeyPress(std::string keyPressed, renderEngineSharedPtr render);  // processes key input
    void processMainMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render);  // processes main menu key input
    void processNetworkMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render);  // processes network menu key input
    void processNetworkServerMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render);  // process network server menu key input
    void processNetworkClientMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render);  // process network client menu key input
    void processOptionsMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render);  // processes options menu key input
    void processDisplayMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render);  // processes display settings menu key input
    void processInputMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render);  // processes input settings menu key input
    void processAudioMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render);  // processes audio settings menu key input
    void processSetupMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render);  // processes game setup menu key input
    void processPlayerStartSelectionMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render);  // process player start selection menu key input
    void processTeamSelectionMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render);  // process team selection menu key input
    void processCourtSelectionMenuKeyPress(std::string keyPressed, renderEngineSharedPtr render);  // process court selection menu key input
	
    void mainMenu(renderEngineSharedPtr render);  // msin in game menu
    void backButtons();  // handles the back buttons
    void startSinglePlayerGame(renderEngineSharedPtr render);  // starts single player game
    void startMultiPlayerGame(renderEngineSharedPtr render);  // starts multiplayer game
    void optionsMenu(renderEngineSharedPtr render);  // displays options menu
    void displayMenu(renderEngineSharedPtr render);  // displays display menu
    void inputMenu(renderEngineSharedPtr render);  // displays the input menu
    void audioMenu(renderEngineSharedPtr render);  // displays the audio menu
    void setupMenu(renderEngineSharedPtr render);  // displays game setup menu
    void playerStartSelectionMenu(renderEngineSharedPtr render);  // displays player start selection menu
    void teamSelectionMenu(renderEngineSharedPtr render);  // displays team selection menu
    void courtSelectionMenu(renderEngineSharedPtr render);  // displays court selection menu
    void networkClientSetupMenu(renderEngineSharedPtr render);  // sets up the network client connection
    void networkServerSetupMenu(renderEngineSharedPtr render);  // sets up the networkServer instance
    
    bool addCourtSelectionMenuData();  // adds data to Court Selection Menu widgets

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
    void backMainMenuSelected(renderEngineSharedPtr render);  // processes back to main menu selection
    void backNetworkSetupMenuSelected(renderEngineSharedPtr render);  // returns back to network setup screen
    void backNetworkClientMenuSelected(renderEngineSharedPtr render);  // returns back to the network client menu
    
    bool checkTeamInstancesCreated();  // Checks if team instances have been created and if not creates them.

    // MyGUI functions
    void startMultiGameButtonClicked(MyGUI::Widget *_sender);  // hands startMultiGameButton click event
    void optionsButtonClicked(MyGUI::Widget *_sender);  // handles optionsButton click event
    void exitButtonClicked(MyGUI::Widget *_sender);  // handles exitButton click event
    void serverButtonClicked(MyGUI::Widget *_sender);  // handles serverButton click event
    void clientButtonClicked(MyGUI::Widget *_sender);  // handles clientButton click event
    void serverHostButtonClicked(MyGUI::Widget *_sender);  // handles hostGameButton click event
    void clientConnectButtonClicked(MyGUI::Widget *_sender);  // handles connectButton click event
    void backMainMenuButtonClicked(MyGUI::Widget *_sender);  // handles backMainMenuButton click event
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
    void courtSelectButtonClicked(MyGUI::Widget *_sender);  // handles courtSelectButton click event

    void hideMainMenuWidgets();	 // hides all widgets tied to the Main Menu
    void showMainMenuWidgets();  // shows all widgets tied to the Main Menu

    void hideNetworkSetupWidgets();  // hides all widgets tied to the Network Setup Menu
    void showNetworkSetupWidgets();  // shows all widgets tied to the Network Setup Menu

    void hideNetworkServerSetupWidgets();  // hides all widgets tied to the Network Server Setup Menu
    void showNetworkServerSetupWidgets();  // shows all widgets tied to the Network Server Setup Menu

    void hideNetworkClientSetupWidgets();  // hides all widgets tied to the Network Client Setup Menu
    void showNetworkClientSetupWidgets();  // shows all widgets tied to the Network Client Setup Menu

    void hideOptionsMenuWidgets();	// hides all widgets tied to the Options Menu
    void showOptionsMenuWidgets();  // shows all widgets tied to the Options Menu

    void hideDisplayMenuWidgets();	// hides all widgets tied to the Display Menu
    void showDisplayMenuWidgets();  // shows all widgets tied to the Display Menu

    void hideInputMenuWidgets();  // hides all widgets tied to the Input Menu
    void showInputMenuWidgets();  // shows all widgets tied to the Input Menu

    void hideAudioMenuWidgets();  // hides all widgets tied to the Audio Menu
    void showAudioMenuWidgets();  // shows all widgets tied to the Audio Menu

    void hideSetupMenuWidgets();  // hides all widgets tied to the Game Setup Menu
    void showSetupMenuWidgets();  // shows all widgets tied to the Game Setup Menu

    void hidePlayerStartSelectionMenuWidgets(); // hides all widgets tied to the Player Start Selection Menu
    void showPlayerStartSelectionMenuWidgets(renderEngineSharedPtr render); // shows all widgets tied to the Player Start Selection Menu

    void hideTeamSelectionMenuWidgets(); // hides all widgets tied to the Team Selection Menu
    void showTeamSelectionMenuWidgets(renderEngineSharedPtr render); // show all widgets tied to the Team Selection Menu

    void hideCourtSelectionMenuWidgets(); // hides all widgets tied to the Court Selection Menu
    void showCourtSelectionMenuWidgets(renderEngineSharedPtr render); // show all widgets tied to the Court Selection Menu
	
    void hideActiveMenuWidgets();  // hides active menus widgets
    void showActiveMenuWidgets(renderEngineSharedPtr render);  // shows active menus widgets
    
    void changeActiveMenu(activeMenus menu, renderEngineSharedPtr render);  // changes the actively displayed menu
    
private:

    GUIComponentsSharedPtr component;  // stores gui related components
    
    guiFlagsSharedPtr flag;  // stores gui related flags

//    UBCGameSharedPtr game;  // stores a copy of the game object
    gameEntitySharedPtr gameInstance;  // stores a copy of the gameInstance
//    teamEntityMSharedPtr teamInstance;  // stores a copy of the teamInstance
    
    gameEngineSharedPtr gameE; // stores a copy of gameE
    
    activeMenus activeMenu;  // stores which menu is being displayed
    activeMenus previousActiveMenu;  // stores which menu was last displayed

    std::vector<stdStringVec> playerNames;
    std::vector<stdStringVec> playerPositionsPlayed;
    std::vector<sizeTVec> playerIDs;  // stores player IDs for each team
    std::vector<sizeTVec> team0IDs;
    std::vector<sizeTVec> team1IDs;
    teamStarterIDsVecM teamStarterID; // stores the selected starters for each team 

    size_t displayCount;
};

#endif // GUI_H_INCLUDED
