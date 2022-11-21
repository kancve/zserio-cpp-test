cmake_minimum_required(VERSION 3.2.0 FATAL_ERROR)

project(app)

include_directories(
    ${CMAKE_SOURCE_DIR}/cpp
    ${CMAKE_SOURCE_DIR}/runtime
    ${CMAKE_SOURCE_DIR}/sqlite3
)

# exe
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ZserioCppRuntime sqlite3 sql_databases)

# install
install(TARGETS ${PROJECT_NAME} DESTINATION bin)