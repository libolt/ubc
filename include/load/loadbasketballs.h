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
 
#ifndef _LOAD_BASKETBALLS_H_
#define _LOAD_BASKETBALLS_H_

#include <string>
#include <vector>
#include <unordered_map>

#include "load/load.h"
#include "utilities/typedefs.h"

class loadBasketballs  : public loader
{
    public:
    
    loadBasketballs();  // constructor
    ~loadBasketballs();  // destructor
    
    stdStringVec getBasketballFiles() const;  // retrieves the value of basketballFiles
    void setBasketballFiles(const stdStringVec &set);  // sets the value of basketballFiles

    bool getBasketballFilesLoaded() const;  // retrieves the value of basketballFilesLoaded
    void setBasketballFilesLoaded(const bool &set);  // sets the value of basketballFilesLoaded

    basketballEntityMSharedPtr getBInstance() const;  // retrieves the value of bInstance
    void setBInstance(const basketballEntityMSharedPtr &set);  // sets the value of bInstance
    
    bool checkIfBasketballFilesLoaded();  // checks if basketballs have been loaded into bInstance

    // Basketballs
    basketballEntityMSharedPtr loadFiles();  // load basketball XML files
    stdStringVec loadListFile(const std::string &fileName);  // load the list of basketballs from basketballs.xml
    basketballEntitySharedPtr loadFile(const std::string &fileName);  // loads data from the basketball XML files.

    void loadModel(basketballComponentsSharedPtr &component, basketballDataSharedPtr &data, basketballFlagsSharedPtr &flag, const renderEngineSharedPtr &render);  // loads selected basketball model

    private:
    
    basketballEntityMSharedPtr bInstance;
    stdStringVec basketballFiles;  // stores list of basketball xml files
    bool basketballFilesLoaded;

};
#endif
