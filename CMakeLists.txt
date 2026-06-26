cmake_minimum_required(VERSION 4.2 FATAL_ERROR)
project(Warframe-Randomizer)

# Build settings
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${SRC_DIR}/include")

include(FetchContent)
FetchContent_Declare(ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
    GIT_TAG main
)
FetchContent_MakeAvailable(ftxui)

# Main program
add_executable(wfrand)
target_sources(wfrand PRIVATE
    ${SRC_DIR}/wfrand.cpp
    ${SRC_DIR}/AppState.cpp
    ${SRC_DIR}/ComponentFactories.cpp
)
target_link_libraries(wfrand PRIVATE ftxui::ftxui)

target_compile_options(wfrand PRIVATE
    -Wall
    -Wextra
    -O2
)
