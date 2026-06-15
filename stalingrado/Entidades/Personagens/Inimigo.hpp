#pragma once
#include "Personagem.hpp"

namespace Stalingrado {


namespace Entidades {
namespace Personagens {
class Jogador;
class Inimigo : public Personagem{
protected:
    int nivel_maldade;
    //float max_speed;
    //float dt_movimento;
    //float dt_dano;
    bool isChefao;
    const int pontos_por_kill;
public:
    Inimigo(int vida, int maldade, const std::string& nomeTextura);
    ~Inimigo();
    void salvarDataBuffer();
    virtual void executar();
    const int getPontos() const;
    virtual void mover();
    virtual void salvar();
    const bool getChefao() const;
};
}

} // Fim do namespace Entidades

} // Fim do namespace Stalingrado
