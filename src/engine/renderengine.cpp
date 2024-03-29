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
#include "OgreIdString.h"
#include "OgrePlatformInformation.h"
#include "Compositor/OgreCompositorManager2.h"
#define FREEIMAGE_LIB
//#include "FreeImage.h"
//#include "OgreDDSCodec.h"
//#include "OgreFreeImageCodec.h"
#include "OgreWindow.h"

#ifndef OGRE_PLUGIN_DIR
#define OGRE_PLUGIN_DIRr
#endif

#ifdef __ANDROID
    android_app *renderEngine::app;
    Ogre::StaticPluginLoader *renderEngine::gStaticPluginLoader;
    AConfiguration *renderEngine::config;
#endif


#ifdef __ANDROID
AAssetManager *renderEngine::mAssetMgr; 
#endif

renderEngine::renderEngine()
{

#ifdef __ANDROID
    gStaticPluginLoader = nullptr;
    mAssetMgr = nullptr;
    mSceneMgr = nullptr;
#endif
//    sharedPtr<Ogre::Window> tempWindow(new Ogre::Window);
    mWindow = nullptr;
    RERoot = nullptr;
//    bballNode = new Ogre::SceneNode;
//    cfgOpts = 0;

    instance = 0;
    useRTSS = false;
    mMoveSpeed = 0.0;
    mMoveScale = 0.0;
    mTimeUntilNextToggle = 0.0;
    windowWidth = 1280;
    windowHeight = 720;
//   windowWidth = 0;
//   windowHeight = 0;
}

renderEngine::~renderEngine() = default;  // destructor

bool renderEngine::frameStarted()
{
	return true;
}
bool renderEngine::frameEnded()
{
	return true;
}
Ogre::Root *renderEngine::getRERoot() const  // retrieves the value of RERoot
{
	return (RERoot);
}
void renderEngine::setRERoot( Ogre::Root *set)  // sets the value of RERoot
{
	RERoot = set;
}

Ogre::Camera *renderEngine::getMCamera() const  // retrieves the value of mCamera
{
	return (mCamera);
}
void renderEngine::setMCamera(Ogre::Camera *set)  // sets the value of mCamera
{
	mCamera = set;
}

Ogre::SceneNode *renderEngine::getCameraNode() const  // retrieves the value of cameraNode
{
    return (cameraNode);
}
void renderEngine::setCameraNode(Ogre::SceneNode *set)  // stes the value of cameraNode
{
    cameraNode = set;
}

Ogre::SceneManager *renderEngine::getMSceneMgr() const  // retrieves the value of mSceneMgr
{
	return (mSceneMgr);
}
void renderEngine::setMSceneMgr(Ogre::SceneManager *set)  // sets the value of mSceneMgr
{
	mSceneMgr = set;
}

Ogre::Window *renderEngine::getMWindow() const  // retrieves the value of mWindow
{
	return (mWindow);
}
void renderEngine::setMWindow(Ogre::Window *set)  // sets the value of mWindow
{
	mWindow = set;
}

Ogre::Viewport *renderEngine::getViewPort() const  // retrieves the value of viewPort
{
	return (viewPort);
}
void renderEngine::setViewPort(Ogre::Viewport *set) // sets the value of viewPort
{
	viewPort = set;
}

#ifdef __ANDROID

AAssetManager *renderEngine::getMAssetMgr() const  // retrieves the value of mAssetMgr
{
	return (mAssetMgr);
}
void renderEngine::setMAssetMgr(const AAssetManager* &set)  // sets the value of mAssetMgr
{
	mAssetMgr = set;
}
android_app *renderEngine::getApp() const  // retrieves the value of app
{
	return (app);
}
void renderEngine::setApp(const android_app* &set)  // sets the value of app
{
	app = set;
}
#endif

Ogre::Vector3 renderEngine::getMTranslateVector() const  // retrieves the value of mTranslateVector
{
	return (mTranslateVector);
}
void renderEngine::setMTranslateVector(const Ogre::Vector3 &set)  // sets the value of mTranslateVector
{
	mTranslateVector = set;
}

Ogre::Radian renderEngine::getMRotX() const  // retrieves the value of mRotX
{
	return (mRotX);
}
void renderEngine::setMRotX(const Ogre::Radian &set)  // sets the value of mRotX
{
	mRotX = set;
}

Ogre::Radian renderEngine::getMRotY() const  // retrieves the value of mRotY
{
	return (mRotY);
}
void renderEngine::setMRotY(const Ogre::Radian &set)  // stes the value of mRotY
{
	mRotY = set;
}

Ogre::Real renderEngine::getMMoveSpeed() const  // retrieves the value of mMoveSpeed
{
	return (mMoveSpeed);
}
void renderEngine::setMMoveSpeed(const Ogre::Real &set)  // sets the value of mMoveSpeed
{
	mMoveSpeed = set;
}

Ogre::Degree renderEngine::getMRotateSpeed() const  // retrieves the value of mRotateSpeed
{
	return (mRotateSpeed);
}
void renderEngine::setMRotateSpeed(const Ogre::Degree &set)  // sets the value of mRotateSpeed
{
	mRotateSpeed = set;
}

float renderEngine::getMMoveScale() const  // retrieves the value of mMoveScale
{
	return (mMoveScale);
}
void renderEngine::setMMoveScale(const float &set)  // sets the value of mMoveScale
{
	mMoveScale = set;
}

Ogre::Degree renderEngine::getMRotScale() const  // retrieves the value of mRotScale
{
	return (mRotScale);
}
void renderEngine::setMRotScale(const Ogre::Degree &set)  // sets the value of mRotScale
{
	mRotScale = set;
}

std::string renderEngine::getMResourceGroup()  // retrieves the value of mResourceGroup
{
	return (mResourceGroup);
}
void renderEngine::setMResourceGroup(const std::string &set)  // sets the value of mResourceGroup
{
	mResourceGroup = set;
}

SDL_Window *renderEngine::getSDLWindow() const  // retrieves the value of sdlWindow
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

Ogre::CompositorManager2 *renderEngine::getCompositorManager() const
{
    return (compositorManager);
}
void renderEngine::setCompositorManager(Ogre::CompositorManager2 *set)
{
    compositorManager = set;
}


#ifdef __ANDROID
Ogre::DataStreamPtr renderEngine::openAPKFile(const std::string& fileName)  // Opens the UBC apk file
{
    struct android_app* app;
	Ogre::DataStreamPtr stream;
	AConfiguration* config = AConfiguration_new();
    std::string func = "renderEngine::openAPKFile()";
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
    logMsg(func +" APK?");

//	mAssetMgr = app->activity->assetManager;
    AAsset* asset = AAssetManager_open(mAssetMgr, fileName.c_str(),
                                       AASSET_MODE_BUFFER);
    if(asset)
    {
		off_t length = AAsset_getLength(asset);
        void* membuf = OGRE_MALLOC(length, Ogre::MEMCATEGORY_GENERAL);
        memcpy(membuf, AAsset_getBuffer(asset), length);
        AAsset_close(asset);

        stream = Ogre::DataStreamPtr(new Ogre::MemoryDataStream(membuf, length,
                                                                true, true));
    }
    return stream;
}
#endif



bool renderEngine::initSDL() // Initializes SDL Subsystem
{
    conversionSharedPtr convert ;
    std::string func = "renderEngine::initSDL()";
    
    logMsg(func +" begin");

//    exit(0);
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS|SDL_INIT_GAMECONTROLLER) != 0)
    {
//        exit(0);
        logMsg(func +" Unable to initialize SDL: "
               +convert->toString(SDL_GetError()));
#ifdef __ANDROID

//        __android_log_print(ANDROID_LOG_DEBUG, "com.libolt.ubc", "SDL Error = %s", SDL_GetError());
	std::string msg = "SDL Error = " +convert->toString(SDL_GetError());
    logMsg(func +" " +msg);
#endif

        return (true);
    }

//    exit(0);
    
#ifdef __ANDROID
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
                                 windowWidth,windowHeight,0);
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
    conversionSharedPtr convert ;
    std::string func = "renderEngine::initOgre()";
    
    logMsg(func +" begin");

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    #ifdef _WIN64
//        winHandle = convert->toString(reinterpret_cast<size_t>(sysInfo.info.win.window));
        winHandle = convert->toString((uintptr_t)sysInfo.info.win.window);
    #else
//        winHandle = convert->toString(reinterpret_cast<unsigned long int>(sysInfo.info.win.window));
        winHandle = convert->toString((uintptr_t)sysInfo.info.win.window);
    #endif
#elif OGRE_PLATFORM == OGRE_PLATFORM_LINUX
//    winHandle = convert->toString(reinterpret_cast<unsigned long>(sysInfo.info.x11.window));
    winHandle = convert->toString((uintptr_t)sysInfo.info.x11.window);
    misc.insert( std::make_pair(
                     "SDL2x11", convert->toString(
                         (uintptr_t)&sysInfo.info.x11 ) ) );
    logMsg(func +"winHandle = " +winHandle);
#elif OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    JNIEnv* env = (JNIEnv*)SDL_AndroidGetJNIEnv();

    jclass class_sdl_activity   = env->FindClass("com/libolt/ubc/UBCActivity");
    jmethodID method_get_native_surface = env->GetStaticMethodID(class_sdl_activity, "getNativeSurface", "()Landroid/view/Surface;");
    jobject raw_surface = env->CallStaticObjectMethod(class_sdl_activity, method_get_native_surface);
    ANativeWindow* native_window = ANativeWindow_fromSurface(env, raw_surface);
//    winHandle = convert->toString((unsigned long)sysInfo.info.android.window);
//    winHandle =  convert->toString((unsigned long)SDL_GetWindowID(sdlWindow));
    winHandle =  convert->toString(reinterpret_cast<int>(native_window));
    logMsg(func +" winHandle = " +winHandle);
//    exit(0);
//	logMsg("winHandle2 = " +winHandle2);
	
//	logMsg("grabbed = " +convert->toString(SDL_GetWindowGrab(sdlWindow)));
#else
	// Error, both can't be defined or undefined same time
#endif

//    exit(0);
	//std::cout << "winHandle = " << winHandle << std::endl;
    RERoot = new Ogre::Root("", "", "Ogre.log");
    const std::string pluginDir = OGRE_PLUGIN_DIR;
    logMsg(func +" winHandle for Ogre = " +winHandle);
//    exit(0);
//#ifdef __ANDROID
//#else
//	inputSystem *input = inputSystem::Instance();
//#endif
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    const std::string buildType = BUILD_TYPE;

    if (buildType == "Debug")
    {
//        logMsg(func +"Loading STBI Image Codec Plguin!");
//        RERoot->loadPlugin(pluginDir +"/Codec_STBI_d.dll");

        logMsg(func +" Loading GL Debug RenderSystem!");
//        RERoot->loadPlugin(pluginDir + "/RenderSystem_Direct3D11_d.dll");
        RERoot->loadPlugin(pluginDir + "/RenderSystem_GL3Plus_d.dll");

//        RERoot->loadPlugin(pluginDir + "/Plugin_CgProgramManager_d");
    }
    else
    {
        logMsg(func +"Loading STBI Image Codec Plugin!");
        RERoot->loadPlugin(pluginDir +"/Codec_STBI.dll");
        
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

//    RERoot->loadPlugin(pluginDir +"/RenderSystem_GL_d");
    RERoot->loadPlugin(pluginDir + "/RenderSystem_GL3Plus_d");
//    RERoot->loadPlugin(pluginDir + "/Plugin_CgProgramManager");
#endif
//    exit(0);

#ifdef __ANDROID
    RERoot->setRenderSystem(RERoot->getAvailableRenderers().at(0));
#else
    Ogre::RenderSystemList rsList = RERoot->getAvailableRenderers();

    int c = 0;
    bool foundit = false;
    Ogre::RenderSystem *selectedRenderSystem = nullptr;
    while (c < (int)rsList.size())
    {
        selectedRenderSystem = rsList.at(c);
        std::string rname = selectedRenderSystem->getName();
//	if (rname.compare("OpenGL Rendering Subsystem") == 0)
        logMsg(func +" rname == " +rname);
//        exit(0);

        if (rname == "OpenGL Rendering Subsystem"
                || rname == "OpenGL 3+ Rendering Subsystem"
                || rname == "Direct3D11 Rendering Subsystem")
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
        logMsg(func +" rendersystem not found!");
	    exit(0);
    }
#endif
    
    
    mWindow = RERoot->initialise(false);

    // sets configuration options for Ogre Window
    cfgOpts =RERoot->getRenderSystem()->getConfigOptions();

    Ogre::ConfigOptionMap::iterator opt = cfgOpts.find( "Video Mode" );

    int width = 1280;
    int height = 720;

    if( opt != cfgOpts.end() && !opt->second.currentValue.empty() )
    {
        //Ignore leading space
        const Ogre::String::size_type start =
                opt->second.currentValue.find_first_of("012356789");
        //Get the width and height
        Ogre::String::size_type widthEnd = opt->second.currentValue.find(' ',
                                                                         start);
        // we know that the height starts 3 characters after the width and goes until the next space
        Ogre::String::size_type heightEnd =
                opt->second.currentValue.find(' ', widthEnd+3);
        // Now we can parse out the values
        width = Ogre::StringConverter::parseInt(
                    opt->second.currentValue.substr( 0, widthEnd ) );
        height =
                Ogre::StringConverter::parseInt( opt->second.currentValue.substr(
                                                     widthEnd+3, heightEnd ) );
    }

/*    misc["externalWindowHandle"] = winHandle;
//    misc["externalGLContext"] = convert->toString((unsigned long)SDL_GL_GetCurrentContext());
//    exit(0);
    logMsg("Hello??");
//    exit(0);
    mWindow = RERoot->createRenderWindow("Ultimate Basketball Challenge", 0, 0, false, &misc);
    exit(0);
*/
//    Ogre::DDSCodec::startup();
    
//    Ogre::FreeImageCodec::startup();
//    FreeImage_Initialise();
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

const char *renderEngine::getMediaReadArchiveType() const
{
#if OGRE_PLATFORM != OGRE_PLATFORM_ANDROID
    return "FileSystem";
#else
    return "APKFileSystem";
#endif
}

void renderEngine::registerHlms(void)
{
    std::string func = "renderEngine::registerHlms()";

    logMsg(func +"Setting up HLMS");


#if __ANDROID__
    std::string dataPath = "data";
#else
    std::string dataPath = UBC_DATADIR;
#endif

    hlmsManager = RERoot->getHlmsManager();

    logMsg(func +"Hlms setup");
    Ogre::ConfigFile cf;
 //   cf.load( AndroidSystems::openFile( mResourcePath + "resources2.cfg" ) );


    Ogre::String rootHlmsFolder = dataPath +"/Media/" +
                                  cf.getSetting("DoNotUseAsResource","Hlms","");

    logMsg(func +" " +rootHlmsFolder);
    if( rootHlmsFolder.empty() )
        rootHlmsFolder = "./";
    else if( *( rootHlmsFolder.end() - 1 ) != '/' )
        rootHlmsFolder += "/";

    Ogre::HlmsUnlit *hlmsUnlit = 0;
    Ogre::HlmsPbs *hlmsPbs = 0;

    //For retrieval of the paths to the different folders needed
    Ogre::String mainFolderPath;
    Ogre::StringVector libraryFoldersPaths;
    Ogre::StringVector::const_iterator libraryFolderPathIt;
    Ogre::StringVector::const_iterator libraryFolderPathEn;

    Ogre::ArchiveManager &archiveManager = Ogre::ArchiveManager::getSingleton();

    {
           // Create & Register HlmsUnlit
           // Get the path to all the subdirectories used by HlmsUnlit
           Ogre::HlmsUnlit::getDefaultPaths( mainFolderPath, libraryFoldersPaths );
           Ogre::Archive *archiveUnlit =
               archiveManager.load( rootHlmsFolder + mainFolderPath, "FileSystem", true );
           Ogre::ArchiveVec archiveUnlitLibraryFolders;
           libraryFolderPathIt = libraryFoldersPaths.begin();
           libraryFolderPathEn = libraryFoldersPaths.end();
           while( libraryFolderPathIt != libraryFolderPathEn )
           {
               Ogre::Archive *archiveLibrary =
                   archiveManager.load( rootHlmsFolder + *libraryFolderPathIt, "FileSystem", true );
               logMsg(func +" Unlit Path = " +*libraryFolderPathIt);

               archiveUnlitLibraryFolders.push_back( archiveLibrary );
               ++libraryFolderPathIt;
           }

           // Create and register the unlit Hlms
           hlmsUnlit = OGRE_NEW Ogre::HlmsUnlit( archiveUnlit, &archiveUnlitLibraryFolders );
           Ogre::Root::getSingleton().getHlmsManager()->registerHlms( hlmsUnlit );
       }

       {
           // Create & Register HlmsPbs
           // Do the same for HlmsPbs:
           Ogre::HlmsPbs::getDefaultPaths( mainFolderPath, libraryFoldersPaths );
           Ogre::Archive *archivePbs = archiveManager.load( rootHlmsFolder + mainFolderPath, "FileSystem", true );

           // Get the library archive(s)
           Ogre::ArchiveVec archivePbsLibraryFolders;
           libraryFolderPathIt = libraryFoldersPaths.begin();
           libraryFolderPathEn = libraryFoldersPaths.end();
           while( libraryFolderPathIt != libraryFolderPathEn )
           {
               Ogre::Archive *archiveLibrary =
                   archiveManager.load( rootHlmsFolder + *libraryFolderPathIt, "FileSystem", true );
               logMsg(func +" Pbs Path = " +*libraryFolderPathIt);
               archivePbsLibraryFolders.push_back( archiveLibrary );
               ++libraryFolderPathIt;
           }

           // Create and register
           hlmsPbs = OGRE_NEW Ogre::HlmsPbs( archivePbs, &archivePbsLibraryFolders );
           Ogre::Root::getSingleton().getHlmsManager()->registerHlms( hlmsPbs );
       }

/*    {
        //Create & Register HlmsUnlit
        //Get the path to all the subdirectories used by HlmsUnlit
        Ogre::HlmsUnlit::getDefaultPaths( mainFolderPath, libraryFoldersPaths );
        Ogre::Archive *archiveUnlit = archiveManager.load(rootHlmsFolder
                                                          +mainFolderPath,
                                                           archiveType, true );
        Ogre::ArchiveVec archiveUnlitLibraryFolders;
        libraryFolderPathIt = libraryFoldersPaths.begin();
        libraryFolderPathEn = libraryFoldersPaths.end();
        while( libraryFolderPathIt != libraryFolderPathEn )
        {
            logMsg(func +" dah");
            Ogre::Archive *archiveLibrary =
                    archiveManager.load( rootHlmsFolder + *libraryFolderPathIt, archiveType, true );
            archiveUnlitLibraryFolders.push_back( archiveLibrary );
            ++libraryFolderPathIt;
        }

        //Create and register the unlit Hlms
        hlmsUnlit = OGRE_NEW Ogre::HlmsUnlit( archiveUnlit, &archiveUnlitLibraryFolders );
        Ogre::Root::getSingleton().getHlmsManager()->registerHlms( hlmsUnlit );
    }

    {
        //Create & Register HlmsPbs
        //Do the same for HlmsPbs:
        Ogre::HlmsPbs::getDefaultPaths( mainFolderPath, libraryFoldersPaths );
        Ogre::Archive *archivePbs = archiveManager.load( rootHlmsFolder
                                                         +mainFolderPath,
                                                         archiveType, true );

        //Get the library archive(s)
        Ogre::ArchiveVec archivePbsLibraryFolders;
        libraryFolderPathIt = libraryFoldersPaths.begin();
        libraryFolderPathEn = libraryFoldersPaths.end();
        while( libraryFolderPathIt != libraryFolderPathEn )
        {
            Ogre::Archive *archiveLibrary =
                    archiveManager.load( rootHlmsFolder + *libraryFolderPathIt,
                                         archiveType, true );
            archivePbsLibraryFolders.push_back( archiveLibrary );
            ++libraryFolderPathIt;
        }

        //Create and register
        hlmsPbs = OGRE_NEW Ogre::HlmsPbs( archivePbs, &archivePbsLibraryFolders );
        Ogre::Root::getSingleton().getHlmsManager()->registerHlms( hlmsPbs );
    }
*/

    Ogre::RenderSystem *renderSystem = RERoot->getRenderSystem();
    if( renderSystem->getName() == "Direct3D11 Rendering Subsystem" )
    {
        //Set lower limits 512kb instead of the default 4MB per Hlms in D3D 11.0
        //and below to avoid saturating AMD's discard limit (8MB) or
        //saturate the PCIE bus in some low end machines.
        bool supportsNoOverwriteOnTextureBuffers;
        renderSystem->getCustomAttribute( "MapNoOverwriteOnDynamicBufferSRV",
                                          &supportsNoOverwriteOnTextureBuffers );

        if( !supportsNoOverwriteOnTextureBuffers )
        {
            hlmsPbs->setTextureBufferDefaultSize( 512 * 1024 );
            hlmsUnlit->setTextureBufferDefaultSize( 512 * 1024 );
        }
    }
}


bool renderEngine::createScene()
{
    conversionSharedPtr convert ;
    std::string func = "renderEngine::createScene()";
    
    logMsg(func +" begin");

    instance += 1;
//    exit(0);
#ifdef __ANDROID
    logMsg(func +" Hello");
    config = AConfiguration_new();
    logMsg(func +" Mello");
//    exit(0);
//	AConfiguration_fromAssetManager(config, app->activity->assetManager);
//	mAssetMgr = app->activity->assetManager;
    JNIEnv* env = (JNIEnv*)SDL_AndroidGetJNIEnv();

    jclass class_sdl_activity   = env->FindClass("com/libolt/ubc/UBCActivity");
    jmethodID method_get_native_surface = env->GetStaticMethodID(class_sdl_activity,
                                                                 "getNativeSurface",
                                                                 "()Landroid/view/Surface;");
    jobject raw_surface = env->CallStaticObjectMethod(class_sdl_activity,
                                                      method_get_native_surface);
    ANativeWindow* native_window = ANativeWindow_fromSurface(env, raw_surface);
    
    if ( !native_window )
    {
        logMsg(func +" No Window, Goodbye!");
        return(0);
    }
    
    jclass class_activity = env->FindClass("com/libolt/ubc/UBCActivity");
    jclass class_resources = env->FindClass("android/content/res/Resources");
    jmethodID method_get_resources = env->GetMethodID(class_activity,
                                                      "getResources",
                                                      "()Landroid/content/res/Resources;");
    jmethodID method_get_assets = env->GetMethodID(class_resources,
                                                   "getAssets",
                                                   "()Landroid/content/res/AssetManager;");
    jobject raw_activity = (jobject)SDL_AndroidGetActivity();
    jobject raw_resources = env->CallObjectMethod(raw_activity,
                                                  method_get_resources);
    jobject raw_asset_manager = env->CallObjectMethod(raw_resources,
                                                      method_get_assets);
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

    Ogre::ArchiveManager::getSingleton().addArchiveFactory(
                new Ogre::APKFileSystemArchiveFactory(mAssetMgr) );
    Ogre::ArchiveManager::getSingleton().addArchiveFactory(
                new Ogre::APKZipArchiveFactory(mAssetMgr) );
    logMsg(func +" Hello?");
//    exit(0);
#endif

    logMsg(func +" winHandle = " +winHandle);

    std::string windowTitle = "Ultimate Basketball Challenge";

    #if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
        misc.insert( std::make_pair("externalWindowHandle",  winHandle) );
    #elif OGRE_PLATFORM == OGRE_PLATFORM_LINUX
        misc.insert( std::make_pair("parentWindowHandle",  winHandle) );
    #endif

    misc.insert( std::make_pair("title", windowTitle) );
    misc.insert( std::make_pair("gamma",
                                cfgOpts["sRGB Gamma Conversion"].currentValue) );
    if( cfgOpts.find( "VSync Method" ) != cfgOpts.end() )
        misc.insert( std::make_pair( "vsync_method",
                                     cfgOpts["VSync Method"].currentValue ) );
    misc.insert( std::make_pair("FSAA", cfgOpts["FSAA"].currentValue) );
    misc.insert( std::make_pair("vsync", cfgOpts["VSync"].currentValue) );
    misc.insert( std::make_pair("reverse_depth", "Yes" ) );


    logMsg(func + " windowTitle = " +windowTitle);
    logMsg(func +" windowWidth = " +convert->toString(windowWidth));
    logMsg(func +" windowHeight = " +convert->toString(windowHeight));

    mWindow = RERoot->createRenderWindow(windowTitle, windowWidth,windowHeight,
                                         false, &misc);

    logMsg(func +" renderWindow created!");
//    std::size_t handle = 0;
//    mWindow->getCustomAttribute("WINDOW", &handle);
//    logMsg(func +" mWindow handle = " +convert->toString(handle));
    logMsg(func +" Dead");
#ifdef __ANDROID
    sdlWindow = SDL_CreateWindowFrom(mWindow.get());
#endif
     if (mWindow == nullptr)
     {
         logMsg(func +" createScene mWindow == nullptr!");
     }


    mResourceGroup = "UBCData";
//	Ogre::ResourceGroupManager *rsm
    rsm = Ogre::ResourceGroupManager::getSingletonPtr();
    rsm->createResourceGroup(mResourceGroup);

//    Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);

#if __ANDROID__
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
    Ogre::RTShader::ShaderGenerator* shaderGen =
            Ogre::RTShader::ShaderGenerator::getSingletonPtr();
	//Ogre::RTShader::ShaderGenerator::getSingletonPtr()->setTargetLanguage("glsles");
    shaderGen->setTargetLanguage("glsles");
    if (mMatListener == nullptr)
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
//    mWindow->set
//    mWindow->setVisible(true);
#endif
    logMsg(func +" Alive?");

#if __ANDROID__
    std::string dataPath = "data";
#else
    std::string dataPath = UBC_DATADIR;
//exit(0);

    // load the basic resource location(s)
    rsm->addResourceLocation(dataPath + "/Media", "FileSystem", mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/compositor", "FileSystem",
                             mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/fonts", "FileSystem",
                             mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/gui", "FileSystem",
                             mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/MyGUI_Media", "FileSystem",
                             mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/models", "FileSystem",
                             mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/materials/textures", "FileSystem",
                             mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/materials/programs", "FileSystem",
                             mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/materialss/scripts", "FileSystem",
                             mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/materials", "FileSystem",
                             mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/overlays", "FileSystem",
                             mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/packs", "FileSystem",
                             mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/skins", "FileSystem",
                             mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/skins/qgui", "FileSystem",
                             mResourceGroup);
    rsm->addResourceLocation(dataPath + "/Media/Audio", "FileSystem",
                             mResourceGroup);
    rsm->initialiseResourceGroup("UBCData", false);

#endif

    registerHlms();  // registers Hlms shader system

    //register HLMS
/*    rootHlmsFolder = dataPath + "/Media/";

    //For retrieval of the paths to the different folders needed
    Ogre::String mainFolderPath;
    Ogre::StringVector libraryFoldersPaths;
    Ogre::StringVector::const_iterator libraryFolderPathIt;
    Ogre::StringVector::const_iterator libraryFolderPathEn;

    Ogre::ArchiveManager &archiveManager = Ogre::ArchiveManager::getSingleton();

    {
        //Create & Register HlmsUnlit
        //Get the path to all the subdirectories used by HlmsUnlit
        Ogre::HlmsUnlit::getDefaultPaths( mainFolderPath, libraryFoldersPaths );
        logMsg(func +" mainFolderPath" +mainFolderPath);
//        exit(0);
        Ogre::Archive *archiveUnlit = archiveManager.load( rootHlmsFolder
                                                           +mainFolderPath,
                                                           "FileSystem", true );
        Ogre::ArchiveVec archiveUnlitLibraryFolders;
        libraryFolderPathIt = libraryFoldersPaths.begin();
        libraryFolderPathEn = libraryFoldersPaths.end();
        while( libraryFolderPathIt != libraryFolderPathEn )
        {
            Ogre::Archive *archiveLibrary =
                    archiveManager.load( rootHlmsFolder + *libraryFolderPathIt,
                                         "FileSystem", true );
            archiveUnlitLibraryFolders.push_back( archiveLibrary );

            ++libraryFolderPathIt;
        }

        //Create and register the unlit Hlms
        mHlmsUnlit = OGRE_NEW Ogre::HlmsUnlit( archiveUnlit,
                                               &archiveUnlitLibraryFolders );
        Ogre::Root::getSingleton().getHlmsManager()->registerHlms( mHlmsUnlit );
    }

    {
        //Create & Register HlmsPbs
        //Do the same for HlmsPbs:
        Ogre::HlmsPbs::getDefaultPaths( mainFolderPath, libraryFoldersPaths );
        Ogre::Archive *archivePbs = archiveManager.load( rootHlmsFolder
                                                         +mainFolderPath,
                                                         "FileSystem", true );

        //Get the library archive(s)
        Ogre::ArchiveVec archivePbsLibraryFolders;
        libraryFolderPathIt = libraryFoldersPaths.begin();
        libraryFolderPathEn = libraryFoldersPaths.end();
        while( libraryFolderPathIt != libraryFolderPathEn )
        {
            Ogre::Archive *archiveLibrary =
                    archiveManager.load( rootHlmsFolder + *libraryFolderPathIt,
                                         "FileSystem", true );
            archivePbsLibraryFolders.push_back( archiveLibrary );
            ++libraryFolderPathIt;
        }

        //Create and register
        mHlmsPbs = OGRE_NEW Ogre::HlmsPbs( archivePbs,
                                           &archivePbsLibraryFolders );
        Ogre::Root::getSingleton().getHlmsManager()->registerHlms( mHlmsPbs );
    }



    //configure shadow quality
    mHlmsPbs->setShadowSettings(Ogre::HlmsPbs::PCF_4x4);
*/
    
#if OGRE_VERSION_MAJOR == 1 && OGRE_VERSION_MINOR <= 10
    mSceneMgr = sharedPtr<Ogre::SceneManager>(
                RERoot->createSceneManager(Ogre::ST_GENERIC)); // creates the scene manager
#else
    const std::size_t numThreads = std::max<std::size_t>(1,
                                               Ogre::PlatformInformation::getNumLogicalCores() );
    mSceneMgr = RERoot->createSceneManager(Ogre::ST_GENERIC, numThreads,
                                           "UBCSceneManager"); // creates the scene manager
    logMsg(func +"mSceneMgr setup");
#endif

//    mSceneMgr = RERoot->createSceneManager("DefaultSceneManager"); // creates the scene manager

    mCamera = mSceneMgr->createCamera("camera");

    const Ogre::String workspaceName( "MyOwnWorkspace" );
    compositorManager = RERoot->getCompositorManager2();
    Ogre::CompositorChannelVec externalChannels(1);

    if( !compositorManager->hasWorkspaceDefinition( workspaceName ) )
        compositorManager->createBasicWorkspaceDef( workspaceName,
                                                    Ogre::ColourValue( 0.6f,
                                                                       0.0f,
                                                                       0.6f));

    compositorManager->addWorkspace( mSceneMgr, mWindow->getTexture(),
                                     mCamera, workspaceName, true );

    logMsg(func +"Compositor setup");

/*
#ifdef __ANDROID
	mCamera->setNearClipDistance(1.0f);
	mCamera->setFarClipDistance(100000.0f);
	mCamera->setPosition(0, 0, 20.0f);
	mCamera->lookAt(0, 0, 0);
	mCamera->setAutoAspectRatio(true);
#endif
*/


    // Position it at 500 in Z direction
    mCamera->setAutoAspectRatio(true);
    mCamera->setPosition(Ogre::Vector3(0, 0, 455));
    // Look back along -Z
    mCamera->lookAt(Ogre::Vector3(0, 0, -300));

    mCamera->setNearClipDistance(5);
    mCamera->setFarClipDistance(5000);
    cameraNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    mCamera->detachFromParent();
    cameraNode->attachObject(mCamera);
    logMsg(func +"Camera setup");
//    viewPort = sharedPtr<Ogre::Viewport>(mWindow->addViewport(mCamera.get()));
// 2.2    viewPort = sharedPtr<Ogre::Viewport>(mWindow->addViewport());

//    viewPort->setBackgroundColour(Ogre::ColourValue(0, 0, 0));

//    mCamera->setAspectRatio(Ogre::Real(viewPort->getActualWidth()) / Ogre::Real(viewPort->getActualHeight()));

    // most examples get the viewport size to calculate this; for now, we'll just
    // set it to 4:3 the easy way

#ifdef __ANDROID
    viewPort->setMaterialScheme(
                Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME);
#endif
    viewPort->setOverlaysEnabled(true);	// sets overlays true so that MyGUI can render

    bool overlayEnabled = viewPort->getOverlaysEnabled();
    logMsg(func +" overlayEnabled = " +convert->toString(overlayEnabled));
//.0.236	exit(0);
//    mCamera->setAspectRatio((Ogre::Real)1.333333);

    // Set ambient light
/// OGRE21 Removal
///    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5),
///                               Ogre::ColourValue( 0.6f, 0.45f, 0.3f ) * 0.065f * 0.75f,
///                               -light->getDirection() + Ogre::Vector3::UNIT_Y * 0.2f );


    // Create a light
    light = mSceneMgr->createLight();
    lightNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    lightNode->attachObject(light);
    lightNode->setPosition(20,80,56);
    light->setPowerScale(1);
    logMsg(func +"light setup");

    if (mWindow == nullptr)
    {
        logMsg(func +" createScene mWindow 2 == nullptr!");
        exit(0);
    }


/*    bball = Ogre::v1::Entity(mSceneMgr->createEntity("bball.mesh",
                                                        "UBCData"));
    bballNode = Ogre::SceneNode(
                mSceneMgr->getRootSceneNode()->createChildSceneNode());
    bballNode->setName("bball");
    bballNode->attachObject(bball.get());
    bballNode->setScale(1.0f,1.0f,1.0f);
    bballNode->setPosition(0.8f,-5.0f,352.0f);
    compositorManager->addNodeDefinition("bball");

    if (bball == nullptr)
    {
        logMsg(func +"bball.mesh didn't load");
        exit(0);
    }
*/
	//	    Ogre::LogManager::getSingletonPtr()->logMessage("winHandle = " +winHandle);

	// this next bit is for the sake of the input handler
	//	unsigned long hWnd;
	//		mWindow->getCustomAttribute("WINDOW", &winHandle);
/*
#ifdef __ANDROID
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

Ogre::SceneNode *renderEngine::createNode(Ogre::v1::Entity *model,
                                                const std::string &entityNodeName)  // create scene node for model
{
    Ogre::SceneNode *tempNode; //(new Ogre::SceneNode);
    conversionSharedPtr convert ;
//    std::string entityNodeName;
//    std::string entityNodeNum;
    std::string func = "render::createNode()";


//    entityNodeNum = convert->toString(nodeNum);
//    entityNodeName = entityName +"node" +entityNodeNum;
//    logMsg(func +" entityNodeName == " +entityNodeName);
//    exit(0);
    tempNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    logMsg(func +" tempNode created!");
    tempNode->setName(entityNodeName);
//    tempNode->setName();
//FIXME!    tempNode->attachObject(model);
    logMsg(func +" node attached!");

    // attaches 3D model to the node
//    node->attachObject(model);
    // sets the size of the bball node
    tempNode->setScale(0.25f,0.25f,0.25f);
    tempNode->setPosition(0.0f,0.0f,0.0f);

//    node = tempNode;
    logMsg(func +" ECB node name == " +tempNode->getName());
    logMsg(func +" node position == " +convert->toString(
               tempNode->getPosition()));
//    exit(0);
///    logMsg("scene node created!");
///    node->attachObject(model);
///    logMsg("node attached!");
    // attaches 3D model to the node
//    node->attachObject(model);
    // sets the size of the bball node
///    node->setScale(0.25f,0.25f,0.25f);
///    node->setPosition(0.0f,0.0f,0.0f);

    return (tempNode);
}

bool renderEngine::renderFrame()  // renders a frame to the screen
{
    conversionSharedPtr convert ;
    std::string func = "renderEngine::renderFrame()";
    
    logMsg(func +" begin");

//    exit(0);
    logMsg(func +" Rendering Frame!");
    logMsg(func +" Render Instance == " +convert->toString(instance));
    if (mWindow == nullptr)
    {
        logMsg(func +" mWindow is nullptr!");
    }
    
    if (mWindow != nullptr && mWindow->isFocused())
    {
//        logMsg(func +" LastFPS == " +convert->toString(mWindow->getLastFPS()));
//      Ogre::LogManager::getSingletonPtr()->logMessage("Rendering frame");
        mWindow->windowMovedOrResized();
//        exit(0);
        logMsg(func +" windowMovedOrResized()");
        logMsg(func +" RERoot is initialized = " +convert->toString(
                   RERoot->isInitialised()));
        RERoot->renderOneFrame();
//        exit(0);
        logMsg(func +" Frame Rendered!");

    }
//    exit(0);
    
    logMsg(func +" end");

    return (true);
}

