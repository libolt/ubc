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

#include "components/gamecomponents.h"
#include "data/courtdata.h"

gameComponents::gameComponents()  // constructor
{
    AI = nullptr;
    jumpBall = nullptr;

}
gameComponents::~gameComponents() = default;  // destructor

AISystemSharedPtr gameComponents::getAI() const  // retrieves the value of AI;
{
    return (AI);
}
void gameComponents::setAI(const AISystemSharedPtr &set)  // sets the value of AI
{
    AI = set;
}

courtDataVec  gameComponents::getCourtDataInstance() const  // retrieves the value of courtDataInstance
{
    return (courtDataInstance);
}
void gameComponents::setCourtDataInstance(const courtDataVec &set)  // sets the value of courtDataInstance
{
    courtDataInstance = set;
}

inputInGameWorkQueues gameComponents::getInputInGameWorkQueue() const  // retrieves the value of inputInGameWorkQueue
{
    return (inputInGameWorkQueue);
}
void gameComponents::setInputInGameWorkQueue(const inputInGameWorkQueues &set)  // sets the value of inputInGameWorkQueue
{
    inputInGameWorkQueue = set;
}

basketballEntityMSharedPtr gameComponents::getActiveBasketballInstance() const  // retrieves the value of activeBasketballInstance
{
    return (activeBasketballInstance);
}
void gameComponents::setActiveBasketballInstance(const basketballEntityMSharedPtr &set)  // sets the value of activeBasketballInstance
{
    activeBasketballInstance = set;
}

courtEntityMSharedPtr gameComponents::getActiveCourtInstance() const  // retrieves the value of activeCourtInstance
{
    return (activeCourtInstance);
}
void gameComponents::setActiveCourtInstance(const courtEntityMSharedPtr &set)  // sets the value of activeCourtInstance
{
    activeCourtInstance = set;
}

hoopEntityMSharedPtr gameComponents::getActiveHoopInstance() const  // retrieves the value of activeHoopInstance
{
    return(activeHoopInstance);
}
void gameComponents::setActiveHoopInstance(const hoopEntityMSharedPtr &set)  // sets the value of activeHoopInstance
{
    activeHoopInstance = set;
}

teamEntityMSharedPtr gameComponents::getActiveTeamInstance() const  // retrieves the value of activeTeamInstance
{
    return (activeTeamInstance);
}
void gameComponents::setActiveTeamInstance(const teamEntityMSharedPtr &set)  // sets the value of activeTeamInstance
{
    activeTeamInstance = set;
}

basketballEntityMSharedPtr gameComponents::getBasketballInstance() const  // retrieves the value of basketballInstance
{
    return (basketballInstance);
}
void gameComponents::setBasketballInstance(const basketballEntityMSharedPtr &set)  // sets the value of basketballInstance
{
    basketballInstance = set;
}

courtEntityMSharedPtr gameComponents::getCourtInstance() const  // retrieves the value of courtInstance
{
    return (courtInstance);
}
void gameComponents::setCourtInstance(const courtEntityMSharedPtr &set)  // sets the value of courtInstance
{
    courtInstance = set;
}

hoopEntityMSharedPtr gameComponents::getHoopInstance() const  // retrieves the value of hoopInstance
{
    return (hoopInstance);
}
void gameComponents::setHoopInstance(const hoopEntityMSharedPtr &set)  // sets the value of hoopInstance
{
    hoopInstance = set;
}

playerEntityMSharedPtr gameComponents::getPlayerInstance() const  // retrieves the value of playerInstance
{
    return (playerInstance);
}
void gameComponents::setPlayerInstance(const playerEntityMSharedPtr &set)  // sets the value of playerInstance
{
    playerInstance = set;
}

teamEntityMSharedPtr gameComponents::getTeamInstance() const  // retrieves the value of teamInstance
{
    return (teamInstance);
}
void gameComponents::setTeamInstance(const teamEntityMSharedPtr &set)  // sets the value of teamInstance
{
    teamInstance = set;
}

jumpBallsSharedPtr gameComponents::getJumpBall() const  // retrieves the value of jumpBall
{
    return (jumpBall);
}
void gameComponents::setJumpBall(const jumpBallsSharedPtr &set)  // sets the value of jumpBall
{
    jumpBall = set;
}


