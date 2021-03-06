# - Find MyGUI includes and library
#
# This module defines
# MYGUI_INCLUDE_DIRS
# MYGUI_LIBRARIES, the libraries to link against to use MYGUI.
# MYGUI_LIB_DIR, the location of the libraries
# MYGUI_FOUND, If false, do not try to use MYGUI
#
# Copyright  2007, Matt Williams
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.
CMAKE_POLICY(PUSH)
include(FindPkgMacros)

# IF (MYGUI_LIBRARIES AND MYGUI_INCLUDE_DIRS)
    # SET(MYGUI_FIND_QUIETLY TRUE)
# ENDIF (MYGUI_LIBRARIES AND MYGUI_INCLUDE_DIRS)

MESSAGE(STATUS "Looking for MyGUI")

IF (WIN32) #Windows
    SET(MYGUISDK $ENV{MYGUI_HOME})
    IF (MYGUISDK)
        findpkg_begin("MYGUI")
        MESSAGE(STATUS "Using MyGUI in MyGUI SDK")
        STRING(REGEX REPLACE "[\\]" "/" MYGUISDK "${MYGUISDK}")

        find_path(MYGUI_INCLUDE_DIRS
                  MyGUI.h
		  "${MYGUISDK}/MyGUIEngine/include"
                  "${MYGUISDK}/include/MYGUI"
                  NO_DEFAULT_PATH)

        find_path(MYGUI_PLATFORM_INCLUDE_DIRS
                  MyGUI_Ogre2Platform.h
                  "${MYGUISDK}/Platforms/Ogre/OgrePlatform/include"
                  "${MYGUISDK}/include/MYGUI"
                  NO_DEFAULT_PATH)

        SET(MYGUI_LIB_DIR ${MYGUISDK}/lib ${MYGUISDK}/*/lib)

	IF (MSVC)
            find_library(MYGUI_LIBRARIES_REL
                         NAMES MyGUIEngine.lib MyGUI.Ogre2Platform.lib
                         HINTS ${MYGUI_LIB_DIR}
                         PATH_SUFFIXES "" release relwithdebinfo minsizerel)

            find_library(MYGUI_LIBRARIES_DBG
                         NAMES MyGUIEngine_d.lib MyGUI.Ogre2Platform_d.lib
                         HINTS ${MYGUI_LIB_DIR}
                         PATH_SUFFIXES "" debug)

            find_library(MYGUI_PLATFORM_LIBRARIES_REL
                         NAMES MyGUI.Ogre2Platform.lib
                         HINTS ${MYGUI_LIB_DIR}
                         PATH_SUFFIXES "" release relwithdebinfo minsizerel)

            find_library(MYGUI_PLATFORM_LIBRARIES_DBG
                         NAMES MyGUI.Ogre2Platform_d.lib
                         HINTS ${MYGUI_LIB_DIR}
                         PATH_SUFFIXES "" debug)
	ENDIF (MSVC)

        IF (MINGW)
            find_library(MYGUI_LIBRARIES_REL
                         NAMES libMyGUIEngine.dll.a libMyGUI.Ogre2Platform.a
                         HINTS ${MYGUI_LIB_DIR}
                         PATH_SUFFIXES "" release relwithdebinfo minsizerel)

            find_library(MYGUI_LIBRARIES_DBG
                         NAMES libMyGUIEngine_d.dll.a libMyGUI.Ogre2Platform_d.a
                         HINTS ${MYGUI_LIB_DIR}
                         PATH_SUFFIXES "" debug)

            find_library(MYGUI_PLATFORM_LIBRARIES_REL
                         NAMES libMyGUI.Ogre2Platform.a
                         HINTS ${MYGUI_LIB_DIR}
                         PATH_SUFFIXES "" release relwithdebinfo minsizerel)

            find_library(MYGUI_PLATFORM_LIBRARIES_DBG
                         NAMES libMyGUI.Ogre2Platform_d.a
                         HINTS ${MYGUI_LIB_DIR}
                         PATH_SUFFIXES "" debug)
        ENDIF (MINGW)

        make_library_set(MYGUI_LIBRARIES)
        make_library_set(MYGUI_PLATFORM_LIBRARIES)

        MESSAGE("${MYGUI_LIBRARIES}")
        MESSAGE("${MYGUI_PLATFORM_LIBRARIES}")
    ENDIF (MYGUISDK)
    IF (OGRESOURCE)
        MESSAGE(STATUS "Using MyGUI in OGRE dependencies")
        STRING(REGEX REPLACE "[\\]" "/" OGRESDK "${OGRESOURCE}" )
        SET(MYGUI_INCLUDE_DIRS ${OGRESOURCE}/OgreMain/include/MYGUI)
        SET(MYGUI_LIB_DIR ${OGRESOURCE}/lib)
        SET(MYGUI_LIBRARIES debug Debug/MyGUIEngine_d optimized
            Release/MyGUIEngine)
    ENDIF (OGRESOURCE)
ELSE (WIN32) #Unix
    CMAKE_MINIMUM_REQUIRED(VERSION 2.4.7 FATAL_ERROR)
    FIND_PACKAGE(PkgConfig)
    IF(MYGUI_STATIC)
        IF (NOT APPLE)
            PKG_SEARCH_MODULE(MYGUI MYGUIStatic MyGUIStatic)
            IF (MYGUI_INCLUDE_DIRS)
                SET(MYGUI_INCLUDE_DIRS ${MYGUI_INCLUDE_DIRS})
                SET(MYGUI_LIB_DIR ${MYGUI_LIBDIR})
                SET(MYGUI_LIBRARIES ${MYGUI_LIBRARIES} CACHE STRING "")
            ELSE (MYGUI_INCLUDE_DIRS)
                FIND_PATH(MYGUI_INCLUDE_DIRS MyGUI.h PATHS /usr/local/include
                    /usr/include PATH_SUFFIXES MyGUI MYGUI)
        FIND_LIBRARY(MYGUI_LIBRARIES myguistatic MyGUI.Ogre2Platform PATHS
            /usr/lib /usr/local/lib)
                SET(MYGUI_LIB_DIR ${MYGUI_LIBRARIES})
                STRING(REGEX REPLACE "(.*)/.*" "\\1" MYGUI_LIB_DIR
                    "${MYGUI_LIB_DIR}")
                STRING(REGEX REPLACE ".*/" "" MYGUI_LIBRARIES
                    "${MYGUI_LIBRARIES}")
            ENDIF (MYGUI_INCLUDE_DIRS)
        ELSE (NOT APPLE)
            SET(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${MYGUI_DEPENDENCIES_DIR}
                ${OGRE_DEPENDENCIES_DIR})
            FIND_PATH(MYGUI_INCLUDE_DIRS MyGUI.h PATHS /usr/local/include
                /usr/include PATH_SUFFIXES MyGUI MYGUI)
        FIND_LIBRARY(MYGUI_LIBRARIES MyGUIEngineStatic MyGUI.Ogre2Platform PATHS
            /usr/lib /usr/local/lib)
            SET(MYGUI_LIB_DIR ${MYGUI_LIBRARIES})
            STRING(REGEX REPLACE "(.*)/.*" "\\1" MYGUI_LIB_DIR
                "${MYGUI_LIB_DIR}")
            STRING(REGEX REPLACE ".*/" "" MYGUI_LIBRARIES "${MYGUI_LIBRARIES}")
            # freetype is needed on OS X for static builds
            FIND_PACKAGE(freetype)
            SET(MYGUI_LIBRARIES ${MYGUI_LIBRARIES} ${FREETYPE_LIBRARIES})
        ENDIF (NOT APPLE)
    ELSE(MYGUI_STATIC)
        # Linux shared library
        SET(MYGUISDK $ENV{MYGUI_HOME})
        FIND_PATH(MYGUI_INCLUDE_DIRS MyGUI.h PATHS ${MYGUISDK}/include
            /usr/local/include /usr/include PATH_SUFFIXES MyGUI MYGUI)
    FIND_LIBRARY(MYGUI_LIBRARIES MyGUIEngine MyGUI.Ogre2Platform PATHS
        ${MYGUISDK}/lib /usr/lib /usr/local/lib)
        STRING(REGEX REPLACE "(.*)/.*" "\\1" MYGUI_LIB_DIR "${MYGUI_LIBRARIES}")
    FIND_LIBRARY(MYGUI_PLATFORM_LIBRARIES MyGUI.Ogre2Platform
        libMyGUI.Ogre2Platform_d.a libMyGUI.Ogre2Platform.a PATHS
        ${MYGUISDK}/lib /usr/lib /usr/local/lib)
        STRING(REGEX REPLACE "(.*)/.*" "\\1" MYGUI_LIB_DIR
            "${MYGUI_PLATFORM_LIBRARIES}")
    ENDIF(MYGUI_STATIC)
ENDIF (WIN32)

IF (MYGUI_INCLUDE_DIRS AND MYGUI_LIBRARIES)
    SET(MYGUI_FOUND TRUE)
ENDIF()

# We need explicit freetype libs only on OS X for static build
IF (NOT FREETYPE_LIBRARIES AND APPLE AND MYGUI_STATIC)
    MESSAGE(FATAL_ERROR "Freetype is requires for static build on OS X")
    SET(MYGUI_FOUND FALSE)
ENDIF()

IF (MYGUI_FOUND)
    MARK_AS_ADVANCED(MYGUI_LIB_DIR)
    IF (NOT MYGUI_FIND_QUIETLY)
        MESSAGE(STATUS " libraries : ${MYGUI_LIBRARIES}
            ${MYGUI_PLATFORM_LIBRARIES}
            from ${MYGUI_LIB_DIR}")
        MESSAGE(STATUS " includes : ${MYGUI_INCLUDE_DIRS}")
    ENDIF (NOT MYGUI_FIND_QUIETLY)
ELSE (MYGUI_FOUND)
    IF (MYGUI_FIND_REQUIRED)
        MESSAGE(FATAL_ERROR "Could not find MYGUI")
    ENDIF (MYGUI_FIND_REQUIRED)
ENDIF (MYGUI_FOUND)

CMAKE_POLICY(POP)
