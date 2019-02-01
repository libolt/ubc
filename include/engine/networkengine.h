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

#ifndef _NETWORKENGINE_H_
#define _NETWORKENGINE_H_


#ifndef _ENET_ISINCLUDED_
#define _ENET_ISINCLUDED_
#define WIN32_LEAN_AND_MEAN
#include "enet/enet.h"
#endif 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//#include <boost/shared_ptr.hpp>

/*
#include "OgreString.h"
#include "OgreStringConverter.h"
#include "Ogre.h"
*/
#include "utilities/enums.h"
// #include "engine/inputengine.h"
#include "engine.h"

#include "utilities/typedefs.h"

class inputEngine;

class networkEngine : public engine
{
    public:

    networkEngine();  // constructor
    ~networkEngine();  // destructor

    teamTypes getTeamType() const;  // retrieves the value of teamType
    void setTeamType(const teamTypes &set);  // sets the value of teamType
    
    bool getIsClient() const;	 // retrieves the value of isClient 
    void setIsClient(const bool &set);  // sets the value of isClient

    bool getIsServer() const;	// retrieves the value of isServer 
    void setIsServer(const bool &set);	// sets the value of isServer

    bool getClientEstablishedConnection() const;  // retrieves the value of clientEstablishedConnection 
    void setClientEstablishedConnection(const bool &set);  // sets the value of clientEstablishedConnection

    bool getServerReceivedConnection() const;	 // retrieves the value of serverReceivedConnection 
    void setServerReceivedConnection(const bool &set);	  // sets the value of serverReceivedConnection

    bool getPacketReceived() const;  // retrieves the value of packetReceived
    void setPacketReceived(const bool &set);  // sets the value of packetReceived 

    int getClientID() const;	// retrieves the value of clientID 
    void setClientID(const int &set);  // sets the value of clientID

    std::string getIPAddress() const;	// retrieves the value of ipAddress 
    void setIPAddress(const std::string &set);	 // sets the value of ipAddress

    std::string getReceivedData() const;  // retrieves the value of receivedData
    void setReceivedData(const std::string &set);  // sets the value of receivedData

    ENetAddress getListenAddress() const;  // retrieves the value of  listenAddress 
    void setListenAddress(const ENetAddress &set);  // sets the value of listenAddress

    ENetAddress getServerAddress() const;  // retrieves the value of serverAddress 
    void setServerAddress(const ENetAddress &set);  // sets the value of serverAddress

    ENetHostSharedPtr getClient() const;  // retrieves the value of client
    void setClient(const ENetHostSharedPtr &set);  // sets the value of client

    ENetEvent getEvent() const;  // retrieves the value of event 
    void setEvent(const ENetEvent &set);  // sets event

    ENetPeerSharedPtr getPeer() const;  // retrieves the value of peer
    void setPeer(const ENetPeerSharedPtr &set);  // sets the value of peer

    ENetHostSharedPtr getServer() const;  // retrieves the value of server
    void setServer(const ENetHostSharedPtr &set);  // sets the value of server

    int initialize();  // initialize networkEngine code
    bool clientConnect();  // setup client connection.
    void networkClient();  // Client code

    bool serverSetup();	 // setup server.
    void networkServer();  // Server code

    void sendPacket(const std::string &packetData);  // sends a packet to the peer

    private:

    int counter;

    int clientID;  // defines the client ID number used to identify which client is communicating with the server
    std::string ipAddress;  // stores IP Address used for either server or client code
    std::string receivedData;  // stores received packet data
    bool packetReceived;  // if set then a packet was received from remote connection

    // ENET related code
    ENetAddress listenAddress;
    ENetAddress serverAddress;
    ENetHostSharedPtr client;
    ENetEvent event;
    ENetPeerSharedPtr peer;
    ENetHostSharedPtr server;
    sharedPtr<ENetPacket> packet;

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
