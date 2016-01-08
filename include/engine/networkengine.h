/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean                              *
 *   libolt@libolt.net                                                      *
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

#ifndef _NETWORKENGINE_H_
#define _NETWORKENGINE_H_

#ifndef _ENET_ISINCLUDED_
#define _ENET_ISINCLUDED_
#include "enet/enet.h"
#endif 

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "OgreString.h"
#include "OgreStringConverter.h"
#include "Ogre.h"

#include "enums.h"
#include "engine/inputengine.h"


class networkEngine
{
    public:

    //static networkEngine *Instance();
//    static boost::shared_ptr<networkEngine> Instance();


    networkEngine();  // constructor
    ~networkEngine();  // destructor

    teamTypes getTeamType();  // retrieves the value of teamType
    void setTeamType(teamTypes set);  // sets the value of teamType
    
    bool getIsClient();	 // retrieves the value of isClient 
    void setIsClient(bool set);  // sets the value of isClient 

    bool getIsServer();	// retrieves the value of isServer 
    void setIsServer(bool set);	// sets the value of isServer 

    bool getClientEstablishedConnection();  // retrieves the value of clientEstablishedConnection 
    void setClientEstablishedConnection(bool set);  // sets the value of clientEstablishedConnection 

    bool getServerReceivedConnection();	 // retrieves the value of serverReceivedConnection 
    void setServerReceivedConnection(bool set);	  // sets the value of serverReceivedConnection

    bool getPacketReceived();  // retrieves the value of packetReceived 
    void setPacketReceived(bool set);  // sets the value of packetReceived 

    int getClientID();	// retrieves the value of clientID 
    void setClientID(int set);  // sets the value of clientID 

    std::string getIPAddress();	// retrieves the value of ipAddress 
    void setIPAddress(std::string set);	 // sets the value of ipAddress 

    std::string getReceivedData();  // retrieves the value of receivedData
    void setReceivedData(std::string set);  // sets the value of receivedData

    ENetAddress getListenAddress();  // retrieves the value of  listenAddress 
    void setListenAddress(ENetAddress set);  // sets the value of listenAddress 

    ENetAddress getServerAddress();  // retrieves the value of serverAddress 
    void setServerAddress(ENetAddress set);  // sets the value of serverAddress 

    ENetHost *getClient();  // retrieves the value of client 
    void setClient(ENetHost *set);  // sets the value of client 

    ENetEvent getEvent();  // retrieves the value of event 
    void setEvent(ENetEvent set);  // sets event 

    ENetPeer *getPeer();  // retrieves the value of peer 
    void setPeer(ENetPeer *set);  // sets the value of peer 

    ENetHost *getServer();  // retrieves the value of server 
    void setServer(ENetHost *set);  // sets the value of server 

    int initialize();  // initialize networkEngine code
    bool clientConnect();  // setup client connection.
    void networkClient();  // Client code

    bool serverSetup();	 // setup server.
    void networkServer();  // Server code

    void processLocalInput(boost::shared_ptr<inputEngine> input);  // processes local input for sending to remote system
    void processRemoteInput();  // processes input received from a remote system
    
    void sendPacket(std::string packetData);  // sends a packet to the peer

    protected:
/*    networkEngine();
    networkEngine(const networkEngine&);
    networkEngine& operator= (const networkEngine&);
*/
    private:

    int counter;
    //static networkEngine *pInstance;
//    static boost::shared_ptr<networkEngine> pInstance;


    int clientID;  // defines the client ID number used to identify which client is communicating with the server
    std::string ipAddress;  // stores IP Address used for either server or client code
    std::string receivedData;  // stores received packet data
    bool packetReceived;  // if set then a packet was received from remote connection

    // ENET related code
    ENetAddress listenAddress;
    ENetAddress serverAddress;
    ENetHost *client;
    ENetEvent event;
    ENetPeer *peer;
    ENetHost *server;
    ENetPacket *packet;

    netGameTypes netGameType;  // stores what type of network game this instance is
    teamTypes teamType;  // stores which team the network player is on
    // FiXME! deprecated in favor of netGameTypes
    bool isClient;  // stores whether or not this instance is the client
    bool isServer;  // stores whethr or not this instance is the server

    bool serverSetupComplete;  // stores whether or not the server is setup and running
    bool clientEstablishedConnection;  // stores whether or not a connection from client to server was successful
    bool serverReceivedConnection;  // stores whether or not server received a client connection.
};


#endif
