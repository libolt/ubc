/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
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

#ifndef _OFFENSEPLAYS_H_
#define _OFFENSEPLAYS_H_

#include "Ogre.h"
#include "enums.h"
#include "typedefs.h"


typedef std::vector<playerPositions> playerPositionsVec;
typedef std::vector<Ogre::Vector3> OgreVector3Vec;

class offensePlays  // class that contains the information to run each play
{
    public:

        class playerDirectives
        {
            public:

                playerPositions getPlayerPosition();  // retrieves the value of playerPosition
                void setPlayerPosition(playerPositions set);  // sets the value of playerPosition

                directiveTypes getType();  // retrieves the value of type
                void setType(directiveTypes set);  // sets the value of type

                offenseWaitFor getWaitFor();  // retrieves the value of waitFor
                void setWaitFor(offenseWaitFor set);  // sets the value of waitFor

                playerPositions getPlayerSet();  // retrieves the value of playerSet
                void setPlayerSet(playerPositions set);  // sets the value of playerSet

                positionTypes getPositionType();  // retrieves the value of positionType
                void setPositionType(positionTypes set);  // sets the value of positionType

                int getPosition();  // retrieves the value of position
                void setPosition(int set);  // sets the value of position

            private:
                playerPositions playerPosition;  // stores which position the directive belongs to
                directiveTypes type;  // stores type of directive given
                offenseWaitFor waitFor;  // stores what to wait for if anything
                playerPositions playerSet;  // stores which player position sets
                positionTypes positionType;  // stores position types
                int position;
        };
        typedef std::vector<offensePlays::playerDirectives> playerDirectivesVec;

        std::string getPlayName();  // retrieves the value of playName;
        void setPlayName(std::string set);  // sets the value of playName

        int getVariation();  // retrieves the value of variation
        void setVariation(int set);  // sets the value of variation

        std::string getTitle();  // retrieves the value of title
        void setTitle(std::string set);  // sets the value of title

        playerPositionsVec getPlayerPosition();  // retrieves the value of playerPosition
        void setPlayerPosition(playerPositionsVec set);  // sets the value of playerPosition

        OgreVector3Vec getStartPositions();  // retrieves the value of startPositions
        void setStartPositions(OgreVector3Vec set);  // sets the value of startPositions

        std::vector <OgreVector3Vec > getExecutePositions();    // retrieves the value of executePositions
        void setExecutePositions(std::vector< OgreVector3Vec > set);    // sets the value of executePositions

        boolVec getStartPositionSet();  // retrieves the value of startPositionSet
        void setStartPositionSet(boolVec set);  // sets the value of startPositionSet

        std::vector< boolVec > getExecutePositionReached();  // retrieves the value of executePositionSet
        void setExecutePositionReached(std::vector< boolVec > set);  // sets the value of executePositionSet

        playerDirectivesVec getPlayerDirective();  // returns the value of playerDirective
        void setPlayerDirective(playerDirectivesVec set);  // sets the value of playerDirective

private:
    std::string playName;  // stores the name of the play
    int variation;  // store sthe name of the variation of the play
    std::string title;  // stores title of the play
    playerPositionsVec playerPosition;  // stores player positions
    OgreVector3Vec startPositions;  // stores the positions for players get to in order to execute offense
    std::vector< OgreVector3Vec > executePositions;  // stores the positions where players move when executing offense
    playerDirectivesVec playerDirective;  // stores directives for each player
    boolVec startPositionSet;  // stores whether player is at start position
    std::vector< boolVec > executePositionReached;  // stores whether player is at execute position

};

typedef std::vector<offensePlays::playerDirectives> playerDirectivesVec;

#endif
