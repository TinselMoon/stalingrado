#pragma once

#include "Menu.hpp"
#include "../States/State.hpp"

namespace Stalingrado {
    namespace States {
        class Jogo;
    }

    using namespace States;

    namespace Menus {

        class MenuInicial : public Menu, public State {

        private:
            Jogo* pJogo;
            bool two_players;

        public:
            MenuInicial(Jogo* pJ=nullptr);
            ~MenuInicial();
            void resetState();
            void executar();
            void confirmar();
            void update(const float dt);
            void desenharState();
            void carregarBotoes();
            bool getTwoPlayers() const;
        };

    }
}
