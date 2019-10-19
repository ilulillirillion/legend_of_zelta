---

# Compiling

CMake: `cd <path_to_dir_with_cmakelists> && cmake . && make`
g++: `g++ database_connector.cpp -o database_connector -isysroot <path_to_sysroot> -I/usr/local/include -I<path_to_jdbc> -L<path_to_mysql-connector-c++_libs> -lmysqlcppconn -l ssl`

I've spent a lot of hours on trying to make sure the dynamic libraries available here link correctly but it's either not possible or I'm lacking some sort of understanding. The best solution I've come up with to avoid runtime errors finding dylibs on macos is to append the mysqlconnection libraries to the default dynamic library search path via `export DYLD_LIBRARY_PATH="${DYLD_LIBRARY_PATH}:/usr/local/mysql-connector-c++-8.0.18/lib64"`. For an actual release I would need to find some way to bundle this better, which might just boil down to a static linking solution.
