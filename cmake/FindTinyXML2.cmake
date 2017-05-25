# - Try to find TinyXML2
# Once done this will define
#
# TINYXML2_FOUND - system has TinyXML2
# TinyXML2_INCLUDE_DIRS - the BtOgre include directory
# TinyXML2_LIBRARIES - the libraries needed to use TinyXML2
#
# $TINYXML2_HOME is an environment variable used for finding TinyXML2.
#
# Borrowed from The Mana World
# http://themanaworld.org/
#
# Several changes and additions by Fabian 'x3n' Landau
# Lots of simplifications by Adrian Friedli
# > www.orxonox.net <

FIND_PATH(TinyXML2_INCLUDE_DIRS tinyxml2.h
    PATHS
    $ENV{TINYXML2_HOME}
    /usr/local
    /usr
    PATH_SUFFIXES include
    )
IF (WIN32)
FIND_LIBRARY(TinyXML2_LIBRARIES_REL
    NAMES tinyxml2 libtinyxml2.a
    PATHS
    $ENV{TINYXML2_HOME}/lib/Release
    $ENV{TINYXML2_HOME}/lib
    /usr/local
    /usr
    )

FIND_LIBRARY(TinyXML2_LIBRARIES_DBG
    NAMES tinyxml2_Debug tinyxml2 libTinyXML2_d.a
    PATHS
    $ENV{TINYXML2_HOME}/lib/Debug
    $ENV{TINYXML2_HOME}/lib
    /usr/local
    /usr
    )
ELSE (WIN32)
FIND_LIBRARY(TinyXML2_LIBRARY
    NAMES TinyXML2 tinyxml2 libTinyXML2.a
    PATHS
    $ENV{TINYXML2_HOME}
    /usr/local
    /usr
    )
ENDIF (WIN32)
# handle the QUIETLY and REQUIRED arguments and set TINYXML2_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
IF (WIN32)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(TinyXML2 DEFAULT_MSG TinyXML2_LIBRARIES_REL TinyXML2_LIBRARIES_DBG TinyXML2_INCLUDE_DIRS)
ELSE (WIN32)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(TinyXML2 DEFAULT_MSG TinyXML2_LIBRARY TinyXML2_INCLUDE_DIRS)
ENDIF (WIN32)
IF (TINYXML2_FOUND)
    IF (WIN32)
        SET(TinyXML2_LIBRARIES optimized ${TinyXML2_LIBRARIES_REL} debug ${TinyXML2_LIBRARIES_DBG})
    ELSE (WIN32)
        SET (TinyXML2_LIBRARIES ${TinyXML2_LIBRARY})
    ENDIF (WIN32)
ELSE (TINYXML2_FOUND)
    MESSAGE("TinyXML2 Not Found!")
ENDIF (TINYXML2_FOUND)

MARK_AS_ADVANCED(TinyXML2_LIBRARY TinyXML2_LIBRARIES TinyXML2_INCLUDE_DIRS)

