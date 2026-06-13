#include "Menu.hpp"

namespace Stalingrado{
    
    Menu::Menu(const Jogo *pJ) : Ente(), pJogo(pJ) {

    }

    Menu::~Menu(){

    }

    void Menu::executar(){
        desenhar();
    }

}
