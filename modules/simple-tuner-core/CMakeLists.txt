file(GLOB SOURCES "src/*.cpp")
add_library(simple-tuner-core ${SOURCES})
target_include_directories(simple-tuner-core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
