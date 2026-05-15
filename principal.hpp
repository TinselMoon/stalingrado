#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "/home/x/Desktop/stalingrad/jogador.hpp"

namespace Stalingrado {

    class Principal {

    private:
        sf::RenderWindow window;
        Jogador::Jogador jogador;
    public:
        Principal();
        ~Principal();
        void executar();
    };

}

