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
//#ifdef BTOGRE_MYGUI_ENABLED

#include "flags/guiflags.h"
#include "gui/guidefines.h"

#include "MyGUI_Gui.h"
#include "MyGUI_Ogre2Platform.h"
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

    guiEventsSharedPtr getEvent() const;  // retrieves the value of event
    void setEvent(const guiEventsSharedPtr &set);  // sets the value of event

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

    bool initializeObjects(const renderEngineSharedPtr &render);  // initializes gui objects
    bool initializeStateMachine(const renderEngineSharedPtr &render);  // initializes gui stateMachine

    bool updateStateMachine(const renderEngineSharedPtr &render);  // updates gui stateMachine

private:

    bool objectsInitialized;  // stores whether gui objects have been initialized
    
    guiComponentsSharedPtr component;  // stores gui related components
    
    guiCreateSharedPtr create;  // stores gui create functions
    
    guiDataSharedPtr data;  // stores gui data functions

    guiDisplaySharedPtr display;  // stores gui display functions

    guiEventsSharedPtr event;  // stores gui display functions

    guiFlagsSharedPtr flag;  // stores gui related flags

    guiInputSharedPtr input;  // stores gui input functions

    guiStateMachineSharedPtr stateMachine;  // stores gui stateMachine object

    gameEngineSharedPtr gameE; // stores a copy of gameE

    gameEntitySharedPtr gameInstance;  // stores a copy of the gameInstance

};
//#endif

#endif // GUI_H_INCLUDED
