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

//#include "RTShaderHelper.h"

#define OGRE_STATIC_GLES2
//#define OGRE_STATIC_ParticleFX
//#define OGRE_STATIC_OctreeSceneManager
#include "OgreStaticPluginLoader.h"

#include <EGL/egl.h>
#include <android/log.h>
//#include <android_native_app_glue.h>

#include "Ogre.h"
#include "OgreRenderWindow.h"
#include "OgreStringConverter.h"
#include "RTShaderHelper.h"
//#include "Android/OgreAndroidEGLWindow.h"
#include "Android/OgreAPKFileSystemArchive.h"
#include "Android/OgreAPKZipArchive.h"


//static Ogre::RenderWindow* gRenderWnd = NULL;
//static Ogre::Root* gRoot = NULL;
static Ogre::StaticPluginLoader* gStaticPluginLoader = NULL;
//static AAssetManager* gAssetMgr = NULL; 
//static Ogre::SceneManager* gSceneMgr = NULL;
static Ogre::ShaderGeneratorTechniqueResolverListener* gMatListener = NULL;

//static int32_t handleInput(struct android_app* app, AInputEvent* event);

//static void handleCmd(struct android_app* app, int32_t cmd);

