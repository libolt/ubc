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

#ifndef _TEAMENTITY_H_
#define _TEAMENTITY_H_

#include "utilities/typedefs.h"

class teamSMData;

class teamEntity
{
    public:

        teamEntity();  // constructor
        ~teamEntity();  // destructor

        bool getObjectsInitialized() const;  //  retrieves the value of objectsInitialized
        void setObjectsInitialized(const bool &set);  //  sets the value of objectsInitialized

        teamComponentsSharedPtr getComponent() const;  // retrieves the value of component
        void setComponent(const teamComponentsSharedPtr &set);  // sets the value of component

        teamDataSharedPtr getData() const;  // retrieves the value of data
        void setData(const teamDataSharedPtr &set);  // sets the value of data

        teamFlagsSharedPtr getFlag() const;  // retrieves the value of flag
        void setFlag(const teamFlagsSharedPtr &set);  // sets the value of flag

        teamGameDataSharedPtr getGameData() const;  // retrieves the value of gameData
        void setGameData(const teamGameDataSharedPtr &set);  // sets the value of gameData

        teamStateMachineSharedPtr getStateMachine() const;  // retrieves the value of stateMachine
        void setStateMachine(const teamStateMachineSharedPtr &set);  // sets the value of stateMachine

        teamStatisticsSharedPtr getStatistics() const;  // retrieves the value of statistics
        void setStatistics(teamStatisticsSharedPtr &set);  // sets the value of statistics

        offDefs getOffDef() const;  // retrieves the value of offDef
        void setOffDef(const offDefs &set);  // sets the value of offDef

        bool initializeObjects();  // initializes teamEntity object

        bool initializeStateMachine();  // initializes teamStateMachine object

        void updateState(const gameComponentsSharedPtr &gameComponent,
                         const gameFlagsSharedPtr &gameFlag,
                         const gameDataSharedPtr &gameData,
                         const renderEngineSharedPtr &render);  // updates the state of the teamState object

        
    private:

        bool objectsInitialized;  //  stores whether or not objects have been initialized

        teamComponentsSharedPtr component;  // instance of teamComponents object

        teamDataSharedPtr data;  //  instance of the teamData object

        teamFlagsSharedPtr flag;  // instance of teamFlags object

        teamGameDataSharedPtr gameData;  // instance of teamGameData object

        teamStateMachineSharedPtr stateMachine;  // instance of teamStateMachine object

        teamStatisticsSharedPtr statistics;  // instance of teamStatistics object

        offDefs offDef;  // stores whether to execute offense, defense or neither
};

#endif // _TEAMENTITY_H_
