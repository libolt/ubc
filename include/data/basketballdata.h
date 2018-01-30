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

#ifndef _BASKETBALLDATA_H_
#define _BASKETBALLDATA_H_

#include <string>

class basketballData
{
    public:
        basketballData();  // constructor
        ~basketballData();  // destructor
        
        std::string  getName();   // retrieves the value of name
        void setName(std::string set);  // setes the value of name

        std::string getModelFileName();  // retrieves the value of modelFileName
        void setModelFileName(std::string set);  // sets the value of modelFileName

    private:
        std::string name;  // stores the object name
        std::string modelFileName;  // stores the modelFileName
};
#endif
