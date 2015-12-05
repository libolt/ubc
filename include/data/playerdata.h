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

#ifndef _PLAYERDATA_H_
#define _PLAYERDATA_H_

#include <string>

#include "enums.h"

using namespace std;

class playerData
{

    public:

        playerData();
        ~playerData();

        string getFirstName(void);  // retrieves the value of firstName
        void setFirstName(string set);  // sets the value of firstName

        string getLastName(void);  // retrieves the value of lastName
        void setLastName(string set);  // sets the value of lastName

        int getAge(void);  // retrieves the value of age
        void setAge(int age);  // sets the value of  age

        int getHeight(void);  // retrieves the value of height
        void setHeight(int height);  // sets the value of height 

        int getWeight(void);  // retrieves the value of weight
        void setWeight(int weight);  // sets the value of weight

        int getID(void);  // retrieves the value of ID
        void setID(int id);  // sets the value of ID

        int getTeamID(void);  // retrieves the value of teamID
        void setTeamID(int id);  // sets the value of teamID

        playerPositions getPrimaryPosition();  // retrieves the value of primaryPosition
        void setPrimaryPosition(playerPositions set);  // sets the value of primaryPosition

        playerPositions getSecondaryPosition();  // retrieves the value of secondaryPosition
        void setSecondaryPosition(playerPositions set);  // sets the value of secondaryPosition

        bool getActive(void);  // retrieves the value of active
        void setActive(bool active);  // sets the value of active

        string getModel();  // retrieves the value of model
        void setModel(string Model);  // sets the value of model

        int getShooting();  // retrieves the value of shooting
        void setShooting(int set);  // sets the value of shooting
        
        int getFreeThrow();  // retrieves the value of freeThrow
        void setFreeThrow(int set);  // sets the value of freeThrow
        
        int getLayup();  // retrieves the value of layup
        void setLayup(int set);  // sets the value of layup
        
        int getDunk();  // retrieves the value of dunk
        void setDunk(int set);  // sets the value of dunk
        
        int getInside();  // retrieves the value of inside
        void setInside(int set);  // sets the value of inside
        
        int getMidRange();  // retrieves the value of midRange
        void setMidRange(int set);  // sets the value of midRange
        
        int getThreePoint();  // retrieves the value of threePoint
        void setThreePoint(int set);  // sets the value of threePoint
        
        int getBallHandling();  // retrieves the value of ballHandling
        void setBallHandling(int set);  // sets the value of ballHandling
        
        int getBallSecurity();  // retrieves the value of ballSecurity
        void setBallSecurity(int set);  // sets the value of ballSecurity
        
        int getPassing();  // retrieves the value of passing
        void setPassing(int set);  // sets the value of passing
        
        int getPickSetting();  // retrieves the value of pickSetting
        void setPickSetting(int set);  // sets the value of pickSetting
        
        int getOffenseAwareness();  // retrieves the value of offenseAwareness
        void setOffenseAwareness(int set);  // sets the value of offenseAwareness
        
        int getDefenseAwareness();  // retrieves the value of defenseAwareness
        void setDefenseAwareness(int set);  // sets the value of defenseAwareness

        int getOffenseRebound();  // retrieves the value of offenseRebound
        void setOffenseRebound(int set);  // sets the value of offenseRebound
        
        int getDefenseRebound();  // retrieves the value of defenseRebound
        void setDefenseRebound(int set);  // sets the value of defenseRebound
        
        int getBlocking();  // retrieves the value of blocking
        void setBlocking(int set);  // sets the value of blocking
        
        int getStealing();  // retrieves the value of stealing
        void setStealing(int set);  // sets the value of stealing
        
        int getInteriorDefense();  // retrieves the value of interiorDefense
        void setInteriorDefense(int set);  // sets the value of interiorDefense
        
        int getMidRangeDefense();  // retrieves the value of midRangeDefense
        void setMidRangeDefense(int set);  // sets the value of midRangeDefense
        
        int getPerimeterDefense();  // retrieves the value of perimeterDefense
        void setPerimeterDefense(int set);  // sets the value of perimeterDefense
        
        int getHustle();  // retrieves the value of hustle
        void setHustle(int set);  // sets the value of hustle
        
        int getSpeed();  // retrieves the value of speed
        void setSpeed(int set);  // sets the value of speed
        
        int getQuickness();  // retrieves the value of quickness
        void setQuickness(int set);  // sets the value of quickness
        
        int getFatigue();  // retrieves the value of fatigue
        void setFatigue(int set);  // sets the value of fatigue
        
        int getDurability();  // retrieves the value of durability
        void setDurability(int set);  // sets the value of durability
        
        int getDemeanor();  // retrieves the value of demeanor
        void setDemeanor(int set);  // sets the value of demeanor
        
        int getImprovability();  // retrieves the value of improvability
        void setImprovability(int set);  // sets the value of improvability
        
        int getOverallRating();  // retrieves the value of overallRating
        void setOverallRating(int set);  // sets the value of overallRating
        
        void calculateOverallRating();  // calculates the value of overallRating
        
    private:

        string firstName;  // stores the first name of the player
        string lastName;  // stores the last name of the player
        int age;  // stores the age of the player
        int height;  // stores the height in centimeters of the player
        int weight;  // stores the weight of the player in pounds.
        int ID;  // stores the unique ID of the player.
        int teamID;  // stores the unique ID of the team the player plays for.
        playerPositions primaryPosition;  // stores the primary position of the player
        playerPositions secondaryPosition;  // stores the secondary position of the player
        int shooting;  // stores the overall shooting proficiency
        int freeThrow;  // storee freethrow shooting proficiency
        int layup;  // storee layup shooting proficiencu
        int dunk;  // stores dunking proficiency
        int inside;  // stores scoring profiency in the paint
        int midRange;  // stores mid range scoring proficiency
        int threePoint;  // stores three point scoring proficiency
        int ballHandling;  // stores ability to dribble the ball
        int ballSecurity;  // stores ability to hang on to the ball when defended
        int passing;  // stores ability to make passes accurately
        int pickSetting;  // stores ability to set a pick
        int offenseAwareness;  // stores awareness of what happens during offense execution
        int defenseAwareness;  // stores awareness of what happens playing defense
        int offenseRebound;  // stores ability to rebound missed shots on offense
        int defenseRebound;  // stores ability to rebound missed shots on defense
        int blocking;  // stores ability to block opposing players' shot
        int stealing;  // stores ability to steal ball from opposing player
        int interiorDefense;  // stores ability to defend the paint
        int midRangeDefense;  // stores ability to defend between paint and three point linr
        int perimeterDefense;  // stores ability to defend from three point line extended
        int hustle;  // stores willingness to go after loose balls and rebounds
        int speed;  // stores how fast player can run
        int quickness;  // stores how quick player takes off on move
        int fatigue;  // stores how quickly player tires
        int durability;  // stores how healthy a player stays during game/season
        int demeanor;  // stores how passive, excited, agressive a player is
        int improvability;  // stores players ability to improve skills
        int overallRating;  // stores overall rating which is the sum of all ratings/number of ratings
        
        // if player is playing this is true
        bool active;

        string model;  // stores the name of the 3D model to load for the player
        


};


#endif // _PLAYERDATA_H_
