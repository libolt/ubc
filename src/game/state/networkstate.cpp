/***************************************************************************
 *   Copyright (C) 1999 - 2016 by Mike McLean                              *
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

 #include "networkstate.h"
 #include "teamstate.h"

void networkState::processLocalInput(std::vector<boost::shared_ptr<teamState> > activeTeamInstance)  // processes local input for sending to remote system
{
//    boost::shared_ptr<inputSystem> input = inputSystem::Instance();
//    boost::shared_ptr<gameState> gameS = gameState::Instance();
    
    inputWorkQueues inputQueue;
    networkPlayerStateObject netPStateObj;
    
//    std::vector<boost::shared_ptr<teamState> > activeTeamInstance = gameS->getActiveTeamInstance();
    int humanControlled = activeTeamInstance[teamType]->getHumanControlled();
    int humanPlayer = activeTeamInstance[teamType]->getHumanPlayer();
    
//                              logMsg("INPUT MAP ======== "  +toString(inputMap));
    std::string packetData;
    std::stringstream ss;
    //  exit(0);
    size_t x = 0;
    while (inputQueue.size() > 0)
    {
        // switch (inputMap)
        switch (inputQueue[x])
        {
            case INUP:
//                                      packetData = "player0up";
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(teamType);
                netPStateObj.setPlayerID(humanPlayer);
                netPStateObj.setMovement(true);
                netPStateObj.setDirection(0);
                ss << netPStateObj;
                packetData = ss.str();
            break;
            case INDOWN:
//                                      packetData = "player0down";
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(teamType);
                netPStateObj.setPlayerID(humanPlayer);
                netPStateObj.setMovement(true);
                netPStateObj.setDirection(1);
                ss << netPStateObj;
                packetData = ss.str();
            break;
            case INLEFT:
//                                      packetData = "player0left";
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(teamType);
                netPStateObj.setPlayerID(humanPlayer);
                netPStateObj.setMovement(true);
                netPStateObj.setDirection(2);
                ss << netPStateObj;
                packetData = ss.str();
            break;
            case INRIGHT:
//                                      packetData = "player0right";
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(teamType);
                netPStateObj.setPlayerID(humanPlayer);
                netPStateObj.setMovement(true);
                netPStateObj.setDirection(3);
                ss << netPStateObj;
                packetData = ss.str();
            break;
            case INUPLEFT:
//                                      packetData = "player0upleft";
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(teamType);
                netPStateObj.setPlayerID(humanPlayer);
                netPStateObj.setMovement(true);
                netPStateObj.setDirection(4);
                ss << netPStateObj;
                packetData = ss.str();
            break;
            case INUPRIGHT:
//                                      packetData = "player0upright";
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(teamType);
                netPStateObj.setPlayerID(humanPlayer);
                netPStateObj.setMovement(true);
                netPStateObj.setDirection(5);
                ss << netPStateObj;
                packetData = ss.str();
            break;
            case INDOWNLEFT:
//                                      packetData = "player0downleft";
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(teamType);
                netPStateObj.setPlayerID(humanPlayer);
                netPStateObj.setMovement(true);
                netPStateObj.setDirection(6);
                ss << netPStateObj;
                packetData = ss.str();
            break;
            case INDOWNRIGHT:
//                                      packetData = "player0downright";
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(teamType);
                netPStateObj.setPlayerID(humanPlayer);
                netPStateObj.setMovement(true);
                netPStateObj.setDirection(7);
                ss << netPStateObj;
                packetData = ss.str();
            break;
            case INSHOOTBLOCK:
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(teamType);
                netPStateObj.setPlayerID(humanPlayer);
                netPStateObj.setMovement(false);
                netPStateObj.setShootBlock(true);
                ss << netPStateObj;
                packetData = ss.str();
            break;
            case INPASSSTEAL:
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(teamType);
                netPStateObj.setPlayerID(humanPlayer);
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
            /*
                netPStateObj.setPacketType(3);
                netPStateObj.setTeamID(teamType);
                netPStateObj.setPlayerID(1);
                std::stringstream ss;
                ss << netPStateObj;
                packetData = ss.str();
            */
                packetData = "";
            break;
        }
        if (packetData != "")
        {
            sendPacket(packetData);
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
