if(CMAKE_CURRENT_BINARY_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    message(FATAL_ERROR "The binaries directory and sources directory must be \
    different, try run:
    cmake -S <source-dir> -B <binary-dir>")
endif()

cmake_minimum_required(VERSION 3.12.0)

project(opengl
    LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Change the output directory of some binary files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/target/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/target/libs")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/target/libs")

# Build options
option(USE_SYSTEM_GLFW "Enable the use of system installed GLFW." ON)

# Include directories
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

# List source files
file(GLOB SOURCES_FILES "src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES_FILES})

# Custom run target
add_custom_target(run
    COMMAND
        $<TARGET_FILE_NAME:${PROJECT_NAME}>
    COMMENT
        "Building and running the executable ${PROJECT_NAME}..."
    DEPENDS
        ${PROJECT_NAME}
    WORKING_DIRECTORY
        ${CMAKE_CURRENT_SOURCE_DIR})

# GLFW dependecy
if(USE_SYSTEM_GLFW STREQUAL "ON")
    find_package(glfw3 REQUIRED)
endif()

if(glfw3_FOUND)
    target_link_libraries(${PROJECT_NAME} glfw)
endif()

if(NOT glfw3_FOUND AND USE_SYSTEM_GLFW STREQUAL "OFF")
    message(FATAL_ERROR "Bundle GLFW isn't supported yet.")
endif()

