cmake_minimum_required(VERSION 3.10)
project(http_sqlite_server)

set(CMAKE_CXX_STANDARD 17)

# Ajout des bibliothèques
find_package(SQLiteCpp REQUIRED)
find_package(SQLite3 REQUIRED)

add_executable(server main.cpp)

target_include_directories(server PRIVATE ${SQLiteCpp_INCLUDE_DIRS})
target_link_libraries(server PRIVATE SQLiteCpp::SQLiteCpp sqlite3)
