#pragma once
#include "Obstaculo.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Obstaculos {
class Entulho : public Obstaculos::Obstaculo {
private:
    const float mult_impulso;
public:
    Entulho();
    ~Entulho();
    void executar();
    void salvar(std::ofstream& arquivo);
    void obstaculizar(Personagens::Jogador* pJ);
};
}

} // Fim do namespace Entidades

} // Fim do namespace Stalingrado
