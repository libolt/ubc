# - Try to find Ogg and Vorbis librariesCKAGE_HANDLE_STANDARD_ARGS(OGGVORBIS DEFAULT_MSG PTHREADS_LIBRARY PTHREADS_INCLUDE_DIRS)
# Once done this will define
#
# OGGVORBIS_FOUND - system has pthreads
# OGGVORBIS_INCLUDE_DIRS - the pthreads include directory
# OGGVORBIS_LIBRARIES - the libraries needed to use pthreads
#
# $OGG_HOME is an environment variable used for finding ogg.  
# $VORBIS_HOME is an environment variable used for finding vorbis.
#
# Borrowed from The Mana World
# http://themanaworld.org/
#
# Several changes and additions by Fabian 'x3n' Landau
# Lots of simplifications by Adrian Friedli
# > www.orxonox.net <

FIND_PATH(OGG_INCLUDE_DIRS ogg/ogg.h
    PATHS
    $ENV{OGG_HOME}/include
    /usr/local
    /usr
#    PATH_SUFFIXES 
    )

FIND_PATH(VORBIS_INCLUDE_DIRS vorbis/vorbisfile.h
    PATHS
    $ENV{VORBIS_HOME}/include
    /usr/local/include
    /usr/include
#    PATH_SUFFIXES 
    )
    
IF (WIN32)
    SET (OGG_LIB_DIR $ENV{OGG_HOME}/lib)
    FIND_LIBRARY(OGG_LIBRARY_DBG
        NAMES libogg
        HINTS ${OGG_LIB_DIR}
        PATH_SUFFIXES debug 
    )
    FIND_LIBRARY(OGG_LIBRARY_REL
        NAMES libogg
        HINTS ${OGG_LIB_DIR}
        PATH_SUFFIXES release
    )
ELSE (WIN32)
    FIND_LIBRARY(OGG_LIBRARY
       NAMES libogg ogg
        PATHS
        $ENV{OGG_HOME}/lib
        /usr/local
        /usr
        PATH_SUFFIXES lib
        )
ENDIF (WIN32)
IF (WIN32)
    SET (VORBIS_LIB_DIR $ENV{VORBIS_HOME}/lib)
    FIND_LIBRARY(VORBIS_LIBRARY_DBG
        NAMES libvorbis
        HINTS ${VORBIS_LIB_DIR}
        PATH_SUFFIXES debug
    )
    FIND_LIBRARY(VORBIS_LIBRARY_REL
        NAMES libvorbis
        HINTS ${VORBIS_LIB_DIR}
        PATH_SUFFIXES release
    )
ELSE (WIN32)
    FIND_LIBRARY(VORBIS_LIBRARY
       NAMES  libvorbis vorbis
        PATHS
        $ENV{VORBIS_HOME}/lib
        /usr/local
        /usr
        PATH_SUFFIXES lib
        )
ENDIF (WIN32)
IF (WIN32)
    SET (VORBIS_LIB_DIR $ENV{VORBIS_HOME}/lib)
    FIND_LIBRARY(VORBISFILE_LIBRARY_DBG
        NAMES libvorbisfile
        HINTS ${VORBIS_LIB_DIR}
        PATH_SUFFIXES debug
    )
    FIND_LIBRARY(VORBISFILE_LIBRARY_REL
        NAMES libvorbisfile
        HINTS ${VORBIS_LIB_DIR}
        PATH_SUFFIXES release
    )
ELSE (WIN32)
    FIND_LIBRARY(VORBISFILE_LIBRARY
       NAMES libvorbisfile vorbisfile
        PATHS
        $ENV{VORBIS_HOME}/lib
        /usr/local
        /usr
        PATH_SUFFIXES lib
        )
ENDIF (WIN32)
# handle the QUIETLY and REQUIRED arguments and set PTHREADS_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
IF (WIN32)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(OGGVORBIS DEFAULT_MSG OGG_LIBRARY_DBG OGG_LIBRARY_REL  OGG_INCLUDE_DIRS VORBIS_LIBRARY_DBG VORBIS_LIBRARY_REL VORBIS_INCLUDE_DIRS VORBISFILE_LIBRARY_DBG VORBISFILE_LIBRARY_REL)
ELSE (WIN32)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(OGGVORBIS DEFAULT_MSG OGG_LIBRARY OGG_INCLUDE_DIRS VORBIS_LIBRARY VORBIS_INCLUDE_DIRS VORBISFILE_LIBRARY)
ENDIF(WIN32)
IF (OGGVORBIS_FOUND)
    IF(WIN32)
        SET(OGGVORBIS_LIBRARIES debug ${OGG_LIBRARY_DBG} ${VORBIS_LIBRARY_DBG} ${VORBISFILE_LIBRARY_DBG} optimized ${OGG_LIBRARY_REL} ${VORBIS_LIBRARY_REL} ${VORBISFILE_LIBRARY_REL})
    ELSE(WIN32)
        SET(OGGVORBIS_LIBRARIES ${OGG_LIBRARY} ${VORBIS_LIBRARY} ${VORBISFILE_LIBRARY})
    ENDIF(WIN32)
ENDIF (OGGVORBIS_FOUND)

#MARK_AS_ADVANCED(EADS_LIBRARY PTHREADS_LIBRARIES PTHREADS_INCLUDE_DIRS)


