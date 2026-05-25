#pragma once
#include "../Obstaculo.hpp"

namespace Entidades {
namespace Obstaculos {
class Arame_farp : public Obstaculos::Obstaculo{
private:
    //COLOCAR ALGO AQUI SLA
public:
    Arame_farp();
    ~Arame_farp();
    void executar();
    void salvar();
    void obstaculizar(Personagens::Jogador* pJ);
};
}

} // Fim do namespace Entidades
