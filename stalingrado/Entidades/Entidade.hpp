#pragma once
#include "../Ente.hpp"
#include <ostream>

namespace Stalingrado {

namespace Entidades{
class Projetil;
class Entidade : public Ente{
protected:
    //std::ostream buffer;// Ainda não entendi para que serve
    virtual void salvarDataBuffer();
    bool ativo;
public:
    Entidade(const std::string& nomeTextura);
    virtual ~Entidade();
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void movePos(float x, float y) = 0;
    virtual void setVelocidadeY(float vy) = 0;
    const bool isAtivo() const;
};


}

} // Fim do namespace Stalingrado
