# - Try to find enet
# Once done this will define
#
# ENET_FOUND - system has enet
# ENet_INCLUDE_DIRS - the enet include directory
# ENet_LIBRARIES - the libraries needed to use enet
#
# $ENET_HOME is an environment variable used for finding enet.
#
# Borrowed from The Mana World
# http://themanaworld.org/
#
# Several changes and additions by Fabian 'x3n' Landau
# Lots of simplifications by Adrian Friedli
# > www.orxonox.net <

FIND_PATH(ENet_INCLUDE_DIRS enet/enet.h
    PATHS
    $ENV{ENET_HOME}/include
    /usr/local
    /usr
    /mingw64
    /mingw32
    PATH_SUFFIXES include
    )

FIND_LIBRARY(ENet_LIBRARY_DBG
    NAMES ENet_d libENet_d.a
    PATHS
    $ENV{ENET_HOME}/lib
    /usr/local
    /usr
    /mingw64
    /mingw32
    PATH_SUFFIXES lib
    )

FIND_LIBRARY(ENet_LIBRARY_REL
    NAMES ENet libENet.a libenet.so
    PATHS
    $ENV{ENET_HOME}/lib
    /usr/local
    /usr
    PATH_SUFFIXES lib lib64
    )

# handle the QUIETLY and REQUIRED arguments and set ENET_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
#FIND_PACKAGE_HANDLE_STANDARD_ARGS(ENet DEFAULT_MSG ENet_LIBRARY ENet_INCLUDE_DIRS)

IF (WIN32)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(ENet DEFAULT_MSG ENet_LIBRARY_REL ENet_LIBRARY_DBG ENet_INCLUDE_DIRS)
ELSE (WIN32)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(ENet DEFAULT_MSG ENet_LIBRARY_REL ENet_INCLUDE_DIRS)
ENDIF (WIN32)

IF (ENET_FOUND)
    MESSAGE("ENet FOUND!")
    IF(WIN32)
        SET(WINDOWS_ENET_DEPENDENCIES "ws2_32;winmm")
        SET(ENet_LIBRARIES optimized ${ENet_LIBRARY_REL} ${WINDOWS_ENET_DEPENDENCIES} debug ${ENet_LIBRARY_DBG} ${WINDOWS_ENET_DEPENDENCIES})
    ELSE(WIN32)
        SET(ENet_LIBRARIES ${ENet_LIBRARY_REL})
    ENDIF(WIN32)
ELSE (ENET_FOUND)
    MESSAGE("ENet NOT FOUND!!")
ENDIF (ENET_FOUND)

MARK_AS_ADVANCED(ENet_LIBRARY ENet_LIBRARIES ENet_INCLUDE_DIRS)

