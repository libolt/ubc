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

#include "utilities/conversion.h"
#include "components/gamecomponents.h"
#include "components/teamcomponents.h"
#include "data/gamedata.h"
#include "data/playerdata.h"
#include "data/playergamedata.h"
#include "data/teamgamedata.h"
#include "entity/basketballentity.h"
#include "entity/courtentity.h"
#include "entity/playerentity.h"
#include "flags/gameflags.h"
#include "flags/playerflags.h"
#include "flags/teamflags.h"
#include "setup/setupplayers.h"
#include "setup/setupplayerpositions.h"
#include "physics/basketballphysics.h"
#include "state/teamstate.h"
#include "engine/gameengine.h"
#include "state/basketballstate.h"
//#include "state/courtstate.h"
#include "entity/gameentity.h"
#include "state/hoopstate.h"
#include "state/defensestate.h"
#include "state/playerstate.h"
#include "state/offensestate.h"
#include "statemachine/playerstatemachine.h"
#include "statistics/teamstatistics.h"
#include "utilities/logging.h"
#include "engine/physicsengine.h"
#include "ai/playersteer.h"
#include "utilities/enums.h"
#include "jumpballs.h"

// static declarations

teamState::teamState()  // constructor
{
    
}

teamState::~teamState()  // destructor
{
}

// FIXME! update for class reorganization






