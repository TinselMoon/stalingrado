#pragma once
#include "Inimigo.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Personagens {
class Inim_facil : public Personagens::Inimigo{
private:
    const float tempo_atordoar;
public:
    Inim_facil(int vida = 5, int maldade = 1);
    ~Inim_facil();
    void danificar(Personagem* pPers);
    void executar();
    void salvar(std::ofstream& arquivo);
};

}

} // Fim do namespace Entidades

} // Fim do namespace Stalingrado
