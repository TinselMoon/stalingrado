#pragma once
#include "../Entidade.hpp"

class Jogador;

namespace Obstaculos{
class Obstaculo : public Entidades::Entidade{
protected:
    bool danoso;
    bool lentidao;
public:
    Obstaculo();
    Obstaculo(bool dano, bool lento);
    ~Obstaculo();
    void salvarDataBuffer();
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void obstaculizar(Jogador* pJ) = 0;
};
}
