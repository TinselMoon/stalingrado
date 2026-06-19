#pragma once
#include "Entidade.hpp"

namespace Stalingrado {

namespace Entidades{
namespace Personagens{
class Jogador;
class Inim_chefao;
}
class Projetil : public Entidade{
protected:
    float vel_x;
    float vel_y;
    const float vel_projetil;
    float dt_exist;
    Personagens::Inim_chefao *pChefao;
    float mult_impulso;
public:
    Projetil();
    ~Projetil();
    void danificar(Personagens::Jogador *pJ);
    void executar();
    void salvar(std::ofstream& arquivo);
    void movePos(float x, float y);
    void setDir(float x,float y);
    void setPosition(float x, float y);
    void ativar();
    void destruir();
    void setVelocidadeY(float vy){}
    void setChefao(Personagens::Inim_chefao *pInim);
};
}

} // Fim do namespace Stalingrado
