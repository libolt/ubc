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
#include "utilities/enums.h"
#include "utilities/logging.h"
#include "state/networkstate.h"
#include "network/networkplayerstateobject.h"
#include "data/teamgamedata.h"
#include "engine/networkengine.h"
#include "engine/inputengine.h"
#include "entity/playerentity.h"
#include "entity/teamentity.h"
#include "flags/teamflags.h"

networkState::networkState()  // constructor
{
    network = nullptr;
}
networkState::~networkState() = default;  // destructor

networkEngineSharedPtr networkState::getNetworkE() const  // retrieves the value of network
{
    return (network);
}

void networkState::setNetwork(const networkEngineSharedPtr &set)  // sets the value of network
{
    network = set;
}

void networkState::processLocalInput(teamEntityVecSharedPtr activeTeamInstance)  // processes local input for sending to remote system
{
//    sharedPtr<inputSystem> input = inputSystem::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
    conversionSharedPtr convert;
    inputInGameWorkQueues inputQueue;
    inputInGameWorkQueues::iterator IQITT;
    networkPlayerStateObject netPStateObj;
    
//    teamStateVecSharedPtr activeTeamInstance = gameS->getActiveTeamInstance();
    int humanControlled = activeTeamInstance[getNetworkE()->getTeamType()]->getFlag()->getHumanControlled();
    std::string humanPlayer = convert->toString(activeTeamInstance[getNetworkE()->getTeamType()]->getGameData()->getHumanPlayer());

//                              logMsg("INPUT MAP ======== "  +toString(inputMap));
    std::string packetData;
    std::stringstream ss;
    //  exit(0);
    size_t x = 0;
    while (!inputQueue.empty())
    {
        // switch (inputMap)
        switch (inputQueue[x])
        {
            case INUP:
//                                      packetData = "player0up";
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(getNetworkE()->getTeamType());
//                netPStateObj.setPlayerID(humanPlayer);
                netPStateObj.setMovement(true);
                netPStateObj.setDirection(0);
                ss << netPStateObj;
                packetData = ss.str();
            break;
            case INDOWN:
//                                      packetData = "player0down";
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(getNetworkE()->getTeamType());
//                netPStateObj.setPlayerID(humanPlayer);
                netPStateObj.setMovement(true);
                netPStateObj.setDirection(1);
                ss << netPStateObj;
                packetData = ss.str();
            break;
            case INLEFT:
//                                      packetData = "player0left";
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(getNetworkE()->getTeamType());
//                netPStateObj.setPlayerID(humanPlayer);
                netPStateObj.setMovement(true);
                netPStateObj.setDirection(2);
                ss << netPStateObj;
                packetData = ss.str();
            break;
            case INRIGHT:
//                                      packetData = "player0right";
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(getNetworkE()->getTeamType());
//                netPStateObj.setPlayerID(humanPlayer);
                netPStateObj.setMovement(true);
                netPStateObj.setDirection(3);
                ss << netPStateObj;
                packetData = ss.str();
            break;
            case INUPLEFT:
//                                      packetData = "player0upleft";
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(getNetworkE()->getTeamType());
//                netPStateObj.setPlayerID(humanPlayer);
                netPStateObj.setMovement(true);
                netPStateObj.setDirection(4);
                ss << netPStateObj;
                packetData = ss.str();
            break;
            case INUPRIGHT:
//                                      packetData = "player0upright";
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(getNetworkE()->getTeamType());
//                netPStateObj.setPlayerID(humanPlayer);
                netPStateObj.setMovement(true);
                netPStateObj.setDirection(5);
                ss << netPStateObj;
                packetData = ss.str();
            break;
            case INDOWNLEFT:
//                                      packetData = "player0downleft";
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(getNetworkE()->getTeamType());
//                netPStateObj.setPlayerID(humanPlayer);
                netPStateObj.setMovement(true);
                netPStateObj.setDirection(6);
                ss << netPStateObj;
                packetData = ss.str();
            break;
            case INDOWNRIGHT:
//                                      packetData = "player0downright";
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(getNetworkE()->getTeamType());
//                netPStateObj.setPlayerID(humanPlayer);
                netPStateObj.setMovement(true);
                netPStateObj.setDirection(7);
                ss << netPStateObj;
                packetData = ss.str();
            break;
            case INSHOOTBLOCK:
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(getNetworkE()->getTeamType());
//                netPStateObj.setPlayerID(humanPlayer);
                netPStateObj.setMovement(false);
                netPStateObj.setShootBlock(true);
                ss << netPStateObj;
                packetData = ss.str();
            break;
            case INPASSSTEAL:
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(getNetworkE()->getTeamType());
//                netPStateObj.setPlayerID(humanPlayer);
                netPStateObj.setMovement(false);
                netPStateObj.setPassSteal(true);
                ss << netPStateObj;
                packetData = ss.str();
            break;
            case INQUIT:
//                logMsg("Quitting!");
//                quitGame = true;
                //exit(0);
            break;
            default:
            
///                netPStateObj.setPacketType(3);
///                netPStateObj.setTeamID(teamType);
///                netPStateObj.setPlayerID(1);
///                std::stringstream ss;
///                ss << netPStateObj;
///                packetData = ss.str();
            
                packetData = "";
            break;
        }
        if (!packetData.empty())
        {
            getNetworkE()->sendPacket(packetData);
        }
        ++x;
    }
    inputQueue.clear();
/*    if (gameS->getGameType() == MULTI && clientRunning && packetData != "") // checks if game is running in client mode
    {
        logMsg("client packetData = " +packetData);
        sendPacket(packetData);
    }
    else  if (gameS->getGameType() == MULTI && serverRunning && packetData != "")
    {
        logMsg("server packetData = " +packetData);
        sendPacket(packetData);
    }
    else
    {
    }
*/
}

void networkState::processRemoteInput() // processes input received from a remote system
{
    
}

void networkState::processNetworkEvents(const teamEntityVecSharedPtr &activeTeamInstance)  // processes events from network code
{
//    teamStateVecSharedPtr activeTeamInstance = getActiveTeamInstance();
    //    networkEngineSharedPtr network = networkEngine::Instance();

//  std::vector <playerState> playerInstance = gameS->getPlayerInstance();

    if(Ogre::StringUtil::startsWith(getNetworkE()->getReceivedData(), "3" ))
    {
        logMsg("process!ng network player event");
        processNetworkPlayerEvents(activeTeamInstance);
    }

//  teamStateVec teamInstance = teamInstance();
/*TS    activeTeamInstance[0]->setPlayerType("human");  // sets playerType for activeTeamInstance 0 to human

    // checks if this instance is a server and whether activeTeamInstance 1 is set to be controlled by network player
    if (getNetworkE()->getServerReceivedConnection() && activeTeamInstance[1]->getPlayerType() != "network")
    {
        activeTeamInstance[1]->setPlayerType("network");  // sets activeTeamInstance 1 playerType to 'network'
    }
    // checks if this instance is a client and whether activeTeamInstance 0 is set to be controlled by network player
    else if (getNetworkE()->getClientEstablishedConnection() && activeTeamInstance[0]->getPlayerType() != "network" )
    {
        activeTeamInstance[0]->setPlayerType("network");
    }
TS*/
///    setActiveTeamInstance(activeTeamInstance);
}

void networkState::processNetworkPlayerEvents(const teamEntityVecSharedPtr &activeTeamInstance)  // processes player events from network code
{
    conversionSharedPtr convert ;
//    networkEngineSharedPtr network = networkEngine::Instance();

//    teamStateVecSharedPtr activeTeamInstance = getActiveTeamInstance();

    networkPlayerStateObject netPStateObj;
    std::stringstream strStream;
    playerEntityVecSharedPtr activePlayerInstance;
    std::string receivedData = getNetworkE()->getReceivedData();  // stores receivedData value
    size_t playerNumber = -1;  // stores which player the data is for
    size_t iterator;  // iterator for match loop

    logMsg("received Data === " +receivedData);
    strStream << receivedData;
    strStream >> netPStateObj;
    logMsg("received teamID = " +convert->toString(netPStateObj.getTeamID()));
    logMsg("received playerID = " +convert->toString(netPStateObj.getPlayerID()));

    // sets which team's activePlayerInstance to use
    if (getNetworkE()->getIsClient())
    {
        logMsg("is client");
//TS        activePlayerInstance = activeTeamInstance[1]->getActivePlayerInstance();
    }
    else if (getNetworkE()->getIsServer())
    {
        logMsg("is server");
//TS        activePlayerInstance = activeTeamInstance[0]->getActivePlayerInstance();
    }
    else
    {
    }
    logMsg("activePlayerInstance size == " +convert->toString(activePlayerInstance.size()));
/*  for (iterator = 0; iterator < 5; ++iterator)
    {
        std::string searchString;   // stores search String
        std::string searchIterator = convert->toString(iterator); // converts iterator to a string
        searchString = "*" +searchIterator + "*";   // creates search string
        if (Ogre::StringUtil::match(receivedData,searchString)) // checks for a match
        {
            playerNumber = iterator;    // sets playerNumber to value of iterator
        }
    }
    logMsg("alive????");
*/
    playerNumber = netPStateObj.getPlayerID();
    if (!activePlayerInstance.empty())
    {
        if (netPStateObj.getMovement())
        {
//FIXME! Needs reworked once playerStateMachine is implemented
/*            switch (netPStateObj.getDirection())
            {
                case 0:  // move player up
                    activePlayerInstance[playerNumber]->setMovement(true);
                    activePlayerInstance[playerNumber]->setDirection(UP);
                break;
                case 1:  // move player down
                    activePlayerInstance[playerNumber]->setMovement(true);
                    activePlayerInstance[playerNumber]->setDirection(DOWN);
                break;
                case 2:  // move player left
                    activePlayerInstance[playerNumber]->setMovement(true);
                    activePlayerInstance[playerNumber]->setDirection(LEFT);
                break;
                case 3:  // move player right
                    activePlayerInstance[playerNumber]->setMovement(true);
                    activePlayerInstance[playerNumber]->setDirection(RIGHT);
                break;
                case 4:  // move player up and left
                    activePlayerInstance[playerNumber]->setMovement(true);
                    activePlayerInstance[playerNumber]->setDirection(UPLEFT);
                break;
                case 5:  // move player up aned right
                    activePlayerInstance[playerNumber]->setMovement(true);
                    activePlayerInstance[playerNumber]->setDirection(UPRIGHT);
                break;
                case 6:  // move player down and left
                    activePlayerInstance[playerNumber]->setMovement(true);
                    activePlayerInstance[playerNumber]->setDirection(DOWNLEFT);
                break;
                case 7:  // move player down and right
                    activePlayerInstance[playerNumber]->setMovement(true);
                    activePlayerInstance[playerNumber]->setDirection(DOWNRIGHT);
                break;
                default:
                    activePlayerInstance[playerNumber]->setMovement(false);
                break;
            }
*/
            if (getNetworkE()->getIsClient())
            {
//TS                activeTeamInstance[1]->setActivePlayerInstance(activePlayerInstance);
            }
            else if (getNetworkE()->getIsServer())
            {
//TS                activeTeamInstance[0]->setActivePlayerInstance(activePlayerInstance);
            }
        }
        else if (netPStateObj.getShootBlock())
        {
        }
        else if (netPStateObj.getPassSteal())
        {
        }
        else
        {
        }
    }
//    setActiveTeamInstance(activeTeamInstance);
    logMsg("Survived!");
    getNetworkE()->setReceivedData("");
}
