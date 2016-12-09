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

 
#ifndef _LOAD_H_
#define _LOAD_H_

#include <string>
#include <vector>
#include <unordered_map>
#include <boost/shared_ptr.hpp>

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
class userInput;

class loader
{
public:

    loader();  // constructor
    ~loader(); // destructor   
    stdStringVec pathSplit(const std::string paths);
    std::string findFile(std::string fileName);
//	string * pathArray;

    stdStringVec getBasketballFiles();  // retrieves the value of basketballFiles
    void setBasketballFiles(stdStringVec set);  // sets the value of basketballFiles

    stdStringVec getCourtFiles();  // retrieves the value of courtFiles
    void setCourtFiles(stdStringVec set);  // sets the value of courtFiles

    stdStringVec getOffensePlayFiles();  // retrieves the value of offensePlayFiles
    void setOffensePlayFiles(stdStringVec set);  // sets the value of offensePlayFiles
    
    stdStringVec getPlayerFiles();  // retrieves the value of playerFiles
    void setPlayerFiles(stdStringVec set);  // sets the value of playerFiles

    stdStringVec getTeamFiles();  // retrieves the value of teamFiles
    void setTeamFiles(stdStringVec set);  // sets the value of teamFiles

    stdStringVec getUserInputFiles();  // retrieves the value of userInputFiles
    void setUserInputFiles(stdStringVec set);  // sets the value of userInputFiles

    basketballStateVecSharedPtr getBInstance();  // retrieves the value of bInstance
    void setBInstance(basketballStateVecSharedPtr set);  // sets the value of bInstance
    
    std::unordered_map <size_t, courtStateSharedPtr>  getCInstance();  // retrieves the value of cInstance
    void setCInstance(std::unordered_map <size_t, courtStateSharedPtr>  set);  // sets the value of cInstance
  
    std::unordered_map <size_t, hoopStateSharedPtr>  getHInstance();  // retrieves the value of hInstance
    void setHInstance(std::unordered_map <size_t, hoopStateSharedPtr>  set);  // sets the value of hInstance

    offensePlaysVecSharedPtr getOPInstance();  // retrieves the value of opInstance
    void setOPInstance(offensePlaysVecSharedPtr set);  // sets the value of opInstance
    
    std::unordered_map <size_t, playerStateSharedPtr> getPInstance();  // retrieves the value of pInstance
    void setPInstance(std::unordered_map <size_t, playerStateSharedPtr> set);  // sets the value of pInstance
    
    static std::unordered_map <size_t, teamStateSharedPtr> getTInstance();  // retrieves the value of tInstance
    void setTInstance(std::unordered_map <size_t, teamStateSharedPtr> set);  // sets the value of tInstance
    
    userInputVecSharedPtr getUIInstance();  // retrieves the value of uiInstance
    void setUIInstance(userInputVecSharedPtr set);  // sets the value of uiInstance
    
    static bool getBasketballFilesLoaded();  // retrieves the value of basketballFilesLoaded
    void setBasketballFilesLoaded(bool set);  // sets the value of basketballFilesLoaded
    
    static bool getCourtFilesLoaded();  // retrieves the value of courtFilesLoaded
    void setCourtFilesLoaded(bool set);  // sets the value of courtFilesLoaded
    
    static bool getOffensePlayFilesLoaded();  // retrieves the value of offensePlaFilesLoaded
    void setOffensePlayFilesLoaded(bool set);  // sets the value of offensePlayFilesLoaded
    
    static bool getPlayerFilesLoaded();  // retrieves the value of playerFilesLoaded
    void setPlayerFilesLoaded(bool set);  // sets the value of playerFilesLoaded
    
    static bool getTeamFilesLoaded();  // retrieves the value of teamFilesLoaded
    void setTeamFilesLoaded(bool set);  // sets the value of teamFilesLoaded
    
    static bool getUserInputFilesLoaded();  // retrieves the value of userInputFilesLoaded
    void setUserInputFilesLoaded(bool set);  // sets the value of userInputFilesLoaded  

    bool loadXMLFile(std::string fileName);

    int readFile(const char *sourceFile, char **destination);  // reads in the XML file

    SDL_RWops *readBinaryFile(const char *sourceFile);
    
    bool checkIfBasketballsLoaded();  // checks if basketballs have been loaded into bInstance
    bool checkIfCourtsLoaded();  // checks if courts have been loaded into cInstance
    bool checkIfHoopsLoaded();  // checks if the hooops have been loaded into hInstance
    bool checkIfOffensePlaysLoaded();  // checks if offense plays have been loaded into opInstance
    bool checkIfPlayersLoaded();  // checks if players have been loaded into pInstance
    bool checkIfTeamsLoaded();  // checks if teams have been loaded into tInstance
    bool checkIfUserInputsLoaded();  // checks if uset inputs have been loaded into uiInstance
    
    // Basketballs
    basketballStateVecSharedPtr loadBasketballs();  // load basketball XML files
    stdStringVec loadBasketballListFile(std::string fileName);  // load the list of basketballs from basketballs.xml
    basketballStateSharedPtr loadBasketballFile(std::string fileName);  // loads data from the basketball XML files.
    
    // Courts
    std::unordered_map <size_t, courtStateSharedPtr>  loadCourts();  // load court XML files
    stdStringVec loadCourtListFile(std::string fileName);  // load the list of courts from courts.xml
    courtStateSharedPtr loadCourtFile(std::string fileName);  // loads data from the court XML files.

    // Hoops
    std::unordered_map <size_t, hoopStateSharedPtr>  loadHoops();  // load hoop XML files
    stdStringVec loadHoopListFile(std::string fileName);  // load the list of hoops from hoops.xml
    hoopStateSharedPtr loadHoopFile(std::string fileName);  // loads data from the hoop XML files.

    //Offense
    offensePlaysVecSharedPtr loadOffensePlays();  // load offense plays from XML files
    stdStringVec loadOffensePlayListFile(std::string fileName);  // loads the list of offense play files from plays.xml
    offensePlaysSharedPtr loadOffensePlayFile(std::string fileName); // loads data from the offense play XML files

   // Players
    std::unordered_map<size_t, playerStateSharedPtr> loadPlayers();  // loads player data from XML files
    stdStringVec loadPlayerListFile(std::string fileName);  // loads list of player files from players.xml
    playerStateSharedPtr loadPlayerFile(std::string fileName);  // loads data from the player XML files

    // Teams
    std::unordered_map <size_t, teamStateSharedPtr> loadTeams();  // loads team data from XML files
    stdStringVec loadTeamListFile(std::string fileName);  // loads list of team files from teams.xml
    teamStateSharedPtr loadTeamFile(std::string fileName);  // loads data from the team XML files

    // User input
    userInputVecSharedPtr loadUserInputs();  // load user input XML files
    stdStringVec loadUserInputListFile(std::string fileName);  // load the list of user input configs from userinputs.xml
    userInputSharedPtr loadUserInputFile(std::string fileName);  // loads data from the user input XML files.

    
protected:
//    loader();
//    loader(const loader&);
//    loader& operator= (const loader&);

private:
    static basketballStateVecSharedPtr bInstance;
    static std::unordered_map <size_t, courtStateSharedPtr>  cInstance;
    static std::unordered_map <size_t, hoopStateSharedPtr>  hInstance;
    static offensePlaysVecSharedPtr opInstance;
    static std::unordered_map <size_t, playerStateSharedPtr> pInstance;
    static std::unordered_map <size_t, teamStateSharedPtr> tInstance;
    static userInputVecSharedPtr uiInstance;

    static stdStringVec basketballFiles;  // stores list of basketball xml files
    static stdStringVec courtFiles;  // stores list of court xml files
    static stdStringVec hoopFiles;  // stores list of hoop xml files
    static stdStringVec offensePlayFiles;  // stores list of offense play xml files
    static stdStringVec playerFiles;  // stores list of player xml files
    static stdStringVec teamFiles;	 // stores list of team xml files
    static stdStringVec userInputFiles;  // stores list of court xml files

    // determines whether files have been loaded successfully
    static bool basketballFilesLoaded;
    static bool courtFilesLoaded;
    static bool hoopFilesLoaded;
    static bool offensePlayFilesLoaded;
    static bool playerFilesLoaded;
    static bool teamFilesLoaded;
    static bool userInputFilesLoaded;
    static int count;  // counts number of times a function has been called
};


#endif

