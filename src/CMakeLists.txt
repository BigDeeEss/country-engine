# CMakeLists.txt for CountryEngine.

# Add source files for celib and specify that they are module files.
add_library(celib STATIC)

target_sources(celib
    PUBLIC
    FILE_SET CXX_MODULES FILES
    hello_world.cppm
)

# Install the library to the appropriate directory
install(
    TARGETS celib
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Add the main application executable.
add_executable(ce main.cpp)

# Link emp with all libraries.
target_link_libraries(ce
    PRIVATE
    celib
)

# Install the executable to the appropriate directory
install(
    TARGETS ce
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
