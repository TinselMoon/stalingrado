#pragma once 
#include "Entidade.hpp"

namespace Stalingrado{
namespace Entidades{
class Chao : public Entidade{
private:
    const int comprimento;
    const int altura;
public:
    Chao(const int comp, const std::string& textura);
    ~Chao();
    void setPosicao(float x, float y);
    const int getComprimento() const;
    void executar();
    void salvar(std::ofstream& arquivo);
    void movePos(float x, float y){}
    void setVelocidadeY(float vy){}
};
}
}
