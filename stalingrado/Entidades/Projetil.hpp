#pragma once
#include "Entidade.hpp"

namespace Stalingrado {

namespace Entidades{
namespace Personagens{
class Jogador;
}
class Projetil : public Entidade{
protected:
    float vel_x;
    float vel_y;
    const float vel_projetil;
    float dt_exist;
public:
    Projetil();
    ~Projetil();
    void danificar(Personagens::Jogador *pJ);
    void executar();
    void salvar();
    void movePos(float x, float y);
    void setDir(float x,float y);
    void setPosition(float x, float y);
    void ativar();
    void destruir();
    void setVelocidadeY(float vy){}
};
}

} // Fim do namespace Stalingrado
