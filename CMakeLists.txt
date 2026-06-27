cmake_minimum_required(VERSION 3.22)
project(stalingrado)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML 2.6 COMPONENTS graphics window system audio REQUIRED)

file(GLOB_RECURSE SOURCES
    "stalingrado/*.cpp"
    "main.cpp"
)

add_executable(stalingrado ${SOURCES}
)

target_include_directories(stalingrado PRIVATE
  Gerenciadores
)

target_link_libraries(stalingrado sfml-graphics sfml-window sfml-system sfml-audio)

message(STATUS "Compilador CXX em uso: ${CMAKE_CXX_COMPILER}")

