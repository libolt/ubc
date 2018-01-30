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

gameComponents::gameComponents()  // constructor
{

}
gameComponents::~gameComponents()  // destructor
{
    
}

courtDataVec  gameComponents::getCourtDataInstance()  // retrieves the value of courtDataInstance
{
    return (courtDataInstance);
}
void gameComponents::setCourtDataInstance(courtDataVec set)  // sets the value of courtDataInstance
{
    courtDataInstance = set;
}

inputInGameWorkQueues gameComponents::getInputInGameWorkQueue()  // retrieves the value of inputInGameWorkQueue
{
    return (inputInGameWorkQueue);
}
void gameComponents::setInputInGameWorkQueue(inputInGameWorkQueues set)  // sets the value of inputInGameWorkQueue
{
    inputInGameWorkQueue = set;
}

basketballStateMSharedPtr gameComponents::getActiveBasketballInstance()  // retrieves the value of activeBasketballInstance
{
    return (activeBasketballInstance);
}
void gameComponents::setActiveBasketballInstance(basketballStateMSharedPtr set)  // sets the value of activeBasketballInstance
{
    activeBasketballInstance = set;
}

courtStateMSharedPtr gameComponents::getActiveCourtInstance()  // retrieves the value of activeCourtInstance
{
    return (activeCourtInstance);
}
void gameComponents::setActiveCourtInstance(courtStateMSharedPtr set)  // sets the value of activeCourtInstance
{
    activeCourtInstance = set;
}

hoopStateMSharedPtr gameComponents::getActiveHoopInstance()  // retrieves the value of activeHoopInstance
{
    return(activeHoopInstance);
}
void gameComponents::setActiveHoopInstance(hoopStateMSharedPtr set)  // sets the value of activeHoopInstance
{
    activeHoopInstance = set;
}

teamStateMSharedPtr gameComponents::getActiveTeamInstance()  // retrieves the value of activeTeamInstance
{
    return (activeTeamInstance);
}
void gameComponents::setActiveTeamInstance(teamStateMSharedPtr set)  // sets the value of activeTeamInstance
{
    activeTeamInstance = set;
}

basketballStateMSharedPtr gameComponents::getBasketballInstance()  // retrieves the value of basketballInstance
{
    return (basketballInstance);
}
void gameComponents::setBasketballInstance(basketballStateMSharedPtr set)  // sets the value of basketballInstance
{
    basketballInstance = set;
}

courtStateMSharedPtr gameComponents::getCourtInstance()  // retrieves the value of courtInstance
{
    return (courtInstance);
}
void gameComponents::setCourtInstance(courtStateMSharedPtr set)  // sets the value of courtInstance
{
    courtInstance = set;
}

hoopStateMSharedPtr gameComponents::getHoopInstance()  // retrieves the value of hoopInstance
{
    return (hoopInstance);
}
void gameComponents::setHoopInstance(hoopStateMSharedPtr set)  // sets the value of hoopInstance
{
    hoopInstance = set;
}

playerEntityMSharedPtr gameComponents::getPlayerInstance()  // retrieves the value of playerInstance
{
    return (playerInstance);
}
void gameComponents::setPlayerInstance(playerEntityMSharedPtr set)  // sets the value of playerInstance
{
    playerInstance = set;
}

teamStateMSharedPtr gameComponents::getTeamInstance()  // retrieves the value of teamInstance
{
    return (teamInstance);
}
void gameComponents::setTeamInstance(teamStateMSharedPtr set)  // sets the value of teamInstance
{
    teamInstance = set;
}

jumpBallsSharedPtr gameComponents::getJumpBall()  // retrieves the value of jumpBall
{
    return (jumpBall);
}
void gameComponents::setJumpBall(jumpBallsSharedPtr set)  // sets the value of jumpBall
{
    jumpBall = set;
}


