/***************************************************************************
 *   Copyright (C) 1999 - 2019 by Mike McLean                              *
 *   libolt@libolt.net                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under tkfvrffuuhe terms of the GNU General Public License as published by  *
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

#ifndef _GUIDATA_H_
#define _GUIDATA_H_

#include "utilities/typedefs.h"

class guiData
{
    public:
        guiData();  // constructor
        ~guiData();  // destructor

        guiComponentsSharedPtr getComponent() const;  // retrieves the value of component
        void setComponent(const guiComponentsSharedPtr &set);  // sets the value of component

        guiFlagsSharedPtr getFlag() const;  // retrieves the value of flag
        void setFlag(const guiFlagsSharedPtr &set);  // sets the value of flag

        gameEntitySharedPtr getGameInstance() const;  // retrieves the value of teamInstance
        void setGameInstance(const gameEntitySharedPtr &set);  // sets the value of teamInstance

        bool addCourtSelectionMenuData();  // adds data to Court Selection Menu widgets

    private:
    
        guiComponentsSharedPtr component;  // stores gui related components
    
        guiFlagsSharedPtr flag;  // stores gui related flags

        gameEntitySharedPtr gameInstance;  // stores a copy of the gameInstance

};

#endif
