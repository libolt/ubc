/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean                              *
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
    //static loader *Instance();
    static boost::shared_ptr<loader> Instance();

    std::vector<std::string> pathSplit(const std::string paths);
    std::string findFile(std::string fileName);
//	string * pathArray;

    std::vector<std::string> getPlayerFiles();  // retrieves the value of playerFiles
    void setPlayerFiles(std::vector<std::string> set);  // sets the value of playerFiles

    std::vector<std::string> getTeamFiles();  // retrieves the value of teamFiles
    void setTeamFiles(std::vector<std::string> set);  // sets the value of teamFiles

    std::vector<std::string> getOffensePlayFiles();  // retrieves the value of offensePlayFiles
    void setOffensePlayFiles(std::vector<std::string> set);  // sets the value of offensePlayFiles

    
    std::vector<std::string> getBasketballFiles();  // retrieves the value of basketballFiles
    void setBasketballFiles(std::vector<std::string> set);  // sets the value of basketballFiles

    std::vector<std::string> getCourtFiles();  // retrieves the value of courtFiles
    void setCourtFiles(std::vector<std::string> set);  // sets the value of courtFiles

    std::vector<std::string> getUserInputFiles();  // retrieves the value of userInputFiles
    void setUserInputFiles(std::vector<std::string> set);  // sets the value of userInputFiles

    bool loadXMLFile(std::string fileName);

    int readFile(const char *sourceFile, char **destination);  // reads in the XML file

    SDL_RWops *readBinaryFile(const char *sourceFile);


    // Teams
    std::vector<boost::shared_ptr<teamState> > loadTeams();  // loads team data from XML files
    bool loadTeamListFile(std::string fileName);  // loads list of team files from teams.xml
    boost::shared_ptr<teamState> loadTeamFile(std::string fileName);  // loads data from the team XML files

    // Players
    std::vector<boost::shared_ptr<playerState> > loadPlayers();  // loads player data from XML files
    bool loadPlayerListFile(std::string fileName);  // loads list of player files from players.xml
    boost::shared_ptr<playerState> loadPlayerFile(std::string fileName);  // loads data from the player XML files

    //Offense
    std::vector<offensePlays> loadOffensePlays();  // load offense plays from XML files
    bool loadOffensePlayListFile(std::string fileName);  // loads the list of offense play files from plays.xml
    offensePlays loadOffensePlayFile(std::string fileName);	// loads data from the offense play XML files

    // Basketballs
    std::vector<basketballState> loadBasketballs();  // load basketball XML files
    bool loadBasketballListFile(std::string fileName);  // load the list of basketballs from basketballs.xml
    basketballState loadBasketballFile(std::string fileName);  // loads data from the basketball XML files.

    // Courts
    std::vector<courtState> loadCourts();  // load court XML files
    bool loadCourtListFile(std::string fileName);  // load the list of courts from courts.xml
    courtState loadCourtFile(std::string fileName);  // loads data from the court XML files.

    // User input
    std::vector<userInput> loadUserInputs();  // load user input XML files
    bool loadUserInputListFile(std::string fileName);  // load the list of user input configs from userinputs.xml
    userInput loadUserInputFile(std::string fileName);  // loads data from the user input XML files.

protected:
    loader();
    loader(const loader&);
    loader& operator= (const loader&);

private:
    static boost::shared_ptr<loader> pInstance;

    std::vector<std::string> playerFiles;  // stores list of player xml files
    std::vector<std::string> teamFiles;	 // stores list of team xml files
    std::vector<std::string> offensePlayFiles;  // stores list of offense play xml files
    std::vector<std::string> courtFiles;  // stores list of court xml files
    std::vector<std::string> basketballFiles;  // stores list of basketball xml files
    std::vector<std::string> userInputFiles;  // stores list of court xml files

};


#endif

