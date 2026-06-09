# CMakeLists.txt - Main CMake configuration for the newp project.
add_library(print_hello_world_lib)

# Add the C++ module source file to the library target. The CXX_MODULES option indicates that this is a C++ module interface unit.
target_sources(print_hello_world_lib
    PUBLIC
    FILE_SET CXX_MODULES FILES
    print_hello_world.cpp
)

install(
    TARGETS print_hello_world_lib
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

add_executable(newp main.cpp)

target_link_libraries(newp
    PRIVATE
    print_hello_world_lib
)

# Install the executable to the appropriate directory
install(
    TARGETS newp
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
