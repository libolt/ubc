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

#ifndef _ENTITYCOMPONENTS_H_
#define _ENTITYCOMPONENTS_H_

#include "utilities/enums.h"
#include "utilities/typedefs.h"

class entityComponents
{
    public:

        entityComponents();  // constructor
        ~entityComponents();  // destructor
        
        size_t getID() const;  // retrieves the value of ID
        void setID(const size_t &set);  // sets the value of ID
    
        std::string getModelFileName() const;  // retrieves the value of modelFileName
        void setModelFileName(const std::string &set);  // sets the value of modelFileName

        std::string getName() const;  // retrieves the value of name
        void setName(const std::string &set);  // sets the value of name

        std::string getNodeName() const;  // retrieves the value of nodeName
        void setNodeName(const std::string &set);  // sets the value of nodeName

        OgreEntitySharedPtr getModel() const;  // retrieves the value of model
        void setModel(const OgreEntitySharedPtr &set);  // sets the value of model

        OgreSceneNodeSharedPtr getNode() const;  // retrieves the value of node
        void setNode(const OgreSceneNodeSharedPtr &set);  // sets the value of node

        Ogre::Vector3 getNodePosition() const;  // retrieves the value of nodePosition
        void setNodePosition(const Ogre::Vector3 &set);  // sets the value of nodePosition

    private:
    
        size_t ID;  // stores the ID number to distinguish between entities
    
        std::string modelFileName;  // stores the file name of the 3d model

        std::string name;  // stores the name of the model object in the scene

        std::string nodeName;  // stores the name of the scene node

        OgreEntitySharedPtr model;  // stores 3d model

        OgreSceneNodeSharedPtr node;  // stores node 3d model is attached to

        Ogre::Vector3 nodePosition;  // stores the position of the node
    

    
};

#endif
