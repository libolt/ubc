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

        bool initMyGUI(renderEngineSharedPtr render);  // Initializes MyGUI

    private:
    
        MyGUIGuiSharedPtr mGUI;  // The MyGUI object
        MyGUIOgrePlatformSharedPtr mPlatform;  // The MyGUI Platform object

};

#endif
