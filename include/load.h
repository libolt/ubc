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
    std::vector<std::string> pathSplit(const std::string paths);
    std::string findFile(std::string fileName);
//	string * pathArray;

    std::vector<std::string> getBasketballFiles();  // retrieves the value of basketballFiles
    void setBasketballFiles(std::vector<std::string> set);  // sets the value of basketballFiles

    std::vector<std::string> getCourtFiles();  // retrieves the value of courtFiles
    void setCourtFiles(std::vector<std::string> set);  // sets the value of courtFiles

    std::vector<std::string> getOffensePlayFiles();  // retrieves the value of offensePlayFiles
    void setOffensePlayFiles(std::vector<std::string> set);  // sets the value of offensePlayFiles
    
    std::vector<std::string> getPlayerFiles();  // retrieves the value of playerFiles
    void setPlayerFiles(std::vector<std::string> set);  // sets the value of playerFiles

    std::vector<std::string> getTeamFiles();  // retrieves the value of teamFiles
    void setTeamFiles(std::vector<std::string> set);  // sets the value of teamFiles

    std::vector<std::string> getUserInputFiles();  // retrieves the value of userInputFiles
    void setUserInputFiles(std::vector<std::string> set);  // sets the value of userInputFiles

    std::vector<basketballStateSharedPtr > getBInstance();  // retrieves the value of bInstance
    void setBInstance(std::vector<basketballStateSharedPtr > set);  // sets the value of bInstance
    
    std::vector<courtStateSharedPtr > getCInstance();  // retrieves the value of cInstance
    void setCInstance(std::vector<courtStateSharedPtr > set);  // sets the value of cInstance
  
    std::vector<offensePlaysSharedPtr> getOPInstance();  // retrieves the value of opInstance
    void setOPInstance(std::vector<offensePlaysSharedPtr> set);  // sets the value of opInstance
    
    std::vector<playerStateSharedPtr > getPInstance();  // retrieves the value of pInstance
    void setPInstance(std::vector<playerStateSharedPtr > set);  // sets the value of pInstance
    
    static std::vector<teamStateSharedPtr > getTInstance();  // retrieves the value of tInstance
    void setTInstance(std::vector<teamStateSharedPtr > set);  // sets the value of tInstance
    
    std::vector<userInputSharedPtr > getUIInstance();  // retrieves the value of uiInstance
    void setUIInstance(std::vector<userInputSharedPtr > set);  // sets the value of uiInstance
    
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
    bool checkIfOffensePlaysLoaded();  // checks if offense plays have been loaded into opInstance
    bool checkIfPlayersLoaded();  // checks if players have been loaded into pInstance
    bool checkIfTeamsLoaded();  // checks if teams have been loaded into tInstance
    bool checkIfUserInputsLoaded();  // checks if uset inputs have been loaded into uiInstance
    
    // Basketballs
    std::vector<basketballStateSharedPtr > loadBasketballs();  // load basketball XML files
    std::vector<std::string> loadBasketballListFile(std::string fileName);  // load the list of basketballs from basketballs.xml
    basketballStateSharedPtr loadBasketballFile(std::string fileName);  // loads data from the basketball XML files.

    // Courts
    std::vector<courtStateSharedPtr > loadCourts();  // load court XML files
    std::vector<std::string> loadCourtListFile(std::string fileName);  // load the list of courts from courts.xml
    courtStateSharedPtr loadCourtFile(std::string fileName);  // loads data from the court XML files.

    //Offense
    std::vector<offensePlaysSharedPtr> loadOffensePlays();  // load offense plays from XML files
    std::vector<std::string> loadOffensePlayListFile(std::string fileName);  // loads the list of offense play files from plays.xml
    offensePlaysSharedPtr loadOffensePlayFile(std::string fileName); // loads data from the offense play XML files

   // Players
    std::vector<playerStateSharedPtr > loadPlayers();  // loads player data from XML files
    std::vector<std::string> loadPlayerListFile(std::string fileName);  // loads list of player files from players.xml
    playerStateSharedPtr loadPlayerFile(std::string fileName);  // loads data from the player XML files

    // Teams
    std::vector<teamStateSharedPtr > loadTeams();  // loads team data from XML files
    std::vector<std::string> loadTeamListFile(std::string fileName);  // loads list of team files from teams.xml
    bool loadTeamFile(std::string fileName);  // loads data from the team XML files

    // User input
    std::vector<userInputSharedPtr > loadUserInputs();  // load user input XML files
    std::vector<std::string> loadUserInputListFile(std::string fileName);  // load the list of user input configs from userinputs.xml
    userInputSharedPtr loadUserInputFile(std::string fileName);  // loads data from the user input XML files.

    
protected:
//    loader();
//    loader(const loader&);
//    loader& operator= (const loader&);

private:
    static std::vector<basketballStateSharedPtr> bInstance;
    static std::vector<courtStateSharedPtr> cInstance;
    static std::vector<offensePlaysSharedPtr> opInstance;
    static std::vector<playerStateSharedPtr> pInstance;
    static std::vector<teamStateSharedPtr > tInstance;
    static std::vector<userInputSharedPtr > uiInstance;

    static std::vector<std::string> basketballFiles;  // stores list of basketball xml files
    static std::vector<std::string> courtFiles;  // stores list of court xml files
    static std::vector<std::string> offensePlayFiles;  // stores list of offense play xml files
    static std::vector<std::string> playerFiles;  // stores list of player xml files
    static std::vector<std::string> teamFiles;	 // stores list of team xml files
    static std::vector<std::string> userInputFiles;  // stores list of court xml files

    // determines whether files have been loaded successfully
    static bool basketballFilesLoaded;
    static bool courtFilesLoaded;
    static bool offensePlayFilesLoaded;
    static bool playerFilesLoaded;
    static bool teamFilesLoaded;
    static bool userInputFilesLoaded;
    static int count;  // counts number of times a function has been called
};


#endif

