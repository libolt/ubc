/***************************************************************************
 *   Copyright (C) 1999 - 2016 by Mike McLean                              *
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
 
#include "state/inputstate.h"
#include "logging.h"
#include "engine/inputengine.h"
//#include "engine/gameengine.h"

boost::shared_ptr<inputEngine> inputState::inputE;  // the inputEngine object

boost::shared_ptr<inputEngine> inputState::getInputE()  // retrieves the value of inputE
{
    return (inputE);
}
void inputState::setInputE(boost::shared_ptr<inputEngine> set)  // sets the value of inputE
{
    inputE = set;
}

bool inputState::process()  // processes input
{
    logMsg("inputState->process menuReceiveKeyPress == " +inputE->getKeyPressed());
//    exit(0);
    return (true);
}
