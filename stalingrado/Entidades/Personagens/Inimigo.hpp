#pragma once
#include "Personagem.hpp"

namespace Stalingrado {


namespace Entidades {
namespace Personagens {
class Jogador;
class Inimigo : public Personagem{
protected:
    int nivel_maldade;
    float max_speed;
    float dt_movimento;
    bool isChefao;
    const int pontos_por_kill;
    float dt_mudar_direcao;
public:
    Inimigo(int vida, int maldade, const std::string& nomeTextura);
    ~Inimigo();
    void salvarDataBuffer();
    virtual void executar();
    const int getPontos() const;
    virtual void mover()=0;
    virtual void salvar(std::ofstream& arquivo);
    virtual void aplicarVelocidadeSalva(float vx)=0;
    const bool getChefao() const;
};
}

} // Fim do namespace Entidades

} // Fim do namespace Stalingrado
