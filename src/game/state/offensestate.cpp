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
#include "data/gamedata.h"
#include "engine/gameengine.h"
#include "load/loadoffenseplays.h"
#include "utilities/logging.h"
//#include "state/basketballstate.h"
//#include "state/courtstate.h"
#include "entity/gameentity.h"
#include "state/offensestate.h"
#include "state/playerstate.h"
#include "ai/playersteer.h"
//#include "state/teamstate.h"

offenseState::offenseState()  // constructor
{
//    gameSInitialized = false;
    teamType = NOTEAM;
    selectedOffense = -1; // sets the default offense to box
    execute = false;
    offenseSet = false;
    courtSide = NOSIDE;
/*  startPositions = new Ogre::Vector3[5];

    for (int x=0; x<5; ++x)
    {
        startPositions[x]   = Ogre::Vector3(0.0f,0.0f,0.0f);

    }
*/
//    startPositions[4] = Ogre::Vector3(3000.0f,-1300.5f,3780.0f);

//  executePositions = new OgreVector3Vec[5];
//  executePositions[0] = new OgreVector3Vec;
//  exit(0);

    executePositions.resize(5);

/*    startXPosSet = new bool[5];
    startYPosSet = new bool[5];
    startZPosSet = new bool[5];
*/
    allStartPositionsReached = false;
    allExecutePositionsReached = false;

//    executePositionSet = new bool[5];
/*    for (int x=0;x<5;++x)
    {
        startXPosSet[x] = false;
        startYPosSet[x] = false;
        startZPosSet[x] = false;
        startPositionReached.push_back(false);
//      executePositionSet[x] = false;
    }
*/
    numStartPositionsReached = 0;
    offenseSetup = false;
    loadPlays();
}

/*gameStateSharedPtr offenseState::getGameS()  // retrieves the value of gameS
{
    return (gameS);
}
void offenseState::setGameS(gameStateSharedPtr set)  // sets the value of gameS
{
    gameS = set;
}

bool offenseState::getGameSInitialized()  // retrieves the value of gameSInitialized
{
    return (gameSInitialized);
}
void offenseState::setGameSInitialized(bool set)  // sets the value of gameSInitialized
{
    gameSInitialized = set;
}
*/

teamTypes offenseState::getTeamType() const  // retrieves the value of teamType
{
    return (teamType);
}
void offenseState::setTeamType(const teamTypes &set)  // sets the value of teamType
{
    teamType = set;
}

courtSide_t offenseState::getCourtSide() const  // retrieves the value of courtSide
{
    return (courtSide);
}
void offenseState::setCourtSide(const courtSide_t &set)  // sets the value of courtSide
{
    courtSide = set;
}

int offenseState::getSelectedOffense() const  // returns value of selectedOffense
{
    return (selectedOffense);
}
void offenseState::setSelectedOffense(const int &set)  // sets the value of selectedOffense
{
    selectedOffense = set;
}

bool offenseState::getExecute() const  // retrieves the value of execute variable
{
    return (execute);
}
void offenseState::setExecute(const bool &set)  // sets the value of the execute variable
{
    execute = set;
}

offensePlaysVecSharedPtr offenseState::getPlays() const  // returns the value of plays
{
    return (plays);
}
void offenseState::setPlays(const offensePlaysVecSharedPtr &set)  // sets the value of plays
{
    plays = set;
}

OgreVector3Vec offenseState::getStartPositions() const  // retrieves the value of startPositions
{
    return (startPositions);
}
void offenseState::setStartPositions(const OgreVector3Vec &set)  // sets the value of startPositions
{
    startPositions = set;
}

std::vector< OgreVector3Vec > offenseState::getExecutePositions() const  // retrieves the value of startPositions
{
    return (executePositions);
}
void offenseState::setExecutePositions(const std::vector<OgreVector3Vec> &set)  // sets the value of startPositions
{
    executePositions = set;
}

boolVec offenseState::getStartXPosSet() const  // returns the value of startXPosSet
{
    return (startXPosSet);
}
void offenseState::setStartXPosSet(const boolVec &set)  // sets the value of startXPosSet
{
    startXPosSet = set;
}

boolVec offenseState::getStartYPosSet() const  // returns the value of startYPosSet
{
    return (startYPosSet);
}
void offenseState::setStartYPosSet(const boolVec &set) // sets the value of startYPosSet
{
    startYPosSet = set;
}

boolVec offenseState::getStartZPosSet() const  // returns the value of startZPosSet
{
    return (startZPosSet);
}
void offenseState::setStartZPosSet(const boolVec &set)  // sets the value of startZPosSet
{
    startZPosSet = set;
}

boolVec offenseState::getStartPositionReached() const  // returns the value of startPositionReached
{
    return (startPositionReached);
}
void offenseState::setStartPositionReached(const boolVec &set) // sets the value of startPositionReached
{
    startPositionReached = set;
}

bool offenseState::getAllStartPositionsReached() const  // retrieves the value of allStartPositionsReached
{
    return (allStartPositionsReached);
}
void offenseState::setAllStartPositionsReached(const bool &set)  // sets the value of allStartPositionsReached
{
    allStartPositionsReached = set;
}

std::vector< boolVec > offenseState::getExecutePositionReached() const  // returns the value of executePositionSet
{
    return (executePositionReached);
}
void offenseState::setExecutePositionReached(const std::vector<boolVec> &set) // sets the value of executePositionSet
{
    executePositionReached = set;
}

void offenseState::setupState()  // sets up initial state of the object
{
//    startPositions[0] = Ogre::Vector3(5.0f,-13.5f,380.0f);
}

void offenseState::updateState(teamTypes teamType, const gameComponentsSharedPtr &gameComponent, const gameDataSharedPtr &gameData)  // updates the state of the object
{
//    sharedPtr<gameState> gameS = gameState::Instance();
//    teamStateVecSharedPtr activeTeamInstance = gameS->getActiveTeamInstance();
    teamEntityMSharedPtr activeTeamInstance = gameComponent->getActiveTeamInstance();
//TS    playerStateVecSharedPtr activePlayerInstance = activeTeamInstance[teamType]->getActivePlayerInstance();

    if (!offenseSetup)
    {
        setupOffense(gameData);
    }
    else
    {
        executeOffense(gameComponent, gameData);
    }
//TS    activeTeamInstance[teamType]->setActivePlayerInstance(activePlayerInstance);
    gameComponent->setActiveTeamInstance(activeTeamInstance);
}

void offenseState::loadPlays()  // loads offense plays from file
{
    loadOffensePlaysSharedPtr loadOffensePlay(new loadOffensePlays);

    if (loadOffensePlay->checkIfOffensePlaysLoaded())
    {
        plays = loadOffensePlay->loadOffensePlayFiles();
    }
    else
    {
        logMsg("Unable to load offense plays!");
        exit(0);
    }
}

void offenseState::setupOffense(const gameDataSharedPtr &gameData)  // sets up box offense
{
    conversionSharedPtr convert ;
//    sharedPtr<gameEngine> gameE = gameEngine::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();

//    quarters currentQuarter = gameS->getQuarter();  // gets the current quarter the game is in.
    quarters currentQuarter = gameData->getQuarter();

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
    default:
    break;
    }
    
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
    for (size_t x=0;x<plays.size();++x)
//    for (PIT = plays.begin(); PIT != plays.end(); ++PIT)
    {
        if (plays[x]->getPlayName() == playName)  // sets up the offense
        {
            if (plays[x]->getTitle() == playTitle) 
            {
                startPositions = plays[x]->getStartPositions();
                executePositions = plays[x]->getExecutePositions();
                playerDirective = plays[x]->getPlayerDirective();
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
  
    float yOffset = gameData->getYOffset();
    for (size_t y=0;y < startPositions.size(); ++y)
    {
        startPositions[y].y = yOffset;
    }
    for (size_t x=0;x<executePositions.size();++x)
    {
        for (size_t y=0;y<executePositions[x].size();++y)
        {
            executePositions[x][y].y = yOffset;
            //exit(0);
        }
    }
        
    offenseSetup = true;
}

void offenseState::executeOffense(const gameComponentsSharedPtr &gameComponent, const gameDataSharedPtr &gameData)  // executes box offense
{
    conversionSharedPtr convert ;
//    sharedPtr<gameState> gameS = gameState::Instance();
    teamTypes teamWithBall = gameData->getTeamWithBall();

    teamEntityMSharedPtr activeTeamInstance = gameComponent->getActiveTeamInstance();
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

bool offenseState::checkForDirective(playerPositions playerPosition)  // checks if a directive needs to be completed before execution
{
    conversionSharedPtr convert ;
    bool retVal = true;
    size_t x = 0;
    logMsg("playerDirective.size() == " +convert->toString(playerDirective.size()));
    while (x < playerDirective.size())
    {
        logMsg("playerPosition = " +convert->toString(playerDirective[x].getPlayerPosition()));
        if (playerDirective[x].getPlayerPosition() == playerPosition)
        {
            //directiveTypes type =
            switch (playerDirective[x].getType())
            {
                case WAIT:
                    switch (playerDirective[x].getWaitFor())
                    {
                        case PLAYERPOSITIONSET:
                            logMsg("playerSet = " +convert->toString(playerDirective[x].getPlayerSet()));
                            switch (playerDirective[x].getPositionType())
                            {
                                case START:
                                    logMsg("offense position type = START");
                                    logMsg("startPositionReached.size() == " +convert->toString(startPositionReached.size()));
                                    logMsg("x == " +convert->toString(x));
                                    logMsg("playerSet == " +convert->toString(playerDirective[x].getPlayerSet()));
                                    logMsg("startPositionReached == " +convert->toString(startPositionReached[playerDirective[x].getPlayerSet()]));
                                    if (!startPositionReached[playerDirective[x].getPlayerSet()])
                                    {
                                        //exit(0);
                                    }
                                    logMsg("surived startPosition reached!");
                                break;
                                case EXECUTE:
                                    logMsg("offense position type = EXECUTe");
                                    if (!executePositionReached[playerDirective[x].getPlayerSet()][playerDirective[x].getPosition()])
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
            }
        }
        ++x;
    }
    return (retVal);
}

void offenseState::executePass()  // executes the pass between players
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
