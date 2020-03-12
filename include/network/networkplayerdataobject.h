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

#ifndef _NETWORKPLAYERDATAOBJECT_H_
#define _NETWORKPLAYERDATAOBJECT_H_

#include <iostream>
#include "utilities/enums.h"

class networkPlayerDataObject 
{
    public:
	
    int ID;
    int packetType;

    friend std::ostream& operator<< (std::ostream& out,
                                     networkPlayerDataObject& object)
    {
        out << object.ID << " " << object.packetType;   //The space (" ") is necessari for separete elements
        return out;
    }

    friend std::istream& operator>> (std::istream& in,
                                     networkPlayerDataObject& object)
    {
        in >> object.ID;
        in >> object.packetType;
        return in;
    }
    private:
};
 
#endif
 
