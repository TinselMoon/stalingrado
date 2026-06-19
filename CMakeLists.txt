cmake_minimum_required(VERSION 3.22)
project(stalingrado)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

file(GLOB_RECURSE SOURCES
    "stalingrado/*.cpp"
    "main.cpp"
)

add_executable(stalingrado ${SOURCES}
        stalingrado/States/Jogo.hpp
        stalingrado/Menus/MenuInicial.hpp
        stalingrado/Gerenciadores/Gerenciador_eventos.hpp
        stalingrado/Controle/ControleJogador.hpp
        stalingrado/Controle/TextInput.hpp
        stalingrado/Gráficos/Texto.hpp
        stalingrado/Gráficos/Botao.hpp
        stalingrado/Gerenciadores/Gerenciador_input.hpp
        stalingrado/Gerenciadores/Gerenciador_grafico.hpp
        stalingrado/Gerenciadores/Gerenciador_colisoes.hpp
        stalingrado/Entidades/Projetil.hpp
        stalingrado/Entidades/Obstaculos/Arame_farp.hpp
        stalingrado/Entidades/Obstaculos/Entulho.hpp
        stalingrado/Controle/ControleMenu.hpp
        stalingrado/Controle/Observer.hpp
        stalingrado/Entidades/Obstaculos/Explosivo.hpp
        stalingrado/Entidades/Obstaculos/Obstaculo.hpp
        stalingrado/Entidades/Personagens/Inim_chefao.hpp
        stalingrado/Entidades/Personagens/Inim_facil.hpp
        stalingrado/Entidades/Personagens/Inim_medio.hpp
        stalingrado/Entidades/Personagens/Inimigo.hpp
        stalingrado/Entidades/Personagens/Jogador.hpp
        stalingrado/Entidades/Personagens/Personagem.hpp
        stalingrado/Entidades/Chao.hpp
        stalingrado/Entidades/Entidade.hpp
        stalingrado/Ente.hpp
        stalingrado/States/State.hpp
        stalingrado/States/StateMachine.hpp
        stalingrado/States/Fases/fase.hpp
        stalingrado/States/Fases/Fase_prim.hpp
        stalingrado/States/Fases/Fase_seg.hpp
        stalingrado/Listas/Lista_entidades.hpp
        stalingrado/Listas/listas.hpp
        stalingrado/Menus/Menu.hpp
        stalingrado/Menus/MenuConfig.hpp
        stalingrado/Menus/MenuGameOver.hpp
        stalingrado/Menus/MenuPausa.hpp
        stalingrado/Menus/MenuRanking.hpp
)

target_include_directories(stalingrado PRIVATE
  Gerenciadores
)

target_link_libraries(stalingrado sfml-graphics sfml-window sfml-system)
