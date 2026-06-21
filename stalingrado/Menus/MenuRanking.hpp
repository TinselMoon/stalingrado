#pragma once

#include "Menu.hpp"
#include "../Gráficos/Texto.hpp"
#include <vector>

namespace Stalingrado {
    namespace States {
        class Jogo;
    }

    namespace Menus {

        class MenuRanking : public Menu {

        private:
            States::Jogo* pJogo;
            std::vector<Graficos::Texto*> entradas;
            std::vector<Graficos::Texto*>::iterator itTexto;

            void limparEntradas();
            void carregarPontuacoes();

        public:
            MenuRanking(States::Jogo* pJ = nullptr);
            ~MenuRanking();
            void executar();
            void confirmar();
            void resetMenu();
            void carregarBotoes();
            bool getTwoPlayers() const;
        };

    }
}
