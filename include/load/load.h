/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
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
 
#ifndef _LOAD_H_
#define _LOAD_H_

#include <string>
#include <vector>
#include <unordered_map>

#include "Ogre.h"
#include "SDL.h"

#include "tinyxml2.h"

#include "typedefs.h"

//#include "state/basketballstate.h"
//#include "state/courtstate.h"
//#include "state/hoopstate.h"
//#include "state/gamestate.h"
//#include "state/teamstate.h"
//#include "offenseplays.h"
//#include "userinput.h"

class basketballState;
class courtState;
class hoopState;
class gameState;
class playerState;
class teamState;
class offensePlays;
class usersInput;

class loader
{
public:

    loader();  // constructor
    ~loader(); // destructor   
    
    stdStringVec pathSplit(const std::string paths);
    std::string findFile(std::string fileName);
//	string * pathArray;

    stdStringVec getOffensePlayFiles();  // retrieves the value of offensePlayFiles
    void setOffensePlayFiles(stdStringVec set);  // sets the value of offensePlayFiles
    
    stdStringVec getPlayerFiles();  // retrieves the value of playerFiles
    void setPlayerFiles(stdStringVec set);  // sets the value of playerFiles

    stdStringVec getTeamFiles();  // retrieves the value of teamFiles
    void setTeamFiles(stdStringVec set);  // sets the value of teamFiles

    stdStringVec getUsersInputFiles();  // retrieves the value of userInputFiles
    void setUsersInputFiles(stdStringVec set);  // sets the value of userInputFiles
    
    hoopStateUMSharedPtr  getHInstance();  // retrieves the value of hInstance
    void setHInstance(hoopStateUMSharedPtr  set);  // sets the value of hInstance

    offensePlaysVecSharedPtr getOPInstance();  // retrieves the value of opInstance
    void setOPInstance(offensePlaysVecSharedPtr set);  // sets the value of opInstance
    
    playerEntityUMSharedPtr getPInstance();  // retrieves the value of pInstance
    void setPInstance(playerEntityUMSharedPtr set);  // sets the value of pInstance
    
    teamStateUMSharedPtr getTInstance();  // retrieves the value of tInstance
    void setTInstance(teamStateUMSharedPtr set);  // sets the value of tInstance
    
    usersInputVecSharedPtr getUIInstance();  // retrieves the value of uiInstance
    void setUIInstance(usersInputVecSharedPtr set);  // sets the value of uiInstance
              
    bool getOffensePlayFilesLoaded();  // retrieves the value of offensePlaFilesLoaded
    void setOffensePlayFilesLoaded(bool set);  // sets the value of offensePlayFilesLoaded
    
    bool getPlayerFilesLoaded();  // retrieves the value of playerFilesLoaded
    void setPlayerFilesLoaded(bool set);  // sets the value of playerFilesLoaded
    
    bool getTeamFilesLoaded();  // retrieves the value of teamFilesLoaded
    void setTeamFilesLoaded(bool set);  // sets the value of teamFilesLoaded
    
    bool getUsersInputFilesLoaded();  // retrieves the value of userInputFilesLoaded
    void setUsersInputFilesLoaded(bool set);  // sets the value of userInputFilesLoaded  

    bool loadXMLFile(std::string fileName);

    int readFile(const char *sourceFile, char **destination);  // reads in the XML file

    SDL_RWops *readBinaryFile(const char *sourceFile);
    
    bool checkIfHoopsLoaded();  // checks if the hooops have been loaded into hInstance
    bool checkIfOffensePlaysLoaded();  // checks if offense plays have been loaded into opInstance
    bool checkIfPlayersLoaded();  // checks if players have been loaded into pInstance
    bool checkIfTeamsLoaded();  // checks if teams have been loaded into tInstance
    bool checkIfUsersInputsLoaded();  // checks if uset inputs have been loaded into uiInstance
        
    // Hoops
    hoopStateUMSharedPtr  loadHoops();  // load hoop XML files
    stdStringVec loadHoopListFile(std::string fileName);  // load the list of hoops from hoops.xml
    hoopStateSharedPtr loadHoopFile(std::string fileName);  // loads data from the hoop XML files.

    //Offense
    offensePlaysVecSharedPtr loadOffensePlays();  // load offense plays from XML files
    stdStringVec loadOffensePlayListFile(std::string fileName);  // loads the list of offense play files from plays.xml
    offensePlaysSharedPtr loadOffensePlayFile(std::string fileName); // loads data from the offense play XML files

   // Players
    playerEntityUMSharedPtr loadPlayers();  // loads player data from XML files
    stdStringVec loadPlayerListFile(std::string fileName);  // loads list of player files from players.xml
    playerEntitySharedPtr loadPlayerFile(std::string fileName);  // loads data from the player XML files

    // Teams
    teamStateUMSharedPtr loadTeams();  // loads team data from XML files
    stdStringVec loadTeamListFile(std::string fileName);  // loads list of team files from teams.xml
    teamStateSharedPtr loadTeamFile(std::string fileName);  // loads data from the team XML files

    // User input
    usersInputVecSharedPtr loadUsersInputs();  // load user input XML files
    stdStringVec loadUsersInputListFile(std::string fileName);  // load the list of user input configs from userinputs.xml
    usersInputSharedPtr loadUsersInputFile(std::string fileName);  // loads data from the user input XML files.

    
protected:
//    loader();
//    loader(const loader&);
//    loader& operator= (const loader&);

private:

    static hoopStateUMSharedPtr  hInstance;
    static offensePlaysVecSharedPtr opInstance;
    static playerEntityUMSharedPtr pInstance;
    static teamStateUMSharedPtr tInstance;
    static usersInputVecSharedPtr uiInstance;

    static stdStringVec hoopFiles;  // stores list of hoop xml files
    static stdStringVec offensePlayFiles;  // stores list of offense play xml files
    static stdStringVec playerFiles;  // stores list of player xml files
    static stdStringVec teamFiles;	 // stores list of team xml files
    static stdStringVec usersInputFiles;  // stores list of court xml files

    // determines whether files have been loaded successfully
    static bool hoopFilesLoaded;
    static bool offensePlayFilesLoaded;
    static bool playerFilesLoaded;
    static bool teamFilesLoaded;
    static bool userInputFilesLoaded;
    static int count;  // counts number of times a function has been called
};


#endif

