/***************************************************************************
 *   Copyright (C) 1999 - 2017 by Mike McLean                              *
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

#ifdef __ANDROID__
#include "utilities/android-config.h"
#else
#include "config.h"
#endif
#include "utilities/conversion.h"
#include "engine/gameengine.h"
#include "utilities/logging.h"
#include "engine/physicsengine.h"
#include "engine/renderengine.h"
#include "engine/sound/soundengine.h"

#define FREEIMAGE_LIB
#include "FreeImage.h"
#include "OgreDDSCodec.h"
#include "OgreFreeImageCodec.h"

#include "OgreRenderWindow.h"

#ifndef OGRE_PLUGIN_DIR
#define OGRE_PLUGIN_DIRr
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    android_app *renderEngine::app;
    Ogre::StaticPluginLoader *renderEngine::gStaticPluginLoader;
    AConfiguration *renderEngine::config;
#endif


// static declarations
int renderEngine::instance;
SDL_Window *renderEngine::sdlWindow;
SDL_SysWMinfo renderEngine::sysInfo; 
sharedPtr<Ogre::Root> renderEngine::RERoot;  // stores the OGRE Root
sharedPtr<Ogre::SceneManager> renderEngine::mSceneMgr;  // static declaration of mSceneMgr
sharedPtr<Ogre::Camera> renderEngine::mCamera;  // static declaration of mSceneMgr
sharedPtr<Ogre::RenderWindow> renderEngine::mWindow;  // static declaration of mSceneMgr
sharedPtr<Ogre::Viewport> renderEngine::viewPort;  // static declaration of mSceneMgr
sharedPtr<Ogre::Light> renderEngine::l;  // static declaration of l
sharedPtr<Ogre::ResourceGroupManager> renderEngine::rsm; // static declaration of rsm
Ogre::NameValuePairList renderEngine::misc; 
Ogre::ShaderGeneratorTechniqueResolverListener *renderEngine::mMatListener; 
Ogre::RenderSystem *renderEngine::selectedRenderSystem;
Ogre::Vector3 renderEngine::mTranslateVector; 
Ogre::Radian renderEngine::mRotX;
Ogre::Radian renderEngine::mRotY; 
Ogre::Real renderEngine::mMoveSpeed;  
Ogre::Degree renderEngine::mRotateSpeed;
float renderEngine::mMoveScale; 
Ogre::Degree renderEngine::mRotScale; 
Ogre::Real renderEngine::mTimeUntilNextToggle;
std::string renderEngine::winHandle;
std::string renderEngine::mResourceGroup;

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
AAssetManager *renderEngine::mAssetMgr; 
#endif

renderEngine::renderEngine()
{

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    gStaticPluginLoader = NULL;
	mAssetMgr = NULL;
	mSceneMgr = NULL;
#endif
//    sharedPtr<Ogre::RenderWindow> tempWindow(new Ogre::RenderWindow);
    mWindow = NULL;
    RERoot = NULL;
   
    instance = 0;
//   windowWidth = 0;
//   windowHeight = 0;
}

renderEngine::~renderEngine()
{
}

bool renderEngine::frameStarted()
{
	return true;
}
bool renderEngine::frameEnded()
{
	return true;
}
sharedPtr<Ogre::Root> renderEngine::getRERoot()  // retrieves the value of RERoot
{
	return (RERoot);
}
void renderEngine::setRERoot(sharedPtr<Ogre::Root> set)  // sets the value of RERoot
{
	RERoot = set;
}

sharedPtr<Ogre::Camera> renderEngine::getMCamera()  // retrieves the value of mCamera
{
	return (mCamera);
}
void renderEngine::setMCamera(sharedPtr<Ogre::Camera> set)  // sets the value of mCamera
{
	mCamera = set;
}

sharedPtr<Ogre::SceneManager> renderEngine::getMSceneMgr()  // retrieves the value of mSceneMgr
{
	return (mSceneMgr);
}
void renderEngine::setMSceneMgr(sharedPtr<Ogre::SceneManager> set)  // sets the value of mSceneMgr
{
	mSceneMgr = set;
}

sharedPtr<Ogre::RenderWindow> renderEngine::getMWindow()  // retrieves the value of mWindow
{
	return (mWindow);
}
void renderEngine::setMWindow(sharedPtr<Ogre::RenderWindow> set)  // sets the value of mWindow
{
	mWindow = set;
}

sharedPtr<Ogre::Viewport> renderEngine::getViewPort() // retrieves the value of viewPort
{
	return (viewPort);
}
void renderEngine::setViewPort(sharedPtr<Ogre::Viewport> set) // sets the value of viewPort
{
	viewPort = set;
}

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID

AAssetManager *renderEngine::getMAssetMgr()  // retrieves the value of mAssetMgr
{
	return (mAssetMgr);
}
void renderEngine::setMAssetMgr(AAssetManager *set)  // sets the value of mAssetMgr
{
	mAssetMgr = set;
}
android_app *renderEngine::getApp()  // retrieves the value of app
{
	return (app);
}
void renderEngine::setApp(android_app *set)  // sets the value of app
{
	app = set;
}
#endif

Ogre::Vector3 renderEngine::getMTranslateVector()  // retrieves the value of mTranslateVector
{
	return (mTranslateVector);
}
void renderEngine::setMTranslateVector(Ogre::Vector3 set)  // sets the value of mTranslateVector
{
	mTranslateVector = set;
}

Ogre::Radian renderEngine::getMRotX()  // retrieves the value of mRotX
{
	return (mRotX);
}
void renderEngine::setMRotX(Ogre::Radian set)  // sets the value of mRotX
{
	mRotX = set;
}

Ogre::Radian renderEngine::getMRotY()  // retrieves the value of mRotY
{
	return (mRotY);
}
void renderEngine::setMRotY(Ogre::Radian set)  // stes the value of mRotY
{
	mRotY = set;
}

Ogre::Real renderEngine::getMMoveSpeed()  // retrieves the value of mMoveSpeed
{
	return (mMoveSpeed);
}
void renderEngine::setMMoveSpeed(Ogre::Real set)  // sets the value of mMoveSpeed
{
	mMoveSpeed = set;
}

Ogre::Degree renderEngine::getMRotateSpeed()  // retrieves the value of mRotateSpeed
{
	return (mRotateSpeed);
}
void renderEngine::setMRotateSpeed(Ogre::Degree set)  // sets the value of mRotateSpeed
{
	mRotateSpeed = set;
}

float renderEngine::getMMoveScale()  // retrieves the value of mMoveScale
{
	return (mMoveScale);
}
void renderEngine::setMMoveScale(float set)  // sets the value of mMoveScale
{
	mMoveScale = set;
}

Ogre::Degree renderEngine::getMRotScale()  // retrieves the value of mRotScale
{
	return (mRotScale);
}
void renderEngine::setMRotScale(Ogre::Degree set)  // sets the value of mRotScale
{
	mRotScale = set;
}

std::string renderEngine::getMResourceGroup()  // retrieves the value of mResourceGroup
{
	return (mResourceGroup);
}
void renderEngine::setMResourceGroup(std::string set)  // sets the value of mResourceGroup
{
	mResourceGroup = set;
}

SDL_Window *renderEngine::getSDLWindow()  // retrieves the value of sdlWindow
{
	return (sdlWindow);
}
void renderEngine::setSDLWindow(SDL_Window *set)  // sets the value of sdlWindow
{
	sdlWindow = set;
}

/*
uint32_t renderEngine::getWindowWidth()  // retrieves the value of windowWidth
{
    return (windowWidth);
}
void renderEngine::setWindowWidth(uint32_t set)  // sets the value of windowWidth
{
    windowWidth = set;
}

uint32_t renderEngine::getWindowHeight()  // retrieves the value of windowHeight
{
    return (windowHeight);
}
void renderEngine::setWindowHeight(uint32_t set)  // sets the value of windowHeight
{
    windowHeight = set;
}
*/

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
Ogre::DataStreamPtr renderEngine::openAPKFile(const std::string& fileName)  // Opens the UBC apk file
{
    struct android_app* app;
	Ogre::DataStreamPtr stream;
	AConfiguration* config = AConfiguration_new();

	JNIEnv* env = (JNIEnv*)SDL_AndroidGetJNIEnv();

    jclass class_sdl_activity   = env->FindClass("com/libolt/ubc/UBCActivity");
    jclass class_activity       = env->FindClass("com/libolt/ubc/UBCActivity");
    jclass class_resources      = env->FindClass("android/content/res/Resources");
    jmethodID method_get_resources      = env->GetMethodID(class_activity, "getResources", "()Landroid/content/res/Resources;");
    jmethodID method_get_assets         = env->GetMethodID(class_resources, "getAssets", "()Landroid/content/res/AssetManager;");
    jobject raw_activity = (jobject)SDL_AndroidGetActivity();
	jobject raw_resources = env->CallObjectMethod(raw_activity, method_get_resources);
    jobject raw_asset_manager = env->CallObjectMethod(raw_resources, method_get_assets);
    mAssetMgr = AAssetManager_fromJava(env, raw_asset_manager);
    
//	state->onInputEvent = &handleInput;

//    AConfiguration_fromAssetManager(config, mAssetMgr);
    logMsg("APK?");

//	mAssetMgr = app->activity->assetManager;
    AAsset* asset = AAssetManager_open(mAssetMgr, fileName.c_str(), AASSET_MODE_BUFFER);
    if(asset)
    {
		off_t length = AAsset_getLength(asset);
        void* membuf = OGRE_MALLOC(length, Ogre::MEMCATEGORY_GENERAL);
        memcpy(membuf, AAsset_getBuffer(asset), length);
        AAsset_close(asset);

        stream = Ogre::DataStreamPtr(new Ogre::MemoryDataStream(membuf, length, true, true));
    }
    return stream;
}
#endif



bool renderEngine::initSDL() // Initializes SDL Subsystem
{
    sharedPtr<conversion> convert = conversion::Instance();
    std::string func = "renderEngine::initSDL()";
    
    logMsg(func +" beginning");

//    exit(0);
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS|SDL_INIT_GAMECONTROLLER) != 0)
    {
//        exit(0);
        logMsg(func +" Unable to initialize SDL: " +convert->toString(SDL_GetError()));
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID

//        __android_log_print(ANDROID_LOG_DEBUG, "com.libolt.ubc", "SDL Error = %s", SDL_GetError());
	std::string msg = "SDL Error = " +convert->toString(SDL_GetError());
        logMsg(func +" " +msg);
#endif

        return 1;
    }

//    exit(0);
    
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    SDL_DisplayMode mode;
	SDL_GetDesktopDisplayMode(0,&mode);

    JNIEnv* env = (JNIEnv*)SDL_AndroidGetJNIEnv();

    jclass class_sdl_activity   = env->FindClass("com/libolt/ubc/UBCActivity");
    jmethodID method_get_native_surface = env->GetStaticMethodID(class_sdl_activity, "getNativeSurface", "()Landroid/view/Surface;");
    jobject raw_surface = env->CallStaticObjectMethod(class_sdl_activity, method_get_native_surface);
    ANativeWindow* native_window = ANativeWindow_fromSurface(env, raw_surface);

/*    sdlWindow = SDL_CreateWindow("Ultimate Basketball Challenge",
                                 SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED,
                                 mode.w,mode.h,SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
*/                                 
//    SDL_CreateWindowFrom(native_window);
//    SDL_SetWindowFullscreen(sdlWindow, SDL_TRUE);                         
    std::string message = "SDL Window Created!";
	logMsg(func +" " +message);

#else
    sdlWindow = SDL_CreateWindow("Ultimate Basketball Challenge",
	                             SDL_WINDOWPOS_UNDEFINED,
	                             SDL_WINDOWPOS_UNDEFINED,
                                 1280,1024,0);
//    exit(0);
    SDL_VERSION( &sysInfo.version );


    if (SDL_GetWindowWMInfo(sdlWindow, &sysInfo) <= 0)
    {
    	assert( false );
    }
#endif

    logMsg(func +" end");

	return true;
}

bool renderEngine::initOgre() // Initializes Ogre Subsystem
{
    sharedPtr<conversion> convert = conversion::Instance();
    std::string func = "renderEngine::initOgre()";
    
    logMsg(func +" beginning");

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    #ifdef _WIN64
        winHandle = convert->toString((size_t)sysInfo.info.win.window);
    #else
        winHandle = convert->toString((unsigned long int)sysInfo.info.win.window);
    #endif
#elif OGRE_PLATFORM == OGRE_PLATFORM_LINUX
    winHandle = convert->toString((unsigned long)sysInfo.info.x11.window);
#elif OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    JNIEnv* env = (JNIEnv*)SDL_AndroidGetJNIEnv();

    jclass class_sdl_activity   = env->FindClass("com/libolt/ubc/UBCActivity");
    jmethodID method_get_native_surface = env->GetStaticMethodID(class_sdl_activity, "getNativeSurface", "()Landroid/view/Surface;");
    jobject raw_surface = env->CallStaticObjectMethod(class_sdl_activity, method_get_native_surface);
    ANativeWindow* native_window = ANativeWindow_fromSurface(env, raw_surface);
//    winHandle = convert->toString((unsigned long)sysInfo.info.android.window);
//    winHandle =  convert->toString((unsigned long)SDL_GetWindowID(sdlWindow));
    winHandle =  convert->toString((int)native_window);
    logMsg(func +" winHandle = " +winHandle);
//    exit(0);
//	logMsg("winHandle2 = " +winHandle2);
	
//	logMsg("grabbed = " +convert->toString(SDL_GetWindowGrab(sdlWindow)));
#else
	// Error, both can't be defined or undefined same time
#endif

//    exit(0);
	//std::cout << "winHandle = " << winHandle << std::endl;
    RERoot = sharedPtr<Ogre::Root>(new Ogre::Root("", "", "Ogre.log"));
    const std::string pluginDir = OGRE_PLUGIN_DIR;
    logMsg(func +" winHandle for Ogre = " +winHandle);
//    exit(0);
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//#else
//	inputSystem *input = inputSystem::Instance();
//#endif
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    const std::string buildType = BUILD_TYPE;

    if (buildType == "Debug")
    {
        logMsg(func +" Loading GL Debug RenderSystem!");
        RERoot->loadPlugin(pluginDir + "/RenderSystem_GL_d.dll");
//        RERoot->loadPlugin(pluginDir + "/Plugin_CgProgramManager_d");
    }
    else
    {
        logMsg(func +" Loading GL Release RenderSystem!");
        RERoot->loadPlugin(pluginDir + "/RenderSystem_GL");
//        RERoot->loadPlugin(pluginDir + "/Plugin_CgProgramManager");
    }
#elif OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	//	    RERoot->loadPlugin();
#ifdef OGRE_STATIC_LIB
    gStaticPluginLoader = new Ogre::StaticPluginLoader();
    gStaticPluginLoader->load();
//    exit(0);
#endif
#elif OGRE_PLATFORM == OGRE_PLATFORM_APPLE
    RERoot->loadPlugin("RenderSystem_GL");
#else
    RERoot->loadPlugin(pluginDir + "/RenderSystem_GL_d");
//    RERoot->loadPlugin(pluginDir + "/Plugin_CgProgramManager");
#endif
//    exit(0);

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    RERoot->setRenderSystem(RERoot->getAvailableRenderers().at(0));
//    RERoot->initialise(false);
//    RERoot->init = true;
//    exit(0);
#else
    Ogre::RenderSystemList rsList = RERoot->getAvailableRenderers();

    int c = 0;
    bool foundit = false;
    Ogre::RenderSystem *selectedRenderSystem = 0;
    while (c < (int)rsList.size())
    {
        selectedRenderSystem = rsList.at(c);
        std::string rname = selectedRenderSystem->getName();
	if (rname.compare("OpenGL Rendering Subsystem") == 0)
        {
            foundit = true;
            break;
        }
        c++; // <-- oh how clever
        logMsg(convert->toString(c++));
    }
//    exit(0);
	//we found it, we might as well use it!
    if (foundit)
    {
        RERoot->setRenderSystem(selectedRenderSystem);
    }
    else
    {
        logMsg(func +" renersystem not found!");
	    exit(0);
    }
#endif
    
    
    mWindow = sharedPtr<Ogre::RenderWindow>(RERoot->initialise(false));

/*    misc["externalWindowHandle"] = winHandle;
//    misc["externalGLContext"] = convert->toString((unsigned long)SDL_GL_GetCurrentContext());
//    exit(0);
    logMsg("Hello??");
//    exit(0);
    mWindow = RERoot->createRenderWindow("Ultimate Basketball Challenge", 0, 0, false, &misc);
    exit(0);
*/
    Ogre::DDSCodec::startup();
    
    Ogre::FreeImageCodec::startup();
    FreeImage_Initialise();
//    Ogre::DDSCodec::startup();
//    Ogre::FreeImageCodec::startup();
    //log->setOgreRootInitialized(true);

    logMsg(func +" OGRE initialized successfully!");
//    exit(0);

/*    logMsg("winHandle = " +winHandle);

    //    exit(0);
                misc["externalWindowHandle"] = winHandle;
                //      misc["externalGLContext"] = convert->toString((unsigned long)SDL_GL_GetCurrentContext());
                //    exit(0);
                        logMsg("Hello??");
                        //    exit(0);
                            mWindow = RERoot->createRenderWindow("Ultimate Basketball Challenge", 0, 0, false, &misc);
    exit(0);
*/

    logMsg(func +" end");
    
    return true;
}

bool renderEngine::createScene()
{
    sharedPtr<conversion> convert = conversion::Instance(); 
    std::string func = "renderEngine::createScene()";
    
    logMsg(func +" beginning");

    instance += 1;
//    exit(0);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    logMsg(func +" Hello");
    config = AConfiguration_new();
    logMsg(func +" Mello");
//    exit(0);
//	AConfiguration_fromAssetManager(config, app->activity->assetManager);
//	mAssetMgr = app->activity->assetManager;
    JNIEnv* env = (JNIEnv*)SDL_AndroidGetJNIEnv();

    jclass class_sdl_activity   = env->FindClass("com/libolt/ubc/UBCActivity");
    jmethodID method_get_native_surface = env->GetStaticMethodID(class_sdl_activity, "getNativeSurface", "()Landroid/view/Surface;");
    jobject raw_surface = env->CallStaticObjectMethod(class_sdl_activity, method_get_native_surface);
    ANativeWindow* native_window = ANativeWindow_fromSurface(env, raw_surface);
    
    if ( !native_window )
    {
        logMsg(func +" No Window, Goodbye!");
        return(0);
    }
    
    jclass class_activity = env->FindClass("com/libolt/ubc/UBCActivity");
    jclass class_resources = env->FindClass("android/content/res/Resources");
    jmethodID method_get_resources = env->GetMethodID(class_activity, "getResources", "()Landroid/content/res/Resources;");
    jmethodID method_get_assets = env->GetMethodID(class_resources, "getAssets", "()Landroid/content/res/AssetManager;");
    jobject raw_activity = (jobject)SDL_AndroidGetActivity();
    jobject raw_resources = env->CallObjectMethod(raw_activity, method_get_resources);
    jobject raw_asset_manager = env->CallObjectMethod(raw_resources, method_get_assets);
//    jobject raw_surface = env->CallStaticObjectMethod(class_sdl_activity, method_get_native_surface);

//    ANativeWindow* native_window = ANativeWindow_fromSurface(env, raw_surface);
//    exit(0);
    uint32_t w = ANativeWindow_getWidth(native_window);
    uint32_t h = ANativeWindow_getHeight(native_window);

    logMsg(func +" Width = " +convert->toString(w));
    logMsg(func +" Height = " +convert->toString(h));
    
    setWindowWidth(w);
    setWindowHeight(h);
    
    mAssetMgr = AAssetManager_fromJava(env, raw_asset_manager);
    logMsg(func +" Yello");
    AConfiguration_fromAssetManager(config, mAssetMgr);
    logMsg(func +" Bello");
//	mAssetMgr = app->activity->assetManager;

    Ogre::ArchiveManager::getSingleton().addArchiveFactory( new Ogre::APKFileSystemArchiveFactory(mAssetMgr) );
    Ogre::ArchiveManager::getSingleton().addArchiveFactory( new Ogre::APKZipArchiveFactory(mAssetMgr) );
    logMsg(func +" Hello?");
//    exit(0);
#endif
	//  AConfiguration_fromAssetManager(config, app->activity->assetManager);
	//gAssetMgr = app->activity->assetManager;
//	misc["currentGLContext"] = "true";
//	misc["androidConfig"] = convert->toString((int)config);
	//    misc["externalWindowHandle"] = convert->toString((int)app->window);

//	misc["currentGLContext"]     = "true";
//    misc["externalGLContext"]    = convert->toString((int)sdlWindow);
//    winHandle = convert->toString((unsigned long)sysInfo.info.android.window);
//    exit(0);
    logMsg(func +" winHandle = " +winHandle);

//    exit(0);
    misc["externalWindowHandle"] = winHandle;
//	misc["externalGLContext"] = convert->toString((unsigned long)SDL_GL_GetCurrentContext());
//    exit(0);
    logMsg(func +" Hello??");
//    exit(0);
    mWindow = sharedPtr<Ogre::RenderWindow>(RERoot->createRenderWindow("Ultimate Basketball Challenge", 0, 0, false, &misc));

//    exit(0);
    logMsg(func +" renderWindow created!");
    size_t handle = 0;
    mWindow->getCustomAttribute("WINDOW", &handle);
    logMsg(func +" mWindow handle = " +convert->toString(handle));
//    exit(0);
    logMsg(func +" Dead");
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    sdlWindow = SDL_CreateWindowFrom(mWindow.get());
//    exit(0);
#endif
     if (mWindow == NULL)
     {
         logMsg(func +" createScene mWindow == NULL!");
     }
//exit(0);
/*        
//    SDL_SetWindowSize(sdlWindow, w, h);
//    SDL_GetWindowSize(sdlWindow, w, h);
    Ogre::WindowEventUtilities::messagePump();
    w = mWindow->getViewport(0)->getActualWidth();
    h = mWindow->getViewport(0)->getActualHeight();
    logMsg("Width = " +convert->toString(w));
    logMsg("Height = " +convert->toString(h));
//    exit(0);
    logMsg("window ID = " +convert->toString(SDL_GetWindowID(sdlWindow)));
	SDL_ShowWindow(sdlWindow);
	SDL_SetWindowGrab(sdlWindow,SDL_TRUE);
	SDL_MaximizeWindow(sdlWindow);
*/

//#endif

    mResourceGroup = "UBCData";
//	Ogre::ResourceGroupManager *rsm
    rsm = sharedPtr<Ogre::ResourceGroupManager>(Ogre::ResourceGroupManager::getSingletonPtr());
    rsm->createResourceGroup(mResourceGroup);

    Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    Ogre::ConfigFile cf;
    cf.load(openAPKFile("resources.cfg"));
    logMsg(func +" or");
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
//exit(0);
    while (seci.hasMoreElements())
    {
        std::string sec, type, arch;
        sec = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap* settings = seci.getNext();
        Ogre::ConfigFile::SettingsMultiMap::iterator i;

        for (i = settings->begin(); i != settings->end(); i++)
        {
            type = i->first;
            arch = i->second;
//			Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch, type, sec);
            rsm->addResourceLocation(arch, type, mResourceGroup);
        }
    }

//	Ogre::ResourceGroupManager::getSingletonPtr()->initialiseResourceGroup(Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

    Ogre::RTShader::ShaderGenerator::initialize();
     // The Shader generator instance
    Ogre::RTShader::ShaderGenerator* shaderGen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
	//Ogre::RTShader::ShaderGenerator::getSingletonPtr()->setTargetLanguage("glsles");
    shaderGen->setTargetLanguage("glsles");
    if (mMatListener == NULL)
    {
        mMatListener = new Ogre::ShaderGeneratorTechniqueResolverListener();
        Ogre::MaterialManager::getSingleton().addListener(mMatListener);
    }
//    shaderGen->addSceneManager(mSceneMgr);
#else

	// logMsg("Rendering!");
    misc["externalWindowHandle"] = winHandle; //

//    mWindow = RERoot->createRenderWindow("Ultimate Basketball Challenge", 0, 0, false, &misc);

	//    exit(0);
    mWindow->setVisible(true);
#endif
    logMsg(func +" Alive?");

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    std::string dataPath = "data";
#else
    std::string dataPath = UBC_DATADIR;


    // load the basic resource location(s)
    rsm->addResourceLocation(dataPath + "/Media", "FileSystem", mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/fonts", "FileSystem", mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/gui", "FileSystem", mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/MyGUI_Media", "FileSystem", mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/models", "FileSystem", mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/materials/textures", "FileSystem", mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/materials/programs", "FileSystem", mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/materialss/scripts", "FileSystem", mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/materials", "FileSystem", mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/overlays", "FileSystem", mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/packs", "FileSystem", mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/skins", "FileSystem", mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/skins/qgui", "FileSystem", mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/Audio", "FileSystem", mResourceGroup);
#endif

    rsm->initialiseResourceGroup(mResourceGroup);
//  exit(0);
    mSceneMgr = sharedPtr<Ogre::SceneManager>(RERoot->createSceneManager(Ogre::ST_GENERIC)); // creates the scene manager
//    mSceneMgr = RERoot->createSceneManager("DefaultSceneManager"); // creates the scene manager

    mCamera = sharedPtr<Ogre::Camera>(mSceneMgr->createCamera("camera"));

/*
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	mCamera->setNearClipDistance(1.0f);
	mCamera->setFarClipDistance(100000.0f);
	mCamera->setPosition(0, 0, 20.0f);
	mCamera->lookAt(0, 0, 0);
	mCamera->setAutoAspectRatio(true);
#endif
*/

    // Position it at 500 in Z direction
    mCamera->setPosition(Ogre::Vector3(0, 0, 455));
    // Look back along -Z
    mCamera->lookAt(Ogre::Vector3(0, 0, -300));

    mCamera->setNearClipDistance(5);
    mCamera->setFarClipDistance(5000);
    viewPort = sharedPtr<Ogre::Viewport>(mWindow->addViewport(mCamera.get()));
    viewPort->setBackgroundColour(Ogre::ColourValue(0, 0, 0));

    mCamera->setAspectRatio(Ogre::Real(viewPort->getActualWidth()) / Ogre::Real(viewPort->getActualHeight()));
    // most examples get the viewport size to calculate this; for now, we'll just
    // set it to 4:3 the easy way

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    viewPort->setMaterialScheme(Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME);
#endif
    viewPort->setOverlaysEnabled(true);	// sets overlays true so that MyGUI can render

    bool overlayEnabled = viewPort->getOverlaysEnabled();
    logMsg(func +" overlayEnabled = " +convert->toString(overlayEnabled));
//.0.236	exit(0);
    mCamera->setAspectRatio((Ogre::Real)1.333333);

    // Set ambient light
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

    // Create a light
    l = sharedPtr<Ogre::Light>(mSceneMgr->createLight("MainLight"));
    l->setPosition(20,80,56);

 
    if (mWindow == NULL)
    {
        logMsg(func +" createScene mWindow 2 == NULL!");
    }
//     exit(0);
	//	    Ogre::LogManager::getSingletonPtr()->logMessage("winHandle = " +winHandle);

	// this next bit is for the sake of the input handler
	//	unsigned long hWnd;
	//		mWindow->getCustomAttribute("WINDOW", &winHandle);
/*
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	Ogre::Entity* pEntity = mSceneMgr->createEntity("court", "Player.mesh");
	Ogre::SceneNode* pNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("court");
	pNode->attachObject(pEntity);
	pNode->setScale(1.8f, 1.8f, 1.8f);
#endif
*/
//    GUISystem *gui = GUISystem::Instance();
//    gameEngine *gameE = gameEngine::Instance();
//    teams *team = teams::Instance();
//    players *player = players::Instance();
//    basketballs *basketball = basketballs::Instance();
//    renderEngine *render = renderEngine::Instance();


    // basketball
//    bballInstance[0].setNode(render->getMSceneMgr()->getRootSceneNode()->createChildSceneNode("bball"));

    // Player
//    for (int x = 0; x < 10; ++x)
//    {
//        SceneNode *playerNode = player->getNode(x);
//        playerNode = render->getMSceneMgr()->getRootSceneNode()->createChildSceneNode();
//        player->setNode(x, playerNode);
    //		playerNode[x]->pitch ( Degree (-90));
//    }
//	mSceneMgr->setWorldGeometry( "terrain.cfg" );

    // Set up GUI system
//    gui->setupGUI();

    // loads the Main Menu GUI
//    gui->loadMainMenu();

    // sets up the event handlers for main menu buttons
//    gui->setupMainMenuEventHandlers();

//    setMenuActive(true);

//    startGame();
//	setGameStarted(true);
//	bballInstance[0].setDribbling(true);

/*	vector<players::playerData> playerN = player->getPlayer();
//		exit(0);

	cout << "size = " << playerN.size() << endl;
	for (int i = 0; i < playerN.size(); i++)
	{
		cout << "FIRST name = " << playerN[i].getPlayerFirstName() << endl;
	}
*/
//	load->loadPlayerFile(
//    exit(0);
  //  gameE->startGame()
  
  logMsg(func +" end");
  
  
return (true);
}

//bool renderEngine::createScene()
//{
//    return (true);
//}

bool renderEngine::renderFrame()  // renders a frame to the screen
{
    sharedPtr<conversion> convert = conversion::Instance();
    std::string func = "renderEngine::renderFrame()";
    
    logMsg(func +" beginning");

//    exit(0);
    logMsg(func +" Rendering Frame!");
    logMsg(func +" Render Instance == " +convert->toString(instance));
    if (mWindow == NULL)
    {
        logMsg(func +" mWindow is NULL!");
    }
    
    if (mWindow != NULL && mWindow->isActive())
    {
        logMsg(func +" LastFPS == " +convert->toString(mWindow->getLastFPS()));
//      Ogre::LogManager::getSingletonPtr()->logMessage("Rendering frame");
        mWindow->windowMovedOrResized();
//        exit(0);
        logMsg(func +" windowMovedOrResized()");
        logMsg(func +" RERoot is initialized = " +convert->toString(RERoot->isInitialised()));
        RERoot->renderOneFrame();
//        exit(0);
        logMsg(func +" Frame Rendered!");

    }
//    exit(0);
    
    logMsg(func +" end");

    return (true);
}
