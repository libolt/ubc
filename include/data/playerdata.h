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

#ifndef _PLAYERDATA_H_
#define _PLAYERDATA_H_

#include <string>

#include "utilities/enums.h"

class playerData
{

    public:

        playerData();
        ~playerData();

        std::string getFirstName() const;  // retrieves the value of firstName
        void setFirstName(const std::string &set);  // sets the value of firstName

        std::string getLastName() const;  // retrieves the value of lastName
        void setLastName(const std::string &set);  // sets the value of lastName

        std::string getPlayerName() const;  // retrieves the value of playerName
        void setPlayerName(const std::string &set);  // sets the value of playerName

        size_t getAge() const;  // retrieves the value of age
        void setAge(const size_t &set);  // sets the value of  age

        size_t getHeight() const;  // retrieves the value of height
        void setHeight(const size_t &set);  // sets the value of height 

        size_t getWeight() const;  // retrieves the value of weight
        void setWeight(const size_t &set);  // sets the value of weight

        size_t getID() const;  // retrieves the value of ID
        void setID(const size_t &set);  // sets the value of ID

        size_t getTeamID() const;  // retrieves the value of teamID
        void setTeamID(const size_t &set);  // sets the value of teamID

        playerPositions getPrimaryPosition() const;  // retrieves the value of primaryPosition
        void setPrimaryPosition(const playerPositions &set);  // sets the value of primaryPosition

        playerPositions getSecondaryPosition() const;  // retrieves the value of secondaryPosition
        void setSecondaryPosition(const playerPositions &set);  // sets the value of secondaryPosition

        bool getActive() const;  // retrieves the value of active
        void setActive(const bool &set);  // sets the value of active

/*        string getModelFileName();  // retrieves the value of modelName
        void setModelFileName(string set);  // sets the value of modelName
*/

        size_t getShooting() const;  // retrieves the value of shooting
        void setShooting(const size_t &set);  // sets the value of shooting
        
        size_t getFreeThrow() const;  // retrieves the value of freeThrow
        void setFreeThrow(const size_t &set);  // sets the value of freeThrow
        
        size_t getLayup() const;  // retrieves the value of layup
        void setLayup(const size_t &set);  // sets the value of layup
        
        size_t getDunk() const;  // retrieves the value of dunk
        void setDunk(const size_t &set);  // sets the value of dunk
        
        size_t getInside() const;  // retrieves the value of inside
        void setInside(const size_t &set);  // sets the value of inside
        
        size_t getMidRange() const;  // retrieves the value of midRange
        void setMidRange(const size_t &set);  // sets the value of midRange
        
        size_t getThreePoint() const;  // retrieves the value of threePoint
        void setThreePoint(const size_t &set);  // sets the value of threePoint
        
        size_t getBallHandling() const;  // retrieves the value of ballHandling
        void setBallHandling(const size_t &set);  // sets the value of ballHandling
        
        size_t getBallSecurity() const;  // retrieves the value of ballSecurity
        void setBallSecurity(const size_t &set);  // sets the value of ballSecurity
        
        size_t getPassing() const;  // retrieves the value of passing
        void setPassing(const size_t &set);  // sets the value of passing
        
        size_t getPickSetting() const;  // retrieves the value of pickSetting
        void setPickSetting(const size_t &set);  // sets the value of pickSetting
        
        size_t getOffenseAwareness() const;  // retrieves the value of offenseAwareness
        void setOffenseAwareness(const size_t &set);  // sets the value of offenseAwareness
        
        size_t getDefenseAwareness() const;  // retrieves the value of defenseAwareness
        void setDefenseAwareness(const size_t &set);  // sets the value of defenseAwareness

        size_t getOffenseRebound() const;  // retrieves the value of offenseRebound
        void setOffenseRebound(const size_t &set);  // sets the value of offenseRebound
        
        size_t getDefenseRebound() const;  // retrieves the value of defenseRebound
        void setDefenseRebound(const size_t &set);  // sets the value of defenseRebound
        
        size_t getBlocking() const;  // retrieves the value of blocking
        void setBlocking(const size_t &set);  // sets the value of blocking
        
        size_t getStealing() const;  // retrieves the value of stealing
        void setStealing(const size_t &set);  // sets the value of stealing
        
        size_t getInteriorDefense() const;  // retrieves the value of interiorDefense
        void setInteriorDefense(const size_t &set);  // sets the value of interiorDefense
        
        size_t getMidRangeDefense() const;  // retrieves the value of midRangeDefense
        void setMidRangeDefense(const size_t &set);  // sets the value of midRangeDefense
        
        size_t getPerimeterDefense() const;  // retrieves the value of perimeterDefense
        void setPerimeterDefense(const size_t &set);  // sets the value of perimeterDefense
        
        size_t getHustle() const;  // retrieves the value of hustle
        void setHustle(const size_t &set);  // sets the value of hustle
        
        size_t getSpeed() const;  // retrieves the value of speed
        void setSpeed(const size_t &set);  // sets the value of speed
        
        size_t getQuickness() const;  // retrieves the value of quickness
        void setQuickness(const size_t &set);  // sets the value of quickness
        
        size_t getFatigue() const;  // retrieves the value of fatigue
        void setFatigue(const size_t &set);  // sets the value of fatigue
        
        size_t getDurability() const;  // retrieves the value of durability
        void setDurability(const size_t &set);  // sets the value of durability
        
        size_t getDemeanor() const;  // retrieves the value of demeanor
        void setDemeanor(const size_t &set);  // sets the value of demeanor
        
        size_t getImprovability() const;  // retrieves the value of improvability
        void setImprovability(const size_t &set);  // sets the value of improvability
        
        size_t getOverallRating() const;  // retrieves the value of overallRating
        void setOverallRating(const size_t &set);  // sets the value of overallRating
        
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

//        std::string modelFileName;  // stores the name of the 3D model to load for the player
        


};


#endif // _PLAYERDATA_H_
