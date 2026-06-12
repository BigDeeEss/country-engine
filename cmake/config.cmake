# Set language standards.
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable generation of compile_commands.json for better integration with code editors and tools.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Use pre-defined installation directory variables.
include(GNUInstallDirs)

# Configure CMAKE_INSTALL_PREFIX for a local install.
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)

# Check the build type and print a message accordingly.
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "[${PROJECT_NAME}] Configuring for Debug build.")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "[${PROJECT_NAME}] Configuring for Release build.")
else()
    message(STATUS "[${PROJECT_NAME}] Unknown CMAKE_BUILD_TYPE. Defaulting to Debug.")
    set(CMAKE_BUILD_TYPE "Debug")
endif()


