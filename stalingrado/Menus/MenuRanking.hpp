#pragma once

#include "Menu.hpp"
#include "../Graficos/Texto.hpp"
#include <vector>

//Inspirado na implementação do ex-monitor Matheus Augusto Burda, conforme este mostra nos seus vídeos tutoriais.

namespace Stalingrado {
    namespace Menus {

        class MenuRanking : public Menu {

        private:
            std::vector<Graficos::Texto*> entradas;
            std::vector<Graficos::Texto*>::iterator itTexto;

            static bool compararPontuacao(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b);
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
