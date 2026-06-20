#pragma once
#include "Inimigo.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Personagens {
class Inim_medio : public Inimigo{
private:
    const int recover_life;
public:
    Inim_medio(int vida = 10, int maldade = 2);
    ~Inim_medio();
    void danificar(Personagem* pPers);
    void executar();
    void salvar(std::ofstream& arquivo);
};

}

} // Fim do namespace Entidades

} // Fim do namespace Stalingrado
