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

#ifndef _ENUMS_H_
#define _ENUMS_H_

    enum inputInGameMaps { INNO, INUP, INDOWN, INLEFT, INRIGHT, INUPLEFT, INUPRIGHT, INDOWNLEFT, INDOWNRIGHT, INSHOOTBLOCK, INPASSSTEAL, INPAUSE, INSTARTSELECT, INQUIT }; // map of human player input
    enum inputKeyMaps  // maps input to appropriate keys
    {
        INKEY_A,
        INKEY_B,
        INKEY_C,
        INKEY_D,
        INKEY_E,
        INKEY_F,
        INKEY_G,
        INKEY_H,
        INKEY_I,
        INKEY_J,
        INKEY_K,
        INKEY_L,
        INKEY_M,
        INKEY_N,
        INKEY_O,
        INKEY_P,
        INKEY_Q,
        INKEY_R,
        INKEY_S,
        INKEY_T,
        INKEY_U,
        INKEY_V,
        INKEY_W,
        INKEY_X,
        INKEY_Y,
        INKEY_Z,
        INKEY_BACKSPACE,
        INKEY_RETURN,
        INKEY_ESCAPE,
        INKEY_TAB,
        INKEY_SPACE,
        INKEY_LSHIFT,
        INKEY_LCTRL,
        INKEY_LALT,
        INKEY_LGUI,
        INKEY_RSHIFT,
        INKEY_RCTRL,
        INKEY_RALT,
        INKEY_RGUI,
        INKEY_MENU,
        INKEY_CAPSLOCK,
        INKEY_F1,
        INKEY_F2,
        INKEY_F3,
        INKEY_F4,
        INKEY_F5,
        INKEY_F6,
        INKEY_F7,
        INKEY_F8,
        INKEY_F9,
        INKEY_F10,
        INKEY_F11,
        INKEY_F12,
        INKEY_UP,
        INKEY_DOWN,
        INKEY_LEFT,
        INKEY_RIGHT,
        INKEY_SCROLLLOCK,
        INKEY_HOME,
        INKEY_PRTSCN,
        INKEY_PAUSE_BREAK,
        INKEY_INSERT,
        INKEY_DELETE,
        INKEY_PAGEUP,
        INKEY_PAGEDOWN,
        INKEY_END,
        INKEY_NUMLOCK,
        INKEY_DIVIDE,
        INKEY_MULTIPLY,
        INKEY_MINUS,
        INKEY_PLUS,
        INKEY_ENTER,
        INKEY_PERIOD,
        INKEY_0,
        INKEY_1,
        INKEY_2,
        INKEY_3,
        INKEY_4,
        INKEY_5,
        INKEY_6,
        INKEY_7,
        INKEY_8,
        INKEY_9,
        INKEY_NONE
    };
    
    enum inputGamePadMaps  // Maps input for gamepads
    {
        AXISUP0, 
        AXISDOWN0, 
        AXISLEFT0, 
        AXISRIGHT0, 
        AXISUPLEFT0, 
        AXISUPRIGHT0, 
        AXISDOWNLEFT0,
        AXISUP1, 
        AXISDOWN1, 
        AXISLEFT1, 
        AXISRIGHT1, 
        AXISUPLEFT1, 
        AXISUPRIGHT1, 
        AXISDOWNLEFT1,
        BUTTON0,
        BUTTON1,
        BUTTON2,
        BUTTON3,
        BUTTON4,
        BUTTON5,
        BUTTON6,
        BUTTON7,
        BUTTON8,
        INGP_NONE
    };
    
    enum inputTypes { KEYBOARD, MOUSE, GAMEPAD, TOUCH, INNOTYPE };  // types of inputs used in the game
	enum mouseClicks { NOCLICK, LEFTCLICK, RIGHTCLICK, MIDDLECLICK, WHEELCLICK };  // stores which mouse button has been clicked
    enum directions { NODIRECT, UP, DOWN, LEFT, RIGHT, UPLEFT, UPRIGHT, DOWNLEFT, DOWNRIGHT };	// direction objects are moving
    enum gameTypes { NOGAME, SINGLE, MULTILOCAL, MULTINET }; // defines whether a game is single or multi player
    enum netGameTypes { CLIENT, SERVER}; // defines which type of network game this instance is running
    enum quarters { NOQUARTER, FIRST, SECOND, THIRD, FOURTH }; // defines the quarters within the game
    enum courtSide_t {NOSIDE, RIGHTSIDE, LEFTSIDE };	// defines which side of the court the offensive team is on

    // GUI
    enum activeMenus { NOACTIVEMENU, MAIN, NETWORK, NETWORKCLIENT, NETWORKSERVER, OPTIONS, DISPLAY, INPUTMENU, AUDIO, GAMESETUP, PLAYERSTART, TEAMSELECT, COURTSELECT }; // stores which menu is set to active

    // jump ball
    enum jumpBallLocations_t { NOLOCATION, CENTERCIRCLE, RIGHTKEYCIRCLE, LEFTKEYCIRCLE };

    // offense / defense
    enum offDefs { NOOFFDEF, OFFENSE, DEFENSE };
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
    enum teamTypes {NOTEAM, HOMETEAM, AWAYTEAM };  // Defines the type of team
    // Data Types
    //enum dataTypes { CHAR, INT, FLOAT, DOUBLE, OGREVEC3, OPENSTEERVEC3, BULLETVEC3 };  // Defines type of data being passed to function
    
    // physics
    enum physicsShapes {CAPSULE, BOX, CYLINDER, SPHERE };  // Defines what type of physics object to create

    enum playerActions {NOACTION, MOVE, CHANGECOURTPOS, CHANGEDIRECTION, SETNODE, SETMODEL, JUMP, SHOOT, PASS, STEAL, BLOCK };
    
    enum userTypes {LOCALUSER, NETWORKUSER };
    
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
