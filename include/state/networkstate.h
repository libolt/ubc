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

#ifndef _NETWORKSTATE_H_
#define _NETWORKSTATE_H_

#include "state/state.h"
//#include "state/gamestateshared.h"
//#include "ubc/ubc.h"

#include "utilities/typedefs.h"

// Forward declarations
class teamEntity;
class networkEngine;

class networkState : public state
{
    public:
        networkState();  // constructor
        ~networkState();  // destructor
        
        // getters and setters
        networkEngineSharedPtr getNetworkE() const;  // retrieves the value of network
        void setNetwork(const networkEngineSharedPtr &set);  // sets the value of network

        void processLocalInput(teamEntityVecSharedPtr activeTeamInstance);  // processes local input for sending to remote system
        void processRemoteInput();  // processes input received from a remote system
        void processNetworkEvents(
                const teamEntityVecSharedPtr &activeTeamInstance);  // processes events received from network connection.
        void processNetworkPlayerEvents(
                const teamEntityVecSharedPtr &activeTeamInstance);  // processes player evernts received from network connection

    
    private:
        networkEngineSharedPtr network;
};
#endif
