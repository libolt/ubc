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

//#include "Ogre.h"
#include "utilities/conversion.h"
#include "ai/ai.h"
#include "ai/playersteerplugin.h"
#include "ai/playersteer.h"
#include "components/courtcomponents.h"
#include "components/gamecomponents.h"
#include "components/playercomponents.h"
#include "components/teamcomponents.h"
#include "data/playergamedata.h"
#include "data/teamdata.h"
#include "entity/courtentity.h"
#include "entity/playerentity.h"
#include "entity/teamentity.h"
#include "flags/playerflags.h"
#include "flags/teamflags.h"
#include "entity/gameentity.h"
#include "utilities/logging.h"
#include "utilities/typedefs.h"

playerSteerPlugin::playerSteerPlugin()  // constructor
{
    m_PlayerCountA = 0;
    m_PlayerCountB = 0;
    teamWithBall = NOTEAM;
}
playerSteerPlugin::~playerSteerPlugin() = default;  // destructor

gameEntitySharedPtr playerSteerPlugin::getGameInstance() const  // retrieves the value of gameInstance
{
    return (gameInstance);
}
void playerSteerPlugin::setGameInstance(const gameEntitySharedPtr &set)  // sets the value of gameInstance
{
    gameInstance = set;
}

basketballEntityMSharedPtr playerSteerPlugin::getActiveBasketballInstance() const  // retrieves the value of activeBasketballInstance
{
    return (activeBasketballInstance);
}
void playerSteerPlugin::setActiveBasketballInstance(const basketballEntityMSharedPtr &set)  // sets the value of activeBasketballInstance
{
    activeBasketballInstance = set;
}

courtEntityMSharedPtr playerSteerPlugin::getActiveCourtInstance() const  // retrieves the value of activeCourtInstance
{
    return (activeCourtInstance);
}
void playerSteerPlugin::setActiveCourtInstance(const courtEntityMSharedPtr &set)  // sets the value of activeCourtInstance
{
    activeCourtInstance = set;
}

teamEntityMSharedPtr playerSteerPlugin::getActiveTeamInstance() const  // retrieves the value of activeTeamInstance
{
    return (activeTeamInstance);
}
void playerSteerPlugin::setActiveTeamInstance(const teamEntityMSharedPtr &set)  // sets the value of activeTeamInstance
{
    activeTeamInstance = set;
}

teamTypes playerSteerPlugin::getTeamWithBall() const  // retrieves the value of teamWithBall
{
    return (teamWithBall);
}
void playerSteerPlugin::setTeamWithBall(const teamTypes &set)  // sets the value of teamWithBall
{
    teamWithBall = set;
}

std::string playerSteerPlugin::getHumanPlayer() const  // retrieves the value of the humanPlayer
{
    return (humanPlayer);
}
void playerSteerPlugin::setHumanPlayer(const std::string &set)  // sets the value of human player
{
    humanPlayer = set;
}

void playerSteerPlugin::open()  // opens the plugin
{
    AISystemSharedPtr AI = gameInstance->getComponent()->getAI();
    conversionSharedPtr convert ;
//    sharedPtr<gameState> gameS = gameState::Instance();

//    courtStateVec courtInstance = gameS->getCourtInstance();
//    teamStateVecSharedPtr activeTeamInstance = gameS->getActiveTeamInstance();
/*    playerStateVec team0ActivePlayerInstance = activeTeamInstance[0].getActivePlayerInstance();
    playerStateVec team1ActivePlayerInstance = activeTeamInstance[1].getActivePlayerInstance();
    std::vector<int> team0ActivePlayerID = activeTeamInstance[0].getActivePlayerID();
    std::vector<int> team1ActivePlayerID = activeTeamInstance[1].getActivePlayerID();
*/
//    std::vector <std::unordered_map<std::string, playerStateSharedPtr> > activePlayerInstance;
//    std::unordered_map<std::string, playerStateSharedPtr> activePlayerInstance;
    playerEntityMSharedPtr activePlayerInstance;
//    std::vector <std::unordered_map<std::string, playerStateSharedPtr> >::iterator activePlayerInstanceIT;
    playerSteerVecSharedPtr allPlayerSteers = AI->getAllPlayerSteers();
//    teamTypes teamWithBall;
    std::string func = "playerSteerPlugin::open()";
    logMsg(func +" begin");
    logMsg(func +" Opening playerSteer plugin");

    gameInstance = AI->getGameInstance();
    activeBasketballInstance = AI->getActiveBasketballInstance();
    activeCourtInstance = AI->getActiveCourtInstance();
    activeTeamInstance = AI->getActiveTeamInstance();
    teamWithBall = AI->getTeamWithBall();
    humanPlayer = AI->getHumanPlayer();

	// builds team 0 steering instances
    logMsg(func +" activeTeamInstance.size() == " +convert->toString(activeTeamInstance.size()));
//    exit(0);
//    if (activeTeamInstance.size() > 0)
    if (!activeTeamInstance.empty())
    {
        for (auto ATIIT : activeTeamInstance)
        {
            if (ATIIT.second->getFlag()->getActivePlayerInstancesCreated())
            {
                logMsg(func +" activePlayerInstances Created!");
    //            exit(0);
            }
            else
            {
                logMsg(func + " activePlayerInstances NOT Created!!");
                exit(0);
            }
            activePlayerInstance = ATIIT.second->getComponent()->getActivePlayerInstance();
            logMsg(func +" team name == " +ATIIT.second->getData()->getName());
            logMsg(func +" ATIIT.second->getComponent()->getActivePlayerInstance().size() == " +convert->toString(ATIIT.second->getComponent()->getActivePlayerInstance().size()));

    //        exit(0);
            logMsg(func +" for (auto ATIIT : getActiveTeamInstance())");
    /*        activePlayerInstance.insert(activePlayerInstance.begin(), ATIIT.second->getActivePlayerInstance());
            logMsg(func +" activePlayerInstance.size() == " +convert->toString(activePlayerInstance.size()));
    //        size_t y = 0;
    //        while (y < activePlayerInstance[x].size())
            logMsg(func +" AIIT.first == " +convert->toString(ATIIT.first));
            logMsg(func +" activePlayerInstance[ATIIT.first].size() == " +convert->toString(activePlayerInstance[1].size()));
    */

            for (auto APIIT : activePlayerInstance)
            {
                logMsg(func +" for (auto APIIT : activePlayerInstance[ATIIT.first])");
                playerSteerSharedPtr steer = APIIT.second->getComponent()->getSteer();
                bool steerInitialized = APIIT.second->getFlag()->getSteerInitialized();
                if (!steerInitialized)
                {
                    playerSteerSharedPtr tempSteer(new playerSteer);
                    steer = tempSteer;
//BASEREMOVAL                    steer->setGameS(gameInstan);
                    steerInitialized = true;
                }
            //      logMsg("Alive1");
                logMsg(" APIIT.first = " +convert->toString(APIIT.first));
                logMsg(" player position = " +convert->toString(APIIT.second->getGameData()->getCourtPosition()));
                steer->setPosition(convert->toOpenSteerVec3(APIIT.second->getGameData()->getCourtPosition()));
            //      steer.setPosition(OpenSteer::Vec3(0,0,0));
            //      logMsg("Alive2");

            //      steer->setID(x);
                logMsg(func +" ai->selectedVehicle = steer");
                AI->selectedVehicle = steer;
                logMsg(func +" APIIT.second->setSteer(steer);");
                APIIT.second->getComponent()->setSteer(steer);
                logMsg(func + " allPlayerSteers.push_back(APIIT.second->getSteer());");
                allPlayerSteers.push_back(APIIT.second->getComponent()->getSteer());
        //            ++y;
                logMsg(func +" allPlayerSteers.push_back(APIIT.second->getSteer());");
                APIIT.second->getComponent()->setSteer(steer);
                logMsg(func +" APIIT.second->setSteerInitialized(steerInitialized);");
                APIIT.second->getFlag()->setSteerInitialized(steerInitialized);
            }
            logMsg(func +" ATIIT.second->setActivePlayerInstance(activePlayerInstance);");
            ATIIT.second->getComponent()->setActivePlayerInstance(activePlayerInstance);
    //        ++x;
        }
    }
        //    exit(0);
/*	while (x<team0ActivePlayerInstance.size())
	{
//		logMsg("Alive0");
	    logMsg("team 0 steer!");

                playerSteer *steer = team0ActivePlayerInstance[x].getSteer();
        //		logMsg("Alive1");
                logMsg("x = " +convert->toString(x));
                logMsg("player position = " +convert->toString(team0ActivePlayerInstance[x].getCourtPosition()));
                steer->setPosition(convert->toOpenSteerVec3(team0ActivePlayerInstance[x].getCourtPosition()));
        //		steer.setPosition(OpenSteer::Vec3(0,0,0));
        //		logMsg("Alive2");

        //		steer->setID(x);
                ai->selectedVehicle = steer;
                team0ActivePlayerInstance[x].setSteer(steer);
                allPlayerSteers.push_back(team0ActivePlayerInstance[x].getSteer());
    //        logMsg("team 0 activePlayerInstance added =  " +convert->toString(x));

        ++x;
	}
//	exit(0);
	// builds team 1 steering instances

	logMsg("team 1 steer!");
	x = 0;
//	for (size_t x=0;x<team1ActivePlayerInstance.size();++x)
	while (x<team1ActivePlayerInstance.size())
	{
                playerSteer *steer = team1ActivePlayerInstance[x].getSteer();
                steer->setPosition(convert->toOpenSteerVec3(team1ActivePlayerInstance[x].getCourtPosition()));
        //		steer->setID(x);
                team1ActivePlayerInstance[x].setSteer(steer);
                allPlayerSteers.push_back(team1ActivePlayerInstance[x].getSteer());

        ++x;
	}
*/
    AI->setAllPlayerSteers(allPlayerSteers);	// stores the instances
//    logMsg("team 0 activePlayerInstance added =  " +convert->toString( ai->getAllPlayerSteers().size()));


	// create the court bounding box based off the meshes bbox
#ifdef BTOGRE_MYGUI_ENABLEd
    Ogre::AxisAlignedBox cbox = gameInstance->getComponent()->getCourtInstance()[0]->getComponent()->getModel()->getBoundingBox();
    Ogre::Vector3 cboxMin = cbox.getMinimum();
    Ogre::Vector3 cboxMax = cbox.getMaximum();

    OpenSteer::Vec3 courtBoxMin = convert->toOpenSteerVec3(cboxMin);
    OpenSteer::Vec3 courtBoxMax = convert->toOpenSteerVec3(cboxMax);

//    courtBBox = steeringAABBoxSharedPtr(new steering::AABBox( OpenSteer::Vec3(0,0,0), OpenSteer::Vec3(0,0,0)));
    courtBBox = std::make_shared<steering::AABBox>(OpenSteer::Vec3(0,0,0), OpenSteer::Vec3(0,0,0));
    courtBBox->setMin(courtBoxMin);
#endif
 /*           // Red goal
            m_TeamAGoal = new AABBox(Vec3(-21,0,-7), Vec3(-19,0,7));
            // Blue Goal
            m_TeamBGoal = new AABBox(Vec3(19,0,-7), Vec3(21,0,7));
            // Make a ball
            m_Ball = new Ball(m_bbox);
*/
        // Build team A

/*    m_PlayerCountA = 8;
    for(unsigned int i=0; i < m_PlayerCountA ; i++)
    {
        playerSteer *playerSteerTest = new playerSteer;
        ai->setSelectedVehicle(playerSteerTest);
        TeamA.push_back (playerSteerTest);
        m_AllPlayers.push_back(playerSteerTest);
    }
*/
    // Build Team B

/*    m_PlayerCountB = 8;
    for(unsigned int i=0; i < m_PlayerCountB ; i++)
    {
        playerSteer *playerSteerTest = new playerSteer;
        ai->setSelectedVehicle(playerSteerTest);
        TeamB.push_back (playerSteerTest);
        m_AllPlayers.push_back(playerSteerTest);
    }
    */
    // initialize camera
/*            OpenSteerDemo::init2dCamera (*m_Ball);
            OpenSteerDemo::camera.setPosition (10, OpenSteerDemo::camera2dElevation, 10);
            OpenSteerDemo::camera.fixedPosition.set (40, 40, 40);
            OpenSteerDemo::camera.mode = Camera::cmFixed;
            m_redScore = 0;
            m_blueScore = 0;
*/
    logMsg(func +" end");
}

void playerSteerPlugin::update(const float currentTime, const float elapsedTime)
{
    conversionSharedPtr convert ;
    playerEntityVecMSharedPtr activePlayerInstance;
//	exit(0);
    // update simulation of test vehicle
//    logMsg("team 0 activePlayerInstance size =  " +convert->toString(team0ActivePlayerInstance.size()));

// FIXME testing with one specific player for now

//    team1ActivePlayerInstance[3].getSteer()->update(currentTime, elapsedTime);

    for (const auto &ATIIT : gameInstance->getComponent()->getActiveTeamInstance())
    {
        activePlayerInstance.push_back(ATIIT.second->getComponent()->getActivePlayerInstance());
        for (const auto &APIIT : activePlayerInstance[ATIIT.first])
        {
/*FIXME!            if (APIIT.first != ATIIT.second->getHumanPlayer() && APIIT.second->getModelLoaded())
            {
//                exit(0);
//                logMsg("ATIIT.first = " +ATIIT.first +"APIIT.first = " +APIIT.first);
                APIIT.second->getSteer()->update(currentTime, elapsedTime);
            }*/
//            ++y;
        }
        
//        ++x;
    }
    
/*
//    for(unsigned int i=0;i<team0ActivePlayerInstance.size();i++)
    x = 0;
    while (x<team0ActivePlayerInstance.size())
    {
        if (x != activeTeamInstance[0].getHumanPlayer())
        {
            team0ActivePlayerInstance[4].getSteer()->update(currentTime, elapsedTime);
        }
        ++x;
    }

    x = 0;
//    for(unsigned int i=0;i<team1ActivePlayerInstance.size();i++)
    while (x<team1ActivePlayerInstance.size())
    {
        logMsg("team1steer.getHumanPlayer() ==" +convert->toString(activeTeamInstance[1].getHumanPlayer()));
        logMsg("player1SteerID == " +convert->toString(team1ActivePlayerInstance[x].getPlayerID()));
        activeTeamInstance[1].setHumanPlayer(1);
        if (x != activeTeamInstance[1].getHumanPlayer())
        {
            team1ActivePlayerInstance[x].getSteer()->update(currentTime, elapsedTime);
        }
        ++x;
    }*/

/*            m_Ball->update(currentTime, elapsedTime);

            if(m_TeamAGoal->InsideX(m_Ball->position()) && m_TeamAGoal->InsideZ(m_Ball->position()))
            {
                m_Ball->reset();	// Ball in blue teams goal, red scores
                m_redScore++;
            }
            if(m_TeamBGoal->InsideX(m_Ball->position()) && m_TeamBGoal->InsideZ(m_Ball->position()))
            {
                m_Ball->reset();	// Ball in red teams goal, blue scores
                    m_blueScore++;
            }
*/
}

void playerSteerPlugin::redraw (const float currentTime, const float elapsedTime)
{
/*
            // draw test vehicle
            for(unsigned int i=0; i < m_PlayerCountA ; i++)
                TeamA[i]->draw ();
            for(unsigned int i=0; i < m_PlayerCountB ; i++)
                TeamB[i]->draw ();
            m_Ball->draw();
            m_bbox->draw();
            m_TeamAGoal->draw();
            m_TeamBGoal->draw();
            {
                std::ostringstream annote;
                annote << "Red: "<< m_redScore;
                draw2dTextAt3dLocation (annote, Vec3(23,0,0), Color(1.0f,0.7f,0.7f), drawGetWindowWidth(), drawGetWindowHeight());
            }
            {
                std::ostringstream annote;
                annote << "Blue: "<< m_blueScore;
                draw2dTextAt3dLocation (annote, Vec3(-23,0,0), Color(0.7f,0.7f,1.0f), drawGetWindowWidth(), drawGetWindowHeight());
            }

            // textual annotation (following the test vehicle's screen position)
    if(0)
        for(unsigned int i=0; i < m_PlayerCountA ; i++)
            {
                std::ostringstream annote;
                annote << std::setprecision (2) << std::setiosflags (std::ios::fixed);
                annote << "      speed: " << TeamA[i]->speed() << "ID:" << i << std::ends;
                draw2dTextAt3dLocation (annote, TeamA[i]->position(), gRed, drawGetWindowWidth(), drawGetWindowHeight());
                draw2dTextAt3dLocation (*"start", Vec3::zero, gGreen, drawGetWindowWidth(), drawGetWindowHeight());
            }
            // update camera, tracking test vehicle
            OpenSteerDemo::updateCamera (currentTime, elapsedTime, *OpenSteerDemo::selectedVehicle);

            // draw "ground plane"
            OpenSteerDemo::gridUtility (Vec3(0,0,0));
*/
}

void playerSteerPlugin::close ()
{
/*    for(unsigned int i=0; i < m_PlayerCountA ; i++)
    {
        delete TeamA[i];
    }
    TeamA.clear ();
    for(unsigned int i=0; i < m_PlayerCountB ; i++)
    {
        delete TeamB[i];
    }
    TeamB.clear ();
    m_AllPlayers.clear();
*/
}

void playerSteerPlugin::reset ()
{
    // reset vehicle
    for(unsigned int i=0; i < m_PlayerCountA ; i++)
    {
        TeamA[i]->reset ();
    }
    for(unsigned int i=0; i < m_PlayerCountB ; i++)
    {
        TeamB[i]->reset ();
    }
//            m_Ball->reset();
}
