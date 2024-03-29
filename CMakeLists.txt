cmake_minimum_required(VERSION 3.10)
PROJECT (UBC)
SET(CMAKE_MODULE_PATH "${UBC_SOURCE_DIR}/cmake")
#set(Boost_USE_MULTITHREADED ON)

IF (WIN32)
    IF(MSVC)
        # Deactivate warning C4251
        SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4251 /wd4275" )
    ENDIF()
ENDIF (WIN32)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Debug' as none was specified.")
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif()

find_package (ENet)
#find_package (FreeImage)
find_package (OGRE COMPONENTS HlmsPbs HlmsUnlit Overlay)
find_package (SDL2)
#find_package (SDL_Mixer)
#find_package (MyGUI)
#find_package (Bulletlibs)
#find_package (BtOgre21)
find_package (TinyXML2)
find_package (OpenSteer)
find_package (OpenAL)
#INCLUDE (FindOggVorbis)
#find_package (ALMixer)
#find_package(Boost COMPONENTS chrono date_time program_options filesystem
#    system thread REQUIRED)
find_package(Threads REQUIRED)
#find_package(OGRE COMPONENTS Bites RTShaderSystem)
#if (UNIX)
#    find_package (TIFF)
#    find_package (OpenJPEG2)
#    find_package (WebP)
#    find_package (OpenEXR)
#    find_package (LibRaw)
#    find_package (JXR)
#endif (UNIX)
SET (UBC_DEPENDENCIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dependencies)
SET (UBC_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
SET (UBC_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
SET (UBC_DATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/data)


FILE(GLOB_RECURSE UBC_HEADERS include/*.h)
FILE(GLOB_RECURSE ENGINE_SRCS src/engine/*.cpp)
FILE(GLOB_RECURSE UBC_SRCS src/game/*.cpp)
FILE(GLOB_RECURSE UBC_SRCS2 src/game/*.cc)

ADD_SUBDIRECTORY (include)

IF (WIN32)
    SET(OGRE_HLMSCOMMON_DIR $ENV{OGRE_HOME}\\include\\OGRE\\Hlms\\Common)
ELSE ()
    SET(OGRE_HLMSCOMMON_DIR $ENV{OGRE_HOME}/include/OGRE/Hlms/Common)
ENDIF (WIN32)

INCLUDE_DIRECTORIES(${UBC_INCLUDE_DIR} ${ENet_INCLUDE_DIRS}
    ${FreeImage_INCLUDE_DIR} ${BtOgre21_INCLUDE_DIR} ${BULLET_INCLUDE_DIRS}
    ${MYGUI_INCLUDE_DIRS} ${OGRE_INCLUDE_DIRS} ${OGRE_HlmsPbs_INCLUDE_DIRS}
    ${OGRE_HlmsUnlit_INCLUDE_DIRS} ${OGRE_HLMSCOMMON_DIR}
    ${OGRE_RTShaderSystem_INCLUDE_DIRS} ${SDL2_INCLUDE_DIR}
    ${SDL_Mixer_INCLUDE_DIRS} ${TinyXML2_INCLUDE_DIRS} ${OpenSteer_INCLUDE_DIR})

LINK_DIRECTORIES(${ENET_LIBDIR} ${OGRE_LIBRARY_DIRS}
    ${OGRE_HlmsPbs_LIBRARY_DIRS} ${OGRE_DEPENDLIBDIR} ${TinyXML2_LIB_DIRS}
    ${OpenSteer_LIBRARY_DIRS})

IF (CMAKE_BUILD_TYPE MATCHES "Debug")
    SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/debug")
ELSEIF (CMAKE_BUILD_TYPE MATCHES "Release")
    SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/release")
ELSEIF (CMAKE_BUILD_TYPE MATCHES "RelWithDebInfo")
    SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/relwithdebinfo")
ENDIF (CMAKE_BUILD_TYPE MATCHES "Debug")

IF (WIN32)
    ADD_EXECUTABLE(ubc WIN32 ${ENGINE_SRCS} ${UBC_SRCS} ${UBC_SRCS2}
        ${UBC_HEADERS})
    TARGET_LINK_LIBRARIES(ubc ${ENet_LIBRARIES} ${TinyXML2_LIBRARIES}
        ${OpenSteer_LIBRARY} ${SDL2_LIBRARY} ${FreeImage_LIBRARY}
        ${BtOgre21_LIBRARIES} ${BULLET_LIBRARIES} ${MYGUI_PLATFORM_LIBRARIES}
        ${MYGUI_LIBRARIES} ${OGRE_LIBRARIES} ${OGRE_HlmsPbs_LIBRARIES}
        ${OGRE_HlmsUnlit_LIBRARIES} ${OGRE_RTShaderSystem_LIBRARIES}  version.lib
        imm32.lib)

ELSEIF (APPLE)
    INCLUDE_DIRECTORIES (../include ../src/tinyxml ../Dependencies/include)
    LINK_DIRECTORIES(../src/tinyxml ../Dependencies/lib/Debug)
    FIND_LIBRARY(OGRE_LIB Ogre)
    MARK_AS_ADVANCED(OGRE_LIB)
    FIND_LIBRARY(CG_LIB Cg)
    MARK_AS_ADVANCED(CG_LIB)
    FIND_LIBRARY(CARBON_LIB Carbon)
    MARK_AS_ADVANCED(CARBON_LIB)
    ADD_EXECUTABLE (ubc ${UBC_SRCS})
    TARGET_LINK_LIBRARIES( ubc tinyxml ${OGRE_LIB} ${CG_LIB} ${CARBON_LIB})
ELSE (APPLE)
    ADD_CUSTOM_COMMAND(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/config.h
        COMMAND ${CMAKE_COMMAND} -E  echo ${OGRE_PLUGINDIR} >>
        ${CMAKE_CURRENT_SOURCE_DIR}/src/config.h
    )
    ADD_EXECUTABLE(ubc ${ENGINE_SRCS} ${UBC_SRCS} ${UBC_SRCS2} ${UBC_HEADERS})
    TARGET_LINK_LIBRARIES(ubc ${ENet_LIBRARIES} ${TinyXML2_LIBRARIES}
        ${OpenSteer_LIBRARY} ${BtOgre21_LIBRARIES} ${BULLET_LIBRARIES}
        ${SDL2_LIBRARY} ${FreeImage_LIBRARY} ${MYGUI_PLATFORM_LIBRARIES}
        ${MYGUI_LIBRARIES} ${OGRE_LIBRARIES} ${OGRE_HlmsPbs_LIBRARIES}
        ${OGRE_HlmsUnlit_LIBRARIES} ${OGRE_RTShaderSystem_LIBRARIES}
        ${OPENAL_LIBRARY} ${ALMIXER_LIBRARY})
ENDIF (WIN32)
