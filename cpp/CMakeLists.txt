cmake_minimum_required(VERSION 3.2.0 FATAL_ERROR)
project(sql_databases)

if(WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
endif()

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/sqlite3
)

file (GLOB_RECURSE SOURCES_NDSLIVE "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_library(${PROJECT_NAME} STATIC ${SOURCES_NDSLIVE})

# set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO CXX_VISIBILITY_PRESET hidden)
target_link_libraries(${PROJECT_NAME} ZserioCppRuntime sqlite3)
