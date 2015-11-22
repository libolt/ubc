# - Try to find enet
# Once done this will define
#
# OGREOGGSOUND_FOUND - system has enet
# OgreOggSound_INCLUDE_DIRS - the enet include directory
# OgreOggSound_LIBRARIES - the libraries needed to use enet
#
# $OGREOGGSOUND_HOME is an environment variable used for finding enet.
#
# Borrowed from The Mana World
# http://themanaworld.org/
#
# Several changes and additions by Fabian 'x3n' Landau
# Lots of simplifications by Adrian Friedli
# > www.orxonox.net <

FIND_PATH(OgreOggSound_INCLUDE_DIRS OgreOggSound.h
    PATHS
    $ENV{OGREOGGSOUND_HOME}/include
    /usr/local
    /usr
    PATH_SUFFIXES include OgreOggSound
    )

FIND_LIBRARY(OgreOggSound_LIBRARY
	NAMES libogreoggsound.dll.a ogreoggsound libOgreOggSound.so
    PATHS
    $ENV{OGREOGGSOUND_HOME}
    /usr/local
    /usr
#    c:/mingw/msys/1.0
    PATH_SUFFIXES lib
    )

# handle the QUIETLY and REQUIRED arguments and set ENET_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(OgreOggSound DEFAULT_MSG OgreOggSound_LIBRARY OgreOggSound_INCLUDE_DIRS)

IF (OGREOGGSOUND_FOUND)
    SET(OgreOggSound_LIBRARIES ${OgreOggSound_LIBRARY})
ENDIF (OGREOGGSOUND_FOUND)

MARK_AS_ADVANCED(OgreOggSound_LIBRARY OgreOggSound_LIBRARIES OgreOggSound_INCLUDE_DIRS)

