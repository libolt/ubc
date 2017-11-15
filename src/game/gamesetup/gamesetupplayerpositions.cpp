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

#include "gamesetup/gamesetupplayerpositions.h"
#include "entity/playerentity.h"
#include "ai/playersteer.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"

gameSetupPlayerPositions::gameSetupPlayerPositions()  // constructor
{
    
}
gameSetupPlayerPositions::~gameSetupPlayerPositions()  // destructor
{
    
}

playerEntityMSharedPtr gameSetupPlayerPositions::setJumpBallPositions(playerEntityMSharedPtr activePlayerInstance, teamTypes teamType, Ogre::Vector3 courtPos)  // sets player positions for jumpball
{
    conversionSharedPtr convert = conversion::Instance();
//    sharedPtr<gameState> gameS = gameState::Instance();
//    sharedPtr<gameEngine> gameE = gameEngine::Instance();
//    std::vector<std::unordered_map<std::string, size_t> > teamStarterID = base->getGameS()->getTeamStarterID();
    OgreVector3Vec startingPos;
//    directions playerDirection; // stores the direction players face at start
    std::string func = "gameSetupPlayerPositions::setJumpBallPositions()";
//    courtStateMSharedPtr courtInstance = base->getGameS()->getCourtInstance();
//    Ogre::Vector3 courtPos = courtInstance[0]->getEntity()->getNodePosition();

//    exit(0);
    logMsg(func +" begining");

    logMsg(func +" courtPos.y == " +convert->toString(courtPos.y));
    float yOffset = courtPos.y + 6.0;

    logMsg(func +" courtpos.y == " +convert->toString(courtPos.y));
    logMsg(func +" yOffset == " +convert->toString(yOffset));

//    exit(0);
    // set initial player coordinates for the tipoff

    switch (teamType)
    {
        case HOMETEAM:   // assigns the positions and directions for team 1 player
//            base->getGameS()->setYOffset(yOffset);
            // assign positions
            startingPos.push_back(Ogre::Vector3(14.4f,yOffset,352.0f));
            startingPos.push_back(Ogre::Vector3(2.0f,yOffset,347.6f));
            startingPos.push_back(Ogre::Vector3(2.0f,yOffset,360.0f));
            startingPos.push_back(Ogre::Vector3(5.2f,yOffset,351.6f));
            startingPos.push_back(Ogre::Vector3(1.6f,yOffset,352.0f));
        break;

        case AWAYTEAM: // assigns the positions and directions for team 2 players
            // assign positions
            startingPos.push_back(Ogre::Vector3(-13.8f,yOffset,352.0f));
            startingPos.push_back(Ogre::Vector3(-0.8f,yOffset,347.6f));
            startingPos.push_back(Ogre::Vector3(-0.8f,yOffset,360.8f));
            startingPos.push_back(Ogre::Vector3(4.4f,yOffset,348.8f));
            startingPos.push_back(Ogre::Vector3(-0.4f,yOffset,352.0f));
        break;
    }


    if (startingPos.size() > 0)
    {
        logMsg(func +" startingPosition.size > 0");
//        exit(0);
//        for (size_t i=0;i<5;++i)
        size_t i = 0;

        size_t x = 0;
        for (auto APIIT : activePlayerInstance)
        {
            logMsg(func +" activePlayerInstance.size > 0!");

            std::vector<playerActions> stateAction = APIIT.second->getStateAction();
            switch (APIIT.second->getActivePosition())
            {
                case PG:
                    APIIT.second->setCourtPositionChanged(true);
                    APIIT.second->setCourtPositionChangedType(STARTCHANGE);
                    APIIT.second->setNewCourtPosition(startingPos[0]);
                    APIIT.second->setStateChanged(true);
                    stateAction.push_back(CHANGECOURTPOS);
                    APIIT.second->setStateAction(stateAction);
                    APIIT.second->getSteer()->setPlayerPosition(PG);
//                    exit(0);
                break;
                case SG:
                    APIIT.second->setCourtPositionChanged(true);
                    APIIT.second->setCourtPositionChangedType(STARTCHANGE);
                    APIIT.second->setNewCourtPosition(startingPos[1]);
                    APIIT.second->setStateChanged(true);
                    stateAction.push_back(CHANGECOURTPOS);
                    APIIT.second->setStateAction(stateAction);
                    APIIT.second->getSteer()->setPlayerPosition(SG);
                break;
                case SF:
                    APIIT.second->setCourtPositionChanged(true);
                    APIIT.second->setCourtPositionChangedType(STARTCHANGE);
                    APIIT.second->setNewCourtPosition(startingPos[2]);
                    APIIT.second->setStateChanged(true);
                    stateAction.push_back(CHANGECOURTPOS);
                    APIIT.second->setStateAction(stateAction);
                    APIIT.second->getSteer()->setPlayerPosition(SF);
                break;
                case PF:
                    APIIT.second->setCourtPositionChanged(true);
                    APIIT.second->setCourtPositionChangedType(STARTCHANGE);
                    APIIT.second->setNewCourtPosition(startingPos[3]);
                    APIIT.second->setStateChanged(true);
                    stateAction.push_back(CHANGECOURTPOS);
                    APIIT.second->setStateAction(stateAction);
                    APIIT.second->getSteer()->setPlayerPosition(PF);
                break;
                case C:
                    APIIT.second->setCourtPositionChanged(true);
                    APIIT.second->setCourtPositionChangedType(STARTCHANGE);
                    APIIT.second->setNewCourtPosition(startingPos[4]);
                    APIIT.second->setStateChanged(true);
                    stateAction.push_back(CHANGECOURTPOS);
                    APIIT.second->setStateAction(stateAction);
                    APIIT.second->getSteer()->setPlayerPosition(C);
                break;
            }
        }
    }
    return (activePlayerInstance);
}
bool gameSetupPlayerPositions::setHalfTimePositions()  // sets player positions for start of the second half
{
    return (true);
}
bool gameSetupPlayerPositions::setTimeOutPositions()  // sets playerpositions coming out of timeout
{
    return (true);
}
