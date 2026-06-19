#pragma once
#include "Obstaculo.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Obstaculos {
class Arame_farp : public Obstaculos::Obstaculo{
private:
    //COLOCAR ALGO AQUI SLA
    const float fator_lentidao;
public:
    Arame_farp();
    ~Arame_farp();
    void executar();
    void salvar(std::ofstream& arquivo);
    void obstaculizar(Personagens::Jogador* pJ);
};
}

} // Fim do namespace Entidades

} // Fim do namespace Stalingrado
