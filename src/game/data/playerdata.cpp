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

#include "utilities/conversion.h"
#include "Ogre.h"

#include "data/playerdata.h"
#include "utilities/logging.h"

playerData::playerData()  // constructor
{
    firstName = '\0';
    lastName = '\0';
    age = 0;
    height = 0;
    weight = 0;
    ID = 0;
    teamID = -1;
    primaryPosition = NONE;
    secondaryPosition = NONE;
    shooting = 0;
    freeThrow = 0;
    layup = 0;
    dunk = 0;
    inside = 0;
    midRange = 0;
    threePoint = 0;
    ballHandling = 0;
    ballSecurity = 0;
    passing = 0;
    pickSetting = 0;
    offenseAwareness = 0;
    defenseAwareness = 0;
    offenseRebound = 0;
    defenseRebound = 0;
    blocking = 0;
    stealing = 0;
    interiorDefense = 0;
    midRangeDefense = 0;
    perimeterDefense = 0;
    hustle = 0;
    speed = 0;
    quickness = 0;
    fatigue = 0;
    durability = 0;
    demeanor = 0;
    improvability = 0;
    overallRating = 0;
    active = false;
}

playerData::~playerData()  // destructor
{
}

std::string playerData::getFirstName() const  // retrieves the value of firstName
{
    return(firstName);
}
void playerData::setFirstName(const std::string &set)  // sets the value of firstName
{
    firstName = set;
}

std::string playerData::getLastName() const // retrieves the value of lastName
{
    return(lastName);
}
void playerData::setLastName(const std::string &set)  // sets the value of lastName
{
    lastName = set;
}

std::string playerData::getPlayerName() const // retrieves the value of playerName
{
    return(playerName);
}
void playerData::setPlayerName(const std::string &set)  // sets the value of playerName
{
    playerName = set;
}

size_t playerData::getAge() const // retrieves the value of age
{
    return(age);
}
void playerData::setAge(const size_t &set)  // sets the value of age
{
    age = set;
}

size_t playerData::getHeight() const  // retrieves the value of height
{
    return(height);
}
void playerData::setHeight(const size_t &set)  // sets the value of height
{
    height = set;
}

size_t playerData::getWeight() const  // retrieves the value of weight
{
    return(weight);
}
void playerData::setWeight(const size_t &set)  // sets the value of weight
{
    weight = set;
}

size_t playerData::getID() const // retrieves the value of ID
{
    return(ID);
}
void playerData::setID(const size_t &set)  // sets the value of ID
{
    ID = set;
}

size_t playerData::getTeamID() const // retrieves the value of teamID
{
	return (teamID);
}
void playerData::setTeamID(const size_t &set)  // sets the value of teamID
{
	teamID = set;
}

playerPositions playerData::getPrimaryPosition() const // retrieves the value of primaryPosition
{
    return(primaryPosition);
}
void playerData::setPrimaryPosition(const playerPositions &set)  // sets the value of primaryPosition
{
    primaryPosition = set;
}

playerPositions playerData::getSecondaryPosition() const  // retrieves the value of secondaryPosition
{
    return (secondaryPosition);
}
void playerData::setSecondaryPosition(const playerPositions &set)  // sets the value of secondaryPosition
{
    secondaryPosition = set;
}

bool playerData::getActive() const  // retrieves the value of active
{
    return(active);
}

void playerData::setActive(const bool &set)  // sets the value of active
{
    active = set;
}

/*std::string playerData::getModelFileName()  // retrieves the value of model
{
    return (modelFileName);
}
void playerData::setModelFileName(string set)  // sets the value of model
{
    modelFileName = set; 
}
*/

size_t playerData::getShooting() const // retrieves the value of shooting
{
    return (shooting);
}
void playerData::setShooting(const size_t &set)  // sets the value of shooting
{
    shooting = set;
}

size_t playerData::getFreeThrow() const  // retrieves the value of freeThrow
{
    return (freeThrow);
}
void playerData::setFreeThrow(const size_t &set)  // sets the value of freeThrow
{
    freeThrow = set;
}

size_t playerData::getLayup() const  // retrieves the value of layup
{
    return (layup);
}
void playerData::setLayup(const size_t &set)  // sets the value of layup
{
    layup = set;
}

size_t playerData::getDunk() const  // retrieves the value of dunk
{
    return (dunk);
}
void playerData::setDunk(const size_t &set)  // sets the value of dunk
{
    dunk = set;
}

size_t playerData::getInside() const  // retrieves the value of inside
{
    return (inside);
}
void playerData::setInside(const size_t &set)  // sets the value of inside
{
    inside = set;
}

size_t playerData::getMidRange() const  // retrieves the value of midRange
{
    return (midRange);
}
void playerData::setMidRange(const size_t &set)  // sets the value of midRange
{
    midRange = set;
}

size_t playerData::getThreePoint() const  // retrieves the value of threePoint
{
    return (threePoint);
}
void playerData::setThreePoint(const size_t &set)  // sets the value of threePoint
{
    threePoint = set;
}

size_t playerData::getBallHandling() const  // retrieves the value of ballHandling
{
    return (ballHandling);
}
void playerData::setBallHandling(const size_t &set)  // sets the value of ballHandling
{
    ballHandling = set;
}
size_t playerData::getBallSecurity() const // retrieves the value of ballSecurity
{
    return (ballSecurity);
}
void playerData::setBallSecurity(const size_t &set)  // sets the value of ballSecurity
{
    ballSecurity = set;
}

size_t playerData::getPassing() const // retrieves the value of passing
{
    return (passing);
}
void playerData::setPassing(const size_t &set)  // sets the value of passing
{
    passing = set;
}

size_t playerData::getPickSetting() const  // retrieves the value of pickSetting
{
    return (pickSetting);
}
void playerData::setPickSetting(const size_t &set)  // sets the value of pickSetting
{
    pickSetting = set;
}

size_t playerData::getOffenseAwareness() const // retrieves the value of offenseAwareness
{
    return (offenseAwareness);
}
void playerData::setOffenseAwareness(const size_t &set)  // sets the value of offenseAwareness
{
    offenseAwareness = set;
}

size_t playerData::getDefenseAwareness() const  // retrieves the value of defenseAwareness
{
    return (defenseAwareness);
}
void playerData::setDefenseAwareness(const size_t &set)  // sets the value of defenseAwareness
{
    defenseAwareness = set;
}

size_t playerData::getOffenseRebound() const  // retrieves the value of offenseRebound
{
    return (offenseRebound);
}
void playerData::setOffenseRebound(const size_t &set)  // sets the value of offenseRebound
{
    offenseRebound = set;
}

size_t playerData::getDefenseRebound() const  // retrieves the value of defenseRebound
{
    return (defenseRebound);
}
void playerData::setDefenseRebound(const size_t &set)  // sets the value of defenseRebound
{
    defenseRebound = set;
}

size_t playerData::getBlocking() const  // retrieves the value of blocking
{
    return (blocking);
}
void playerData::setBlocking(const size_t &set)  // sets the value of blocking
{
    blocking = set;
}

size_t playerData::getStealing() const // retrieves the value of stealing
{
    return (stealing);
}
void playerData::setStealing(const size_t &set)  // sets the value of stealing
{
    stealing = set;
}

size_t playerData::getInteriorDefense() const // retrieves the value of interiorDefense
{
    return (interiorDefense);
}
void playerData::setInteriorDefense(const size_t &set)  // sets the value of interiorDefense
{
    interiorDefense = set;
}

size_t playerData::getMidRangeDefense() const // retrieves the value of midRangeDefense
{
    return(midRangeDefense);
}
void playerData::setMidRangeDefense(const size_t &set)  // sets the value of midRangeDefense
{
    midRangeDefense = set;
}

size_t playerData::getPerimeterDefense() const // retrieves the value of perimeterDefense
{
    return (perimeterDefense);
}
void playerData::setPerimeterDefense(const size_t &set)  // sets the value of perimeterDefense
{
    perimeterDefense = set;
}

size_t playerData::getHustle() const  // retrieves the value of hustle
{
    return (hustle);
}
void playerData::setHustle(const size_t &set)  // sets the value of hustle
{
    hustle = set;
}

size_t playerData::getSpeed() const  // retrieves the value of speed
{
    return (speed);
}
void playerData::setSpeed(const size_t &set)  // sets the value of speed
{
    speed = set;
}

size_t playerData::getQuickness() const // retrieves the value of quickness
{
    return (quickness);
}
void playerData::setQuickness(const size_t &set)  // sets the value of quickness
{
    quickness = set;
}

size_t playerData::getFatigue() const  // retrieves the value of fatigue
{
    return (fatigue);
}
void playerData::setFatigue(const size_t &set)  // sets the value of fatigue
{
    fatigue = set;
}

size_t playerData::getDurability() const // retrieves the value of durability
{
    return (durability);
}
void playerData::setDurability(const size_t &set)  // sets the value of durability
{
    durability = set;
}

size_t playerData::getDemeanor() const  // retrieves the value of demeanor
{
    return (demeanor);
}
void playerData::setDemeanor(const size_t &set)  // sets the value of demeanor
{
    demeanor = set;
}

size_t playerData::getImprovability() const  // retrieves the value of improvability
{
    return (improvability);
}
void playerData::setImprovability(const size_t &set)  // sets the value of improvability
{
    improvability = set;
}

size_t playerData::getOverallRating() const // retrieves the value of overallRating
{
    return (overallRating);
}
void playerData::setOverallRating(const size_t &set)  // sets the value of overallRating
{
    overallRating = set;
}

void playerData::calculateOverallRating() // calculates the value of overallRating
{
    conversionSharedPtr convert ;
    
    overallRating = shooting + freeThrow + layup + dunk + inside + midRange +
    threePoint + ballHandling + ballSecurity + passing + pickSetting +
    offenseAwareness + defenseAwareness + offenseRebound + defenseRebound +
    blocking + stealing + interiorDefense + midRangeDefense + perimeterDefense +
    hustle + speed + quickness + fatigue + durability + demeanor + improvability;
    logMsg("Overall first = " +convert->toString(overallRating));
    overallRating = overallRating / 27;
    logMsg("Overall Rating = " +convert->toString(overallRating));
//    exit(0);
}
