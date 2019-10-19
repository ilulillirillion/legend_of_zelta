if(COMMAND cmake_policy)
  cmake_policy(SET CMP0023 NEW)
  cmake_policy(SET CMP0003 NEW) # Because linker searches custom paths
endif(COMMAND cmake_policy)

# Project name
project( database_connector )

# Specify a minimum version of cmake required for building
cmake_minimum_required( VERSION 2.4 )

#[[ 
Define build targets and source files
  database_connector
]]
add_executable( database_connector ./database_connector.cpp )

#set_property( database_connector PROPERTY ENVIRONMENT "DYLD_LIBRARY_PATH=/Users/justinheil/repositories/firelink/games/legend_of_zelta/src/tests/mysql_connection_test/mysql-connector-c++-8.0.18-macos10.14-x86-64bit/lib64" )

#set( ENV{DYLD_LIBRARY_PATH} /Users/justinheil/repositories/firelink/games/legend_of_zelta/src/tests/mysql_connection_test/mysql-connector-c++-8.0.18-macos10.14-x86-64bit/lib64 )

# Set sysroot (required for building on macos)
set( CMAKE_SYSROOT /Library/Developer/CommandLineTools/SDKs/MacOSX10.14.sdk)

#[[ 
Add include files:
  mysql-connector-c++
    boost (/usr/local/include)
]]
target_include_directories( database_connector PRIVATE /usr/local/include ${PROJECT_SOURCE_DIR}/mysql-connector-c++-8.0.18-macos10.14-x86-64bit/include/jdbc )
#target_include_directories( database_connector PRIVATE /usr/local/include ./mysql-connector-c++-8.0.18-macos10.14-x86-64bit/include/jdbc )

# Locate mysqlcppconn
find_library(MYSQLCPPCONN NAMES "mysqlcppconn"
  PATHS ${PROJECT_SOURCE_DIR}/mysql-connector-c++-8.0.18-macos10.14-x86-64bit/lib64 NO_DEFAULT_PATH )
if( NOT MYSQLCPPCONN )
  message( FATAL_ERROR "mysqlcppconn library not found")
endif()

# Locate ssl
find_library(SSL NAMES "ssl"
  PATHS ${PROJECT_SOURCE_DIR}/mysql-connector-c++-8.0.18-macos10.14-x86-64bit/lib64 NO_DEFAULT_PATH )
if( NOT SSL )
  message( FATAL_ERROR "ssl library not found")
endif()

#if ( MYSQLCPPCONN AND SSL )
message( STATUS ${MYSQLCPPCONN} )
message( STATUS ${SSL} )
target_link_libraries( database_connector PRIVATE ${MYSQLCPPCONN} ${SSL} )
#else()
#  message( FATAL_ERROR "missing library!" )
#endif()

#[[
Extend library search path:
  mysql-connector-c++
]]
#set( CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} ./mysql-connector-c++-8.0.18-macos10.14-x86-64bit/lib64 )

#set( mysqlcppconn ${MYSQLCPPCONN} )

#[[
Link external libraries:
  mysql-connector-c++
  ssl
]]
#target_link_libraries( database_connector PRIVATE mysqlcppconn ssl )
#target_link_libraries( TARGET database_connector PRIVATE mysqlcppconn ssl )
#target_link_libraries( database_connector PUBLIC mysqlcppconn ssl )
