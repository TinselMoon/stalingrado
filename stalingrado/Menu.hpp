#pragma once
#include "Ente.hpp"

namespace Stalingrado{

    //Forward declaration para usar ponteiro
    class Jogo;

    class Menu : public Ente{
    private:
        const Jogo* pJog;
    public:
        Menu(const Jogo *pJ = NULL);
        ~Menu();
        void desenhar();
        void executar();
    };
}
