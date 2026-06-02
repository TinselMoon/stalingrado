#pragma once
#include "../Entidade.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Personagens{
class Jogador;
}
namespace Obstaculos {
class Obstaculo : public Entidades::Entidade{
protected:
    bool danoso;
    bool lentidao;
public:
    Obstaculo(bool dano, bool lento, const std::string& nomeTextura);
    ~Obstaculo();
    void salvarDataBuffer();
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void obstaculizar(Personagens::Jogador* pJ) = 0;
};
}

} // Fim do namespace Entidades

} // Fim do namespace Stalingrado
