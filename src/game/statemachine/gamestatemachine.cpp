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
#include "statemachine/gamestatemachine.h"
#include "components/gamecomponents.h"
#include "data/gamedata.h"
#include "engine/renderengine.h"
#include "entity/basketballentity.h"
#include "entity/courtentity.h"
#include "entity/hoopentity.h"
#include "flags/gameflags.h"
#include "jumpballs/jumpballs.h"
#include "jumpballs/jumpballsexecute.h"
#include "load/loadbasketballs.h"
#include "load/loadcourts.h"
#include "load/loadhoops.h"
#include "setup/setupbasketballs.h"
#include "setup/setupcourts.h"
#include "setup/setuphoops.h"
#include "setup/setupjumpballs.h"
#include "setup/setupteams.h"
//#include "state/basketballstate.h"
//#include "state/courtstate.h"
//#include "state/hoopstate.h"
#include "utilities/logging.h"

gameStateMachine::gameStateMachine() :
    stateMachine(ST_MAX_STATES)    
{
}

void gameStateMachine::pCreateInstances(gameSMData *data) // creates the object instances
{
    std:: string func = "gameStateMachine::pCreateInstances";
    
    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_CREATE_INSTANCES)          // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_CREATE_INSTANCES)          // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_CREATE_INSTANCES)          // ST_CREATE_NODES
        TRANSITION_MAP_ENTRY (ST_CREATE_INSTANCES)          // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (ST_CREATE_INSTANCES)          // ST_IDLE
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SETUP_JUMPBALL
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_EXECUTE_JUMPBALL
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_START
        TRANSITION_MAP_ENTRY (ST_CREATE_INSTANCES)          // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SHOOT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_PASS
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);

}

void gameStateMachine::pLoadModels(gameSMData *data) // loads the object models
{
    std:: string func = "gameStateMachine::pLoadModels";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_LOAD_MODELS)               // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_LOAD_MODELS)               // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_LOAD_MODELS)               // ST_CREATE_NODES
        TRANSITION_MAP_ENTRY (ST_LOAD_MODELS)               // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SETUP_JUMPBALL
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_EXECUTE_JUMPBALL
        TRANSITION_MAP_ENTRY (ST_LOAD_MODELS)               // ST_IDLE
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_START
        TRANSITION_MAP_ENTRY (ST_LOAD_MODELS)               // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SHOOT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_PASS
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);

}
void gameStateMachine::pCreateNodes(gameSMData *data) // creates the scene nodes and attaches models
{
    std:: string func = "gameStateMachine::pCreateNodes";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_CREATE_NODES)             // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_CREATE_NODES)             // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_CREATE_NODES)             // ST_CREATE_NODES
        TRANSITION_MAP_ENTRY (ST_CREATE_NODES)             // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SETUP_JUMPBALL
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_EXECUTE_JUMPBALL
        TRANSITION_MAP_ENTRY (ST_CREATE_NODES)             // ST_IDLE
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_START
        TRANSITION_MAP_ENTRY (ST_CREATE_NODES)             // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SHOOT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_PASS
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);

}
// set player speed external event
void gameStateMachine::pSetStartPositions(gameSMData *data)
{
    std:: string func = "gameStateMachine::pSetStartPositions";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_SET_START_POS)            // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_SET_START_POS)            // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_SET_START_POS)            // ST_CREATE_NODES
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SETUP_JUMPBALL
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_EXECUTE_JUMPBALL
        TRANSITION_MAP_ENTRY (ST_SET_START_POS)            // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_SET_START_POS)              // ST_START
        TRANSITION_MAP_ENTRY (ST_SET_START_POS)              // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SHOOT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_PASS
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);
}

// halt player external event
void gameStateMachine::halt()
{
    std:: string func = "playerStateMachine::halt";

    logMsg(func +" begin");

  /*  BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_CREATE_NODES
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_SETUP_JUMPBALL
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_EXECUTE_JUMPBALL
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_START
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_STOP_MOVEMENT)             // ST_CHANGE_SPEED

        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_SHOOT
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)                // ST_PASS
    END_TRANSITION_MAP(nullptr)
*/
    logMsg(func +" end");

}
    
// Setup Jump Ball external event
void gameStateMachine::pSetupJumpBall(gameSMData *data)
{
    std:: string func = "gameStateMachine::pSetupJumpBall";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_SETUP_JUMPBALL)                      // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_SETUP_JUMPBALL)                      // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_SETUP_JUMPBALL)                      // ST_CREATE_NODES
        TRANSITION_MAP_ENTRY (ST_SETUP_JUMPBALL)                      // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SETUP_JUMPBALL
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_EXECUTE_JUMPBALL
        TRANSITION_MAP_ENTRY (ST_SETUP_JUMPBALL)                      // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_SETUP_JUMPBALL)                      // ST_START
        TRANSITION_MAP_ENTRY (ST_SETUP_JUMPBALL)                      // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_SETUP_JUMPBALL)                      // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_SHOOT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)                // ST_PASS
    END_TRANSITION_MAP(data)
    logMsg(func +" end");
//    exit(0);
}
   
// Execute Jump Ball external event
void gameStateMachine::pExecuteJumpBall(gameSMData *data)
{
    std:: string func = "gameStateMachine::pExecuteJumpBall";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_EXECUTE_JUMPBALL)          // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_EXECUTE_JUMPBALL)          // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_EXECUTE_JUMPBALL)          // ST_CREATE_NODES
        TRANSITION_MAP_ENTRY (ST_EXECUTE_JUMPBALL)          // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (ST_EXECUTE_JUMPBALL)          // ST_SETUP_JUMPBALL
        TRANSITION_MAP_ENTRY (ST_EXECUTE_JUMPBALL)          // ST_EXECUTE_JUMPBALL
        TRANSITION_MAP_ENTRY (ST_EXECUTE_JUMPBALL)          // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_EXECUTE_JUMPBALL)          // ST_START
        TRANSITION_MAP_ENTRY (ST_EXECUTE_JUMPBALL)          // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_EXECUTE_JUMPBALL)          // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_EXECUTE_JUMPBALL)          // ST_SHOOT
        TRANSITION_MAP_ENTRY (ST_EXECUTE_JUMPBALL)          // ST_PASS
    END_TRANSITION_MAP(data)

    logMsg(func +" end");

            //    exit(0);
}
    
// change  player position external event
void gameStateMachine::pChangePosition(gameSMData *data)
{
    std:: string func = "playerStateMachine::pChangePosition";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_CREATE_NODES
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_SETUP_JUMPBALL
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_EXECUTE_JUMPBALL
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_START
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_CHANGE_POSITION
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_CHANGE_SPEED
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_SHOOT
        TRANSITION_MAP_ENTRY (ST_CHANGE_POSITION)           // ST_PASS
    END_TRANSITION_MAP(data)
    logMsg(func +" end");
//    exit(0);
}

// creates game object instances
STATE_DEFINE(gameStateMachine, createInstances, gameSMData)
{
    conversionSharedPtr convert ;
    setupBasketballsSharedPtr setupBasketball(new setupBasketballs);
    setupCourtsSharedPtr setupCourt(new setupCourts);
    setupHoopsSharedPtr setupHoop(new setupHoops);
    setupTeamsSharedPtr setupTeam(new setupTeams);
    std:: string func = "gameStateMachine::createInstances";

    logMsg(func +" begin");

/*    gameFlagsSharedPtr tempFlag(new gameFlags);
    data->flag = tempFlag;
*/
    if (!data->flag->getActiveBasketballInstancesCreated())
    {
        basketballEntityMSharedPtr activeBasketballInstance = setupBasketball->createBasketballInstances();
        if (!activeBasketballInstance.empty())
        {
            logMsg("activeBasketballInstances Created!");
            basketballEntitySharedPtr tempBasketball(new basketballEntity);

/*            for (auto ABIIT : activeBasketballInstance) // loop that checks if each active hoop instance's entity has been initialized
            {
                if (!ABIIT.second->getEntityInitialized()) // if not initialized it initializes the entity
                {
                    ABIIT.second->setEntity(tempBasketball);
                    ABIIT.second->setEntityInitialized(true);
                }
                else
                {

                }
            }*/

            data->flag->setActiveBasketballInstancesCreated(true);
            data->component->setActiveBasketballInstance(activeBasketballInstance);
        }
        else
        {
            logMsg(func +" Unable to create Active Basketball Instances!");
            exit(0);
        }
    }
    else
    {
        
    }

    if (!data->flag->getCourtInstancesCreated())
    {
        courtEntityMSharedPtr courtInstance = setupCourt->createCourtInstances();
        if (!courtInstance.empty())
        {
            logMsg(func +" Court Instances Created!!");
            data->flag->setCourtInstancesCreated(true);
            data->component->setCourtInstance(courtInstance);
        }
        else
        {
            logMsg(func +" Unable to Create Court Instances!");
            exit(0);
        }
    }
    if (!data->flag->getActiveCourtInstancesCreated())
    {
        courtEntityMSharedPtr courtInstance = data->component->getCourtInstance();
        courtEntityMSharedPtr activeCourtInstance;
        activeCourtInstance = setupCourt->createActiveCourtInstances(courtInstance);
        if (!activeCourtInstance.empty())
        {
            logMsg(func +" Active Court Instances Created!!");

            courtEntitySharedPtr tempCourt(new courtEntity);

            for (auto ACIIT : activeCourtInstance) // loop that checks if each active hoop instance's entity has been initialized
            {
                if (!ACIIT.second->getInitialized()) // if not initialized it initializes the entity
                {
                    ACIIT.second = tempCourt;
                    ACIIT.second->setInitialized(true);
                }
                else
                {

                }
            }
            data->flag->setActiveCourtInstancesCreated(true);
            data->component->setActiveCourtInstance(activeCourtInstance);
        }
        else
        {
            logMsg(func +" Unable to create Active Court Instances!");
            exit(0);
        }
    }
    else
    {

    }
    
    if (!data->flag->getHoopInstancesCreated())
    {
        hoopEntityMSharedPtr hoopInstance = setupHoop->createHoopInstances();
        if (!hoopInstance.empty())
        {
            logMsg(func +"Hoop Instances Created!");
            data->flag->setHoopInstancesCreated(true);
            data->component->setHoopInstance(hoopInstance);
        }
        else
        {
            logMsg(func +" Unable to Create Hoop Instances!");
            exit(0);
        }

    }
    logMsg(func +" hoop instance size == " +convert->toString(data->component->getHoopInstance().size()));
    logMsg(func +" hoop instance name == " +data->component->getHoopInstance()[0]->getName());
        
    if (!data->flag->getActiveHoopInstancesCreated())
    {
        //FIXME! Should not be hard coded!
        size_t numActiveHoops = 2;
        hoopEntityMSharedPtr hoopInstance = data->component->getHoopInstance();
        hoopEntityMSharedPtr activeHoopInstance = setupHoop->createActiveHoopInstances(hoopInstance, numActiveHoops);
        logMsg(func +" active hoop instance size == " +convert->toString(activeHoopInstance.size()));
        logMsg(func +" active hoop instance name == " +activeHoopInstance[0]->getName());
//        exit(0);
        
        if (!activeHoopInstance.empty())
        {
            logMsg(func +"Active Hoop Instances Created!");
//            exit(0);
            hoopEntitySharedPtr tempHoop(new hoopEntity);

            for (auto AHIIT : activeHoopInstance) // loop that checks if each active hoop instance's entity has been initialized
            {
                AHIIT.second = tempHoop;           
                logMsg(func +" active hoop instance name == " +AHIIT.second->getName());

            }          
//            exit(0);

        }
        else
        {
            logMsg(func +" Unable to create Active Hoop Instances!");
            exit(0);
        }
        data->flag->setActiveHoopInstancesCreated(true);
        data->component->setActiveHoopInstance(activeHoopInstance);

    }
    else
    {
        
    }
    logMsg(func +" activeHoopInstance.size() == " +convert->toString(data->component->getActiveHoopInstance().size()));
    logMsg(func +" end");
//    exit(0);
}

// loads the model object
STATE_DEFINE(gameStateMachine, loadModels, gameSMData)
{
    conversionSharedPtr convert ;
    std:: string func = "gameStateMachine::loadModels";

    logMsg(func +" begin");
//    exit(0);
    
    
    if (!data->flag->getBasketballModelLoaded())  // Checks if basketball model has been loaded
    {
        logMsg(func +" Basketball models not loaded!");
//        exit(0);
//        setActiveBBallInstance(0);  // Sets the active basketball instance
        loadBasketballsSharedPtr loadBasketball(new loadBasketballs);
        basketballEntityMSharedPtr activeBasketballInstance;
        logMsg(func +" Loading basketball Model!");
//        exit(0);
        activeBasketballInstance = loadBasketball->loadModels(data->component->getActiveBasketballInstance(), data->render);  // Loads the basketball model
//        exit(0);
        if (!activeBasketballInstance.empty())
        {          
            data->flag->setBasketballModelLoaded(true);
            data->component->setActiveBasketballInstance(activeBasketballInstance);          
//            return (true);
        }
        else
        {
            logMsg(func +" Unable to load basketball model!");
//            returnType = false;
        }

        // FIXEME! this should not be hard coded
    }
    else
    {
        logMsg(func +" Basketball models loaded!");
//        exit(0);
    }
    logMsg(func +" weeee");
//    exit(0);

    if (!data->flag->getCourtModelLoaded())  // Checks if the court model has been loaded
    {
        logMsg(func +" Court models not loaded!");
//        exit(0);
        loadCourtsSharedPtr loadCourt(new loadCourts);
        courtEntityMSharedPtr activeCourtInstance;
        
        logMsg(func +" Loading court model!");
//        exit(0);
        activeCourtInstance = loadCourt->loadModels(data->component->getActiveCourtInstance(), data->render);  // load the court model
        if (!activeCourtInstance.empty())
        {
            data->flag->setCourtModelLoaded(true);
            data->component->setActiveCourtInstance(activeCourtInstance);
//            return (true);
        }
        else
        {
            logMsg(func +" Unable to load the court model!");
//            returnType = false;
        }
    }
    else
    {
        logMsg(func +" Court models loaded!");
//        exit(0);
    }

    if (!data->flag->getHoopModelLoaded())  // Checks if the hoop model(s) have been loaded
    {
        logMsg(func +" Hoop models not loaded!");
//        exit(0);
        loadHoopsSharedPtr loadHoop(new loadHoops);
        hoopEntityMSharedPtr activeHoopInstance;
        
        logMsg(func +" Loading hoop model(s)!");
//        exit(0);
        activeHoopInstance = loadHoop->loadModels(data->component->getActiveHoopInstance(), data->render);  // Creates the hoop instances
        if (!activeHoopInstance.empty())
        {
            data->flag->setHoopModelLoaded(true);
            data->component->setActiveHoopInstance(activeHoopInstance);
//            return (true);
        }
        else
        {
            logMsg(func +" Unable to load the hoop model(s)!");
//            returnType = false;
        }
    }
    else
    {
        logMsg(func +" Hoop models loaded!");
//        exit(0);
    }
    if (!data->flag->getModelsLoaded())
    {
        if (data->flag->getBasketballModelLoaded() && data->flag->getCourtModelLoaded() && data->flag->getHoopModelLoaded())
        {
            logMsg(func +" All models loaded!");
            data->flag->setModelsLoaded(true);
        }
        else
        {
            
        }
    }
    else
    {
        
    }
    logMsg(func +" end");
//    exit(0);
}
// sets the model object
STATE_DEFINE(gameStateMachine, createNodes, gameSMData)
{
    conversionSharedPtr convert ;
    bool returnType = true;
    OgreEntitySharedPtr activeModel;
    OgreSceneNodeSharedPtr activeNode;
    std::string activeEntityName;
    std::string activeNodeNum;
    std::string activeNodeName;
    std:: string func = "gameStateMachine::createNodes";

    logMsg(func +" begin");
    if (!data->flag->getBasketballNodeCreated())
    {
        for (auto ABIIT : data->component->getActiveBasketballInstance())  // loop through active basketball instances
        {
            activeModel = ABIIT.second->getModel();
            activeEntityName = ABIIT.second->getName();
            activeNodeNum = convert->toString(ABIIT.first);
            activeNodeName = ABIIT.second->getNodeName();
            if (activeNodeName.empty())
            {
                activeNodeName = activeEntityName + activeNodeNum;
                ABIIT.second->setNodeName(activeNodeName);
            }
            else
            {
                
            }
            activeNode = data->render->createNode(activeModel, activeNodeName);  // creates node
            ABIIT.second->setNode(activeNode);  // saves node to current instance
        }
        data->flag->setBasketballNodeCreated(true);
    }
    else
    {
        logMsg(func +" Basketball Node Already Created!");
    }
    
    if (!data->flag->getCourtNodeCreated())
    {
        for (auto ACIIT : data->component->getActiveCourtInstance())  // loop through active court instances
        {
            activeModel = ACIIT.second->getModel();
            activeEntityName = ACIIT.second->getName();
            activeNodeNum = convert->toString(ACIIT.first);
            activeNodeName = ACIIT.second->getNodeName();
            if (activeNodeName.empty())
            {
                activeNodeName = activeEntityName + activeNodeNum;
                ACIIT.second->setNodeName(activeNodeName);
            }
            else
            {
                
            }
            activeNode = data->render->createNode(activeModel, activeNodeName);  // creates node
            ACIIT.second->setNode(activeNode);  // saves node to current instance
        }
        data->flag->setCourtNodeCreated(true);
    }
    else
    {
        logMsg(func +" Court Node Already Created!");
    }
    if (!data->flag->getHoopNodeCreated())
    {
        for (auto AHIIT : data->component->getActiveHoopInstance())  // loop through active hoop instances
        {
            activeModel = AHIIT.second->getModel();
            activeEntityName = AHIIT.second->getModel()->getName();
            logMsg(func +" activeEntityName == " +=activeEntityName);
            activeNodeNum = convert->toString(AHIIT.first);
            activeNodeName = AHIIT.second->getNodeName();
            if (activeNodeName.empty())
            {
                activeNodeName = activeEntityName + activeNodeNum;
                AHIIT.second->setNodeName(activeNodeName);
            }
            else
            {
                
            }
            activeNode = data->render->createNode(activeModel, activeNodeName);  // creates node
            AHIIT.second->setNode(activeNode);  // saves node to current instance

        }
        data->flag->setHoopNodeCreated(true);
    }
    else
    {
        logMsg(func +" Hoop Node Already Created!");
    }
    
    if (data->flag->getBasketballNodeCreated() && data->flag->getCourtNodeCreated() && data->flag->getHoopNodeCreated())
    {
        logMsg (func +" All Nodes Created!");
        data->flag->setNodesCreated(true);
    }
    else
    {
        logMsg(func + " Not all nodes created yet!");
    }
    
    logMsg(func +" end");

}

// stop the player
STATE_DEFINE(gameStateMachine, setStartPositions, gameSMData)
{
    conversionSharedPtr convert ;

    basketballEntityMSharedPtr activeBasketballInstance;
    setupBasketballsSharedPtr setupBasketball(new setupBasketballs);

    courtEntityMSharedPtr activeCourtInstance;
    setupCourtsSharedPtr setupCourt(new setupCourts);

    hoopEntityMSharedPtr activeHoopInstance;
    setupHoopsSharedPtr setupHoop(new setupHoops);

    std:: string func = "gameStateMachine::setStartPositions";

    logMsg(func +" begin");

    if (!data->flag->getBasketballStartPositionSet())
    {
        activeBasketballInstance = data->component->getActiveBasketballInstance();
        activeBasketballInstance = setupBasketball->setBasketballStartPositions(activeBasketballInstance);
        data->component->setActiveBasketballInstance(activeBasketballInstance);
        data->flag->setBasketballStartPositionSet(true);
        for (auto ABIIT : activeBasketballInstance)
        {          
            logMsg(func +"Active Basketball Pos == " +convert->toString(ABIIT.second->getNode()->getPosition()));
            if (ABIIT.second->getNode()->getPosition() == Ogre::Vector3(0,0,0))
            {
                data->flag->setBasketballStartPositionSet(false);
            }
        }
    }
    else
    {
        logMsg(func +" basketballStartPositionsSet");
    }
    
    if (!data->flag->getCourtStartPositionSet())
    {
        activeCourtInstance = data->component->getActiveCourtInstance();
        activeCourtInstance = setupCourt->setCourtStartPositions(activeCourtInstance);
        data->component->setActiveCourtInstance(activeCourtInstance);
        data->flag->setCourtStartPositionSet(true);
        for (auto ACIIT : activeCourtInstance)
        {          
            logMsg(func +"Active Court Pos == " +convert->toString(ACIIT.second->getNode()->getPosition()));
            if (ACIIT.second->getNode()->getPosition() == Ogre::Vector3(0,0,0))
            {
                data->flag->setCourtStartPositionSet(false);
            }
        }
    }
    else
    {
        logMsg(func +" courtStartPositionsSet");
    }
    if (!data->flag->getHoopStartPositionSet())
    {
        activeHoopInstance = data->component->getActiveHoopInstance();
        activeHoopInstance = setupHoop->setHoopStartPositions(activeHoopInstance);
        data->component->setActiveHoopInstance(activeHoopInstance);
        data->flag->setHoopStartPositionSet(true);
        for (auto AHIIT : activeHoopInstance)
        {
            logMsg(func +"Active Hoop Pos == " +convert->toString(AHIIT.second->getNode()->getPosition()));
            if (AHIIT.second->getNode()->getPosition() == Ogre::Vector3(0,0,0))
            {
                data->flag->setHoopStartPositionSet(false);
            }
        }
    }
    else
    {
        logMsg(func +" hoopStartPositionsSet");
    }
    if (data->flag->getBasketballStartPositionSet() && data->flag->getCourtStartPositionSet() && data->flag->getHoopStartPositionSet())
    {
        data->flag->setStartPositionsSet(true);
    }

    //    exit(0);
    logMsg(func +" end");

}

STATE_DEFINE(gameStateMachine, setupJumpBall, gameSMData)
{
    conversionSharedPtr convert ;
    std:: string func = "gameStateMachine::setupJumpBall";
    jumpBallsSharedPtr jumpBall;
    sharedPtr<setupJumpBalls> setupJumpBall;
   
    logMsg(func +" begin");
    
    
    jumpBall = data->component->getJumpBall();
    if (!data->flag->getJumpBallCreated())
    {
        jumpBall = setupJumpBall->checkifJumpBallCreated(jumpBall, data->flag);
    }
    else
    {
        logMsg("Jump Ball Already Created!");
        exit(0);
    }
    logMsg(func +" jumpBall");
    logMsg(func +"current Team == " +convert->toString(jumpBall->getBallTippedToTeam()));
    teamTypes currentTeam = jumpBall->getBallTippedToTeam();
    logMsg(func +" currentTeam");

    playerPositionsVec jumpBallPlayer = jumpBall->getJumpBallPlayer();
    logMsg(func +" jumpBallPlayer");

    if (data->gData->getTeamWithBall() == NOTEAM && data->flag->getActiveTeamInstancesCreated())
    {
        if (!jumpBall->getSetupComplete())
        {
            logMsg(func + " jumpBall Setup Not Complete!");
            jumpBall->setJumpBallLocation(CENTERCIRCLE);
            jumpBallPlayer.clear();
            jumpBallPlayer.push_back(C);
            jumpBallPlayer.push_back(C);
            jumpBall->setJumpBallPlayer(jumpBallPlayer);
            jumpBall->setSetupComplete(true);
            jumpBall->setExecuteJumpBall(true);
            data->component->setJumpBall(jumpBall);
//            return (true);
        }
        else
        {
            logMsg(func + " jumpBall Setup Complete!");
        }
    }
//    internalEvent(ST_IDLE);

    logMsg(func +" end");

}

// changes the player's direction once the player is moving
STATE_DEFINE(gameStateMachine, executeJumpBall, gameSMData)
{
    basketballEntityMSharedPtr activeBasketballInstance = data->component->getActiveBasketballInstance();
    conversionSharedPtr convert ;
    teamTypes teamWithBall = data->gData->getTeamWithBall();
    jumpBallsSharedPtr jumpBall = data->component->getJumpBall();
    jumpBallsExecuteSharedPtr jumpBallExecute(new jumpBallsExecute);
    bool jumpBallComplete = jumpBall->getJumpBallComplete();
    bool ballTipped = jumpBall->getBallTipped();
    bool ballTippedToTeam = jumpBall->getBallTippedToTeam();

    std:: string func = "gameStateMachine::setupJumpBall";
    
    logMsg(func +" begin");

    
    logMsg(func +" updating jumpBall state!");
    logMsg(func +" teamWithBall == " +convert->toString(teamWithBall));

//    size_t activeBBallInstance = gameS->getActiveBBallInstance();
//    basketballStateVec basketBallInstance = gameS->getBasketballInstance();
   // FIXME! Do NOT hard code activeBasketballInstance in the future
    bool bballPhysicsSetup = activeBasketballInstance[0]->getPhysicsSetup();
    if (teamWithBall == NOTEAM && bballPhysicsSetup) //&& gameS->getActiveTeamInstancesCreated())
    {

        logMsg(func +" teamWithBall = NOTEAM");
//        exit(0);
        logMsg(func +" jumpBallComplete == " +convert->toString(jumpBallComplete));
        if (!jumpBallComplete)
        {
//            exit(0);
            logMsg(func +" jump ball not complete");
            logMsg(func +" not complete ballTipped == " +convert->toString(ballTipped));
            
//            tipoff complete!exit(0);
            if (!ballTipped)
            {
                ballTipped = jumpBallExecute->executeJump(data->component);  // executes jump ball until ball is tipped
                logMsg (func +" Ball Tippped? " +convert->toString(ballTipped));
//                exit(0);
            }
            else
            {
//                exit(0);
                jumpBallComplete = jumpBallExecute->tipToPlayer(data->component, data->gData->getQuarter());

                logMsg(func +" jumpBallComplete == " +convert->toString(jumpBallComplete));
//                exit(0);
            }
//            exit(0);
        }
        else
        {
            logMsg(func +" teamWithBall = " +convert->toString(teamWithBall));
//            exit(0);
        }
        logMsg(func +" ballTipped == " +convert->toString(ballTipped));
        logMsg(func +" ballTippedToTeam == " +convert->toString(ballTippedToTeam));
    }
    else
    {
        logMsg(func +" teamWithBall == " +convert->toString(teamWithBall));
//        return (true);
    }
    
    jumpBall->setJumpBallComplete(jumpBallComplete);
    jumpBall->setBallTipped(ballTipped);
    
    logMsg(func +" jumpBall return(false)");
  
/*    if (!data->component->getJumpBall()->updateState(data->gData->getTeamWithBall(), activeBasketballInstance, data->component->getActiveTeamInstance(), data->gData->getQuarter()))
    {
        logMsg("tipOff not complete!");
//        exit(0);
    }
    else
    {
        return (true);
    }*/
    
    logMsg(func +" end");

}

// state machine sits here when player is not moving
STATE_DEFINE(gameStateMachine, Idle, noEventData)
{
    std:: string func = "playerStateMachine::Idle";

    logMsg(func +" begin");

    logMsg("playerStateMachine::ST_Idle");
    logMsg(func +" end");

//    exit(0);
}

// start the player moving
STATE_DEFINE(gameStateMachine, StartMovement, gameSMData)
{
    conversionSharedPtr convert ;
    std:: string func = "playerStateMachine::StartMovement";

    logMsg(func +" begin");

//    logMsg("playerStateMachine::ST_Start : Speed is " +convert->toString(data->speed));
//    currentSpeed = data->speed;
//    exit(0);
    // set initial player speed processing here
    logMsg(func +" end");

}

// changes the player's position on the court
STATE_DEFINE(gameStateMachine, ChangePosition, gameSMData)
{
//    exit(0);
    conversionSharedPtr convert ;
    std:: string func = "playerStateMachine::ChangePosition";

    logMsg(func +" begin");

//    logMsg("playerStateMachine::ST_ChangePosition : court position is " +convert->toString(data->position));
//    currentPosition = data->position;
//    currentNode->setPosition(currentPosition);
//    logMsg(func +" Node Position == " +convert->toString(currentNode->getPosition()));
    logMsg(func +" end");

//    exit(0);
}
// changes the player's speed once the player is moving
STATE_DEFINE(gameStateMachine, ChangeSpeed, gameSMData)
{
//    exit(0);
    conversionSharedPtr convert ;
    std:: string func = "playerStateMachine::ChangeSpeed";

    logMsg(func +" begin");

//    logMsg("playerStateMachine::ST_ChangeSpeed : Speed is " +convert->toString(data->speed));
//    currentSpeed = data->speed;

    logMsg(func +" end");

    //    exit(0);
    // perform the change player speed to data->speed here
}

STATE_DEFINE(gameStateMachine, Shoot, gameSMData)
{
    conversionSharedPtr convert ;
    std:: string func = "playerStateMachine::Shoot";

    logMsg(func +" begin");

//    logMsg("playerStateMachine::ST_Shoot : Speed is " +convert->toString(data->speed));
//    currentSpeed = data->speed;

    logMsg(func +" end");

//    exit(0);

    // set initial player shoot processing here
}

STATE_DEFINE(gameStateMachine, Pass, gameSMData)
{
    conversionSharedPtr convert ;
    std:: string func = "playerStateMachine::Pass";


    logMsg(func +" begin");

//    logMsg("playerStateMachine::ST_Pass : Speed is " +convert->toString(data->speed));
//    currentSpeed = data->speed;

    logMsg(func +" end");

//    exit(0);
    // set initial player pass processing here
}
