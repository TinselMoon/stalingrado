cmake_minimum_required(VERSION 3.22)
project(stalingrado)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib/SFML)

file(GLOB_RECURSE GAME_SOURCES "stalingrado/*.cpp")


add_executable(stalingrado
    ${GAME_SOURCES}
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
)

target_include_directories(stalingrado PRIVATE
  Gerenciadores
)

target_link_libraries(stalingrado sfml-graphics sfml-window sfml-system sfml-audio)

message(STATUS "Compilador CXX em uso: ${CMAKE_CXX_COMPILER}")

