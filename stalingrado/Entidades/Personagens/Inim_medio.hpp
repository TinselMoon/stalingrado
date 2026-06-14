#pragma once
#include "Inimigo.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Personagens {
class Inim_medio : public Personagens::Inimigo {
    Jogador* pJog;
public:
    Inim_medio(int vida, int maldade);
    ~Inim_medio();
    void danificar(Personagem* pPers);
    void executar();
    void salvar();
    void mover();
};

}

} // Fim do namespace Entidades

} // Fim do namespace Stalingrado
