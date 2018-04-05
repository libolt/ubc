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
 
#include "components/guicomponents.h"
#include "utilities/logging.h

GUIComponents::GUIComponents()  // constructor
{

}

GUIComponents::~GUIComponents()  // destructor
{

}

MyGUIGuiSharedPtr GUIComponents::getMGUI()  // retrieves the value of mGUI
{
    return (mGUI);
}
void GUIComponents::setMGUI(MyGUIGuiSharedPtr set)  // sets the value of mGUI
{
    mGUI = set;
}

bool GUIComponents::initMyGUI(renderEngineSharedPtr render)  // Initializes MyGUI
{
//    exit(0);
//    renderEngineSharedPtr render; // = renderEngine::Instance();
    std::string func = "GUIComponents::initMyGUI()";
    
    logMsg(func +" begin");
    logMsg(func +" *** Initializing MyGUI ***");
    MyGUIOgrePlatformSharedPtr tempPlatform(new MyGUI::OgrePlatform());
    mPlatform = tempPlatform;
    logMsg(func +" Crash?");

    mPlatform->initialise(render->getMWindow().get(), render->getMSceneMgr().get(), "UBCData"); // mWindow is Ogre::RenderWindow*, mSceneManager is Ogre::SceneManager*a@aa

    logMsg(func +" Crash??");
    MyGUIGuiSharedPtr tempGUI(new MyGUI::Gui());
//    exit(0);
    mGUI = tempGUI;
//    exit(0);
    logMsg(func +" Crash???");
    mGUI->initialise();
//    exit(0);
    logMsg(func +" *** MyGUI Initialized ***");
    logMsg(func +" end");
    return true;
}

