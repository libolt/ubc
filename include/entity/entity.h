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

#ifndef _ENTITY_H_
#define _ENTITY_H_

//#include "utilities/conversion.h"

#include <string>
#include "Ogre.h"
#include "OgreEntity.h"
#include "OgreVector3.h"
#include "BtOgrePG.h"
#include "BtOgreGP.h"
#include "BtOgreExtras.h"
#include "utilities/typedefs.h"

class entity
{
    public:
    
    entity();  // constructor
    ~entity();  // destructor
    
    bool getInitialized();  // retrieves the value of initialized
    void setInitialized(bool set);  // sets the value of initialized
    
    bool getNameSet();  // retrieves the value of nameSet
    void setNameSet(bool set);  // sets the value of nameSet

    bool getNodeNameSet();  // retrieves the value of nodeNameSet
    void setNodeNameSet(bool set);  // sets the value of nodeNameSet

    size_t getID();  // retrieves the value of ID
    void setID(size_t set);  // sets the value of ID
    
    std::string getModelFileName();  // retrieves the value of modelFileName
    void setModelFileName(std::string set);  // sets the value of modelFileName

    std::string getName();  // retrieves the value of name
    void setName(std::string set);  // sets the value of name

    std::string getNodeName();  // retrieves the value of nodeName
    void setNodeName(std::string set);  // sets the value of nodeName

    OgreEntitySharedPtr getModel();  // retrieves the value of model
    void setModel(OgreEntitySharedPtr set);  // sets the value of model

    OgreSceneNodeSharedPtr getNode();  // retrieves the value of node
    void setNode(OgreSceneNodeSharedPtr set);  // sets the value of node

    bool getPhysicsSetup();  // retrieves the value of physicsSetup
    void setPhysicsSetup(bool set);  // sets the value of physicsSetup
    
    bool getModelNeedsLoaded();  // retrieves the value of modelNeedsLoaded
    void setModelNeedsLoaded(bool set);  // sets the value of modelNeedsLoaded

    bool getModelLoaded();  // retrieves the value of modelLoaded
    void setModelLoaded(bool set);  // sets the value of modelLoaded

    bool getNodeCreated();  // retrieves the value of nodeaCreated
    void setNodeCreated(bool set);  // sets the value of nodeCreated

    Ogre::Vector3 getNodePosition();  // retrieves the value of nodePosition
    void setNodePosition(Ogre::Vector3 set);  // sets the value of nodePosition

//    bool loadModel();  // loads the 3D model from file specified in modelName
    
//    bool setupPhysics();  // sets up the physics object
    
    private:
    
    bool initialized;  // stores whether entity object has been initialized
        
    bool nameSet;  // stores the name of the value of nameSet

    bool nodeNameSet;  // stores the value of bodeNameSet

    size_t ID;  // stores the ID number to distinguish between entities
    
    std::string modelFileName;  // stores the file name of the 3d model

    std::string name;  // stores the name of the model object in the scene

    std::string nodeName;  // stores the name of the scene node

    OgreEntitySharedPtr model;  // stores 3d model

    OgreSceneNodeSharedPtr node;  // stores node 3d model is attached to

    Ogre::Vector3 nodePosition;  // stores the position of the node

    bool physicsSetup;  // stores whether the physics object needs setup
    
    bool modelNeedsLoaded;  // stores whether or not to load the model

    bool modelLoaded;  // stores whether the 3D model of the basketball has been loaded
    
    bool nodeCreated;  // stores whether entitiy's node has been created
};

#endif

