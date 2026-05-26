#pragma once
#include "../Entidade.hpp"

namespace Entidades{
    namespace Personagens{
        class Jogador;
    }
}

namespace Entidades {
namespace Obstaculos {
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
    virtual void obstaculizar(Personagens::Jogador* pJ) = 0;
};
}

} // Fim do namespace Entidades
