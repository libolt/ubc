/***************************************************************************
 *   Copyright (C) 1999 - 2019 by Mike McLean                              *
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
//#include <boost/shared_ptr.hpp>

#ifdef BTOGRE_MYGUI_ENABLED
#include "BtOgrePG.h"
#include "BtOgreGP.h"
#include "BtOgreExtras.h"
#include "BulletDynamics/Dynamics/btRigidBody.h"
#endif

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

class basketballComponents;
class basketballData;
class basketballEntity;
class basketballFlags;
class basketballPhysics;
class basketballStateMachine;
class basketballSteer;

class conversion;

class courtComponents;;
class courtData;
class courtEntity;
class courtFlags;
class courtPhysics;
class courtStateMachine;

class defense;
class defenseComponents;
class defenseFlags;
class defenseStateMachine;

class gameComponents;
class gameData;
class gameEngine;
class gameEntity;
class gameFlags;
class gameStateMachine;
class gameSMData;
class setupBasketballs;
class setupCourts;
class setupHoops;
class setupLineups;
class setupPlayers;
class setupPlayerPositions;
class setupTeams;
//class gameState;
class GUISystem;
class guiComponents;
class guiCreate;
class guiData;
class guiDisplay;
class guiEvents;
class guiFlags;
class guiInput;
class guiStateMachine;

class hoopComponents;
class hoopEntity;
class hoopFlags;
class hoopPhysics;
class hoopStateMachine;

class inputEngine;
class input;
class inputGamePads;
class inputKeyboards;

class jumpBalls;
class jumpBallsExecute;

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

class offense;
class offenseComponents;
class offenseFlags;
class offensePlays;
class offenseStateMachine;

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
class teamStateMachine;
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

typedef sharedPtr<guiComponents> guiComponentsSharedPtr;

typedef sharedPtr<guiCreate> guiCreateSharedPtr;

typedef sharedPtr<guiData> guiDataSharedPtr;

typedef sharedPtr<guiDisplay> guiDisplaySharedPtr;

typedef sharedPtr<guiEvents> guiEventsSharedPtr;

typedef sharedPtr<guiFlags> guiFlagsSharedPtr;

typedef sharedPtr<guiInput> guiInputSharedPtr;

typedef sharedPtr<guiStateMachine> guiStateMachineSharedPtr;

typedef sharedPtr<conversion> conversionSharedPtr;

typedef sharedPtr<basketballComponents> basketballComponentsSharedPtr;

typedef sharedPtr<basketballData> basketballDataSharedPtr;

typedef sharedPtr<basketballFlags> basketballFlagsSharedPtr;

typedef sharedPtr<basketballPhysics> basketballPhysicsSharedPtr;

typedef sharedPtr<basketballStateMachine> basketballStateMachineSharedPtr;

typedef sharedPtr<gameComponents> gameComponentsSharedPtr;

typedef sharedPtr<gameStateMachine> gameStateMachineSharedPtr;

typedef sharedPtr<UBCComponents> UBCComponentsSharedPtr;

typedef sharedPtr<courtComponents> courtComponentsSharedPtr;

typedef sharedPtr<courtData> courtDataSharedPtr;

typedef sharedPtr<courtFlags> courtFlagsSharedPtr;

typedef sharedPtr<courtPhysics> courtPhysicsSharedPtr;

typedef sharedPtr<courtStateMachine> courtStateMachineSharedPtr;

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

typedef sharedPtr<hoopComponents> hoopComponentsSharedPtr;

typedef sharedPtr<hoopEntity> hoopEntitySharedPtr;

typedef sharedPtr<hoopFlags> hoopFlagsSharedPtr;

typedef sharedPtr<hoopPhysics> hoopPhysicsSharedPtr;

typedef sharedPtr<hoopStateMachine> hoopStateMachineSharedPtr;

typedef sharedPtr<playerEntity> playerEntitySharedPtr;

typedef sharedPtr<gameFlags> gameFlagsSharedPtr;

typedef sharedPtr<playerFlags> playerFlagsSharedPtr;

//typedef sharedPtr<basketballState> basketballEntitySharedPtr;

//typedef sharedPtr<courtState> courtStateSharedPtr;

typedef sharedPtr<defenseComponents> defenseComponentsSharedPtr;

typedef sharedPtr<defenseFlags> defenseFlagsSharedPtr;

typedef sharedPtr<defense> defenseSharedPtr;

typedef sharedPtr<defenseStateMachine> defenseStateMachineSharedPtr;

//typedef sharedPtr<gameState> gameStateSharedPtr;

//typedef sharedPtr<hoopState> hoopStateSharedPtr;

typedef sharedPtr<input> inputSharedPtr;

typedef sharedPtr<inputKeyboards> inputKeyboardsSharedPtr;
    
typedef sharedPtr<inputGamePads> inputGamePadsSharedPtr;

typedef sharedPtr<networkState> networkStateSharedPtr;

typedef sharedPtr<offenseComponents> offenseComponentsSharedPtr;

typedef sharedPtr<offenseFlags> offenseFlagsSharedPtr;

typedef sharedPtr<offense> offenseSharedPtr;

typedef  sharedPtr<offenseStateMachine> offenseStateMachineSharedPtr;

//typedef sharedPtr<playerState> playerStateSharedPtr;

typedef sharedPtr<teamComponents> teamComponentsSharedPtr;

typedef sharedPtr<teamData> teamDataSharedPtr;

typedef sharedPtr<teamEntity> teamEntitySharedPtr;

typedef sharedPtr<teamFlags> teamFlagsSharedPtr;

typedef sharedPtr<teamGameData> teamGameDataSharedPtr;

typedef sharedPtr<teamStateMachine> teamStateMachineSharedPtr;

typedef sharedPtr<teamStatistics> teamStatisticsSharedPtr;

typedef sharedPtr<jumpBalls> jumpBallsSharedPtr;

typedef sharedPtr<jumpBallsExecute> jumpBallsExecuteSharedPtr;

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

#ifdef BTOGRE_MYGUI_ENABLED

// physics

typedef sharedPtr<btDynamicsWorld> btDynamicsWorldSharedPtr;

typedef sharedPtr<btCollisionShape> btCollisionShapeSharedPtr;

typedef sharedPtr<BtOgre::RigidBodyState> BtOgreRigidBodyStateSharedPtr;

typedef sharedPtr<btRigidBody> btRigidBodySharedPtr;
#endif

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

typedef std::vector<basketballEntitySharedPtr> basketballEntityVecSharedPtr;

typedef std::vector<sharedPtr<hoopEntity> > hoopEntityVecSharedPtr;

//typedef std::vector<sharedPtr<playerState> > playerStateVecSharedPtr;

typedef std::vector<sharedPtr<teamEntity> > teamEntityVecSharedPtr;
typedef std::vector<sharedPtr<teamStateMachine> > teamStateMachineVecSharedPtr;

typedef std::vector<sharedPtr<courtEntity> > courtEntityVecSharedPtr;

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


typedef std::vector<basketballEntity> basketballEntityVec;

typedef std::vector<courtEntity> courtEntityVec;

typedef std::vector<hoopEntity> hoopEntityVec;

//typedef std::vector<playerState> playerStateVec;

typedef std::vector<teamStateMachine> teamStateMachineVec;


typedef std::vector<playerSteer> playerSteerVec;

typedef std::vector<std::string> stdStringVec;

typedef std::vector<bool> boolVec;

typedef std::vector<size_t> sizeTVec;

typedef std::vector<Ogre::Vector3> OgreVector3Vec;

// Map shared pointers
//typedef std::map<size_t, playerEntitySharedPtr, std::hash<int> > playerEntityMSharedPtr;
typedef std::map <size_t, playerEntitySharedPtr> playerEntityMSharedPtr;

typedef std::map <size_t, basketballEntitySharedPtr> basketballEntityMSharedPtr;
typedef std::map <size_t, courtEntitySharedPtr> courtEntityMSharedPtr;

typedef std::map <size_t, hoopEntitySharedPtr> hoopEntityMSharedPtr;

//typedef std::map <size_t, playerStateSharedPtr> playerStateMSharedPtr;

typedef std::map <size_t, teamEntitySharedPtr> teamEntityMSharedPtr;

typedef std::map <size_t, teamStateMachineSharedPtr> teamStateMachineMSharedPtr;

typedef std::map <size_t, usersSharedPtr> usersMSharedPtr;

#ifdef BTOGRE_MYGUI_ENABLED

typedef std::map<std::string, sharedPtr<MyGUI::Button> > MyGUIButtonMSharedPtr;

typedef std::map<size_t, sharedPtr<MyGUI::ListBox> > MyGUIListBoxMSharedPtr;

typedef std::map<playerPositions, sharedPtr<MyGUI::ListBox> > MyGUIPlayerListBoxMSharedPtr;

typedef std::map<std::string, sharedPtr<MyGUI::TextBox> > MyGUITextBoxMSharedPtr;

typedef std::map<std::string, sharedPtr<MyGUI::ImageBox> > MyGUIImageBoxMSharedPtr;
#endif

typedef std::map<playerPositions, size_t> teamStarterIDsM;

// Vector Unordered_map shared pointers

//typedef std::vector<std::map <std::string, sharedPtr<MyGUI::ListBox> > > MyGUIListBoxVecMSharedPtr;

typedef std::vector <MyGUIListBoxMSharedPtr> MyGUIListBoxVecMSharedPtr;

typedef std::vector <MyGUIPlayerListBoxMSharedPtr> MyGUIPlayerListBoxVecMSharedPtr;

typedef std::vector<MyGUITextBoxMSharedPtr> MyGUITextBoxVecMSharedPtr;

typedef std::vector<basketballEntityMSharedPtr> basketballEntityVecMSharedPtr;

typedef std::vector<playerEntityMSharedPtr> playerEntityVecMSharedPtr;

// Vector maps
typedef std::vector<std::map<playerPositions, size_t> > teamStarterIDsVecM;
#endif
