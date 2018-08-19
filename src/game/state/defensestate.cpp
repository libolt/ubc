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
#include "utilities/logging.h"
#include "components/gamecomponents.h"
#include "data/gamedata.h"
#include "state/defensestate.h"
#include "entity/gameentity.h"
#include "state/playerstate.h"
//#include "state/teamstate.h"

defenseState::defenseState() // constructor
{
//    gameSInitialized = false;
    teamType = NOTEAM;
    courtSide = NOSIDE;
    execute = false;
}

/*gameStateSharedPtr defenseState::getGameS()  // retrieves the value of gameS
{
    return (gameS);
}
void defenseState::setGameS(gameStateSharedPtr set)  // sets the value of gameS
{
    gameS = set;
}

bool defenseState::getGameSInitialized()  // retrieves the value of gameSInitialized
{
    return (gameSInitialized);
}
void defenseState::setGameSInitialized(bool set)  // sets the value of gameSInitialized
{
    gameSInitialized = set;
}
*/

teamTypes defenseState::getTeamType()  // retrieves the value of teamType
{
    return (teamType);
}
void defenseState::setTeamType(teamTypes set)  // sets the value of teamType
{
    teamType = set;
}

courtSide_t defenseState::getCourtSide()  // retrieves the value of courtSide
{
    return (courtSide);
}
void defenseState::setCourtSide(courtSide_t set)  // sets the value of courtSide
{
    courtSide = set;
}

bool defenseState::getExecute() // retrieves the value of execute variable
{
    return (execute);
}
void defenseState::setExecute(bool ex)  // sets the value of the execute variable
{
    execute = ex;
}

void defenseState::setupState(gameComponentsSharedPtr gameComponent)  // sets up initial state of the object
{

}

void defenseState::updateState(teamTypes teamType, gameComponentsSharedPtr gameComponent, gameDataSharedPtr gameData)  // updates the state of the object
{
    conversionSharedPtr convert = conversion::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
    teamTypes teamWithBall = gameData->getTeamWithBall();

    teamEntityMSharedPtr activeTeamInstance = gameComponent->getActiveTeamInstance();
//TS    playerStateVecSharedPtr playerDInstance = activeTeamInstance[teamOnDefense]->getActivePlayerInstance();
//TS    playerStateVecSharedPtr playerOInstance = activeTeamInstance[teamWithBall]->getActivePlayerInstance();
//TS    sizeTVec activeDID = activeTeamInstance[teamOnDefense]->getActivePlayerID();
//TS    sizeTVec activeOID = activeTeamInstance[teamWithBall]->getActivePlayerID();
    OgreVector3Vec playerOPos;  // stores positions of offensive players
    OgreVector3Vec playerDPos;  // stores positions of defensive players

//TS    int humanPlayer = activeTeamInstance[teamOnDefense]->getHumanPlayer();
//TS    int numPlayers = activeDID.size(); // stores the number of players on the court per team
//  exit(0);
    if (execute)
    {
/*
        for (int x=0;x<playerOInstance.size();++x)
        {
            playerOPos.push_back(playerOInstance[x].getNode()->getPosition());
        }

        for (int x=0;x<playerDInstance.size();++x)
        {
            playerDPos.push_back(playerDInstance[x].getNode()->getPosition());
        }
*/
//        activePlayerInstance = activeTeamInstance[1].getPlayerInstance();
        size_t x = 0;
/*TS        while (x<playerOInstance.size())
        {
            size_t i = 0;
            while (i<activeOID.size())
            {
                if (activeOID[i] == playerOInstance[x]->getID())
                {
                    playerOPos.push_back(playerOInstance[x]->getNode()->getPosition());

                    logMsg("offensive player set!");
                }
                i++;
            }
            x++;
        }
        
        x = 0;
        while (x<playerDInstance.size())
        {
            size_t i = 0;
            while (i<activeDID.size())
            {
                if (activeDID[i] == playerDInstance[x]->getID())
                {
                    playerDPos.push_back(playerDInstance[x]->getNode()->getPosition());

                    logMsg("offensive player set!");
                }
                i++;
            }
            x++;
        }
//        exit(0);
        x = 0;
//      for (int x=0;x<playerDInstance.size();++x)
        std::vector<int> activeDNum; // stores the position in the playerDInstance vector that a player belongs to
        std::vector<int> activeONum; // stores the position in the playerOInstance vector that a player belongs to

        for (size_t j=0;j<5;++j)
        {
            int z = 0;
            activeDNum.push_back(z);
            activeONum.push_back(z);
        }
        while (x<playerDInstance.size())
        {
            size_t i = 0;
            while (i<activeDID.size())
            {
                if (activeDID[i] == playerDInstance[x]->getID())
                {
                    if (playerDInstance[x]->getActivePosition() == PG)
                    {
                        activeDNum[0] = x;
                    }
                    else if (playerDInstance[x]->getActivePosition() == SG)
                    {
                        activeDNum[1] = x;
                    }
                    else if (playerDInstance[x]->getActivePosition() == SF)
                    {
                        activeDNum[2] = x;
                    }
                    else if (playerDInstance[x]->getActivePosition() == PF)
                    {
                        activeDNum[3] = x;
                    }
                    else if (playerDInstance[x]->getActivePosition() == C)
                    {
                        activeDNum[4] = x;
                    }
                }
                else
                {
                }
                i++;
            }
            x++;
        }
        
        x = 0; // resets x
        while (x<playerOInstance.size())
        {
            size_t i = 0;
            while (i<activeOID.size())
            {
                if (activeOID[i] == playerOInstance[x]->getID())
                {
                    if (playerOInstance[x]->getActivePosition() == PG)
                    {
                        activeONum[0] = x;
                    }
                    else if (playerOInstance[x]->getActivePosition() == SG)
                    {
                        activeONum[1] = x;
                    }
                    else if (playerOInstance[x]->getActivePosition() == SF)
                    {
                        activeONum[2] = x;
                    }
                    else if (playerOInstance[x]->getActivePosition() == PF)
                    {
                        activeONum[3] = x;
                    }
                    else if (playerOInstance[x]->getActivePosition() == C)
                    {
                        activeONum[4] = x;
                    }
                }
                else
                {
                }
                i++;
            }
            x++;
        }
        
        x = 0; // resets x
        while (x<numPlayers) // loops until the number of players on court per team is reached
        {
            int DNum = activeDNum[x];
            if (DNum < activeDNum.size() && DNum < playerDInstance.size())
            {
                if (activeDNum[DNum] != humanPlayer && !playerDInstance[DNum]->getDefenseSet())
                {
                    logMsg("playerO " +convert->toString(x) +"X Pos = " +convert->toString(playerOPos[x][0]));
                    logMsg("playerD " +convert->toString(x) +"X Pos = " +convert->toString(playerDPos[x][0]));
                    logMsg("playerO " +convert->toString(x) +"Z Pos = " +convert->toString(playerOPos[x][2]));
                    logMsg("playerD " +convert->toString(x) +"Z Pos = " +convert->toString(playerDPos[x][2]));
                    directions playerDirection = playerOInstance[x]->getDirection();
    //                exit(0);
                    switch (playerDirection)
                    {
                        case LEFT:
                            if (playerDPos[x][0] >= (playerOPos[x][0] + 4.0f))
                            {

                                playerDInstance[x]->setMovement(true);
                                playerDInstance[x]->setDirection(LEFT);
                            }
                            else if (playerDPos[x][0] <= (playerOPos[x][0] - 4.0f))
                            {
                                playerDInstance[x]->setMovement(true);
                                playerDInstance[x]->setDirection(RIGHT);
                            }
                        break;
                        case RIGHT:
                            if (playerDPos[x][0] <= (playerOPos[x][0] + 4.0f))
                            {
                                playerDInstance[x]->setMovement(true);
                                playerDInstance[x]->setDirection(RIGHT);
                            }
                           else if (playerDPos[x][0] >= (playerOPos[x][0] - 4.0f))
                           {
                               playerDInstance[x]->setMovement(true);
                               playerDInstance[x]->setDirection(LEFT);
                           }
                        break;
                        case UP:
                            if (playerDPos[x][2] >= (playerOPos[x][2] - 1.0f))
                            {
                                playerDInstance[x]->setMovement(true);
                                playerDInstance[x]->setDirection(UP);
                            }
                            else if (playerDPos[x][2] <= (playerOPos[x][2] + 1.0f))
                                {
                                    playerDInstance[x]->setMovement(true);
                                    playerDInstance[x]->setDirection(DOWN);
                                }
                        break;
                        case DOWN:
                            if (playerDPos[x][2] <= (playerOPos[x][2] + 1.0f))
                            {
                                playerDInstance[x]->setMovement(true);
                                playerDInstance[x]->setDirection(DOWN);
                            }
                            else if (playerDPos[x][2] >= (playerOPos[x][2] - 1.0f))
                            {
                                playerDInstance[x]->setMovement(true);
                                playerDInstance[x]->setDirection(UP);
                            }
                        break;
                        case UPLEFT:
                            if (playerDPos[x][2] >= (playerOPos[x][2] - 1.0f) && playerDPos[x][0] >= (playerOPos[x][0] + 4.0f))
                                {
                                    playerDInstance[x]->setMovement(true);
                                    playerDInstance[x]->setDirection(UPLEFT);
                                }
                            else if (playerDPos[x][2] <= (playerOPos[x][2] + 1.0f) && playerDPos[x][0] <= (playerOPos[x][0] - 4.0f))
                            {
                                playerDInstance[x]->setMovement(true);
                                playerDInstance[x]->setDirection(DOWNRIGHT);
                            }
                        break;
                        case UPRIGHT:
                            if (playerDPos[x][2] >= (playerOPos[x][2] - 1.0f) && playerDPos[x][0] <= (playerOPos[x][0] + 4.0f))
                            {
                                playerDInstance[x]->setMovement(true);
                                playerDInstance[x]->setDirection(UPRIGHT);
                            }
                            else if (playerDPos[x][2] <= (playerOPos[x][2] + 1.0f) && playerDPos[x][0] >= (playerOPos[x][0] - 4.0f))
                            {
                                playerDInstance[x]->setMovement(true);
                                playerDInstance[x]->setDirection(DOWNLEFT);
                            }
                        break;
                        case DOWNLEFT:
                            if (playerDPos[x][2] <= (playerOPos[x][2] + 1.0f) && playerDPos[x][0] >= (playerOPos[x][0] + 4.0f))
                            {
                                playerDInstance[x]->setMovement(true);
                                playerDInstance[x]->setDirection(DOWNLEFT);
                            }
                            else if (playerDPos[x][2] >= (playerOPos[x][2] - 1.0f) && playerDPos[x][0] <= (playerOPos[x][0] - 4.0f))
                            {
                                playerDInstance[x]->setMovement(true);
                                playerDInstance[x]->setDirection(UPRIGHT);
                            }
                        break;
                        case DOWNRIGHT:
                            if (playerDPos[x][2] <= (playerOPos[x][2] + 1.0f) && playerDPos[x][0] <= (playerOPos[x][0] + 4.0f))
                            {
                                playerDInstance[x]->setMovement(true);
                                playerDInstance[x]->setDirection(DOWNRIGHT);
                            }
                            else if (playerDPos[x][2] >= (playerOPos[x][2] - 1.0f) && playerDPos[x][0] >= (playerOPos[x][0] - 4.0f))
                            {
                                playerDInstance[x]->setMovement(true);
                                playerDInstance[x]->setDirection(UPLEFT);
                            }
                        break;
                        default:
                            playerDInstance[x]->setMovement(false);
                        break;
                    }
                }
            }
            x++;
        }
TS*/
/*        
                if (x != humanPlayer && !playerDInstance[x].getDefenseSet())
                {
                    logMsg("playerO " +convert->toString(x) +"X Pos = " +convert->toString(playerOPos[x][0]));
                    logMsg("playerD " +convert->toString(x) +"X Pos = " +convert->toString(playerDPos[x][0]));
                    logMsg("playerO " +convert->toString(x) +"Z Pos = " +convert->toString(playerOPos[x][2]));
                    logMsg("playerD " +convert->toString(x) +"Z Pos = " +convert->toString(playerDPos[x][2]));
                    directions playerDirection = playerOInstance[x].getDirection();
                    switch (playerDirection)
                    {
                    case LEFT:
                        if (playerDPos[x][0] >= (playerOPos[x][0] + 4.0f))
                        {
      
                            playerDInstance[x].setMovement(true);
                            playerDInstance[x].setDirection(LEFT);
                        }
                        else if (playerDPos[x][0] <= (playerOPos[x][0] - 4.0f))
                        {
                            playerDInstance[x].setMovement(true);
                            playerDInstance[x].setDirection(RIGHT);
                        }
                    break;
                    case RIGHT:
                        if (playerDPos[x][0] <= (playerOPos[x][0] + 4.0f))
                        {
                            playerDInstance[x].setMovement(true);
                            playerDInstance[x].setDirection(RIGHT);
                        }
                       else if (playerDPos[x][0] >= (playerOPos[x][0] - 4.0f))
                       {
                           playerDInstance[x].setMovement(true);
                           playerDInstance[x].setDirection(LEFT);
                       }
                    break;
                    case UP:
                        if (playerDPos[x][2] >= (playerOPos[x][2] - 1.0f))
                        {
                            playerDInstance[x].setMovement(true);
                            playerDInstance[x].setDirection(UP);
                        }
                        else if (playerDPos[x][2] <= (playerOPos[x][2] + 1.0f))
                            {
                                playerDInstance[x].setMovement(true);
                                playerDInstance[x].setDirection(DOWN);
                            }
                    break;
                    case DOWN:
                        if (playerDPos[x][2] <= (playerOPos[x][2] + 1.0f))
                        {
                            playerDInstance[x].setMovement(true);
                            playerDInstance[x].setDirection(DOWN);
                        }
                        else if (playerDPos[x][2] >= (playerOPos[x][2] - 1.0f))
                        {
                            playerDInstance[x].setMovement(true);
                            playerDInstance[x].setDirection(UP);
                        }
                    break;
                    case UPLEFT:
                        if (playerDPos[x][2] >= (playerOPos[x][2] - 1.0f) && playerDPos[x][0] >= (playerOPos[x][0] + 4.0f))
                            {
                                playerDInstance[x].setMovement(true);
                                playerDInstance[x].setDirection(UPLEFT);
                            }
                        else if (playerDPos[x][2] <= (playerOPos[x][2] + 1.0f) && playerDPos[x][0] <= (playerOPos[x][0] - 4.0f))
                        {
                            playerDInstance[x].setMovement(true);
                            playerDInstance[x].setDirection(DOWNRIGHT);
                        }
                    break;
                    case UPRIGHT:
                        if (playerDPos[x][2] >= (playerOPos[x][2] - 1.0f) && playerDPos[x][0] <= (playerOPos[x][0] + 4.0f))
                        {
                            playerDInstance[x].setMovement(true);
                            playerDInstance[x].setDirection(UPRIGHT);
                        }
                        else if (playerDPos[x][2] <= (playerOPos[x][2] + 1.0f) && playerDPos[x][0] >= (playerOPos[x][0] - 4.0f))
                        {
                            playerDInstance[x].setMovement(true);
                            playerDInstance[x].setDirection(DOWNLEFT);
                        }
                    break;
                    case DOWNLEFT:
                        if (playerDPos[x][2] <= (playerOPos[x][2] + 1.0f) && playerDPos[x][0] >= (playerOPos[x][0] + 4.0f))
                        {
                            playerDInstance[x].setMovement(true);
                            playerDInstance[x].setDirection(DOWNLEFT);
                        }
                        else if (playerDPos[x][2] >= (playerOPos[x][2] - 1.0f) && playerDPos[x][0] <= (playerOPos[x][0] - 4.0f))
                        {
                            playerDInstance[x].setMovement(true);
                            playerDInstance[x].setDirection(UPRIGHT);
                        }
                    break;
                    case DOWNRIGHT:
                        if (playerDPos[x][2] <= (playerOPos[x][2] + 1.0f) && playerDPos[x][0] <= (playerOPos[x][0] + 4.0f))
                        {
                            playerDInstance[x].setMovement(true);
                            playerDInstance[x].setDirection(DOWNRIGHT);
                        }
                        else if (playerDPos[x][2] >= (playerOPos[x][2] - 1.0f) && playerDPos[x][0] >= (playerOPos[x][0] - 4.0f))
                        {
                            playerDInstance[x].setMovement(true);
                            playerDInstance[x].setDirection(UPLEFT);
                        }
                    break;
                    default:
                        playerDInstance[x].setMovement(false);
                    break;
                }
            }
*/
/*
                // checks to see if its the defense is in position
                if (playerDPos[x][0] > (playerOPos[x][0] -4.0f) || playerDPos[x][0] < (playerOPos[x][0] +4.0f))
                {
//                  exit(0);
                    if (playerDPos[x][0] > (playerOPos[x][0] -4.0f))
                    {
//                      exit(0);
                        Ogre::LogManager::getSingletonPtr()->logMessage("DEEEEE");

                        playerDInstance[x].setMovement(true);
                        playerDInstance[x].setDirection(LEFT);
                    }
                    else if (playerDPos[x][0] < (playerOPos[x][0] +4.0f))
                    {
//                      exit(0);
                        playerDInstance[x].setMovement(true);
                        playerDInstance[x].setDirection(RIGHT);
                    }
                    else
                    {
                        playerDInstance[x].setMovement(false);
                    }
                }
                else if (playerDPos[x][0] >= (playerOPos[x][0] -4.0f) && playerDPos[x][0] <= (playerOPos[x][0] +4.0f))
                {
//                  exit(0);
                    playerDInstance[x].setDefenseSet(true);
                }

            }
            else
            {
            }
            */
//      }
    }

//TS    activeTeamInstance[teamOnDefense]->setActivePlayerInstance(playerDInstance);
    gameComponent->setActiveTeamInstance(activeTeamInstance);

}
