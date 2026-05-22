cmake_minimum_required(VERSION 3.22)
project(stalingrado)

set(CMAKE_CXX_STANDARD 98)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/libs/SFML-2.5/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(stalingrado
        jogo.cpp
        Gerenciadores/Gerenciador_Grafico.cpp
        Gerenciadores/Gerenciador_Grafico.hpp
        Ente.cpp
        Ente.hpp
)

target_include_directories(stalingrado PRIVATE Gerenciadores)

target_link_libraries(stalingrado sfml-graphics sfml-window sfml-system)
