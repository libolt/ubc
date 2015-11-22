APP_CFLAGS := -fno-lto
APP_CPPFLAGS := -fno-lto
APP_LDFLAGS := -fno-lto 


LOCAL_PATH := $(call my-dir)

BUILD_ROOT := ../../..
UBC_DEPENDS_PATH := $(BUILD_ROOT)/ubc-depends
UBC_DEPENDS_LIB_PATH := $(UBC_DEPENDS_PATH)/lib
UBC_DEPENDS_INC_PATH := $(UBC_DEPENDS_PATH)/include


   include $(CLEAR_VARS)
   LOCAL_MODULE := Native-App-Glue-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libandroid_native_app_glue.a
   include $(PREBUILT_STATIC_LIBRARY)
   
   include $(CLEAR_VARS)
   LOCAL_MODULE := Cpu-Features-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libcpufeatures.a
   include $(PREBUILT_STATIC_LIBRARY)
   

   include $(CLEAR_VARS)
   LOCAL_MODULE := ALMixer-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libalmixer.so
   include $(PREBUILT_SHARED_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := OpenAL-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libopenal.so
   include $(PREBUILT_SHARED_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := OGG-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libogg.so
   include $(PREBUILT_SHARED_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := Vorbis-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libvorbis.so
   include $(PREBUILT_SHARED_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := Vorbis-JNI-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libvorbis-jni.so
   include $(PREBUILT_SHARED_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := SDL2-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libSDL2.so
   include $(PREBUILT_SHARED_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := Boost-Atomic-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libboost_atomic-gcc-mt-s-1_58.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := Boost-Chrono-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libboost_chrono-gcc-mt-s-1_58.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := Boost-System-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libboost_system-gcc-mt-s-1_58.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := Boost-Thread-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libboost_thread_pthread-gcc-mt-s-1_58.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := OgreMain-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libOgreMainStatic.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := OgreOverlay-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libOgreOverlayStatic.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := OgreProperty-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libOgrePropertyStatic.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := OgreRTShaderSystem-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libOgreRTShaderSystemStatic.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := OgreParticleFXplugin-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/OGRE/libPlugin_ParticleFXStatic.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := OgreRenderSystem_GLES2-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/OGRE/libRenderSystem_GLES2Static.a
   include $(PREBUILT_STATIC_LIBRARY)
   
   include $(CLEAR_VARS)
   LOCAL_MODULE := BtOgre-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libBtOgre.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := BulletCollision-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libBulletCollision.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := BulletDynamics-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libBulletDynamics.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := BulletFileLoader-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libBulletFileLoader.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := BulletSoftbody-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libBulletSoftBody.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := BulletWorldImporter-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libBulletWorldImporter.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := BulletXmlWorldImporter-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libBulletXmlWorldImporter.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := BulletConvexDecomposition-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libConvexDecomposition.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := BulletGIMPACTUtils-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libGIMPACTUtils.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := BulletHACD-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libHACD.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := BulletLinearMath-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libLinearMath.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := ENet-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libenet.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := FreeImage-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libFreeImage.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := FreeType-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libfreetype.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := MyGUIEngine-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libMyGUIEngine.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := MyGUIOgrePlatform-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libMyGUIOgrePlatform.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := MyGUIOpenGLESPlatform-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libMyGUIOpenGLESPlatform.a
   include $(PREBUILT_STATIC_LIBRARY)
   
   include $(CLEAR_VARS)
   LOCAL_MODULE := OpenSteer-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libopensteer.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := SDL_Sound-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libsdl_sound.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := TinyXML2-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libtinyxml2.a
   include $(PREBUILT_STATIC_LIBRARY)
   
   include $(CLEAR_VARS)
   LOCAL_MODULE := ZLib-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libzlib.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := ZZipLib-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libzziplib.a
   include $(PREBUILT_STATIC_LIBRARY)

#LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES  := ALMixer-Prebuilt OpeanAL-Prebuilt OGG-Prebuilt Vorbis-Prebuilt  SDL2-Prebuilt 
LOCAL_STATIC_LIBRARIES  := Boost-System-Prebuilt MyGUIOgrePlatform-Prebuilt MyGUIEngine-Prebuilt TinyXML2-Prebuilt BtOgre-Prebuilt BulletDynamics-Prebuilt BulletCollision-Prebuilt BulletSoftbody-Prebuilt BulletLinearMath-Prebuilt OgreRTShaderSystem-Prebuilt OgreRenderSystem_GLES2-Prebuilt OgreMain-Prebuilt OgreParticleFXPlugin-Prebuilt OpenSteer-Prebuilt Boost-Thread-Prebuilt Boost-Chrono-Prebuilt FreeImage-Prebuilt ZZipLib-Prebuilt FreeType-Prebuilt ENet-Prebuilt Native-App-Glue-Prebuilt Cpu-Features-Prebuilt 
 # BtOgre-Prebuilt  BulletCollision-Prebuilt BulletDynamics-Prebuilt BulletSoftbody-Prebuilt BulletLinearMath-Prebuilt Boost-Atomic-Prebuilt Boost-Chrono-Prebuilt Boost-System-Prebuilt Boost-Thread-Prebuilt Native-App-Glue-Prebuilt Cpu-Features-Prebuilt 
#LOCAL_SHARED_LIBRARIES  += OgreMain-Prebuilt OgreOverlay-Prebuilt OgreProperty-Prebuilt OgreRTShaderSystem-Prebuilt OgreRenderSystem_GLES2-Prebuilt
#LOCAl_STATIC_LIBRARIES  += 
#LOCAL_SHARED_LIBRARIES  += FreeImage-Prebuilt FreeType-Prebuilt 
#LOCAL_SHARED_LIBRARIES  += MyGUIEngine-Prebuilt MyGUIOgrePlatform-Prebuilt
#LOCAL_SHARED_LIBRARIES  += OpenSteer-Prebuilt SDL_Sound-Prebuilt TinyXML-Prebuilt ZLib-Prebuilt ZZipLib-Prebuilt
LOCAL_STATIC_LIBRARIES  +=  android_native_app_glue cpufeatures  gnustl_static supc++
 
LOCAL_MODULE := UltimateBasketballChallenge

#ALMIXER_PATH = $(BUILD_ROOT)/almixer
#BTOGRE_PATH := $(BUILD_ROOT)/btogre
#BULLET_PATH := $(BUILD_ROOT)bullet4droid
#ENET_PATH := $(BUILD_ROOT)/enet 
#MYGUI_PATH := $(BUILD_ROOT)/mygui-svn
#SDL_PATH := $(BUILD_ROOT)/SDL2
#TINYXML_PATH := $(BUILD_ROOT)/tinyxml
#OPENSTEER_PATH := ${BUILD_ROOT}/opensteer
#OGRE_PATH := ../../../../OgreSDK/Ogre
#OGREDEPS_PATH :=../../../../OgreSDK/Dependencies
#OGGVORBIS_PATH := ${BUILD_ROOT}/libvorbislibogg
#OPENAL_PATH := ${BUILD_ROOT}/openal-soft

UBC_ROOT := $(BUILD_ROOT)/ubc
UBC_SRC_DIR := $(UBC_ROOT)/src/game

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/bullet
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/enet
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/SDL2
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/boost-1_58
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/OGRE
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/OGRE/Overlay
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/OGRE/RTShaderSystem 
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/OGRE/PlugIns/ParticleFX 
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/OGRE/PlugIns/OctreeSceneManager
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/OGRE/RenderSystems/GLES2
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/OGRE/RenderSystems/GLES2/EGL
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/AL
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/MYGUI
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../include/ai
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../include/engine
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../include/entity
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../include/gui
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../include/network
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../include/physics
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../include/state

LOCAL_SRC_FILES := \
                   $(subst $(LOCAL_PATH)/,, \
                       $(wildcard $(LOCAL_PATH)/../../src/game/*.cpp)) \
                   $(subst $(LOCAL_PATH)/,, \
                       $(wildcard $(LOCAL_PATH)/../../src/game/*.c)) \
                   $(subst $(LOCAL_PATH)/,, \
                       $(wildcard $(LOCAL_PATH)/../../src/game/ai/*.cpp)) \
                   $(subst $(LOCAL_PATH)/,, \
                       $(wildcard $(LOCAL_PATH)/../../src/game/gui/*.cpp)) \
                   $(subst $(LOCAL_PATH)/,, \
                       $(wildcard $(LOCAL_PATH)/../../src/game/network/*.cpp)) \
                   $(subst $(LOCAL_PATH)/,, \
                       $(wildcard $(LOCAL_PATH)/../../src/game/sound/*.cpp)) \
                   $(subst $(LOCAL_PATH)/,, \
                       $(wildcard $(LOCAL_PATH)/../../src/game/physics/*.cpp)) \
                   $(subst $(LOCAL_PATH)/,, \
                       $(wildcard $(LOCAL_PATH)/../../src/game/state/*.cpp)) \
                   $(subst $(LOCAL_PATH)/,, \
                       $(wildcard $(LOCAL_PATH)/../../src/game/entity/*.cpp)) \
                   $(subst $(LOCAL_PATH)/,, \
                       $(wildcard $(LOCAL_PATH)/../../src/game/engine/*.cpp)) \

LOCAL_LDLIBS	:= -landroid -lc -lm -ldl -llog -lEGL -lGLESv1_CM -lGLESv2 

LOCAL_CFLAGS := -w -fno-lto -fPIC -frtti -fexceptions -fpermissive -x c++ -D___ANDROID___ -DANDROID -DZZIP_OMIT_CONFIG_H -std=c++11  $(COMMON_FLAGS_LIST) 
LOCAL_CPPFLAGS := -fno-lto
LOCAL_LDFLAGS := -fno-lto
APP_CFLAGS := -fno-lto
APP_CPPFLAGS := -fno-lto
APP_LDFLAGS := -fno-lto

#LOCAL_CPPFLAGS :=  $(COMMON_FLAGS_LIST) -DOGRE_NO_GLES3_SUPPORT=1
include $(BUILD_SHARED_LIBRARY)

#$(call import-module,android/cpufeatures) 
#$(call import-module,android/native_app_glue) 
#$(CALL IMPORT-MODULE,ENet-Prebuilt)
