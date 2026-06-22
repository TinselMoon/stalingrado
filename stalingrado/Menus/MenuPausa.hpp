#pragma once

#include "Menu.hpp"

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
