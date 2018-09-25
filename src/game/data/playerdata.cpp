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

std::string playerData::getFirstName()  // retrieves the value of firstName
{
    return(firstName);
}
void playerData::setFirstName(std::string set)  // sets the value of firstName
{
    firstName = set;
}

std::string playerData::getLastName()  // retrieves the value of lastName
{
    return(lastName);
}
void playerData::setLastName(std::string set)  // sets the value of lastName
{
    lastName = set;
}

std::string playerData::getPlayerName()  // retrieves the value of playerName
{
    return(playerName);
}
void playerData::setPlayerName(std::string set)  // sets the value of playerName
{
    playerName = set;
}

size_t playerData::getAge()  // retrieves the value of age
{
    return(age);
}
void playerData::setAge(size_t set)  // sets the value of age
{
    age = set;
}

size_t playerData::getHeight()  // retrieves the value of height
{
    return(height);
}
void playerData::setHeight(size_t set)  // sets the value of height
{
    height = set;
}

size_t playerData::getWeight()  // retrieves the value of weight
{
    return(weight);
}
void playerData::setWeight(size_t set)  // sets the value of weight
{
    weight = set;
}

size_t playerData::getID()  // retrieves the value of ID
{
    return(ID);
}
void playerData::setID(size_t set)  // sets the value of ID
{
    ID = set;
}

size_t playerData::getTeamID()  // retrieves the value of teamID
{
	return (teamID);
}
void playerData::setTeamID(size_t set)  // sets the value of teamID
{
	teamID = set;
}

playerPositions playerData::getPrimaryPosition()  // retrieves the value of primaryPosition
{
    return(primaryPosition);
}
void playerData::setPrimaryPosition(playerPositions set)  // sets the value of primaryPosition
{
    primaryPosition = set;
}

playerPositions playerData::getSecondaryPosition()  // retrieves the value of secondaryPosition
{
    return (secondaryPosition);
}
void playerData::setSecondaryPosition(playerPositions set)  // sets the value of secondaryPosition
{
    secondaryPosition = set;
}

bool playerData::getActive()  // retrieves the value of active
{
    return(active);
}

void playerData::setActive(bool set)  // sets the value of active
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

size_t playerData::getShooting()  // retrieves the value of shooting
{
    return (shooting);
}
void playerData::setShooting(size_t set)  // sets the value of shooting
{
    shooting = set;
}

size_t playerData::getFreeThrow()  // retrieves the value of freeThrow
{
    return (freeThrow);
}
void playerData::setFreeThrow(size_t set)  // sets the value of freeThrow
{
    freeThrow = set;
}

size_t playerData::getLayup()  // retrieves the value of layup
{
    return (layup);
}
void playerData::setLayup(size_t set)  // sets the value of layup
{
    layup = set;
}

size_t playerData::getDunk()  // retrieves the value of dunk
{
    return (dunk);
}
void playerData::setDunk(size_t set)  // sets the value of dunk
{
    dunk = set;
}

size_t playerData::getInside()  // retrieves the value of inside
{
    return (inside);
}
void playerData::setInside(size_t set)  // sets the value of inside
{
    inside = set;
}

size_t playerData::getMidRange()  // retrieves the value of midRange
{
    return (midRange);
}
void playerData::setMidRange(size_t set)  // sets the value of midRange
{
    midRange = set;
}

size_t playerData::getThreePoint()  // retrieves the value of threePoint
{
    return (threePoint);
}
void playerData::setThreePoint(size_t set)  // sets the value of threePoint
{
    threePoint = set;
}

size_t playerData::getBallHandling()  // retrieves the value of ballHandling
{
    return (ballHandling);
}
void playerData::setBallHandling(size_t set)  // sets the value of ballHandling
{
    ballHandling = set;
}
size_t playerData::getBallSecurity()  // retrieves the value of ballSecurity
{
    return (ballSecurity);
}
void playerData::setBallSecurity(size_t set)  // sets the value of ballSecurity
{
    ballSecurity = set;
}

size_t playerData::getPassing()  // retrieves the value of passing
{
    return (passing);
}
void playerData::setPassing(size_t set)  // sets the value of passing
{
    passing = set;
}

size_t playerData::getPickSetting()  // retrieves the value of pickSetting
{
    return (pickSetting);
}
void playerData::setPickSetting(size_t set)  // sets the value of pickSetting
{
    pickSetting = set;
}

size_t playerData::getOffenseAwareness()  // retrieves the value of offenseAwareness
{
    return (offenseAwareness);
}
void playerData::setOffenseAwareness(size_t set)  // sets the value of offenseAwareness
{
    offenseAwareness = set;
}

size_t playerData::getDefenseAwareness()  // retrieves the value of defenseAwareness
{
    return (defenseAwareness);
}
void playerData::setDefenseAwareness(size_t set)  // sets the value of defenseAwareness
{
    defenseAwareness = set;
}

size_t playerData::getOffenseRebound()  // retrieves the value of offenseRebound
{
    return (offenseRebound);
}
void playerData::setOffenseRebound(size_t set)  // sets the value of offenseRebound
{
    offenseRebound = set;
}

size_t playerData::getDefenseRebound()  // retrieves the value of defenseRebound
{
    return (defenseRebound);
}
void playerData::setDefenseRebound(size_t set)  // sets the value of defenseRebound
{
    defenseRebound = set;
}

size_t playerData::getBlocking()  // retrieves the value of blocking
{
    return (blocking);
}
void playerData::setBlocking(size_t set)  // sets the value of blocking
{
    blocking = set;
}

size_t playerData::getStealing()  // retrieves the value of stealing
{
    return (stealing);
}
void playerData::setStealing(size_t set)  // sets the value of stealing
{
    stealing = set;
}

size_t playerData::getInteriorDefense()  // retrieves the value of interiorDefense
{
    return (interiorDefense);
}
void playerData::setInteriorDefense(size_t set)  // sets the value of interiorDefense
{
    interiorDefense = set;
}

size_t playerData::getMidRangeDefense()  // retrieves the value of midRangeDefense
{
    return(midRangeDefense);
}
void playerData::setMidRangeDefense(size_t set)  // sets the value of midRangeDefense
{
    midRangeDefense = set;
}

size_t playerData::getPerimeterDefense()  // retrieves the value of perimeterDefense
{
    return (perimeterDefense);
}
void playerData::setPerimeterDefense(size_t set)  // sets the value of perimeterDefense
{
    perimeterDefense = set;
}

size_t playerData::getHustle()  // retrieves the value of hustle
{
    return (hustle);
}
void playerData::setHustle(size_t set)  // sets the value of hustle
{
    hustle = set;
}

size_t playerData::getSpeed()  // retrieves the value of speed
{
    return (speed);
}
void playerData::setSpeed(size_t set)  // sets the value of speed
{
    speed = set;
}

size_t playerData::getQuickness()  // retrieves the value of quickness
{
    return (quickness);
}
void playerData::setQuickness(size_t set)  // sets the value of quickness
{
    quickness = set;
}

size_t playerData::getFatigue()  // retrieves the value of fatigue
{
    return (fatigue);
}
void playerData::setFatigue(size_t set)  // sets the value of fatigue
{
    fatigue = set;
}

size_t playerData::getDurability()  // retrieves the value of durability
{
    return (durability);
}
void playerData::setDurability(size_t set)  // sets the value of durability
{
    durability = set;
}

size_t playerData::getDemeanor()  // retrieves the value of demeanor
{
    return (demeanor);
}
void playerData::setDemeanor(size_t set)  // sets the value of demeanor
{
    demeanor = set;
}

size_t playerData::getImprovability()  // retrieves the value of improvability
{
    return (improvability);
}
void playerData::setImprovability(size_t set)  // sets the value of improvability
{
    improvability = set;
}

size_t playerData::getOverallRating()  // retrieves the value of overallRating
{
    return (overallRating);
}
void playerData::setOverallRating(size_t set)  // sets the value of overallRating
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
