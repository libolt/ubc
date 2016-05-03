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

#include "conversion.h"
#include "logging.h"
#include "comparison.h"

comparison::comparison()
{
    
}

bool comparison::OgreVector3ToOgreVector3(const Ogre::Vector3 &currentValue, const Ogre::Vector3 &newValue)  // compares two Ogre::Vector3 objects and returns true if the same,false if diffeeent
{
    if (currentValue.x != newValue.x || currentValue.y != newValue.y || currentValue.z != newValue.z)
    {
        return (false);
    }
    else
    {
        return (true);
    }
    return (true);
}

Ogre::Vector3 comparison::OgreVector3ToOgreVector3Result(const Ogre::Vector3 &currentValue, const Ogre::Vector3 &newValue)  // compares two Ogre::Vector3 objects and returns their differences
{
    boost::shared_ptr<conversion> convert = conversion::Instance();

    Ogre::Vector3 change = Ogre::Vector3(0,0,0);

    logMsg("currentValue.x == " +convert->toString(currentValue.x));
    logMsg("newValue.x == " +convert->toString(newValue.x));
    
    if (convert->toString(newValue.x) != "nan" && convert->toString(newValue.y) != "nan" && convert->toString(newValue.z) != "nan")
    {
    
        if (currentValue.x > 0)
        {
            if (newValue.x >= 0)
            {
                if (newValue.x > currentValue.x)
                {
                    change.x = newValue.x - currentValue.x;
                }
                else if (newValue.x < currentValue.x)
                {
                    change.x = (currentValue.x - newValue.x)*(-1);
                }
                else
                {
                
                }
            }
            else if (newValue.x < 0)
            {
                change.x = currentValue.x + newValue.x;
            }
        }
        else if (currentValue.x < 0)
        {
            if (newValue.x >= 0)
            {
                change.x = currentValue.x + newValue.x;
            }
            else if (newValue.x < 0)
            {
                if (newValue.x < currentValue.x)
                {
                    change.x = newValue.x - currentValue.x;
                }
                else if (newValue.x > currentValue.x)
                {
                    change.x = (currentValue.x - newValue.x)*(-1);
                }
            }
            else
            {
            
            }
        }
        else if (currentValue.x == 0)
        {
            if (newValue.x >= 0)
            {
                change.x = newValue.x - currentValue.x;
            }
            else if (newValue.x < 0)
            {
                change.x = currentValue.x - newValue.x;
            }
        }
        else
        {
        
        }

        logMsg("changeValue.x == " +convert->toString(change.x));

        logMsg("currentValue.y == " +convert->toString(currentValue.y));
        logMsg("newValue.y == " +convert->toString(newValue.y));
        if (currentValue.y > 0)
        {
            if (newValue.y >= 0)
            {
                if (newValue.y > currentValue.y)
                {
                    change.y = newValue.y - currentValue.y;
                }
                else if (newValue.y < currentValue.y)
                {
                    change.y = (currentValue.y - newValue.y)*(-1);
                }
                else
                {

                }
            }
            else if (newValue.y < 0)
            {
                change.y = currentValue.y + newValue.y;
            }
        }
        else if (currentValue.y < 0)
        {
            if (newValue.y >= 0)
            {
                change.y = currentValue.y + newValue.y;
            }
            else if (newValue.y < 0)
            {
                if (newValue.y < currentValue.y)
                {
                    change.y = newValue.y - currentValue.y;
                }
                else if (newValue.y > currentValue.y)
                {
                    change.y = (currentValue.y - newValue.y)*(-1);
                }
            }
            else
            {

            }
        }
        else if (currentValue.y == 0)
        {
            if (newValue.y >= 0)
            {
                change.y = newValue.y - currentValue.y;
            }
            else if (newValue.y < 0)
            {
                change.y = currentValue.y - newValue.y;
            }
        }
        else
        {

        }


        logMsg("changeValue.y == " +convert->toString(change.y));

        logMsg("currentValue.z == " +convert->toString(currentValue.z));
        logMsg("newValue.z == " +convert->toString(newValue.z));
        if (currentValue.z > 0)
        {
            if (newValue.z >= 0)
            {
                if (newValue.z > currentValue.z)
                {
                    change.z = newValue.z - currentValue.z;
                }
                else if (newValue.z < currentValue.z)
                {
                    change.z = (currentValue.z - newValue.z)*(-1);
                }
                else
                {

                }
            }
            else if (newValue.z < 0)
            {
                change.z = currentValue.z + newValue.z;
            }
        }
        else if (currentValue.z < 0)
        {
            if (newValue.z >= 0)
            {
                change.z = currentValue.z + newValue.z;
            }
            else if (newValue.z < 0)
            {
                if (newValue.z < currentValue.z)
                {
                    change.z = newValue.z - currentValue.z;
                }
                else if (newValue.z > currentValue.z)
                {
                    change.z = (currentValue.z - newValue.z)*(-1);
                }
            }
            else
            {

            }
        }
        else if (currentValue.z == 0)
        {
            if (newValue.z >= 0)
            {
                change.z = newValue.z - currentValue.z;
            }
            else if (newValue.z < 0)
            {
                change.z = currentValue.z - newValue.z;
            }
        }
        else
        {

        }

        logMsg("changeValue.z == " +convert->toString(change.z));
    }
    else 
    {
        change.x = 0;
        change.y = 0;
        change.z = 0;
    }
    return (change);
}

bool comparison::OgreVector3ToOpenSteerVec3(const Ogre::Vector3 &currentValue, const OpenSteer::Vec3 &newValue)  // compares an Ogre::Vector3 object to an OpenSteer::Vec3 and returns true if the same,false if different
{
    if (currentValue.x != newValue.x || currentValue.y != newValue.y || currentValue.z != newValue.z)
    {
        return (false);
    }
    else
    {
        return (true);
    }
    return (true);
}
Ogre::Vector3 comparison::OgreVector3ToOpenSteerVec3Result(const Ogre::Vector3 &currentValue, const OpenSteer::Vec3 &newValue)  // compares an Ogre::Vector3 object to an OpenSteer::Vec3 and returns their differences in Ogre::Vector3 format
{
    boost::shared_ptr<conversion> convert = conversion::Instance();

    Ogre::Vector3 change = Ogre::Vector3(0,0,0);

    logMsg("currentValue.x == " +convert->toString(currentValue.x));
    logMsg("newValue.x == " +convert->toString(newValue.x));
    
    if (convert->toString(newValue.x) != "nan" && convert->toString(newValue.y) != "nan" && convert->toString(newValue.z) != "nan")
    {
        if (currentValue.x > 0)
        {
            if (newValue.x >= 0)
            {
                if (newValue.x > currentValue.x)
                {
                    change.x = newValue.x - currentValue.x;
                }
                else if (newValue.x < currentValue.x)
                {
                    change.x = (currentValue.x - newValue.x)*(-1);
                }
                else
                {

                }
            }
            else if (newValue.x < 0)
            {
                change.x = currentValue.x + newValue.x;
            }
        }
        else if (currentValue.x < 0)
        {
            if (newValue.x >= 0)
            {
                change.x = currentValue.x + newValue.x;
            }
            else if (newValue.x < 0)
            {
                if (newValue.x < currentValue.x)
                {
                    change.x = newValue.x - currentValue.x;
                }
                else if (newValue.x > currentValue.x)
                {
                    change.x = (currentValue.x - newValue.x)*(-1);
                }
            }
            else
            {

            }
        }
        else if (currentValue.x == 0)
        {
            if (newValue.x >= 0)
            {
                change.x = newValue.x - currentValue.x;
            }
            else if (newValue.x < 0)
            {
                change.x = currentValue.x - newValue.x;
            }
        }
        else
        {

        }

        logMsg("changeValue.x == " +convert->toString(change.x));

        logMsg("currentValue.y == " +convert->toString(currentValue.y));
        logMsg("newValue.y == " +convert->toString(newValue.y));
        if (currentValue.y > 0)
        {
            if (newValue.y >= 0)
            {
                if (newValue.y > currentValue.y)
                {
                    change.y = newValue.y - currentValue.y;
                }
                else if (newValue.y < currentValue.y)
                {
                    change.y = (currentValue.y - newValue.y)*(-1);
                }
                else
                {

                }
            }
            else if (newValue.y < 0)
            {
                change.y = currentValue.y + newValue.y;
            }
        }
        else if (currentValue.y < 0)
        {
            if (newValue.y >= 0)
            {
                change.y = currentValue.y + newValue.y;
            }
            else if (newValue.y < 0)
            {
                if (newValue.y < currentValue.y)
                {
                    change.y = newValue.y - currentValue.y;
                }
                else if (newValue.y > currentValue.y)
                {
                    change.y = (currentValue.y - newValue.y)*(-1);
                }
            }
            else
            {

            }
        }
        else if (currentValue.y == 0)
        {
            if (newValue.y >= 0)
            {
                change.y = newValue.y - currentValue.y;
            }
            else if (newValue.y < 0)
            {
                change.y = currentValue.y - newValue.y;
            }
        }
        else
        {

        }


        logMsg("changeValue.y == " +convert->toString(change.y));

        logMsg("currentValue.z == " +convert->toString(currentValue.z));
        logMsg("newValue.z == " +convert->toString(newValue.z));
        if (currentValue.z > 0)
        {
            if (newValue.z >= 0)
            {
                if (newValue.z > currentValue.z)
                {
                    change.z = newValue.z - currentValue.z;
                }
                else if (newValue.z < currentValue.z)
                {
                    change.z = (currentValue.z - newValue.z)*(-1);
                }
                else
                {

                }
            }
            else if (newValue.z < 0)
            {
                change.z = currentValue.z + newValue.z;
            }
        }
        else if (currentValue.z < 0)
        {
            if (newValue.z >= 0)
            {
                change.z = currentValue.z + newValue.z;
            }
            else if (newValue.z < 0)
            {
                if (newValue.z < currentValue.z)
                {
                    change.z = newValue.z - currentValue.z;
                }
                else if (newValue.z > currentValue.z)
                {
                    change.z = (currentValue.z - newValue.z)*(-1);
                }
            }
            else
            {

            }
        }
        else if (currentValue.z == 0)
        {
            if (newValue.z >= 0)
            {
                change.z = newValue.z - currentValue.z;
            }
            else if (newValue.z < 0)
            {
                change.z = currentValue.z - newValue.z;
            }
        }
        else
        {

        }

        logMsg("changeValue.z == " +convert->toString(change.z));
    }
    else
    {
        change.x = 0;
        change.y = 0;
        change.z = 0;
    }
    return (change);
}

bool comparison::OgreVector3ToBTVector3(const Ogre::Vector3 &currentValue, const btVector3 &newValue)  // compares an Ogre::Vector3 object to an btVector3 and returns true if the same,false if different
{
    if (currentValue.x != newValue.getX() || currentValue.y != newValue.getY() || currentValue.z != newValue.getZ())
    {
        return (false);
    }
    else
    {
        return (true);
    }
    return (true);
}
Ogre::Vector3 comparison::OgreVector3ToBTVector3Result(const Ogre::Vector3 &currentValue, const btVector3 &newValue)  // compares an Ogre::Vector3 object to an btVector3 and returns their differences in Ogre::Vector3 format
{
    boost::shared_ptr<conversion> convert = conversion::Instance();

    Ogre::Vector3 change = Ogre::Vector3(0,0,0);

    logMsg("currentValue.x == " +convert->toString(currentValue.x));
    logMsg("newValue.getX() == " +convert->toString(newValue.getX()));
    
    if (convert->toString(newValue.getX()) != "nan" && convert->toString(newValue.getY()) != "nan" && convert->toString(newValue.getZ()) != "nan")
    {

        if (currentValue.x > 0)
        {
            if (newValue.getX() >= 0)
            {
                if (newValue.getX() > currentValue.x)
                {
                    change.x = newValue.getX() - currentValue.x;
                }
                else if (newValue.getX() < currentValue.x)
                {
                    change.x = (currentValue.x - newValue.getX())*(-1);
                }
                else
                {

                }
            }
            else if (newValue.getX() < 0)
            {
                change.x = currentValue.x + newValue.getX();
            }
        }
        else if (currentValue.x < 0)
        {
            if (newValue.getX() >= 0)
            {
                change.x = currentValue.x + newValue.getX();
            }
            else if (newValue.getX() < 0)
            {
                if (newValue.getX() < currentValue.x)
                {
                    change.x = newValue.getX() - currentValue.x;
                }
                else if (newValue.getX() > currentValue.x)
                {
                    change.x = (currentValue.x - newValue.getX())*(-1);
                }
            }
            else
            {

            }
        }
        else if (currentValue.x == 0)
        {
            if (newValue.getX() >= 0)
            {
                change.x = newValue.getX() - currentValue.x;
            }
            else if (newValue.getX() < 0)
            {
                change.x = currentValue.x - newValue.getX();
            }
        }
        else
        {

        }

        logMsg("changeValue.x == " +convert->toString(change.x));

        logMsg("currentValue.y == " +convert->toString(currentValue.y));
        logMsg("newValue.getY() == " +convert->toString(newValue.getY()));
        if (currentValue.y > 0)
        {
            if (newValue.getY() >= 0)
            {
                if (newValue.getY() > currentValue.y)
                {
                    change.y = newValue.getY() - currentValue.y;
                }
                else if (newValue.getY() < currentValue.y)
                {
                    change.y = (currentValue.y - newValue.getY())*(-1);
                }
                else
                {

                }
            }
            else if (newValue.getY() < 0)
            {
                change.y = currentValue.y + newValue.getY();
            }
        }
        else if (currentValue.y < 0)
        {
            if (newValue.getY() >= 0)
            {
                change.y = currentValue.y + newValue.getY();
            }
            else if (newValue.getY() < 0)
            {
                if (newValue.getY() < currentValue.y)
                {
                    change.y = newValue.getY() - currentValue.y;
                }
                else if (newValue.getY() > currentValue.y)
                {
                    change.y = (currentValue.y - newValue.getY())*(-1);
                }
            }
            else
            {

            }
        }
        else if (currentValue.y == 0)
        {
            if (newValue.getY() >= 0)
            {
                change.y = newValue.getY() - currentValue.y;
            }
            else if (newValue.getY() < 0)
            {
                change.y = currentValue.y - newValue.getY();
            }
        }
        else
        {

        }


        logMsg("changeValue.y == " +convert->toString(change.y));

        logMsg("currentValue.z == " +convert->toString(currentValue.z));
        logMsg("newValue.getZ() == " +convert->toString(newValue.getZ()));
        if (currentValue.z > 0)
        {
            if (newValue.getZ() >= 0)
            {
                if (newValue.getZ() > currentValue.z)
                {
                    change.z = newValue.getZ() - currentValue.z;
                }
                else if (newValue.getZ() < currentValue.z)
                {
                    change.z = (currentValue.z - newValue.getZ())*(-1);
                }
                else
                {

                }
            }
            else if (newValue.getZ() < 0)
            {
                change.z = currentValue.z + newValue.getZ();
            }
        }
        else if (currentValue.z < 0)
        {
            if (newValue.getZ() >= 0)
            {
                change.z = currentValue.z + newValue.getZ();
            }
            else if (newValue.getZ() < 0)
            {
                if (newValue.getZ() < currentValue.z)
                {
                    change.z = newValue.getZ() - currentValue.z;
                }
                else if (newValue.getZ() > currentValue.z)
                {
                    change.z = (currentValue.z - newValue.getZ())*(-1);
                }
            }
            else
            {

            }
        }
        else if (currentValue.z == 0)
        {
            if (newValue.getZ() >= 0)
            {
                change.z = newValue.getZ() - currentValue.z;
            }
            else if (newValue.getZ() < 0)
            {
                change.z = currentValue.z - newValue.getZ();
            }
        }
        else
        {

        }

        logMsg("changeValue.z == " +convert->toString(change.z));
    }
    else
    {
        change.x = 0;
        change.y = 0;
        change.z = 0;
    }
    return (change);
}
