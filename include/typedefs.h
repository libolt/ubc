/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
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

#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#ifndef _ENET_ISINCLUDED_
#define _ENET_ISINCLUDED_
#include "enet/enet.h"
#endif 5
;
#include <vector>
#include <unordered_map>
#include <boost/shared_ptr.hpp>

#include "BtOgrePG.h"
#include "BtOgreGP.h"
#include "BtOgreExtras.h"
#include "BulletDynamics/Dynamics/btRigidBody.h"

#include "enums.h"

#include "ai/steering.h"
//#include "offenseplays.h"

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

// forward declarations

class UBCBase;
class GUISystem;
class conversion;

class gameEngine;
class inputEngine;
class networkEngine;
class physicsEngine;
class renderEngine;

class playerEntity;

class basketballState;
class courtState;
class defenseState;
class gameState;
class hoopState;
class inputState;
class networkState;
class offenseState;
class playerState;
class teamState;

class courtData;

class loader;
class logging;
class userInput;

class AISystem;
class basketballSteer;
class playerSteer;
class playerSteerPlugin;
//class steering;
//class steering::AABBox;
//class OpenSteer;

class offensePlays;
//class offensePlays::playerDirectives;
class jumpBalls;
//class playerDirectives;
//class ENetHost;


#ifndef sharedPtr
#define sharedPtr std::shared_ptr
#endif

// typedefs

typedef sharedPtr<UBCBase> UBCBaseSharedPtr;

typedef sharedPtr<GUISystem> GUISystemSharedPtr;

typedef sharedPtr<conversion> conversionSharedPtr;

typedef sharedPtr<gameEngine> gameEngineSharedPtr;

typedef sharedPtr<inputEngine> inputEngineSharedPtr;

typedef sharedPtr<networkEngine> networkEngineSharedPtr;

typedef sharedPtr<physicsEngine> physicsEngineSharedPtr;

typedef sharedPtr<renderEngine> renderEngineSharedPtr;

typedef sharedPtr<playerEntity> playerEntitySharedPtr;

typedef sharedPtr<basketballState> basketballStateSharedPtr;

typedef sharedPtr<courtState> courtStateSharedPtr;

typedef sharedPtr<defenseState> defenseStateSharedPtr;

typedef sharedPtr<gameState> gameStateSharedPtr;

typedef sharedPtr<hoopState> hoopStateSharedPtr;

typedef sharedPtr<inputState> inputStateSharedPtr;

typedef sharedPtr<networkState> networkStateSharedPtr;

typedef sharedPtr<offenseState> offenseStateSharedPtr;

typedef sharedPtr<playerState> playerStateSharedPtr;

typedef sharedPtr<teamState> teamStateSharedPtr;

typedef sharedPtr<jumpBalls> jumpBallsSharedPtr;

typedef sharedPtr<AISystem> AISystemSharedPtr;

typedef sharedPtr<basketballSteer> basketballSteerSharedPtr;

typedef sharedPtr<playerSteer> playerSteerSharedPtr;

typedef sharedPtr<playerSteerPlugin> playerSteerPluginSharedPtr;

typedef sharedPtr<steering::AABBox> steeringAABBoxSharedPtr;

typedef sharedPtr<OpenSteer::AbstractVehicle> OpenSteerAbstractVehicleSharedPtr;

typedef sharedPtr<OpenSteer::PlugIn> OpenSteerPluginSharedPtr;

typedef sharedPtr<loader> loaderSharedPtr;

typedef sharedPtr<logging> loggingSharedPtr;

typedef sharedPtr<offensePlays> offensePlaysSharedPtr;

typedef sharedPtr<userInput> userInputSharedPtr;


typedef sharedPtr<ENetHost> ENetHostSharedPtr;

typedef sharedPtr<ENetPeer> ENetPeerSharedPtr;

typedef sharedPtr<ENetPacket> ENetPacketSharedPtr;

// OGRE Shared Ptr

typedef sharedPtr<Ogre::Entity> OgreEntitySharedPtr;

typedef sharedPtr<Ogre::SceneNode> OgreSceneNodeSharedPtr;


// MyGUI Shared Ptr

typedef sharedPtr<MyGUI::Gui> MyGUIGuiSharedPtr;

typedef sharedPtr<MyGUI::OgrePlatform> MyGUIOgrePlatformSharedPtr;

typedef sharedPtr<MyGUI::ListBox> MyGUIListBoxSharedPtr;

typedef sharedPtr<MyGUI::ImageBox> MyGUIImageBoxSharedPtr;

typedef sharedPtr<MyGUI::TextBox> MyGUITextBoxSharedPtr;

// physics

typedef sharedPtr<btDynamicsWorld> btDynamicsWorldSharedPtr;

typedef sharedPtr<btCollisionShape> btCollisionShapeSharedPtr;

typedef sharedPtr<BtOgre::RigidBodyState> BtOgreRigidBodyStateSharedPtr;

typedef sharedPtr<btRigidBody> btRigidBodySharedPtr;

// vector typedefs

typedef std::vector<sharedPtr<playerSteer> > playerSteerVecSharedPtr;

typedef std::vector<sharedPtr<basketballState> > basketballStateVecSharedPtr;

typedef std::vector<sharedPtr<hoopState> > hoopStateVecSharedPtr;

typedef std::vector<sharedPtr<playerState> > playerStateVecSharedPtr;

typedef std::vector<sharedPtr<teamState> > teamStateVecSharedPtr;

typedef std::vector<sharedPtr<courtState> > courtStateVecSharedPtr;

typedef std::vector<sharedPtr<offensePlays> > offensePlaysVecSharedPtr;

typedef std::vector<playerPositions> playerPositionsVec;

//typedef std::vector<offensePlays::playerDirectives> playerDirectivesVec;

typedef std::vector<courtData> courtDataVec;

typedef std::vector<inputKeyMaps>   inputKeyWorkQueues;
typedef std::vector<inputGamePadMaps>   inputGamePadWorkQueues;
typedef std::vector<inputInGameMaps> inputInGameWorkQueues;  // stores types of input processed by the engine
typedef std::vector<inputTypes> inputTypeQueues;  // stores types of input processed by the engine


typedef std::vector<sharedPtr<userInput> > userInputVecSharedPtr;

typedef std::vector<playerEntity> playerEntityVecSharedPtr;


typedef std::vector<basketballState> basketballStateVec;

typedef std::vector<courtState> courtStateVec;

typedef std::vector<hoopState> hoopStateVec;

typedef std::vector<playerState> playerStateVec;

typedef std::vector<teamState> teamStateVec;


typedef std::vector<playerSteer> playerSteerVec;

typedef std::vector<std::string> stdStringVec;

typedef std::vector<bool> boolVec;

typedef std::vector<size_t> sizeTVec;

typedef std::vector<Ogre::Vector3> OgreVector3Vec;

// Unordered_map shared pointers
typedef std::unordered_map<size_t, playerEntitySharedPtr, std::hash<int> > playerEntityUMSharedPtr;
//typedef std::unordered_map <size_t, playerEntitySharedPtr> playerEntityUMSharedPtr;

typedef std::unordered_map <size_t, basketballStateSharedPtr> basketballStateUMSharedPtr;
typedef std::unordered_map <size_t, courtStateSharedPtr> courtStateUMSharedPtr;

typedef std::unordered_map <size_t, hoopStateSharedPtr> hoopStateUMSharedPtr;

typedef std::unordered_map <size_t, playerStateSharedPtr> playerStateUMSharedPtr;

typedef std::unordered_map <size_t, teamStateSharedPtr> teamStateUMSharedPtr;

typedef std::unordered_map<std::string, sharedPtr<MyGUI::Button> > MyGUIButtonUMSharedPtr;

typedef std::unordered_map<size_t, sharedPtr<MyGUI::ListBox> > MyGUIListBoxUMSharedPtr;

typedef std::unordered_map<std::string, sharedPtr<MyGUI::ImageBox> > MyGUIImageBoxUMSharedPtr;

// Vector Unordered_map shared pointers

typedef std::vector<std::unordered_map <std::string, sharedPtr<MyGUI::ListBox> > > MyGUIListBoxVecUMSharedPtr;

typedef std::vector<std::unordered_map<std::string, sharedPtr<MyGUI::TextBox> > > MyGUITextBoxVecUMSharedPtr;

typedef std::vector<playerEntityUMSharedPtr> playerEntityVecUMSharedPtr;

#endif
