# CMake configuration for unit tests in the CountryEngine project.

# Add the test executable target and specify its source files.
add_executable(countryenginetests.x main.cpp)

# Add source files for the test executable and specify that they are private files.
target_sources(countryenginetests.x
    PRIVATE
    # FILE_SET CXX_MODULES FILES
    utils/logger_test.cpp
)

# Link the test executable with the countryengine library and Google Test. framework.
target_link_libraries(countryenginetests.x
    PRIVATE
    countryengine
    GTest::gtest
)

# Install the executable to the appropriate directory
install(
    TARGETS countryenginetests.x
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

include(GoogleTest)
gtest_discover_tests(countryenginetests.x)
