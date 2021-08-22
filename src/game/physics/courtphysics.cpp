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
#ifdef _ENABLE_BTOGRE

#include "entity/gameentity.h"

#include "physics/courtphysics.h"

courtPhysics::courtPhysics() = default;  // constructor

courtPhysics::~courtPhysics() = default;  // destructor

/*
bool physicsEngine::setupCourtPhysics()
{
    sharedPtr<gameState> gameS = gameState::Instance();

    courtStateVec courtInstance = gameS->getCourtInstance();
    btRigidBody *courtBody;
    btScalar mass = 0;
    btVector3 inertia, inertia2;
    inertia = btVector3(0,0,0);

    //Create the ground shape.
    BtOgre::StaticMeshToShapeConverter converter(courtInstance.at(0).getModel());
//    courtShape = converter.createTrimesh();
    courtShape = converter.createBox();
//    courtShape = new btStaticPlaneShape(btVector3(0,1,0),1);
//    courtShape->;
//s    courtShape->
    //Create MotionState (no need for BtOgre here, you can use it if you want to though).
//    courtBodyState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,-25,0)));
    courtBodyState = new BtOgre::RigidBodyState(courtInstance[0].getNode());
//    courtBodyState = new BtOgre::RigidBodyState(courtInstance.at(0).getNode());
    btRigidBody::btRigidBodyConstructionInfo info(mass,courtBodyState,courtShape,inertia);  //motion state would actually be non-null in most real usages
    info.m_restitution = 1.0f;
    info.m_friction = 15.5f;

    //Create the Body.
//    courtBody = new btRigidBody(0, courtBodyState, courtShape, btVector3(0,0,0));
    courtBody = new btRigidBody(info);

    courtInstance[0].setPhysBody(courtBody);
    world->addRigidBody(courtInstance[0].getPhysBody(), COL_COURT, courtCollidesWith);
//    world->addRigidBody(courtBody);
//    courtInstance[0].getPhysBody()->setActivationState(ACTIVE_TAG);

    gameS->setCourtInstance(courtInstance);

    return true;
}

bool physicsEngine::setupHoopPhysics()  // sets up physics for the hoop
{
//    courtState *courtS = courtState::Instance();
    //gameState *gameS = gameState::Instance();
    sharedPtr<gameState> gameS = gameState::Instance();

    hoopStateVec hoopInstance = gameS->getHoopInstance();
    btRigidBody *hoopBody;
    btScalar mass = 0;
    btVector3 inertia, inertia2;
    inertia = btVector3(0,0,0);

    size_t x = 0;
    while (x<hoopInstance.size())
    {
        btCollisionShape *hoopShape;
        BtOgre::RigidBodyState *hoopBodyState;

        //Create the ground shape.
        BtOgre::StaticMeshToShapeConverter converter(hoopInstance.at(x).getModel());
    //    courtShape = converter.createTrimesh();
        hoopShape = converter.createBox();
    //    courtShape = new btStaticPlaneShape(btVector3(0,1,0),1);
    //    courtShape->;
    //s    courtShape->
        //Create MotionState (no need for BtOgre here, you can use it if you want to though).
    //    courtBodyState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,-25,0)));
        hoopBodyState = new BtOgre::RigidBodyState(hoopInstance[x].getNode());
    //    courtBodyState = new BtOgre::RigidBodyState(courtInstance.at(0).getNode());
        btRigidBody::btRigidBodyConstructionInfo info(mass,hoopBodyState,hoopShape,inertia);  // motion state would actually be non-null in most real usages
        info.m_restitution = 1.0f;
        info.m_friction = 15.5f;

        //Create the Body.
    //    courtBody = new btRigidBody(0, courtBodyState, courtShape, btVector3(0,0,0));
        hoopBody = new btRigidBody(info);

        hoopInstance[x].setPhysBody(hoopBody);
    //    world->addRigiBody(courtInstance[0].getPhysBody(), COL_COURT, courtCollidesWith);
        world->addRigidBody(hoopBody, COL_HOOP, hoopCollidesWith);
        ++x;
    }
    gameS->setHoopInstance(hoopInstance);

    return (true);
}*/
#endif
