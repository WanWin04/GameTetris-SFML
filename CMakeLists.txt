cmake_minimum_required(VERSION 3.12)

project(game-tetris-sfml)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.cpp")

if (WIN32)
    set(SFML_DIR "D:/SFML")
endif()

find_package(SFML 2.6 COMPONENTS graphics window system audio REQUIRED)

add_executable(game ${SOURCES})

target_link_libraries(game sfml-graphics sfml-window sfml-system sfml-audio)

target_include_directories(game PRIVATE ${SFML_INCLUDE_DIR})