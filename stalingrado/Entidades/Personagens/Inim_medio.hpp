#pragma once
#include "Inimigo.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Personagens {
class Inim_medio : public Inimigo{
//
public:
    Inim_medio();
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
