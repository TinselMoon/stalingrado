#pragma once
#include "../Ente.hpp"
#include <fstream>

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
    virtual void salvar(std::ofstream& arquivo) = 0;
    virtual void movePos(float x, float y) = 0;
    virtual void setVelocidadeY(float vy) = 0;
    const bool isAtivo() const;
    void setAtivo(bool at);
};


}

} // Fim do namespace Stalingrado
