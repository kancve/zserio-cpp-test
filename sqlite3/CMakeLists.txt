cmake_minimum_required(VERSION 3.2.0 FATAL_ERROR)
project(sqlite3)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(${PROJECT_NAME} STATIC sqlite3.c)
