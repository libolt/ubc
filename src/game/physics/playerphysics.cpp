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

#include "utilities/conversion.h"
#include "components/gamecomponents.h"
#include "entity/gameentity.h"
/*#include "state/basketballstate.h"
#include "state/courtstate.h"
#include "state/hoopstate.h"
#include "state/playerstate.h"
#include "state/teamstate.h"
#include "engine/physicsengine.h"*/
#include "physics/playerphysics.h"
#include "utilities/logging.h"
#include "utilities/comparison.h"
  
playerPhysics::playerPhysics()  // constructor
{
//    physicsSetup = false;
//    stateSet = false;
}

playerPhysics::~playerPhysics()  // destructor
{
}

/*bool playerPhysics::getPhysicsSetup()  // retrieves the value of physicsSetup
{
    return (physicsSetup);
}
void playerPhysics::setPhysicsSetup(bool set)  // sets the value of physicsSetup
{
    physicsSetup = set;
}

bool playerPhysics::getStateSet()  // retrieves the value of stateSet
{
    return (stateSet);
}
void playerPhysics::setStateSet(bool set)  // sets the value of stateSet
{
    stateSet = set;
}

bool playerPhysics::setupState()  // sets up state of player physics
{
    if (setupPhysics())
    {
        physicsSetup = true;
        return (true);
    }
    return (false);
}

bool playerPhysics::setupPhysics()  // sets up playerPhysics
{
//    exit(0);
    conversionSharedPtr convert ;
    sharedPtr<gameState> gameS = gameState::Instance();
    sharedPtr<physicsEngine> physEngine = physicsEngine::Instance();

    teamStateVec activeTeamInstance = getGameS()->getActiveTeamInstance();
    btDynamicsWorld *world;
    for (size_t x=0; x<activeTeamInstance.size();++x)
    {
        playerStateVec activePlayerInstance = activeTeamInstance[x].getActivePlayerInstance();

        btRigidBody *playerBody;
        btCollisionShape *playerShape;
        BtOgre::RigidBodyState *playerBodyState;

        logMsg("activePlayerInstance.size = " +convert->toString(activePlayerInstance.size()));

        // loops through physics objects for all players
        size_t i = 0;
        size_t j = 0;
        sizeTVec activeID = activeTeamInstance[x].getActivePlayerID();

//      for (size_t i=0; i<activePlayerInstance.size(); ++i)
        while (i<activePlayerInstance.size())
        {
            logMsg("Converting Mesh to Shape");
//                    exit(0);
            // create shape
            logMsg("Converting " +activePlayerInstance[i].getPlayerName() +"'s Mesh");
            BtOgre::StaticMeshToShapeConverter converter(activePlayerInstance[i].getModel());

            logMsg("Creating capsule");
            playerShape = converter.createCapsule();

            // calculates inertia
            btScalar mass = 1;
            btVector3 inertia, inertia2;
            inertia = btVector3(0,0,0);
            logMsg("Calculating local inertia");
            playerShape->calculateLocalInertia(mass, inertia);

            //Create BtOgre MotionState (connects Ogre and Bullet).
        //    BtOgre::RigidBodyState *bodyState = new BtOgre::RigidBodyState(pInstance[2].getNode());

            logMsg("Creating Body State");
            playerBodyState = new BtOgre::RigidBodyState(activePlayerInstance[i].getNode());
//        playerBodyState.at(i) = new btDefaultMotionState(btform(btQuaternion(0,0,0,1),btVector3(10.0f,-13.5f,380.0f)));
            //Create the Body.
    //        playerBody.at(i) = new btRigidBody(mass, playerBodyState.at(i), playerShape.at(i), inertia);
            logMsg("Creating Rigid Body");
            playerBody = new btRigidBody(mass, playerBodyState, playerShape, inertia);
     //       playerBody->setActivationState(DISABLE_DEACTIVATION);

            logMsg("Setting PhysBody");
            activePlayerInstance[i].setPhysBody(playerBody);
    //        world->addRigidBody(playerBody.at(i));
            if (x == 0)
            {
                logMsg("Setting Team 0 Player  Activation State");
                //activePlayerInstance[i].getPhysBody()->setActivationState(DISABLE_SIMULATION);
                logMsg("team = " + convert->toString(x));

                logMsg("Adding Rigid Body to world");
                world = physEngine.getWorld();
                size_t team1CollidesWith = physEngine.getTeam1CollidesWith();
                world->addRigidBody(activePlayerInstance[i].getPhysBody(), COL_TEAM1, team1CollidesWith);
                physEngine.setWorld(world);

    //          world->addRigidBody(pInstance[i].getPhysBody());
            }
            else if (x == 1)
            {
                logMsg("Setting Team 1 Player  Activation State");
             //   activePlayerInstance[i].getPhysBody()->setActivationState(DISABLE_SIMULATION);
                logMsg("team = " + convert->toString(x));

                logMsg("Adding Rigid Body to world");
                world = physEngine.getWorld();
                size_t team2CollidesWith = physEngine.getTeam2CollidesWith();
                world->addRigidBody(activePlayerInstance[i].getPhysBody(), COL_TEAM2, team2CollidesWith);
                physEngine.setWorld(world);
    //          world->addRigidBody(pInstance[i].getPhysBody());

            }
            else
            {
            }
            i++;
        }
//        exit(0);
        activeTeamInstance[x].setActivePlayerInstance(activePlayerInstance);
    }
//  activePlayerInstance[0].getPhysBody()->translate(btVector3 (0,1,0));
//    playerShape.push_back(*shape);
    for (int x=0;x<2; ++x)
    {
        playerStateVec activePlayerInstance = activeTeamInstance[x].getActivePlayerInstance();

        logMsg("activePlayerInstance.size = " + convert->toString(activePlayerInstance.size()));
    }
    getGameS()->setActiveTeamInstance(activeTeamInstance);   // stores all the changes to the activeTeamInstance
//    exit(0);
    return true;
}
*/

void playerPhysics::update()  // updates the player physics object
{
    std::string func = "playerPhysics::update()";
    logMsg(func +" begin");
//exit(0);
    logMsg(func +" end");
//    exit(0);
}

void playerPhysics::updatePosition()  // updates the position of player objecgts
{
    conversionSharedPtr convert ;
//    sharedPtr<gameState> gameS = gameState::Instance();
    comparison compare;
    std::string func = "playerPhysics::updatePosition()";
    logMsg(func +" begin");
    exit(0);
//    int activeBBallInstance = getGameS()->getActiveBBallInstance();

//    teamTypes teamWithBall = getGameS()->getTeamWithBall();
    int playerWithBall;

    teamEntityMSharedPtr activeTeamInstance = getGameInstance()->getComponent()->getActiveTeamInstance();
    playerEntityVecMSharedPtr activePlayerInstance;
    basketballEntityMSharedPtr basketballInstance = getGameInstance()->getComponent()->getBasketballInstance();

    // checks to see if player positions need updated
    size_t z = 0;
    while (z < activeTeamInstance.size())
    {
/*TS        activePlayerInstance.push_back(activeTeamInstance[z]->getActivePlayerInstance());
        size_t y = 0;
        while (y < activePlayerInstance[z].size())
        {
            int humanInstance = -1;
            if (activeTeamInstance[z]->getHumanControlled())
            {
                logMsg("phys update human == " +convert->toString(activeTeamInstance[z]->getHumanPlayer()));
                humanInstance = activeTeamInstance[z]->getHumanPlayer();

            }
            if (y != humanInstance && !activePlayerInstance[z][y]->getCourtPositionChanged())
            {
                btTransform transform = activePlayerInstance[z][y]->getPhysBody()->getWorldTransform();
                btVector3 physPos = transform.getOrigin();

                Ogre::Vector3 courtPosition = activePlayerInstance[z][y]->getCourtPosition();
                Ogre::Vector3 newCourtPosition;
                logMsg("comparing court position");
                if (!compare.OgreVector3ToBTVector3(courtPosition,physPos))
                {
                    newCourtPosition = compare.OgreVector3ToBTVector3Result(courtPosition,physPos);
                }

                logMsg("court position = " +convert->toString(courtPosition));
                logMsg("new court position = " +convert->toString(newCourtPosition));
                if (activePlayerInstance[z][y]->getStartPosReached())
                {
                    if (newCourtPosition.x != 0 && newCourtPosition.y != 0 && newCourtPosition.z != 0)
                    {
                        activePlayerInstance[z][y]->setCourtPositionChanged(true);
                        activePlayerInstance[z][y]->setCourtPositionChangedType(PHYSICSCHANGE);
                        activePlayerInstance[z][y]->setNewCourtPosition(newCourtPosition);
                    }
                }
            }
            ++y;
        }
        activeTeamInstance[z]->setActivePlayerInstance(activePlayerInstance[z]);
TS*/
    ++z;
    }
    getGameInstance()->getComponent()->setActiveTeamInstance(activeTeamInstance);
}

bool playerPhysics::jump(teamTypes teamType, int playerID)  // calculates and executes player jumping in the air
{
    conversionSharedPtr convert ;
//    sharedPtr<gameState> gameS = gameState::Instance();

    courtEntityMSharedPtr  courtInstance = getGameInstance()->getComponent()->getCourtInstance();
    teamEntityMSharedPtr activeTeamInstance = getGameInstance()->getComponent()->getActiveTeamInstance();
/*TS    playerStateVecSharedPtr activePlayerInstance = getActiveTeamInstance()[teamType]->getActivePlayerInstance();
    sizeTVec activePlayerID = activeTeamInstance[teamType]->getActivePlayerID();
    btVector3 playerJumpBeginPos;
    btVector3 playerJumpEndPos;
    size_t x = 0;
    size_t y = 0;
    while (x<activePlayerInstance.size())
    {
//        while (y<activePlayerID.size())
//        {
//        if (activePlayerInstance[x].getPlayerID() == activePlayerID[y])
        if (activePlayerInstance[x]->getID() == playerID)
        {
            bool jumpSet = activePlayerInstance[x]->getJumpSet();
            bool jumpComplete = activePlayerInstance[x]->getJumpComplete();
            if (!jumpComplete)
            {
                if (!jumpSet)
                {
                    playerJumpBeginPos = BtOgre::Convert::toBullet(activePlayerInstance[x]->getNode()->getPosition());
                    playerJumpEndPos = playerJumpBeginPos;
                    playerJumpEndPos.setY(playerJumpEndPos.getY() + 5);
                    jumpSet = true;
                }
                else
                {
                    playerJumpBeginPos = BtOgre::Convert::toBullet(activePlayerInstance[x]->getJumpBeginPos());
                    playerJumpEndPos = BtOgre::Convert::toBullet(activePlayerInstance[x]->getJumpEndPos());
                // activePlayerInstance[x].getPhysBody()->setLinearVelocity(btVector3(-35,0,0));
                    activePlayerInstance[x]->getPhysBody()->forceActivationState(ACTIVE_TAG);
                    activePlayerInstance[x]->getPhysBody()->translate(btVector3(0,0.5,0));//, btVector3(-35,0,0));
                }
                btTransform transform = activePlayerInstance[x]->getPhysBody()->getWorldTransform();
                btVector3 playerCurrentPos = transform.getOrigin();
                if (playerCurrentPos.getY() >= playerJumpEndPos.getY())
                {
                    jumpComplete = true;
                }
            }
            else
            {
                btTransform courtTransform = courtInstance[0]->getPhysBody()->getWorldTransform();
                btVector3 courtPos = courtTransform.getOrigin();
                btTransform playerTransform = activePlayerInstance[x]->getPhysBody()->getWorldTransform();
                btVector3 playerPos = playerTransform.getOrigin();
                logMsg("playerPos.getY = " +convert->toString(playerPos.getY()));
                logMsg("courtPos.getY = " +convert->toString(courtPos.getY()));
                if (playerPos.getY() > courtPos.getY() + 3.0)
                {
                    activePlayerInstance[x]->getPhysBody()->forceActivationState(ACTIVE_TAG);
                }
                else
                {
//                    exit(0);
                    activePlayerInstance[x]->getPhysBody()->setLinearVelocity(btVector3(0,0,0));
                    activePlayerInstance[x]->getPhysBody()->setActivationState(ISLAND_SLEEPING);
                    activePlayerInstance[x]->setShootBlock(false);
                    jumpSet = false;
                    jumpComplete = false;
                }
//                activePlayerInstance[x].getPhysBody()->setGravity(btVector3(0,-9.8,0));
//                activePlayerInstance[x].getPhysBody()->applyGravity();
//                activePlayerInstance[x].getPhysBody()->setLinearVelocity(btVector3(0,-.5,0));
//                activePlayerInstance[x].setShootBlock(false);
 //               exit(0);
            }
            activePlayerInstance[x]->setJumpSet(jumpSet);
            activePlayerInstance[x]->setJumpComplete(jumpComplete);
            activePlayerInstance[x]->setJumpBeginPos(BtOgre::Convert::toOgre(playerJumpBeginPos));
            activePlayerInstance[x]->setJumpEndPos(BtOgre::Convert::toOgre(playerJumpEndPos));

             logMsg("JUMP!");
          //  exit(0);
        }
//            ++y;
//        }
        ++x;
    }
    activeTeamInstance[teamType]->setActivePlayerInstance(activePlayerInstance);
    setActiveTeamInstance(activeTeamInstance);
    getActiveTeamInstance()[teamType]->getActivePlayerInstance()[playerID]->getPhysBody()->setLinearVelocity(btVector3(15,-15,0));
TS*/
    return (true);
}

bool playerPhysics::shootBasketball(teamTypes teamType, int playerID)  // calculates and executes basketball being shot
{

    // FIXME! Disabled until I can do a proper rewrite
/*    conversionSharedPtr convert ;
//    sharedPtr<gameState> gameS = gameState::Instance();

    comparison compare;
    courtStateVec courtInstance = getCourtInstance();
    hoopStateVec hoopInstance = getHoopInstance();
    basketballStateVec basketballInstance = getBasketballInstance();
    teamStateVecSharedPtr activeTeamInstance = getActiveTeamInstance();
    playerStateVecSharedPtr activePlayerInstance = activeTeamInstance[teamType]->getActivePlayerInstance();

    int activeBBallInstance = getActiveBBallInstance();

//    Ogre::Vector3 playerPos = activePlayerInstance[x].getNode()->getPosition();
//    Ogre::Vector3 basketballPos = basketballInstance[activeBBallInstance].getNode()->getPosition();

             
    size_t x = 0;
    while (x<activePlayerInstance.size())
    {
        
        if (activePlayerInstance[x]->getID() == playerID)
        {
            shotSet = activePlayerInstance[x]->getShotSet();
            shotComplete = activePlayerInstance[x]->getShotComplete();
            if (!shotComplete)
            {
                int hoop = activeTeamInstance[teamType]->getHoop();
                logMsg("Hoop number = " +convert->toString(hoop));
                btTransform hoopTransform = hoopInstance[hoop].getPhysBody()->getWorldTransform();
                btVector3 hoopPos = hoopTransform.getOrigin();

                btTransform basketballTransform = basketballInstance[activeBBallInstance].getPhysBody()->getWorldTransform();
                btVector3 basketballPos = basketballTransform.getOrigin();

                btTransform playerTransform = activePlayerInstance[x]->getPhysBody()->getWorldTransform();
                btVector3 playerPos = playerTransform.getOrigin();
                float hoopBasketballDistanceX = 0;
                float hoopBasketballDistanceY = 0;
                float hoopBasketballDistanceZ = 0;

                if (activeTeamInstance[teamType]->getPlayerWithBallDribbling())
                {
                    activeTeamInstance[teamType]->setPlayerWithBallDribbling(false);
                   // exit(0);
                    setActiveTeamInstance(activeTeamInstance);
                }       

                if (!shotSet)
                {
                    
                    if (!beginShotPosSet)
                    {
                        if (activePlayerInstance[x]->getDirection() == RIGHT)
                        {
                            basketballPos.setX(playerPos.getX() + 3);
                            basketballPos.setY(playerPos.getY() + 5);
                            basketballPos.setZ(playerPos.getZ());
                        }
                        else if (activePlayerInstance[x]->getDirection() == LEFT)
                        {
                            basketballPos.setX(playerPos.getX() - 3);
                            basketballPos.setY(playerPos.getY() + 5);
                            basketballPos.setZ(playerPos.getZ());

                        }
                        else if (activePlayerInstance[x]->getDirection() == UP)
                        {
                            basketballPos.setX(playerPos.getX() - 3);
                            basketballPos.setY(playerPos.getY() + 5);
                            basketballPos.setZ(playerPos.getZ() + 3);

                        }
                        else if (activePlayerInstance[x]->getDirection() == DOWN)
                        {
                            basketballPos.setX(playerPos.getX() - 3);
                            basketballPos.setY(playerPos.getY() + 5);
                            basketballPos.setZ(playerPos.getZ() - 3);

                        }
                        else
                        {
                        }
                        beginShotPos = basketballPos;
                        beginShotPosSet = true;
                        logMsg("beginShotPosSet");
                    }

                    // sets end position of the shot
                    if (!endShotPosSet)
                    {
                        if (hoopPos.getX() < 0)
                        {
                            endShotPos.setX(hoopPos.getX() - 35);
                        }
                        else
                        {
                            endShotPos.setX(hoopPos.getX());
                            float hoopPosX = hoopPos.getX();
                            logMsg("hoopPosX = " +convert->toString(hoopPosX));
                        }

                        endShotPos.setY(hoopPos.getY() + 5);
                        endShotPos.setZ(hoopPos.getZ() - 2);
                        endShotPos.setX(hoopPos.getX() - 5);
                        endShotPosSet = true;
                        logMsg("endShotPosSet");
                    }
                    // sets the midPoint of the shot
                    if (!midShotPosSet)
                    {
                        midShotPos.setY(endShotPos.getY() +8);
//                        if (midShotPos.getY() < 0)
//                        {
//                            midShotPos.setY(-1 * (midShotPos.getY()));
//                        }
                        midShotPosSet = true;
                        logMsg("midShotPos y = " +convert->toString(midShotPos.getY()));
                        logMsg("midShotPosSet");
                    }

                    if (beginShotPosSet && midShotPosSet && endShotPosSet)
                    {
                        hoopBasketballDistanceX = endShotPos.getX() - basketballPos.getX();
                        hoopBasketballDistanceY = endShotPos.getY() - basketballPos.getY();
                        hoopBasketballDistanceZ = endShotPos.getZ() - basketballPos.getZ();
                        logMsg("X distance between hoop and basketball" +convert->toString(hoopBasketballDistanceX));
    //                    exit(0);
                        beginShotDistance.setX(hoopBasketballDistanceX);
                        beginShotDistance.setY(hoopBasketballDistanceY);
                        beginShotDistance.setZ(hoopBasketballDistanceZ);
//                        exit(0);

                        midShotPos.setX(beginShotDistance.getX()/2);
    //                    maxShotHeight = basketballPos.getY() + 15;
                        
                    }
                    shotSet = true;
                }
                else
                {
                //    exit(0);
                    
                }
                
                if (hoopBasketballDistanceX > -1 && hoopBasketballDistanceX < 1 && shotSet)
                {
                    shotComplete = true;
                    logMsg("hoopBasketballDistanceX = " +convert->toString(hoopBasketballDistanceX));
//                    exit(0);
                }
            }
            else
            {
                if ( shotSet)
                {
                    float hoopBasketballDistanceX = 0;
                    float hoopBasketballDistanceZ = 0;
                    float beginXPoint = 0;
                    float midXPoint = 0;
                    float endXPoint = 0;
                    float basketballMidXDistance = 0;
                    float force = 0;
                    float yForce = 0;
                    float zForce = 0;
                    float maxForce = 0;
                    float maxYForce = 1750;
                    float maxZForce = 1700;
                    btVector3 hoopDimMin;
                    btVector3 hoopDimMax;
                    float hoopXMin = 0;
                    float hoopXMax = 0;
                    float vecX =  36*(cos(138));
                    int hoop = activeTeamInstance[teamType]->getHoop();
                    hoopInstance[hoop].getPhysBody()->getAabb(hoopDimMin,hoopDimMax);
                    hoopXMin = hoopDimMin.getX();
                    hoopXMax = hoopDimMax.getX();
                    logMsg("hoop dimensions XMin = " +convert->toString(hoopXMin) +" XMax = " +convert->toString(hoopXMax));
                    btTransform basketballTransform = basketballInstance[activeBBallInstance].getPhysBody()->getWorldTransform();
                    btVector3 basketballPos = basketballTransform.getOrigin();
                    beginXPoint = beginShotPos.getX();
                    midXPoint = beginShotPos.getX() + ((endShotPos.getX() - beginShotPos.getX())/2);
                    endXPoint = endShotPos.getX();
                    hoopBasketballDistanceX = endShotPos.getX() - basketballPos.getX();
                    hoopBasketballDistanceZ = endShotPos.getZ() - basketballPos.getZ();
                    basketballMidXDistance = midXPoint - basketballPos.getX();
                    // if (hoopBasketballDistanceX > 0)
                    maxForce = beginShotDistance.getX()*10;
                    if (basketballMidXDistance > 0)
                    {
                        //yForce = ((maxYForce / 50) *(100 - hoopBasketballDistanceX))*3.5;
                        //yForce = ((maxYForce / 50) *(midXPoint))*(hoopBasketballDistanceX/1.0);
                        //yForce = (beginShotDistance.getX())/2.0;
                        force = hoopBasketballDistanceX*(100 - hoopBasketballDistanceX);
                        //yForce = force/1.5;
                        yForce = maxYForce*(hoopBasketballDistanceX/beginShotDistance.getX());
                    }
                    else
                    {
                        
                        force = hoopBasketballDistanceX*(100 - hoopBasketballDistanceX);
                        //yForce = force/1.5;
                        //yForce = force/2;
                        yForce = maxYForce*(hoopBasketballDistanceX/beginShotDistance.getX());

                    //    exit(0);
                      //  yForce = -20;
                    }
                    if (hoopBasketballDistanceZ > 1)
                    {
                        zForce = maxZForce*(hoopBasketballDistanceZ/beginShotDistance.getZ());
                    }
                    else if (hoopBasketballDistanceZ < 1)
                    {
                        zForce = (maxZForce*(hoopBasketballDistanceZ/beginShotDistance.getZ()))*(-1);
                    }
                    else
                    {
                        zForce = 0;
                    }
                    logMsg("hoopBasketballDistanceX = " +convert->toString(hoopBasketballDistanceX));
                    logMsg("hoopBasketballDistanceZ = " +convert->toString(hoopBasketballDistanceZ));
                    logMsg("beginShotDistance.getX() = " +convert->toString(beginShotDistance.getX()));
                    logMsg("beginShotDistance.getZ() = " +convert->toString(beginShotDistance.getZ()));
                    logMsg("yDistanceForce = " +convert->toString(yForce));
                    logMsg("zDistanceForce = " +convert->toString(zForce));
                    logMsg("beginXPointDistance = " +convert->toString(beginXPoint));
                    logMsg("midXPointDistance = " +convert->toString(midXPoint));
                    logMsg("endXPointDistance = " +convert->toString(endXPoint));
                    logMsg("basketballMidXDistance = " +convert->toString(basketballMidXDistance));
                    logMsg("vecX = " +convert->toString(vecX));
                    logMsg("forceDistance = " +convert->toString(force));


                    
                    forceToApply.setX(30);
                    //basketballInstance[activeBBallInstance].getPhysBody()->applyForce(forceToApply,btVector3(1,1,1));
                  //  basketballInstance[activeBBallInstance].getPhysBody()->applyForce(btVector3(beginShotDistance.getX()*2.5,yForce,0.0),btVector3(1,1,1));
                   
                    basketballInstance[activeBBallInstance].getPhysBody()->applyForce(btVector3(force,yForce,zForce),btVector3(1,1,1));
                    
                  //basketballInstance[activeBBallInstance].getPhysBody()-> setAngularVelocity(btVector3(3.0,5.0,0));
                    basketballInstance[activeBBallInstance].getPhysBody()->setGravity(btVector3(-9.8,0,0));
                    basketballInstance[activeBBallInstance].getPhysBody()->applyGravity();
                    logMsg("bballForce");
                    logMsg("player dribbling == " +convert->toString(activeTeamInstance[teamType]->getPlayerWithBallDribbling()));

                }
            }

           activePlayerInstance[x]->setShotSet(shotSet);
           activePlayerInstance[x]->setShotComplete(shotComplete);
        }
        
        ++x;
    }
    logMsg("playerdribble = " +convert->toString(activeTeamInstance[teamType]->getPlayerWithBallDribbling()));
    activeTeamInstance[teamType]->setActivePlayerInstance(activePlayerInstance);
    getGameS()->setActiveTeamInstance(activeTeamInstance);
   // getGameS()->getActiveTeamInstance()[teamType].getPlayerInstance()[playerID].getPhysBody()->setLinearVelocity(btVector3(15,-15,0));
  //  exit(0);
    getGameS()->setBasketballInstance(basketballInstance);
    */
    return (true);

}

