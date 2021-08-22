/***************************************************************************
 *   Copyright (C) 1999 - 2019 by Mike McLean                              *
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

#include <algorithm>
#ifdef __ANDROID__
//#ifdef __ANDROID
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
#undef None
#include "Ogre.h"
#include "OgreHlms.h"
#include "OgreHlmsPbs.h"
#include "OgreHlmsUnlit.h"
#include "OgreHlmsManager.h"
#include "OgreHlmsPbsDatablock.h"
#include "OgreHlmsUnlitDatablock.h"
#endif

#include <memory>
#include "utilities/RTShaderHelper.h"
#include "utilities/typedefs.h"

#include "SDL.h"
#include "SDL_syswm.h"
#include "SDL_test_common.h"

#include "engine.h"

class renderEngine : public engine
{
    public:

    renderEngine();  // constructor 
    
    Ogre::Root *getRERoot() const;  // retrieves the value of mRoot
    void setRERoot(Ogre::Root *set);  // sets the value of mRoot

    Ogre::Camera *getMCamera() const;  // retrieves the value of mCamera
    void setMCamera(Ogre::Camera *set);  // sets the value of mCamera

    Ogre::SceneNode *getCameraNode() const;  // retrieves the value of cameraNode
    void setCameraNode(Ogre::SceneNode *set);  // stes the value of cameraNode

    Ogre::SceneManager *getMSceneMgr() const;  // retrieves the value of mSceneMgr
    void setMSceneMgr(Ogre::SceneManager *set);  // sets the value of mSceneMgr

    Ogre::Window *getMWindow() const;  // retrieves the value of mWindow
    void setMWindow(Ogre::Window *set);  // sets the value of mWindow

    Ogre::Viewport *getViewPort() const; // retrieves the value of viewPort
    void setViewPort(Ogre::Viewport *set); // sets the value of viewPort
	
#ifdef __ANDROID
    Ogre::DataStreamPtr openAPKFile(const std::string &set);  // opens APK file

    AAssetManager* getMAssetMgr() const;  // retrieves the value of mAssetMgr
    void setMAssetMgr(const AAssetManager* &set);  // sets the value of mAssetMgr
	
    android_app *getApp() const;  // retireves the value of app
    void setApp(const android_app* &set);  // sets the value of app
#endif

    Ogre::Vector3 getMTranslateVector() const;  // retrieves the value of mTranslateVector
    void setMTranslateVector(const Ogre::Vector3 &set);  // sets the value of mTranslateVector

    Ogre::Radian getMRotX() const;  // retrieves the value of mRotX
    void setMRotX(const Ogre::Radian &set);  // sets the value of mRotX

    Ogre::Radian getMRotY() const;  // retrieves the value of mRotY
    void setMRotY(const Ogre::Radian &set);  // sets the value of mRotY

    Ogre::Real getMMoveSpeed() const;  // retrieves the value of mMoveSpeed
    void setMMoveSpeed(const Ogre::Real &set);  // sets the value of mMoveSpeed

    Ogre::Degree getMRotateSpeed() const;  // retrieves the value of mRotateSpeed
    void setMRotateSpeed(const Ogre::Degree &set);  // stes the value of mRotateSpeed

    float getMMoveScale() const;  // retrieves the value of mMoveScale
    void setMMoveScale(const float &set);  // sets the value of mMoveScale

    Ogre::Degree getMRotScale() const;  // retrieves the value of mRotScale
    void setMRotScale(const Ogre::Degree &set);  // sets the value of mRotScale

    std::string getMResourceGroup();  // retrieves the value of mResourceGroup
    void setMResourceGroup(const std::string &set);  // sets the value of mResourceGroup

    SDL_Window *getSDLWindow() const;  // retireves the value of SDLWindow
    void setSDLWindow(SDL_Window *set);  // sets the value of SDLWindow

/*    uint32_t getWindowWidth();  // retrieves the value of windowWidth
    void setWindowWidth(uint32_t set);  // sets the value of windowWidth
    
    uint32_t getWindowHeight();  // retrieves the value of windowHeight
    void setWindowHeight(uint32_t set);  // sets the value of windowHeight
*/
    Ogre::CompositorManager2 *getCompositorManager() const;
    void setCompositorManager(Ogre::CompositorManager2 *set);
    Ogre::v1::Entity *bball;
//    Ogre::SceneNode bballNode;

    ~renderEngine();


    bool initSDL();  // initializes the SDL Subsystem
    bool initOgre();  // initializes the OGRE Subsystem

    const char *getMediaReadArchiveType() const;
    void registerHlms();  // registers the Hlms shader system
    bool createWindow();  // creates a window
    bool createScene();  // creates a scene
    Ogre::SceneNode *createNode(Ogre::v1::Entity *model,
                                      const std::string &entityNodeName);  // create scene node for model

    bool frameStarted();  // begins a frame
    bool frameEnded();  // ends a frame
//    void createSceneManager();  // creates the scene manager

    bool renderFrame();  // renders a frame to the screen
    
    protected:
#ifdef __ANDROID
    static android_app *app;
    //static
    static Ogre::StaticPluginLoader *gStaticPluginLoader;
    static AConfiguration *config;

#endif
    
    size_t instance;  // used to count number of instances

    // SDL code
    SDL_Window *sdlWindow;  // stores the SDL window
    SDL_GLContext sdlGLContext;  // the SDL GL Context
    SDL_SysWMinfo sysInfo;  // stores the SDL System information
    SDLTest_CommonState *state;  // stores the state

    // Ogre code
    Ogre::Root *RERoot;  // stores the OGRE Root
    Ogre::Camera *mCamera;  // stores the camera used by OGRE
    Ogre::SceneNode *cameraNode;  // stores the camera node
    Ogre::SceneManager *mSceneMgr;  // store the OGRE Scene Manager
    Ogre::Window *mWindow;  // stores the OGRE Render Window
    Ogre::Viewport *viewPort;  // stores the OGRE View Port
    Ogre::Light *light;  // stores the vslue of light
    Ogre::SceneNode *lightNode;  // stores the light scene node.
    Ogre::ResourceGroupManager *rsm;  // stores resources
    Ogre::HlmsPbs* mHlmsPbs;
    Ogre::HlmsUnlit* mHlmsUnlit;
    Ogre::HlmsManager *hlmsManager;
    std::string mResourceGroup;  // stores resource locations
    Ogre::String rootHlmsFolder;  // stores the root Hlms folder
    Ogre::NameValuePairList misc;  // options to pass to mWindow during creation
    Ogre::ConfigOptionMap cfgOpts;  // stores render window config options
    std::string winHandle;  // window handle

    Ogre::CompositorManager2 *compositorManager;

    // general
//    uint32_t windowWidth;  // stores the width of the window
//    uint32_t windowHeight;  // stores the height of the window
    // Android support
#ifdef __ANDROID
    static AAssetManager* mAssetMgr;  // stores the android asset manager
#endif

#if OGRE_VERSION_MAJOR == 1 && OGRE_VERSION_MINOR == 10
    Ogre::ShaderGeneratorTechniqueResolverListener* mMatListener;  // stores the material listener
#endif

    Ogre::RenderSystem *selectedRenderSystem;

    // InputReader* mInputDevice;
    Ogre::Vector3 mTranslateVector;  // stores the translate vector
    Ogre::Radian mRotX, mRotY;  // stores x and y rotations
    Ogre::Real mMoveSpeed;  // stores the movement speed
    Ogre::Degree mRotateSpeed;  // stores the rotation speed
    float mMoveScale;  // stores the movement scale
    Ogre::Degree mRotScale;  // stores the rotation scale
    Ogre::Real mTimeUntilNextToggle;  // stores the time until next toggle
    
    private:

//    static renderEngine *pInstance;
//    static renderEngineSharedPtr pInstance;

        bool useRTSS;
        size_t windowWidth;  // stoers the width of the SDL and OGRE windows
        size_t windowHeight;   // stores the height of the SDL and OGRE windows
};

#endif // RENDERENGINE_H_INCLUDED
