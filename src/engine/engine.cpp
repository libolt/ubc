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

#include "engine/engine.h"

engine::engine()  // constructor
{
    windowWidth = 0;
    windowHeight = 0;
}

engine::~engine() = default;  // destructor

 
float engine::getWindowWidth() const  // retrieves the value of windowWidth
{
    return (windowWidth);
}
void engine::setWindowWidth(const float &set)  // sets the value of windowWidth
{
    windowWidth = set;
}

float engine::getWindowHeight() const  // retrieves the value of windowHeight
{
    return (windowHeight);
}
void engine::setWindowHeight(const float &set)  // sets the value of windowHeight
{
    windowHeight = set;
}
