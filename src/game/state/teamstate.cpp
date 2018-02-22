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
#include "gamesetup/gamesetupplayers.h"
#include "gamesetup/gamesetupplayerpositions.h"
#include "physics/basketballphysics.h"
#include "state/teamstate.h"
#include "engine/gameengine.h"
#include "state/basketballstate.h"
#include "state/courtstate.h"
#include "state/gamestate.h"
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

void teamState::executePass()  // executes the pass between players
{

//FIXME! Needs fixed after playerStateMachine is implemented
/*
    //conversion *convert = conversion::Instance();
    conversionSharedPtr convert = conversion::Instance();
    //gameState *gameS = gameState::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
//    size_t activeBBallInstance = gameInstance->getActiveBBallInstance();
    playerPositions passToPlayer = activePlayerInstance[convert->toString(playerWithBallInstance)]->getPassToPlayer();
//    basketballStateVecSharedPtr basketballInstance = gameInstance->getBasketballInstance();
    basketballStateMSharedPtr activeBasketballInstance = gameInstance->getActiveBasketballInstance();
    Ogre::Vector3 playerWithBallCoords = activePlayerInstance[convert->toString(playerWithBallInstance)]->getNode()->getPosition();
    Ogre::Vector3 passToPlayerCoords = activePlayerInstance[convert->toString(passToPlayer)]->getNode()->getPosition();
//  exit(0);
    // FIXME! HARDCODED
    Ogre::Vector3 bballCoords = activeBasketballInstance[0]->getNode()->getPosition();
    btVector3 bballPosChange;
    btVector3 bballPhysCoords;
    btTransform transform;
//  exit(0);
    std::string func = "teamState::executePass()";
    
    logMsg(func +" beginning");

    logMsg(func +" Basketball = " + convert->toString(bballCoords));
    logMsg(func +" passToPlayer = " + convert->toString(passToPlayerCoords));

    if (bballCoords[1] != passToPlayerCoords[1])
    {
        bballCoords[1] = passToPlayerCoords[1];
        // FIXME! HARDCODED
        activeBasketballInstance[0]->getNode()->setPosition(bballCoords);
        bballPhysCoords = BtOgre::Convert::toBullet(bballCoords); // converts from Ogre::Vector3 to btVector3
        transform.setOrigin(bballPhysCoords);
        // FIXME! HARDCODED
        activeBasketballInstance[0]->getPhysics()->getPhysBody()->setWorldTransform(transform);


    }
    if (bballCoords[0] < passToPlayerCoords[0])
    {
        if (bballCoords[2] < passToPlayerCoords[2])
        {
//          basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(15,0,15));
            bballPosChange[0] = 15;
            bballPosChange[2] = 15;
        }
        else if (bballCoords[2] > passToPlayerCoords[2])
        {
//          basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(15,0,-15));
            bballPosChange[0] = 15;
            bballPosChange[2] = -15;

        }
        else
        {
        }
    }
    else if (bballCoords[0] > passToPlayerCoords[0])
    {
        if (bballCoords[2] < passToPlayerCoords[2])
        {
//          basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(-15,0,15));
            bballPosChange[0] = -15;
            bballPosChange[2] = 15;

        }
        else if (bballCoords[2] > passToPlayerCoords[2])
        {
//          basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(-15,0,-15));
            bballPosChange[0] = -15;
            bballPosChange[2] = -15;

        }
        else
        {
        }
    }
    else
    {
    }

    activeBasketballInstance[0]->getPhysics()->getPhysBody()->setLinearVelocity(btVector3(bballPosChange));


    gameInstance->setActiveBasketballInstance(activeBasketballInstance);        // saves changes to the basketballInstance object
*/
}




