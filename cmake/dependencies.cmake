# Add GTest when tests are enabled.
if(BUILD_TESTING OR CMAKE_BUILD_TYPE STREQUAL "Debug")
    find_package(GTest REQUIRED)
endif()
# find_package(yaml-cpp REQUIRED)
# find_package(ryml REQUIRED)
