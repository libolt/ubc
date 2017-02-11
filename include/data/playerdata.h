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

#ifndef _PLAYERDATA_H_
#define _PLAYERDATA_H_

#include <string>

#include "enums.h"

class playerData
{

    public:

        playerData();
        ~playerData();

        std::string getFirstName();  // retrieves the value of firstName
        void setFirstName(std::string set);  // sets the value of firstName

        std::string getLastName();  // retrieves the value of lastName
        void setLastName(std::string set);  // sets the value of lastName

        std::string getPlayerName();  // retrieves the value of playerName
        void setPlayerName(std::string set);  // sets the value of playerName

        size_t getAge();  // retrieves the value of age
        void setAge(size_t set);  // sets the value of  age

        size_t getHeight();  // retrieves the value of height
        void setHeight(size_t set);  // sets the value of height 

        size_t getWeight();  // retrieves the value of weight
        void setWeight(size_t set);  // sets the value of weight

        size_t getID();  // retrieves the value of ID
        void setID(size_t set);  // sets the value of ID

        size_t getTeamID();  // retrieves the value of teamID
        void setTeamID(size_t set);  // sets the value of teamID

        playerPositions getPrimaryPosition();  // retrieves the value of primaryPosition
        void setPrimaryPosition(playerPositions set);  // sets the value of primaryPosition

        playerPositions getSecondaryPosition();  // retrieves the value of secondaryPosition
        void setSecondaryPosition(playerPositions set);  // sets the value of secondaryPosition

        bool getActive();  // retrieves the value of active
        void setActive(bool set);  // sets the value of active

/*        string getModelFileName();  // retrieves the value of modelName
        void setModelFileName(string set);  // sets the value of modelName
*/

        size_t getShooting();  // retrieves the value of shooting
        void setShooting(size_t set);  // sets the value of shooting
        
        size_t getFreeThrow();  // retrieves the value of freeThrow
        void setFreeThrow(size_t set);  // sets the value of freeThrow
        
        size_t getLayup();  // retrieves the value of layup
        void setLayup(size_t set);  // sets the value of layup
        
        size_t getDunk();  // retrieves the value of dunk
        void setDunk(size_t set);  // sets the value of dunk
        
        size_t getInside();  // retrieves the value of inside
        void setInside(size_t set);  // sets the value of inside
        
        size_t getMidRange();  // retrieves the value of midRange
        void setMidRange(size_t set);  // sets the value of midRange
        
        size_t getThreePoint();  // retrieves the value of threePoint
        void setThreePoint(size_t set);  // sets the value of threePoint
        
        size_t getBallHandling();  // retrieves the value of ballHandling
        void setBallHandling(size_t set);  // sets the value of ballHandling
        
        size_t getBallSecurity();  // retrieves the value of ballSecurity
        void setBallSecurity(size_t set);  // sets the value of ballSecurity
        
        size_t getPassing();  // retrieves the value of passing
        void setPassing(size_t set);  // sets the value of passing
        
        size_t getPickSetting();  // retrieves the value of pickSetting
        void setPickSetting(size_t set);  // sets the value of pickSetting
        
        size_t getOffenseAwareness();  // retrieves the value of offenseAwareness
        void setOffenseAwareness(size_t set);  // sets the value of offenseAwareness
        
        size_t getDefenseAwareness();  // retrieves the value of defenseAwareness
        void setDefenseAwareness(size_t set);  // sets the value of defenseAwareness

        size_t getOffenseRebound();  // retrieves the value of offenseRebound
        void setOffenseRebound(size_t set);  // sets the value of offenseRebound
        
        size_t getDefenseRebound();  // retrieves the value of defenseRebound
        void setDefenseRebound(size_t set);  // sets the value of defenseRebound
        
        size_t getBlocking();  // retrieves the value of blocking
        void setBlocking(size_t set);  // sets the value of blocking
        
        size_t getStealing();  // retrieves the value of stealing
        void setStealing(size_t set);  // sets the value of stealing
        
        size_t getInteriorDefense();  // retrieves the value of interiorDefense
        void setInteriorDefense(size_t set);  // sets the value of interiorDefense
        
        size_t getMidRangeDefense();  // retrieves the value of midRangeDefense
        void setMidRangeDefense(size_t set);  // sets the value of midRangeDefense
        
        size_t getPerimeterDefense();  // retrieves the value of perimeterDefense
        void setPerimeterDefense(size_t set);  // sets the value of perimeterDefense
        
        size_t getHustle();  // retrieves the value of hustle
        void setHustle(size_t set);  // sets the value of hustle
        
        size_t getSpeed();  // retrieves the value of speed
        void setSpeed(size_t set);  // sets the value of speed
        
        size_t getQuickness();  // retrieves the value of quickness
        void setQuickness(size_t set);  // sets the value of quickness
        
        size_t getFatigue();  // retrieves the value of fatigue
        void setFatigue(size_t set);  // sets the value of fatigue
        
        size_t getDurability();  // retrieves the value of durability
        void setDurability(size_t set);  // sets the value of durability
        
        size_t getDemeanor();  // retrieves the value of demeanor
        void setDemeanor(size_t set);  // sets the value of demeanor
        
        size_t getImprovability();  // retrieves the value of improvability
        void setImprovability(size_t set);  // sets the value of improvability
        
        size_t getOverallRating();  // retrieves the value of overallRating
        void setOverallRating(size_t set);  // sets the value of overallRating
        
        void calculateOverallRating();  // calculates the value of overallRating
        
    private:

        std::string firstName;  // stores the first name of the player
        std::string lastName;  // stores the last name of the player
        std::string playerName;  // stores the full player name
        size_t age;  // stores the age of the player
        size_t height;  // stores the height in centimeters of the player
        size_t weight;  // stores the weight of the player in pounds.
        size_t ID;  // stores the unique ID of the player.
        size_t teamID;  // stores the unique ID of the team the player plays for.
        playerPositions primaryPosition;  // stores the primary position of the player
        playerPositions secondaryPosition;  // stores the secondary position of the player
        size_t shooting;  // stores the overall shooting proficiency
        size_t freeThrow;  // storee freethrow shooting proficiency
        size_t layup;  // storee layup shooting proficiencu
        size_t dunk;  // stores dunking proficiency
        size_t inside;  // stores scoring profiency in the paint
        size_t midRange;  // stores mid range scoring proficiency
        size_t threePoint;  // stores three point scoring proficiency
        size_t ballHandling;  // stores ability to dribble the ball
        size_t ballSecurity;  // stores ability to hang on to the ball when defended
        size_t passing;  // stores ability to make passes accurately
        size_t pickSetting;  // stores ability to set a pick
        size_t offenseAwareness;  // stores awareness of what happens during offense execution
        size_t defenseAwareness;  // stores awareness of what happens playing defense
        size_t offenseRebound;  // stores ability to rebound missed shots on offense
        size_t defenseRebound;  // stores ability to rebound missed shots on defense
        size_t blocking;  // stores ability to block opposing players' shot
        size_t stealing;  // stores ability to steal ball from opposing player
        size_t interiorDefense;  // stores ability to defend the paint
        size_t midRangeDefense;  // stores ability to defend between paint and three point linr
        size_t perimeterDefense;  // stores ability to defend from three point line extended
        size_t hustle;  // stores willingness to go after loose balls and rebounds
        size_t speed;  // stores how fast player can run
        size_t quickness;  // stores how quick player takes off on move
        size_t fatigue;  // stores how quickly player tires
        size_t durability;  // stores how healthy a player stays during game/season
        size_t demeanor;  // stores how passive, excited, agressive a player is
        size_t improvability;  // stores players ability to improve skills
        size_t overallRating;  // stores overall rating which is the sum of all ratings/number of ratings
        
        // if player is playing this is true
        bool active;

        std::string modelFileName;  // stores the name of the 3D model to load for the player
        


};


#endif // _PLAYERDATA_H_
