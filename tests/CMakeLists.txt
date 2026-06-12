# CMake configuration for unit tests in the CountryEngine project.

# Add the test executable target and specify its source files.
add_executable(countryenginetests.x main.cpp)

target_sources(countryenginetests.x
    PRIVATE
    FILE_SET CXX_MODULES FILES
    utils/logger_test.cppm
)

target_link_libraries(countryenginetests.x
    PRIVATE
    countryengine
    GTest::gtest
)

include(GoogleTest)
gtest_discover_tests(countryenginetests.x)
