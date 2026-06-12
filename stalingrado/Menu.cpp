#include "Menu.hpp"

namespace Stalingrado{

    Menu* Menu::instancia = NULL;

    Menu::Menu(const Jogo *pJ) : Ente(), pJogo(pJ) {

    }

    Menu::~Menu(){

    }

    Menu* Menu::getInstancia(const Jogo *pJ) {

        if (instancia == NULL)
            instancia = new Menu(pJ);

        return instancia;
    }

    void Menu::executar(){

    }

    void Menu::desenhar(){

    }
}
