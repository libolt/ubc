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

#include "statemachine/offensestatemachine.h"
#include "components/offensecomponents.h"
#include "flags/offenseflags.h"
#include "offense/offenseplays.h"

#include "utilities/conversion.h"
#include "utilities/logging.h"
#include "utilities/typedefs.h"


offenseStateMachine::offenseStateMachine() :
    stateMachine(ST_MAX_STATES)
{
}

void offenseStateMachine::pSetup(offenseSMData *data)  // sets up the state machine
{
    std:: string func = "offenseStateMachine::pSetup";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)          // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_SETUP)          // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_SETUP)          // ST_CREATE_NODES
        TRANSITION_MAP_ENTRY (ST_SETUP)          // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (ST_SETUP)          // ST_IDLE
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);

}

void offenseStateMachine::pExecute(offenseSMData *data)  // executes the offense
{
    std:: string func = "offenseStateMachine::pExecute";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_EXECUTE)          // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)          // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_EXECUTE)          // ST_CREATE_NODES
        TRANSITION_MAP_ENTRY (ST_EXECUTE)          // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (ST_EXECUTE)          // ST_IDLE
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);

}

void offenseStateMachine::pCheckDirectives(offenseSMData *data)  // checks for offensive directive
{
    std:: string func = "offenseStateMachine::pCheckDirectives";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_CHECKDIRECTIVES)          // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_CHECKDIRECTIVES)          // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)          // ST_CREATE_NODES
        TRANSITION_MAP_ENTRY (ST_CHECKDIRECTIVES)          // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (ST_CHECKDIRECTIVES)          // ST_IDLE
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);

}

void offenseStateMachine::pExecutePass(offenseSMData *data)  // executes a pass
{
    std:: string func = "offenseStateMachine::pExecutePass";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_EXECUTEPASS)          // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_EXECUTEPASS)          // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_EXECUTEPASS)          // ST_CREATE_NODES
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)          // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (ST_EXECUTEPASS)          // ST_IDLE
    END_TRANSITION_MAP(data)

    logMsg(func +" end");
//    exit(0);

}

void offenseStateMachine::pHalt()
{
    std:: string func = "offenseStateMachine::halt";

    logMsg(func +" begin");

    BEGIN_TRANSITION_MAP                                    // - Current State -
        TRANSITION_MAP_ENTRY (ST_IDLE)          // ST_CREATE_INSTANCES
        TRANSITION_MAP_ENTRY (ST_IDLE)          // ST_LOAD_MODELS
        TRANSITION_MAP_ENTRY (ST_IDLE)          // ST_CREATE_NODES
        TRANSITION_MAP_ENTRY (ST_IDLE)          // ST_SET_START_POS
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)          // ST_IDLE
    END_TRANSITION_MAP(nullptr)

    logMsg(func +" end");
//    exit(0);

}

// sets up the state machine
STATE_DEFINE(offenseStateMachine, setup, offenseSMData)
{
    conversionSharedPtr convert ;
    quarters currentQuarter = data->currentQuarter;
    courtSide_t courtSide = data->component->getCourtSide();
    teamTypes teamType = data->component->getTeamType();
    std::string playName = data->component->getPlayName();
    std::string playTitle  = data->component->getPlayTitle();
    offensePlaysVecSharedPtr plays = data->component->getPlays();
    OgreVector3Vec startPositions;
    std::vector< OgreVector3Vec > executePositions;
    std::vector<offensePlays::playerDirectives> playerDirective;
    std::vector< boolVec > executePositionReached = data->flag->getExecutePositionReached();
    
    switch (currentQuarter)
    {
        case FIRST:
        case SECOND:
           switch (teamType)
           {
               case HOMETEAM:
                   courtSide = LEFTSIDE;
               break;
               case AWAYTEAM:
                   courtSide = RIGHTSIDE;
               break;
               default:
               break;
           }
        break;
    case THIRD:
    case FOURTH:
       switch (teamType)
       {
           case HOMETEAM:
               courtSide = RIGHTSIDE;
           break;
           case AWAYTEAM:
               courtSide = LEFTSIDE;
           break;
           default:
           break;
       }
    break;
    }
    data->component->setCourtSide(courtSide);
    
    // FIXME! Hard coded values need to be made dynamic
    playName = "Box";
    playTitle = "FlashHighPassLow";

    switch (courtSide)
    {
        case RIGHTSIDE:
            playTitle.append("Right");
        break;
        case LEFTSIDE:
            playTitle.append("Left");
        break;
        default:
        break;
    }

    logMsg("plays.size() = " +convert->toString(plays.size()));

    offensePlaysVecSharedPtr::iterator PIT;
    for (auto PIT : plays)
    {
        if (PIT->getPlayName() == playName)  // sets up the offense
        {
            if (PIT->getTitle() == playTitle)
            {
                startPositions = PIT->getStartPositions();
                executePositions = PIT->getExecutePositions();
                playerDirective = PIT->getPlayerDirective();
            }
            else
            {
            }
        }
        else
        {
        }
    }

    executePositionReached.resize(5);
    for (auto EPIT : executePositions)
//    for (size_t x=0; x<executePositions.size(); ++x)
    {
        for (auto EPRIT : executePositionReached)
        {
//        executePositionReached[x].resize(executePositions[x].size());
            EPRIT.resize(EPIT.size());
            for (auto EPRITIT : EPRIT)
//            for (size_t y=0;y<executePositionReached[x].size(); ++y)
            {
//                logMsg("Y = " +convert->toString(y));
//                    executePositionReached[x][y] = false;
                EPRITIT = false;
            }
        }
    }
//        size_t z = 0;
//        while (z < startPositions.size())
    for (auto SPIT : startPositions)
    {
        size_t z = 0;
        float posZ = SPIT.z;
        logMsg("Start Position Z for player[" +convert->toString(z) +"] " +convert->toString(SPIT.z));
        ++z;
    }
    
    // checks for a Y Offset so that players dont fall through the court
  
    float yOffset = data->yOffset;
    for (auto SPIT : startPositions)
    {
        SPIT.y = yOffset;
    }
    for (auto EPIT : executePositions)
    {
        for (auto EPXIT : EPIT)
        {
            EPXIT.y = yOffset;
            //exit(0);
        }
    }
    data->component->setStartPositions(startPositions);
    data->component->setExecutePositions(executePositions);
    data->component->setPlayerDirective(playerDirective);
    data->component->setPlayName(playName);
    data->component->setPlayTitle(playTitle);
    data->component->setPlays(plays);
    data->flag->setExecutePositionReached(executePositionReached);
    data->flag->setOffenseSetup(true);
}

// executes the offense
STATE_DEFINE(offenseStateMachine, execute, offenseSMData)
{
    conversionSharedPtr convert ;
//    sharedPtr<gameState> gameS = gameState::Instance();
    teamTypes teamWithBall = data->teamWithBall;

//FIXME!    teamEntityMSharedPtr activeTeamInstance = gameComponent->getActiveTeamInstance();
/*TS    playerStateVecSharedPtr activePlayerInstance = activeTeamInstance[teamWithBall]->getActivePlayerInstance();

    size_t playerWithBallInstance = activeTeamInstance[teamWithBall]->getPlayerWithBallInstance();
    size_t playerWithBallID = activeTeamInstance[teamWithBall]->getPlayerWithBallID();

    playerSteer *pSteer;

    if (!allStartPositionsReached)  // checks if all players have reached their start positions for the offense being run
    {
        logMsg("teamWithBallExecute == " +convert->toString(teamWithBall));
        logMsg("playerWithBallInstanceExecute == " +convert->toString(playerWithBallInstance));
        size_t x = 0;
        while (x < activePlayerInstance.size())
        {
            if ( activePlayerInstance[x]->getID() != playerWithBallID)
            {
                logMsg("activeSteerInstanceID == " +convert->toString(activePlayerInstance[x]->getID()));
                pSteer = activePlayerInstance[x]->getSteer().get();
                boolVec positionReached = pSteer->getPositionReached();
                if (positionReached.size() != 1)
                {
                    positionReached.push_back(false);
                    pSteer->setPositionReached(positionReached);
                }

                if (!startPositionReached[x])  // checks if each player has reached the start position
                {
                    logMsg("startPosition " +convert->toString(x) +" not reached!");
                    OgreVector3Vec steerCoords = plays[0]->getStartPositions();
                    OpenSteer::Vec3 coords = convert->toOpenSteerVec3(startPositions[x]);
                    pSteer->setSteerCoords(coords);
                    pSteer->setExecute(true);
                }
                else    // increments the counter
                {
//                  numStartPositionsReached += 1;
                    pSteer->setExecute(false);
                }

                if (numStartPositionsReached == 4)  // FIXME: hard coded for a human player
                {
//              exit(0);
                    allStartPositionsReached = true;
                }
                if (!startPositionReached[x] && pSteer->getDistToPosition() < 3 && pSteer->getDistToPosition() != -1.0f)
                {
                    startPositionReached[x] = true;
                    numStartPositionsReached += 1;
                    pSteer->setExecute(false);
                }
                logMsg("startPositionsReached = " +convert->toString(startPositionReached[x]));
            }
            ++x;
        }
    }
    else
    {
//      exit(0);
        if (!allExecutePositionsReached)
        {
//          exit(0);
            int allExecutionsReached = 0;
            for (int ID=0;ID<5;++ID)
            {
                if (allExecutionsReached < 4)
                {
                    if (ID != playerWithBallInstance)
                    {
                        pSteer = activePlayerInstance[ID]->getSteer().get();
                        bool directiveComplete = checkForDirective(pSteer->getPlayerPosition());  // checks if player must follow directive before executing
                        if (directiveComplete)
                        {
                            logMsg("Player " +convert->toString(ID) +" executePositionReached size = " +convert->toString(executePositionReached[ID].size()));
                            for (int x=0;x<executePositionReached[ID].size();++x)
                            {
                                if (executePositionReached[ID][x] == true)
                                {
                                    logMsg("Player " +convert->toString(ID));
//                                  exit(0);
                                }
                                else
                                {
                                    int lastPos = executePositionReached[ID].size() - 1;
                                    if (executePositionReached[ID][lastPos])
                                    {
                                        allExecutionsReached += 1;
                                    }
                                    // checks if previous position was reached
                                    else if ( x > 0 && !executePositionReached[ID][x - 1])
                                    {
//                                      exit(0);
//                                      break;
                                    }
                                    else //if (!executePositionReached[ID][x])
                                    {
                                        logMsg("Team " +convert->toString(teamWithBall) +" Player " +convert->toString(ID) +" Seeking Offense Execute Position!");
                                        OpenSteer::Vec3 executePosition = convert->toOpenSteerVec3(executePositions[ID][x]);
                                        pSteer->setSteerCoords(executePosition);
                                        float distToPosition = OpenSteer::Vec3::distance (pSteer->getSteerCoords(), pSteer->position());
                                        pSteer->setDistToPosition(distToPosition);
                                        if (pSteer->getDistToPosition() < 3 && pSteer->getDistToPosition() != -1.0f)
                                        {
                                        //    exit(0);
                                            executePositionReached[ID][x] = true;
                                            pSteer->setExecute(false);
                                        }
                                        else
                                        {
//                                          exit(0);
                                            pSteer->setExecute(true);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    allExecutePositionsReached = true;
                }
            }
        }
        else
        {
            for (int x=0;x<5;++x)
            {
                pSteer = activePlayerInstance[x]->getSteer().get();
                pSteer->setExecute(false);
                activePlayerInstance[x]->setSteer(playerSteerSharedPtr(pSteer));
            }
        }
//          exit(0);
    }
TS*/

}

// checks offense directives
STATE_DEFINE(offenseStateMachine, checkDirectives, offenseSMData)
{
    conversionSharedPtr convert ;
    bool retVal = true;
    playerDirectivesVec playerDirective = data->component->getPlayerDirective();
    playerPositions playerPosition = data->playerPosition;
    boolVec startPositionReached = data->flag->getStartPositionReached();
    std::vector<boolVec> executePositionReached = data->flag->getExecutePositionReached();

    logMsg("playerDirective.size() == " +convert->toString(playerDirective.size()));

//    while (x < playerDirective.size())
    for(auto PDIT : playerDirective)
    {
        logMsg("playerPosition = " +convert->toString(PDIT.getPlayerPosition()));
        if (PDIT.getPlayerPosition() == playerPosition)
        {
            //directiveTypes type =
            switch (PDIT.getType())
            {
                case WAIT:
                    switch (PDIT.getWaitFor())
                    {
                        case PLAYERPOSITIONSET:
                            logMsg("playerSet = " +convert->toString(PDIT.getPlayerSet()));
                            switch (PDIT.getPositionType())
                            {
                                case START:
                                    logMsg("offense position type = START");
                                    logMsg("startPositionReached.size() == " +convert->toString(startPositionReached.size()));
//                                    logMsg("x == " +convert->toString(x));
                                    logMsg("playerSet == " +convert->toString(PDIT.getPlayerSet()));
                                    logMsg("startPositionReached == " +convert->toString(startPositionReached[PDIT.getPlayerSet()]));
                                    if (!startPositionReached[PDIT.getPlayerSet()])
                                    {
                                        //exit(0);
                                    }
                                    logMsg("surived startPosition reached!");
                                break;
                                case EXECUTE:
                                    logMsg("offense position type = EXECUTe");
                                    if (!executePositionReached[PDIT.getPlayerSet()][PDIT.getPosition()])
                                    {
                                        retVal = false;
                                    }
                                    else
                                    {
                                    }
                                    //exit(0);
                                break;
                            }
                            //return (true);
//                          exit(0);
                        break;
                        case TIME:
                        break;
                    }
                break;
                case FREELANCE:
                break;
            }
        }
    }
}

// executes a pass
STATE_DEFINE(offenseStateMachine, executePass, offenseSMData)
{
    //FIXME! Needs fixed after playerStateMachine is implemented
    /*
        //conversion *convert = conversion::Instance();
        conversionSharedPtr convert ;
        //gameState *gameS = gameState::Instance();
    //    sharedPtr<gameState> gameS = gameState::Instance();
    //    size_t activeBBallInstance = gameInstance->getActiveBBallInstance();
        playerPositions passToPlayer = activePlayerInstance[convert->toString(playerWithBallInstance)]->getPassToPlayer();
    //    basketballStateVecSharedPtr basketballInstance = gameInstance->getBasketballInstance();
        basketballEntityMSharedPtr activeBasketballInstance = gameInstance->getActiveBasketballInstance();
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

        logMsg(func +" begin");

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

// sets offense to Idle
STATE_DEFINE(offenseStateMachine, Idle, noEventData)
{

}
