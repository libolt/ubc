/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean   *
 *   libolt@libolt.net   *
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

#ifndef _COURTSTATE_H_
#define _COURTSTATE_H_

#include "Ogre.h"

#include "BtOgrePG.h"
#include "BtOgreGP.h"
#include "BtOgreExtras.h"
#include "state/state.h"
#include "entity/entity.h"

class courtState : public state, public entity
{
    public:

        courtState();   // constructor
        ~courtState();  // destructor

/*        std::string getModelName();  // retrieves the value of modelName
        void setModelName(std::string set);  // sets the value of modelName

        Ogre::Entity *getModel();  // retrieves the value of model
        void setModel(Ogre::Entity *set);  // sets the value of model

        Ogre::SceneNode *getNode();  // retrieves the value of node
        void setNode(Ogre::SceneNode *set);  // sets the value of node

        btRigidBody *getPhysBody();	// retrieves the value of physBody
        void setPhysBody(btRigidBody *set);	// sets the value physBody 

        Ogre::Vector3 getNodePosition();  // retrieves the value of nodePosition
        void setNodePosition(Ogre::Vector3 set);  // sets the value of nodePosition
*/

//        bool getStateSet();  // retrieves the value of stateSet
//        void setStateSet(bool set);  // sets the value of stateSet
        
        // loads the 3D Model and attaches it to the node as well as sets coordinates
//        bool loadModel();

    private:

/*        std::string modelName;   // stores the file name of the 3D Model

        Ogre::Entity *model;    // stores the 3D Model representing the court

        Ogre::SceneNode *node;  // stores the node the 3D Model is attached to

        Ogre::Vector3 nodePosition;  // stores the position of the node
        // stores the physics object that represents the player
        btRigidBody *physBody;
*/
//        bool stateSet;  // if true then the basketball court state has been set

};

#endif // COURTSTATE_H_INCLUDED
