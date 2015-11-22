# - Try to find enet
# Once done this will define
#
# TINYXML_FOUND - system has enet
# TinyXML_INCLUDE_DIRS - the BtOgre include directory
# TinyXML_LIBRARIES - the libraries needed to use enet
#
# $BTOGRE_HOME is an environment variable used for finding enet.
#
# Borrowed from The Mana World
# http://themanaworld.org/
#
# Several changes and additions by Fabian 'x3n' Landau
# Lots of simplifications by Adrian Friedli
# > www.orxonox.net <

FIND_PATH(TinyXML_INCLUDE_DIRS tinyxml.h
    PATHS
    $ENV{TINYXML_HOME}
    /usr/local
    /usr
    PATH_SUFFIXES include
    )
IF (WIN32)
FIND_LIBRARY(TinyXML_LIBRARIES_REL
    NAMES tinyxml libtinyxml.a
    PATHS
    $ENV{TINYXML_HOME}/lib/Release
    /usr/local
    /usr
    )

FIND_LIBRARY(TinyXML_LIBRARIES_DBG
    NAMES tinyxml_Debug tinyxml libTinyXML_d.a
    PATHS
    $ENV{TINYXML_HOME}/lib/Debug
    /usr/local
    /usr
    )
ELSE (WIN32)
FIND_LIBRARY(TinyXML_LIBRARY
    NAMES TinyXML tinyxml libTinyXML.a
    PATHS
    $ENV{TINYXML_HOME}
    /usr/local
    /usr
    )
ENDIF (WIN32)
# handle the QUIETLY and REQUIRED arguments and set ENET_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
IF (WIN32)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(TinyXML DEFAULT_MSG TinyXML_LIBRARIES_REL TinyXML_LIBRARIES_DBG TinyXML_INCLUDE_DIRS)
ELSE (WIN32)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(TinyXML DEFAULT_MSG TinyXML_LIBRARY TinyXML_INCLUDE_DIRS)
ENDIF (WIN32)
IF (TINYXML_FOUND)
    IF (WIN32)
        SET(TinyXML_LIBRARIES optimized ${TinyXML_LIBRARIES_REL} debug ${TinyXML_LIBRARIES_DBG})
    ELSE (WIN32)
        SET (TinyXML_LIBRARIES ${TinyXML_LIBRARY})
    ENDIF (WIN32)
ELSE (TINYXML_FOUND)
    MESSAGE("TinyXML Not Found!")
ENDIF (TINYXML_FOUND)

MARK_AS_ADVANCED(TinyXML_LIBRARY TinyXML_LIBRARIES TinyXML_INCLUDE_DIRS)

