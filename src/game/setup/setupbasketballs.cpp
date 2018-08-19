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

#include "setup/setupbasketballs.h"
#include "entity/basketballentity.h"
#include "data/basketballdata.h"
//#include "state/basketballstate.h"
#include "ai/basketballsteer.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"
#include "load/loadbasketballs.h"

setupBasketballs::setupBasketballs()  // constructor
{
    
}
setupBasketballs::~setupBasketballs()  // destructor
{
    
}

basketballEntityMSharedPtr setupBasketballs::createBasketballInstances()  // creates basketball Instances
{
    basketballEntityMSharedPtr basketballInstance;
    loadBasketballsSharedPtr loadBasketball(new loadBasketballs);
    basketballInstance = loadBasketball->loadFiles();
    std::string func = "setupBasketballs::createBasketballInstance()";

    logMsg(func +" begin");
//    exit(0);
    logMsg(func +" creating temporary baskteball instance");
    logMsg(func +" setting model name");
//  FIXME! these are currently hard coded
    size_t bballNum = 0;

    for (auto BIIT : basketballInstance)  // loop
    {
        BIIT.second->setModelFileName("bball.mesh");
        BIIT.second->setName(BIIT.second->getData()->getModelFileName());
        BIIT.second->setNodeName(BIIT.second->getData()->getModelFileName());
/*BASEREMOVAL        if (!BIIT.second->getEntity()->getBaseInitialized())
        {
//            BIIT.second->getEntity()->setBase(getBase());
        }
*/
        logMsg(func +" creating steer object");
        basketballSteer *bballSteer = new basketballSteer;  // steer instance
        BIIT.second->setSteer(basketballSteerSharedPtr(bballSteer));
        logMsg(func +" setting instance number");
        BIIT.second->setNumber(bballNum);
        BIIT.second->setNumberSet(true);
        bballNum++;
    }

//    bballInstance->setModelNeedsLoaded(true);
//    getBasketballInstance().push_back(bballInstance);

    logMsg(func +" end");

    return (basketballInstance);
}

basketballEntityMSharedPtr setupBasketballs::createActiveBasketballInstances(basketballEntityMSharedPtr basketballInstance, size_t numActiveBasketballs)  // creates active basketball instances
{    
    conversionSharedPtr convert = conversion::Instance();
    loadBasketballsSharedPtr loadBasketball;  // = base->getLoad();
//    basketballEntityMSharedPtr basketballInstance = getBasketballInstance();
    basketballEntityMSharedPtr activeBasketballInstance;
    std::string func = "gameState::createActiveBasketballInstances()";

    logMsg(func +" begin");

    logMsg(func +" basketballInstance.size() == " +convert->toString(basketballInstance.size()));
    if (basketballInstance.size() == 0)
    {
        if (loadBasketball->checkIfBasketballFilesLoaded())
        {
            basketballInstance = loadBasketball->getBInstance();
        }
        else
        {
            logMsg(func +" Failed to load Basketball Instances!");
            exit(0);
        }
    }
    else
    {

    }

    //FIXME! should not be hard coded
//    setNumActiveBasketballs(1);
    logMsg("Creating Active Basketball Instances!");
    for (auto x=0; x<numActiveBasketballs; ++x)
    {
        activeBasketballInstance.insert(std::pair<size_t, basketballEntitySharedPtr>(x, basketballInstance[x]));
//        activeBasketballInstance[x]->setGameS(base->getGameS());
    }
//    setBasketballInstance(basketballInstance);
//    setActiveBasketballInstance(activeBasketballInstance);
    logMsg(func +" end");
    return (activeBasketballInstance);
}

basketballEntityMSharedPtr setupBasketballs::setBasketballStartPositions(basketballEntityMSharedPtr activeBasketballInstance)  // sets the initial coordinates for the basketball(s)
{
    conversionSharedPtr convert = conversion::Instance();
//    size_t activeBBallInstance = getActiveBBallInstance();
//    basketballStateVecSharedPtr basketballInstance = getBasketballInstance();
//    basketballEntityMSharedPtr activeBasketballInstance = component->getActiveBasketballInstance();
    std::string func = "setupBasketballs::setBasketballStartPositions()";
    
    logMsg(func +" begin");

    for (auto ABIIT : activeBasketballInstance)
    {
        
        logMsg(func +" activeBasketballInstance == " +convert->toString(ABIIT.first));
    
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//    exit(0);
        ABIIT.second->getNode()->setPosition(0.8f,10.0f,352.0f);
#else
        ABIIT.second->getNode()->setPosition(0.8f,-5.0f,352.0f);
//    exit(0);
#endif
    }
    
    logMsg(func +" end");
    
    return (activeBasketballInstance);
    
}
