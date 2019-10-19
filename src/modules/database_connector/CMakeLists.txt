if(COMMAND cmake_policy)
  cmake_policy(SET CMP0023 NEW)
  cmake_policy(SET CMP0003 NEW) # Because linker searches custom paths
endif(COMMAND cmake_policy)

#set(CMAKE_INSTALL_NAME_DIR "/Users/justinheil/repositories/firelink/games/legend_of_zelta/src/modules/database_connector/mysql-connector-c++-8.0.18-macos10.14-x86-64bit/lib64" )
#set(CMAKE_INSTALL_NAME_DIR "/Users/justinheil/repositories/firelink/games/legend_of_zelta/src/modules/database_connector" )

#IF(APPLE)
#  SET(CMAKE_INSTALL_NAME_DIR @executable_path)
#  SET(CMAKE_BUILD_WITH_INSTALL_RPATH ON)
#ENDIF(APPLE)

# Project name
project( database_connector )


# Specify a minimum version of cmake required for building
cmake_minimum_required( VERSION 2.4 )

#[[ 
Define build targets and source files
  database_connector
]]
add_executable( database_connector ./database_connector.cpp )

#set(CMAKE_MACOSX_RPATH ON)
#set_target_properties( database_connector PROPERTIES INSTALL_RPATH
#  "/usr/local/mysql-connector-c++-8.0.18/lib64" )


# NO LONGER REQUIRED: https://gitlab.kitware.com/cmake/cmake/issues/19120
# Set sysroot (required for building on macos)
#set( CMAKE_SYSROOT /Library/Developer/CommandLineTools/SDKs/MacOSX10.14.sdk)

#[[ 
Add include files:
  mysql-connector-c++
    boost (/usr/local/include)
]]
#target_include_directories( database_connector PRIVATE /usr/local/include ${PROJECT_SOURCE_DIR}/mysql-connector-c++-8.0.18-macos10.14-x86-64bit/include/jdbc )
target_include_directories( database_connector PRIVATE /usr/local/mysql-connector-c++-8.0.18/include/jdbc/ )


# Locate mysqlcppconn
find_library(MYSQLCPPCONN NAMES "mysqlcppconn"
  PATHS /usr/local/mysql-connector-c++-8.0.18/lib64 NO_DEFAULT_PATH )
if( NOT MYSQLCPPCONN )
  message( FATAL_ERROR "mysqlcppconn library not found")
endif()

# Locate ssl
find_library(SSL NAMES "ssl"
  PATHS /usr/local/mysql-connector-c++-8.0.18/lib64 NO_DEFAULT_PATH )
if( NOT SSL )
  message( FATAL_ERROR "ssl library not found")
endif()

#if ( MYSQLCPPCONN AND SSL )
message( STATUS "mysqlcppconn: ${MYSQLCPPCONN}" )
message( STATUS "ssl: ${SSL}" )
target_link_libraries( database_connector ${MYSQLCPPCONN} ${SSL} )
