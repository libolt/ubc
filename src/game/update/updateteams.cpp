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

#include "update/updateteams.h"
#include "data/teamgamedata.h"
#include "entity/teamentity.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

updateTeams::updateTeams()  // constructor
{
    
}
updateTeams::~updateTeams()  // destructor
{
    
}

void updateTeams::updateActivePlayers()  // updates the states of active players
{
    conversionSharedPtr convert = conversion::Instance();
    playerEntityMSharedPtr activePlayerInstance = component->getActivePlayerInstance();

    std::string func = "updateTeams::updateActivePlayers()";

    logMsg(func +" begin");
    
    for (auto APIIT : activePlayerInstance)
    {
        logMsg(func +" APIIT.second->getGameData()->getStateAction().size() = " +convert->toString(APIIT.second->getGameData()->getStateAction().size()));
    }
//    exit(0);
    
    for (auto APIIT : activePlayerInstance)  // executes updates to activePlayerInstances
    {
        APIIT.second->update();
    }
//    exit(0);
//FIXME! Needs refactored after playerStateMachine migration
/*    conversionSharedPtr convert = conversion::Instance();
    std::string func = "teamState::updatePlayerStates()";
    size_t x = 0;
    
    logMsg(func +" begin");
//    exit(0);
    //    while (x<activePlayerInstance.size())
    for (auto APIIT : activePlayerInstance)
    {
        std::string xString = convert->toString(x);
        APIIT.second->updateState();
        logMsg(func +" " +xString + " Name == " +APIIT.second->getData()->getFirstName() +" " +APIIT.second->getData()->getLastName());
        logMsg(func +" " +xString + " Entity UC Name == " +APIIT.second->getEntityName());
        logMsg(func +" " +xString + " Entity UC Node Name == " +APIIT.second->getEntityNodeName());
        logMsg(func +" " +xString + " UC Node Name == " +APIIT.second->getNode()->getName());




//        APIIT.second->getNode()->setPosition(Ogre::Vector3(-20,15,400));
///        logMsg(func +" APIIT.second->getPlayerEntity()->getNode()->getPosition() == " +convert->toString(APIIT.second->getNode()->getPosition()));
///        logMsg("PlayerSteerNode Position == " +convert->toString(APIIT.second->getNode()->getPosition()));
///        logMsg("PlayerSteer Position == " +convert->toString(APIIT.second->getSteer()->position()));
        ++x;
        
    }

//    exit(0);
*/

    component->setActivePlayerInstance(activePlayerInstance);

    logMsg(func +" end");

}

void updateTeams::updatePlayerDirections(gameComponentsSharedPtr gameComponent)  // updates the direction players are facing
{
    conversionSharedPtr convert = conversion::Instance();
    playerEntityMSharedPtr activePlayerInstance = component->getActivePlayerInstance();
    directions playerDirection, oldPlayerDirection;
    basketballStateMSharedPtr basketballInstance = gameComponent->getBasketballInstance();
    std::vector<Ogre::SceneNode>::iterator playersIT;
    std::string playerID = convert->toString(activePlayerInstance[4]->getData()->getID());
    std::string func = "updateTeams::updatePlayerDirections()";

    logMsg(func +" begin");

    exit(0);
    for (auto APIIT : activePlayerInstance)
    {
        playerDirection = APIIT.second->getGameData()->getDirection();
        oldPlayerDirection = APIIT.second->getGameData()->getOldDirection();
        if (oldPlayerDirection != playerDirection)
        {
            
            
///            std::string oldPlayerDirect = Ogre::SingConverter::toString(oldPlayerDirection[i]);
///            std::string playerDirect = toString(playerDirection[i]);
///            std::string bballPlayer = toString(basketballInstance[activeBBallInstance].getPlayer());
///            logMsg(func +" oldPlayerDirection = " + oldPlayerDirect);
///            logMsg(func +" playerDirection = " + playerDirect);
///            logMsg(func +" bball player = " + bballPlayer);
///            playerInstance[basketballInstance[activeBBallInstance]->getPlayer()] = playerInstance[i];
//            playerNodes.at(basketballInstance[activeBBallInstance]->getPlayer()) = playerNodes.at(i);  // sets the current player node
            
            switch (oldPlayerDirection)
            {
                case UP:
                    switch (playerDirection)
                    {
                        case DOWN:
                            APIIT.second->getNode()->yaw(Ogre::Degree (180));
                            break;
                        case LEFT:
                            APIIT.second->getNode()->yaw(Ogre::Degree (270));
                            break;
                        case RIGHT:
                            APIIT.second->getNode()->yaw(Ogre::Degree (90));
//                            exit(0);
                            break;
                        default:
                            break;
                    }
                    break;
                case DOWN:
                    switch (playerDirection)
                    {
                        case UP:
                            APIIT.second->getNode()->yaw(Ogre::Degree (180));
                            break;
                        case LEFT:
                            APIIT.second->getNode()->yaw(Ogre::Degree (90));
                            break;
                        case RIGHT:
                            APIIT.second->getNode()->yaw(Ogre::Degree (270));
                            break;
                        default:
                            break;
                    }
                    break;
                    case LEFT:
                        switch (playerDirection)
                        {
                            case UP:
                                APIIT.second->getNode()->yaw(Ogre::Degree (90));
                                break;
                            case DOWN:
                                APIIT.second->getNode()->yaw(Ogre::Degree (270));
                                break;
                            case RIGHT:
                                APIIT.second->getNode()->yaw(Ogre::Degree (180));
                                break;
                            default:
                                break;
                        }
                        break;
                    case RIGHT:
                        switch (playerDirection)
                        {
                            case UP:
                                APIIT.second->getNode()->yaw(Ogre::Degree (270));
                                break;
                            case DOWN:
                                APIIT.second->getNode()->yaw(Ogre::Degree (90));
                                break;
                            case LEFT:
                                APIIT.second->getNode()->yaw(Ogre::Degree (180));
                                break;
                            default:
                                break;
                        }
                        break;
                default:
                    break;
            }
        }
        logMsg(func +" directPlayerID == " +convert->toString(APIIT.second->getData()->getID()));
        logMsg(func +" directPlayerWithBallInstance == " +convert->toString(gameData->getPlayerWithBallInstance()));
        if (APIIT.second->getData()->getID() != gameData->getPlayerWithBallID())
        {
            oldPlayerDirection = playerDirection;
            APIIT.second->getGameData()->setOldDirection(oldPlayerDirection);  // copies contents of oldPlayerDirection to the oldDirection variable
        }
        else
        {
        }
///            }
///            ++y;
///        }

//        ++x;
    }

    component->setActivePlayerInstance(activePlayerInstance);

    logMsg(func + " end");
}


void updateTeams::updatePlayerMovements()  // updates player movements
{
    //conversion *convert = conversion::Instance();
    conversionSharedPtr convert = conversion::Instance();
    playerEntityMSharedPtr activePlayerInstance = component->getActivePlayerInstance();
    Ogre::Vector3 posChange;    // stores change in position
    posChange = Ogre::Vector3(0.0f, 0.0f, 0.0f);
    std::string func = "updateTeams::updatePlayerMovements()";

    logMsg(func +" begin");


    for (auto APIIT : activePlayerInstance)
    {
        if (APIIT.second->getFlag()->getMovement()) // if true sets coordinate change accordingly
        {
//                    exit(0);
            if (APIIT.second->getGameData()->getDirection() == UP)
            {
                posChange = Ogre::Vector3(0.0f, 0.0f, -0.400f);
                logMsg("UP!");
//              exit(0);
            }
            else if (APIIT.second->getGameData()->getDirection() == DOWN)
            {
                posChange = Ogre::Vector3(0.0f, 0.0f, 0.400f);
            }
            else if (APIIT.second->getGameData()->getDirection() == LEFT)
            {
//              exit(0);

                posChange = Ogre::Vector3(-0.400f, 0.0f, 0.0f);
//              playerInstance[i]->getPhysBody()->setLinearVelocity(btVector3(0.4,0,0));
            }
            else if (APIIT.second->getGameData()->getDirection() == RIGHT)
            {
                posChange = Ogre::Vector3(0.400f, 0.0f, 0.0f);
            }
            else if (APIIT.second->getGameData()->getDirection() == UPLEFT)
            {
                posChange = Ogre::Vector3(-0.400f, 0.0f, -0.400f);
            }
            else if (APIIT.second->getGameData()->getDirection() == UPRIGHT)
            {
                posChange = Ogre::Vector3(0.400f, 0.0f, -0.400f);
            }
            else if (APIIT.second->getGameData()->getDirection() == DOWNLEFT)
            {
                posChange = Ogre::Vector3(-0.400f, 0.0f, 0.400f);
            }
            else if (APIIT.second->getGameData()->getDirection() == DOWNRIGHT)
            {
                posChange = Ogre::Vector3(0.400f, 0.0f, 0.400f);
            }

        }
        else if (!APIIT.second->getFlag()->getMovement())   // if false then sets their coordinate changes to 0.0
        {
            posChange = Ogre::Vector3(0.0f, 0.0f, 0.0f);
        }

        if (posChange.x != 0 || posChange.y != 0 || posChange.z != 0)
        {
            APIIT.second->getGameData()->setNewCourtPosition(posChange);    // sets the newCourtPosition for current playerInstance
            APIIT.second->getFlag()->setCourtPositionChanged(true);
            APIIT.second->getGameData()->setCourtPositionChangedType(INPUTCHANGE);
            APIIT.second->getFlag()->setMovement(false);
        }       
//        ++x;
    }

    component->setActivePlayerInstance(activePlayerInstance);

    logMsg(func + " end");
    
}

void updateTeams::updatePositions()  // updates player on court positions
{
//FIXME! Needs reworked after playerStateMachine migration
/*
    //conversion *convert = conversion::Instance();
    conversionSharedPtr convert = conversion::Instance();
    
//    size_t x = 0;
    // updates the player positions on the court
//    while (x<activePlayerInstance.size())
    for (auto APIIT : activePlayerInstance)
    {
        exit(0);
//      logMsg("updatePositions X = " +convert->toString(x));
        APIIT.second->updateCourtPosition();
//        x++;
    }
    logMsg("courtPosition updated!!");
*/
}

void updateTeams::updateActivePlayerSettings()  // updates the settings of active players
{

}

