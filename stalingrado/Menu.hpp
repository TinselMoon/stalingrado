#pragma once
#include "Ente.hpp"

namespace Stalingrado {
    //Forward declaration para usar ponteiro
    class Jogo;
    class Menu : public Ente {
    private:
        const Jogo* pJogo;
        static Menu* instancia;
        
        Menu(const Jogo *pJ);
    public:
        ~Menu();
        static Menu* getInstancia(const Jogo *pJ);
        void desenhar();
        void executar();
    };
}
