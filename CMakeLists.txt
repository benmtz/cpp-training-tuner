cmake_minimum_required(VERSION 3.27)

project(SIMPLE_TUNER VERSION 0.0.1)

# CLang setup
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcoverage-mapping -fprofile-instr-generate --coverage")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()


# Setup testing
enable_testing()

#set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")

option(TEST_ONLY_MODE "Collect coverage from test library" OFF)


# Made in order to try to have something working with sonar
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(third_party/juce)
add_subdirectory(third_party/catch2)

add_subdirectory(modules/simple-tuner-core)
add_subdirectory(modules/simple-tuner-core-2)
add_subdirectory(modules/simple-tuner-gui)
