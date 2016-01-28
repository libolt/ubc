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
 *                                        m                                *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   5s 9 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _HOOP_H_
#define _HOOP_H_

#include "Ogre.h"
#include "BtOgrePG.h"
#include "BtOgreGP.h"
#include "BtOgreExtras.h"

#include "state/state.h"
#include "entity/hoopentity.h"
#include "physics/hoopphysics.h"

//class state;
//class hoopEntity;
//class hoopPhysics;

class hoopState : public state, public hoopEntity, public hoopPhysics
{
    public:

    hoopState(); // constructor
    ~hoopState();  // destructor

/*    std::string getModelName();  // retrieves the value of modelName
    void setModelName(std::string set);  // sets the value of modelName

    std::string getEntityName();  // retrieves the value of entityName
    void setEntityName(std::string set);  // sets the value of entityName

    std::string getNodeName();  // retrieves the value of nodeName
    void setNodeName(std::string set);  // sets the value of nodeName

    Ogre::Entity *getModel();  // retrieves the value of model	
    void setModel(Ogre::Entity *set);  // sets the value of model

    Ogre::SceneNode *getNode();  // retrieves the value of node
    void setNode(Ogre::SceneNode *set);  // sets the value of node

    btRigidBody *getPhysBody();	 // retrieves the value of physBody 
    void setPhysBody(btRigidBody *set);  // sets the value of physBody 

    bool getStateSet();  // retrieves the value of stateSet
    void setStateSet(bool set);  // sets the value of stateSet
        
    bool loadModel();  // loads the 3D Model and attaches it to the node as well as sets coordinates
*/
    private:

/*    std::string modelName;  // stores the file name of the 3D Model
    std::string entityName;  // stores the name of the model object in the scene
    std::string nodeName;  // stores the name of the scene node
    Ogre::Entity *model;  // stores the 3D Model representing the first hoop

    Ogre::SceneNode *node;  // stores the node the 3D Model is attached to

    btRigidBody *physBody;  // stores the physics object representing the hoop

    bool stateSet;  // if true then the hoop state has been set
*/
};

#endif
