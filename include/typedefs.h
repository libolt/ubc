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

#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#ifndef _ENET_ISINCLUDED_
#define _ENET_ISINCLUDED_
#include "enet/enet.h"
#endif 

#include <vector>

#include <boost/shared_ptr.hpp>

#include "BtOgrePG.h"
#include "BtOgreGP.h"
#include "BtOgreExtras.h"
#include "BulletDynamics/Dynamics/btRigidBody.h"

#include "enums.h"

#include "ai/steering.h"
//#include "offenseplays.h"

// forward declarations

class UBCBase;
class GUISystem;
class conversion;

class gameEngine;
class inputEngine;
class networkEngine;
class physicsEngine;
class renderEngine;

class basketballState;
class courtState;
class gameState;
class hoopState;
class inputState;
class networkState;
class playerState;
class teamState;

class courtData;

class logging;
class userInput;

class AISystem;
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


// typedefs
typedef boost::shared_ptr<UBCBase> UBCBaseSharedPtr;

typedef boost::shared_ptr<GUISystem> GUISystemSharedPtr;

typedef boost::shared_ptr<conversion> conversionSharedPtr; 


typedef boost::shared_ptr<gameEngine> gameEngineSharedPtr;

typedef boost::shared_ptr<inputEngine> inputEngineSharedPtr;

typedef boost::shared_ptr<networkEngine> networkEngineSharedPtr;

typedef boost::shared_ptr<physicsEngine> physicsEngineSharedPtr;

typedef boost::shared_ptr<renderEngine> renderEngineSharedPtr;


typedef boost::shared_ptr<basketballState> basketballStateSharedPtr;

typedef boost::shared_ptr<courtState> courtStateSharedPtr;

typedef boost::shared_ptr<gameState> gameStateSharedPtr;

typedef boost::shared_ptr<hoopState> hoopStateSharedPtr;

typedef boost::shared_ptr<inputState> inputStateSharedPtr;

typedef boost::shared_ptr<networkState> networkStateSharedPtr;

typedef boost::shared_ptr<playerState> playerStateSharedPtr;

typedef boost::shared_ptr<teamState> teamStateSharedPtr;

typedef boost::shared_ptr<jumpBalls> jumpBallsSharedPtr;

typedef boost::shared_ptr<AISystem> AISystemSharedPtr;

typedef boost::shared_ptr<playerSteer> playerSteerSharedPtr;

typedef boost::shared_ptr<playerSteerPlugin> playerSteerPluginSharedPtr;

typedef boost::shared_ptr<steering::AABBox> steeringAABBoxSharedPtr;

typedef boost::shared_ptr<OpenSteer::AbstractVehicle> OpenSteerAbstractVehicleSharedPtr;

typedef boost::shared_ptr<OpenSteer::PlugIn> OpenSteerPluginSharedPtr;
typedef boost::shared_ptr<logging> loggingSharedPtr;

typedef boost::shared_ptr<offensePlays> offensePlaysSharedPtr;

typedef boost::shared_ptr<userInput> userInputSharedPtr;


typedef boost::shared_ptr<ENetHost> ENetHostSharedPtr;

typedef boost::shared_ptr<ENetPeer> ENetPeerSharedPtr;

typedef boost::shared_ptr<ENetPacket> ENetPacketSharedPtr;

// physics

typedef boost::shared_ptr<btDynamicsWorld> btDynamicsWorldSharedPtr;

// vector typedefs

typedef std::vector<boost::shared_ptr<playerSteer> > playerSteerVecSharedPtr;

typedef std::vector<boost::shared_ptr<basketballState> > basketballStateVecSharedPtr;

typedef std::vector<boost::shared_ptr<hoopState> > hoopStateVecSharedPtr;

typedef std::vector<boost::shared_ptr<playerState> > playerStateVecSharedPtr;

typedef std::vector<boost::shared_ptr<teamState> > teamStateVecSharedPtr;

typedef std::vector<boost::shared_ptr<courtState> > courtStateVecSharedPtr;

typedef std::vector<boost::shared_ptr<offensePlays> > offensePlaysVecSharedPtr;

typedef std::vector<playerPositions> playerPositionsVec;

//typedef std::vector<offensePlays::playerDirectives> playerDirectivesVec;

typedef std::vector<courtData> courtDataVec;

typedef std::vector<inputKeyMaps>   inputKeyWorkQueues;
typedef std::vector<inputGamePadMaps>   inputGamePadWorkQueues;
typedef std::vector<inputInGameMaps> inputInGameWorkQueues;  // stores types of input processed by the engine
typedef std::vector<inputTypes> inputTypeQueues;  // stores types of input processed by the engine


typedef std::vector<boost::shared_ptr<userInput> > userInputVecSharedPtr;

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

#endif
