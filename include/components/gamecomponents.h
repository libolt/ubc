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

#ifndef _GAMECOMPONENTS_H_
#define _GAMECOMPONENTS_H_

#include "utilities/typedefs.h"

class gameStateMachine;
class gameSMData;

class gameComponents
{
    public:
        gameComponents();  // constructor
        ~gameComponents();  // destructor

        AISystemSharedPtr getAI() const;  // retrieves the value of AI;
        void setAI(const AISystemSharedPtr &set);  // sets the value of AI

        courtDataVec getCourtDataInstance() const;  // retrieves the value of courtDataInstance
        void setCourtDataInstance(const courtDataVec &set);  // sets the value of courtDataInstance

        inputInGameWorkQueues getInputInGameWorkQueue() const;  // retrieves the value of inputInGameWorkQueue
        void setInputInGameWorkQueue(const inputInGameWorkQueues &set);  // sets the value of inputInGameWorkQueue

        basketballEntityMSharedPtr getActiveBasketballInstance() const;  // retrieves the value of activeBasketballInstance
        void setActiveBasketballInstance(const basketballEntityMSharedPtr &set);  // sets the value of activeBasketballInstance

        courtEntityMSharedPtr getActiveCourtInstance() const;  // retrieves the value of activeCourtInstance
        void setActiveCourtInstance(const courtEntityMSharedPtr &set);  // sets the value of activeCourtInstance

        hoopEntityMSharedPtr getActiveHoopInstance() const;  // retrieves the value of activeHoopInstance
        void setActiveHoopInstance(const hoopEntityMSharedPtr &set);  // sets the value of activeHoopInstance

        teamEntityMSharedPtr getActiveTeamInstance() const;  // retrieves the value of activeTeamInstance
        void setActiveTeamInstance(const teamEntityMSharedPtr &set);  // sets the value of activeTeamInstance
               
//        size_t getActiveBBallInstance();  // retrieves the value of activeBBallInstance
//        void setActiveBBallInstance(size_t set);  // sets the value of activeBBallInstance

        basketballEntityMSharedPtr getBasketballInstance() const;  // retrieves the value of basketballInstance
        void setBasketballInstance(const basketballEntityMSharedPtr &set);  // sets the value of basketballInstance

        courtEntityMSharedPtr  getCourtInstance() const;  // retrieves the value of courtInstance
        void setCourtInstance(const courtEntityMSharedPtr  &set);  // sets the value of courtInstance

        hoopEntityMSharedPtr getHoopInstance() const;  // retrieves the value of hoopInstance
        void setHoopInstance(const hoopEntityMSharedPtr &set);  // sets the value of hoopInstance

        playerEntityMSharedPtr getPlayerInstance() const;  // retrieves the value of playerInstance
        void setPlayerInstance(const playerEntityMSharedPtr &set);  // sets the value of  playerInstance

        teamEntityMSharedPtr getTeamInstance() const;  // retireves the value of teamInstance
        void setTeamInstance(const teamEntityMSharedPtr &set);  // sets the value of teamInstance

        jumpBallsSharedPtr getJumpBall() const;  // retrieves the value of jumpBall
        void setJumpBall(const jumpBallsSharedPtr &set);  // sets the value of jumpBall

    private:
    
        AISystemSharedPtr AI;  // stores the AI Instance
        courtDataVec courtDataInstance;  // stores the vector the courts loaded from the xml files
        inputInGameWorkQueues inputInGameWorkQueue;  // queue of input events for game

        basketballEntityMSharedPtr activeBasketballInstance;  // creates instance of the basketballState class
        courtEntityMSharedPtr activeCourtInstance;  // stores the active court instance
        hoopEntityMSharedPtr activeHoopInstance;  // creates instance of the hoopState class
        teamEntityMSharedPtr activeTeamInstance;  // stores active team instance
        
        basketballEntityMSharedPtr basketballInstance;  // creates instance of the basketballs class
        courtEntityMSharedPtr courtInstance;  // stores the court instance
        hoopEntityMSharedPtr hoopInstance;  // creates instance of the hoop class
        playerEntityMSharedPtr playerInstance;  // stores the map of the players loaded from the xml files
        teamEntityMSharedPtr  teamInstance;  // creates instance of the teamState class

        jumpBallsSharedPtr jumpBall; // instance that is used for jumpBall functions.

};

#endif
