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

#ifndef _TEAMENTITY_H_
#define _TEAMENTITY_H_

#include "utilities/typedefs.h"

class teamEntity
{
    public:

        teamEntity();  // constructor
        ~teamEntity();  // destructor

        bool getInitialized();  // retrieves the value of initialized
        void setInitialized(bool set);  // sets the value of initialized

        teamComponentsSharedPtr getComponent();  // retrieves the value of component
        void setComponent(teamComponentsSharedPtr set);  // sets the value of component

        teamDataSharedPtr getData();  // retrieves the value of data
        void setData(teamDataSharedPtr set);  // sets the value of data

        teamFlagsSharedPtr getFlag();  // retrieves the value of flag
        void setFlag(teamFlagsSharedPtr set);  // sets the value of flag

        teamGameDataSharedPtr getGameData();  // retrieves the value of gameData
        void setGameData(teamGameDataSharedPtr set);  // sets the value of gameData

        teamStatisticsSharedPtr getStatistics();  // retrieves the value of statistics
        void setStatistics(teamStatisticsSharedPtr set);  // sets the value of statistics

        bool initialize();  // initializes teamEntity object

        void updateState(gameComponentsSharedPtr gameComponent, gameFlagsSharedPtr gameFlag, gameDataSharedPtr gameData, renderEngineSharedPtr render);  // updates the state of the teamState object

        
    private:

        bool initialized;  // stores whether object has been initialized

        teamComponentsSharedPtr component;  // instance of teamComponents object

        teamDataSharedPtr data;  //  instance of the teamData object

        teamFlagsSharedPtr flag;  // instance of teamFlags object

        teamGameDataSharedPtr gameData;  // instance of teamGameData object

        teamStatisticsSharedPtr statistics;  // instance of teamStatistics object

};

#endif // _TEAMENTITY_H_
