/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean                              *
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

#include "engine/networkengine.h"
#include "network/networkplayerstateobject.h"
#include "engine/gameengine.h"
#include "state/gamestate.h"
#include "logging.h"
#include "input.h"
#include "conversion.h"

#if _MSC_VER
#define snprintf _snprintf
#endif

networkEngine::networkEngine()
{
    initialize();
    counter = 0;
    clientID = 0;
    teamType = NOTEAM;
    clientEstablishedConnection = false;
    serverReceivedConnection = false;
    serverSetupComplete = false;
    packetReceived = false;
}

networkEngine::~networkEngine()
{
    enet_host_destroy(server);	// cleans up server
    enet_host_destroy(client);	// cleans up client

}

/*boost::shared_ptr<networkEngine> networkEngine::pInstance;

boost::shared_ptr<networkEngine> networkEngine::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        //pInstance = new networkEngine; // create sole instance
        boost::shared_ptr<networkEngine> tInstance(new networkEngine);
        pInstance = tInstance;
    }
    return pInstance; // address of sole instance
}
*/

teamTypes networkEngine::getTeamType()  // retrieves the value of teamType
{
    return (teamType);
}
void networkEngine::setTeamType(teamTypes set)  // sets the value of teamType
{
    teamType = set;
}

bool networkEngine::getIsClient()  // retrieves the value of isClient 
{
    return (isClient);
}
void networkEngine::setIsClient(bool set)  // sets the value of isClient
{
    isClient = set;
}

bool networkEngine::getIsServer()  // retrieves the value of isServer 
{
    return (isServer);
}
void networkEngine::setIsServer(bool set)  // sets the value of the isServer 
{
    isServer = set;
}

bool networkEngine::getClientEstablishedConnection()  // retrieves the value of clientEstablishedConnection
{
    return (clientEstablishedConnection);
}

void networkEngine::setClientEstablishedConnection(bool set)  // sets the value of clientEstablishedConnection
{
    clientEstablishedConnection = set;
}

bool networkEngine::getServerReceivedConnection()  // retrieves the value of serverReceivedConnection
{
    return (serverReceivedConnection);
}

void networkEngine::setServerReceivedConnection(bool set)  // sets the value of serverReceivedConnection
{
    serverReceivedConnection = set;
}
int networkEngine::getClientID()  // retrieves the value of clientID
{
    return (clientID);
}

void networkEngine::setClientID(int set)  // sets the value of clientID
{
    clientID = set;
}

std::string networkEngine::getIPAddress()  // retrieves ipAddress string
{
    return(ipAddress);
}

void networkEngine::setIPAddress(std::string set)  // sets ipAddress string
{
    ipAddress = set;
}

std::string networkEngine::getReceivedData()  // retrieves receivedData variable
{
    return (receivedData);
}
void networkEngine::setReceivedData(std::string set)  // sets receivedData variable
{
    receivedData = set;
}

bool networkEngine::getPacketReceived()  // retrieves packetReceived variable
{
    return (packetReceived);
}
void networkEngine::setPacketReceived(bool set)  // sets packetReceived variable
{
    packetReceived = set;
}

ENetAddress networkEngine::getListenAddress()  // retrieves the value of listenAddress
{
    return (listenAddress);
}
void networkEngine::setListenAddress(ENetAddress set)  // sets the value of listenAddress
{
    listenAddress = set;
}

ENetAddress networkEngine::getServerAddress()  // retrieves the value of serverAddress
{
    return (serverAddress);
}

void networkEngine::setServerAddress(ENetAddress set)  // sets the value of serverAddress
{
    serverAddress = set;
}

ENetHost *networkEngine::getClient()  // retrieves the value of client
{
    return (client);
}
void networkEngine::setClient(ENetHost *set)  // sets the value of client
{
    client = set;
}

ENetEvent networkEngine::getEvent()  // retrieves the value of event
{
    return (event);
}
void networkEngine::setEvent(ENetEvent set)  // sets the value of event
{
    event = set;
}

ENetPeer *networkEngine::getPeer()  // retrieves the value of peer
{
    return (peer);
}
void networkEngine::setPeer(ENetPeer *set)  // sets the value of peer
{
    peer = set;
}

ENetHost *networkEngine::getServer()  // retrieves the value of server
{
    return (server);
}
void networkEngine::setServer(ENetHost *set)  // sets the value of server
{
    server = set;
}


int networkEngine::initialize()  // initializes the network engine
{
    if (enet_initialize () != 0)
    {
        logMsg("An error occurred while initializing ENet.");
        return EXIT_FAILURE;
    }
    atexit (enet_deinitialize);
    return (0);
}

void networkEngine::clientConnect()  // performs a client connection to the server
{
//    boost::shared_ptr<gameEngine> gameE = gameEngine::Instance();

    if (!clientEstablishedConnection)
    {

        client = enet_host_create (NULL  /* create a client host */,
                                   4  /* only allow 1 outgoing connection */,
                                   2  /* allow up to 2 channels to be used, 0 and 1*/,
                                   0  /* 56K modem with 56 Kbps downstream bandwidth */,
                                   0  /* 56K modem with 14 Kbps upstream bandwidth */);

        if (client == NULL)
        {
            logMsg("An error occurred while trying to create an ENet client host.");
            exit (EXIT_FAILURE);
        }

// Old Pre-GUI ipAddress input code
//    string ipAddress;
//    cout << "IP Address: " << endl;
//    cin >> ipAddress;

        /* Connect to some.server.net:1234. */
        enet_address_set_host (& serverAddress, ipAddress.c_str());
        serverAddress.port = 1234;

        /* Initiate the connection, allocating the two channels 0 and 1. */
        peer = enet_host_connect (client, & serverAddress, 2, 0);

        if (peer == NULL)
        {
            logMsg("No available peers for initiating an ENet connection.");
            exit (EXIT_FAILURE);
        }

        /* Wait up to 5 seconds for the connection attempt to succeed. */
        if (enet_host_service (client, & event, 5000) > 0 && event.type == ENET_EVENT_TYPE_CONNECT)
        {
            logMsg("Connection to " +ipAddress +":1234 succeeded.");
            clientEstablishedConnection = true; // Tells other code that this instance is a network client
        }
        else
        {
            /* Either the 5 seconds are up or a disconnect event was */
            /* received. Reset the peer in the event the 5 seconds   */
            /* had run out without any significant event.            */
            enet_peer_reset (peer);

            logMsg("Connection to " +ipAddress +":1234 failed.");
        }
        gameE->setClientRunning(true);
        clientEstablishedConnection = true;
    }
}

void networkEngine::networkClient()
{
//    ENetPeer *peer;
//    ENetPacket *packet2;
//    clientConnect();

// do something here
    int x = 1;
//    do
//   {

        // Wait up to 1000 milliseconds for an event.
//        ENetHost *client = network->getClient();
//	ENetEvent event; // = network->getEvent();
//	event = network->getEvent();

    // processes client event ever 0 seconds.
    while (enet_host_service (client, &event, 0) > 0)
    {
        switch (event.type)
        {
            case ENET_EVENT_TYPE_CONNECT:
                printf("A new client connected from %x:%u.\n",
                        event.peer -> address.host,
                        event.peer -> address.port);
            break;
            case ENET_EVENT_TYPE_RECEIVE:
                char *data; // char array that stores data received in the packet

                printf ("A packet of length %u containing %s was received from %s on channel %u.\n",
                         event.packet -> dataLength,
                         event.packet -> data,
                         event.peer -> data,
                         event.channelID);

                packetReceived = true;	// lets code know that a packet was received
//    cout << "event.packet->data = " << event.packet->data << endl;

                data = new char[event.packet->dataLength + 1];	// creates array the size of the packet data + 1
                snprintf(data,event.packet->dataLength + 1, "%s", event.packet->data);	// copies contents of packet to data variable

                receivedData = data;  // copies conetents of data array to receivedData std::string variable
                logMsg("receivedData == " +receivedData);
                // Clean up the packet now that we're done using it.
                enet_packet_destroy (event.packet);
//            exit(0);
            break;
            case ENET_EVENT_TYPE_DISCONNECT:
                printf ("%s disconected.\n", event.peer -> data);
                // Reset the peer's client information.
                event.peer -> data = NULL;
            break;
            case ENET_EVENT_TYPE_NONE:
            break;
        }
    }
}

void networkEngine::serverSetup()  // sets up the network server
{
//    boost::shared_ptr<gameEngine> gameE = gameEngine::Instance();
    
/* Bind the server to the default localhost.     */
/* A specific host address can be specified by   */
/* enet_address_set_host (& address, "x.x.x.x"); */

// Old Pre-GUI ip address input code
//    string ipAddress;
//    cout << "IP Address to bind to:" << endl;
//    cin >> ipAddress;

    listenAddress.host = enet_address_set_host (& listenAddress, ipAddress.c_str());
//    listenAddress.host = enet_address_set_host (& listenAddress, ENET_HOST_ANY);
	
    /* Bind the server to port 1234. */
    listenAddress.port = 1234;

    server = enet_host_create (& listenAddress /* the address to bind the server host to */,
                               32  /* allow up to 32 clients and/or outgoing connections */,
                               2  /* allows up to 2 channels, 0, 1*/,
                               0  /* assume any amount of incoming bandwidth */,
                               0  /* assume any amount of outgoing bandwidth */);
    if (server == NULL)
    {
        logMsg("An error occurred while trying to create an ENet server host.");
        exit (EXIT_FAILURE);
    }
    gameE->setServerRunning(true);
}

void networkEngine::networkServer()  // executes the network server code
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<gameEngine> gameE = gameEngine::Instance();
    
    char *host; 
    std::string addressHost, addressPort, packetData, packetDataLength, packetPeer, packetChannelID;
    int x = 0;
    networkPlayerStateObject netPStateObj;
    std::stringstream ss;
    if (serverReceivedConnection)
    {
//    exit(0);
        netPStateObj.setPacketType(3);
        netPStateObj.setTeamID(1);
        netPStateObj.setPlayerID(1);
        netPStateObj.setMovement(true);
        netPStateObj.setDirection(0);
        ss << netPStateObj;
        packetData = ss.str();
        sendPacket(packetData);
    }
//    do
//    {
    /* Wait up to 1000 milliseconds for an event. */
    while (enet_host_service (server, & event, 1) > 0)
    {

        logMsg("EVENT == " +event.type);
        switch (event.type)
        {
            case ENET_EVENT_TYPE_CONNECT:
          	peer = event.peer;  // stores the peer connection for later use.
            	serverReceivedConnection = true;  // Tells code that a client has connected
//           	exit(0);
//                logMsg("Peer == " +convert->toString(addressHost));
            break;
            case ENET_EVENT_TYPE_RECEIVE:
                char *data;  // char array that stores data received in the packet

                printf ("A packet of length %u containing %s was received from %s on channel %u.\n",
                        event.packet -> dataLength,
                        event.packet -> data,
                        event.peer -> data,
                        event.channelID);
                // converts and writes data to Ogre.log for packet
                packetData = convert->toString(event.packet->data);
                packetDataLength = convert->toString(event.packet->dataLength);
                packetPeer = convert->toString(event.peer->data);
                packetChannelID = convert->toString(event.channelID);
                logMsg("A packet of length " +packetDataLength + " containing " +packetData + " was received from " +packetPeer + " on channel " +packetChannelID);
                packetReceived = true;	// lets code know that a packet was received
                data = new char[event.packet->dataLength + 1];  // creates array the size of the packet data + 1
                snprintf(data,event.packet->dataLength + 1, "%s", event.packet->data);	// copies contents of packet to data variable
                receivedData = data;  // copies conetents of data array to receivedData std::string variable
                logMsg("receivedData == " +receivedData);
                exit(0);
                enet_packet_destroy (event.packet);
            break;
            case ENET_EVENT_TYPE_DISCONNECT:
                logMsg(convert->toString(event.peer->data) +" disconected.");

                // Reset the peer's client information.
                event.peer -> data = NULL;
            break;
            case ENET_EVENT_TYPE_NONE:
            break;

        }
    }
    logMsg("End of networkServer");
}

void networkEngine::processLocalInput()  // processes local input for sending to remote system
{
    //inputSystem *input = inputSystem::Instance();
    boost::shared_ptr<inputSystem> input = inputSystem::Instance();
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    
    inputWorkQueues inputQueue;
    networkPlayerStateObject netPStateObj;
    
    std::vector<teamState> activeTeamInstance = gameS->getActiveTeamInstance();
    int humanControlled = activeTeamInstance[teamType].getHumanControlled();
    int humanPlayer = activeTeamInstance[teamType].getHumanPlayer();
    
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

void networkEngine::processRemoteInput() // processes input received from a remote system
{
    
}

void networkEngine::sendPacket(std::string packetData)  // sends a packet to remote system
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
//    boost::shared_ptr<gameEngine> gameE = gameEngine::Instance();

    if (gameE->getServerRunning())
    {
        while (enet_host_service (server, &event, 0) > 0)
        {
        }
    }
    else if (gameE->getClientRunning())
    {
        while (enet_host_service (client, &event, 0) > 0)
        {
        }
	}
        std::string host = convert->toString(peer->address.host);
        logMsg("packetData == " + packetData);
        logMsg("Peer host == " +host);
        exit(0);
        packet = enet_packet_create(packetData.c_str(),strlen(packetData.c_str())+1,ENET_PACKET_FLAG_RELIABLE);
        enet_peer_send (peer, 0, packet);
}


struct ePacket
{
    int ID;
    string data;
};