cmake_minimum_required(VERSION 3.22)
project(stalingrado)

set(CMAKE_CXX_STANDARD 98)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/libs/SFML-2.5/lib/cmake/SFML")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(stalingrado
        main.cpp
        Gerenciadores/Gerenciadores.cpp
        Gerenciadores/Gerenciadores.hpp
        Stalingrad.hpp
        Stalingrad.cpp
)

target_include_directories(stalingrado PRIVATE
  Gerenciadores
  ${CMAKE_SOURCE_DIR}/libs/SFML-2.5/include
)

target_link_libraries(stalingrado sfml-graphics sfml-window sfml-system)
