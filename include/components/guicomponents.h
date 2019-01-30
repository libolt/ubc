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

class guiComponents
{
    public:
        guiComponents();  // constructor
        ~guiComponents();  // destructor
        
        bool getInitialized() const;  // retrieves the value of initialized
        void setInitialized(const bool &set);  // sets the value of initialized

        MyGUIGuiSharedPtr getMGUI() const;  // retrieves the value of mGUI
        void setMGUI(const MyGUIGuiSharedPtr &set);  // sets the value of mGUI

        MyGUIButtonMSharedPtr getMainMenuButtons() const;  // retrieves the value of mainMenuButtons
        void setMainMenuButtons(const MyGUIButtonMSharedPtr &set);  // sets the value of mainMenuButtons
        
        MyGUIButtonMSharedPtr getNetworkMenuButtons() const;  // retrieves the value of networkMenuButtons
        void setNetworkMenuButtons(const MyGUIButtonMSharedPtr &set);  // sets the value of networkMenuButtons
        
        MyGUIButtonMSharedPtr getOptionsMenuButtons() const;  // retrieves the value of optionsMenuButtons
        void setOptionsMenuButtons(const MyGUIButtonMSharedPtr &set);  // sets the value of optionsMenuButtons
        
        MyGUIButtonMSharedPtr getDisplayMenuButtons() const;  // retrieves the value of displayMenuButtons
        void setDisplayMenuButtons(const MyGUIButtonMSharedPtr &set);  // sets the value of displayMenuButtons
        
        MyGUIButtonMSharedPtr getInputMenuButtons() const;  // retrieves the value of inputMenuButtons
        void setInputMenuButtons(const MyGUIButtonMSharedPtr &set);  // sets the value of inputMenuButtons
        
        MyGUIButtonMSharedPtr getAudioMenuButtons() const;  // retrieves the value of audioMenuButtons
        void setAudioMenuButtons(const MyGUIButtonMSharedPtr &set);  // sets the value of audioMenuButtons
        
        MyGUIButtonMSharedPtr getTeamSelectionMenuButtons() const;  // retrieves the value of teamSelectionMenuButtons
        void setTeamSelectionMenuButtons(const MyGUIButtonMSharedPtr &set);  // sets the value of teamSelectionMenuButtons
        
        MyGUIButtonMSharedPtr getPlayerStartSelectionMenuButtons() const;  // retrieves the value of playerStartSelectionMenuButtons
        void setPlayerStartSelectionMenuButtons(const MyGUIButtonMSharedPtr &set);  // sets the value of playerStartSelectionMenuButtons

        MyGUIListBoxMSharedPtr getTeamSelectBox() const;  // retrieves the value of teamSelectBox
        void setTeamSelectBox(const MyGUIListBoxMSharedPtr &set);  // sets the value of teamSelectBox

        MyGUIListBoxSharedPtr getNumClientsSelectBox() const;  // retrieves the value of numClientsSelectBox
        void setNumClientsSelectBox(const MyGUIListBoxSharedPtr &set);  // sets the value of numClientsSelectBox

        sharedPtr<MyGUI::EditBox> getServerIPAddressBox() const;  // retrieves the value of serverIPAddressBox
        void setServerIPAddressBox(const sharedPtr<MyGUI::EditBox> &set);  // sets the value of serverIPAddressBox

        MyGUIButtonMSharedPtr getNetworkServerSetupMenuButtons() const;  // retrieves the value of networkServerSetupMenuButtons
        void setNetworkServerSetupMenuButtons(const MyGUIButtonMSharedPtr &set);  // sets the value of networkServerSetupMenuButtons

        sharedPtr<MyGUI::EditBox> getClientIPAddressBox() const;  // retrieves the value of clientIPAddressBox
        void setClientIPAddressBox(const sharedPtr<MyGUI::EditBox> &set);  // sets the value of clientIPAddressBox

        MyGUIButtonMSharedPtr getNetworkClientSetupMenuButtons() const;  // retrieves the value of networkClientSetupMenuButtons
        void setNetworkClientSetupMenuButtons(const MyGUIButtonMSharedPtr &set);  // sets the value of networkClientSetupMenuButtons

        MyGUIPlayerListBoxVecMSharedPtr getTeamPlayerPosSelectBox() const;  // retrieves the value of teamPlayerPosSelectBox
        void setTeamPlayerPosSelectBox(const MyGUIPlayerListBoxVecMSharedPtr &set);  // sets the value of teamPlayerPosSelectBox

        MyGUITextBoxVecMSharedPtr getTeamPlayerRating() const;  // retrieves the value of teamPlayerRating
        void setTeamPlayerRating(const MyGUITextBoxVecMSharedPtr &set);  // sets the value of teamPlayerRating

        MyGUIImageBoxMSharedPtr getTeamLogo() const;  // retrieves the value of teamLogo
        void setTeamLogo(const MyGUIImageBoxMSharedPtr &set);  // sets the value of teamLogo

        MyGUIButtonMSharedPtr getCourtSelectionMenuButtons() const;  // retrieves the value of courtSelectionMenuButtons
        void setCourtSelectionMenuButtons(const MyGUIButtonMSharedPtr &set);  // sets the value of courtSelectionMenuButtons

        MyGUIListBoxSharedPtr getCourtSelectBox() const;  // retrieves the value of courtSelectBox
        void setCourtSelectBox(const MyGUIListBoxSharedPtr &set);  // sets the value of courtSelectBox

        MyGUIImageBoxSharedPtr getCourtPreviewImgBox() const;  // retrieves the value of courtPreviewImgBox
        void setCourtPreviewImgBox(const MyGUIImageBoxSharedPtr &set);  // sets the value of courtPreviewImgBox

        MyGUITextBoxSharedPtr getCourtNameTxtBox() const;  // retrieves the value of courtNameTxtBox
        void setCourtNameTxtBox(const MyGUITextBoxSharedPtr &set);  // sets the value of courtNameTxtBox

//        void startSingleGameButtonClicked(MyGUI::Widget *_sender);  // handles startSingleGameButton click event

        bool initMyGUI(const renderEngineSharedPtr &render);  // Initializes MyGUI

    private:

        bool initialized;  // stores whether object has been initialized

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

        sharedPtr<MyGUI::EditBox> serverIPAddressBox;
    
        MyGUIButtonMSharedPtr networkServerSetupMenuButtons;
    
        // Network Client Setup Widgets
        sharedPtr<MyGUI::EditBox> clientIPAddressBox;
    
        MyGUIButtonMSharedPtr networkClientSetupMenuButtons;
    
        MyGUIPlayerListBoxVecMSharedPtr teamPlayerPosSelectBox;

        MyGUITextBoxVecMSharedPtr teamPlayerRating;

        MyGUIImageBoxMSharedPtr teamLogo;

        // Court selection menu widgets
        MyGUIButtonMSharedPtr courtSelectionMenuButtons;

        MyGUIListBoxSharedPtr courtSelectBox;
        MyGUIImageBoxSharedPtr courtPreviewImgBox;
        MyGUITextBoxSharedPtr courtNameTxtBox;

};

#endif
