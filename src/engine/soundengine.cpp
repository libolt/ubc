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

 
#include "engine/sound/soundengine.h"
#include "conversion.h"
#include "load.h"

/*
boost::shared_ptr<soundEngine> soundEngine::pInstance;

boost::shared_ptr<soundEngine> soundEngine::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        boost::shared_ptr<soundEngine> tInstance(new soundEngine);
        pInstance = tInstance;

    }
    return pInstance; // address of sole instance
}

soundEngine::soundEngine()  // constructor
{
//    g_PlayingAudio[16];
    still_playing = AL_TRUE;
//    audio_data = new ALmixer_Data;
    setupComplete = false;
        
}

soundEngine::~soundEngine()  // destructor
{
    
}

void soundEngine::Internal_SoundFinished_CallbackIntercept(ALint which_channel, ALuint al_source, ALmixer_Data* almixer_data, ALboolean finished_naturally, void* user_data)
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    logMsg("Channel " +convert->toString(which_channel) +" finished\n");
    g_PlayingAudio[which_channel] = AL_FALSE;
}

bool soundEngine::getSetupComplete()  // retrieves the value of setupComplete
{
    logMsg("returning setupComplete!");
    return (setupComplete);
}
void soundEngine::setSetupComplete(bool set)  // sets the value of setupComplete
{
    setupComplete = set;
}

bool soundEngine::loadSound(std::string sound)  // loads sounds from media file
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<loader> load = loader::Instance();

    ALmixer_Data *sample;
//    if(!(sample=ALmixer_LoadAll( "roar.wav", AL_FALSE) ))
//    if (!(audio_data[0]=ALmixer_LoadStream( sound.c_str(), AL_FALSE) ))
///    {
///        logMsg(convert->toString(ALmixer_GetError()) +". Quiting program.");
///		return (false);
///    }
    
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    std::string sampleFile = "data/Media/Audio/roar.wav";
#else
    std::string sampleFile = load->findFile("Media/Audio/roar.wav");
#endif
    logMsg("sampleFile = " +sampleFile);

    sample = ALmixer_LoadAll(sampleFile.c_str(), 0);
    audio_data = sample;
    if (sample == NULL)
    {
        logMsg("Failed to load sample!");
//        exit(0);
    }
    int which_channel = 0;
    ALmixer_ReserveChannels(2);
    which_channel = ALmixer_PlayChannel(0, audio_data, 0);
//    exit(0);
    return (true);}

bool soundEngine::setup()  // sets up the sound engine
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();

    logMsg("Sound Engine Setup!");
    
    ALint i;
    
///    if(argc < 1)
///    {
///        logMsg("Pass a sound file (or files) as a parameter\n");
///    }
///    else if(argc-1 > MAX_SOURCES)
///    {
///        logMsg("Maximum supported files is "  +convert->toString(MAX_SOURCES));
///    }

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID

    JNIEnv* env = (JNIEnv*)SDL_AndroidGetJNIEnv();
    jobject UBCActivity = (jobject)SDL_AndroidGetActivity();
    ALmixer_Android_Init(UBCActivity);
#endif  
    
    ALmixer_Init(22050, 0, 0);
    

    
    logMsg("Sound Engine Setup Complete!");
    return true;
}
*/
