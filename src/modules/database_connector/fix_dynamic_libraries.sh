#!/usr/bin/env bash

#install_name_tool -change libssl.1.1.dylib ./mysql-connector-c++-8.0.18-macos10.14-x86-64bit/lib64/libssl.1.1.dylib database_connector && echo "Done!";

echo "Make sure to run this from the same directory as the build artifact."

install_name_tool -change @rpath/libmysqlcppconn.7.dylib /usr/local/mysql-connector-c++-8.0.18/lib64/libmysqlcppconn.7.dylib database_connector && echo "Set mysqlcppconn connection" && install_name_tool -change libssl.1.1.dylib /usr/local/mysql-connector-c++-8.0.18/lib64/libssl.1.1.dylib database_connector && echo "Set mysqlcppcon/ssl connection" 

#&& install_name_tool -change libcrypto.1.1.dylib ./mysql-connector-c++-8.0.18-macos10.14-x86-64bit/lib64/libcrypto.1.1.dylib ./mysql-connector-c++-8.0.18-macos10.14-x86-64bit/lib64/libmysqlcppconn.7.dylib && echo "Set mysqlcppcon/crypto connection" && install_name_tool -change libcrypto.1.1.dylib ./mysql-connector-c++-8.0.18-macos10.14-x86-64bit/lib64/libcrypto.1.1.dylib ./mysql-connector-c++-8.0.18-macos10.14-x86-64bit/lib64/libssl.1.1.dylib && echo "Set ssl/crypto connection";
