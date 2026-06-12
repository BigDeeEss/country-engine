# CMakeLists.txt for the root of the project. 
# This file sets up the project and includes the necessary subdirectories and 
# configuration files.
cmake_minimum_required(VERSION 3.28)

# Define the project name and specify that it uses C++.
project(CountryEngine LANGUAGES CXX)

# Include depoendencies, configuration settings and flags from separate CMake 
# files for better organization and maintainability.
include(cmake/config.cmake)
include(cmake/dependencies.cmake)
include(cmake/flags.cmake)

# Add the src directory, which contains the main application and its library.
add_subdirectory(src)

# Add test targets when available.
if(${GTEST_FOUND})
    enable_testing()
    add_subdirectory(tests)
endif()
