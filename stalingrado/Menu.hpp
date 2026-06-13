#pragma once
#include "Ente.hpp"

namespace Stalingrado {
    //Forward declaration para usar ponteiro
    class Jogo;
    class Menu : public Ente {
    private:
        const Jogo* pJogo;
    public:
        Menu(const Jogo *pJ);
        ~Menu();
        void desenhar();
        void executar();
    };
}
