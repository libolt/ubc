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
 
#ifndef _LOAD_PLAYERS_H_
#define _LOAD_PLAYERS_H_

#include <string>
#include <vector>
#include <unordered_map>
#include "load/load.h"
#include "utilities/typedefs.h"

class loadPlayers : public loader
{
    public:
    
    loadPlayers();  // constructor
    ~loadPlayers();  // destructor
    
    stdStringVec getPlayerFiles() const;  // retrieves the value of playerFiles
    void setPlayerFiles(const stdStringVec &set);  // sets the value of playerFiles

    playerEntityMSharedPtr getPInstance() const;  // retrieves the value of pInstance
    void setPInstance(const playerEntityMSharedPtr &set);  // sets the value of pInstance

    bool getPlayerFilesLoaded() const;  // retrieves the value of playerFilesLoaded
    void setPlayerFilesLoaded(const bool &set);  // sets the value of playerFilesLoaded
    
    bool checkIfPlayersLoaded();  // checks if players have been loaded into pInstance

    // Players
    playerEntityMSharedPtr loadPlayerFiles();  // loads player data from XML files
    stdStringVec loadPlayerListFile(const std::string &fileName);  // loads list of player files from players.xml
    playerEntitySharedPtr loadPlayerFile(const std::string &fileName);  // loads data from the player XML files

    void loadModel(playerComponentsSharedPtr &component, playerFlagsSharedPtr &flag, const renderEngineSharedPtr &render);  // loads selected basketball model

    private:
    
        playerEntityMSharedPtr pInstance;
        stdStringVec playerFiles;  // stores list of player xml files
        bool playerFilesLoaded;

};

#endif
