# See https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md#usage
set(APP_CATCH2_VERSION CACHE STRING "")
if(NOT APP_CATCH2_VERSION)
    message(FATAL_ERROR "APP_CATCH2_VERSION is not set")
endif()


Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        ${APP_CATCH2_VERSION}
)
FetchContent_MakeAvailable(Catch2)

if(TARGET Catch2::Catch2)
    message(STATUS "Catch2 library fetched successfully.")
else()
    message(FATAL_ERROR "Failed to fetch Catch2 library.")
endif()

# Mandatory in order to find tests when using fetchcontent
list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)

include(CTest)
include(Catch)
