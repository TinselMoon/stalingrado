#pragma once

#include "Menu.hpp"

//Pedi ajuda para IAs (Gemini e Claude) com o fim de elaborar um fundo transparente para enegrecer a fase no final e para me ajudar
//a ajudar a desenvolver uma lógica para renderizar a fase ao fundo enquanto o menu aparece na frente. --Gustavo

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
