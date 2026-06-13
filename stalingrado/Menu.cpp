#include "Menu.hpp"

namespace Stalingrado{
    
    Menu::Menu(const Jogo *pJ) : Ente("Menu"), pJogo(pJ) {

    }

    Menu::~Menu(){

    }

    void Menu::executar(){
        desenhar();

        
    }

}
