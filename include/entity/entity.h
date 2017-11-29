/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
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
    
    size_t getEntityID();  // retrieves the value of entityID
    void setEntityID(size_t set);  // sets the value of entityID
    
    std::string getEntityModelFileName();  // retrieves the value of modelName
    void setEntityModelFileName(std::string set);  // sets the value of modelName

    std::string getEntityName();  // retrieves the value of entityName
    void setEntityName(std::string set);  // sets the value of entityName

    std::string getEntityNodeName();  // retrieves the value of nodeName
    void setEntityNodeName(std::string set);  // sets the value of nodeName

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

    Ogre::Vector3 getNodePosition();  // retrieves the value of nodePosition
    void setNodePosition(Ogre::Vector3 set);  // sets the value of nodePosition

//    bool loadModel();  // loads the 3D model from file specified in modelName
    
//    bool setupPhysics();  // sets up the physics object
    
    private:
    
    bool initialized;  // stores whether entity object has been initialized
        
    bool baseInitialized;  // stores whether or not the base class has been initialized.

    size_t entityID;  // stores the entity ID number to distinguish between entities
    
    std::string entityModelFileName;  // stores the file name of the 3d model

    std::string entityName;  // stores the name of the model object in the scene

    std::string entityNodeName;  // stores the name of the scene node

    OgreEntitySharedPtr model;  // stores 3d model

    OgreSceneNodeSharedPtr node;  // stores node 3d model is attached to

    Ogre::Vector3 nodePosition;  // stores the position of the node

    bool physicsSetup;  // stores whether the physics object needs setup
    
    bool modelNeedsLoaded;  // stores whether or not to load the model

    bool modelLoaded;  // stores whether the 3D model of the basketball has been loaded
    
};

#endif

