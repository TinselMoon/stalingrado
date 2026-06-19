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
        public:
            MenuInicial(Jogo* pJ=nullptr);
            ~MenuInicial();
            void resetState();
            void executar();
            void update(const float dt);
            void desenharState();
        };

    }
}
