# - Try to find OpenSteer 
# Once done this will define
#
# OpenSteer_FOUND - system has OpenSteer
# OpenSteer_INCLUDE_DIRS - the OpenSteer include directory
# OpenSteer_LIBRARIES - the libraries needed to use OpenSteer 
#
# $OpenSteer_HOME is an environment variable used for finding OpenSteer.
#
# Borrowed from The Mana World
# http://themanaworld.org/
#
# Several changes and additions by Fabian 'x3n' Landau
# Lots of simplifications by Adrian Friedli
# > www.orxonox.net <

FIND_PATH(OpenSteer_INCLUDE_DIRS OpenSteer/OpenSteer.h
    PATHS
    $ENV{OpenSteer_HOME}/include
    /usr/local
    /usr
    PATH_SUFFIXES include
    )

FIND_LIBRARY(OpenSteer_LIBRARY_DBG
    NAMES opensteer libopensteer.a libopensteer
    PATHS
    $ENV{OpenSteer_HOME}
    /usr/local
    /usr
    PATH_SUFFIXES lib/debug
    )

FIND_LIBRARY(OpenSteer_LIBRARY_REL
    NAMES opensteer libopensteer.a libopensteer
    PATHS
    $ENV{OpenSteer_HOME}
    /usr/local
    /usr
    PATH_SUFFIXES lib/Release lib
    )

make_library_set(OpenSteer_LIBRARY)

# handle the QUIETLY and REQUIRED arguments and set OpenSteer_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(OpenSteer DEFAULT_MSG OpenSteer_LIBRARY OpenSteer_INCLUDE_DIRS)

IF (OpenSteer_FOUND)
	MESSAGE("DAH!")
    SET(OpenSteer_LIBRARIES ${OpenSteer_LIBRARY})
ENDIF (OpenSteer_FOUND)

MARK_AS_ADVANCED(OpenSteer_LIBRARY OpenSteer_LIBRARIES OpenSteer_INCLUDE_DIRS)

