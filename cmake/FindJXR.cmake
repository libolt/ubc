# - Try to find OpenJPEG2 
# Once done this will define
#
# JXR_FOUND - system has JXR
# JXR_INCLUDE_DIRS - the JXR include directory
# JXR_LIBRARIES - the libraries needed to use JXR
#
# $JXR_HOME is an environment variable used for finding JXR.
#
#

FIND_PATH(JXR_INCLUDE_DIRS jxrlib/guiddef.h
    PATHS
    $ENV{JXR_HOME}/include
    /usr/local
    /usr
    PATH_SUFFIXES include
    )

FIND_LIBRARY(JXR_LIBRARY
    NAMES jxrglue
    PATHS
    $ENV{JXR_HOME}
    /usr/local
    /usr
#    PATH_SUFFIXES lib
    )

# handle the QUIETLY and REQUIRED arguments and set JXR_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(JXR DEFAULT_MSG JXR_LIBRARY JXR_INCLUDE_DIRS)

IF (JXR_FOUND)
    IF(WIN32)
	    SET(JXR_LIBRARIES ${JXR_LIBRARY})
    ELSE(WIN32)
	    SET(JXR_LIBRARIES ${JXR_LIBRARY})
    ENDIF(WIN32)
ENDIF (JXR_FOUND)

MARK_AS_ADVANCED(JXR_LIBRARY JXR_LIBRARIES JXR_INCLUDE_DIRS)

