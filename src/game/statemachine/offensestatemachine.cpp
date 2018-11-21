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
    for (size_t x=0; x<executePositions.size(); ++x)
    {
        executePositionReached[x].resize(executePositions[x].size());
        for (size_t y=0;y<executePositionReached[x].size(); ++y)
        {
            logMsg("Y = " +convert->toString(y));
                    executePositionReached[x][y] = false;
        }
    }
        size_t z = 0;
        while (z < startPositions.size())
        {
            float posZ = startPositions[z].z;
            logMsg("Start Position Z for player[" +convert->toString(z) +"] " +convert->toString(startPositions[z].z));
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
        
    data->flag->setOffenseSetup(true);
}

// executes the offense
STATE_DEFINE(offenseStateMachine, execute, offenseSMData)
{

}

// checks offense directives
STATE_DEFINE(offenseStateMachine, checkDirectives, offenseSMData)
{

}

// executes a pass
STATE_DEFINE(offenseStateMachine, executePass, offenseSMData)
{

}

// sets offense to Idle
STATE_DEFINE(offenseStateMachine, Idle, noEventData)
{

}
