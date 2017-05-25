# - Try to find BtOgre
# Once done this will define
#
# BTOGRE_FOUND - system has BtOgre
# BtOgre_INCLUDE_DIRS - the BtOgre include directory
# BtOgre_LIBRARIES - the libraries needed to use BtOgre
#
# $BTOGRE_HOME is an environment variable used for finding BtOgre.
#
# Borrowed from The Mana World
# http://themanaworld.org/
#
# Several changes and additions by Fabian 'x3n' Landau
# Lots of simplifications by Adrian Friedli
# > www.orxonox.net <

FIND_PATH(BtOgre_INCLUDE_DIRS BtOgreGP.h
    PATHS
    $ENV{BTOGRE_HOME}/include
    /usr/local
    /usr
    PATH_SUFFIXES include
    )
IF (WIN32)
FIND_LIBRARY(BtOgre_LIBRARIES_REL
    NAMES BtOgre libBtOgre.a
    PATHS
    $ENV{BTOGRE_HOME}/lib
    /usr/local
    /usr
    )

FIND_LIBRARY(BtOgre_LIBRARIES_DBG
	NAMES BtOgre_Debug BtOgre_D BtOgre_d libBtOgre_d.a
    PATHS
    $ENV{BTOGRE_HOME}/lib
    /usr/local
    /usr
    )
ELSE (WIN32)
    FIND_LIBRARY(BtOgre_LIBRARY
    NAMES BtOgre libBtOgre.a
	PATHS
	$ENV{BTOGRE_HOME}
        /usr/local
	/usr
        )
ENDIF (WIN32)
# handle the QUIETLY and REQUIRED arguments and set BtOgre_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
IF (WIN32)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(BtOgre DEFAULT_MSG BtOgre_LIBRARIES_REL BtOgre_LIBRARIES_DBG BtOgre_INCLUDE_DIRS)
ELSE (WIN32)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(BtOgre DEFAULT_MSG BtOgre_LIBRARY BtOgre_INCLUDE_DIRS)
ENDIF (WIN32)
IF (BTOGRE_FOUND)
    IF (WIN32)
        SET(BtOgre_LIBRARIES optimized ${BtOgre_LIBRARIES_REL} debug ${BtOgre_LIBRARIES_DBG})
    ELSE (WIN32)
	    SET (BtOgre_LIBRARIES ${BtOgre_LIBRARY})
    ENDIF (WIN32)
ELSE (BTOGRE_FOUND)
    MESSAGE("BtOgre Not Found!")
ENDIF (BTOGRE_FOUND)

MARK_AS_ADVANCED(BtOgre_LIBRARY BtOgre_LIBRARIES BtOgre_INCLUDE_DIRS)

