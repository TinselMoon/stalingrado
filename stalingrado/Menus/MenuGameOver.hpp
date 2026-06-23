#pragma once

#include "Menu.hpp"

//Inspirado na implementação do ex-monitor Matheus Augusto Burda, conforme este mostra nos seus vídeos tutoriais.
namespace Stalingrado {
    namespace Menus {

        class MenuGameOver : public Menu {

        private:
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
