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
class logging;
class userInput;

class AISystem;

class offensePlays;

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


typedef boost::shared_ptr<AISystem> AISystemSharedPtr;
typedef boost::shared_ptr<logging> loggingSharedPtr;

typedef boost::shared_ptr<offensePlays> offensePlaysSharedPtr;

typedef boost::shared_ptr<userInput> userInputSharedPtr;

typedef boost::shared_ptr<ENetHost> ENetHostSharedPtr;

#endif
