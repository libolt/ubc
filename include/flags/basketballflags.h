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

#ifndef _BASKETBALLFLAGS_H_
#define _BASKETBALLFLAGS_H_

class basketballFlags
{
    public:
        basketballFlags();
        ~basketballFlags();

        bool getInitialized() const;  // retrieves the value of initialized
        void setInitialized(const bool &set);  // sets the value of initialized

        bool getMaxHeightReached() const;  // retrieves the value of maxHeightReached
        void setMaxHeightReached(const bool &set);  // sets the value of maxHeightReached

        bool getMinHeightReached() const;  // retrieves the value of minHeightReached
        void setMinHeightReached(const bool &set);  // sets minHeightReached

        bool getTipOffStart() const;  // retrieves the value of tipOffStart
        void setTipOffStart(const bool &set);  // sets the value of tipOFfStart

        bool getTipOff() const;  // retrieves the value of tipOff
        void setTipOff(const bool &set);  // sets the value of tipOff

        bool getDribblingStart() const;  // retrieves the value of dribblingStart
        void setDribblingStart(const bool &set);  // sets the value of dribblingStart

        bool getDribbling() const;  // retrieves the value of dribbling
        void setDribbling(const bool &set);  // sets the value of dribbling

        bool getMovement() const;  // retrieves the value of movement
        void setMovement(const bool &set);  // sets the value of movement

        bool getDirectChange() const;  // retrieves the value of directChange
        void setDirectChange(const bool &set);  // sets the value of directChange

        bool getPlayerControlled() const;  // retrieves the value of player controlled
        void setPlayerControlled(const bool &set);  // sets the value of playerControlled

        bool getNumberSet() const;  // retrieves the value of numberSet
        void setNumberSet(const bool &set);  // sets the value of numberSet

        bool getCourtPositionChanged() const;  // retrieves the value of courtPositionChanged
        void setCourtPositionChanged(const bool &set);  // sets the value of courtPositionChanged

    private:

        bool numberSet;  // stores whether the the instance number had been set

        bool maxHeightReached;  // stores whether the maximum height has been reached

        bool minHeightReached;  // stores whether the minimum height has been reached

        bool tipOffStart;  // defines whether or not to setup ball position for tip off
        bool tipOff;  // defines whether or not tip off is executing
        bool dribblingStart;  // defines whether or not to start the dribbling animation
        bool dribbling;  // defines whether or not the ball is being dribbled

        bool movement;  // basketball has been moved by an outside force.
        bool directChange; // baskteball has changed direction

        bool playerControlled;  // set to true if human or cpu player has the ball

        // if the court position has changed then this flag is set
        bool courtPositionChanged;

        bool initialized;  // stores whether the basketball entity object has been initialized

};


#endif // _BASKETBALLFLAGS_H_
