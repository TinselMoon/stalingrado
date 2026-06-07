#pragma once
#include "Personagem.hpp"

namespace Stalingrado {


namespace Entidades {
namespace Personagens {
class Jogador;
class Inimigo : public Personagens::Personagem{
protected:
    int nivel_maldade;
    float dt_movimento;
    float dt_dano;
public:
    Inimigo(int vida, int maldade, const std::string& nomeTextura);
    ~Inimigo();
    void salvarDataBuffer();
    virtual void executar() = 0;
    virtual void danificar(Jogador* pJ) = 0;
    virtual void mover();
    virtual void salvar();
};
}

} // Fim do namespace Entidades

} // Fim do namespace Stalingrado
