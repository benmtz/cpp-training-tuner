file(GLOB SOURCES "src/factorial.cpp")

add_library(simple-tuner-core ${SOURCES})
target_include_directories(simple-tuner-core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(simple-tuner-core ${llvm_libs})

add_executable(simple_tuner_core_tests src/factorial_test.cpp)
target_link_libraries(simple_tuner_core_tests PRIVATE Catch2::Catch2WithMain simple-tuner-core)

# Register module tests
catch_discover_tests(simple_tuner_core_tests)
