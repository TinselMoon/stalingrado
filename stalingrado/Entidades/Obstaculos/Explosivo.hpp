#pragma once
#include "Obstaculo.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Obstaculos {
class Explosivo : public Obstaculos::Obstaculo{
private:
    int danosidade;
public:
    Explosivo();
    ~Explosivo();
    void executar();
    void salvar(std::ofstream& arquivo);
    void obstaculizar(Personagens::Jogador* pJ);
};
}

} // Fim do namespace Entidades

} // Fim do namespace Stalingrado
