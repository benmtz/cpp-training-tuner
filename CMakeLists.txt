cmake_minimum_required(VERSION 3.27)

project(SIMPLE_TUNER VERSION 0.0.1)

# Append brew installed llvm
list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/opt/llvm")
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})
llvm_map_components_to_libnames(llvm_libs support core irreader)

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

function(print_all_targets DIR)
    get_property(TGTS DIRECTORY "${DIR}" PROPERTY BUILDSYSTEM_TARGETS)
    foreach(TGT IN LISTS TGTS)
        message(STATUS "Target: ${TGT}")
        # TODO: Do something about it
    endforeach()

    get_property(SUBDIRS DIRECTORY "${DIR}" PROPERTY SUBDIRECTORIES)
    foreach(SUBDIR IN LISTS SUBDIRS)
        print_all_targets("${SUBDIR}")
    endforeach()
endfunction()

print_all_targets(.)

