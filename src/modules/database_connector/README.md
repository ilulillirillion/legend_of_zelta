---

# Compiling

CMake: `cd <path_to_dir_with_cmakelists> && cmake . && make`
g++: `g++ database_connector.cpp -o database_connector -isysroot <path_to_sysroot> -I/usr/local/include -I<path_to_jdbc> -L<path_to_mysql-connector-c++_libs> -lmysqlcppconn -l ssl`
