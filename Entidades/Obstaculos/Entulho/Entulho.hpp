#pragma once
#include "../Obstaculo.hpp"

namespace Obstaculos{
class Entulho : public Obstaculos::Obstaculo{
private:
    //COLOCAR ALGO AQUI SLA
public:
    Entulho();
    ~Entulho();
    void executar();
    void salvar();
    void obstaculizar(Personagens::Jogador* pJ);
};
}
