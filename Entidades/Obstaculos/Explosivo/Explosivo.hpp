#pragma once
#include "../Obstaculo.hpp"

namespace Obstaculos{
class Explosivo : public Obstaculos::Obstaculo{
private:
    //COLOCAR ALGO AQUI SLA
    int danosidade;
public:
    Explosivo();
    Explosivo(int dano);
    ~Explosivo();
    void executar();
    void salvar();
    void obstaculizar(Personagens::Jogador* pJ);
};
}
