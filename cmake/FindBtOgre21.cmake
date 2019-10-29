# - Try to find BtOgre21

#set(BtOgre21_ROOT "notSet" CACHE PATH "Where your BtOgre21 instlallation is")

find_path(BtOgre21_INCLUDE_DIR BtOgre.hpp HINTS $ENV{BTOGRE_HOME}/include
          PATH_SUFFIXES BtOgre21)
message("BTOGRE_HOME == " $ENV{BTOGRE_HOME})
find_library(BtOgre21_LIBRARY libBtOgre21.a BtOgre21.lib libBtOgre21 BtOgre21
             HINTS $ENV{BTOGRE_HOME}/lib PATH_SUFFIXES BtOgre21 BtOgre lib)
find_library(BtOgre21_DEBUG_LIBRARY libBtOgre21_d.a BtOgre21_d.lib libBtOgre21_d
             BtOgre21_d HINTS $ENV{BTOGRE_HOME}/lib PATH_SUFFIXES BtOgre21
             BtOgre lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(BtOgre21 DEFAULT_MSG BtOgre21_LIBRARY
                                  BtOgre21_INCLUDE_DIR)

mark_as_advanced(BtOgre21_INCLUDE_DIR BtOgre21_LIBRARY BtOgre21_DEBUG_LIBRARY)

set(BtOgre21_INCLUDE_DIRS ${BtOgre21_INCLUDE_DIR})
set(BtOgre21_LIBRARIES optimized ${BtOgre21_LIBRARY} debug
    ${BtOgre21_DEBUG_LIBRARY})

