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

#ifndef _GUICOMPONENTS_H_
#define _GUICOMPONENTS_H_

#include "MyGUI_Gui.h"
#include "MyGUI_OgrePlatform.h"
#include "MyGUI_IItemContainer.h"
#include "MyGUI_ListBox.h"
#include "MyGUI_InputManager.h"
#include "MyGUI_EditBox.h"
#include "MyGUI_FontManager.h"
#include "MyGUI_LayoutManager.h"
#include "MyGUI_ImageBox.h"

#include "utilities/typedefs.h"

class GUIComponents
{
    public:
        GUIComponents();  // constructor
        ~GUIComponents();  // destructor
        
        MyGUIGuiSharedPtr getMGUI();  // retrieves the value of mGUI
        void setMGUI(MyGUIGuiSharedPtr set);  // sets the value of mGUI

        MyGUIButtonMSharedPtr getMainMenuButtons();  // retrieves the value of mainMenuButtons
        void setMainMenuButtons(MyGUIButtonMSharedPtr set);  // sets the value of mainMenuButtons
        
        MyGUIButtonMSharedPtr getNetworkMenuButtons();  // retrieves the value of networkMenuButtons
        void setNetworkMenuButtons(MyGUIButtonMSharedPtr set);  // sets the value of networkMenuButtons
        
        MyGUIButtonMSharedPtr getOptionsMenuButtons();  // retrieves the value of optionsMenuButtons
        void setOptionsMenuButtons(MyGUIButtonMSharedPtr set);  // sets the value of optionsMenuButtons
        
        MyGUIButtonMSharedPtr getDisplayMenuButtons();  // retrieves the value of displayMenuButtons
        void setDisplayMenuButtons(MyGUIButtonMSharedPtr set);  // sets the value of displayMenuButtons
        
        MyGUIButtonMSharedPtr getInputMenuButtons();  // retrieves the value of inputMenuButtons
        void setInputMenuButtons(MyGUIButtonMSharedPtr set);  // sets the value of inputMenuButtons
        
        MyGUIButtonMSharedPtr getAudioMenuButtons();  // retrieves the value of audioMenuButtons
        void setAudioMenuButtons(MyGUIButtonMSharedPtr set);  // sets the value of audioMenuButtons
        
        MyGUIButtonMSharedPtr getTeamSelectionMenuButtons();  // retrieves the value of teamSelectionMenuButtons
        void setTeamSelectionMenuButtons(MyGUIButtonMSharedPtr set);  // sets the value of teamSelectionMenuButtons
        
        MyGUIButtonMSharedPtr getPlayerStartSelectionMenuButtons();  // retrieves the value of playerStartSelectionMenuButtons
        void setPlayerStartSelectionMenuButtons(MyGUIButtonMSharedPtr set);  // sets the value of playerStartSelectionMenuButtons

        MyGUIListBoxMSharedPtr getTeamSelectBox();  // retrieves the value of teamSelectBox
        void setTeamSelectBox(MyGUIListBoxMSharedPtr set);  // sets the value of teamSelectBox

        MyGUIListBoxSharedPtr getNumClientsSelectBox();  // retrieves the value of numClientsSelectBox
        void setNumClientsSelectBox(MyGUIListBoxSharedPtr set);  // sets the value of numClientsSelectBox

        sharedPtr<MyGUI::EditBox> getServerIPAddressBox();  // retrieves the value of serverIPAddressBox
        void setServerIPAddressBox(sharedPtr<MyGUI::EditBox> set);  // sets the value of serverIPAddressBox
    
        MyGUIButtonMSharedPtr getNetworkServerSetupMenuButtons();  // retrieves the value of networkServerSetupMenuButtons
        void setNetworkServerSetupMenuButtons(MyGUIButtonMSharedPtr set);  // sets the value of networkServerSetupMenuButtons
    
        sharedPtr<MyGUI::EditBox> getClientIPAddressBox();  // retrieves the value of clientIPAddressBox
        void setClientIPAddressBox(sharedPtr<MyGUI::EditBox> set);  // sets the value of clientIPAddressBox
    
        MyGUIButtonMSharedPtr getNetworkClientSetupMenuButtons();  // retrieves the value of networkClientSetupMenuButtons
        void setNetworkClientSetupMenuButtons(MyGUIButtonMSharedPtr set);  // sets the value of networkClientSetupMenuButtons
    
        MyGUIListBoxVecMSharedPtr getTeamPlayerPosSelectBox();  // retrieves the value of teamPlayerPosSelectBox
        void setTeamPlayerPosSelectBox(MyGUIListBoxVecMSharedPtr set);  // sets the value of teamPlayerPosSelectBox

        MyGUITextBoxVecMSharedPtr getTeamPlayerRating();  // retrieves the value of teamPlayerRating
        void setTeamPlayerRating(MyGUITextBoxVecMSharedPtr set);  // sets the value of teamPlayerRating

        MyGUIImageBoxMSharedPtr getTeamLogo();  // retrieves the value of teamLogo
        void setTeamLogo(MyGUIImageBoxMSharedPtr set);  // sets the value of teamLogo

        MyGUIButtonMSharedPtr getCourtSelectionMenuButtons();  // retrieves the value of courtSelectionMenuButtons
        void setCourtSelectionMenuButtons(MyGUIButtonMSharedPtr set);  // sets the value of courtSelectionMenuButtons

        MyGUIListBoxSharedPtr getCourtSelectBox();  // retrieves the value of courtSelectBox
        void setCourtSelectBox(MyGUIListBoxSharedPtr set);  // sets the value of courtSelectBox
        
        MyGUIImageBoxSharedPtr getCourtPreviewImgBox();  // retrieves the value of courtPreviewImgBox
        void setCourtPreviewImgBox(MyGUIImageBoxSharedPtr set);  // sets the value of courtPreviewImgBox
        
        MyGUITextBoxSharedPtr getCourtNameTxtBox();  // retrieves the value of courtNameTxtBox
        void setCourtNameTxtBox(MyGUITextBoxSharedPtr set);  // sets the value of courtNameTxtBox  
       
        void startSingleGameButtonClicked(MyGUI::Widget *_sender);  // handles startSingleGameButton click event
        
        bool initMyGUI(renderEngineSharedPtr render);  // Initializes MyGUI

    private:
    
        MyGUIGuiSharedPtr mGUI;  // The MyGUI object
        MyGUIOgrePlatformSharedPtr mPlatform;  // The MyGUI Platform object

        // button widgets
    
        // Main Menu
        MyGUIButtonMSharedPtr mainMenuButtons;
        MyGUIButtonMSharedPtr networkMenuButtons;
        MyGUIButtonMSharedPtr optionsMenuButtons;
        MyGUIButtonMSharedPtr displayMenuButtons;
        MyGUIButtonMSharedPtr inputMenuButtons;
        MyGUIButtonMSharedPtr audioMenuButtons;

        // Team Selection Menu
        MyGUIButtonMSharedPtr teamSelectionMenuButtons;

        // Player Start Selection Menu
        MyGUIButtonMSharedPtr playerStartSelectionMenuButtons;

        // Team selection listbox widgets
        MyGUIListBoxMSharedPtr teamSelectBox;

        // Network Server Setup Widgets
        MyGUIListBoxSharedPtr numClientsSelectBox;  // allows you to select the number of network players
        //    static sharedPtr<MyGUI::Button> serverHostButton;
        sharedPtr<MyGUI::EditBox> serverIPAddressBox;
    
        MyGUIButtonMSharedPtr networkServerSetupMenuButtons;
    
        // Network Client Setup Widgets
        sharedPtr<MyGUI::EditBox> clientIPAddressBox;
//    static sharedPtr<MyGUI::Button> clientConnectButton;
    
        MyGUIButtonMSharedPtr networkClientSetupMenuButtons;
    
        MyGUIListBoxVecMSharedPtr teamPlayerPosSelectBox;

        MyGUITextBoxVecMSharedPtr teamPlayerRating;

        MyGUIImageBoxMSharedPtr teamLogo;

        // Court selection menu widgets
        MyGUIButtonMSharedPtr courtSelectionMenuButtons;

        MyGUIListBoxSharedPtr courtSelectBox;
        MyGUIImageBoxSharedPtr courtPreviewImgBox;
        MyGUITextBoxSharedPtr courtNameTxtBox;

};

#endif
