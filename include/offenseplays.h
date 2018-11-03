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

#ifndef _OFFENSEPLAYS_H_
#define _OFFENSEPLAYS_H_

#include "Ogre.h"
#include "utilities/enums.h"
#include "utilities/typedefs.h"


typedef std::vector<playerPositions> playerPositionsVec;
typedef std::vector<Ogre::Vector3> OgreVector3Vec;

class offensePlays  // class that contains the information to run each play
{
    public:

        class playerDirectives
        {
            public:

                playerPositions getPlayerPosition() const;  // retrieves the value of playerPosition
                void setPlayerPosition(const playerPositions &set);  // sets the value of playerPosition

                directiveTypes getType() const;  // retrieves the value of type
                void setType(const directiveTypes &set);  // sets the value of type

                offenseWaitFor getWaitFor() const;  // retrieves the value of waitFor
                void setWaitFor(const offenseWaitFor &set);  // sets the value of waitFor

                playerPositions getPlayerSet() const;  // retrieves the value of playerSet
                void setPlayerSet(const playerPositions &set);  // sets the value of playerSet

                positionTypes getPositionType() const;  // retrieves the value of positionType
                void setPositionType(const positionTypes &set);  // sets the value of positionType

                int getPosition() const;  // retrieves the value of position
                void setPosition(const int &set);  // sets the value of position

            private:
                playerPositions playerPosition;  // stores which position the directive belongs to
                directiveTypes type;  // stores type of directive given
                offenseWaitFor waitFor;  // stores what to wait for if anything
                playerPositions playerSet;  // stores which player position sets
                positionTypes positionType;  // stores position types
                int position;
        };
        typedef std::vector<offensePlays::playerDirectives> playerDirectivesVec;

        offensePlays();  // constructor
        ~offensePlays();  // destructor

        std::string getPlayName() const;  // retrieves the value of playName;
        void setPlayName(const std::string &set);  // sets the value of playName

        int getVariation() const;  // retrieves the value of variation
        void setVariation(const int &set);  // sets the value of variation

        std::string getTitle() const;  // retrieves the value of title
        void setTitle(const std::string &set);  // sets the value of title

        playerPositionsVec getPlayerPosition() const;  // retrieves the value of playerPosition
        void setPlayerPosition(const playerPositionsVec &set);  // sets the value of playerPosition

        OgreVector3Vec getStartPositions() const;  // retrieves the value of startPositions
        void setStartPositions(const OgreVector3Vec &set);  // sets the value of startPositions

        std::vector <OgreVector3Vec > getExecutePositions() const;    // retrieves the value of executePositions
        void setExecutePositions(const std::vector< OgreVector3Vec > &set);    // sets the value of executePositions

        boolVec getStartPositionSet() const;  // retrieves the value of startPositionSet
        void setStartPositionSet(const boolVec &set);  // sets the value of startPositionSet

        std::vector< boolVec > getExecutePositionReached() const;  // retrieves the value of executePositionSet
        void setExecutePositionReached(const std::vector< boolVec > &set);  // sets the value of executePositionSet

        playerDirectivesVec getPlayerDirective() const;  // returns the value of playerDirective
        void setPlayerDirective(const playerDirectivesVec &set);  // sets the value of playerDirective

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
