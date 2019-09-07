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

#include "components/hoopcomponents.h"
#include "entity/hoopentity.h"
#include "flags/hoopflags.h"
#include "statemachine/hoopstatemachine.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

hoopEntity::hoopEntity()  // constructor
{
    objectsInitialized = false;

}
hoopEntity::~hoopEntity()  = default;  // destructor

hoopComponentsSharedPtr hoopEntity::getComponent()  // retrieves the value of component
{
    return (component);
}
void hoopEntity::setComponent(hoopComponentsSharedPtr set)  // sets the value of component
{
    component = set;
}

hoopFlagsSharedPtr hoopEntity::getFlag()  // retrieves the value of flag
{
    return (flag);
}
void hoopEntity::setFlag(hoopFlagsSharedPtr set)  // sets the value of flag
{
    flag = set;
}

hoopStateMachineSharedPtr hoopEntity::getStateMachine() const  // retrievees the value of stateMachine
{
    return (stateMachine);
}
void hoopEntity::setStateMachine(const hoopStateMachineSharedPtr &set)  // sets the value of stateMachine
{
    stateMachine = set;
}

hoopActions hoopEntity::getAction() const  // retrieves the value of action
{
    return (action);
}
void hoopEntity::setAction(const hoopActions &set)  // sets the vlue of action
{
    action = set;
}


bool hoopEntity::initializeObjects()  // initializes hoop entity objects
{
    
    hoopComponentsSharedPtr tempComponent(new hoopComponents);
    component = tempComponent;
    
    hoopFlagsSharedPtr tempFlag(new hoopFlags);
    flag = tempFlag;

    hoopStateMachineSharedPtr tempStateMachine(new hoopStateMachine);
    stateMachine = tempStateMachine;

    return (true);
}

bool hoopEntity::initializeStateMachine()  // initializes the basketball stateMachine object
{

    std::string func = "hoopEntity::initializeStateMachine()";

    logMsg(func +" begin");

    if (!objectsInitialized)
    {
        logMsg(func +" Initializing objects!");
        objectsInitialized = initializeObjects();
    }
    else
    {
        logMsg(func +" Objects already initialized!");
    }

    hoopSMData *initSMData(new hoopSMData);

    initSMData->component = component;
//    initSMData->bData = data;
    initSMData->flag = flag;

    stateMachine->pInitialize(initSMData);

    logMsg(func +" end");
//    exit(0);
    return (true);
}

bool hoopEntity::updateStateMachine(renderEngineSharedPtr render)  // updates the stateMahine object
{

    conversionSharedPtr convert;
    bool modelNeedsLoaded = flag->getModelNeedsLoaded();
    hoopSMData *udSMData(new hoopSMData);
    hoopSMData *umSMData(new hoopSMData);
    hoopSMData *upSMData(new hoopSMData);

    std::string func = "courtEntity::updateStateMachine()";

    logMsg(func + " begin");

    if (objectsInitialized)
    {
        if (component != nullptr && component->getNode() != nullptr)
        {
            logMsg(func +" activeCourtInstance Pos = " +convert->toString(component->getNode()->getPosition()));
//            exit(0);
        }
    }
//    exit(0);
/*    if (entity->getModelNeedsLoaded())
    {

        if (entity->loadModel())
        {
            entity->setModelNeedsLoaded(false);
            entity->setModelLoaded(true);

        }
    }
*/
//    exit(0);
    if (flag->getStateChanged())
    {
        logMsg(func +" State Changed!");
//        exit(0);
        switch (action)
        {
            case HLOADMODEL:
                logMsg(func +" CLOADMODEL");
//                udSMData->cData = data;
                udSMData->component = component;
                udSMData->flag = flag;
                udSMData->render = render;
                stateMachine->pLoadModel(udSMData);
//                exit(0);
            break;
            case HCREATENODE:
                logMsg(func +" CCREATENODE");
                udSMData->component = component;
                udSMData->flag = flag;
                udSMData->render = render;
                stateMachine->pCreateNode(udSMData);
//                exit(0);
            break;
        }
        flag->setStateChanged(false);
        action = HNOACTION;
    }

    logMsg(func +" end");

    return (true);
}
