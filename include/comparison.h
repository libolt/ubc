/***************************************************************************
 *   Copyright (C) 1999 - 2016 by Mike McLean                              *
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

#ifndef _COMPARISON_H_
#define _COMPARISON_H_

#include "OgreVector3.h"
#include "LinearMath/btVector3.h"
class comparison
{
    public:
        comparison();
        bool OgreVector3ToOgreVector3(const Ogre::Vector3 &currentValue, const Ogre::Vector3 &newValue);  // compares two Ogre::Vector3 objects and returns true if the same,false if different
        Ogre::Vector3 OgreVector3ToOgreVector3Result(const Ogre::Vector3 &currentValue, const Ogre::Vector3 &newValue);  // compares two Ogre::Vector3 objects and returns their differences in Ogre::Vector3 format

        bool OgreVector3ToOpenSteerVec3(const Ogre::Vector3 &currentValue, const OpenSteer::Vec3 &newValue);  // compares an Ogre::Vector3 object to an OpenSteer::Vec3 and returns true if the same,false if different
        Ogre::Vector3 OgreVector3ToOpenSteerVec3Result(const Ogre::Vector3 &currentValue, const OpenSteer::Vec3 &newValue);  // compares an Ogre::Vector3 object to an OpenSteer::Vec3 and returns their differences in Ogre::Vector3 format

        bool OgreVector3ToBTVector3(const Ogre::Vector3 &currentValue, const btVector3 &newValue);  // compares an Ogre::Vector3 object to an btVector3 and returns true if the same,false if different
        Ogre::Vector3 OgreVector3ToBTVector3Result(const Ogre::Vector3 &currentValue, const btVector3 &newValue);  // compares an Ogre::Vector3 object to an btVector3 and returns their differences in Ogre::Vector3 format

    private:
};


#endif
