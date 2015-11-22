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

#ifndef _OFFENSEPLAYS_H_
#define _OFFENSEPLAYS_H_

#include "Ogre.h"

#include "enums.h"

class offensePlays	// class that contains the information to run each play
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

        std::string getPlayName();  // retrieves the value of playName;
        void setPlayName(std::string set);  // sets the value of playName

        int getVariation();  // retrieves the value of variation
        void setVariation(int set);  // sets the value of variation

        std::string getTitle();	 // retrieves the value of title
        void setTitle(std::string set);  // sets the value of title

        std::vector<playerPositions> getPlayerPosition();  // retrieves the value of playerPosition
        void setPlayerPosition(std::vector<playerPositions> set);  // sets the value of playerPosition

        std::vector<Ogre::Vector3> getStartPositions();  // retrieves the value of startPositions 
        void setStartPositions(std::vector<Ogre::Vector3> set);  // sets the value of startPositions 

        std::vector <std::vector<Ogre::Vector3> > getExecutePositions();	// retrieves the value of executePositions 
        void setExecutePositions(std::vector< std::vector<Ogre::Vector3> > set);	// sets the value of executePositions

        std::vector<bool> getStartPositionSet();  // retrieves the value of startPositionSet
        void setStartPositionSet(std::vector<bool> set);  // sets the value of startPositionSet

        std::vector< std::vector<bool> > getExecutePositionReached();  // retrieves the value of executePositionSet
        void setExecutePositionReached(std::vector< std::vector<bool> > set);  // sets the value of executePositionSet

        std::vector<playerDirectives> getPlayerDirective();  // returns the value of playerDirective
        void setPlayerDirective(std::vector<playerDirectives> set);  // sets the value of playerDirective

private:
    std::string playName;  // stores the name of the play
    int variation;  // store sthe name of the variation of the play
    std::string title;  // stores title of the play
    std::vector<playerPositions> playerPosition;  // stores player positions
    std::vector<Ogre::Vector3> startPositions;  // stores the positions for players get to in order to execute offense
    std::vector< std::vector<Ogre::Vector3> > executePositions;  // stores the positions where players move when executing offense
    std::vector<playerDirectives> playerDirective;  // stores directives for each player
    std::vector<bool> startPositionSet;  // stores whether player is at start position
    std::vector< std::vector<bool> > executePositionReached;  // stores whether player is at execute position

};
#endif
