#pragma once
#include "Entidade.hpp"
namespace Stalingrado{
namespace Entidades{
class Parede : public Entidade{
private:
    float altura;
    float largura;
public:
    Parede();
    ~Parede();
    void setPosicao(float x, float y);
    void executar();
    void salvar();
};
}
}
