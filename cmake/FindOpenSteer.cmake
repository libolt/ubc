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

FIND_PATH(OpenSteer_INCLUDE_DIR OpenSteer/OpenSteer.h
    PATHS
    $ENV{OpenSteer_HOME}/include
    /usr/local
    /usr
    PATH_SUFFIXES include
    )

FIND_LIBRARY(OpenSteer_LIBRARY_DBG
<<<<<<< HEAD
    NAMES opensteer_d opensteer_debug libopensteer_debug.a libopensteer_debug libOpenSteer_d.a
=======
	NAMES opensteer_d opensteer_debug libopensteer_debug.a libopensteer_debug libopensteer_d libopensteer_d.a libOpenSteer_d libOpenSteer_d.a
>>>>>>> origin/ogre-2.0
    PATHS
    $ENV{OpenSteer_HOME}/lib
    /usr/local
    /usr
    PATH_SUFFIXES lib
    )

FIND_LIBRARY(OpenSteer_LIBRARY_REL
<<<<<<< HEAD
    NAMES opensteer libopensteer.a libopensteer libOpenSteer.a
=======
	NAMES opensteer libopensteer.a libopensteer libOpeSteer.a libOpenSteer
>>>>>>> origin/ogre-2.0
    PATHS
    $ENV{OpenSteer_HOME}/lib
    /usr/local
    /usr
    PATH_SUFFIXES lib/Release lib
    )

make_library_set(OpenSteer_LIBRARY)

# handle the QUIETLY and REQUIRED arguments and set OpenSteer_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(OpenSteer DEFAULT_MSG OpenSteer_LIBRARY OpenSteer_INCLUDE_DIR)

IF (OpenSteer_FOUND)
    MESSAGE("OpenSteer Found!")
    MESSAGE(${OpenSteer_INCLUDE_DIR})
    IF (WIN32)
        SET(OpenSteer_LIBRARIES optimized ${OpenSteer_LIBRARIES_REL} debug ${OpenSteer_LIBRARIES_DBG})
    ELSE (WIN32)
        SET (OpenSteer_LIBRARIES ${OpenSteer_LIBRARY})
    ENDIF (WIN32)
ELSE (OpenSteer_FOUND)
    MESSAGE("OpenSteer Not Found!")
ENDIF (OpenSteer_FOUND)

MARK_AS_ADVANCED(OpenSteer_LIBRARY OpenSteer_LIBRARIES OpenSteer_INCLUDE_DIRS)

