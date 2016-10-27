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

#ifndef _GUI_H_
#define _GUI_H_

#include "boost/shared_ptr.hpp"

#include "engine/gameengine.h"

#undef None
#undef Button1
#undef Button2
#undef Button3
#undef Button4
#undef Button5
#undef Button6
#undef Button7

#include "MyGUI_Gui.h"
#include "MyGUI_OgrePlatform.h"
#include "MyGUI_IItemContainer.h"
#include "MyGUI_ListBox.h"
#include "MyGUI_InputManager.h"
#include "MyGUI_EditBox.h"
#include "MyGUI_FontManager.h"
#include "MyGUI_LayoutManager.h"
#include "MyGUI_ImageBox.h"
#include "engine/gameengine.h"

/* #include "MyGUI.h"
#include "MyGUI_OgrePlatform.h"
#include "MyGUI_OgreRenderManager.h"
*/

//#include "ubcbase.h"
#include "enums.h"
#include "state/gamestateshared.h"
//#include "input.h" 
//#include "engine/renderengine.h" 

//#include "ubc.h"

//class networkEngine;
//class renderEngine;
//class gameEngine;

class UBCBase;

class GUISystem //: public UBCBase //: public UBC //: public renderEngine //, inputSystem
{
public:
    GUISystem();  // constructor
    ~GUISystem();  // destructor

    //static GUISystem *Instance();
//    static boost::shared_ptr<GUISystem> Instance();

/*    boost::shared_ptr<networkEngine> getNetworkG();  // retrieves the value of networkG
    void setNetworkG(boost::shared_ptr<networkEngine> set);  // sets the value of networkG

    boost::shared_ptr<renderEngine> getRenderE();  // retrieves the value of render
    void setRender(boost::shared_ptr<renderEngine> set);  // sets the value of render
*/

    static UBCBaseSharedPtr getBase();  // retrieves the value of base
    void setBase(UBCBaseSharedPtr set);  // sets the value of base

    bool getSetupComplete();  // retrieves the value of setupComplete
    void setSetupComplete(bool set);  // sets the value of setupComplete
    
    bool getMainMenuCreated();   // retrieves the value of mainMenuCreated
    void setMainMenuCreated(bool set); // sets the value of mainMenuCreated

    bool getBackButtonsCreated(); // retrieves the value of backButtonsCreated
    void setBackButtonsCreated(bool set); // sets the value of backButtonsCreated

    bool getNetworkSetupMenuCreated();  // retrieves the value of networkSetupMenuCreated
    void setNetworkSetupMenuCreated(bool set);  // sets the value of networkSetupMenuCreated

    bool getOptionsMenuCreated();  // retrieves the value of optionsMenuCreated
    void setOptionsMenuCreated(bool set);  // sets the value of optionsMenuCreated

    bool getDisplaySetupMenuCreated();  // retrieves the value of displaySettingsMenuCreated
    void setDisplaySetupMenuCreated(bool set);  // sets the value of displaySettingsMenuCreated

    bool getInputSetupMenuCreated();  // retrieves the value of inputSettingsMenuCreated
    void setInputSetupMenuCreated(bool set);  // sets the value of inputSettingsMenuCreated

    bool getAuduoSetupMenuCreated();  // retrieves the value of audioSettingsMenuCreated
    void setAudioSetupMenuCreated(bool set);  // sets the value of audioSettingsMenuCreated

    bool getGameSetupMenuCreated();  // retrieves the value of gameSetupMenuCreated
    void setGameSetupMenuCreated(bool set);  // sets the value of gameSetupMenuCreated

    bool getPlayerStartSelectionMenuCreated();  // retrieves the value of playerStartSelectionMenuCreated
    void setPlayerStartSelectionMenuCreated(bool set);  // sets the value of playerStartSelectionMenuCreated

    bool getTeamSelectionMenuCreated();  // retrieves the value of teamSelectionMenuCreated
    void setTeamSelectionMenuCreated(bool set);  // sets the value of teamSelectionMenuCreated

    bool getTeamSelectionMenuDataAdded();  // retrieves the value of teamSelectionMenuDataAdded
    void setTeamSelectionMenuDataAdded(bool set);  // sets the value of teamSelectionDataAdded

    bool getCourtSelectionMenuCreated();  // retrieves the value of courtSelectionMenuCreated
    void setCourtSelectionMenuCreated(bool set);  // sets the value of courtSelectionMenuCreated	

    bool getCourtSelectionDataLoaded();  // retrieves the value of courtSelectionEntriesLoaded
    void setCourtSelectionDataLoaded(bool set);  // sets the value of courtSelectionEntriesLoaded
	
    bool getMenuActive(); // retrieves the value of menuActive
    void setMenuActive(bool set); // sets the value of menuActive

    activeMenus getActiveMenu(); // retrieves the value of activeMenu
    void setActiveMenu(activeMenus set); // sets the value of activeMenu

    activeMenus getPreviousActiveMenu(); // retrieves the value of previousActiveMenu
    void setPreviousActiveMenu(activeMenus set); // sets the value of previousActiveMenu

    boost::shared_ptr<MyGUI::Gui> getMGUI();  // retrieves the value of mGUI
    void setMGUI(boost::shared_ptr<MyGUI::Gui> set);  // sets the value of mGUI
    
/*    Ogre::Viewport *getViewPort();  // retrieves the value of viewPort
    void setViewPort(const Ogre::Viewport &set);  // sets the value of viewPort
*/

    bool setup();  // sets up the in game gui
    bool initMyGUI();  // Initializes MyGUI
    bool createMainMenuGUI();  // creates GUI gor main menu screen.
    bool createNetworkSetupGUI();  // creates GUI for network setup screen.
    bool createNetworkClientSetupGUI();  // creates GUI for network client setup screen.
    bool createNetworkServerSetupGUI();  // creates GUI for network server setup screen.
    bool createOptionsMenuGUI();  // creates GUI for options menu screen.
    bool createDisplaySetupGUI();  // creates GUI for display settings screen.
    bool createInputSetupGUI();  // creates GUI for input settings screen.
    bool createAudioSetupGUI();	 // creates GUI for audo settings screen.
    bool createGameSetupMenuGUI();  // creates GUI for game setup menu screen.
    bool createPlayerStartSelectionMenuGUI();  // creates GUI for player start selection menu screen.
    bool createTeamSelectionMenuGUI();	// creates GUI for team selection menu screen.
    bool createCourtSelectionMenuGUI();  // creates GUI for court selection menu screen.
    bool createBackButtons();  // creates the back buttons for the menus

    void menuReceiveKeyPress(std::string keyPressed);  // processes key input
    void processMainMenuKeyPress(std::string keyPressed);  // processes main menu key input
    void processNetworkMenuKeyPress(std::string keyPressed);  // processes network menu key input
    void processNetworkServerMenuKeyPress(std::string keyPressed);  // process network server menu key input
    void processNetworkClientMenuKeyPress(std::string keyPressed);  // process network client menu key input
    void processOptionsMenuKeyPress(std::string keyPressed);  // processes options menu key input
    void processDisplayMenuKeyPress(std::string keyPressed);  // processes display settings menu key input
    void processInputMenuKeyPress(std::string keyPressed);  // processes input settings menu key input
    void processAudioMenuKeyPress(std::string keyPressed);  // processes audio settings menu key input
    void processGameSetupMenuKeyPress(std::string keyPressed);  // processes game setup menu key input
    void processPlayerStartSelectionMenuKeyPress(std::string keyPressed);  // process player start selection menu key input
    void processTeamSelectionMenuKeyPress(std::string keyPressed);  // process team selection menu key input
    void processCourtSelectionMenuKeyPress(std::string keyPressed);  // process court selection menu key input
	
    void mainMenu();  // msin in game menu
    void backButtons();  // handles the back buttons
    void startSinglePlayerGame();  // starts single player game
    void startMultiPlayerGame();  // starts multiplayer game
    void optionsMenu();  // displays options menu
    void displayMenu();  // displays display menu
    void inputMenu();  // displays the input menu
    void audioMenu();  // displays the audio menu
    void gameSetupMenu();  // displays game setup menu
    void playerStartSelectionMenu();  // displays player start selection menu
    void teamSelectionMenu();  // displays team selection menu
    void courtSelectionMenu();  // displays court selection menu
    void networkClientSetupMenu();  // sets up the network client connection
    void networkServerSetupMenu();  // sets up the networkServer instance
    
    bool addCourtSelectionMenuData();  // adds data to Court Selection Menu widgets

    void addPlayerStartSelectionMenuData();  // adds data to Player Start Selection Menu widgets

    bool addTeamStartSelectionMenuData();  // adds data to Team Start Selection Menu
    
    void setSelectedIndexes();  // sets all player listbox indexes to zero
    void networkServer();  // sets up  game as a network server
    void networkClient();  // sets up game as a network client

    void courtSelected();  // processes court selection
    void teamsSelected();  // processes team selection
    void playerStartSelected();  // process player start selection
    void gameSetupAwaySelected();  // processes away team selectdion on game setup menu
    void gameSetupHomeSelected();  // process home team selection on game setup menu
    void backMainMenuSelected();  // processes back to main menu selection
    void backNetworkSetupMenuSelected();  // returns back to network setup screen
    void backNetworkClientMenuSelected();  // returns back to the network client menu
    
    bool checkTeamInstancesCreated();  // Checks if team instances have been created and if not creates them.



//    GUISystem();
//    GUISystem(const GUISystem&);
//    GUISystem& operator= (const GUISystem&);

    
    // MyGUI functions
    void startSingleGameButtonClicked(MyGUI::Widget *_sender);  // handles startSingleGameButton click event
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
    void backGameSetupMenuButtonClicked(MyGUI::Widget *_sender);  // handles backGameSetupMenuButton click event
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

    void hideGameSetupMenuWidgets();  // hides all widgets tied to the Game Setup Menu
    void showGameSetupMenuWidgets();  // shows all widgets tied to the Game Setup Menu

    void hidePlayerStartSelectionMenuWidgets(); // hides all widgets tied to the Player Start Selection Menu
    void showPlayerStartSelectionMenuWidgets(); // shows all widgets tied to the Player Start Selection Menu

    void hideTeamSelectionMenuWidgets(); // hides all widgets tied to the Team Selection Menu
    void showTeamSelectionMenuWidgets(); // show all widgets tied to the Team Selection Menu

    void hideCourtSelectionMenuWidgets(); // hides all widgets tied to the Court Selection Menu
    void showCourtSelectionMenuWidgets(); // show all widgets tied to the Court Selection Menu
	
    void hideActiveMenuWidgets();  // hides active menus widgets
    void showActiveMenuWidgets();  // shows active menus widgets
    
    void changeActiveMenu(activeMenus menu);  // changes the actively displayed menu
    
private:

    //static GUISystem *pInstance;
//    static boost::shared_ptr<GUISystem> pInstance;
    
//    static MyGUI::Gui *mGUI;
//    static MyGUI::OgrePlatform *mPlatform;
    
    static UBCBaseSharedPtr base;
    static boost::shared_ptr<MyGUI::Gui> mGUI;  // The MyGUI object
    static boost::shared_ptr<MyGUI::OgrePlatform> mPlatform;  // The MyGUI Platform object

    // button widgets
    
    // Main Menu
    static std::tr1::unordered_map<std::string, boost::shared_ptr<MyGUI::Button> > mainMenuButtons;
/*    static boost::shared_ptr<MyGUI::Button> exitButton;
    static boost::shared_ptr<MyGUI::Button> startSingleGameButton;
    static boost::shared_ptr<MyGUI::Button> startMultiGameButton;
    static boost::shared_ptr<MyGUI::Button> optionsButton;
    static boost::shared_ptr<MyGUI::Button> serverButton;
    static boost::shared_ptr<MyGUI::Button> clientButton;
*/
     static std::tr1::unordered_map<std::string, boost::shared_ptr<MyGUI::Button> > networkMenuButtons;

    static boost::shared_ptr<MyGUI::Button> backMainMenuButton;
    static boost::shared_ptr<MyGUI::Button> backNetworkSetupButton;
    static boost::shared_ptr<MyGUI::Button> displayButton;
    static boost::shared_ptr<MyGUI::Button> inputButton;
    static boost::shared_ptr<MyGUI::Button> audioButton;
    static boost::shared_ptr<MyGUI::Button> team0SelectButton;
    static boost::shared_ptr<MyGUI::Button> team1SelectButton;
    static boost::shared_ptr<MyGUI::Button> startGameButton;
    static boost::shared_ptr<MyGUI::Button> backNetworkClientButton;
    static boost::shared_ptr<MyGUI::Button> changeResolutionButton;
    static boost::shared_ptr<MyGUI::Button> changeInputTypeButton;
    static boost::shared_ptr<MyGUI::Button> enableAudioButton;
    static boost::shared_ptr<MyGUI::Button> disableAudioButton;
    static boost::shared_ptr<MyGUI::Button> backOptionsMenuButton;
    static boost::shared_ptr<MyGUI::Button> backGameSetupMenuButton;
    static boost::shared_ptr<MyGUI::Button> backTeamSelectionMenuButton;
    static boost::shared_ptr<MyGUI::Button> backCourtSelectionMenuButton;
    static boost::shared_ptr<MyGUI::Button> teamsSelectedButton;
    
    // Player Start Selection Menu
/*    static boost::shared_ptr<MyGUI::Button> team0StartingLineupSetButton;
    static boost::shared_ptr<MyGUI::Button> team1StartingLineupSetButton;
    static boost::shared_ptr<MyGUI::Button> startingLineupsSetButton;
*/
    static std::tr1::unordered_map<std::string, boost::shared_ptr<MyGUI::Button> > playerStartSelectionMenuButtons;

    // Team selection listbox widgets
//    static boost::shared_ptr<MyGUI::ListBox> team0SelectBox;
//    static boost::shared_ptr<MyGUI::ListBox> team1SelectBox;
    static std::tr1::unordered_map<size_t, boost::shared_ptr<MyGUI::ListBox> > teamSelectBox;

    // Network Server Setup Widgets
    static boost::shared_ptr<MyGUI::ListBox> numClientsSelectBox;  // allows you to select the number of network players
    static boost::shared_ptr<MyGUI::Button> serverHostButton;
    static boost::shared_ptr<MyGUI::EditBox> serverIPAddressBox;
    
    // Network Client Setup Widgets
    static boost::shared_ptr<MyGUI::EditBox> clientIPAddressBox;
    static boost::shared_ptr<MyGUI::Button> clientConnectButton;
    
    static std::vector<std::tr1::unordered_map <std::string, boost::shared_ptr<MyGUI::ListBox> > > teamPlayerPosSelectBox;

    
/*    static boost::shared_ptr<MyGUI::ListBox> team0Player1SelectBox;
    static boost::shared_ptr<MyGUI::ListBox> team0Player2SelectBox;
    static boost::shared_ptr<MyGUI::ListBox> team0Player3SelectBox;
    static boost::shared_ptr<MyGUI::ListBox> team0Player4SelectBox;
    static boost::shared_ptr<MyGUI::ListBox> team0Player5SelectBox;
    static boost::shared_ptr<MyGUI::ListBox> team1Player1SelectBox;
    static boost::shared_ptr<MyGUI::ListBox> team1Player2SelectBox;
    static boost::shared_ptr<MyGUI::ListBox> team1Player3SelectBox;
    static boost::shared_ptr<MyGUI::ListBox> team1Player4SelectBox;
    static boost::shared_ptr<MyGUI::ListBox> team1Player5SelectBox;

    
    // Player Selection Menu widgets
    static boost::shared_ptr<MyGUI::ListBox> team0PGSelectBox;
    static boost::shared_ptr<MyGUI::ListBox> team0SGSelectBox;
    static boost::shared_ptr<MyGUI::ListBox> team0SFSelectBox;
    static boost::shared_ptr<MyGUI::ListBox> team0PFSelectBox;
    static boost::shared_ptr<MyGUI::ListBox> team0CSelectBox;

    static boost::shared_ptr<MyGUI::ListBox> team1PGSelectBox;
    static boost::shared_ptr<MyGUI::ListBox> team1SGSelectBox;
    static boost::shared_ptr<MyGUI::ListBox> team1SFSelectBox;
    static boost::shared_ptr<MyGUI::ListBox> team1PFSelectBox;
    static boost::shared_ptr<MyGUI::ListBox> team1CSelectBox;
*/

    static std::vector<std::map<std::string, boost::shared_ptr<MyGUI::TextBox> > > teamPlayerRating;


/*    static boost::shared_ptr<MyGUI::TextBox> team0PGRating;
    static boost::shared_ptr<MyGUI::TextBox> team0SGRating;
    static boost::shared_ptr<MyGUI::TextBox> team0SFRating;
    static boost::shared_ptr<MyGUI::TextBox> team0PFRating;
    static boost::shared_ptr<MyGUI::TextBox> team0CRating;

    static boost::shared_ptr<MyGUI::TextBox> team1PGRating;
    static boost::shared_ptr<MyGUI::TextBox> team1SGRating;
    static boost::shared_ptr<MyGUI::TextBox> team1SFRating;
    static boost::shared_ptr<MyGUI::TextBox> team1PFRating;
    static boost::shared_ptr<MyGUI::TextBox> team1CRating;
*/

    static std::tr1::unordered_map<std::string, boost::shared_ptr<MyGUI::ImageBox> > teamLogo;

//    static boost::shared_ptr<MyGUI::ImageBox> team0Logo;
//    static boost::shared_ptr<MyGUI::ImageBox> team1Logo;
	
    // Court selection menu widgets
    static boost::shared_ptr<MyGUI::Button> backPlayerStartSelectionMenuButton;
    static boost::shared_ptr<MyGUI::Button> courtSelectButton;
    static boost::shared_ptr<MyGUI::ListBox> courtSelectBox;  
    static boost::shared_ptr<MyGUI::ImageBox> courtPreviewImgBox;
    static boost::shared_ptr<MyGUI::TextBox> courtNameTxtBox;

    // OGRE specific code
/*    boost::shared_ptr<renderEngine> render;  // stores a copy of the render object for use in the gui
    Ogre::Viewport *viewPort; // stores the view port for mygui

    // network engine
    boost::shared_ptr<networkEngine> networkG;  // stores a copy of the network object for use in the gui
*/

	// booleans
    static bool setupComplete;  // determinrs if the gui has been properly setup.
    static bool mainMenuCreated;   // determines whether the main menu gui has been created
    static bool backButtonsCreated;  // determines whether the back buttons have been created
    static bool networkSetupMenuCreated;   // determines whether the network setup gui has been created
    static bool networkServerSetupMenuCreated;   // determines whether the network server setup gui has been created
    static bool networkClientSetupMenuCreated;   // determines whether the network client setup gui has been created
    static bool optionsMenuCreated;   // determines whether the options menu gui has been created
    static bool displaySetupMenuCreated;   // determines whether the display settings menu gui has been created
    static bool inputSetupMenuCreated;   // determines whether the input settings menu gui has been created
    static bool audioSetupMenuCreated;   // determines whether the audio settings menu gui has been created
    static bool gameSetupMenuCreated;  // determines whether the game setup menu gui has been created
    static bool playerStartSelectionMenuCreated;  // determines whether the player start selection menu gui has been created
    static bool teamSelectionMenuCreated;  // determines whether the team selection menu gui has been created
    static bool teamSelectionMenuDataAdded;  // determines whether teeam data has been added to the the team selection menu
    static bool courtSelectionMenuCreated;  // deteemines whether the court selection menu has been created;
    static bool menuActive;  // stores whether a menu is being diplayed
    static bool gameSetupMenuAwaySelected;  // determines whether the away team listbox is selected;
    static bool gameSetupMenuHomeSelected;  // determines whether the home team listbox is selected;
    static bool courtSelectionDataLoaded;  // determines whether court names have been added to the select box
    
    static activeMenus activeMenu;  // stores which menu is being displayed
    static activeMenus previousActiveMenu;  // stores which menu was last displayed

    static std::vector< stdStringVec > playerNames;
    static std::vector< stdStringVec > playerPositionsPlayed;
    static std::vector< sizeTVec > playerIDs;  // stores player IDs for each team
    static std::vector< sizeTVec > team0IDs;
    static std::vector< sizeTVec > team1IDs;
    static std::vector< sizeTVec > teamStarterID; // stores the selected starters for each team 

    static size_t displayCount;
};

#endif // GUI_H_INCLUDED
