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
 *   along with this program; if not, write to the         n                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "conversion.h"
#include "teamstate.h"
#include "gameengine.h"
#include "gamestate.h"
#include "logging.h"
#include "physicsengine.h"
#include "playersteer.h"
#include "enums.h"
#include "jumpballs.h"

//extern "C"
//{
teamState::teamState()
{
    //teamNumber = -1;
    teamID = -1;
    teamType = NOTEAM;
	playerType = ' ';
    assists = 0;
    blocks = 0;
    fouls = 0;
    rebounds = 0;
    steals = 0;
    technicals = 0;
    timeouts = 0;

//    activePlayerID = new size_t[5];
/*    for (size_t x=0;x<5;++x)
    {
        activePlayerID.push_back(0);
    }
*/
    offenseInstance = new offenseState;
    defenseInstance = new defenseState;

	playerInstancesCreated = false;
    playerInstanceCreatedCount = 0;
    playerWithBallInstance = -1;
    playerWithBallID = -1;
    playerWithBallDribbling = false;

    humanControlled = false;
    humanPlayer = 4;

    hoop = -1;

    stateSet = false;
//    setupState();
}

teamState::~teamState()
{
}

/*teamTypes teamState::getTeamType()	// retrieves the value of teamType
{
    return (teamType);
}
void teamState::setTeamType(teamTypes set)	// sets the value of the teamType
{
    teamType = set;
}
*/
size_t teamState::getID()	// retrieves the value of teamID
{
    return (teamID);
}
void teamState::setTeamID(size_t set)	// sets the value of teamID
{
    teamID = set;
}

teamTypes teamState::getTeamType()  // retrieves the value of teamType
{
 return (teamType);
}
void teamState::setTeamType(teamTypes set) // sets the value of teamType
{
    teamType = set;
}

std::string teamState::getPlayerType()	// retrieves the value of playerType
{
	return (playerType);
}
void teamState::setPlayerType(std::string set)	// sets the value of playerType
{
	playerType = set;
}

size_t teamState::getAssists(void)   // retrieves the value of assists
{
    return (assists);
}
void teamState::setAssists(size_t set)    // sets the value of assists
{
    assists = set;
}

size_t teamState::getBlocks(void)    // retrieves the value of blocks
{
    return (blocks);
}
void teamState::setBlocks(size_t set)   // sets the value of blocks
{
    blocks = set;
}

size_t teamState::getFouls(void) // retrieves the value of fouls
{
    return (fouls);
}
void teamState::setFouls(size_t set)    // sets the value of fouls
{
    fouls = set;
}

size_t teamState::getRebounds(void)  // retrieves the value of rebounds
{
    return (rebounds);
}
void teamState::setRebounds(size_t set)  // sets the value of rebounds
{
    rebounds = set;
}

size_t teamState::getOffensiveRebounds(void) // retrieves the value of offensiveRebounds
{
    return (offensiveRebounds);
}
void teamState::setOffensiveRebounds(size_t set)    // sets the value of offensiveRebounds
{
    offensiveRebounds = set;
}

size_t teamState::getDefensiveRebounds(void) // retrieves the value of defensiveRebounds
{
    return (defensiveRebounds);
}
void teamState::setDefensiveRebounds(size_t set)    // sets the value of defensiveRebounds
{
    defensiveRebounds = set;
}

size_t teamState::getSteals(void)    // retrieves the value of steals
{
    return (steals);
}
void teamState::setSteals(size_t set)    // sets the value of steals
{
    steals = set;
}

size_t teamState::getTechnicals(void)    // retrieves the value of technicals
{
    return (technicals);
}
void teamState::setTechnicals(size_t set)  // sets the value of technicals
{
    technicals = set;
}

size_t teamState::getTimeouts(void)  // retrieves the value of timeouts
{
    return (timeouts);
}
void teamState::setTimeouts(size_t set)  // sets the value of timeouts
{
    timeouts = set;
}

size_t teamState::getTurnovers() // retrieves the value of turnovers
{
	return (turnovers);
}
void teamState::setTurnovers(size_t set)    // sets the value of turnovers
{
	turnovers = set;
}

size_t teamState::getFieldGoalsAttempted(void)   // retrieves the value of fieldGoalsAttempted
{
    return (fieldGoalsAttempted);
}
void teamState::setFieldGoalsAttempted(size_t set)    // sets the value of fieldGoalsAttempted
{
    fieldGoalsAttempted = set;
}

size_t teamState::getFieldGoalsMade(void)   // retrieves the value of fieldGoalsMade
{
    return (fieldGoalsMade);
}
void teamState::setFieldGoalsMade(size_t set)    // sets the value of fieldGoalsMade
{
    fieldGoalsMade = set;
}

size_t teamState::getThreePointersAttempted(void)   // retrieves the value of threePointersAttempted
{
    return (threePointersAttempted);
}
void teamState::setThreePointersAttempted(size_t set)  // sets the value of threePointersAttempted
{
    threePointersAttempted = set;
}

size_t teamState::getThreePointersMade(void)   // retrieves the value of threePointersMade
{
    return (threePointersMade);
}
void teamState::setThreePointersMade(size_t set)  // sets the value of threePointersMade
{
    threePointersMade = set;
}

size_t teamState::getFreeThrowsAttempted(void)   // retrieves the value of freeThrowsAttempted
{
    return (freeThrowsAttempted);
}
void teamState::setFreeThrowsAttempted(size_t set)    // sets the value of freeThrowsAttempted
{
    freeThrowsAttempted = set;
}

size_t teamState::getFreeThrowsMade(void)   // retrieves the value of freeThrowsMade
{
    return (freeThrowsMade);
}
void teamState::setFreeThrowsMade(size_t set)    // sets the value of freeThrowsMade
{
    freeThrowsMade = set;
}

std::vector<size_t> teamState::getPlayerID()  // retrieves the value of playerID
{
    return (playerID);
}
void teamState::setPlayerID(std::vector<size_t> set)   // sets the value of playerID
{
    playerID = set;
}

std::vector<size_t> teamState::getActivePlayerID()  // retrieves the value of activePlayerID
{
    return (activePlayerID);
}
void teamState::setActivePlayerID(std::vector<size_t> set)   // sets the value of activePlayerID
{
    activePlayerID = set;
}

std::vector<size_t> teamState::getStarterID() // retrieves the value of starterID
{
    return (starterID);
}
void teamState::setStarterID(std::vector<size_t> set)  // sets the value of starterID
{
    logMsg("blap");
    starterID = set;
}

bool teamState::getOffense()	// returns the value of offense
{
	return (offense);
}
void teamState::setOffense(bool set)	// sets the value of offense
{
	offense = set;
}
bool teamState::getDefense()	// returns the value of defense
{
	return (defense);
}
void teamState::setDefense(bool set)	// sets the value of defense
{
	defense = set;
}

std::vector <playerState> teamState::getPlayerInstance()  // retrieves the value of playerInstance
{
    return (playerInstance);
}
void teamState::setPlayerInstance(std::vector<playerState> set)  // sets the value of playerInstance
{
    playerInstance = set;
}

std::vector <playerState> teamState::getActivePlayerInstance()  // retrieves the value of activePlayerInstance
{
    return (activePlayerInstance);
}
void teamState::setActivePlayerInstance(std::vector<playerState> set) // sets the value of activePlayerInstance
{
    activePlayerInstance = set;
}

bool teamState::getPlayerInstancesCreated()	// retrieves the value of playerInstancesCreated
{
	return (playerInstancesCreated);
}
void teamState::setPlayerInstancesCreated(bool set)	// sets the value of playerInstancesCreated
{
	playerInstancesCreated = set;
}

size_t teamState::getPlayerWithBallID()    // retrieves the value of the playerWithBallID
{
    return (playerWithBallID);
}
void teamState::setPlayerWithBallID(size_t set)   // sets the value of the playerWithBallID
{
    playerWithBallID = set;
}

size_t teamState::getPlayerWithBallInstance(void) 	// retrives the value of playerWithBall
{
	return (playerWithBallInstance);
}
void teamState::setPlayerWithBallInstance(size_t set)	// sets the value of playerWithBall
{
	playerWithBallInstance = set;
}

bool teamState::getPlayerWithBallDribbling()	// retrieves the value of playerWithBallDribbling
{
	return (playerWithBallDribbling);
}
void teamState::setPlayerWithBallDribbling(bool set)	// sets the value of playerWithBallDribbling
{
	playerWithBallDribbling = set;
}

bool teamState::getHumanControlled()		// retrieves the value of humanControlled
{
	return (humanControlled);
}
void teamState::setHumanControlled(bool set)		// sets the value of humanControlled
{
	humanControlled = set;
}

size_t teamState::getHumanPlayer()		// retrieves the value of the humanPlayer
{
	return (humanPlayer);
}
void teamState::setHumanPlayer(size_t set)		// sets the value of human player
{
	humanPlayer = set;
}

size_t teamState::getHoop()  // retrieves the value of hoop
{
    return (hoop);
}

void teamState::setHoop(size_t set)  // sets the value of hoop
{
    hoop = set;
}

offenseState *teamState::getOffenseInstance()	// retrievers the value of offenseInstance
{
	return (offenseInstance);
}
void teamState::setOffenseInstance(offenseState *set)	// sets the value of offenseInstance
{
	offenseInstance = set;
}
defenseState *teamState::getDefenseInstance()	// retrieves the value of defenseInstance
{
	return (defenseInstance);
}
void teamState::setDefenseInstance(defenseState *set)	// sets the value of defenseInstance
{
	defenseInstance = set;
}

bool teamState::getStateSet() // retrieves the value of stateSet
{
    return (stateSet);
}
void teamState::setStateSet(bool set) // sets the value of stateSet
{
    stateSet = set;
}

void teamState::setupState()	// sets up the state of the object
{
    if (!stateSet)
    {
        logMsg("Setting state");
//	    boost::shared_ptr<physicsEngine> physEngine = physicsEngine::Instance();
/*        if (!playerInstancesCreated)	// checks if playerInstances have been created
        {
    	    if (createPlayerInstances()) // creates the player instances based on playerIDS
		    {
                logMsg("Player instances created!");
                playerInstancesCreated = true;
//        	exit(0);
		    }
        }
*/
//        setPlayerStartPositions();	// sets starting positions for the players
        logMsg("Player start positions set");
//    playerWithBall = 3; // FIXME! Temporarily ahrd code player controlling ball
//    humanPlayer = 3;	// sets the human controlled player to the center for tip off
/*    player->mAnimationState2 =  activePlayerInstance[5].getModel()->getAnimationState("Walk");
    player->mAnimationState2->setLoop(true);
    player->mAnimationState2->setEnabled(true);
*/
    stateSet = true;
    }
}
void teamState::updateState()	// updates the state of the object
{

//	exit(0);
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //gameEngine *gameE = gameEngine::Instance();
    boost::shared_ptr<gameEngine> gameE = gameEngine::Instance();
	//gameState *gameS = gameState::Instance();
	boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<physicsEngine> physEngine = physicsEngine::Instance();

    jumpBalls jumpBall = gameS->getJumpBall();

    size_t activeBBallInstance = gameS->getActiveBBallInstance();

//	logMsg("Updating team state " +convert->toString(teamNumber));
	if (gameS->getBasketballInstancesCreated() && playerInstancesCreated)
	{
		std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();

//		exit(0);

		// checks whether to execute offense or defense logic
		if (offense == true && defense == false)
		{
			offenseInstance->setExecute(true);
			defenseInstance->setExecute(false);
            if (offenseInstance->getTeamType() !=  teamType)  // sets type of team for offense
            {
                offenseInstance->setTeamType(teamType);
            }
		}
		else if (defense == true && offense == false)
		{
			offenseInstance->setExecute(false);
			defenseInstance->setExecute(true);
            if (defenseInstance->getTeamType() !=  teamType)  // sets type of team for defense
            {
                defenseInstance->setTeamType(teamType);
            }
		}
		else
		{

		}

        if (gameS->getTipOffComplete())
		{
//			exit(0);
//			logMsg("Team with ball ==  "  +convert->toString(gameS->getTeamWithBall()));
//			logMsg("Player with ball ==  "  +convert->toString(playerWithBall));

            if (gameS->getTeamWithBall() == teamType) // checks if the team has the basketball
			{
                logMsg("tipoffcomplete playerWithBallInstance == " +convert->toString(playerWithBallInstance));

                size_t x = 0;
                size_t instanceWithBall = -1;
                while (x < activePlayerInstance.size())
                {
                    if (activePlayerInstance[x].getPlayerID() == playerWithBallID)
                    {
                        instanceWithBall = x;
                        break;
                    }

                    ++x;
                }
                if (!activePlayerInstance[instanceWithBall].getPassBall())	// checks if the player with ball is passing it.
				{
	//				exit(0);
                }
                else if (activePlayerInstance[instanceWithBall].getPassBall())
				{
					logMsg("Calculating Pass");
	//				exit(0);
                    if (!playerInstance[instanceWithBall].getPassCalculated())
					{
	//					exit(0);
						Ogre::Vector3 bballPos;
						Ogre::Vector3 playerPos;
                        activePlayerInstance[instanceWithBall].calculatePass();

						//sets the basketball Height;
						bballPos = basketballInstance[activeBBallInstance].getNode()->getPosition();
                        playerPos = activePlayerInstance[instanceWithBall].getNode()->getPosition();
						bballPos[1] = playerPos[1];
						basketballInstance[activeBBallInstance].getNode()->setPosition(bballPos);

					}
                    else if (activePlayerInstance[playerWithBallInstance].getPassCalculated())
					{
//						exit(0);
						executePass();
						if (physEngine->getPassCollision())	// checks if ball has collided with player being passed to.
						{
//							exit(0);
                            activePlayerInstance[instanceWithBall].setPassBall(false);	// player is no longer passing the ball
                            playerWithBallInstance = activePlayerInstance[instanceWithBall].getPassToPlayer(); // playerWithBall has changed

							if (humanControlled)
							{
                                humanPlayer = instanceWithBall;
							}
							physEngine->setPassCollision(false);	// resets the pass collision state

						}
						else
						{
						}

					}
				}
//				logMsg("Player with ball ==  "  +convert->toString(playerWithBall));
//			    logMsg("Player with ball's name: "  +activePlayerInstance[playerWithBall].getPlayerName());
//				logMsg("Player with ball's current position: "  +convert->toString(activePlayerInstance[playerWithBall].getNode()->getPosition()));
			}
		}
        logMsg("Team type = " +convert->toString(teamType));

        logMsg("Human player = " +convert->toString(humanPlayer));
                                        
        updatePlayerStates();
        //updatePlayerMovements();	// updates movement of player objects
        //updatePlayerDirections();	// updates the direction the players are facing
//		exit(0);


/*		if (physEngine->getPlayerPhysicsSetup())	// makes sure player physics are setup before modifying physics positions
		{
			updatePositions();
//            exit(0);
		}
		else
		{
		}
*/
//	logMsg("Team ==  "  +toString(teamType));

		//		exit(0);
	}
	else
	{
	}
//	exit(0);

    if (gameS->getTipOffComplete())
	{
        logMsg("tipOff Complete!");
//        exit(0);
        if (gameS->getTeamWithBall() == teamType)
	    {
            offenseInstance->updateState(teamType);	// updates the state of the offenseInstance object
	    }
	    else
	    {
            defenseInstance->updateState(teamType); // updates the state of the defenseInstance object
	    }
	}
	else
	{
	}


//   logMsg("team state updated = " +convert->toString(teamType));
}

bool teamState::createPlayerInstances()
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();

    std::vector< std::vector<size_t> > teamStarterID = gameS->getTeamStarterID();
	std::vector<playerData> playerDataInstance = gameS->getPlayerDataInstance();
//	size_t x = 0;
	//	size_t playerID =
//    std::vector <playerData> playerN = player->getPlayer(); // copies Player values to playerN
    std::vector <playerData>::iterator playerIT;
//    std::vector <playerState>::iterator pInstanceIT;
    logMsg("Creating players");


    logMsg("playerDataInstance size = " +convert->toString(playerDataInstance.size()));
//    exit(0);
//    for (playerIT = playerDataInstance.begin(); playerIT != playerDataInstance.end(); ++playerIT)   // loops through playerID std::vector
    size_t id = -1; // stores id for steer
    size_t i = 0;
    
    //    for (size_t i = 0;i < playerDataInstance.size(); ++i)
    while (i<playerDataInstance.size())
    {

        playerState pInstance;  // creates a new instance of playerState
        playerSteer *pSteer = new playerSteer; // steer instance
        playerPhysics pPhysics;
            logMsg("Player Team ID = " +convert->toString(playerDataInstance[i].getTeamID()));
            logMsg("Team ID = " +convert->toString(teamID));

        if (playerDataInstance[i].getTeamID() == teamID)	// checks if player is assigned to this team
        {
            logMsg("teamID!!!!");
            id += 1;
            pInstance.setModelName(playerDataInstance[i].getModel());
            pInstance.setFirstName(playerDataInstance[i].getFirstName());  // copies the first name from the playerData std::vector to the pInstance class
            pInstance.setLastName(playerDataInstance[i].getLastName());    // copies the last name from the playerData std::vector to the pInstance class
            pInstance.setPlayerName(playerDataInstance[i].getFirstName() + " " +playerDataInstance[i].getLastName());
            pInstance.setPlayerID(playerDataInstance[i].getID());
            pInstance.setTeamType(teamType);  // sets the team number the player belongs to
            logMsg("teamtype1");
            pInstance.setPrimaryPosition(playerDataInstance[i].getPrimaryPosition());    // copies the primary position from the playerData std::vector to the pInstance class
            pInstance.setSecondaryPosition(playerDataInstance[i].getSecondaryPosition());    // copies the secondary position from the playerData std::vector to the pInstance class
            pInstance.setPosChange(Ogre::Vector3(0.0f,0.0f,0.0f));
//            pSteer->setTeamType(teamType);
//            logMsg("teamtyp2");
            pSteer->reset();
            logMsg("psteer resset!");
            pInstance.setSteer(pSteer);
            logMsg("steer set!");
            if (pPhysics.setupState())
            {
                pInstance.setPhysics(pPhysics);
            }
            else
            {
                logMsg("Unable to setup Player Physics!");
                exit(0);
            }
            playerInstance.push_back(pInstance);    // adds pInstance to the playerInstance std::vector.
            logMsg("pInstance set!");
            logMsg("steerID = " +convert->toString(pInstance.getSteer()->getID()));
            logMsg("player name = " +pInstance.getPlayerName());
        }
        else
        {
        }
        i++;
    }
//    std::vector <playerState>::iterator pInstanceIT;

    logMsg("before playerID");
//        size_t playerID = teamStarterID[teamType][i];
//        size_t playerID = activePlayerID[i];
//        logMsg("ID " +convert->toString(i) +" = " +convert->toString(playerID));
    logMsg("activePlayerID.size() = " +convert->toString(activePlayerID.size()));
//    logMsg("playerID = " +convert->toString(activePlayerID[i]));
    size_t x = 0;

    logMsg("activePlayerInstance.size() = " +convert->toString(playerInstance.size()));

    bool IDMatch = false;
//            for (size_t j=0;j<playerInstance.size();++j)
    while (x<playerInstance.size())
    {
        size_t i = 0;
//        while (!IDMatch && x < playerInstance.size())
        while (i<activePlayerID.size())
        {

            logMsg("playerInstance[x].getPlayerID() = " +convert->toString(playerInstance[x].getPlayerID()));
            if (activePlayerID[i] == playerInstance[x].getPlayerID())
            {
//                exit(0);
//                IDMatch = true;
                logMsg("Success!");
//                exit(0);
                if (!playerInstance[x].getModelLoaded())
                {
                    if (playerInstance[x].loadModel())
                    {
                        logMsg("Loading Model");
//                        exit(0);
                        playerInstance[x].setModelLoaded(true);
                    }
                    else
                    {
                        logMsg("Failed to load model " +playerInstance[x].getPlayerName());
                    }
                }
//                    exit(0);
            }
           i++;
        }
        x++;
    }

    return true;
}

void teamState::setPlayerStartPositions()	// sets the initial coordinates for the players.
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<gameEngine> gameE = gameEngine::Instance();

    std::vector< std::vector<size_t> > teamStarterID = gameS->getTeamStarterID();

    std::vector<Ogre::Vector3> startingPos;
    directions playerDirection; // stores the direction players face at start

    if (!gameS->getCourtInstanceCreated())
    {
        if (gameS->createCourtInstances())
        {
            gameS->setCourtInstanceCreated(true);
            gameS->setCourdModelLoaded(true);
            gameS->setCourtStartPositions();
        }
    }
    std::vector<courtState> courtInstance = gameS->getCourtInstance();

    Ogre::Vector3 courtPos = courtInstance[0].getNodePosition();
//    exit(0);
    float yOffset = courtPos.y + 5.0;
    float y = 0.0;
    logMsg("courtpos.y == " +convert->toString(courtPos.y));
    logMsg("yOffset == " +convert->toString(yOffset));
//    exit(0);
    // set initial player coordinates for the tipoff

    if (teamType == HOMETEAM)	// assigns the positions and directions for team 1 players
	{
		// assign positions
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        y = -0.0f;
#else
        y = -23.5f;
#endif

//        yOffset = y;
        gameE->setYOffset(yOffset);
        
        startingPos.push_back(Ogre::Vector3(14.4f,yOffset,352.0f));
        startingPos.push_back(Ogre::Vector3(2.0f,yOffset,347.6f));
        startingPos.push_back(Ogre::Vector3(2.0f,yOffset,360.0f));
        startingPos.push_back(Ogre::Vector3(5.2f,yOffset,351.6f));
        startingPos.push_back(Ogre::Vector3(1.6f,yOffset,352.0f));
        
        playerDirection = LEFT;
    }
    else if (teamType == AWAYTEAM) // assigns the positions and directions for team 2 players
    {
        float y = 0.0f;
        // assign positions
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        y = -0.0f;
#else
        y = -23.5f;
#endif

        startingPos.push_back(Ogre::Vector3(-13.8f,yOffset,352.0f));
        startingPos.push_back(Ogre::Vector3(-0.8f,yOffset,347.6f));
        startingPos.push_back(Ogre::Vector3(-0.8f,yOffset,360.8f));
        startingPos.push_back(Ogre::Vector3(4.4f,yOffset,348.8f));
        startingPos.push_back(Ogre::Vector3(-0.4f,yOffset,352.0f));

        playerDirection = RIGHT;
    }
    
    if (startingPos.size() > 0)
    {
        
//        for (size_t i=0;i<5;++i)
        size_t i = 0;
/*        while (i<teamStarterID[teamType].size())
        {
            size_t playerID = teamStarterID[teamType][i];
            logMsg("ID " +convert->toString(i) +" = " +convert->toString(playerID));
*/
        size_t x = 0;
        while (x < activePlayerInstance.size()) //&& playerID != playerInstance[x].getPlayerID())
        {
/*            if (playerID == playerInstance[x].getPlayerID())
            {

                logMsg("Player ID = " +convert->toString(playerInstance[x].getPlayerID()));
                logMsg("X " +convert->toString(i) +" = " +convert->toString(x));
            playerInstance[x].setIsActive(true);    // sets the player active for startup which is used by other code such as physics and steering
*/
            if (activePlayerInstance[x].getActivePosition() == PG)
            {
                //activePlayerInstance[x].getNode()->setPosition(startingPos[0]);
                activePlayerInstance[x].setCourtPositionChanged(true);
                activePlayerInstance[x].setCourtPositionChangedType(STARTCHANGE);
                activePlayerInstance[x].setNewCourtPosition(startingPos[0]);
                
                activePlayerInstance[x].setDirection(playerDirection);
                activePlayerInstance[x].getSteer()->setPlayerPosition(PG);
                //activePlayerInstance[x].getSteer()->setPosition(convert->toOpenSteerVec3(startingPos[0]));
            }
            else if (activePlayerInstance[x].getActivePosition() == SG)
            {
                //activePlayerInstance[x].getNode()->setPosition(startingPos[1]);
                activePlayerInstance[x].setCourtPositionChanged(true);
                activePlayerInstance[x].setCourtPositionChangedType(STARTCHANGE);
                activePlayerInstance[x].setNewCourtPosition(startingPos[1]);

                activePlayerInstance[x].setDirection(playerDirection);
                activePlayerInstance[x].getSteer()->setPlayerPosition(SG);
                //activePlayerInstance[x].getSteer()->setPosition(convert->toOpenSteerVec3(startingPos[1]-5));
            }
            else if (activePlayerInstance[x].getActivePosition() == SF)
            {
                //activePlayerInstance[x].getNode()->setPosition(startingPos[2]);
                activePlayerInstance[x].setCourtPositionChanged(true);
                activePlayerInstance[x].setCourtPositionChangedType(STARTCHANGE);
                activePlayerInstance[x].setNewCourtPosition(startingPos[2]);

                activePlayerInstance[x].setDirection(playerDirection);
                activePlayerInstance[x].getSteer()->setPlayerPosition(SF);
                //activePlayerInstance[x].getSteer()->setPosition(convert->toOpenSteerVec3(startingPos[2]));
            }
            else if (activePlayerInstance[x].getActivePosition() == PF)
            {
                //activePlayerInstance[x].getNode()->setPosition(startingPos[3]);
                activePlayerInstance[x].setCourtPositionChanged(true);
                activePlayerInstance[x].setCourtPositionChangedType(STARTCHANGE);
                activePlayerInstance[x].setNewCourtPosition(startingPos[3]);

                activePlayerInstance[x].setDirection(playerDirection);
                activePlayerInstance[x].getSteer()->setPlayerPosition(PF);
                //activePlayerInstance[x].getSteer()->setPosition(convert->toOpenSteerVec3(startingPos[3]));
            }
            else if (activePlayerInstance[x].getActivePosition() == C)
            {
               // activePlayerInstance[x].getNode()->setPosition(startingPos[4]);
                activePlayerInstance[x].setCourtPositionChanged(true);
                activePlayerInstance[x].setCourtPositionChangedType(STARTCHANGE);
                activePlayerInstance[x].setNewCourtPosition(startingPos[4]);

                activePlayerInstance[x].setDirection(playerDirection);
                activePlayerInstance[x].getSteer()->setPlayerPosition(C);
               // activePlayerInstance[x].getSteer()->setPosition(convert->toOpenSteerVec3(startingPos[4]));
            }
            else
            {
            }
//            }
            x++;
        }
/*            i++;
        }
*/
//	    exit(0);
	}
    size_t x = 0;
    while (x < activePlayerInstance.size())
    {
        
        logMsg("PlayerSteerNode Position == " +convert->toString(activePlayerInstance[x].getNode()->getPosition()));
        logMsg("PlayerSteer Position == " +convert->toString(activePlayerInstance[x].getSteer()->position()));
        ++x;
    }
//    exit(0);
}

void teamState::setPlayerStartActivePositions() // sets the position the players will play at the start of the game
{
    boost::shared_ptr<conversion> convert = conversion::Instance();

    logMsg("activePlayerInstance.size() =" +convert->toString(activePlayerInstance.size()));
    if (activePlayerInstance.size() > 0) // checks that activePlayerInstance has data before executing
    {
        activePlayerInstance[0].setActivePosition(PG);
        activePlayerInstance[1].setActivePosition(SG);
        activePlayerInstance[2].setActivePosition(SF);
        activePlayerInstance[3].setActivePosition(PF);
        activePlayerInstance[4].setActivePosition(C);
    }
    // set steer IDs
    size_t x = 0;
    while (x < activePlayerInstance.size())
    {
        //playerSteer *pSteer = activePlayerInstance[x].getSteer();
       // pSteer->setID(x);
        activePlayerInstance[x].getSteer()->setID(x);
        ++x;
    }
    
}

void teamState::updatePlayerStates()  // updates the states of active players
{
    boost::shared_ptr<conversion> convert = conversion::Instance();

    size_t x = 0;
    
    while (x<activePlayerInstance.size())
    {
        activePlayerInstance[x].updateState();
        ++x;
    }
    
    x = 0;
    while (x < activePlayerInstance.size())
    {
        logMsg("PlayerSteerNode Position == " +convert->toString(activePlayerInstance[x].getNode()->getPosition()));
        logMsg("PlayerSteer Position == " +convert->toString(activePlayerInstance[x].getSteer()->position()));
        ++x;
    }
}

void teamState::updatePlayerDirections()
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();

    directions playerDirection, oldPlayerDirection;
//    std::vector<playerState> pInstance = getPlayerInstance();
 //   std::vector<size_t> playerDirection = player->getPlayerDirection(); // stores contents of playerDirectdion from players class in local variable
//    std::vector<size_t> oldPlayerDirection = player->getOldPlayerDirection();   // stores contents of oldPlayerDirection form players in local variable
	std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();
    std::vector<Ogre::SceneNode>::iterator playersIT;

    std::string playerID = convert->toString(playerInstance[4].getPlayerID());
//    exit(0);
//    logMsg("playerID == " +playerID);
    // checks if a player's direction has changed and rotates the model accordingly.
//    for(playersIT = playerNodes.begin(); playersIT != playerNodes.end(); ++playersIT)

    size_t x = 0;
    size_t y = 0;
//    for (size_t i = 0; i < playerInstance.size(); ++i)
    while (x<activePlayerInstance.size())
    {
        playerDirection = activePlayerInstance[x].getDirection();
        oldPlayerDirection = activePlayerInstance[x].getOldDirection();
        if (oldPlayerDirection != playerDirection)
        {
            
            /*
            std::string oldPlayerDirect = Ogre::SingConverter::toString(oldPlayerDirection[i]);
            std::string playerDirect = toString(playerDirection[i]);
            std::string bballPlayer = toString(basketballInstance[activeBBallInstance].getPlayer());
            logMsg("oldPlayerDirection = " + oldPlayerDirect);
            logMsg("playerDirection = " + playerDirect);
            logMsg("bball player = " + bballPlayer);
            playerInstance[basketballInstance[activeBBallInstance].getPlayer()] = playerInstance[i];
//            playerNodes.at(basketballInstance[activeBBallInstance].getPlayer()) = playerNodes.at(i);  // sets the current player node
            */
            switch (oldPlayerDirection)
            {
                case UP:
                    switch (playerDirection)
                    {
                        case DOWN:
                            activePlayerInstance[x].getNode()->yaw(Ogre::Degree (180));
                            break;
                        case LEFT:
                            activePlayerInstance[x].getNode()->yaw(Ogre::Degree (270));
                            break;
                        case RIGHT:
                            activePlayerInstance[x].getNode()->yaw(Ogre::Degree (90));
                            exit(0);
                            break;
                        default:
                            break;
                    }
                    break;
                case DOWN:
                    switch (playerDirection)
                    {
                        case UP:
                            activePlayerInstance[x].getNode()->yaw(Ogre::Degree (180));
                            break;
                        case LEFT:
                            activePlayerInstance[x].getNode()->yaw(Ogre::Degree (90));
                            break;
                        case RIGHT:
                            activePlayerInstance[x].getNode()->yaw(Ogre::Degree (270));
                            break;
                        default:
                            break;
                    }
                    break;
                    case LEFT:
                        switch (playerDirection)
                        {
                            case UP:
                                activePlayerInstance[x].getNode()->yaw(Ogre::Degree (90));
                                break;
                            case DOWN:
                                activePlayerInstance[x].getNode()->yaw(Ogre::Degree (270));
                                break;
                            case RIGHT:
                                activePlayerInstance[x].getNode()->yaw(Ogre::Degree (180));
                                break;
                            default:
                                break;
                        }
                        break;
                    case RIGHT:
                        switch (playerDirection)
                        {
                            case UP:
                                activePlayerInstance[x].getNode()->yaw(Ogre::Degree (270));
                                break;
                            case DOWN:
                                activePlayerInstance[x].getNode()->yaw(Ogre::Degree (90));
                                break;
                            case LEFT:
                                activePlayerInstance[x].getNode()->yaw(Ogre::Degree (180));
                                break;
                            default:
                                break;
                        }
                        break;
                default:
                    break;
            }
        }
        logMsg("directPlayerID == " +convert->toString(activePlayerInstance[x].getPlayerID()));
        logMsg("directPlayerWithBallInstance == " +convert->toString(playerWithBallInstance));
        if (activePlayerInstance[x].getPlayerID() != playerWithBallID)
        {
            oldPlayerDirection = playerDirection;
            activePlayerInstance[x].setOldDirection(oldPlayerDirection);  // copies contents of oldPlayerDirection to the oldDirection variable
        }
        else
        {
        }
/*            }
            ++y;
        }
*/
        ++x;
    }
}


void teamState::updatePlayerMovements()	// updates player movements
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    
    Ogre::Vector3 posChange;	// stores change in position
	posChange = Ogre::Vector3(0.0f, 0.0f, 0.0f);

    size_t x = 0;
    size_t y = 0;
//	for (size_t i = 0; i < playerInstance.size(); ++i)
    while(x<activePlayerInstance.size())
	{
        if (activePlayerInstance[x].getMovement())	// if true sets coordinate change accordingly
        {
//                    exit(0);
            if (activePlayerInstance[x].getDirection() == UP)
            {
                posChange = Ogre::Vector3(0.0f, 0.0f, -0.400f);
                logMsg("UP!");
//				exit(0);
            }
            else if (activePlayerInstance[x].getDirection() == DOWN)
            {
                posChange = Ogre::Vector3(0.0f, 0.0f, 0.400f);
            }
            else if (activePlayerInstance[x].getDirection() == LEFT)
            {
//			    exit(0);

                posChange = Ogre::Vector3(-0.400f, 0.0f, 0.0f);
//			    playerInstance[i].getPhysBody()->setLinearVelocity(btVector3(0.4,0,0));
            }
            else if (activePlayerInstance[x].getDirection() == RIGHT)
            {
                posChange = Ogre::Vector3(0.400f, 0.0f, 0.0f);
            }
            else if (activePlayerInstance[x].getDirection() == UPLEFT)
            {
                posChange = Ogre::Vector3(-0.400f, 0.0f, -0.400f);
            }
            else if (activePlayerInstance[x].getDirection() == UPRIGHT)
            {
                posChange = Ogre::Vector3(0.400f, 0.0f, -0.400f);
            }
            else if (activePlayerInstance[x].getDirection() == DOWNLEFT)
            {
                posChange = Ogre::Vector3(-0.400f, 0.0f, 0.400f);
            }
            else if (activePlayerInstance[x].getDirection() == DOWNRIGHT)
            {
                posChange = Ogre::Vector3(0.400f, 0.0f, 0.400f);
            }

        }
        else if (!activePlayerInstance[x].getMovement())	// if false then sets their coordinate changes to 0.0
        {
            posChange = Ogre::Vector3(0.0f, 0.0f, 0.0f);
        }

        if (posChange.x != 0 || posChange.y != 0 || posChange.z != 0)
        {
            activePlayerInstance[x].setNewCourtPosition(posChange);	// sets the newCourtPosition for current playerInstance
            activePlayerInstance[x].setCourtPositionChanged(true);
            activePlayerInstance[x].setCourtPositionChangedType(INPUTCHANGE);
            activePlayerInstance[x].setMovement(false);
        }       
        ++x;
	}

//	exit(0);
}

// FIXME! update for class reorganization

void teamState::executePass()		// executes the pass between players
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();

    logMsg("In executePass function");

    size_t activeBBallInstance = gameS->getActiveBBallInstance();

    size_t passToPlayer = activePlayerInstance[playerWithBallInstance].getPassToPlayer();
	std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();
    Ogre::Vector3 playerWithBallCoords = activePlayerInstance[playerWithBallInstance].getNode()->getPosition();
    Ogre::Vector3 passToPlayerCoords = activePlayerInstance[passToPlayer].getNode()->getPosition();
//	exit(0);
	Ogre::Vector3 bballCoords = basketballInstance[activeBBallInstance].getNode()->getPosition();
	btVector3 bballPosChange;
	btVector3 bballPhysCoords;
	btTransform transform;
//	exit(0);
    logMsg("Basketball = " + convert->toString(bballCoords));
    logMsg("passToPlayer = " + convert->toString(passToPlayerCoords));

    if (bballCoords[1] != passToPlayerCoords[1])
    {
    	bballCoords[1] = passToPlayerCoords[1];
    	basketballInstance[activeBBallInstance].getNode()->setPosition(bballCoords);
		bballPhysCoords = BtOgre::Convert::toBullet(bballCoords); // converts from Ogre::Vector3 to btVector3
		transform.setOrigin(bballPhysCoords);
		basketballInstance[activeBBallInstance].getPhysBody()->setWorldTransform(transform);


    }
	if (bballCoords[0] < passToPlayerCoords[0])
	{
		if (bballCoords[2] < passToPlayerCoords[2])
		{
//	    	basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(15,0,15));
			bballPosChange[0] = 15;
			bballPosChange[2] = 15;
		}
		else if (bballCoords[2] > passToPlayerCoords[2])
		{
//	    	basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(15,0,-15));
			bballPosChange[0] = 15;
			bballPosChange[2] = -15;

		}
		else
		{
		}
	}
	else if (bballCoords[0] > passToPlayerCoords[0])
	{
		if (bballCoords[2] < passToPlayerCoords[2])
		{
//	    	basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(-15,0,15));
			bballPosChange[0] = -15;
			bballPosChange[2] = 15;

		}
		else if (bballCoords[2] > passToPlayerCoords[2])
		{
//	    	basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(-15,0,-15));
			bballPosChange[0] = -15;
			bballPosChange[2] = -15;

		}
		else
		{
		}
	}
	else
	{
	}

	basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(bballPosChange));


	gameS->setBasketballInstance(basketballInstance);		// saves changes to the basketballInstance object
}


void teamState::updatePositions()
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    
    size_t x = 0;
	// updates the player positions on the court
    while (x<activePlayerInstance.size())
	{
//		logMsg("updatePositions X = " +convert->toString(x));
        activePlayerInstance[x].updateCourtPosition();
        x++;
    }
    logMsg("courtPosition updated!!");

}


