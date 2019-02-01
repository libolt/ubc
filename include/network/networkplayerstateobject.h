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

#ifndef _NETWORKPLAYERSTATEOBJECT_H_
#define _NETWORKPLAYERSTATEOBJECT_H_

#include "Ogre.h"

#include <iostream>

#include "utilities/enums.h"

class networkPlayerStateObject // object that holde network state data for a player
{
    public:

    networkPlayerStateObject();

    int getPacketType(); // retrieves the value of packetType
    void setPacketType(int type); // sets the value of packetType

    int getTeamID(); // retrieves the value of teamID
    void setTeamID(int id); // sets the value of teamID

    int getPlayerID(); // retrieves the value of playerID
    void setPlayerID(int id); // sets the value of playerID

    bool getMovement(); // retrieves the value of movement
    void setMovement(bool move); // sets the value of movement

    int getDirection(); // retrieves the value of direction
    void setDirection(int dir); // sets value of direction

    bool getShootBlock();  // retrieves the value of shootBlock
    void setShootBlock(bool set);   // sets the value of shootBlock

    bool getPassSteal();    // retrieves the value of passSteal
    void setPassSteal(bool set);  // sets the value of passSteal

    float getXCoord(); // retrieves the value of XCoord
    void setXCoord(float coord); // sets the value of XCoord

    float getYCoord(); // retrieves the value of YCoord
    void setYCoord(float coord); // sets the value of YCoord

    float getZCoord(); // retrieves the value of ZCoord
    void setZCoord(float coord); // sets the value of ZCoord


    friend std::ostream& operator<< (std::ostream& out, networkPlayerStateObject& object)
    {
        out << object.packetType << " " << object.teamID << " " << object.playerID << " " << object.movement
        << " " << object.direction << " " << object.shootBlock << " " << object.passSteal << " "
        <<  object.XCoord << " " << object.YCoord << " " << object.ZCoord;   //The space (" ") is necessary for separate elements
        return out;
    }

    friend std::istream& operator>> (std::istream& in, networkPlayerStateObject& object)
    {

        in >> object.packetType;
        in >> object.teamID;
        in >> object.playerID;
        in >> object.movement;
        in >> object.direction;
        in >> object.shootBlock;
        in >> object.passSteal;
        in >> object.XCoord;
        in >> object.YCoord;
        in >> object.ZCoord;

        return in;
    }
    private:
        int teamID;
        int playerID;
        int packetType;
        bool movement;
        int direction;
        bool shootBlock;
        bool passSteal;
        float XCoord;
        float YCoord;
        float ZCoord;
};

#endif

