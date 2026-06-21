#pragma once

#include "Menu.hpp"

namespace Stalingrado {
    namespace States {
        class Jogo;
    }

    namespace Menus {

        class MenuGameOver : public Menu {

        private:
            States::Jogo* pJogo;
            bool vitoria;
            int pontuacaoFinal;
            std::string nomeDigitado;

        public:
            MenuGameOver(States::Jogo* pJ = nullptr);
            ~MenuGameOver();
            void configurar(bool vitoriaFinal, int pontuacao);
            void executar();
            void inserirCaractere(unsigned int unicode);
            void apagarCaractere();
            void confirmar();
            bool getTwoPlayers() const;
        };

    }
}
