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
 *   MERCHANTABILITY or FITNESS FOR A PAhRTICULAR PURPOSE.  See the        *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "data/courtdata.h"

courtData::courtData()  // constructor
{
    initialized = false;
    name = "";
    modelFileName = "";
    dimensions = Ogre::Vector2(0,0);
    boundary = Ogre::Vector2(0,0);
    boundaryPos = Ogre::Vector2(0,0);
    centerCourt = 0;
    centerJumpRadius = 0;
    keyDimensions = Ogre::Vector2(0,0);
    keyJumpRadius = 0;
    threePointSideLength = 0;
    threePointZPos = 0;
    threePointArcRadius = 0;
    baselineInboundPos = Ogre::Vector2(0,0);
    sidelineInboundPos = Ogre::Vector2(0,0);
}

courtData::~courtData() = default;  // destructor


std::string courtData::getName() const  // retrieves the value of name
{
    return (name);
}
void courtData::setName(const std::string &set)  // sets the value of name
{
    name = set;
}

bool courtData::getInitialized() const  // retrieves the value of initialized
{
    return (initialized);
}
void courtData::setInitialized(const bool &set)  // sets the value of initialized
{
    initialized = set;
}

std::string courtData::getModelFileName() const  // retrieves the value of modelFileName;
{
    return (modelFileName);
}
void courtData::setModelFileName(const std::string &set)  // sets the value of modelFileName
{
    modelFileName = set;
}

Ogre::Vector2 courtData::getDimensions() const // retrieves the value of dimensions
{
    return (dimensions);
}
void courtData::setDimensions(const Ogre::Vector2 &set)  // sets the value of dimensions
{
    dimensions = set;
}

Ogre::Vector2 courtData::getBoundary() const  // retrieves the value of boundary
{
   return (boundary);
}
void courtData::setBoundary(const Ogre::Vector2 &set)  // sets the value of boundary
{
    boundary = set;
}

Ogre::Vector2 courtData::getBoundaryPos() const  // retrieves the value of boundaryPos
{
    return (boundaryPos);
}
void courtData::setBoundaryPos(const Ogre::Vector2 &set)  // sets the value of boundaryPos
{
    boundaryPos = set;
}

float courtData::getCenterCourt() const  // retrieves the value of centerCourt
{
    return (centerCourt);
}
void courtData::setCenterCourt(const float &set)  // sets the value of centerCourt
{
    centerCourt = set;
}

float courtData::getCenterJumpRadius() const // retrieves the value of centerJumpRadius
{
    return (centerJumpRadius);
}
void courtData::setCenterJumpRadius(const float &set)  // sets the value of centerJumpRadius
{
    centerJumpRadius = set;
}

Ogre::Vector2 courtData::getKeyDimensions() const // retrieves the value of keyDimensions
{
    return (keyDimensions);
}
void courtData::setKeyDimensions(const Ogre::Vector2 &set)  // sets the value of keyDimensions
{
    keyDimensions = set;
}

float courtData::getKeyJumpRadius() const // retrieves the value of keyJumpRadius
{
    return (keyJumpRadius);
}
void courtData::setKeyJumpRadius(const float &set)  // sets the value of keyJumpRadius
{
    keyJumpRadius = set;
}

float courtData::getThreePointSideLength() const  // retrieves the value of threePointSideLength
{
    return (threePointSideLength);
}
void courtData::setThreePointSideLength(const float &set)  // sets the value of threePointSideLength
{
    threePointSideLength = set;
}

float courtData::getThreePointZPos() const  // retrieves the value of threePointZPos
{
    return (threePointZPos);
}
void courtData::setThreePointZPos(const float &set)  // sets the value of threePointZPos
{
    threePointZPos = set;
}

float courtData::getThreePointArcRadius() const  // retrieves the value of threePointArcRadius
{
    return (threePointArcRadius);
}
void courtData::setThreePointArcRadius(const float &set)  // sets the value of threePointArcRadius
{
    threePointArcRadius = set;
}

Ogre::Vector2 courtData::getBaselineInboundPos() const  // retrieves the value of baselineInputPos
{
    return (baselineInboundPos);
}
void courtData::setBaselineInboundPos(const Ogre::Vector2 &set)  // sets the value of baselineInputPos
{
    baselineInboundPos = set;
}

Ogre::Vector2 courtData::getSidelineInboundPos() const  // retrieves the value of sidelineInputPos
{
    return (sidelineInboundPos);
}
void courtData::setSidelineInboundPos(const Ogre::Vector2 &set)  // sets the value of sidelineInputPos
{
    sidelineInboundPos = set;
}


