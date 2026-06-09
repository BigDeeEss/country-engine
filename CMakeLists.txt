# CMakeLists.txt for the newp project, which demonstrates a simple C++ application with modular structure and modern CMake practices.
cmake_minimum_required(VERSION 3.28)

# Define the project name and specify that it uses C++.
project(newp LANGUAGES CXX)

# Include configuration and flags from separate CMake files for better organization and maintainability.
include(cmake/config.cmake)
include(cmake/flags.cmake)

# Add the src directory, which contains the main application and its library.
add_subdirectory(src)
