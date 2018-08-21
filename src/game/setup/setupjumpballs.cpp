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

#include "setup/setupjumpballs.h"
#include "entity/basketballentity.h"
#include "flags/gameflags.h"
#include "jumpballs/jumpballs.h"
#include "utilities/conversion.h"
#include "utilities/logging.h"


setupJumpBalls::setupJumpBalls()  // constructor
{
    
}
setupJumpBalls::~setupJumpBalls()  // destructor
{
    
}

jumpBallsSharedPtr setupJumpBalls::checkifJumpBallCreated(jumpBallsSharedPtr jumpBall, gameFlagsSharedPtr flag)  // checks if jumpBall object has been created
{
    conversionSharedPtr convert = conversion::Instance();
    std::string func = "setupJumpballs::checkifJumpBallCreated()";

    logMsg(func +" begin");

    if (!flag->getJumpBallCreated())
    {
        logMsg(func +" jumpBall not created yet!");
        jumpBallsSharedPtr tempJumpBall(new jumpBalls);
        jumpBall = tempJumpBall;
        if (jumpBall != nullptr)
        {
            flag->setJumpBallCreated(true);
        }
        else
        {
            
        }
    }
    else
    {
        logMsg(func +" jumpBall Already created!");
    }

    logMsg(func +" end");

    return (jumpBall);
}
