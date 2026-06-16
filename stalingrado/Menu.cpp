#include "Menu.hpp"
#include "Jogo.hpp"

namespace Stalingrado {

    Menu::Menu(Jogo* pJ) : Ente("Menu"), pJogo(pJ), inMenu(true) {
    }

    Menu::~Menu() {
    }

    void Menu::executar() {
        if (inMenu)
            desenhar();
    }
}
