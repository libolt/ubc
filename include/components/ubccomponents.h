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

#ifndef _UBCCOMPONENTS_H_
#define _UBCCOMPONENTS_H_

#include "utilities/typedefs.h"

class UBCComponents
{
    public:

        UBCComponents();  // constructor
        ~UBCComponents();  // destructor
        
        gameEngineSharedPtr getGameE() const;  // retrieves the value of gameE
        void setGameE(const gameEngineSharedPtr &set);  // sets the value of gameE

        GUISystemSharedPtr getGui() const;  // retrieves the value of gui
        void setGui(const GUISystemSharedPtr &set);  // sets the value of gui

        UBCGameSharedPtr getGame() const;  // retrieves the value of game
        void setGame(const UBCGameSharedPtr &set);  // sets the value of game

        UBCInputSharedPtr getInput() const;  // retrieves the value of input
        void setInput(const UBCInputSharedPtr &set);  // sets the value of input

    private:
    
        static gameEngineSharedPtr gameE;  // the gameEngine object

        static GUISystemSharedPtr gui;  // the GUI object.

        static UBCGameSharedPtr game;  // static copy of game class

        static UBCInputSharedPtr input;  // static copy of input class

};

#endif
