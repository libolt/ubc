# - Try to find pthreads
# Once done this will define
#
# PTHREADS_FOUND - system has pthreads
# PTHREADS_INCLUDE_DIRS - the pthreads include directory
# PTHREADS_LIBRARIES - the libraries needed to use pthreads
#
# $PTHREADS_HOME is an environment variable used for finding pthreads.
#
# Borrowed from The Mana World
# http://themanaworld.org/
#
# Several changes and additions by Fabian 'x3n' Landau
# Lots of simplifications by Adrian Friedli
# > www.orxonox.net <

FIND_PATH(PTHREADS_INCLUDE_DIRS pthread.h
    PATHS
    $ENV{PTHREADS_HOME}/include
    /usr/local
    /usr
    PATH_SUFFIXES include
    )

IF (WIN32)
    FIND_LIBRARY(PTHREADVCE2_LIBRARY
        NAMES PTHREADVCE2
        PATHS
            $ENV{PTHREADS_HOME}/lib
            /usr/local
            /usr
    )
    FIND_LIBRARY(PTHREADVC2_LIBRARY
        NAMES PTHREADVC2
        PATHS
            $ENV{PTHREADS_HOME}/lib
            /usr/local
            /usr
    )
    FIND_LIBRARY(PTHREADVSE2_LIBRARY
        NAMES PTHREADVSE2
        PATHS
            $ENV{PTHREADS_HOME}/lib
            /usr/local
            /usr
    )
ELSE (WIN32)
    FIND_LIBRARY(PTHREADS_LIBRARY
       NAMES pthreads 
        PATHS
        $ENV{PTHREADS_HOME}/lib
        /usr/local
        /usr
#    PATH_SUFFIXES lib
        )
ENDIF (WIN32)
# handle the QUIETLY and REQUIRED arguments and set PTHREADS_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(PTHREADS DEFAULT_MSG PTHREADVC2_LIBRARY PTHREADVSE2_LIBRARY PTHREADVCE2_LIBRARY PTHREADS_INCLUDE_DIRS)

IF (PTHREADS_FOUND)
    IF(WIN32)
        SET(PTHREADS_LIBRARIES ${PTHREADVCE2_LIBRARY} ${PTHREADVC2_LIBRARY} ${PTHREADVSE2_LIBRARY})
    ELSE(WIN32)
        SET(PTHREADS_LIBRARIES ${PTHREADS_LIBRARY})
    ENDIF(WIN32)
ENDIF (PTHREADS_FOUND)

MARK_AS_ADVANCED(PTHREADS_LIBRARY PTHREADS_LIBRARIES PTHREADS_INCLUDE_DIRS)


