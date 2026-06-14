#pragma once
#include "Ente.hpp"

namespace Stalingrado {
    class Jogo;

    class Menu : public Ente {
    private:
        Jogo* pJogo;
        bool inMenu;
    public:
        Menu(Jogo* pJ);
        ~Menu();
        void executar();
        void set_inMenu(bool noMenu);
        void processarEvento(const sf::Event& e);
    };
}