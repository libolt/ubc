# - Try to find Bullet
# Once done this will define
#
# BULLLET_FOUND - system has Bullet
# BULLET_INCLUDE_DIRS - the Bullet include directory
# BULLET_LIBRARIES - the libraries needed to use Bullet
#
# $BULLET_HOME is an environment variable used for finding Bullet.
#
# Borrowed from The Mana World
# http://themanaworld.org/
#
# Several changes and additions by Fabian 'x3n' Landau
# Lots of simplifications by Adrian Friedli
# > www.orxonox.net <

FIND_PATH(BULLET_INCLUDE_DIRS btBulletCollisionCommon.h
    PATHS
    $ENV{BULLET_HOME}/include
    $ENV{BULLET_ROOT}/src
    /opt/include
    /usr/local/include
    /usr/local
    /usr/include
    /usr
    PATH_SUFFIXES bullet include/bullet
    )

FIND_LIBRARY(BULLETDYNAMICS_LIBRARY_REL
	NAMES libBulletDynamics.a BulletDynamics
    PATHS
    $ENV{BULLET_HOME}
    $ENV{BULLET_ROOT}
    /usr/local
    /usr
    PATH_SUFFIXES lib
    )
FIND_LIBRARY(BULLETDYNAMICS_LIBRARY_DBG
	NAMES libBulletDynamics_d.a BulletDynamics_debug
    PATHS
    $ENV{BULLET_HOME}
    $ENV{BULLET_ROOT}
    /usr/local
    /usr
    PATH_SUFFIXES lib
    )

FIND_LIBRARY(BULLETCOLLISION_LIBRARY_REL
	NAMES libBulletCollision.a BulletCollision
    PATHS
    $ENV{BULLET_HOME}
    $ENV{BULLET_ROOT}
    /usr/local
    /usr
    PATH_SUFFIXES lib
    )
FIND_LIBRARY(BULLETCOLLISION_LIBRARY_DBG
	NAMES libBulletCollision_d.a BulletCollision_debug
    PATHS
    $ENV{BULLET_HOME}
    $ENV{BULLET_ROOT}
    /usr/local
    /usr
    PATH_SUFFIXES lib
   ) 
FIND_LIBRARY(BULLETLINEARMATH_LIBRARY_REL
	NAMES libLinearMath.a LinearMath
    PATHS
    $ENV{BULLET_HOME}
    $ENV{BULLET_ROOT}
    /usr/local
    /usr
    PATH_SUFFIXES lib
    )
FIND_LIBRARY(BULLETLINEARMATH_LIBRARY_DBG
	NAMES libLinearMath_d.a LinearMath_debug
    PATHS
    $ENV{BULLET_HOME}
    $ENV{BULLET_ROOT}
    /usr/local
    /usr
    PATH_SUFFIXES lib
    )

 make_library_set(BULLETDYNAMICS_LIBRARY)
 make_library_set(BULLETCOLLISION_LIBRARY)
 make_library_set(BULLETLINEARMATH_LIBRARY)

# handle the QUIETLY and REQUIRED arguments and set Bullet_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(BulletDynamics DEFAULT_MSG BULLETDYNAMICS_LIBRARY BULLET_INCLUDE_DIRS)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(BulletCollision DEFAULT_MSG BULLETCOLLISION_LIBRARY BULLET_INCLUDE_DIRS)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(LinearMath DEFAULT_MSG BULLETLINEARMATH_LIBRARY BULLET_INCLUDE_DIRS)

IF (BULLETDYNAMICS_FOUND)
    IF (BULLETCOLLISION_FOUND)
        IF (LINEARMATH_FOUND) 
            SET(BULLET_LIBRARIES ${BULLETDYNAMICS_LIBRARY} ${BULLETCOLLISION_LIBRARY} ${BULLETLINEARMATH_LIBRARY})
        ENDIF (LINEARMATH_FOUND)
    ENDIF (BULLETCOLLISION_FOUND)
ENDIF (BULLETDYNAMICS_FOUND)

MARK_AS_ADVANCED(BULLETDYNAMICS_LIBRARY BULLETCOLLISION_LIBRARY BULLETLINEARMATH_LIBRARY BULLET_LIBRARIES BULLET_INCLUDE_DIRS)

