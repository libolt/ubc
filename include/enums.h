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

#ifndef _ENUMS_H_
#define _ENUMS_H_

    enum inputMaps { INNO, INUP, INDOWN, INLEFT, INRIGHT, INUPLEFT, INUPRIGHT, INDOWNLEFT, INDOWNRIGHT, INSHOOTBLOCK, INPASSSTEAL, INPAUSE, INSTARTSELECT, INQUIT, INBACKSPACE, INRETURN }; // map of human player input
    enum inputKeyMaps  // maps input to appropriate keys
    {
        INKEY_A = 'a',
        INKEY_B = 'b',
        INKEY_C = 'c',
        INKEY_D = 'd',
        INKEY_E = 'e',
        INKEY_F = 'f',
        INKEY_G = 'g',
        INKEY_H = 'h',
        INKEY_I = 'i',
        INKEY_J = 'j',
        INKEY_K = 'k',
        INKEY_L = 'l',
        INKEY_M = 'm',
        INKEY_N = 'n',
        INKEY_O = 'o',
        INKEY_P = 'p',
        INKEY_Q = 'q',
        INKEY_R = 'r',
        INKEY_S = 's',
        INKEY_T = 't',
        INKEY_U = 'u',
        INKEY_V = 'v',
        INKEY_W = 'w',
        INKEY_X = 'x',
        INKEY_Y = 'y',
        INKEY_Z = 'z',
        INKEY_BACKSPACE = 'bsp',
        INKEY_RETURN = 'rtn',
        INKEY_ESCAPE = 'esc',
        INKEY_TAB = 'tab',
        INKEY_SPACE = 'spc',
        INKEY_LSHIFT = 'lsft',
        INKEY_LCTRL = 'lctl',
        INKEY_LALT = 'lalt',
        INKEY_LGUI = 'lgui',
        INKEY_RSHIFT = 'rsft',
        INKEY_RCTRL = 'rctl',
        INKEY_RALT = 'ralt',
        INKEY_RGUI = 'rgui',
        INKEY_MENU = 'menu',
        INKEY_CAPSLOCK = 'caps',
        INKEY_F1 = 'f1',
        INKEY_F2 = 'f2',
        INKEY_F3 = 'f3',
        INKEY_F4 = 'f4',
        INKEY_F5 = 'f5',
        INKEY_F6 = 'f6',
        INKEY_F7 = 'f7',
        INKEY_F8 = 'f8',
        INKEY_F9 = 'f9',
        INKEY_F10 = 'f10',
        INKEY_F11 = 'f11',
        INKEY_F12 = 'f22',
        INKEY_UP = 'up',
        INKEY_DOWN = 'down',
        INKEY_LEFT = 'left',
        INKEY_RIGHT = 'rght',
        INKEY_SCROLLLOCK = 'scrl',
        INKEY_HOME = 'hme',
        INKEY_PRTSCN = 'prts',
        INKEY_PAUSE_BREAK = 'psbk',
        INKEY_INSERT = 'inst',
        INKEY_DELETE = 'del',
        INKEY_PAGEUP = 'pgup',
        INKEY_PAGEDOWN = 'pgdn',
        INKEY_END = 'end',
        INKEY_NUMLOCK = 'nmlk',
        INKEY_DIVIDE = 'div',
        INKEY_MULTIPLY = 'mult',
        INKEY_MINUS = 'min',
        INKEY_PLUS = 'plus',
        INKEY_ENTER = 'entr',
        INKEY_PERIOD = '.',
        INKEY_0 = '0',
        INKEY_1 = '1',
        INKEY_2 = '2',
        INKEY_3 = '3',
        INKEY_4 = '4',
        INKEY_5 = '5',
        INKEY_6 = '6',
        INKEY_7 = '7',
        INKEY_8 = '8',
        INKEY_9 = '9',
        INKEY_NONE = 'none'
    };
    enum inputTypes { KEYBOARD, MOUSE, GAMEPAD, TOUCH };  // types of inputs used in the game
	enum mouseClicks { NOCLICK, LEFTCLICK, RIGHTCLICK, MIDDLECLICK, WHEELCLICK };  // stores which mouse button has been clicked
    enum directions { NODIRECT, UP, DOWN, LEFT, RIGHT, UPLEFT, UPRIGHT, DOWNLEFT, DOWNRIGHT };	// direction objects are moving
    enum gameTypes { NOGAME, SINGLE, MULTI }; // defines whether a game is single or multi player
    enum netGameTypes { CLIENT, SERVER}; // defines which type of network game this instance is running
    enum quarters { NOQUARTER, FIRST, SECOND, THIRD, FOURTH }; // defines the quarters within the game
    enum courtSide_t {NOSIDE, RIGHTSIDE, LEFTSIDE };	// defines which side of the court the offensive team is on

    // GUI
    enum activeMenus { MAIN, NETWORK, NETWORKCLIENT, NETWORKSERVER, OPTIONS, DISPLAY, INPUTMENU, AUDIO, GAMESETUP, PLAYERSTART, TEAMSELECT, COURTSELECT }; // stores which menu is set to active

    // jump ball
    enum jumpBallLocations_t { NOLOCATION, CENTERCIRCLE, RIGHTKEYCIRCLE, LEFTKEYCIRCLE };

    // offense / defense
    enum playerPositions { NONE, PG, SG, SF, PF, C }; // defines the name for each player position
    enum directiveTypes { WAIT, FREELANCE}; // defines the type of directive a player has
    enum offenseWaitFor { PLAYERPOSITIONSET, TIME }; // defines what an offensive player is waiting for
    enum positionTypes { START, EXECUTE};

    enum bballBounces { NOBOUNCE, BOUNCEUP, BOUNCEDOWN};  // defines state of basketball bounce
    // Network
    enum packetTypes { GAMEDATA, GAMESTATE, PLAYERDATA, PLAYERSTATE, TEAMDATA, TEAMSTATE }; // Defines what type of data is being sent over the network
    // Physics bit masks
    #define BIT(x) (1<<(x))

    // Player and Basketball
    enum positionChangedTypes { NOCHANGE, STARTCHANGE, STEERCHANGE, INPUTCHANGE, PHYSICSCHANGE, PLAYERMOVECHANGE, PLAYERDIRECTCHANGE }; // Defines the type of position change that occured

    // Teams
    enum teamTypes {HOMETEAM, AWAYTEAM, NOTEAM };  // Defines the type of team
    // Data Types
    //enum dataTypes { CHAR, INT, FLOAT, DOUBLE, OGREVEC3, OPENSTEERVEC3, BULLETVEC3 };  // Defines type of data being passed to function
    
    // physics
    enum physicsShapes {CAPSULE, BOX, CYLINDER, SPHERE };  // Defines what type of physics object to create

    enum collisionTypes
    {
        COL_NOTHING = 0, //<Collide with nothing
        COL_COURT = BIT(0), // Collide with court
        COL_HOOP = BIT(1), // Collide with hoop
        COL_BBALL = BIT(2), // Collide with basketball
        COL_PLAYER0 = BIT(3), // Collides with player 0
        COL_PLAYER1 = BIT(4), // Collides with player 1
        COL_PLAYER2 = BIT(5), // Collides with player 2
        COL_PLAYER3 = BIT(6), // Collides with player 3
        COL_PLAYER4 = BIT(7), // Collides with player 4
        COL_PLAYER5 = BIT(8), // Collides with player 5
        COL_PLAYER6 = BIT(9), // Collides with player 6
        COL_PLAYER7 = BIT(10), // Collides with player 7
        COL_PLAYER8 = BIT(11), // Collides with player 8
        COL_PLAYER9 = BIT(12), // Collides with player 9
        COL_TEAM1 = COL_PLAYER0 | COL_PLAYER1 | COL_PLAYER2 | COL_PLAYER3 | COL_PLAYER4, //<Collide with team1
        COL_TEAM2 = COL_PLAYER5 | COL_PLAYER6 | COL_PLAYER7 | COL_PLAYER8 | COL_PLAYER9  //<Collide with team2

    };

#endif /* ENUMS_H_ */
