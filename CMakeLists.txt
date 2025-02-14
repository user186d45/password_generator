cmake_minimum_required(VERSION 3.10)

# Set some basic project attributes
project (password_generator VERSION 1.0.0)

set(password_generator_VERSION_MINOR ${password_generator_VERSION_MINOR})
set(password_generator_VERSION_MAJOR ${password_generator_VERSION_MAJOR})
set(password_generator_VERSION_PATCH ${password_generator_VERSION_PATCH})

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/version.h.in"
    "${CMAKE_CURRENT_BINARY_DIR}/version.h"
    @ONLY
)

include_directories(includes)

# This project will output an executable file
add_executable(${PROJECT_NAME} src/CommandHandler.cpp src/passGen.cpp src/passGenLogic.cpp src/password_generator.cpp)

# Include the configuration header in the build
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")
