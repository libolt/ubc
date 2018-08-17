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

#include "setup/setupteams.h"
#include "data/playergamedata.h"
#include "data/teamgamedata.h"
#include "entity/courtentity.h"
#include "entity/playerentity.h"
#include "entity/teamentity.h"
#include "flags/playerflags.h"
#include "setup/setupplayers.h"
#include "utilities/conversion.h"
#include "setup/setupplayerpositions.h"
//#include "state/courtstate.h"
#include "entity/gameentity.h"
#include "state/teamstate.h"
#include "statemachine/playerstatemachine.h"
#include "utilities/logging.h"
#include "load/loadteams.h"

setupTeams::setupTeams()  // constructor
{
    
}
setupTeams::~setupTeams()  // destructor
{
    
}

teamEntityMSharedPtr setupTeams::createTeamInstances()  // creates team Instances
{
    conversionSharedPtr convert = conversion::Instance();
    loadTeamsSharedPtr loadTeam(new loadTeams); // = base->getLoadTeam();
    std::string func = "setupTeams::createTeamInstances()";
    
    logMsg(func +" begin");
//    exit(0);
    teamEntityMSharedPtr tInstance;
///    teamStateVecSharedPtr tInstance2;
///    teamStateSharedPtr tempInstance(new teamState);
//    teamState *tempInstance = new teamState;
///    tempInstance->setID(1);
///    tempInstance->setCity("tempCity");
///    tempInstance->setName("tempTeam");
///    tempInstance->setCoach("tempCoach|");
///    tempInstance->setTeamType(HOMETEAM);

///    tInstance2.push_back(tempInstance);

    logMsg(func +" loadTeams");
    if (loadTeam->checkIfTeamsLoaded())
    {
        logMsg(func +" loadTeam->getTInstance().size() == " +convert->toString(loadTeam->getTInstance().size()));
//        exit(0);
        tInstance = loadTeam->getTInstance();
        if (tInstance.size() > 0)
        {
            logMsg(func +" tInstance Loaded!");
//            setTeamInstance(tInstance);
        }
        else
        {
            logMsg(func +" tInstance NOT Loaded!");
        }
    }
    else
    {
        logMsg(func +" loading of teams failed!");
        exit(0);
//        return (false);
    }
    

//    exit(0);
    logMsg(func +" uno");
    

    logMsg(func +" tInstance.size() == " +convert->toString(tInstance.size()));
    logMsg(func +" too");
    
//    exit(0);
    logMsg("tInstance size == " +convert->toString(tInstance.size()));


//    logMsg("teamID.size() == " +convert->toString(getTeamIDS().size()));
//    logMsg("tInstance size = " +convert->toString(tInstance.size()));
//    logMsg("tInstance city 0 = " +tInstance[0]->getCity());

//    exit(0);
///    getTeamInstance()[0]->setID(tInstance[0]->getID());
///    teamInstance[1].setTeamID(teamID[1]);
///    exit(0);
///    teamInstance[0].setTeamType(HOMETEAM);
///    teamInstance[1].setTeamType(AWAYTEAM);
///    teamInstance[0].setHumanControlled(true);
///    teamInstance[1].setHumanControlled(false);
///    teamInstance[0].setTeamColObject(COL_TEAM1);
///    teamInstance[1].setTeamColObject(COL_TEAM2);

//    teamInstance[0].setTeamCollidesWith(COL_COURT); // | COL_BBALL | COL_TEAM2;   determines what team0 collides with);
//    teamInstance[1].setTeamCollidesWith(COL_COURT); // | COL_BBALL | COL_TEAM2;   determines what team1 collides with);
//    teamInstance[0].setupState();
//    teamInstance[1].setupState();
//    exit(0);

    if (tInstance.size() > 0)
    {
//        setTeamInstance(tInstance);
//        setTeamInstancesCreated(true);
        logMsg(func +" teamInstance CREATED!!");
//        exit(0);
    }
    else 
    {
        logMsg(func +" Failed to create Team Instances!");
        exit(0);
//        return (false);
    }

    logMsg(func +" end");
//    exit(0);
    return (tInstance);
}

teamEntityMSharedPtr setupTeams::createActiveTeamInstances(teamEntityMSharedPtr teamInstance, sizeTVec teamID)  // creates active team instances
{
    conversionSharedPtr convert = conversion::Instance();
    teamEntityMSharedPtr activeTeamInstance;
    std::string func = "setupTeams::createActiveTeamInstances()";
       
    logMsg(func +" begin");
//    gameStateSharedPtr gameInstance;
//    logMsg(func +" Team Instances created == " +convert->toString(gameInstance->getTeamInstancesCreated()));
    logMsg(func +" teamInstance size == " +convert->toString(teamInstance.size()));
//    logMsg(func +" gameInstance teamInstance size == " +convert->toString(gameInstance->getTeamInstance().size()));
    
//    exit(0);
    logMsg(func +" teamI");
    sizeTVec::iterator TIDIT;
    for (TIDIT = teamID.begin(); TIDIT != teamID.end(); ++TIDIT)  // creates active team instances
    {
        activeTeamInstance.insert(std::pair<size_t, teamEntitySharedPtr>(*TIDIT, teamInstance[*TIDIT]));
    }
    
    logMsg(func +" teamID.size() == " +convert->toString(teamID.size()));
    logMsg(func +" activeTeamInstance.size() == " +convert->toString(activeTeamInstance.size()));

    teamTypes teamType;
    
    for (auto ATIIT : activeTeamInstance)  // sets team type
    {
        logMsg(func +" ATIIT.first == " +convert->toString(ATIIT.first));

        if (!ATIIT.second->getInitialized())
        {
            if (ATIIT.second->initialize())
            {
                ATIIT.second->setInitialized(true);
            }
            else
            {
                logMsg(func +" Unable to initialize Active Team Instance!");
                exit(0);
            }
        }

        switch (ATIIT.first)
        {
            case 0:
                teamType = HOMETEAM;
                logMsg("HOMETEAM");
            break;
            case 1:
                logMsg("AWAYTEAM");
                teamType = AWAYTEAM;
                
            break;
        }
        ATIIT.second->getGameData()->setTeamType(teamType);
        logMsg(func +" teamType set!");
    }
//    exit(0);
    logMsg(func +" end");
    
    return (activeTeamInstance);
}

playerEntityMSharedPtr setupTeams::setPlayerStartPositions(playerEntityMSharedPtr activePlayerInstance, courtEntityMSharedPtr courtInstance, teamGameDataSharedPtr gameData, teamStarterIDsVecM teamStarterID)  // sets the initial coordinates for the players.
{
    conversionSharedPtr convert = conversion::Instance();
    setupPlayerPositionsSharedPtr setupPlayerPosition(new setupPlayerPositions);
    OgreVector3Vec startingPos;
    Ogre::Vector3 courtPos = courtInstance[0]->getNodePosition();
    std::string func = "setupTeams::setPlayerStartPositions()";

//    exit(0);
    logMsg(func +" begin");
    
    logMsg(func +" courtPos.y == " +convert->toString(courtPos.y));
    float yOffset = courtPos.y + 6.0;
    
    logMsg(func +" courtpos.y == " +convert->toString(courtPos.y));
    logMsg(func +" yOffset == " +convert->toString(yOffset));

//    exit(0);
    activePlayerInstance = setupPlayerPosition->setJumpBallPositions(activePlayerInstance, gameData->getTeamType(), courtPos);
    logMsg(func +" activePlayerInstance size == " +convert->toString(activePlayerInstance.size()));
//    exit(0);
    // set initial player coordinates for the tipoff

/*    switch (teamType)
    {
        case HOMETEAM:   // assigns the positions and directions for team 1 player
            gameInstance->setYOffset(yOffset);
            // assign positions
            startingPos.push_back(Ogre::Vector3(14.4f,yOffset,352.0f));
            startingPos.push_back(Ogre::Vector3(2.0f,yOffset,347.6f));
            startingPos.push_back(Ogre::Vector3(2.0f,yOffset,360.0f));
            startingPos.push_back(Ogre::Vector3(5.2f,yOffset,351.6f));
            startingPos.push_back(Ogre::Vector3(1.6f,yOffset,352.0f));
        break;
        
        case AWAYTEAM: // assigns the positions and directions for team 2 players       
            // assign positions
            startingPos.push_back(Ogre::Vector3(-13.8f,yOffset,352.0f));
            startingPos.push_back(Ogre::Vector3(-0.8f,yOffset,347.6f));
            startingPos.push_back(Ogre::Vector3(-0.8f,yOffset,360.8f));
            startingPos.push_back(Ogre::Vector3(4.4f,yOffset,348.8f));
            startingPos.push_back(Ogre::Vector3(-0.4f,yOffset,352.0f));
        break;
    }


    if (startingPos.size() > 0)
    {
        logMsg(func +" startingPosition.size > 0");
//        exit(0);
//        for (size_t i=0;i<5;++i)
        size_t i = 0;

        size_t x = 0;
        for (auto APIIT : activePlayerInstance)
        {
            logMsg(func +" activePlayerInstance.size > 0!");
            
            std::vector<playerActions> stateAction = APIIT.second->getStateAction();
            switch (APIIT.second->getActivePosition())
            {
                case PG:
                    APIIT.second->setCourtPositionChanged(true);
                    APIIT.second->setCourtPositionChangedType(STARTCHANGE);
                    APIIT.second->setNewCourtPosition(startingPos[0]);
                    APIIT.second->setStateChanged(true);
                    stateAction.push_back(CHANGECOURTPOS);
                    APIIT.second->setStateAction(stateAction);
                    APIIT.second->getSteer()->setPlayerPosition(PG);
//                    exit(0);
                break;
                case SG:          
                    APIIT.second->setCourtPositionChanged(true);
                    APIIT.second->setCourtPositionChangedType(STARTCHANGE);
                    APIIT.second->setNewCourtPosition(startingPos[1]);
                    APIIT.second->setStateChanged(true);
                    stateAction.push_back(CHANGECOURTPOS);
                    APIIT.second->setStateAction(stateAction);
                    APIIT.second->getSteer()->setPlayerPosition(SG);
                break;
                case SF:           
                    APIIT.second->setCourtPositionChanged(true);
                    APIIT.second->setCourtPositionChangedType(STARTCHANGE);
                    APIIT.second->setNewCourtPosition(startingPos[2]);
                    APIIT.second->setStateChanged(true);
                    stateAction.push_back(CHANGECOURTPOS);
                    APIIT.second->setStateAction(stateAction);
                    APIIT.second->getSteer()->setPlayerPosition(SF);
                break;
                case PF:            
                    APIIT.second->setCourtPositionChanged(true);
                    APIIT.second->setCourtPositionChangedType(STARTCHANGE);
                    APIIT.second->setNewCourtPosition(startingPos[3]);
                    APIIT.second->setStateChanged(true);
                    stateAction.push_back(CHANGECOURTPOS);
                    APIIT.second->setStateAction(stateAction);
                    APIIT.second->getSteer()->setPlayerPosition(PF);
                break;
                case C:
                    APIIT.second->setCourtPositionChanged(true);
                    APIIT.second->setCourtPositionChangedType(STARTCHANGE);
                    APIIT.second->setNewCourtPosition(startingPos[4]);
                    APIIT.second->setStateChanged(true);
                    stateAction.push_back(CHANGECOURTPOS);
                    APIIT.second->setStateAction(stateAction);
                    APIIT.second->getSteer()->setPlayerPosition(C);
                break;
            }
        }
    }*/

    for (auto APIIT : activePlayerInstance)
    {
        logMsg(func +" APIIT.second->getStateAction().size() = " +convert->toString(APIIT.second->getGameData()->getStateAction().size()));
    }
//    exit(0);
        
    size_t x = 0;
    
///    while (x < activePlayerInstance.size())
///    {
        
///        logMsg("Team " +convert->toString(teamType) +" PlayerSteerNode" +convert->toString(x) +" Position == " +convert->toString(activePlayerInstance[x]->getNode()->getPosition()));
//        exit(0);
///        logMsg("Team " +convert->toString(teamType) +" PlayerSteer " +convert->toString(x) +" Position ==  " +convert->toString(activePlayerInstance[x]->getSteer()->position()));
///        ++x;
///    }
    
//    exit(0);
    
//    component->setActivePlayerInstance(activePlayerInstance);
    
    logMsg(func +" end");
    
    return (activePlayerInstance);
}

playerEntityMSharedPtr setupTeams::setPlayerStartActivePositions(playerEntityMSharedPtr activePlayerInstance)  // sets the position the players will play at the start of the game
{
    conversionSharedPtr convert = conversion::Instance();
//    playerEntityMSharedPtr activePlayerInstance = component->getActivePlayerInstance();
    std::string func = "setupTeams::setPlayerStartActivePositions()";

    logMsg(func +" begin");
    
    logMsg(func + " activePlayerInstance.size() == " +convert->toString(activePlayerInstance.size()));
    exit(0);
    if (activePlayerInstance.size() > 0) // checks that activePlayerInstance has data before executing
    {
        activePlayerInstance[0]->getGameData()->setActivePosition(PG);
        activePlayerInstance[1]->getGameData()->setActivePosition(SG);
        activePlayerInstance[2]->getGameData()->setActivePosition(SF);
        activePlayerInstance[3]->getGameData()->setActivePosition(PF);
        activePlayerInstance[4]->getGameData()->setActivePosition(C);
    }
    // set steer IDs
    for (auto APIIT : activePlayerInstance)
    {
        //playerSteer *pSteer = activePlayerInstance[x]->getSteer();
       // pSteer->setID(x);
//FIXME!        APIIT.second->getSteer()->setID(APIIT.second->getID());
    }
    
//    component->setActivePlayerInstance(activePlayerInstance);
    logMsg(func +" end");

    return (activePlayerInstance);
}

playerEntityMSharedPtr setupTeams::setPlayerStartDirections(playerEntityMSharedPtr activePlayerInstance, teamGameDataSharedPtr gameData)  // sets the initial directions for the players.
{
    conversionSharedPtr convert = conversion::Instance();
//    playerEntityMSharedPtr activePlayerInstance = component->getActivePlayerInstance();
    std::vector<directions> playerDirection; // stores the direction players face at start
    std::string func = "setupTeams::setPlayerStartDirections()";

    logMsg(func +" begin");
    
    for (auto APIIT : activePlayerInstance)
    {
        logMsg(func +" APIIT.second->getGameData()->getStateAction().size() = " +convert->toString(APIIT.second->getGameData()->getStateAction().size()));
    }
//    exit(0);
    
    switch (gameData->getTeamType())
    {
        case HOMETEAM:   // assigns the positions and directions for team 1 player
            playerDirection.push_back(LEFT);  
            playerDirection.push_back(LEFT);  
            playerDirection.push_back(LEFT);  
            playerDirection.push_back(LEFT);  
            playerDirection.push_back(LEFT);  
        break;
        case AWAYTEAM:   // assigns the positions and directions for team 2 players       
            playerDirection.push_back(RIGHT); 
            playerDirection.push_back(RIGHT); 
            playerDirection.push_back(RIGHT); 
            playerDirection.push_back(RIGHT); 
            playerDirection.push_back(RIGHT); 
        break;
    }
    
    for (auto APIIT : activePlayerInstance)
    {
        playerSMData *SMData = new playerSMData;
        std::vector<playerActions> stateAction = APIIT.second->getGameData()->getStateAction();

        logMsg(func +" activePlayerInstance.size > 0!");
//           exit(0);
        switch (APIIT.second->getGameData()->getActivePosition())
        {
            case PG:
                SMData->direction = playerDirection[0];
                APIIT.second->getFlag()->setStateChanged(true);
                stateAction.push_back(CHANGEDIRECTION);
                APIIT.second->getGameData()->setStateAction(stateAction);
//                exit(0);
            break;       
            case SG:
                SMData->direction = playerDirection[1];
                APIIT.second->getFlag()->setStateChanged(true);
                stateAction.push_back(CHANGEDIRECTION);
                APIIT.second->getGameData()->setStateAction(stateAction);
            break;
            case SF:
                SMData->direction = playerDirection[2];
                APIIT.second->getFlag()->setStateChanged(true);
                stateAction.push_back(CHANGEDIRECTION);
                APIIT.second->getGameData()->setStateAction(stateAction);
            break;
            case PF:
                SMData->direction = playerDirection[3];
                APIIT.second->getFlag()->setStateChanged(true);
                stateAction.push_back(CHANGEDIRECTION);
                APIIT.second->getGameData()->setStateAction(stateAction);
            break;
            case C:
                SMData->direction = playerDirection[4];
                APIIT.second->getFlag()->setStateChanged(true);
                stateAction.push_back(CHANGEDIRECTION);
                APIIT.second->getGameData()->setStateAction(stateAction);
            break;
        }
        
        
/*        if (!APIIT.second->getSMStartDirectionSet())  // sets the start value of direction if it has not been set already
        {                   
//            SMData->node = APIIT.second->getNode();
            APIIT.second->setStateChanged(true);
            if (APIIT.second->updateStateMachine(CHANGEDIRECTION, SMData))
            {
                APIIT.second->setSMStartDirectionSet(true);
                logMsg(func +" stateMachine direction has been set!");
            }
            else
            {
                logMsg(func +" Unable to set stateMachine direction");
                exit(0);
            }
//                    exit(0);
        }
        else
        {
            logMsg(func +" stateMachine direction already set");
        }*/
    }
    
    for (auto APIIT : activePlayerInstance)
    {
        logMsg(func +" APIIT.second->getGameData()->getStateAction().size() = " +convert->toString(APIIT.second->getGameData()->getStateAction().size()));
    }
    
//    component->setActivePlayerInstance(activePlayerInstance);

    logMsg(func +" end");
//    exit(0);
    return (activePlayerInstance);
}
