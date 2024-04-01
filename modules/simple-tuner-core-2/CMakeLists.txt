file(GLOB SOURCES "src/adder.cpp")

add_library(simple-tuner-core-2 ${SOURCES})
target_include_directories(simple-tuner-core-2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(simple-tuner-core-2 ${llvm_libs})

add_executable(simple_tuner_core_2_tests src/adder_test.cpp)
target_link_libraries(simple_tuner_core_2_tests PRIVATE Catch2::Catch2WithMain simple-tuner-core-2)

# Register module tests
catch_discover_tests(simple_tuner_core_2_tests)
