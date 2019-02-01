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

#ifndef _ENTITYFLAGS_H_
#define _ENTITYFLAGS_H_

class entityFlags
{
    public:
    
        entityFlags();  // constructor
        ~entityFlags();  // destructor

        bool getPhysicsSetup() const;  // retrieves the value of physicsSetup
        void setPhysicsSetup(const bool &set);  // sets the value of physicsSetup
    
        bool getInitialized() const;  // retrieves the value of initialized
        void setInitialized(const bool &set);  // sets the value of initialized

            
        bool getNameSet() const;  // retrieves the value of nameSet
        void setNameSet(const bool &set);  // sets the value of nameSet

        bool getNodeNameSet() const;  // retrieves the value of nodeNameSet
        void setNodeNameSet(const bool &set);  // sets the value of nodeNameSet
        
        bool getModelNeedsLoaded() const;  // retrieves the value of modelNeedsLoaded
        void setModelNeedsLoaded(const bool &set);  // sets the value of modelNeedsLoaded

        bool getModelLoaded() const;  // retrieves the value of modelLoaded
        void setModelLoaded(const bool &set);  // sets the value of modelLoaded

        bool getNodeCreated() const;  // retrieves the value of nodeCreated
        void setNodeCreated(const bool &set);  // sets the value of nodeCreated

    private:
    
        bool initialized;  // stores whether the court entity object has been initialized

        bool physicsSetup;  // stores whether the physics object needs setup

        bool nameSet;  // stores the name of the value of nameSet

        bool nodeNameSet;  // stores the value of bodeNameSet

        bool modelNeedsLoaded;  // stores whether or not to load the model

        bool modelLoaded;  // stores whether the 3D model of the basketball has been loaded
    
        bool nodeCreated;  // stores whether entitiy's node has been created

};

#endif
