#pragma once
#include "../Entidade.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Personagens {
class Personagem : public Entidades::Entidade {
protected:
    int num_vidas;
    float vel_x;
    float vel_y;
public:
    Personagem(int vida, const std::string& nomeTextura);
    ~Personagem();
    void salvarDataBuffer();
    void setNewPos(float x, float y);
    void setVelocidadeX(float vx);
    void setVelocidadeY(float vy);
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void mover() = 0;
};
}

} // Fim do namespace Entidades

} // Fim do namespace Stalingrado
