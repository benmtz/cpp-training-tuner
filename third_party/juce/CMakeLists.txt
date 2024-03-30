set(APP_JUCE_VERSION CACHE STRING "")
if(NOT APP_JUCE_VERSION)
    message(FATAL_ERROR "APP_JUCE_VERSION is not set")
endif()

include(FetchContent)
FetchContent_Declare (
        juce
        GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
        GIT_TAG ${APP_JUCE_VERSION}
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable (juce)
