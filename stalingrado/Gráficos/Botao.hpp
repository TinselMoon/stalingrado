#pragma once

#include "../Ente.hpp"
#include "Texto.hpp"

//Inspirado na implementação do ex-monitor Matheus Augusto Burda, conforme este mostra nos seus vídeos tutoriais.

namespace Stalingrado {
    namespace Graficos {

        class Botao : public Ente {
        private:
            Texto textInfo;
            const sf::Texture* defaultTexture;
            const sf::Texture* selectedTexture;

        public:
            Botao(sf::Vector2f position = sf::Vector2f(0, 0), std::string info = "");
            ~Botao();
            void select(const bool isSelected);
            void executar();
        };

    }
}