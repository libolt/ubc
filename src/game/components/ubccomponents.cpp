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

#include "components/ubccomponents.h"

UBCComponents::UBCComponents()  // constructor
{
    gameE = nullptr;
    gui = nullptr;
    game = nullptr;
    input = nullptr;
}

UBCComponents::~UBCComponents() = default;  // destructor

gameEngineSharedPtr UBCComponents::getGameE() const  // retrieves the value of gameE
{
    return (gameE);
}
void UBCComponents::setGameE(const gameEngineSharedPtr &set)  // sets the value of gameE
{
    gameE = set;
}

GUISystemSharedPtr UBCComponents::getGui() const  // retrieves the value of gui
{
    return (gui);
}
void UBCComponents::setGui(const GUISystemSharedPtr &set)  // sets the value of gui
{
    gui = set;
}

UBCGameSharedPtr UBCComponents::getGame() const  // retrieves the value of game
{
    return (game);
}
void UBCComponents::setGame(const UBCGameSharedPtr &set)  // sets the value of game
{
    game = set;
}

UBCInputSharedPtr UBCComponents::getInput() const // retrieves the value of input
{
    return (input);
}
void UBCComponents::setInput(const UBCInputSharedPtr &set)  // sets the value of input
{
    input = set;
}
