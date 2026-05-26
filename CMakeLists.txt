cmake_minimum_required(VERSION 3.22)
project(stalingrado)

set(CMAKE_CXX_STANDARD 98)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

file(GLOB_RECURSE SOURCES
    "stalingrado/Entidades/*.cpp"
    "stalingrado/Entidades/Obstaculos/*.cpp"
    "stalingrado/Entidades/Obstaculos/Arame_farp/*.cpp"
    "stalingrado/Entidades/Obstaculos/Entulho/*.cpp"
    "stalingrado/Entidades/Obstaculos/Explosivo/*.cpp"
    "stalingrado/Entidades/Personagens/*.cpp"
    "stalingrado/Entidades/Personagens/Inim_chefao/*.cpp"
    "stalingrado/Entidades/Personagens/Inim_facil/*.cpp"
    "stalingrado/Entidades/Personagens/Inim_medio/*.cpp"
    "stalingrado/Entidades/Personagens/Jogador/*.cpp"
    "stalingrado/Fases/*.cpp"
    "stalingrado/Gerenciadores/*.cpp"
    "stalingrado/Listas/*.cpp"
    "main.cpp"
    "stalingrado/Stalingrad.cpp"
)

add_executable(stalingrado ${SOURCES})

target_include_directories(stalingrado PRIVATE
  Gerenciadores
)

target_link_libraries(stalingrado sfml-graphics sfml-window sfml-system)
