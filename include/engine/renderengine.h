/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
 *   libolt@libolt.net                                                     *
 *         ?
 *
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

#ifndef _RENDERENGINE_H_
#define _RENDERENGINE_H_

#ifdef __ANDROID__
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    #define OGRE_STATIC_GLES2
//    #define OGRE_STATIC_ParticleFX
//    #define OGRE_STATIC_OctreeSceneManager
#include "OgreStaticPluginLoader.h"


#include <EGL/egl.h>
#include <android/log.h>
#include <android_native_app_glue.h>
#include <android/native_window.h> 
#include <android/native_window_jni.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

//#include "Android/OgreAndroidEGLWindow.h"
#include "Android/OgreAPKFileSystemArchive.h"
#include "Android/OgreAPKZipArchive.h"
#else
#include "Ogre.h"
#endif

#include <memory>
#include "RTShaderHelper.h"

#include "SDL.h"
#include "SDL_syswm.h"
#include "SDL_test_common.h"
#include <boost/shared_ptr.hpp>

#include "engine.h"

class renderEngine : public engine
{
    public:

    //static renderEngine *Instance();
//    static sharedPtr<renderEngine> Instance();

    renderEngine();  // constructor 
    
    sharedPtr<Ogre::Root> getRERoot();  // retrieves the value of mRoot
    void setRERoot(sharedPtr<Ogre::Root> set);  // sets the value of mRoot

    sharedPtr<Ogre::Camera> getMCamera();  // retrieves the value of mCamera
    void setMCamera(sharedPtr<Ogre::Camera> set);  // sets the value of mCamera

    sharedPtr<Ogre::SceneManager> getMSceneMgr();  // retrieves the value of mSceneMgr
    void setMSceneMgr(sharedPtr<Ogre::SceneManager> set);  // sets the value of mSceneMgr

    sharedPtr<Ogre::RenderWindow> getMWindow();  // retrieves the value of mWindow
    void setMWindow(sharedPtr<Ogre::RenderWindow> set);  // sets the value of mWindow

    sharedPtr<Ogre::Viewport> getViewPort(); // retrieves the value of viewPort
    void setViewPort(sharedPtr<Ogre::Viewport> set); // sets the value of viewPort
	
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    Ogre::DataStreamPtr openAPKFile(const std::string &set);  // opens APK file

    AAssetManager* getMAssetMgr();  // retrieves the value of mAssetMgr
    void setMAssetMgr(AAssetManager* set);  // stes the value of mAssetMgr
	
    android_app *getApp();  // retireves the value of app
    void setApp(android_app *set);  // sets the value of app
#endif

    Ogre::Vector3 getMTranslateVector();  // retrieves the value of mTranslateVector
    void setMTranslateVector(Ogre::Vector3 set);  // sets the value of mTranslateVector

    Ogre::Radian getMRotX();  // retrieves the value of mRotX
    void setMRotX(Ogre::Radian set);  // sets the value of mRotX

    Ogre::Radian getMRotY();  // retrieves the value of mRotY
    void setMRotY(Ogre::Radian set);  // sets the value of mRotY

    Ogre::Real getMMoveSpeed();  // retrieves the value of mMoveSpeed
    void setMMoveSpeed(Ogre::Real set);  // sets the value of mMoveSpeed

    Ogre::Degree getMRotateSpeed();  // retrieves the value of mRotateSpeed
    void setMRotateSpeed(Ogre::Degree set);  // stes the value of mRotateSpeed

    float getMMoveScale();  // retrieves the value of mMoveScale
    void setMMoveScale(float set);  // sets the value of mMoveScale

    Ogre::Degree getMRotScale();  // retrieves the value of mRotScale
    void setMRotScale(Ogre::Degree set);  // sets the value of mRotScale

    std::string getMResourceGroup();  // retrieves the value of mResourceGroup
    void setMResourceGroup(std::string set);  // sets the value of mResourceGroup

    SDL_Window *getSDLWindow();  // retireves the value of SDLWindow
    void setSDLWindow(SDL_Window *set);  // sets the value of SDLWindow

/*    uint32_t getWindowWidth();  // retrieves the value of windowWidth
    void setWindowWidth(uint32_t set);  // sets the value of windowWidth
    
    uint32_t getWindowHeight();  // retrieves the value of windowHeight
    void setWindowHeight(uint32_t set);  // sets the value of windowHeight
*/
    ~renderEngine();


    bool initSDL();  // initializes the SDL Subsystem
    bool initOgre();  // initializes the OGRE Subsystem

    bool createWindow();  // creates a window
    bool createScene();  // creates a scene
    bool frameStarted();  // begins a frame
    bool frameEnded();  // ends a frame
//    void createSceneManager();  // creates the scene manager

    bool renderFrame();  // renders a frame to the screen
    
    protected:
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    static android_app *app;
    //static
    static Ogre::StaticPluginLoader *gStaticPluginLoader;
    static AConfiguration *config;

#endif
    
    static int instance;  // used to count number of instances

    // SDL code
    static SDL_Window *sdlWindow;  // stores the SDL window
    SDL_GLContext sdlGLContext;  // the SDL GL Context
    static SDL_SysWMinfo sysInfo;  // stores the SDL System information
    SDLTest_CommonState *state;  // stores the state

    // Ogre code
    static sharedPtr<Ogre::Root> RERoot;  // stores the OGRE Root
    static sharedPtr<Ogre::Camera> mCamera;  // stores the camera used by OGRE
    static sharedPtr<Ogre::SceneManager> mSceneMgr;  // store the OGRE Scene Manager
    static sharedPtr<Ogre::RenderWindow> mWindow;  // stores the OGRE Render Window
    static sharedPtr<Ogre::Viewport> viewPort;  // stores the OGRE View Port
    static sharedPtr<Ogre::Light> l;  // stores the vslue of light
    static sharedPtr<Ogre::ResourceGroupManager> rsm;  // stores resources
    static std::string mResourceGroup;  // stores resource locations
    static Ogre::NameValuePairList misc;  // options to pass to mWindow during creation
    static std::string winHandle;  // window handle

    // general
//    uint32_t windowWidth;  // stores the width of the window
//    uint32_t windowHeight;  // stores the height of the window
    // Android support
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    static AAssetManager* mAssetMgr;  // stores the android asset manager
#endif

    static Ogre::ShaderGeneratorTechniqueResolverListener* mMatListener;  // stores the material listener
    static Ogre::RenderSystem *selectedRenderSystem;

    // InputReader* mInputDevice;
    static Ogre::Vector3 mTranslateVector;  // stores the translate vector
    static Ogre::Radian mRotX, mRotY;  // stores x and y rotations
    static Ogre::Real mMoveSpeed;  // stores the movement speed
    static Ogre::Degree mRotateSpeed;  // stores the rotation speed
    static float mMoveScale;  // stores the movement scale
    static Ogre::Degree mRotScale;  // stores the rotation scale
    static Ogre::Real mTimeUntilNextToggle;  // stores the time until next toggle
    
    private:

//    static renderEngine *pInstance;
//    static sharedPtr<renderEngine> pInstance;
    bool useRTSS;

};

#endif // RENDERENGINE_H_INCLUDED
