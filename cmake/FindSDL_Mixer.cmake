# - Try to find SDL_Mixer
# Once done this will define
#
# SDL_Mixer_FOUND - system has SDL_Mixer
# SDL_Mixer_INCLUDE_DIRS - the SDL_Mixer include directory
# TinyXML2_LIBRARIES - the libraries needed to use SDL_Mixer
#
# $SDL_Mixer_HOME is an environment variable used for finding SDL_Mixer.
#
# Borrowed from The Mana World
# http://themanaworld.org/
#
# Several changes and additions by Fabian 'x3n' Landau
# Lots of simplifications by Adrian Friedli
# > www.orxonox.net <

FIND_PATH(SDL_Mixer_INCLUDE_DIRS SDL_mixer.h
    PATHS
    $ENV{SDL_Mixer_HOME}
    /usr/local
    /usr
    PATH_SUFFIXES include include/SDL2
    )
IF (WIN32)
FIND_LIBRARY(SDL_Mixer_LIBRARIES_REL
    NAMES sdl2_mixer libSDL2_mixer.a
    PATHS
    $ENV{SDL_Mixer_HOME}/lib/Release
    $ENV{SDL_Mixer_HOME}/lib
    /usr/local
    /usr
    )

FIND_LIBRARY(SDL_Mixer_LIBRARIES_DBG
    NAMES sdl2_mixer_Debug sdl2_mixer libsdl2_mixer.a
    PATHS
    $ENV{SDL_Mixer_HOME}/lib/Debug
    $ENV{SDL_Mixer_HOME}/lib
    /usr/local
    /usr
    )
ELSE (WIN32)
FIND_LIBRARY(SDL_Mixer_LIBRARY
    NAMES SDL2_mixer sdl2_mixer libSDL2_mixer.a
    PATHS
    $ENV{SDL_Mixer_HOME}
    /usr/local
    /usr
    )
ENDIF (WIN32)
# handle the QUIETLY and REQUIRED arguments and set SDL_Mixer_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
IF (WIN32)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL_Mixer DEFAULT_MSG SDL_Mixer_LIBRARIES_REL SDL_Mixer_LIBRARIES_DBG SDL_Mixer_INCLUDE_DIRS)
ELSE (WIN32)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL_Mixer DEFAULT_MSG SDL_Mixer_LIBRARY SDL_Mixer_INCLUDE_DIRS)
ENDIF (WIN32)
IF (SDL_Mixer_FOUND)
    IF (WIN32)
        SET(SDL_Mixer_LIBRARIES optimized ${SDL_Mixer_LIBRARIES_REL} debug ${SDL_Mixer_LIBRARIES_DBG})
    ELSE (WIN32)
        SET (SDL_Mixer_LIBRARIES ${SDL_Mixer_LIBRARY})
    ENDIF (WIN32)
ELSE (SDL_Mixer_FOUND)
    MESSAGE("SDL_Mixer Not Found!")
ENDIF (SDL_Mixer_FOUND)

MARK_AS_ADVANCED(SDL_Mixer_LIBRARY SDL_Mixer_LIBRARIES SDL_Mixer_INCLUDE_DIRS)

