# CMakeLists.txt for CountryEngine.
add_library(countryengine STATIC)

# Add source files for countryengine and specify that they are module files.
target_sources(countryengine
    PUBLIC
    FILE_SET CXX_MODULES FILES
    hello_world.cppm
    utils/logger.cppm
    PRIVATE
    utils/logger.cpp
)

# Link countryengine library.
target_link_libraries(countryengine
    PRIVATE
    yaml-cpp::yaml-cpp
    ryml::ryml
)

# Install the library to the appropriate directory
install(
    TARGETS countryengine
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Add the main application executable.
add_executable(countryengine.x main.cpp)

# Link emp with all libraries.
target_link_libraries(countryengine.x
    PRIVATE
    countryengine
)

# Install the executable to the appropriate directory
install(
    TARGETS countryengine.x
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
