#pragma once

#include "Menu.hpp"

namespace Stalingrado {
    namespace States {
        class Jogo;
    }

    namespace Menus {

        class MenuPausa : public Menu {

        private:
            States::Jogo* pJogo;

        public:
            MenuPausa(States::Jogo* pJ = nullptr);
            ~MenuPausa();
            void executar();
            void confirmar();
            void resetMenu();
            void carregarBotoes();
            bool getTwoPlayers() const;
        };

    }
}
