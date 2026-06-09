# CMakeLists.txt for ExampleModularProject.
add_library(emplib)

# Add source files for emplib and specify that they are module files.
target_sources(emplib
    PUBLIC
    FILE_SET CXX_MODULES FILES
    hello_world.cpp
)

# Install the library to the appropriate directory
install(
    TARGETS emplib
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Add the main application executable.
add_executable(emp main.cpp)

# Link emp with all libraries.
target_link_libraries(emp
    PRIVATE
    emplib
)

# Install the executable to the appropriate directory
install(
    TARGETS emp
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
