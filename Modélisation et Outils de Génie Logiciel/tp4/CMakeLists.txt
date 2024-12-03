cmake_minimum_required(VERSION 3.22.1)

project(sqliteapp)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/SQLiteCpp)

add_executable(main src/server.cpp)

target_link_libraries(main
  SQLiteCpp
  sqlite3
  pthread
  dl
  ssl
  crypto
  )