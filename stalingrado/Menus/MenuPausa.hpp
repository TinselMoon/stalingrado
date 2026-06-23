#pragma once

#include "Menu.hpp"

//Inspirado na implementação do ex-monitor Matheus Augusto Burda, conforme este mostra nos seus vídeos tutoriais.

namespace Stalingrado {
    namespace Menus {

        class MenuPausa : public Menu {

        private:
            bool taPausado;

        public:
            MenuPausa(States::Jogo* pJ = nullptr);
            ~MenuPausa();
            void executar();
            void confirmar();
            void resetMenu();
            void carregarBotoes();
            bool getTwoPlayers() const;
            bool getTaPausado() const;
        };

    }
}
