#pragma once
#include "Obstaculo.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Obstaculos {
class Entulho : public Obstaculos::Obstaculo{
private:
    float mult_impulso;
public:
    Entulho();
    ~Entulho();
    void executar();
    void salvar();
    void obstaculizar(Personagens::Jogador* pJ);
};
}

} // Fim do namespace Entidades

} // Fim do namespace Stalingrado
