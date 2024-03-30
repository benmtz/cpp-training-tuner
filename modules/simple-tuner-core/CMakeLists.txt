file(GLOB SOURCES "src/adder.cpp")

add_library(simple-tuner-core ${SOURCES})
target_include_directories(simple-tuner-core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(simple_tuner_core_tests src/test_adder.cpp)
target_link_libraries(simple_tuner_core_tests PRIVATE Catch2::Catch2WithMain)

catch_discover_tests(simple_tuner_core_tests)
