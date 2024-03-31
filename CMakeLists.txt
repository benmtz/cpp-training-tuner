cmake_minimum_required(VERSION 3.27)

project(SIMPLE_TUNER VERSION 0.0.1)

enable_testing()

#set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")

add_subdirectory(third_party/juce)
add_subdirectory(third_party/catch2)

add_subdirectory(modules/simple-tuner-core)
add_subdirectory(modules/simple-tuner-core-2)
add_subdirectory(modules/simple-tuner-gui)

