/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean   *
 *   libolt@libolt.net   *
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
#include "android-config.h"
#else
#include "config.h"
#endif


#include "conversion.h"
#include "renderengine.h"
#include "gameengine.h"
#include "gamestate.h"
#include "gui.h"
#include "logging.h"
#include "physicsengine.h"
#include "soundengine.h"

#define FREEIMAGE_LIB
#include "FreeImage.h"
#include "OgreDDSCodec.h"
#include "OgreFreeImageCodec.h"

#ifndef OGRE_PLUGIN_DIR
#define OGRE_PLUGIN_DIR
#endif
//renderEngine* renderEngine::pInstance = 0;
boost::shared_ptr<renderEngine> renderEngine::pInstance;


//renderEngine* renderEngine::Instance()
boost::shared_ptr<renderEngine> renderEngine::Instance()

{
    if (pInstance == 0)  // is it the first call?
    {
//        pInstance = new renderEngine; // create sole instance
        boost::shared_ptr<renderEngine> tInstance(new renderEngine);
        pInstance = tInstance;
    }
    return pInstance; // address of sole instance
}


renderEngine::renderEngine()
{
#ifdef __ANDROID__
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    gStaticPluginLoader = NULL;
	mAssetMgr = NULL;
	mSceneMgr = NULL;
#endif
   mWindow = NULL;
   mRoot = NULL;
   
   windowWidth = 0;
   windowHeight = 0;
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
Ogre::Root *renderEngine::getMRoot()
{
	return (mRoot);
}
void renderEngine::setMRoot(Ogre::Root *root)
{
	mRoot = root;
}

Ogre::Camera *renderEngine::getMCamera()
{
	return (mCamera);
}
void renderEngine::setMCamera(Ogre::Camera *camera)
{
	mCamera = camera;
}

Ogre::SceneManager *renderEngine::getMSceneMgr()
{
	return (mSceneMgr);
}
void renderEngine::setMSceneMgr(Ogre::SceneManager *sceneMgr)
{
	mSceneMgr = sceneMgr;
}

Ogre::RenderWindow *renderEngine::getMWindow()
{
	return (mWindow);
}
void renderEngine::setMWindow(Ogre::RenderWindow *window)
{
	mWindow = window;
}

Ogre::Viewport *renderEngine::getViewPort() // retrieves the value of viewPort
{
	return (viewPort);
}
void renderEngine::setViewPort(Ogre::Viewport *vp) // sets the value of viewPort
{
	viewPort = vp;
}

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID

AAssetManager *renderEngine::getMAssetMgr()
{
	return (mAssetMgr);
}
void renderEngine::setMAssetMgr(AAssetManager *asset)
{
	mAssetMgr = asset;
}
android_app *renderEngine::getApp()
{
	return (app);
}
void renderEngine::setApp(android_app *ap)
{
	app = ap;
}
#endif

Ogre::Vector3 renderEngine::getMTranslateVector()
{
	return (mTranslateVector);
}
void renderEngine::setMTranslateVector(Ogre::Vector3 vector)
{
	mTranslateVector = vector;
}

Ogre::Radian renderEngine::getMRotX()
{
	return (mRotX);
}
void renderEngine::setMRotX(Ogre::Radian rotX)
{
	mRotX = rotX;
}

Ogre::Radian renderEngine::getMRotY()
{
	return (mRotY);
}
void renderEngine::setMRotY(Ogre::Radian rotY)
{
	mRotY = rotY;
}

Ogre::Real renderEngine::getMMoveSpeed()
{
	return (mMoveSpeed);
}
void renderEngine::setMMoveSpeed(Ogre::Real speed)
{
	mMoveSpeed = speed;
}

Ogre::Degree renderEngine::getMRotateSpeed()
{
	return (mRotateSpeed);
}
void renderEngine::setMRotateSpeed(Ogre::Degree speed)
{
	mRotateSpeed = speed;
}

float renderEngine::getMMoveScale()
{
	return (mMoveScale);
}
void renderEngine::setMMoveScale(float scale)
{
	mMoveScale = scale;
}

Ogre::Degree renderEngine::getMRotScale()
{
	return (mRotScale);
}
void renderEngine::setMRotScale(Ogre::Degree scale)
{
	mRotScale = scale;
}

std::string renderEngine::getMResourceGroup()
{
	return (mResourceGroup);
}

void renderEngine::setMResourceGroup(std::string resource)
{
	mResourceGroup = resource;
}

SDL_Window *renderEngine::getSDLWindow()
{
	return (sdlWindow);
}

void renderEngine::setSDLWindow(SDL_Window *window)
{
	sdlWindow = window;
}

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

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
Ogre::DataStreamPtr renderEngine::openAPKFile(const std::string& fileName)
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
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
        fprintf(stderr,
                "\nUnable to initialize SDL:  %s\n",
                SDL_GetError()
               );
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID

//        __android_log_print(ANDROID_LOG_DEBUG, "com.libolt.ubc", "SDL Error = %s", SDL_GetError());
        std::string msg = "SDL Error = " +convert->toString(SDL_GetError());
        logMsg(msg);
#endif

        return 1;
    }

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
	logMsg(message);

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

	return true;
}

/*    sdlWindow = SDL_CreateWindow("Ultimate Basketball Challenge",
                               SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, 0);
*/
//    winHandle =  convert->toString((unsigned long)native_window);
//    sdlWindow = SDL_CreateWindowFrom(app->window);

/*    sdlWindow = SDL_CreateWindow("Ultimate Basketball Challenge", SDL_WINDOWPOS_UNDEFINED,
                                 SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);


    sdlWindow = SDL_CreateWindow("Ultimate Basketball Challenge", SDL_WINDOWPOS_UNDEFINED,
                                 SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_INPUT_GRABBED | SDL_WINDOW_OPENGL | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MOUSE_FOCUS | SDL_WINDOW_SHOWN);
*/
//  sdlGLContext = SDL_GL_CreateContext(sdlWindow);
//    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 0);

//    SDL_SetWindowGrab(sdlWindow, SDL_TRUE);
//    SDL_SetRelativeMouseMode(SDL_TRUE);

bool renderEngine::initOgre() // Initializes Ogre Subsystem
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    
	//    GUISystem *gui = GUISystem::Instance();
	//    SoundSystem *sound = SoundSystem::Instance();

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    winHandle = convert->toString((unsigned long /*int*/)sysInfo.info.win.window);
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
	logMsg("winHandle = " +winHandle);
//    exit(0);
//	logMsg("winHandle2 = " +winHandle2);
	
//	logMsg("grabbed = " +convert->toString(SDL_GetWindowGrab(sdlWindow)));
#else
	// Error, both can't be defined or undefined same time
#endif
    FreeImage_Initialise();
    
	//std::cout << "winHandle = " << winHandle << std::endl;
	mRoot = new Ogre::Root("", "", "Ogre.log");
	const std::string pluginDir = OGRE_PLUGIN_DIR;
    logMsg("winHandle for Ogre = " +winHandle);

//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//#else
//	inputSystem *input = inputSystem::Instance();
//#endif
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	const std::string buildType = BUILD_TYPE;

	if (buildType == "Debug")
	{
		mRoot->loadPlugin(pluginDir + "/RenderSystem_Direct3D9_d.dll");
//		mRoot->loadPlugin(pluginDir + "/Plugin_CgProgramManager_d");
	}
	else
	{
		mRoot->loadPlugin(pluginDir + "/RenderSystem_Direct3D9");
//		mRoot->loadPlugin(pluginDir + "/Plugin_CgProgramManager");
	}
#elif OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	//	    mRoot->loadPlugin();
#ifdef OGRE_STATIC_LIB
	gStaticPluginLoader = new Ogre::StaticPluginLoader();
	gStaticPluginLoader->load();
#endif
#elif OGRE_PLATFORM == OGRE_PLATFORM_APPLE
	mRoot->loadPlugin("RenderSystem_GL");
#else
	mRoot->loadPlugin(pluginDir + "/RenderSystem_GL");
	mRoot->loadPlugin(pluginDir + "/Plugin_CgProgramManager");
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	mRoot->setRenderSystem(mRoot->getAvailableRenderers().at(0));
	mRoot->initialise(false);
#else
	Ogre::RenderSystemList rsList = mRoot->getAvailableRenderers();

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

	//we found it, we might as well use it!
	mRoot->setRenderSystem(selectedRenderSystem);
	mWindow = mRoot->initialise(false, "Ultimate Basketball Challenge");
#endif

    Ogre::DDSCodec::startup();
    Ogre::FreeImageCodec::startup();FreeImage_Initialise();
    Ogre::DDSCodec::startup();
    Ogre::FreeImageCodec::startup();
    logMsg("OGRE initialized successfully!");

	return true;
}

void renderEngine::createSceneManager()
{
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

    // Create the SceneManager, in this case a generic one
    render->setMSceneMgr(render->getMRoot()->createSceneManager(Ogre::ST_EXTERIOR_CLOSE));

}

bool renderEngine::createWindow()
{
	return true;
}



bool renderEngine::createScene()
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    logMsg("Hello");
	config = AConfiguration_new();
	logMsg("Mello");
//	AConfiguration_fromAssetManager(config, app->activity->assetManager);
//	mAssetMgr = app->activity->assetManager;
    JNIEnv* env = (JNIEnv*)SDL_AndroidGetJNIEnv();

    jclass class_sdl_activity   = env->FindClass("com/libolt/ubc/UBCActivity");
    jmethodID method_get_native_surface = env->GetStaticMethodID(class_sdl_activity, "getNativeSurface", "()Landroid/view/Surface;");
    jobject raw_surface = env->CallStaticObjectMethod(class_sdl_activity, method_get_native_surface);
    ANativeWindow* native_window = ANativeWindow_fromSurface(env, raw_surface);

    if ( !native_window )
	{
		logMsg("No Window, Goodbye!");
        return(0);
	}

    jclass class_activity       = env->FindClass("com/libolt/ubc/UBCActivity");
    jclass class_resources      = env->FindClass("android/content/res/Resources");
    jmethodID method_get_resources      = env->GetMethodID(class_activity, "getResources", "()Landroid/content/res/Resources;");
    jmethodID method_get_assets         = env->GetMethodID(class_resources, "getAssets", "()Landroid/content/res/AssetManager;");
    jobject raw_activity = (jobject)SDL_AndroidGetActivity();
	jobject raw_resources = env->CallObjectMethod(raw_activity, method_get_resources);
    jobject raw_asset_manager = env->CallObjectMethod(raw_resources, method_get_assets);
//    jobject raw_surface = env->CallStaticObjectMethod(class_sdl_activity, method_get_native_surface);

//    ANativeWindow* native_window = ANativeWindow_fromSurface(env, raw_surface);

    uint32_t w = ANativeWindow_getWidth(native_window);
    uint32_t h = ANativeWindow_getHeight(native_window);

    logMsg("Width = " +convert->toString(w));
    logMsg("Height = " +convert->toString(h));
    
    windowWidth = w;
    windowHeight = h;
    
    mAssetMgr = AAssetManager_fromJava(env, raw_asset_manager);
	logMsg("Yello");
    AConfiguration_fromAssetManager(config, mAssetMgr);
	logMsg("Bello");
//	mAssetMgr = app->activity->assetManager;

    Ogre::ArchiveManager::getSingleton().addArchiveFactory( new Ogre::APKFileSystemArchiveFactory(mAssetMgr) );
    Ogre::ArchiveManager::getSingleton().addArchiveFactory( new Ogre::APKZipArchiveFactory(mAssetMgr) );
	logMsg("Hello?");
#endif
	//  AConfiguration_fromAssetManager(config, app->activity->assetManager);
	//gAssetMgr = app->activity->assetManager;
//	misc["currentGLContext"] = "true";
//	misc["androidConfig"] = convert->toString((int)config);
    //    misc["externalWindowHandle"] = convert->toString((int)app->window);

//	misc["currentGLContext"]     = "true";
//    misc["externalGLContext"]    = convert->toString((int)sdlWindow);
//    winHandle = convert->toString((unsigned long)sysInfo.info.android.window);
    
	misc["externalWindowHandle"] = winHandle;
//	misc["externalGLContext"] = convert->toString((unsigned long)SDL_GL_GetCurrentContext());
//	exit(0);
	logMsg("Hello??");
	mWindow = mRoot->createRenderWindow("Ultimate Basketball Challenge", 1280, 1024, false, &misc);
//	exit(0);
    logMsg("renderWindow created!");
	unsigned long handle = 0;
	mWindow->getCustomAttribute("WINDOW", &handle);
    logMsg("mWindow handle = " +convert->toString(handle));

    logMsg("Dead");
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	sdlWindow = SDL_CreateWindowFrom(mWindow);
#endif
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
	Ogre::ResourceGroupManager *rsm = Ogre::ResourceGroupManager::getSingletonPtr();
	rsm->createResourceGroup(mResourceGroup);


#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	Ogre::ConfigFile cf;
	cf.load(openAPKFile("resources.cfg"));
    logMsg("or");
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
	Ogre::RTShader::ShaderGenerator::getSingletonPtr()->setTargetLanguage("glsles");
	mMatListener = new Ogre::ShaderGeneratorTechniqueResolverListener();
	Ogre::MaterialManager::getSingleton().addListener(mMatListener);
#else

	// logMsg("Rendering!");
	misc["externalWindowHandle"] = winHandle; //

//    mWindow = mRoot->createRenderWindow("Ultimate Basketball Challenge", 1280, 1024, false, &misc);

	//    exit(0);
	mWindow->setVisible(true);
#endif
logMsg("Alive?");

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

	mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC); // for OGRE 1.2 Dagon
	mCamera = mSceneMgr->createCamera("camera");

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

	viewPort = mWindow->addViewport(mCamera);
	viewPort->setBackgroundColour(Ogre::ColourValue(0, 0, 0));

	// most examples get the viewport size to calculate this; for now, we'll just
	// set it to 4:3 the easy way

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	viewPort->setMaterialScheme(Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME);
#endif
	viewPort->setOverlaysEnabled(true);	// sets overlays true so that MyGUI can render

    bool overlayEnabled = viewPort->getOverlaysEnabled();
    logMsg("overlayEnabled = " +convert->toString(overlayEnabled));
//.0.236	exit(0);
	mCamera->setAspectRatio((Ogre::Real)1.333333);

    // Set ambient light
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

    // Create a light
    Ogre::Light* l = mSceneMgr->createLight("MainLight");
    l->setPosition(20,80,56);

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
//    basketballs *basketball = basketballs::Instance();
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();


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
//	exit(0);
  //  gameE->startGame();
return (true);
}
