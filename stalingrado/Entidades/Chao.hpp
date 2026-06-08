#pragma once 
#include "Entidade.hpp"

namespace Stalingrado{
namespace Entidades{
class Chao : public Entidade{
private:
    const int comprimento;
    float altura;
public:
    Chao(const int comp);
    ~Chao();
    void setPosicao(float x, float y);
    const int getComprimento() const;
    void executar();
    void salvar();
    virtual void movePos(float x, float y){}
    virtual void setVelocidadeY(float vy){}
};
}
}
