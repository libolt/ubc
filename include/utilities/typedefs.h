/***************************************************************************
 *   Copyright (C) 1999 - 2018 by Mike McLean                              *
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
#endif 

#include <vector>
#include <unordered_map>
#include <boost/shared_ptr.hpp>

#include "BtOgrePG.h"
#include "BtOgreGP.h"
#include "BtOgreExtras.h"
#include "BulletDynamics/Dynamics/btRigidBody.h"

#include "utilities/enums.h"

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

class AISystem;

class basketballEntity;
class basketballState;
class basketballSteer;

class conversion;

class courtData;
class courtEntity;
class courtState;

class defenseState;

class gameComponents;
class gameData;
class gameEngine;
class gameEntity;
class gameFlags;
class setupBasketballs;
class setupCourts;
class setupHoops;
class setupLineups;
class setupPlayers;
class setupPlayerPositions;
class setupTeams;
//class gameState;
class GUISystem;
class GUIComponents;
class guiFlags;

class hoopEntity;
class hoopState;

class inputEngine;
class input;
class inputGamePads;
class inputKeyboards;

class jumpBalls;

class loader;
class loadBasketballs;
class loadCourts;
class loadHoops;
class loadOffensePlays;
class loadPlayers;
class loadTeams;
class loadUsersInputs;
class logging;

class networkEngine;
class networkState;

class offensePlays;
class offenseState;

class playerComponents;
class playerData;
class playerEntity;
class playerFlags;
class playerGameData;
class playerPhysics;
class playerStateMachine;
class playerStatistics;
class playerSteer;
class playerSteerPlugin;
class physicsEngine;

class renderEngine;

class teamComponents;
class teamData;
class teamEntity;
class teamFlags;
class teamGameData;
class teamState;
class teamStatistics;

class UBCComponents;
class UBCGame;
class UBCInput;

class updatePlayers;
class updateTeams;

class users;
class usersInputs;

#ifndef sharedPtr
#define sharedPtr std::shared_ptr
#endif

// typedefs

typedef sharedPtr<UBCGame> UBCGameSharedPtr;

typedef sharedPtr<UBCInput> UBCInputSharedPtr;

typedef sharedPtr<GUISystem> GUISystemSharedPtr;

typedef sharedPtr<GUIComponents> GUIComponentsSharedPtr;

typedef sharedPtr<guiFlags> guiFlagsSharedPtr;

typedef sharedPtr<conversion> conversionSharedPtr;

typedef sharedPtr<gameComponents> gameComponentsSharedPtr;

typedef sharedPtr<UBCComponents> UBCComponentsSharedPtr;

typedef sharedPtr<courtData> courtDataSharedPtr;

typedef sharedPtr<gameData> gameDataSharedPtr;

typedef sharedPtr<playerComponents> playerComponentsSharedPtr;

typedef sharedPtr<playerData> playerDataSharedPtr;

typedef sharedPtr<playerGameData> playerGameDataSharedPtr;

typedef sharedPtr<playerPhysics> playerPhysicsSharedPtr;

typedef sharedPtr<playerStateMachine> playerStateMachineSharedPtr;

typedef sharedPtr<playerStatistics> playerStatisticsSharedPtr;

typedef sharedPtr<gameEngine> gameEngineSharedPtr;

typedef sharedPtr<inputEngine> inputEngineSharedPtr;

typedef sharedPtr<networkEngine> networkEngineSharedPtr;

typedef sharedPtr<physicsEngine> physicsEngineSharedPtr;

typedef sharedPtr<renderEngine> renderEngineSharedPtr;

typedef sharedPtr<basketballEntity> basketballEntitySharedPtr;

typedef sharedPtr<courtEntity> courtEntitySharedPtr;

typedef sharedPtr<gameEntity> gameEntitySharedPtr;

typedef sharedPtr<hoopEntity> hoopEntitySharedPtr;

typedef sharedPtr<playerEntity> playerEntitySharedPtr;

typedef sharedPtr<gameFlags> gameFlagsSharedPtr;

typedef sharedPtr<playerFlags> playerFlagsSharedPtr;

typedef sharedPtr<basketballState> basketballStateSharedPtr;

typedef sharedPtr<courtState> courtStateSharedPtr;

typedef sharedPtr<defenseState> defenseStateSharedPtr;

//typedef sharedPtr<gameState> gameStateSharedPtr;

typedef sharedPtr<hoopState> hoopStateSharedPtr;

typedef sharedPtr<input> inputSharedPtr;

typedef sharedPtr<inputKeyboards> inputKeyboardsSharedPtr;
    
typedef sharedPtr<inputGamePads> inputGamePadsSharedPtr;

typedef sharedPtr<networkState> networkStateSharedPtr;

typedef sharedPtr<offenseState> offenseStateSharedPtr;

//typedef sharedPtr<playerState> playerStateSharedPtr;

typedef sharedPtr<teamComponents> teamComponentsSharedPtr;

typedef sharedPtr<teamData> teamDataSharedPtr;

typedef sharedPtr<teamEntity> teamEntitySharedPtr;

typedef sharedPtr<teamFlags> teamFlagsSharedPtr;

typedef sharedPtr<teamGameData> teamGameDataSharedPtr;

typedef sharedPtr<teamState> teamStateSharedPtr;

typedef sharedPtr<teamStatistics> teamStatisticsSharedPtr;

typedef sharedPtr<jumpBalls> jumpBallsSharedPtr;

typedef sharedPtr<AISystem> AISystemSharedPtr;

typedef sharedPtr<basketballSteer> basketballSteerSharedPtr;

typedef sharedPtr<playerSteer> playerSteerSharedPtr;

typedef sharedPtr<playerSteerPlugin> playerSteerPluginSharedPtr;

typedef sharedPtr<steering::AABBox> steeringAABBoxSharedPtr;

typedef sharedPtr<OpenSteer::AbstractVehicle> OpenSteerAbstractVehicleSharedPtr;

typedef sharedPtr<OpenSteer::PlugIn> OpenSteerPluginSharedPtr;

typedef sharedPtr<loader> loaderSharedPtr;

typedef sharedPtr<loadBasketballs> loadBasketballsSharedPtr;

typedef sharedPtr<loadCourts> loadCourtsSharedPtr;

typedef sharedPtr<loadHoops> loadHoopsSharedPtr;

typedef sharedPtr<loadOffensePlays> loadOffensePlaysSharedPtr;

typedef sharedPtr<loadPlayers> loadPlayersSharedPtr;

typedef sharedPtr<loadTeams> loadTeamsSharedPtr;

typedef sharedPtr<loadUsersInputs> loadUsersInputsSharedPtr;

typedef sharedPtr<logging> loggingSharedPtr;

typedef sharedPtr<offensePlays> offensePlaysSharedPtr;

typedef sharedPtr<updatePlayers> updatePlayersSharedPtr;

typedef sharedPtr<updateTeams> updateTeamsSharedPtr;

typedef sharedPtr<usersInputs> usersInputsSharedPtr;

typedef sharedPtr<users> usersSharedPtr;

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

// game setup classses

typedef sharedPtr<setupBasketballs> setupBasketballsSharedPtr;

typedef sharedPtr<setupCourts> setupCourtsSharedPtr;

typedef sharedPtr<setupHoops> setupHoopsSharedPtr;

typedef sharedPtr<setupLineups> setupLineupsSharedPtr;

typedef sharedPtr<setupPlayers> setupPlayersSharedPtr;

typedef sharedPtr<setupPlayerPositions> setupPlayerPositionsSharedPtr;

typedef sharedPtr<setupTeams> setupTeamsSharedPtr;

// vector typedefs

typedef std::vector<sharedPtr<playerSteer> > playerSteerVecSharedPtr;

typedef std::vector<basketballStateSharedPtr> basketballStateVecSharedPtr;

typedef std::vector<sharedPtr<hoopState> > hoopStateVecSharedPtr;

//typedef std::vector<sharedPtr<playerState> > playerStateVecSharedPtr;

typedef std::vector<sharedPtr<teamEntity> > teamEntityVecSharedPtr;
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


typedef std::vector<usersInputsSharedPtr> usersInputsVecSharedPtr;

typedef std::vector<playerEntity> playerEntityVecSharedPtr;


typedef std::vector<basketballState> basketballStateVec;

typedef std::vector<courtState> courtStateVec;

typedef std::vector<hoopState> hoopStateVec;

//typedef std::vector<playerState> playerStateVec;

typedef std::vector<teamState> teamStateVec;


typedef std::vector<playerSteer> playerSteerVec;

typedef std::vector<std::string> stdStringVec;

typedef std::vector<bool> boolVec;

typedef std::vector<size_t> sizeTVec;

typedef std::vector<Ogre::Vector3> OgreVector3Vec;

// Map shared pointers
//typedef std::map<size_t, playerEntitySharedPtr, std::hash<int> > playerEntityMSharedPtr;
typedef std::map <size_t, playerEntitySharedPtr> playerEntityMSharedPtr;

typedef std::map <size_t, basketballStateSharedPtr> basketballStateMSharedPtr;
typedef std::map <size_t, courtStateSharedPtr> courtStateMSharedPtr;

typedef std::map <size_t, hoopStateSharedPtr> hoopStateMSharedPtr;

//typedef std::map <size_t, playerStateSharedPtr> playerStateMSharedPtr;

typedef std::map <size_t, teamEntitySharedPtr> teamEntityMSharedPtr;

typedef std::map <size_t, teamStateSharedPtr> teamStateMSharedPtr;

typedef std::map <size_t, usersSharedPtr> usersMSharedPtr;

typedef std::map<std::string, sharedPtr<MyGUI::Button> > MyGUIButtonMSharedPtr;

typedef std::map<size_t, sharedPtr<MyGUI::ListBox> > MyGUIListBoxMSharedPtr;

typedef std::map<playerPositions, sharedPtr<MyGUI::ListBox> > MyGUIPlayerListBoxMSharedPtr;

typedef std::map<std::string, sharedPtr<MyGUI::TextBox> > MyGUITextBoxMSharedPtr;

typedef std::map<std::string, sharedPtr<MyGUI::ImageBox> > MyGUIImageBoxMSharedPtr;

typedef std::map<playerPositions, size_t> teamStarterIDsM;

// Vector Unordered_map shared pointers

//typedef std::vector<std::map <std::string, sharedPtr<MyGUI::ListBox> > > MyGUIListBoxVecMSharedPtr;

typedef std::vector <MyGUIListBoxMSharedPtr> MyGUIListBoxVecMSharedPtr;

typedef std::vector <MyGUIPlayerListBoxMSharedPtr> MyGUIPlayerListBoxVecMSharedPtr;

typedef std::vector<MyGUITextBoxMSharedPtr> MyGUITextBoxVecMSharedPtr;

typedef std::vector<basketballStateMSharedPtr> basketballStateVecMSharedPtr;

typedef std::vector<playerEntityMSharedPtr> playerEntityVecMSharedPtr;

// Vector maps
typedef std::vector<std::map<playerPositions, size_t> > teamStarterIDsVecM;
#endif
