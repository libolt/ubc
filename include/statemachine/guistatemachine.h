#ifndef _GUISTATEMACHINE_H_
#define _GUISTATEMACHINE_H_

#include "statemachine/statemachine.h"
#include "utilities/typedefs.h"

class guiSMData : public eventData
{
public:

    guiComponentsSharedPtr component;  // stores copy of guiComponents object
    guiCreateSharedPtr create;  // stores copy of guiCreate object
    guiDataSharedPtr gData;  // stores copy of guiData object
    guiDisplaySharedPtr display;  // stores copy of guiDisplay object
    guiEventsSharedPtr event;  // stores copy of guiEvents object
    guiFlagsSharedPtr flag;  // stores copy of guiFlags object
    guiInputSharedPtr input;  // stores copy of guiInput object
    gameEntitySharedPtr gameInstance;  // stores copy of gameEngine object
    renderEngineSharedPtr render;  // stores copy of renderEngine object
       
/*    OgreEntitySharedPtr model;  // stores 3d model
    OgreSceneNodeSharedPtr node;  // stores node 3d model is attached to
*/

private:
//    courtPhysicsSharedPtr physics;  // stores copy of courtPhysics object
/*    gameComponentsSharedPtr gComponent;  // stores copy of gameComponent object
    gameDataSharedPtr gData;  // stores copy of gameData object
    gameFlagsSharedPtr gFlag;  // stores copy of gameFlag object
*/

};

class guiStateMachine : public stateMachine
{
public:
    guiStateMachine();

    // External events taken by this state machine
    void pInitialize(const guiSMData *data);
    void pAudioMenu(const guiSMData *data);
    void pDisplayMenu(const guiSMData *data);
    void pInputMenu(const guiSMData *data);
    void pMainMenu(const guiSMData *data);
    void pNetworkMenu(const guiSMData *data);
    void pNetworkClientMenu(const guiSMData *data);
    void pNetworkServerMenu(const guiSMData *data);
    void pOptionsMenu(const guiSMData *data);
    void pCourtMenu(const guiSMData *data);
    void pStartersMenu(guiSMData *data);
    void pTeamMenu(guiSMData *data);
    void halt();

private:
    INT m_currentSpeed;

    // State enumeration order must match the order of state method entries
    // in the state map.
    enum States
    {
        ST_INITIALIZE,
        ST_MAIN_MENU,
        ST_NETWORK_MENU,
        ST_NETWORKCLIENT_MENU,
        ST_NETWORKSERVER_MENU,
        ST_IDLE,
        ST_COURT_MENU,
        ST_TEAM_MENU,
        ST_STARTERS_MENU,
        ST_OPTIONS_MENU,
        ST_AUDIO_MENU,
        ST_DISPLAY_MENU,
        ST_INPUT_MENU,
        ST_MAX_STATES
    };

    // Define the state machine state functions with event data type
    STATE_DECLARE(guiStateMachine,    Initialize,    guiSMData)
    STATE_DECLARE(guiStateMachine,    MainMenu,    guiSMData)
    STATE_DECLARE(guiStateMachine,    NetworkMenu,    guiSMData)
    STATE_DECLARE(guiStateMachine,    NetworkClientMenu,    guiSMData)
    STATE_DECLARE(guiStateMachine,    NetworkServerMenu,    guiSMData)
    STATE_DECLARE(guiStateMachine,    Idle,    noEventData)
    STATE_DECLARE(guiStateMachine,    CourtMenu,    guiSMData)
    STATE_DECLARE(guiStateMachine,    TeamMenu,    guiSMData)
    STATE_DECLARE(guiStateMachine,    StartersMenu,    guiSMData)
    STATE_DECLARE(guiStateMachine,    OptionsMenu,    guiSMData)
    STATE_DECLARE(guiStateMachine,    AudioMenu,    guiSMData)
    STATE_DECLARE(guiStateMachine,    DisplayMenu,    guiSMData)
    STATE_DECLARE(guiStateMachine,    InputMenu,    guiSMData)

    // State map to define state object order. Each state map entry defines a
    // state object.
    BEGIN_STATE_MAP
        STATE_MAP_ENTRY(&Initialize)
        STATE_MAP_ENTRY(&MainMenu)
        STATE_MAP_ENTRY(&NetworkMenu)
        STATE_MAP_ENTRY(&NetworkClientMenu)
        STATE_MAP_ENTRY(&NetworkServerMenu)
        STATE_MAP_ENTRY(&Idle)
        STATE_MAP_ENTRY(&CourtMenu)
        STATE_MAP_ENTRY(&TeamMenu)
        STATE_MAP_ENTRY(&StartersMenu)
        STATE_MAP_ENTRY(&OptionsMenu)
        STATE_MAP_ENTRY(&AudioMenu)
        STATE_MAP_ENTRY(&DisplayMenu)
        STATE_MAP_ENTRY(&InputMenu)
    END_STATE_MAP
};


#endif // _GUISTATEMACHINE_H_
