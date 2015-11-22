# - Try to find almixer

# Once done this will define
#
# ALMIXER_FOUND - system has almixer
# ALMIXER_INCLUDE_DIRS - the almixer include directory
# ALMIXER_LIBRARIES - the libraries needed to use almixer
#
# $ALMIXER_HOME is an environment variable used for finding almixer.
#
# Borrowed from The Mana World
# http://themanaworld.org/
#
# Several changes and additions by Fabian 'x3n' Landau
# Lots of simplifications by Adrian Friedli
# > www.orxonox.net <

FIND_PATH(ALMIXER_INCLUDE_DIRS ALmixer.h
    PATHS
    $ENV{ALMIXER_HOME}/include
    /usr/local
    /usr
    PATH_SUFFIXES include
    )

FIND_LIBRARY(ALMIXER_LIBRARY
    NAMES ALmixer.dll.a libALmixer.dll.a libALMixer.dll.a ALMixer AlMixer ALmixer almixer almixer.lib
    PATHS
    $ENV{ALMIXER_HOME}/lib
    /usr/local
    /usr
#    PATH_SUFFIXES lib
    )

# handle the QUIETLY and REQUIRED arguments and set ALMIXER_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(ALMIXER DEFAULT_MSG ALMIXER_LIBRARY ALMIXER_INCLUDE_DIRS)

IF (ALMIXER_FOUND)
    IF(WIN32)
        SET(WINDOWS_ALMIXER_DEPENDENCIES "sdl_sound")
        SET(ALMIXER_LIBRARIES ${ALMIXER_LIBRARY})
    ELSE(WIN32)
        SET(ALMIXER_LIBRARIES ${ALMIXER_LIBRARY})
    ENDIF(WIN32)
ENDIF (ALMIXER_FOUND)

MARK_AS_ADVANCED(ALMIXER_LIBRARY ALMIXER_LIBRARIES ALMIXER_INCLUDE_DIRS)

